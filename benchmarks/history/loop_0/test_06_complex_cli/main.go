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
	if len(args) == 0 || args[0] == "--help" {
		return CliResult{0, "Usage: tool <stats|transform|pipeline> [options]"}
	}
	switch args[0] {
	case "stats":
		var nums []int
		for _, a := range args[1:] {
			if strings.HasPrefix(a, "--values=") {
				for _, p := range strings.Split(a[9:], ",") {
					n, _ := strconv.Atoi(strings.TrimSpace(p))
					nums = append(nums, n)
				}
			}
		}
		sum, minV, maxV := 0, nums[0], nums[0]
		for _, n := range nums {
			sum += n
			if n < minV { minV = n }
			if n > maxV { maxV = n }
		}
		return CliResult{0, fmt.Sprintf("count=%d sum=%d min=%d max=%d", len(nums), sum, minV, maxV)}
	case "pipeline":
		text, upper, rev := "", false, false
		for _, a := range args[1:] {
			if strings.HasPrefix(a, "--input=") { text = a[8:] }
			if a == "--upper" { upper = true }
			if a == "--reverse-words" { rev = true }
		}
		if upper { text = strings.ToUpper(text) }
		if rev {
			w := strings.Fields(text)
			for i, j := 0, len(w)-1; i < j; i, j = i+1, j-1 { w[i], w[j] = w[j], w[i] }
			text = strings.Join(w, " ")
		}
		return CliResult{0, text}
	}
	return CliResult{127, "Unknown"}
}

func main() {
	r2 := executeCliCommand([]string{"stats", "--values=10,25,5,40"})
	r3 := executeCliCommand([]string{"pipeline", "--input=aipl fast native cli", "--upper", "--reverse-words"})
	if r2.output != "count=4 sum=80 min=5 max=40" || r3.output != "CLI NATIVE FAST AIPL" { panic("assert") }
	fmt.Printf("%s | %s\nBENCH_06_OK\n", r2.output, r3.output)
}
