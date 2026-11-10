w = {
    "px": 0.0, "py": 0.0, "vx": 0.0, "vy": 0.0, "cam": 0.0, "goal": 120.0, "mush_x": 40.0,
    "ground": True, "mush": False, "power": 0, "coins": 0, "score": 0, "lives": 3,
    "status": "PLAYING", "coin_pos": [30.0, 60.0, 90.0], "enemies": [{"x": 50.0, "vx": -1.0, "alive": True}],
}
for f in range(40):
    if w["status"] != "PLAYING": break
    dt = 0.2
    w["vx"] = 20.0
    if f == 8 and w["ground"]:
        w["vy"], w["ground"] = 18.0, False
    w["vy"] -= 30.0 * dt
    w["px"] += w["vx"] * dt
    w["py"] += w["vy"] * dt
    if w["py"] <= 0.0:
        w["py"], w["vy"], w["ground"] = 0.0, 0.0, True
    if not w["mush"] and abs(w["px"] - w["mush_x"]) <= 2.0:
        w["mush"], w["power"], w["score"] = True, 1, w["score"] + 1000
    rem = []
    for cx in w["coin_pos"]:
        if abs(w["px"] - cx) <= 2.0:
            w["coins"] += 1
            w["score"] += 200
        else:
            rem.append(cx)
    w["coin_pos"] = rem
    for e in w["enemies"]:
        if e["alive"]:
            e["x"] += e["vx"] * dt
            if abs(w["px"] - e["x"]) <= 2.5 and w["py"] > 0.5 and w["vy"] < 0:
                e["alive"], w["score"], w["vy"] = False, w["score"] + 500, 10.0
    w["cam"] = max(0.0, w["px"] - 20.0)
    if w["px"] >= w["goal"]:
        w["status"], w["score"] = "LEVEL_CLEAR", w["score"] + 2000

assert w["status"] == "LEVEL_CLEAR" and w["score"] == 4100 and w["coins"] == 3 and not w["enemies"][0]["alive"]
print(f"Mario Status={w['status']} Score={w['score']} Coins={w['coins']}\nBENCH_12_OK")
