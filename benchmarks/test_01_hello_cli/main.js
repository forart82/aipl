function formatGreeting(name, role, count) {
  return `Hello, ${name} [${role}]! Welcome #${count} to AIPL.`;
}

function parseCliArgs(args) {
  const opts = {};
  for (const a of args) {
    if (a.startsWith("--") && a.includes("=")) {
      const parts = a.slice(2).split("=");
      opts[parts[0]] = parts[1];
    }
  }
  return opts;
}

const parsed = parseCliArgs(["--name=Developer", "--role=Engineer"]);
const user = parsed.name || "Developer";
const role = parsed.role || "Engineer";
const msg1 = formatGreeting(user, role, 1);
const msg2 = formatGreeting("Ada", "Architect", 42);
if (msg1 !== "Hello, Developer [Engineer]! Welcome #1 to AIPL.") {
  throw new Error("assert");
}
if (msg2 !== "Hello, Ada [Architect]! Welcome #42 to AIPL.") {
  throw new Error("assert");
}
console.log(msg1 + "\n" + msg2 + "\nBENCH_01_OK");
