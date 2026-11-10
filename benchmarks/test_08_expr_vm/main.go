package main

import (
	"fmt"
	"strconv"
	"strings"
)

func precedence(op string) int {
	if op == "*" || op == "/" {
		return 3
	}
	if op == "+" || op == "-" {
		return 2
	}
	if op == ">" || op == "==" {
		return 1
	}
	return 0
}

func compileInfixToRpn(expr string) []string {
	var out []string
	var ops []string
	tokens := strings.Fields(expr)
	for _, token := range tokens {
		if token == "(" {
			ops = append(ops, token)
		} else if token == ")" {
			for len(ops) > 0 && ops[len(ops)-1] != "(" {
				out = append(out, ops[len(ops)-1])
				ops = ops[:len(ops)-1]
			}
			if len(ops) > 0 {
				ops = ops[:len(ops)-1]
			}
		} else if precedence(token) > 0 {
			for len(ops) > 0 && precedence(ops[len(ops)-1]) >= precedence(token) {
				out = append(out, ops[len(ops)-1])
				ops = ops[:len(ops)-1]
			}
			ops = append(ops, token)
		} else {
			out = append(out, token)
		}
	}
	for len(ops) > 0 {
		out = append(out, ops[len(ops)-1])
		ops = ops[:len(ops)-1]
	}
	return out
}

func evalRpnVm(tokens []string, env map[string]int) int {
	var stack []int
	for _, token := range tokens {
		if precedence(token) > 0 {
			b := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			a := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			switch token {
			case "+":
				stack = append(stack, a+b)
			case "-":
				stack = append(stack, a-b)
			case "*":
				stack = append(stack, a*b)
			case "/":
				if b == 0 {
					panic("division by zero")
				}
				stack = append(stack, a/b)
			case ">":
				if a > b {
					stack = append(stack, 1)
				} else {
					stack = append(stack, 0)
				}
			case "==":
				if a == b {
					stack = append(stack, 1)
				} else {
					stack = append(stack, 0)
				}
			}
		} else if val, ok := env[token]; ok {
			stack = append(stack, val)
		} else {
			n, _ := strconv.Atoi(token)
			stack = append(stack, n)
		}
	}
	return stack[len(stack)-1]
}

func main() {
	env := map[string]int{"x": 12, "y": 5}
	v1 := evalRpnVm(compileInfixToRpn("( x + y * 4 ) - 2"), env)
	v2 := evalRpnVm(compileInfixToRpn("x * 2 > y + 10"), env)
	if v1 != 30 || v2 != 1 {
		panic("assert")
	}
	fmt.Printf("v1=%d v2=%d\nBENCH_08_OK\n", v1, v2)
}
