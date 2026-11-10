def execute_cli_command(args: list[str]) -> tuple[int, str]:
    if not args or args[0] == "--help":
        return 0, "Usage: tool"
    if args[0] == "stats":
        nums = [int(p.strip()) for a in args[1:] if a.startswith("--values=") for p in a[9:].split(",")]
        return 0, f"count={len(nums)} sum={sum(nums)} min={min(nums)} max={max(nums)}"
    if args[0] == "pipeline":
        text = next((a[8:] for a in args[1:] if a.startswith("--input=")), "")
        if "--upper" in args: text = text.upper()
        if "--reverse-words" in args: text = " ".join(reversed(text.split(" ")))
        return 0, text
    return 127, "Unknown"

_, o2 = execute_cli_command(["stats", "--values=10,25,5,40"])
_, o3 = execute_cli_command(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"])
assert o2 == "count=4 sum=80 min=5 max=40" and o3 == "CLI NATIVE FAST AIPL"
print(f"{o2} | {o3}\nBENCH_06_OK")
