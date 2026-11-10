package main

import (
	"fmt"
	"strconv"
	"strings"
)

type ConfigRecord struct {
	service string
	port    int
	tls     bool
	tags    []string
}

func parseRecords(src string) []ConfigRecord {
	var out []ConfigRecord
	lines := strings.Split(src, "\n")
	for _, line := range lines {
		t := strings.TrimSpace(line)
		if len(t) > 0 && !strings.HasPrefix(t, "#") {
			parts := strings.Split(t, "|")
			if len(parts) >= 4 {
				svc := strings.TrimSpace(parts[0])
				port, _ := strconv.Atoi(strings.TrimSpace(parts[1]))
				tls := strings.TrimSpace(parts[2]) == "true"
				rawTags := strings.Split(strings.TrimSpace(parts[3]), ",")
				var tags []string
				for _, tg := range rawTags {
					tags = append(tags, strings.TrimSpace(tg))
				}
				out = append(out, ConfigRecord{svc, port, tls, tags})
			}
		}
	}
	return out
}

func validateAndMutate(records []ConfigRecord) []ConfigRecord {
	var out []ConfigRecord
	for _, r := range records {
		if len(r.service) > 0 && r.port > 0 && r.port <= 65535 {
			var tags []string
			for _, tg := range r.tags {
				tags = append(tags, strings.TrimSpace(tg))
			}
			tags = append(tags, "verified")
			out = append(out, ConfigRecord{r.service, r.port + 100, true, tags})
		}
	}
	return out
}

func serializeJson(records []ConfigRecord) string {
	var items []string
	for _, r := range records {
		var q []string
		for _, t := range r.tags {
			q = append(q, fmt.Sprintf("\"%s\"", t))
		}
		tlsStr := "false"
		if r.tls {
			tlsStr = "true"
		}
		item := fmt.Sprintf("{\"service\":\"%s\",\"port\":%d,\"tls\":%s,\"tags\":[%s]}", r.service, r.port, tlsStr, strings.Join(q, ","))
		items = append(items, item)
	}
	return "[" + strings.Join(items, ",") + "]"
}

func main() {
	raw := "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n"
	parsed := parseRecords(raw)
	valid := validateAndMutate(parsed)
	jsonOut := serializeJson(valid)
	if len(parsed) != 3 || len(valid) != 2 || !strings.Contains(jsonOut, "\"service\":\"auth\"") {
		panic("assert")
	}
	fmt.Println(jsonOut)
	fmt.Println("BENCH_03_OK")
}
