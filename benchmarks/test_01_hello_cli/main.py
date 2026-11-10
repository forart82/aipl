def formatGreeting(name: str, role: str, count: int) -> str:
    return f"Hello, {name} [{role}]! Welcome #{count} to AIPL."

def parseCliArgs(args: list[str]) -> dict[str, str]:
    opts: dict[str, str] = {}
    for a in args:
        if a.startswith("--") and "=" in a:
            parts = a[2:].split("=", 1)
            opts[parts[0]] = parts[1]
    return opts

parsed = parseCliArgs(["--name=Developer", "--role=Engineer"])
user = parsed.get("name", "Developer")
role = parsed.get("role", "Engineer")
msg1 = formatGreeting(user, role, 1)
msg2 = formatGreeting("Ada", "Architect", 42)
assert msg1 == "Hello, Developer [Engineer]! Welcome #1 to AIPL."
assert msg2 == "Hello, Ada [Architect]! Welcome #42 to AIPL."
print(f"{msg1}\n{msg2}\nBENCH_01_OK")
