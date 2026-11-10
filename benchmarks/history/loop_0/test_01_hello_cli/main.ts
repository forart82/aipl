function formatGreeting(name: string, role: string, count: number): string {
  return `Hello, ${name} [${role}]! Welcome #${count} to AIPL.`;
}
function parseCliArgs(args: string[]): Record<string, string> {
  const opts: Record<string, string> = {};
  for (const a of args) {
    if (a.startsWith("--") && a.includes("=")) {
      const [k, v] = a.slice(2).split("=");
      opts[k] = v;
    }
  }
  return opts;
}
const parsed = parseCliArgs(["--name=Developer", "--role=Engineer"]);
const msg1 = formatGreeting(parsed["name"] ?? "Developer", parsed["role"] ?? "Engineer", 1);
const msg2 = formatGreeting("Ada", "Architect", 42);
if (msg1 !== "Hello, Developer [Engineer]! Welcome #1 to AIPL.") throw new Error("assert");
if (msg2 !== "Hello, Ada [Architect]! Welcome #42 to AIPL.") throw new Error("assert");
console.log(msg1 + "\n" + msg2 + "\nBENCH_01_OK");
