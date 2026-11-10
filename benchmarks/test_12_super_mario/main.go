package main

import (
	"fmt"
	"math"
)

type EnemyGoomba struct {
	x     float64
	y     float64
	vx    float64
	alive bool
}

type MarioWorld struct {
	playerX       float64
	playerY       float64
	playerVx      float64
	playerVy      float64
	onGround      bool
	powerUpState  int
	coins         int
	score         int
	lives         int
	cameraX       float64
	goalX         float64
	status        string
	coinPositions []float64
	mushroomX     float64
	mushroomTaken bool
	enemies       []EnemyGoomba
}

func createMarioLevel() MarioWorld {
	return MarioWorld{
		playerX:       0.0,
		playerY:       0.0,
		playerVx:      0.0,
		playerVy:      0.0,
		onGround:      true,
		powerUpState:  0,
		coins:         0,
		score:         0,
		lives:         3,
		cameraX:       0.0,
		goalX:         120.0,
		status:        "PLAYING",
		coinPositions: []float64{30.0, 60.0, 90.0},
		mushroomX:     40.0,
		mushroomTaken: false,
		enemies:       []EnemyGoomba{{50.0, 0.0, -1.0, true}},
	}
}

func stepMarioFrame(w *MarioWorld, moveDir float64, jumpPressed bool, dt float64) {
	if w.status != "PLAYING" {
		return
	}
	w.playerVx = moveDir * 20.0
	if jumpPressed && w.onGround {
		w.playerVy = 18.0
		w.onGround = false
	}
	w.playerVy -= 30.0 * dt
	w.playerX += w.playerVx * dt
	w.playerY += w.playerVy * dt
	if w.playerY <= 0.0 {
		w.playerY = 0.0
		w.playerVy = 0.0
		w.onGround = true
	}
	if !w.mushroomTaken && math.Abs(w.playerX-w.mushroomX) <= 2.0 {
		w.mushroomTaken = true
		w.powerUpState = 1
		w.score += 1000
	}
	var rem []float64
	for _, cx := range w.coinPositions {
		if math.Abs(w.playerX-cx) <= 2.0 {
			w.coins++
			w.score += 200
		} else {
			rem = append(rem, cx)
		}
	}
	w.coinPositions = rem
	for i := range w.enemies {
		e := &w.enemies[i]
		if !e.alive {
			continue
		}
		e.x += e.vx * dt
		if math.Abs(w.playerX-e.x) <= 2.5 {
			if w.playerY > 0.5 && w.playerVy < 0.0 {
				e.alive = false
				w.score += 500
				w.playerVy = 10.0
			} else if w.playerY <= 0.5 {
				if w.powerUpState > 0 {
					w.powerUpState = 0
				} else {
					w.lives--
					if w.lives <= 0 {
						w.status = "GAME_OVER"
					}
				}
			}
		}
	}
	w.cameraX = math.Max(0.0, w.playerX-20.0)
	if w.playerX >= w.goalX {
		w.status = "LEVEL_CLEAR"
		w.score += 2000
	}
}

func main() {
	w := createMarioLevel()
	for f := 0; f < 40; f++ {
		if w.status != "PLAYING" {
			break
		}
		stepMarioFrame(&w, 1.0, f == 8, 0.2)
	}
	if w.status != "LEVEL_CLEAR" || w.score != 4100 || w.coins != 3 || w.enemies[0].alive || w.cameraX <= 80.0 {
		panic("assert")
	}
	fmt.Printf("Mario Status=%s Score=%d Coins=%d\nBENCH_12_OK\n", w.status, w.score, w.coins)
}
