package main

import (
	"fmt"
	"strconv"
	"strings"
)

type CliResult struct {
	exitCode int
	output   string
}

func executeCliCommand(args []string) CliResult {
	if len(args) == 0 || args[0] == "--help" || args[0] == "help" {
		return CliResult{0, "Usage: tool <stats|transform|pipeline> [options]"}
	}
	if args[0] == "stats" {
		var nums []int
		for _, a := range args[1:] {
			if strings.HasPrefix(a, "--values=") {
				for _, p := range strings.Split(a[9:], ",") {
					if n, err := strconv.Atoi(strings.TrimSpace(p)); err == nil {
						nums = append(nums, n)
					}
				}
			}
		}
		if len(nums) == 0 {
			return CliResult{2, "Error: --values required"}
		}
		sum := 0
		mn := nums[0]
		mx := nums[0]
		for _, n := range nums {
			sum += n
			if n < mn {
				mn = n
			}
			if n > mx {
				mx = n
			}
		}
		return CliResult{0, fmt.Sprintf("count=%d sum=%d min=%d max=%d", len(nums), sum, mn, mx)}
	}
	if args[0] == "pipeline" {
		text := ""
		upper := false
		rev := false
		for _, a := range args[1:] {
			if strings.HasPrefix(a, "--input=") {
				text = a[8:]
			} else if a == "--upper" {
				upper = true
			} else if a == "--reverse-words" {
				rev = true
			}
		}
		if len(text) == 0 {
			return CliResult{1, "Error: empty input"}
		}
		if upper {
			text = strings.ToUpper(text)
		}
		if rev {
			ws := strings.Fields(text)
			for i, j := 0, len(ws)-1; i < j; i, j = i+1, j-1 {
				ws[i], ws[j] = ws[j], ws[i]
			}
			text = strings.Join(ws, " ")
		}
		return CliResult{0, text}
	}
	return CliResult{127, fmt.Sprintf("Unknown subcommand: %s", args[0])}
}

func main() {
	r1 := executeCliCommand([]string{"--help"})
	r2 := executeCliCommand([]string{"stats", "--values=10,25,5,40"})
	r3 := executeCliCommand([]string{"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"})
	r4 := executeCliCommand([]string{"unknown_cmd"})
	if r1.exitCode != 0 || r2.exitCode != 0 || r3.exitCode != 0 || r4.exitCode != 127 {
		panic("assert exit codes")
	}
	fmt.Printf("%s | %s\nBENCH_06_OK\n", r2.output, r3.output)
}
