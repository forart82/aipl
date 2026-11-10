#!/usr/bin/env python3
"""
tools/conductor.py - Multi-Agent Concurrency Contracts & Deterministic Worktree Arbitration
Enforces Scope(A) ∩ Scope(B) = ∅ for owned files and reserved symbols across concurrent agents.
Computes deterministic topological cherry-pick merge sequences.
"""

import sys
import os
import json
import re
import argparse
from typing import List, Dict, Any, Tuple, Optional

class AgentScopePartition:
    def __init__(self, agent_id: str, owned_files: List[str], reserved_symbols: List[str], priority_order: int):
        self.agent_id = agent_id
        self.owned_files = [os.path.normpath(f.strip()) for f in owned_files if f.strip()]
        self.reserved_symbols = [s.strip() for s in reserved_symbols if s.strip()]
        self.priority_order = priority_order

    def to_dict(self) -> Dict[str, Any]:
        return {
            "agentId": self.agent_id,
            "ownedFiles": self.owned_files,
            "reservedSymbols": self.reserved_symbols,
            "priorityOrder": self.priority_order,
        }

class ConductorArbitrationReport:
    def __init__(self, is_disjoint: bool, conflict_count: int, conflicting_file: str, conflicting_symbol: str, merge_order: List[str]):
        self.is_disjoint = is_disjoint
        self.conflict_count = conflict_count
        self.conflicting_file = conflicting_file
        self.conflicting_symbol = conflicting_symbol
        self.merge_order = merge_order

    def to_dict(self) -> Dict[str, Any]:
        return {
            "isDisjoint": self.is_disjoint,
            "conflictCount": self.conflict_count,
            "conflictingFile": self.conflicting_file,
            "conflictingSymbol": self.conflicting_symbol,
            "mergeOrder": self.merge_order,
        }

def parse_partition_spec(spec_data: Any) -> List[AgentScopePartition]:
    raw_list = []
    if isinstance(spec_data, list):
        raw_list = spec_data
    elif isinstance(spec_data, dict):
        if "partitions" in spec_data and isinstance(spec_data["partitions"], list):
            raw_list = spec_data["partitions"]
        elif "tasks" in spec_data and isinstance(spec_data["tasks"], list):
            raw_list = spec_data["tasks"]
        else:
            raise ValueError("Invalid manifest JSON format: expected 'partitions' or 'tasks' array or root array")
    else:
        raise ValueError("Invalid manifest JSON: expected JSON object or array")

    partitions = []
    for item in raw_list:
        agent_id = item.get("agentId") or item.get("role") or f"agent_{len(partitions)+1}"
        owned_files = item.get("ownedFiles") or item.get("allowedWriteFiles") or []
        reserved_symbols = item.get("reservedSymbols") or item.get("symbols") or []
        priority_order = item.get("priorityOrder", item.get("priority", 100))
        partitions.append(AgentScopePartition(agent_id, owned_files, reserved_symbols, priority_order))
    return partitions

def extract_ast_symbols_from_file(file_path: str) -> List[str]:
    """Extract declared top-level symbols (fn, struct, enum) from an AIPL source file."""
    if not os.path.exists(file_path) or not os.path.isfile(file_path):
        return []
    try:
        with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
            content = f.read()
    except Exception:
        return []

    symbols = []
    # Pattern for pub fn / fn / pub struct / struct / pub enum / enum
    pattern = re.compile(r"^\s*(?:pub\s+)?(?:fn|struct|enum)\s+([a-zA-Z0-9_]+)", re.MULTILINE)
    for match in pattern.finditer(content):
        symbols.append(match.group(1))
    return symbols

def verify_disjoint_agent_contracts(partitions: List[AgentScopePartition], check_ast_files: bool = False) -> ConductorArbitrationReport:
    conflict_count = 0
    conflicting_file = ""
    conflicting_symbol = ""

    # Check pairwise file collisions and symbol collisions
    n = len(partitions)
    for i in range(n):
        p_a = partitions[i]
        for j in range(i + 1, n):
            p_b = partitions[j]

            # File collision check: Scope(A).ownedFiles ∩ Scope(B).ownedFiles = ∅
            common_files = set(p_a.owned_files).intersection(set(p_b.owned_files))
            for f in sorted(common_files):
                conflict_count += 1
                if not conflicting_file:
                    conflicting_file = f

            # Reserved symbol collision check: Scope(A).reservedSymbols ∩ Scope(B).reservedSymbols = ∅
            common_symbols = set(p_a.reserved_symbols).intersection(set(p_b.reserved_symbols))
            for s in sorted(common_symbols):
                conflict_count += 1
                if not conflicting_symbol:
                    conflicting_symbol = s

    # Optional AST check against existing files
    if check_ast_files:
        for i in range(n):
            p_a = partitions[i]
            extracted = []
            for f in p_a.owned_files:
                extracted.extend(extract_ast_symbols_from_file(f))
            for j in range(n):
                if i == j:
                    continue
                p_b = partitions[j]
                leaked = set(extracted).intersection(set(p_b.reserved_symbols))
                for s in sorted(leaked):
                    conflict_count += 1
                    if not conflicting_symbol:
                        conflicting_symbol = s

    is_disjoint = (conflict_count == 0)

    # Sort partitions deterministically by priorityOrder ascending, then agentId
    sorted_parts = sorted(partitions, key=lambda p: (p.priority_order, p.agent_id))
    merge_order = [p.agent_id for p in sorted_parts]

    return ConductorArbitrationReport(
        is_disjoint=is_disjoint,
        conflict_count=conflict_count,
        conflicting_file=conflicting_file,
        conflicting_symbol=conflicting_symbol,
        merge_order=merge_order,
    )

def print_arbitration(report: ConductorArbitrationReport, json_mode: bool = False):
    if json_mode:
        print(json.dumps(report.to_dict(), indent=2))
        return

    print("[AIPL Conductor] Deterministic Worktree Arbitration Sequence:")
    print(f"  Disjoint Scopes: {'VALID (Scope(A) ∩ Scope(B) = ∅)' if report.is_disjoint else 'COLLISION DETECTED'}")
    print(f"  Conflict Count:  {report.conflict_count}")
    if not report.is_disjoint:
        if report.conflicting_file:
            print(f"  Conflicting File:   {report.conflicting_file}")
        if report.conflicting_symbol:
            print(f"  Conflicting Symbol: {report.conflicting_symbol}")
    print("\n  Topological Cherry-Pick Integration Sequence:")
    for step, agent in enumerate(report.merge_order, 1):
        print(f"    {step}. git cherry-pick {agent}")

def run_self_test() -> int:
    print("[tools/conductor.py] Running multi-agent conductor self-tests...")

    # Test 1: Disjoint Partitions
    p1 = AgentScopePartition("agent-ui", ["src/ui/hud.aipl"], ["drawHud"], 10)
    p2 = AgentScopePartition("agent-audio", ["src/audio/synth.aipl"], ["synthWav"], 20)
    p3 = AgentScopePartition("agent-net", ["src/net/http.aipl"], ["getHttp"], 5)
    rep1 = verify_disjoint_agent_contracts([p1, p2, p3])
    assert rep1.is_disjoint, "Test 1 Failed: Expected disjoint partitions"
    assert rep1.conflict_count == 0, "Test 1 Failed: Expected 0 conflicts"
    assert rep1.merge_order == ["agent-net", "agent-ui", "agent-audio"], f"Test 1 Failed: Expected merge order, got {rep1.merge_order}"
    print("  ✓ Test 1 Passed: Disjoint partitions & topological priority ordering")

    # Test 2: File Collision Detection
    p_bad_file = AgentScopePartition("agent-bad-file", ["src/ui/hud.aipl"], ["otherSymbol"], 15)
    rep2 = verify_disjoint_agent_contracts([p1, p_bad_file])
    assert not rep2.is_disjoint, "Test 2 Failed: Expected collision"
    assert rep2.conflict_count >= 1, "Test 2 Failed: Expected conflict count >= 1"
    assert "hud.aipl" in rep2.conflicting_file, f"Test 2 Failed: Expected conflicting file hud.aipl, got {rep2.conflicting_file}"
    print("  ✓ Test 2 Passed: File collision detected")

    # Test 3: Reserved Symbol Collision Detection
    p_bad_sym = AgentScopePartition("agent-bad-sym", ["src/other.aipl"], ["drawHud"], 25)
    rep3 = verify_disjoint_agent_contracts([p1, p_bad_sym])
    assert not rep3.is_disjoint, "Test 3 Failed: Expected collision"
    assert rep3.conflict_count >= 1, "Test 3 Failed: Expected conflict count >= 1"
    assert rep3.conflicting_symbol == "drawHud", f"Test 3 Failed: Expected conflicting symbol drawHud, got {rep3.conflicting_symbol}"
    print("  ✓ Test 3 Passed: AST reserved symbol collision detected")

    # Test 4: Manifest JSON serialization and parsing
    spec = {
        "partitions": [
            p1.to_dict(),
            p2.to_dict(),
            p3.to_dict()
        ]
    }
    parsed = parse_partition_spec(spec)
    rep4 = verify_disjoint_agent_contracts(parsed)
    assert rep4.is_disjoint, "Test 4 Failed: Spec parsing failed"
    print("  ✓ Test 4 Passed: Partition manifest JSON parsing")

    print("\nALL CONDUCTOR SELF-TESTS PASSED (4/4)!")
    return 0

def load_manifest(path: str) -> List[AgentScopePartition]:
    with open(path, "r", encoding="utf-8") as f:
        data = json.load(f)
    return parse_partition_spec(data)

def main():
    parser = argparse.ArgumentParser(description="AIPL Multi-Agent Concurrency Conductor & Worktree Arbiter")
    parser.add_argument("--verify-scopes", metavar="MANIFEST", nargs="?", const="", help="Verify Scope(A) ∩ Scope(B) = ∅")
    parser.add_argument("--arbitrate", metavar="MANIFEST", nargs="?", const="", help="Compute deterministic cherry-pick merge order")
    parser.add_argument("--self-test", action="store_true", help="Run comprehensive unit tests")
    parser.add_argument("--json", action="store_true", help="Output results in JSON format")
    parser.add_argument("manifest_pos", nargs="?", default="", help="Positional manifest JSON path")

    args = parser.parse_args()

    if args.self_test:
        sys.exit(run_self_test())

    manifest_file = args.verify_scopes or args.arbitrate or args.manifest_pos
    if not manifest_file:
        # Default self-test / demo if no manifest provided
        print("No manifest specified. Running --self-test...")
        sys.exit(run_self_test())

    if not os.path.exists(manifest_file):
        print(f"Error: manifest file '{manifest_file}' not found.", file=sys.stderr)
        sys.exit(1)

    try:
        partitions = load_manifest(manifest_file)
    except Exception as e:
        print(f"Error parsing manifest '{manifest_file}': {e}", file=sys.stderr)
        sys.exit(1)

    report = verify_disjoint_agent_contracts(partitions, check_ast_files=True)
    print_arbitration(report, json_mode=args.json)

    if not report.is_disjoint:
        sys.exit(1)
    sys.exit(0)

if __name__ == "__main__":
    main()
