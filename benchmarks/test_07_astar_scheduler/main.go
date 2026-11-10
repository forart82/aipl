package main

import (
	"fmt"
	"math"
	"sort"
)

type ScheduledJob struct {
	id         int
	priority   int
	durationMs int
	pathCost   float64
}

func astarCost(g [][]int, sx, sy, gx, gy int) float64 {
	h := len(g)
	w := len(g[0])
	dist := make([][]float64, h)
	visited := make([][]bool, h)
	for i := range dist {
		dist[i] = make([]float64, w)
		visited[i] = make([]bool, w)
		for j := range dist[i] {
			dist[i][j] = 1e9
		}
	}
	dist[sy][sx] = 0.0
	dirs := [][3]float64{
		{1, 0, 1.0}, {-1, 0, 1.0}, {0, 1, 1.0}, {0, -1, 1.0},
		{1, 1, 1.4142}, {1, -1, 1.4142}, {-1, 1, 1.4142}, {-1, -1, 1.4142},
	}
	for {
		bestF := 1e9
		bx := -1
		by := -1
		found := false
		for y := 0; y < h; y++ {
			for x := 0; x < w; x++ {
				if !visited[y][x] && dist[y][x] < 1e8 {
					f := dist[y][x] + math.Sqrt(float64((gx-x)*(gx-x)+(gy-y)*(gy-y)))
					if f < bestF {
						bestF = f
						bx = x
						by = y
						found = true
					}
				}
			}
		}
		if !found {
			return -1.0
		}
		if bx == gx && by == gy {
			return dist[by][bx]
		}
		visited[by][bx] = true
		for _, d := range dirs {
			nx := bx + int(d[0])
			ny := by + int(d[1])
			if nx >= 0 && nx < w && ny >= 0 && ny < h {
				if g[ny][nx] == 0 && dist[by][bx]+d[2] < dist[ny][nx] {
					dist[ny][nx] = dist[by][bx] + d[2]
				}
			}
		}
	}
}

func scheduleJobsByPriority(jobs []ScheduledJob) []int {
	sorted := make([]ScheduledJob, len(jobs))
	copy(sorted, jobs)
	sort.Slice(sorted, func(i, j int) bool {
		if sorted[i].priority != sorted[j].priority {
			return sorted[i].priority > sorted[j].priority
		}
		return sorted[i].pathCost < sorted[j].pathCost
	})
	var order []int
	for _, j := range sorted {
		order = append(order, j.id)
	}
	return order
}

func main() {
	g := make([][]int, 6)
	for i := range g {
		g[i] = make([]int, 6)
	}
	g[0][2] = 1
	g[1][2] = 1
	g[2][2] = 1
	c1 := astarCost(g, 0, 0, 5, 0)
	c2 := astarCost(g, 0, 5, 5, 5)
	if c1 <= c2 || c2 <= 0.0 {
		panic("assert")
	}
	jobs := []ScheduledJob{
		{101, 5, 100, c1},
		{102, 10, 200, c1},
		{103, 5, 150, c2},
	}
	order := scheduleJobsByPriority(jobs)
	if order[0] != 102 || order[1] != 103 || order[2] != 101 {
		panic("assert order")
	}
	fmt.Printf("Order=%d,%d,%d\nBENCH_07_OK\n", order[0], order[1], order[2])
}
