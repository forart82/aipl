import java.util.*;

public class Main {
    static class CliResult {
        int exitCode;
        String output;
        CliResult(int c, String o) {
            exitCode = c;
            output = o;
        }
    }

    static CliResult executeCliCommand(String[] args) {
        if (args.length == 0 || args[0].equals("--help") || args[0].equals("help")) {
            return new CliResult(0, "Usage: tool <stats|transform|pipeline> [options]");
        }
        if (args[0].equals("stats")) {
            List<Integer> nums = new ArrayList<>();
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--values=")) {
                    for (String p : args[i].substring(9).split(",")) {
                        nums.add(Integer.parseInt(p.trim()));
                    }
                }
            }
            if (nums.isEmpty()) {
                return new CliResult(2, "Error: --values required");
            }
            int sum = 0;
            int mn = nums.get(0);
            int mx = nums.get(0);
            for (int n : nums) {
                sum += n;
                if (n < mn) mn = n;
                if (n > mx) mx = n;
            }
            return new CliResult(0, "count=" + nums.size() + " sum=" + sum + " min=" + mn + " max=" + mx);
        }
        if (args[0].equals("pipeline")) {
            String text = "";
            boolean upper = false;
            boolean rev = false;
            for (int i = 1; i < args.length; i++) {
                if (args[i].startsWith("--input=")) {
                    text = args[i].substring(8);
                } else if (args[i].equals("--upper")) {
                    upper = true;
                } else if (args[i].equals("--reverse-words")) {
                    rev = true;
                }
            }
            if (text.isEmpty()) {
                return new CliResult(1, "Error: empty input");
            }
            if (upper) {
                text = text.toUpperCase();
            }
            if (rev) {
                String[] ws = text.split("\\s+");
                Collections.reverse(Arrays.asList(ws));
                text = String.join(" ", ws);
            }
            return new CliResult(0, text);
        }
        return new CliResult(127, "Unknown subcommand: " + args[0]);
    }

    public static void main(String[] args) {
        CliResult r1 = executeCliCommand(new String[]{"--help"});
        CliResult r2 = executeCliCommand(new String[]{"stats", "--values=10,25,5,40"});
        CliResult r3 = executeCliCommand(new String[]{"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"});
        CliResult r4 = executeCliCommand(new String[]{"unknown_cmd"});
        if (r1.exitCode != 0 || r2.exitCode != 0 || !r2.output.equals("count=4 sum=80 min=5 max=40") || r3.exitCode != 0 || !r3.output.equals("CLI NATIVE FAST AIPL") || r4.exitCode != 127) {
            throw new AssertionError();
        }
        System.out.println(r2.output + " | " + r3.output + "\nBENCH_06_OK");
    }
}
