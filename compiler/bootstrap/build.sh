#!/usr/bin/env bash
# ==============================================================================
# AIPL cold-start bootstrap (no pre-existing aipl binary required).
#
# Compiles the split modular runtime (runtime/rt_*.c) and the 16 fixed-point compiler
# shards (compiler/bootstrap/shards/mod_*.c, emitted by `aipl bootstrap`) in parallel with
# the host C compiler, then links bin/aipl. Afterwards run `./bin/aipl bootstrap` to verify
# the 3-stage fixed point.
# ==============================================================================
set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
cd "$REPO_ROOT"

CC="${CC:-cc}"
NPROC="$(getconf _NPROCESSORS_ONLN 2>/dev/null || echo 4)"
DEFAULT_JOBS=$(( NPROC > 2 ? (NPROC - 2 > 14 ? 14 : NPROC - 2) : NPROC ))
JOBS="${AIPL_JOBS:-$DEFAULT_JOBS}"
OUT="${1:-bin/aipl}"
OBJ_DIR="$(mktemp -d "${TMPDIR:-/tmp}/aipl-coldstart.XXXXXX")"
trap 'rm -f "$OBJ_DIR"/*.o; rmdir "$OBJ_DIR" 2>/dev/null || true' EXIT

SHARD_DIR=compiler/bootstrap/shards
CFLAGS="-std=c99 -O2 -pipe -pthread -w -I runtime -I $SHARD_DIR"
SOURCES=(runtime/rt_core.c runtime/rt_crypto_data.c runtime/rt_sys.c)
# The compiler itself is headless; include the GUI/audio module only if the shards opt in.
if grep -q "AIPL_ENABLE_GUI_AUDIO" "$SHARD_DIR/common.h"; then
  CFLAGS="$CFLAGS -DAIPL_ENABLE_GUI_AUDIO=1"
  SOURCES+=(runtime/rt_gui_audio.c)
fi
SOURCES+=("$SHARD_DIR"/mod_*.c)

# CC/CFLAGS/OBJ_DIR travel through the environment so quotes in them cannot break the script.
export AIPL_CC="$CC" AIPL_CFLAGS="$CFLAGS" AIPL_OBJ_DIR="$OBJ_DIR"
printf '%s\0' "${SOURCES[@]}" | xargs -0 -P "$JOBS" -n 1 sh -c \
  'obj="$AIPL_OBJ_DIR/$(printf "%s" "$1" | tr "/" "_").o"; $AIPL_CC $AIPL_CFLAGS -c "$1" -o "$obj"' _

mkdir -p "$(dirname "$OUT")"
"$CC" -pthread "$OBJ_DIR"/*.o -o "$OUT" -lm -ldl -lpthread
echo "AIPL cold-start compiler built: $OUT"
