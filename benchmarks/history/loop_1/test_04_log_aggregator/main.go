package main

import (
	"fmt"
	"os"
	"strings"
)

type LogSummary struct {
	totalLines, errorCount, warnCount, infoCount int
	topEndpoint                                  string
	errorRatePct                                 float64
}

func analyzeLogs(content string) LogSummary {
	total, errs, warns, infos, bestCnt := 0, 0, 0, 0, 0
	bestEp := ""
	counts := map[string]int{}
	for _, line := range strings.Split(content, "\n") {
		t := strings.TrimSpace(line)
		if len(t) > 0 {
			total++
			cols := strings.Fields(t)
			if len(cols) >= 3 {
				switch cols[1] {
				case "ERROR":
					errs++
				case "WARN":
					warns++
				case "INFO":
					infos++
				}
				counts[cols[2]]++
				if counts[cols[2]] > bestCnt {
					bestCnt = counts[cols[2]]
					bestEp = cols[2]
				}
			}
		}
	}
	return LogSummary{total, errs, warns, infos, bestEp, float64(errs) * 100.0 / float64(total)}
}

func main() {
	path := "/tmp/go_bench04.log"
	sample := "2026-11-02T10:00:01Z INFO /api/login 200\n2026-11-02T10:00:02Z ERROR /api/pay 500\n2026-11-02T10:00:03Z INFO /api/pay 200\n2026-11-02T10:00:04Z WARN /api/login 429\n2026-11-02T10:00:05Z ERROR /api/pay 503\n"
	_ = os.WriteFile(path, []byte(sample), 0644)
	b, _ := os.ReadFile(path)
	s := analyzeLogs(string(b))
	if s.totalLines != 5 || s.errorCount != 2 || s.topEndpoint != "/api/pay" {
		panic("assert")
	}
	fmt.Printf("Total=%d Errors=%d Top=%s\nBENCH_04_OK\n", s.totalLines, s.errorCount, s.topEndpoint)
}
