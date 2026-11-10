package main

import (
	"fmt"
	"strings"
)

func formatGreeting(name string, role string, count int) string {
	return fmt.Sprintf("Hello, %s [%s]! Welcome #%d to AIPL.", name, role, count)
}

func parseCliArgs(args []string) map[string]string {
	opts := make(map[string]string)
	for _, a := range args {
		if strings.HasPrefix(a, "--") {
			parts := strings.SplitN(a[2:], "=", 2)
			if len(parts) == 2 {
				opts[parts[0]] = parts[1]
			}
		}
	}
	return opts
}

func main() {
	parsed := parseCliArgs([]string{"--name=Developer", "--role=Engineer"})
	user := "Developer"
	if val, ok := parsed["name"]; ok {
		user = val
	}
	role := "Engineer"
	if val, ok := parsed["role"]; ok {
		role = val
	}
	msg1 := formatGreeting(user, role, 1)
	msg2 := formatGreeting("Ada", "Architect", 42)
	if msg1 != "Hello, Developer [Engineer]! Welcome #1 to AIPL." {
		panic("assertion failed")
	}
	if msg2 != "Hello, Ada [Architect]! Welcome #42 to AIPL." {
		panic("assertion failed")
	}
	fmt.Println(msg1)
	fmt.Println(msg2)
	fmt.Println("BENCH_01_OK")
}
