import json

def parse_records(src: str) -> list[dict]:
    out = []
    for line in src.splitlines():
        t = line.strip()
        if t and not t.startswith("#"):
            parts = [p.strip() for p in t.split("|")]
            if len(parts) >= 4:
                out.append({"service": parts[0], "port": int(parts[1]), "tls": parts[2] == "true", "tags": parts[3].split(",")})
    return out

def validate_and_mutate(records: list[dict]) -> list[dict]:
    return [
        {"service": r["service"], "port": r["port"] + 100, "tls": True, "tags": [t.strip() for t in r["tags"]] + ["verified"]}
        for r in records if r["service"] and 0 < r["port"] <= 65535
    ]

raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n"
parsed = parse_records(raw)
valid = validate_and_mutate(parsed)
json_out = json.dumps(valid, separators=(",", ":"))
assert len(parsed) == 3 and len(valid) == 2 and '"service":"auth"' in json_out
print(json_out + "\nBENCH_03_OK")
