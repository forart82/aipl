package main

import (
	"fmt"
	"os"
	"strings"
)

type LogSummary struct {
	totalLines   int
	errorCount   int
	warnCount    int
	infoCount    int
	topEndpoint  string
	errorRatePct float64
}

func analyzeLogs(content string) LogSummary {
	lines := strings.Split(content, "\n")
	total := 0
	errs := 0
	warns := 0
	infos := 0
	counts := make(map[string]int)
	topEp := ""
	topCnt := 0
	for _, line := range lines {
		t := strings.TrimSpace(line)
		if len(t) > 0 {
			total++
			parts := strings.Fields(t)
			if len(parts) >= 3 {
				lvl := parts[1]
				ep := parts[2]
				if lvl == "ERROR" {
					errs++
				} else if lvl == "WARN" {
					warns++
				} else if lvl == "INFO" {
					infos++
				}
				counts[ep]++
				if counts[ep] > topCnt {
					topCnt = counts[ep]
					topEp = ep
				}
			}
		}
	}
	rate := 0.0
	if total > 0 {
		rate = (float64(errs) * 100.0) / float64(total)
	}
	return LogSummary{total, errs, warns, infos, topEp, rate}
}

func main() {
	p := "/tmp/bench04_sample.log"
	sample := "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n"
	os.WriteFile(p, []byte(sample), 0644)
	data, _ := os.ReadFile(p)
	s := analyzeLogs(string(data))
	if s.totalLines != 5 || s.errorCount != 2 || s.warnCount != 1 || s.infoCount != 2 || s.topEndpoint != "/api/pay" {
		panic("assert")
	}
	fmt.Printf("Total=%d Errors=%d Top=%s\nBENCH_04_OK\n", s.totalLines, s.errorCount, s.topEndpoint)
}
