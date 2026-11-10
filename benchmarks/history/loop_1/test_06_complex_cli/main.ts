interface CliResult { exitCode: number; output: string; }
function executeCliCommand(args: string[]): CliResult {
  if (args.length === 0 || args[0] === "--help") return { exitCode: 0, output: "Usage: tool" };
  if (args[0] === "stats") {
    const nums: number[] = [];
    for (const a of args.slice(1)) {
      if (a.startsWith("--values=")) a.slice(9).split(",").forEach((p) => nums.push(parseInt(p.trim(), 10)));
    }
    const sum = nums.reduce((a, b) => a + b, 0);
    return { exitCode: 0, output: `count=${nums.length} sum=${sum} min=${Math.min(...nums)} max=${Math.max(...nums)}` };
  }
  if (args[0] === "pipeline") {
    let text = "", upper = false, rev = false;
    for (const a of args.slice(1)) {
      if (a.startsWith("--input=")) text = a.slice(8);
      else if (a === "--upper") upper = true;
      else if (a === "--reverse-words") rev = true;
    }
    if (upper) text = text.toUpperCase();
    if (rev) text = text.split(" ").reverse().join(" ");
    return { exitCode: 0, output: text };
  }
  return { exitCode: 127, output: "Unknown" };
}
const r2 = executeCliCommand(["stats", "--values=10,25,5,40"]);
const r3 = executeCliCommand(["pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"]);
if (r2.output !== "count=4 sum=80 min=5 max=40" || r3.output !== "CLI NATIVE FAST AIPL") throw new Error("assert");
console.log(`${r2.output} | ${r3.output}\nBENCH_06_OK`);
