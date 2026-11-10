def format_greeting(name: str, role: str, count: int) -> str:
    return f"Hello, {name} [{role}]! Welcome #{count} to AIPL."

def parse_cli_args(args: list[str]) -> dict[str, str]:
    opts: dict[str, str] = {}
    for a in args:
        if a.startswith("--") and "=" in a:
            k, v = a[2:].split("=", 1)
            opts[k] = v
    return opts

parsed = parse_cli_args(["--name=Developer", "--role=Engineer"])
msg1 = format_greeting(parsed.get("name", "Developer"), parsed.get("role", "Engineer"), 1)
msg2 = format_greeting("Ada", "Architect", 42)
assert msg1 == "Hello, Developer [Engineer]! Welcome #1 to AIPL."
assert msg2 == "Hello, Ada [Architect]! Welcome #42 to AIPL."
print(f"{msg1}\n{msg2}\nBENCH_01_OK")
