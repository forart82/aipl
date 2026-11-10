#!/usr/bin/env bash
# ==============================================================================
# AIPL 4-Layer Defense-in-Depth Filesystem Shield - Pre-Commit Guard
# ADR-0008: Validates SSOT cryptographic manifest & chmod 0444 kernel locks
# ==============================================================================
set -euo pipefail

REPO_ROOT="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
MANIFEST="$REPO_ROOT/.aipl/manifest.sha256"

if [ ! -f "$MANIFEST" ]; then
    echo ":: [AIPL Shield] No manifest found at .aipl/manifest.sha256. Skipping pre-commit guard."
    exit 0
fi

echo ":: [AIPL Shield] Verifying Layer 4 Cryptographic SSOT Manifest & Layer 1 Permissions..."

# 1. Prefer compiled aipl CLI in bin/, PATH, or environment
AIPL_BIN=""
if [ -x "$REPO_ROOT/bin/aipl" ]; then
    AIPL_BIN="$REPO_ROOT/bin/aipl"
elif command -v aipl >/dev/null 2>&1; then
    AIPL_BIN="aipl"
fi

if [ -n "$AIPL_BIN" ]; then
    if ! "$AIPL_BIN" shield verify; then
        echo ":: [AIPL Shield FATAL] Pre-commit rejected: SSOT integrity or permissions violation detected!" >&2
        exit 1
    fi
    echo ":: [AIPL Shield] Pre-commit integrity check PASSED."
    exit 0
fi

# 2. Portable fallback using standard POSIX/GNU tools
cd "$REPO_ROOT"
FAILED=0

# Check SHA-256 digests
if command -v sha256sum >/dev/null 2>&1; then
    if ! grep -v '^#' "$MANIFEST" | sha256sum -c --status -; then
        echo ":: [AIPL Shield ERROR] SHA-256 checksum divergence in SSOT files!" >&2
        grep -v '^#' "$MANIFEST" | sha256sum -c - || true
        FAILED=1
    fi
elif command -v shasum >/dev/null 2>&1; then
    if ! grep -v '^#' "$MANIFEST" | shasum -a 256 -c -s -; then
        echo ":: [AIPL Shield ERROR] SHA-256 checksum divergence in SSOT files!" >&2
        grep -v '^#' "$MANIFEST" | shasum -a 256 -c - || true
        FAILED=1
    fi
else
    echo ":: [AIPL Shield WARNING] Neither sha256sum nor shasum available; cannot verify hashes." >&2
fi

# Check file permissions (ensure no write bits)
while IFS= read -r line || [ -n "$line" ]; do
    [[ "$line" =~ ^[[:space:]]*# ]] && continue
    [[ -z "${line// }" ]] && continue
    file_rel=$(echo "$line" | awk '{print $2}')
    file_path="$REPO_ROOT/$file_rel"
    if [ -f "$file_path" ]; then
        if [ -w "$file_path" ]; then
            echo ":: [AIPL Shield ERROR] File '$file_rel' is writable! Expected chmod 0444 read-only lock." >&2
            FAILED=1
        fi
    else
        echo ":: [AIPL Shield ERROR] Manifest references missing file: '$file_rel'!" >&2
        FAILED=1
    fi
done < "$MANIFEST"

if [ "$FAILED" -ne 0 ]; then
    echo ":: [AIPL Shield FATAL] Pre-commit commit blocked by 4-Layer Defense-in-Depth Shield." >&2
    echo ":: Hint: Run 'aipl shield lock' to regenerate manifest or restore locks." >&2
    exit 1
fi

# Keep global binaries synchronized
if [ -f "$REPO_ROOT/bin/aipl" ]; then
    mkdir -p "$HOME/.local/bin" "$HOME/.cargo/bin"
    cp "$REPO_ROOT/bin/aipl" "$HOME/.local/bin/aipl"
    chmod +x "$HOME/.local/bin/aipl"
    cp "$REPO_ROOT/bin/aipl" "$HOME/.cargo/bin/aipl"
    chmod +x "$HOME/.cargo/bin/aipl"
fi

echo ":: [AIPL Shield] Pre-commit integrity check PASSED."
exit 0
