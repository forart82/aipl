#!/usr/bin/env bash
set -euo pipefail

# Usage: ./bundle_aipl.sh [search_directory] [output_file]
SEARCH_DIR="${1:-.}"
OUTPUT_FILE="${2:-aipl_bundle.txt}"

# Resolve absolute paths to prevent the script from reading its own output file
SEARCH_DIR_ABS="$(cd "$SEARCH_DIR" && pwd)"
mkdir -p "$(dirname "$OUTPUT_FILE")"
OUTPUT_FILE_ABS="$(cd "$(dirname "$OUTPUT_FILE")" && pwd)/$(basename "$OUTPUT_FILE")"

# Initialize the output file with a global header
{
    echo "================================================================================"
    echo " AIPL CONCATENATED BUNDLE"
    echo " Source Directory : $SEARCH_DIR_ABS"
    echo " Generated On     : $(date -u '+%Y-%m-%d %H:%M:%S UTC')"
    echo "================================================================================"
    echo ""
} > "$OUTPUT_FILE_ABS"

count=0

# Find all *.aipl files, sort them deterministically, and handle spaces in filenames safely
while IFS= read -r -d '' file; do
    # Compute clean relative path for the section header
    rel_path="${file#"$SEARCH_DIR_ABS"/}"

    {
        echo "/* =========================================================================="
        echo " * FILE: $rel_path"
        echo " * ========================================================================== */"
        cat "$file"
        echo ""
        echo ""
    } >> "$OUTPUT_FILE_ABS"

    count=$((count + 1))
done < <(find "$SEARCH_DIR_ABS" -type f -name "*.aipl" ! -path "$OUTPUT_FILE_ABS" -print0 | sort -z)

echo "Done! Concatenated $count .aipl file(s) into: $OUTPUT_FILE_ABS"
