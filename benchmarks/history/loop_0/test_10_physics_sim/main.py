import math

def step_world(bs: list[dict], dt: float):
    for b in bs:
        b["vy"] += 9.8 * dt
        b["x"] += b["vx"] * dt
        b["y"] += b["vy"] * dt
    for i in range(len(bs)):
        for j in range(i + 1, len(bs)):
            a, b = bs[i], bs[j]
            dx, dy = b["x"] - a["x"], b["y"] - a["y"]
            d2, min_d = dx*dx + dy*dy, a["r"] + b["r"]
            if 1e-4 < d2 < min_d * min_d:
                d = math.sqrt(d2)
                nx, ny = dx / d, dy / d
                vn = (b["vx"] - a["vx"])*nx + (b["vy"] - a["vy"])*ny
                if vn < 0:
                    imp = -(1.9 * vn) / (1/a["m"] + 1/b["m"])
                    a["vx"] -= (imp / a["m"]) * nx
                    b["vx"] += (imp / b["m"]) * nx

w = [{"id": 1, "x": 20.0, "y": 50.0, "vx": 40.0, "vy": 0.0, "r": 5.0, "m": 1.0},
     {"id": 2, "x": 28.0, "y": 50.0, "vx": -40.0, "vy": 0.0, "r": 5.0, "m": 1.0}]
for _ in range(5): step_world(w, 0.05)
assert w[0]["vx"] < 0 and w[1]["vx"] > 0
print(f"v0={w[0]['vx']} v1={w[1]['vx']}\nBENCH_10_OK")
