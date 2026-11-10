package main

import (
	"fmt"
	"strings"
)

func sievePrimes(limit int) []int {
	isPrime := make([]bool, limit+1)
	for i := 2; i <= limit; i++ {
		isPrime[i] = true
	}
	for p := 2; p*p <= limit; p++ {
		if isPrime[p] {
			for m := p * p; m <= limit; m += p {
				isPrime[m] = false
			}
		}
	}
	var primes []int
	for k := 2; k <= limit; k++ {
		if isPrime[k] {
			primes = append(primes, k)
		}
	}
	return primes
}

func classifyCell(n int, isPrime bool) string {
	if isPrime {
		return fmt.Sprintf("PRIME(%d)", n)
	}
	if n%15 == 0 {
		return "FizzBuzz"
	}
	if n%3 == 0 {
		return "Fizz"
	}
	if n%5 == 0 {
		return "Buzz"
	}
	return fmt.Sprintf("%d", n)
}

func main() {
	primes := sievePrimes(30)
	pset := make(map[int]bool)
	for _, p := range primes {
		pset[p] = true
	}
	var rows []string
	for r := 0; r < 3; r++ {
		var cols []string
		for c := 1; c <= 5; c++ {
			v := r*5 + c
			cols = append(cols, classifyCell(v, pset[v]))
		}
		rows = append(rows, strings.Join(cols, " | "))
	}
	fmt.Println(strings.Join(rows, "\n"))
	fmt.Println("BENCH_02_OK")
}
