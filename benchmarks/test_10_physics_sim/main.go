package main

import (
	"fmt"
	"math"
)

type Body2D struct {
	id     int
	x      float64
	y      float64
	vx     float64
	vy     float64
	radius float64
	mass   float64
}

func stepPhysicsWorld(bodies []Body2D, dt float64, worldW float64, worldH float64) {
	for i := range bodies {
		bodies[i].vy += 9.8 * dt
		bodies[i].x += bodies[i].vx * dt
		bodies[i].y += bodies[i].vy * dt
		if bodies[i].x-bodies[i].radius < 0.0 {
			bodies[i].x = bodies[i].radius
			bodies[i].vx = -bodies[i].vx * 0.9
		} else if bodies[i].x+bodies[i].radius > worldW {
			bodies[i].x = worldW - bodies[i].radius
			bodies[i].vx = -bodies[i].vx * 0.9
		}
		if bodies[i].y+bodies[i].radius > worldH {
			bodies[i].y = worldH - bodies[i].radius
			bodies[i].vy = -bodies[i].vy * 0.85
		}
	}
	n := len(bodies)
	for i := 0; i < n; i++ {
		for j := i + 1; j < n; j++ {
			dx := bodies[j].x - bodies[i].x
			dy := bodies[j].y - bodies[i].y
			distSq := dx*dx + dy*dy
			minDist := bodies[i].radius + bodies[j].radius
			if distSq < minDist*minDist && distSq > 0.0001 {
				d := math.Sqrt(distSq)
				nx := dx / d
				ny := dy / d
				velAlongNormal := (bodies[j].vx-bodies[i].vx)*nx + (bodies[j].vy-bodies[i].vy)*ny
				if velAlongNormal < 0.0 {
					impulse := -(1.9 * velAlongNormal) / (1.0/bodies[i].mass + 1.0/bodies[j].mass)
					bodies[i].vx -= (impulse / bodies[i].mass) * nx
					bodies[i].vy -= (impulse / bodies[i].mass) * ny
					bodies[j].vx += (impulse / bodies[j].mass) * nx
					bodies[j].vy += (impulse / bodies[j].mass) * ny
				}
			}
		}
	}
}

func main() {
	world := []Body2D{
		{1, 20.0, 50.0, 40.0, 0.0, 5.0, 1.0},
		{2, 28.0, 50.0, -40.0, 0.0, 5.0, 1.0},
	}
	for s := 0; s < 5; s++ {
		stepPhysicsWorld(world, 0.05, 100.0, 100.0)
	}
	if world[0].vx >= 0.0 || world[1].vx <= 0.0 {
		panic("assert")
	}
	fmt.Printf("v0=%d v1=%d\nBENCH_10_OK\n", int(math.Round(world[0].vx)), int(math.Round(world[1].vx)))
}
