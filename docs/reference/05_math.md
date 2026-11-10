[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 05: `math` API Reference

> Complete API reference manual for AIPL standard library domain `math` (440 callable functions & methods across ["std/math/bigint.aipl", "std/math/complex_fft.aipl", "std/math/consts.aipl", "std/math/curve.aipl", "std/math/ease.aipl", "std/math/fixed_point.aipl", "std/math/geom2d.aipl", "std/math/geom3d.aipl", "std/math/mat.aipl", "std/math/math_mod.aipl", "std/math/prng.aipl", "std/math/prob_stats.aipl", "std/math/quat.aipl", "std/math/simd.aipl", "std/math/trig.aipl", "std/math/vec_math.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `math`
- **Target Source Modules**: ["std/math/bigint.aipl", "std/math/complex_fft.aipl", "std/math/consts.aipl", "std/math/curve.aipl", "std/math/ease.aipl", "std/math/fixed_point.aipl", "std/math/geom2d.aipl", "std/math/geom3d.aipl", "std/math/mat.aipl", "std/math/math_mod.aipl", "std/math/prng.aipl", "std/math/prob_stats.aipl", "std/math/quat.aipl", "std/math/simd.aipl", "std/math/trig.aipl", "std/math/vec_math.aipl"]
- **Total Callable Functions & Methods**: 440
- **Total Data Types (`struct` & `enum`)**: 53
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(53 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BigInt` | `pub struct` | `std/math/bigint.aipl` | `sign: int`, `digits: [int]` | `BigInt(sign, digits)` |
| `Complex64` | `pub struct` | `std/math/complex_fft.aipl` | `re: float`, `im: float` | `Complex64(re, im)` |
| `FixedQ16_16` | `pub struct` | `std/math/fixed_point.aipl` | `raw: int` | `FixedQ16_16(raw)` |
| `FixedQ32_32` | `pub struct` | `std/math/fixed_point.aipl` | `raw: int` | `FixedQ32_32(raw)` |
| `Rect` | `pub struct` | `std/math/geom2d.aipl` | `x: float`, `y: float`, `w: float`, `h: float` | `Rect(x, y, w, h)` |
| `IRect` | `pub struct` | `std/math/geom2d.aipl` | `x: int`, `y: int`, `w: int`, `h: int` | `IRect(x, y, w, h)` |
| `Rect2D` | `pub struct` | `std/math/geom2d.aipl` | `x: float`, `y: float`, `w: float = 0.0`, `h: float = 0.0`, `width: float = 0.0`, `height: float = 0.0` | `Rect2D(x, y, w, h, width, height)` |
| `Circle2D` | `pub struct` | `std/math/geom2d.aipl` | `x: float`, `y: float`, `r: float`, `cx: float = 0.0`, `cy: float = 0.0` | `Circle2D(x, y, r, cx, cy)` |
| `Segment2D` | `pub struct` | `std/math/geom2d.aipl` | `p1: Vec2`, `p2: Vec2` | `Segment2D(p1, p2)` |
| `Capsule2D` | `pub struct` | `std/math/geom2d.aipl` | `p1: Vec2`, `p2: Vec2`, `radius: float` | `Capsule2D(p1, p2, radius)` |
| `Ray2D` | `pub struct` | `std/math/geom2d.aipl` | `origin: Vec2`, `dir: Vec2 = Vec2(x = 1.0, y = 0.0)`, `direction: Vec2 = Vec2(x = 1.0, y = 0.0)`, `maxDistance: float = 1000.0` | `Ray2D(origin, dir, direction, maxDistance)` |
| `Polygon2D` | `pub struct` | `std/math/geom2d.aipl` | `vertices: [Vec2]` | `Polygon2D(vertices)` |
| `CollisionHit` | `pub struct` | `std/math/geom2d.aipl` | `hit: bool`, `normalX: float`, `normalY: float`, `depth: float` | `CollisionHit(hit, normalX, normalY, depth)` |
| `SweptHit` | `pub struct` | `std/math/geom2d.aipl` | `hit: bool`, `time: float`, `normalX: float`, `normalY: float` | `SweptHit(hit, time, normalX, normalY)` |
| `Mat2D` | `pub struct` | `std/math/geom2d.aipl` | `a: float`, `b: float`, `c: float`, `d: float`, `tx: float`, `ty: float` | `Mat2D(a, b, c, d, tx, ty)` |
| `SegmentHit2D` | `pub struct` | `std/math/geom2d.aipl` | `hit: bool`, `x: float`, `y: float`, `t: float`, `u: float` | `SegmentHit2D(hit, x, y, t, u)` |
| `AABB3D` | `pub struct` | `std/math/geom3d.aipl` | `min: Vec3`, `max: Vec3` | `AABB3D(min, max)` |
| `Sphere3D` | `pub struct` | `std/math/geom3d.aipl` | `center: Vec3`, `radius: float` | `Sphere3D(center, radius)` |
| `Plane3D` | `pub struct` | `std/math/geom3d.aipl` | `normal: Vec3`, `distance: float = 0.0`, `d: float = 0.0` | `Plane3D(normal, distance, d)` |
| `Ray3D` | `pub struct` | `std/math/geom3d.aipl` | `origin: Vec3`, `dir: Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)`, `direction: Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)`, `maxDistance: float = 1000.0` | `Ray3D(origin, dir, direction, maxDistance)` |
| `Triangle3D` | `pub struct` | `std/math/geom3d.aipl` | `v0: Vec3`, `v1: Vec3`, `v2: Vec3` | `Triangle3D(v0, v1, v2)` |
| `Frustum3D` | `pub struct` | `std/math/geom3d.aipl` | `planes: [Plane3D]` | `Frustum3D(planes)` |
| `GeomRayHit3D` | `pub struct` | `std/math/geom3d.aipl` | `hit: bool`, `distance: float`, `point: Vector3`, `normal: Vector3` | `GeomRayHit3D(hit, distance, point, normal)` |
| `Capsule3D` | `pub struct` | `std/math/geom3d.aipl` | `start: Vector3`, `end: Vector3`, `radius: float` | `Capsule3D(start, end, radius)` |
| `EulerVectors` | `pub struct` | `std/math/geom3d.aipl` | `forward: Vector3`, `right: Vector3`, `up: Vector3` | `EulerVectors(forward, right, up)` |
| `EulerTransform3D` | `pub struct` | `std/math/geom3d.aipl` | `translation: Vector3`, `rotationEuler: Vector3`, `scale: Vector3` | `EulerTransform3D(translation, rotationEuler, scale)` |
| `Mat2` | `pub struct` | `std/math/mat.aipl` | `m00: float`, `m01: float`, `m10: float`, `m11: float` | `Mat2(m00, m01, m10, m11)` |
| `Mat3` | `pub struct` | `std/math/mat.aipl` | `m00: float`, `m01: float`, `m02: float`, `m10: float`, `m11: float`, `m12: float`, `m20: float`, `m21: float`, `m22: float` | `Mat3(m00, m01, m02, m10, m11, m12, m20, m21, m22)` |
| `Mat4` | `pub struct` | `std/math/mat.aipl` | `m00: float`, `m01: float`, `m02: float`, `m03: float`, `m10: float`, `m11: float`, `m12: float`, `m13: float`, `m20: float`, `m21: float`, `m22: float`, `m23: float`, `m30: float`, `m31: float`, `m32: float`, `m33: float` | `Mat4(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33)` |
| `Pcg32Rng` | `pub struct` | `std/math/prng.aipl` | `mut state: int`, `mut inc: int` | `Pcg32Rng(mut state, mut inc)` |
| `Xoshiro256Rng` | `pub struct` | `std/math/prng.aipl` | `mut s0: int`, `mut s1: int`, `mut s2: int`, `mut s3: int` | `Xoshiro256Rng(mut s0, mut s1, mut s2, mut s3)` |
| `Rng` | `pub struct` | `std/math/prng.aipl` | `mut state: int` | `Rng(mut state)` |
| `RngState` | `pub struct` | `std/math/prng.aipl` | `mut state: int = 0`, `mut seed: int = 0` | `RngState(mut state, mut seed)` |
| `CurveKnot` | `pub struct` | `std/math/prob_stats.aipl` | `x: float`, `y: float` | `CurveKnot(x, y)` |
| `SummaryStats` | `pub struct` | `std/math/prob_stats.aipl` | `count: int`, `mean: float`, `variance: float = 0.0`, `stdDev: float = 0.0`, `minVal: float`, `maxVal: float`, `median: float = 0.0`, `p95: float = 0.0`, `p99: float = 0.0` | `SummaryStats(count, mean, variance, stdDev, minVal, maxVal, median, p95, p99)` |
| `HdrHistogram` | `pub struct` | `std/math/prob_stats.aipl` | `bucketCount: int = 0`, `counts: [int] = []`, `totalCount: int = 0`, `minVal: float = 1000000000.0`, `maxVal: float = -1000000000.0`, `count: int = 0`, `sum: float = 0.0`, `values: [float] = []` | `HdrHistogram(bucketCount, counts, totalCount, minVal, maxVal, count, sum, values)` |
| `KalmanFilter1D` | `pub struct` | `std/math/prob_stats.aipl` | `estimate: float`, `errorCov: float`, `processNoise: float`, `measurementNoise: float` | `KalmanFilter1D(estimate, errorCov, processNoise, measurementNoise)` |
| `Quat` | `pub struct` | `std/math/quat.aipl` | `x: float`, `y: float`, `z: float`, `w: float` | `Quat(x, y, z, w)` |
| `F32x4` | `pub struct` | `std/math/simd.aipl` | `x: float`, `y: float`, `z: float`, `w: float` | `F32x4(x, y, z, w)` |
| `I32x4` | `pub struct` | `std/math/simd.aipl` | `x: int`, `y: int`, `z: int`, `w: int` | `I32x4(x, y, z, w)` |
| `Float32Tensor` | `pub struct` | `std/math/simd.aipl` | `rows: int`, `cols: int`, `data: [float]` | `Float32Tensor(rows, cols, data)` |
| `Float64Tensor` | `pub struct` | `std/math/simd.aipl` | `rows: int`, `cols: int`, `data: [float]` | `Float64Tensor(rows, cols, data)` |
| `SimdLoopVectorPlan` | `pub struct` | `std/math/simd.aipl` | `strideElem: int`, `tripCount: int`, `vectorWidthLanes: int`, `vectorIterations: int`, `scalarTailCount: int`, `isaTarget: str`, `isVectorizable: bool` | `SimdLoopVectorPlan(strideElem, tripCount, vectorWidthLanes, vectorIterations, scalarTailCount, isaTarget, isVectorizable)` |
| `Vec2` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float` | `Vec2(x, y)` |
| `Vector2` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float` | `Vector2(x, y)` |
| `Vec3` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float`, `z: float` | `Vec3(x, y, z)` |
| `Vector3` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float`, `z: float` | `Vector3(x, y, z)` |
| `Vec4` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float`, `z: float`, `w: float` | `Vec4(x, y, z, w)` |
| `Vector4` | `pub struct` | `std/math/vec_math.aipl` | `x: float`, `y: float`, `z: float`, `w: float` | `Vector4(x, y, z, w)` |
| `IVec2` | `pub struct` | `std/math/vec_math.aipl` | `x: int`, `y: int` | `IVec2(x, y)` |
| `IVec3` | `pub struct` | `std/math/vec_math.aipl` | `x: int`, `y: int`, `z: int` | `IVec3(x, y, z)` |
| `IVec4` | `pub struct` | `std/math/vec_math.aipl` | `x: int`, `y: int`, `z: int`, `w: int` | `IVec4(x, y, z, w)` |
| `UVec2` | `pub struct` | `std/math/vec_math.aipl` | `x: int`, `y: int` | `UVec2(x, y)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/math/bigint.aipl` | `normalizeLimbs` | `fn normalizeLimbs(limbs: [int]): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `2` | `std/math/bigint.aipl` | `isZeroLimbs` | `fn isZeroLimbs(limbs: [int]): bool:` | `tests/functions/math/bigint_test.aipl` |
| `3` | `std/math/bigint.aipl` | `cmpAbsLimbs` | `fn cmpAbsLimbs(a: [int], b: [int]): int:` | `tests/functions/math/bigint_test.aipl` |
| `4` | `std/math/bigint.aipl` | `addAbsLimbs` | `fn addAbsLimbs(a: [int], b: [int]): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `5` | `std/math/bigint.aipl` | `subAbsLimbs` | `fn subAbsLimbs(a: [int], b: [int]): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `6` | `std/math/bigint.aipl` | `mulAbsLimbs` | `fn mulAbsLimbs(a: [int], b: [int]): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `7` | `std/math/bigint.aipl` | `bigIntFromInt` | `pub fn bigIntFromInt(val: int): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `8` | `std/math/bigint.aipl` | `bigIntFromString` | `pub fn bigIntFromString(strVal: str): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `9` | `std/math/bigint.aipl` | `toInt64` | `pub fn (self: BigInt) toInt64(): int:` | `tests/functions/math/bigint_test.aipl` |
| `10` | `std/math/bigint.aipl` | `padLimb9` | `fn padLimb9(val: int): str:` | `tests/functions/math/bigint_test.aipl` |
| `11` | `std/math/bigint.aipl` | `toString` | `pub fn (self: BigInt) toString(): str:` | `tests/functions/math/bigint_test.aipl` |
| `12` | `std/math/bigint.aipl` | `cmp` | `pub fn (self: BigInt) cmp(other: BigInt): int:` | `tests/functions/math/bigint_test.aipl` |
| `13` | `std/math/bigint.aipl` | `add` | `pub fn (self: BigInt) add(other: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `14` | `std/math/bigint.aipl` | `sub` | `pub fn (self: BigInt) sub(other: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `15` | `std/math/bigint.aipl` | `mul` | `pub fn (self: BigInt) mul(other: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `16` | `std/math/bigint.aipl` | `mulLimbScalar` | `fn mulLimbScalar(a: [int], scalar: int): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `17` | `std/math/bigint.aipl` | `shiftLimbAndAdd` | `fn shiftLimbAndAdd(rem: [int], limb: int): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `18` | `std/math/bigint.aipl` | `divModAbsLimbs` | `fn divModAbsLimbs(a: [int], b: [int], returnRem: bool): [int]:` | `tests/functions/math/bigint_test.aipl` |
| `19` | `std/math/bigint.aipl` | `div` | `pub fn (self: BigInt) div(other: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `20` | `std/math/bigint.aipl` | `mod` | `pub fn (self: BigInt) mod(other: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `21` | `std/math/bigint.aipl` | `bigIntDiv` | `pub fn bigIntDiv(a: BigInt, b: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `22` | `std/math/bigint.aipl` | `bigIntMod` | `pub fn bigIntMod(a: BigInt, b: BigInt): BigInt:` | `tests/functions/math/bigint_test.aipl` |
| `23` | `std/math/complex_fft.aipl` | `Complex64.new` | `pub fn Complex64.new(re: float, im: float): Complex64:` | `tests/functions/math/complex_fft_test.aipl` |
| `24` | `std/math/complex_fft.aipl` | `add` | `pub fn (self: Complex64) add(other: Complex64): Complex64:` | `tests/functions/math/complex_fft_test.aipl` |
| `25` | `std/math/complex_fft.aipl` | `sub` | `pub fn (self: Complex64) sub(other: Complex64): Complex64:` | `tests/functions/math/complex_fft_test.aipl` |
| `26` | `std/math/complex_fft.aipl` | `mul` | `pub fn (self: Complex64) mul(other: Complex64): Complex64:` | `tests/functions/math/complex_fft_test.aipl` |
| `27` | `std/math/complex_fft.aipl` | `mag` | `pub fn (self: Complex64) mag(): float:` | `tests/functions/math/complex_fft_test.aipl` |
| `28` | `std/math/complex_fft.aipl` | `conj` | `pub fn (self: Complex64) conj(): Complex64:` | `tests/functions/math/complex_fft_test.aipl` |
| `29` | `std/math/complex_fft.aipl` | `fftRadix2` | `pub fn fftRadix2(mut samples: [Complex64], inverse: bool): void:` | `tests/functions/math/complex_fft_test.aipl` |
| `30` | `std/math/consts.aipl` | `pi` | `pub fn pi(): float:` | `tests/functions/math/consts_test.aipl` |
| `31` | `std/math/consts.aipl` | `tau` | `pub fn tau(): float:` | `tests/functions/math/consts_test.aipl` |
| `32` | `std/math/consts.aipl` | `eulerE` | `pub fn eulerE(): float:` | `tests/functions/math/consts_test.aipl` |
| `33` | `std/math/consts.aipl` | `abs` | `pub fn abs(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `34` | `std/math/consts.aipl` | `absInt` | `pub fn absInt(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `35` | `std/math/consts.aipl` | `absFloat` | `pub fn absFloat(x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `36` | `std/math/consts.aipl` | `min` | `pub fn min(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `37` | `std/math/consts.aipl` | `max` | `pub fn max(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `38` | `std/math/consts.aipl` | `clamp` | `pub fn clamp(val: int, minVal: int, maxVal: int): int:` | `tests/functions/math/consts_test.aipl` |
| `39` | `std/math/consts.aipl` | `sign` | `pub fn sign(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `40` | `std/math/consts.aipl` | `signInt` | `pub fn signInt(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `41` | `std/math/consts.aipl` | `signFloat` | `pub fn signFloat(x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `42` | `std/math/consts.aipl` | `lerp` | `pub fn lerp(a: float, b: float, t: float): float:` | `tests/functions/math/consts_test.aipl` |
| `43` | `std/math/consts.aipl` | `inverseLerp` | `pub fn inverseLerp(a: float, b: float, v: float): float:` | `tests/functions/math/consts_test.aipl` |
| `44` | `std/math/consts.aipl` | `remapFloat` | `pub fn remapFloat(inMin: float, inMax: float, outMin: float, outMax: float, v: float): float:` | `tests/functions/math/consts_test.aipl` |
| `45` | `std/math/consts.aipl` | `smoothstep` | `pub fn smoothstep(edge0: float, edge1: float, x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `46` | `std/math/consts.aipl` | `smootherstep` | `pub fn smootherstep(edge0: float, edge1: float, x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `47` | `std/math/consts.aipl` | `pingPong` | `pub fn pingPong(t: float, length: float): float:` | `tests/functions/math/consts_test.aipl` |
| `48` | `std/math/consts.aipl` | `bitTest` | `pub fn bitTest(val: int, bitIdx: int): bool:` | `tests/functions/math/consts_test.aipl` |
| `49` | `std/math/consts.aipl` | `bitSet` | `pub fn bitSet(val: int, bitIdx: int): int:` | `tests/functions/math/consts_test.aipl` |
| `50` | `std/math/consts.aipl` | `bitClear` | `pub fn bitClear(val: int, bitIdx: int): int:` | `tests/functions/math/consts_test.aipl` |
| `51` | `std/math/consts.aipl` | `bitToggle` | `pub fn bitToggle(val: int, bitIdx: int): int:` | `tests/functions/math/consts_test.aipl` |
| `52` | `std/math/consts.aipl` | `rotateLeft32` | `pub fn rotateLeft32(val: int, shift: int): int:` | `tests/functions/math/consts_test.aipl` |
| `53` | `std/math/consts.aipl` | `rotateRight32` | `pub fn rotateRight32(val: int, shift: int): int:` | `tests/functions/math/consts_test.aipl` |
| `54` | `std/math/consts.aipl` | `popcount64` | `pub fn popcount64(val: int): int:` | `tests/functions/math/consts_test.aipl` |
| `55` | `std/math/consts.aipl` | `moveTowards` | `pub fn moveTowards(current: float, target: float, maxDelta: float): float:` | `tests/functions/math/consts_test.aipl` |
| `56` | `std/math/consts.aipl` | `remap` | `pub fn remap(val: float, inMin: float, inMax: float, outMin: float, outMax: float): float:` | `tests/functions/math/consts_test.aipl` |
| `57` | `std/math/consts.aipl` | `fract` | `pub fn fract(x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `58` | `std/math/consts.aipl` | `modFloat` | `pub fn modFloat(x: float, y: float): float:` | `tests/functions/math/consts_test.aipl` |
| `59` | `std/math/consts.aipl` | `distSq` | `pub fn distSq(x1: float, y1: float, x2: float, y2: float): float:` | `tests/functions/math/consts_test.aipl` |
| `60` | `std/math/consts.aipl` | `roundFloat` | `pub fn roundFloat(val: float): int:` | `tests/functions/math/consts_test.aipl` |
| `61` | `std/math/consts.aipl` | `roundTo` | `pub fn roundTo(val: float, decimals: int): float:` | `tests/functions/math/consts_test.aipl` |
| `62` | `std/math/consts.aipl` | `remEuclid` | `pub fn remEuclid(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `63` | `std/math/consts.aipl` | `gcdInt` | `pub fn gcdInt(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `64` | `std/math/consts.aipl` | `lcmInt` | `pub fn lcmInt(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `65` | `std/math/consts.aipl` | `isPowerOfTwo` | `pub fn isPowerOfTwo(n: int): bool:` | `tests/functions/math/consts_test.aipl` |
| `66` | `std/math/consts.aipl` | `nextPowerOfTwo` | `pub fn nextPowerOfTwo(n: int): int:` | `tests/functions/math/consts_test.aipl` |
| `67` | `std/math/consts.aipl` | `popcnt` | `pub fn popcnt(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `68` | `std/math/consts.aipl` | `ctz` | `pub fn ctz(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `69` | `std/math/consts.aipl` | `clz` | `pub fn clz(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `70` | `std/math/consts.aipl` | `popcnt64` | `pub fn popcnt64(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `71` | `std/math/consts.aipl` | `ctz64` | `pub fn ctz64(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `72` | `std/math/consts.aipl` | `clz64` | `pub fn clz64(x: int): int:` | `tests/functions/math/consts_test.aipl` |
| `73` | `std/math/consts.aipl` | `gf256Mul` | `pub fn gf256Mul(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `74` | `std/math/consts.aipl` | `gf256Inv` | `pub fn gf256Inv(b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `75` | `std/math/consts.aipl` | `gf256Div` | `pub fn gf256Div(a: int, b: int): int:` | `tests/functions/math/consts_test.aipl` |
| `76` | `std/math/consts.aipl` | `ldexpFloat` | `pub fn ldexpFloat(m: float, exp2: int): float:` | `tests/functions/math/consts_test.aipl` |
| `77` | `std/math/consts.aipl` | `sqrtSafePrescaled` | `pub fn sqrtSafePrescaled(x: float): float:` | `tests/functions/math/consts_test.aipl` |
| `78` | `std/math/curve.aipl` | `vector2ToVec2` | `pub fn vector2ToVec2(v: Vector2): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `79` | `std/math/curve.aipl` | `vec2ToVector2` | `pub fn vec2ToVector2(v: Vec2): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `80` | `std/math/curve.aipl` | `quadraticBezier2D` | `pub fn quadraticBezier2D(p0: Vec2, p1: Vec2, p2: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `81` | `std/math/curve.aipl` | `cubicBezier2D` | `pub fn cubicBezier2D(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `82` | `std/math/curve.aipl` | `catmullRom2D` | `pub fn catmullRom2D(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `83` | `std/math/curve.aipl` | `hermite2D` | `pub fn hermite2D(p0: Vec2, m0: Vec2, p1: Vec2, m1: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `84` | `std/math/curve.aipl` | `evaluateQuadraticBezier` | `pub fn evaluateQuadraticBezier(p0: Vector2, p1: Vector2, p2: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `85` | `std/math/curve.aipl` | `evaluateQuadraticBezierVec2` | `pub fn evaluateQuadraticBezierVec2(p0: Vec2, p1: Vec2, p2: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `86` | `std/math/curve.aipl` | `evaluateCubicBezier` | `pub fn evaluateCubicBezier(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `87` | `std/math/curve.aipl` | `evaluateCubicBezierVec2` | `pub fn evaluateCubicBezierVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `88` | `std/math/curve.aipl` | `evaluateCubicBezierTangentVec2` | `pub fn evaluateCubicBezierTangentVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `89` | `std/math/curve.aipl` | `evaluateCubicBezierTangent` | `pub fn evaluateCubicBezierTangent(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `90` | `std/math/curve.aipl` | `evaluateCubicBezierNormalVec2` | `pub fn evaluateCubicBezierNormalVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `91` | `std/math/curve.aipl` | `evaluateCubicBezierNormal` | `pub fn evaluateCubicBezierNormal(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `92` | `std/math/curve.aipl` | `evaluateCatmullRomVec2` | `pub fn evaluateCatmullRomVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `93` | `std/math/curve.aipl` | `evaluateCatmullRom` | `pub fn evaluateCatmullRom(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `94` | `std/math/curve.aipl` | `evaluateUniformCubicBSplineVec2` | `pub fn evaluateUniformCubicBSplineVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:` | `tests/functions/math/curve_test.aipl` |
| `95` | `std/math/curve.aipl` | `evaluateUniformCubicBSpline` | `pub fn evaluateUniformCubicBSpline(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:` | `tests/functions/math/curve_test.aipl` |
| `96` | `std/math/curve.aipl` | `evaluateCubicBezierArcLengthVec2` | `pub fn evaluateCubicBezierArcLengthVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, steps: int): float:` | `tests/functions/math/curve_test.aipl` |
| `97` | `std/math/curve.aipl` | `evaluateCubicBezierArcLength` | `pub fn evaluateCubicBezierArcLength(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, steps: int): float:` | `tests/functions/math/curve_test.aipl` |
| `98` | `std/math/ease.aipl` | `easeLinear` | `pub fn easeLinear(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `99` | `std/math/ease.aipl` | `easeInQuad` | `pub fn easeInQuad(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `100` | `std/math/ease.aipl` | `easeOutQuad` | `pub fn easeOutQuad(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `101` | `std/math/ease.aipl` | `easeInOutQuad` | `pub fn easeInOutQuad(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `102` | `std/math/ease.aipl` | `easeInCubic` | `pub fn easeInCubic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `103` | `std/math/ease.aipl` | `easeOutCubic` | `pub fn easeOutCubic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `104` | `std/math/ease.aipl` | `easeInOutCubic` | `pub fn easeInOutCubic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `105` | `std/math/ease.aipl` | `easeInQuart` | `pub fn easeInQuart(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `106` | `std/math/ease.aipl` | `easeOutQuart` | `pub fn easeOutQuart(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `107` | `std/math/ease.aipl` | `easeInOutQuart` | `pub fn easeInOutQuart(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `108` | `std/math/ease.aipl` | `easeInBack` | `pub fn easeInBack(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `109` | `std/math/ease.aipl` | `easeOutBack` | `pub fn easeOutBack(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `110` | `std/math/ease.aipl` | `easeInOutBack` | `pub fn easeInOutBack(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `111` | `std/math/ease.aipl` | `easeInElastic` | `pub fn easeInElastic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `112` | `std/math/ease.aipl` | `easeOutElastic` | `pub fn easeOutElastic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `113` | `std/math/ease.aipl` | `easeInOutElastic` | `pub fn easeInOutElastic(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `114` | `std/math/ease.aipl` | `easeOutBounce` | `pub fn easeOutBounce(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `115` | `std/math/ease.aipl` | `easeInBounce` | `pub fn easeInBounce(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `116` | `std/math/ease.aipl` | `easeInOutBounce` | `pub fn easeInOutBounce(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `117` | `std/math/ease.aipl` | `easeSmoothstep` | `pub fn easeSmoothstep(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `118` | `std/math/ease.aipl` | `easeSmootherstep` | `pub fn easeSmootherstep(t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `119` | `std/math/ease.aipl` | `evalEase` | `pub fn evalEase(mode: int, t: float): float:` | `tests/functions/math/ease_test.aipl` |
| `120` | `std/math/fixed_point.aipl` | `fixedFromInt` | `pub fn fixedFromInt(val: int): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `121` | `std/math/fixed_point.aipl` | `fixedFromFloat` | `pub fn fixedFromFloat(val: float): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `122` | `std/math/fixed_point.aipl` | `toInt` | `pub fn (self: FixedQ16_16) toInt(): int:` | `tests/functions/math/fixed_point_test.aipl` |
| `123` | `std/math/fixed_point.aipl` | `toFloat` | `pub fn (self: FixedQ16_16) toFloat(): float:` | `tests/functions/math/fixed_point_test.aipl` |
| `124` | `std/math/fixed_point.aipl` | `add` | `pub fn (self: FixedQ16_16) add(other: FixedQ16_16): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `125` | `std/math/fixed_point.aipl` | `sub` | `pub fn (self: FixedQ16_16) sub(other: FixedQ16_16): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `126` | `std/math/fixed_point.aipl` | `mul` | `pub fn (self: FixedQ16_16) mul(other: FixedQ16_16): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `127` | `std/math/fixed_point.aipl` | `div` | `pub fn (self: FixedQ16_16) div(other: FixedQ16_16): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `128` | `std/math/fixed_point.aipl` | `abs` | `pub fn (self: FixedQ16_16) abs(): FixedQ16_16:` | `tests/functions/math/fixed_point_test.aipl` |
| `129` | `std/math/fixed_point.aipl` | `fixedQ32FromInt` | `pub fn fixedQ32FromInt(val: int): FixedQ32_32:` | `tests/functions/math/fixed_point_test.aipl` |
| `130` | `std/math/fixed_point.aipl` | `toInt` | `pub fn (self: FixedQ32_32) toInt(): int:` | `tests/functions/math/fixed_point_test.aipl` |
| `131` | `std/math/fixed_point.aipl` | `add` | `pub fn (self: FixedQ32_32) add(other: FixedQ32_32): FixedQ32_32:` | `tests/functions/math/fixed_point_test.aipl` |
| `132` | `std/math/fixed_point.aipl` | `sub` | `pub fn (self: FixedQ32_32) sub(other: FixedQ32_32): FixedQ32_32:` | `tests/functions/math/fixed_point_test.aipl` |
| `133` | `std/math/geom2d.aipl` | `Rect.new` | `pub fn Rect.new(x: float, y: float, w: float, h: float): Rect:` | `tests/functions/math/geom2d_test.aipl` |
| `134` | `std/math/geom2d.aipl` | `contains` | `pub fn (self: Rect) contains(px: float, py: float): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `135` | `std/math/geom2d.aipl` | `intersects` | `pub fn (self: Rect) intersects(other: Rect): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `136` | `std/math/geom2d.aipl` | `vec2New` | `pub fn vec2New(x: float, y: float): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `137` | `std/math/geom2d.aipl` | `ivec2` | `pub fn ivec2(x: int, y: int): IVec2:` | `tests/functions/math/geom2d_test.aipl` |
| `138` | `std/math/geom2d.aipl` | `rect` | `pub fn rect(x: float, y: float, w: float, h: float): Rect:` | `tests/functions/math/geom2d_test.aipl` |
| `139` | `std/math/geom2d.aipl` | `irect` | `pub fn irect(x: int, y: int, w: int, h: int): IRect:` | `tests/functions/math/geom2d_test.aipl` |
| `140` | `std/math/geom2d.aipl` | `rectToRect2D` | `pub fn rectToRect2D(r: Rect): Rect2D:` | `tests/functions/math/geom2d_test.aipl` |
| `141` | `std/math/geom2d.aipl` | `rectFromRect2D` | `pub fn rectFromRect2D(r: Rect2D): Rect:` | `tests/functions/math/geom2d_test.aipl` |
| `142` | `std/math/geom2d.aipl` | `vec2Add` | `pub fn vec2Add(a: Vec2, b: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `143` | `std/math/geom2d.aipl` | `vec2Sub` | `pub fn vec2Sub(a: Vec2, b: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `144` | `std/math/geom2d.aipl` | `vec2Scale` | `pub fn vec2Scale(v: Vec2, s: float): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `145` | `std/math/geom2d.aipl` | `vec2Dot` | `pub fn vec2Dot(a: Vec2, b: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `146` | `std/math/geom2d.aipl` | `vec2Cross` | `pub fn vec2Cross(a: Vec2, b: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `147` | `std/math/geom2d.aipl` | `vec2Len` | `pub fn vec2Len(v: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `148` | `std/math/geom2d.aipl` | `vec2Dist` | `pub fn vec2Dist(a: Vec2, b: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `149` | `std/math/geom2d.aipl` | `vec2Norm` | `pub fn vec2Norm(v: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `150` | `std/math/geom2d.aipl` | `vec2Rotate` | `pub fn vec2Rotate(v: Vec2, radians: float): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `151` | `std/math/geom2d.aipl` | `vec2Reflect` | `pub fn vec2Reflect(v: Vec2, normal: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `152` | `std/math/geom2d.aipl` | `rectContainsPoint` | `pub fn rectContainsPoint(r: Rect2D, p: Vec2): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `153` | `std/math/geom2d.aipl` | `rectIntersectsRect` | `pub fn rectIntersectsRect(a: Rect2D, b: Rect2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `154` | `std/math/geom2d.aipl` | `rectIntersects` | `pub fn rectIntersects(a: Rect2D, b: Rect2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `155` | `std/math/geom2d.aipl` | `pointInRect` | `pub fn pointInRect(px: float, py: float, rx: float, ry: float, rw: float, rh: float): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `156` | `std/math/geom2d.aipl` | `pointInRectInt` | `pub fn pointInRectInt(px: int, py: int, rx: int, ry: int, rw: int, rh: int): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `157` | `std/math/geom2d.aipl` | `circleIntersectsCircle` | `pub fn circleIntersectsCircle(a: Circle2D, b: Circle2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `158` | `std/math/geom2d.aipl` | `circleIntersectsRect` | `pub fn circleIntersectsRect(c: Circle2D, r: Rect2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `159` | `std/math/geom2d.aipl` | `circleRectIntersects` | `pub fn circleRectIntersects(c: Circle2D, r: Rect2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `160` | `std/math/geom2d.aipl` | `collideCircleRect` | `pub fn collideCircleRect(c: Circle2D, r: Rect2D): CollisionHit:` | `tests/functions/math/geom2d_test.aipl` |
| `161` | `std/math/geom2d.aipl` | `rayIntersectsRect2D` | `pub fn rayIntersectsRect2D(ray: Ray2D, rect: Rect2D): Option[float]:` | `tests/functions/math/geom2d_test.aipl` |
| `162` | `std/math/geom2d.aipl` | `projectPolygonMin` | `fn projectPolygonMin(poly: Polygon2D, axis: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `163` | `std/math/geom2d.aipl` | `projectPolygonMax` | `fn projectPolygonMax(poly: Polygon2D, axis: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `164` | `std/math/geom2d.aipl` | `polygonSAT2D` | `pub fn polygonSAT2D(polyA: Polygon2D, polyB: Polygon2D): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `165` | `std/math/geom2d.aipl` | `collideCircles` | `pub fn collideCircles(a: Circle2D, b: Circle2D): CollisionHit:` | `tests/functions/math/geom2d_test.aipl` |
| `166` | `std/math/geom2d.aipl` | `vec2Length` | `pub fn vec2Length(v: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `167` | `std/math/geom2d.aipl` | `vec2Normalize` | `pub fn vec2Normalize(v: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `168` | `std/math/geom2d.aipl` | `aabbIntersects` | `pub fn aabbIntersects(x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `169` | `std/math/geom2d.aipl` | `sweptAabb` | `pub fn sweptAabb(x1: float, y1: float, w1: float, h1: float, vx: float, vy: float, x2: float, y2: float, w2: float, h2: float): SweptHit:` | `tests/functions/math/geom2d_test.aipl` |
| `170` | `std/math/geom2d.aipl` | `mat2DIdentity` | `pub fn mat2DIdentity(): Mat2D:` | `tests/functions/math/geom2d_test.aipl` |
| `171` | `std/math/geom2d.aipl` | `mat2DFromTRS` | `pub fn mat2DFromTRS(tx: float, ty: float, radians: float, sx: float, sy: float): Mat2D:` | `tests/functions/math/geom2d_test.aipl` |
| `172` | `std/math/geom2d.aipl` | `mat2DMul` | `pub fn mat2DMul(m1: Mat2D, m2: Mat2D): Mat2D:` | `tests/functions/math/geom2d_test.aipl` |
| `173` | `std/math/geom2d.aipl` | `mat2DTransformPoint` | `pub fn mat2DTransformPoint(m: Mat2D, p: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `174` | `std/math/geom2d.aipl` | `intersectSegments` | `pub fn intersectSegments(p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2): SegmentHit2D:` | `tests/functions/math/geom2d_test.aipl` |
| `175` | `std/math/geom2d.aipl` | `segmentIntersect2D` | `pub fn segmentIntersect2D(p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2): SegmentHit2D:` | `tests/functions/math/geom2d_test.aipl` |
| `176` | `std/math/geom2d.aipl` | `pointInPolygon` | `pub fn pointInPolygon(pt: Vec2, poly: [Vec2]): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `177` | `std/math/geom2d.aipl` | `pointInPolygon2D` | `pub fn pointInPolygon2D(pt: Vec2, poly: [Vec2]): bool:` | `tests/functions/math/geom2d_test.aipl` |
| `178` | `std/math/geom2d.aipl` | `hullCross2D` | `fn hullCross2D(o: Vec2, a: Vec2, b: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `179` | `std/math/geom2d.aipl` | `convexHull2D` | `pub fn convexHull2D(pts: [Vec2]): [Vec2]:` | `tests/functions/math/geom2d_test.aipl` |
| `180` | `std/math/geom2d.aipl` | `worldToDisc2D` | `pub fn worldToDisc2D(origin2D: Vec2, target2D: Vec2, headingRad: float, discCenter: Vec2, discRadius: float, maxRange: float): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `181` | `std/math/geom2d.aipl` | `closestPointOnSegment2D` | `pub fn closestPointOnSegment2D(pt: Vec2, a: Vec2, b: Vec2): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `182` | `std/math/geom2d.aipl` | `distancePointToSegment2D` | `pub fn distancePointToSegment2D(pt: Vec2, a: Vec2, b: Vec2): float:` | `tests/functions/math/geom2d_test.aipl` |
| `183` | `std/math/geom2d.aipl` | `polygonArea2D` | `pub fn polygonArea2D(poly: [Vec2]): float:` | `tests/functions/math/geom2d_test.aipl` |
| `184` | `std/math/geom2d.aipl` | `polygonCentroid2D` | `pub fn polygonCentroid2D(poly: [Vec2]): Vec2:` | `tests/functions/math/geom2d_test.aipl` |
| `185` | `std/math/geom3d.aipl` | `vec3` | `pub fn vec3(x: float, y: float, z: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `186` | `std/math/geom3d.aipl` | `vec3Add` | `pub fn vec3Add(a: Vector3, b: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `187` | `std/math/geom3d.aipl` | `vec3Sub` | `pub fn vec3Sub(a: Vector3, b: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `188` | `std/math/geom3d.aipl` | `vec3Scale` | `pub fn vec3Scale(v: Vector3, s: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `189` | `std/math/geom3d.aipl` | `vec3Dot` | `pub fn vec3Dot(a: Vector3, b: Vector3): float:` | `tests/functions/math/geom3d_test.aipl` |
| `190` | `std/math/geom3d.aipl` | `vec3Cross` | `pub fn vec3Cross(a: Vector3, b: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `191` | `std/math/geom3d.aipl` | `vec3Length` | `pub fn vec3Length(v: Vector3): float:` | `tests/functions/math/geom3d_test.aipl` |
| `192` | `std/math/geom3d.aipl` | `vec3Distance` | `pub fn vec3Distance(a: Vector3, b: Vector3): float:` | `tests/functions/math/geom3d_test.aipl` |
| `193` | `std/math/geom3d.aipl` | `vec3DistanceSquared` | `pub fn vec3DistanceSquared(a: Vector3, b: Vector3): float:` | `tests/functions/math/geom3d_test.aipl` |
| `194` | `std/math/geom3d.aipl` | `vec3Lerp` | `pub fn vec3Lerp(a: Vector3, b: Vector3, t: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `195` | `std/math/geom3d.aipl` | `vec3Normalize` | `pub fn vec3Normalize(v: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `196` | `std/math/geom3d.aipl` | `rotateX` | `pub fn rotateX(v: Vector3, angle: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `197` | `std/math/geom3d.aipl` | `rotateY` | `pub fn rotateY(v: Vector3, angle: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `198` | `std/math/geom3d.aipl` | `rotateZ` | `pub fn rotateZ(v: Vector3, angle: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `199` | `std/math/geom3d.aipl` | `rotateEuler` | `pub fn rotateEuler(v: Vector3, rx: float, ry: float, rz: float): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `200` | `std/math/geom3d.aipl` | `project3D` | `pub fn project3D(v: Vector3, cameraDist: float, screenW: float, screenH: float, focalLength: float): Vector2:` | `tests/functions/math/geom3d_test.aipl` |
| `201` | `std/math/geom3d.aipl` | `aabbIntersectsAABB` | `pub fn aabbIntersectsAABB(a: AABB3D, b: AABB3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `202` | `std/math/geom3d.aipl` | `sphereIntersectsSphere` | `pub fn sphereIntersectsSphere(a: Sphere3D, b: Sphere3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `203` | `std/math/geom3d.aipl` | `rayIntersectsAABB` | `pub fn rayIntersectsAABB(ray: Ray3D, aabb: AABB3D): Option[float]:` | `tests/functions/math/geom3d_test.aipl` |
| `204` | `std/math/geom3d.aipl` | `rayIntersectsTriangle` | `pub fn rayIntersectsTriangle(ray: Ray3D, tri: Triangle3D): Option[float]:` | `tests/functions/math/geom3d_test.aipl` |
| `205` | `std/math/geom3d.aipl` | `frustumContainsPoint` | `pub fn frustumContainsPoint(frustum: Frustum3D, pt: Vec3): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `206` | `std/math/geom3d.aipl` | `frustumIntersectsAABB` | `pub fn frustumIntersectsAABB(frustum: Frustum3D, aabb: AABB3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `207` | `std/math/geom3d.aipl` | `vec3Reflect` | `pub fn vec3Reflect(v: Vector3, normal: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `208` | `std/math/geom3d.aipl` | `aabb3DIntersects` | `pub fn aabb3DIntersects(minA: Vector3, maxA: Vector3, minB: Vector3, maxB: Vector3): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `209` | `std/math/geom3d.aipl` | `aabbContainsPoint` | `pub fn aabbContainsPoint(box: AABB3D, pt: Vec3): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `210` | `std/math/geom3d.aipl` | `aabbIntersects3D` | `pub fn aabbIntersects3D(a: AABB3D, b: AABB3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `211` | `std/math/geom3d.aipl` | `aabb3DIntersectsBox` | `pub fn aabb3DIntersectsBox(a: AABB3D, b: AABB3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `212` | `std/math/geom3d.aipl` | `aabbFromCenterExtents` | `pub fn aabbFromCenterExtents(center: Vec3, halfExtents: Vec3): AABB3D:` | `tests/functions/math/geom3d_test.aipl` |
| `213` | `std/math/geom3d.aipl` | `aabb2DTo3D` | `pub fn aabb2DTo3D(x: float, z: float, w: float, d: float, height: float): AABB3D:` | `tests/functions/math/geom3d_test.aipl` |
| `214` | `std/math/geom3d.aipl` | `screenToWorldRay` | `pub fn screenToWorldRay(mouseX: float, mouseY: float, screenW: float, screenH: float, camPos: Vector3, camTarget: Vector3, camUp: Vector3, fovyDeg: float): Ray3D:` | `tests/functions/math/geom3d_test.aipl` |
| `215` | `std/math/geom3d.aipl` | `rayIntersectTriangle` | `pub fn rayIntersectTriangle(ray: Ray3D, v0: Vector3, v1: Vector3, v2: Vector3): GeomRayHit3D:` | `tests/functions/math/geom3d_test.aipl` |
| `216` | `std/math/geom3d.aipl` | `rayIntersectAABB` | `pub fn rayIntersectAABB(ray: Ray3D, box: AABB3D): GeomRayHit3D:` | `tests/functions/math/geom3d_test.aipl` |
| `217` | `std/math/geom3d.aipl` | `rayIntersectSphere` | `pub fn rayIntersectSphere(ray: Ray3D, center: Vector3, radius: float): GeomRayHit3D:` | `tests/functions/math/geom3d_test.aipl` |
| `218` | `std/math/geom3d.aipl` | `sweepSphereAABB` | `pub fn sweepSphereAABB(center: Vector3, radius: float, vel: Vector3, box: AABB3D): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `219` | `std/math/geom3d.aipl` | `capsuleIntersectsAABB` | `pub fn capsuleIntersectsAABB(cap: Capsule3D, box: AABB3D): bool:` | `tests/functions/math/geom3d_test.aipl` |
| `220` | `std/math/geom3d.aipl` | `rayIntersectsCylinder` | `pub fn rayIntersectsCylinder(rayOrigin: Vector3, rayDir: Vector3, cylCenter: Vector3, radius: float, height: float): Option[float]:` | `tests/functions/math/geom3d_test.aipl` |
| `221` | `std/math/geom3d.aipl` | `eulerToAngleVectors` | `pub fn eulerToAngleVectors(pitchDeg: float, yawDeg: float, rollDeg: float = 0.0): EulerVectors:` | `tests/functions/math/geom3d_test.aipl` |
| `222` | `std/math/geom3d.aipl` | `radialAttenuation` | `pub fn radialAttenuation(origin: Vector3, target: Vector3, maxRadius: float, curve: float = 1.0): float:` | `tests/functions/math/geom3d_test.aipl` |
| `223` | `std/math/geom3d.aipl` | `transform3DIdentity` | `pub fn transform3DIdentity(): EulerTransform3D:` | `tests/functions/math/geom3d_test.aipl` |
| `224` | `std/math/geom3d.aipl` | `transform3DPoint` | `pub fn transform3DPoint(t: EulerTransform3D, p: Vector3): Vector3:` | `tests/functions/math/geom3d_test.aipl` |
| `225` | `std/math/mat.aipl` | `Mat2.identity` | `pub fn Mat2.identity(): Mat2:` | `tests/functions/math/mat_test.aipl` |
| `226` | `std/math/mat.aipl` | `Mat2.rotation` | `pub fn Mat2.rotation(rad: float): Mat2:` | `tests/functions/math/mat_test.aipl` |
| `227` | `std/math/mat.aipl` | `transformVec2` | `pub fn (self: Mat2) transformVec2(v: Vec2): Vec2:` | `tests/functions/math/mat_test.aipl` |
| `228` | `std/math/mat.aipl` | `det` | `pub fn (self: Mat2) det(): float:` | `tests/functions/math/mat_test.aipl` |
| `229` | `std/math/mat.aipl` | `Mat3.identity` | `pub fn Mat3.identity(): Mat3:` | `tests/functions/math/mat_test.aipl` |
| `230` | `std/math/mat.aipl` | `transformVec3` | `pub fn (self: Mat3) transformVec3(v: Vec3): Vec3:` | `tests/functions/math/mat_test.aipl` |
| `231` | `std/math/mat.aipl` | `Mat4.identity` | `pub fn Mat4.identity(): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `232` | `std/math/mat.aipl` | `Mat4.translation` | `pub fn Mat4.translation(x: float, y: float, z: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `233` | `std/math/mat.aipl` | `Mat4.scaling` | `pub fn Mat4.scaling(sx: float, sy: float, sz: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `234` | `std/math/mat.aipl` | `Mat4.rotationX` | `pub fn Mat4.rotationX(rad: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `235` | `std/math/mat.aipl` | `Mat4.rotationY` | `pub fn Mat4.rotationY(rad: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `236` | `std/math/mat.aipl` | `Mat4.rotationZ` | `pub fn Mat4.rotationZ(rad: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `237` | `std/math/mat.aipl` | `Mat4.perspective` | `pub fn Mat4.perspective(fovyRad: float, aspect: float, near: float, far: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `238` | `std/math/mat.aipl` | `Mat4.orthographic` | `pub fn Mat4.orthographic(left: float, right: float, bottom: float, top: float, near: float, far: float): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `239` | `std/math/mat.aipl` | `Mat4.lookAt` | `pub fn Mat4.lookAt(eye: Vec3, target: Vec3, up: Vec3): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `240` | `std/math/mat.aipl` | `mul` | `pub fn (self: Mat4) mul(other: Mat4): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `241` | `std/math/mat.aipl` | `transformVec4` | `pub fn (self: Mat4) transformVec4(v: Vec4): Vec4:` | `tests/functions/math/mat_test.aipl` |
| `242` | `std/math/mat.aipl` | `transpose` | `pub fn (self: Mat4) transpose(): Mat4:` | `tests/functions/math/mat_test.aipl` |
| `243` | `std/math/mat.aipl` | `inverse` | `pub fn (self: Mat4) inverse(): Option[Mat4]:` | `tests/functions/math/mat_test.aipl` |
| `244` | `std/math/mat.aipl` | `mat3Identity` | `pub fn mat3Identity(): Mat3:` | `tests/functions/math/mat_test.aipl` |
| `245` | `std/math/mat.aipl` | `mat3TransformVec3` | `pub fn mat3TransformVec3(mat: Mat3, v: Vector3): Vector3:` | `tests/functions/math/mat_test.aipl` |
| `246` | `std/math/mat.aipl` | `mat3Mul` | `pub fn mat3Mul(a: Mat3, b: Mat3): Mat3:` | `tests/functions/math/mat_test.aipl` |
| `247` | `std/math/mat.aipl` | `mat3Det` | `pub fn mat3Det(m: Mat3): float:` | `tests/functions/math/mat_test.aipl` |
| `248` | `std/math/prng.aipl` | `splitMix64Next` | `pub fn splitMix64Next(state: int): [int]:` | `tests/functions/math/prng_test.aipl` |
| `249` | `std/math/prng.aipl` | `pcg32Next` | `pub fn pcg32Next(state: int, inc: int): [int]:` | `tests/functions/math/prng_test.aipl` |
| `250` | `std/math/prng.aipl` | `pcg32Init` | `pub fn pcg32Init(seed: int, seq: int = 54): Pcg32Rng:` | `tests/functions/math/prng_test.aipl` |
| `251` | `std/math/prng.aipl` | `nextU32` | `pub fn (mut self: Pcg32Rng) nextU32(): int:` | `tests/functions/math/prng_test.aipl` |
| `252` | `std/math/prng.aipl` | `nextFloat` | `pub fn (mut self: Pcg32Rng) nextFloat(): float:` | `tests/functions/math/prng_test.aipl` |
| `253` | `std/math/prng.aipl` | `rangeInt` | `pub fn (mut self: Pcg32Rng) rangeInt(minVal: int, maxVal: int): int:` | `tests/functions/math/prng_test.aipl` |
| `254` | `std/math/prng.aipl` | `xoshiro256Init` | `pub fn xoshiro256Init(seed: int): Xoshiro256Rng:` | `tests/functions/math/prng_test.aipl` |
| `255` | `std/math/prng.aipl` | `nextU64` | `pub fn (mut self: Xoshiro256Rng) nextU64(): int:` | `tests/functions/math/prng_test.aipl` |
| `256` | `std/math/prng.aipl` | `rngNew` | `pub fn rngNew(seed: int): Rng:` | `tests/functions/math/prng_test.aipl` |
| `257` | `std/math/prng.aipl` | `rngNext` | `pub fn rngNext(mut rng: Rng): (Rng, int):` | `tests/functions/math/prng_test.aipl` |
| `258` | `std/math/prng.aipl` | `rngNextInt` | `pub fn rngNextInt(mut rng: Rng, minVal: int, maxVal: int): (Rng, int):` | `tests/functions/math/prng_test.aipl` |
| `259` | `std/math/prng.aipl` | `rngNextFloat` | `pub fn rngNextFloat(mut rng: Rng): (Rng, float):` | `tests/functions/math/prng_test.aipl` |
| `260` | `std/math/prng.aipl` | `setRandomSeed` | `pub fn setRandomSeed(seed: int): void:` | `tests/functions/math/prng_test.aipl` |
| `261` | `std/math/prng.aipl` | `randomFloat` | `pub fn randomFloat(): float:` | `tests/functions/math/prng_test.aipl` |
| `262` | `std/math/prng.aipl` | `randomRange` | `pub fn randomRange(minVal: float, maxVal: float): float:` | `tests/functions/math/prng_test.aipl` |
| `263` | `std/math/prng.aipl` | `randomIntRange` | `pub fn randomIntRange(minVal: int, maxVal: int): int:` | `tests/functions/math/prng_test.aipl` |
| `264` | `std/math/prng.aipl` | `randomBool` | `pub fn randomBool(probability: float = 0.5): bool:` | `tests/functions/math/prng_test.aipl` |
| `265` | `std/math/prng.aipl` | `randomSign` | `pub fn randomSign(): float:` | `tests/functions/math/prng_test.aipl` |
| `266` | `std/math/prng.aipl` | `randomAngle` | `pub fn randomAngle(): float:` | `tests/functions/math/prng_test.aipl` |
| `267` | `std/math/prng.aipl` | `randomGaussian` | `pub fn randomGaussian(): float:` | `tests/functions/math/prng_test.aipl` |
| `268` | `std/math/prng.aipl` | `randomInCircleX` | `pub fn randomInCircleX(radius: float): float:` | `tests/functions/math/prng_test.aipl` |
| `269` | `std/math/prng.aipl` | `randomInCircleY` | `pub fn randomInCircleY(radius: float): float:` | `tests/functions/math/prng_test.aipl` |
| `270` | `std/math/prng.aipl` | `shuffleInts` | `pub fn shuffleInts(arr: [int], seed: int): [int]:` | `tests/functions/math/prng_test.aipl` |
| `271` | `std/math/prng.aipl` | `createRng` | `pub fn createRng(initialSeed: int): RngState:` | `tests/functions/math/prng_test.aipl` |
| `272` | `std/math/prng.aipl` | `nextRng` | `pub fn nextRng(rng: RngState): RngState:` | `tests/functions/math/prng_test.aipl` |
| `273` | `std/math/prng.aipl` | `randomInt` | `pub fn randomInt(rng: RngState, minVal: int, maxVal: int): int:` | `tests/functions/math/prng_test.aipl` |
| `274` | `std/math/prob_stats.aipl` | `sampleWeightedIndex` | `pub fn sampleWeightedIndex(weights: [int], roll: int): int:` | `tests/functions/math/prob_stats_test.aipl` |
| `275` | `std/math/prob_stats.aipl` | `gaussianSample` | `pub fn gaussianSample(mean: float, stdDev: float, u1: float, u2: float): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `276` | `std/math/prob_stats.aipl` | `poissonSample` | `pub fn poissonSample(lambda: float, u: float): int:` | `tests/functions/math/prob_stats_test.aipl` |
| `277` | `std/math/prob_stats.aipl` | `computeMean` | `pub fn computeMean(values: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `278` | `std/math/prob_stats.aipl` | `computeVariance` | `pub fn computeVariance(values: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `279` | `std/math/prob_stats.aipl` | `computeStdDev` | `pub fn computeStdDev(values: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `280` | `std/math/prob_stats.aipl` | `computeSummaryStats` | `pub fn computeSummaryStats(values: [float]): SummaryStats:` | `tests/functions/math/prob_stats_test.aipl` |
| `281` | `std/math/prob_stats.aipl` | `kalman1DNew` | `pub fn kalman1DNew(initialEstimate: float, initialError: float, processNoise: float, measurementNoise: float): KalmanFilter1D:` | `tests/functions/math/prob_stats_test.aipl` |
| `282` | `std/math/prob_stats.aipl` | `kalman1DUpdate` | `pub fn kalman1DUpdate(kf: KalmanFilter1D, measurement: float): KalmanFilter1D:` | `tests/functions/math/prob_stats_test.aipl` |
| `283` | `std/math/prob_stats.aipl` | `statsMean` | `pub fn statsMean(vals: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `284` | `std/math/prob_stats.aipl` | `statsPercentile` | `pub fn statsPercentile(sortedVals: [float], p: float): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `285` | `std/math/prob_stats.aipl` | `percentile` | `pub fn percentile(sortedValues: [float], p: float): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `286` | `std/math/prob_stats.aipl` | `summaryStats` | `pub fn summaryStats(vals: [float]): SummaryStats:` | `tests/functions/math/prob_stats_test.aipl` |
| `287` | `std/math/prob_stats.aipl` | `hdrHistogramNew` | `pub fn hdrHistogramNew(): HdrHistogram:` | `tests/functions/math/prob_stats_test.aipl` |
| `288` | `std/math/prob_stats.aipl` | `hdrRecord` | `pub fn hdrRecord(mut h: HdrHistogram, v: float): HdrHistogram:` | `tests/functions/math/prob_stats_test.aipl` |
| `289` | `std/math/prob_stats.aipl` | `hdrMean` | `pub fn hdrMean(h: HdrHistogram): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `290` | `std/math/prob_stats.aipl` | `evalPiecewiseLinearCurve` | `pub fn evalPiecewiseLinearCurve(x: float, knotsX: [float], knotsY: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `291` | `std/math/prob_stats.aipl` | `evalTieredMarginalRate` | `pub fn evalTieredMarginalRate(amount: float, thresholds: [float], rates: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `292` | `std/math/prob_stats.aipl` | `movingAverage` | `pub fn movingAverage(values: [float], windowSize: int): [float]:` | `tests/functions/math/prob_stats_test.aipl` |
| `293` | `std/math/prob_stats.aipl` | `exponentialMovingAverage` | `pub fn exponentialMovingAverage(values: [float], alpha: float): [float]:` | `tests/functions/math/prob_stats_test.aipl` |
| `294` | `std/math/prob_stats.aipl` | `commComputeTieredAcceleratorPayout` | `pub fn commComputeTieredAcceleratorPayout(attainmentPct: int, baseCommission: int, tier1MultPct: int, tier2MultPct: int): int:` | `tests/functions/math/prob_stats_test.aipl` |
| `295` | `std/math/prob_stats.aipl` | `computeCovariance` | `pub fn computeCovariance(xs: [float], ys: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `296` | `std/math/prob_stats.aipl` | `computeCorrelation` | `pub fn computeCorrelation(xs: [float], ys: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `297` | `std/math/prob_stats.aipl` | `linearRegressionSlope` | `pub fn linearRegressionSlope(xs: [float], ys: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `298` | `std/math/prob_stats.aipl` | `linearRegressionIntercept` | `pub fn linearRegressionIntercept(xs: [float], ys: [float]): float:` | `tests/functions/math/prob_stats_test.aipl` |
| `299` | `std/math/quat.aipl` | `Quat.identity` | `pub fn Quat.identity(): Quat:` | `tests/functions/math/quat_test.aipl` |
| `300` | `std/math/quat.aipl` | `Quat.fromAxisAngle` | `pub fn Quat.fromAxisAngle(axis: Vec3, rad: float): Quat:` | `tests/functions/math/quat_test.aipl` |
| `301` | `std/math/quat.aipl` | `Quat.fromEuler` | `pub fn Quat.fromEuler(pitch: float, yaw: float, roll: float): Quat:` | `tests/functions/math/quat_test.aipl` |
| `302` | `std/math/quat.aipl` | `lenSq` | `pub fn (self: Quat) lenSq(): float:` | `tests/functions/math/quat_test.aipl` |
| `303` | `std/math/quat.aipl` | `len` | `pub fn (self: Quat) len(): float:` | `tests/functions/math/quat_test.aipl` |
| `304` | `std/math/quat.aipl` | `norm` | `pub fn (self: Quat) norm(): Quat:` | `tests/functions/math/quat_test.aipl` |
| `305` | `std/math/quat.aipl` | `conjugate` | `pub fn (self: Quat) conjugate(): Quat:` | `tests/functions/math/quat_test.aipl` |
| `306` | `std/math/quat.aipl` | `mul` | `pub fn (self: Quat) mul(other: Quat): Quat:` | `tests/functions/math/quat_test.aipl` |
| `307` | `std/math/quat.aipl` | `slerp` | `pub fn (self: Quat) slerp(target: Quat, t: float): Quat:` | `tests/functions/math/quat_test.aipl` |
| `308` | `std/math/quat.aipl` | `rotateVec3` | `pub fn (self: Quat) rotateVec3(v: Vec3): Vec3:` | `tests/functions/math/quat_test.aipl` |
| `309` | `std/math/quat.aipl` | `toMat4` | `pub fn (self: Quat) toMat4(): Mat4:` | `tests/functions/math/quat_test.aipl` |
| `310` | `std/math/simd.aipl` | `f32x4Add` | `pub fn f32x4Add(a: F32x4, b: F32x4): F32x4:` | `tests/functions/math/simd_test.aipl` |
| `311` | `std/math/simd.aipl` | `f32x4Sub` | `pub fn f32x4Sub(a: F32x4, b: F32x4): F32x4:` | `tests/functions/math/simd_test.aipl` |
| `312` | `std/math/simd.aipl` | `f32x4Mul` | `pub fn f32x4Mul(a: F32x4, b: F32x4): F32x4:` | `tests/functions/math/simd_test.aipl` |
| `313` | `std/math/simd.aipl` | `f32x4Dot` | `pub fn f32x4Dot(a: F32x4, b: F32x4): float:` | `tests/functions/math/simd_test.aipl` |
| `314` | `std/math/simd.aipl` | `f32x4Min` | `pub fn f32x4Min(a: F32x4, b: F32x4): F32x4:` | `tests/functions/math/simd_test.aipl` |
| `315` | `std/math/simd.aipl` | `f32x4Max` | `pub fn f32x4Max(a: F32x4, b: F32x4): F32x4:` | `tests/functions/math/simd_test.aipl` |
| `316` | `std/math/simd.aipl` | `tensorDot` | `pub fn tensorDot(a: [float], b: [float]): float:` | `tests/functions/math/simd_test.aipl` |
| `317` | `std/math/simd.aipl` | `tensorMatmul` | `pub fn tensorMatmul(a: [float], b: [float], m: int, n: int, k: int): [float]:` | `tests/functions/math/simd_test.aipl` |
| `318` | `std/math/simd.aipl` | `tensorSoftmax` | `pub fn tensorSoftmax(a: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `319` | `std/math/simd.aipl` | `tensorCosineSimilarity` | `pub fn tensorCosineSimilarity(a: [float], b: [float]): float:` | `tests/functions/math/simd_test.aipl` |
| `320` | `std/math/simd.aipl` | `tensorLayerNorm` | `pub fn tensorLayerNorm(a: [float], eps: float = 0.00001): [float]:` | `tests/functions/math/simd_test.aipl` |
| `321` | `std/math/simd.aipl` | `analyzeSimdLoopAutoVectorization` | `pub fn analyzeSimdLoopAutoVectorization(strideElem: int, tripCount: int, hasLoopCarriedDep: bool, targetBits: int): SimdLoopVectorPlan:` | `tests/functions/math/simd_test.aipl` |
| `322` | `std/math/simd.aipl` | `simdDotProduct8Wide` | `pub fn simdDotProduct8Wide(a: [float], b: [float]): float:` | `tests/functions/math/simd_test.aipl` |
| `323` | `std/math/simd.aipl` | `simdAxpy8Wide` | `pub fn simdAxpy8Wide(alpha: float, x: [float], y: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `324` | `std/math/simd.aipl` | `intBufferNew` | `pub fn intBufferNew(size: int): [int]:` | `tests/functions/math/simd_test.aipl` |
| `325` | `std/math/simd.aipl` | `intBufferGet` | `pub fn intBufferGet(buf: [int], idx: int): int:` | `tests/functions/math/simd_test.aipl` |
| `326` | `std/math/simd.aipl` | `intBufferSet` | `pub fn intBufferSet(buf: [int], idx: int, val: int): [int]:` | `tests/functions/math/simd_test.aipl` |
| `327` | `std/math/simd.aipl` | `intBufferLen` | `pub fn intBufferLen(buf: [int]): int:` | `tests/functions/math/simd_test.aipl` |
| `328` | `std/math/simd.aipl` | `floatBufferNew` | `pub fn floatBufferNew(size: int): [float]:` | `tests/functions/math/simd_test.aipl` |
| `329` | `std/math/simd.aipl` | `floatBufferGet` | `pub fn floatBufferGet(buf: [float], idx: int): float:` | `tests/functions/math/simd_test.aipl` |
| `330` | `std/math/simd.aipl` | `floatBufferSet` | `pub fn floatBufferSet(buf: [float], idx: int, val: float): [float]:` | `tests/functions/math/simd_test.aipl` |
| `331` | `std/math/simd.aipl` | `floatBufferLen` | `pub fn floatBufferLen(buf: [float]): int:` | `tests/functions/math/simd_test.aipl` |
| `332` | `std/math/simd.aipl` | `sumIntsFast` | `pub fn sumIntsFast(arr: [int]): int:` | `tests/functions/math/simd_test.aipl` |
| `333` | `std/math/simd.aipl` | `sumFloatsFast` | `pub fn sumFloatsFast(arr: [float]): float:` | `tests/functions/math/simd_test.aipl` |
| `334` | `std/math/simd.aipl` | `dotProductFloats` | `pub fn dotProductFloats(a: [float], b: [float]): float:` | `tests/functions/math/simd_test.aipl` |
| `335` | `std/math/simd.aipl` | `axpyFloats` | `pub fn axpyFloats(alpha: float, x: [float], y: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `336` | `std/math/simd.aipl` | `simdFma4Wide` | `pub fn simdFma4Wide(a: [float], b: [float], c: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `337` | `std/math/simd.aipl` | `simdMatmul4x4Tiled` | `pub fn simdMatmul4x4Tiled(a: [float], b: [float], n: int): [float]:` | `tests/functions/math/simd_test.aipl` |
| `338` | `std/math/simd.aipl` | `tensorAdd` | `pub fn tensorAdd(a: [float], b: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `339` | `std/math/simd.aipl` | `tensorScale` | `pub fn tensorScale(a: [float], s: float): [float]:` | `tests/functions/math/simd_test.aipl` |
| `340` | `std/math/simd.aipl` | `tensorRelu` | `pub fn tensorRelu(a: [float]): [float]:` | `tests/functions/math/simd_test.aipl` |
| `341` | `std/math/simd.aipl` | `tensorTranspose` | `pub fn tensorTranspose(a: [float], rows: int, cols: int): [float]:` | `tests/functions/math/simd_test.aipl` |
| `342` | `std/math/trig.aipl` | `degToRad` | `pub fn degToRad(deg: float): float:` | `tests/functions/math/trig_test.aipl` |
| `343` | `std/math/trig.aipl` | `radToDeg` | `pub fn radToDeg(rad: float): float:` | `tests/functions/math/trig_test.aipl` |
| `344` | `std/math/trig.aipl` | `sqrt` | `pub fn sqrt(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `345` | `std/math/trig.aipl` | `cbrt` | `pub fn cbrt(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `346` | `std/math/trig.aipl` | `hypot` | `pub fn hypot(x: float, y: float): float:` | `tests/functions/math/trig_test.aipl` |
| `347` | `std/math/trig.aipl` | `powInt` | `pub fn powInt(base: float, exp: int): float:` | `tests/functions/math/trig_test.aipl` |
| `348` | `std/math/trig.aipl` | `lnFloat` | `pub fn lnFloat(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `349` | `std/math/trig.aipl` | `expFloat` | `pub fn expFloat(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `350` | `std/math/trig.aipl` | `pow` | `pub fn pow(base: float, exponent: float): float:` | `tests/functions/math/trig_test.aipl` |
| `351` | `std/math/trig.aipl` | `sin` | `pub fn sin(rad: float): float:` | `tests/functions/math/trig_test.aipl` |
| `352` | `std/math/trig.aipl` | `cos` | `pub fn cos(rad: float): float:` | `tests/functions/math/trig_test.aipl` |
| `353` | `std/math/trig.aipl` | `tan` | `pub fn tan(rad: float): float:` | `tests/functions/math/trig_test.aipl` |
| `354` | `std/math/trig.aipl` | `atan` | `pub fn atan(z: float): float:` | `tests/functions/math/trig_test.aipl` |
| `355` | `std/math/trig.aipl` | `atan2` | `pub fn atan2(y: float, x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `356` | `std/math/trig.aipl` | `asin` | `pub fn asin(v: float): float:` | `tests/functions/math/trig_test.aipl` |
| `357` | `std/math/trig.aipl` | `acos` | `pub fn acos(v: float): float:` | `tests/functions/math/trig_test.aipl` |
| `358` | `std/math/trig.aipl` | `sinh` | `pub fn sinh(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `359` | `std/math/trig.aipl` | `cosh` | `pub fn cosh(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `360` | `std/math/trig.aipl` | `tanh` | `pub fn tanh(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `361` | `std/math/trig.aipl` | `sineWave` | `pub fn sineWave(amplitude: float, frequency: float, t: float): float:` | `tests/functions/math/trig_test.aipl` |
| `362` | `std/math/trig.aipl` | `cosineWave` | `pub fn cosineWave(amplitude: float, frequency: float, t: float): float:` | `tests/functions/math/trig_test.aipl` |
| `363` | `std/math/trig.aipl` | `sawtoothWave` | `pub fn sawtoothWave(amplitude: float, frequency: float, t: float): float:` | `tests/functions/math/trig_test.aipl` |
| `364` | `std/math/trig.aipl` | `triangleWave` | `pub fn triangleWave(amplitude: float, frequency: float, t: float): float:` | `tests/functions/math/trig_test.aipl` |
| `365` | `std/math/trig.aipl` | `squareWave` | `pub fn squareWave(amplitude: float, frequency: float, t: float, dutyCycle: float = 0.5): float:` | `tests/functions/math/trig_test.aipl` |
| `366` | `std/math/trig.aipl` | `log2Float` | `pub fn log2Float(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `367` | `std/math/trig.aipl` | `log10Float` | `pub fn log10Float(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `368` | `std/math/trig.aipl` | `sincFloat` | `pub fn sincFloat(x: float): float:` | `tests/functions/math/trig_test.aipl` |
| `369` | `std/math/trig.aipl` | `wrapAngle` | `pub fn wrapAngle(angle: float): float:` | `tests/functions/math/trig_test.aipl` |
| `370` | `std/math/trig.aipl` | `wrapAnglePi` | `pub fn wrapAnglePi(angle: float): float:` | `tests/functions/math/trig_test.aipl` |
| `371` | `std/math/trig.aipl` | `angleDeltaRad` | `pub fn angleDeltaRad(target: float, source: float): float:` | `tests/functions/math/trig_test.aipl` |
| `372` | `std/math/trig.aipl` | `wrapAngleDeg` | `pub fn wrapAngleDeg(deg: float): float:` | `tests/functions/math/trig_test.aipl` |
| `373` | `std/math/trig.aipl` | `angleDeltaDeg` | `pub fn angleDeltaDeg(targetDeg: float, sourceDeg: float): float:` | `tests/functions/math/trig_test.aipl` |
| `374` | `std/math/trig.aipl` | `wrapAngleByte` | `pub fn wrapAngleByte(b: int): int:` | `tests/functions/math/trig_test.aipl` |
| `375` | `std/math/trig.aipl` | `angleDeltaByte` | `pub fn angleDeltaByte(targetByte: int, sourceByte: int): int:` | `tests/functions/math/trig_test.aipl` |
| `376` | `std/math/trig.aipl` | `stepAngleByte` | `pub fn stepAngleByte(currentByte: int, targetByte: int, maxStep: int): int:` | `tests/functions/math/trig_test.aipl` |
| `377` | `std/math/trig.aipl` | `vec2RotateFixed` | `pub fn vec2RotateFixed(x: int, y: int, angleBytes: int): (int, int):` | `tests/functions/math/trig_test.aipl` |
| `378` | `std/math/vec_math.aipl` | `Vec2.new` | `pub fn Vec2.new(x: float, y: float): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `379` | `std/math/vec_math.aipl` | `Vector2.new` | `pub fn Vector2.new(x: float, y: float): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `380` | `std/math/vec_math.aipl` | `toVector2` | `pub fn (self: Vec2) toVector2(): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `381` | `std/math/vec_math.aipl` | `toVec2` | `pub fn (self: Vector2) toVec2(): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `382` | `std/math/vec_math.aipl` | `add` | `pub fn (self: Vec2) add(other: Vec2): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `383` | `std/math/vec_math.aipl` | `sub` | `pub fn (self: Vec2) sub(other: Vec2): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `384` | `std/math/vec_math.aipl` | `scale` | `pub fn (self: Vec2) scale(s: float): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `385` | `std/math/vec_math.aipl` | `dot` | `pub fn (self: Vec2) dot(other: Vec2): float:` | `tests/functions/math/vec_math_test.aipl` |
| `386` | `std/math/vec_math.aipl` | `cross` | `pub fn (self: Vec2) cross(other: Vec2): float:` | `tests/functions/math/vec_math_test.aipl` |
| `387` | `std/math/vec_math.aipl` | `lenSq` | `pub fn (self: Vec2) lenSq(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `388` | `std/math/vec_math.aipl` | `len` | `pub fn (self: Vec2) len(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `389` | `std/math/vec_math.aipl` | `length` | `pub fn (self: Vec2) length(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `390` | `std/math/vec_math.aipl` | `norm` | `pub fn (self: Vec2) norm(): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `391` | `std/math/vec_math.aipl` | `normalize` | `pub fn (self: Vec2) normalize(): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `392` | `std/math/vec_math.aipl` | `dist` | `pub fn (self: Vec2) dist(other: Vec2): float:` | `tests/functions/math/vec_math_test.aipl` |
| `393` | `std/math/vec_math.aipl` | `lerp` | `pub fn (self: Vec2) lerp(other: Vec2, t: float): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `394` | `std/math/vec_math.aipl` | `add` | `pub fn (self: Vector2) add(other: Vector2): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `395` | `std/math/vec_math.aipl` | `sub` | `pub fn (self: Vector2) sub(other: Vector2): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `396` | `std/math/vec_math.aipl` | `scale` | `pub fn (self: Vector2) scale(s: float): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `397` | `std/math/vec_math.aipl` | `dot` | `pub fn (self: Vector2) dot(other: Vector2): float:` | `tests/functions/math/vec_math_test.aipl` |
| `398` | `std/math/vec_math.aipl` | `length` | `pub fn (self: Vector2) length(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `399` | `std/math/vec_math.aipl` | `normalize` | `pub fn (self: Vector2) normalize(): Vector2:` | `tests/functions/math/vec_math_test.aipl` |
| `400` | `std/math/vec_math.aipl` | `Vec3.new` | `pub fn Vec3.new(x: float, y: float, z: float): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `401` | `std/math/vec_math.aipl` | `Vector3.new` | `pub fn Vector3.new(x: float, y: float, z: float): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `402` | `std/math/vec_math.aipl` | `add` | `pub fn (self: Vec3) add(other: Vec3): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `403` | `std/math/vec_math.aipl` | `sub` | `pub fn (self: Vec3) sub(other: Vec3): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `404` | `std/math/vec_math.aipl` | `scale` | `pub fn (self: Vec3) scale(s: float): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `405` | `std/math/vec_math.aipl` | `dot` | `pub fn (self: Vec3) dot(other: Vec3): float:` | `tests/functions/math/vec_math_test.aipl` |
| `406` | `std/math/vec_math.aipl` | `cross` | `pub fn (self: Vec3) cross(other: Vec3): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `407` | `std/math/vec_math.aipl` | `lenSq` | `pub fn (self: Vec3) lenSq(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `408` | `std/math/vec_math.aipl` | `len` | `pub fn (self: Vec3) len(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `409` | `std/math/vec_math.aipl` | `length` | `pub fn (self: Vec3) length(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `410` | `std/math/vec_math.aipl` | `norm` | `pub fn (self: Vec3) norm(): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `411` | `std/math/vec_math.aipl` | `normalize` | `pub fn (self: Vec3) normalize(): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `412` | `std/math/vec_math.aipl` | `distanceSquared` | `pub fn (self: Vec3) distanceSquared(other: Vec3): float:` | `tests/functions/math/vec_math_test.aipl` |
| `413` | `std/math/vec_math.aipl` | `dist` | `pub fn (self: Vec3) dist(other: Vec3): float:` | `tests/functions/math/vec_math_test.aipl` |
| `414` | `std/math/vec_math.aipl` | `lerp` | `pub fn (self: Vec3) lerp(other: Vec3, t: float): Vec3:` | `tests/functions/math/vec_math_test.aipl` |
| `415` | `std/math/vec_math.aipl` | `add` | `pub fn (self: Vector3) add(other: Vector3): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `416` | `std/math/vec_math.aipl` | `sub` | `pub fn (self: Vector3) sub(other: Vector3): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `417` | `std/math/vec_math.aipl` | `scale` | `pub fn (self: Vector3) scale(s: float): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `418` | `std/math/vec_math.aipl` | `dot` | `pub fn (self: Vector3) dot(other: Vector3): float:` | `tests/functions/math/vec_math_test.aipl` |
| `419` | `std/math/vec_math.aipl` | `length` | `pub fn (self: Vector3) length(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `420` | `std/math/vec_math.aipl` | `normalize` | `pub fn (self: Vector3) normalize(): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `421` | `std/math/vec_math.aipl` | `distanceSquared` | `pub fn (self: Vector3) distanceSquared(other: Vector3): float:` | `tests/functions/math/vec_math_test.aipl` |
| `422` | `std/math/vec_math.aipl` | `lerp` | `pub fn (self: Vector3) lerp(other: Vector3, t: float): Vector3:` | `tests/functions/math/vec_math_test.aipl` |
| `423` | `std/math/vec_math.aipl` | `Vec4.new` | `pub fn Vec4.new(x: float, y: float, z: float, w: float): Vec4:` | `tests/functions/math/vec_math_test.aipl` |
| `424` | `std/math/vec_math.aipl` | `add` | `pub fn (self: Vec4) add(other: Vec4): Vec4:` | `tests/functions/math/vec_math_test.aipl` |
| `425` | `std/math/vec_math.aipl` | `sub` | `pub fn (self: Vec4) sub(other: Vec4): Vec4:` | `tests/functions/math/vec_math_test.aipl` |
| `426` | `std/math/vec_math.aipl` | `scale` | `pub fn (self: Vec4) scale(s: float): Vec4:` | `tests/functions/math/vec_math_test.aipl` |
| `427` | `std/math/vec_math.aipl` | `dot` | `pub fn (self: Vec4) dot(other: Vec4): float:` | `tests/functions/math/vec_math_test.aipl` |
| `428` | `std/math/vec_math.aipl` | `lenSq` | `pub fn (self: Vec4) lenSq(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `429` | `std/math/vec_math.aipl` | `len` | `pub fn (self: Vec4) len(): float:` | `tests/functions/math/vec_math_test.aipl` |
| `430` | `std/math/vec_math.aipl` | `norm` | `pub fn (self: Vec4) norm(): Vec4:` | `tests/functions/math/vec_math_test.aipl` |
| `431` | `std/math/vec_math.aipl` | `distSq2D` | `pub fn distSq2D(x1: int, y1: int, x2: int, y2: int): int:` | `tests/functions/math/vec_math_test.aipl` |
| `432` | `std/math/vec_math.aipl` | `inDisk2D` | `pub fn inDisk2D(x: int, y: int, cx: int, cy: int, radius: int): bool:` | `tests/functions/math/vec_math_test.aipl` |
| `433` | `std/math/vec_math.aipl` | `distSq2Df` | `pub fn distSq2Df(x1: float, y1: float, x2: float, y2: float): float:` | `tests/functions/math/vec_math_test.aipl` |
| `434` | `std/math/vec_math.aipl` | `inDisk2Df` | `pub fn inDisk2Df(x: float, y: float, cx: float, cy: float, radius: float): bool:` | `tests/functions/math/vec_math_test.aipl` |
| `435` | `std/math/vec_math.aipl` | `distSq2DFloat` | `pub fn distSq2DFloat(x1: float, y1: float, x2: float, y2: float): float:` | `tests/functions/math/vec_math_test.aipl` |
| `436` | `std/math/vec_math.aipl` | `inDisk2DFloat` | `pub fn inDisk2DFloat(x: float, y: float, cx: float, cy: float, radius: float): bool:` | `tests/functions/math/vec_math_test.aipl` |
| `437` | `std/math/vec_math.aipl` | `vec4` | `pub fn vec4(x: float, y: float, z: float, w: float): Vector4:` | `tests/functions/math/vec_math_test.aipl` |
| `438` | `std/math/vec_math.aipl` | `vec2Lerp` | `pub fn vec2Lerp(a: Vec2, b: Vec2, t: float): Vec2:` | `tests/functions/math/vec_math_test.aipl` |
| `439` | `std/math/vec_math.aipl` | `vec2Distance` | `pub fn vec2Distance(a: Vec2, b: Vec2): float:` | `tests/functions/math/vec_math_test.aipl` |
| `440` | `std/math/vec_math.aipl` | `vec2DistanceSquared` | `pub fn vec2DistanceSquared(a: Vec2, b: Vec2): float:` | `tests/functions/math/vec_math_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `normalizeLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn normalizeLimbs(limbs: [int]): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `limbs: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `normalizeLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `limbs: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.bigint_z1_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_normalizeLimbs_1(): int:
  let arg_limbs = [4]
  let edge_limbs = []
  let resNom = normalizeLimbs(arg_limbs)
  let resEdge = normalizeLimbs(edge_limbs)
  assertEqInt(resNom.len(), 1, "normalizeLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "normalizeLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### `isZeroLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn isZeroLimbs(limbs: [int]): bool:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `limbs: [int]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `isZeroLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `limbs: [int] = [1]`; exercises core body path returning/computing `limbs.len == 0 or (limbs.len == 1 and limbs[0] == 0)`.

```aipl
module tests.functions.math.bigint_z2_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_isZeroLimbs_2(): int:
  let arg_limbs = [4]
  let edge_limbs = []
  let resNom = isZeroLimbs(arg_limbs)
  let resEdge = isZeroLimbs(edge_limbs)
  assert(resNom == false, "isZeroLimbs nominal resNom == false")
  assert(resEdge == true, "isZeroLimbs boundary resEdge == true")
  ret 0
```

---

### `cmpAbsLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn cmpAbsLimbs(a: [int], b: [int]): int:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], b: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `cmpAbsLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `b: [int] = [1]`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.math.bigint_z3_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_cmpAbsLimbs_3(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_b = [4]
  let edge_b = []
  let resNom = cmpAbsLimbs(arg_a, arg_b)
  let resEdge = cmpAbsLimbs(edge_a, edge_b)
  assertEqInt(resNom, -1, "cmpAbsLimbs nominal resNom == -1")
  assertEqInt(resEdge, 0, "cmpAbsLimbs boundary resEdge == 0")
  ret 0
```

---

### `addAbsLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn addAbsLimbs(a: [int], b: [int]): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], b: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `addAbsLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `b: [int] = [1]`; exercises core body path returning/computing `normalizeLimbs(out)`.

```aipl
module tests.functions.math.bigint_z4_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_addAbsLimbs_4(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_b = [4]
  let edge_b = []
  let resNom = addAbsLimbs(arg_a, arg_b)
  let resEdge = addAbsLimbs(edge_a, edge_b)
  assertEqInt(resNom.len(), 1, "addAbsLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "addAbsLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### `subAbsLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn subAbsLimbs(a: [int], b: [int]): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], b: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `subAbsLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `b: [int] = [1]`; exercises core body path returning/computing `normalizeLimbs(out)`.

```aipl
module tests.functions.math.bigint_z5_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_subAbsLimbs_5(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_b = [4]
  let edge_b = []
  let resNom = subAbsLimbs(arg_a, arg_b)
  let resEdge = subAbsLimbs(edge_a, edge_b)
  assertEqInt(resNom.len(), 1, "subAbsLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "subAbsLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### `mulAbsLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn mulAbsLimbs(a: [int], b: [int]): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], b: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `mulAbsLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `b: [int] = [1]`; exercises core body path returning/computing `normalizeLimbs(res)`.

```aipl
module tests.functions.math.bigint_z6_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_mulAbsLimbs_6(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_b = [4]
  let edge_b = []
  let resNom = mulAbsLimbs(arg_a, arg_b)
  let resEdge = mulAbsLimbs(edge_a, edge_b)
  assertEqInt(resNom.len(), 1, "mulAbsLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "mulAbsLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### `bigIntFromInt` (`std/math/bigint.aipl`)

- **Signature**: `pub fn bigIntFromInt(val: int): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `bigIntFromInt` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `BigInt(sign = sign, digits = limbs)`.

```aipl
module tests.functions.math.bigint_z7_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_bigIntFromInt_7(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = bigIntFromInt(arg_val)
  let resEdge = bigIntFromInt(edge_val)
  assertEqInt(resNom.sign, 1, "bigIntFromInt nominal resNom.sign == 1")
  assertEqInt(resEdge.sign, 0, "bigIntFromInt boundary resEdge.sign == 0")
  ret 0
```

---

### `bigIntFromString` (`std/math/bigint.aipl`)

- **Signature**: `pub fn bigIntFromString(strVal: str): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `strVal: str` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `bigIntFromString` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `strVal: str = "aipl_test"`; exercises core body path returning/computing `BigInt(sign = sign, digits = norm)`.

```aipl
module tests.functions.math.bigint_z8_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_bigIntFromString_8(): int:
  let arg_strVal = "42"
  let edge_strVal = "0"
  let resNom = bigIntFromString(arg_strVal)
  let resEdge = bigIntFromString(edge_strVal)
  assertEqInt(resNom.sign, 1, "bigIntFromString nominal resNom.sign == 1")
  assertEqInt(resEdge.sign, 0, "bigIntFromString boundary resEdge.sign == 0")
  ret 0
```

---

### `toInt64` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) toInt64(): int:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `toInt64` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `self.sign * acc`.

```aipl
module tests.functions.math.bigint_z9_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_toInt64_9(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let resNom = recv_self.toInt64()
  let resEdge = edge_self.toInt64()
  assertEqInt(resNom, 0, "toInt64 nominal resNom == 0")
  assertEqInt(resEdge, 0, "toInt64 boundary resEdge == 0")
  ret 0
```

---

### `padLimb9` (`std/math/bigint.aipl`)

- **Signature**: `fn padLimb9(val: int): str:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `padLimb9` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `pad + s`.

```aipl
module tests.functions.math.bigint_z10_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_padLimb9_10(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = padLimb9(arg_val)
  let resEdge = padLimb9(edge_val)
  assertEqStr(resNom, "000000002", "padLimb9 nominal string matches")
  assertEqStr(resEdge, "000000000", "padLimb9 boundary string matches")
  ret 0
```

---

### `toString` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) toString(): str:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `toString` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.bigint_z11_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_toString_11(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let resNom = recv_self.toString()
  let resEdge = edge_self.toString()
  assertEqStr(resNom, "0", "toString nominal string matches")
  assertEqStr(resEdge, "0", "toString boundary string matches")
  ret 0
```

---

### `cmp` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) cmp(other: BigInt): int:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `cmp` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `if sA > 0: absCmp else: -absCmp`.

```aipl
module tests.functions.math.bigint_z12_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_cmp_12(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.cmp(arg_other)
  let resEdge = edge_self.cmp(edge_other)
  assertEqInt(resNom, 0, "cmp nominal resNom == 0")
  assertEqInt(resEdge, 0, "cmp boundary resEdge == 0")
  ret 0
```

---

### `add` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) add(other: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `add` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `BigInt(sign = sB, digits = subAbsLimbs(db, da))`.

```aipl
module tests.functions.math.bigint_z13_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_add_13(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertEqInt(resNom.sign, 4, "add nominal resNom.sign == 4")
  assertEqInt(resEdge.sign, 1, "add boundary resEdge.sign == 1")
  ret 0
```

---

### `sub` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) sub(other: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `sub` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `self.add(negOther)`.

```aipl
module tests.functions.math.bigint_z14_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_sub_14(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertEqInt(resNom.sign, -4, "sub nominal resNom.sign == -4")
  assertEqInt(resEdge.sign, -1, "sub boundary resEdge.sign == -1")
  ret 0
```

---

### `mul` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) mul(other: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `mul` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `BigInt(sign = sA * sB, digits = prod)`.

```aipl
module tests.functions.math.bigint_z15_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_mul_15(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.mul(arg_other)
  let resEdge = edge_self.mul(edge_other)
  assertEqInt(resNom.sign, 0, "mul nominal resNom.sign == 0")
  assertEqInt(resEdge.sign, 0, "mul boundary resEdge.sign == 0")
  ret 0
```

---

### `mulLimbScalar` (`std/math/bigint.aipl`)

- **Signature**: `fn mulLimbScalar(a: [int], scalar: int): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], scalar: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `mulLimbScalar` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `scalar: int = 1`; exercises core body path returning/computing `normalizeLimbs(res)`.

```aipl
module tests.functions.math.bigint_z16_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_mulLimbScalar_16(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_scalar = 2
  let edge_scalar = 0
  let resNom = mulLimbScalar(arg_a, arg_scalar)
  let resEdge = mulLimbScalar(edge_a, edge_scalar)
  assertEqInt(resNom.len(), 1, "mulLimbScalar nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "mulLimbScalar boundary resEdge.len() == 1")
  ret 0
```

---

### `shiftLimbAndAdd` (`std/math/bigint.aipl`)

- **Signature**: `fn shiftLimbAndAdd(rem: [int], limb: int): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rem: [int], limb: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `shiftLimbAndAdd` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `rem: [int] = [1]`, `limb: int = 1`; exercises core body path returning/computing `normalizeLimbs(out)`.

```aipl
module tests.functions.math.bigint_z17_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_shiftLimbAndAdd_17(): int:
  let arg_rem = [4]
  let edge_rem = []
  let arg_limb = 4
  let edge_limb = 1
  let resNom = shiftLimbAndAdd(arg_rem, arg_limb)
  let resEdge = shiftLimbAndAdd(edge_rem, edge_limb)
  assertEqInt(resNom.len(), 2, "shiftLimbAndAdd nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 1, "shiftLimbAndAdd boundary resEdge.len() == 1")
  ret 0
```

---

### `divModAbsLimbs` (`std/math/bigint.aipl`)

- **Signature**: `fn divModAbsLimbs(a: [int], b: [int], returnRem: bool): [int]:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [int], b: [int], returnRem: bool` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `divModAbsLimbs` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: [int] = [1]`, `b: [int] = [1]`, `returnRem: bool = true`; exercises core body path returning/computing `normalizeLimbs(qLimbs)`.

```aipl
module tests.functions.math.bigint_z18_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_divModAbsLimbs_18(): int:
  let arg_a = [2]
  let edge_a = []
  let arg_b = [4]
  let edge_b = []
  let arg_returnRem = true
  let edge_returnRem = false
  let resNom = divModAbsLimbs(arg_a, arg_b, arg_returnRem)
  let resEdge = divModAbsLimbs(edge_a, edge_b, edge_returnRem)
  assertEqInt(resNom.len(), 1, "divModAbsLimbs nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 1, "divModAbsLimbs boundary resEdge.len() == 1")
  ret 0
```

---

### `div` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) div(other: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `div` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `BigInt(sign = sA * sB, digits = qLimbs)`.

```aipl
module tests.functions.math.bigint_z19_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_div_19(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.div(arg_other)
  let resEdge = edge_self.div(edge_other)
  assertEqInt(resNom.sign, 0, "div nominal resNom.sign == 0")
  assertEqInt(resEdge.sign, 0, "div boundary resEdge.sign == 0")
  ret 0
```

---

### `mod` (`std/math/bigint.aipl`)

- **Signature**: `pub fn (self: BigInt) mod(other: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: BigInt` | **Parameters**: `other: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `mod` (`self: BigInt`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: receiver `recvObj: BigInt = BigInt(sign = 1, digits = [1])`, `other: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `BigInt(sign = sA, digits = rLimbs)`.

```aipl
module tests.functions.math.bigint_z20_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_BigInt_mod_20(): int:
  let recv_self = BigInt(sign = 4, digits = [])
  let edge_self = BigInt(sign = 1, digits = [])
  let arg_other = BigInt(sign = 4, digits = [])
  let edge_other = BigInt(sign = 1, digits = [])
  let resNom = recv_self.mod(arg_other)
  let resEdge = edge_self.mod(edge_other)
  assertEqInt(resNom.sign, 0, "mod nominal resNom.sign == 0")
  assertEqInt(resEdge.sign, 0, "mod boundary resEdge.sign == 0")
  ret 0
```

---

### `bigIntDiv` (`std/math/bigint.aipl`)

- **Signature**: `pub fn bigIntDiv(a: BigInt, b: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: BigInt, b: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `bigIntDiv` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: BigInt = BigInt(sign = 1, digits = [1])`, `b: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `a.div(b)`.

```aipl
module tests.functions.math.bigint_z21_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_bigIntDiv_21(): int:
  let arg_a = BigInt(sign = 4, digits = [])
  let edge_a = BigInt(sign = 1, digits = [])
  let arg_b = BigInt(sign = 4, digits = [])
  let edge_b = BigInt(sign = 1, digits = [])
  let resNom = bigIntDiv(arg_a, arg_b)
  let resEdge = bigIntDiv(edge_a, edge_b)
  assertEqInt(resNom.sign, 0, "bigIntDiv nominal resNom.sign == 0")
  assertEqInt(resEdge.sign, 0, "bigIntDiv boundary resEdge.sign == 0")
  ret 0
```

---

### `bigIntMod` (`std/math/bigint.aipl`)

- **Signature**: `pub fn bigIntMod(a: BigInt, b: BigInt): BigInt:`
- **Import**: `import * from "std/math/bigint"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: BigInt, b: BigInt` | **Returns**: `BigInt`
- **Unit Test**: `tests/functions/math/bigint_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify arbitrary-precision `bigIntMod` (`free fn`) on zero `[0]`, single-limb, and multi-limb base-10^9 carry/borrow boundaries (`999999999 + 1`), signed `(+,+)/(+,-)/(-,-)` combinations, and algebraic round-trip invariants. Concrete nominal inputs: `a: BigInt = BigInt(sign = 1, digits = [1])`, `b: BigInt = BigInt(sign = 1, digits = [1])`; exercises core body path returning/computing `a.mod(b)`.

```aipl
module tests.functions.math.bigint_z22_test
import * from "std/math/bigint"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_bigint_bigIntMod_22(): int:
  let arg_a = BigInt(sign = 4, digits = [])
  let edge_a = BigInt(sign = 1, digits = [])
  let arg_b = BigInt(sign = 4, digits = [])
  let edge_b = BigInt(sign = 1, digits = [])
  let resNom = bigIntMod(arg_a, arg_b)
  let resEdge = bigIntMod(edge_a, edge_b)
  assertEqInt(resNom.sign, 0, "bigIntMod nominal resNom.sign == 0")
  assertEqInt(resEdge.sign, 0, "bigIntMod boundary resEdge.sign == 0")
  ret 0
```

---

### `Complex64.new` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn Complex64.new(re: float, im: float): Complex64:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `re: float, im: float` | **Returns**: `Complex64`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: `re: float = 1.0`, `im: float = 1.0`; exercises core body path returning/computing `Complex64(re = re, im = im)`.

```aipl
module tests.functions.math.complex_fft_z1_test
import * from "std/math/complex_fft"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_new_1(): int:
  let arg_re = 1.0
  let edge_re = 0.0
  let arg_im = 1.0
  let edge_im = 0.0
  let resNom = Complex64.new(arg_re, arg_im)
  let resEdge = Complex64.new(edge_re, edge_im)
  assertApproxEq(resNom.re, 1.0, 0.001, "Complex64.new nominal resNom.re ~= 1.0")
  assertApproxEq(resEdge.re, 0.0, 0.001, "Complex64.new boundary resEdge.re ~= 0.0")
  ret 0
```

---

### `add` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn (self: Complex64) add(other: Complex64): Complex64:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Complex64` | **Parameters**: `other: Complex64` | **Returns**: `Complex64`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: receiver `recvObj: Complex64 = Complex64(re = 1.0, im = 1.0)`, `other: Complex64 = Complex64(re = 1.0, im = 1.0)`; exercises core body path returning/computing `Complex64(re = self.re + other.re, im = self.im + other.im)`.

```aipl
module tests.functions.math.complex_fft_z2_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_add_2(): int:
  let recv_self = Complex64(re = 1.0, im = 1.0)
  let edge_self = Complex64(re = 0.5, im = 0.5)
  let arg_other = Complex64(re = 1.0, im = 1.0)
  let edge_other = Complex64(re = 0.5, im = 0.5)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.re, 2.0, 0.001, "add nominal resNom.re ~= 2.0")
  assertApproxEq(resEdge.re, 1.0, 0.001, "add boundary resEdge.re ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn (self: Complex64) sub(other: Complex64): Complex64:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Complex64` | **Parameters**: `other: Complex64` | **Returns**: `Complex64`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: receiver `recvObj: Complex64 = Complex64(re = 1.0, im = 1.0)`, `other: Complex64 = Complex64(re = 1.0, im = 1.0)`; exercises core body path returning/computing `Complex64(re = self.re - other.re, im = self.im - other.im)`.

```aipl
module tests.functions.math.complex_fft_z3_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_sub_3(): int:
  let recv_self = Complex64(re = 1.0, im = 1.0)
  let edge_self = Complex64(re = 0.5, im = 0.5)
  let arg_other = Complex64(re = 1.0, im = 1.0)
  let edge_other = Complex64(re = 0.5, im = 0.5)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.re, 0.0, 0.001, "sub nominal resNom.re ~= 0.0")
  assertApproxEq(resEdge.re, 0.0, 0.001, "sub boundary resEdge.re ~= 0.0")
  ret 0
```

---

### `mul` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn (self: Complex64) mul(other: Complex64): Complex64:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Complex64` | **Parameters**: `other: Complex64` | **Returns**: `Complex64`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: receiver `recvObj: Complex64 = Complex64(re = 1.0, im = 1.0)`, `other: Complex64 = Complex64(re = 1.0, im = 1.0)`; exercises core body path returning/computing `Complex64(`.

```aipl
module tests.functions.math.complex_fft_z4_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_mul_4(): int:
  let recv_self = Complex64(re = 1.0, im = 1.0)
  let edge_self = Complex64(re = 0.5, im = 0.5)
  let arg_other = Complex64(re = 1.0, im = 1.0)
  let edge_other = Complex64(re = 0.5, im = 0.5)
  let resNom = recv_self.mul(arg_other)
  let resEdge = edge_self.mul(edge_other)
  assertApproxEq(resNom.re, 0.0, 0.001, "mul nominal resNom.re ~= 0.0")
  assertApproxEq(resEdge.re, 0.0, 0.001, "mul boundary resEdge.re ~= 0.0")
  ret 0
```

---

### `mag` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn (self: Complex64) mag(): float:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Complex64` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: receiver `recvObj: Complex64 = Complex64(re = 1.0, im = 1.0)`; exercises core body path returning/computing `sqrt(self.re * self.re + self.im * self.im)`.

```aipl
module tests.functions.math.complex_fft_z5_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_mag_5(): int:
  let recv_self = Complex64(re = 1.0, im = 1.0)
  let edge_self = Complex64(re = 0.5, im = 0.5)
  let resNom = recv_self.mag()
  let resEdge = edge_self.mag()
  assertApproxEq(resNom, 1.41421, 0.001, "mag nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "mag boundary resEdge ~= 0.707107")
  ret 0
```

---

### `conj` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn (self: Complex64) conj(): Complex64:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Complex64` | **Parameters**: `none` | **Returns**: `Complex64`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: receiver `recvObj: Complex64 = Complex64(re = 1.0, im = 1.0)`; exercises core body path returning/computing `Complex64(re = self.re, im = -self.im)`.

```aipl
module tests.functions.math.complex_fft_z6_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_Complex64_conj_6(): int:
  let recv_self = Complex64(re = 1.0, im = 1.0)
  let edge_self = Complex64(re = 0.5, im = 0.5)
  let resNom = recv_self.conj()
  let resEdge = edge_self.conj()
  assertApproxEq(resNom.re, 1.0, 0.001, "conj nominal resNom.re ~= 1.0")
  assertApproxEq(resEdge.re, 0.5, 0.001, "conj boundary resEdge.re ~= 0.5")
  ret 0
```

---

### `fftRadix2` (`std/math/complex_fft.aipl`)

- **Signature**: `pub fn fftRadix2(mut samples: [Complex64], inverse: bool): void:`
- **Import**: `import * from "std/math/complex_fft"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut samples: [Complex64], inverse: bool` | **Returns**: `void`
- **Unit Test**: `tests/functions/math/complex_fft_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ^2 = z * conj(z)`) and radix-2 forward/inverse FFT reconstruction. Concrete nominal inputs: `samples: [Complex64] = [Complex64(re = 1.0, im = 1.0)]`, `inverse: bool = true`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.math.complex_fft_z7_test
import * from "std/math/complex_fft"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_complex_fft_fftRadix2_7(): int:
  let arg_samples = [Complex64(re = 1.0, im = 1.0)]
  let edge_samples = []
  let arg_inverse = true
  let edge_inverse = false
  fftRadix2(arg_samples, arg_inverse)
  fftRadix2(edge_samples, edge_inverse)
  assertEqInt(arg_samples.len(), 1, "fftRadix2 nominal arg_samples.len() == 1")
  assertEqInt(edge_samples.len(), 0, "fftRadix2 boundary edge_samples.len() == 0")
  ret 0
```

---

### `pi` (`std/math/consts.aipl`)

- **Signature**: `pub fn pi(): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `pi` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `PI`.

```aipl
module tests.functions.math.consts_z1_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_pi_1(): int:
  let resNom = pi()
  let resEdge = pi()
  assertApproxEq(resNom, 3.14159, 0.001, "pi nominal resNom ~= 3.14159")
  assertApproxEq(resEdge, 3.14159, 0.001, "pi boundary resEdge ~= 3.14159")
  ret 0
```

---

### `tau` (`std/math/consts.aipl`)

- **Signature**: `pub fn tau(): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `tau` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `TAU`.

```aipl
module tests.functions.math.consts_z2_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_tau_2(): int:
  let resNom = tau()
  let resEdge = tau()
  assertApproxEq(resNom, 6.28319, 0.001, "tau nominal resNom ~= 6.28319")
  assertApproxEq(resEdge, 6.28319, 0.001, "tau boundary resEdge ~= 6.28319")
  ret 0
```

---

### `eulerE` (`std/math/consts.aipl`)

- **Signature**: `pub fn eulerE(): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `eulerE` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `E`.

```aipl
module tests.functions.math.consts_z3_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_eulerE_3(): int:
  let resNom = eulerE()
  let resEdge = eulerE()
  assertApproxEq(resNom, 2.71828, 0.001, "eulerE nominal resNom ~= 2.71828")
  assertApproxEq(resEdge, 2.71828, 0.001, "eulerE boundary resEdge ~= 2.71828")
  ret 0
```

---

### `abs` (`std/math/consts.aipl`)

- **Signature**: `pub fn abs(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `abs` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `if x < 0: -x else: x`.

```aipl
module tests.functions.math.consts_z4_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_abs_4(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = abs(arg_x)
  let resEdge = abs(edge_x)
  assertEqInt(resNom, 1, "abs nominal resNom == 1")
  assertEqInt(resEdge, 0, "abs boundary resEdge == 0")
  ret 0
```

---

### `absInt` (`std/math/consts.aipl`)

- **Signature**: `pub fn absInt(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `absInt` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `if x < 0: -x else: x`.

```aipl
module tests.functions.math.consts_z5_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_absInt_5(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = absInt(arg_x)
  let resEdge = absInt(edge_x)
  assertEqInt(resNom, 1, "absInt nominal resNom == 1")
  assertEqInt(resEdge, 0, "absInt boundary resEdge == 0")
  ret 0
```

---

### `absFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn absFloat(x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `absFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `if x < 0.0: -x else: x`.

```aipl
module tests.functions.math.consts_z6_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_absFloat_6(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = absFloat(arg_x)
  let resEdge = absFloat(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "absFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "absFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `min` (`std/math/consts.aipl`)

- **Signature**: `pub fn min(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `min` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `if a < b: a else: b`.

```aipl
module tests.functions.math.consts_z7_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_min_7(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = min(arg_a, arg_b)
  let resEdge = min(edge_a, edge_b)
  assertEqInt(resNom, 2, "min nominal resNom == 2")
  assertEqInt(resEdge, 0, "min boundary resEdge == 0")
  ret 0
```

---

### `max` (`std/math/consts.aipl`)

- **Signature**: `pub fn max(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `max` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `if a > b: a else: b`.

```aipl
module tests.functions.math.consts_z8_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_max_8(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = max(arg_a, arg_b)
  let resEdge = max(edge_a, edge_b)
  assertEqInt(resNom, 4, "max nominal resNom == 4")
  assertEqInt(resEdge, 1, "max boundary resEdge == 1")
  ret 0
```

---

### `clamp` (`std/math/consts.aipl`)

- **Signature**: `pub fn clamp(val: int, minVal: int, maxVal: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, minVal: int, maxVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `clamp` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `minVal: int = 1`, `maxVal: int = 1`; exercises core body path returning/computing `val`.

```aipl
module tests.functions.math.consts_z9_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_clamp_9(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = clamp(arg_val, arg_minVal, arg_maxVal)
  let resEdge = clamp(edge_val, edge_minVal, edge_maxVal)
  assertEqInt(resNom, 4, "clamp nominal resNom == 4")
  assertEqInt(resEdge, 1, "clamp boundary resEdge == 1")
  ret 0
```

---

### `sign` (`std/math/consts.aipl`)

- **Signature**: `pub fn sign(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `sign` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.math.consts_z10_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_sign_10(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = sign(arg_x)
  let resEdge = sign(edge_x)
  assertEqInt(resNom, 1, "sign nominal resNom == 1")
  assertEqInt(resEdge, 0, "sign boundary resEdge == 0")
  ret 0
```

---

### `signInt` (`std/math/consts.aipl`)

- **Signature**: `pub fn signInt(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `signInt` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `sign(x)`.

```aipl
module tests.functions.math.consts_z11_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_signInt_11(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = signInt(arg_x)
  let resEdge = signInt(edge_x)
  assertEqInt(resNom, 1, "signInt nominal resNom == 1")
  assertEqInt(resEdge, 0, "signInt boundary resEdge == 0")
  ret 0
```

---

### `signFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn signFloat(x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `signFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.math.consts_z12_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_signFloat_12(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = signFloat(arg_x)
  let resEdge = signFloat(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "signFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "signFloat boundary resEdge ~= 1.0")
  ret 0
```

---

### `lerp` (`std/math/consts.aipl`)

- **Signature**: `pub fn lerp(a: float, b: float, t: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `lerp` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: float = 1.0`, `b: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `a + (b - a) * t`.

```aipl
module tests.functions.math.consts_z13_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_lerp_13(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = lerp(arg_a, arg_b, arg_t)
  let resEdge = lerp(edge_a, edge_b, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "lerp nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "lerp boundary resEdge ~= 0.5")
  ret 0
```

---

### `inverseLerp` (`std/math/consts.aipl`)

- **Signature**: `pub fn inverseLerp(a: float, b: float, v: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: float, b: float, v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `inverseLerp` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: float = 1.0`, `b: float = 1.0`, `v: float = 1.0`; exercises core body path returning/computing `(v - a) / denom`.

```aipl
module tests.functions.math.consts_z14_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_inverseLerp_14(): int:
  let arg_a = 1.0
  let edge_a = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = inverseLerp(arg_a, arg_b, arg_v)
  let resEdge = inverseLerp(edge_a, edge_b, edge_v)
  assertApproxEq(resNom, 0.0, 0.001, "inverseLerp nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "inverseLerp boundary resEdge ~= 0.0")
  ret 0
```

---

### `remapFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn remapFloat(inMin: float, inMax: float, outMin: float, outMax: float, v: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `inMin: float, inMax: float, outMin: float, outMax: float, v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `remapFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `inMin: float = 1.0`, `inMax: float = 1.0`, `outMin: float = 1.0`, `outMax: float = 1.0`, `v: float = 1.0`; exercises core body path returning/computing `lerp(outMin, outMax, t)`.

```aipl
module tests.functions.math.consts_z15_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_remapFloat_15(): int:
  let arg_inMin = 0.0
  let edge_inMin = 0.0
  let arg_inMax = 2.0
  let edge_inMax = 1.0
  let arg_outMin = 0.0
  let edge_outMin = 0.0
  let arg_outMax = 2.0
  let edge_outMax = 1.0
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = remapFloat(arg_inMin, arg_inMax, arg_outMin, arg_outMax, arg_v)
  let resEdge = remapFloat(edge_inMin, edge_inMax, edge_outMin, edge_outMax, edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "remapFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "remapFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `smoothstep` (`std/math/consts.aipl`)

- **Signature**: `pub fn smoothstep(edge0: float, edge1: float, x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `edge0: float, edge1: float, x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `smoothstep` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `edge0: float = 1.0`, `edge1: float = 1.0`, `x: float = 1.0`; exercises core body path returning/computing `t * t * (3.0 - 2.0 * t)`.

```aipl
module tests.functions.math.consts_z16_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_smoothstep_16(): int:
  let arg_edge0 = 1.0
  let edge_edge0 = 0.5
  let arg_edge1 = 1.0
  let edge_edge1 = 0.5
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = smoothstep(arg_edge0, arg_edge1, arg_x)
  let resEdge = smoothstep(edge_edge0, edge_edge1, edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "smoothstep nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "smoothstep boundary resEdge ~= 0.0")
  ret 0
```

---

### `smootherstep` (`std/math/consts.aipl`)

- **Signature**: `pub fn smootherstep(edge0: float, edge1: float, x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `edge0: float, edge1: float, x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `smootherstep` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `edge0: float = 1.0`, `edge1: float = 1.0`, `x: float = 1.0`; exercises core body path returning/computing `t * t * t * (t * (t * 6.0 - 15.0) + 10.0)`.

```aipl
module tests.functions.math.consts_z17_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_smootherstep_17(): int:
  let arg_edge0 = 1.0
  let edge_edge0 = 0.5
  let arg_edge1 = 1.0
  let edge_edge1 = 0.5
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = smootherstep(arg_edge0, arg_edge1, arg_x)
  let resEdge = smootherstep(edge_edge0, edge_edge1, edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "smootherstep nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "smootherstep boundary resEdge ~= 0.0")
  ret 0
```

---

### `pingPong` (`std/math/consts.aipl`)

- **Signature**: `pub fn pingPong(t: float, length: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float, length: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `pingPong` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `t: float = 0.5`, `length: float = 1.0`; exercises core body path returning/computing `twoLen - modVal`.

```aipl
module tests.functions.math.consts_z18_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_pingPong_18(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_length = 2.0
  let edge_length = 1.0
  let resNom = pingPong(arg_t, arg_length)
  let resEdge = pingPong(edge_t, edge_length)
  assertApproxEq(resNom, 1.0, 0.001, "pingPong nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "pingPong boundary resEdge ~= 0.5")
  ret 0
```

---

### `bitTest` (`std/math/consts.aipl`)

- **Signature**: `pub fn bitTest(val: int, bitIdx: int): bool:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, bitIdx: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `bitTest` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `bitIdx: int = 0`; exercises core body path returning/computing `((val >> bitIdx) & 1) != 0`.

```aipl
module tests.functions.math.consts_z19_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_bitTest_19(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_bitIdx = 4
  let edge_bitIdx = 1
  let resNom = bitTest(arg_val, arg_bitIdx)
  let resEdge = bitTest(edge_val, edge_bitIdx)
  assert(resNom == false, "bitTest nominal resNom == false")
  assert(resEdge == false, "bitTest boundary resEdge == false")
  ret 0
```

---

### `bitSet` (`std/math/consts.aipl`)

- **Signature**: `pub fn bitSet(val: int, bitIdx: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, bitIdx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `bitSet` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `bitIdx: int = 0`; exercises core body path returning/computing `val | (1 << bitIdx)`.

```aipl
module tests.functions.math.consts_z20_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_bitSet_20(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_bitIdx = 4
  let edge_bitIdx = 1
  let resNom = bitSet(arg_val, arg_bitIdx)
  let resEdge = bitSet(edge_val, edge_bitIdx)
  assertEqInt(resNom, 18, "bitSet nominal resNom == 18")
  assertEqInt(resEdge, 2, "bitSet boundary resEdge == 2")
  ret 0
```

---

### `bitClear` (`std/math/consts.aipl`)

- **Signature**: `pub fn bitClear(val: int, bitIdx: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, bitIdx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `bitClear` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `bitIdx: int = 0`; exercises core body path returning/computing `val & (~(1 << bitIdx))`.

```aipl
module tests.functions.math.consts_z21_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_bitClear_21(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_bitIdx = 4
  let edge_bitIdx = 1
  let resNom = bitClear(arg_val, arg_bitIdx)
  let resEdge = bitClear(edge_val, edge_bitIdx)
  assertEqInt(resNom, 2, "bitClear nominal resNom == 2")
  assertEqInt(resEdge, 0, "bitClear boundary resEdge == 0")
  ret 0
```

---

### `bitToggle` (`std/math/consts.aipl`)

- **Signature**: `pub fn bitToggle(val: int, bitIdx: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, bitIdx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `bitToggle` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `bitIdx: int = 0`; exercises core body path returning/computing `val ^ (1 << bitIdx)`.

```aipl
module tests.functions.math.consts_z22_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_bitToggle_22(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_bitIdx = 4
  let edge_bitIdx = 1
  let resNom = bitToggle(arg_val, arg_bitIdx)
  let resEdge = bitToggle(edge_val, edge_bitIdx)
  assertEqInt(resNom, 18, "bitToggle nominal resNom == 18")
  assertEqInt(resEdge, 2, "bitToggle boundary resEdge == 2")
  ret 0
```

---

### `rotateLeft32` (`std/math/consts.aipl`)

- **Signature**: `pub fn rotateLeft32(val: int, shift: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, shift: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `rotateLeft32` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `shift: int = 1`; exercises core body path returning/computing `((u << s) | (u >> (32 - s))) & 0xFFFFFFFF`.

```aipl
module tests.functions.math.consts_z23_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_rotateLeft32_23(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_shift = 2
  let edge_shift = 0
  let resNom = rotateLeft32(arg_val, arg_shift)
  let resEdge = rotateLeft32(edge_val, edge_shift)
  assertEqInt(resNom, 8, "rotateLeft32 nominal resNom == 8")
  assertEqInt(resEdge, 0, "rotateLeft32 boundary resEdge == 0")
  ret 0
```

---

### `rotateRight32` (`std/math/consts.aipl`)

- **Signature**: `pub fn rotateRight32(val: int, shift: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, shift: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `rotateRight32` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`, `shift: int = 1`; exercises core body path returning/computing `((u >> s) | (u << (32 - s))) & 0xFFFFFFFF`.

```aipl
module tests.functions.math.consts_z24_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_rotateRight32_24(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_shift = 2
  let edge_shift = 0
  let resNom = rotateRight32(arg_val, arg_shift)
  let resEdge = rotateRight32(edge_val, edge_shift)
  assertEqInt(resNom, 2147483648, "rotateRight32 nominal resNom == 2147483648")
  assertEqInt(resEdge, 0, "rotateRight32 boundary resEdge == 0")
  ret 0
```

---

### `popcount64` (`std/math/consts.aipl`)

- **Signature**: `pub fn popcount64(val: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `popcount64` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.math.consts_z25_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_popcount64_25(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = popcount64(arg_val)
  let resEdge = popcount64(edge_val)
  assertEqInt(resNom, 1, "popcount64 nominal resNom == 1")
  assertEqInt(resEdge, 0, "popcount64 boundary resEdge == 0")
  ret 0
```

---

### `moveTowards` (`std/math/consts.aipl`)

- **Signature**: `pub fn moveTowards(current: float, target: float, maxDelta: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `current: float, target: float, maxDelta: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `moveTowards` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `current: float = 1.0`, `target: float = 1.0`, `maxDelta: float = 1.0`; exercises core body path returning/computing `current + signFloat(diff) * maxDelta`.

```aipl
module tests.functions.math.consts_z26_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_moveTowards_26(): int:
  let arg_current = 1.0
  let edge_current = 0.5
  let arg_target = 1.0
  let edge_target = 0.5
  let arg_maxDelta = 2.0
  let edge_maxDelta = 1.0
  let resNom = moveTowards(arg_current, arg_target, arg_maxDelta)
  let resEdge = moveTowards(edge_current, edge_target, edge_maxDelta)
  assertApproxEq(resNom, 1.0, 0.001, "moveTowards nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "moveTowards boundary resEdge ~= 0.5")
  ret 0
```

---

### `remap` (`std/math/consts.aipl`)

- **Signature**: `pub fn remap(val: float, inMin: float, inMax: float, outMin: float, outMax: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, inMin: float, inMax: float, outMin: float, outMax: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `remap` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: float = 1.0`, `inMin: float = 1.0`, `inMax: float = 1.0`, `outMin: float = 1.0`, `outMax: float = 1.0`; exercises core body path returning/computing `outMin + (outMax - outMin) * t`.

```aipl
module tests.functions.math.consts_z27_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_remap_27(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_inMin = 0.0
  let edge_inMin = 0.0
  let arg_inMax = 2.0
  let edge_inMax = 1.0
  let arg_outMin = 0.0
  let edge_outMin = 0.0
  let arg_outMax = 2.0
  let edge_outMax = 1.0
  let resNom = remap(arg_val, arg_inMin, arg_inMax, arg_outMin, arg_outMax)
  let resEdge = remap(edge_val, edge_inMin, edge_inMax, edge_outMin, edge_outMax)
  assertApproxEq(resNom, 1.0, 0.001, "remap nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "remap boundary resEdge ~= 0.5")
  ret 0
```

---

### `fract` (`std/math/consts.aipl`)

- **Signature**: `pub fn fract(x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `fract` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `x - floor(x)`.

```aipl
module tests.functions.math.consts_z28_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_fract_28(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = fract(arg_x)
  let resEdge = fract(edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "fract nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.5, 0.001, "fract boundary resEdge ~= 0.5")
  ret 0
```

---

### `modFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn modFloat(x: float, y: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `modFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `x - y * floor(x / y)`.

```aipl
module tests.functions.math.consts_z29_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_modFloat_29(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = modFloat(arg_x, arg_y)
  let resEdge = modFloat(edge_x, edge_y)
  assertApproxEq(resNom, 0.0, 0.001, "modFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "modFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `distSq` (`std/math/consts.aipl`)

- **Signature**: `pub fn distSq(x1: float, y1: float, x2: float, y2: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, x2: float, y2: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `distSq` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`; exercises core body path returning/computing `dx * dx + dy * dy`.

```aipl
module tests.functions.math.consts_z30_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_distSq_30(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let resNom = distSq(arg_x1, arg_y1, arg_x2, arg_y2)
  let resEdge = distSq(edge_x1, edge_y1, edge_x2, edge_y2)
  assertApproxEq(resNom, 0.0, 0.001, "distSq nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distSq boundary resEdge ~= 0.0")
  ret 0
```

---

### `roundFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn roundFloat(val: float): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `roundFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: float = 1.0`; exercises core body path returning/computing `int(val - 0.5)`.

```aipl
module tests.functions.math.consts_z31_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_roundFloat_31(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = roundFloat(arg_val)
  let resEdge = roundFloat(edge_val)
  assertEqInt(resNom, 1, "roundFloat nominal resNom == 1")
  assertEqInt(resEdge, 1, "roundFloat boundary resEdge == 1")
  ret 0
```

---

### `roundTo` (`std/math/consts.aipl`)

- **Signature**: `pub fn roundTo(val: float, decimals: int): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, decimals: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `roundTo` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `val: float = 1.0`, `decimals: int = 1`; exercises core body path returning/computing `float(r) / factor`.

```aipl
module tests.functions.math.consts_z32_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_roundTo_32(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_decimals = 4
  let edge_decimals = 1
  let resNom = roundTo(arg_val, arg_decimals)
  let resEdge = roundTo(edge_val, edge_decimals)
  assertApproxEq(resNom, 1.0, 0.001, "roundTo nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "roundTo boundary resEdge ~= 0.5")
  ret 0
```

---

### `remEuclid` (`std/math/consts.aipl`)

- **Signature**: `pub fn remEuclid(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `remEuclid` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.math.consts_z33_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_remEuclid_33(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = remEuclid(arg_a, arg_b)
  let resEdge = remEuclid(edge_a, edge_b)
  assertEqInt(resNom, 2, "remEuclid nominal resNom == 2")
  assertEqInt(resEdge, 0, "remEuclid boundary resEdge == 0")
  ret 0
```

---

### `gcdInt` (`std/math/consts.aipl`)

- **Signature**: `pub fn gcdInt(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `gcdInt` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `x`.

```aipl
module tests.functions.math.consts_z34_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_gcdInt_34(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = gcdInt(arg_a, arg_b)
  let resEdge = gcdInt(edge_a, edge_b)
  assertEqInt(resNom, 2, "gcdInt nominal resNom == 2")
  assertEqInt(resEdge, 1, "gcdInt boundary resEdge == 1")
  ret 0
```

---

### `lcmInt` (`std/math/consts.aipl`)

- **Signature**: `pub fn lcmInt(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `lcmInt` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `(abs(a) / g) * abs(b)`.

```aipl
module tests.functions.math.consts_z35_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_lcmInt_35(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = lcmInt(arg_a, arg_b)
  let resEdge = lcmInt(edge_a, edge_b)
  assertEqInt(resNom, 4, "lcmInt nominal resNom == 4")
  assertEqInt(resEdge, 0, "lcmInt boundary resEdge == 0")
  ret 0
```

---

### `isPowerOfTwo` (`std/math/consts.aipl`)

- **Signature**: `pub fn isPowerOfTwo(n: int): bool:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `isPowerOfTwo` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `n > 0 and (n & (n - 1)) == 0`.

```aipl
module tests.functions.math.consts_z36_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_isPowerOfTwo_36(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = isPowerOfTwo(arg_n)
  let resEdge = isPowerOfTwo(edge_n)
  assert(resNom == true, "isPowerOfTwo nominal resNom == true")
  assert(resEdge == true, "isPowerOfTwo boundary resEdge == true")
  ret 0
```

---

### `nextPowerOfTwo` (`std/math/consts.aipl`)

- **Signature**: `pub fn nextPowerOfTwo(n: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `nextPowerOfTwo` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `v + 1`.

```aipl
module tests.functions.math.consts_z37_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_nextPowerOfTwo_37(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = nextPowerOfTwo(arg_n)
  let resEdge = nextPowerOfTwo(edge_n)
  assertEqInt(resNom, 4, "nextPowerOfTwo nominal resNom == 4")
  assertEqInt(resEdge, 1, "nextPowerOfTwo boundary resEdge == 1")
  ret 0
```

---

### `popcnt` (`std/math/consts.aipl`)

- **Signature**: `pub fn popcnt(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `popcnt` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `popcount64(x)`.

```aipl
module tests.functions.math.consts_z38_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_popcnt_38(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = popcnt(arg_x)
  let resEdge = popcnt(edge_x)
  assertEqInt(resNom, 1, "popcnt nominal resNom == 1")
  assertEqInt(resEdge, 0, "popcnt boundary resEdge == 0")
  ret 0
```

---

### `ctz` (`std/math/consts.aipl`)

- **Signature**: `pub fn ctz(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `ctz` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `64`.

```aipl
module tests.functions.math.consts_z39_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_ctz_39(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = ctz(arg_x)
  let resEdge = ctz(edge_x)
  assertEqInt(resNom, 0, "ctz nominal resNom == 0")
  assertEqInt(resEdge, 64, "ctz boundary resEdge == 64")
  ret 0
```

---

### `clz` (`std/math/consts.aipl`)

- **Signature**: `pub fn clz(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `clz` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `64`.

```aipl
module tests.functions.math.consts_z40_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_clz_40(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = clz(arg_x)
  let resEdge = clz(edge_x)
  assertEqInt(resNom, 63, "clz nominal resNom == 63")
  assertEqInt(resEdge, 64, "clz boundary resEdge == 64")
  ret 0
```

---

### `popcnt64` (`std/math/consts.aipl`)

- **Signature**: `pub fn popcnt64(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `popcnt64` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `popcount64(x)`.

```aipl
module tests.functions.math.consts_z41_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_popcnt64_41(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = popcnt64(arg_x)
  let resEdge = popcnt64(edge_x)
  assertEqInt(resNom, 1, "popcnt64 nominal resNom == 1")
  assertEqInt(resEdge, 0, "popcnt64 boundary resEdge == 0")
  ret 0
```

---

### `ctz64` (`std/math/consts.aipl`)

- **Signature**: `pub fn ctz64(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `ctz64` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `ctz(x)`.

```aipl
module tests.functions.math.consts_z42_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_ctz64_42(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = ctz64(arg_x)
  let resEdge = ctz64(edge_x)
  assertEqInt(resNom, 0, "ctz64 nominal resNom == 0")
  assertEqInt(resEdge, 64, "ctz64 boundary resEdge == 64")
  ret 0
```

---

### `clz64` (`std/math/consts.aipl`)

- **Signature**: `pub fn clz64(x: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `clz64` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: int = 1`; exercises core body path returning/computing `clz(x)`.

```aipl
module tests.functions.math.consts_z43_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_clz64_43(): int:
  let arg_x = 1
  let edge_x = 0
  let resNom = clz64(arg_x)
  let resEdge = clz64(edge_x)
  assertEqInt(resNom, 63, "clz64 nominal resNom == 63")
  assertEqInt(resEdge, 64, "clz64 boundary resEdge == 64")
  ret 0
```

---

### `gf256Mul` (`std/math/consts.aipl`)

- **Signature**: `pub fn gf256Mul(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `gf256Mul` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.math.consts_z44_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_gf256Mul_44(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = gf256Mul(arg_a, arg_b)
  let resEdge = gf256Mul(edge_a, edge_b)
  assertEqInt(resNom, 8, "gf256Mul nominal resNom == 8")
  assertEqInt(resEdge, 0, "gf256Mul boundary resEdge == 0")
  ret 0
```

---

### `gf256Inv` (`std/math/consts.aipl`)

- **Signature**: `pub fn gf256Inv(b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `gf256Inv` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `b: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.math.consts_z45_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_gf256Inv_45(): int:
  let arg_b = 4
  let edge_b = 1
  let resNom = gf256Inv(arg_b)
  let resEdge = gf256Inv(edge_b)
  assertEqInt(resNom, 71, "gf256Inv nominal resNom == 71")
  assertEqInt(resEdge, 1, "gf256Inv boundary resEdge == 1")
  ret 0
```

---

### `gf256Div` (`std/math/consts.aipl`)

- **Signature**: `pub fn gf256Div(a: int, b: int): int:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `gf256Div` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `gf256Mul(a & 255, gf256Inv(y))`.

```aipl
module tests.functions.math.consts_z46_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_gf256Div_46(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = gf256Div(arg_a, arg_b)
  let resEdge = gf256Div(edge_a, edge_b)
  assertEqInt(resNom, 142, "gf256Div nominal resNom == 142")
  assertEqInt(resEdge, 0, "gf256Div boundary resEdge == 0")
  ret 0
```

---

### `ldexpFloat` (`std/math/consts.aipl`)

- **Signature**: `pub fn ldexpFloat(m: float, exp2: int): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: float, exp2: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `ldexpFloat` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `m: float = 1.0`, `exp2: int = 1`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.math.consts_z47_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_ldexpFloat_47(): int:
  let arg_m = 1.0
  let edge_m = 0.5
  let arg_exp2 = 1
  let edge_exp2 = 0
  let resNom = ldexpFloat(arg_m, arg_exp2)
  let resEdge = ldexpFloat(edge_m, edge_exp2)
  assertApproxEq(resNom, 2.0, 0.001, "ldexpFloat nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "ldexpFloat boundary resEdge ~= 0.5")
  ret 0
```

---

### `sqrtSafePrescaled` (`std/math/consts.aipl`)

- **Signature**: `pub fn sqrtSafePrescaled(x: float): float:`
- **Import**: `import * from "std/math/consts"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/consts_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify scalar/bitwise/Galois-field helper `sqrtSafePrescaled` across boundary inputs (`0`, `-1`, power-of-two edges, `[min, max]` clamping, or GF(2^8) inverse identities). Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `ldexpFloat(g, exp2 / 2)`.

```aipl
module tests.functions.math.consts_z48_test
import * from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_consts_sqrtSafePrescaled_48(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = sqrtSafePrescaled(arg_x)
  let resEdge = sqrtSafePrescaled(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "sqrtSafePrescaled nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.707107, 0.001, "sqrtSafePrescaled boundary resEdge ~= 0.707107")
  ret 0
```

---

### `vector2ToVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn vector2ToVec2(v: Vector2): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `vector2ToVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `v: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = v.x, y = v.y)`.

```aipl
module tests.functions.math.curve_z1_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_vector2ToVec2_1(): int:
  let arg_v = Vector2(x = 1.0, y = 1.0)
  let edge_v = Vector2(x = 0.5, y = 0.5)
  let resNom = vector2ToVec2(arg_v)
  let resEdge = vector2ToVec2(edge_v)
  assertApproxEq(resNom.x, 1.0, 0.001, "vector2ToVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vector2ToVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec2ToVector2` (`std/math/curve.aipl`)

- **Signature**: `pub fn vec2ToVector2(v: Vec2): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `vec2ToVector2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vector2(x = v.x, y = v.y)`.

```aipl
module tests.functions.math.curve_z2_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_vec2ToVector2_2(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2ToVector2(arg_v)
  let resEdge = vec2ToVector2(edge_v)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec2ToVector2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec2ToVector2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `quadraticBezier2D` (`std/math/curve.aipl`)

- **Signature**: `pub fn quadraticBezier2D(p0: Vec2, p1: Vec2, p2: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `quadraticBezier2D` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z3_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_quadraticBezier2D_3(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = quadraticBezier2D(arg_p0, arg_p1, arg_p2, arg_t)
  let resEdge = quadraticBezier2D(edge_p0, edge_p1, edge_p2, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "quadraticBezier2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "quadraticBezier2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `cubicBezier2D` (`std/math/curve.aipl`)

- **Signature**: `pub fn cubicBezier2D(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `cubicBezier2D` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z4_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_cubicBezier2D_4(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = cubicBezier2D(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = cubicBezier2D(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "cubicBezier2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "cubicBezier2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `catmullRom2D` (`std/math/curve.aipl`)

- **Signature**: `pub fn catmullRom2D(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `catmullRom2D` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z5_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_catmullRom2D_5(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = catmullRom2D(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = catmullRom2D(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "catmullRom2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "catmullRom2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `hermite2D` (`std/math/curve.aipl`)

- **Signature**: `pub fn hermite2D(p0: Vec2, m0: Vec2, p1: Vec2, m1: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, m0: Vec2, p1: Vec2, m1: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `hermite2D` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `m0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `m1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z6_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_hermite2D_6(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_m0 = Vec2(x = 1.0, y = 1.0)
  let edge_m0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_m1 = Vec2(x = 1.0, y = 1.0)
  let edge_m1 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = hermite2D(arg_p0, arg_m0, arg_p1, arg_m1, arg_t)
  let resEdge = hermite2D(edge_p0, edge_m0, edge_p1, edge_m1, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "hermite2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "hermite2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateQuadraticBezier` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateQuadraticBezier(p0: Vector2, p1: Vector2, p2: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateQuadraticBezier` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z7_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateQuadraticBezier_7(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateQuadraticBezier(arg_p0, arg_p1, arg_p2, arg_t)
  let resEdge = evaluateQuadraticBezier(edge_p0, edge_p1, edge_p2, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateQuadraticBezier nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateQuadraticBezier boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateQuadraticBezierVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateQuadraticBezierVec2(p0: Vec2, p1: Vec2, p2: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateQuadraticBezierVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `quadraticBezier2D(p0, p1, p2, t)`.

```aipl
module tests.functions.math.curve_z8_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateQuadraticBezierVec2_8(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateQuadraticBezierVec2(arg_p0, arg_p1, arg_p2, arg_t)
  let resEdge = evaluateQuadraticBezierVec2(edge_p0, edge_p1, edge_p2, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateQuadraticBezierVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateQuadraticBezierVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCubicBezier` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezier(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezier` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z9_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezier_9(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezier(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezier(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateCubicBezier nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateCubicBezier boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCubicBezierVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `cubicBezier2D(p0, p1, p2, p3, t)`.

```aipl
module tests.functions.math.curve_z10_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierVec2_10(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezierVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezierVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateCubicBezierVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateCubicBezierVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCubicBezierTangentVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierTangentVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierTangentVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z11_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierTangentVec2_11(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezierTangentVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezierTangentVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluateCubicBezierTangentVec2 nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateCubicBezierTangentVec2 boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateCubicBezierTangent` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierTangent(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierTangent` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z12_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierTangent_12(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezierTangent(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezierTangent(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluateCubicBezierTangent nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateCubicBezierTangent boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateCubicBezierNormalVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierNormalVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierNormalVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(x = -tan.y / l, y = tan.x / l)`.

```aipl
module tests.functions.math.curve_z13_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierNormalVec2_13(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezierNormalVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezierNormalVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluateCubicBezierNormalVec2 nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateCubicBezierNormalVec2 boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateCubicBezierNormal` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierNormal(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierNormal` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z14_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierNormal_14(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCubicBezierNormal(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCubicBezierNormal(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluateCubicBezierNormal nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateCubicBezierNormal boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateCatmullRomVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCatmullRomVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCatmullRomVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `catmullRom2D(p0, p1, p2, p3, t)`.

```aipl
module tests.functions.math.curve_z15_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCatmullRomVec2_15(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCatmullRomVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCatmullRomVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateCatmullRomVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateCatmullRomVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCatmullRom` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCatmullRom(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCatmullRom` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z16_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCatmullRom_16(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateCatmullRom(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateCatmullRom(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateCatmullRom nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateCatmullRom boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateUniformCubicBSplineVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateUniformCubicBSplineVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateUniformCubicBSplineVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.curve_z17_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateUniformCubicBSplineVec2_17(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateUniformCubicBSplineVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateUniformCubicBSplineVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateUniformCubicBSplineVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateUniformCubicBSplineVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateUniformCubicBSpline` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateUniformCubicBSpline(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float): Vector2:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, t: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateUniformCubicBSpline` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `vec2ToVector2(r)`.

```aipl
module tests.functions.math.curve_z18_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateUniformCubicBSpline_18(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateUniformCubicBSpline(arg_p0, arg_p1, arg_p2, arg_p3, arg_t)
  let resEdge = evaluateUniformCubicBSpline(edge_p0, edge_p1, edge_p2, edge_p3, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateUniformCubicBSpline nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateUniformCubicBSpline boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCubicBezierArcLengthVec2` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierArcLengthVec2(p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, steps: int): float:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vec2, p1: Vec2, p2: Vec2, p3: Vec2, steps: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierArcLengthVec2` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `steps: int = 1`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.math.curve_z19_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierArcLengthVec2_19(): int:
  let arg_p0 = Vec2(x = 1.0, y = 1.0)
  let edge_p0 = Vec2(x = 0.5, y = 0.5)
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_steps = 4
  let edge_steps = 1
  let resNom = evaluateCubicBezierArcLengthVec2(arg_p0, arg_p1, arg_p2, arg_p3, arg_steps)
  let resEdge = evaluateCubicBezierArcLengthVec2(edge_p0, edge_p1, edge_p2, edge_p3, edge_steps)
  assertApproxEq(resNom, 0.0, 0.001, "evaluateCubicBezierArcLengthVec2 nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "evaluateCubicBezierArcLengthVec2 boundary resEdge ~= 0.0")
  ret 0
```

---

### `evaluateCubicBezierArcLength` (`std/math/curve.aipl`)

- **Signature**: `pub fn evaluateCubicBezierArcLength(p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, steps: int): float:`
- **Import**: `import * from "std/math/curve"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p0: Vector2, p1: Vector2, p2: Vector2, p3: Vector2, steps: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/curve_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify parametric spline evaluator `evaluateCubicBezierArcLength` endpoint interpolation at `t=0` and `t=1`, tangent/normal perpendicularity (`dot(T, N) ~= 0`), and arc-length quadrature convergence. Concrete nominal inputs: `p0: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p1: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p2: Vector2 = Vector2(x = 1.0, y = 1.0)`, `p3: Vector2 = Vector2(x = 1.0, y = 1.0)`, `steps: int = 1`; exercises core body path returning/computing `evaluateCubicBezierArcLengthVec2(vector2ToVec2(p0), vector2ToVec2(p1), vector2ToVec2(p2), vector2ToVec2(p3), steps)`.

```aipl
module tests.functions.math.curve_z20_test
import * from "std/math/curve"
import { sqrt } from "std/math/trig"
import { Vec2, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_evaluateCubicBezierArcLength_20(): int:
  let arg_p0 = Vector2(x = 1.0, y = 1.0)
  let edge_p0 = Vector2(x = 0.5, y = 0.5)
  let arg_p1 = Vector2(x = 1.0, y = 1.0)
  let edge_p1 = Vector2(x = 0.5, y = 0.5)
  let arg_p2 = Vector2(x = 1.0, y = 1.0)
  let edge_p2 = Vector2(x = 0.5, y = 0.5)
  let arg_p3 = Vector2(x = 1.0, y = 1.0)
  let edge_p3 = Vector2(x = 0.5, y = 0.5)
  let arg_steps = 4
  let edge_steps = 1
  let resNom = evaluateCubicBezierArcLength(arg_p0, arg_p1, arg_p2, arg_p3, arg_steps)
  let resEdge = evaluateCubicBezierArcLength(edge_p0, edge_p1, edge_p2, edge_p3, edge_steps)
  assertApproxEq(resNom, 0.0, 0.001, "evaluateCubicBezierArcLength nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "evaluateCubicBezierArcLength boundary resEdge ~= 0.0")
  ret 0
```

---

### `easeLinear` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeLinear(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeLinear` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `clampFloat(t, 0.0, 1.0)`.

```aipl
module tests.functions.math.ease_z1_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeLinear_1(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeLinear(arg_t)
  let resEdge = easeLinear(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeLinear nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeLinear boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeInQuad` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInQuad(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInQuad` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * c`.

```aipl
module tests.functions.math.ease_z2_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInQuad_2(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInQuad(arg_t)
  let resEdge = easeInQuad(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInQuad nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.25, 0.001, "easeInQuad boundary resEdge ~= 0.25")
  ret 0
```

---

### `easeOutQuad` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutQuad(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutQuad` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * (2.0 - c)`.

```aipl
module tests.functions.math.ease_z3_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutQuad_3(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutQuad(arg_t)
  let resEdge = easeOutQuad(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutQuad nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.75, 0.001, "easeOutQuad boundary resEdge ~= 0.75")
  ret 0
```

---

### `easeInOutQuad` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutQuad(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutQuad` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `-1.0 + (4.0 - 2.0 * c) * c`.

```aipl
module tests.functions.math.ease_z4_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutQuad_4(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutQuad(arg_t)
  let resEdge = easeInOutQuad(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutQuad nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutQuad boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeInCubic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInCubic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInCubic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * c * c`.

```aipl
module tests.functions.math.ease_z5_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInCubic_5(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInCubic(arg_t)
  let resEdge = easeInCubic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInCubic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.125, 0.001, "easeInCubic boundary resEdge ~= 0.125")
  ret 0
```

---

### `easeOutCubic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutCubic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutCubic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `u * u * u + 1.0`.

```aipl
module tests.functions.math.ease_z6_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutCubic_6(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutCubic(arg_t)
  let resEdge = easeOutCubic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutCubic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.875, 0.001, "easeOutCubic boundary resEdge ~= 0.875")
  ret 0
```

---

### `easeInOutCubic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutCubic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutCubic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 - (u * u * u) * 0.5`.

```aipl
module tests.functions.math.ease_z7_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutCubic_7(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutCubic(arg_t)
  let resEdge = easeInOutCubic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutCubic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutCubic boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeInQuart` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInQuart(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInQuart` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * c * c * c`.

```aipl
module tests.functions.math.ease_z8_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInQuart_8(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInQuart(arg_t)
  let resEdge = easeInQuart(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInQuart nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0625, 0.001, "easeInQuart boundary resEdge ~= 0.0625")
  ret 0
```

---

### `easeOutQuart` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutQuart(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutQuart` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 - u * u * u * u`.

```aipl
module tests.functions.math.ease_z9_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutQuart_9(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutQuart(arg_t)
  let resEdge = easeOutQuart(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutQuart nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.9375, 0.001, "easeOutQuart boundary resEdge ~= 0.9375")
  ret 0
```

---

### `easeInOutQuart` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutQuart(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutQuart` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 - (u * u * u * u) * 0.5`.

```aipl
module tests.functions.math.ease_z10_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutQuart_10(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutQuart(arg_t)
  let resEdge = easeInOutQuart(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutQuart nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutQuart boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeInBack` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInBack(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInBack` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c3 * c * c * c - c1 * c * c`.

```aipl
module tests.functions.math.ease_z11_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInBack_11(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInBack(arg_t)
  let resEdge = easeInBack(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInBack nominal resNom ~= 1.0")
  assertApproxEq(resEdge, -0.087697, 0.001, "easeInBack boundary resEdge ~= -0.087697")
  ret 0
```

---

### `easeOutBack` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutBack(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutBack` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 + c3 * u * u * u + c1 * u * u`.

```aipl
module tests.functions.math.ease_z12_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutBack_12(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutBack(arg_t)
  let resEdge = easeOutBack(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutBack nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0877, 0.001, "easeOutBack boundary resEdge ~= 1.0877")
  ret 0
```

---

### `easeInOutBack` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutBack(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutBack` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `(u * u * ((c2 + 1.0) * u + c2) + 2.0) * 0.5`.

```aipl
module tests.functions.math.ease_z13_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutBack_13(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutBack(arg_t)
  let resEdge = easeInOutBack(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutBack nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutBack boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeInElastic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInElastic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInElastic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `-pow(2.0, 10.0 * c - 10.0) * sin((c * 10.0 - 10.75) * c4)`.

```aipl
module tests.functions.math.ease_z14_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInElastic_14(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInElastic(arg_t)
  let resEdge = easeInElastic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInElastic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, -0.015625, 0.001, "easeInElastic boundary resEdge ~= -0.015625")
  ret 0
```

---

### `easeOutElastic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutElastic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutElastic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `pow(2.0, -10.0 * c) * sin((c * 10.0 - 0.75) * c4) + 1.0`.

```aipl
module tests.functions.math.ease_z15_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutElastic_15(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutElastic(arg_t)
  let resEdge = easeOutElastic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutElastic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.01562, 0.001, "easeOutElastic boundary resEdge ~= 1.01562")
  ret 0
```

---

### `easeInOutElastic` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutElastic(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutElastic` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `(pow(2.0, -20.0 * c + 10.0) * sin((20.0 * c - 11.125) * c5)) * 0.5 + 1.0`.

```aipl
module tests.functions.math.ease_z16_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutElastic_16(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutElastic(arg_t)
  let resEdge = easeInOutElastic(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutElastic nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutElastic boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeOutBounce` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeOutBounce(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeOutBounce` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `n1 * u * u + 0.984375`.

```aipl
module tests.functions.math.ease_z17_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeOutBounce_17(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeOutBounce(arg_t)
  let resEdge = easeOutBounce(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeOutBounce nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.765625, 0.001, "easeOutBounce boundary resEdge ~= 0.765625")
  ret 0
```

---

### `easeInBounce` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInBounce(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInBounce` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `1.0 - easeOutBounce(1.0 - c)`.

```aipl
module tests.functions.math.ease_z18_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInBounce_18(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInBounce(arg_t)
  let resEdge = easeInBounce(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInBounce nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.234375, 0.001, "easeInBounce boundary resEdge ~= 0.234375")
  ret 0
```

---

### `easeInOutBounce` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeInOutBounce(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeInOutBounce` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `(1.0 + easeOutBounce(2.0 * c - 1.0)) * 0.5`.

```aipl
module tests.functions.math.ease_z19_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeInOutBounce_19(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeInOutBounce(arg_t)
  let resEdge = easeInOutBounce(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeInOutBounce nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeInOutBounce boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeSmoothstep` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeSmoothstep(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeSmoothstep` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * c * (3.0 - 2.0 * c)`.

```aipl
module tests.functions.math.ease_z20_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeSmoothstep_20(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeSmoothstep(arg_t)
  let resEdge = easeSmoothstep(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeSmoothstep nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeSmoothstep boundary resEdge ~= 0.5")
  ret 0
```

---

### `easeSmootherstep` (`std/math/ease.aipl`)

- **Signature**: `pub fn easeSmootherstep(t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify easing curve `easeSmootherstep` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `t: float = 0.5`; exercises core body path returning/computing `c * c * c * (c * (c * 6.0 - 15.0) + 10.0)`.

```aipl
module tests.functions.math.ease_z21_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_easeSmootherstep_21(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = easeSmootherstep(arg_t)
  let resEdge = easeSmootherstep(edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "easeSmootherstep nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "easeSmootherstep boundary resEdge ~= 0.5")
  ret 0
```

---

### `evalEase` (`std/math/ease.aipl`)

- **Signature**: `pub fn evalEase(mode: int, t: float): float:`
- **Import**: `import * from "std/math/ease"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mode: int, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/ease_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify easing curve `evalEase` endpoint fixation (`f(0.0) == 0.0`, `f(1.0) == 1.0`), midpoint `t = 0.5` value, and monotonic or elastic/back overshoot profile. Concrete nominal inputs: `mode: int = 1`, `t: float = 0.5`; exercises core body path returning/computing `easeLinear(t)`.

```aipl
module tests.functions.math.ease_z22_test
import * from "std/math/ease"
import { PI, clampFloat } from "std/math/consts"
import { sin, pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ease_evalEase_22(): int:
  let arg_mode = 4
  let edge_mode = 1
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evalEase(arg_mode, arg_t)
  let resEdge = evalEase(edge_mode, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "evalEase nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.25, 0.001, "evalEase boundary resEdge ~= 0.25")
  ret 0
```

---

### `fixedFromInt` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn fixedFromInt(val: int): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `fixedFromInt` (`free fn`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `FixedQ16_16(raw = val << FIXED_Q16_SHIFT)`.

```aipl
module tests.functions.math.fixed_point_z1_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_fixedFromInt_1(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = fixedFromInt(arg_val)
  let resEdge = fixedFromInt(edge_val)
  assertEqInt(resNom.raw, 131072, "fixedFromInt nominal resNom.raw == 131072")
  assertEqInt(resEdge.raw, 0, "fixedFromInt boundary resEdge.raw == 0")
  ret 0
```

---

### `fixedFromFloat` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn fixedFromFloat(val: float): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `fixedFromFloat` (`free fn`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: `val: float = 1.0`; exercises core body path returning/computing `FixedQ16_16(raw = r)`.

```aipl
module tests.functions.math.fixed_point_z2_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_fixedFromFloat_2(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = fixedFromFloat(arg_val)
  let resEdge = fixedFromFloat(edge_val)
  assertEqInt(resNom.raw, 65536, "fixedFromFloat nominal resNom.raw == 65536")
  assertEqInt(resEdge.raw, 32768, "fixedFromFloat boundary resEdge.raw == 32768")
  ret 0
```

---

### `toInt` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) toInt(): int:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `toInt` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `self.raw >> FIXED_Q16_SHIFT`.

```aipl
module tests.functions.math.fixed_point_z3_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_toInt_3(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let resNom = recv_self.toInt()
  let resEdge = edge_self.toInt()
  assertEqInt(resNom, 0, "toInt nominal resNom == 0")
  assertEqInt(resEdge, 0, "toInt boundary resEdge == 0")
  ret 0
```

---

### `toFloat` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) toFloat(): float:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `toFloat` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `float(self.raw) / 65536.0`.

```aipl
module tests.functions.math.fixed_point_z4_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_toFloat_4(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let resNom = recv_self.toFloat()
  let resEdge = edge_self.toFloat()
  assertApproxEq(resNom, 0.000031, 0.001, "toFloat nominal resNom ~= 0.000031")
  assertApproxEq(resEdge, 0.0, 0.001, "toFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `add` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) add(other: FixedQ16_16): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `other: FixedQ16_16` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `add` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`, `other: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `FixedQ16_16(raw = self.raw + other.raw)`.

```aipl
module tests.functions.math.fixed_point_z5_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_add_5(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let arg_other = FixedQ16_16(raw = 2)
  let edge_other = FixedQ16_16(raw = 0)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertEqInt(resNom.raw, 4, "add nominal resNom.raw == 4")
  assertEqInt(resEdge.raw, 0, "add boundary resEdge.raw == 0")
  ret 0
```

---

### `sub` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) sub(other: FixedQ16_16): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `other: FixedQ16_16` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `sub` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`, `other: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `FixedQ16_16(raw = self.raw - other.raw)`.

```aipl
module tests.functions.math.fixed_point_z6_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_sub_6(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let arg_other = FixedQ16_16(raw = 2)
  let edge_other = FixedQ16_16(raw = 0)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertEqInt(resNom.raw, 0, "sub nominal resNom.raw == 0")
  assertEqInt(resEdge.raw, 0, "sub boundary resEdge.raw == 0")
  ret 0
```

---

### `mul` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) mul(other: FixedQ16_16): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `other: FixedQ16_16` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `mul` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`, `other: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `FixedQ16_16(raw = (self.raw * other.raw) >> FIXED_Q16_SHIFT)`.

```aipl
module tests.functions.math.fixed_point_z7_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_mul_7(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let arg_other = FixedQ16_16(raw = 2)
  let edge_other = FixedQ16_16(raw = 0)
  let resNom = recv_self.mul(arg_other)
  let resEdge = edge_self.mul(edge_other)
  assertEqInt(resNom.raw, 0, "mul nominal resNom.raw == 0")
  assertEqInt(resEdge.raw, 0, "mul boundary resEdge.raw == 0")
  ret 0
```

---

### `div` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) div(other: FixedQ16_16): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `other: FixedQ16_16` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `div` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`, `other: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `FixedQ16_16(raw = (self.raw << FIXED_Q16_SHIFT) / other.raw)`.

```aipl
module tests.functions.math.fixed_point_z8_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_div_8(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let arg_other = FixedQ16_16(raw = 2)
  let edge_other = FixedQ16_16(raw = 0)
  let resNom = recv_self.div(arg_other)
  let resEdge = edge_self.div(edge_other)
  assertEqInt(resNom.raw, 65536, "div nominal resNom.raw == 65536")
  assertEqInt(resEdge.raw, 0, "div boundary resEdge.raw == 0")
  ret 0
```

---

### `abs` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ16_16) abs(): FixedQ16_16:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ16_16` | **Parameters**: `none` | **Returns**: `FixedQ16_16`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `abs` (`self: FixedQ16_16`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ16_16 = FixedQ16_16(raw = 1)`; exercises core body path returning/computing `FixedQ16_16(raw = if self.raw < 0: -self.raw else: self.raw)`.

```aipl
module tests.functions.math.fixed_point_z9_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ16_16_abs_9(): int:
  let recv_self = FixedQ16_16(raw = 2)
  let edge_self = FixedQ16_16(raw = 0)
  let resNom = recv_self.abs()
  let resEdge = edge_self.abs()
  assertEqInt(resNom.raw, 2, "abs nominal resNom.raw == 2")
  assertEqInt(resEdge.raw, 0, "abs boundary resEdge.raw == 0")
  ret 0
```

---

### `fixedQ32FromInt` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn fixedQ32FromInt(val: int): FixedQ32_32:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `FixedQ32_32`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `fixedQ32FromInt` (`free fn`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `FixedQ32_32(raw = val << 32)`.

```aipl
module tests.functions.math.fixed_point_z10_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_fixedQ32FromInt_10(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = fixedQ32FromInt(arg_val)
  let resEdge = fixedQ32FromInt(edge_val)
  assertEqInt(resNom.raw, 8589934592, "fixedQ32FromInt nominal resNom.raw == 8589934592")
  assertEqInt(resEdge.raw, 0, "fixedQ32FromInt boundary resEdge.raw == 0")
  ret 0
```

---

### `toInt` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ32_32) toInt(): int:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ32_32` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `toInt` (`self: FixedQ32_32`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ32_32 = FixedQ32_32(raw = 1)`; exercises core body path returning/computing `self.raw >> 32`.

```aipl
module tests.functions.math.fixed_point_z11_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ32_32_toInt_11(): int:
  let recv_self = FixedQ32_32(raw = 2)
  let edge_self = FixedQ32_32(raw = 0)
  let resNom = recv_self.toInt()
  let resEdge = edge_self.toInt()
  assertEqInt(resNom, 0, "toInt nominal resNom == 0")
  assertEqInt(resEdge, 0, "toInt boundary resEdge == 0")
  ret 0
```

---

### `add` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ32_32) add(other: FixedQ32_32): FixedQ32_32:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ32_32` | **Parameters**: `other: FixedQ32_32` | **Returns**: `FixedQ32_32`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `add` (`self: FixedQ32_32`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ32_32 = FixedQ32_32(raw = 1)`, `other: FixedQ32_32 = FixedQ32_32(raw = 1)`; exercises core body path returning/computing `FixedQ32_32(raw = self.raw + other.raw)`.

```aipl
module tests.functions.math.fixed_point_z12_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ32_32_add_12(): int:
  let recv_self = FixedQ32_32(raw = 2)
  let edge_self = FixedQ32_32(raw = 0)
  let arg_other = FixedQ32_32(raw = 2)
  let edge_other = FixedQ32_32(raw = 0)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertEqInt(resNom.raw, 4, "add nominal resNom.raw == 4")
  assertEqInt(resEdge.raw, 0, "add boundary resEdge.raw == 0")
  ret 0
```

---

### `sub` (`std/math/fixed_point.aipl`)

- **Signature**: `pub fn (self: FixedQ32_32) sub(other: FixedQ32_32): FixedQ32_32:`
- **Import**: `import * from "std/math/fixed_point"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: FixedQ32_32` | **Parameters**: `other: FixedQ32_32` | **Returns**: `FixedQ32_32`
- **Unit Test**: `tests/functions/math/fixed_point_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify deterministic fixed-point `sub` (`self: FixedQ32_32`) bit-exact Q16.16 (`1/65536`) / Q32.32 scaling on negative, zero, and fractional values (`1.5`, `-2.25`) without IEEE-754 drift. Concrete nominal inputs: receiver `recvObj: FixedQ32_32 = FixedQ32_32(raw = 1)`, `other: FixedQ32_32 = FixedQ32_32(raw = 1)`; exercises core body path returning/computing `FixedQ32_32(raw = self.raw - other.raw)`.

```aipl
module tests.functions.math.fixed_point_z13_test
import * from "std/math/fixed_point"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fixed_point_FixedQ32_32_sub_13(): int:
  let recv_self = FixedQ32_32(raw = 2)
  let edge_self = FixedQ32_32(raw = 0)
  let arg_other = FixedQ32_32(raw = 2)
  let edge_other = FixedQ32_32(raw = 0)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertEqInt(resNom.raw, 0, "sub nominal resNom.raw == 0")
  assertEqInt(resEdge.raw, 0, "sub boundary resEdge.raw == 0")
  ret 0
```

---

### `Rect.new` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn Rect.new(x: float, y: float, w: float, h: float): Rect:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, w: float, h: float` | **Returns**: `Rect`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `Rect.new` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `Rect(x = x, y = y, w = w, h = h)`.

```aipl
module tests.functions.math.geom2d_z1_test
import * from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_Rect_new_1(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let arg_w = 1.0
  let edge_w = 0.0
  let arg_h = 1.0
  let edge_h = 0.0
  let resNom = Rect.new(arg_x, arg_y, arg_w, arg_h)
  let resEdge = Rect.new(edge_x, edge_y, edge_w, edge_h)
  assertApproxEq(resNom.x, 1.0, 0.001, "Rect.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Rect.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `contains` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn (self: Rect) contains(px: float, py: float): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Rect` | **Parameters**: `px: float, py: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `contains` (`self: Rect`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: receiver `recvObj: Rect = Rect(x = 1.0, y = 1.0, w = 1.0, h = 1.0)`, `px: float = 1.0`, `py: float = 1.0`; exercises core body path returning/computing `px >= self.x and px <= self.x + self.w and py >= self.y and py <= self.y + self.h`.

```aipl
module tests.functions.math.geom2d_z2_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_Rect_contains_2(): int:
  let recv_self = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_self = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let resNom = recv_self.contains(arg_px, arg_py)
  let resEdge = edge_self.contains(edge_px, edge_py)
  assert(resNom == true, "contains nominal resNom == true")
  assert(resEdge == true, "contains boundary resEdge == true")
  ret 0
```

---

### `intersects` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn (self: Rect) intersects(other: Rect): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Rect` | **Parameters**: `other: Rect` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `intersects` (`self: Rect`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: receiver `recvObj: Rect = Rect(x = 1.0, y = 1.0, w = 1.0, h = 1.0)`, `other: Rect = Rect(x = 1.0, y = 1.0, w = 1.0, h = 1.0)`; exercises core body path returning/computing `self.x < other.x + other.w and self.x + self.w > other.x and self.y < other.y + other.h and self.y + self.h > other.y`.

```aipl
module tests.functions.math.geom2d_z3_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_Rect_intersects_3(): int:
  let recv_self = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_self = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let arg_other = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_other = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let resNom = recv_self.intersects(arg_other)
  let resEdge = edge_self.intersects(edge_other)
  assert(resNom == true, "intersects nominal resNom == true")
  assert(resEdge == true, "intersects boundary resEdge == true")
  ret 0
```

---

### `vec2New` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2New(x: float, y: float): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2New` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `Vec2(x = x, y = y)`.

```aipl
module tests.functions.math.geom2d_z4_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2New_4(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = vec2New(arg_x, arg_y)
  let resEdge = vec2New(edge_x, edge_y)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec2New nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec2New boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `ivec2` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn ivec2(x: int, y: int): IVec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int` | **Returns**: `IVec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `ivec2` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `IVec2(x = x, y = y)`.

```aipl
module tests.functions.math.geom2d_z5_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_ivec2_5(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = ivec2(arg_x, arg_y)
  let resEdge = ivec2(edge_x, edge_y)
  assertEqInt(resNom.x, 1, "ivec2 nominal resNom.x == 1")
  assertEqInt(resEdge.x, 0, "ivec2 boundary resEdge.x == 0")
  ret 0
```

---

### `rect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rect(x: float, y: float, w: float, h: float): Rect:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, w: float, h: float` | **Returns**: `Rect`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `w: float = 1.0`, `h: float = 1.0`; exercises core body path returning/computing `Rect(x = x, y = y, w = w, h = h)`.

```aipl
module tests.functions.math.geom2d_z6_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rect_6(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_h = 2.0
  let edge_h = 1.0
  let resNom = rect(arg_x, arg_y, arg_w, arg_h)
  let resEdge = rect(edge_x, edge_y, edge_w, edge_h)
  assertApproxEq(resNom.x, 1.0, 0.001, "rect nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "rect boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `irect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn irect(x: int, y: int, w: int, h: int): IRect:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int, w: int, h: int` | **Returns**: `IRect`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `irect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x: int = 1`, `y: int = 1`, `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `IRect(x = x, y = y, w = w, h = h)`.

```aipl
module tests.functions.math.geom2d_z7_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_irect_7(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = irect(arg_x, arg_y, arg_w, arg_h)
  let resEdge = irect(edge_x, edge_y, edge_w, edge_h)
  assertEqInt(resNom.x, 1, "irect nominal resNom.x == 1")
  assertEqInt(resEdge.x, 0, "irect boundary resEdge.x == 0")
  ret 0
```

---

### `rectToRect2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rectToRect2D(r: Rect): Rect2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: Rect` | **Returns**: `Rect2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rectToRect2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `r: Rect = Rect(x = 1.0, y = 1.0, w = 1.0, h = 1.0)`; exercises core body path returning/computing `Rect2D(x = r.x, y = r.y, w = r.w, h = r.h)`.

```aipl
module tests.functions.math.geom2d_z8_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rectToRect2D_8(): int:
  let arg_r = Rect(x = 1.0, y = 1.0, w = 2.0, h = 2.0)
  let edge_r = Rect(x = 0.5, y = 0.5, w = 1.0, h = 1.0)
  let resNom = rectToRect2D(arg_r)
  let resEdge = rectToRect2D(edge_r)
  assertApproxEq(resNom.x, 1.0, 0.001, "rectToRect2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "rectToRect2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `rectFromRect2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rectFromRect2D(r: Rect2D): Rect:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: Rect2D` | **Returns**: `Rect`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rectFromRect2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `Rect(x = r.x, y = r.y, w = r.w, h = r.h)`.

```aipl
module tests.functions.math.geom2d_z9_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rectFromRect2D_9(): int:
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rectFromRect2D(arg_r)
  let resEdge = rectFromRect2D(edge_r)
  assertApproxEq(resNom.x, 1.0, 0.001, "rectFromRect2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "rectFromRect2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec2Add` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Add(a: Vec2, b: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Add` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = a.x + b.x, y = a.y + b.y)`.

```aipl
module tests.functions.math.geom2d_z10_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Add_10(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Add(arg_a, arg_b)
  let resEdge = vec2Add(edge_a, edge_b)
  assertApproxEq(resNom.x, 2.0, 0.001, "vec2Add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "vec2Add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `vec2Sub` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Sub(a: Vec2, b: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Sub` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = a.x - b.x, y = a.y - b.y)`.

```aipl
module tests.functions.math.geom2d_z11_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Sub_11(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Sub(arg_a, arg_b)
  let resEdge = vec2Sub(edge_a, edge_b)
  assertApproxEq(resNom.x, 0.0, 0.001, "vec2Sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "vec2Sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `vec2Scale` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Scale(v: Vec2, s: float): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2, s: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Scale` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vec2(x = v.x * s, y = v.y * s)`.

```aipl
module tests.functions.math.geom2d_z12_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Scale_12(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = vec2Scale(arg_v, arg_s)
  let resEdge = vec2Scale(edge_v, edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec2Scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "vec2Scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `vec2Dot` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Dot(a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Dot` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `a.x * b.x + a.y * b.y`.

```aipl
module tests.functions.math.geom2d_z13_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Dot_13(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Dot(arg_a, arg_b)
  let resEdge = vec2Dot(edge_a, edge_b)
  assertApproxEq(resNom, 2.0, 0.001, "vec2Dot nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "vec2Dot boundary resEdge ~= 0.5")
  ret 0
```

---

### `vec2Cross` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Cross(a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Cross` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `a.x * b.y - a.y * b.x`.

```aipl
module tests.functions.math.geom2d_z14_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Cross_14(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Cross(arg_a, arg_b)
  let resEdge = vec2Cross(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec2Cross nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec2Cross boundary resEdge ~= 0.0")
  ret 0
```

---

### `vec2Len` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Len(v: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Len` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `sqrt(v.x * v.x + v.y * v.y)`.

```aipl
module tests.functions.math.geom2d_z15_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Len_15(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Len(arg_v)
  let resEdge = vec2Len(edge_v)
  assertApproxEq(resNom, 1.41421, 0.001, "vec2Len nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "vec2Len boundary resEdge ~= 0.707107")
  ret 0
```

---

### `vec2Dist` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Dist(a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Dist` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `sqrt(dx * dx + dy * dy)`.

```aipl
module tests.functions.math.geom2d_z16_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Dist_16(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Dist(arg_a, arg_b)
  let resEdge = vec2Dist(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec2Dist nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec2Dist boundary resEdge ~= 0.0")
  ret 0
```

---

### `vec2Norm` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Norm(v: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Norm` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = 0.0, y = 0.0)`.

```aipl
module tests.functions.math.geom2d_z17_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Norm_17(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Norm(arg_v)
  let resEdge = vec2Norm(edge_v)
  assertApproxEq(resNom.x, 0.707107, 0.001, "vec2Norm nominal resNom.x ~= 0.707107")
  assertApproxEq(resEdge.x, 0.707107, 0.001, "vec2Norm boundary resEdge.x ~= 0.707107")
  ret 0
```

---

### `vec2Rotate` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Rotate(v: Vec2, radians: float): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2, radians: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Rotate` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radians: float = 1.0`; exercises core body path returning/computing `Vec2(x = v.x * c - v.y * s, y = v.x * s + v.y * c)`.

```aipl
module tests.functions.math.geom2d_z18_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Rotate_18(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let arg_radians = 1.0
  let edge_radians = 0.5
  let resNom = vec2Rotate(arg_v, arg_radians)
  let resEdge = vec2Rotate(edge_v, edge_radians)
  assertApproxEq(resNom.x, -0.301169, 0.001, "vec2Rotate nominal resNom.x ~= -0.301169")
  assertApproxEq(resEdge.x, 0.199079, 0.001, "vec2Rotate boundary resEdge.x ~= 0.199079")
  ret 0
```

---

### `vec2Reflect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Reflect(v: Vec2, normal: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2, normal: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Reflect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`, `normal: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = v.x - dot2 * normal.x, y = v.y - dot2 * normal.y)`.

```aipl
module tests.functions.math.geom2d_z19_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Reflect_19(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let arg_normal = Vec2(x = 1.0, y = 1.0)
  let edge_normal = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Reflect(arg_v, arg_normal)
  let resEdge = vec2Reflect(edge_v, edge_normal)
  assertApproxEq(resNom.x, -3.0, 0.001, "vec2Reflect nominal resNom.x ~= -3.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "vec2Reflect boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `rectContainsPoint` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rectContainsPoint(r: Rect2D, p: Vec2): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: Rect2D, p: Vec2` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rectContainsPoint` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `p: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `p.x >= r.x and p.x <= r.x + r.w and p.y >= r.y and p.y <= r.y + r.h`.

```aipl
module tests.functions.math.geom2d_z20_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rectContainsPoint_20(): int:
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_p = Vec2(x = 1.0, y = 1.0)
  let edge_p = Vec2(x = 0.5, y = 0.5)
  let resNom = rectContainsPoint(arg_r, arg_p)
  let resEdge = rectContainsPoint(edge_r, edge_p)
  assert(resNom == true, "rectContainsPoint nominal resNom == true")
  assert(resEdge == true, "rectContainsPoint boundary resEdge == true")
  ret 0
```

---

### `rectIntersectsRect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rectIntersectsRect(a: Rect2D, b: Rect2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Rect2D, b: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rectIntersectsRect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `b: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `a.x < b.x + b.w and a.x + a.w > b.x and a.y < b.y + b.h and a.y + a.h > b.y`.

```aipl
module tests.functions.math.geom2d_z21_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rectIntersectsRect_21(): int:
  let arg_a = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_a = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_b = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_b = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rectIntersectsRect(arg_a, arg_b)
  let resEdge = rectIntersectsRect(edge_a, edge_b)
  assert(resNom == true, "rectIntersectsRect nominal resNom == true")
  assert(resEdge == true, "rectIntersectsRect boundary resEdge == true")
  ret 0
```

---

### `rectIntersects` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rectIntersects(a: Rect2D, b: Rect2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Rect2D, b: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rectIntersects` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `b: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `rectIntersectsRect(a, b)`.

```aipl
module tests.functions.math.geom2d_z22_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rectIntersects_22(): int:
  let arg_a = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_a = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_b = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_b = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rectIntersects(arg_a, arg_b)
  let resEdge = rectIntersects(edge_a, edge_b)
  assert(resNom == true, "rectIntersects nominal resNom == true")
  assert(resEdge == true, "rectIntersects boundary resEdge == true")
  ret 0
```

---

### `pointInRect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn pointInRect(px: float, py: float, rx: float, ry: float, rw: float, rh: float): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `px: float, py: float, rx: float, ry: float, rw: float, rh: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `pointInRect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `px: float = 1.0`, `py: float = 1.0`, `rx: float = 1.0`, `ry: float = 1.0`, `rw: float = 1.0`, `rh: float = 1.0`; exercises core body path returning/computing `px >= rx and px <= rx + rw and py >= ry and py <= ry + rh`.

```aipl
module tests.functions.math.geom2d_z23_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_pointInRect_23(): int:
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_rx = 1.0
  let edge_rx = 0.5
  let arg_ry = 1.0
  let edge_ry = 0.5
  let arg_rw = 2.0
  let edge_rw = 1.0
  let arg_rh = 2.0
  let edge_rh = 1.0
  let resNom = pointInRect(arg_px, arg_py, arg_rx, arg_ry, arg_rw, arg_rh)
  let resEdge = pointInRect(edge_px, edge_py, edge_rx, edge_ry, edge_rw, edge_rh)
  assert(resNom == true, "pointInRect nominal resNom == true")
  assert(resEdge == true, "pointInRect boundary resEdge == true")
  ret 0
```

---

### `pointInRectInt` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn pointInRectInt(px: int, py: int, rx: int, ry: int, rw: int, rh: int): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `px: int, py: int, rx: int, ry: int, rw: int, rh: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `pointInRectInt` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `px: int = 1`, `py: int = 1`, `rx: int = 1`, `ry: int = 1`, `rw: int = 1`, `rh: int = 1`; exercises core body path returning/computing `px >= rx and px <= rx + rw and py >= ry and py <= ry + rh`.

```aipl
module tests.functions.math.geom2d_z24_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_pointInRectInt_24(): int:
  let arg_px = 1
  let edge_px = 0
  let arg_py = 1
  let edge_py = 0
  let arg_rx = 1
  let edge_rx = 0
  let arg_ry = 1
  let edge_ry = 0
  let arg_rw = 2
  let edge_rw = 0
  let arg_rh = 2
  let edge_rh = 0
  let resNom = pointInRectInt(arg_px, arg_py, arg_rx, arg_ry, arg_rw, arg_rh)
  let resEdge = pointInRectInt(edge_px, edge_py, edge_rx, edge_ry, edge_rw, edge_rh)
  assert(resNom == true, "pointInRectInt nominal resNom == true")
  assert(resEdge == true, "pointInRectInt boundary resEdge == true")
  ret 0
```

---

### `circleIntersectsCircle` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn circleIntersectsCircle(a: Circle2D, b: Circle2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Circle2D, b: Circle2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `circleIntersectsCircle` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`, `b: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`; exercises core body path returning/computing `(dx * dx + dy * dy) <= (rSum * rSum)`.

```aipl
module tests.functions.math.geom2d_z25_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_circleIntersectsCircle_25(): int:
  let arg_a = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_a = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let arg_b = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_b = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let resNom = circleIntersectsCircle(arg_a, arg_b)
  let resEdge = circleIntersectsCircle(edge_a, edge_b)
  assert(resNom == true, "circleIntersectsCircle nominal resNom == true")
  assert(resEdge == true, "circleIntersectsCircle boundary resEdge == true")
  ret 0
```

---

### `circleIntersectsRect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn circleIntersectsRect(c: Circle2D, r: Rect2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: Circle2D, r: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `circleIntersectsRect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `c: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`, `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `(dx * dx + dy * dy) <= (c.r * c.r)`.

```aipl
module tests.functions.math.geom2d_z26_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_circleIntersectsRect_26(): int:
  let arg_c = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_c = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = circleIntersectsRect(arg_c, arg_r)
  let resEdge = circleIntersectsRect(edge_c, edge_r)
  assert(resNom == true, "circleIntersectsRect nominal resNom == true")
  assert(resEdge == true, "circleIntersectsRect boundary resEdge == true")
  ret 0
```

---

### `circleRectIntersects` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn circleRectIntersects(c: Circle2D, r: Rect2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: Circle2D, r: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `circleRectIntersects` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `c: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`, `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `circleIntersectsRect(c, r)`.

```aipl
module tests.functions.math.geom2d_z27_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_circleRectIntersects_27(): int:
  let arg_c = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_c = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = circleRectIntersects(arg_c, arg_r)
  let resEdge = circleRectIntersects(edge_c, edge_r)
  assert(resNom == true, "circleRectIntersects nominal resNom == true")
  assert(resEdge == true, "circleRectIntersects boundary resEdge == true")
  ret 0
```

---

### `collideCircleRect` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn collideCircleRect(c: Circle2D, r: Rect2D): CollisionHit:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: Circle2D, r: Rect2D` | **Returns**: `CollisionHit`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `collideCircleRect` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `c: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`, `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `CollisionHit(hit = true, normalX = 0.0, normalY = -1.0, depth = c.r)`.

```aipl
module tests.functions.math.geom2d_z28_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_collideCircleRect_28(): int:
  let arg_c = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_c = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = collideCircleRect(arg_c, arg_r)
  let resEdge = collideCircleRect(edge_c, edge_r)
  assert(resNom.hit == true, "collideCircleRect nominal resNom.hit == true")
  assert(resEdge.hit == true, "collideCircleRect boundary resEdge.hit == true")
  ret 0
```

---

### `rayIntersectsRect2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn rayIntersectsRect2D(ray: Ray2D, rect: Rect2D): Option[float]:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray2D, rect: Rect2D` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `rayIntersectsRect2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `ray: Ray2D = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2 = Vec2(x = 1.0, y = 0.0)(), direction = Vec2 = Vec2(x = 1.0, y = 0.0)(), maxDistance = float = 1000.0())`, `rect: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `Some(if tMin >= 0.0: tMin else: tMax)`.

```aipl
module tests.functions.math.geom2d_z29_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_rayIntersectsRect2D_29(): int:
  let arg_ray = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2(x = 1.0, y = 1.0), direction = Vec2(x = 1.0, y = 1.0), maxDistance = 2.0)
  let edge_ray = Ray2D(origin = Vec2(x = 0.5, y = 0.5), dir = Vec2(x = 0.5, y = 0.5), direction = Vec2(x = 0.5, y = 0.5), maxDistance = 1.0)
  let arg_rect = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_rect = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rayIntersectsRect2D(arg_ray, arg_rect)
  let resEdge = rayIntersectsRect2D(edge_ray, edge_rect)
  assert(resNom.isSome() == true, "rayIntersectsRect2D nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "rayIntersectsRect2D boundary resEdge.isSome() == true")
  ret 0
```

---

### `projectPolygonMin` (`std/math/geom2d.aipl`)

- **Signature**: `fn projectPolygonMin(poly: Polygon2D, axis: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `poly: Polygon2D, axis: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `projectPolygonMin` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `poly: Polygon2D = Polygon2D(vertices = [Vec2(x = 0, y = 0)])`, `axis: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `minP`.

```aipl
module tests.functions.math.geom2d_z30_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_projectPolygonMin_30(): int:
  let arg_poly = Polygon2D(vertices = [])
  let edge_poly = Polygon2D(vertices = [])
  let arg_axis = Vec2(x = 1.0, y = 1.0)
  let edge_axis = Vec2(x = 0.5, y = 0.5)
  let resNom = projectPolygonMin(arg_poly, arg_axis)
  let resEdge = projectPolygonMin(edge_poly, edge_axis)
  assertApproxEq(resNom, 0.0, 0.001, "projectPolygonMin nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "projectPolygonMin boundary resEdge ~= 0.0")
  ret 0
```

---

### `projectPolygonMax` (`std/math/geom2d.aipl`)

- **Signature**: `fn projectPolygonMax(poly: Polygon2D, axis: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `poly: Polygon2D, axis: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `projectPolygonMax` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `poly: Polygon2D = Polygon2D(vertices = [Vec2(x = 0, y = 0)])`, `axis: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `maxP`.

```aipl
module tests.functions.math.geom2d_z31_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_projectPolygonMax_31(): int:
  let arg_poly = Polygon2D(vertices = [])
  let edge_poly = Polygon2D(vertices = [])
  let arg_axis = Vec2(x = 1.0, y = 1.0)
  let edge_axis = Vec2(x = 0.5, y = 0.5)
  let resNom = projectPolygonMax(arg_poly, arg_axis)
  let resEdge = projectPolygonMax(edge_poly, edge_axis)
  assertApproxEq(resNom, 0.0, 0.001, "projectPolygonMax nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "projectPolygonMax boundary resEdge ~= 0.0")
  ret 0
```

---

### `polygonSAT2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn polygonSAT2D(polyA: Polygon2D, polyB: Polygon2D): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `polyA: Polygon2D, polyB: Polygon2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `polygonSAT2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `polyA: Polygon2D = Polygon2D(vertices = [Vec2(x = 0, y = 0)])`, `polyB: Polygon2D = Polygon2D(vertices = [Vec2(x = 0, y = 0)])`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.math.geom2d_z32_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_polygonSAT2D_32(): int:
  let arg_polyA = Polygon2D(vertices = [])
  let edge_polyA = Polygon2D(vertices = [])
  let arg_polyB = Polygon2D(vertices = [])
  let edge_polyB = Polygon2D(vertices = [])
  let resNom = polygonSAT2D(arg_polyA, arg_polyB)
  let resEdge = polygonSAT2D(edge_polyA, edge_polyB)
  assert(resNom == false, "polygonSAT2D nominal resNom == false")
  assert(resEdge == false, "polygonSAT2D boundary resEdge == false")
  ret 0
```

---

### `collideCircles` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn collideCircles(a: Circle2D, b: Circle2D): CollisionHit:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Circle2D, b: Circle2D` | **Returns**: `CollisionHit`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `collideCircles` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `a: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`, `b: Circle2D = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = float = 0.0(), cy = float = 0.0())`; exercises core body path returning/computing `CollisionHit(hit = true, normalX = 1.0, normalY = 0.0, depth = radSum)`.

```aipl
module tests.functions.math.geom2d_z33_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_collideCircles_33(): int:
  let arg_a = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_a = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let arg_b = Circle2D(x = 1.0, y = 1.0, r = 1.0, cx = 1.0, cy = 1.0)
  let edge_b = Circle2D(x = 0.5, y = 0.5, r = 0.5, cx = 0.5, cy = 0.5)
  let resNom = collideCircles(arg_a, arg_b)
  let resEdge = collideCircles(edge_a, edge_b)
  assert(resNom.hit == true, "collideCircles nominal resNom.hit == true")
  assert(resEdge.hit == true, "collideCircles boundary resEdge.hit == true")
  ret 0
```

---

### `vec2Length` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Length(v: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Length` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `vec2Len(v)`.

```aipl
module tests.functions.math.geom2d_z34_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Length_34(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Length(arg_v)
  let resEdge = vec2Length(edge_v)
  assertApproxEq(resNom, 1.41421, 0.001, "vec2Length nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "vec2Length boundary resEdge ~= 0.707107")
  ret 0
```

---

### `vec2Normalize` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn vec2Normalize(v: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `vec2Normalize` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `vec2Norm(v)`.

```aipl
module tests.functions.math.geom2d_z35_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_vec2Normalize_35(): int:
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Normalize(arg_v)
  let resEdge = vec2Normalize(edge_v)
  assertApproxEq(resNom.x, 0.707107, 0.001, "vec2Normalize nominal resNom.x ~= 0.707107")
  assertApproxEq(resEdge.x, 0.707107, 0.001, "vec2Normalize boundary resEdge.x ~= 0.707107")
  ret 0
```

---

### `aabbIntersects` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn aabbIntersects(x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, w1: float, h1: float, x2: float, y2: float, w2: float, h2: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `aabbIntersects` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `w1: float = 1.0`, `h1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `w2: float = 1.0`, `h2: float = 1.0`; exercises core body path returning/computing `x1 < x2 + w2 and x1 + w1 > x2 and y1 < y2 + h2 and y1 + h1 > y2`.

```aipl
module tests.functions.math.geom2d_z36_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_aabbIntersects_36(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_w1 = 2.0
  let edge_w1 = 1.0
  let arg_h1 = 2.0
  let edge_h1 = 1.0
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_w2 = 2.0
  let edge_w2 = 1.0
  let arg_h2 = 2.0
  let edge_h2 = 1.0
  let resNom = aabbIntersects(arg_x1, arg_y1, arg_w1, arg_h1, arg_x2, arg_y2, arg_w2, arg_h2)
  let resEdge = aabbIntersects(edge_x1, edge_y1, edge_w1, edge_h1, edge_x2, edge_y2, edge_w2, edge_h2)
  assert(resNom == true, "aabbIntersects nominal resNom == true")
  assert(resEdge == true, "aabbIntersects boundary resEdge == true")
  ret 0
```

---

### `sweptAabb` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn sweptAabb(x1: float, y1: float, w1: float, h1: float, vx: float, vy: float, x2: float, y2: float, w2: float, h2: float): SweptHit:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, w1: float, h1: float, vx: float, vy: float, x2: float, y2: float, w2: float, h2: float` | **Returns**: `SweptHit`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `sweptAabb` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `w1: float = 1.0`, `h1: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`, `w2: float = 1.0`, `h2: float = 1.0`; exercises core body path returning/computing `SweptHit(hit = true, time = maxFloat(0.0, entryTime), normalX = normX, normalY = normY)`.

```aipl
module tests.functions.math.geom2d_z37_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_sweptAabb_37(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_w1 = 2.0
  let edge_w1 = 1.0
  let arg_h1 = 2.0
  let edge_h1 = 1.0
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let arg_w2 = 2.0
  let edge_w2 = 1.0
  let arg_h2 = 2.0
  let edge_h2 = 1.0
  let resNom = sweptAabb(arg_x1, arg_y1, arg_w1, arg_h1, arg_vx, arg_vy, arg_x2, arg_y2, arg_w2, arg_h2)
  let resEdge = sweptAabb(edge_x1, edge_y1, edge_w1, edge_h1, edge_vx, edge_vy, edge_x2, edge_y2, edge_w2, edge_h2)
  assert(resNom.hit == false, "sweptAabb nominal resNom.hit == false")
  assert(resEdge.hit == false, "sweptAabb boundary resEdge.hit == false")
  ret 0
```

---

### `mat2DIdentity` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn mat2DIdentity(): Mat2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `mat2DIdentity` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat2D(a = 1.0, b = 0.0, c = 0.0, d = 1.0, tx = 0.0, ty = 0.0)`.

```aipl
module tests.functions.math.geom2d_z38_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_mat2DIdentity_38(): int:
  let resNom = mat2DIdentity()
  let resEdge = mat2DIdentity()
  assertApproxEq(resNom.a, 1.0, 0.001, "mat2DIdentity nominal resNom.a ~= 1.0")
  assertApproxEq(resEdge.a, 1.0, 0.001, "mat2DIdentity boundary resEdge.a ~= 1.0")
  ret 0
```

---

### `mat2DFromTRS` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn mat2DFromTRS(tx: float, ty: float, radians: float, sx: float, sy: float): Mat2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `tx: float, ty: float, radians: float, sx: float, sy: float` | **Returns**: `Mat2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `mat2DFromTRS` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `tx: float = 1.0`, `ty: float = 1.0`, `radians: float = 1.0`, `sx: float = 1.0`, `sy: float = 1.0`; exercises core body path returning/computing `Mat2D(a = cs * sx, b = sn * sx, c = -sn * sy, d = cs * sy, tx = tx, ty = ty)`.

```aipl
module tests.functions.math.geom2d_z39_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_mat2DFromTRS_39(): int:
  let arg_tx = 1.0
  let edge_tx = 0.5
  let arg_ty = 1.0
  let edge_ty = 0.5
  let arg_radians = 1.0
  let edge_radians = 0.5
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let resNom = mat2DFromTRS(arg_tx, arg_ty, arg_radians, arg_sx, arg_sy)
  let resEdge = mat2DFromTRS(edge_tx, edge_ty, edge_radians, edge_sx, edge_sy)
  assertApproxEq(resNom.a, 0.540302, 0.001, "mat2DFromTRS nominal resNom.a ~= 0.540302")
  assertApproxEq(resEdge.a, 0.438791, 0.001, "mat2DFromTRS boundary resEdge.a ~= 0.438791")
  ret 0
```

---

### `mat2DMul` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn mat2DMul(m1: Mat2D, m2: Mat2D): Mat2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m1: Mat2D, m2: Mat2D` | **Returns**: `Mat2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `mat2DMul` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `m1: Mat2D = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)`, `m2: Mat2D = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)`; exercises core body path returning/computing `Mat2D(`.

```aipl
module tests.functions.math.geom2d_z40_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_mat2DMul_40(): int:
  let arg_m1 = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)
  let edge_m1 = Mat2D(a = 0.5, b = 0.5, c = 0.5, d = 0.5, tx = 0.5, ty = 0.5)
  let arg_m2 = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)
  let edge_m2 = Mat2D(a = 0.5, b = 0.5, c = 0.5, d = 0.5, tx = 0.5, ty = 0.5)
  let resNom = mat2DMul(arg_m1, arg_m2)
  let resEdge = mat2DMul(edge_m1, edge_m2)
  assertApproxEq(resNom.a, 2.0, 0.001, "mat2DMul nominal resNom.a ~= 2.0")
  assertApproxEq(resEdge.a, 0.5, 0.001, "mat2DMul boundary resEdge.a ~= 0.5")
  ret 0
```

---

### `mat2DTransformPoint` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn mat2DTransformPoint(m: Mat2D, p: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat2D, p: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `mat2DTransformPoint` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `m: Mat2D = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)`, `p: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = m.a * p.x + m.c * p.y + m.tx, y = m.b * p.x + m.d * p.y + m.ty)`.

```aipl
module tests.functions.math.geom2d_z41_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_mat2DTransformPoint_41(): int:
  let arg_m = Mat2D(a = 1.0, b = 1.0, c = 1.0, d = 1.0, tx = 1.0, ty = 1.0)
  let edge_m = Mat2D(a = 0.5, b = 0.5, c = 0.5, d = 0.5, tx = 0.5, ty = 0.5)
  let arg_p = Vec2(x = 1.0, y = 1.0)
  let edge_p = Vec2(x = 0.5, y = 0.5)
  let resNom = mat2DTransformPoint(arg_m, arg_p)
  let resEdge = mat2DTransformPoint(edge_m, edge_p)
  assertApproxEq(resNom.x, 3.0, 0.001, "mat2DTransformPoint nominal resNom.x ~= 3.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "mat2DTransformPoint boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `intersectSegments` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn intersectSegments(p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2): SegmentHit2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2` | **Returns**: `SegmentHit2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `intersectSegments` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p4: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `SegmentHit2D(hit = false, x = 0.0, y = 0.0, t = t, u = u)`.

```aipl
module tests.functions.math.geom2d_z42_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_intersectSegments_42(): int:
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_p4 = Vec2(x = 1.0, y = 1.0)
  let edge_p4 = Vec2(x = 0.5, y = 0.5)
  let resNom = intersectSegments(arg_p1, arg_p2, arg_p3, arg_p4)
  let resEdge = intersectSegments(edge_p1, edge_p2, edge_p3, edge_p4)
  assert(resNom.hit == false, "intersectSegments nominal resNom.hit == false")
  assert(resEdge.hit == false, "intersectSegments boundary resEdge.hit == false")
  ret 0
```

---

### `segmentIntersect2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn segmentIntersect2D(p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2): SegmentHit2D:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p1: Vec2, p2: Vec2, p3: Vec2, p4: Vec2` | **Returns**: `SegmentHit2D`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `segmentIntersect2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `p1: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p2: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p3: Vec2 = Vec2(x = 1.0, y = 1.0)`, `p4: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `intersectSegments(p1, p2, p3, p4)`.

```aipl
module tests.functions.math.geom2d_z43_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_segmentIntersect2D_43(): int:
  let arg_p1 = Vec2(x = 1.0, y = 1.0)
  let edge_p1 = Vec2(x = 0.5, y = 0.5)
  let arg_p2 = Vec2(x = 1.0, y = 1.0)
  let edge_p2 = Vec2(x = 0.5, y = 0.5)
  let arg_p3 = Vec2(x = 1.0, y = 1.0)
  let edge_p3 = Vec2(x = 0.5, y = 0.5)
  let arg_p4 = Vec2(x = 1.0, y = 1.0)
  let edge_p4 = Vec2(x = 0.5, y = 0.5)
  let resNom = segmentIntersect2D(arg_p1, arg_p2, arg_p3, arg_p4)
  let resEdge = segmentIntersect2D(edge_p1, edge_p2, edge_p3, edge_p4)
  assert(resNom.hit == false, "segmentIntersect2D nominal resNom.hit == false")
  assert(resEdge.hit == false, "segmentIntersect2D boundary resEdge.hit == false")
  ret 0
```

---

### `pointInPolygon` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn pointInPolygon(pt: Vec2, poly: [Vec2]): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pt: Vec2, poly: [Vec2]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `pointInPolygon` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `pt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `poly: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `inside`.

```aipl
module tests.functions.math.geom2d_z44_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_pointInPolygon_44(): int:
  let arg_pt = Vec2(x = 1.0, y = 1.0)
  let edge_pt = Vec2(x = 0.5, y = 0.5)
  let arg_poly = [Vec2(x = 1.0, y = 1.0)]
  let edge_poly = []
  let resNom = pointInPolygon(arg_pt, arg_poly)
  let resEdge = pointInPolygon(edge_pt, edge_poly)
  assert(resNom == false, "pointInPolygon nominal resNom == false")
  assert(resEdge == false, "pointInPolygon boundary resEdge == false")
  ret 0
```

---

### `pointInPolygon2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn pointInPolygon2D(pt: Vec2, poly: [Vec2]): bool:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pt: Vec2, poly: [Vec2]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `pointInPolygon2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `pt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `poly: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `pointInPolygon(pt, poly)`.

```aipl
module tests.functions.math.geom2d_z45_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_pointInPolygon2D_45(): int:
  let arg_pt = Vec2(x = 1.0, y = 1.0)
  let edge_pt = Vec2(x = 0.5, y = 0.5)
  let arg_poly = [Vec2(x = 1.0, y = 1.0)]
  let edge_poly = []
  let resNom = pointInPolygon2D(arg_pt, arg_poly)
  let resEdge = pointInPolygon2D(edge_pt, edge_poly)
  assert(resNom == false, "pointInPolygon2D nominal resNom == false")
  assert(resEdge == false, "pointInPolygon2D boundary resEdge == false")
  ret 0
```

---

### `hullCross2D` (`std/math/geom2d.aipl`)

- **Signature**: `fn hullCross2D(o: Vec2, a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `o: Vec2, a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `hullCross2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `o: Vec2 = Vec2(x = 1.0, y = 1.0)`, `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `(a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x)`.

```aipl
module tests.functions.math.geom2d_z46_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_hullCross2D_46(): int:
  let arg_o = Vec2(x = 1.0, y = 1.0)
  let edge_o = Vec2(x = 0.5, y = 0.5)
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = hullCross2D(arg_o, arg_a, arg_b)
  let resEdge = hullCross2D(edge_o, edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "hullCross2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "hullCross2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `convexHull2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn convexHull2D(pts: [Vec2]): [Vec2]:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pts: [Vec2]` | **Returns**: `[Vec2]`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `convexHull2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `pts: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `lower`.

```aipl
module tests.functions.math.geom2d_z47_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_convexHull2D_47(): int:
  let arg_pts = [Vec2(x = 1.0, y = 1.0)]
  let edge_pts = []
  let resNom = convexHull2D(arg_pts)
  let resEdge = convexHull2D(edge_pts)
  assertEqInt(resNom.len(), 1, "convexHull2D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "convexHull2D boundary resEdge.len() == 0")
  ret 0
```

---

### `worldToDisc2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn worldToDisc2D(origin2D: Vec2, target2D: Vec2, headingRad: float, discCenter: Vec2, discRadius: float, maxRange: float): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `origin2D: Vec2, target2D: Vec2, headingRad: float, discCenter: Vec2, discRadius: float, maxRange: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `worldToDisc2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `origin2D: Vec2 = Vec2(x = 1.0, y = 1.0)`, `target2D: Vec2 = Vec2(x = 1.0, y = 1.0)`, `headingRad: float = 1.0`, `discCenter: Vec2 = Vec2(x = 1.0, y = 1.0)`, `discRadius: float = 1.0`, `maxRange: float = 1.0`; exercises core body path returning/computing `Vec2(x = discCenter.x + px, y = discCenter.y + py)`.

```aipl
module tests.functions.math.geom2d_z48_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_worldToDisc2D_48(): int:
  let arg_origin2D = Vec2(x = 1.0, y = 1.0)
  let edge_origin2D = Vec2(x = 0.5, y = 0.5)
  let arg_target2D = Vec2(x = 1.0, y = 1.0)
  let edge_target2D = Vec2(x = 0.5, y = 0.5)
  let arg_headingRad = 2.0
  let edge_headingRad = 1.0
  let arg_discCenter = Vec2(x = 1.0, y = 1.0)
  let edge_discCenter = Vec2(x = 0.5, y = 0.5)
  let arg_discRadius = 2.0
  let edge_discRadius = 1.0
  let arg_maxRange = 2.0
  let edge_maxRange = 1.0
  let resNom = worldToDisc2D(arg_origin2D, arg_target2D, arg_headingRad, arg_discCenter, arg_discRadius, arg_maxRange)
  let resEdge = worldToDisc2D(edge_origin2D, edge_target2D, edge_headingRad, edge_discCenter, edge_discRadius, edge_maxRange)
  assertApproxEq(resNom.x, 1.0, 0.001, "worldToDisc2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "worldToDisc2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `closestPointOnSegment2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn closestPointOnSegment2D(pt: Vec2, a: Vec2, b: Vec2): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pt: Vec2, a: Vec2, b: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `closestPointOnSegment2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `pt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = a.x + abx * t, y = a.y + aby * t)`.

```aipl
module tests.functions.math.geom2d_z49_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_closestPointOnSegment2D_49(): int:
  let arg_pt = Vec2(x = 1.0, y = 1.0)
  let edge_pt = Vec2(x = 0.5, y = 0.5)
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = closestPointOnSegment2D(arg_pt, arg_a, arg_b)
  let resEdge = closestPointOnSegment2D(edge_pt, edge_a, edge_b)
  assertApproxEq(resNom.x, 1.0, 0.001, "closestPointOnSegment2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "closestPointOnSegment2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `distancePointToSegment2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn distancePointToSegment2D(pt: Vec2, a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pt: Vec2, a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `distancePointToSegment2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `pt: Vec2 = Vec2(x = 1.0, y = 1.0)`, `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `vec2Dist(pt, c)`.

```aipl
module tests.functions.math.geom2d_z50_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_distancePointToSegment2D_50(): int:
  let arg_pt = Vec2(x = 1.0, y = 1.0)
  let edge_pt = Vec2(x = 0.5, y = 0.5)
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = distancePointToSegment2D(arg_pt, arg_a, arg_b)
  let resEdge = distancePointToSegment2D(edge_pt, edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "distancePointToSegment2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distancePointToSegment2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `polygonArea2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn polygonArea2D(poly: [Vec2]): float:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `poly: [Vec2]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `polygonArea2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `poly: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `absFloat(area2) * 0.5`.

```aipl
module tests.functions.math.geom2d_z51_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_polygonArea2D_51(): int:
  let arg_poly = [Vec2(x = 1.0, y = 1.0)]
  let edge_poly = []
  let resNom = polygonArea2D(arg_poly)
  let resEdge = polygonArea2D(edge_poly)
  assertApproxEq(resNom, 0.0, 0.001, "polygonArea2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "polygonArea2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `polygonCentroid2D` (`std/math/geom2d.aipl`)

- **Signature**: `pub fn polygonCentroid2D(poly: [Vec2]): Vec2:`
- **Import**: `import * from "std/math/geom2d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `poly: [Vec2]` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/geom2d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 2D geometric primitive/intersection query `polygonCentroid2D` (`free fn`) across colliding, grazing-boundary, and separated shapes (AABB, Circle, Segment, Ray, SAT convex polygon, Convex Hull, Shoelace area/centroid). Concrete nominal inputs: `poly: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `Vec2(x = sx / float(n), y = sy / float(n))`.

```aipl
module tests.functions.math.geom2d_z52_test
import * from "std/math/geom2d"
import { EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sqrt, hypot, sin, cos } from "std/math/trig"
import { Vec2, IVec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom2d_polygonCentroid2D_52(): int:
  let arg_poly = [Vec2(x = 1.0, y = 1.0)]
  let edge_poly = []
  let resNom = polygonCentroid2D(arg_poly)
  let resEdge = polygonCentroid2D(edge_poly)
  assertApproxEq(resNom.x, 1.0, 0.001, "polygonCentroid2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "polygonCentroid2D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `vec3` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3(x: float, y: float, z: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`; exercises core body path returning/computing `Vector3(x = x, y = y, z = z)`.

```aipl
module tests.functions.math.geom3d_z1_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3_1(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_z = 1.0
  let edge_z = 0.5
  let resNom = vec3(arg_x, arg_y, arg_z)
  let resEdge = vec3(edge_x, edge_y, edge_z)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec3 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec3 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec3Add` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Add(a: Vector3, b: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Add` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = a.x + b.x, y = a.y + b.y, z = a.z + b.z)`.

```aipl
module tests.functions.math.geom3d_z2_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Add_2(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Add(arg_a, arg_b)
  let resEdge = vec3Add(edge_a, edge_b)
  assertApproxEq(resNom.x, 2.0, 0.001, "vec3Add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "vec3Add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `vec3Sub` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Sub(a: Vector3, b: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Sub` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = a.x - b.x, y = a.y - b.y, z = a.z - b.z)`.

```aipl
module tests.functions.math.geom3d_z3_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Sub_3(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Sub(arg_a, arg_b)
  let resEdge = vec3Sub(edge_a, edge_b)
  assertApproxEq(resNom.x, 0.0, 0.001, "vec3Sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "vec3Sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `vec3Scale` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Scale(v: Vector3, s: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, s: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Scale` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vector3(x = v.x * s, y = v.y * s, z = v.z * s)`.

```aipl
module tests.functions.math.geom3d_z4_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Scale_4(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = vec3Scale(arg_v, arg_s)
  let resEdge = vec3Scale(edge_v, edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec3Scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "vec3Scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `vec3Dot` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Dot(a: Vector3, b: Vector3): float:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Dot` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `a.x * b.x + a.y * b.y + a.z * b.z`.

```aipl
module tests.functions.math.geom3d_z5_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Dot_5(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Dot(arg_a, arg_b)
  let resEdge = vec3Dot(edge_a, edge_b)
  assertApproxEq(resNom, 3.0, 0.001, "vec3Dot nominal resNom ~= 3.0")
  assertApproxEq(resEdge, 0.75, 0.001, "vec3Dot boundary resEdge ~= 0.75")
  ret 0
```

---

### `vec3Cross` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Cross(a: Vector3, b: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Cross` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(`.

```aipl
module tests.functions.math.geom3d_z6_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Cross_6(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Cross(arg_a, arg_b)
  let resEdge = vec3Cross(edge_a, edge_b)
  assertApproxEq(resNom.x, 0.0, 0.001, "vec3Cross nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "vec3Cross boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `vec3Length` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Length(v: Vector3): float:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Length` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `sqrt(v.x * v.x + v.y * v.y + v.z * v.z)`.

```aipl
module tests.functions.math.geom3d_z7_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Length_7(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Length(arg_v)
  let resEdge = vec3Length(edge_v)
  assertApproxEq(resNom, 1.73205, 0.001, "vec3Length nominal resNom ~= 1.73205")
  assertApproxEq(resEdge, 0.866025, 0.001, "vec3Length boundary resEdge ~= 0.866025")
  ret 0
```

---

### `vec3Distance` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Distance(a: Vector3, b: Vector3): float:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Distance` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `sqrt(dx * dx + dy * dy + dz * dz)`.

```aipl
module tests.functions.math.geom3d_z8_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Distance_8(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Distance(arg_a, arg_b)
  let resEdge = vec3Distance(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec3Distance nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec3Distance boundary resEdge ~= 0.0")
  ret 0
```

---

### `vec3DistanceSquared` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3DistanceSquared(a: Vector3, b: Vector3): float:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3DistanceSquared` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `dx * dx + dy * dy + dz * dz`.

```aipl
module tests.functions.math.geom3d_z9_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3DistanceSquared_9(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3DistanceSquared(arg_a, arg_b)
  let resEdge = vec3DistanceSquared(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec3DistanceSquared nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec3DistanceSquared boundary resEdge ~= 0.0")
  ret 0
```

---

### `vec3Lerp` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Lerp(a: Vector3, b: Vector3, t: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vector3, b: Vector3, t: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Lerp` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `b: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vector3(`.

```aipl
module tests.functions.math.geom3d_z10_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Lerp_10(): int:
  let arg_a = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_a = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_b = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_b = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = vec3Lerp(arg_a, arg_b, arg_t)
  let resEdge = vec3Lerp(edge_a, edge_b, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec3Lerp nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec3Lerp boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec3Normalize` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Normalize(v: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Normalize` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = v.x / l, y = v.y / l, z = v.z / l)`.

```aipl
module tests.functions.math.geom3d_z11_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Normalize_11(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Normalize(arg_v)
  let resEdge = vec3Normalize(edge_v)
  assertApproxEq(resNom.x, 0.57735, 0.001, "vec3Normalize nominal resNom.x ~= 0.57735")
  assertApproxEq(resEdge.x, 0.57735, 0.001, "vec3Normalize boundary resEdge.x ~= 0.57735")
  ret 0
```

---

### `rotateX` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rotateX(v: Vector3, angle: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, angle: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rotateX` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `angle: float = 1.0`; exercises core body path returning/computing `Vector3(x = v.x, y = v.y * c - v.z * s, z = v.y * s + v.z * c)`.

```aipl
module tests.functions.math.geom3d_z12_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rotateX_12(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = rotateX(arg_v, arg_angle)
  let resEdge = rotateX(edge_v, edge_angle)
  assertApproxEq(resNom.x, 1.0, 0.001, "rotateX nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "rotateX boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `rotateY` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rotateY(v: Vector3, angle: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, angle: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rotateY` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `angle: float = 1.0`; exercises core body path returning/computing `Vector3(x = v.x * c + v.z * s, y = v.y, z = -v.x * s + v.z * c)`.

```aipl
module tests.functions.math.geom3d_z13_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rotateY_13(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = rotateY(arg_v, arg_angle)
  let resEdge = rotateY(edge_v, edge_angle)
  assertApproxEq(resNom.x, 1.38177, 0.001, "rotateY nominal resNom.x ~= 1.38177")
  assertApproxEq(resEdge.x, 0.678504, 0.001, "rotateY boundary resEdge.x ~= 0.678504")
  ret 0
```

---

### `rotateZ` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rotateZ(v: Vector3, angle: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, angle: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rotateZ` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `angle: float = 1.0`; exercises core body path returning/computing `Vector3(x = v.x * c - v.y * s, y = v.x * s + v.y * c, z = v.z)`.

```aipl
module tests.functions.math.geom3d_z14_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rotateZ_14(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = rotateZ(arg_v, arg_angle)
  let resEdge = rotateZ(edge_v, edge_angle)
  assertApproxEq(resNom.x, -0.301169, 0.001, "rotateZ nominal resNom.x ~= -0.301169")
  assertApproxEq(resEdge.x, 0.199079, 0.001, "rotateZ boundary resEdge.x ~= 0.199079")
  ret 0
```

---

### `rotateEuler` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rotateEuler(v: Vector3, rx: float, ry: float, rz: float): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, rx: float, ry: float, rz: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rotateEuler` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `rx: float = 1.0`, `ry: float = 1.0`, `rz: float = 1.0`; exercises core body path returning/computing `rotateZ(rotateY(rotateX(v, rx), ry), rz)`.

```aipl
module tests.functions.math.geom3d_z15_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rotateEuler_15(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rx = 1.0
  let edge_rx = 0.5
  let arg_ry = 1.0
  let edge_ry = 0.5
  let arg_rz = 1.0
  let edge_rz = 0.5
  let resNom = rotateEuler(arg_v, arg_rx, arg_ry, arg_rz)
  let resEdge = rotateEuler(edge_v, edge_rx, edge_ry, edge_rz)
  assertApproxEq(resNom.x, 1.17357, 0.001, "rotateEuler nominal resNom.x ~= 1.17357")
  assertApproxEq(resEdge.x, 0.575103, 0.001, "rotateEuler boundary resEdge.x ~= 0.575103")
  ret 0
```

---

### `project3D` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn project3D(v: Vector3, cameraDist: float, screenW: float, screenH: float, focalLength: float): Vector2:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, cameraDist: float, screenW: float, screenH: float, focalLength: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `project3D` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `cameraDist: float = 1.0`, `screenW: float = 1.0`, `screenH: float = 1.0`, `focalLength: float = 1.0`; exercises core body path returning/computing `Vector2(x = screenW / 2.0 + v.x * factor, y = screenH / 2.0 - v.y * factor)`.

```aipl
module tests.functions.math.geom3d_z16_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_project3D_16(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_cameraDist = 1.0
  let edge_cameraDist = 0.5
  let arg_screenW = 2.0
  let edge_screenW = 1.0
  let arg_screenH = 2.0
  let edge_screenH = 1.0
  let arg_focalLength = 2.0
  let edge_focalLength = 1.0
  let resNom = project3D(arg_v, arg_cameraDist, arg_screenW, arg_screenH, arg_focalLength)
  let resEdge = project3D(edge_v, edge_cameraDist, edge_screenW, edge_screenH, edge_focalLength)
  assertApproxEq(resNom.x, 2.0, 0.001, "project3D nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "project3D boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `aabbIntersectsAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabbIntersectsAABB(a: AABB3D, b: AABB3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AABB3D, b: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabbIntersectsAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `b: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `a.min.x <= b.max.x and a.max.x >= b.min.x and a.min.y <= b.max.y and a.max.y >= b.min.y and a.min.z <= b.max.z and a.max.z >= b.min.z`.

```aipl
module tests.functions.math.geom3d_z17_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabbIntersectsAABB_17(): int:
  let arg_a = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_a = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_b = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_b = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = aabbIntersectsAABB(arg_a, arg_b)
  let resEdge = aabbIntersectsAABB(edge_a, edge_b)
  assert(resNom == true, "aabbIntersectsAABB nominal resNom == true")
  assert(resEdge == true, "aabbIntersectsAABB boundary resEdge == true")
  ret 0
```

---

### `sphereIntersectsSphere` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn sphereIntersectsSphere(a: Sphere3D, b: Sphere3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Sphere3D, b: Sphere3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `sphereIntersectsSphere` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: Sphere3D = Sphere3D(center = Vec3(x = 1.0, y = 1.0, z = 1.0), radius = 1.0)`, `b: Sphere3D = Sphere3D(center = Vec3(x = 1.0, y = 1.0, z = 1.0), radius = 1.0)`; exercises core body path returning/computing `(dx * dx + dy * dy + dz * dz) <= (rSum * rSum)`.

```aipl
module tests.functions.math.geom3d_z18_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_sphereIntersectsSphere_18(): int:
  let arg_a = Sphere3D(center = Vec3(x = 1.0, y = 1.0, z = 1.0), radius = 2.0)
  let edge_a = Sphere3D(center = Vec3(x = 0.5, y = 0.5, z = 0.5), radius = 1.0)
  let arg_b = Sphere3D(center = Vec3(x = 1.0, y = 1.0, z = 1.0), radius = 2.0)
  let edge_b = Sphere3D(center = Vec3(x = 0.5, y = 0.5, z = 0.5), radius = 1.0)
  let resNom = sphereIntersectsSphere(arg_a, arg_b)
  let resEdge = sphereIntersectsSphere(edge_a, edge_b)
  assert(resNom == true, "sphereIntersectsSphere nominal resNom == true")
  assert(resEdge == true, "sphereIntersectsSphere boundary resEdge == true")
  ret 0
```

---

### `rayIntersectsAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectsAABB(ray: Ray3D, aabb: AABB3D): Option[float]:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, aabb: AABB3D` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectsAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `aabb: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `Some(if tMin >= 0.0: tMin else: tMax)`.

```aipl
module tests.functions.math.geom3d_z19_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectsAABB_19(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_aabb = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_aabb = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = rayIntersectsAABB(arg_ray, arg_aabb)
  let resEdge = rayIntersectsAABB(edge_ray, edge_aabb)
  assert(resNom.isSome() == true, "rayIntersectsAABB nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "rayIntersectsAABB boundary resEdge.isSome() == true")
  ret 0
```

---

### `rayIntersectsTriangle` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectsTriangle(ray: Ray3D, tri: Triangle3D): Option[float]:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, tri: Triangle3D` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectsTriangle` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `tri: Triangle3D = Triangle3D(v0 = Vec3(x = 1.0, y = 1.0, z = 1.0), v1 = Vec3(x = 1.0, y = 1.0, z = 1.0), v2 = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.math.geom3d_z20_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectsTriangle_20(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_tri = Triangle3D(v0 = Vec3(x = 1.0, y = 1.0, z = 1.0), v1 = Vec3(x = 1.0, y = 1.0, z = 1.0), v2 = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_tri = Triangle3D(v0 = Vec3(x = 0.5, y = 0.5, z = 0.5), v1 = Vec3(x = 0.5, y = 0.5, z = 0.5), v2 = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = rayIntersectsTriangle(arg_ray, arg_tri)
  let resEdge = rayIntersectsTriangle(edge_ray, edge_tri)
  assert(resNom.isSome() == false, "rayIntersectsTriangle nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "rayIntersectsTriangle boundary resEdge.isSome() == false")
  ret 0
```

---

### `frustumContainsPoint` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn frustumContainsPoint(frustum: Frustum3D, pt: Vec3): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, pt: Vec3` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `frustumContainsPoint` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `pt: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.math.geom3d_z21_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_frustumContainsPoint_21(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_pt = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pt = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = frustumContainsPoint(arg_frustum, arg_pt)
  let resEdge = frustumContainsPoint(edge_frustum, edge_pt)
  assert(resNom == true, "frustumContainsPoint nominal resNom == true")
  assert(resEdge == true, "frustumContainsPoint boundary resEdge == true")
  ret 0
```

---

### `frustumIntersectsAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn frustumIntersectsAABB(frustum: Frustum3D, aabb: AABB3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, aabb: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `frustumIntersectsAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `aabb: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.math.geom3d_z22_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_frustumIntersectsAABB_22(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_aabb = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_aabb = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = frustumIntersectsAABB(arg_frustum, arg_aabb)
  let resEdge = frustumIntersectsAABB(edge_frustum, edge_aabb)
  assert(resNom == true, "frustumIntersectsAABB nominal resNom == true")
  assert(resEdge == true, "frustumIntersectsAABB boundary resEdge == true")
  ret 0
```

---

### `vec3Reflect` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn vec3Reflect(v: Vector3, normal: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: Vector3, normal: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `vec3Reflect` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `normal: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = v.x - dot2 * normal.x, y = v.y - dot2 * normal.y, z = v.z - dot2 * normal.z)`.

```aipl
module tests.functions.math.geom3d_z23_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_vec3Reflect_23(): int:
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_normal = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_normal = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = vec3Reflect(arg_v, arg_normal)
  let resEdge = vec3Reflect(edge_v, edge_normal)
  assertApproxEq(resNom.x, -5.0, 0.001, "vec3Reflect nominal resNom.x ~= -5.0")
  assertApproxEq(resEdge.x, -0.25, 0.001, "vec3Reflect boundary resEdge.x ~= -0.25")
  ret 0
```

---

### `aabb3DIntersects` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabb3DIntersects(minA: Vector3, maxA: Vector3, minB: Vector3, maxB: Vector3): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minA: Vector3, maxA: Vector3, minB: Vector3, maxB: Vector3` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabb3DIntersects` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `minA: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `maxA: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `minB: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `maxB: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `minA.x <= maxB.x and maxA.x >= minB.x and minA.y <= maxB.y and maxA.y >= minB.y and minA.z <= maxB.z and maxA.z >= minB.z`.

```aipl
module tests.functions.math.geom3d_z24_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabb3DIntersects_24(): int:
  let arg_minA = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_minA = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_maxA = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_maxA = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_minB = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_minB = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_maxB = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_maxB = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = aabb3DIntersects(arg_minA, arg_maxA, arg_minB, arg_maxB)
  let resEdge = aabb3DIntersects(edge_minA, edge_maxA, edge_minB, edge_maxB)
  assert(resNom == true, "aabb3DIntersects nominal resNom == true")
  assert(resEdge == true, "aabb3DIntersects boundary resEdge == true")
  ret 0
```

---

### `aabbContainsPoint` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabbContainsPoint(box: AABB3D, pt: Vec3): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `box: AABB3D, pt: Vec3` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabbContainsPoint` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `box: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `pt: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `pt.x >= box.min.x and pt.x <= box.max.x and pt.y >= box.min.y and pt.y <= box.max.y and pt.z >= box.min.z and pt.z <= box.max.z`.

```aipl
module tests.functions.math.geom3d_z25_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabbContainsPoint_25(): int:
  let arg_box = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_box = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_pt = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pt = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = aabbContainsPoint(arg_box, arg_pt)
  let resEdge = aabbContainsPoint(edge_box, edge_pt)
  assert(resNom == true, "aabbContainsPoint nominal resNom == true")
  assert(resEdge == true, "aabbContainsPoint boundary resEdge == true")
  ret 0
```

---

### `aabbIntersects3D` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabbIntersects3D(a: AABB3D, b: AABB3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AABB3D, b: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabbIntersects3D` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `b: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `aabbIntersectsAABB(a, b)`.

```aipl
module tests.functions.math.geom3d_z26_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabbIntersects3D_26(): int:
  let arg_a = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_a = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_b = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_b = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = aabbIntersects3D(arg_a, arg_b)
  let resEdge = aabbIntersects3D(edge_a, edge_b)
  assert(resNom == true, "aabbIntersects3D nominal resNom == true")
  assert(resEdge == true, "aabbIntersects3D boundary resEdge == true")
  ret 0
```

---

### `aabb3DIntersectsBox` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabb3DIntersectsBox(a: AABB3D, b: AABB3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: AABB3D, b: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabb3DIntersectsBox` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `a: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `b: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `aabbIntersectsAABB(a, b)`.

```aipl
module tests.functions.math.geom3d_z27_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabb3DIntersectsBox_27(): int:
  let arg_a = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_a = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_b = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_b = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = aabb3DIntersectsBox(arg_a, arg_b)
  let resEdge = aabb3DIntersectsBox(edge_a, edge_b)
  assert(resNom == true, "aabb3DIntersectsBox nominal resNom == true")
  assert(resEdge == true, "aabb3DIntersectsBox boundary resEdge == true")
  ret 0
```

---

### `aabbFromCenterExtents` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabbFromCenterExtents(center: Vec3, halfExtents: Vec3): AABB3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: Vec3, halfExtents: Vec3` | **Returns**: `AABB3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabbFromCenterExtents` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `halfExtents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `AABB3D(min = center.sub(halfExtents), max = center.add(halfExtents))`.

```aipl
module tests.functions.math.geom3d_z28_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabbFromCenterExtents_28(): int:
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_halfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_halfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = aabbFromCenterExtents(arg_center, arg_halfExtents)
  let resEdge = aabbFromCenterExtents(edge_center, edge_halfExtents)
  assertApproxEq(resNom.min.x, 0.0, 0.001, "aabbFromCenterExtents nominal resNom.min.x ~= 0.0")
  assertApproxEq(resEdge.min.x, 0.0, 0.001, "aabbFromCenterExtents boundary resEdge.min.x ~= 0.0")
  ret 0
```

---

### `aabb2DTo3D` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn aabb2DTo3D(x: float, z: float, w: float, d: float, height: float): AABB3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, z: float, w: float, d: float, height: float` | **Returns**: `AABB3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `aabb2DTo3D` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `x: float = 1.0`, `z: float = 1.0`, `w: float = 1.0`, `d: float = 1.0`, `height: float = 1.0`; exercises core body path returning/computing `AABB3D(min = Vec3(x = x, y = 0.0, z = z), max = Vec3(x = x + w, y = height, z = z + d))`.

```aipl
module tests.functions.math.geom3d_z29_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_aabb2DTo3D_29(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_z = 1.0
  let edge_z = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let arg_d = 1.0
  let edge_d = 0.5
  let arg_height = 2.0
  let edge_height = 1.0
  let resNom = aabb2DTo3D(arg_x, arg_z, arg_w, arg_d, arg_height)
  let resEdge = aabb2DTo3D(edge_x, edge_z, edge_w, edge_d, edge_height)
  assertApproxEq(resNom.min.x, 1.0, 0.001, "aabb2DTo3D nominal resNom.min.x ~= 1.0")
  assertApproxEq(resEdge.min.x, 0.5, 0.001, "aabb2DTo3D boundary resEdge.min.x ~= 0.5")
  ret 0
```

---

### `screenToWorldRay` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn screenToWorldRay(mouseX: float, mouseY: float, screenW: float, screenH: float, camPos: Vector3, camTarget: Vector3, camUp: Vector3, fovyDeg: float): Ray3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mouseX: float, mouseY: float, screenW: float, screenH: float, camPos: Vector3, camTarget: Vector3, camUp: Vector3, fovyDeg: float` | **Returns**: `Ray3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `screenToWorldRay` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `mouseX: float = 1.0`, `mouseY: float = 1.0`, `screenW: float = 1.0`, `screenH: float = 1.0`, `camPos: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `camTarget: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `camUp: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `fovyDeg: float = 1.0`; exercises core body path returning/computing `Ray3D(origin = origVec, dir = dirVec, direction = dirVec)`.

```aipl
module tests.functions.math.geom3d_z30_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_screenToWorldRay_30(): int:
  let arg_mouseX = 1.0
  let edge_mouseX = 0.5
  let arg_mouseY = 1.0
  let edge_mouseY = 0.5
  let arg_screenW = 2.0
  let edge_screenW = 1.0
  let arg_screenH = 2.0
  let edge_screenH = 1.0
  let arg_camPos = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_camPos = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_camTarget = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_camTarget = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_camUp = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_camUp = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_fovyDeg = 1.0
  let edge_fovyDeg = 0.5
  let resNom = screenToWorldRay(arg_mouseX, arg_mouseY, arg_screenW, arg_screenH, arg_camPos, arg_camTarget, arg_camUp, arg_fovyDeg)
  let resEdge = screenToWorldRay(edge_mouseX, edge_mouseY, edge_screenW, edge_screenH, edge_camPos, edge_camTarget, edge_camUp, edge_fovyDeg)
  assertApproxEq(resNom.maxDistance, 1000.0, 0.001, "screenToWorldRay nominal resNom.maxDistance ~= 1000.0")
  assertApproxEq(resEdge.maxDistance, 1000.0, 0.001, "screenToWorldRay boundary resEdge.maxDistance ~= 1000.0")
  ret 0
```

---

### `rayIntersectTriangle` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectTriangle(ray: Ray3D, v0: Vector3, v1: Vector3, v2: Vector3): GeomRayHit3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, v0: Vector3, v1: Vector3, v2: Vector3` | **Returns**: `GeomRayHit3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectTriangle` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `v0: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `v1: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `v2: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `GeomRayHit3D(hit = true, distance = t, point = hitPt, normal = norm)`.

```aipl
module tests.functions.math.geom3d_z31_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectTriangle_31(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_v0 = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v0 = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_v1 = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v1 = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_v2 = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v2 = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = rayIntersectTriangle(arg_ray, arg_v0, arg_v1, arg_v2)
  let resEdge = rayIntersectTriangle(edge_ray, edge_v0, edge_v1, edge_v2)
  assert(resNom.hit == false, "rayIntersectTriangle nominal resNom.hit == false")
  assert(resEdge.hit == false, "rayIntersectTriangle boundary resEdge.hit == false")
  ret 0
```

---

### `rayIntersectAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectAABB(ray: Ray3D, box: AABB3D): GeomRayHit3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, box: AABB3D` | **Returns**: `GeomRayHit3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `box: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `miss`.

```aipl
module tests.functions.math.geom3d_z32_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectAABB_32(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_box = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_box = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = rayIntersectAABB(arg_ray, arg_box)
  let resEdge = rayIntersectAABB(edge_ray, edge_box)
  assert(resNom.hit == true, "rayIntersectAABB nominal resNom.hit == true")
  assert(resEdge.hit == true, "rayIntersectAABB boundary resEdge.hit == true")
  ret 0
```

---

### `rayIntersectSphere` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectSphere(ray: Ray3D, center: Vector3, radius: float): GeomRayHit3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, center: Vector3, radius: float` | **Returns**: `GeomRayHit3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectSphere` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `center: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `GeomRayHit3D(hit = true, distance = t, point = pt, normal = norm)`.

```aipl
module tests.functions.math.geom3d_z33_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectSphere_33(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_center = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = rayIntersectSphere(arg_ray, arg_center, arg_radius)
  let resEdge = rayIntersectSphere(edge_ray, edge_center, edge_radius)
  assert(resNom.hit == true, "rayIntersectSphere nominal resNom.hit == true")
  assert(resEdge.hit == true, "rayIntersectSphere boundary resEdge.hit == true")
  ret 0
```

---

### `sweepSphereAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn sweepSphereAABB(center: Vector3, radius: float, vel: Vector3, box: AABB3D): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: Vector3, radius: float, vel: Vector3, box: AABB3D` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `sweepSphereAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `center: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`, `vel: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `box: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `vec3Add(nextPos, vec3Scale(pushDir, penetration))`.

```aipl
module tests.functions.math.geom3d_z34_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_sweepSphereAABB_34(): int:
  let arg_center = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_vel = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_vel = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_box = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_box = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = sweepSphereAABB(arg_center, arg_radius, arg_vel, arg_box)
  let resEdge = sweepSphereAABB(edge_center, edge_radius, edge_vel, edge_box)
  assertApproxEq(resNom.x, 2.1547, 0.001, "sweepSphereAABB nominal resNom.x ~= 2.1547")
  assertApproxEq(resEdge.x, 1.07735, 0.001, "sweepSphereAABB boundary resEdge.x ~= 1.07735")
  ret 0
```

---

### `capsuleIntersectsAABB` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn capsuleIntersectsAABB(cap: Capsule3D, box: AABB3D): bool:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cap: Capsule3D, box: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `capsuleIntersectsAABB` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `cap: Capsule3D = Capsule3D(start = Vector3(x = 1.0, y = 1.0, z = 1.0), end = Vector3(x = 1.0, y = 1.0, z = 1.0), radius = 1.0)`, `box: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.math.geom3d_z35_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_capsuleIntersectsAABB_35(): int:
  let arg_cap = Capsule3D(start = Vector3(x = 1.0, y = 1.0, z = 1.0), end = Vector3(x = 1.0, y = 1.0, z = 1.0), radius = 2.0)
  let edge_cap = Capsule3D(start = Vector3(x = 0.5, y = 0.5, z = 0.5), end = Vector3(x = 0.5, y = 0.5, z = 0.5), radius = 1.0)
  let arg_box = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_box = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = capsuleIntersectsAABB(arg_cap, arg_box)
  let resEdge = capsuleIntersectsAABB(edge_cap, edge_box)
  assert(resNom == true, "capsuleIntersectsAABB nominal resNom == true")
  assert(resEdge == true, "capsuleIntersectsAABB boundary resEdge == true")
  ret 0
```

---

### `rayIntersectsCylinder` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn rayIntersectsCylinder(rayOrigin: Vector3, rayDir: Vector3, cylCenter: Vector3, radius: float, height: float): Option[float]:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rayOrigin: Vector3, rayDir: Vector3, cylCenter: Vector3, radius: float, height: float` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `rayIntersectsCylinder` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `rayOrigin: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `rayDir: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `cylCenter: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`, `height: float = 1.0`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.math.geom3d_z36_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_rayIntersectsCylinder_36(): int:
  let arg_rayOrigin = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_rayOrigin = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rayDir = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_rayDir = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_cylCenter = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_cylCenter = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let resNom = rayIntersectsCylinder(arg_rayOrigin, arg_rayDir, arg_cylCenter, arg_radius, arg_height)
  let resEdge = rayIntersectsCylinder(edge_rayOrigin, edge_rayDir, edge_cylCenter, edge_radius, edge_height)
  assert(resNom.isSome() == true, "rayIntersectsCylinder nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "rayIntersectsCylinder boundary resEdge.isSome() == true")
  ret 0
```

---

### `eulerToAngleVectors` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn eulerToAngleVectors(pitchDeg: float, yawDeg: float, rollDeg: float = 0.0): EulerVectors:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pitchDeg: float, yawDeg: float, rollDeg: float = 0.0` | **Returns**: `EulerVectors`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `eulerToAngleVectors` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `pitchDeg: float = 1.0`, `yawDeg: float = 1.0`, `rollDeg: float = 1.0`; exercises core body path returning/computing `EulerVectors(forward = fwd, right = rgt, up = upVec)`.

```aipl
module tests.functions.math.geom3d_z37_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_eulerToAngleVectors_37(): int:
  let arg_pitchDeg = 2.0
  let edge_pitchDeg = 1.0
  let arg_yawDeg = 2.0
  let edge_yawDeg = 1.0
  let arg_rollDeg = 1.0
  let edge_rollDeg = 0.5
  let resNom = eulerToAngleVectors(arg_pitchDeg, arg_yawDeg, arg_rollDeg)
  let resEdge = eulerToAngleVectors(edge_pitchDeg, edge_yawDeg, edge_rollDeg)
  assertApproxEq(resNom.forward.x, 0.998782, 0.001, "eulerToAngleVectors nominal resNom.forward.x ~= 0.998782")
  assertApproxEq(resEdge.forward.x, 0.999695, 0.001, "eulerToAngleVectors boundary resEdge.forward.x ~= 0.999695")
  ret 0
```

---

### `radialAttenuation` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn radialAttenuation(origin: Vector3, target: Vector3, maxRadius: float, curve: float = 1.0): float:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `origin: Vector3, target: Vector3, maxRadius: float, curve: float = 1.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `radialAttenuation` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `origin: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `maxRadius: float = 1.0`, `curve: float = 1.0`; exercises core body path returning/computing `pow(factor, curve)`.

```aipl
module tests.functions.math.geom3d_z38_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_radialAttenuation_38(): int:
  let arg_origin = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_origin = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_maxRadius = 2.0
  let edge_maxRadius = 1.0
  let arg_curve = 1.0
  let edge_curve = 0.5
  let resNom = radialAttenuation(arg_origin, arg_target, arg_maxRadius, arg_curve)
  let resEdge = radialAttenuation(edge_origin, edge_target, edge_maxRadius, edge_curve)
  assertApproxEq(resNom, 1.0, 0.001, "radialAttenuation nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "radialAttenuation boundary resEdge ~= 1.0")
  ret 0
```

---

### `transform3DIdentity` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn transform3DIdentity(): EulerTransform3D:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `EulerTransform3D`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `transform3DIdentity` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `EulerTransform3D(`.

```aipl
module tests.functions.math.geom3d_z39_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_transform3DIdentity_39(): int:
  let resNom = transform3DIdentity()
  let resEdge = transform3DIdentity()
  assertApproxEq(resNom.translation.x, 0.0, 0.001, "transform3DIdentity nominal resNom.translation.x ~= 0.0")
  assertApproxEq(resEdge.translation.x, 0.0, 0.001, "transform3DIdentity boundary resEdge.translation.x ~= 0.0")
  ret 0
```

---

### `transform3DPoint` (`std/math/geom3d.aipl`)

- **Signature**: `pub fn transform3DPoint(t: EulerTransform3D, p: Vector3): Vector3:`
- **Import**: `import * from "std/math/geom3d"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: EulerTransform3D, p: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/geom3d_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 3D geometric transform/intersection query `transform3DPoint` across hit and miss configurations (Ray-Triangle Moller-Trumbore, Ray-AABB slab, Ray-Sphere, Ray-Cylinder, Frustum-AABB, swept sphere). Concrete nominal inputs: `t: EulerTransform3D = EulerTransform3D(translation = Vector3(x = 1.0, y = 1.0, z = 1.0), rotationEuler = Vector3(x = 1.0, y = 1.0, z = 1.0), scale = Vector3(x = 1.0, y = 1.0, z = 1.0))`, `p: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `vec3Add(rotated, t.translation)`.

```aipl
module tests.functions.math.geom3d_z40_test
import * from "std/math/geom3d"
import { PI, EPSILON, absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, pow } from "std/math/trig"
import { Vec3, Vector3, Vector2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_geom3d_transform3DPoint_40(): int:
  let arg_t = EulerTransform3D(translation = Vector3(x = 1.0, y = 1.0, z = 1.0), rotationEuler = Vector3(x = 1.0, y = 1.0, z = 1.0), scale = Vector3(x = 1.0, y = 1.0, z = 1.0))
  let edge_t = EulerTransform3D(translation = Vector3(x = 0.5, y = 0.5, z = 0.5), rotationEuler = Vector3(x = 0.5, y = 0.5, z = 0.5), scale = Vector3(x = 0.5, y = 0.5, z = 0.5))
  let arg_p = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_p = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = transform3DPoint(arg_t, arg_p)
  let resEdge = transform3DPoint(edge_t, edge_p)
  assertApproxEq(resNom.x, 2.17357, 0.001, "transform3DPoint nominal resNom.x ~= 2.17357")
  assertApproxEq(resEdge.x, 0.787551, 0.001, "transform3DPoint boundary resEdge.x ~= 0.787551")
  ret 0
```

---

### `Mat2.identity` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat2.identity(): Mat2:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat2`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat2.identity` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat2(m00 = 1.0, m01 = 0.0, m10 = 0.0, m11 = 1.0)`.

```aipl
module tests.functions.math.mat_z1_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat2_identity_1(): int:
  let resNom = Mat2.identity()
  let resEdge = Mat2.identity()
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat2.identity nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat2.identity boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat2.rotation` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat2.rotation(rad: float): Mat2:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `Mat2`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat2.rotation` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `Mat2(m00 = c, m01 = -s, m10 = s, m11 = c)`.

```aipl
module tests.functions.math.mat_z2_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat2_rotation_2(): int:
  let arg_rad = 1.0
  let edge_rad = 0.0
  let resNom = Mat2.rotation(arg_rad)
  let resEdge = Mat2.rotation(edge_rad)
  assertApproxEq(resNom.m00, 0.540302, 0.001, "Mat2.rotation nominal resNom.m00 ~= 0.540302")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat2.rotation boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `transformVec2` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat2) transformVec2(v: Vec2): Vec2:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat2` | **Parameters**: `v: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `transformVec2` (`self: Mat2`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat2 = Mat2(m00 = 1.0, m01 = 1.0, m10 = 1.0, m11 = 1.0)`, `v: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.math.mat_z3_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat2_transformVec2_3(): int:
  let recv_self = Mat2(m00 = 1.0, m01 = 1.0, m10 = 1.0, m11 = 1.0)
  let edge_self = Mat2(m00 = 0.5, m01 = 0.5, m10 = 0.5, m11 = 0.5)
  let arg_v = Vec2(x = 1.0, y = 1.0)
  let edge_v = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.transformVec2(arg_v)
  let resEdge = edge_self.transformVec2(edge_v)
  assertApproxEq(resNom.x, 2.0, 0.001, "transformVec2 nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "transformVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `det` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat2) det(): float:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat2` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `det` (`self: Mat2`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat2 = Mat2(m00 = 1.0, m01 = 1.0, m10 = 1.0, m11 = 1.0)`; exercises core body path returning/computing `self.m00 * self.m11 - self.m01 * self.m10`.

```aipl
module tests.functions.math.mat_z4_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat2_det_4(): int:
  let recv_self = Mat2(m00 = 1.0, m01 = 1.0, m10 = 1.0, m11 = 1.0)
  let edge_self = Mat2(m00 = 0.5, m01 = 0.5, m10 = 0.5, m11 = 0.5)
  let resNom = recv_self.det()
  let resEdge = edge_self.det()
  assertApproxEq(resNom, 0.0, 0.001, "det nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "det boundary resEdge ~= 0.0")
  ret 0
```

---

### `Mat3.identity` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat3.identity(): Mat3:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat3`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat3.identity` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat3(`.

```aipl
module tests.functions.math.mat_z5_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat3_identity_5(): int:
  let resNom = Mat3.identity()
  let resEdge = Mat3.identity()
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat3.identity nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat3.identity boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `transformVec3` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat3) transformVec3(v: Vec3): Vec3:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat3` | **Parameters**: `v: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `transformVec3` (`self: Mat3`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat3 = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)`, `v: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(`.

```aipl
module tests.functions.math.mat_z6_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat3_transformVec3_6(): int:
  let recv_self = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)
  let edge_self = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5)
  let arg_v = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.transformVec3(arg_v)
  let resEdge = edge_self.transformVec3(edge_v)
  assertApproxEq(resNom.x, 3.0, 0.001, "transformVec3 nominal resNom.x ~= 3.0")
  assertApproxEq(resEdge.x, 0.75, 0.001, "transformVec3 boundary resEdge.x ~= 0.75")
  ret 0
```

---

### `Mat4.identity` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.identity(): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.identity` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z7_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_identity_7(): int:
  let resNom = Mat4.identity()
  let resEdge = Mat4.identity()
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat4.identity nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat4.identity boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat4.translation` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.translation(x: float, y: float, z: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.translation` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z8_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_translation_8(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let arg_z = 1.0
  let edge_z = 0.0
  let resNom = Mat4.translation(arg_x, arg_y, arg_z)
  let resEdge = Mat4.translation(edge_x, edge_y, edge_z)
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat4.translation nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat4.translation boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat4.scaling` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.scaling(sx: float, sy: float, sz: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sx: float, sy: float, sz: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.scaling` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `sx: float = 1.0`, `sy: float = 1.0`, `sz: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z9_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_scaling_9(): int:
  let arg_sx = 1.0
  let edge_sx = 0.0
  let arg_sy = 1.0
  let edge_sy = 0.0
  let arg_sz = 1.0
  let edge_sz = 0.0
  let resNom = Mat4.scaling(arg_sx, arg_sy, arg_sz)
  let resEdge = Mat4.scaling(edge_sx, edge_sy, edge_sz)
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat4.scaling nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "Mat4.scaling boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `Mat4.rotationX` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.rotationX(rad: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.rotationX` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z10_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_rotationX_10(): int:
  let arg_rad = 1.0
  let edge_rad = 0.0
  let resNom = Mat4.rotationX(arg_rad)
  let resEdge = Mat4.rotationX(edge_rad)
  assertApproxEq(resNom.m00, 1.0, 0.001, "Mat4.rotationX nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat4.rotationX boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat4.rotationY` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.rotationY(rad: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.rotationY` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z11_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_rotationY_11(): int:
  let arg_rad = 1.0
  let edge_rad = 0.0
  let resNom = Mat4.rotationY(arg_rad)
  let resEdge = Mat4.rotationY(edge_rad)
  assertApproxEq(resNom.m00, 0.540302, 0.001, "Mat4.rotationY nominal resNom.m00 ~= 0.540302")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat4.rotationY boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat4.rotationZ` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.rotationZ(rad: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.rotationZ` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z12_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_rotationZ_12(): int:
  let arg_rad = 1.0
  let edge_rad = 0.0
  let resNom = Mat4.rotationZ(arg_rad)
  let resEdge = Mat4.rotationZ(edge_rad)
  assertApproxEq(resNom.m00, 0.540302, 0.001, "Mat4.rotationZ nominal resNom.m00 ~= 0.540302")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "Mat4.rotationZ boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `Mat4.perspective` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.perspective(fovyRad: float, aspect: float, near: float, far: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fovyRad: float, aspect: float, near: float, far: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.perspective` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `fovyRad: float = 1.0`, `aspect: float = 1.0`, `near: float = 1.0`, `far: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z13_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_perspective_13(): int:
  let arg_fovyRad = 1.0
  let edge_fovyRad = 0.0
  let arg_aspect = 1.0
  let edge_aspect = 0.0
  let arg_near = 1.0
  let edge_near = 0.0
  let arg_far = 1.0
  let edge_far = 0.0
  let resNom = Mat4.perspective(arg_fovyRad, arg_aspect, arg_near, arg_far)
  let resEdge = Mat4.perspective(edge_fovyRad, edge_aspect, edge_near, edge_far)
  assertApproxEq(resNom.m00, 1.83049, 0.001, "Mat4.perspective nominal resNom.m00 ~= 1.83049")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "Mat4.perspective boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `Mat4.orthographic` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.orthographic(left: float, right: float, bottom: float, top: float, near: float, far: float): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `left: float, right: float, bottom: float, top: float, near: float, far: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.orthographic` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `left: float = 1.0`, `right: float = 1.0`, `bottom: float = 1.0`, `top: float = 1.0`, `near: float = 1.0`, `far: float = 1.0`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z14_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_orthographic_14(): int:
  let arg_left = 1.0
  let edge_left = 0.0
  let arg_right = 1.0
  let edge_right = 0.0
  let arg_bottom = 1.0
  let edge_bottom = 0.0
  let arg_top = 1.0
  let edge_top = 0.0
  let arg_near = 1.0
  let edge_near = 0.0
  let arg_far = 1.0
  let edge_far = 0.0
  let resNom = Mat4.orthographic(arg_left, arg_right, arg_bottom, arg_top, arg_near, arg_far)
  let resEdge = Mat4.orthographic(edge_left, edge_right, edge_bottom, edge_top, edge_near, edge_far)
  assertApproxEq(resNom.m00, 0.0, 0.001, "Mat4.orthographic nominal resNom.m00 ~= 0.0")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "Mat4.orthographic boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `Mat4.lookAt` (`std/math/mat.aipl`)

- **Signature**: `pub fn Mat4.lookAt(eye: Vec3, target: Vec3, up: Vec3): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `eye: Vec3, target: Vec3, up: Vec3` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `Mat4.lookAt` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `eye: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `up: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z15_test
import * from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_lookAt_15(): int:
  let arg_eye = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_eye = Vec3(x = 0.0, y = 0.0, z = 0.0)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.0, y = 0.0, z = 0.0)
  let arg_up = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_up = Vec3(x = 0.0, y = 0.0, z = 0.0)
  let resNom = Mat4.lookAt(arg_eye, arg_target, arg_up)
  let resEdge = Mat4.lookAt(edge_eye, edge_target, edge_up)
  assertApproxEq(resNom.m00, 0.0, 0.001, "Mat4.lookAt nominal resNom.m00 ~= 0.0")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "Mat4.lookAt boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `mul` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat4) mul(other: Mat4): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat4` | **Parameters**: `other: Mat4` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `mul` (`self: Mat4`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`, `other: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z16_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_mul_16(): int:
  let recv_self = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_self = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let arg_other = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_other = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = recv_self.mul(arg_other)
  let resEdge = edge_self.mul(edge_other)
  assertApproxEq(resNom.m00, 4.0, 0.001, "mul nominal resNom.m00 ~= 4.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "mul boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `transformVec4` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat4) transformVec4(v: Vec4): Vec4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat4` | **Parameters**: `v: Vec4` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `transformVec4` (`self: Mat4`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`, `v: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Vec4(`.

```aipl
module tests.functions.math.mat_z17_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_transformVec4_17(): int:
  let recv_self = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_self = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let arg_v = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_v = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.transformVec4(arg_v)
  let resEdge = edge_self.transformVec4(edge_v)
  assertApproxEq(resNom.x, 5.0, 0.001, "transformVec4 nominal resNom.x ~= 5.0")
  assertApproxEq(resEdge.x, 1.25, 0.001, "transformVec4 boundary resEdge.x ~= 1.25")
  ret 0
```

---

### `transpose` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat4) transpose(): Mat4:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat4` | **Parameters**: `none` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `transpose` (`self: Mat4`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.mat_z18_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_transpose_18(): int:
  let recv_self = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_self = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = recv_self.transpose()
  let resEdge = edge_self.transpose()
  assertApproxEq(resNom.m00, 1.0, 0.001, "transpose nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 0.5, 0.001, "transpose boundary resEdge.m00 ~= 0.5")
  ret 0
```

---

### `inverse` (`std/math/mat.aipl`)

- **Signature**: `pub fn (self: Mat4) inverse(): Option[Mat4]:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Mat4` | **Parameters**: `none` | **Returns**: `Option[Mat4]`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `inverse` (`self: Mat4`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: receiver `recvObj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Some(Mat4(`.

```aipl
module tests.functions.math.mat_z19_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_Mat4_inverse_19(): int:
  let recv_self = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_self = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = recv_self.inverse()
  let resEdge = edge_self.inverse()
  assert(resNom.isSome() == false, "inverse nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "inverse boundary resEdge.isSome() == false")
  ret 0
```

---

### `mat3Identity` (`std/math/mat.aipl`)

- **Signature**: `pub fn mat3Identity(): Mat3:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat3`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `mat3Identity` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat3.identity()`.

```aipl
module tests.functions.math.mat_z20_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_mat3Identity_20(): int:
  let resNom = mat3Identity()
  let resEdge = mat3Identity()
  assertApproxEq(resNom.m00, 1.0, 0.001, "mat3Identity nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "mat3Identity boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `mat3TransformVec3` (`std/math/mat.aipl`)

- **Signature**: `pub fn mat3TransformVec3(mat: Mat3, v: Vector3): Vector3:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mat: Mat3, v: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `mat3TransformVec3` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `mat: Mat3 = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)`, `v: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(`.

```aipl
module tests.functions.math.mat_z21_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_mat3TransformVec3_21(): int:
  let arg_mat = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)
  let edge_mat = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5)
  let arg_v = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = mat3TransformVec3(arg_mat, arg_v)
  let resEdge = mat3TransformVec3(edge_mat, edge_v)
  assertApproxEq(resNom.x, 3.0, 0.001, "mat3TransformVec3 nominal resNom.x ~= 3.0")
  assertApproxEq(resEdge.x, 0.75, 0.001, "mat3TransformVec3 boundary resEdge.x ~= 0.75")
  ret 0
```

---

### `mat3Mul` (`std/math/mat.aipl`)

- **Signature**: `pub fn mat3Mul(a: Mat3, b: Mat3): Mat3:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Mat3, b: Mat3` | **Returns**: `Mat3`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `mat3Mul` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `a: Mat3 = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)`, `b: Mat3 = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)`; exercises core body path returning/computing `Mat3(`.

```aipl
module tests.functions.math.mat_z22_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_mat3Mul_22(): int:
  let arg_a = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)
  let edge_a = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5)
  let arg_b = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)
  let edge_b = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5)
  let resNom = mat3Mul(arg_a, arg_b)
  let resEdge = mat3Mul(edge_a, edge_b)
  assertApproxEq(resNom.m00, 3.0, 0.001, "mat3Mul nominal resNom.m00 ~= 3.0")
  assertApproxEq(resEdge.m00, 0.75, 0.001, "mat3Mul boundary resEdge.m00 ~= 0.75")
  ret 0
```

---

### `mat3Det` (`std/math/mat.aipl`)

- **Signature**: `pub fn mat3Det(m: Mat3): float:`
- **Import**: `import * from "std/math/mat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/mat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify matrix operation `mat3Det` (`free fn`) identity neutrality (`I * v == v`), determinant multiplicativity, transpose involutivity, and TRS / inverse round-trip accuracy. Concrete nominal inputs: `m: Mat3 = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)`; exercises core body path returning/computing `m.m00 * (m.m11 * m.m22 - m.m12 * m.m21) - m.m01 * (m.m10 * m.m22 - m.m12 * m.m20) + m.m02 * (m.m10 * m.m21 - m.m11 * m.m20)`.

```aipl
module tests.functions.math.mat_z23_test
import * from "std/math/mat"
import { EPSILON, absFloat } from "std/math/consts"
import { sin, cos, tan } from "std/math/trig"
import { Vec2, Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mat_mat3Det_23(): int:
  let arg_m = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0)
  let edge_m = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5)
  let resNom = mat3Det(arg_m)
  let resEdge = mat3Det(edge_m)
  assertApproxEq(resNom, 0.0, 0.001, "mat3Det nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "mat3Det boundary resEdge ~= 0.0")
  ret 0
```

---

### `splitMix64Next` (`std/math/prng.aipl`)

- **Signature**: `pub fn splitMix64Next(state: int): [int]:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `splitMix64Next` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `state: int = 1`; exercises core body path returning/computing `[nextState, out]`.

```aipl
module tests.functions.math.prng_z1_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_splitMix64Next_1(): int:
  let arg_state = 1
  let edge_state = 0
  let resNom = splitMix64Next(arg_state)
  let resEdge = splitMix64Next(edge_state)
  assertEqInt(resNom.len(), 2, "splitMix64Next nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "splitMix64Next boundary resEdge.len() == 2")
  ret 0
```

---

### `pcg32Next` (`std/math/prng.aipl`)

- **Signature**: `pub fn pcg32Next(state: int, inc: int): [int]:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `state: int, inc: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `pcg32Next` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `state: int = 1`, `inc: int = 1`; exercises core body path returning/computing `[nextState, out]`.

```aipl
module tests.functions.math.prng_z2_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_pcg32Next_2(): int:
  let arg_state = 1
  let edge_state = 0
  let arg_inc = 4
  let edge_inc = 1
  let resNom = pcg32Next(arg_state, arg_inc)
  let resEdge = pcg32Next(edge_state, edge_inc)
  assertEqInt(resNom.len(), 2, "pcg32Next nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "pcg32Next boundary resEdge.len() == 2")
  ret 0
```

---

### `pcg32Init` (`std/math/prng.aipl`)

- **Signature**: `pub fn pcg32Init(seed: int, seq: int = 54): Pcg32Rng:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int, seq: int = 54` | **Returns**: `Pcg32Rng`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `pcg32Init` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `seed: int = 42`, `seq: int = 1`; exercises core body path returning/computing `Pcg32Rng(state = step2[0], inc = seq)`.

```aipl
module tests.functions.math.prng_z3_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_pcg32Init_3(): int:
  let arg_seed = 1
  let edge_seed = 0
  let arg_seq = 2
  let edge_seq = 0
  let resNom = pcg32Init(arg_seed, arg_seq)
  let resEdge = pcg32Init(edge_seed, edge_seq)
  assertEqInt(resNom.state, 1291329195661654803, "pcg32Init nominal resNom.state == 1291329195661654803")
  assertEqInt(resEdge.state, 1568382538196212880, "pcg32Init boundary resEdge.state == 1568382538196212880")
  ret 0
```

---

### `nextU32` (`std/math/prng.aipl`)

- **Signature**: `pub fn (mut self: Pcg32Rng) nextU32(): int:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `mut self: Pcg32Rng` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `nextU32` (`mut self: Pcg32Rng`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: receiver `recvObj: Pcg32Rng = Pcg32Rng()`; exercises core body path returning/computing `res[1]`.

```aipl
module tests.functions.math.prng_z4_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_Pcg32Rng_nextU32_4(): int:
  let mut recv_self = Pcg32Rng(state = 0, inc = 4)
  let mut edge_self = Pcg32Rng(state = 0, inc = 1)
  let resNom = recv_self.nextU32()
  let resEdge = edge_self.nextU32()
  assertEqInt(resNom, 0, "nextU32 nominal resNom == 0")
  assertEqInt(resEdge, 0, "nextU32 boundary resEdge == 0")
  ret 0
```

---

### `nextFloat` (`std/math/prng.aipl`)

- **Signature**: `pub fn (mut self: Pcg32Rng) nextFloat(): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `mut self: Pcg32Rng` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `nextFloat` (`mut self: Pcg32Rng`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: receiver `recvObj: Pcg32Rng = Pcg32Rng()`; exercises core body path returning/computing `float(u % 16777216) / 16777216.0`.

```aipl
module tests.functions.math.prng_z5_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_Pcg32Rng_nextFloat_5(): int:
  let mut recv_self = Pcg32Rng(state = 0, inc = 4)
  let mut edge_self = Pcg32Rng(state = 0, inc = 1)
  let resNom = recv_self.nextFloat()
  let resEdge = edge_self.nextFloat()
  assertApproxEq(resNom, 0.0, 0.001, "nextFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "nextFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `rangeInt` (`std/math/prng.aipl`)

- **Signature**: `pub fn (mut self: Pcg32Rng) rangeInt(minVal: int, maxVal: int): int:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `mut self: Pcg32Rng` | **Parameters**: `minVal: int, maxVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `rangeInt` (`mut self: Pcg32Rng`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: receiver `recvObj: Pcg32Rng = Pcg32Rng()`, `minVal: int = 1`, `maxVal: int = 1`; exercises core body path returning/computing `minVal + (u % span)`.

```aipl
module tests.functions.math.prng_z6_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_Pcg32Rng_rangeInt_6(): int:
  let mut recv_self = Pcg32Rng(state = 0, inc = 4)
  let mut edge_self = Pcg32Rng(state = 0, inc = 1)
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = recv_self.rangeInt(arg_minVal, arg_maxVal)
  let resEdge = edge_self.rangeInt(edge_minVal, edge_maxVal)
  assertEqInt(resNom, 4, "rangeInt nominal resNom == 4")
  assertEqInt(resEdge, 1, "rangeInt boundary resEdge == 1")
  ret 0
```

---

### `xoshiro256Init` (`std/math/prng.aipl`)

- **Signature**: `pub fn xoshiro256Init(seed: int): Xoshiro256Rng:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `Xoshiro256Rng`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `xoshiro256Init` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `Xoshiro256Rng(s0 = sm0[1], s1 = sm1[1], s2 = sm2[1], s3 = sm3[1])`.

```aipl
module tests.functions.math.prng_z7_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_xoshiro256Init_7(): int:
  let arg_seed = 1
  let edge_seed = 0
  let resNom = xoshiro256Init(arg_seed)
  let resEdge = xoshiro256Init(edge_seed)
  assertEqInt(resNom.s0, 643517647554758034, "xoshiro256Init nominal resNom.s0 == 643517647554758034")
  assertEqInt(resEdge.s0, 1517046713075839355, "xoshiro256Init boundary resEdge.s0 == 1517046713075839355")
  ret 0
```

---

### `nextU64` (`std/math/prng.aipl`)

- **Signature**: `pub fn (mut self: Xoshiro256Rng) nextU64(): int:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `mut self: Xoshiro256Rng` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `nextU64` (`mut self: Xoshiro256Rng`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: receiver `recvObj: Xoshiro256Rng = Xoshiro256Rng()`; exercises core body path returning/computing `result`.

```aipl
module tests.functions.math.prng_z8_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_Xoshiro256Rng_nextU64_8(): int:
  let mut recv_self = Xoshiro256Rng(s0 = 2, s1 = 2, s2 = 2, s3 = 2)
  let mut edge_self = Xoshiro256Rng(s0 = 0, s1 = 0, s2 = 0, s3 = 0)
  let resNom = recv_self.nextU64()
  let resEdge = edge_self.nextU64()
  assertEqInt(resNom, 4, "nextU64 nominal resNom == 4")
  assertEqInt(resEdge, 0, "nextU64 boundary resEdge == 0")
  ret 0
```

---

### `rngNew` (`std/math/prng.aipl`)

- **Signature**: `pub fn rngNew(seed: int): Rng:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `Rng`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `rngNew` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `Rng(state = s)`.

```aipl
module tests.functions.math.prng_z9_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_rngNew_9(): int:
  let arg_seed = 1
  let edge_seed = 0
  let resNom = rngNew(arg_seed)
  let resEdge = rngNew(edge_seed)
  assertEqInt(resNom.state, 1, "rngNew nominal resNom.state == 1")
  assertEqInt(resEdge.state, 123456789, "rngNew boundary resEdge.state == 123456789")
  ret 0
```

---

### `rngNext` (`std/math/prng.aipl`)

- **Signature**: `pub fn rngNext(mut rng: Rng): (Rng, int):`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut rng: Rng` | **Returns**: `(Rng, int)`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `rngNext` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `rng: Rng): (Rng = Rng): (Rng()`, `int: any = 42`; exercises core body path returning/computing `(Rng(state = sm[0]), sm[1])`.

```aipl
module tests.functions.math.prng_z10_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_rngNext_10(): int:
  let arg_rng = Rng(state = 0)
  let edge_rng = Rng(state = 0)
  let resNom = rngNext(arg_rng)
  let resEdge = rngNext(edge_rng)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.state, 2177342782468422677, "rngNext nominal n_t0.state == 2177342782468422677")
  assertEqInt(e_t0.state, 2177342782468422677, "rngNext boundary e_t0.state == 2177342782468422677")
  ret 0
```

---

### `rngNextInt` (`std/math/prng.aipl`)

- **Signature**: `pub fn rngNextInt(mut rng: Rng, minVal: int, maxVal: int): (Rng, int):`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut rng: Rng, minVal: int, maxVal: int` | **Returns**: `(Rng, int)`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `rngNextInt` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `rng: Rng = Rng()`, `minVal: int = 1`, `maxVal: int): (Rng = int): (Rng()`, `int: any = 42`; exercises core body path returning/computing `(nextRng, minVal + (raw % span))`.

```aipl
module tests.functions.math.prng_z11_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_rngNextInt_11(): int:
  let arg_rng = Rng(state = 0)
  let edge_rng = Rng(state = 0)
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = rngNextInt(arg_rng, arg_minVal, arg_maxVal)
  let resEdge = rngNextInt(edge_rng, edge_minVal, edge_maxVal)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.state, 0, "rngNextInt nominal n_t0.state == 0")
  assertEqInt(e_t0.state, 0, "rngNextInt boundary e_t0.state == 0")
  ret 0
```

---

### `rngNextFloat` (`std/math/prng.aipl`)

- **Signature**: `pub fn rngNextFloat(mut rng: Rng): (Rng, float):`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut rng: Rng` | **Returns**: `(Rng, float)`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `rngNextFloat` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `rng: Rng): (Rng = Rng): (Rng()`, `float: any = 42`; exercises core body path returning/computing `(nextRng, float(raw % 16777216) / 16777216.0)`.

```aipl
module tests.functions.math.prng_z12_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_rngNextFloat_12(): int:
  let arg_rng = Rng(state = 0)
  let edge_rng = Rng(state = 0)
  let resNom = rngNextFloat(arg_rng)
  let resEdge = rngNextFloat(edge_rng)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.state, 2177342782468422677, "rngNextFloat nominal n_t0.state == 2177342782468422677")
  assertEqInt(e_t0.state, 2177342782468422677, "rngNextFloat boundary e_t0.state == 2177342782468422677")
  ret 0
```

---

### `setRandomSeed` (`std/math/prng.aipl`)

- **Signature**: `pub fn setRandomSeed(seed: int): void:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `setRandomSeed` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.math.prng_z13_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_setRandomSeed_13(): int:
  mut completedCalls = 0
  let arg_seed = 1
  let edge_seed = 0
  setRandomSeed(arg_seed)
  setRandomSeed(edge_seed)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setRandomSeed nominal and boundary void calls completed")
  ret 0
```

---

### `randomFloat` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomFloat(): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomFloat` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `randFloat()`.

```aipl
module tests.functions.math.prng_z14_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomFloat_14(): int:
  let resNom = randomFloat()
  let resEdge = randomFloat()
  assert(resNom >= 0.0 and resNom <= 1.0, "randomFloat nominal float in [0.0, 1.0]")
  assert(resEdge >= 0.0 and resEdge <= 1.0, "randomFloat boundary float in [0.0, 1.0]")
  ret 0
```

---

### `randomRange` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomRange(minVal: float, maxVal: float): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minVal: float, maxVal: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomRange` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `minVal: float = 1.0`, `maxVal: float = 1.0`; exercises core body path returning/computing `minVal + (maxVal - minVal) * randomFloat()`.

```aipl
module tests.functions.math.prng_z15_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomRange_15(): int:
  let arg_minVal = 0.0
  let edge_minVal = 0.0
  let arg_maxVal = 2.0
  let edge_maxVal = 1.0
  let resNom = randomRange(arg_minVal, arg_maxVal)
  let resEdge = randomRange(edge_minVal, edge_maxVal)
  assert(resNom >= 1.0 and resNom <= 2.0, "randomRange nominal float in [1.0, 2.0]")
  assert(resEdge >= 0.5 and resEdge <= 1.0, "randomRange boundary float in [0.5, 1.0]")
  ret 0
```

---

### `randomIntRange` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomIntRange(minVal: int, maxVal: int): int:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minVal: int, maxVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomIntRange` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `minVal: int = 1`, `maxVal: int = 1`; exercises core body path returning/computing `minVal + r`.

```aipl
module tests.functions.math.prng_z16_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomIntRange_16(): int:
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = randomIntRange(arg_minVal, arg_maxVal)
  let resEdge = randomIntRange(edge_minVal, edge_maxVal)
  assertEqInt(resNom, 4, "randomIntRange nominal resNom == 4")
  assertEqInt(resEdge, 1, "randomIntRange boundary resEdge == 1")
  ret 0
```

---

### `randomBool` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomBool(probability: float = 0.5): bool:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `probability: float = 0.5` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomBool` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `probability: float = 1.0`; exercises core body path returning/computing `randomFloat() < probability`.

```aipl
module tests.functions.math.prng_z17_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomBool_17(): int:
  let arg_probability = 1.0
  let edge_probability = 0.0
  let resNom = randomBool(arg_probability)
  let resEdge = randomBool(edge_probability)
  assert(resNom == true, "randomBool nominal resNom == true")
  assert(resEdge == false, "randomBool boundary resEdge == false")
  ret 0
```

---

### `randomSign` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomSign(): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomSign` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `if randomFloat() < 0.5: -1.0 else: 1.0`.

```aipl
module tests.functions.math.prng_z18_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomSign_18(): int:
  let resNom = randomSign()
  let resEdge = randomSign()
  assertApproxEq(resNom, -1.0, 0.001, "randomSign nominal resNom ~= -1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "randomSign boundary resEdge ~= 1.0")
  ret 0
```

---

### `randomAngle` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomAngle(): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomAngle` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `randomFloat() * TAU`.

```aipl
module tests.functions.math.prng_z19_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomAngle_19(): int:
  let resNom = randomAngle()
  let resEdge = randomAngle()
  assert(resNom >= 0.0 and resNom <= 6.283186, "randomAngle nominal float in [0.0, TAU]")
  assert(resEdge >= 0.0 and resEdge <= 6.283186, "randomAngle boundary float in [0.0, TAU]")
  ret 0
```

---

### `randomGaussian` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomGaussian(): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomGaussian` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `(u - 3.0) * 1.41421356237`.

```aipl
module tests.functions.math.prng_z20_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomGaussian_20(): int:
  let resNom = randomGaussian()
  let resEdge = randomGaussian()
  assert(resNom >= -4.25 and resNom <= 4.25, "randomGaussian nominal float in [-4.25, 4.25]")
  assert(resEdge >= -4.25 and resEdge <= 4.25, "randomGaussian boundary float in [-4.25, 4.25]")
  ret 0
```

---

### `randomInCircleX` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomInCircleX(radius: float): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomInCircleX` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `radius: float = 1.0`; exercises core body path returning/computing `cos(randomAngle()) * r`.

```aipl
module tests.functions.math.prng_z21_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomInCircleX_21(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = randomInCircleX(arg_radius)
  let resEdge = randomInCircleX(edge_radius)
  assert(resNom >= -2.0 and resNom <= 2.0, "randomInCircleX nominal float in [-2.0, 2.0]")
  assert(resEdge >= -1.0 and resEdge <= 1.0, "randomInCircleX boundary float in [-1.0, 1.0]")
  ret 0
```

---

### `randomInCircleY` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomInCircleY(radius: float): float:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomInCircleY` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `radius: float = 1.0`; exercises core body path returning/computing `sin(randomAngle()) * r`.

```aipl
module tests.functions.math.prng_z22_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomInCircleY_22(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = randomInCircleY(arg_radius)
  let resEdge = randomInCircleY(edge_radius)
  assert(resNom >= -2.0 and resNom <= 2.0, "randomInCircleY nominal float in [-2.0, 2.0]")
  assert(resEdge >= -1.0 and resEdge <= 1.0, "randomInCircleY boundary float in [-1.0, 1.0]")
  ret 0
```

---

### `shuffleInts` (`std/math/prng.aipl`)

- **Signature**: `pub fn shuffleInts(arr: [int], seed: int): [int]:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [int], seed: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `shuffleInts` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `arr: [int] = [1]`, `seed: int = 42`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.prng_z23_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_shuffleInts_23(): int:
  let arg_arr = [2]
  let edge_arr = []
  let arg_seed = 1
  let edge_seed = 0
  let resNom = shuffleInts(arg_arr, arg_seed)
  let resEdge = shuffleInts(edge_arr, edge_seed)
  assertEqInt(resNom.len(), 1, "shuffleInts nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "shuffleInts boundary resEdge.len() == 0")
  ret 0
```

---

### `createRng` (`std/math/prng.aipl`)

- **Signature**: `pub fn createRng(initialSeed: int): RngState:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialSeed: int` | **Returns**: `RngState`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `createRng` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `initialSeed: int = 42`; exercises core body path returning/computing `RngState(state = s, seed = s)`.

```aipl
module tests.functions.math.prng_z24_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_createRng_24(): int:
  let arg_initialSeed = 4
  let edge_initialSeed = 1
  let resNom = createRng(arg_initialSeed)
  let resEdge = createRng(edge_initialSeed)
  assertEqInt(resNom.state, 4, "createRng nominal resNom.state == 4")
  assertEqInt(resEdge.state, 1, "createRng boundary resEdge.state == 1")
  ret 0
```

---

### `nextRng` (`std/math/prng.aipl`)

- **Signature**: `pub fn nextRng(rng: RngState): RngState:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rng: RngState` | **Returns**: `RngState`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `nextRng` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `rng: RngState = RngState()`; exercises core body path returning/computing `RngState(state = nextSeed, seed = nextSeed)`.

```aipl
module tests.functions.math.prng_z25_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_nextRng_25(): int:
  let arg_rng = RngState(state = 0, seed = 0)
  let edge_rng = RngState(state = 0, seed = 0)
  let resNom = nextRng(arg_rng)
  let resEdge = nextRng(edge_rng)
  assertEqInt(resNom.state, 12345, "nextRng nominal resNom.state == 12345")
  assertEqInt(resEdge.state, 12345, "nextRng boundary resEdge.state == 12345")
  ret 0
```

---

### `randomInt` (`std/math/prng.aipl`)

- **Signature**: `pub fn randomInt(rng: RngState, minVal: int, maxVal: int): int:`
- **Import**: `import * from "std/math/prng"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rng: RngState, minVal: int, maxVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prng_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify PRNG function `randomInt` (`free fn`) cross-run deterministic reproducibility from identical seed, distinct streams across seeds, and strict output interval bounds. Concrete nominal inputs: `rng: RngState = RngState()`, `minVal: int = 1`, `maxVal: int = 1`; exercises core body path returning/computing `minVal + val`.

```aipl
module tests.functions.math.prng_z26_test
import * from "std/math/prng"
import { TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prng_randomInt_26(): int:
  let arg_rng = RngState(state = 0, seed = 0)
  let edge_rng = RngState(state = 0, seed = 0)
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = randomInt(arg_rng, arg_minVal, arg_maxVal)
  let resEdge = randomInt(edge_rng, edge_minVal, edge_maxVal)
  assertEqInt(resNom, 4, "randomInt nominal resNom == 4")
  assertEqInt(resEdge, 1, "randomInt boundary resEdge == 1")
  ret 0
```

---

### `sampleWeightedIndex` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn sampleWeightedIndex(weights: [int], roll: int): int:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `weights: [int], roll: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `sampleWeightedIndex` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `weights: [int] = [1]`, `roll: int = 1`; exercises core body path returning/computing `weights.len - 1`.

```aipl
module tests.functions.math.prob_stats_z1_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_sampleWeightedIndex_1(): int:
  let arg_weights = [2]
  let edge_weights = []
  let arg_roll = 2
  let edge_roll = 0
  let resNom = sampleWeightedIndex(arg_weights, arg_roll)
  let resEdge = sampleWeightedIndex(edge_weights, edge_roll)
  assertEqInt(resNom, 0, "sampleWeightedIndex nominal resNom == 0")
  assertEqInt(resEdge, -1, "sampleWeightedIndex boundary resEdge == -1")
  ret 0
```

---

### `gaussianSample` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn gaussianSample(mean: float, stdDev: float, u1: float, u2: float): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mean: float, stdDev: float, u1: float, u2: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `gaussianSample` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `mean: float = 1.0`, `stdDev: float = 1.0`, `u1: float = 1.0`, `u2: float = 1.0`; exercises core body path returning/computing `mean + z0`.

```aipl
module tests.functions.math.prob_stats_z2_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_gaussianSample_2(): int:
  let arg_mean = 1.0
  let edge_mean = 0.5
  let arg_stdDev = 1.0
  let edge_stdDev = 0.5
  let arg_u1 = 1.0
  let edge_u1 = 0.5
  let arg_u2 = 1.0
  let edge_u2 = 0.5
  let resNom = gaussianSample(arg_mean, arg_stdDev, arg_u1, arg_u2)
  let resEdge = gaussianSample(edge_mean, edge_stdDev, edge_u1, edge_u2)
  assertApproxEq(resNom, 1.00141, 0.001, "gaussianSample nominal resNom ~= 1.00141")
  assertApproxEq(resEdge, -0.088705, 0.001, "gaussianSample boundary resEdge ~= -0.088705")
  ret 0
```

---

### `poissonSample` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn poissonSample(lambda: float, u: float): int:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lambda: float, u: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `poissonSample` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `lambda: float = 1.0`, `u: float = 1.0`; exercises core body path returning/computing `k`.

```aipl
module tests.functions.math.prob_stats_z3_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_poissonSample_3(): int:
  let arg_lambda = 1.0
  let edge_lambda = 0.5
  let arg_u = 1.0
  let edge_u = 0.5
  let resNom = poissonSample(arg_lambda, arg_u)
  let resEdge = poissonSample(edge_lambda, edge_u)
  assertEqInt(resNom, 9, "poissonSample nominal resNom == 9")
  assertEqInt(resEdge, 0, "poissonSample boundary resEdge == 0")
  ret 0
```

---

### `computeMean` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeMean(values: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeMean` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`; exercises core body path returning/computing `sum / float(values.len)`.

```aipl
module tests.functions.math.prob_stats_z4_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeMean_4(): int:
  let arg_values = [1.0]
  let edge_values = []
  let resNom = computeMean(arg_values)
  let resEdge = computeMean(edge_values)
  assertApproxEq(resNom, 1.0, 0.001, "computeMean nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeMean boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeVariance` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeVariance(values: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeVariance` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`; exercises core body path returning/computing `sumSq / float(values.len)`.

```aipl
module tests.functions.math.prob_stats_z5_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeVariance_5(): int:
  let arg_values = [1.0]
  let edge_values = []
  let resNom = computeVariance(arg_values)
  let resEdge = computeVariance(edge_values)
  assertApproxEq(resNom, 0.0, 0.001, "computeVariance nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeVariance boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeStdDev` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeStdDev(values: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeStdDev` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`; exercises core body path returning/computing `sqrt(computeVariance(values))`.

```aipl
module tests.functions.math.prob_stats_z6_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeStdDev_6(): int:
  let arg_values = [1.0]
  let edge_values = []
  let resNom = computeStdDev(arg_values)
  let resEdge = computeStdDev(edge_values)
  assertApproxEq(resNom, 0.0, 0.001, "computeStdDev nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeStdDev boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeSummaryStats` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeSummaryStats(values: [float]): SummaryStats:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float]` | **Returns**: `SummaryStats`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeSummaryStats` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`; exercises core body path returning/computing `SummaryStats(`.

```aipl
module tests.functions.math.prob_stats_z7_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeSummaryStats_7(): int:
  let arg_values = [1.0]
  let edge_values = []
  let resNom = computeSummaryStats(arg_values)
  let resEdge = computeSummaryStats(edge_values)
  assertEqInt(resNom.count, 1, "computeSummaryStats nominal resNom.count == 1")
  assertEqInt(resEdge.count, 0, "computeSummaryStats boundary resEdge.count == 0")
  ret 0
```

---

### `kalman1DNew` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn kalman1DNew(initialEstimate: float, initialError: float, processNoise: float, measurementNoise: float): KalmanFilter1D:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `initialEstimate: float, initialError: float, processNoise: float, measurementNoise: float` | **Returns**: `KalmanFilter1D`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `kalman1DNew` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `initialEstimate: float = 1.0`, `initialError: float = 1.0`, `processNoise: float = 1.0`, `measurementNoise: float = 1.0`; exercises core body path returning/computing `KalmanFilter1D(`.

```aipl
module tests.functions.math.prob_stats_z8_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_kalman1DNew_8(): int:
  let arg_initialEstimate = 1.0
  let edge_initialEstimate = 0.5
  let arg_initialError = 1.0
  let edge_initialError = 0.5
  let arg_processNoise = 1.0
  let edge_processNoise = 0.5
  let arg_measurementNoise = 1.0
  let edge_measurementNoise = 0.5
  let resNom = kalman1DNew(arg_initialEstimate, arg_initialError, arg_processNoise, arg_measurementNoise)
  let resEdge = kalman1DNew(edge_initialEstimate, edge_initialError, edge_processNoise, edge_measurementNoise)
  assertApproxEq(resNom.estimate, 1.0, 0.001, "kalman1DNew nominal resNom.estimate ~= 1.0")
  assertApproxEq(resEdge.estimate, 0.5, 0.001, "kalman1DNew boundary resEdge.estimate ~= 0.5")
  ret 0
```

---

### `kalman1DUpdate` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn kalman1DUpdate(kf: KalmanFilter1D, measurement: float): KalmanFilter1D:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `kf: KalmanFilter1D, measurement: float` | **Returns**: `KalmanFilter1D`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `kalman1DUpdate` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `kf: KalmanFilter1D = KalmanFilter1D(estimate = 1.0, errorCov = 1.0, processNoise = 1.0, measurementNoise = 1.0)`, `measurement: float = 1.0`; exercises core body path returning/computing `KalmanFilter1D(`.

```aipl
module tests.functions.math.prob_stats_z9_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_kalman1DUpdate_9(): int:
  let arg_kf = KalmanFilter1D(estimate = 1.0, errorCov = 1.0, processNoise = 1.0, measurementNoise = 1.0)
  let edge_kf = KalmanFilter1D(estimate = 0.5, errorCov = 0.5, processNoise = 0.5, measurementNoise = 0.5)
  let arg_measurement = 1.0
  let edge_measurement = 0.5
  let resNom = kalman1DUpdate(arg_kf, arg_measurement)
  let resEdge = kalman1DUpdate(edge_kf, edge_measurement)
  assertApproxEq(resNom.estimate, 1.0, 0.001, "kalman1DUpdate nominal resNom.estimate ~= 1.0")
  assertApproxEq(resEdge.estimate, 0.5, 0.001, "kalman1DUpdate boundary resEdge.estimate ~= 0.5")
  ret 0
```

---

### `statsMean` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn statsMean(vals: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `vals: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `statsMean` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `vals: [float] = [1.0]`; exercises core body path returning/computing `computeMean(vals)`.

```aipl
module tests.functions.math.prob_stats_z10_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_statsMean_10(): int:
  let arg_vals = [1.0]
  let edge_vals = []
  let resNom = statsMean(arg_vals)
  let resEdge = statsMean(edge_vals)
  assertApproxEq(resNom, 1.0, 0.001, "statsMean nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "statsMean boundary resEdge ~= 0.0")
  ret 0
```

---

### `statsPercentile` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn statsPercentile(sortedVals: [float], p: float): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sortedVals: [float], p: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `statsPercentile` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `sortedVals: [float] = [1.0]`, `p: float = 1.0`; exercises core body path returning/computing `sortedVals[low] * (1.0 - weight) + sortedVals[high] * weight`.

```aipl
module tests.functions.math.prob_stats_z11_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_statsPercentile_11(): int:
  let arg_sortedVals = [1.0]
  let edge_sortedVals = []
  let arg_p = 1.0
  let edge_p = 0.5
  let resNom = statsPercentile(arg_sortedVals, arg_p)
  let resEdge = statsPercentile(edge_sortedVals, edge_p)
  assertApproxEq(resNom, 1.0, 0.001, "statsPercentile nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "statsPercentile boundary resEdge ~= 0.0")
  ret 0
```

---

### `percentile` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn percentile(sortedValues: [float], p: float): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sortedValues: [float], p: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `percentile` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `sortedValues: [float] = [1.0]`, `p: float = 1.0`; exercises core body path returning/computing `statsPercentile(sortedValues, p)`.

```aipl
module tests.functions.math.prob_stats_z12_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_percentile_12(): int:
  let arg_sortedValues = [1.0]
  let edge_sortedValues = []
  let arg_p = 1.0
  let edge_p = 0.5
  let resNom = percentile(arg_sortedValues, arg_p)
  let resEdge = percentile(edge_sortedValues, edge_p)
  assertApproxEq(resNom, 1.0, 0.001, "percentile nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "percentile boundary resEdge ~= 0.0")
  ret 0
```

---

### `summaryStats` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn summaryStats(vals: [float]): SummaryStats:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `vals: [float]` | **Returns**: `SummaryStats`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `summaryStats` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `vals: [float] = [1.0]`; exercises core body path returning/computing `SummaryStats(`.

```aipl
module tests.functions.math.prob_stats_z13_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_summaryStats_13(): int:
  let arg_vals = [1.0]
  let edge_vals = []
  let resNom = summaryStats(arg_vals)
  let resEdge = summaryStats(edge_vals)
  assertEqInt(resNom.count, 1, "summaryStats nominal resNom.count == 1")
  assertEqInt(resEdge.count, 0, "summaryStats boundary resEdge.count == 0")
  ret 0
```

---

### `hdrHistogramNew` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn hdrHistogramNew(): HdrHistogram:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `HdrHistogram`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `hdrHistogramNew` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `HdrHistogram(`.

```aipl
module tests.functions.math.prob_stats_z14_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_hdrHistogramNew_14(): int:
  let resNom = hdrHistogramNew()
  let resEdge = hdrHistogramNew()
  assertEqInt(resNom.bucketCount, 0, "hdrHistogramNew nominal resNom.bucketCount == 0")
  assertEqInt(resEdge.bucketCount, 0, "hdrHistogramNew boundary resEdge.bucketCount == 0")
  ret 0
```

---

### `hdrRecord` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn hdrRecord(mut h: HdrHistogram, v: float): HdrHistogram:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut h: HdrHistogram, v: float` | **Returns**: `HdrHistogram`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `hdrRecord` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `h: HdrHistogram = HdrHistogram(bucketCount = int = 0(), counts = [int] = [()], totalCount = int = 0(), minVal = float = 1000000000.0(), maxVal = float = -1000000000.0(), count = int = 0(), sum = float = 0.0(), values = [float] = [()])`, `v: float = 1.0`; exercises core body path returning/computing `h`.

```aipl
module tests.functions.math.prob_stats_z15_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_hdrRecord_15(): int:
  let arg_h = HdrHistogram(bucketCount = 4, counts = [], totalCount = 4, minVal = 0.0, maxVal = 2.0, count = 0, sum = 1.0, values = [])
  let edge_h = HdrHistogram(bucketCount = 4, counts = [], totalCount = 1, minVal = 0.0, maxVal = 1.0, count = 0, sum = 0.5, values = [])
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = hdrRecord(arg_h, arg_v)
  let resEdge = hdrRecord(edge_h, edge_v)
  assertEqInt(resNom.bucketCount, 4, "hdrRecord nominal resNom.bucketCount == 4")
  assertEqInt(resEdge.bucketCount, 4, "hdrRecord boundary resEdge.bucketCount == 4")
  ret 0
```

---

### `hdrMean` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn hdrMean(h: HdrHistogram): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `h: HdrHistogram` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `hdrMean` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `h: HdrHistogram = HdrHistogram(bucketCount = int = 0(), counts = [int] = [()], totalCount = int = 0(), minVal = float = 1000000000.0(), maxVal = float = -1000000000.0(), count = int = 0(), sum = float = 0.0(), values = [float] = [()])`; exercises core body path returning/computing `h.sum / float(h.count)`.

```aipl
module tests.functions.math.prob_stats_z16_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_hdrMean_16(): int:
  let arg_h = HdrHistogram(bucketCount = 4, counts = [], totalCount = 4, minVal = 0.0, maxVal = 2.0, count = 0, sum = 1.0, values = [])
  let edge_h = HdrHistogram(bucketCount = 4, counts = [], totalCount = 1, minVal = 0.0, maxVal = 1.0, count = 0, sum = 0.5, values = [])
  let resNom = hdrMean(arg_h)
  let resEdge = hdrMean(edge_h)
  assertApproxEq(resNom, 0.0, 0.001, "hdrMean nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "hdrMean boundary resEdge ~= 0.0")
  ret 0
```

---

### `evalPiecewiseLinearCurve` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn evalPiecewiseLinearCurve(x: float, knotsX: [float], knotsY: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, knotsX: [float], knotsY: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `evalPiecewiseLinearCurve` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `x: float = 1.0`, `knotsX: [float] = [1.0]`, `knotsY: [float] = [1.0]`; exercises core body path returning/computing `knotsY[n - 1]`.

```aipl
module tests.functions.math.prob_stats_z17_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_evalPiecewiseLinearCurve_17(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_knotsX = [1.0]
  let edge_knotsX = []
  let arg_knotsY = [1.0]
  let edge_knotsY = []
  let resNom = evalPiecewiseLinearCurve(arg_x, arg_knotsX, arg_knotsY)
  let resEdge = evalPiecewiseLinearCurve(edge_x, edge_knotsX, edge_knotsY)
  assertApproxEq(resNom, 1.0, 0.001, "evalPiecewiseLinearCurve nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "evalPiecewiseLinearCurve boundary resEdge ~= 0.0")
  ret 0
```

---

### `evalTieredMarginalRate` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn evalTieredMarginalRate(amount: float, thresholds: [float], rates: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amount: float, thresholds: [float], rates: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `evalTieredMarginalRate` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `amount: float = 1.0`, `thresholds: [float] = [1.0]`, `rates: [float] = [1.0]`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.math.prob_stats_z18_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_evalTieredMarginalRate_18(): int:
  let arg_amount = 1.0
  let edge_amount = 0.5
  let arg_thresholds = [2.0]
  let edge_thresholds = []
  let arg_rates = [2.0]
  let edge_rates = []
  let resNom = evalTieredMarginalRate(arg_amount, arg_thresholds, arg_rates)
  let resEdge = evalTieredMarginalRate(edge_amount, edge_thresholds, edge_rates)
  assertApproxEq(resNom, 0.0, 0.001, "evalTieredMarginalRate nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "evalTieredMarginalRate boundary resEdge ~= 0.0")
  ret 0
```

---

### `movingAverage` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn movingAverage(values: [float], windowSize: int): [float]:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float], windowSize: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `movingAverage` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`, `windowSize: int = 64`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.prob_stats_z19_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_movingAverage_19(): int:
  let arg_values = [1.0]
  let edge_values = []
  let arg_windowSize = 4
  let edge_windowSize = 1
  let resNom = movingAverage(arg_values, arg_windowSize)
  let resEdge = movingAverage(edge_values, edge_windowSize)
  assertEqInt(resNom.len(), 1, "movingAverage nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "movingAverage boundary resEdge.len() == 0")
  ret 0
```

---

### `exponentialMovingAverage` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn exponentialMovingAverage(values: [float], alpha: float): [float]:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `values: [float], alpha: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `exponentialMovingAverage` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `values: [float] = [1.0]`, `alpha: float = 0.5`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.prob_stats_z20_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_exponentialMovingAverage_20(): int:
  let arg_values = [1.0]
  let edge_values = []
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let resNom = exponentialMovingAverage(arg_values, arg_alpha)
  let resEdge = exponentialMovingAverage(edge_values, edge_alpha)
  assertEqInt(resNom.len(), 1, "exponentialMovingAverage nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "exponentialMovingAverage boundary resEdge.len() == 0")
  ret 0
```

---

### `commComputeTieredAcceleratorPayout` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn commComputeTieredAcceleratorPayout(attainmentPct: int, baseCommission: int, tier1MultPct: int, tier2MultPct: int): int:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `attainmentPct: int, baseCommission: int, tier1MultPct: int, tier2MultPct: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `commComputeTieredAcceleratorPayout` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `attainmentPct: int = 1`, `baseCommission: int = 1`, `tier1MultPct: int = 1`, `tier2MultPct: int = 1`; exercises core body path returning/computing `p0 + p1 + p2`.

```aipl
module tests.functions.math.prob_stats_z21_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_commComputeTieredAcceleratorPayout_21(): int:
  let arg_attainmentPct = 4
  let edge_attainmentPct = 1
  let arg_baseCommission = 4
  let edge_baseCommission = 1
  let arg_tier1MultPct = 4
  let edge_tier1MultPct = 1
  let arg_tier2MultPct = 4
  let edge_tier2MultPct = 1
  let resNom = commComputeTieredAcceleratorPayout(arg_attainmentPct, arg_baseCommission, arg_tier1MultPct, arg_tier2MultPct)
  let resEdge = commComputeTieredAcceleratorPayout(edge_attainmentPct, edge_baseCommission, edge_tier1MultPct, edge_tier2MultPct)
  assertEqInt(resNom, 0, "commComputeTieredAcceleratorPayout nominal resNom == 0")
  assertEqInt(resEdge, 0, "commComputeTieredAcceleratorPayout boundary resEdge == 0")
  ret 0
```

---

### `computeCovariance` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeCovariance(xs: [float], ys: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `xs: [float], ys: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeCovariance` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`; exercises core body path returning/computing `sum / float(n)`.

```aipl
module tests.functions.math.prob_stats_z22_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeCovariance_22(): int:
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let resNom = computeCovariance(arg_xs, arg_ys)
  let resEdge = computeCovariance(edge_xs, edge_ys)
  assertApproxEq(resNom, 0.0, 0.001, "computeCovariance nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeCovariance boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeCorrelation` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn computeCorrelation(xs: [float], ys: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `xs: [float], ys: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `computeCorrelation` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`; exercises core body path returning/computing `computeCovariance(xs, ys) / denom`.

```aipl
module tests.functions.math.prob_stats_z23_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_computeCorrelation_23(): int:
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let resNom = computeCorrelation(arg_xs, arg_ys)
  let resEdge = computeCorrelation(edge_xs, edge_ys)
  assertApproxEq(resNom, 0.0, 0.001, "computeCorrelation nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeCorrelation boundary resEdge ~= 0.0")
  ret 0
```

---

### `linearRegressionSlope` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn linearRegressionSlope(xs: [float], ys: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `xs: [float], ys: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `linearRegressionSlope` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`; exercises core body path returning/computing `computeCovariance(xs, ys) / vx`.

```aipl
module tests.functions.math.prob_stats_z24_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_linearRegressionSlope_24(): int:
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let resNom = linearRegressionSlope(arg_xs, arg_ys)
  let resEdge = linearRegressionSlope(edge_xs, edge_ys)
  assertApproxEq(resNom, 0.0, 0.001, "linearRegressionSlope nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "linearRegressionSlope boundary resEdge ~= 0.0")
  ret 0
```

---

### `linearRegressionIntercept` (`std/math/prob_stats.aipl`)

- **Signature**: `pub fn linearRegressionIntercept(xs: [float], ys: [float]): float:`
- **Import**: `import * from "std/math/prob_stats"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `xs: [float], ys: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/prob_stats_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify statistical/filtering function `linearRegressionIntercept` against exact analytical reference values (mean, variance, quantiles, OLS linear regression `y = mx + b`, HDR histogram, or 1D Kalman gain convergence). Concrete nominal inputs: `xs: [float] = [1.0]`, `ys: [float] = [1.0]`; exercises core body path returning/computing `my - m * mx`.

```aipl
module tests.functions.math.prob_stats_z25_test
import * from "std/math/prob_stats"
import { TAU, clampFloat, floor } from "std/math/consts"
import { sqrt, cos, lnFloat, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_prob_stats_linearRegressionIntercept_25(): int:
  let arg_xs = [1.0]
  let edge_xs = []
  let arg_ys = [1.0]
  let edge_ys = []
  let resNom = linearRegressionIntercept(arg_xs, arg_ys)
  let resEdge = linearRegressionIntercept(edge_xs, edge_ys)
  assertApproxEq(resNom, 1.0, 0.001, "linearRegressionIntercept nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "linearRegressionIntercept boundary resEdge ~= 0.0")
  ret 0
```

---

### `Quat.identity` (`std/math/quat.aipl`)

- **Signature**: `pub fn Quat.identity(): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Quat(x = 0.0, y = 0.0, z = 0.0, w = 1.0)`.

```aipl
module tests.functions.math.quat_z1_test
import * from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_identity_1(): int:
  let resNom = Quat.identity()
  let resEdge = Quat.identity()
  assertApproxEq(resNom.x, 0.0, 0.001, "Quat.identity nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Quat.identity boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `Quat.fromAxisAngle` (`std/math/quat.aipl`)

- **Signature**: `pub fn Quat.fromAxisAngle(axis: Vec3, rad: float): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `axis: Vec3, rad: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: `axis: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `rad: float = 1.0`; exercises core body path returning/computing `Quat(x = n.x * s, y = n.y * s, z = n.z * s, w = c)`.

```aipl
module tests.functions.math.quat_z2_test
import * from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_fromAxisAngle_2(): int:
  let arg_axis = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_axis = Vec3(x = 0.0, y = 0.0, z = 0.0)
  let arg_rad = 1.0
  let edge_rad = 0.0
  let resNom = Quat.fromAxisAngle(arg_axis, arg_rad)
  let resEdge = Quat.fromAxisAngle(edge_axis, edge_rad)
  assertApproxEq(resNom.x, 0.276796, 0.001, "Quat.fromAxisAngle nominal resNom.x ~= 0.276796")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Quat.fromAxisAngle boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `Quat.fromEuler` (`std/math/quat.aipl`)

- **Signature**: `pub fn Quat.fromEuler(pitch: float, yaw: float, roll: float): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pitch: float, yaw: float, roll: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: `pitch: float = 1.0`, `yaw: float = 1.0`, `roll: float = 1.0`; exercises core body path returning/computing `Quat(`.

```aipl
module tests.functions.math.quat_z3_test
import * from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_fromEuler_3(): int:
  let arg_pitch = 1.0
  let edge_pitch = 0.0
  let arg_yaw = 1.0
  let edge_yaw = 0.0
  let arg_roll = 1.0
  let edge_roll = 0.0
  let resNom = Quat.fromEuler(arg_pitch, arg_yaw, arg_roll)
  let resEdge = Quat.fromEuler(edge_pitch, edge_yaw, edge_roll)
  assertApproxEq(resNom.x, 0.167519, 0.001, "Quat.fromEuler nominal resNom.x ~= 0.167519")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Quat.fromEuler boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `lenSq` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) lenSq(): float:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `self.x * self.x + self.y * self.y + self.z * self.z + self.w * self.w`.

```aipl
module tests.functions.math.quat_z4_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_lenSq_4(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.lenSq()
  let resEdge = edge_self.lenSq()
  assertApproxEq(resNom, 7.0, 0.001, "lenSq nominal resNom ~= 7.0")
  assertApproxEq(resEdge, 1.75, 0.001, "lenSq boundary resEdge ~= 1.75")
  ret 0
```

---

### `len` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) len(): float:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `sqrt(self.lenSq())`.

```aipl
module tests.functions.math.quat_z5_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_len_5(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertApproxEq(resNom, 2.64575, 0.001, "len nominal resNom ~= 2.64575")
  assertApproxEq(resEdge, 1.32288, 0.001, "len boundary resEdge ~= 1.32288")
  ret 0
```

---

### `norm` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) norm(): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `none` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Quat.identity()`.

```aipl
module tests.functions.math.quat_z6_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_norm_6(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.norm()
  let resEdge = edge_self.norm()
  assertApproxEq(resNom.x, 0.377964, 0.001, "norm nominal resNom.x ~= 0.377964")
  assertApproxEq(resEdge.x, 0.377964, 0.001, "norm boundary resEdge.x ~= 0.377964")
  ret 0
```

---

### `conjugate` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) conjugate(): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `none` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Quat(x = -self.x, y = -self.y, z = -self.z, w = self.w)`.

```aipl
module tests.functions.math.quat_z7_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_conjugate_7(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.conjugate()
  let resEdge = edge_self.conjugate()
  assertApproxEq(resNom.x, -1.0, 0.001, "conjugate nominal resNom.x ~= -1.0")
  assertApproxEq(resEdge.x, -0.5, 0.001, "conjugate boundary resEdge.x ~= -0.5")
  ret 0
```

---

### `mul` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) mul(other: Quat): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `other: Quat` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `other: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Quat(`.

```aipl
module tests.functions.math.quat_z8_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_mul_8(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_other = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_other = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.mul(arg_other)
  let resEdge = edge_self.mul(edge_other)
  assertApproxEq(resNom.x, 4.0, 0.001, "mul nominal resNom.x ~= 4.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "mul boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `slerp` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) slerp(target: Quat, t: float): Quat:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `target: Quat, t: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `target: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Quat(`.

```aipl
module tests.functions.math.quat_z9_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_slerp_9(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_target = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_target = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = recv_self.slerp(arg_target, arg_t)
  let resEdge = edge_self.slerp(edge_target, edge_t)
  assertApproxEq(resNom.x, 0.377964, 0.001, "slerp nominal resNom.x ~= 0.377964")
  assertApproxEq(resEdge.x, 0.377964, 0.001, "slerp boundary resEdge.x ~= 0.377964")
  ret 0
```

---

### `rotateVec3` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) rotateVec3(v: Vec3): Vec3:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `v: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `v: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `v.add(t.scale(self.w)).add(u.cross(t))`.

```aipl
module tests.functions.math.quat_z10_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_rotateVec3_10(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_v = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.rotateVec3(arg_v)
  let resEdge = edge_self.rotateVec3(edge_v)
  assertApproxEq(resNom.x, 1.0, 0.001, "rotateVec3 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "rotateVec3 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `toMat4` (`std/math/quat.aipl`)

- **Signature**: `pub fn (self: Quat) toMat4(): Mat4:`
- **Import**: `import * from "std/math/quat"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Quat` | **Parameters**: `none` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/math/quat_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: ~= 1`), axis-angle/Euler 3D vector rotation equivalence with `toMat4()`, and `slerp` constant angular velocity. Concrete nominal inputs: receiver `recvObj: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.math.quat_z11_test
import * from "std/math/quat"
import { sin, cos, acos, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_quat_Quat_toMat4_11(): int:
  let recv_self = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.toMat4()
  let resEdge = edge_self.toMat4()
  assertApproxEq(resNom.m00, -3.0, 0.001, "toMat4 nominal resNom.m00 ~= -3.0")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "toMat4 boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `f32x4Add` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Add(a: F32x4, b: F32x4): F32x4:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `F32x4`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Add` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `F32x4(x = a.x + b.x, y = a.y + b.y, z = a.z + b.z, w = a.w + b.w)`.

```aipl
module tests.functions.math.simd_z1_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Add_1(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Add(arg_a, arg_b)
  let resEdge = f32x4Add(edge_a, edge_b)
  assertApproxEq(resNom.x, 2.0, 0.001, "f32x4Add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "f32x4Add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `f32x4Sub` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Sub(a: F32x4, b: F32x4): F32x4:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `F32x4`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Sub` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `F32x4(x = a.x - b.x, y = a.y - b.y, z = a.z - b.z, w = a.w - b.w)`.

```aipl
module tests.functions.math.simd_z2_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Sub_2(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Sub(arg_a, arg_b)
  let resEdge = f32x4Sub(edge_a, edge_b)
  assertApproxEq(resNom.x, 0.0, 0.001, "f32x4Sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "f32x4Sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `f32x4Mul` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Mul(a: F32x4, b: F32x4): F32x4:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `F32x4`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Mul` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `F32x4(x = a.x * b.x, y = a.y * b.y, z = a.z * b.z, w = a.w * b.w)`.

```aipl
module tests.functions.math.simd_z3_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Mul_3(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Mul(arg_a, arg_b)
  let resEdge = f32x4Mul(edge_a, edge_b)
  assertApproxEq(resNom.x, 1.0, 0.001, "f32x4Mul nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "f32x4Mul boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `f32x4Dot` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Dot(a: F32x4, b: F32x4): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Dot` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w`.

```aipl
module tests.functions.math.simd_z4_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Dot_4(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Dot(arg_a, arg_b)
  let resEdge = f32x4Dot(edge_a, edge_b)
  assertApproxEq(resNom, 7.0, 0.001, "f32x4Dot nominal resNom ~= 7.0")
  assertApproxEq(resEdge, 1.75, 0.001, "f32x4Dot boundary resEdge ~= 1.75")
  ret 0
```

---

### `f32x4Min` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Min(a: F32x4, b: F32x4): F32x4:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `F32x4`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Min` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `F32x4(`.

```aipl
module tests.functions.math.simd_z5_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Min_5(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Min(arg_a, arg_b)
  let resEdge = f32x4Min(edge_a, edge_b)
  assertApproxEq(resNom.x, 1.0, 0.001, "f32x4Min nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "f32x4Min boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `f32x4Max` (`std/math/simd.aipl`)

- **Signature**: `pub fn f32x4Max(a: F32x4, b: F32x4): F32x4:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: F32x4, b: F32x4` | **Returns**: `F32x4`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `f32x4Max` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: F32x4 = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `F32x4(`.

```aipl
module tests.functions.math.simd_z6_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_f32x4Max_6(): int:
  let arg_a = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = F32x4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = F32x4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = f32x4Max(arg_a, arg_b)
  let resEdge = f32x4Max(edge_a, edge_b)
  assertApproxEq(resNom.x, 1.0, 0.001, "f32x4Max nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "f32x4Max boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `tensorDot` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorDot(a: [float], b: [float]): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorDot` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.math.simd_z7_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorDot_7(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let resNom = tensorDot(arg_a, arg_b)
  let resEdge = tensorDot(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "tensorDot nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tensorDot boundary resEdge ~= 0.0")
  ret 0
```

---

### `tensorMatmul` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorMatmul(a: [float], b: [float], m: int, n: int, k: int): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float], m: int, n: int, k: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorMatmul` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`, `m: int = 1`, `n: int = 1`, `k: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z8_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorMatmul_8(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let arg_m = 4
  let edge_m = 1
  let arg_n = 4
  let edge_n = 1
  let arg_k = 4
  let edge_k = 1
  let resNom = tensorMatmul(arg_a, arg_b, arg_m, arg_n, arg_k)
  let resEdge = tensorMatmul(edge_a, edge_b, edge_m, edge_n, edge_k)
  assertEqInt(resNom.len(), 16, "tensorMatmul nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 1, "tensorMatmul boundary resEdge.len() == 1")
  ret 0
```

---

### `tensorSoftmax` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorSoftmax(a: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorSoftmax` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z9_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorSoftmax_9(): int:
  let arg_a = [1.0]
  let edge_a = []
  let resNom = tensorSoftmax(arg_a)
  let resEdge = tensorSoftmax(edge_a)
  assertEqInt(resNom.len(), 1, "tensorSoftmax nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "tensorSoftmax boundary resEdge.len() == 0")
  ret 0
```

---

### `tensorCosineSimilarity` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorCosineSimilarity(a: [float], b: [float]): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorCosineSimilarity` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`; exercises core body path returning/computing `dot / denom`.

```aipl
module tests.functions.math.simd_z10_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorCosineSimilarity_10(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let resNom = tensorCosineSimilarity(arg_a, arg_b)
  let resEdge = tensorCosineSimilarity(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "tensorCosineSimilarity nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "tensorCosineSimilarity boundary resEdge ~= 0.0")
  ret 0
```

---

### `tensorLayerNorm` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorLayerNorm(a: [float], eps: float = 0.00001): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], eps: float = 0.00001` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorLayerNorm` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `eps: float = 0.0001`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z11_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorLayerNorm_11(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_eps = 1.0
  let edge_eps = 0.5
  let resNom = tensorLayerNorm(arg_a, arg_eps)
  let resEdge = tensorLayerNorm(edge_a, edge_eps)
  assertEqInt(resNom.len(), 1, "tensorLayerNorm nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "tensorLayerNorm boundary resEdge.len() == 0")
  ret 0
```

---

### `analyzeSimdLoopAutoVectorization` (`std/math/simd.aipl`)

- **Signature**: `pub fn analyzeSimdLoopAutoVectorization(strideElem: int, tripCount: int, hasLoopCarriedDep: bool, targetBits: int): SimdLoopVectorPlan:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `strideElem: int, tripCount: int, hasLoopCarriedDep: bool, targetBits: int` | **Returns**: `SimdLoopVectorPlan`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `analyzeSimdLoopAutoVectorization` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `strideElem: int = 1`, `tripCount: int = 64`, `hasLoopCarriedDep: bool = true`, `targetBits: int = 1`; exercises core body path returning/computing `SimdLoopVectorPlan(`.

```aipl
module tests.functions.math.simd_z12_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_analyzeSimdLoopAutoVectorization_12(): int:
  let arg_strideElem = 4
  let edge_strideElem = 1
  let arg_tripCount = 4
  let edge_tripCount = 1
  let arg_hasLoopCarriedDep = true
  let edge_hasLoopCarriedDep = false
  let arg_targetBits = 4
  let edge_targetBits = 1
  let resNom = analyzeSimdLoopAutoVectorization(arg_strideElem, arg_tripCount, arg_hasLoopCarriedDep, arg_targetBits)
  let resEdge = analyzeSimdLoopAutoVectorization(edge_strideElem, edge_tripCount, edge_hasLoopCarriedDep, edge_targetBits)
  assertEqInt(resNom.strideElem, 4, "analyzeSimdLoopAutoVectorization nominal resNom.strideElem == 4")
  assertEqInt(resEdge.strideElem, 1, "analyzeSimdLoopAutoVectorization boundary resEdge.strideElem == 1")
  ret 0
```

---

### `simdDotProduct8Wide` (`std/math/simd.aipl`)

- **Signature**: `pub fn simdDotProduct8Wide(a: [float], b: [float]): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `simdDotProduct8Wide` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`; exercises core body path returning/computing `(acc0 + acc1) + (acc2 + acc3) + tail`.

```aipl
module tests.functions.math.simd_z13_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_simdDotProduct8Wide_13(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let resNom = simdDotProduct8Wide(arg_a, arg_b)
  let resEdge = simdDotProduct8Wide(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "simdDotProduct8Wide nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "simdDotProduct8Wide boundary resEdge ~= 0.0")
  ret 0
```

---

### `simdAxpy8Wide` (`std/math/simd.aipl`)

- **Signature**: `pub fn simdAxpy8Wide(alpha: float, x: [float], y: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `alpha: float, x: [float], y: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `simdAxpy8Wide` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `alpha: float = 0.5`, `x: [float] = [1.0]`, `y: [float] = [1.0]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z14_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_simdAxpy8Wide_14(): int:
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let arg_x = [1.0]
  let edge_x = []
  let arg_y = [1.0]
  let edge_y = []
  let resNom = simdAxpy8Wide(arg_alpha, arg_x, arg_y)
  let resEdge = simdAxpy8Wide(edge_alpha, edge_x, edge_y)
  assertEqInt(resNom.len(), 1, "simdAxpy8Wide nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "simdAxpy8Wide boundary resEdge.len() == 0")
  ret 0
```

---

### `intBufferNew` (`std/math/simd.aipl`)

- **Signature**: `pub fn intBufferNew(size: int): [int]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `intBufferNew` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `buf`.

```aipl
module tests.functions.math.simd_z15_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_intBufferNew_15(): int:
  let arg_size = 4
  let edge_size = 1
  let resNom = intBufferNew(arg_size)
  let resEdge = intBufferNew(edge_size)
  assertEqInt(resNom.len(), 4, "intBufferNew nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "intBufferNew boundary resEdge.len() == 1")
  ret 0
```

---

### `intBufferGet` (`std/math/simd.aipl`)

- **Signature**: `pub fn intBufferGet(buf: [int], idx: int): int:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [int], idx: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `intBufferGet` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [int] = [1]`, `idx: int = 0`; exercises core body path returning/computing `buf[idx]`.

```aipl
module tests.functions.math.simd_z16_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_intBufferGet_16(): int:
  let arg_buf = [4]
  let edge_buf = []
  let arg_idx = 1
  let edge_idx = 0
  let resNom = intBufferGet(arg_buf, arg_idx)
  let resEdge = intBufferGet(edge_buf, edge_idx)
  assertEqInt(resNom, 0, "intBufferGet nominal resNom == 0")
  assertEqInt(resEdge, 0, "intBufferGet boundary resEdge == 0")
  ret 0
```

---

### `intBufferSet` (`std/math/simd.aipl`)

- **Signature**: `pub fn intBufferSet(buf: [int], idx: int, val: int): [int]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [int], idx: int, val: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `intBufferSet` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [int] = [1]`, `idx: int = 0`, `val: int = 1`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.math.simd_z17_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_intBufferSet_17(): int:
  let arg_buf = [4]
  let edge_buf = []
  let arg_idx = 1
  let edge_idx = 0
  let arg_val = 2
  let edge_val = 0
  let resNom = intBufferSet(arg_buf, arg_idx, arg_val)
  let resEdge = intBufferSet(edge_buf, edge_idx, edge_val)
  assertEqInt(resNom.len(), 1, "intBufferSet nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "intBufferSet boundary resEdge.len() == 0")
  ret 0
```

---

### `intBufferLen` (`std/math/simd.aipl`)

- **Signature**: `pub fn intBufferLen(buf: [int]): int:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `intBufferLen` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [int] = [1]`; exercises core body path returning/computing `buf.len`.

```aipl
module tests.functions.math.simd_z18_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_intBufferLen_18(): int:
  let arg_buf = [4]
  let edge_buf = []
  let resNom = intBufferLen(arg_buf)
  let resEdge = intBufferLen(edge_buf)
  assertEqInt(resNom, 1, "intBufferLen nominal resNom == 1")
  assertEqInt(resEdge, 0, "intBufferLen boundary resEdge == 0")
  ret 0
```

---

### `floatBufferNew` (`std/math/simd.aipl`)

- **Signature**: `pub fn floatBufferNew(size: int): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `floatBufferNew` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `buf`.

```aipl
module tests.functions.math.simd_z19_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_floatBufferNew_19(): int:
  let arg_size = 4
  let edge_size = 1
  let resNom = floatBufferNew(arg_size)
  let resEdge = floatBufferNew(edge_size)
  assertEqInt(resNom.len(), 4, "floatBufferNew nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "floatBufferNew boundary resEdge.len() == 1")
  ret 0
```

---

### `floatBufferGet` (`std/math/simd.aipl`)

- **Signature**: `pub fn floatBufferGet(buf: [float], idx: int): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [float], idx: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `floatBufferGet` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [float] = [1.0]`, `idx: int = 0`; exercises core body path returning/computing `buf[idx]`.

```aipl
module tests.functions.math.simd_z20_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_floatBufferGet_20(): int:
  let arg_buf = [1.0]
  let edge_buf = []
  let arg_idx = 1
  let edge_idx = 0
  let resNom = floatBufferGet(arg_buf, arg_idx)
  let resEdge = floatBufferGet(edge_buf, edge_idx)
  assertApproxEq(resNom, 0.0, 0.001, "floatBufferGet nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "floatBufferGet boundary resEdge ~= 0.0")
  ret 0
```

---

### `floatBufferSet` (`std/math/simd.aipl`)

- **Signature**: `pub fn floatBufferSet(buf: [float], idx: int, val: float): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [float], idx: int, val: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `floatBufferSet` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [float] = [1.0]`, `idx: int = 0`, `val: float = 1.0`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.math.simd_z21_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_floatBufferSet_21(): int:
  let arg_buf = [1.0]
  let edge_buf = []
  let arg_idx = 1
  let edge_idx = 0
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = floatBufferSet(arg_buf, arg_idx, arg_val)
  let resEdge = floatBufferSet(edge_buf, edge_idx, edge_val)
  assertEqInt(resNom.len(), 1, "floatBufferSet nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "floatBufferSet boundary resEdge.len() == 0")
  ret 0
```

---

### `floatBufferLen` (`std/math/simd.aipl`)

- **Signature**: `pub fn floatBufferLen(buf: [float]): int:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: [float]` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `floatBufferLen` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `buf: [float] = [1.0]`; exercises core body path returning/computing `buf.len`.

```aipl
module tests.functions.math.simd_z22_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_floatBufferLen_22(): int:
  let arg_buf = [1.0]
  let edge_buf = []
  let resNom = floatBufferLen(arg_buf)
  let resEdge = floatBufferLen(edge_buf)
  assertEqInt(resNom, 1, "floatBufferLen nominal resNom == 1")
  assertEqInt(resEdge, 0, "floatBufferLen boundary resEdge == 0")
  ret 0
```

---

### `sumIntsFast` (`std/math/simd.aipl`)

- **Signature**: `pub fn sumIntsFast(arr: [int]): int:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `sumIntsFast` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `arr: [int] = [1]`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.math.simd_z23_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_sumIntsFast_23(): int:
  let arg_arr = [2]
  let edge_arr = []
  let resNom = sumIntsFast(arg_arr)
  let resEdge = sumIntsFast(edge_arr)
  assertEqInt(resNom, 2, "sumIntsFast nominal resNom == 2")
  assertEqInt(resEdge, 0, "sumIntsFast boundary resEdge == 0")
  ret 0
```

---

### `sumFloatsFast` (`std/math/simd.aipl`)

- **Signature**: `pub fn sumFloatsFast(arr: [float]): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `arr: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `sumFloatsFast` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `arr: [float] = [1.0]`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.math.simd_z24_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_sumFloatsFast_24(): int:
  let arg_arr = [1.0]
  let edge_arr = []
  let resNom = sumFloatsFast(arg_arr)
  let resEdge = sumFloatsFast(edge_arr)
  assertApproxEq(resNom, 1.0, 0.001, "sumFloatsFast nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sumFloatsFast boundary resEdge ~= 0.0")
  ret 0
```

---

### `dotProductFloats` (`std/math/simd.aipl`)

- **Signature**: `pub fn dotProductFloats(a: [float], b: [float]): float:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `dotProductFloats` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`; exercises core body path returning/computing `tensorDot(a, b)`.

```aipl
module tests.functions.math.simd_z25_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_dotProductFloats_25(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let resNom = dotProductFloats(arg_a, arg_b)
  let resEdge = dotProductFloats(edge_a, edge_b)
  assertApproxEq(resNom, 1.0, 0.001, "dotProductFloats nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "dotProductFloats boundary resEdge ~= 0.0")
  ret 0
```

---

### `axpyFloats` (`std/math/simd.aipl`)

- **Signature**: `pub fn axpyFloats(alpha: float, x: [float], y: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `alpha: float, x: [float], y: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `axpyFloats` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `alpha: float = 0.5`, `x: [float] = [1.0]`, `y: [float] = [1.0]`; exercises core body path returning/computing `simdAxpy8Wide(alpha, x, y)`.

```aipl
module tests.functions.math.simd_z26_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_axpyFloats_26(): int:
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let arg_x = [1.0]
  let edge_x = []
  let arg_y = [1.0]
  let edge_y = []
  let resNom = axpyFloats(arg_alpha, arg_x, arg_y)
  let resEdge = axpyFloats(edge_alpha, edge_x, edge_y)
  assertEqInt(resNom.len(), 1, "axpyFloats nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "axpyFloats boundary resEdge.len() == 0")
  ret 0
```

---

### `simdFma4Wide` (`std/math/simd.aipl`)

- **Signature**: `pub fn simdFma4Wide(a: [float], b: [float], c: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float], c: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `simdFma4Wide` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`, `c: [float] = [1.0]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z27_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_simdFma4Wide_27(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let arg_c = [1.0]
  let edge_c = []
  let resNom = simdFma4Wide(arg_a, arg_b, arg_c)
  let resEdge = simdFma4Wide(edge_a, edge_b, edge_c)
  assertEqInt(resNom.len(), 1, "simdFma4Wide nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "simdFma4Wide boundary resEdge.len() == 0")
  ret 0
```

---

### `simdMatmul4x4Tiled` (`std/math/simd.aipl`)

- **Signature**: `pub fn simdMatmul4x4Tiled(a: [float], b: [float], n: int): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float], n: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `simdMatmul4x4Tiled` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`, `n: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z28_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_simdMatmul4x4Tiled_28(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let arg_n = 4
  let edge_n = 1
  let resNom = simdMatmul4x4Tiled(arg_a, arg_b, arg_n)
  let resEdge = simdMatmul4x4Tiled(edge_a, edge_b, edge_n)
  assertEqInt(resNom.len(), 0, "simdMatmul4x4Tiled nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "simdMatmul4x4Tiled boundary resEdge.len() == 0")
  ret 0
```

---

### `tensorAdd` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorAdd(a: [float], b: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], b: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorAdd` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `b: [float] = [1.0]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z29_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorAdd_29(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_b = [1.0]
  let edge_b = []
  let resNom = tensorAdd(arg_a, arg_b)
  let resEdge = tensorAdd(edge_a, edge_b)
  assertEqInt(resNom.len(), 1, "tensorAdd nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "tensorAdd boundary resEdge.len() == 0")
  ret 0
```

---

### `tensorScale` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorScale(a: [float], s: float): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], s: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorScale` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `s: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z30_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorScale_30(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = tensorScale(arg_a, arg_s)
  let resEdge = tensorScale(edge_a, edge_s)
  assertEqInt(resNom.len(), 1, "tensorScale nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "tensorScale boundary resEdge.len() == 0")
  ret 0
```

---

### `tensorRelu` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorRelu(a: [float]): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorRelu` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z31_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorRelu_31(): int:
  let arg_a = [1.0]
  let edge_a = []
  let resNom = tensorRelu(arg_a)
  let resEdge = tensorRelu(edge_a)
  assertEqInt(resNom.len(), 1, "tensorRelu nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "tensorRelu boundary resEdge.len() == 0")
  ret 0
```

---

### `tensorTranspose` (`std/math/simd.aipl`)

- **Signature**: `pub fn tensorTranspose(a: [float], rows: int, cols: int): [float]:`
- **Import**: `import * from "std/math/simd"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: [float], rows: int, cols: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/math/simd_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify 4-wide/8-wide SIMD & tensor kernel `tensorTranspose` element-wise parity against scalar reference loops, softmax probability normalization (`sum(p_i) == 1.0`), and tiled 4x4 matrix multiplication. Concrete nominal inputs: `a: [float] = [1.0]`, `rows: int = 1`, `cols: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.math.simd_z32_test
import * from "std/math/simd"
import { minFloat, maxFloat } from "std/math/consts"
import { sqrt, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_simd_tensorTranspose_32(): int:
  let arg_a = [1.0]
  let edge_a = []
  let arg_rows = 4
  let edge_rows = 1
  let arg_cols = 4
  let edge_cols = 1
  let resNom = tensorTranspose(arg_a, arg_rows, arg_cols)
  let resEdge = tensorTranspose(edge_a, edge_rows, edge_cols)
  assertEqInt(resNom.len(), 0, "tensorTranspose nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "tensorTranspose boundary resEdge.len() == 0")
  ret 0
```

---

### `degToRad` (`std/math/trig.aipl`)

- **Signature**: `pub fn degToRad(deg: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `deg: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `degToRad` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `deg: float = 1.0`; exercises core body path returning/computing `deg * DEG2RAD`.

```aipl
module tests.functions.math.trig_z1_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_degToRad_1(): int:
  let arg_deg = 1.0
  let edge_deg = 0.5
  let resNom = degToRad(arg_deg)
  let resEdge = degToRad(edge_deg)
  assertApproxEq(resNom, 0.017453, 0.001, "degToRad nominal resNom ~= 0.017453")
  assertApproxEq(resEdge, 0.008727, 0.001, "degToRad boundary resEdge ~= 0.008727")
  ret 0
```

---

### `radToDeg` (`std/math/trig.aipl`)

- **Signature**: `pub fn radToDeg(rad: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `radToDeg` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `rad * RAD2DEG`.

```aipl
module tests.functions.math.trig_z2_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_radToDeg_2(): int:
  let arg_rad = 1.0
  let edge_rad = 0.5
  let resNom = radToDeg(arg_rad)
  let resEdge = radToDeg(edge_rad)
  assertApproxEq(resNom, 57.2958, 0.001, "radToDeg nominal resNom ~= 57.2958")
  assertApproxEq(resEdge, 28.6479, 0.001, "radToDeg boundary resEdge ~= 28.6479")
  ret 0
```

---

### `sqrt` (`std/math/trig.aipl`)

- **Signature**: `pub fn sqrt(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sqrt` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `guess`.

```aipl
module tests.functions.math.trig_z3_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sqrt_3(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = sqrt(arg_x)
  let resEdge = sqrt(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "sqrt nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.707107, 0.001, "sqrt boundary resEdge ~= 0.707107")
  ret 0
```

---

### `cbrt` (`std/math/trig.aipl`)

- **Signature**: `pub fn cbrt(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `cbrt` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `if neg: -g else: g`.

```aipl
module tests.functions.math.trig_z4_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_cbrt_4(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = cbrt(arg_x)
  let resEdge = cbrt(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "cbrt nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.793701, 0.001, "cbrt boundary resEdge ~= 0.793701")
  ret 0
```

---

### `hypot` (`std/math/trig.aipl`)

- **Signature**: `pub fn hypot(x: float, y: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `hypot` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `sqrt(x * x + y * y)`.

```aipl
module tests.functions.math.trig_z5_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_hypot_5(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let resNom = hypot(arg_x, arg_y)
  let resEdge = hypot(edge_x, edge_y)
  assertApproxEq(resNom, 1.41421, 0.001, "hypot nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "hypot boundary resEdge ~= 0.707107")
  ret 0
```

---

### `powInt` (`std/math/trig.aipl`)

- **Signature**: `pub fn powInt(base: float, exp: int): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `base: float, exp: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `powInt` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `base: float = 1.0`, `exp: int = 1`; exercises core body path returning/computing `if exp < 0: 1.0 / result else: result`.

```aipl
module tests.functions.math.trig_z6_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_powInt_6(): int:
  let arg_base = 1.0
  let edge_base = 0.5
  let arg_exp = 1
  let edge_exp = 0
  let resNom = powInt(arg_base, arg_exp)
  let resEdge = powInt(edge_base, edge_exp)
  assertApproxEq(resNom, 1.0, 0.001, "powInt nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "powInt boundary resEdge ~= 1.0")
  ret 0
```

---

### `lnFloat` (`std/math/trig.aipl`)

- **Signature**: `pub fn lnFloat(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `lnFloat` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `2.0 * sum + (float(k) * 0.6931471805599453)`.

```aipl
module tests.functions.math.trig_z7_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_lnFloat_7(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = lnFloat(arg_x)
  let resEdge = lnFloat(edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "lnFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, -0.693147, 0.001, "lnFloat boundary resEdge ~= -0.693147")
  ret 0
```

---

### `expFloat` (`std/math/trig.aipl`)

- **Signature**: `pub fn expFloat(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `expFloat` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `sum`.

```aipl
module tests.functions.math.trig_z8_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_expFloat_8(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = expFloat(arg_x)
  let resEdge = expFloat(edge_x)
  assertApproxEq(resNom, 2.71828, 0.001, "expFloat nominal resNom ~= 2.71828")
  assertApproxEq(resEdge, 1.64872, 0.001, "expFloat boundary resEdge ~= 1.64872")
  ret 0
```

---

### `pow` (`std/math/trig.aipl`)

- **Signature**: `pub fn pow(base: float, exponent: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `base: float, exponent: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `pow` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `base: float = 1.0`, `exponent: float = 1.0`; exercises core body path returning/computing `expFloat(exponent * lnFloat(base))`.

```aipl
module tests.functions.math.trig_z9_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_pow_9(): int:
  let arg_base = 1.0
  let edge_base = 0.5
  let arg_exponent = 1.0
  let edge_exponent = 0.5
  let resNom = pow(arg_base, arg_exponent)
  let resEdge = pow(edge_base, edge_exponent)
  assertApproxEq(resNom, 1.0, 0.001, "pow nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.707107, 0.001, "pow boundary resEdge ~= 0.707107")
  ret 0
```

---

### `sin` (`std/math/trig.aipl`)

- **Signature**: `pub fn sin(rad: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sin` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `x - (x3 / 6.0) + (x5 / 120.0) - (x7 / 5040.0) + (x9 / 362880.0) - (x11 / 39916800.0)`.

```aipl
module tests.functions.math.trig_z10_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sin_10(): int:
  let arg_rad = 1.0
  let edge_rad = 0.5
  let resNom = sin(arg_rad)
  let resEdge = sin(edge_rad)
  assertApproxEq(resNom, 0.841471, 0.001, "sin nominal resNom ~= 0.841471")
  assertApproxEq(resEdge, 0.479426, 0.001, "sin boundary resEdge ~= 0.479426")
  ret 0
```

---

### `cos` (`std/math/trig.aipl`)

- **Signature**: `pub fn cos(rad: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `cos` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `sin(rad + HALF_PI)`.

```aipl
module tests.functions.math.trig_z11_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_cos_11(): int:
  let arg_rad = 1.0
  let edge_rad = 0.5
  let resNom = cos(arg_rad)
  let resEdge = cos(edge_rad)
  assertApproxEq(resNom, 0.540302, 0.001, "cos nominal resNom ~= 0.540302")
  assertApproxEq(resEdge, 0.877583, 0.001, "cos boundary resEdge ~= 0.877583")
  ret 0
```

---

### `tan` (`std/math/trig.aipl`)

- **Signature**: `pub fn tan(rad: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rad: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `tan` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `rad: float = 1.0`; exercises core body path returning/computing `sin(rad) / c`.

```aipl
module tests.functions.math.trig_z12_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_tan_12(): int:
  let arg_rad = 1.0
  let edge_rad = 0.5
  let resNom = tan(arg_rad)
  let resEdge = tan(edge_rad)
  assertApproxEq(resNom, 1.55741, 0.001, "tan nominal resNom ~= 1.55741")
  assertApproxEq(resEdge, 0.546302, 0.001, "tan boundary resEdge ~= 0.546302")
  ret 0
```

---

### `atan` (`std/math/trig.aipl`)

- **Signature**: `pub fn atan(z: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `z: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `atan` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `z: float = 1.0`; exercises core body path returning/computing `if neg: -res else: res`.

```aipl
module tests.functions.math.trig_z13_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_atan_13(): int:
  let arg_z = 1.0
  let edge_z = 0.5
  let resNom = atan(arg_z)
  let resEdge = atan(edge_z)
  assertApproxEq(resNom, 0.785398, 0.001, "atan nominal resNom ~= 0.785398")
  assertApproxEq(resEdge, 0.463648, 0.001, "atan boundary resEdge ~= 0.463648")
  ret 0
```

---

### `atan2` (`std/math/trig.aipl`)

- **Signature**: `pub fn atan2(y: float, x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `y: float, x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `atan2` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `y: float = 1.0`, `x: float = 1.0`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.math.trig_z14_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_atan2_14(): int:
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = atan2(arg_y, arg_x)
  let resEdge = atan2(edge_y, edge_x)
  assertApproxEq(resNom, 0.785398, 0.001, "atan2 nominal resNom ~= 0.785398")
  assertApproxEq(resEdge, 0.785398, 0.001, "atan2 boundary resEdge ~= 0.785398")
  ret 0
```

---

### `asin` (`std/math/trig.aipl`)

- **Signature**: `pub fn asin(v: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `asin` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `atan2(c, sqrt(1.0 - c * c))`.

```aipl
module tests.functions.math.trig_z15_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_asin_15(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = asin(arg_v)
  let resEdge = asin(edge_v)
  assertApproxEq(resNom, 1.5708, 0.001, "asin nominal resNom ~= 1.5708")
  assertApproxEq(resEdge, 0.523599, 0.001, "asin boundary resEdge ~= 0.523599")
  ret 0
```

---

### `acos` (`std/math/trig.aipl`)

- **Signature**: `pub fn acos(v: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `acos` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `HALF_PI - asin(v)`.

```aipl
module tests.functions.math.trig_z16_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_acos_16(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = acos(arg_v)
  let resEdge = acos(edge_v)
  assertApproxEq(resNom, 0.0, 0.001, "acos nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 1.0472, 0.001, "acos boundary resEdge ~= 1.0472")
  ret 0
```

---

### `sinh` (`std/math/trig.aipl`)

- **Signature**: `pub fn sinh(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sinh` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `0.5 * (ex - emx)`.

```aipl
module tests.functions.math.trig_z17_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sinh_17(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = sinh(arg_x)
  let resEdge = sinh(edge_x)
  assertApproxEq(resNom, 1.1752, 0.001, "sinh nominal resNom ~= 1.1752")
  assertApproxEq(resEdge, 0.521095, 0.001, "sinh boundary resEdge ~= 0.521095")
  ret 0
```

---

### `cosh` (`std/math/trig.aipl`)

- **Signature**: `pub fn cosh(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `cosh` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `0.5 * (ex + emx)`.

```aipl
module tests.functions.math.trig_z18_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_cosh_18(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = cosh(arg_x)
  let resEdge = cosh(edge_x)
  assertApproxEq(resNom, 1.54308, 0.001, "cosh nominal resNom ~= 1.54308")
  assertApproxEq(resEdge, 1.12763, 0.001, "cosh boundary resEdge ~= 1.12763")
  ret 0
```

---

### `tanh` (`std/math/trig.aipl`)

- **Signature**: `pub fn tanh(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `tanh` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `(e2x - 1.0) / (e2x + 1.0)`.

```aipl
module tests.functions.math.trig_z19_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_tanh_19(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = tanh(arg_x)
  let resEdge = tanh(edge_x)
  assertApproxEq(resNom, 0.761594, 0.001, "tanh nominal resNom ~= 0.761594")
  assertApproxEq(resEdge, 0.462117, 0.001, "tanh boundary resEdge ~= 0.462117")
  ret 0
```

---

### `sineWave` (`std/math/trig.aipl`)

- **Signature**: `pub fn sineWave(amplitude: float, frequency: float, t: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amplitude: float, frequency: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sineWave` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `amplitude: float = 1.0`, `frequency: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `amplitude * sin(TAU * frequency * t)`.

```aipl
module tests.functions.math.trig_z20_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sineWave_20(): int:
  let arg_amplitude = 1.0
  let edge_amplitude = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = sineWave(arg_amplitude, arg_frequency, arg_t)
  let resEdge = sineWave(edge_amplitude, edge_frequency, edge_t)
  assertApproxEq(resNom, 0.0, 0.001, "sineWave nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sineWave boundary resEdge ~= 0.0")
  ret 0
```

---

### `cosineWave` (`std/math/trig.aipl`)

- **Signature**: `pub fn cosineWave(amplitude: float, frequency: float, t: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amplitude: float, frequency: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `cosineWave` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `amplitude: float = 1.0`, `frequency: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `amplitude * cos(TAU * frequency * t)`.

```aipl
module tests.functions.math.trig_z21_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_cosineWave_21(): int:
  let arg_amplitude = 1.0
  let edge_amplitude = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = cosineWave(arg_amplitude, arg_frequency, arg_t)
  let resEdge = cosineWave(edge_amplitude, edge_frequency, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "cosineWave nominal resNom ~= 1.0")
  assertApproxEq(resEdge, -0.5, 0.001, "cosineWave boundary resEdge ~= -0.5")
  ret 0
```

---

### `sawtoothWave` (`std/math/trig.aipl`)

- **Signature**: `pub fn sawtoothWave(amplitude: float, frequency: float, t: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amplitude: float, frequency: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sawtoothWave` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `amplitude: float = 1.0`, `frequency: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `amplitude * (2.0 * frac - 1.0)`.

```aipl
module tests.functions.math.trig_z22_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sawtoothWave_22(): int:
  let arg_amplitude = 1.0
  let edge_amplitude = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = sawtoothWave(arg_amplitude, arg_frequency, arg_t)
  let resEdge = sawtoothWave(edge_amplitude, edge_frequency, edge_t)
  assertApproxEq(resNom, -1.0, 0.001, "sawtoothWave nominal resNom ~= -1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sawtoothWave boundary resEdge ~= 0.0")
  ret 0
```

---

### `triangleWave` (`std/math/trig.aipl`)

- **Signature**: `pub fn triangleWave(amplitude: float, frequency: float, t: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amplitude: float, frequency: float, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `triangleWave` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `amplitude: float = 1.0`, `frequency: float = 1.0`, `t: float = 0.5`; exercises core body path returning/computing `amplitude * v`.

```aipl
module tests.functions.math.trig_z23_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_triangleWave_23(): int:
  let arg_amplitude = 1.0
  let edge_amplitude = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = triangleWave(arg_amplitude, arg_frequency, arg_t)
  let resEdge = triangleWave(edge_amplitude, edge_frequency, edge_t)
  assertApproxEq(resNom, -1.0, 0.001, "triangleWave nominal resNom ~= -1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "triangleWave boundary resEdge ~= 0.5")
  ret 0
```

---

### `squareWave` (`std/math/trig.aipl`)

- **Signature**: `pub fn squareWave(amplitude: float, frequency: float, t: float, dutyCycle: float = 0.5): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `amplitude: float, frequency: float, t: float, dutyCycle: float = 0.5` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `squareWave` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `amplitude: float = 1.0`, `frequency: float = 1.0`, `t: float = 0.5`, `dutyCycle: float = 1.0`; exercises core body path returning/computing `if frac < dutyCycle: amplitude else: -amplitude`.

```aipl
module tests.functions.math.trig_z24_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_squareWave_24(): int:
  let arg_amplitude = 1.0
  let edge_amplitude = 0.5
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_dutyCycle = 1.0
  let edge_dutyCycle = 0.5
  let resNom = squareWave(arg_amplitude, arg_frequency, arg_t, arg_dutyCycle)
  let resEdge = squareWave(edge_amplitude, edge_frequency, edge_t, edge_dutyCycle)
  assertApproxEq(resNom, 1.0, 0.001, "squareWave nominal resNom ~= 1.0")
  assertApproxEq(resEdge, -0.5, 0.001, "squareWave boundary resEdge ~= -0.5")
  ret 0
```

---

### `log2Float` (`std/math/trig.aipl`)

- **Signature**: `pub fn log2Float(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `log2Float` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `lnFloat(x) / 0.6931471805599453`.

```aipl
module tests.functions.math.trig_z25_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_log2Float_25(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = log2Float(arg_x)
  let resEdge = log2Float(edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "log2Float nominal resNom ~= 0.0")
  assertApproxEq(resEdge, -1.0, 0.001, "log2Float boundary resEdge ~= -1.0")
  ret 0
```

---

### `log10Float` (`std/math/trig.aipl`)

- **Signature**: `pub fn log10Float(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `log10Float` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `lnFloat(x) / 2.302585092994046`.

```aipl
module tests.functions.math.trig_z26_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_log10Float_26(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = log10Float(arg_x)
  let resEdge = log10Float(edge_x)
  assertApproxEq(resNom, 0.0, 0.001, "log10Float nominal resNom ~= 0.0")
  assertApproxEq(resEdge, -0.30103, 0.001, "log10Float boundary resEdge ~= -0.30103")
  ret 0
```

---

### `sincFloat` (`std/math/trig.aipl`)

- **Signature**: `pub fn sincFloat(x: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `sincFloat` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `sin(x) / x`.

```aipl
module tests.functions.math.trig_z27_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_sincFloat_27(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = sincFloat(arg_x)
  let resEdge = sincFloat(edge_x)
  assertApproxEq(resNom, 0.841471, 0.001, "sincFloat nominal resNom ~= 0.841471")
  assertApproxEq(resEdge, 0.958851, 0.001, "sincFloat boundary resEdge ~= 0.958851")
  ret 0
```

---

### `wrapAngle` (`std/math/trig.aipl`)

- **Signature**: `pub fn wrapAngle(angle: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `angle: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `wrapAngle` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `angle: float = 1.0`; exercises core body path returning/computing `angle - TAU * floor((angle + PI) / TAU)`.

```aipl
module tests.functions.math.trig_z28_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_wrapAngle_28(): int:
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = wrapAngle(arg_angle)
  let resEdge = wrapAngle(edge_angle)
  assertApproxEq(resNom, 1.0, 0.001, "wrapAngle nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "wrapAngle boundary resEdge ~= 0.5")
  ret 0
```

---

### `wrapAnglePi` (`std/math/trig.aipl`)

- **Signature**: `pub fn wrapAnglePi(angle: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `angle: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `wrapAnglePi` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `angle: float = 1.0`; exercises core body path returning/computing `wrapAngle(angle)`.

```aipl
module tests.functions.math.trig_z29_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_wrapAnglePi_29(): int:
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = wrapAnglePi(arg_angle)
  let resEdge = wrapAnglePi(edge_angle)
  assertApproxEq(resNom, 1.0, 0.001, "wrapAnglePi nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "wrapAnglePi boundary resEdge ~= 0.5")
  ret 0
```

---

### `angleDeltaRad` (`std/math/trig.aipl`)

- **Signature**: `pub fn angleDeltaRad(target: float, source: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `target: float, source: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `angleDeltaRad` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `target: float = 1.0`, `source: float = 1.0`; exercises core body path returning/computing `wrapAngle(target - source)`.

```aipl
module tests.functions.math.trig_z30_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_angleDeltaRad_30(): int:
  let arg_target = 1.0
  let edge_target = 0.5
  let arg_source = 1.0
  let edge_source = 0.5
  let resNom = angleDeltaRad(arg_target, arg_source)
  let resEdge = angleDeltaRad(edge_target, edge_source)
  assertApproxEq(resNom, 0.0, 0.001, "angleDeltaRad nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "angleDeltaRad boundary resEdge ~= 0.0")
  ret 0
```

---

### `wrapAngleDeg` (`std/math/trig.aipl`)

- **Signature**: `pub fn wrapAngleDeg(deg: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `deg: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `wrapAngleDeg` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `deg: float = 1.0`; exercises core body path returning/computing `deg - 360.0 * floor((deg + 180.0) / 360.0)`.

```aipl
module tests.functions.math.trig_z31_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_wrapAngleDeg_31(): int:
  let arg_deg = 1.0
  let edge_deg = 0.5
  let resNom = wrapAngleDeg(arg_deg)
  let resEdge = wrapAngleDeg(edge_deg)
  assertApproxEq(resNom, 1.0, 0.001, "wrapAngleDeg nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "wrapAngleDeg boundary resEdge ~= 0.5")
  ret 0
```

---

### `angleDeltaDeg` (`std/math/trig.aipl`)

- **Signature**: `pub fn angleDeltaDeg(targetDeg: float, sourceDeg: float): float:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `targetDeg: float, sourceDeg: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `angleDeltaDeg` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `targetDeg: float = 1.0`, `sourceDeg: float = 1.0`; exercises core body path returning/computing `wrapAngleDeg(targetDeg - sourceDeg)`.

```aipl
module tests.functions.math.trig_z32_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_angleDeltaDeg_32(): int:
  let arg_targetDeg = 1.0
  let edge_targetDeg = 0.5
  let arg_sourceDeg = 1.0
  let edge_sourceDeg = 0.5
  let resNom = angleDeltaDeg(arg_targetDeg, arg_sourceDeg)
  let resEdge = angleDeltaDeg(edge_targetDeg, edge_sourceDeg)
  assertApproxEq(resNom, 0.0, 0.001, "angleDeltaDeg nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "angleDeltaDeg boundary resEdge ~= 0.0")
  ret 0
```

---

### `wrapAngleByte` (`std/math/trig.aipl`)

- **Signature**: `pub fn wrapAngleByte(b: int): int:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `wrapAngleByte` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `b: int = 1`; exercises core body path returning/computing `m`.

```aipl
module tests.functions.math.trig_z33_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_wrapAngleByte_33(): int:
  let arg_b = 4
  let edge_b = 1
  let resNom = wrapAngleByte(arg_b)
  let resEdge = wrapAngleByte(edge_b)
  assertEqInt(resNom, 4, "wrapAngleByte nominal resNom == 4")
  assertEqInt(resEdge, 1, "wrapAngleByte boundary resEdge == 1")
  ret 0
```

---

### `angleDeltaByte` (`std/math/trig.aipl`)

- **Signature**: `pub fn angleDeltaByte(targetByte: int, sourceByte: int): int:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `targetByte: int, sourceByte: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `angleDeltaByte` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `targetByte: int = 1`, `sourceByte: int = 1`; exercises core body path returning/computing `diff`.

```aipl
module tests.functions.math.trig_z34_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_angleDeltaByte_34(): int:
  let arg_targetByte = 4
  let edge_targetByte = 1
  let arg_sourceByte = 4
  let edge_sourceByte = 1
  let resNom = angleDeltaByte(arg_targetByte, arg_sourceByte)
  let resEdge = angleDeltaByte(edge_targetByte, edge_sourceByte)
  assertEqInt(resNom, 0, "angleDeltaByte nominal resNom == 0")
  assertEqInt(resEdge, 0, "angleDeltaByte boundary resEdge == 0")
  ret 0
```

---

### `stepAngleByte` (`std/math/trig.aipl`)

- **Signature**: `pub fn stepAngleByte(currentByte: int, targetByte: int, maxStep: int): int:`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `currentByte: int, targetByte: int, maxStep: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `stepAngleByte` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `currentByte: int = 1`, `targetByte: int = 1`, `maxStep: int = 1`; exercises core body path returning/computing `wrapAngleByte(currentByte + step)`.

```aipl
module tests.functions.math.trig_z35_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_stepAngleByte_35(): int:
  let arg_currentByte = 4
  let edge_currentByte = 1
  let arg_targetByte = 4
  let edge_targetByte = 1
  let arg_maxStep = 4
  let edge_maxStep = 1
  let resNom = stepAngleByte(arg_currentByte, arg_targetByte, arg_maxStep)
  let resEdge = stepAngleByte(edge_currentByte, edge_targetByte, edge_maxStep)
  assertEqInt(resNom, 4, "stepAngleByte nominal resNom == 4")
  assertEqInt(resEdge, 1, "stepAngleByte boundary resEdge == 1")
  ret 0
```

---

### `vec2RotateFixed` (`std/math/trig.aipl`)

- **Signature**: `pub fn vec2RotateFixed(x: int, y: int, angleBytes: int): (int, int):`
- **Import**: `import * from "std/math/trig"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int, angleBytes: int` | **Returns**: `(int, int)`
- **Unit Test**: `tests/functions/math/trig_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify transcendental/angular function `vec2RotateFixed` at cardinal angles (`0, pi/6, pi/4, pi/2, pi`), wrap-around seams (`+-pi`, `0..360` deg, `0..255` byte angles), and Pythagorean/inverse identities within `eps = 1e-6`. Concrete nominal inputs: `x: int = 1`, `y: int = 1`, `angleBytes: int): (int = int): (int()`, `int: any = 42`; exercises core body path returning/computing `(roundFloat(rx), roundFloat(ry))`.

```aipl
module tests.functions.math.trig_z36_test
import * from "std/math/trig"
import { PI, TAU, HALF_PI, DEG2RAD, RAD2DEG, absFloat, roundFloat, remEuclid, floor } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_trig_vec2RotateFixed_36(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_angleBytes = 4
  let edge_angleBytes = 1
  let resNom = vec2RotateFixed(arg_x, arg_y, arg_angleBytes)
  let resEdge = vec2RotateFixed(edge_x, edge_y, edge_angleBytes)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0, 1, "vec2RotateFixed nominal n_t0 == 1")
  assertEqInt(e_t0, 0, "vec2RotateFixed boundary e_t0 == 0")
  ret 0
```

---

### `Vec2.new` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn Vec2.new(x: float, y: float): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `Vec2.new` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `Vec2(x = x, y = y)`.

```aipl
module tests.functions.math.vec_math_z1_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_new_1(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let resNom = Vec2.new(arg_x, arg_y)
  let resEdge = Vec2.new(edge_x, edge_y)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vec2.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vec2.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `Vector2.new` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn Vector2.new(x: float, y: float): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `Vector2.new` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`; exercises core body path returning/computing `Vector2(x = x, y = y)`.

```aipl
module tests.functions.math.vec_math_z2_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_new_2(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let resNom = Vector2.new(arg_x, arg_y)
  let resEdge = Vector2.new(edge_x, edge_y)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vector2.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vector2.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `toVector2` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) toVector2(): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `toVector2` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vector2(x = self.x, y = self.y)`.

```aipl
module tests.functions.math.vec_math_z3_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_toVector2_3(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.toVector2()
  let resEdge = edge_self.toVector2()
  assertApproxEq(resNom.x, 1.0, 0.001, "toVector2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "toVector2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `toVec2` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) toVec2(): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `none` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `toVec2` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = self.x, y = self.y)`.

```aipl
module tests.functions.math.vec_math_z4_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_toVec2_4(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.toVec2()
  let resEdge = edge_self.toVec2()
  assertApproxEq(resNom.x, 1.0, 0.001, "toVec2 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "toVec2 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `add` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) add(other: Vec2): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `add` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = self.x + other.x, y = self.y + other.y)`.

```aipl
module tests.functions.math.vec_math_z5_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_add_5(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.x, 2.0, 0.001, "add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) sub(other: Vec2): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `sub` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = self.x - other.x, y = self.y - other.y)`.

```aipl
module tests.functions.math.vec_math_z6_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_sub_6(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `scale` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) scale(s: float): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `s: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `scale` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vec2(x = self.x * s, y = self.y * s)`.

```aipl
module tests.functions.math.vec_math_z7_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_scale_7(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = recv_self.scale(arg_s)
  let resEdge = edge_self.scale(edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `dot` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) dot(other: Vec2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dot` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.x * other.x + self.y * other.y`.

```aipl
module tests.functions.math.vec_math_z8_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_dot_8(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.dot(arg_other)
  let resEdge = edge_self.dot(edge_other)
  assertApproxEq(resNom, 2.0, 0.001, "dot nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "dot boundary resEdge ~= 0.5")
  ret 0
```

---

### `cross` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) cross(other: Vec2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `cross` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.x * other.y - self.y * other.x`.

```aipl
module tests.functions.math.vec_math_z9_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_cross_9(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.cross(arg_other)
  let resEdge = edge_self.cross(edge_other)
  assertApproxEq(resNom, 0.0, 0.001, "cross nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "cross boundary resEdge ~= 0.0")
  ret 0
```

---

### `lenSq` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) lenSq(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lenSq` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.x * self.x + self.y * self.y`.

```aipl
module tests.functions.math.vec_math_z10_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_lenSq_10(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.lenSq()
  let resEdge = edge_self.lenSq()
  assertApproxEq(resNom, 2.0, 0.001, "lenSq nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "lenSq boundary resEdge ~= 0.5")
  ret 0
```

---

### `len` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) len(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `len` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `sqrt(self.lenSq())`.

```aipl
module tests.functions.math.vec_math_z11_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_len_11(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertApproxEq(resNom, 1.41421, 0.001, "len nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "len boundary resEdge ~= 0.707107")
  ret 0
```

---

### `length` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) length(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `length` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.len()`.

```aipl
module tests.functions.math.vec_math_z12_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_length_12(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.length()
  let resEdge = edge_self.length()
  assertApproxEq(resNom, 1.41421, 0.001, "length nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "length boundary resEdge ~= 0.707107")
  ret 0
```

---

### `norm` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) norm(): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `norm` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vec2(x = 0.0, y = 0.0)`.

```aipl
module tests.functions.math.vec_math_z13_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_norm_13(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.norm()
  let resEdge = edge_self.norm()
  assertApproxEq(resNom.x, 0.707107, 0.001, "norm nominal resNom.x ~= 0.707107")
  assertApproxEq(resEdge.x, 0.707107, 0.001, "norm boundary resEdge.x ~= 0.707107")
  ret 0
```

---

### `normalize` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) normalize(): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `none` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `normalize` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.norm()`.

```aipl
module tests.functions.math.vec_math_z14_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_normalize_14(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.normalize()
  let resEdge = edge_self.normalize()
  assertApproxEq(resNom.x, 0.707107, 0.001, "normalize nominal resNom.x ~= 0.707107")
  assertApproxEq(resEdge.x, 0.707107, 0.001, "normalize boundary resEdge.x ~= 0.707107")
  ret 0
```

---

### `dist` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) dist(other: Vec2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dist` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.sub(other).len()`.

```aipl
module tests.functions.math.vec_math_z15_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_dist_15(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let resNom = recv_self.dist(arg_other)
  let resEdge = edge_self.dist(edge_other)
  assertApproxEq(resNom, 0.0, 0.001, "dist nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "dist boundary resEdge ~= 0.0")
  ret 0
```

---

### `lerp` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec2) lerp(other: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec2` | **Parameters**: `other: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lerp` (`self: Vec2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec2 = Vec2(x = 1.0, y = 1.0)`, `other: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(x = self.x + (other.x - self.x) * t, y = self.y + (other.y - self.y) * t)`.

```aipl
module tests.functions.math.vec_math_z16_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec2_lerp_16(): int:
  let recv_self = Vec2(x = 1.0, y = 1.0)
  let edge_self = Vec2(x = 0.5, y = 0.5)
  let arg_other = Vec2(x = 1.0, y = 1.0)
  let edge_other = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = recv_self.lerp(arg_other, arg_t)
  let resEdge = edge_self.lerp(edge_other, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "lerp nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "lerp boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `add` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) add(other: Vector2): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `other: Vector2` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `add` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`, `other: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vector2(x = self.x + other.x, y = self.y + other.y)`.

```aipl
module tests.functions.math.vec_math_z17_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_add_17(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let arg_other = Vector2(x = 1.0, y = 1.0)
  let edge_other = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.x, 2.0, 0.001, "add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) sub(other: Vector2): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `other: Vector2` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `sub` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`, `other: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vector2(x = self.x - other.x, y = self.y - other.y)`.

```aipl
module tests.functions.math.vec_math_z18_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_sub_18(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let arg_other = Vector2(x = 1.0, y = 1.0)
  let edge_other = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `scale` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) scale(s: float): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `s: float` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `scale` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vector2(x = self.x * s, y = self.y * s)`.

```aipl
module tests.functions.math.vec_math_z19_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_scale_19(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = recv_self.scale(arg_s)
  let resEdge = edge_self.scale(edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `dot` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) dot(other: Vector2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `other: Vector2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dot` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`, `other: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `self.x * other.x + self.y * other.y`.

```aipl
module tests.functions.math.vec_math_z20_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_dot_20(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let arg_other = Vector2(x = 1.0, y = 1.0)
  let edge_other = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.dot(arg_other)
  let resEdge = edge_self.dot(edge_other)
  assertApproxEq(resNom, 2.0, 0.001, "dot nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "dot boundary resEdge ~= 0.5")
  ret 0
```

---

### `length` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) length(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `length` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `sqrt(self.x * self.x + self.y * self.y)`.

```aipl
module tests.functions.math.vec_math_z21_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_length_21(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.length()
  let resEdge = edge_self.length()
  assertApproxEq(resNom, 1.41421, 0.001, "length nominal resNom ~= 1.41421")
  assertApproxEq(resEdge, 0.707107, 0.001, "length boundary resEdge ~= 0.707107")
  ret 0
```

---

### `normalize` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector2) normalize(): Vector2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector2` | **Parameters**: `none` | **Returns**: `Vector2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `normalize` (`self: Vector2`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector2 = Vector2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Vector2(x = 0.0, y = 0.0)`.

```aipl
module tests.functions.math.vec_math_z22_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector2_normalize_22(): int:
  let recv_self = Vector2(x = 1.0, y = 1.0)
  let edge_self = Vector2(x = 0.5, y = 0.5)
  let resNom = recv_self.normalize()
  let resEdge = edge_self.normalize()
  assertApproxEq(resNom.x, 0.707107, 0.001, "normalize nominal resNom.x ~= 0.707107")
  assertApproxEq(resEdge.x, 0.707107, 0.001, "normalize boundary resEdge.x ~= 0.707107")
  ret 0
```

---

### `Vec3.new` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn Vec3.new(x: float, y: float, z: float): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `Vec3.new` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`; exercises core body path returning/computing `Vec3(x = x, y = y, z = z)`.

```aipl
module tests.functions.math.vec_math_z23_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_new_23(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let arg_z = 1.0
  let edge_z = 0.0
  let resNom = Vec3.new(arg_x, arg_y, arg_z)
  let resEdge = Vec3.new(edge_x, edge_y, edge_z)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vec3.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vec3.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `Vector3.new` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn Vector3.new(x: float, y: float, z: float): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `Vector3.new` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`; exercises core body path returning/computing `Vector3(x = x, y = y, z = z)`.

```aipl
module tests.functions.math.vec_math_z24_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_new_24(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let arg_z = 1.0
  let edge_z = 0.0
  let resNom = Vector3.new(arg_x, arg_y, arg_z)
  let resEdge = Vector3.new(edge_x, edge_y, edge_z)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vector3.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vector3.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `add` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) add(other: Vec3): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `add` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(x = self.x + other.x, y = self.y + other.y, z = self.z + other.z)`.

```aipl
module tests.functions.math.vec_math_z25_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_add_25(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.x, 2.0, 0.001, "add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) sub(other: Vec3): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `sub` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(x = self.x - other.x, y = self.y - other.y, z = self.z - other.z)`.

```aipl
module tests.functions.math.vec_math_z26_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_sub_26(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `scale` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) scale(s: float): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `s: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `scale` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vec3(x = self.x * s, y = self.y * s, z = self.z * s)`.

```aipl
module tests.functions.math.vec_math_z27_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_scale_27(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = recv_self.scale(arg_s)
  let resEdge = edge_self.scale(edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `dot` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) dot(other: Vec3): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dot` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.x * other.x + self.y * other.y + self.z * other.z`.

```aipl
module tests.functions.math.vec_math_z28_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_dot_28(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.dot(arg_other)
  let resEdge = edge_self.dot(edge_other)
  assertApproxEq(resNom, 3.0, 0.001, "dot nominal resNom ~= 3.0")
  assertApproxEq(resEdge, 0.75, 0.001, "dot boundary resEdge ~= 0.75")
  ret 0
```

---

### `cross` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) cross(other: Vec3): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `cross` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(`.

```aipl
module tests.functions.math.vec_math_z29_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_cross_29(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.cross(arg_other)
  let resEdge = edge_self.cross(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "cross nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "cross boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `lenSq` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) lenSq(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lenSq` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.x * self.x + self.y * self.y + self.z * self.z`.

```aipl
module tests.functions.math.vec_math_z30_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_lenSq_30(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.lenSq()
  let resEdge = edge_self.lenSq()
  assertApproxEq(resNom, 3.0, 0.001, "lenSq nominal resNom ~= 3.0")
  assertApproxEq(resEdge, 0.75, 0.001, "lenSq boundary resEdge ~= 0.75")
  ret 0
```

---

### `len` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) len(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `len` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `sqrt(self.lenSq())`.

```aipl
module tests.functions.math.vec_math_z31_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_len_31(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertApproxEq(resNom, 1.73205, 0.001, "len nominal resNom ~= 1.73205")
  assertApproxEq(resEdge, 0.866025, 0.001, "len boundary resEdge ~= 0.866025")
  ret 0
```

---

### `length` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) length(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `length` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.len()`.

```aipl
module tests.functions.math.vec_math_z32_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_length_32(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.length()
  let resEdge = edge_self.length()
  assertApproxEq(resNom, 1.73205, 0.001, "length nominal resNom ~= 1.73205")
  assertApproxEq(resEdge, 0.866025, 0.001, "length boundary resEdge ~= 0.866025")
  ret 0
```

---

### `norm` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) norm(): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `none` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `norm` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(x = 0.0, y = 0.0, z = 0.0)`.

```aipl
module tests.functions.math.vec_math_z33_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_norm_33(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.norm()
  let resEdge = edge_self.norm()
  assertApproxEq(resNom.x, 0.57735, 0.001, "norm nominal resNom.x ~= 0.57735")
  assertApproxEq(resEdge.x, 0.57735, 0.001, "norm boundary resEdge.x ~= 0.57735")
  ret 0
```

---

### `normalize` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) normalize(): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `none` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `normalize` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.norm()`.

```aipl
module tests.functions.math.vec_math_z34_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_normalize_34(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.normalize()
  let resEdge = edge_self.normalize()
  assertApproxEq(resNom.x, 0.57735, 0.001, "normalize nominal resNom.x ~= 0.57735")
  assertApproxEq(resEdge.x, 0.57735, 0.001, "normalize boundary resEdge.x ~= 0.57735")
  ret 0
```

---

### `distanceSquared` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) distanceSquared(other: Vec3): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `distanceSquared` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.sub(other).lenSq()`.

```aipl
module tests.functions.math.vec_math_z35_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_distanceSquared_35(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.distanceSquared(arg_other)
  let resEdge = edge_self.distanceSquared(edge_other)
  assertApproxEq(resNom, 0.0, 0.001, "distanceSquared nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distanceSquared boundary resEdge ~= 0.0")
  ret 0
```

---

### `dist` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) dist(other: Vec3): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dist` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.sub(other).len()`.

```aipl
module tests.functions.math.vec_math_z36_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_dist_36(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.dist(arg_other)
  let resEdge = edge_self.dist(edge_other)
  assertApproxEq(resNom, 0.0, 0.001, "dist nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "dist boundary resEdge ~= 0.0")
  ret 0
```

---

### `lerp` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec3) lerp(other: Vec3, t: float): Vec3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec3` | **Parameters**: `other: Vec3, t: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lerp` (`self: Vec3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec3(`.

```aipl
module tests.functions.math.vec_math_z37_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec3_lerp_37(): int:
  let recv_self = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = recv_self.lerp(arg_other, arg_t)
  let resEdge = edge_self.lerp(edge_other, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "lerp nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "lerp boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `add` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) add(other: Vector3): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `other: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `add` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = self.x + other.x, y = self.y + other.y, z = self.z + other.z)`.

```aipl
module tests.functions.math.vec_math_z38_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_add_38(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.x, 2.0, 0.001, "add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) sub(other: Vector3): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `other: Vector3` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `sub` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = self.x - other.x, y = self.y - other.y, z = self.z - other.z)`.

```aipl
module tests.functions.math.vec_math_z39_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_sub_39(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `scale` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) scale(s: float): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `s: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `scale` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vector3(x = self.x * s, y = self.y * s, z = self.z * s)`.

```aipl
module tests.functions.math.vec_math_z40_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_scale_40(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = recv_self.scale(arg_s)
  let resEdge = edge_self.scale(edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `dot` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) dot(other: Vector3): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `other: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dot` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `self.x * other.x + self.y * other.y + self.z * other.z`.

```aipl
module tests.functions.math.vec_math_z41_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_dot_41(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.dot(arg_other)
  let resEdge = edge_self.dot(edge_other)
  assertApproxEq(resNom, 3.0, 0.001, "dot nominal resNom ~= 3.0")
  assertApproxEq(resEdge, 0.75, 0.001, "dot boundary resEdge ~= 0.75")
  ret 0
```

---

### `length` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) length(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `length` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `sqrt(self.x * self.x + self.y * self.y + self.z * self.z)`.

```aipl
module tests.functions.math.vec_math_z42_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_length_42(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.length()
  let resEdge = edge_self.length()
  assertApproxEq(resNom, 1.73205, 0.001, "length nominal resNom ~= 1.73205")
  assertApproxEq(resEdge, 0.866025, 0.001, "length boundary resEdge ~= 0.866025")
  ret 0
```

---

### `normalize` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) normalize(): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `none` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `normalize` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vector3(x = 0.0, y = 0.0, z = 0.0)`.

```aipl
module tests.functions.math.vec_math_z43_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_normalize_43(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.normalize()
  let resEdge = edge_self.normalize()
  assertApproxEq(resNom.x, 0.57735, 0.001, "normalize nominal resNom.x ~= 0.57735")
  assertApproxEq(resEdge.x, 0.57735, 0.001, "normalize boundary resEdge.x ~= 0.57735")
  ret 0
```

---

### `distanceSquared` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) distanceSquared(other: Vector3): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `other: Vector3` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `distanceSquared` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `dx * dx + dy * dy + dz * dz`.

```aipl
module tests.functions.math.vec_math_z44_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_distanceSquared_44(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = recv_self.distanceSquared(arg_other)
  let resEdge = edge_self.distanceSquared(edge_other)
  assertApproxEq(resNom, 0.0, 0.001, "distanceSquared nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distanceSquared boundary resEdge ~= 0.0")
  ret 0
```

---

### `lerp` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vector3) lerp(other: Vector3, t: float): Vector3:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vector3` | **Parameters**: `other: Vector3, t: float` | **Returns**: `Vector3`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lerp` (`self: Vector3`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `other: Vector3 = Vector3(x = 1.0, y = 1.0, z = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vector3(`.

```aipl
module tests.functions.math.vec_math_z45_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vector3_lerp_45(): int:
  let recv_self = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_self = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_other = Vector3(x = 1.0, y = 1.0, z = 1.0)
  let edge_other = Vector3(x = 0.5, y = 0.5, z = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = recv_self.lerp(arg_other, arg_t)
  let resEdge = edge_self.lerp(edge_other, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "lerp nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "lerp boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `Vec4.new` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn Vec4.new(x: float, y: float, z: float, w: float): Vec4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float, w: float` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `Vec4.new` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`, `w: float = 1.0`; exercises core body path returning/computing `Vec4(x = x, y = y, z = z, w = w)`.

```aipl
module tests.functions.math.vec_math_z46_test
import * from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_new_46(): int:
  let arg_x = 1.0
  let edge_x = 0.0
  let arg_y = 1.0
  let edge_y = 0.0
  let arg_z = 1.0
  let edge_z = 0.0
  let arg_w = 1.0
  let edge_w = 0.0
  let resNom = Vec4.new(arg_x, arg_y, arg_z, arg_w)
  let resEdge = Vec4.new(edge_x, edge_y, edge_z, edge_w)
  assertApproxEq(resNom.x, 1.0, 0.001, "Vec4.new nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "Vec4.new boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `add` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) add(other: Vec4): Vec4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `other: Vec4` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `add` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `other: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Vec4(x = self.x + other.x, y = self.y + other.y, z = self.z + other.z, w = self.w + other.w)`.

```aipl
module tests.functions.math.vec_math_z47_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_add_47(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_other = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_other = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertApproxEq(resNom.x, 2.0, 0.001, "add nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "add boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `sub` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) sub(other: Vec4): Vec4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `other: Vec4` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `sub` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `other: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Vec4(x = self.x - other.x, y = self.y - other.y, z = self.z - other.z, w = self.w - other.w)`.

```aipl
module tests.functions.math.vec_math_z48_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_sub_48(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_other = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_other = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertApproxEq(resNom.x, 0.0, 0.001, "sub nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sub boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `scale` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) scale(s: float): Vec4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `s: float` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `scale` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `s: float = 1.0`; exercises core body path returning/computing `Vec4(x = self.x * s, y = self.y * s, z = self.z * s, w = self.w * s)`.

```aipl
module tests.functions.math.vec_math_z49_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_scale_49(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_s = 1.0
  let edge_s = 0.5
  let resNom = recv_self.scale(arg_s)
  let resEdge = edge_self.scale(edge_s)
  assertApproxEq(resNom.x, 1.0, 0.001, "scale nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.25, 0.001, "scale boundary resEdge.x ~= 0.25")
  ret 0
```

---

### `dot` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) dot(other: Vec4): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `other: Vec4` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `dot` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `other: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `self.x * other.x + self.y * other.y + self.z * other.z + self.w * other.w`.

```aipl
module tests.functions.math.vec_math_z50_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_dot_50(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_other = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_other = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.dot(arg_other)
  let resEdge = edge_self.dot(edge_other)
  assertApproxEq(resNom, 7.0, 0.001, "dot nominal resNom ~= 7.0")
  assertApproxEq(resEdge, 1.75, 0.001, "dot boundary resEdge ~= 1.75")
  ret 0
```

---

### `lenSq` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) lenSq(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `lenSq` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `self.dot(self)`.

```aipl
module tests.functions.math.vec_math_z51_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_lenSq_51(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.lenSq()
  let resEdge = edge_self.lenSq()
  assertApproxEq(resNom, 7.0, 0.001, "lenSq nominal resNom ~= 7.0")
  assertApproxEq(resEdge, 1.75, 0.001, "lenSq boundary resEdge ~= 1.75")
  ret 0
```

---

### `len` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) len(): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `len` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `sqrt(self.lenSq())`.

```aipl
module tests.functions.math.vec_math_z52_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_len_52(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.len()
  let resEdge = edge_self.len()
  assertApproxEq(resNom, 2.64575, 0.001, "len nominal resNom ~= 2.64575")
  assertApproxEq(resEdge, 1.32288, 0.001, "len boundary resEdge ~= 1.32288")
  ret 0
```

---

### `norm` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn (self: Vec4) norm(): Vec4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `self: Vec4` | **Parameters**: `none` | **Returns**: `Vec4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `norm` (`self: Vec4`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: receiver `recvObj: Vec4 = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `Vec4(x = 0.0, y = 0.0, z = 0.0, w = 0.0)`.

```aipl
module tests.functions.math.vec_math_z53_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_Vec4_norm_53(): int:
  let recv_self = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_self = Vec4(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = recv_self.norm()
  let resEdge = edge_self.norm()
  assertApproxEq(resNom.x, 0.377964, 0.001, "norm nominal resNom.x ~= 0.377964")
  assertApproxEq(resEdge.x, 0.377964, 0.001, "norm boundary resEdge.x ~= 0.377964")
  ret 0
```

---

### `distSq2D` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn distSq2D(x1: int, y1: int, x2: int, y2: int): int:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: int, y1: int, x2: int, y2: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `distSq2D` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x1: int = 1`, `y1: int = 1`, `x2: int = 1`, `y2: int = 1`; exercises core body path returning/computing `dx * dx + dy * dy`.

```aipl
module tests.functions.math.vec_math_z54_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_distSq2D_54(): int:
  let arg_x1 = 1
  let edge_x1 = 0
  let arg_y1 = 1
  let edge_y1 = 0
  let arg_x2 = 1
  let edge_x2 = 0
  let arg_y2 = 1
  let edge_y2 = 0
  let resNom = distSq2D(arg_x1, arg_y1, arg_x2, arg_y2)
  let resEdge = distSq2D(edge_x1, edge_y1, edge_x2, edge_y2)
  assertEqInt(resNom, 0, "distSq2D nominal resNom == 0")
  assertEqInt(resEdge, 0, "distSq2D boundary resEdge == 0")
  ret 0
```

---

### `inDisk2D` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn inDisk2D(x: int, y: int, cx: int, cy: int, radius: int): bool:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: int, y: int, cx: int, cy: int, radius: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `inDisk2D` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: int = 1`, `y: int = 1`, `cx: int = 1`, `cy: int = 1`, `radius: int = 1`; exercises core body path returning/computing `distSq2D(x, y, cx, cy) <= (radius * radius)`.

```aipl
module tests.functions.math.vec_math_z55_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_inDisk2D_55(): int:
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let arg_radius = 2
  let edge_radius = 0
  let resNom = inDisk2D(arg_x, arg_y, arg_cx, arg_cy, arg_radius)
  let resEdge = inDisk2D(edge_x, edge_y, edge_cx, edge_cy, edge_radius)
  assert(resNom == true, "inDisk2D nominal resNom == true")
  assert(resEdge == true, "inDisk2D boundary resEdge == true")
  ret 0
```

---

### `distSq2Df` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn distSq2Df(x1: float, y1: float, x2: float, y2: float): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, x2: float, y2: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `distSq2Df` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`; exercises core body path returning/computing `dx * dx + dy * dy`.

```aipl
module tests.functions.math.vec_math_z56_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_distSq2Df_56(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let resNom = distSq2Df(arg_x1, arg_y1, arg_x2, arg_y2)
  let resEdge = distSq2Df(edge_x1, edge_y1, edge_x2, edge_y2)
  assertApproxEq(resNom, 0.0, 0.001, "distSq2Df nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distSq2Df boundary resEdge ~= 0.0")
  ret 0
```

---

### `inDisk2Df` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn inDisk2Df(x: float, y: float, cx: float, cy: float, radius: float): bool:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, cx: float, cy: float, radius: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `inDisk2Df` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`; exercises core body path returning/computing `distSq2Df(x, y, cx, cy) <= (radius * radius)`.

```aipl
module tests.functions.math.vec_math_z57_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_inDisk2Df_57(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = inDisk2Df(arg_x, arg_y, arg_cx, arg_cy, arg_radius)
  let resEdge = inDisk2Df(edge_x, edge_y, edge_cx, edge_cy, edge_radius)
  assert(resNom == true, "inDisk2Df nominal resNom == true")
  assert(resEdge == true, "inDisk2Df boundary resEdge == true")
  ret 0
```

---

### `distSq2DFloat` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn distSq2DFloat(x1: float, y1: float, x2: float, y2: float): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x1: float, y1: float, x2: float, y2: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `distSq2DFloat` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x1: float = 1.0`, `y1: float = 1.0`, `x2: float = 1.0`, `y2: float = 1.0`; exercises core body path returning/computing `distSq2Df(x1, y1, x2, y2)`.

```aipl
module tests.functions.math.vec_math_z58_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_distSq2DFloat_58(): int:
  let arg_x1 = 1.0
  let edge_x1 = 0.5
  let arg_y1 = 1.0
  let edge_y1 = 0.5
  let arg_x2 = 1.0
  let edge_x2 = 0.5
  let arg_y2 = 1.0
  let edge_y2 = 0.5
  let resNom = distSq2DFloat(arg_x1, arg_y1, arg_x2, arg_y2)
  let resEdge = distSq2DFloat(edge_x1, edge_y1, edge_x2, edge_y2)
  assertApproxEq(resNom, 0.0, 0.001, "distSq2DFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "distSq2DFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `inDisk2DFloat` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn inDisk2DFloat(x: float, y: float, cx: float, cy: float, radius: float): bool:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, cx: float, cy: float, radius: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `inDisk2DFloat` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `cx: float = 1.0`, `cy: float = 1.0`, `radius: float = 1.0`; exercises core body path returning/computing `inDisk2Df(x, y, cx, cy, radius)`.

```aipl
module tests.functions.math.vec_math_z59_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_inDisk2DFloat_59(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_cx = 1.0
  let edge_cx = 0.5
  let arg_cy = 1.0
  let edge_cy = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = inDisk2DFloat(arg_x, arg_y, arg_cx, arg_cy, arg_radius)
  let resEdge = inDisk2DFloat(edge_x, edge_y, edge_cx, edge_cy, edge_radius)
  assert(resNom == true, "inDisk2DFloat nominal resNom == true")
  assert(resEdge == true, "inDisk2DFloat boundary resEdge == true")
  ret 0
```

---

### `vec4` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn vec4(x: float, y: float, z: float, w: float): Vector4:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float, w: float` | **Returns**: `Vector4`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `vec4` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`, `w: float = 1.0`; exercises core body path returning/computing `Vector4(x = x, y = y, z = z, w = w)`.

```aipl
module tests.functions.math.vec_math_z60_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_vec4_60(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_z = 1.0
  let edge_z = 0.5
  let arg_w = 2.0
  let edge_w = 1.0
  let resNom = vec4(arg_x, arg_y, arg_z, arg_w)
  let resEdge = vec4(edge_x, edge_y, edge_z, edge_w)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec4 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec4 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec2Lerp` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn vec2Lerp(a: Vec2, b: Vec2, t: float): Vec2:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2, t: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_029_math_vec2_vec3_vec4_cli.aipl`
- **Behavioral Summary**: Verify vector operation `vec2Lerp` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `Vec2(x = a.x + (b.x - a.x) * t, y = a.y + (b.y - a.y) * t)`.

```aipl
module tests.functions.math.vec_math_z61_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_vec2Lerp_61(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = vec2Lerp(arg_a, arg_b, arg_t)
  let resEdge = vec2Lerp(edge_a, edge_b, edge_t)
  assertApproxEq(resNom.x, 1.0, 0.001, "vec2Lerp nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "vec2Lerp boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `vec2Distance` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn vec2Distance(a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_027_math_consts_and_num_theory_cli.aipl`
- **Behavioral Summary**: Verify vector operation `vec2Distance` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `sqrt(distSq2Df(a.x, a.y, b.x, b.y))`.

```aipl
module tests.functions.math.vec_math_z62_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_vec2Distance_62(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2Distance(arg_a, arg_b)
  let resEdge = vec2Distance(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec2Distance nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec2Distance boundary resEdge ~= 0.0")
  ret 0
```

---

### `vec2DistanceSquared` (`std/math/vec_math.aipl`)

- **Signature**: `pub fn vec2DistanceSquared(a: Vec2, b: Vec2): float:`
- **Import**: `import * from "std/math/vec_math"` (or barrel `import * from "std/math/math_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Vec2, b: Vec2` | **Returns**: `float`
- **Unit Test**: `tests/functions/math/vec_math_test.aipl` | **Example**: `examples/ex_028_math_trig_and_spherical_cli.aipl`
- **Behavioral Summary**: Verify vector operation `vec2DistanceSquared` (`free fn`) component-wise accuracy, dot/cross orthogonality, Euclidean norm non-negativity, and zero-vector normalization safety. Concrete nominal inputs: `a: Vec2 = Vec2(x = 1.0, y = 1.0)`, `b: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `distSq2Df(a.x, a.y, b.x, b.y)`.

```aipl
module tests.functions.math.vec_math_z63_test
import * from "std/math/vec_math"
import { sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vec_math_vec2DistanceSquared_63(): int:
  let arg_a = Vec2(x = 1.0, y = 1.0)
  let edge_a = Vec2(x = 0.5, y = 0.5)
  let arg_b = Vec2(x = 1.0, y = 1.0)
  let edge_b = Vec2(x = 0.5, y = 0.5)
  let resNom = vec2DistanceSquared(arg_a, arg_b)
  let resEdge = vec2DistanceSquared(edge_a, edge_b)
  assertApproxEq(resNom, 0.0, 0.001, "vec2DistanceSquared nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "vec2DistanceSquared boundary resEdge ~= 0.0")
  ret 0
```
