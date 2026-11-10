class ConfigRecord {
  constructor(service, port, tls, tags) {
    this.service = service;
    this.port = port;
    this.tls = tls;
    this.tags = tags;
  }
}

function parseRecords(src) {
  const records = [];
  for (const line of src.split("\n")) {
    const t = line.trim();
    if (t && !t.startsWith("#")) {
      const parts = t.split("|").map((p) => p.trim());
      if (parts.length >= 4) {
        const tags = parts[3].split(",").map((t) => t.trim());
        records.push(new ConfigRecord(parts[0], parseInt(parts[1], 10), parts[2] === "true", tags));
      }
    }
  }
  return records;
}

function validateAndMutate(records) {
  const valid = [];
  for (const r of records) {
    if (r.service && r.port > 0 && r.port <= 65535) {
      const tags = r.tags.map((t) => t.trim());
      tags.push("verified");
      valid.push(new ConfigRecord(r.service, r.port + 100, true, tags));
    }
  }
  return valid;
}

function serializeJson(records) {
  const items = records.map((r) => {
    const qtags = r.tags.map((t) => `"${t}"`).join(",");
    return `{"service":"${r.service}","port":${r.port},"tls":${r.tls},"tags":[${qtags}]}`;
  });
  return "[" + items.join(",") + "]";
}

const raw = "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n";
const parsed = parseRecords(raw);
const valid = validateAndMutate(parsed);
const jsonOut = serializeJson(valid);
if (parsed.length !== 3 || valid.length !== 2 || !jsonOut.includes('"service":"auth"')) {
  throw new Error("assert");
}
console.log(jsonOut + "\nBENCH_03_OK");
