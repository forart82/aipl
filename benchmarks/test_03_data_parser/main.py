from dataclasses import dataclass

@dataclass
class ConfigRecord:
    service: str
    port: int
    tls: bool
    tags: list[str]

def parseRecords(src: str) -> list[ConfigRecord]:
    records: list[ConfigRecord] = []
    for line in src.splitlines():
        line = line.strip()
        if line and not line.startswith("#"):
            parts = [p.strip() for p in line.split("|")]
            if len(parts) >= 4:
                tags = [t.strip() for t in parts[3].split(",")]
                records.append(ConfigRecord(parts[0], int(parts[1]), parts[2] == "true", tags))
    return records

def validateAndMutate(records: list[ConfigRecord]) -> list[ConfigRecord]:
    valid: list[ConfigRecord] = []
    for r in records:
        if r.service and 0 < r.port <= 65535:
            tags = [t.strip() for t in r.tags]
            tags.append("verified")
            valid.append(ConfigRecord(r.service, r.port + 100, True, tags))
    return valid

def serializeJson(records: list[ConfigRecord]) -> str:
    items: list[str] = []
    for r in records:
        qtags = ",".join(f'"{t}"' for t in r.tags)
        tls_str = "true" if r.tls else "false"
        items.append(f'{{"service":"{r.service}","port":{r.port},"tls":{tls_str},"tags":[{qtags}]}}')
    return "[" + ",".join(items) + "]"

raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n"
parsed = parseRecords(raw)
valid = validateAndMutate(parsed)
jsonOut = serializeJson(valid)
assert len(parsed) == 3
assert len(valid) == 2
assert '"service":"auth"' in jsonOut
print(jsonOut + "\nBENCH_03_OK")
