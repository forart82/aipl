package main

import (
	"fmt"
	"math"
	"sort"
)

func astarCost(g [][]int, sx, sy, gx, gy int) float64 {
	h, w := len(g), len(g[0])
	dist := make([][]float64, h)
	vis := make([][]bool, h)
	for y := 0; y < h; y++ {
		dist[y] = make([]float64, w)
		vis[y] = make([]bool, w)
		for x := 0; x < w; x++ { dist[y][x] = 1e9 }
	}
	dist[sy][sx] = 0
	dx := []int{1,-1,0,0,1,1,-1,-1}
	dy := []int{0,0,1,-1,1,-1,1,-1}
	for {
		bestF, bx, by, ok := 1e9, 0, 0, false
		for y := 0; y < h; y++ {
			for x := 0; x < w; x++ {
				if !vis[y][x] && dist[y][x] < 1e8 {
					f := dist[y][x] + math.Hypot(float64(gx-x), float64(gy-y))
					if f < bestF { bestF, bx, by, ok = f, x, y, true }
				}
			}
		}
		if !ok { return -1 }
		if bx == gx && by == gy { return dist[by][bx] }
		vis[by][bx] = true
		for d := 0; d < 8; d++ {
			nx, ny := bx+dx[d], by+dy[d]
			if nx >= 0 && nx < w && ny >= 0 && ny < h && g[ny][nx] == 0 {
				step := 1.0
				if dx[d] != 0 && dy[d] != 0 { step = 1.414 }
				if dist[by][bx]+step < dist[ny][nx] { dist[ny][nx] = dist[by][bx] + step }
			}
		}
	}
}

func main() {
	g := make([][]int, 6)
	for i := range g { g[i] = make([]int, 6) }
	g[0][2], g[1][2], g[2][2] = 1, 1, 1
	c1, c2 := astarCost(g, 0, 0, 5, 0), astarCost(g, 0, 5, 5, 5)
	type Job struct { id, prio int; cost float64 }
	jobs := []Job{{101, 5, c1}, {102, 10, c1}, {103, 5, c2}}
	sort.Slice(jobs, func(i, j int) bool {
		if jobs[i].prio != jobs[j].prio { return jobs[i].prio > jobs[j].prio }
		return jobs[i].cost < jobs[j].cost
	})
	fmt.Printf("Order=%d,%d,%d\nBENCH_07_OK\n", jobs[0].id, jobs[1].id, jobs[2].id)
}
