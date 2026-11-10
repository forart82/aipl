[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 28: `particle` API Reference

> Complete API reference manual for AIPL standard library domain `particle` (52 callable functions & methods across ["std/particle/affector.aipl", "std/particle/curve_prop.aipl", "std/particle/emitter2d.aipl", "std/particle/emitter3d.aipl", "std/particle/gpu_compute_particles.aipl", "std/particle/particle_mod.aipl", "std/particle/ribbon_trail.aipl", "std/particle/sub_emitter.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `particle`
- **Target Source Modules**: ["std/particle/affector.aipl", "std/particle/curve_prop.aipl", "std/particle/emitter2d.aipl", "std/particle/emitter3d.aipl", "std/particle/gpu_compute_particles.aipl", "std/particle/particle_mod.aipl", "std/particle/ribbon_trail.aipl", "std/particle/sub_emitter.aipl"]
- **Total Callable Functions & Methods**: 52
- **Total Data Types (`struct` & `enum`)**: 18
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(18 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ParticleAffector` | `pub struct` | `std/particle/affector.aipl` | `affectorType: int`, `strength: float`, `center: Vec3`, `direction: Vec3`, `falloffDistance: float`, `frequency: float` | `ParticleAffector(affectorType, strength, center, direction, falloffDistance, frequency)` |
| `CurveKeyframe` | `pub struct` | `std/particle/curve_prop.aipl` | `time: float`, `value: float`, `inTangent: float`, `outTangent: float` | `CurveKeyframe(time, value, inTangent, outTangent)` |
| `KeyframeCurve` | `pub struct` | `std/particle/curve_prop.aipl` | `keyframes: [CurveKeyframe]` | `KeyframeCurve(keyframes)` |
| `ColorStop` | `pub struct` | `std/particle/curve_prop.aipl` | `time: float`, `color: ColorRgba8` | `ColorStop(time, color)` |
| `ColorGradient` | `pub struct` | `std/particle/curve_prop.aipl` | `stops: [ColorStop]` | `ColorGradient(stops)` |
| `MinMaxCurveProperty` | `pub struct` | `std/particle/curve_prop.aipl` | `mode: int`, `constantMin: float`, `constantMax: float`, `curveMin: KeyframeCurve`, `curveMax: KeyframeCurve` | `MinMaxCurveProperty(mode, constantMin, constantMax, curveMin, curveMax)` |
| `Particle2D` | `pub struct` | `std/particle/emitter2d.aipl` | `pos: Vec2`, `vel: Vec2`, `startColor: ColorRgba8`, `endColor: ColorRgba8`, `size: float`, `rotationRad: float`, `rotSpeedRad: float`, `ageSec: float`, `lifetimeSec: float`, `isAlive: bool` | `Particle2D(pos, vel, startColor, endColor, size, rotationRad, rotSpeedRad, ageSec, lifetimeSec, isAlive)` |
| `EmissionShape2D` | `pub struct` | `std/particle/emitter2d.aipl` | `shapeType: int`, `radius: float`, `innerRadius: float`, `boxExtents: Vec2` | `EmissionShape2D(shapeType, radius, innerRadius, boxExtents)` |
| `ParticlePool2D` | `pub struct` | `std/particle/emitter2d.aipl` | `particles: [Particle2D]`, `maxParticles: int`, `liveCount: int`, `emissionRatePerSec: float`, `emissionAccumulator: float` | `ParticlePool2D(particles, maxParticles, liveCount, emissionRatePerSec, emissionAccumulator)` |
| `Particle3D` | `pub struct` | `std/particle/emitter3d.aipl` | `pos: Vec3`, `vel: Vec3`, `color: ColorRgba8`, `size: float`, `ageSec: float`, `lifetimeSec: float`, `isAlive: bool` | `Particle3D(pos, vel, color, size, ageSec, lifetimeSec, isAlive)` |
| `EmissionShape3D` | `pub struct` | `std/particle/emitter3d.aipl` | `shapeType: int`, `radius: float`, `coneAngleRad: float`, `boxExtents: Vec3` | `EmissionShape3D(shapeType, radius, coneAngleRad, boxExtents)` |
| `ParticlePool3D` | `pub struct` | `std/particle/emitter3d.aipl` | `particles: [Particle3D]`, `maxParticles: int`, `liveCount: int`, `emissionRate: float`, `emissionAccumulator: float` | `ParticlePool3D(particles, maxParticles, liveCount, emissionRate, emissionAccumulator)` |
| `GpuParticleSoA` | `pub struct` | `std/particle/gpu_compute_particles.aipl` | `posX: [float]`, `posY: [float]`, `posZ: [float]`, `velX: [float]`, `velY: [float]`, `velZ: [float]`, `age: [float]`, `lifetime: [float]`, `colorRgba: [int]`, `capacity: int`, `liveCount: int` | `GpuParticleSoA(posX, posY, posZ, velX, velY, velZ, age, lifetime, colorRgba, capacity, liveCount)` |
| `GpuComputeParticlePipeline` | `pub struct` | `std/particle/gpu_compute_particles.aipl` | `wgslSource: str`, `workgroupSizeX: int`, `maxParticles: int` | `GpuComputeParticlePipeline(wgslSource, workgroupSizeX, maxParticles)` |
| `RibbonNode` | `pub struct` | `std/particle/ribbon_trail.aipl` | `position: Vec3`, `normal: Vec3`, `width: float`, `ageSec: float` | `RibbonNode(position, normal, width, ageSec)` |
| `RibbonTrail` | `pub struct` | `std/particle/ribbon_trail.aipl` | `nodes: [RibbonNode]`, `maxNodes: int`, `lifetimeSec: float`, `minDistance: float` | `RibbonTrail(nodes, maxNodes, lifetimeSec, minDistance)` |
| `RibbonMeshVertex` | `pub struct` | `std/particle/ribbon_trail.aipl` | `pos: Vec3`, `uv: Vec2`, `color: ColorRgba8` | `RibbonMeshVertex(pos, uv, color)` |
| `SubEmitterBinding` | `pub struct` | `std/particle/sub_emitter.aipl` | `triggerEvent: int`, `childPoolId: int`, `burstCount: int`, `inheritVelocityFactor: float` | `SubEmitterBinding(triggerEvent, childPoolId, burstCount, inheritVelocityFactor)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/particle/affector.aipl` | `createGravityAffector` | `pub fn createGravityAffector(gravityVec: Vec3): ParticleAffector:` | `tests/functions/particle/affector_test.aipl` |
| `2` | `std/particle/affector.aipl` | `createDragAffector` | `pub fn createDragAffector(dragCoefficient: float): ParticleAffector:` | `tests/functions/particle/affector_test.aipl` |
| `3` | `std/particle/affector.aipl` | `createVortexAffector` | `pub fn createVortexAffector(axisOrigin: Vec3, axisDir: Vec3, angularSpeed: float): ParticleAffector:` | `tests/functions/particle/affector_test.aipl` |
| `4` | `std/particle/affector.aipl` | `createCurlNoiseAffector` | `pub fn createCurlNoiseAffector(frequency: float, strength: float): ParticleAffector:` | `tests/functions/particle/affector_test.aipl` |
| `5` | `std/particle/affector.aipl` | `evaluateVortexForce` | `pub fn evaluateVortexForce(affector: ParticleAffector, pos: Vec3): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `6` | `std/particle/affector.aipl` | `pseudoPotentialVec` | `fn pseudoPotentialVec(x: float, y: float, z: float): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `7` | `std/particle/affector.aipl` | `evaluateCurlNoiseForce` | `pub fn evaluateCurlNoiseForce(affector: ParticleAffector, pos: Vec3): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `8` | `std/particle/affector.aipl` | `createPointAttractorAffector` | `pub fn createPointAttractorAffector(center: Vec3, strength: float, falloffDistance: float = 50.0): ParticleAffector:` | `tests/functions/particle/affector_test.aipl` |
| `9` | `std/particle/affector.aipl` | `evaluatePointAttractorForce` | `pub fn evaluatePointAttractorForce(affector: ParticleAffector, pos: Vec3): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `10` | `std/particle/affector.aipl` | `evaluateAffectorForce3D` | `pub fn evaluateAffectorForce3D(affector: ParticleAffector, pos: Vec3, vel: Vec3): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `11` | `std/particle/affector.aipl` | `combineAffectorForces3D` | `pub fn combineAffectorForces3D(affectors: [ParticleAffector], pos: Vec3, vel: Vec3): Vec3:` | `tests/functions/particle/affector_test.aipl` |
| `12` | `std/particle/curve_prop.aipl` | `evaluateKeyframeCurve` | `pub fn evaluateKeyframeCurve(curve: KeyframeCurve, t: float): float:` | `tests/functions/particle/curve_prop_test.aipl` |
| `13` | `std/particle/curve_prop.aipl` | `evaluateMinMaxCurve` | `pub fn evaluateMinMaxCurve(prop: MinMaxCurveProperty, t: float, random01: float): float:` | `tests/functions/particle/curve_prop_test.aipl` |
| `14` | `std/particle/curve_prop.aipl` | `evaluateColorGradient` | `pub fn evaluateColorGradient(gradient: ColorGradient, t: float): ColorRgba8:` | `tests/functions/particle/curve_prop_test.aipl` |
| `15` | `std/particle/curve_prop.aipl` | `createLinearRampCurve` | `pub fn createLinearRampCurve(startVal: float, endVal: float): KeyframeCurve:` | `tests/functions/particle/curve_prop_test.aipl` |
| `16` | `std/particle/curve_prop.aipl` | `createConstantCurveProperty` | `pub fn createConstantCurveProperty(val: float): MinMaxCurveProperty:` | `tests/functions/particle/curve_prop_test.aipl` |
| `17` | `std/particle/curve_prop.aipl` | `createRandomConstantsProperty` | `pub fn createRandomConstantsProperty(minVal: float, maxVal: float): MinMaxCurveProperty:` | `tests/functions/particle/curve_prop_test.aipl` |
| `18` | `std/particle/curve_prop.aipl` | `createTwoStopColorGradient` | `pub fn createTwoStopColorGradient(startColor: ColorRgba8, endColor: ColorRgba8): ColorGradient:` | `tests/functions/particle/curve_prop_test.aipl` |
| `19` | `std/particle/curve_prop.aipl` | `sampleCurveIntegral` | `pub fn sampleCurveIntegral(curve: KeyframeCurve, steps: int = 16): float:` | `tests/functions/particle/curve_prop_test.aipl` |
| `20` | `std/particle/emitter2d.aipl` | `createParticlePool2D` | `pub fn createParticlePool2D(maxParticles: int = 1024, emissionRate: float = 100.0): ParticlePool2D:` | `tests/functions/particle/emitter2d_test.aipl` |
| `21` | `std/particle/emitter2d.aipl` | `sampleEmissionPosition2D` | `pub fn sampleEmissionPosition2D(shape: EmissionShape2D, rngRoll1: float, rngRoll2: float): Vec2:` | `tests/functions/particle/emitter2d_test.aipl` |
| `22` | `std/particle/emitter2d.aipl` | `stepParticlePool2D` | `pub fn stepParticlePool2D(pool: ParticlePool2D, dt: float, affectors: [ParticleAffector]): ParticlePool2D:` | `tests/functions/particle/emitter2d_test.aipl` |
| `23` | `std/particle/emitter2d.aipl` | `spawnParticle2D` | `pub fn spawnParticle2D(pool: ParticlePool2D, p: Particle2D): ParticlePool2D:` | `tests/functions/particle/emitter2d_test.aipl` |
| `24` | `std/particle/emitter2d.aipl` | `emitParticleBurst2D` | `pub fn emitParticleBurst2D(pool: ParticlePool2D, origin: Vec2, count: int, speed: float, lifetimeSec: float, startColor: ColorRgba8, endColor: ColorRgba8): ParticlePool2D:` | `tests/functions/particle/emitter2d_test.aipl` |
| `25` | `std/particle/emitter2d.aipl` | `particleNormalizedAge2D` | `pub fn particleNormalizedAge2D(p: Particle2D): float:` | `tests/functions/particle/emitter2d_test.aipl` |
| `26` | `std/particle/emitter2d.aipl` | `clearParticlePool2D` | `pub fn clearParticlePool2D(pool: ParticlePool2D): ParticlePool2D:` | `tests/functions/particle/emitter2d_test.aipl` |
| `27` | `std/particle/emitter2d.aipl` | `countActiveParticles2D` | `pub fn countActiveParticles2D(pool: ParticlePool2D): int:` | `tests/functions/particle/emitter2d_test.aipl` |
| `28` | `std/particle/emitter3d.aipl` | `createParticlePool3D` | `pub fn createParticlePool3D(maxParticles: int = 4096, emissionRate: float = 250.0): ParticlePool3D:` | `tests/functions/particle/emitter3d_test.aipl` |
| `29` | `std/particle/emitter3d.aipl` | `sampleEmissionPosition3D` | `pub fn sampleEmissionPosition3D(shape: EmissionShape3D, r1: float, r2: float, r3: float): Vec3:` | `tests/functions/particle/emitter3d_test.aipl` |
| `30` | `std/particle/emitter3d.aipl` | `stepParticlePool3D` | `pub fn stepParticlePool3D(pool: ParticlePool3D, dt: float, affectors: [ParticleAffector]): ParticlePool3D:` | `tests/functions/particle/emitter3d_test.aipl` |
| `31` | `std/particle/emitter3d.aipl` | `spawnParticle3D` | `pub fn spawnParticle3D(pool: ParticlePool3D, p: Particle3D): ParticlePool3D:` | `tests/functions/particle/emitter3d_test.aipl` |
| `32` | `std/particle/emitter3d.aipl` | `emitParticleBurst3D` | `pub fn emitParticleBurst3D(pool: ParticlePool3D, origin: Vec3, count: int, speed: float, lifetimeSec: float, color: ColorRgba8): ParticlePool3D:` | `tests/functions/particle/emitter3d_test.aipl` |
| `33` | `std/particle/emitter3d.aipl` | `particleNormalizedAge3D` | `pub fn particleNormalizedAge3D(p: Particle3D): float:` | `tests/functions/particle/emitter3d_test.aipl` |
| `34` | `std/particle/emitter3d.aipl` | `clearParticlePool3D` | `pub fn clearParticlePool3D(pool: ParticlePool3D): ParticlePool3D:` | `tests/functions/particle/emitter3d_test.aipl` |
| `35` | `std/particle/gpu_compute_particles.aipl` | `createGpuParticleSoA` | `pub fn createGpuParticleSoA(capacity: int): GpuParticleSoA:` | `tests/functions/particle/gpu_compute_particles_test.aipl` |
| `36` | `std/particle/gpu_compute_particles.aipl` | `buildComputeParticleShaderWgsl` | `pub fn buildComputeParticleShaderWgsl(workgroupSize: int = 64): str:` | `tests/functions/particle/gpu_compute_particles_test.aipl` |
| `37` | `std/particle/gpu_compute_particles.aipl` | `createComputeParticlePipeline` | `pub fn createComputeParticlePipeline(maxParticles: int = 65536, workgroupSizeX: int = 64): GpuComputeParticlePipeline:` | `tests/functions/particle/gpu_compute_particles_test.aipl` |
| `38` | `std/particle/gpu_compute_particles.aipl` | `spawnGpuParticleSoA` | `pub fn spawnGpuParticleSoA(mut soa: GpuParticleSoA, px: float, py: float, pz: float, vx: float, vy: float, vz: float, lifetime: float, rgba: int): GpuParticleSoA:` | `tests/functions/particle/gpu_compute_particles_test.aipl` |
| `39` | `std/particle/gpu_compute_particles.aipl` | `stepGpuParticleSoACpuFallback` | `pub fn stepGpuParticleSoACpuFallback(mut soa: GpuParticleSoA, dt: float, gravityY: float): GpuParticleSoA:` | `tests/functions/particle/gpu_compute_particles_test.aipl` |
| `40` | `std/particle/ribbon_trail.aipl` | `createRibbonTrail` | `pub fn createRibbonTrail(maxNodes: int = 64, lifetimeSec: float = 1.0, minDistance: float = 0.1): RibbonTrail:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `41` | `std/particle/ribbon_trail.aipl` | `pushRibbonPosition` | `pub fn pushRibbonPosition(trail: RibbonTrail, pos: Vec3, width: float): RibbonTrail:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `42` | `std/particle/ribbon_trail.aipl` | `updateRibbonTrail` | `pub fn updateRibbonTrail(trail: RibbonTrail, dt: float): RibbonTrail:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `43` | `std/particle/ribbon_trail.aipl` | `generateRibbonQuadStrip` | `pub fn generateRibbonQuadStrip(trail: RibbonTrail, cameraPos: Vec3, color: ColorRgba8): [RibbonMeshVertex]:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `44` | `std/particle/ribbon_trail.aipl` | `clearRibbonTrail` | `pub fn clearRibbonTrail(trail: RibbonTrail): RibbonTrail:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `45` | `std/particle/ribbon_trail.aipl` | `ribbonTrailLength` | `pub fn ribbonTrailLength(trail: RibbonTrail): float:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `46` | `std/particle/ribbon_trail.aipl` | `fxUpdateParticleTrailNodeX` | `pub fn fxUpdateParticleTrailNodeX(prevX: float, targetX: float, followFactor: float): float:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `47` | `std/particle/ribbon_trail.aipl` | `fxUpdateParticleTrailNodeY` | `pub fn fxUpdateParticleTrailNodeY(prevY: float, targetY: float, followFactor: float): float:` | `tests/functions/particle/ribbon_trail_test.aipl` |
| `48` | `std/particle/sub_emitter.aipl` | `bindSubEmitter` | `pub fn bindSubEmitter(trigger: int, childPoolId: int, count: int, inheritVel: float = 0.0): SubEmitterBinding:` | `tests/functions/particle/sub_emitter_test.aipl` |
| `49` | `std/particle/sub_emitter.aipl` | `dispatchSubEmitterEvent` | `pub fn dispatchSubEmitterEvent(binding: SubEmitterBinding, parentPos: Vec3, parentVel: Vec3): [Particle3D]:` | `tests/functions/particle/sub_emitter_test.aipl` |
| `50` | `std/particle/sub_emitter.aipl` | `shouldTriggerSubEmitter` | `pub fn shouldTriggerSubEmitter(binding: SubEmitterBinding, eventKind: int): bool:` | `tests/functions/particle/sub_emitter_test.aipl` |
| `51` | `std/particle/sub_emitter.aipl` | `dispatchSubEmitterCone` | `pub fn dispatchSubEmitterCone(binding: SubEmitterBinding, parentPos: Vec3, dir: Vec3, speed: float, lifetimeSec: float): [Particle3D]:` | `tests/functions/particle/sub_emitter_test.aipl` |
| `52` | `std/particle/sub_emitter.aipl` | `mergeSubEmitterSpawn3D` | `pub fn mergeSubEmitterSpawn3D(pool: ParticlePool3D, spawned: [Particle3D]): ParticlePool3D:` | `tests/functions/particle/sub_emitter_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createGravityAffector` (`std/particle/affector.aipl`)

- **Signature**: `pub fn createGravityAffector(gravityVec: Vec3): ParticleAffector:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gravityVec: Vec3` | **Returns**: `ParticleAffector`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createGravityAffector` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `gravityVec: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `ParticleAffector(`.

```aipl
module tests.functions.particle.affector_z1_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createGravityAffector_1(): int:
  let arg_gravityVec = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_gravityVec = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = createGravityAffector(arg_gravityVec)
  let resEdge = createGravityAffector(edge_gravityVec)
  assertEqInt(resNom.affectorType, 1, "createGravityAffector nominal resNom.affectorType == 1")
  assertEqInt(resEdge.affectorType, 1, "createGravityAffector boundary resEdge.affectorType == 1")
  ret 0
```

---

### `createDragAffector` (`std/particle/affector.aipl`)

- **Signature**: `pub fn createDragAffector(dragCoefficient: float): ParticleAffector:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dragCoefficient: float` | **Returns**: `ParticleAffector`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `createDragAffector` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `dragCoefficient: float = 1.0`; exercises core body path returning/computing `ParticleAffector(`.

```aipl
module tests.functions.particle.affector_z2_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createDragAffector_2(): int:
  let arg_dragCoefficient = 1.0
  let edge_dragCoefficient = 0.5
  let resNom = createDragAffector(arg_dragCoefficient)
  let resEdge = createDragAffector(edge_dragCoefficient)
  assertEqInt(resNom.affectorType, 2, "createDragAffector nominal resNom.affectorType == 2")
  assertEqInt(resEdge.affectorType, 2, "createDragAffector boundary resEdge.affectorType == 2")
  ret 0
```

---

### `createVortexAffector` (`std/particle/affector.aipl`)

- **Signature**: `pub fn createVortexAffector(axisOrigin: Vec3, axisDir: Vec3, angularSpeed: float): ParticleAffector:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `axisOrigin: Vec3, axisDir: Vec3, angularSpeed: float` | **Returns**: `ParticleAffector`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `createVortexAffector` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `axisOrigin: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `axisDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `angularSpeed: float = 1.0`; exercises core body path returning/computing `ParticleAffector(`.

```aipl
module tests.functions.particle.affector_z3_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createVortexAffector_3(): int:
  let arg_axisOrigin = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_axisOrigin = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_axisDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_axisDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_angularSpeed = 1.0
  let edge_angularSpeed = 0.5
  let resNom = createVortexAffector(arg_axisOrigin, arg_axisDir, arg_angularSpeed)
  let resEdge = createVortexAffector(edge_axisOrigin, edge_axisDir, edge_angularSpeed)
  assertEqInt(resNom.affectorType, 3, "createVortexAffector nominal resNom.affectorType == 3")
  assertEqInt(resEdge.affectorType, 3, "createVortexAffector boundary resEdge.affectorType == 3")
  ret 0
```

---

### `createCurlNoiseAffector` (`std/particle/affector.aipl`)

- **Signature**: `pub fn createCurlNoiseAffector(frequency: float, strength: float): ParticleAffector:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frequency: float, strength: float` | **Returns**: `ParticleAffector`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createCurlNoiseAffector` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `frequency: float = 1.0`, `strength: float = 1.0`; exercises core body path returning/computing `ParticleAffector(`.

```aipl
module tests.functions.particle.affector_z4_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createCurlNoiseAffector_4(): int:
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_strength = 2.0
  let edge_strength = 1.0
  let resNom = createCurlNoiseAffector(arg_frequency, arg_strength)
  let resEdge = createCurlNoiseAffector(edge_frequency, edge_strength)
  assertEqInt(resNom.affectorType, 4, "createCurlNoiseAffector nominal resNom.affectorType == 4")
  assertEqInt(resEdge.affectorType, 4, "createCurlNoiseAffector boundary resEdge.affectorType == 4")
  ret 0
```

---

### `evaluateVortexForce` (`std/particle/affector.aipl`)

- **Signature**: `pub fn evaluateVortexForce(affector: ParticleAffector, pos: Vec3): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `affector: ParticleAffector, pos: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `evaluateVortexForce` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `affector: ParticleAffector = ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 1.0, frequency = 1.0)`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `tangent.scale(affector.strength)`.

```aipl
module tests.functions.particle.affector_z5_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_evaluateVortexForce_5(): int:
  let arg_affector = ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)
  let edge_affector = ParticleAffector(affectorType = 0, strength = 1.0, center = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), falloffDistance = 0.0, frequency = 1.0)
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluateVortexForce(arg_affector, arg_pos)
  let resEdge = evaluateVortexForce(edge_affector, edge_pos)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluateVortexForce nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateVortexForce boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `pseudoPotentialVec` (`std/particle/affector.aipl`)

- **Signature**: `fn pseudoPotentialVec(x: float, y: float, z: float): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float, y: float, z: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `pseudoPotentialVec` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `x: float = 1.0`, `y: float = 1.0`, `z: float = 1.0`; exercises core body path returning/computing `Vec3(x = px, y = py, z = pz)`.

```aipl
module tests.functions.particle.affector_z6_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_pseudoPotentialVec_6(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_z = 1.0
  let edge_z = 0.5
  let resNom = pseudoPotentialVec(arg_x, arg_y, arg_z)
  let resEdge = pseudoPotentialVec(edge_x, edge_y, edge_z)
  assertApproxEq(resNom.x, 0.068533, 0.001, "pseudoPotentialVec nominal resNom.x ~= 0.068533")
  assertApproxEq(resEdge.x, 1.86463, 0.001, "pseudoPotentialVec boundary resEdge.x ~= 1.86463")
  ret 0
```

---

### `evaluateCurlNoiseForce` (`std/particle/affector.aipl`)

- **Signature**: `pub fn evaluateCurlNoiseForce(affector: ParticleAffector, pos: Vec3): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `affector: ParticleAffector, pos: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `evaluateCurlNoiseForce` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `affector: ParticleAffector = ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 1.0, frequency = 1.0)`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `curl.scale(affector.strength)`.

```aipl
module tests.functions.particle.affector_z7_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_evaluateCurlNoiseForce_7(): int:
  let arg_affector = ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)
  let edge_affector = ParticleAffector(affectorType = 0, strength = 1.0, center = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), falloffDistance = 0.0, frequency = 1.0)
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluateCurlNoiseForce(arg_affector, arg_pos)
  let resEdge = evaluateCurlNoiseForce(edge_affector, edge_pos)
  assertApproxEq(resNom.x, -1.03424, 0.001, "evaluateCurlNoiseForce nominal resNom.x ~= -1.03424")
  assertApproxEq(resEdge.x, -0.007083, 0.001, "evaluateCurlNoiseForce boundary resEdge.x ~= -0.007083")
  ret 0
```

---

### `createPointAttractorAffector` (`std/particle/affector.aipl`)

- **Signature**: `pub fn createPointAttractorAffector(center: Vec3, strength: float, falloffDistance: float = 50.0): ParticleAffector:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `center: Vec3, strength: float, falloffDistance: float = 50.0` | **Returns**: `ParticleAffector`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `createPointAttractorAffector` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `strength: float = 1.0`, `falloffDistance: float = 1.0`; exercises core body path returning/computing `ParticleAffector(`.

```aipl
module tests.functions.particle.affector_z8_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_createPointAttractorAffector_8(): int:
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_strength = 2.0
  let edge_strength = 1.0
  let arg_falloffDistance = 0.0
  let edge_falloffDistance = 0.0
  let resNom = createPointAttractorAffector(arg_center, arg_strength, arg_falloffDistance)
  let resEdge = createPointAttractorAffector(edge_center, edge_strength, edge_falloffDistance)
  assertEqInt(resNom.affectorType, 5, "createPointAttractorAffector nominal resNom.affectorType == 5")
  assertEqInt(resEdge.affectorType, 5, "createPointAttractorAffector boundary resEdge.affectorType == 5")
  ret 0
```

---

### `evaluatePointAttractorForce` (`std/particle/affector.aipl`)

- **Signature**: `pub fn evaluatePointAttractorForce(affector: ParticleAffector, pos: Vec3): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `affector: ParticleAffector, pos: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `evaluatePointAttractorForce` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `affector: ParticleAffector = ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 1.0, frequency = 1.0)`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `dir.scale(affector.strength * atten)`.

```aipl
module tests.functions.particle.affector_z9_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_evaluatePointAttractorForce_9(): int:
  let arg_affector = ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)
  let edge_affector = ParticleAffector(affectorType = 0, strength = 1.0, center = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), falloffDistance = 0.0, frequency = 1.0)
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluatePointAttractorForce(arg_affector, arg_pos)
  let resEdge = evaluatePointAttractorForce(edge_affector, edge_pos)
  assertApproxEq(resNom.x, 0.0, 0.001, "evaluatePointAttractorForce nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluatePointAttractorForce boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateAffectorForce3D` (`std/particle/affector.aipl`)

- **Signature**: `pub fn evaluateAffectorForce3D(affector: ParticleAffector, pos: Vec3, vel: Vec3): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `affector: ParticleAffector, pos: Vec3, vel: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `evaluateAffectorForce3D` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `affector: ParticleAffector = ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 1.0, frequency = 1.0)`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `vel: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(x = 0.0, y = 0.0, z = 0.0)`.

```aipl
module tests.functions.particle.affector_z10_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_evaluateAffectorForce3D_10(): int:
  let arg_affector = ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)
  let edge_affector = ParticleAffector(affectorType = 0, strength = 1.0, center = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), falloffDistance = 0.0, frequency = 1.0)
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_vel = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_vel = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluateAffectorForce3D(arg_affector, arg_pos, arg_vel)
  let resEdge = evaluateAffectorForce3D(edge_affector, edge_pos, edge_vel)
  assertApproxEq(resNom.x, 2.0, 0.001, "evaluateAffectorForce3D nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "evaluateAffectorForce3D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `combineAffectorForces3D` (`std/particle/affector.aipl`)

- **Signature**: `pub fn combineAffectorForces3D(affectors: [ParticleAffector], pos: Vec3, vel: Vec3): Vec3:`
- **Import**: `import * from "std/particle/affector"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `affectors: [ParticleAffector], pos: Vec3, vel: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/affector_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `combineAffectorForces3D` divergence-free 3D curl-noise, tangential vortex swirl, radial point attractor/repulsor, linear drag, and force superposition. Concrete nominal inputs: `affectors: [ParticleAffector] = [ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 0, y = 0, z = 0), direction = Vec3(x = 0, y = 0, z = 0), falloffDistance = 1.0, frequency = 1.0)]`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `vel: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.particle.affector_z11_test
import * from "std/particle/affector"
import { EPSILON, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_affector_combineAffectorForces3D_11(): int:
  let arg_affectors = [ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)]
  let edge_affectors = []
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_vel = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_vel = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = combineAffectorForces3D(arg_affectors, arg_pos, arg_vel)
  let resEdge = combineAffectorForces3D(edge_affectors, edge_pos, edge_vel)
  assertApproxEq(resNom.x, 2.0, 0.001, "combineAffectorForces3D nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "combineAffectorForces3D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `evaluateKeyframeCurve` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn evaluateKeyframeCurve(curve: KeyframeCurve, t: float): float:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `curve: KeyframeCurve, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `evaluateKeyframeCurve` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `curve: KeyframeCurve = KeyframeCurve(keyframes = [CurveKeyframe(time = 0, value = 0, inTangent = 0, outTangent = 0)])`, `t: float = 0.5`; exercises core body path returning/computing `curve.keyframes[lastIdx].value`.

```aipl
module tests.functions.particle.curve_prop_z1_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_evaluateKeyframeCurve_1(): int:
  let arg_curve = KeyframeCurve(keyframes = [])
  let edge_curve = KeyframeCurve(keyframes = [])
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateKeyframeCurve(arg_curve, arg_t)
  let resEdge = evaluateKeyframeCurve(edge_curve, edge_t)
  assertApproxEq(resNom, 0.0, 0.001, "evaluateKeyframeCurve nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "evaluateKeyframeCurve boundary resEdge ~= 0.0")
  ret 0
```

---

### `evaluateMinMaxCurve` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn evaluateMinMaxCurve(prop: MinMaxCurveProperty, t: float, random01: float): float:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prop: MinMaxCurveProperty, t: float, random01: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `evaluateMinMaxCurve` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `prop: MinMaxCurveProperty = MinMaxCurveProperty(mode = 1, constantMin = 1.0, constantMax = 1.0, curveMin = KeyframeCurve(keyframes = [0]), curveMax = KeyframeCurve(keyframes = [0]))`, `t: float = 0.5`, `random01: float = 1.0`; exercises core body path returning/computing `prop.constantMin`.

```aipl
module tests.functions.particle.curve_prop_z2_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_evaluateMinMaxCurve_2(): int:
  let arg_prop = MinMaxCurveProperty(mode = 4, constantMin = 0.0, constantMax = 2.0, curveMin = KeyframeCurve(keyframes = []), curveMax = KeyframeCurve(keyframes = []))
  let edge_prop = MinMaxCurveProperty(mode = 1, constantMin = 0.0, constantMax = 1.0, curveMin = KeyframeCurve(keyframes = []), curveMax = KeyframeCurve(keyframes = []))
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_random01 = 1.0
  let edge_random01 = 0.5
  let resNom = evaluateMinMaxCurve(arg_prop, arg_t, arg_random01)
  let resEdge = evaluateMinMaxCurve(edge_prop, edge_t, edge_random01)
  assertApproxEq(resNom, 0.0, 0.001, "evaluateMinMaxCurve nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.5, 0.001, "evaluateMinMaxCurve boundary resEdge ~= 0.5")
  ret 0
```

---

### `evaluateColorGradient` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn evaluateColorGradient(gradient: ColorGradient, t: float): ColorRgba8:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gradient: ColorGradient, t: float` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `evaluateColorGradient` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `gradient: ColorGradient = ColorGradient(stops = [ColorStop(time = 0, color = 0)])`, `t: float = 0.5`; exercises core body path returning/computing `gradient.stops[lastIdx].color`.

```aipl
module tests.functions.particle.curve_prop_z3_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_evaluateColorGradient_3(): int:
  let arg_gradient = ColorGradient(stops = [])
  let edge_gradient = ColorGradient(stops = [])
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateColorGradient(arg_gradient, arg_t)
  let resEdge = evaluateColorGradient(edge_gradient, edge_t)
  assertEqInt(resNom.r, 255, "evaluateColorGradient nominal resNom.r == 255")
  assertEqInt(resEdge.r, 255, "evaluateColorGradient boundary resEdge.r == 255")
  ret 0
```

---

### `createLinearRampCurve` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn createLinearRampCurve(startVal: float, endVal: float): KeyframeCurve:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startVal: float, endVal: float` | **Returns**: `KeyframeCurve`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `createLinearRampCurve` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `startVal: float = 1.0`, `endVal: float = 1.0`; exercises core body path returning/computing `KeyframeCurve(keyframes = [`.

```aipl
module tests.functions.particle.curve_prop_z4_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_createLinearRampCurve_4(): int:
  let arg_startVal = 0.0
  let edge_startVal = 0.0
  let arg_endVal = 2.0
  let edge_endVal = 1.0
  let resNom = createLinearRampCurve(arg_startVal, arg_endVal)
  let resEdge = createLinearRampCurve(edge_startVal, edge_endVal)
  assertEqInt(resNom.keyframes.len(), 2, "createLinearRampCurve nominal resNom.keyframes.len() == 2")
  assertEqInt(resEdge.keyframes.len(), 2, "createLinearRampCurve boundary resEdge.keyframes.len() == 2")
  ret 0
```

---

### `createConstantCurveProperty` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn createConstantCurveProperty(val: float): MinMaxCurveProperty:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float` | **Returns**: `MinMaxCurveProperty`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createConstantCurveProperty` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `val: float = 1.0`; exercises core body path returning/computing `MinMaxCurveProperty(`.

```aipl
module tests.functions.particle.curve_prop_z5_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_createConstantCurveProperty_5(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let resNom = createConstantCurveProperty(arg_val)
  let resEdge = createConstantCurveProperty(edge_val)
  assertEqInt(resNom.mode, 0, "createConstantCurveProperty nominal resNom.mode == 0")
  assertEqInt(resEdge.mode, 0, "createConstantCurveProperty boundary resEdge.mode == 0")
  ret 0
```

---

### `createRandomConstantsProperty` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn createRandomConstantsProperty(minVal: float, maxVal: float): MinMaxCurveProperty:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minVal: float, maxVal: float` | **Returns**: `MinMaxCurveProperty`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `createRandomConstantsProperty` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `minVal: float = 1.0`, `maxVal: float = 1.0`; exercises core body path returning/computing `MinMaxCurveProperty(`.

```aipl
module tests.functions.particle.curve_prop_z6_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_createRandomConstantsProperty_6(): int:
  let arg_minVal = 0.0
  let edge_minVal = 0.0
  let arg_maxVal = 2.0
  let edge_maxVal = 1.0
  let resNom = createRandomConstantsProperty(arg_minVal, arg_maxVal)
  let resEdge = createRandomConstantsProperty(edge_minVal, edge_maxVal)
  assertEqInt(resNom.mode, 1, "createRandomConstantsProperty nominal resNom.mode == 1")
  assertEqInt(resEdge.mode, 1, "createRandomConstantsProperty boundary resEdge.mode == 1")
  ret 0
```

---

### `createTwoStopColorGradient` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn createTwoStopColorGradient(startColor: ColorRgba8, endColor: ColorRgba8): ColorGradient:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startColor: ColorRgba8, endColor: ColorRgba8` | **Returns**: `ColorGradient`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `createTwoStopColorGradient` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `startColor: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `endColor: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `ColorGradient(stops = [`.

```aipl
module tests.functions.particle.curve_prop_z7_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_createTwoStopColorGradient_7(): int:
  let arg_startColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_startColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_endColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_endColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = createTwoStopColorGradient(arg_startColor, arg_endColor)
  let resEdge = createTwoStopColorGradient(edge_startColor, edge_endColor)
  assertEqInt(resNom.stops.len(), 2, "createTwoStopColorGradient nominal resNom.stops.len() == 2")
  assertEqInt(resEdge.stops.len(), 2, "createTwoStopColorGradient boundary resEdge.stops.len() == 2")
  ret 0
```

---

### `sampleCurveIntegral` (`std/particle/curve_prop.aipl`)

- **Signature**: `pub fn sampleCurveIntegral(curve: KeyframeCurve, steps: int = 16): float:`
- **Import**: `import * from "std/particle/curve_prop"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `curve: KeyframeCurve, steps: int = 16` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/curve_prop_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `sampleCurveIntegral` multi-keyframe scalar/color-over-life gradient evaluation and clamped `t in [0.0, 1.0]` interpolation. Concrete nominal inputs: `curve: KeyframeCurve = KeyframeCurve(keyframes = [CurveKeyframe(time = 0, value = 0, inTangent = 0, outTangent = 0)])`, `steps: int = 1`; exercises core body path returning/computing `sum`.

```aipl
module tests.functions.particle.curve_prop_z8_test
import * from "std/particle/curve_prop"
import { EPSILON, clampFloat } from "std/math/consts"
import { ColorRgba8, lerpOklab } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_curve_prop_sampleCurveIntegral_8(): int:
  let arg_curve = KeyframeCurve(keyframes = [])
  let edge_curve = KeyframeCurve(keyframes = [])
  let arg_steps = 4
  let edge_steps = 1
  let resNom = sampleCurveIntegral(arg_curve, arg_steps)
  let resEdge = sampleCurveIntegral(edge_curve, edge_steps)
  assertApproxEq(resNom, 0.0, 0.001, "sampleCurveIntegral nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sampleCurveIntegral boundary resEdge ~= 0.0")
  ret 0
```

---

### `createParticlePool2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn createParticlePool2D(maxParticles: int = 1024, emissionRate: float = 100.0): ParticlePool2D:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxParticles: int = 1024, emissionRate: float = 100.0` | **Returns**: `ParticlePool2D`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `createParticlePool2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `maxParticles: int = 1`, `emissionRate: float = 1.0`; exercises core body path returning/computing `ParticlePool2D(`.

```aipl
module tests.functions.particle.emitter2d_z1_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_createParticlePool2D_1(): int:
  let arg_maxParticles = 4
  let edge_maxParticles = 1
  let arg_emissionRate = 2.0
  let edge_emissionRate = 1.0
  let resNom = createParticlePool2D(arg_maxParticles, arg_emissionRate)
  let resEdge = createParticlePool2D(edge_maxParticles, edge_emissionRate)
  assertEqInt(resNom.particles.len(), 0, "createParticlePool2D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "createParticlePool2D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `sampleEmissionPosition2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn sampleEmissionPosition2D(shape: EmissionShape2D, rngRoll1: float, rngRoll2: float): Vec2:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `shape: EmissionShape2D, rngRoll1: float, rngRoll2: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `sampleEmissionPosition2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `shape: EmissionShape2D = EmissionShape2D(shapeType = 1, radius = 1.0, innerRadius = 1.0, boxExtents = Vec2(x = 1.0, y = 1.0))`, `rngRoll1: float = 1.0`, `rngRoll2: float = 1.0`; exercises core body path returning/computing `Vec2(`.

```aipl
module tests.functions.particle.emitter2d_z2_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_sampleEmissionPosition2D_2(): int:
  let arg_shape = EmissionShape2D(shapeType = 1, radius = 2.0, innerRadius = 2.0, boxExtents = Vec2(x = 1.0, y = 1.0))
  let edge_shape = EmissionShape2D(shapeType = 0, radius = 1.0, innerRadius = 1.0, boxExtents = Vec2(x = 0.5, y = 0.5))
  let arg_rngRoll1 = 1.0
  let edge_rngRoll1 = 0.5
  let arg_rngRoll2 = 1.0
  let edge_rngRoll2 = 0.5
  let resNom = sampleEmissionPosition2D(arg_shape, arg_rngRoll1, arg_rngRoll2)
  let resEdge = sampleEmissionPosition2D(edge_shape, edge_rngRoll1, edge_rngRoll2)
  assertApproxEq(resNom.x, 2.0, 0.001, "sampleEmissionPosition2D nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sampleEmissionPosition2D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `stepParticlePool2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn stepParticlePool2D(pool: ParticlePool2D, dt: float, affectors: [ParticleAffector]): ParticlePool2D:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool2D, dt: float, affectors: [ParticleAffector]` | **Returns**: `ParticlePool2D`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `stepParticlePool2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `pool: ParticlePool2D = ParticlePool2D(particles = [Particle2D(pos = 0, vel = 0, startColor = 0, endColor = 0, size = 0, rotationRad = 0, rotSpeedRad = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRatePerSec = 1.0, emissionAccumulator = 1.0)`, `dt: float = 0.016667`, `affectors: [ParticleAffector] = [ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 0, y = 0, z = 0), direction = Vec3(x = 0, y = 0, z = 0), falloffDistance = 1.0, frequency = 1.0)]`; exercises core body path returning/computing `ParticlePool2D(`.

```aipl
module tests.functions.particle.emitter2d_z3_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_stepParticlePool2D_3(): int:
  let arg_pool = ParticlePool2D(particles = [], maxParticles = 4, liveCount = 4, emissionRatePerSec = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool2D(particles = [], maxParticles = 1, liveCount = 1, emissionRatePerSec = 1.0, emissionAccumulator = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_affectors = [ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)]
  let edge_affectors = []
  let resNom = stepParticlePool2D(arg_pool, arg_dt, arg_affectors)
  let resEdge = stepParticlePool2D(edge_pool, edge_dt, edge_affectors)
  assertEqInt(resNom.particles.len(), 0, "stepParticlePool2D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "stepParticlePool2D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `spawnParticle2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn spawnParticle2D(pool: ParticlePool2D, p: Particle2D): ParticlePool2D:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool2D, p: Particle2D` | **Returns**: `ParticlePool2D`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `spawnParticle2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `pool: ParticlePool2D = ParticlePool2D(particles = [Particle2D(pos = 0, vel = 0, startColor = 0, endColor = 0, size = 0, rotationRad = 0, rotSpeedRad = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRatePerSec = 1.0, emissionAccumulator = 1.0)`, `p: Particle2D = Particle2D(pos = Vec2(x = 1.0, y = 1.0), vel = Vec2(x = 1.0, y = 1.0), startColor = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), endColor = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), size = 1.0, rotationRad = 1.0, rotSpeedRad = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)`; exercises core body path returning/computing `ParticlePool2D(`.

```aipl
module tests.functions.particle.emitter2d_z4_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_spawnParticle2D_4(): int:
  let arg_pool = ParticlePool2D(particles = [], maxParticles = 4, liveCount = 4, emissionRatePerSec = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool2D(particles = [], maxParticles = 1, liveCount = 1, emissionRatePerSec = 1.0, emissionAccumulator = 0.5)
  let arg_p = Particle2D(pos = Vec2(x = 1.0, y = 1.0), vel = Vec2(x = 1.0, y = 1.0), startColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2), endColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2), size = 1.0, rotationRad = 1.0, rotSpeedRad = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)
  let edge_p = Particle2D(pos = Vec2(x = 0.5, y = 0.5), vel = Vec2(x = 0.5, y = 0.5), startColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0), endColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0), size = 0.5, rotationRad = 0.5, rotSpeedRad = 0.5, ageSec = 0.5, lifetimeSec = 0.5, isAlive = false)
  let resNom = spawnParticle2D(arg_pool, arg_p)
  let resEdge = spawnParticle2D(edge_pool, edge_p)
  assertEqInt(resNom.particles.len(), 1, "spawnParticle2D nominal resNom.particles.len() == 1")
  assertEqInt(resEdge.particles.len(), 1, "spawnParticle2D boundary resEdge.particles.len() == 1")
  ret 0
```

---

### `emitParticleBurst2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn emitParticleBurst2D(pool: ParticlePool2D, origin: Vec2, count: int, speed: float, lifetimeSec: float, startColor: ColorRgba8, endColor: ColorRgba8): ParticlePool2D:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool2D, origin: Vec2, count: int, speed: float, lifetimeSec: float, startColor: ColorRgba8, endColor: ColorRgba8` | **Returns**: `ParticlePool2D`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `emitParticleBurst2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `pool: ParticlePool2D = ParticlePool2D(particles = [Particle2D(pos = 0, vel = 0, startColor = 0, endColor = 0, size = 0, rotationRad = 0, rotSpeedRad = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRatePerSec = 1.0, emissionAccumulator = 1.0)`, `origin: Vec2 = Vec2(x = 1.0, y = 1.0)`, `count: int = 64`, `speed: float = 1.0`, `lifetimeSec: float = 1.0`, `startColor: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `endColor: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `cur`.

```aipl
module tests.functions.particle.emitter2d_z5_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_emitParticleBurst2D_5(): int:
  let arg_pool = ParticlePool2D(particles = [], maxParticles = 4, liveCount = 4, emissionRatePerSec = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool2D(particles = [], maxParticles = 1, liveCount = 1, emissionRatePerSec = 1.0, emissionAccumulator = 0.5)
  let arg_origin = Vec2(x = 1.0, y = 1.0)
  let edge_origin = Vec2(x = 0.5, y = 0.5)
  let arg_count = 4
  let edge_count = 1
  let arg_speed = 1.0
  let edge_speed = 0.5
  let arg_lifetimeSec = 1.0
  let edge_lifetimeSec = 0.5
  let arg_startColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_startColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_endColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_endColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = emitParticleBurst2D(arg_pool, arg_origin, arg_count, arg_speed, arg_lifetimeSec, arg_startColor, arg_endColor)
  let resEdge = emitParticleBurst2D(edge_pool, edge_origin, edge_count, edge_speed, edge_lifetimeSec, edge_startColor, edge_endColor)
  assertEqInt(resNom.particles.len(), 4, "emitParticleBurst2D nominal resNom.particles.len() == 4")
  assertEqInt(resEdge.particles.len(), 1, "emitParticleBurst2D boundary resEdge.particles.len() == 1")
  ret 0
```

---

### `particleNormalizedAge2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn particleNormalizedAge2D(p: Particle2D): float:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: Particle2D` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `particleNormalizedAge2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `p: Particle2D = Particle2D(pos = Vec2(x = 1.0, y = 1.0), vel = Vec2(x = 1.0, y = 1.0), startColor = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), endColor = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), size = 1.0, rotationRad = 1.0, rotSpeedRad = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)`; exercises core body path returning/computing `clampFloat(p.ageSec / p.lifetimeSec, 0.0, 1.0)`.

```aipl
module tests.functions.particle.emitter2d_z6_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_particleNormalizedAge2D_6(): int:
  let arg_p = Particle2D(pos = Vec2(x = 1.0, y = 1.0), vel = Vec2(x = 1.0, y = 1.0), startColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2), endColor = ColorRgba8(r = 2, g = 2, b = 4, a = 2), size = 1.0, rotationRad = 1.0, rotSpeedRad = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)
  let edge_p = Particle2D(pos = Vec2(x = 0.5, y = 0.5), vel = Vec2(x = 0.5, y = 0.5), startColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0), endColor = ColorRgba8(r = 0, g = 0, b = 1, a = 0), size = 0.5, rotationRad = 0.5, rotSpeedRad = 0.5, ageSec = 0.5, lifetimeSec = 0.5, isAlive = false)
  let resNom = particleNormalizedAge2D(arg_p)
  let resEdge = particleNormalizedAge2D(edge_p)
  assertApproxEq(resNom, 1.0, 0.001, "particleNormalizedAge2D nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "particleNormalizedAge2D boundary resEdge ~= 1.0")
  ret 0
```

---

### `clearParticlePool2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn clearParticlePool2D(pool: ParticlePool2D): ParticlePool2D:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool2D` | **Returns**: `ParticlePool2D`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `clearParticlePool2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `pool: ParticlePool2D = ParticlePool2D(particles = [Particle2D(pos = 0, vel = 0, startColor = 0, endColor = 0, size = 0, rotationRad = 0, rotSpeedRad = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRatePerSec = 1.0, emissionAccumulator = 1.0)`; exercises core body path returning/computing `ParticlePool2D(`.

```aipl
module tests.functions.particle.emitter2d_z7_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_clearParticlePool2D_7(): int:
  let arg_pool = ParticlePool2D(particles = [], maxParticles = 4, liveCount = 4, emissionRatePerSec = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool2D(particles = [], maxParticles = 1, liveCount = 1, emissionRatePerSec = 1.0, emissionAccumulator = 0.5)
  let resNom = clearParticlePool2D(arg_pool)
  let resEdge = clearParticlePool2D(edge_pool)
  assertEqInt(resNom.particles.len(), 0, "clearParticlePool2D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "clearParticlePool2D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `countActiveParticles2D` (`std/particle/emitter2d.aipl`)

- **Signature**: `pub fn countActiveParticles2D(pool: ParticlePool2D): int:`
- **Import**: `import * from "std/particle/emitter2d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/particle/emitter2d_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `countActiveParticles2D` 2D SoA particle pool creation, burst/continuous spawning, velocity/gravity integration, and swap-and-pop dead particle compaction. Concrete nominal inputs: `pool: ParticlePool2D = ParticlePool2D(particles = [Particle2D(pos = 0, vel = 0, startColor = 0, endColor = 0, size = 0, rotationRad = 0, rotSpeedRad = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRatePerSec = 1.0, emissionAccumulator = 1.0)`; exercises core body path returning/computing `c`.

```aipl
module tests.functions.particle.emitter2d_z8_test
import * from "std/particle/emitter2d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter2d_countActiveParticles2D_8(): int:
  let arg_pool = ParticlePool2D(particles = [], maxParticles = 4, liveCount = 4, emissionRatePerSec = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool2D(particles = [], maxParticles = 1, liveCount = 1, emissionRatePerSec = 1.0, emissionAccumulator = 0.5)
  let resNom = countActiveParticles2D(arg_pool)
  let resEdge = countActiveParticles2D(edge_pool)
  assertEqInt(resNom, 0, "countActiveParticles2D nominal resNom == 0")
  assertEqInt(resEdge, 0, "countActiveParticles2D boundary resEdge == 0")
  ret 0
```

---

### `createParticlePool3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn createParticlePool3D(maxParticles: int = 4096, emissionRate: float = 250.0): ParticlePool3D:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxParticles: int = 4096, emissionRate: float = 250.0` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createParticlePool3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `maxParticles: int = 1`, `emissionRate: float = 1.0`; exercises core body path returning/computing `ParticlePool3D(`.

```aipl
module tests.functions.particle.emitter3d_z1_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_createParticlePool3D_1(): int:
  let arg_maxParticles = 4
  let edge_maxParticles = 1
  let arg_emissionRate = 2.0
  let edge_emissionRate = 1.0
  let resNom = createParticlePool3D(arg_maxParticles, arg_emissionRate)
  let resEdge = createParticlePool3D(edge_maxParticles, edge_emissionRate)
  assertEqInt(resNom.particles.len(), 0, "createParticlePool3D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "createParticlePool3D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `sampleEmissionPosition3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn sampleEmissionPosition3D(shape: EmissionShape3D, r1: float, r2: float, r3: float): Vec3:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `shape: EmissionShape3D, r1: float, r2: float, r3: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `sampleEmissionPosition3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `shape: EmissionShape3D = EmissionShape3D(shapeType = 1, radius = 1.0, coneAngleRad = 1.0, boxExtents = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `r1: float = 1.0`, `r2: float = 1.0`, `r3: float = 1.0`; exercises core body path returning/computing `Vec3(`.

```aipl
module tests.functions.particle.emitter3d_z2_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_sampleEmissionPosition3D_2(): int:
  let arg_shape = EmissionShape3D(shapeType = 1, radius = 2.0, coneAngleRad = 1.0, boxExtents = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_shape = EmissionShape3D(shapeType = 0, radius = 1.0, coneAngleRad = 0.5, boxExtents = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_r1 = 1.0
  let edge_r1 = 0.5
  let arg_r2 = 1.0
  let edge_r2 = 0.5
  let arg_r3 = 1.0
  let edge_r3 = 0.5
  let resNom = sampleEmissionPosition3D(arg_shape, arg_r1, arg_r2, arg_r3)
  let resEdge = sampleEmissionPosition3D(edge_shape, edge_r1, edge_r2, edge_r3)
  assertApproxEq(resNom.x, 0.0, 0.001, "sampleEmissionPosition3D nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "sampleEmissionPosition3D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `stepParticlePool3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn stepParticlePool3D(pool: ParticlePool3D, dt: float, affectors: [ParticleAffector]): ParticlePool3D:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool3D, dt: float, affectors: [ParticleAffector]` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `stepParticlePool3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `pool: ParticlePool3D = ParticlePool3D(particles = [Particle3D(pos = 0, vel = 0, color = 0, size = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRate = 1.0, emissionAccumulator = 1.0)`, `dt: float = 0.016667`, `affectors: [ParticleAffector] = [ParticleAffector(affectorType = 1, strength = 1.0, center = Vec3(x = 0, y = 0, z = 0), direction = Vec3(x = 0, y = 0, z = 0), falloffDistance = 1.0, frequency = 1.0)]`; exercises core body path returning/computing `ParticlePool3D(`.

```aipl
module tests.functions.particle.emitter3d_z3_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_stepParticlePool3D_3(): int:
  let arg_pool = ParticlePool3D(particles = [], maxParticles = 4, liveCount = 4, emissionRate = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool3D(particles = [], maxParticles = 1, liveCount = 1, emissionRate = 1.0, emissionAccumulator = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_affectors = [ParticleAffector(affectorType = 1, strength = 2.0, center = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), falloffDistance = 0.0, frequency = 2.0)]
  let edge_affectors = []
  let resNom = stepParticlePool3D(arg_pool, arg_dt, arg_affectors)
  let resEdge = stepParticlePool3D(edge_pool, edge_dt, edge_affectors)
  assertEqInt(resNom.particles.len(), 0, "stepParticlePool3D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "stepParticlePool3D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `spawnParticle3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn spawnParticle3D(pool: ParticlePool3D, p: Particle3D): ParticlePool3D:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool3D, p: Particle3D` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `spawnParticle3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `pool: ParticlePool3D = ParticlePool3D(particles = [Particle3D(pos = 0, vel = 0, color = 0, size = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRate = 1.0, emissionAccumulator = 1.0)`, `p: Particle3D = Particle3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), vel = Vec3(x = 1.0, y = 1.0, z = 1.0), color = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)`; exercises core body path returning/computing `ParticlePool3D(`.

```aipl
module tests.functions.particle.emitter3d_z4_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_spawnParticle3D_4(): int:
  let arg_pool = ParticlePool3D(particles = [], maxParticles = 4, liveCount = 4, emissionRate = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool3D(particles = [], maxParticles = 1, liveCount = 1, emissionRate = 1.0, emissionAccumulator = 0.5)
  let arg_p = Particle3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), vel = Vec3(x = 1.0, y = 1.0, z = 1.0), color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)
  let edge_p = Particle3D(pos = Vec3(x = 0.5, y = 0.5, z = 0.5), vel = Vec3(x = 0.5, y = 0.5, z = 0.5), color = ColorRgba8(r = 0, g = 0, b = 1, a = 0), size = 0.5, ageSec = 0.5, lifetimeSec = 0.5, isAlive = false)
  let resNom = spawnParticle3D(arg_pool, arg_p)
  let resEdge = spawnParticle3D(edge_pool, edge_p)
  assertEqInt(resNom.particles.len(), 1, "spawnParticle3D nominal resNom.particles.len() == 1")
  assertEqInt(resEdge.particles.len(), 1, "spawnParticle3D boundary resEdge.particles.len() == 1")
  ret 0
```

---

### `emitParticleBurst3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn emitParticleBurst3D(pool: ParticlePool3D, origin: Vec3, count: int, speed: float, lifetimeSec: float, color: ColorRgba8): ParticlePool3D:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool3D, origin: Vec3, count: int, speed: float, lifetimeSec: float, color: ColorRgba8` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `emitParticleBurst3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `pool: ParticlePool3D = ParticlePool3D(particles = [Particle3D(pos = 0, vel = 0, color = 0, size = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRate = 1.0, emissionAccumulator = 1.0)`, `origin: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `count: int = 64`, `speed: float = 1.0`, `lifetimeSec: float = 1.0`, `color: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `cur`.

```aipl
module tests.functions.particle.emitter3d_z5_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_emitParticleBurst3D_5(): int:
  let arg_pool = ParticlePool3D(particles = [], maxParticles = 4, liveCount = 4, emissionRate = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool3D(particles = [], maxParticles = 1, liveCount = 1, emissionRate = 1.0, emissionAccumulator = 0.5)
  let arg_origin = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_origin = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_count = 4
  let edge_count = 1
  let arg_speed = 1.0
  let edge_speed = 0.5
  let arg_lifetimeSec = 1.0
  let edge_lifetimeSec = 0.5
  let arg_color = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_color = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = emitParticleBurst3D(arg_pool, arg_origin, arg_count, arg_speed, arg_lifetimeSec, arg_color)
  let resEdge = emitParticleBurst3D(edge_pool, edge_origin, edge_count, edge_speed, edge_lifetimeSec, edge_color)
  assertEqInt(resNom.particles.len(), 4, "emitParticleBurst3D nominal resNom.particles.len() == 4")
  assertEqInt(resEdge.particles.len(), 1, "emitParticleBurst3D boundary resEdge.particles.len() == 1")
  ret 0
```

---

### `particleNormalizedAge3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn particleNormalizedAge3D(p: Particle3D): float:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: Particle3D` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `particleNormalizedAge3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `p: Particle3D = Particle3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), vel = Vec3(x = 1.0, y = 1.0, z = 1.0), color = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255()), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)`; exercises core body path returning/computing `clampFloat(p.ageSec / p.lifetimeSec, 0.0, 1.0)`.

```aipl
module tests.functions.particle.emitter3d_z6_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_particleNormalizedAge3D_6(): int:
  let arg_p = Particle3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), vel = Vec3(x = 1.0, y = 1.0, z = 1.0), color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)
  let edge_p = Particle3D(pos = Vec3(x = 0.5, y = 0.5, z = 0.5), vel = Vec3(x = 0.5, y = 0.5, z = 0.5), color = ColorRgba8(r = 0, g = 0, b = 1, a = 0), size = 0.5, ageSec = 0.5, lifetimeSec = 0.5, isAlive = false)
  let resNom = particleNormalizedAge3D(arg_p)
  let resEdge = particleNormalizedAge3D(edge_p)
  assertApproxEq(resNom, 1.0, 0.001, "particleNormalizedAge3D nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "particleNormalizedAge3D boundary resEdge ~= 1.0")
  ret 0
```

---

### `clearParticlePool3D` (`std/particle/emitter3d.aipl`)

- **Signature**: `pub fn clearParticlePool3D(pool: ParticlePool3D): ParticlePool3D:`
- **Import**: `import * from "std/particle/emitter3d"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool3D` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/emitter3d_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `clearParticlePool3D` 3D SoA particle pool creation, cone/sphere directional emission, and lifetime expiration compaction. Concrete nominal inputs: `pool: ParticlePool3D = ParticlePool3D(particles = [Particle3D(pos = 0, vel = 0, color = 0, size = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRate = 1.0, emissionAccumulator = 1.0)`; exercises core body path returning/computing `ParticlePool3D(`.

```aipl
module tests.functions.particle.emitter3d_z7_test
import * from "std/particle/emitter3d"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { TAU, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt, cbrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { ParticleAffector, AFFECTOR_GRAVITY, AFFECTOR_DRAG, AFFECTOR_VORTEX, AFFECTOR_CURL_NOISE, evaluateVortexForce, evaluateCurlNoiseForce } from "std/particle/affector"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_emitter3d_clearParticlePool3D_7(): int:
  let arg_pool = ParticlePool3D(particles = [], maxParticles = 4, liveCount = 4, emissionRate = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool3D(particles = [], maxParticles = 1, liveCount = 1, emissionRate = 1.0, emissionAccumulator = 0.5)
  let resNom = clearParticlePool3D(arg_pool)
  let resEdge = clearParticlePool3D(edge_pool)
  assertEqInt(resNom.particles.len(), 0, "clearParticlePool3D nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "clearParticlePool3D boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `createGpuParticleSoA` (`std/particle/gpu_compute_particles.aipl`)

- **Signature**: `pub fn createGpuParticleSoA(capacity: int): GpuParticleSoA:`
- **Import**: `import * from "std/particle/gpu_compute_particles"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `GpuParticleSoA`
- **Unit Test**: `tests/functions/particle/gpu_compute_particles_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `createGpuParticleSoA` 64-thread workgroup dispatch sizing and CPU fallback SoA simulation parity. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `GpuParticleSoA(`.

```aipl
module tests.functions.particle.gpu_compute_particles_z1_test
import * from "std/particle/gpu_compute_particles"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_compute_particles_createGpuParticleSoA_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = createGpuParticleSoA(arg_capacity)
  let resEdge = createGpuParticleSoA(edge_capacity)
  assertEqInt(resNom.posX.len(), 4, "createGpuParticleSoA nominal resNom.posX.len() == 4")
  assertEqInt(resEdge.posX.len(), 1, "createGpuParticleSoA boundary resEdge.posX.len() == 1")
  ret 0
```

---

### `buildComputeParticleShaderWgsl` (`std/particle/gpu_compute_particles.aipl`)

- **Signature**: `pub fn buildComputeParticleShaderWgsl(workgroupSize: int = 64): str:`
- **Import**: `import * from "std/particle/gpu_compute_particles"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `workgroupSize: int = 64` | **Returns**: `str`
- **Unit Test**: `tests/functions/particle/gpu_compute_particles_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `buildComputeParticleShaderWgsl` 64-thread workgroup dispatch sizing and CPU fallback SoA simulation parity. Concrete nominal inputs: `workgroupSize: int = 64`; exercises core body path returning/computing `"@compute @workgroup_size(" + str(wg) + ")\nfn cs_main(@builtin(global_invocation_id) gid: vec3<u32>) {\n  let idx = gid.x;\n  // Advect particle position and decay lifetime in VRAM\n}\n"`.

```aipl
module tests.functions.particle.gpu_compute_particles_z2_test
import * from "std/particle/gpu_compute_particles"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_compute_particles_buildComputeParticleShaderWgsl_2(): int:
  let arg_workgroupSize = 4
  let edge_workgroupSize = 1
  let resNom = buildComputeParticleShaderWgsl(arg_workgroupSize)
  let resEdge = buildComputeParticleShaderWgsl(edge_workgroupSize)
  assertEqInt(resNom.len(), 166, "buildComputeParticleShaderWgsl nominal string length == 166")
  assertEqInt(resEdge.len(), 166, "buildComputeParticleShaderWgsl boundary string length == 166")
  ret 0
```

---

### `createComputeParticlePipeline` (`std/particle/gpu_compute_particles.aipl`)

- **Signature**: `pub fn createComputeParticlePipeline(maxParticles: int = 65536, workgroupSizeX: int = 64): GpuComputeParticlePipeline:`
- **Import**: `import * from "std/particle/gpu_compute_particles"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxParticles: int = 65536, workgroupSizeX: int = 64` | **Returns**: `GpuComputeParticlePipeline`
- **Unit Test**: `tests/functions/particle/gpu_compute_particles_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createComputeParticlePipeline` 64-thread workgroup dispatch sizing and CPU fallback SoA simulation parity. Concrete nominal inputs: `maxParticles: int = 1`, `workgroupSizeX: int = 64`; exercises core body path returning/computing `GpuComputeParticlePipeline(`.

```aipl
module tests.functions.particle.gpu_compute_particles_z3_test
import * from "std/particle/gpu_compute_particles"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_compute_particles_createComputeParticlePipeline_3(): int:
  let arg_maxParticles = 4
  let edge_maxParticles = 1
  let arg_workgroupSizeX = 4
  let edge_workgroupSizeX = 1
  let resNom = createComputeParticlePipeline(arg_maxParticles, arg_workgroupSizeX)
  let resEdge = createComputeParticlePipeline(edge_maxParticles, edge_workgroupSizeX)
  assertEqInt(resNom.wgslSource.len(), 166, "createComputeParticlePipeline nominal string length == 166")
  assertEqInt(resEdge.wgslSource.len(), 166, "createComputeParticlePipeline boundary string length == 166")
  ret 0
```

---

### `spawnGpuParticleSoA` (`std/particle/gpu_compute_particles.aipl`)

- **Signature**: `pub fn spawnGpuParticleSoA(mut soa: GpuParticleSoA, px: float, py: float, pz: float, vx: float, vy: float, vz: float, lifetime: float, rgba: int): GpuParticleSoA:`
- **Import**: `import * from "std/particle/gpu_compute_particles"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut soa: GpuParticleSoA, px: float, py: float, pz: float, vx: float, vy: float, vz: float, lifetime: float, rgba: int` | **Returns**: `GpuParticleSoA`
- **Unit Test**: `tests/functions/particle/gpu_compute_particles_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `spawnGpuParticleSoA` 64-thread workgroup dispatch sizing and CPU fallback SoA simulation parity. Concrete nominal inputs: `soa: GpuParticleSoA = GpuParticleSoA(posX = [1.0], posY = [1.0], posZ = [1.0], velX = [1.0], velY = [1.0], velZ = [1.0], age = [1.0], lifetime = [1.0], colorRgba = [1], capacity = 64, liveCount = 64)`, `px: float = 1.0`, `py: float = 1.0`, `pz: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `vz: float = 1.0`, `lifetime: float = 1.0`, `rgba: int = 1`; exercises core body path returning/computing `soa`.

```aipl
module tests.functions.particle.gpu_compute_particles_z4_test
import * from "std/particle/gpu_compute_particles"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_compute_particles_spawnGpuParticleSoA_4(): int:
  let arg_soa = GpuParticleSoA(posX = [], posY = [], posZ = [], velX = [], velY = [], velZ = [], age = [], lifetime = [], colorRgba = [], capacity = 4, liveCount = 4)
  let edge_soa = GpuParticleSoA(posX = [], posY = [], posZ = [], velX = [], velY = [], velZ = [], age = [], lifetime = [], colorRgba = [], capacity = 4, liveCount = 1)
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_pz = 1.0
  let edge_pz = 0.5
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_vz = 1.0
  let edge_vz = 0.5
  let arg_lifetime = 1.0
  let edge_lifetime = 0.5
  let arg_rgba = 4
  let edge_rgba = 1
  let resNom = spawnGpuParticleSoA(arg_soa, arg_px, arg_py, arg_pz, arg_vx, arg_vy, arg_vz, arg_lifetime, arg_rgba)
  let resEdge = spawnGpuParticleSoA(edge_soa, edge_px, edge_py, edge_pz, edge_vx, edge_vy, edge_vz, edge_lifetime, edge_rgba)
  assertEqInt(resNom.posX.len(), 0, "spawnGpuParticleSoA nominal resNom.posX.len() == 0")
  assertEqInt(resEdge.posX.len(), 0, "spawnGpuParticleSoA boundary resEdge.posX.len() == 0")
  ret 0
```

---

### `stepGpuParticleSoACpuFallback` (`std/particle/gpu_compute_particles.aipl`)

- **Signature**: `pub fn stepGpuParticleSoACpuFallback(mut soa: GpuParticleSoA, dt: float, gravityY: float): GpuParticleSoA:`
- **Import**: `import * from "std/particle/gpu_compute_particles"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut soa: GpuParticleSoA, dt: float, gravityY: float` | **Returns**: `GpuParticleSoA`
- **Unit Test**: `tests/functions/particle/gpu_compute_particles_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `stepGpuParticleSoACpuFallback` 64-thread workgroup dispatch sizing and CPU fallback SoA simulation parity. Concrete nominal inputs: `soa: GpuParticleSoA = GpuParticleSoA(posX = [1.0], posY = [1.0], posZ = [1.0], velX = [1.0], velY = [1.0], velZ = [1.0], age = [1.0], lifetime = [1.0], colorRgba = [1], capacity = 64, liveCount = 64)`, `dt: float = 0.016667`, `gravityY: float = 1.0`; exercises core body path returning/computing `soa`.

```aipl
module tests.functions.particle.gpu_compute_particles_z5_test
import * from "std/particle/gpu_compute_particles"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_compute_particles_stepGpuParticleSoACpuFallback_5(): int:
  let arg_soa = GpuParticleSoA(posX = [], posY = [], posZ = [], velX = [], velY = [], velZ = [], age = [], lifetime = [], colorRgba = [], capacity = 4, liveCount = 4)
  let edge_soa = GpuParticleSoA(posX = [], posY = [], posZ = [], velX = [], velY = [], velZ = [], age = [], lifetime = [], colorRgba = [], capacity = 4, liveCount = 1)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_gravityY = 1.0
  let edge_gravityY = 0.5
  let resNom = stepGpuParticleSoACpuFallback(arg_soa, arg_dt, arg_gravityY)
  let resEdge = stepGpuParticleSoACpuFallback(edge_soa, edge_dt, edge_gravityY)
  assertEqInt(resNom.posX.len(), 0, "stepGpuParticleSoACpuFallback nominal resNom.posX.len() == 0")
  assertEqInt(resEdge.posX.len(), 0, "stepGpuParticleSoACpuFallback boundary resEdge.posX.len() == 0")
  ret 0
```

---

### `createRibbonTrail` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn createRibbonTrail(maxNodes: int = 64, lifetimeSec: float = 1.0, minDistance: float = 0.1): RibbonTrail:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxNodes: int = 64, lifetimeSec: float = 1.0, minDistance: float = 0.1` | **Returns**: `RibbonTrail`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `createRibbonTrail` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `maxNodes: int = 1`, `lifetimeSec: float = 1.0`, `minDistance: float = 1.0`; exercises core body path returning/computing `RibbonTrail(`.

```aipl
module tests.functions.particle.ribbon_trail_z1_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_createRibbonTrail_1(): int:
  let arg_maxNodes = 4
  let edge_maxNodes = 1
  let arg_lifetimeSec = 1.0
  let edge_lifetimeSec = 0.5
  let arg_minDistance = 0.0
  let edge_minDistance = 0.0
  let resNom = createRibbonTrail(arg_maxNodes, arg_lifetimeSec, arg_minDistance)
  let resEdge = createRibbonTrail(edge_maxNodes, edge_lifetimeSec, edge_minDistance)
  assertEqInt(resNom.nodes.len(), 0, "createRibbonTrail nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "createRibbonTrail boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `pushRibbonPosition` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn pushRibbonPosition(trail: RibbonTrail, pos: Vec3, width: float): RibbonTrail:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trail: RibbonTrail, pos: Vec3, width: float` | **Returns**: `RibbonTrail`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `pushRibbonPosition` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `trail: RibbonTrail = RibbonTrail(nodes = [RibbonNode(position = 0, normal = 0, width = 0, ageSec = 0)], maxNodes = 1, lifetimeSec = 1.0, minDistance = 1.0)`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `width: float = 0.016667`; exercises core body path returning/computing `RibbonTrail(`.

```aipl
module tests.functions.particle.ribbon_trail_z2_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_pushRibbonPosition_2(): int:
  let arg_trail = RibbonTrail(nodes = [], maxNodes = 4, lifetimeSec = 1.0, minDistance = 0.0)
  let edge_trail = RibbonTrail(nodes = [], maxNodes = 1, lifetimeSec = 0.5, minDistance = 0.0)
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_width = 2.0
  let edge_width = 1.0
  let resNom = pushRibbonPosition(arg_trail, arg_pos, arg_width)
  let resEdge = pushRibbonPosition(edge_trail, edge_pos, edge_width)
  assertEqInt(resNom.nodes.len(), 1, "pushRibbonPosition nominal resNom.nodes.len() == 1")
  assertEqInt(resEdge.nodes.len(), 1, "pushRibbonPosition boundary resEdge.nodes.len() == 1")
  ret 0
```

---

### `updateRibbonTrail` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn updateRibbonTrail(trail: RibbonTrail, dt: float): RibbonTrail:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trail: RibbonTrail, dt: float` | **Returns**: `RibbonTrail`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `updateRibbonTrail` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `trail: RibbonTrail = RibbonTrail(nodes = [RibbonNode(position = 0, normal = 0, width = 0, ageSec = 0)], maxNodes = 1, lifetimeSec = 1.0, minDistance = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `RibbonTrail(`.

```aipl
module tests.functions.particle.ribbon_trail_z3_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_updateRibbonTrail_3(): int:
  let arg_trail = RibbonTrail(nodes = [], maxNodes = 4, lifetimeSec = 1.0, minDistance = 0.0)
  let edge_trail = RibbonTrail(nodes = [], maxNodes = 1, lifetimeSec = 0.5, minDistance = 0.0)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = updateRibbonTrail(arg_trail, arg_dt)
  let resEdge = updateRibbonTrail(edge_trail, edge_dt)
  assertEqInt(resNom.nodes.len(), 0, "updateRibbonTrail nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "updateRibbonTrail boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `generateRibbonQuadStrip` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn generateRibbonQuadStrip(trail: RibbonTrail, cameraPos: Vec3, color: ColorRgba8): [RibbonMeshVertex]:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trail: RibbonTrail, cameraPos: Vec3, color: ColorRgba8` | **Returns**: `[RibbonMeshVertex]`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `generateRibbonQuadStrip` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `trail: RibbonTrail = RibbonTrail(nodes = [RibbonNode(position = 0, normal = 0, width = 0, ageSec = 0)], maxNodes = 1, lifetimeSec = 1.0, minDistance = 1.0)`, `cameraPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `color: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `verts`.

```aipl
module tests.functions.particle.ribbon_trail_z4_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_generateRibbonQuadStrip_4(): int:
  let arg_trail = RibbonTrail(nodes = [], maxNodes = 4, lifetimeSec = 1.0, minDistance = 0.0)
  let edge_trail = RibbonTrail(nodes = [], maxNodes = 1, lifetimeSec = 0.5, minDistance = 0.0)
  let arg_cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_cameraPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_color = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_color = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = generateRibbonQuadStrip(arg_trail, arg_cameraPos, arg_color)
  let resEdge = generateRibbonQuadStrip(edge_trail, edge_cameraPos, edge_color)
  assertEqInt(resNom.len(), 0, "generateRibbonQuadStrip nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "generateRibbonQuadStrip boundary resEdge.len() == 0")
  ret 0
```

---

### `clearRibbonTrail` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn clearRibbonTrail(trail: RibbonTrail): RibbonTrail:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trail: RibbonTrail` | **Returns**: `RibbonTrail`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `clearRibbonTrail` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `trail: RibbonTrail = RibbonTrail(nodes = [RibbonNode(position = 0, normal = 0, width = 0, ageSec = 0)], maxNodes = 1, lifetimeSec = 1.0, minDistance = 1.0)`; exercises core body path returning/computing `RibbonTrail(`.

```aipl
module tests.functions.particle.ribbon_trail_z5_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_clearRibbonTrail_5(): int:
  let arg_trail = RibbonTrail(nodes = [], maxNodes = 4, lifetimeSec = 1.0, minDistance = 0.0)
  let edge_trail = RibbonTrail(nodes = [], maxNodes = 1, lifetimeSec = 0.5, minDistance = 0.0)
  let resNom = clearRibbonTrail(arg_trail)
  let resEdge = clearRibbonTrail(edge_trail)
  assertEqInt(resNom.nodes.len(), 0, "clearRibbonTrail nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "clearRibbonTrail boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `ribbonTrailLength` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn ribbonTrailLength(trail: RibbonTrail): float:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trail: RibbonTrail` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `ribbonTrailLength` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `trail: RibbonTrail = RibbonTrail(nodes = [RibbonNode(position = 0, normal = 0, width = 0, ageSec = 0)], maxNodes = 1, lifetimeSec = 1.0, minDistance = 1.0)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.particle.ribbon_trail_z6_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_ribbonTrailLength_6(): int:
  let arg_trail = RibbonTrail(nodes = [], maxNodes = 4, lifetimeSec = 1.0, minDistance = 0.0)
  let edge_trail = RibbonTrail(nodes = [], maxNodes = 1, lifetimeSec = 0.5, minDistance = 0.0)
  let resNom = ribbonTrailLength(arg_trail)
  let resEdge = ribbonTrailLength(edge_trail)
  assertApproxEq(resNom, 0.0, 0.001, "ribbonTrailLength nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "ribbonTrailLength boundary resEdge ~= 0.0")
  ret 0
```

---

### `fxUpdateParticleTrailNodeX` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn fxUpdateParticleTrailNodeX(prevX: float, targetX: float, followFactor: float): float:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prevX: float, targetX: float, followFactor: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `fxUpdateParticleTrailNodeX` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `prevX: float = 1.0`, `targetX: float = 1.0`, `followFactor: float = 1.0`; exercises core body path returning/computing `prevX + (targetX - prevX) * followFactor`.

```aipl
module tests.functions.particle.ribbon_trail_z7_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_fxUpdateParticleTrailNodeX_7(): int:
  let arg_prevX = 1.0
  let edge_prevX = 0.5
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_followFactor = 0.0
  let edge_followFactor = 0.0
  let resNom = fxUpdateParticleTrailNodeX(arg_prevX, arg_targetX, arg_followFactor)
  let resEdge = fxUpdateParticleTrailNodeX(edge_prevX, edge_targetX, edge_followFactor)
  assertApproxEq(resNom, 1.0, 0.001, "fxUpdateParticleTrailNodeX nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "fxUpdateParticleTrailNodeX boundary resEdge ~= 0.5")
  ret 0
```

---

### `fxUpdateParticleTrailNodeY` (`std/particle/ribbon_trail.aipl`)

- **Signature**: `pub fn fxUpdateParticleTrailNodeY(prevY: float, targetY: float, followFactor: float): float:`
- **Import**: `import * from "std/particle/ribbon_trail"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prevY: float, targetY: float, followFactor: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/particle/ribbon_trail_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `fxUpdateParticleTrailNodeY` ribbon trail ring-buffer node insertion, age pruning, and perpendicular triangle-strip quad extrusion. Concrete nominal inputs: `prevY: float = 1.0`, `targetY: float = 1.0`, `followFactor: float = 1.0`; exercises core body path returning/computing `prevY + (targetY - prevY) * followFactor`.

```aipl
module tests.functions.particle.ribbon_trail_z8_test
import * from "std/particle/ribbon_trail"
import { EPSILON, maxFloat } from "std/math/consts"
import { Vec2, Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ribbon_trail_fxUpdateParticleTrailNodeY_8(): int:
  let arg_prevY = 1.0
  let edge_prevY = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_followFactor = 0.0
  let edge_followFactor = 0.0
  let resNom = fxUpdateParticleTrailNodeY(arg_prevY, arg_targetY, arg_followFactor)
  let resEdge = fxUpdateParticleTrailNodeY(edge_prevY, edge_targetY, edge_followFactor)
  assertApproxEq(resNom, 1.0, 0.001, "fxUpdateParticleTrailNodeY nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "fxUpdateParticleTrailNodeY boundary resEdge ~= 0.5")
  ret 0
```

---

### `bindSubEmitter` (`std/particle/sub_emitter.aipl`)

- **Signature**: `pub fn bindSubEmitter(trigger: int, childPoolId: int, count: int, inheritVel: float = 0.0): SubEmitterBinding:`
- **Import**: `import * from "std/particle/sub_emitter"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `trigger: int, childPoolId: int, count: int, inheritVel: float = 0.0` | **Returns**: `SubEmitterBinding`
- **Unit Test**: `tests/functions/particle/sub_emitter_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `bindSubEmitter` parent particle `OnDeath`/`OnCollision` event triggering and child burst inheritance of parent position and velocity. Concrete nominal inputs: `trigger: int = 1`, `childPoolId: int = 1`, `count: int = 64`, `inheritVel: float = 1.0`; exercises core body path returning/computing `SubEmitterBinding(`.

```aipl
module tests.functions.particle.sub_emitter_z1_test
import * from "std/particle/sub_emitter"
import { TAU, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Particle3D, ParticlePool3D, spawnParticle3D } from "std/particle/emitter3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sub_emitter_bindSubEmitter_1(): int:
  let arg_trigger = 2
  let edge_trigger = 0
  let arg_childPoolId = 1
  let edge_childPoolId = 0
  let arg_count = 4
  let edge_count = 1
  let arg_inheritVel = 2.0
  let edge_inheritVel = 1.0
  let resNom = bindSubEmitter(arg_trigger, arg_childPoolId, arg_count, arg_inheritVel)
  let resEdge = bindSubEmitter(edge_trigger, edge_childPoolId, edge_count, edge_inheritVel)
  assertEqInt(resNom.triggerEvent, 2, "bindSubEmitter nominal resNom.triggerEvent == 2")
  assertEqInt(resEdge.triggerEvent, 0, "bindSubEmitter boundary resEdge.triggerEvent == 0")
  ret 0
```

---

### `dispatchSubEmitterEvent` (`std/particle/sub_emitter.aipl`)

- **Signature**: `pub fn dispatchSubEmitterEvent(binding: SubEmitterBinding, parentPos: Vec3, parentVel: Vec3): [Particle3D]:`
- **Import**: `import * from "std/particle/sub_emitter"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `binding: SubEmitterBinding, parentPos: Vec3, parentVel: Vec3` | **Returns**: `[Particle3D]`
- **Unit Test**: `tests/functions/particle/sub_emitter_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `dispatchSubEmitterEvent` parent particle `OnDeath`/`OnCollision` event triggering and child burst inheritance of parent position and velocity. Concrete nominal inputs: `binding: SubEmitterBinding = SubEmitterBinding(triggerEvent = 1, childPoolId = 1, burstCount = 64, inheritVelocityFactor = 1.0)`, `parentPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `parentVel: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `spawned`.

```aipl
module tests.functions.particle.sub_emitter_z2_test
import * from "std/particle/sub_emitter"
import { TAU, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Particle3D, ParticlePool3D, spawnParticle3D } from "std/particle/emitter3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sub_emitter_dispatchSubEmitterEvent_2(): int:
  let arg_binding = SubEmitterBinding(triggerEvent = 4, childPoolId = 1, burstCount = 4, inheritVelocityFactor = 0.0)
  let edge_binding = SubEmitterBinding(triggerEvent = 1, childPoolId = 0, burstCount = 1, inheritVelocityFactor = 0.0)
  let arg_parentPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_parentPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_parentVel = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_parentVel = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = dispatchSubEmitterEvent(arg_binding, arg_parentPos, arg_parentVel)
  let resEdge = dispatchSubEmitterEvent(edge_binding, edge_parentPos, edge_parentVel)
  assertEqInt(resNom.len(), 4, "dispatchSubEmitterEvent nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "dispatchSubEmitterEvent boundary resEdge.len() == 1")
  ret 0
```

---

### `shouldTriggerSubEmitter` (`std/particle/sub_emitter.aipl`)

- **Signature**: `pub fn shouldTriggerSubEmitter(binding: SubEmitterBinding, eventKind: int): bool:`
- **Import**: `import * from "std/particle/sub_emitter"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `binding: SubEmitterBinding, eventKind: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/particle/sub_emitter_test.aipl` | **Example**: `examples/ex_185_particle_affector_vortex_and_attractor_window.aipl`
- **Behavioral Summary**: Verify `shouldTriggerSubEmitter` parent particle `OnDeath`/`OnCollision` event triggering and child burst inheritance of parent position and velocity. Concrete nominal inputs: `binding: SubEmitterBinding = SubEmitterBinding(triggerEvent = 1, childPoolId = 1, burstCount = 64, inheritVelocityFactor = 1.0)`, `eventKind: int = 1`; exercises core body path returning/computing `binding.triggerEvent == eventKind and binding.burstCount > 0`.

```aipl
module tests.functions.particle.sub_emitter_z3_test
import * from "std/particle/sub_emitter"
import { TAU, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Particle3D, ParticlePool3D, spawnParticle3D } from "std/particle/emitter3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sub_emitter_shouldTriggerSubEmitter_3(): int:
  let arg_binding = SubEmitterBinding(triggerEvent = 4, childPoolId = 1, burstCount = 4, inheritVelocityFactor = 0.0)
  let edge_binding = SubEmitterBinding(triggerEvent = 1, childPoolId = 0, burstCount = 1, inheritVelocityFactor = 0.0)
  let arg_eventKind = 4
  let edge_eventKind = 1
  let resNom = shouldTriggerSubEmitter(arg_binding, arg_eventKind)
  let resEdge = shouldTriggerSubEmitter(edge_binding, edge_eventKind)
  assert(resNom == true, "shouldTriggerSubEmitter nominal resNom == true")
  assert(resEdge == true, "shouldTriggerSubEmitter boundary resEdge == true")
  ret 0
```

---

### `dispatchSubEmitterCone` (`std/particle/sub_emitter.aipl`)

- **Signature**: `pub fn dispatchSubEmitterCone(binding: SubEmitterBinding, parentPos: Vec3, dir: Vec3, speed: float, lifetimeSec: float): [Particle3D]:`
- **Import**: `import * from "std/particle/sub_emitter"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `binding: SubEmitterBinding, parentPos: Vec3, dir: Vec3, speed: float, lifetimeSec: float` | **Returns**: `[Particle3D]`
- **Unit Test**: `tests/functions/particle/sub_emitter_test.aipl` | **Example**: `examples/ex_186_particle_curve_prop_color_over_life_window.aipl`
- **Behavioral Summary**: Verify `dispatchSubEmitterCone` parent particle `OnDeath`/`OnCollision` event triggering and child burst inheritance of parent position and velocity. Concrete nominal inputs: `binding: SubEmitterBinding = SubEmitterBinding(triggerEvent = 1, childPoolId = 1, burstCount = 64, inheritVelocityFactor = 1.0)`, `parentPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `dir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `speed: float = 1.0`, `lifetimeSec: float = 1.0`; exercises core body path returning/computing `spawned`.

```aipl
module tests.functions.particle.sub_emitter_z4_test
import * from "std/particle/sub_emitter"
import { TAU, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Particle3D, ParticlePool3D, spawnParticle3D } from "std/particle/emitter3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sub_emitter_dispatchSubEmitterCone_4(): int:
  let arg_binding = SubEmitterBinding(triggerEvent = 4, childPoolId = 1, burstCount = 4, inheritVelocityFactor = 0.0)
  let edge_binding = SubEmitterBinding(triggerEvent = 1, childPoolId = 0, burstCount = 1, inheritVelocityFactor = 0.0)
  let arg_parentPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_parentPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_dir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_dir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_speed = 1.0
  let edge_speed = 0.5
  let arg_lifetimeSec = 1.0
  let edge_lifetimeSec = 0.5
  let resNom = dispatchSubEmitterCone(arg_binding, arg_parentPos, arg_dir, arg_speed, arg_lifetimeSec)
  let resEdge = dispatchSubEmitterCone(edge_binding, edge_parentPos, edge_dir, edge_speed, edge_lifetimeSec)
  assertEqInt(resNom.len(), 4, "dispatchSubEmitterCone nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "dispatchSubEmitterCone boundary resEdge.len() == 1")
  ret 0
```

---

### `mergeSubEmitterSpawn3D` (`std/particle/sub_emitter.aipl`)

- **Signature**: `pub fn mergeSubEmitterSpawn3D(pool: ParticlePool3D, spawned: [Particle3D]): ParticlePool3D:`
- **Import**: `import * from "std/particle/sub_emitter"` (or barrel `import * from "std/particle/particle_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: ParticlePool3D, spawned: [Particle3D]` | **Returns**: `ParticlePool3D`
- **Unit Test**: `tests/functions/particle/sub_emitter_test.aipl` | **Example**: `examples/ex_184_particle_emitter3d_starfield_and_snow_window.aipl`
- **Behavioral Summary**: Verify `mergeSubEmitterSpawn3D` parent particle `OnDeath`/`OnCollision` event triggering and child burst inheritance of parent position and velocity. Concrete nominal inputs: `pool: ParticlePool3D = ParticlePool3D(particles = [Particle3D(pos = 0, vel = 0, color = 0, size = 0, ageSec = 0, lifetimeSec = 0, isAlive = 0)], maxParticles = 1, liveCount = 64, emissionRate = 1.0, emissionAccumulator = 1.0)`, `spawned: [Particle3D] = [Particle3D(pos = Vec3(x = 0, y = 0, z = 0), vel = Vec3(x = 0, y = 0, z = 0), color = ColorRgba8(r = 0, g = 0, b = 0, a = 0), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)]`; exercises core body path returning/computing `cur`.

```aipl
module tests.functions.particle.sub_emitter_z5_test
import * from "std/particle/sub_emitter"
import { TAU, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8 } from "std/gfx/color"
import { Particle3D, ParticlePool3D, spawnParticle3D } from "std/particle/emitter3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sub_emitter_mergeSubEmitterSpawn3D_5(): int:
  let arg_pool = ParticlePool3D(particles = [], maxParticles = 4, liveCount = 4, emissionRate = 2.0, emissionAccumulator = 1.0)
  let edge_pool = ParticlePool3D(particles = [], maxParticles = 1, liveCount = 1, emissionRate = 1.0, emissionAccumulator = 0.5)
  let arg_spawned = [Particle3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), vel = Vec3(x = 1.0, y = 1.0, z = 1.0), color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), size = 1.0, ageSec = 1.0, lifetimeSec = 1.0, isAlive = true)]
  let edge_spawned = []
  let resNom = mergeSubEmitterSpawn3D(arg_pool, arg_spawned)
  let resEdge = mergeSubEmitterSpawn3D(edge_pool, edge_spawned)
  assertEqInt(resNom.particles.len(), 1, "mergeSubEmitterSpawn3D nominal resNom.particles.len() == 1")
  assertEqInt(resEdge.particles.len(), 0, "mergeSubEmitterSpawn3D boundary resEdge.particles.len() == 0")
  ret 0
```
