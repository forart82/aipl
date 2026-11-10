[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 32: `phys2d` API Reference

> Complete API reference manual for AIPL standard library domain `phys2d` (46 callable functions & methods across ["std/phys2d/broadphase2d.aipl", "std/phys2d/collider2d.aipl", "std/phys2d/fluid2d.aipl", "std/phys2d/joint2d.aipl", "std/phys2d/narrowphase2d.aipl", "std/phys2d/phys2d_mod.aipl", "std/phys2d/phys_query2d.aipl", "std/phys2d/phys_world2d.aipl", "std/phys2d/rigid_body2d.aipl", "std/phys2d/verlet2d.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `phys2d`
- **Target Source Modules**: ["std/phys2d/broadphase2d.aipl", "std/phys2d/collider2d.aipl", "std/phys2d/fluid2d.aipl", "std/phys2d/joint2d.aipl", "std/phys2d/narrowphase2d.aipl", "std/phys2d/phys2d_mod.aipl", "std/phys2d/phys_query2d.aipl", "std/phys2d/phys_world2d.aipl", "std/phys2d/rigid_body2d.aipl", "std/phys2d/verlet2d.aipl"]
- **Total Callable Functions & Methods**: 46
- **Total Data Types (`struct` & `enum`)**: 22
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(22 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BroadphasePair2D` | `pub struct` | `std/phys2d/broadphase2d.aipl` | `bodyIdA: int`, `bodyIdB: int`, `colliderIdxA: int`, `colliderIdxB: int` | `BroadphasePair2D(bodyIdA, bodyIdB, colliderIdxA, colliderIdxB)` |
| `DynamicAABBNode2D` | `pub struct` | `std/phys2d/broadphase2d.aipl` | `aabb: Rect2D`, `bodyId: int`, `parent: int`, `child1: int`, `child2: int`, `height: int`, `active: bool` | `DynamicAABBNode2D(aabb, bodyId, parent, child1, child2, height, active)` |
| `DynamicAABBTree2D` | `pub struct` | `std/phys2d/broadphase2d.aipl` | `nodes: [DynamicAABBNode2D]`, `root: int`, `freeList: int` | `DynamicAABBTree2D(nodes, root, freeList)` |
| `ColliderShapeType2D` | `pub enum` | `std/phys2d/collider2d.aipl` | `Circle`, `Box`, `Capsule`, `ConvexPolygon`, `Segment` | Algebraic Enum (5 variants) |
| `PhysicsMaterial2D` | `pub struct` | `std/phys2d/collider2d.aipl` | `restitution: float`, `friction: float`, `density: float` | `PhysicsMaterial2D(restitution, friction, density)` |
| `Collider2D` | `pub struct` | `std/phys2d/collider2d.aipl` | `shapeType: ColliderShapeType2D`, `offset: Vec2`, `circleRadius: float`, `boxHalfExtents: Vec2`, `capsuleLength: float`, `polygonVertices: [Vec2]`, `material: PhysicsMaterial2D`, `isSensor: bool`, `collisionLayer: int`, `collisionMask: int` | `Collider2D(shapeType, offset, circleRadius, boxHalfExtents, capsuleLength, polygonVertices, material, isSensor, collisionLayer, collisionMask)` |
| `SphParticle2D` | `pub struct` | `std/phys2d/fluid2d.aipl` | `position: Vec2`, `velocity: Vec2`, `force: Vec2`, `density: float`, `pressure: float` | `SphParticle2D(position, velocity, force, density, pressure)` |
| `SphFluidWorld2D` | `pub struct` | `std/phys2d/fluid2d.aipl` | `particles: [SphParticle2D]`, `smoothingRadius: float`, `restDensity: float`, `gasStiffness: float`, `viscosity: float` | `SphFluidWorld2D(particles, smoothingRadius, restDensity, gasStiffness, viscosity)` |
| `CellularSandGrid2D` | `pub struct` | `std/phys2d/fluid2d.aipl` | `width: int`, `height: int`, `cells: [int]` | `CellularSandGrid2D(width, height, cells)` |
| `JointType2D` | `pub enum` | `std/phys2d/joint2d.aipl` | `Distance`, `Revolute`, `Prismatic`, `Rope`, `Spring` | Algebraic Enum (5 variants) |
| `Joint2D` | `pub struct` | `std/phys2d/joint2d.aipl` | `id: int`, `jointType: JointType2D`, `bodyIdA: int`, `bodyIdB: int`, `localAnchorA: Vec2`, `localAnchorB: Vec2`, `targetDistance: float`, `springStiffness: float`, `springDamping: float`, `minLimit: float`, `maxLimit: float`, `enableLimits: bool` | `Joint2D(id, jointType, bodyIdA, bodyIdB, localAnchorA, localAnchorB, targetDistance, springStiffness, springDamping, minLimit, maxLimit, enableLimits)` |
| `ContactPoint2D` | `pub struct` | `std/phys2d/narrowphase2d.aipl` | `position: Vec2`, `normal: Vec2`, `penetration: float`, `normalImpulse: float`, `tangentImpulse: float` | `ContactPoint2D(position, normal, penetration, normalImpulse, tangentImpulse)` |
| `ContactManifold2D` | `pub struct` | `std/phys2d/narrowphase2d.aipl` | `bodyIdA: int`, `bodyIdB: int`, `normal: Vec2`, `points: [ContactPoint2D]`, `isColliding: bool` | `ContactManifold2D(bodyIdA, bodyIdB, normal, points, isColliding)` |
| `RayHit2D` | `pub struct` | `std/phys2d/phys_query2d.aipl` | `bodyId: int`, `point: Vec2`, `normal: Vec2`, `fraction: float`, `hit: bool` | `RayHit2D(bodyId, point, normal, fraction, hit)` |
| `PhysWorldSettings2D` | `pub struct` | `std/phys2d/phys_world2d.aipl` | `gravity: Vec2`, `velocityIterations: int`, `positionIterations: int`, `subSteps: int`, `allowSleep: bool` | `PhysWorldSettings2D(gravity, velocityIterations, positionIterations, subSteps, allowSleep)` |
| `PhysicsWorld2D` | `pub struct` | `std/phys2d/phys_world2d.aipl` | `settings: PhysWorldSettings2D`, `bodies: [RigidBody2D]`, `colliders: [Collider2D]`, `colliderBodyIds: [int]`, `joints: [Joint2D]`, `broadphase: DynamicAABBTree2D` | `PhysicsWorld2D(settings, bodies, colliders, colliderBodyIds, joints, broadphase)` |
| `BodyType2D` | `pub enum` | `std/phys2d/rigid_body2d.aipl` | `Static`, `Kinematic`, `Dynamic` | Algebraic Enum (3 variants) |
| `MassProperties2D` | `pub struct` | `std/phys2d/rigid_body2d.aipl` | `mass: float`, `invMass: float`, `inertia: float`, `invInertia: float`, `localCenter: Vec2` | `MassProperties2D(mass, invMass, inertia, invInertia, localCenter)` |
| `RigidBody2D` | `pub struct` | `std/phys2d/rigid_body2d.aipl` | `id: int`, `bodyType: BodyType2D`, `position: Vec2`, `angle: float`, `linearVelocity: Vec2`, `angularVelocity: float`, `linearDamping: float`, `angularDamping: float`, `gravityScale: float`, `massProps: MassProperties2D`, `isAwake: bool`, `isBullet: bool` | `RigidBody2D(id, bodyType, position, angle, linearVelocity, angularVelocity, linearDamping, angularDamping, gravityScale, massProps, isAwake, isBullet)` |
| `VerletParticle2D` | `pub struct` | `std/phys2d/verlet2d.aipl` | `position: Vec2`, `prevPosition: Vec2`, `acceleration: Vec2`, `isPinned: bool` | `VerletParticle2D(position, prevPosition, acceleration, isPinned)` |
| `VerletStick2D` | `pub struct` | `std/phys2d/verlet2d.aipl` | `p1Idx: int`, `p2Idx: int`, `restLength: float`, `stiffness: float` | `VerletStick2D(p1Idx, p2Idx, restLength, stiffness)` |
| `VerletClothGrid2D` | `pub struct` | `std/phys2d/verlet2d.aipl` | `particles: [VerletParticle2D]`, `sticks: [VerletStick2D]`, `cols: int`, `rows: int` | `VerletClothGrid2D(particles, sticks, cols, rows)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/phys2d/broadphase2d.aipl` | `dynamicAABBTreeNew` | `pub fn dynamicAABBTreeNew(): DynamicAABBTree2D:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `2` | `std/phys2d/broadphase2d.aipl` | `fattenRect2D` | `fn fattenRect2D(r: Rect2D, margin: float): Rect2D:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `3` | `std/phys2d/broadphase2d.aipl` | `rectContainsOther` | `fn rectContainsOther(outer: Rect2D, inner: Rect2D): bool:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `4` | `std/phys2d/broadphase2d.aipl` | `rectsOverlap2D` | `fn rectsOverlap2D(a: Rect2D, b: Rect2D): bool:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `5` | `std/phys2d/broadphase2d.aipl` | `dynamicAABBTreeInsert` | `pub fn dynamicAABBTreeInsert(mut tree: DynamicAABBTree2D, bodyId: int, aabb: Rect2D): int:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `6` | `std/phys2d/broadphase2d.aipl` | `dynamicAABBTreeUpdate` | `pub fn dynamicAABBTreeUpdate(mut tree: DynamicAABBTree2D, nodeId: int, newAABB: Rect2D, velocity: Vec2): bool:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `7` | `std/phys2d/broadphase2d.aipl` | `dynamicAABBTreeRemove` | `pub fn dynamicAABBTreeRemove(mut tree: DynamicAABBTree2D, nodeId: int): void:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `8` | `std/phys2d/broadphase2d.aipl` | `dynamicAABBTreeFindPairs` | `pub fn dynamicAABBTreeFindPairs(tree: DynamicAABBTree2D): [BroadphasePair2D]:` | `tests/functions/phys2d/broadphase2d_test.aipl` |
| `9` | `std/phys2d/collider2d.aipl` | `circleColliderNew` | `pub fn circleColliderNew(radius: float, material: PhysicsMaterial2D): Collider2D:` | `tests/functions/phys2d/collider2d_test.aipl` |
| `10` | `std/phys2d/collider2d.aipl` | `boxColliderNew` | `pub fn boxColliderNew(width: float, height: float, material: PhysicsMaterial2D): Collider2D:` | `tests/functions/phys2d/collider2d_test.aipl` |
| `11` | `std/phys2d/collider2d.aipl` | `capsuleColliderNew` | `pub fn capsuleColliderNew(radius: float, length: float, material: PhysicsMaterial2D): Collider2D:` | `tests/functions/phys2d/collider2d_test.aipl` |
| `12` | `std/phys2d/collider2d.aipl` | `polygonColliderNew` | `pub fn polygonColliderNew(vertices: [Vec2], material: PhysicsMaterial2D): Collider2D:` | `tests/functions/phys2d/collider2d_test.aipl` |
| `13` | `std/phys2d/collider2d.aipl` | `colliderComputeAABB` | `pub fn colliderComputeAABB(collider: Collider2D, bodyPos: Vec2, bodyAngle: float): Rect2D:` | `tests/functions/phys2d/collider2d_test.aipl` |
| `14` | `std/phys2d/fluid2d.aipl` | `sphFluidWorldNew` | `pub fn sphFluidWorldNew(smoothingRadius: float, restDensity: float, stiffness: float, viscosity: float): SphFluidWorld2D:` | `tests/functions/phys2d/fluid2d_test.aipl` |
| `15` | `std/phys2d/fluid2d.aipl` | `sphFluidStep` | `pub fn sphFluidStep(mut world: SphFluidWorld2D, gravity: Vec2, dt: float): void:` | `tests/functions/phys2d/fluid2d_test.aipl` |
| `16` | `std/phys2d/fluid2d.aipl` | `cellularSandStep` | `pub fn cellularSandStep(mut grid: CellularSandGrid2D): int:` | `tests/functions/phys2d/fluid2d_test.aipl` |
| `17` | `std/phys2d/joint2d.aipl` | `distanceJointNew` | `pub fn distanceJointNew(bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, distance: float): Joint2D:` | `tests/functions/phys2d/joint2d_test.aipl` |
| `18` | `std/phys2d/joint2d.aipl` | `springJointNew` | `pub fn springJointNew(bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, restLength: float, stiffness: float, damping: float): Joint2D:` | `tests/functions/phys2d/joint2d_test.aipl` |
| `19` | `std/phys2d/joint2d.aipl` | `revoluteJointNew` | `pub fn revoluteJointNew(bodyIdA: int, bodyIdB: int, worldAnchor: Vec2): Joint2D:` | `tests/functions/phys2d/joint2d_test.aipl` |
| `20` | `std/phys2d/joint2d.aipl` | `jointSolveVelocity` | `pub fn jointSolveVelocity(joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D, dt: float): void:` | `tests/functions/phys2d/joint2d_test.aipl` |
| `21` | `std/phys2d/joint2d.aipl` | `jointSolvePosition` | `pub fn jointSolvePosition(joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D): void:` | `tests/functions/phys2d/joint2d_test.aipl` |
| `22` | `std/phys2d/narrowphase2d.aipl` | `testCircleCircle` | `pub fn testCircleCircle(posA: Vec2, radA: float, posB: Vec2, radB: float): Option[ContactManifold2D]:` | `tests/functions/phys2d/narrowphase2d_test.aipl` |
| `23` | `std/phys2d/narrowphase2d.aipl` | `testCircleBoxSAT` | `pub fn testCircleBoxSAT(circlePos: Vec2, radius: float, boxPos: Vec2, boxExtents: Vec2, boxAngle: float): Option[ContactManifold2D]:` | `tests/functions/phys2d/narrowphase2d_test.aipl` |
| `24` | `std/phys2d/narrowphase2d.aipl` | `buildBoxVerts2D` | `fn buildBoxVerts2D(pos: Vec2, ext: Vec2, rot: float): [Vec2]:` | `tests/functions/phys2d/narrowphase2d_test.aipl` |
| `25` | `std/phys2d/narrowphase2d.aipl` | `testGjkEpa2D` | `pub fn testGjkEpa2D(vertsA: [Vec2], vertsB: [Vec2]): Option[ContactManifold2D]:` | `tests/functions/phys2d/narrowphase2d_test.aipl` |
| `26` | `std/phys2d/narrowphase2d.aipl` | `testBoxBoxSAT` | `pub fn testBoxBoxSAT(posA: Vec2, extA: Vec2, rotA: float, posB: Vec2, extB: Vec2, rotB: float): Option[ContactManifold2D]:` | `tests/functions/phys2d/narrowphase2d_test.aipl` |
| `27` | `std/phys2d/phys_query2d.aipl` | `extractRayDir2D` | `fn extractRayDir2D(ray: Ray2D): Vec2:` | `tests/functions/phys2d/phys_query2d_test.aipl` |
| `28` | `std/phys2d/phys_query2d.aipl` | `raycast2dSegment` | `pub fn raycast2dSegment(ray: Ray2D, segA: Vec2, segB: Vec2): Option[RayHit2D]:` | `tests/functions/phys2d/phys_query2d_test.aipl` |
| `29` | `std/phys2d/phys_query2d.aipl` | `raycast2dCircle` | `pub fn raycast2dCircle(ray: Ray2D, center: Vec2, radius: float): Option[RayHit2D]:` | `tests/functions/phys2d/phys_query2d_test.aipl` |
| `30` | `std/phys2d/phys_query2d.aipl` | `raycast2dBox` | `pub fn raycast2dBox(ray: Ray2D, boxPos: Vec2, boxExtents: Vec2, boxAngle: float): Option[RayHit2D]:` | `tests/functions/phys2d/phys_query2d_test.aipl` |
| `31` | `std/phys2d/phys_query2d.aipl` | `shapeCastCircle2D` | `pub fn shapeCastCircle2D(startPos: Vec2, radius: float, delta: Vec2, colliders: [Collider2D]): Option[RayHit2D]:` | `tests/functions/phys2d/phys_query2d_test.aipl` |
| `32` | `std/phys2d/phys_world2d.aipl` | `physWorld2dNew` | `pub fn physWorld2dNew(gravity: Vec2): PhysicsWorld2D:` | `tests/functions/phys2d/phys_world2d_test.aipl` |
| `33` | `std/phys2d/phys_world2d.aipl` | `physWorld2dAddBody` | `pub fn physWorld2dAddBody(mut world: PhysicsWorld2D, body: RigidBody2D): int:` | `tests/functions/phys2d/phys_world2d_test.aipl` |
| `34` | `std/phys2d/phys_world2d.aipl` | `physWorld2dAddCollider` | `pub fn physWorld2dAddCollider(mut world: PhysicsWorld2D, bodyId: int, collider: Collider2D): int:` | `tests/functions/phys2d/phys_world2d_test.aipl` |
| `35` | `std/phys2d/phys_world2d.aipl` | `physWorld2dAddJoint` | `pub fn physWorld2dAddJoint(mut world: PhysicsWorld2D, joint: Joint2D): int:` | `tests/functions/phys2d/phys_world2d_test.aipl` |
| `36` | `std/phys2d/phys_world2d.aipl` | `physWorld2dStep` | `pub fn physWorld2dStep(mut world: PhysicsWorld2D, dt: float): void:` | `tests/functions/phys2d/phys_world2d_test.aipl` |
| `37` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dNew` | `pub fn rigidBody2dNew(id: int, bodyType: BodyType2D, position: Vec2, angle: float): RigidBody2D:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `38` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dSetMass` | `pub fn rigidBody2dSetMass(mut body: RigidBody2D, mass: float, inertia: float): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `39` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dApplyForce` | `pub fn rigidBody2dApplyForce(mut body: RigidBody2D, force: Vec2, worldPoint: Vec2): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `40` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dApplyLinearImpulse` | `pub fn rigidBody2dApplyLinearImpulse(mut body: RigidBody2D, impulse: Vec2): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `41` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dApplyAngularImpulse` | `pub fn rigidBody2dApplyAngularImpulse(mut body: RigidBody2D, impulse: float): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `42` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dIntegrateVelocity` | `pub fn rigidBody2dIntegrateVelocity(mut body: RigidBody2D, gravity: Vec2, dt: float): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `43` | `std/phys2d/rigid_body2d.aipl` | `rigidBody2dIntegratePosition` | `pub fn rigidBody2dIntegratePosition(mut body: RigidBody2D, dt: float): void:` | `tests/functions/phys2d/rigid_body2d_test.aipl` |
| `44` | `std/phys2d/verlet2d.aipl` | `verletParticleNew` | `pub fn verletParticleNew(pos: Vec2, isPinned: bool): VerletParticle2D:` | `tests/functions/phys2d/verlet2d_test.aipl` |
| `45` | `std/phys2d/verlet2d.aipl` | `verletClothGridNew` | `pub fn verletClothGridNew(cols: int, rows: int, spacing: float): VerletClothGrid2D:` | `tests/functions/phys2d/verlet2d_test.aipl` |
| `46` | `std/phys2d/verlet2d.aipl` | `verletStepSimulation` | `pub fn verletStepSimulation(mut cloth: VerletClothGrid2D, gravity: Vec2, iterations: int, dt: float): void:` | `tests/functions/phys2d/verlet2d_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `dynamicAABBTreeNew` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `pub fn dynamicAABBTreeNew(): DynamicAABBTree2D:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `DynamicAABBTree2D`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `dynamicAABBTreeNew`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `DynamicAABBTree2D(nodes = ns, root = -1, freeList = -1)`.

```aipl
module tests.functions.phys2d.broadphase2d_z1_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeNew_1(): int:
  let resNom = dynamicAABBTreeNew()
  let resEdge = dynamicAABBTreeNew()
  assertEqInt(resNom.nodes.len(), 0, "dynamicAABBTreeNew nominal resNom.nodes.len() == 0")
  assertEqInt(resEdge.nodes.len(), 0, "dynamicAABBTreeNew boundary resEdge.nodes.len() == 0")
  ret 0
```

---

### `fattenRect2D` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `fn fattenRect2D(r: Rect2D, margin: float): Rect2D:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `r: Rect2D, margin: float` | **Returns**: `Rect2D`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `fattenRect2D`. Concrete nominal inputs: `r: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `margin: float = 1.0`; exercises core body path returning/computing `Rect2D(x = r.x - margin, y = r.y - margin, w = nw, h = nh, width = nw, height = nh)`.

```aipl
module tests.functions.phys2d.broadphase2d_z2_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_fattenRect2D_2(): int:
  let arg_r = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_r = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_margin = 1.0
  let edge_margin = 0.5
  let resNom = fattenRect2D(arg_r, arg_margin)
  let resEdge = fattenRect2D(edge_r, edge_margin)
  assertApproxEq(resNom.x, 0.0, 0.001, "fattenRect2D nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "fattenRect2D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `rectContainsOther` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `fn rectContainsOther(outer: Rect2D, inner: Rect2D): bool:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `outer: Rect2D, inner: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `rectContainsOther`. Concrete nominal inputs: `outer: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `inner: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `inner.x >= outer.x and inner.y >= outer.y and (inner.x + iw) <= (outer.x + ow) and (inner.y + ih) <= (outer.y + oh)`.

```aipl
module tests.functions.phys2d.broadphase2d_z3_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_rectContainsOther_3(): int:
  let arg_outer = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_outer = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_inner = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_inner = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rectContainsOther(arg_outer, arg_inner)
  let resEdge = rectContainsOther(edge_outer, edge_inner)
  assert(resNom == true, "rectContainsOther nominal resNom == true")
  assert(resEdge == true, "rectContainsOther boundary resEdge == true")
  ret 0
```

---

### `rectsOverlap2D` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `fn rectsOverlap2D(a: Rect2D, b: Rect2D): bool:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Rect2D, b: Rect2D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `rectsOverlap2D`. Concrete nominal inputs: `a: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `b: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `a.x <= b.x + bw and a.x + aw >= b.x and a.y <= b.y + bh and a.y + ah >= b.y`.

```aipl
module tests.functions.phys2d.broadphase2d_z4_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_rectsOverlap2D_4(): int:
  let arg_a = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_a = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_b = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_b = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = rectsOverlap2D(arg_a, arg_b)
  let resEdge = rectsOverlap2D(edge_a, edge_b)
  assert(resNom == true, "rectsOverlap2D nominal resNom == true")
  assert(resEdge == true, "rectsOverlap2D boundary resEdge == true")
  ret 0
```

---

### `dynamicAABBTreeInsert` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `pub fn dynamicAABBTreeInsert(mut tree: DynamicAABBTree2D, bodyId: int, aabb: Rect2D): int:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut tree: DynamicAABBTree2D, bodyId: int, aabb: Rect2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `dynamicAABBTreeInsert`. Concrete nominal inputs: `tree: DynamicAABBTree2D = DynamicAABBTree2D(nodes = [DynamicAABBNode2D(aabb = 0, bodyId = 0, parent = 0, child1 = 0, child2 = 0, height = 0, active = 0)], root = 1, freeList = 1)`, `bodyId: int = 1`, `aabb: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`; exercises core body path returning/computing `nodeId`.

```aipl
module tests.functions.phys2d.broadphase2d_z5_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeInsert_5(): int:
  let arg_tree = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2)
  let edge_tree = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0)
  let arg_bodyId = 4
  let edge_bodyId = 1
  let arg_aabb = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_aabb = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let resNom = dynamicAABBTreeInsert(arg_tree, arg_bodyId, arg_aabb)
  let resEdge = dynamicAABBTreeInsert(edge_tree, edge_bodyId, edge_aabb)
  assertEqInt(resNom, 0, "dynamicAABBTreeInsert nominal resNom == 0")
  assertEqInt(resEdge, 0, "dynamicAABBTreeInsert boundary resEdge == 0")
  ret 0
```

---

### `dynamicAABBTreeUpdate` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `pub fn dynamicAABBTreeUpdate(mut tree: DynamicAABBTree2D, nodeId: int, newAABB: Rect2D, velocity: Vec2): bool:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut tree: DynamicAABBTree2D, nodeId: int, newAABB: Rect2D, velocity: Vec2` | **Returns**: `bool`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `dynamicAABBTreeUpdate`. Concrete nominal inputs: `tree: DynamicAABBTree2D = DynamicAABBTree2D(nodes = [DynamicAABBNode2D(aabb = 0, bodyId = 0, parent = 0, child1 = 0, child2 = 0, height = 0, active = 0)], root = 1, freeList = 1)`, `nodeId: int = 1`, `newAABB: Rect2D = Rect2D(x = 1.0, y = 1.0, w = float = 0.0(), h = float = 0.0(), width = float = 0.0(), height = float = 0.0())`, `velocity: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.phys2d.broadphase2d_z6_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeUpdate_6(): int:
  let arg_tree = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2)
  let edge_tree = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0)
  let arg_nodeId = 4
  let edge_nodeId = 1
  let arg_newAABB = Rect2D(x = 1.0, y = 1.0, w = 2.0, h = 2.0, width = 2.0, height = 2.0)
  let edge_newAABB = Rect2D(x = 0.5, y = 0.5, w = 1.0, h = 1.0, width = 1.0, height = 1.0)
  let arg_velocity = Vec2(x = 1.0, y = 1.0)
  let edge_velocity = Vec2(x = 0.5, y = 0.5)
  let resNom = dynamicAABBTreeUpdate(arg_tree, arg_nodeId, arg_newAABB, arg_velocity)
  let resEdge = dynamicAABBTreeUpdate(edge_tree, edge_nodeId, edge_newAABB, edge_velocity)
  assert(resNom == false, "dynamicAABBTreeUpdate nominal resNom == false")
  assert(resEdge == false, "dynamicAABBTreeUpdate boundary resEdge == false")
  ret 0
```

---

### `dynamicAABBTreeRemove` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `pub fn dynamicAABBTreeRemove(mut tree: DynamicAABBTree2D, nodeId: int): void:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut tree: DynamicAABBTree2D, nodeId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `dynamicAABBTreeRemove`. Concrete nominal inputs: `tree: DynamicAABBTree2D = DynamicAABBTree2D(nodes = [DynamicAABBNode2D(aabb = 0, bodyId = 0, parent = 0, child1 = 0, child2 = 0, height = 0, active = 0)], root = 1, freeList = 1)`, `nodeId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.broadphase2d_z7_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeRemove_7(): int:
  let arg_tree = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2)
  let edge_tree = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0)
  let arg_nodeId = 4
  let edge_nodeId = 1
  dynamicAABBTreeRemove(arg_tree, arg_nodeId)
  dynamicAABBTreeRemove(edge_tree, edge_nodeId)
  assertEqInt(arg_tree.nodes.len(), 0, "dynamicAABBTreeRemove nominal arg_tree.nodes.len() == 0")
  assertEqInt(edge_tree.nodes.len(), 0, "dynamicAABBTreeRemove boundary edge_tree.nodes.len() == 0")
  ret 0
```

---

### `dynamicAABBTreeFindPairs` (`std/phys2d/broadphase2d.aipl`)

- **Signature**: `pub fn dynamicAABBTreeFindPairs(tree: DynamicAABBTree2D): [BroadphasePair2D]:`
- **Import**: `import * from "std/phys2d/broadphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `tree: DynamicAABBTree2D` | **Returns**: `[BroadphasePair2D]`
- **Unit Test**: `tests/functions/phys2d/broadphase2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D broadphase spatial hash grid and Dynamic AABB Tree fat-AABB insertion, updates, ray queries, and candidate pair generation in `dynamicAABBTreeFindPairs`. Concrete nominal inputs: `tree: DynamicAABBTree2D = DynamicAABBTree2D(nodes = [DynamicAABBNode2D(aabb = 0, bodyId = 0, parent = 0, child1 = 0, child2 = 0, height = 0, active = 0)], root = 1, freeList = 1)`; exercises core body path returning/computing `pairs`.

```aipl
module tests.functions.phys2d.broadphase2d_z8_test
import * from "std/phys2d/broadphase2d"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_broadphase2d_dynamicAABBTreeFindPairs_8(): int:
  let arg_tree = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2)
  let edge_tree = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0)
  let resNom = dynamicAABBTreeFindPairs(arg_tree)
  let resEdge = dynamicAABBTreeFindPairs(edge_tree)
  assertEqInt(resNom.len(), 0, "dynamicAABBTreeFindPairs nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "dynamicAABBTreeFindPairs boundary resEdge.len() == 0")
  ret 0
```

---

### `circleColliderNew` (`std/phys2d/collider2d.aipl`)

- **Signature**: `pub fn circleColliderNew(radius: float, material: PhysicsMaterial2D): Collider2D:`
- **Import**: `import * from "std/phys2d/collider2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, material: PhysicsMaterial2D` | **Returns**: `Collider2D`
- **Unit Test**: `tests/functions/phys2d/collider2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies 2D circle/box/capsule/polygon collider construction and rotated world-space AABB computation in `circleColliderNew`. Concrete nominal inputs: `radius: float = 1.0`, `material: PhysicsMaterial2D = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider2D(`.

```aipl
module tests.functions.phys2d.collider2d_z1_test
import * from "std/phys2d/collider2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider2d_circleColliderNew_1(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5)
  let resNom = circleColliderNew(arg_radius, arg_material)
  let resEdge = circleColliderNew(edge_radius, edge_material)
  assertApproxEq(resNom.circleRadius, 2.0, 0.001, "circleColliderNew nominal resNom.circleRadius ~= 2.0")
  assertApproxEq(resEdge.circleRadius, 1.0, 0.001, "circleColliderNew boundary resEdge.circleRadius ~= 1.0")
  ret 0
```

---

### `boxColliderNew` (`std/phys2d/collider2d.aipl`)

- **Signature**: `pub fn boxColliderNew(width: float, height: float, material: PhysicsMaterial2D): Collider2D:`
- **Import**: `import * from "std/phys2d/collider2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `width: float, height: float, material: PhysicsMaterial2D` | **Returns**: `Collider2D`
- **Unit Test**: `tests/functions/phys2d/collider2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies 2D circle/box/capsule/polygon collider construction and rotated world-space AABB computation in `boxColliderNew`. Concrete nominal inputs: `width: float = 0.016667`, `height: float = 1.0`, `material: PhysicsMaterial2D = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider2D(`.

```aipl
module tests.functions.phys2d.collider2d_z2_test
import * from "std/phys2d/collider2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider2d_boxColliderNew_2(): int:
  let arg_width = 2.0
  let edge_width = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5)
  let resNom = boxColliderNew(arg_width, arg_height, arg_material)
  let resEdge = boxColliderNew(edge_width, edge_height, edge_material)
  assertApproxEq(resNom.circleRadius, 0.0, 0.001, "boxColliderNew nominal resNom.circleRadius ~= 0.0")
  assertApproxEq(resEdge.circleRadius, 0.0, 0.001, "boxColliderNew boundary resEdge.circleRadius ~= 0.0")
  ret 0
```

---

### `capsuleColliderNew` (`std/phys2d/collider2d.aipl`)

- **Signature**: `pub fn capsuleColliderNew(radius: float, length: float, material: PhysicsMaterial2D): Collider2D:`
- **Import**: `import * from "std/phys2d/collider2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, length: float, material: PhysicsMaterial2D` | **Returns**: `Collider2D`
- **Unit Test**: `tests/functions/phys2d/collider2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies 2D circle/box/capsule/polygon collider construction and rotated world-space AABB computation in `capsuleColliderNew`. Concrete nominal inputs: `radius: float = 1.0`, `length: float = 1.0`, `material: PhysicsMaterial2D = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider2D(`.

```aipl
module tests.functions.phys2d.collider2d_z3_test
import * from "std/phys2d/collider2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider2d_capsuleColliderNew_3(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_length = 2.0
  let edge_length = 1.0
  let arg_material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5)
  let resNom = capsuleColliderNew(arg_radius, arg_length, arg_material)
  let resEdge = capsuleColliderNew(edge_radius, edge_length, edge_material)
  assertApproxEq(resNom.circleRadius, 2.0, 0.001, "capsuleColliderNew nominal resNom.circleRadius ~= 2.0")
  assertApproxEq(resEdge.circleRadius, 1.0, 0.001, "capsuleColliderNew boundary resEdge.circleRadius ~= 1.0")
  ret 0
```

---

### `polygonColliderNew` (`std/phys2d/collider2d.aipl`)

- **Signature**: `pub fn polygonColliderNew(vertices: [Vec2], material: PhysicsMaterial2D): Collider2D:`
- **Import**: `import * from "std/phys2d/collider2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `vertices: [Vec2], material: PhysicsMaterial2D` | **Returns**: `Collider2D`
- **Unit Test**: `tests/functions/phys2d/collider2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies 2D circle/box/capsule/polygon collider construction and rotated world-space AABB computation in `polygonColliderNew`. Concrete nominal inputs: `vertices: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`, `material: PhysicsMaterial2D = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider2D(`.

```aipl
module tests.functions.phys2d.collider2d_z4_test
import * from "std/phys2d/collider2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider2d_polygonColliderNew_4(): int:
  let arg_vertices = [Vec2(x = 1.0, y = 1.0)]
  let edge_vertices = []
  let arg_material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5)
  let resNom = polygonColliderNew(arg_vertices, arg_material)
  let resEdge = polygonColliderNew(edge_vertices, edge_material)
  assertApproxEq(resNom.circleRadius, 0.0, 0.001, "polygonColliderNew nominal resNom.circleRadius ~= 0.0")
  assertApproxEq(resEdge.circleRadius, 0.0, 0.001, "polygonColliderNew boundary resEdge.circleRadius ~= 0.0")
  ret 0
```

---

### `colliderComputeAABB` (`std/phys2d/collider2d.aipl`)

- **Signature**: `pub fn colliderComputeAABB(collider: Collider2D, bodyPos: Vec2, bodyAngle: float): Rect2D:`
- **Import**: `import * from "std/phys2d/collider2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `collider: Collider2D, bodyPos: Vec2, bodyAngle: float` | **Returns**: `Rect2D`
- **Unit Test**: `tests/functions/phys2d/collider2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies 2D circle/box/capsule/polygon collider construction and rotated world-space AABB computation in `colliderComputeAABB`. Concrete nominal inputs: `collider: Collider2D = Collider2D(shapeType = ColliderShapeType2D(), offset = Vec2(x = 1.0, y = 1.0), circleRadius = 1.0, boxHalfExtents = Vec2(x = 1.0, y = 1.0), capsuleLength = 1.0, polygonVertices = [Vec2(x = 0, y = 0)], material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`, `bodyPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `bodyAngle: float = 1.0`; exercises core body path returning/computing `Rect2D(x = cx, y = cy, w = 0.0, h = 0.0, width = 0.0, height = 0.0)`.

```aipl
module tests.functions.phys2d.collider2d_z5_test
import * from "std/phys2d/collider2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Rect2D } from "std/math/geom2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider2d_colliderComputeAABB_5(): int:
  let arg_collider = Collider2D(shapeType = ColliderShapeType2D.Circle, offset = Vec2(x = 1.0, y = 1.0), circleRadius = 2.0, boxHalfExtents = Vec2(x = 1.0, y = 1.0), capsuleLength = 2.0, polygonVertices = [], material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_collider = Collider2D(shapeType = ColliderShapeType2D.Circle, offset = Vec2(x = 0.5, y = 0.5), circleRadius = 1.0, boxHalfExtents = Vec2(x = 0.5, y = 0.5), capsuleLength = 1.0, polygonVertices = [], material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let arg_bodyPos = Vec2(x = 1.0, y = 1.0)
  let edge_bodyPos = Vec2(x = 0.5, y = 0.5)
  let arg_bodyAngle = 1.0
  let edge_bodyAngle = 0.5
  let resNom = colliderComputeAABB(arg_collider, arg_bodyPos, arg_bodyAngle)
  let resEdge = colliderComputeAABB(edge_collider, edge_bodyPos, edge_bodyAngle)
  assertApproxEq(resNom.x, -1.30117, 0.001, "colliderComputeAABB nominal resNom.x ~= -1.30117")
  assertApproxEq(resEdge.x, -0.300921, 0.001, "colliderComputeAABB boundary resEdge.x ~= -0.300921")
  ret 0
```

---

### `sphFluidWorldNew` (`std/phys2d/fluid2d.aipl`)

- **Signature**: `pub fn sphFluidWorldNew(smoothingRadius: float, restDensity: float, stiffness: float, viscosity: float): SphFluidWorld2D:`
- **Import**: `import * from "std/phys2d/fluid2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `smoothingRadius: float, restDensity: float, stiffness: float, viscosity: float` | **Returns**: `SphFluidWorld2D`
- **Unit Test**: `tests/functions/phys2d/fluid2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D SPH fluid Poly6/Spiky pressure-viscosity step and falling-sand cellular automata mass conservation in `sphFluidWorldNew`. Concrete nominal inputs: `smoothingRadius: float = 1.0`, `restDensity: float = 1.0`, `stiffness: float = 1.0`, `viscosity: float = 1.0`; exercises core body path returning/computing `SphFluidWorld2D(`.

```aipl
module tests.functions.phys2d.fluid2d_z1_test
import * from "std/phys2d/fluid2d"
import { maxFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fluid2d_sphFluidWorldNew_1(): int:
  let arg_smoothingRadius = 2.0
  let edge_smoothingRadius = 1.0
  let arg_restDensity = 1.0
  let edge_restDensity = 0.5
  let arg_stiffness = 1.0
  let edge_stiffness = 0.5
  let arg_viscosity = 1.0
  let edge_viscosity = 0.5
  let resNom = sphFluidWorldNew(arg_smoothingRadius, arg_restDensity, arg_stiffness, arg_viscosity)
  let resEdge = sphFluidWorldNew(edge_smoothingRadius, edge_restDensity, edge_stiffness, edge_viscosity)
  assertEqInt(resNom.particles.len(), 0, "sphFluidWorldNew nominal resNom.particles.len() == 0")
  assertEqInt(resEdge.particles.len(), 0, "sphFluidWorldNew boundary resEdge.particles.len() == 0")
  ret 0
```

---

### `sphFluidStep` (`std/phys2d/fluid2d.aipl`)

- **Signature**: `pub fn sphFluidStep(mut world: SphFluidWorld2D, gravity: Vec2, dt: float): void:`
- **Import**: `import * from "std/phys2d/fluid2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: SphFluidWorld2D, gravity: Vec2, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/fluid2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D SPH fluid Poly6/Spiky pressure-viscosity step and falling-sand cellular automata mass conservation in `sphFluidStep`. Concrete nominal inputs: `world: SphFluidWorld2D = SphFluidWorld2D(particles = [SphParticle2D(position = 0, velocity = 0, force = 0, density = 0, pressure = 0)], smoothingRadius = 1.0, restDensity = 1.0, gasStiffness = 1.0, viscosity = 1.0)`, `gravity: Vec2 = Vec2(x = 1.0, y = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.fluid2d_z2_test
import * from "std/phys2d/fluid2d"
import { maxFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fluid2d_sphFluidStep_2(): int:
  let arg_world = SphFluidWorld2D(particles = [], smoothingRadius = 2.0, restDensity = 1.0, gasStiffness = 1.0, viscosity = 1.0)
  let edge_world = SphFluidWorld2D(particles = [], smoothingRadius = 1.0, restDensity = 0.5, gasStiffness = 0.5, viscosity = 0.5)
  let arg_gravity = Vec2(x = 1.0, y = 1.0)
  let edge_gravity = Vec2(x = 0.5, y = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  sphFluidStep(arg_world, arg_gravity, arg_dt)
  sphFluidStep(edge_world, edge_gravity, edge_dt)
  assertEqInt(arg_world.particles.len(), 0, "sphFluidStep nominal arg_world.particles.len() == 0")
  assertEqInt(edge_world.particles.len(), 0, "sphFluidStep boundary edge_world.particles.len() == 0")
  ret 0
```

---

### `cellularSandStep` (`std/phys2d/fluid2d.aipl`)

- **Signature**: `pub fn cellularSandStep(mut grid: CellularSandGrid2D): int:`
- **Import**: `import * from "std/phys2d/fluid2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut grid: CellularSandGrid2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys2d/fluid2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D SPH fluid Poly6/Spiky pressure-viscosity step and falling-sand cellular automata mass conservation in `cellularSandStep`. Concrete nominal inputs: `grid: CellularSandGrid2D = CellularSandGrid2D(width = 128, height = 128, cells = [1])`; exercises core body path returning/computing `moved`.

```aipl
module tests.functions.phys2d.fluid2d_z3_test
import * from "std/phys2d/fluid2d"
import { maxFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_fluid2d_cellularSandStep_3(): int:
  let arg_grid = CellularSandGrid2D(width = 4, height = 4, cells = [])
  let edge_grid = CellularSandGrid2D(width = 4, height = 4, cells = [])
  let resNom = cellularSandStep(arg_grid)
  let resEdge = cellularSandStep(edge_grid)
  assertEqInt(resNom, 0, "cellularSandStep nominal resNom == 0")
  assertEqInt(resEdge, 0, "cellularSandStep boundary resEdge == 0")
  ret 0
```

---

### `distanceJointNew` (`std/phys2d/joint2d.aipl`)

- **Signature**: `pub fn distanceJointNew(bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, distance: float): Joint2D:`
- **Import**: `import * from "std/phys2d/joint2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, distance: float` | **Returns**: `Joint2D`
- **Unit Test**: `tests/functions/phys2d/joint2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies 2D distance, spring, revolute, and weld joint constraint error Baumgarte stabilization and impulse solving in `distanceJointNew`. Concrete nominal inputs: `bodyIdA: int = 1`, `bodyIdB: int = 1`, `anchorA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `anchorB: Vec2 = Vec2(x = 1.0, y = 1.0)`, `distance: float = 1.0`; exercises core body path returning/computing `Joint2D(`.

```aipl
module tests.functions.phys2d.joint2d_z1_test
import * from "std/phys2d/joint2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, MassProperties2D } from "std/phys2d/rigid_body2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint2d_distanceJointNew_1(): int:
  let arg_bodyIdA = 4
  let edge_bodyIdA = 1
  let arg_bodyIdB = 4
  let edge_bodyIdB = 1
  let arg_anchorA = Vec2(x = 1.0, y = 1.0)
  let edge_anchorA = Vec2(x = 0.5, y = 0.5)
  let arg_anchorB = Vec2(x = 1.0, y = 1.0)
  let edge_anchorB = Vec2(x = 0.5, y = 0.5)
  let arg_distance = 1.0
  let edge_distance = 0.5
  let resNom = distanceJointNew(arg_bodyIdA, arg_bodyIdB, arg_anchorA, arg_anchorB, arg_distance)
  let resEdge = distanceJointNew(edge_bodyIdA, edge_bodyIdB, edge_anchorA, edge_anchorB, edge_distance)
  assertEqInt(resNom.id, 0, "distanceJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "distanceJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `springJointNew` (`std/phys2d/joint2d.aipl`)

- **Signature**: `pub fn springJointNew(bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, restLength: float, stiffness: float, damping: float): Joint2D:`
- **Import**: `import * from "std/phys2d/joint2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyIdA: int, bodyIdB: int, anchorA: Vec2, anchorB: Vec2, restLength: float, stiffness: float, damping: float` | **Returns**: `Joint2D`
- **Unit Test**: `tests/functions/phys2d/joint2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies 2D distance, spring, revolute, and weld joint constraint error Baumgarte stabilization and impulse solving in `springJointNew`. Concrete nominal inputs: `bodyIdA: int = 1`, `bodyIdB: int = 1`, `anchorA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `anchorB: Vec2 = Vec2(x = 1.0, y = 1.0)`, `restLength: float = 1.0`, `stiffness: float = 1.0`, `damping: float = 1.0`; exercises core body path returning/computing `Joint2D(`.

```aipl
module tests.functions.phys2d.joint2d_z2_test
import * from "std/phys2d/joint2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, MassProperties2D } from "std/phys2d/rigid_body2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint2d_springJointNew_2(): int:
  let arg_bodyIdA = 4
  let edge_bodyIdA = 1
  let arg_bodyIdB = 4
  let edge_bodyIdB = 1
  let arg_anchorA = Vec2(x = 1.0, y = 1.0)
  let edge_anchorA = Vec2(x = 0.5, y = 0.5)
  let arg_anchorB = Vec2(x = 1.0, y = 1.0)
  let edge_anchorB = Vec2(x = 0.5, y = 0.5)
  let arg_restLength = 2.0
  let edge_restLength = 1.0
  let arg_stiffness = 1.0
  let edge_stiffness = 0.5
  let arg_damping = 1.0
  let edge_damping = 0.5
  let resNom = springJointNew(arg_bodyIdA, arg_bodyIdB, arg_anchorA, arg_anchorB, arg_restLength, arg_stiffness, arg_damping)
  let resEdge = springJointNew(edge_bodyIdA, edge_bodyIdB, edge_anchorA, edge_anchorB, edge_restLength, edge_stiffness, edge_damping)
  assertEqInt(resNom.id, 0, "springJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "springJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `revoluteJointNew` (`std/phys2d/joint2d.aipl`)

- **Signature**: `pub fn revoluteJointNew(bodyIdA: int, bodyIdB: int, worldAnchor: Vec2): Joint2D:`
- **Import**: `import * from "std/phys2d/joint2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyIdA: int, bodyIdB: int, worldAnchor: Vec2` | **Returns**: `Joint2D`
- **Unit Test**: `tests/functions/phys2d/joint2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies 2D distance, spring, revolute, and weld joint constraint error Baumgarte stabilization and impulse solving in `revoluteJointNew`. Concrete nominal inputs: `bodyIdA: int = 1`, `bodyIdB: int = 1`, `worldAnchor: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Joint2D(`.

```aipl
module tests.functions.phys2d.joint2d_z3_test
import * from "std/phys2d/joint2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, MassProperties2D } from "std/phys2d/rigid_body2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint2d_revoluteJointNew_3(): int:
  let arg_bodyIdA = 4
  let edge_bodyIdA = 1
  let arg_bodyIdB = 4
  let edge_bodyIdB = 1
  let arg_worldAnchor = Vec2(x = 1.0, y = 1.0)
  let edge_worldAnchor = Vec2(x = 0.5, y = 0.5)
  let resNom = revoluteJointNew(arg_bodyIdA, arg_bodyIdB, arg_worldAnchor)
  let resEdge = revoluteJointNew(edge_bodyIdA, edge_bodyIdB, edge_worldAnchor)
  assertEqInt(resNom.id, 0, "revoluteJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "revoluteJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `jointSolveVelocity` (`std/phys2d/joint2d.aipl`)

- **Signature**: `pub fn jointSolveVelocity(joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D, dt: float): void:`
- **Import**: `import * from "std/phys2d/joint2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/joint2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies 2D distance, spring, revolute, and weld joint constraint error Baumgarte stabilization and impulse solving in `jointSolveVelocity`. Concrete nominal inputs: `joint: Joint2D = Joint2D(id = 1, jointType = JointType2D(), bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 1.0, maxLimit = 1.0, enableLimits = true)`, `bodyA: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `bodyB: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.joint2d_z4_test
import * from "std/phys2d/joint2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, MassProperties2D } from "std/phys2d/rigid_body2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint2d_jointSolveVelocity_4(): int:
  let arg_joint = Joint2D(id = 1, jointType = JointType2D.Distance, bodyIdA = 4, bodyIdB = 4, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 0.0, maxLimit = 2.0, enableLimits = true)
  let edge_joint = Joint2D(id = 0, jointType = JointType2D.Distance, bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 0.5, y = 0.5), localAnchorB = Vec2(x = 0.5, y = 0.5), targetDistance = 0.5, springStiffness = 0.5, springDamping = 0.5, minLimit = 0.0, maxLimit = 1.0, enableLimits = false)
  let arg_bodyA = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_bodyA = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_bodyB = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_bodyB = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  jointSolveVelocity(arg_joint, arg_bodyA, arg_bodyB, arg_dt)
  jointSolveVelocity(edge_joint, edge_bodyA, edge_bodyB, edge_dt)
  assertEqInt(arg_bodyA.id, 1, "jointSolveVelocity nominal arg_bodyA.id == 1")
  assertEqInt(edge_bodyA.id, 0, "jointSolveVelocity boundary edge_bodyA.id == 0")
  ret 0
```

---

### `jointSolvePosition` (`std/phys2d/joint2d.aipl`)

- **Signature**: `pub fn jointSolvePosition(joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D): void:`
- **Import**: `import * from "std/phys2d/joint2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `joint: Joint2D, mut bodyA: RigidBody2D, mut bodyB: RigidBody2D` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/joint2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies 2D distance, spring, revolute, and weld joint constraint error Baumgarte stabilization and impulse solving in `jointSolvePosition`. Concrete nominal inputs: `joint: Joint2D = Joint2D(id = 1, jointType = JointType2D(), bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 1.0, maxLimit = 1.0, enableLimits = true)`, `bodyA: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `bodyB: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.joint2d_z5_test
import * from "std/phys2d/joint2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, MassProperties2D } from "std/phys2d/rigid_body2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint2d_jointSolvePosition_5(): int:
  let arg_joint = Joint2D(id = 1, jointType = JointType2D.Distance, bodyIdA = 4, bodyIdB = 4, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 0.0, maxLimit = 2.0, enableLimits = true)
  let edge_joint = Joint2D(id = 0, jointType = JointType2D.Distance, bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 0.5, y = 0.5), localAnchorB = Vec2(x = 0.5, y = 0.5), targetDistance = 0.5, springStiffness = 0.5, springDamping = 0.5, minLimit = 0.0, maxLimit = 1.0, enableLimits = false)
  let arg_bodyA = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_bodyA = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_bodyB = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_bodyB = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  jointSolvePosition(arg_joint, arg_bodyA, arg_bodyB)
  jointSolvePosition(edge_joint, edge_bodyA, edge_bodyB)
  assertEqInt(arg_bodyA.id, 1, "jointSolvePosition nominal arg_bodyA.id == 1")
  assertEqInt(edge_bodyA.id, 0, "jointSolvePosition boundary edge_bodyA.id == 0")
  ret 0
```

---

### `testCircleCircle` (`std/phys2d/narrowphase2d.aipl`)

- **Signature**: `pub fn testCircleCircle(posA: Vec2, radA: float, posB: Vec2, radB: float): Option[ContactManifold2D]:`
- **Import**: `import * from "std/phys2d/narrowphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `posA: Vec2, radA: float, posB: Vec2, radB: float` | **Returns**: `Option[ContactManifold2D]`
- **Unit Test**: `tests/functions/phys2d/narrowphase2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies exact 2D collision normal, penetration depth, and contact points for Circle-Circle, Circle-Box, Box-Box SAT, and convex GJK-EPA in `testCircleCircle`. Concrete nominal inputs: `posA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radA: float = 1.0`, `posB: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radB: float = 1.0`; exercises core body path returning/computing `Some(ContactManifold2D(`.

```aipl
module tests.functions.phys2d.narrowphase2d_z1_test
import * from "std/phys2d/narrowphase2d"
import { absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase2d_testCircleCircle_1(): int:
  let arg_posA = Vec2(x = 1.0, y = 1.0)
  let edge_posA = Vec2(x = 0.5, y = 0.5)
  let arg_radA = 1.0
  let edge_radA = 0.5
  let arg_posB = Vec2(x = 1.0, y = 1.0)
  let edge_posB = Vec2(x = 0.5, y = 0.5)
  let arg_radB = 1.0
  let edge_radB = 0.5
  let resNom = testCircleCircle(arg_posA, arg_radA, arg_posB, arg_radB)
  let resEdge = testCircleCircle(edge_posA, edge_radA, edge_posB, edge_radB)
  assert(resNom.isSome() == true, "testCircleCircle nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testCircleCircle boundary resEdge.isSome() == true")
  ret 0
```

---

### `testCircleBoxSAT` (`std/phys2d/narrowphase2d.aipl`)

- **Signature**: `pub fn testCircleBoxSAT(circlePos: Vec2, radius: float, boxPos: Vec2, boxExtents: Vec2, boxAngle: float): Option[ContactManifold2D]:`
- **Import**: `import * from "std/phys2d/narrowphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `circlePos: Vec2, radius: float, boxPos: Vec2, boxExtents: Vec2, boxAngle: float` | **Returns**: `Option[ContactManifold2D]`
- **Unit Test**: `tests/functions/phys2d/narrowphase2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies exact 2D collision normal, penetration depth, and contact points for Circle-Circle, Circle-Box, Box-Box SAT, and convex GJK-EPA in `testCircleBoxSAT`. Concrete nominal inputs: `circlePos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `boxPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `boxExtents: Vec2 = Vec2(x = 1.0, y = 1.0)`, `boxAngle: float = 1.0`; exercises core body path returning/computing `Some(ContactManifold2D(`.

```aipl
module tests.functions.phys2d.narrowphase2d_z2_test
import * from "std/phys2d/narrowphase2d"
import { absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase2d_testCircleBoxSAT_2(): int:
  let arg_circlePos = Vec2(x = 1.0, y = 1.0)
  let edge_circlePos = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_boxPos = Vec2(x = 1.0, y = 1.0)
  let edge_boxPos = Vec2(x = 0.5, y = 0.5)
  let arg_boxExtents = Vec2(x = 1.0, y = 1.0)
  let edge_boxExtents = Vec2(x = 0.5, y = 0.5)
  let arg_boxAngle = 1.0
  let edge_boxAngle = 0.5
  let resNom = testCircleBoxSAT(arg_circlePos, arg_radius, arg_boxPos, arg_boxExtents, arg_boxAngle)
  let resEdge = testCircleBoxSAT(edge_circlePos, edge_radius, edge_boxPos, edge_boxExtents, edge_boxAngle)
  assert(resNom.isSome() == true, "testCircleBoxSAT nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testCircleBoxSAT boundary resEdge.isSome() == true")
  ret 0
```

---

### `buildBoxVerts2D` (`std/phys2d/narrowphase2d.aipl`)

- **Signature**: `fn buildBoxVerts2D(pos: Vec2, ext: Vec2, rot: float): [Vec2]:`
- **Import**: `import * from "std/phys2d/narrowphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec2, ext: Vec2, rot: float` | **Returns**: `[Vec2]`
- **Unit Test**: `tests/functions/phys2d/narrowphase2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies exact 2D collision normal, penetration depth, and contact points for Circle-Circle, Circle-Box, Box-Box SAT, and convex GJK-EPA in `buildBoxVerts2D`. Concrete nominal inputs: `pos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `ext: Vec2 = Vec2(x = 1.0, y = 1.0)`, `rot: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.phys2d.narrowphase2d_z3_test
import * from "std/phys2d/narrowphase2d"
import { absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase2d_buildBoxVerts2D_3(): int:
  let arg_pos = Vec2(x = 1.0, y = 1.0)
  let edge_pos = Vec2(x = 0.5, y = 0.5)
  let arg_ext = Vec2(x = 1.0, y = 1.0)
  let edge_ext = Vec2(x = 0.5, y = 0.5)
  let arg_rot = 1.0
  let edge_rot = 0.5
  let resNom = buildBoxVerts2D(arg_pos, arg_ext, arg_rot)
  let resEdge = buildBoxVerts2D(edge_pos, edge_ext, edge_rot)
  assertEqInt(resNom.len(), 4, "buildBoxVerts2D nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "buildBoxVerts2D boundary resEdge.len() == 4")
  ret 0
```

---

### `testGjkEpa2D` (`std/phys2d/narrowphase2d.aipl`)

- **Signature**: `pub fn testGjkEpa2D(vertsA: [Vec2], vertsB: [Vec2]): Option[ContactManifold2D]:`
- **Import**: `import * from "std/phys2d/narrowphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `vertsA: [Vec2], vertsB: [Vec2]` | **Returns**: `Option[ContactManifold2D]`
- **Unit Test**: `tests/functions/phys2d/narrowphase2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies exact 2D collision normal, penetration depth, and contact points for Circle-Circle, Circle-Box, Box-Box SAT, and convex GJK-EPA in `testGjkEpa2D`. Concrete nominal inputs: `vertsA: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`, `vertsB: [Vec2] = [Vec2(x = 1.0, y = 1.0)]`; exercises core body path returning/computing `Some(ContactManifold2D(`.

```aipl
module tests.functions.phys2d.narrowphase2d_z4_test
import * from "std/phys2d/narrowphase2d"
import { absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase2d_testGjkEpa2D_4(): int:
  let arg_vertsA = [Vec2(x = 1.0, y = 1.0)]
  let edge_vertsA = []
  let arg_vertsB = [Vec2(x = 1.0, y = 1.0)]
  let edge_vertsB = []
  let resNom = testGjkEpa2D(arg_vertsA, arg_vertsB)
  let resEdge = testGjkEpa2D(edge_vertsA, edge_vertsB)
  assert(resNom.isSome() == false, "testGjkEpa2D nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "testGjkEpa2D boundary resEdge.isSome() == false")
  ret 0
```

---

### `testBoxBoxSAT` (`std/phys2d/narrowphase2d.aipl`)

- **Signature**: `pub fn testBoxBoxSAT(posA: Vec2, extA: Vec2, rotA: float, posB: Vec2, extB: Vec2, rotB: float): Option[ContactManifold2D]:`
- **Import**: `import * from "std/phys2d/narrowphase2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `posA: Vec2, extA: Vec2, rotA: float, posB: Vec2, extB: Vec2, rotB: float` | **Returns**: `Option[ContactManifold2D]`
- **Unit Test**: `tests/functions/phys2d/narrowphase2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies exact 2D collision normal, penetration depth, and contact points for Circle-Circle, Circle-Box, Box-Box SAT, and convex GJK-EPA in `testBoxBoxSAT`. Concrete nominal inputs: `posA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `extA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `rotA: float = 1.0`, `posB: Vec2 = Vec2(x = 1.0, y = 1.0)`, `extB: Vec2 = Vec2(x = 1.0, y = 1.0)`, `rotB: float = 1.0`; exercises core body path returning/computing `testGjkEpa2D(vA, vB)`.

```aipl
module tests.functions.phys2d.narrowphase2d_z5_test
import * from "std/phys2d/narrowphase2d"
import { absFloat, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase2d_testBoxBoxSAT_5(): int:
  let arg_posA = Vec2(x = 1.0, y = 1.0)
  let edge_posA = Vec2(x = 0.5, y = 0.5)
  let arg_extA = Vec2(x = 1.0, y = 1.0)
  let edge_extA = Vec2(x = 0.5, y = 0.5)
  let arg_rotA = 1.0
  let edge_rotA = 0.5
  let arg_posB = Vec2(x = 1.0, y = 1.0)
  let edge_posB = Vec2(x = 0.5, y = 0.5)
  let arg_extB = Vec2(x = 1.0, y = 1.0)
  let edge_extB = Vec2(x = 0.5, y = 0.5)
  let arg_rotB = 1.0
  let edge_rotB = 0.5
  let resNom = testBoxBoxSAT(arg_posA, arg_extA, arg_rotA, arg_posB, arg_extB, arg_rotB)
  let resEdge = testBoxBoxSAT(edge_posA, edge_extA, edge_rotA, edge_posB, edge_extB, edge_rotB)
  assert(resNom.isSome() == true, "testBoxBoxSAT nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testBoxBoxSAT boundary resEdge.isSome() == true")
  ret 0
```

---

### `extractRayDir2D` (`std/phys2d/phys_query2d.aipl`)

- **Signature**: `fn extractRayDir2D(ray: Ray2D): Vec2:`
- **Import**: `import * from "std/phys2d/phys_query2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray2D` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/phys2d/phys_query2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D analytical raycasts (segment, circle, box), circle shape-casts, and point-in-shape overlap queries in `extractRayDir2D`. Concrete nominal inputs: `ray: Ray2D = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2 = Vec2(x = 1.0, y = 0.0)(), direction = Vec2 = Vec2(x = 1.0, y = 0.0)(), maxDistance = float = 1000.0())`; exercises core body path returning/computing `dirFallback`.

```aipl
module tests.functions.phys2d.phys_query2d_z1_test
import * from "std/phys2d/phys_query2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Ray2D } from "std/math/geom2d"
import { Collider2D, ColliderShapeType2D } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query2d_extractRayDir2D_1(): int:
  let arg_ray = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2(x = 1.0, y = 1.0), direction = Vec2(x = 1.0, y = 1.0), maxDistance = 2.0)
  let edge_ray = Ray2D(origin = Vec2(x = 0.5, y = 0.5), dir = Vec2(x = 0.5, y = 0.5), direction = Vec2(x = 0.5, y = 0.5), maxDistance = 1.0)
  let resNom = extractRayDir2D(arg_ray)
  let resEdge = extractRayDir2D(edge_ray)
  assertApproxEq(resNom.x, 1.0, 0.001, "extractRayDir2D nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "extractRayDir2D boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `raycast2dSegment` (`std/phys2d/phys_query2d.aipl`)

- **Signature**: `pub fn raycast2dSegment(ray: Ray2D, segA: Vec2, segB: Vec2): Option[RayHit2D]:`
- **Import**: `import * from "std/phys2d/phys_query2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray2D, segA: Vec2, segB: Vec2` | **Returns**: `Option[RayHit2D]`
- **Unit Test**: `tests/functions/phys2d/phys_query2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D analytical raycasts (segment, circle, box), circle shape-casts, and point-in-shape overlap queries in `raycast2dSegment`. Concrete nominal inputs: `ray: Ray2D = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2 = Vec2(x = 1.0, y = 0.0)(), direction = Vec2 = Vec2(x = 1.0, y = 0.0)(), maxDistance = float = 1000.0())`, `segA: Vec2 = Vec2(x = 1.0, y = 1.0)`, `segB: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `Some(RayHit2D(`.

```aipl
module tests.functions.phys2d.phys_query2d_z2_test
import * from "std/phys2d/phys_query2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Ray2D } from "std/math/geom2d"
import { Collider2D, ColliderShapeType2D } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query2d_raycast2dSegment_2(): int:
  let arg_ray = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2(x = 1.0, y = 1.0), direction = Vec2(x = 1.0, y = 1.0), maxDistance = 2.0)
  let edge_ray = Ray2D(origin = Vec2(x = 0.5, y = 0.5), dir = Vec2(x = 0.5, y = 0.5), direction = Vec2(x = 0.5, y = 0.5), maxDistance = 1.0)
  let arg_segA = Vec2(x = 1.0, y = 1.0)
  let edge_segA = Vec2(x = 0.5, y = 0.5)
  let arg_segB = Vec2(x = 1.0, y = 1.0)
  let edge_segB = Vec2(x = 0.5, y = 0.5)
  let resNom = raycast2dSegment(arg_ray, arg_segA, arg_segB)
  let resEdge = raycast2dSegment(edge_ray, edge_segA, edge_segB)
  assert(resNom.isSome() == false, "raycast2dSegment nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "raycast2dSegment boundary resEdge.isSome() == false")
  ret 0
```

---

### `raycast2dCircle` (`std/phys2d/phys_query2d.aipl`)

- **Signature**: `pub fn raycast2dCircle(ray: Ray2D, center: Vec2, radius: float): Option[RayHit2D]:`
- **Import**: `import * from "std/phys2d/phys_query2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray2D, center: Vec2, radius: float` | **Returns**: `Option[RayHit2D]`
- **Unit Test**: `tests/functions/phys2d/phys_query2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D analytical raycasts (segment, circle, box), circle shape-casts, and point-in-shape overlap queries in `raycast2dCircle`. Concrete nominal inputs: `ray: Ray2D = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2 = Vec2(x = 1.0, y = 0.0)(), direction = Vec2 = Vec2(x = 1.0, y = 0.0)(), maxDistance = float = 1000.0())`, `center: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `Some(RayHit2D(`.

```aipl
module tests.functions.phys2d.phys_query2d_z3_test
import * from "std/phys2d/phys_query2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Ray2D } from "std/math/geom2d"
import { Collider2D, ColliderShapeType2D } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query2d_raycast2dCircle_3(): int:
  let arg_ray = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2(x = 1.0, y = 1.0), direction = Vec2(x = 1.0, y = 1.0), maxDistance = 2.0)
  let edge_ray = Ray2D(origin = Vec2(x = 0.5, y = 0.5), dir = Vec2(x = 0.5, y = 0.5), direction = Vec2(x = 0.5, y = 0.5), maxDistance = 1.0)
  let arg_center = Vec2(x = 1.0, y = 1.0)
  let edge_center = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = raycast2dCircle(arg_ray, arg_center, arg_radius)
  let resEdge = raycast2dCircle(edge_ray, edge_center, edge_radius)
  assert(resNom.isSome() == false, "raycast2dCircle nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "raycast2dCircle boundary resEdge.isSome() == false")
  ret 0
```

---

### `raycast2dBox` (`std/phys2d/phys_query2d.aipl`)

- **Signature**: `pub fn raycast2dBox(ray: Ray2D, boxPos: Vec2, boxExtents: Vec2, boxAngle: float): Option[RayHit2D]:`
- **Import**: `import * from "std/phys2d/phys_query2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray2D, boxPos: Vec2, boxExtents: Vec2, boxAngle: float` | **Returns**: `Option[RayHit2D]`
- **Unit Test**: `tests/functions/phys2d/phys_query2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D analytical raycasts (segment, circle, box), circle shape-casts, and point-in-shape overlap queries in `raycast2dBox`. Concrete nominal inputs: `ray: Ray2D = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2 = Vec2(x = 1.0, y = 0.0)(), direction = Vec2 = Vec2(x = 1.0, y = 0.0)(), maxDistance = float = 1000.0())`, `boxPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `boxExtents: Vec2 = Vec2(x = 1.0, y = 1.0)`, `boxAngle: float = 1.0`; exercises core body path returning/computing `Some(RayHit2D(`.

```aipl
module tests.functions.phys2d.phys_query2d_z4_test
import * from "std/phys2d/phys_query2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Ray2D } from "std/math/geom2d"
import { Collider2D, ColliderShapeType2D } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query2d_raycast2dBox_4(): int:
  let arg_ray = Ray2D(origin = Vec2(x = 1.0, y = 1.0), dir = Vec2(x = 1.0, y = 1.0), direction = Vec2(x = 1.0, y = 1.0), maxDistance = 2.0)
  let edge_ray = Ray2D(origin = Vec2(x = 0.5, y = 0.5), dir = Vec2(x = 0.5, y = 0.5), direction = Vec2(x = 0.5, y = 0.5), maxDistance = 1.0)
  let arg_boxPos = Vec2(x = 1.0, y = 1.0)
  let edge_boxPos = Vec2(x = 0.5, y = 0.5)
  let arg_boxExtents = Vec2(x = 1.0, y = 1.0)
  let edge_boxExtents = Vec2(x = 0.5, y = 0.5)
  let arg_boxAngle = 1.0
  let edge_boxAngle = 0.5
  let resNom = raycast2dBox(arg_ray, arg_boxPos, arg_boxExtents, arg_boxAngle)
  let resEdge = raycast2dBox(edge_ray, edge_boxPos, edge_boxExtents, edge_boxAngle)
  assert(resNom.isSome() == true, "raycast2dBox nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "raycast2dBox boundary resEdge.isSome() == true")
  ret 0
```

---

### `shapeCastCircle2D` (`std/phys2d/phys_query2d.aipl`)

- **Signature**: `pub fn shapeCastCircle2D(startPos: Vec2, radius: float, delta: Vec2, colliders: [Collider2D]): Option[RayHit2D]:`
- **Import**: `import * from "std/phys2d/phys_query2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `startPos: Vec2, radius: float, delta: Vec2, colliders: [Collider2D]` | **Returns**: `Option[RayHit2D]`
- **Unit Test**: `tests/functions/phys2d/phys_query2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D analytical raycasts (segment, circle, box), circle shape-casts, and point-in-shape overlap queries in `shapeCastCircle2D`. Concrete nominal inputs: `startPos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `radius: float = 1.0`, `delta: Vec2 = Vec2(x = 1.0, y = 1.0)`, `colliders: [Collider2D] = [Collider2D(shapeType = ColliderShapeType2D(), offset = Vec2(x = 0, y = 0), circleRadius = 1.0, boxHalfExtents = Vec2(x = 0, y = 0), capsuleLength = 1.0, polygonVertices = [0], material = PhysicsMaterial2D(restitution = 0, friction = 0, density = 0), isSensor = true, collisionLayer = 1, collisionMask = 1)]`; exercises core body path returning/computing `bestHit`.

```aipl
module tests.functions.phys2d.phys_query2d_z5_test
import * from "std/phys2d/phys_query2d"
import { absFloat, minFloat, maxFloat } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Ray2D } from "std/math/geom2d"
import { Collider2D, ColliderShapeType2D } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query2d_shapeCastCircle2D_5(): int:
  let arg_startPos = Vec2(x = 1.0, y = 1.0)
  let edge_startPos = Vec2(x = 0.5, y = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_delta = Vec2(x = 1.0, y = 1.0)
  let edge_delta = Vec2(x = 0.5, y = 0.5)
  let arg_colliders = [Collider2D(shapeType = ColliderShapeType2D.Circle, offset = Vec2(x = 1.0, y = 1.0), circleRadius = 2.0, boxHalfExtents = Vec2(x = 1.0, y = 1.0), capsuleLength = 2.0, polygonVertices = [], material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)]
  let edge_colliders = []
  let resNom = shapeCastCircle2D(arg_startPos, arg_radius, arg_delta, arg_colliders)
  let resEdge = shapeCastCircle2D(edge_startPos, edge_radius, edge_delta, edge_colliders)
  assert(resNom.isSome() == false, "shapeCastCircle2D nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "shapeCastCircle2D boundary resEdge.isSome() == false")
  ret 0
```

---

### `physWorld2dNew` (`std/phys2d/phys_world2d.aipl`)

- **Signature**: `pub fn physWorld2dNew(gravity: Vec2): PhysicsWorld2D:`
- **Import**: `import * from "std/phys2d/phys_world2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `gravity: Vec2` | **Returns**: `PhysicsWorld2D`
- **Unit Test**: `tests/functions/phys2d/phys_world2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D physics world stepping, sequential impulse velocity/position constraint solving, restitution, and friction in `physWorld2dNew`. Concrete nominal inputs: `gravity: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `PhysicsWorld2D(`.

```aipl
module tests.functions.phys2d.phys_world2d_z1_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dNew_1(): int:
  let arg_gravity = Vec2(x = 1.0, y = 1.0)
  let edge_gravity = Vec2(x = 0.5, y = 0.5)
  let resNom = physWorld2dNew(arg_gravity)
  let resEdge = physWorld2dNew(edge_gravity)
  assertEqInt(resNom.bodies.len(), 0, "physWorld2dNew nominal resNom.bodies.len() == 0")
  assertEqInt(resEdge.bodies.len(), 0, "physWorld2dNew boundary resEdge.bodies.len() == 0")
  ret 0
```

---

### `physWorld2dAddBody` (`std/phys2d/phys_world2d.aipl`)

- **Signature**: `pub fn physWorld2dAddBody(mut world: PhysicsWorld2D, body: RigidBody2D): int:`
- **Import**: `import * from "std/phys2d/phys_world2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld2D, body: RigidBody2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys2d/phys_world2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D physics world stepping, sequential impulse velocity/position constraint solving, restitution, and friction in `physWorld2dAddBody`. Concrete nominal inputs: `world: PhysicsWorld2D = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0, y = 0), velocityIterations = 1, positionIterations = 0, subSteps = 1, allowSleep = true), bodies = [RigidBody2D(id = 0, bodyType = 0, position = 0, angle = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, gravityScale = 0, massProps = 0, isAwake = 0, isBullet = 0)], colliders = [Collider2D(shapeType = 0, offset = 0, circleRadius = 0, boxHalfExtents = 0, capsuleLength = 0, polygonVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint2D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, targetDistance = 0, springStiffness = 0, springDamping = 0, minLimit = 0, maxLimit = 0, enableLimits = 0)], broadphase = DynamicAABBTree2D(nodes = [0], root = 1, freeList = 1))`, `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`; exercises core body path returning/computing `idx`.

```aipl
module tests.functions.phys2d.phys_world2d_z2_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dAddBody_2(): int:
  let arg_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 1.0, y = 1.0), velocityIterations = 4, positionIterations = 4, subSteps = 4, allowSleep = true), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2))
  let edge_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0.5, y = 0.5), velocityIterations = 1, positionIterations = 1, subSteps = 1, allowSleep = false), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0))
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let resNom = physWorld2dAddBody(arg_world, arg_body)
  let resEdge = physWorld2dAddBody(edge_world, edge_body)
  assertEqInt(resNom, 0, "physWorld2dAddBody nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld2dAddBody boundary resEdge == 0")
  ret 0
```

---

### `physWorld2dAddCollider` (`std/phys2d/phys_world2d.aipl`)

- **Signature**: `pub fn physWorld2dAddCollider(mut world: PhysicsWorld2D, bodyId: int, collider: Collider2D): int:`
- **Import**: `import * from "std/phys2d/phys_world2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld2D, bodyId: int, collider: Collider2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys2d/phys_world2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D physics world stepping, sequential impulse velocity/position constraint solving, restitution, and friction in `physWorld2dAddCollider`. Concrete nominal inputs: `world: PhysicsWorld2D = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0, y = 0), velocityIterations = 1, positionIterations = 0, subSteps = 1, allowSleep = true), bodies = [RigidBody2D(id = 0, bodyType = 0, position = 0, angle = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, gravityScale = 0, massProps = 0, isAwake = 0, isBullet = 0)], colliders = [Collider2D(shapeType = 0, offset = 0, circleRadius = 0, boxHalfExtents = 0, capsuleLength = 0, polygonVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint2D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, targetDistance = 0, springStiffness = 0, springDamping = 0, minLimit = 0, maxLimit = 0, enableLimits = 0)], broadphase = DynamicAABBTree2D(nodes = [0], root = 1, freeList = 1))`, `bodyId: int = 1`, `collider: Collider2D = Collider2D(shapeType = ColliderShapeType2D(), offset = Vec2(x = 1.0, y = 1.0), circleRadius = 1.0, boxHalfExtents = Vec2(x = 1.0, y = 1.0), capsuleLength = 1.0, polygonVertices = [Vec2(x = 0, y = 0)], material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`; exercises core body path returning/computing `colIdx`.

```aipl
module tests.functions.phys2d.phys_world2d_z3_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dAddCollider_3(): int:
  let arg_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 1.0, y = 1.0), velocityIterations = 4, positionIterations = 4, subSteps = 4, allowSleep = true), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2))
  let edge_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0.5, y = 0.5), velocityIterations = 1, positionIterations = 1, subSteps = 1, allowSleep = false), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0))
  let arg_bodyId = 4
  let edge_bodyId = 1
  let arg_collider = Collider2D(shapeType = ColliderShapeType2D.Circle, offset = Vec2(x = 1.0, y = 1.0), circleRadius = 2.0, boxHalfExtents = Vec2(x = 1.0, y = 1.0), capsuleLength = 2.0, polygonVertices = [], material = PhysicsMaterial2D(restitution = 1.0, friction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_collider = Collider2D(shapeType = ColliderShapeType2D.Circle, offset = Vec2(x = 0.5, y = 0.5), circleRadius = 1.0, boxHalfExtents = Vec2(x = 0.5, y = 0.5), capsuleLength = 1.0, polygonVertices = [], material = PhysicsMaterial2D(restitution = 0.5, friction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let resNom = physWorld2dAddCollider(arg_world, arg_bodyId, arg_collider)
  let resEdge = physWorld2dAddCollider(edge_world, edge_bodyId, edge_collider)
  assertEqInt(resNom, 0, "physWorld2dAddCollider nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld2dAddCollider boundary resEdge == 0")
  ret 0
```

---

### `physWorld2dAddJoint` (`std/phys2d/phys_world2d.aipl`)

- **Signature**: `pub fn physWorld2dAddJoint(mut world: PhysicsWorld2D, joint: Joint2D): int:`
- **Import**: `import * from "std/phys2d/phys_world2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld2D, joint: Joint2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys2d/phys_world2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D physics world stepping, sequential impulse velocity/position constraint solving, restitution, and friction in `physWorld2dAddJoint`. Concrete nominal inputs: `world: PhysicsWorld2D = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0, y = 0), velocityIterations = 1, positionIterations = 0, subSteps = 1, allowSleep = true), bodies = [RigidBody2D(id = 0, bodyType = 0, position = 0, angle = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, gravityScale = 0, massProps = 0, isAwake = 0, isBullet = 0)], colliders = [Collider2D(shapeType = 0, offset = 0, circleRadius = 0, boxHalfExtents = 0, capsuleLength = 0, polygonVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint2D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, targetDistance = 0, springStiffness = 0, springDamping = 0, minLimit = 0, maxLimit = 0, enableLimits = 0)], broadphase = DynamicAABBTree2D(nodes = [0], root = 1, freeList = 1))`, `joint: Joint2D = Joint2D(id = 1, jointType = JointType2D(), bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 1.0, maxLimit = 1.0, enableLimits = true)`; exercises core body path returning/computing `jIdx`.

```aipl
module tests.functions.phys2d.phys_world2d_z4_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dAddJoint_4(): int:
  let arg_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 1.0, y = 1.0), velocityIterations = 4, positionIterations = 4, subSteps = 4, allowSleep = true), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2))
  let edge_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0.5, y = 0.5), velocityIterations = 1, positionIterations = 1, subSteps = 1, allowSleep = false), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0))
  let arg_joint = Joint2D(id = 1, jointType = JointType2D.Distance, bodyIdA = 4, bodyIdB = 4, localAnchorA = Vec2(x = 1.0, y = 1.0), localAnchorB = Vec2(x = 1.0, y = 1.0), targetDistance = 1.0, springStiffness = 1.0, springDamping = 1.0, minLimit = 0.0, maxLimit = 2.0, enableLimits = true)
  let edge_joint = Joint2D(id = 0, jointType = JointType2D.Distance, bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec2(x = 0.5, y = 0.5), localAnchorB = Vec2(x = 0.5, y = 0.5), targetDistance = 0.5, springStiffness = 0.5, springDamping = 0.5, minLimit = 0.0, maxLimit = 1.0, enableLimits = false)
  let resNom = physWorld2dAddJoint(arg_world, arg_joint)
  let resEdge = physWorld2dAddJoint(edge_world, edge_joint)
  assertEqInt(resNom, 0, "physWorld2dAddJoint nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld2dAddJoint boundary resEdge == 0")
  ret 0
```

---

### `physWorld2dStep` (`std/phys2d/phys_world2d.aipl`)

- **Signature**: `pub fn physWorld2dStep(mut world: PhysicsWorld2D, dt: float): void:`
- **Import**: `import * from "std/phys2d/phys_world2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld2D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/phys_world2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D physics world stepping, sequential impulse velocity/position constraint solving, restitution, and friction in `physWorld2dStep`. Concrete nominal inputs: `world: PhysicsWorld2D = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0, y = 0), velocityIterations = 1, positionIterations = 0, subSteps = 1, allowSleep = true), bodies = [RigidBody2D(id = 0, bodyType = 0, position = 0, angle = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, gravityScale = 0, massProps = 0, isAwake = 0, isBullet = 0)], colliders = [Collider2D(shapeType = 0, offset = 0, circleRadius = 0, boxHalfExtents = 0, capsuleLength = 0, polygonVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint2D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, targetDistance = 0, springStiffness = 0, springDamping = 0, minLimit = 0, maxLimit = 0, enableLimits = 0)], broadphase = DynamicAABBTree2D(nodes = [0], root = 1, freeList = 1))`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.phys_world2d_z5_test
import * from "std/phys2d/phys_world2d"
import { Vec2 } from "std/math/vec_math"
import { RigidBody2D, rigidBody2dIntegrateVelocity, rigidBody2dIntegratePosition } from "std/phys2d/rigid_body2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { DynamicAABBTree2D, dynamicAABBTreeNew, dynamicAABBTreeInsert } from "std/phys2d/broadphase2d"
import { Joint2D, jointSolveVelocity, jointSolvePosition } from "std/phys2d/joint2d"
import { Collider2D, colliderComputeAABB } from "std/phys2d/collider2d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world2d_physWorld2dStep_5(): int:
  let arg_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 1.0, y = 1.0), velocityIterations = 4, positionIterations = 4, subSteps = 4, allowSleep = true), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 2, freeList = 2))
  let edge_world = PhysicsWorld2D(settings = PhysWorldSettings2D(gravity = Vec2(x = 0.5, y = 0.5), velocityIterations = 1, positionIterations = 1, subSteps = 1, allowSleep = false), bodies = [], colliders = [], colliderBodyIds = [], joints = [], broadphase = DynamicAABBTree2D(nodes = [], root = 0, freeList = 0))
  let arg_dt = 2.0
  let edge_dt = 1.0
  physWorld2dStep(arg_world, arg_dt)
  physWorld2dStep(edge_world, edge_dt)
  assertEqInt(arg_world.bodies.len(), 0, "physWorld2dStep nominal arg_world.bodies.len() == 0")
  assertEqInt(edge_world.bodies.len(), 0, "physWorld2dStep boundary edge_world.bodies.len() == 0")
  ret 0
```

---

### `rigidBody2dNew` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dNew(id: int, bodyType: BodyType2D, position: Vec2, angle: float): RigidBody2D:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, bodyType: BodyType2D, position: Vec2, angle: float` | **Returns**: `RigidBody2D`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dNew`. Concrete nominal inputs: `id: int = 1`, `bodyType: BodyType2D = BodyType2D()`, `position: Vec2 = Vec2(x = 1.0, y = 1.0)`, `angle: float = 1.0`; exercises core body path returning/computing `RigidBody2D(`.

```aipl
module tests.functions.phys2d.rigid_body2d_z1_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dNew_1(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_bodyType = BodyType2D.Static
  let edge_bodyType = BodyType2D.Static
  let arg_position = Vec2(x = 1.0, y = 1.0)
  let edge_position = Vec2(x = 0.5, y = 0.5)
  let arg_angle = 1.0
  let edge_angle = 0.5
  let resNom = rigidBody2dNew(arg_id, arg_bodyType, arg_position, arg_angle)
  let resEdge = rigidBody2dNew(edge_id, edge_bodyType, edge_position, edge_angle)
  assertEqInt(resNom.id, 1, "rigidBody2dNew nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "rigidBody2dNew boundary resEdge.id == 0")
  ret 0
```

---

### `rigidBody2dSetMass` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dSetMass(mut body: RigidBody2D, mass: float, inertia: float): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, mass: float, inertia: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dSetMass`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `mass: float = 1.0`, `inertia: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z2_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dSetMass_2(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_mass = 2.0
  let edge_mass = 1.0
  let arg_inertia = 1.0
  let edge_inertia = 0.5
  rigidBody2dSetMass(arg_body, arg_mass, arg_inertia)
  rigidBody2dSetMass(edge_body, edge_mass, edge_inertia)
  assertApproxEq(arg_body.massProps.mass, 0.0, 0.0001, "rigidBody2dSetMass nominal arg_body.massProps.mass approx 0.0")
  assertApproxEq(edge_body.massProps.mass, 0.0, 0.0001, "rigidBody2dSetMass boundary edge_body.massProps.mass approx 0.0")
  ret 0
```

---

### `rigidBody2dApplyForce` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dApplyForce(mut body: RigidBody2D, force: Vec2, worldPoint: Vec2): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, force: Vec2, worldPoint: Vec2` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dApplyForce`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `force: Vec2 = Vec2(x = 1.0, y = 1.0)`, `worldPoint: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z3_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dApplyForce_3(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_force = Vec2(x = 1.0, y = 1.0)
  let edge_force = Vec2(x = 0.5, y = 0.5)
  let arg_worldPoint = Vec2(x = 1.0, y = 1.0)
  let edge_worldPoint = Vec2(x = 0.5, y = 0.5)
  rigidBody2dApplyForce(arg_body, arg_force, arg_worldPoint)
  rigidBody2dApplyForce(edge_body, edge_force, edge_worldPoint)
  assertEqInt(arg_body.id, 1, "rigidBody2dApplyForce nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody2dApplyForce boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody2dApplyLinearImpulse` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dApplyLinearImpulse(mut body: RigidBody2D, impulse: Vec2): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, impulse: Vec2` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dApplyLinearImpulse`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `impulse: Vec2 = Vec2(x = 1.0, y = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z4_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dApplyLinearImpulse_4(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_impulse = Vec2(x = 1.0, y = 1.0)
  let edge_impulse = Vec2(x = 0.5, y = 0.5)
  rigidBody2dApplyLinearImpulse(arg_body, arg_impulse)
  rigidBody2dApplyLinearImpulse(edge_body, edge_impulse)
  assertEqInt(arg_body.id, 1, "rigidBody2dApplyLinearImpulse nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody2dApplyLinearImpulse boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody2dApplyAngularImpulse` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dApplyAngularImpulse(mut body: RigidBody2D, impulse: float): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, impulse: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dApplyAngularImpulse`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `impulse: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z5_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dApplyAngularImpulse_5(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_impulse = 1.0
  let edge_impulse = 0.5
  rigidBody2dApplyAngularImpulse(arg_body, arg_impulse)
  rigidBody2dApplyAngularImpulse(edge_body, edge_impulse)
  assertEqInt(arg_body.id, 1, "rigidBody2dApplyAngularImpulse nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody2dApplyAngularImpulse boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody2dIntegrateVelocity` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dIntegrateVelocity(mut body: RigidBody2D, gravity: Vec2, dt: float): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, gravity: Vec2, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dIntegrateVelocity`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `gravity: Vec2 = Vec2(x = 1.0, y = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z6_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dIntegrateVelocity_6(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_gravity = Vec2(x = 1.0, y = 1.0)
  let edge_gravity = Vec2(x = 0.5, y = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  rigidBody2dIntegrateVelocity(arg_body, arg_gravity, arg_dt)
  rigidBody2dIntegrateVelocity(edge_body, edge_gravity, edge_dt)
  assertEqInt(arg_body.id, 1, "rigidBody2dIntegrateVelocity nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody2dIntegrateVelocity boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody2dIntegratePosition` (`std/phys2d/rigid_body2d.aipl`)

- **Signature**: `pub fn rigidBody2dIntegratePosition(mut body: RigidBody2D, dt: float): void:`
- **Import**: `import * from "std/phys2d/rigid_body2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody2D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/rigid_body2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Tests 2D rigid body mass/inertia initialization, force/torque accumulation, impulse application, and semi-implicit Euler integration in `rigidBody2dIntegratePosition`. Concrete nominal inputs: `body: RigidBody2D = RigidBody2D(id = 1, bodyType = BodyType2D(), position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 1.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 0, y = 0)), isAwake = true, isBullet = true)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.rigid_body2d_z7_test
import * from "std/phys2d/rigid_body2d"
import { maxFloat } from "std/math/consts"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body2d_rigidBody2dIntegratePosition_7(): int:
  let arg_body = RigidBody2D(id = 1, bodyType = BodyType2D.Static, position = Vec2(x = 1.0, y = 1.0), angle = 1.0, linearVelocity = Vec2(x = 1.0, y = 1.0), angularVelocity = 0.0, linearDamping = 1.0, angularDamping = 1.0, gravityScale = 2.0, massProps = MassProperties2D(mass = 2.0, invMass = 2.0, inertia = 1.0, invInertia = 1.0, localCenter = Vec2(x = 1.0, y = 1.0)), isAwake = true, isBullet = true)
  let edge_body = RigidBody2D(id = 0, bodyType = BodyType2D.Static, position = Vec2(x = 0.5, y = 0.5), angle = 0.5, linearVelocity = Vec2(x = 0.5, y = 0.5), angularVelocity = 0.0, linearDamping = 0.5, angularDamping = 0.5, gravityScale = 1.0, massProps = MassProperties2D(mass = 1.0, invMass = 1.0, inertia = 0.5, invInertia = 0.5, localCenter = Vec2(x = 0.5, y = 0.5)), isAwake = false, isBullet = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  rigidBody2dIntegratePosition(arg_body, arg_dt)
  rigidBody2dIntegratePosition(edge_body, edge_dt)
  assertEqInt(arg_body.id, 1, "rigidBody2dIntegratePosition nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody2dIntegratePosition boundary edge_body.id == 0")
  ret 0
```

---

### `verletParticleNew` (`std/phys2d/verlet2d.aipl`)

- **Signature**: `pub fn verletParticleNew(pos: Vec2, isPinned: bool): VerletParticle2D:`
- **Import**: `import * from "std/phys2d/verlet2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec2, isPinned: bool` | **Returns**: `VerletParticle2D`
- **Unit Test**: `tests/functions/phys2d/verlet2d_test.aipl` | **Example**: `examples/ex_218_phys2d_broadphase_sap_grid_window.aipl`
- **Behavioral Summary**: Verifies 2D Verlet particle integration, pinned cloth grid construction, and iterative distance stick constraint relaxation in `verletParticleNew`. Concrete nominal inputs: `pos: Vec2 = Vec2(x = 1.0, y = 1.0)`, `isPinned: bool = true`; exercises core body path returning/computing `VerletParticle2D(`.

```aipl
module tests.functions.phys2d.verlet2d_z1_test
import * from "std/phys2d/verlet2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_verlet2d_verletParticleNew_1(): int:
  let arg_pos = Vec2(x = 1.0, y = 1.0)
  let edge_pos = Vec2(x = 0.5, y = 0.5)
  let arg_isPinned = true
  let edge_isPinned = false
  let resNom = verletParticleNew(arg_pos, arg_isPinned)
  let resEdge = verletParticleNew(edge_pos, edge_isPinned)
  assert(resNom.isPinned == true, "verletParticleNew nominal resNom.isPinned == true")
  assert(resEdge.isPinned == false, "verletParticleNew boundary resEdge.isPinned == false")
  ret 0
```

---

### `verletClothGridNew` (`std/phys2d/verlet2d.aipl`)

- **Signature**: `pub fn verletClothGridNew(cols: int, rows: int, spacing: float): VerletClothGrid2D:`
- **Import**: `import * from "std/phys2d/verlet2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `cols: int, rows: int, spacing: float` | **Returns**: `VerletClothGrid2D`
- **Unit Test**: `tests/functions/phys2d/verlet2d_test.aipl` | **Example**: `examples/ex_219_phys2d_joint_pendulum_and_bridge_window.aipl`
- **Behavioral Summary**: Verifies 2D Verlet particle integration, pinned cloth grid construction, and iterative distance stick constraint relaxation in `verletClothGridNew`. Concrete nominal inputs: `cols: int = 1`, `rows: int = 1`, `spacing: float = 1.0`; exercises core body path returning/computing `VerletClothGrid2D(particles = pts, sticks = stks, cols = cols, rows = rows)`.

```aipl
module tests.functions.phys2d.verlet2d_z2_test
import * from "std/phys2d/verlet2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_verlet2d_verletClothGridNew_2(): int:
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let arg_spacing = 1.0
  let edge_spacing = 0.5
  let resNom = verletClothGridNew(arg_cols, arg_rows, arg_spacing)
  let resEdge = verletClothGridNew(edge_cols, edge_rows, edge_spacing)
  assertEqInt(resNom.particles.len(), 16, "verletClothGridNew nominal resNom.particles.len() == 16")
  assertEqInt(resEdge.particles.len(), 1, "verletClothGridNew boundary resEdge.particles.len() == 1")
  ret 0
```

---

### `verletStepSimulation` (`std/phys2d/verlet2d.aipl`)

- **Signature**: `pub fn verletStepSimulation(mut cloth: VerletClothGrid2D, gravity: Vec2, iterations: int, dt: float): void:`
- **Import**: `import * from "std/phys2d/verlet2d"` (or barrel `import * from "std/phys2d/phys2d_mod"`) (Note: 2D fluid module is canonically named `std/phys2d/fluid2d`)
- **Receiver**: `None (free function)` | **Parameters**: `mut cloth: VerletClothGrid2D, gravity: Vec2, iterations: int, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys2d/verlet2d_test.aipl` | **Example**: `examples/ex_217_phys2d_collider_sat_polygons_window.aipl`
- **Behavioral Summary**: Verifies 2D Verlet particle integration, pinned cloth grid construction, and iterative distance stick constraint relaxation in `verletStepSimulation`. Concrete nominal inputs: `cloth: VerletClothGrid2D = VerletClothGrid2D(particles = [VerletParticle2D(position = 0, prevPosition = 0, acceleration = 0, isPinned = 0)], sticks = [VerletStick2D(p1Idx = 0, p2Idx = 0, restLength = 0, stiffness = 0)], cols = 1, rows = 1)`, `gravity: Vec2 = Vec2(x = 1.0, y = 1.0)`, `iterations: int = 1`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys2d.verlet2d_z3_test
import * from "std/phys2d/verlet2d"
import { sqrt } from "std/math/trig"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_verlet2d_verletStepSimulation_3(): int:
  let arg_cloth = VerletClothGrid2D(particles = [], sticks = [], cols = 4, rows = 4)
  let edge_cloth = VerletClothGrid2D(particles = [], sticks = [], cols = 4, rows = 4)
  let arg_gravity = Vec2(x = 1.0, y = 1.0)
  let edge_gravity = Vec2(x = 0.5, y = 0.5)
  let arg_iterations = 4
  let edge_iterations = 1
  let arg_dt = 2.0
  let edge_dt = 1.0
  verletStepSimulation(arg_cloth, arg_gravity, arg_iterations, arg_dt)
  verletStepSimulation(edge_cloth, edge_gravity, edge_iterations, edge_dt)
  assertEqInt(arg_cloth.particles.len(), 0, "verletStepSimulation nominal arg_cloth.particles.len() == 0")
  assertEqInt(edge_cloth.particles.len(), 0, "verletStepSimulation boundary edge_cloth.particles.len() == 0")
  ret 0
```
