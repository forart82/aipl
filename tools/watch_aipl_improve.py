#!/usr/bin/env python3
"""
Continuous Watcher & Checklist Synchronizer for aipl_improve.md.

Monitors aipl_improve.md for content changes (by SHA-256 and mtime),
extracts any newly added Pain Points (Section 3) or Improvement Proposals (Section 4),
and synchronizes them into AIPL_IMPROVE_CHECKLIST.md without running
any git commit or git push operations.
"""

import argparse
import datetime
import hashlib
import os
from pathlib import Path
import re
import sys
import time

REPO_ROOT = Path(__file__).resolve().parent.parent
DEFAULT_SOURCE = os.environ.get("AIPL_IMPROVE_SOURCE", str(REPO_ROOT.parent / "aipl_dog" / "aipl_improve.md"))
DEFAULT_CHECKLIST = os.environ.get("AIPL_IMPROVE_CHECKLIST", str(REPO_ROOT / "AIPL_IMPROVE_CHECKLIST.md"))

def compute_sha256(path: str) -> str:
    h = hashlib.sha256()
    with open(path, "rb") as f:
        while True:
            chunk = f.read(65536)
            if not chunk:
                break
            h.update(chunk)
    return h.hexdigest()


def extract_findings_and_proposals(md_text: str) -> list[tuple[str, str]]:
    """Extracts numbered pain points and ### Proposal headings from aipl_improve.md."""
    entries: list[tuple[str, str]] = []
    for m in re.finditer(r"^\d+\.\s+\*\*([^*]+)\*\*", md_text, flags=re.MULTILINE):
        title = m.group(1).strip().rstrip(":")
        entries.append(("Pain Point", title))
    for m in re.finditer(r"^###\s+(Proposal\s+\d+[^\n]*)", md_text, flags=re.MULTILINE):
        title = m.group(1).strip()
        entries.append(("Proposal", title))
    return entries


def sync_checklist_once(source_path: str, checklist_path: str) -> bool:
    if not os.path.isfile(source_path):
        return False

    digest = compute_sha256(source_path)
    src_text = open(source_path, "r", encoding="utf-8").read()
    checklist_text = (
        open(checklist_path, "r", encoding="utf-8").read()
        if os.path.isfile(checklist_path)
        else ""
    )

    if f"`{digest}`" in checklist_text:
        return False

    entries = extract_findings_and_proposals(src_text)
    new_items = []
    for kind, title in entries:
        # Check if core keywords of the title are already tracked in the checklist
        norm_key = re.sub(r"\s+", " ", title)[:40]
        if norm_key not in checklist_text:
            new_items.append((kind, title))

    now_iso = datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")
    updated = re.sub(
        r"(- \*\*Tracked SHA-256\*\*: `)[0-9a-fA-F]+(`)",
        rf"\g<1>{digest}\g<2>",
        checklist_text,
    )

    log_lines = [
        f"- `{now_iso}` — Detected update in `{source_path}` (`sha256: {digest}`). "
        f"New untriaged items queued: `{len(new_items)}`."
    ]
    for kind, title in new_items:
        log_lines.append(f"  - [ ] **[NEEDS_TRIAGE: FIXED | ALREADY_SUPPORTED | REJECTED]** ({kind}) {title}")

    marker = "<!-- AUTO_WATCHER_ENTRIES_END -->"
    if marker in updated:
        updated = updated.replace(marker, "\n".join(log_lines) + "\n" + marker)
    else:
        updated += "\n" + "\n".join(log_lines) + "\n"

    with open(checklist_path, "w", encoding="utf-8") as f:
        f.write(updated)
    return True


def main() -> int:
    parser = argparse.ArgumentParser(description="Watch aipl_improve.md and sync AIPL_IMPROVE_CHECKLIST.md")
    parser.add_argument("--source", default=DEFAULT_SOURCE, help="Path to aipl_improve.md")
    parser.add_argument("--checklist", default=DEFAULT_CHECKLIST, help="Path to AIPL_IMPROVE_CHECKLIST.md")
    parser.add_argument("--interval", type=float, default=2.0, help="Polling interval in seconds")
    parser.add_argument("--once", action="store_true", help="Run a single check and exit")
    args = parser.parse_args()

    changed = sync_checklist_once(args.source, args.checklist)
    if args.once:
        print(f"[watch_aipl_improve] Checked {args.source} -> updated={changed}")
        return 0

    print(f"[watch_aipl_improve] Watching {args.source} every {args.interval}s -> {args.checklist}")
    try:
        while True:
            if sync_checklist_once(args.source, args.checklist):
                print(f"[watch_aipl_improve] Synced update from {args.source} into {args.checklist}")
            time.sleep(args.interval)
    except KeyboardInterrupt:
        return 0


if __name__ == "__main__":
    sys.exit(main())
