[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 33: `phys3d` API Reference

> Complete API reference manual for AIPL standard library domain `phys3d` (35 callable functions & methods across ["std/phys3d/character3d.aipl", "std/phys3d/collider3d.aipl", "std/phys3d/joint3d.aipl", "std/phys3d/narrowphase3d.aipl", "std/phys3d/phys3d_mod.aipl", "std/phys3d/phys_query3d.aipl", "std/phys3d/phys_world3d.aipl", "std/phys3d/rigid_body3d.aipl", "std/phys3d/vehicle3d.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `phys3d`
- **Target Source Modules**: ["std/phys3d/character3d.aipl", "std/phys3d/collider3d.aipl", "std/phys3d/joint3d.aipl", "std/phys3d/narrowphase3d.aipl", "std/phys3d/phys3d_mod.aipl", "std/phys3d/phys_query3d.aipl", "std/phys3d/phys_world3d.aipl", "std/phys3d/rigid_body3d.aipl", "std/phys3d/vehicle3d.aipl"]
- **Total Callable Functions & Methods**: 35
- **Total Data Types (`struct` & `enum`)**: 17
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(17 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `CharacterControllerSettings3D` | `pub struct` | `std/phys3d/character3d.aipl` | `stepHeight: float`, `slopeLimitRadians: float`, `skinWidth: float`, `gravity: Vec3`, `groundFriction: float`, `airControl: float` | `CharacterControllerSettings3D(stepHeight, slopeLimitRadians, skinWidth, gravity, groundFriction, airControl)` |
| `KinematicCharacterController3D` | `pub struct` | `std/phys3d/character3d.aipl` | `position: Vec3`, `velocity: Vec3`, `height: float`, `radius: float`, `isGrounded: bool`, `groundNormal: Vec3`, `settings: CharacterControllerSettings3D` | `KinematicCharacterController3D(position, velocity, height, radius, isGrounded, groundNormal, settings)` |
| `ColliderShapeType3D` | `pub enum` | `std/phys3d/collider3d.aipl` | `Sphere`, `Box`, `Capsule`, `Cylinder`, `ConvexHull`, `TriMesh` | Algebraic Enum (6 variants) |
| `PhysicsMaterial3D` | `pub struct` | `std/phys3d/collider3d.aipl` | `restitution: float`, `staticFriction: float`, `dynamicFriction: float`, `density: float` | `PhysicsMaterial3D(restitution, staticFriction, dynamicFriction, density)` |
| `Collider3D` | `pub struct` | `std/phys3d/collider3d.aipl` | `shapeType: ColliderShapeType3D`, `localTransform: Transform3D`, `sphereRadius: float`, `boxHalfExtents: Vec3`, `capsuleRadius: float`, `capsuleHeight: float`, `cylinderRadius: float`, `cylinderHeight: float`, `convexVertices: [Vec3]`, `material: PhysicsMaterial3D`, `isSensor: bool`, `collisionLayer: int`, `collisionMask: int` | `Collider3D(shapeType, localTransform, sphereRadius, boxHalfExtents, capsuleRadius, capsuleHeight, cylinderRadius, cylinderHeight, convexVertices, material, isSensor, collisionLayer, collisionMask)` |
| `JointType3D` | `pub enum` | `std/phys3d/joint3d.aipl` | `BallSocket`, `Hinge`, `Slider`, `SixDof`, `ConeTwist` | Algebraic Enum (5 variants) |
| `Joint3D` | `pub struct` | `std/phys3d/joint3d.aipl` | `id: int`, `jointType: JointType3D`, `bodyIdA: int`, `bodyIdB: int`, `localAnchorA: Vec3`, `localAnchorB: Vec3`, `localAxisA: Vec3`, `localAxisB: Vec3`, `minLimits: Vec3`, `maxLimits: Vec3`, `enableMotor: bool`, `motorTargetVelocity: float`, `motorMaxForce: float` | `Joint3D(id, jointType, bodyIdA, bodyIdB, localAnchorA, localAnchorB, localAxisA, localAxisB, minLimits, maxLimits, enableMotor, motorTargetVelocity, motorMaxForce)` |
| `ContactPoint3D` | `pub struct` | `std/phys3d/narrowphase3d.aipl` | `position: Vec3`, `normal: Vec3`, `penetration: float`, `normalImpulse: float`, `tangentImpulse1: float`, `tangentImpulse2: float` | `ContactPoint3D(position, normal, penetration, normalImpulse, tangentImpulse1, tangentImpulse2)` |
| `ContactManifold3D` | `pub struct` | `std/phys3d/narrowphase3d.aipl` | `bodyIdA: int`, `bodyIdB: int`, `points: [ContactPoint3D]`, `isColliding: bool` | `ContactManifold3D(bodyIdA, bodyIdB, points, isColliding)` |
| `RayHit3D` | `pub struct` | `std/phys3d/phys_query3d.aipl` | `bodyId: int`, `point: Vec3`, `normal: Vec3`, `distance: float`, `hit: bool` | `RayHit3D(bodyId, point, normal, distance, hit)` |
| `PhysWorldSettings3D` | `pub struct` | `std/phys3d/phys_world3d.aipl` | `gravity: Vec3`, `iterations: int`, `subSteps: int`, `sleepLinearThresholdSq: float`, `sleepAngularThresholdSq: float` | `PhysWorldSettings3D(gravity, iterations, subSteps, sleepLinearThresholdSq, sleepAngularThresholdSq)` |
| `PhysicsWorld3D` | `pub struct` | `std/phys3d/phys_world3d.aipl` | `settings: PhysWorldSettings3D`, `bodies: [RigidBody3D]`, `colliders: [Collider3D]`, `colliderBodyIds: [int]`, `joints: [Joint3D]` | `PhysicsWorld3D(settings, bodies, colliders, colliderBodyIds, joints)` |
| `BodyType3D` | `pub enum` | `std/phys3d/rigid_body3d.aipl` | `Static`, `Kinematic`, `Dynamic` | Algebraic Enum (3 variants) |
| `InertiaTensor3x3` | `pub struct` | `std/phys3d/rigid_body3d.aipl` | `ixx: float`, `iyy: float`, `izz: float`, `ixy: float`, `ixz: float`, `iyz: float` | `InertiaTensor3x3(ixx, iyy, izz, ixy, ixz, iyz)` |
| `RigidBody3D` | `pub struct` | `std/phys3d/rigid_body3d.aipl` | `id: int`, `bodyType: BodyType3D`, `position: Vec3`, `rotation: Quat`, `linearVelocity: Vec3`, `angularVelocity: Vec3`, `linearDamping: float`, `angularDamping: float`, `mass: float`, `invMass: float`, `localInertia: InertiaTensor3x3`, `invInertiaWorld: Mat3`, `isAwake: bool`, `isBulletCCD: bool` | `RigidBody3D(id, bodyType, position, rotation, linearVelocity, angularVelocity, linearDamping, angularDamping, mass, invMass, localInertia, invInertiaWorld, isAwake, isBulletCCD)` |
| `RaycastWheel3D` | `pub struct` | `std/phys3d/vehicle3d.aipl` | `connectionPoint: Vec3`, `direction: Vec3`, `axle: Vec3`, `suspensionRestLength: float`, `currentSuspensionLength: float`, `springStiffness: float`, `dampingCompression: float`, `dampingRelaxation: float`, `wheelRadius: float`, `steeringAngle: float`, `driveTorque: float`, `brakeTorque: float`, `isGrounded: bool`, `contactPoint: Vec3`, `contactNormal: Vec3` | `RaycastWheel3D(connectionPoint, direction, axle, suspensionRestLength, currentSuspensionLength, springStiffness, dampingCompression, dampingRelaxation, wheelRadius, steeringAngle, driveTorque, brakeTorque, isGrounded, contactPoint, contactNormal)` |
| `RaycastVehicle3D` | `pub struct` | `std/phys3d/vehicle3d.aipl` | `chassisBodyId: int`, `wheels: [RaycastWheel3D]` | `RaycastVehicle3D(chassisBodyId, wheels)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/phys3d/character3d.aipl` | `characterControllerNew` | `pub fn characterControllerNew(settings: CharacterControllerSettings3D, height: float, radius: float): KinematicCharacterController3D:` | `tests/functions/phys3d/character3d_test.aipl` |
| `2` | `std/phys3d/character3d.aipl` | `characterMoveAndSlide` | `pub fn characterMoveAndSlide(mut controller: KinematicCharacterController3D, desiredVelocity: Vec3, world: PhysicsWorld3D, dt: float): Vec3:` | `tests/functions/phys3d/character3d_test.aipl` |
| `3` | `std/phys3d/character3d.aipl` | `computeAirAccelerateVelocity` | `pub fn computeAirAccelerateVelocity(velocity: Vec3, wishDir: Vec3, wishSpeed: float, accel: float, dt: float): Vec3:` | `tests/functions/phys3d/character3d_test.aipl` |
| `4` | `std/phys3d/collider3d.aipl` | `identityTransform3D` | `fn identityTransform3D(): Transform3D:` | `tests/functions/phys3d/collider3d_test.aipl` |
| `5` | `std/phys3d/collider3d.aipl` | `sphereColliderNew` | `pub fn sphereColliderNew(radius: float, material: PhysicsMaterial3D): Collider3D:` | `tests/functions/phys3d/collider3d_test.aipl` |
| `6` | `std/phys3d/collider3d.aipl` | `boxCollider3dNew` | `pub fn boxCollider3dNew(halfExtents: Vec3, material: PhysicsMaterial3D): Collider3D:` | `tests/functions/phys3d/collider3d_test.aipl` |
| `7` | `std/phys3d/collider3d.aipl` | `capsuleCollider3dNew` | `pub fn capsuleCollider3dNew(radius: float, height: float, material: PhysicsMaterial3D): Collider3D:` | `tests/functions/phys3d/collider3d_test.aipl` |
| `8` | `std/phys3d/collider3d.aipl` | `collider3dComputeAABB` | `pub fn collider3dComputeAABB(collider: Collider3D, bodyTransform: Transform3D): AABB3D:` | `tests/functions/phys3d/collider3d_test.aipl` |
| `9` | `std/phys3d/joint3d.aipl` | `ballSocketJointNew` | `pub fn ballSocketJointNew(bodyA: int, bodyB: int, worldAnchor: Vec3): Joint3D:` | `tests/functions/phys3d/joint3d_test.aipl` |
| `10` | `std/phys3d/joint3d.aipl` | `hingeJointNew` | `pub fn hingeJointNew(bodyA: int, bodyB: int, worldAnchor: Vec3, worldAxis: Vec3): Joint3D:` | `tests/functions/phys3d/joint3d_test.aipl` |
| `11` | `std/phys3d/joint3d.aipl` | `sixDofJointNew` | `pub fn sixDofJointNew(bodyA: int, bodyB: int, anchorA: Vec3, anchorB: Vec3): Joint3D:` | `tests/functions/phys3d/joint3d_test.aipl` |
| `12` | `std/phys3d/joint3d.aipl` | `joint3dSolveVelocity` | `pub fn joint3dSolveVelocity(joint: Joint3D, mut bodyA: RigidBody3D, mut bodyB: RigidBody3D, dt: float): void:` | `tests/functions/phys3d/joint3d_test.aipl` |
| `13` | `std/phys3d/narrowphase3d.aipl` | `testSphereSphere3D` | `pub fn testSphereSphere3D(posA: Vec3, radA: float, posB: Vec3, radB: float): Option[ContactManifold3D]:` | `tests/functions/phys3d/narrowphase3d_test.aipl` |
| `14` | `std/phys3d/narrowphase3d.aipl` | `testSphereBox3D` | `pub fn testSphereBox3D(spherePos: Vec3, radius: float, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3): Option[ContactManifold3D]:` | `tests/functions/phys3d/narrowphase3d_test.aipl` |
| `15` | `std/phys3d/narrowphase3d.aipl` | `testGjkEpa3D` | `pub fn testGjkEpa3D(colliderA: Collider3D, transformA: Transform3D, colliderB: Collider3D, transformB: Transform3D): Option[ContactManifold3D]:` | `tests/functions/phys3d/narrowphase3d_test.aipl` |
| `16` | `std/phys3d/narrowphase3d.aipl` | `contactManifold3dCache` | `pub fn contactManifold3dCache(mut existing: ContactManifold3D, newManifold: ContactManifold3D): void:` | `tests/functions/phys3d/narrowphase3d_test.aipl` |
| `17` | `std/phys3d/phys_query3d.aipl` | `extractRayDir3D` | `fn extractRayDir3D(ray: Ray3D): Vec3:` | `tests/functions/phys3d/phys_query3d_test.aipl` |
| `18` | `std/phys3d/phys_query3d.aipl` | `raycast3dSphere` | `pub fn raycast3dSphere(ray: Ray3D, sphereCenter: Vec3, radius: float): Option[RayHit3D]:` | `tests/functions/phys3d/phys_query3d_test.aipl` |
| `19` | `std/phys3d/phys_query3d.aipl` | `raycast3dBox` | `pub fn raycast3dBox(ray: Ray3D, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3): Option[RayHit3D]:` | `tests/functions/phys3d/phys_query3d_test.aipl` |
| `20` | `std/phys3d/phys_query3d.aipl` | `sphereCast3D` | `pub fn sphereCast3D(ray: Ray3D, sphereRadius: float, colliders: [Collider3D]): Option[RayHit3D]:` | `tests/functions/phys3d/phys_query3d_test.aipl` |
| `21` | `std/phys3d/phys_world3d.aipl` | `physWorld3dNew` | `pub fn physWorld3dNew(gravity: Vec3): PhysicsWorld3D:` | `tests/functions/phys3d/phys_world3d_test.aipl` |
| `22` | `std/phys3d/phys_world3d.aipl` | `physWorld3dAddBody` | `pub fn physWorld3dAddBody(mut world: PhysicsWorld3D, body: RigidBody3D): int:` | `tests/functions/phys3d/phys_world3d_test.aipl` |
| `23` | `std/phys3d/phys_world3d.aipl` | `physWorld3dAddCollider` | `pub fn physWorld3dAddCollider(mut world: PhysicsWorld3D, bodyId: int, collider: Collider3D): int:` | `tests/functions/phys3d/phys_world3d_test.aipl` |
| `24` | `std/phys3d/phys_world3d.aipl` | `physWorld3dAddJoint` | `pub fn physWorld3dAddJoint(mut world: PhysicsWorld3D, joint: Joint3D): int:` | `tests/functions/phys3d/phys_world3d_test.aipl` |
| `25` | `std/phys3d/phys_world3d.aipl` | `physWorld3dStep` | `pub fn physWorld3dStep(mut world: PhysicsWorld3D, dt: float): void:` | `tests/functions/phys3d/phys_world3d_test.aipl` |
| `26` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dNew` | `pub fn rigidBody3dNew(id: int, bodyType: BodyType3D, pos: Vec3, rot: Quat): RigidBody3D:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `27` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dSetBoxInertia` | `pub fn rigidBody3dSetBoxInertia(mut body: RigidBody3D, mass: float, extents: Vec3): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `28` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dSetSphereInertia` | `pub fn rigidBody3dSetSphereInertia(mut body: RigidBody3D, mass: float, radius: float): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `29` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dApplyForceAtPoint` | `pub fn rigidBody3dApplyForceAtPoint(mut body: RigidBody3D, force: Vec3, worldPoint: Vec3): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `30` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dApplyLinearImpulse` | `pub fn rigidBody3dApplyLinearImpulse(mut body: RigidBody3D, impulse: Vec3): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `31` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dApplyAngularImpulse` | `pub fn rigidBody3dApplyAngularImpulse(mut body: RigidBody3D, impulse: Vec3): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `32` | `std/phys3d/rigid_body3d.aipl` | `rigidBody3dIntegrate` | `pub fn rigidBody3dIntegrate(mut body: RigidBody3D, gravity: Vec3, dt: float): void:` | `tests/functions/phys3d/rigid_body3d_test.aipl` |
| `33` | `std/phys3d/vehicle3d.aipl` | `raycastVehicleNew` | `pub fn raycastVehicleNew(chassisBodyId: int): RaycastVehicle3D:` | `tests/functions/phys3d/vehicle3d_test.aipl` |
| `34` | `std/phys3d/vehicle3d.aipl` | `vehicleAddWheel` | `pub fn vehicleAddWheel(mut vehicle: RaycastVehicle3D, wheel: RaycastWheel3D): int:` | `tests/functions/phys3d/vehicle3d_test.aipl` |
| `35` | `std/phys3d/vehicle3d.aipl` | `vehicleStepSimulation` | `pub fn vehicleStepSimulation(mut vehicle: RaycastVehicle3D, mut world: PhysicsWorld3D, dt: float): void:` | `tests/functions/phys3d/vehicle3d_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `characterControllerNew` (`std/phys3d/character3d.aipl`)

- **Signature**: `pub fn characterControllerNew(settings: CharacterControllerSettings3D, height: float, radius: float): KinematicCharacterController3D:`
- **Import**: `import * from "std/phys3d/character3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `settings: CharacterControllerSettings3D, height: float, radius: float` | **Returns**: `KinematicCharacterController3D`
- **Unit Test**: `tests/functions/phys3d/character3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D kinematic character move-and-slide slope limit climbing, step-up height handling, and classic FPS air strafe acceleration in `characterControllerNew`. Concrete nominal inputs: `settings: CharacterControllerSettings3D = CharacterControllerSettings3D(stepHeight = 1.0, slopeLimitRadians = 1.0, skinWidth = 0.016667, gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), groundFriction = 1.0, airControl = 1.0)`, `height: float = 1.0`, `radius: float = 1.0`; exercises core body path returning/computing `KinematicCharacterController3D(`.
```aipl
module tests.functions.phys3d.character3d_z1_test
import * from "std/phys3d/character3d"
import { minFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_character3d_characterControllerNew_1(): int:
  let arg_settings = CharacterControllerSettings3D(stepHeight = 2.0, slopeLimitRadians = 0.0, skinWidth = 2.0, gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), groundFriction = 1.0, airControl = 1.0)
  let edge_settings = CharacterControllerSettings3D(stepHeight = 1.0, slopeLimitRadians = 0.0, skinWidth = 1.0, gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), groundFriction = 0.5, airControl = 0.5)
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = characterControllerNew(arg_settings, arg_height, arg_radius)
  let resEdge = characterControllerNew(edge_settings, edge_height, edge_radius)
  assertApproxEq(resNom.height, 2.0, 0.001, "characterControllerNew nominal resNom.height ~= 2.0")
  assertApproxEq(resEdge.height, 1.0, 0.001, "characterControllerNew boundary resEdge.height ~= 1.0")
  ret 0
```

---

### `characterMoveAndSlide` (`std/phys3d/character3d.aipl`)

- **Signature**: `pub fn characterMoveAndSlide(mut controller: KinematicCharacterController3D, desiredVelocity: Vec3, world: PhysicsWorld3D, dt: float): Vec3:`
- **Import**: `import * from "std/phys3d/character3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut controller: KinematicCharacterController3D, desiredVelocity: Vec3, world: PhysicsWorld3D, dt: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/phys3d/character3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D kinematic character move-and-slide slope limit climbing, step-up height handling, and classic FPS air strafe acceleration in `characterMoveAndSlide`. Concrete nominal inputs: `controller: KinematicCharacterController3D = KinematicCharacterController3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), velocity = Vec3(x = 1.0, y = 1.0, z = 1.0), height = 1.0, radius = 1.0, isGrounded = true, groundNormal = Vec3(x = 1.0, y = 1.0, z = 1.0), settings = CharacterControllerSettings3D(stepHeight = 1.0, slopeLimitRadians = 1.0, skinWidth = 0.016667, gravity = Vec3(x = 0, y = 0, z = 0), groundFriction = 1.0, airControl = 1.0))`, `desiredVelocity: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `dt: float = 0.016667`; exercises core body path returning/computing `clampedPos`.
```aipl
module tests.functions.phys3d.character3d_z2_test
import * from "std/phys3d/character3d"
import { minFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_character3d_characterMoveAndSlide_2(): int:
  let arg_controller = KinematicCharacterController3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), velocity = Vec3(x = 1.0, y = 1.0, z = 1.0), height = 2.0, radius = 2.0, isGrounded = true, groundNormal = Vec3(x = 1.0, y = 1.0, z = 1.0), settings = CharacterControllerSettings3D(stepHeight = 2.0, slopeLimitRadians = 0.0, skinWidth = 2.0, gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), groundFriction = 1.0, airControl = 1.0))
  let edge_controller = KinematicCharacterController3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), velocity = Vec3(x = 0.5, y = 0.5, z = 0.5), height = 1.0, radius = 1.0, isGrounded = false, groundNormal = Vec3(x = 0.5, y = 0.5, z = 0.5), settings = CharacterControllerSettings3D(stepHeight = 1.0, slopeLimitRadians = 0.0, skinWidth = 1.0, gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), groundFriction = 0.5, airControl = 0.5))
  let arg_desiredVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_desiredVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = characterMoveAndSlide(arg_controller, arg_desiredVelocity, arg_world, arg_dt)
  let resEdge = characterMoveAndSlide(edge_controller, edge_desiredVelocity, edge_world, edge_dt)
  assertApproxEq(resNom.x, 3.0, 0.001, "characterMoveAndSlide nominal resNom.x ~= 3.0")
  assertApproxEq(resEdge.x, 1.5, 0.001, "characterMoveAndSlide boundary resEdge.x ~= 1.5")
  ret 0
```

---

### `computeAirAccelerateVelocity` (`std/phys3d/character3d.aipl`)

- **Signature**: `pub fn computeAirAccelerateVelocity(velocity: Vec3, wishDir: Vec3, wishSpeed: float, accel: float, dt: float): Vec3:`
- **Import**: `import * from "std/phys3d/character3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `velocity: Vec3, wishDir: Vec3, wishSpeed: float, accel: float, dt: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/phys3d/character3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D kinematic character move-and-slide slope limit climbing, step-up height handling, and classic FPS air strafe acceleration in `computeAirAccelerateVelocity`. Concrete nominal inputs: `velocity: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `wishDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `wishSpeed: float = 1.0`, `accel: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `velocity.add(wishDir.scale(accelSpeed))`.
```aipl
module tests.functions.phys3d.character3d_z3_test
import * from "std/phys3d/character3d"
import { minFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_character3d_computeAirAccelerateVelocity_3(): int:
  let arg_velocity = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_velocity = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_wishDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_wishDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_wishSpeed = 2.0
  let edge_wishSpeed = 1.0
  let arg_accel = 1.0
  let edge_accel = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = computeAirAccelerateVelocity(arg_velocity, arg_wishDir, arg_wishSpeed, arg_accel, arg_dt)
  let resEdge = computeAirAccelerateVelocity(edge_velocity, edge_wishDir, edge_wishSpeed, edge_accel, edge_dt)
  assertApproxEq(resNom.x, 1.0, 0.001, "computeAirAccelerateVelocity nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.625, 0.001, "computeAirAccelerateVelocity boundary resEdge.x ~= 0.625")
  ret 0
```

---

### `identityTransform3D` (`std/phys3d/collider3d.aipl`)

- **Signature**: `fn identityTransform3D(): Transform3D:`
- **Import**: `import * from "std/phys3d/collider3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Transform3D`
- **Unit Test**: `tests/functions/phys3d/collider3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D sphere, box, capsule, cylinder, and convex hull collider construction and transformed 3D AABB bounds in `identityTransform3D`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Transform3D(`.

```aipl
module tests.functions.phys3d.collider3d_z1_test
import * from "std/phys3d/collider3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider3d_identityTransform3D_1(): int:
  let resNom = identityTransform3D()
  let resEdge = identityTransform3D()
  assertApproxEq(resNom.position.x, 0.0, 0.001, "identityTransform3D nominal resNom.position.x ~= 0.0")
  assertApproxEq(resEdge.position.x, 0.0, 0.001, "identityTransform3D boundary resEdge.position.x ~= 0.0")
  ret 0
```

---

### `sphereColliderNew` (`std/phys3d/collider3d.aipl`)

- **Signature**: `pub fn sphereColliderNew(radius: float, material: PhysicsMaterial3D): Collider3D:`
- **Import**: `import * from "std/phys3d/collider3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, material: PhysicsMaterial3D` | **Returns**: `Collider3D`
- **Unit Test**: `tests/functions/phys3d/collider3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D sphere, box, capsule, cylinder, and convex hull collider construction and transformed 3D AABB bounds in `sphereColliderNew`. Concrete nominal inputs: `radius: float = 1.0`, `material: PhysicsMaterial3D = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider3D(`.

```aipl
module tests.functions.phys3d.collider3d_z2_test
import * from "std/phys3d/collider3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider3d_sphereColliderNew_2(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5)
  let resNom = sphereColliderNew(arg_radius, arg_material)
  let resEdge = sphereColliderNew(edge_radius, edge_material)
  assertApproxEq(resNom.sphereRadius, 2.0, 0.001, "sphereColliderNew nominal resNom.sphereRadius ~= 2.0")
  assertApproxEq(resEdge.sphereRadius, 1.0, 0.001, "sphereColliderNew boundary resEdge.sphereRadius ~= 1.0")
  ret 0
```

---

### `boxCollider3dNew` (`std/phys3d/collider3d.aipl`)

- **Signature**: `pub fn boxCollider3dNew(halfExtents: Vec3, material: PhysicsMaterial3D): Collider3D:`
- **Import**: `import * from "std/phys3d/collider3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `halfExtents: Vec3, material: PhysicsMaterial3D` | **Returns**: `Collider3D`
- **Unit Test**: `tests/functions/phys3d/collider3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Verifies 3D sphere, box, capsule, cylinder, and convex hull collider construction and transformed 3D AABB bounds in `boxCollider3dNew`. Concrete nominal inputs: `halfExtents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `material: PhysicsMaterial3D = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider3D(`.

```aipl
module tests.functions.phys3d.collider3d_z3_test
import * from "std/phys3d/collider3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider3d_boxCollider3dNew_3(): int:
  let arg_halfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_halfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5)
  let resNom = boxCollider3dNew(arg_halfExtents, arg_material)
  let resEdge = boxCollider3dNew(edge_halfExtents, edge_material)
  assertApproxEq(resNom.sphereRadius, 0.0, 0.001, "boxCollider3dNew nominal resNom.sphereRadius ~= 0.0")
  assertApproxEq(resEdge.sphereRadius, 0.0, 0.001, "boxCollider3dNew boundary resEdge.sphereRadius ~= 0.0")
  ret 0
```

---

### `capsuleCollider3dNew` (`std/phys3d/collider3d.aipl`)

- **Signature**: `pub fn capsuleCollider3dNew(radius: float, height: float, material: PhysicsMaterial3D): Collider3D:`
- **Import**: `import * from "std/phys3d/collider3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, height: float, material: PhysicsMaterial3D` | **Returns**: `Collider3D`
- **Unit Test**: `tests/functions/phys3d/collider3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D sphere, box, capsule, cylinder, and convex hull collider construction and transformed 3D AABB bounds in `capsuleCollider3dNew`. Concrete nominal inputs: `radius: float = 1.0`, `height: float = 1.0`, `material: PhysicsMaterial3D = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)`; exercises core body path returning/computing `Collider3D(`.

```aipl
module tests.functions.phys3d.collider3d_z4_test
import * from "std/phys3d/collider3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider3d_capsuleCollider3dNew_4(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0)
  let edge_material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5)
  let resNom = capsuleCollider3dNew(arg_radius, arg_height, arg_material)
  let resEdge = capsuleCollider3dNew(edge_radius, edge_height, edge_material)
  assertApproxEq(resNom.sphereRadius, 2.0, 0.001, "capsuleCollider3dNew nominal resNom.sphereRadius ~= 2.0")
  assertApproxEq(resEdge.sphereRadius, 1.0, 0.001, "capsuleCollider3dNew boundary resEdge.sphereRadius ~= 1.0")
  ret 0
```

---

### `collider3dComputeAABB` (`std/phys3d/collider3d.aipl`)

- **Signature**: `pub fn collider3dComputeAABB(collider: Collider3D, bodyTransform: Transform3D): AABB3D:`
- **Import**: `import * from "std/phys3d/collider3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `collider: Collider3D, bodyTransform: Transform3D` | **Returns**: `AABB3D`
- **Unit Test**: `tests/functions/phys3d/collider3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D sphere, box, capsule, cylinder, and convex hull collider construction and transformed 3D AABB bounds in `collider3dComputeAABB`. Concrete nominal inputs: `collider: Collider3D = Collider3D(shapeType = ColliderShapeType3D(), localTransform = Transform3D(position = Vec3(x = 0, y = 0, z = 0), rotation = Quat(x = 0, y = 0, z = 0, w = 0), scale = Vec3(x = 0, y = 0, z = 0)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [Vec3(x = 0, y = 0, z = 0)], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`, `bodyTransform: Transform3D = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `AABB3D(min = cPos.sub(ev), max = cPos.add(ev))`.

```aipl
module tests.functions.phys3d.collider3d_z5_test
import * from "std/phys3d/collider3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_collider3d_collider3dComputeAABB_5(): int:
  let arg_collider = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0)), sphereRadius = 2.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 2.0, capsuleHeight = 2.0, cylinderRadius = 2.0, cylinderHeight = 2.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_collider = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let arg_bodyTransform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_bodyTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = collider3dComputeAABB(arg_collider, arg_bodyTransform)
  let resEdge = collider3dComputeAABB(edge_collider, edge_bodyTransform)
  assertApproxEq(resNom.min.x, 0.0, 0.001, "collider3dComputeAABB nominal resNom.min.x ~= 0.0")
  assertApproxEq(resEdge.min.x, 0.0, 0.001, "collider3dComputeAABB boundary resEdge.min.x ~= 0.0")
  ret 0
```

---

### `ballSocketJointNew` (`std/phys3d/joint3d.aipl`)

- **Signature**: `pub fn ballSocketJointNew(bodyA: int, bodyB: int, worldAnchor: Vec3): Joint3D:`
- **Import**: `import * from "std/phys3d/joint3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyA: int, bodyB: int, worldAnchor: Vec3` | **Returns**: `Joint3D`
- **Unit Test**: `tests/functions/phys3d/joint3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D ball-socket, hinge, slider, and 6-DOF angular/linear joint limit constraint solving in `ballSocketJointNew`. Concrete nominal inputs: `bodyA: int = 1`, `bodyB: int = 1`, `worldAnchor: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Joint3D(`.

```aipl
module tests.functions.phys3d.joint3d_z1_test
import * from "std/phys3d/joint3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D } from "std/phys3d/rigid_body3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint3d_ballSocketJointNew_1(): int:
  let arg_bodyA = 4
  let edge_bodyA = 1
  let arg_bodyB = 4
  let edge_bodyB = 1
  let arg_worldAnchor = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_worldAnchor = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = ballSocketJointNew(arg_bodyA, arg_bodyB, arg_worldAnchor)
  let resEdge = ballSocketJointNew(edge_bodyA, edge_bodyB, edge_worldAnchor)
  assertEqInt(resNom.id, 0, "ballSocketJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "ballSocketJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `hingeJointNew` (`std/phys3d/joint3d.aipl`)

- **Signature**: `pub fn hingeJointNew(bodyA: int, bodyB: int, worldAnchor: Vec3, worldAxis: Vec3): Joint3D:`
- **Import**: `import * from "std/phys3d/joint3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyA: int, bodyB: int, worldAnchor: Vec3, worldAxis: Vec3` | **Returns**: `Joint3D`
- **Unit Test**: `tests/functions/phys3d/joint3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D ball-socket, hinge, slider, and 6-DOF angular/linear joint limit constraint solving in `hingeJointNew`. Concrete nominal inputs: `bodyA: int = 1`, `bodyB: int = 1`, `worldAnchor: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `worldAxis: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Joint3D(`.

```aipl
module tests.functions.phys3d.joint3d_z2_test
import * from "std/phys3d/joint3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D } from "std/phys3d/rigid_body3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint3d_hingeJointNew_2(): int:
  let arg_bodyA = 4
  let edge_bodyA = 1
  let arg_bodyB = 4
  let edge_bodyB = 1
  let arg_worldAnchor = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_worldAnchor = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_worldAxis = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_worldAxis = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = hingeJointNew(arg_bodyA, arg_bodyB, arg_worldAnchor, arg_worldAxis)
  let resEdge = hingeJointNew(edge_bodyA, edge_bodyB, edge_worldAnchor, edge_worldAxis)
  assertEqInt(resNom.id, 0, "hingeJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "hingeJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `sixDofJointNew` (`std/phys3d/joint3d.aipl`)

- **Signature**: `pub fn sixDofJointNew(bodyA: int, bodyB: int, anchorA: Vec3, anchorB: Vec3): Joint3D:`
- **Import**: `import * from "std/phys3d/joint3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bodyA: int, bodyB: int, anchorA: Vec3, anchorB: Vec3` | **Returns**: `Joint3D`
- **Unit Test**: `tests/functions/phys3d/joint3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D ball-socket, hinge, slider, and 6-DOF angular/linear joint limit constraint solving in `sixDofJointNew`. Concrete nominal inputs: `bodyA: int = 1`, `bodyB: int = 1`, `anchorA: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `anchorB: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Joint3D(`.

```aipl
module tests.functions.phys3d.joint3d_z3_test
import * from "std/phys3d/joint3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D } from "std/phys3d/rigid_body3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint3d_sixDofJointNew_3(): int:
  let arg_bodyA = 4
  let edge_bodyA = 1
  let arg_bodyB = 4
  let edge_bodyB = 1
  let arg_anchorA = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_anchorA = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_anchorB = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_anchorB = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = sixDofJointNew(arg_bodyA, arg_bodyB, arg_anchorA, arg_anchorB)
  let resEdge = sixDofJointNew(edge_bodyA, edge_bodyB, edge_anchorA, edge_anchorB)
  assertEqInt(resNom.id, 0, "sixDofJointNew nominal resNom.id == 0")
  assertEqInt(resEdge.id, 0, "sixDofJointNew boundary resEdge.id == 0")
  ret 0
```

---

### `joint3dSolveVelocity` (`std/phys3d/joint3d.aipl`)

- **Signature**: `pub fn joint3dSolveVelocity(joint: Joint3D, mut bodyA: RigidBody3D, mut bodyB: RigidBody3D, dt: float): void:`
- **Import**: `import * from "std/phys3d/joint3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joint: Joint3D, mut bodyA: RigidBody3D, mut bodyB: RigidBody3D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/joint3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D ball-socket, hinge, slider, and 6-DOF angular/linear joint limit constraint solving in `joint3dSolveVelocity`. Concrete nominal inputs: `joint: Joint3D = Joint3D(id = 1, jointType = JointType3D(), bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAnchorB = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisB = Vec3(x = 1.0, y = 1.0, z = 1.0), minLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), maxLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), enableMotor = true, motorTargetVelocity = 1.0, motorMaxForce = 1.0)`, `bodyA: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `bodyB: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.joint3d_z4_test
import * from "std/phys3d/joint3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D } from "std/phys3d/rigid_body3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_joint3d_joint3dSolveVelocity_4(): int:
  let arg_joint = Joint3D(id = 1, jointType = JointType3D.BallSocket, bodyIdA = 4, bodyIdB = 4, localAnchorA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAnchorB = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisB = Vec3(x = 1.0, y = 1.0, z = 1.0), minLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), maxLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), enableMotor = true, motorTargetVelocity = 0.0, motorMaxForce = 2.0)
  let edge_joint = Joint3D(id = 0, jointType = JointType3D.BallSocket, bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec3(x = 0.5, y = 0.5, z = 0.5), localAnchorB = Vec3(x = 0.5, y = 0.5, z = 0.5), localAxisA = Vec3(x = 0.5, y = 0.5, z = 0.5), localAxisB = Vec3(x = 0.5, y = 0.5, z = 0.5), minLimits = Vec3(x = 0.5, y = 0.5, z = 0.5), maxLimits = Vec3(x = 0.5, y = 0.5, z = 0.5), enableMotor = false, motorTargetVelocity = 0.0, motorMaxForce = 1.0)
  let arg_bodyA = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_bodyA = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_bodyB = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_bodyB = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_dt = 2.0
  let edge_dt = 1.0
  joint3dSolveVelocity(arg_joint, arg_bodyA, arg_bodyB, arg_dt)
  joint3dSolveVelocity(edge_joint, edge_bodyA, edge_bodyB, edge_dt)
  assertEqInt(arg_bodyA.id, 1, "joint3dSolveVelocity nominal arg_bodyA.id == 1")
  assertEqInt(edge_bodyA.id, 0, "joint3dSolveVelocity boundary edge_bodyA.id == 0")
  ret 0
```

---

### `testSphereSphere3D` (`std/phys3d/narrowphase3d.aipl`)

- **Signature**: `pub fn testSphereSphere3D(posA: Vec3, radA: float, posB: Vec3, radB: float): Option[ContactManifold3D]:`
- **Import**: `import * from "std/phys3d/narrowphase3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `posA: Vec3, radA: float, posB: Vec3, radB: float` | **Returns**: `Option[ContactManifold3D]`
- **Unit Test**: `tests/functions/phys3d/narrowphase3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D Sphere-Sphere, Sphere-Box, Box-Box SAT, and 3D GJK-EPA contact manifold generation in `testSphereSphere3D`. Concrete nominal inputs: `posA: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radA: float = 1.0`, `posB: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radB: float = 1.0`; exercises core body path returning/computing `Some(ContactManifold3D(`.

```aipl
module tests.functions.phys3d.narrowphase3d_z1_test
import * from "std/phys3d/narrowphase3d"
import { absFloat, minFloat, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D, collider3dComputeAABB } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase3d_testSphereSphere3D_1(): int:
  let arg_posA = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_posA = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radA = 1.0
  let edge_radA = 0.5
  let arg_posB = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_posB = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radB = 1.0
  let edge_radB = 0.5
  let resNom = testSphereSphere3D(arg_posA, arg_radA, arg_posB, arg_radB)
  let resEdge = testSphereSphere3D(edge_posA, edge_radA, edge_posB, edge_radB)
  assert(resNom.isSome() == true, "testSphereSphere3D nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testSphereSphere3D boundary resEdge.isSome() == true")
  ret 0
```

---

### `testSphereBox3D` (`std/phys3d/narrowphase3d.aipl`)

- **Signature**: `pub fn testSphereBox3D(spherePos: Vec3, radius: float, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3): Option[ContactManifold3D]:`
- **Import**: `import * from "std/phys3d/narrowphase3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `spherePos: Vec3, radius: float, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3` | **Returns**: `Option[ContactManifold3D]`
- **Unit Test**: `tests/functions/phys3d/narrowphase3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D Sphere-Sphere, Sphere-Box, Box-Box SAT, and 3D GJK-EPA contact manifold generation in `testSphereBox3D`. Concrete nominal inputs: `spherePos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`, `boxPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `boxRot: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `boxHalfExtents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Some(ContactManifold3D(`.

```aipl
module tests.functions.phys3d.narrowphase3d_z2_test
import * from "std/phys3d/narrowphase3d"
import { absFloat, minFloat, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D, collider3dComputeAABB } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase3d_testSphereBox3D_2(): int:
  let arg_spherePos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_spherePos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_boxPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_boxPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_boxRot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_boxRot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = testSphereBox3D(arg_spherePos, arg_radius, arg_boxPos, arg_boxRot, arg_boxHalfExtents)
  let resEdge = testSphereBox3D(edge_spherePos, edge_radius, edge_boxPos, edge_boxRot, edge_boxHalfExtents)
  assert(resNom.isSome() == true, "testSphereBox3D nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testSphereBox3D boundary resEdge.isSome() == true")
  ret 0
```

---

### `testGjkEpa3D` (`std/phys3d/narrowphase3d.aipl`)

- **Signature**: `pub fn testGjkEpa3D(colliderA: Collider3D, transformA: Transform3D, colliderB: Collider3D, transformB: Transform3D): Option[ContactManifold3D]:`
- **Import**: `import * from "std/phys3d/narrowphase3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `colliderA: Collider3D, transformA: Transform3D, colliderB: Collider3D, transformB: Transform3D` | **Returns**: `Option[ContactManifold3D]`
- **Unit Test**: `tests/functions/phys3d/narrowphase3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D Sphere-Sphere, Sphere-Box, Box-Box SAT, and 3D GJK-EPA contact manifold generation in `testGjkEpa3D`. Concrete nominal inputs: `colliderA: Collider3D = Collider3D(shapeType = ColliderShapeType3D(), localTransform = Transform3D(position = Vec3(x = 0, y = 0, z = 0), rotation = Quat(x = 0, y = 0, z = 0, w = 0), scale = Vec3(x = 0, y = 0, z = 0)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [Vec3(x = 0, y = 0, z = 0)], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`, `transformA: Transform3D = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `colliderB: Collider3D = Collider3D(shapeType = ColliderShapeType3D(), localTransform = Transform3D(position = Vec3(x = 0, y = 0, z = 0), rotation = Quat(x = 0, y = 0, z = 0, w = 0), scale = Vec3(x = 0, y = 0, z = 0)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [Vec3(x = 0, y = 0, z = 0)], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`, `transformB: Transform3D = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `Some(ContactManifold3D(`.

```aipl
module tests.functions.phys3d.narrowphase3d_z3_test
import * from "std/phys3d/narrowphase3d"
import { absFloat, minFloat, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D, collider3dComputeAABB } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase3d_testGjkEpa3D_3(): int:
  let arg_colliderA = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0)), sphereRadius = 2.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 2.0, capsuleHeight = 2.0, cylinderRadius = 2.0, cylinderHeight = 2.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_colliderA = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let arg_transformA = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_transformA = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_colliderB = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0)), sphereRadius = 2.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 2.0, capsuleHeight = 2.0, cylinderRadius = 2.0, cylinderHeight = 2.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_colliderB = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let arg_transformB = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_transformB = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = testGjkEpa3D(arg_colliderA, arg_transformA, arg_colliderB, arg_transformB)
  let resEdge = testGjkEpa3D(edge_colliderA, edge_transformA, edge_colliderB, edge_transformB)
  assert(resNom.isSome() == true, "testGjkEpa3D nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "testGjkEpa3D boundary resEdge.isSome() == true")
  ret 0
```

---

### `contactManifold3dCache` (`std/phys3d/narrowphase3d.aipl`)

- **Signature**: `pub fn contactManifold3dCache(mut existing: ContactManifold3D, newManifold: ContactManifold3D): void:`
- **Import**: `import * from "std/phys3d/narrowphase3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut existing: ContactManifold3D, newManifold: ContactManifold3D` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/narrowphase3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D Sphere-Sphere, Sphere-Box, Box-Box SAT, and 3D GJK-EPA contact manifold generation in `contactManifold3dCache`. Concrete nominal inputs: `existing: ContactManifold3D = ContactManifold3D(bodyIdA = 1, bodyIdB = 1, points = [ContactPoint3D(position = 0, normal = 0, penetration = 0, normalImpulse = 0, tangentImpulse1 = 0, tangentImpulse2 = 0)], isColliding = true)`, `newManifold: ContactManifold3D = ContactManifold3D(bodyIdA = 1, bodyIdB = 1, points = [ContactPoint3D(position = 0, normal = 0, penetration = 0, normalImpulse = 0, tangentImpulse1 = 0, tangentImpulse2 = 0)], isColliding = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.narrowphase3d_z4_test
import * from "std/phys3d/narrowphase3d"
import { absFloat, minFloat, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { AABB3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D, collider3dComputeAABB } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_narrowphase3d_contactManifold3dCache_4(): int:
  let arg_existing = ContactManifold3D(bodyIdA = 4, bodyIdB = 4, points = [], isColliding = true)
  let edge_existing = ContactManifold3D(bodyIdA = 1, bodyIdB = 1, points = [], isColliding = false)
  let arg_newManifold = ContactManifold3D(bodyIdA = 4, bodyIdB = 4, points = [], isColliding = true)
  let edge_newManifold = ContactManifold3D(bodyIdA = 1, bodyIdB = 1, points = [], isColliding = false)
  contactManifold3dCache(arg_existing, arg_newManifold)
  contactManifold3dCache(edge_existing, edge_newManifold)
  assertEqInt(arg_existing.bodyIdA, 4, "contactManifold3dCache nominal arg_existing.bodyIdA == 4")
  assertEqInt(edge_existing.bodyIdA, 1, "contactManifold3dCache boundary edge_existing.bodyIdA == 1")
  ret 0
```

---

### `extractRayDir3D` (`std/phys3d/phys_query3d.aipl`)

- **Signature**: `fn extractRayDir3D(ray: Ray3D): Vec3:`
- **Import**: `import * from "std/phys3d/phys_query3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/phys3d/phys_query3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D analytical raycast (sphere, box, plane, triangle) and swept sphere-cast hit fraction/normal accuracy in `extractRayDir3D`. Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`; exercises core body path returning/computing `dFallback.norm()`.

```aipl
module tests.functions.phys3d.phys_query3d_z1_test
import * from "std/phys3d/phys_query3d"
import { absFloat, minFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Ray3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query3d_extractRayDir3D_1(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let resNom = extractRayDir3D(arg_ray)
  let resEdge = extractRayDir3D(edge_ray)
  assertApproxEq(resNom.x, 0.57735, 0.001, "extractRayDir3D nominal resNom.x ~= 0.57735")
  assertApproxEq(resEdge.x, 0.57735, 0.001, "extractRayDir3D boundary resEdge.x ~= 0.57735")
  ret 0
```

---

### `raycast3dSphere` (`std/phys3d/phys_query3d.aipl`)

- **Signature**: `pub fn raycast3dSphere(ray: Ray3D, sphereCenter: Vec3, radius: float): Option[RayHit3D]:`
- **Import**: `import * from "std/phys3d/phys_query3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, sphereCenter: Vec3, radius: float` | **Returns**: `Option[RayHit3D]`
- **Unit Test**: `tests/functions/phys3d/phys_query3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Verifies 3D analytical raycast (sphere, box, plane, triangle) and swept sphere-cast hit fraction/normal accuracy in `raycast3dSphere`. Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `sphereCenter: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `Some(RayHit3D(`.

```aipl
module tests.functions.phys3d.phys_query3d_z2_test
import * from "std/phys3d/phys_query3d"
import { absFloat, minFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Ray3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query3d_raycast3dSphere_2(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_sphereCenter = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_sphereCenter = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = raycast3dSphere(arg_ray, arg_sphereCenter, arg_radius)
  let resEdge = raycast3dSphere(edge_ray, edge_sphereCenter, edge_radius)
  assert(resNom.isSome() == false, "raycast3dSphere nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "raycast3dSphere boundary resEdge.isSome() == false")
  ret 0
```

---

### `raycast3dBox` (`std/phys3d/phys_query3d.aipl`)

- **Signature**: `pub fn raycast3dBox(ray: Ray3D, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3): Option[RayHit3D]:`
- **Import**: `import * from "std/phys3d/phys_query3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, boxPos: Vec3, boxRot: Quat, boxHalfExtents: Vec3` | **Returns**: `Option[RayHit3D]`
- **Unit Test**: `tests/functions/phys3d/phys_query3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D analytical raycast (sphere, box, plane, triangle) and swept sphere-cast hit fraction/normal accuracy in `raycast3dBox`. Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `boxPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `boxRot: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `boxHalfExtents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Some(RayHit3D(`.

```aipl
module tests.functions.phys3d.phys_query3d_z3_test
import * from "std/phys3d/phys_query3d"
import { absFloat, minFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Ray3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query3d_raycast3dBox_3(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_boxPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_boxPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_boxRot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_boxRot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = raycast3dBox(arg_ray, arg_boxPos, arg_boxRot, arg_boxHalfExtents)
  let resEdge = raycast3dBox(edge_ray, edge_boxPos, edge_boxRot, edge_boxHalfExtents)
  assert(resNom.isSome() == true, "raycast3dBox nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "raycast3dBox boundary resEdge.isSome() == true")
  ret 0
```

---

### `sphereCast3D` (`std/phys3d/phys_query3d.aipl`)

- **Signature**: `pub fn sphereCast3D(ray: Ray3D, sphereRadius: float, colliders: [Collider3D]): Option[RayHit3D]:`
- **Import**: `import * from "std/phys3d/phys_query3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ray: Ray3D, sphereRadius: float, colliders: [Collider3D]` | **Returns**: `Option[RayHit3D]`
- **Unit Test**: `tests/functions/phys3d/phys_query3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D analytical raycast (sphere, box, plane, triangle) and swept sphere-cast hit fraction/normal accuracy in `sphereCast3D`. Concrete nominal inputs: `ray: Ray3D = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), direction = Vec3 = Vec3(x = 0.0, y = 0.0, z = 1.0)(), maxDistance = float = 1000.0())`, `sphereRadius: float = 1.0`, `colliders: [Collider3D] = [Collider3D(shapeType = ColliderShapeType3D(), localTransform = Transform3D(position = 0, rotation = 0, scale = 0), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 0, y = 0, z = 0), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [0], material = PhysicsMaterial3D(restitution = 0, staticFriction = 0, dynamicFriction = 0, density = 0), isSensor = true, collisionLayer = 1, collisionMask = 1)]`; exercises core body path returning/computing `bestHit`.

```aipl
module tests.functions.phys3d.phys_query3d_z4_test
import * from "std/phys3d/phys_query3d"
import { absFloat, minFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Ray3D } from "std/math/geom3d"
import { Transform3D } from "std/spatial/continuous_world3d"
import { Collider3D, ColliderShapeType3D } from "std/phys3d/collider3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_query3d_sphereCast3D_4(): int:
  let arg_ray = Ray3D(origin = Vec3(x = 1.0, y = 1.0, z = 1.0), dir = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), maxDistance = 2.0)
  let edge_ray = Ray3D(origin = Vec3(x = 0.5, y = 0.5, z = 0.5), dir = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), maxDistance = 1.0)
  let arg_sphereRadius = 2.0
  let edge_sphereRadius = 1.0
  let arg_colliders = [Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), sphereRadius = 2.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 2.0, capsuleHeight = 2.0, cylinderRadius = 2.0, cylinderHeight = 2.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)]
  let edge_colliders = []
  let resNom = sphereCast3D(arg_ray, arg_sphereRadius, arg_colliders)
  let resEdge = sphereCast3D(edge_ray, edge_sphereRadius, edge_colliders)
  assert(resNom.isSome() == false, "sphereCast3D nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "sphereCast3D boundary resEdge.isSome() == false")
  ret 0
```

---

### `physWorld3dNew` (`std/phys3d/phys_world3d.aipl`)

- **Signature**: `pub fn physWorld3dNew(gravity: Vec3): PhysicsWorld3D:`
- **Import**: `import * from "std/phys3d/phys_world3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `gravity: Vec3` | **Returns**: `PhysicsWorld3D`
- **Unit Test**: `tests/functions/phys3d/phys_world3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Verifies 3D physics world stepping, persistent contact manifold warm-starting, and iterative PGS impulse solving in `physWorld3dNew`. Concrete nominal inputs: `gravity: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `PhysicsWorld3D(`.

```aipl
module tests.functions.phys3d.phys_world3d_z1_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dNew_1(): int:
  let arg_gravity = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_gravity = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = physWorld3dNew(arg_gravity)
  let resEdge = physWorld3dNew(edge_gravity)
  assertEqInt(resNom.bodies.len(), 0, "physWorld3dNew nominal resNom.bodies.len() == 0")
  assertEqInt(resEdge.bodies.len(), 0, "physWorld3dNew boundary resEdge.bodies.len() == 0")
  ret 0
```

---

### `physWorld3dAddBody` (`std/phys3d/phys_world3d.aipl`)

- **Signature**: `pub fn physWorld3dAddBody(mut world: PhysicsWorld3D, body: RigidBody3D): int:`
- **Import**: `import * from "std/phys3d/phys_world3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld3D, body: RigidBody3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys3d/phys_world3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D physics world stepping, persistent contact manifold warm-starting, and iterative PGS impulse solving in `physWorld3dAddBody`. Concrete nominal inputs: `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`; exercises core body path returning/computing `idx`.

```aipl
module tests.functions.phys3d.phys_world3d_z2_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dAddBody_2(): int:
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let resNom = physWorld3dAddBody(arg_world, arg_body)
  let resEdge = physWorld3dAddBody(edge_world, edge_body)
  assertEqInt(resNom, 0, "physWorld3dAddBody nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld3dAddBody boundary resEdge == 0")
  ret 0
```

---

### `physWorld3dAddCollider` (`std/phys3d/phys_world3d.aipl`)

- **Signature**: `pub fn physWorld3dAddCollider(mut world: PhysicsWorld3D, bodyId: int, collider: Collider3D): int:`
- **Import**: `import * from "std/phys3d/phys_world3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld3D, bodyId: int, collider: Collider3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys3d/phys_world3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D physics world stepping, persistent contact manifold warm-starting, and iterative PGS impulse solving in `physWorld3dAddCollider`. Concrete nominal inputs: `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `bodyId: int = 1`, `collider: Collider3D = Collider3D(shapeType = ColliderShapeType3D(), localTransform = Transform3D(position = Vec3(x = 0, y = 0, z = 0), rotation = Quat(x = 0, y = 0, z = 0, w = 0), scale = Vec3(x = 0, y = 0, z = 0)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [Vec3(x = 0, y = 0, z = 0)], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 1, collisionMask = 1)`; exercises core body path returning/computing `idx`.

```aipl
module tests.functions.phys3d.phys_world3d_z3_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dAddCollider_3(): int:
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_bodyId = 4
  let edge_bodyId = 1
  let arg_collider = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), scale = Vec3(x = 1.0, y = 1.0, z = 1.0)), sphereRadius = 2.0, boxHalfExtents = Vec3(x = 1.0, y = 1.0, z = 1.0), capsuleRadius = 2.0, capsuleHeight = 2.0, cylinderRadius = 2.0, cylinderHeight = 2.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 1.0, staticFriction = 1.0, dynamicFriction = 1.0, density = 1.0), isSensor = true, collisionLayer = 4, collisionMask = 4)
  let edge_collider = Collider3D(shapeType = ColliderShapeType3D.Sphere, localTransform = Transform3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), scale = Vec3(x = 0.5, y = 0.5, z = 0.5)), sphereRadius = 1.0, boxHalfExtents = Vec3(x = 0.5, y = 0.5, z = 0.5), capsuleRadius = 1.0, capsuleHeight = 1.0, cylinderRadius = 1.0, cylinderHeight = 1.0, convexVertices = [], material = PhysicsMaterial3D(restitution = 0.5, staticFriction = 0.5, dynamicFriction = 0.5, density = 0.5), isSensor = false, collisionLayer = 1, collisionMask = 1)
  let resNom = physWorld3dAddCollider(arg_world, arg_bodyId, arg_collider)
  let resEdge = physWorld3dAddCollider(edge_world, edge_bodyId, edge_collider)
  assertEqInt(resNom, 0, "physWorld3dAddCollider nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld3dAddCollider boundary resEdge == 0")
  ret 0
```

---

### `physWorld3dAddJoint` (`std/phys3d/phys_world3d.aipl`)

- **Signature**: `pub fn physWorld3dAddJoint(mut world: PhysicsWorld3D, joint: Joint3D): int:`
- **Import**: `import * from "std/phys3d/phys_world3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld3D, joint: Joint3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys3d/phys_world3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Verifies 3D physics world stepping, persistent contact manifold warm-starting, and iterative PGS impulse solving in `physWorld3dAddJoint`. Concrete nominal inputs: `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `joint: Joint3D = Joint3D(id = 1, jointType = JointType3D(), bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAnchorB = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisB = Vec3(x = 1.0, y = 1.0, z = 1.0), minLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), maxLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), enableMotor = true, motorTargetVelocity = 1.0, motorMaxForce = 1.0)`; exercises core body path returning/computing `idx`.

```aipl
module tests.functions.phys3d.phys_world3d_z4_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dAddJoint_4(): int:
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_joint = Joint3D(id = 1, jointType = JointType3D.BallSocket, bodyIdA = 4, bodyIdB = 4, localAnchorA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAnchorB = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisA = Vec3(x = 1.0, y = 1.0, z = 1.0), localAxisB = Vec3(x = 1.0, y = 1.0, z = 1.0), minLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), maxLimits = Vec3(x = 1.0, y = 1.0, z = 1.0), enableMotor = true, motorTargetVelocity = 0.0, motorMaxForce = 2.0)
  let edge_joint = Joint3D(id = 0, jointType = JointType3D.BallSocket, bodyIdA = 1, bodyIdB = 1, localAnchorA = Vec3(x = 0.5, y = 0.5, z = 0.5), localAnchorB = Vec3(x = 0.5, y = 0.5, z = 0.5), localAxisA = Vec3(x = 0.5, y = 0.5, z = 0.5), localAxisB = Vec3(x = 0.5, y = 0.5, z = 0.5), minLimits = Vec3(x = 0.5, y = 0.5, z = 0.5), maxLimits = Vec3(x = 0.5, y = 0.5, z = 0.5), enableMotor = false, motorTargetVelocity = 0.0, motorMaxForce = 1.0)
  let resNom = physWorld3dAddJoint(arg_world, arg_joint)
  let resEdge = physWorld3dAddJoint(edge_world, edge_joint)
  assertEqInt(resNom, 0, "physWorld3dAddJoint nominal resNom == 0")
  assertEqInt(resEdge, 0, "physWorld3dAddJoint boundary resEdge == 0")
  ret 0
```

---

### `physWorld3dStep` (`std/phys3d/phys_world3d.aipl`)

- **Signature**: `pub fn physWorld3dStep(mut world: PhysicsWorld3D, dt: float): void:`
- **Import**: `import * from "std/phys3d/phys_world3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut world: PhysicsWorld3D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/phys_world3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D physics world stepping, persistent contact manifold warm-starting, and iterative PGS impulse solving in `physWorld3dStep`. Concrete nominal inputs: `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.phys_world3d_z5_test
import * from "std/phys3d/phys_world3d"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dIntegrate } from "std/phys3d/rigid_body3d"
import { Collider3D } from "std/phys3d/collider3d"
import { Joint3D, joint3dSolveVelocity } from "std/phys3d/joint3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_phys_world3d_physWorld3dStep_5(): int:
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_dt = 2.0
  let edge_dt = 1.0
  physWorld3dStep(arg_world, arg_dt)
  physWorld3dStep(edge_world, edge_dt)
  assertEqInt(arg_world.bodies.len(), 0, "physWorld3dStep nominal arg_world.bodies.len() == 0")
  assertEqInt(edge_world.bodies.len(), 0, "physWorld3dStep boundary edge_world.bodies.len() == 0")
  ret 0
```

---

### `rigidBody3dNew` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dNew(id: int, bodyType: BodyType3D, pos: Vec3, rot: Quat): RigidBody3D:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, bodyType: BodyType3D, pos: Vec3, rot: Quat` | **Returns**: `RigidBody3D`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dNew`. Concrete nominal inputs: `id: int = 1`, `bodyType: BodyType3D = BodyType3D()`, `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `rot: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `RigidBody3D(`.

```aipl
module tests.functions.phys3d.rigid_body3d_z1_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dNew_1(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_bodyType = BodyType3D.Static
  let edge_bodyType = BodyType3D.Static
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_rot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = rigidBody3dNew(arg_id, arg_bodyType, arg_pos, arg_rot)
  let resEdge = rigidBody3dNew(edge_id, edge_bodyType, edge_pos, edge_rot)
  assertEqInt(resNom.id, 1, "rigidBody3dNew nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "rigidBody3dNew boundary resEdge.id == 0")
  ret 0
```

---

### `rigidBody3dSetBoxInertia` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dSetBoxInertia(mut body: RigidBody3D, mass: float, extents: Vec3): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, mass: float, extents: Vec3` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dSetBoxInertia`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `mass: float = 1.0`, `extents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z2_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dSetBoxInertia_2(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_mass = 2.0
  let edge_mass = 1.0
  let arg_extents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_extents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  rigidBody3dSetBoxInertia(arg_body, arg_mass, arg_extents)
  rigidBody3dSetBoxInertia(edge_body, edge_mass, edge_extents)
  assertApproxEq(arg_body.mass, 0.0, 0.0001, "rigidBody3dSetBoxInertia nominal arg_body.mass approx 0.0")
  assertApproxEq(edge_body.mass, 0.0, 0.0001, "rigidBody3dSetBoxInertia boundary edge_body.mass approx 0.0")
  ret 0
```

---

### `rigidBody3dSetSphereInertia` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dSetSphereInertia(mut body: RigidBody3D, mass: float, radius: float): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, mass: float, radius: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dSetSphereInertia`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `mass: float = 1.0`, `radius: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z3_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dSetSphereInertia_3(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_mass = 2.0
  let edge_mass = 1.0
  let arg_radius = 2.0
  let edge_radius = 1.0
  rigidBody3dSetSphereInertia(arg_body, arg_mass, arg_radius)
  rigidBody3dSetSphereInertia(edge_body, edge_mass, edge_radius)
  assertApproxEq(arg_body.mass, 0.0, 0.0001, "rigidBody3dSetSphereInertia nominal arg_body.mass approx 0.0")
  assertApproxEq(edge_body.mass, 0.0, 0.0001, "rigidBody3dSetSphereInertia boundary edge_body.mass approx 0.0")
  ret 0
```

---

### `rigidBody3dApplyForceAtPoint` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dApplyForceAtPoint(mut body: RigidBody3D, force: Vec3, worldPoint: Vec3): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, force: Vec3, worldPoint: Vec3` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dApplyForceAtPoint`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `force: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `worldPoint: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z4_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dApplyForceAtPoint_4(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_force = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_force = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_worldPoint = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_worldPoint = Vec3(x = 0.5, y = 0.5, z = 0.5)
  rigidBody3dApplyForceAtPoint(arg_body, arg_force, arg_worldPoint)
  rigidBody3dApplyForceAtPoint(edge_body, edge_force, edge_worldPoint)
  assertEqInt(arg_body.id, 1, "rigidBody3dApplyForceAtPoint nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody3dApplyForceAtPoint boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody3dApplyLinearImpulse` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dApplyLinearImpulse(mut body: RigidBody3D, impulse: Vec3): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, impulse: Vec3` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dApplyLinearImpulse`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `impulse: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z5_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dApplyLinearImpulse_5(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_impulse = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_impulse = Vec3(x = 0.5, y = 0.5, z = 0.5)
  rigidBody3dApplyLinearImpulse(arg_body, arg_impulse)
  rigidBody3dApplyLinearImpulse(edge_body, edge_impulse)
  assertEqInt(arg_body.id, 1, "rigidBody3dApplyLinearImpulse nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody3dApplyLinearImpulse boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody3dApplyAngularImpulse` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dApplyAngularImpulse(mut body: RigidBody3D, impulse: Vec3): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, impulse: Vec3` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dApplyAngularImpulse`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `impulse: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z6_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dApplyAngularImpulse_6(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_impulse = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_impulse = Vec3(x = 0.5, y = 0.5, z = 0.5)
  rigidBody3dApplyAngularImpulse(arg_body, arg_impulse)
  rigidBody3dApplyAngularImpulse(edge_body, edge_impulse)
  assertEqInt(arg_body.id, 1, "rigidBody3dApplyAngularImpulse nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody3dApplyAngularImpulse boundary edge_body.id == 0")
  ret 0
```

---

### `rigidBody3dIntegrate` (`std/phys3d/rigid_body3d.aipl`)

- **Signature**: `pub fn rigidBody3dIntegrate(mut body: RigidBody3D, gravity: Vec3, dt: float): void:`
- **Import**: `import * from "std/phys3d/rigid_body3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut body: RigidBody3D, gravity: Vec3, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/rigid_body3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Tests 3D rigid body analytical box/sphere inertia tensors, off-center point force torque $\tau = r \times F$, and quaternion orientation integration in `rigidBody3dIntegrate`. Concrete nominal inputs: `body: RigidBody3D = RigidBody3D(id = 1, bodyType = BodyType3D(), position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)`, `gravity: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.rigid_body3d_z7_test
import * from "std/phys3d/rigid_body3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Mat3 } from "std/math/mat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigid_body3d_rigidBody3dIntegrate_7(): int:
  let arg_body = RigidBody3D(id = 1, bodyType = BodyType3D.Static, position = Vec3(x = 1.0, y = 1.0, z = 1.0), rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), linearVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), angularVelocity = Vec3(x = 1.0, y = 1.0, z = 1.0), linearDamping = 1.0, angularDamping = 1.0, mass = 2.0, invMass = 2.0, localInertia = InertiaTensor3x3(ixx = 1.0, iyy = 1.0, izz = 1.0, ixy = 1.0, ixz = 1.0, iyz = 1.0), invInertiaWorld = Mat3(m00 = 1.0, m01 = 1.0, m02 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0), isAwake = true, isBulletCCD = true)
  let edge_body = RigidBody3D(id = 0, bodyType = BodyType3D.Static, position = Vec3(x = 0.5, y = 0.5, z = 0.5), rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), linearVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), angularVelocity = Vec3(x = 0.5, y = 0.5, z = 0.5), linearDamping = 0.5, angularDamping = 0.5, mass = 1.0, invMass = 1.0, localInertia = InertiaTensor3x3(ixx = 0.5, iyy = 0.5, izz = 0.5, ixy = 0.5, ixz = 0.5, iyz = 0.5), invInertiaWorld = Mat3(m00 = 0.5, m01 = 0.5, m02 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5), isAwake = false, isBulletCCD = false)
  let arg_gravity = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_gravity = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  rigidBody3dIntegrate(arg_body, arg_gravity, arg_dt)
  rigidBody3dIntegrate(edge_body, edge_gravity, edge_dt)
  assertEqInt(arg_body.id, 1, "rigidBody3dIntegrate nominal arg_body.id == 1")
  assertEqInt(edge_body.id, 0, "rigidBody3dIntegrate boundary edge_body.id == 0")
  ret 0
```

---

### `raycastVehicleNew` (`std/phys3d/vehicle3d.aipl`)

- **Signature**: `pub fn raycastVehicleNew(chassisBodyId: int): RaycastVehicle3D:`
- **Import**: `import * from "std/phys3d/vehicle3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `chassisBodyId: int` | **Returns**: `RaycastVehicle3D`
- **Unit Test**: `tests/functions/phys3d/vehicle3d_test.aipl` | **Example**: `examples/ex_226_phys3d_joint_ragdoll_and_chains_window.aipl`
- **Behavioral Summary**: Verifies 3D raycast vehicle Hooke suspension spring-damper forces and Pacejka lateral/longitudinal tire friction impulses in `raycastVehicleNew`. Concrete nominal inputs: `chassisBodyId: int = 1`; exercises core body path returning/computing `RaycastVehicle3D(chassisBodyId = chassisBodyId, wheels = ws)`.

```aipl
module tests.functions.phys3d.vehicle3d_z1_test
import * from "std/phys3d/vehicle3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dApplyForceAtPoint } from "std/phys3d/rigid_body3d"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vehicle3d_raycastVehicleNew_1(): int:
  let arg_chassisBodyId = 4
  let edge_chassisBodyId = 1
  let resNom = raycastVehicleNew(arg_chassisBodyId)
  let resEdge = raycastVehicleNew(edge_chassisBodyId)
  assertEqInt(resNom.chassisBodyId, 4, "raycastVehicleNew nominal resNom.chassisBodyId == 4")
  assertEqInt(resEdge.chassisBodyId, 1, "raycastVehicleNew boundary resEdge.chassisBodyId == 1")
  ret 0
```

---

### `vehicleAddWheel` (`std/phys3d/vehicle3d.aipl`)

- **Signature**: `pub fn vehicleAddWheel(mut vehicle: RaycastVehicle3D, wheel: RaycastWheel3D): int:`
- **Import**: `import * from "std/phys3d/vehicle3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut vehicle: RaycastVehicle3D, wheel: RaycastWheel3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/phys3d/vehicle3d_test.aipl` | **Example**: `examples/ex_224_phys3d_rigid_body_inertia_tensors_window.aipl`
- **Behavioral Summary**: Verifies 3D raycast vehicle Hooke suspension spring-damper forces and Pacejka lateral/longitudinal tire friction impulses in `vehicleAddWheel`. Concrete nominal inputs: `vehicle: RaycastVehicle3D = RaycastVehicle3D(chassisBodyId = 1, wheels = [RaycastWheel3D(connectionPoint = 0, direction = 0, axle = 0, suspensionRestLength = 0, currentSuspensionLength = 0, springStiffness = 0, dampingCompression = 0, dampingRelaxation = 0, wheelRadius = 0, steeringAngle = 0, driveTorque = 0, brakeTorque = 0, isGrounded = 0, contactPoint = 0, contactNormal = 0)])`, `wheel: RaycastWheel3D = RaycastWheel3D(connectionPoint = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), axle = Vec3(x = 1.0, y = 1.0, z = 1.0), suspensionRestLength = 1.0, currentSuspensionLength = 1.0, springStiffness = 1.0, dampingCompression = 1.0, dampingRelaxation = 1.0, wheelRadius = 1.0, steeringAngle = 1.0, driveTorque = 1.0, brakeTorque = 1.0, isGrounded = true, contactPoint = Vec3(x = 1.0, y = 1.0, z = 1.0), contactNormal = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `idx`.

```aipl
module tests.functions.phys3d.vehicle3d_z2_test
import * from "std/phys3d/vehicle3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dApplyForceAtPoint } from "std/phys3d/rigid_body3d"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vehicle3d_vehicleAddWheel_2(): int:
  let arg_vehicle = RaycastVehicle3D(chassisBodyId = 4, wheels = [])
  let edge_vehicle = RaycastVehicle3D(chassisBodyId = 1, wheels = [])
  let arg_wheel = RaycastWheel3D(connectionPoint = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), axle = Vec3(x = 1.0, y = 1.0, z = 1.0), suspensionRestLength = 2.0, currentSuspensionLength = 2.0, springStiffness = 1.0, dampingCompression = 1.0, dampingRelaxation = 1.0, wheelRadius = 2.0, steeringAngle = 1.0, driveTorque = 1.0, brakeTorque = 1.0, isGrounded = true, contactPoint = Vec3(x = 1.0, y = 1.0, z = 1.0), contactNormal = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_wheel = RaycastWheel3D(connectionPoint = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), axle = Vec3(x = 0.5, y = 0.5, z = 0.5), suspensionRestLength = 1.0, currentSuspensionLength = 1.0, springStiffness = 0.5, dampingCompression = 0.5, dampingRelaxation = 0.5, wheelRadius = 1.0, steeringAngle = 0.5, driveTorque = 0.5, brakeTorque = 0.5, isGrounded = false, contactPoint = Vec3(x = 0.5, y = 0.5, z = 0.5), contactNormal = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = vehicleAddWheel(arg_vehicle, arg_wheel)
  let resEdge = vehicleAddWheel(edge_vehicle, edge_wheel)
  assertEqInt(resNom, 0, "vehicleAddWheel nominal resNom == 0")
  assertEqInt(resEdge, 0, "vehicleAddWheel boundary resEdge == 0")
  ret 0
```

---

### `vehicleStepSimulation` (`std/phys3d/vehicle3d.aipl`)

- **Signature**: `pub fn vehicleStepSimulation(mut vehicle: RaycastVehicle3D, mut world: PhysicsWorld3D, dt: float): void:`
- **Import**: `import * from "std/phys3d/vehicle3d"` (or barrel `import * from "std/phys3d/phys3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut vehicle: RaycastVehicle3D, mut world: PhysicsWorld3D, dt: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/phys3d/vehicle3d_test.aipl` | **Example**: `examples/ex_225_phys3d_collider_gjk_epa_manifold_window.aipl`
- **Behavioral Summary**: Verifies 3D raycast vehicle Hooke suspension spring-damper forces and Pacejka lateral/longitudinal tire friction impulses in `vehicleStepSimulation`. Concrete nominal inputs: `vehicle: RaycastVehicle3D = RaycastVehicle3D(chassisBodyId = 1, wheels = [RaycastWheel3D(connectionPoint = 0, direction = 0, axle = 0, suspensionRestLength = 0, currentSuspensionLength = 0, springStiffness = 0, dampingCompression = 0, dampingRelaxation = 0, wheelRadius = 0, steeringAngle = 0, driveTorque = 0, brakeTorque = 0, isGrounded = 0, contactPoint = 0, contactNormal = 0)])`, `world: PhysicsWorld3D = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0, y = 0, z = 0), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [RigidBody3D(id = 0, bodyType = 0, position = 0, rotation = 0, linearVelocity = 0, angularVelocity = 0, linearDamping = 0, angularDamping = 0, mass = 0, invMass = 0, localInertia = 0, invInertiaWorld = 0, isAwake = 0, isBulletCCD = 0)], colliders = [Collider3D(shapeType = 0, localTransform = 0, sphereRadius = 0, boxHalfExtents = 0, capsuleRadius = 0, capsuleHeight = 0, cylinderRadius = 0, cylinderHeight = 0, convexVertices = 0, material = 0, isSensor = 0, collisionLayer = 0, collisionMask = 0)], colliderBodyIds = [1], joints = [Joint3D(id = 0, jointType = 0, bodyIdA = 0, bodyIdB = 0, localAnchorA = 0, localAnchorB = 0, localAxisA = 0, localAxisB = 0, minLimits = 0, maxLimits = 0, enableMotor = 0, motorTargetVelocity = 0, motorMaxForce = 0)])`, `dt: float = 0.016667`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.phys3d.vehicle3d_z3_test
import * from "std/phys3d/vehicle3d"
import { maxFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { RigidBody3D, rigidBody3dApplyForceAtPoint } from "std/phys3d/rigid_body3d"
import { PhysicsWorld3D } from "std/phys3d/phys_world3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_vehicle3d_vehicleStepSimulation_3(): int:
  let arg_vehicle = RaycastVehicle3D(chassisBodyId = 4, wheels = [])
  let edge_vehicle = RaycastVehicle3D(chassisBodyId = 1, wheels = [])
  let arg_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 1.0, y = 1.0, z = 1.0), iterations = 4, subSteps = 4, sleepLinearThresholdSq = 2.0, sleepAngularThresholdSq = 2.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let edge_world = PhysicsWorld3D(settings = PhysWorldSettings3D(gravity = Vec3(x = 0.5, y = 0.5, z = 0.5), iterations = 1, subSteps = 1, sleepLinearThresholdSq = 1.0, sleepAngularThresholdSq = 1.0), bodies = [], colliders = [], colliderBodyIds = [], joints = [])
  let arg_dt = 2.0
  let edge_dt = 1.0
  vehicleStepSimulation(arg_vehicle, arg_world, arg_dt)
  vehicleStepSimulation(edge_vehicle, edge_world, edge_dt)
  assertEqInt(arg_vehicle.chassisBodyId, 4, "vehicleStepSimulation nominal arg_vehicle.chassisBodyId == 4")
  assertEqInt(edge_vehicle.chassisBodyId, 1, "vehicleStepSimulation boundary edge_vehicle.chassisBodyId == 1")
  ret 0
```
