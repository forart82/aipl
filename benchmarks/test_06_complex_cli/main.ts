interface CliResult {
  exitCode: number;
  output: string;
}

function executeCliCommand(args: string[]): CliResult {
  if (args.length === 0 || args[0] === "--help" || args[0] === "help") {
    return { exitCode: 0, output: "Usage: tool <stats|transform|pipeline> [options]" };
  }
  if (args[0] === "stats") {
    const nums: number[] = [];
    for (const a of args.slice(1)) {
      if (a.startsWith("--values=")) {
        for (const p of a.slice(9).split(",")) {
          nums.push(parseInt(p.trim(), 10));
        }
      }
    }
    if (nums.length === 0) {
      return { exitCode: 2, output: "Error: --values required" };
    }
    const sum = nums.reduce((a, b) => a + b, 0);
    const mn = Math.min(...nums);
    const mx = Math.max(...nums);
    return { exitCode: 0, output: `count=${nums.length} sum=${sum} min=${mn} max=${mx}` };
  }
  if (args[0] === "pipeline") {
    let text = "";
    let upper = false;
    let rev = false;
    for (const a of args.slice(1)) {
      if (a.startsWith("--input=")) {
        text = a.slice(8);
      } else if (a === "--upper") {
        upper = true;
      } else if (a === "--reverse-words") {
        rev = true;
      }
    }
    if (!text) {
      return { exitCode: 1, output: "Error: empty input" };
    }
    if (upper) {
      text = text.toUpperCase();
    }
    if (rev) {
      text = text.split(" ").reverse().join(" ");
    }
    return { exitCode: 0, output: text };
  }
  return { exitCode: 127, output: `Unknown subcommand: ${args[0]}` };
}

const r1 = executeCliCommand(["--help"]);
const r2 = executeCliCommand(["stats", "--values=10,25,5,40"]);
const r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
const r4 = executeCliCommand(["unknown_cmd"]);
if (r1.exitCode !== 0 || r2.exitCode !== 0 || r2.output !== "count=4 sum=80 min=5 max=40" || r3.exitCode !== 0 || r3.output !== "CLI NATIVE FAST AIPL" || r4.exitCode !== 127) {
  throw new Error("assert");
}
console.log(`${r2.output} | ${r3.output}\nBENCH_06_OK`);
