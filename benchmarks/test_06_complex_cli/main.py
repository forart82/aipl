from dataclasses import dataclass

@dataclass
class CliResult:
    exitCode: int
    output: str

def executeCliCommand(args: list[str]) -> CliResult:
    if not args or args[0] == "--help" or args[0] == "help":
        return CliResult(0, "Usage: tool <stats|transform|pipeline> [options]")
    if args[0] == "stats":
        nums: list[int] = []
        for a in args[1:]:
            if a.startswith("--values="):
                for p in a[9:].split(","):
                    p = p.strip()
                    if p:
                        nums.append(int(p))
        if not nums:
            return CliResult(2, "Error: --values required")
        count = len(nums)
        s = sum(nums)
        mn = min(nums)
        mx = max(nums)
        return CliResult(0, f"count={count} sum={s} min={mn} max={mx}")
    if args[0] == "pipeline":
        text = ""
        upper = False
        rev = False
        for a in args[1:]:
            if a.startswith("--input="):
                text = a[8:]
            elif a == "--upper":
                upper = True
            elif a == "--reverse-words":
                rev = True
        if not text:
            return CliResult(1, "Error: empty input")
        if upper:
            text = text.upper()
        if rev:
            text = " ".join(reversed(text.split()))
        return CliResult(0, text)
    return CliResult(127, f"Unknown subcommand: {args[0]}")

r1 = executeCliCommand(["--help"])
r2 = executeCliCommand(["stats", "--values=10,25,5,40"])
r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"])
r4 = executeCliCommand(["unknown_cmd"])
assert r1.exitCode == 0
assert r2.exitCode == 0 and r2.output == "count=4 sum=80 min=5 max=40"
assert r3.exitCode == 0 and r3.output == "CLI NATIVE FAST AIPL"
assert r4.exitCode == 127
print(f"{r2.output} | {r3.output}\nBENCH_06_OK")
