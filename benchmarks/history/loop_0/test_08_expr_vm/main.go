package main

import (
	"fmt"
	"strconv"
	"strings"
)

func prec(op string) int {
	switch op {
	case "*", "/": return 3
	case "+", "-": return 2
	case ">", "==": return 1
	}
	return 0
}

func compileRpn(expr string) []string {
	var out, ops []string
	for _, t := range strings.Fields(expr) {
		if t == "(" { ops = append(ops, t)
		} else if t == ")" {
			for len(ops) > 0 && ops[len(ops)-1] != "(" {
				out = append(out, ops[len(ops)-1])
				ops = ops[:len(ops)-1]
			}
			ops = ops[:len(ops)-1]
		} else if prec(t) > 0 {
			for len(ops) > 0 && prec(ops[len(ops)-1]) >= prec(t) {
				out = append(out, ops[len(ops)-1])
				ops = ops[:len(ops)-1]
			}
			ops = append(ops, t)
		} else { out = append(out, t) }
	}
	for len(ops) > 0 { out = append(out, ops[len(ops)-1]); ops = ops[:len(ops)-1] }
	return out
}

func evalRpn(tokens []string, env map[string]int) int {
	var st []int
	for _, t := range tokens {
		if prec(t) > 0 {
			b, a := st[len(st)-1], st[len(st)-2]
			st = st[:len(st)-2]
			switch t {
			case "+": st = append(st, a+b)
			case "-": st = append(st, a-b)
			case "*": st = append(st, a*b)
			case ">": if a > b { st = append(st, 1) } else { st = append(st, 0) }
			}
		} else if v, ok := env[t]; ok { st = append(st, v)
		} else { n, _ := strconv.Atoi(t); st = append(st, n) }
	}
	return st[len(st)-1]
}

func main() {
	env := map[string]int{"x": 12, "y": 5}
	v1 := evalRpn(compileRpn("( x + y * 4 ) - 2"), env)
	v2 := evalRpn(compileRpn("x * 2 > y + 10"), env)
	fmt.Printf("v1=%d v2=%d\nBENCH_08_OK\n", v1, v2)
}
