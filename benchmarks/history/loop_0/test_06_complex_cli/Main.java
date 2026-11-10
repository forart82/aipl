import java.util.*;

public class Main {
    static class CliResult { int exitCode; String output; CliResult(int c, String o) { exitCode = c; output = o; } }
    static CliResult executeCliCommand(String... args) {
        if (args.length == 0 || args[0].equals("--help")) return new CliResult(0, "Usage: tool");
        if (args[0].equals("stats")) {
            List<Integer> nums = new ArrayList<>();
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--values=")) {
                    for (String p : args[i].substring(9).split(",")) nums.add(Integer.parseInt(p.trim()));
                }
            }
            int sum = 0, minV = nums.get(0), maxV = nums.get(0);
            for (int n : nums) { sum += n; minV = Math.min(minV, n); maxV = Math.max(maxV, n); }
            return new CliResult(0, "count=" + nums.size() + " sum=" + sum + " min=" + minV + " max=" + maxV);
        }
        if (args[0].equals("pipeline")) {
            String text = ""; boolean upper = false, rev = false;
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--input=")) text = args[i].substring(8);
                else if (args[i].equals("--upper")) upper = true;
                else if (args[i].equals("--reverse-words")) rev = true;
            }
            if (upper) text = text.toUpperCase();
            if (rev) {
                List<String> ws = Arrays.asList(text.split(" "));
                Collections.reverse(ws);
                text = String.join(" ", ws);
            }
            return new CliResult(0, text);
        }
        return new CliResult(127, "Unknown");
    }
    public static void main(String[] args) {
        CliResult r2 = executeCliCommand("stats", "--values=10,25,5,40");
        CliResult r3 = executeCliCommand("pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words");
        if (!r2.output.equals("count=4 sum=80 min=5 max=40") || !r3.output.equals("CLI NATIVE FAST AIPL")) throw new AssertionError();
        System.out.println(r2.output + " | " + r3.output + "\nBENCH_06_OK");
    }
}
