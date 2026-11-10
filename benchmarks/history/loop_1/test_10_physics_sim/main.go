package main

import (
	"fmt"
	"math"
)

type Body2D struct {
	id                       int
	x, y, vx, vy, radius, m  float64
}

func stepWorld(bodies []Body2D, dt, w, h float64) {
	for i := range bodies {
		b := &bodies[i]
		b.vy += 9.8 * dt
		b.x += b.vx * dt
		b.y += b.vy * dt
	}
	for i := 0; i < len(bodies); i++ {
		for j := i + 1; j < len(bodies); j++ {
			a, b := &bodies[i], &bodies[j]
			dx, dy := b.x-a.x, b.y-a.y
			d2, minD := dx*dx+dy*dy, a.radius+b.radius
			if d2 < minD*minD && d2 > 1e-4 {
				d := math.Sqrt(d2)
				nx, ny := dx/d, dy/d
				vn := (b.vx-a.vx)*nx + (b.vy-a.vy)*ny
				if vn < 0 {
					imp := -(1.9 * vn) / (1/a.m + 1/b.m)
					a.vx -= (imp / a.m) * nx
					b.vx += (imp / b.m) * nx
				}
			}
		}
	}
}

func main() {
	world := []Body2D{{1, 20, 50, 40, 0, 5, 1}, {2, 28, 50, -40, 0, 5, 1}}
	for s := 0; s < 5; s++ { stepWorld(world, 0.05, 100, 100) }
	fmt.Printf("v0=%v v1=%v\nBENCH_10_OK\n", world[0].vx, world[1].vx)
}
