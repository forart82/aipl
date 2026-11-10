package main

import (
	"fmt"
	"math"
)

type EnemyGoomba struct {
	x, vx float64
	alive bool
}

type MarioWorld struct {
	px, py, vx, vy, camX, goalX, mushX float64
	onGround, mushTaken                bool
	power, coins, score, lives         int
	status                             string
	coinPos                            []float64
	enemies                            []EnemyGoomba
}

func (w *MarioWorld) step(dir float64, jump bool, dt float64) {
	if w.status != "PLAYING" { return }
	w.vx = dir * 20.0
	if jump && w.onGround { w.vy = 18.0; w.onGround = false }
	w.vy -= 30.0 * dt
	w.px += w.vx * dt
	w.py += w.vy * dt
	if w.py <= 0 { w.py, w.vy, w.onGround = 0, 0, true }
	if !w.mushTaken && math.Abs(w.px-w.mushX) <= 2.0 {
		w.mushTaken, w.power, w.score = true, 1, w.score+1000
	}
	var rem []float64
	for _, cx := range w.coinPos {
		if math.Abs(w.px-cx) <= 2.0 { w.coins++; w.score += 200 } else { rem = append(rem, cx) }
	}
	w.coinPos = rem
	for i := range w.enemies {
		e := &w.enemies[i]
		if !e.alive { continue }
		e.x += e.vx * dt
		if math.Abs(w.px-e.x) <= 2.5 && w.py > 0.5 && w.vy < 0 {
			e.alive = false; w.score += 500; w.vy = 10.0
		}
	}
	w.camX = math.Max(0, w.px-20.0)
	if w.px >= w.goalX { w.status = "LEVEL_CLEAR"; w.score += 2000 }
}

func main() {
	w := MarioWorld{goalX: 120, mushX: 40, onGround: true, lives: 3, status: "PLAYING", coinPos: []float64{30, 60, 90}, enemies: []EnemyGoomba{{50, -1, true}}}
	for f := 0; f < 40 && w.status == "PLAYING"; f++ { w.step(1.0, f == 8, 0.2) }
	if w.status != "LEVEL_CLEAR" || w.score != 4100 { panic("assert") }
	fmt.Printf("Mario Status=%s Score=%d Coins=%d\nBENCH_12_OK\n", w.status, w.score, w.coins)
}
