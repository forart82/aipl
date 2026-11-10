interface ConfigRecord {
  service: string;
  port: number;
  tls: boolean;
  tags: string[];
}
function parseRecords(src: string): ConfigRecord[] {
  const out: ConfigRecord[] = [];
  for (const line of src.split("\n")) {
    const t = line.trim();
    if (t.length > 0 && !t.startsWith("#")) {
      const parts = t.split("|");
      if (parts.length >= 4) {
        out.push({
          service: parts[0].trim(),
          port: parseInt(parts[1].trim(), 10),
          tls: parts[2].trim() === "true",
          tags: parts[3].trim().split(","),
        });
      }
    }
  }
  return out;
}
function validateAndMutate(records: ConfigRecord[]): ConfigRecord[] {
  return records
    .filter((r) => r.service.length > 0 && r.port > 0 && r.port <= 65535)
    .map((r) => ({
      service: r.service,
      port: r.port + 100,
      tls: true,
      tags: [...r.tags.map((t) => t.trim()), "verified"],
    }));
}
const raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
const parsed = parseRecords(raw);
const valid = validateAndMutate(parsed);
const jsonOut = JSON.stringify(valid);
if (parsed.length !== 3 || valid.length !== 2 || !jsonOut.includes('"service":"auth"')) throw new Error("assert");
console.log(jsonOut + "\nBENCH_03_OK");
