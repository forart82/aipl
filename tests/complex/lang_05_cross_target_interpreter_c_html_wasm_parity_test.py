import subprocess
import pytest

def test_lang_05_cross_target_parity():
    # Run the AIPL test suite for lang_05
    res = subprocess.run(["./bin/aipl", "test", "tests/complex/lang_05_cross_target_interpreter_c_html_wasm_parity_test.aipl"], capture_output=True, text=True)
    assert res.returncode == 0, f"AIPL test failed:\n{res.stdout}\n{res.stderr}"
