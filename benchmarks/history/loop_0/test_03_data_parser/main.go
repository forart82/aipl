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
	for _, line := range strings.Split(src, "\n") {
		t := strings.TrimSpace(line)
		if len(t) > 0 && !strings.HasPrefix(t, "#") {
			parts := strings.Split(t, "|")
			if len(parts) >= 4 {
				p, _ := strconv.Atoi(strings.TrimSpace(parts[1]))
				out = append(out, ConfigRecord{
					service: strings.TrimSpace(parts[0]),
					port:    p,
					tls:     strings.TrimSpace(parts[2]) == "true",
					tags:    strings.Split(strings.TrimSpace(parts[3]), ","),
				})
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
		var qtags []string
		for _, tg := range r.tags {
			qtags = append(qtags, fmt.Sprintf("%q", tg))
		}
		items = append(items, fmt.Sprintf(`{"service":%q,"port":%d,"tls":%v,"tags":[%s]}`, r.service, r.port, r.tls, strings.Join(qtags, ",")))
	}
	return "[" + strings.Join(items, ",") + "]"
}

func main() {
	raw := "# Services\nauth | 8000 | false | core,jwt\ngateway | 8080 | true | edge,http\ninvalid | -5 | false | bad\n"
	parsed := parseRecords(raw)
	valid := validateAndMutate(parsed)
	jsonOut := serializeJson(valid)
	if len(parsed) != 3 || len(valid) != 2 || !strings.Contains(jsonOut, `"service":"auth"`) {
		panic("assert")
	}
	fmt.Printf("%s\nBENCH_03_OK\n", jsonOut)
}
