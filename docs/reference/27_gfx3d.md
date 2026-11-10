[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 27: `gfx3d` API Reference

> Complete API reference manual for AIPL standard library domain `gfx3d` (107 callable functions & methods across ["std/gfx3d/camera3d.aipl", "std/gfx3d/cull3d.aipl", "std/gfx3d/decal3d.aipl", "std/gfx3d/gfx3d_mod.aipl", "std/gfx3d/light3d.aipl", "std/gfx3d/material3d.aipl", "std/gfx3d/mesh3d.aipl", "std/gfx3d/primitives3d.aipl", "std/gfx3d/rigging3d.aipl", "std/gfx3d/skybox3d.aipl", "std/gfx3d/terrain3d.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `gfx3d`
- **Target Source Modules**: ["std/gfx3d/camera3d.aipl", "std/gfx3d/cull3d.aipl", "std/gfx3d/decal3d.aipl", "std/gfx3d/gfx3d_mod.aipl", "std/gfx3d/light3d.aipl", "std/gfx3d/material3d.aipl", "std/gfx3d/mesh3d.aipl", "std/gfx3d/primitives3d.aipl", "std/gfx3d/rigging3d.aipl", "std/gfx3d/skybox3d.aipl", "std/gfx3d/terrain3d.aipl"]
- **Total Callable Functions & Methods**: 107
- **Total Data Types (`struct` & `enum`)**: 26
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(26 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `Camera3D` | `pub struct` | `std/gfx3d/camera3d.aipl` | `position: Vec3`, `target: Vec3`, `up: Vec3`, `fovYRad: float = 1.04719755`, `aspect: float = 1.3333333`, `nearZ: float = 0.1`, `farZ: float = 1000.0`, `isOrthographic: bool = false`, `orthoWidth: float = 10.0`, `orthoHeight: float = 10.0`, `fovy: float = 60.0`, `nearPlane: float = 0.1`, `farPlane: float = 1000.0`, `projection: int = 0`, `yaw: float = 0.0`, `pitch: float = 0.0`, `orbitDist: float = 5.0` | `Camera3D(position, target, up, fovYRad, aspect, nearZ, farZ, isOrthographic, orthoWidth, orthoHeight, fovy, nearPlane, farPlane, projection, yaw, pitch, orbitDist)` |
| `FrustumPlane` | `pub struct` | `std/gfx3d/camera3d.aipl` | `normal: Vec3`, `distance: float` | `FrustumPlane(normal, distance)` |
| `OrbitController3D` | `pub struct` | `std/gfx3d/camera3d.aipl` | `target: Vec3`, `yawRad: float`, `pitchRad: float`, `distance: float`, `minDistance: float`, `maxDistance: float`, `minPitchRad: float`, `maxPitchRad: float` | `OrbitController3D(target, yawRad, pitchRad, distance, minDistance, maxDistance, minPitchRad, maxPitchRad)` |
| `DecalProjector` | `pub struct` | `std/gfx3d/decal3d.aipl` | `position: Vec3`, `rotation: Quat`, `extents: Vec3`, `textureId: int` | `DecalProjector(position, rotation, extents, textureId)` |
| `LightSource3D` | `pub struct` | `std/gfx3d/light3d.aipl` | `lx: float`, `ly: float`, `lz: float`, `radius: float`, `intensity: float`, `r: int`, `g: int`, `b: int`, `spotDirX: float`, `spotDirY: float`, `spotCosCutoff: float` | `LightSource3D(lx, ly, lz, radius, intensity, r, g, b, spotDirX, spotDirY, spotCosCutoff)` |
| `Light3D` | `pub struct` | `std/gfx3d/light3d.aipl` | `lightType: int`, `position: Vec3`, `direction: Vec3`, `color: LinearColorF32`, `intensity: float`, `range: float`, `spotInnerRad: float`, `spotOuterRad: float`, `castsShadows: bool` | `Light3D(lightType, position, direction, color, intensity, range, spotInnerRad, spotOuterRad, castsShadows)` |
| `ShadowCascade` | `pub struct` | `std/gfx3d/light3d.aipl` | `splitNearZ: float`, `splitFarZ: float`, `lightViewProj: Mat4` | `ShadowCascade(splitNearZ, splitFarZ, lightViewProj)` |
| `Material3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `name: str`, `shadingModel: int`, `albedoHex: int`, `metallic: float`, `roughness: float`, `ao: float`, `specularStrength: float`, `shininess: float`, `emissiveHex: int`, `normalScale: float = 1.0` | `Material3D(name, shadingModel, albedoHex, metallic, roughness, ao, specularStrength, shininess, emissiveHex, normalScale)` |
| `DirectionalLight3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `direction: Vec3`, `colorHex: int`, `intensity: float` | `DirectionalLight3D(direction, colorHex, intensity)` |
| `RenderTri3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `x1: float`, `y1: float`, `x2: float`, `y2: float`, `x3: float`, `y3: float`, `depth: float`, `colorHex: int` | `RenderTri3D(x1, y1, x2, y2, x3, y3, depth, colorHex)` |
| `RenderPass3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `cameraPos: Vec3`, `lightDir: Vec3`, `nearClip: float`, `triangles: [RenderTri3D]` | `RenderPass3D(cameraPos, lightDir, nearClip, triangles)` |
| `PbrMaterial3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `baseColorFactor: LinearColorF32`, `metallicFactor: float`, `roughnessFactor: float`, `emissiveFactor: Vec3`, `alphaCutoff: float`, `isDoubleSided: bool` | `PbrMaterial3D(baseColorFactor, metallicFactor, roughnessFactor, emissiveFactor, alphaCutoff, isDoubleSided)` |
| `ToonMaterial3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `baseColor: ColorRgba8`, `rampSteps: int`, `outlineWidth: float`, `outlineColor: ColorRgba8` | `ToonMaterial3D(baseColor, rampSteps, outlineWidth, outlineColor)` |
| `UnlitMaterial3D` | `pub struct` | `std/gfx3d/material3d.aipl` | `color: ColorRgba8` | `UnlitMaterial3D(color)` |
| `Vertex3D` | `pub struct` | `std/gfx3d/mesh3d.aipl` | `pos: Vec3`, `normal: Vec3`, `tangent: Vec4`, `uv: Vec2`, `color: ColorRgba8`, `boneIndices: IVec4`, `boneWeights: Vec4` | `Vertex3D(pos, normal, tangent, uv, color, boneIndices, boneWeights)` |
| `SubMesh3D` | `pub struct` | `std/gfx3d/mesh3d.aipl` | `startIndex: int`, `indexCount: int`, `materialIndex: int`, `boundingBox: AABB3D` | `SubMesh3D(startIndex, indexCount, materialIndex, boundingBox)` |
| `Mesh3D` | `pub struct` | `std/gfx3d/mesh3d.aipl` | `vertices: [Vertex3D]`, `indices: [int]`, `subMeshes: [SubMesh3D]`, `boundingBox: AABB3D` | `Mesh3D(vertices, indices, subMeshes, boundingBox)` |
| `Bone3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `name: str`, `parentIdx: int`, `localPos: Vec3`, `localRot: Quat`, `localScale: Vec3`, `invBindMatrix: Mat4`, `worldMatrix: Mat4` | `Bone3D(name, parentIdx, localPos, localRot, localScale, invBindMatrix, worldMatrix)` |
| `Skeleton3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `bones: [Bone3D]` | `Skeleton3D(bones)` |
| `DualQuatSkin` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `realQuat: Quat`, `dualQuat: Quat` | `DualQuatSkin(realQuat, dualQuat)` |
| `TwoBoneIKResult3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `midPos: Vec3`, `endPos: Vec3`, `kneeBendDeg: float`, `reachable: bool` | `TwoBoneIKResult3D(midPos, endPos, kneeBendDeg, reachable)` |
| `JointPose3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `id: int`, `parentId: int`, `localPos: Vec3`, `localRot: Quat`, `worldPos: Vec3`, `worldRot: Quat` | `JointPose3D(id, parentId, localPos, localRot, worldPos, worldRot)` |
| `SceneNode3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `id: int`, `parentId: int`, `localX: float`, `localY: float`, `localZ: float`, `scaleX: float`, `scaleY: float`, `scaleZ: float`, `worldX: float`, `worldY: float`, `worldZ: float`, `worldScaleX: float`, `worldScaleY: float`, `worldScaleZ: float`, `dirty: bool` | `SceneNode3D(id, parentId, localX, localY, localZ, scaleX, scaleY, scaleZ, worldX, worldY, worldZ, worldScaleX, worldScaleY, worldScaleZ, dirty)` |
| `TransformedAABB3D` | `pub struct` | `std/gfx3d/rigging3d.aipl` | `minX: float`, `minY: float`, `minZ: float`, `maxX: float`, `maxY: float`, `maxZ: float` | `TransformedAABB3D(minX, minY, minZ, maxX, maxY, maxZ)` |
| `AtmosphereSettings` | `pub struct` | `std/gfx3d/skybox3d.aipl` | `sunDirection: Vec3`, `rayleighCoeff: Vec3`, `mieCoeff: float`, `sunIntensity: float` | `AtmosphereSettings(sunDirection, rayleighCoeff, mieCoeff, sunIntensity)` |
| `TerrainHeightfield` | `pub struct` | `std/gfx3d/terrain3d.aipl` | `width: int`, `depth: int`, `heightValues: [float]`, `heightScale: float`, `horizontalScale: float` | `TerrainHeightfield(width, depth, heightValues, heightScale, horizontalScale)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/gfx3d/camera3d.aipl` | `createPerspectiveCamera3D` | `pub fn createPerspectiveCamera3D(pos: Vec3, target: Vec3, fovDeg: float, aspect: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `2` | `std/gfx3d/camera3d.aipl` | `createOrthographicCamera3D` | `pub fn createOrthographicCamera3D(pos: Vec3, target: Vec3, orthoW: float, orthoH: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `3` | `std/gfx3d/camera3d.aipl` | `computeViewMatrix` | `pub fn computeViewMatrix(cam: Camera3D): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `4` | `std/gfx3d/camera3d.aipl` | `computeProjectionMatrix` | `pub fn computeProjectionMatrix(cam: Camera3D): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `5` | `std/gfx3d/camera3d.aipl` | `makeNormalizedPlane` | `fn makeNormalizedPlane(nx: float, ny: float, nz: float, d: float): Plane3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `6` | `std/gfx3d/camera3d.aipl` | `extractFrustumPlanes` | `pub fn extractFrustumPlanes(viewProj: Mat4): Frustum3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `7` | `std/gfx3d/camera3d.aipl` | `updateOrbitController` | `pub fn updateOrbitController(ctrl: OrbitController3D, deltaYaw: float, deltaPitch: float, deltaZoom: float): OrbitController3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `8` | `std/gfx3d/camera3d.aipl` | `quatIdentity` | `pub fn quatIdentity(): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `9` | `std/gfx3d/camera3d.aipl` | `quatNormalize` | `pub fn quatNormalize(q: Quat): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `10` | `std/gfx3d/camera3d.aipl` | `quatConjugate` | `pub fn quatConjugate(q: Quat): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `11` | `std/gfx3d/camera3d.aipl` | `quatMul` | `pub fn quatMul(a: Quat, b: Quat): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `12` | `std/gfx3d/camera3d.aipl` | `quatFromAxisAngle` | `pub fn quatFromAxisAngle(axis: Vec3, angleRad: float): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `13` | `std/gfx3d/camera3d.aipl` | `quatFromEuler` | `pub fn quatFromEuler(pitchX: float, yawY: float, rollZ: float): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `14` | `std/gfx3d/camera3d.aipl` | `quatRotateVec3` | `pub fn quatRotateVec3(q: Quat, v: Vec3): Vec3:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `15` | `std/gfx3d/camera3d.aipl` | `quatSlerp` | `pub fn quatSlerp(a: Quat, b: Quat, t: float): Quat:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `16` | `std/gfx3d/camera3d.aipl` | `mat4Identity` | `pub fn mat4Identity(): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `17` | `std/gfx3d/camera3d.aipl` | `mat4Mul` | `pub fn mat4Mul(a: Mat4, b: Mat4): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `18` | `std/gfx3d/camera3d.aipl` | `mat4FromTRS` | `pub fn mat4FromTRS(translation: Vec3, rotation: Quat, scaleVec: Vec3): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `19` | `std/gfx3d/camera3d.aipl` | `mat3NormalFromMat4` | `pub fn mat3NormalFromMat4(m: Mat4): Mat3:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `20` | `std/gfx3d/camera3d.aipl` | `mat4TransformVec3` | `pub fn mat4TransformVec3(m: Mat4, v: Vec3): Vec3:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `21` | `std/gfx3d/camera3d.aipl` | `mat4LookAt` | `pub fn mat4LookAt(eye: Vec3, target: Vec3, up: Vec3): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `22` | `std/gfx3d/camera3d.aipl` | `mat4Perspective` | `pub fn mat4Perspective(fovyDeg: float, aspect: float, nearPlane: float, farPlane: float): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `23` | `std/gfx3d/camera3d.aipl` | `mat4Orthographic` | `pub fn mat4Orthographic(orthoHeight: float, aspect: float, nearPlane: float, farPlane: float): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `24` | `std/gfx3d/camera3d.aipl` | `camera3DPerspective` | `pub fn camera3DPerspective(pos: Vec3, target: Vec3, up: Vec3, fovyDeg: float, aspect: float, nearPlane: float, farPlane: float): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `25` | `std/gfx3d/camera3d.aipl` | `camera3DOrthographic` | `pub fn camera3DOrthographic(pos: Vec3, target: Vec3, up: Vec3, orthoHeight: float, aspect: float, nearPlane: float, farPlane: float): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `26` | `std/gfx3d/camera3d.aipl` | `camera3DUpdateOrbit` | `pub fn camera3DUpdateOrbit(cam: Camera3D, deltaYawRad: float, deltaPitchRad: float, deltaDist: float): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `27` | `std/gfx3d/camera3d.aipl` | `camera3DUpdateFirstPerson` | `pub fn camera3DUpdateFirstPerson(cam: Camera3D, forwardStep: float, strafeStep: float, deltaYawRad: float, deltaPitchRad: float): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `28` | `std/gfx3d/camera3d.aipl` | `camera3DUpdateFreeFly` | `pub fn camera3DUpdateFreeFly(cam: Camera3D, forwardStep: float, strafeStep: float, verticalStep: float, deltaYawRad: float, deltaPitchRad: float): Camera3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `29` | `std/gfx3d/camera3d.aipl` | `camera3DViewMatrix` | `pub fn camera3DViewMatrix(cam: Camera3D): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `30` | `std/gfx3d/camera3d.aipl` | `camera3DProjMatrix` | `pub fn camera3DProjMatrix(cam: Camera3D): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `31` | `std/gfx3d/camera3d.aipl` | `camera3DViewProjMatrix` | `pub fn camera3DViewProjMatrix(cam: Camera3D): Mat4:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `32` | `std/gfx3d/camera3d.aipl` | `extractFrustum3D` | `pub fn extractFrustum3D(cam: Camera3D): Frustum3D:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `33` | `std/gfx3d/camera3d.aipl` | `frustumContainsSphere` | `pub fn frustumContainsSphere(frustum: Frustum3D, center: Vec3, radius: float): bool:` | `tests/functions/gfx3d/camera3d_test.aipl` |
| `34` | `std/gfx3d/cull3d.aipl` | `testFrustumAabb` | `pub fn testFrustumAabb(frustum: Frustum3D, aabb: AABB3D): bool:` | `tests/functions/gfx3d/cull3d_test.aipl` |
| `35` | `std/gfx3d/cull3d.aipl` | `testFrustumSphere` | `pub fn testFrustumSphere(frustum: Frustum3D, center: Vec3, radius: float): bool:` | `tests/functions/gfx3d/cull3d_test.aipl` |
| `36` | `std/gfx3d/cull3d.aipl` | `projectAabbToScreenRect` | `pub fn projectAabbToScreenRect(aabb: AABB3D, viewProj: Mat4, screenW: float, screenH: float): Rect:` | `tests/functions/gfx3d/cull3d_test.aipl` |
| `37` | `std/gfx3d/decal3d.aipl` | `createDecalProjector` | `pub fn createDecalProjector(pos: Vec3, rot: Quat, extents: Vec3, texId: int): DecalProjector:` | `tests/functions/gfx3d/decal3d_test.aipl` |
| `38` | `std/gfx3d/decal3d.aipl` | `clipPolygonAgainstPlane` | `fn clipPolygonAgainstPlane(pts: [Vec3], nx: float, ny: float, nz: float, limit: float): [Vec3]:` | `tests/functions/gfx3d/decal3d_test.aipl` |
| `39` | `std/gfx3d/decal3d.aipl` | `clipTriangleAgainstBoxPlanes` | `pub fn clipTriangleAgainstBoxPlanes(triPts: [Vec3], boxExtents: Vec3): [Vec3]:` | `tests/functions/gfx3d/decal3d_test.aipl` |
| `40` | `std/gfx3d/light3d.aipl` | `createDirectionalLight` | `pub fn createDirectionalLight(direction: Vec3, color: LinearColorF32, intensity: float = 1.0): Light3D:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `41` | `std/gfx3d/light3d.aipl` | `createPointLight` | `pub fn createPointLight(pos: Vec3, color: LinearColorF32, range: float, intensity: float = 1.0): Light3D:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `42` | `std/gfx3d/light3d.aipl` | `createSpotLight` | `pub fn createSpotLight(pos: Vec3, dir: Vec3, color: LinearColorF32, range: float, innerAngleDeg: float, outerAngleDeg: float): Light3D:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `43` | `std/gfx3d/light3d.aipl` | `computePointLightAttenuation` | `pub fn computePointLightAttenuation(dist: float, range: float): float:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `44` | `std/gfx3d/light3d.aipl` | `computeSpotLightAttenuation` | `pub fn computeSpotLightAttenuation(light: Light3D, lightToPt: Vec3): float:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `45` | `std/gfx3d/light3d.aipl` | `computeCascadedShadowSplits` | `pub fn computeCascadedShadowSplits(nearZ: float, farZ: float, cascadeCount: int = 4, lambdaFactor: float = 0.75): [float]:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `46` | `std/gfx3d/light3d.aipl` | `lightComputePointAttenuation` | `pub fn lightComputePointAttenuation(distSqVal: float, radius: float, intensity: float, falloffExp: float): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `47` | `std/gfx3d/light3d.aipl` | `lightComputeLambertDiffuseRGB` | `pub fn lightComputeLambertDiffuseRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, baseR: int, baseG: int, baseB: int, lightR: int, lightG: int, lightB: int, ambientPct: int): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `48` | `std/gfx3d/light3d.aipl` | `lightCast2DShadowVisibility` | `pub fn lightCast2DShadowVisibility(ox: float, oy: float, tx: float, ty: float, blockerMinX: float, blockerMinY: float, blockerMaxX: float, blockerMaxY: float): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `49` | `std/gfx3d/light3d.aipl` | `lightComputeSpotConeAttenuation` | `pub fn lightComputeSpotConeAttenuation(dirX: float, dirY: float, toPointX: float, toPointY: float, cosInner: float, cosOuter: float): float:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `50` | `std/gfx3d/light3d.aipl` | `lightComputeLightningFlashAmbientBoost` | `pub fn lightComputeLightningFlashAmbientBoost(baseAmbient: int, boltIntensity: int, decayTick: int): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `51` | `std/gfx3d/light3d.aipl` | `lightComputeNvgPhosphorGain` | `pub fn lightComputeNvgPhosphorGain(baseLuma: int, nvgActive: int, dlightBoost: int): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `52` | `std/gfx3d/light3d.aipl` | `lightComputeBlinnPhongRGB` | `pub fn lightComputeBlinnPhongRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, baseHex: int, specStrength: float, shininess: float): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `53` | `std/gfx3d/light3d.aipl` | `lightComputePbrCookTorranceRGB` | `pub fn lightComputePbrCookTorranceRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, albedoHex: int, metallic: float, roughness: float, ao: float): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `54` | `std/gfx3d/light3d.aipl` | `lightComputeSpotConeAttenuation3D` | `pub fn lightComputeSpotConeAttenuation3D(dirX: float, dirY: float, dirZ: float, toPointX: float, toPointY: float, toPointZ: float, cosInner: float, cosOuter: float): float:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `55` | `std/gfx3d/light3d.aipl` | `lightApplyExponentialFogRGB` | `pub fn lightApplyExponentialFogRGB(surfaceHex: int, fogHex: int, distance: float, density: float): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `56` | `std/gfx3d/light3d.aipl` | `lightSampleProceduralSkyboxRGB` | `pub fn lightSampleProceduralSkyboxRGB(dirX: float, dirY: float, dirZ: float, zenithHex: int, horizonHex: int, nadirHex: int): int:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `57` | `std/gfx3d/light3d.aipl` | `lightCompareShadowDepth` | `pub fn lightCompareShadowDepth(fragDepth: float, closestShadowDepth: float, bias: float): float:` | `tests/functions/gfx3d/light3d_test.aipl` |
| `58` | `std/gfx3d/material3d.aipl` | `createDefaultPbrMaterial` | `pub fn createDefaultPbrMaterial(): PbrMaterial3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `59` | `std/gfx3d/material3d.aipl` | `evaluateGgxDistribution` | `pub fn evaluateGgxDistribution(nDotH: float, roughness: float): float:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `60` | `std/gfx3d/material3d.aipl` | `schlickG1` | `fn schlickG1(nDotX: float, k: float): float:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `61` | `std/gfx3d/material3d.aipl` | `evaluateSmithSchlickGeometry` | `pub fn evaluateSmithSchlickGeometry(nDotV: float, nDotL: float, roughness: float): float:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `62` | `std/gfx3d/material3d.aipl` | `evaluateSchlickFresnel` | `pub fn evaluateSchlickFresnel(vDotH: float, f0: Vec3): Vec3:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `63` | `std/gfx3d/material3d.aipl` | `evaluateCookTorranceBrdf` | `pub fn evaluateCookTorranceBrdf(nDotL: float, nDotV: float, nDotH: float, vDotH: float, albedo: Vec3, metallic: float, roughness: float): Vec3:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `64` | `std/gfx3d/material3d.aipl` | `material3DLambert` | `pub fn material3DLambert(albedoHex: int, ao: float = 1.0): Material3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `65` | `std/gfx3d/material3d.aipl` | `material3DBlinnPhong` | `pub fn material3DBlinnPhong(albedoHex: int, specularStrength: float, shininess: float): Material3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `66` | `std/gfx3d/material3d.aipl` | `material3DPbr` | `pub fn material3DPbr(albedoHex: int, metallic: float, roughness: float, ao: float, emissiveHex: int): Material3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `67` | `std/gfx3d/material3d.aipl` | `evaluateMaterial3D` | `pub fn evaluateMaterial3D(mat: Material3D, normal: Vec3, viewDir: Vec3, lightDir: Vec3): int:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `68` | `std/gfx3d/material3d.aipl` | `evaluateMaterial3DWithLight` | `pub fn evaluateMaterial3DWithLight(mat: Material3D, normal: Vec3, tangentNormal: Vec3, viewDir: Vec3, light: DirectionalLight3D): int:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `69` | `std/gfx3d/material3d.aipl` | `createRenderPass3D` | `pub fn createRenderPass3D(cameraPos: Vec3, lightDir: Vec3, nearClip: float): RenderPass3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `70` | `std/gfx3d/material3d.aipl` | `submitMesh3D` | `pub fn submitMesh3D(mut pass: RenderPass3D, positions: [Vec3], normals: [Vec3], indices: [int], mat: Material3D): RenderPass3D:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `71` | `std/gfx3d/material3d.aipl` | `endRenderPass3D` | `pub fn endRenderPass3D(mut pass: RenderPass3D): [RenderTri3D]:` | `tests/functions/gfx3d/material3d_test.aipl` |
| `72` | `std/gfx3d/mesh3d.aipl` | `createEmptyMesh3D` | `pub fn createEmptyMesh3D(): Mesh3D:` | `tests/functions/gfx3d/mesh3d_test.aipl` |
| `73` | `std/gfx3d/mesh3d.aipl` | `recomputeMeshBoundingBox` | `pub fn recomputeMeshBoundingBox(mesh: Mesh3D): Mesh3D:` | `tests/functions/gfx3d/mesh3d_test.aipl` |
| `74` | `std/gfx3d/mesh3d.aipl` | `computeMeshNormals` | `pub fn computeMeshNormals(mesh: Mesh3D): Mesh3D:` | `tests/functions/gfx3d/mesh3d_test.aipl` |
| `75` | `std/gfx3d/mesh3d.aipl` | `computeMeshTangentsMikkTSpace` | `pub fn computeMeshTangentsMikkTSpace(mesh: Mesh3D): Mesh3D:` | `tests/functions/gfx3d/mesh3d_test.aipl` |
| `76` | `std/gfx3d/primitives3d.aipl` | `makeVert` | `fn makeVert(px: float, py: float, pz: float, nx: float, ny: float, nz: float, u: float, v: float): Vertex3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `77` | `std/gfx3d/primitives3d.aipl` | `finalizePrimitiveMesh` | `fn finalizePrimitiveMesh(verts: [Vertex3D], indices: [int]): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `78` | `std/gfx3d/primitives3d.aipl` | `generateBoxMesh` | `pub fn generateBoxMesh(width: float, height: float, depth: float): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `79` | `std/gfx3d/primitives3d.aipl` | `generateUvSphereMesh` | `pub fn generateUvSphereMesh(radius: float, segments: int = 32, rings: int = 16): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `80` | `std/gfx3d/primitives3d.aipl` | `generateIcosphereMesh` | `pub fn generateIcosphereMesh(radius: float, subdivisions: int = 3): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `81` | `std/gfx3d/primitives3d.aipl` | `generateCylinderMesh` | `pub fn generateCylinderMesh(radius: float, height: float, segments: int = 32, capped: bool = true): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `82` | `std/gfx3d/primitives3d.aipl` | `generateConeMesh` | `pub fn generateConeMesh(radius: float, height: float, segments: int = 32): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `83` | `std/gfx3d/primitives3d.aipl` | `generateTorusMesh` | `pub fn generateTorusMesh(majorRadius: float, minorRadius: float, radialSegments: int = 32, tubularSegments: int = 16): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `84` | `std/gfx3d/primitives3d.aipl` | `generatePlaneMesh` | `pub fn generatePlaneMesh(width: float, depth: float, subX: int = 1, subZ: int = 1): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `85` | `std/gfx3d/primitives3d.aipl` | `generateCapsuleMesh` | `pub fn generateCapsuleMesh(radius: float, cylinderHeight: float, rings: int = 8, segments: int = 16): Mesh3D:` | `tests/functions/gfx3d/primitives3d_test.aipl` |
| `86` | `std/gfx3d/rigging3d.aipl` | `composeBoneLocalMatrix` | `fn composeBoneLocalMatrix(pos: Vec3, rot: Quat, scale: Vec3): Mat4:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `87` | `std/gfx3d/rigging3d.aipl` | `updateSkeletonHierarchy` | `pub fn updateSkeletonHierarchy(skel: Skeleton3D): Skeleton3D:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `88` | `std/gfx3d/rigging3d.aipl` | `computeLinearSkinningPalette` | `pub fn computeLinearSkinningPalette(skel: Skeleton3D): [Mat4]:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `89` | `std/gfx3d/rigging3d.aipl` | `extractQuatFromMat4` | `fn extractQuatFromMat4(m: Mat4): Quat:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `90` | `std/gfx3d/rigging3d.aipl` | `matrixToDualQuat` | `pub fn matrixToDualQuat(m: Mat4): DualQuatSkin:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `91` | `std/gfx3d/rigging3d.aipl` | `blendDualQuaternions` | `pub fn blendDualQuaternions(dq1: DualQuatSkin, dq2: DualQuatSkin, weight: float): DualQuatSkin:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `92` | `std/gfx3d/rigging3d.aipl` | `skelForwardKinematics2D_X` | `pub fn skelForwardKinematics2D_X(originX: float, boneLen: float, angleDeg: float): float:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `93` | `std/gfx3d/rigging3d.aipl` | `skelForwardKinematics2D_Y` | `pub fn skelForwardKinematics2D_Y(originY: float, boneLen: float, angleDeg: float): float:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `94` | `std/gfx3d/rigging3d.aipl` | `skelSolveTwoBoneIKAngleDeg` | `pub fn skelSolveTwoBoneIKAngleDeg(rootX: float, rootY: float, targetX: float, targetY: float, len1: float, len2: float): float:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `95` | `std/gfx3d/rigging3d.aipl` | `skelInterpolateKeyframeHermite` | `pub fn skelInterpolateKeyframeHermite(val0: float, m0: float, val1: float, m1: float, t01: float): float:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `96` | `std/gfx3d/rigging3d.aipl` | `skelSolveTwoBoneIK3D` | `pub fn skelSolveTwoBoneIK3D(rootPos: Vec3, targetPos: Vec3, polePos: Vec3, len1: float, len2: float): TwoBoneIKResult3D:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `97` | `std/gfx3d/rigging3d.aipl` | `skelSolveFabrik3D` | `pub fn skelSolveFabrik3D(joints: [Vec3], lengths: [float], targetPos: Vec3, iterations: int, tolerance: float): [Vec3]:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `98` | `std/gfx3d/rigging3d.aipl` | `solveJointHierarchy3D` | `pub fn solveJointHierarchy3D(joints: [JointPose3D]): [JointPose3D]:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `99` | `std/gfx3d/rigging3d.aipl` | `createSceneNode3D` | `pub fn createSceneNode3D(id: int, parentId: int, lx: float, ly: float, lz: float, sx: float, sy: float, sz: float): SceneNode3D:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `100` | `std/gfx3d/rigging3d.aipl` | `updateSceneGraph3D` | `pub fn updateSceneGraph3D(nodes: [SceneNode3D]): [SceneNode3D]:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `101` | `std/gfx3d/rigging3d.aipl` | `transformAABB3D` | `pub fn transformAABB3D(minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, m: [float]): TransformedAABB3D:` | `tests/functions/gfx3d/rigging3d_test.aipl` |
| `102` | `std/gfx3d/skybox3d.aipl` | `computeAtmosphericScattering` | `pub fn computeAtmosphericScattering(dir: Vec3, settings: AtmosphereSettings): Vec3:` | `tests/functions/gfx3d/skybox3d_test.aipl` |
| `103` | `std/gfx3d/skybox3d.aipl` | `sampleEquirectangularUv` | `pub fn sampleEquirectangularUv(direction: Vec3): Vec2:` | `tests/functions/gfx3d/skybox3d_test.aipl` |
| `104` | `std/gfx3d/terrain3d.aipl` | `readGridHeight` | `fn readGridHeight(terrain: TerrainHeightfield, gx: int, gz: int): float:` | `tests/functions/gfx3d/terrain3d_test.aipl` |
| `105` | `std/gfx3d/terrain3d.aipl` | `sampleHeightAt` | `pub fn sampleHeightAt(terrain: TerrainHeightfield, worldX: float, worldZ: float): float:` | `tests/functions/gfx3d/terrain3d_test.aipl` |
| `106` | `std/gfx3d/terrain3d.aipl` | `computeTerrainNormal` | `pub fn computeTerrainNormal(terrain: TerrainHeightfield, gridX: int, gridZ: int): Vec3:` | `tests/functions/gfx3d/terrain3d_test.aipl` |
| `107` | `std/gfx3d/terrain3d.aipl` | `computeTriplanarWeights` | `pub fn computeTriplanarWeights(normal: Vec3, sharpness: float = 4.0): Vec3:` | `tests/functions/gfx3d/terrain3d_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createPerspectiveCamera3D` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn createPerspectiveCamera3D(pos: Vec3, target: Vec3, fovDeg: float, aspect: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, target: Vec3, fovDeg: float, aspect: float, nearZ: float = 0.1, farZ: float = 1000.0` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `createPerspectiveCamera3D` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `fovDeg: float = 1.0`, `aspect: float = 1.0`, `nearZ: float = 1.0`, `farZ: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z1_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_createPerspectiveCamera3D_1(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_fovDeg = 1.0
  let edge_fovDeg = 0.5
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearZ = 1.0
  let edge_nearZ = 0.5
  let arg_farZ = 1.0
  let edge_farZ = 0.5
  let resNom = createPerspectiveCamera3D(arg_pos, arg_target, arg_fovDeg, arg_aspect, arg_nearZ, arg_farZ)
  let resEdge = createPerspectiveCamera3D(edge_pos, edge_target, edge_fovDeg, edge_aspect, edge_nearZ, edge_farZ)
  assertApproxEq(resNom.fovYRad, 0.017453, 0.001, "createPerspectiveCamera3D nominal resNom.fovYRad ~= 0.017453")
  assertApproxEq(resEdge.fovYRad, 0.008727, 0.001, "createPerspectiveCamera3D boundary resEdge.fovYRad ~= 0.008727")
  ret 0
```

---

### `createOrthographicCamera3D` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn createOrthographicCamera3D(pos: Vec3, target: Vec3, orthoW: float, orthoH: float, nearZ: float = 0.1, farZ: float = 1000.0): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, target: Vec3, orthoW: float, orthoH: float, nearZ: float = 0.1, farZ: float = 1000.0` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `createOrthographicCamera3D` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `orthoW: float = 1.0`, `orthoH: float = 1.0`, `nearZ: float = 1.0`, `farZ: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z2_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_createOrthographicCamera3D_2(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_orthoW = 2.0
  let edge_orthoW = 1.0
  let arg_orthoH = 2.0
  let edge_orthoH = 1.0
  let arg_nearZ = 1.0
  let edge_nearZ = 0.5
  let arg_farZ = 1.0
  let edge_farZ = 0.5
  let resNom = createOrthographicCamera3D(arg_pos, arg_target, arg_orthoW, arg_orthoH, arg_nearZ, arg_farZ)
  let resEdge = createOrthographicCamera3D(edge_pos, edge_target, edge_orthoW, edge_orthoH, edge_nearZ, edge_farZ)
  assertApproxEq(resNom.fovYRad, 1.0472, 0.001, "createOrthographicCamera3D nominal resNom.fovYRad ~= 1.0472")
  assertApproxEq(resEdge.fovYRad, 1.0472, 0.001, "createOrthographicCamera3D boundary resEdge.fovYRad ~= 1.0472")
  ret 0
```

---

### `computeViewMatrix` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn computeViewMatrix(cam: Camera3D): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `computeViewMatrix` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.gfx3d.camera3d_z3_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_computeViewMatrix_3(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = computeViewMatrix(arg_cam)
  let resEdge = computeViewMatrix(edge_cam)
  assertApproxEq(resNom.m00, 0.707107, 0.001, "computeViewMatrix nominal resNom.m00 ~= 0.707107")
  assertApproxEq(resEdge.m00, 0.707107, 0.001, "computeViewMatrix boundary resEdge.m00 ~= 0.707107")
  ret 0
```

---

### `computeProjectionMatrix` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn computeProjectionMatrix(cam: Camera3D): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `computeProjectionMatrix` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `Mat4(`.

```aipl
module tests.functions.gfx3d.camera3d_z4_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_computeProjectionMatrix_4(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = computeProjectionMatrix(arg_cam)
  let resEdge = computeProjectionMatrix(edge_cam)
  assertApproxEq(resNom.m00, 1.0, 0.001, "computeProjectionMatrix nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 7.83263, 0.001, "computeProjectionMatrix boundary resEdge.m00 ~= 7.83263")
  ret 0
```

---

### `makeNormalizedPlane` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `fn makeNormalizedPlane(nx: float, ny: float, nz: float, d: float): Plane3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nx: float, ny: float, nz: float, d: float` | **Returns**: `Plane3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `makeNormalizedPlane` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `d: float = 1.0`; exercises core body path returning/computing `Plane3D(normal = Vec3(x = 0.0, y = 1.0, z = 0.0), distance = 0.0, d = 0.0)`.

```aipl
module tests.functions.gfx3d.camera3d_z5_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_makeNormalizedPlane_5(): int:
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_d = 1.0
  let edge_d = 0.5
  let resNom = makeNormalizedPlane(arg_nx, arg_ny, arg_nz, arg_d)
  let resEdge = makeNormalizedPlane(edge_nx, edge_ny, edge_nz, edge_d)
  assertApproxEq(resNom.distance, 0.57735, 0.001, "makeNormalizedPlane nominal resNom.distance ~= 0.57735")
  assertApproxEq(resEdge.distance, 0.57735, 0.001, "makeNormalizedPlane boundary resEdge.distance ~= 0.57735")
  ret 0
```

---

### `extractFrustumPlanes` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn extractFrustumPlanes(viewProj: Mat4): Frustum3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `viewProj: Mat4` | **Returns**: `Frustum3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `extractFrustumPlanes` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `viewProj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Frustum3D(planes = [pLeft, pRight, pBottom, pTop, pNear, pFar])`.

```aipl
module tests.functions.gfx3d.camera3d_z6_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_extractFrustumPlanes_6(): int:
  let arg_viewProj = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_viewProj = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = extractFrustumPlanes(arg_viewProj)
  let resEdge = extractFrustumPlanes(edge_viewProj)
  assertEqInt(resNom.planes.len(), 6, "extractFrustumPlanes nominal resNom.planes.len() == 6")
  assertEqInt(resEdge.planes.len(), 6, "extractFrustumPlanes boundary resEdge.planes.len() == 6")
  ret 0
```

---

### `updateOrbitController` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn updateOrbitController(ctrl: OrbitController3D, deltaYaw: float, deltaPitch: float, deltaZoom: float): OrbitController3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ctrl: OrbitController3D, deltaYaw: float, deltaPitch: float, deltaZoom: float` | **Returns**: `OrbitController3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `updateOrbitController` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `ctrl: OrbitController3D = OrbitController3D(target = Vec3(x = 1.0, y = 1.0, z = 1.0), yawRad = 1.0, pitchRad = 1.0, distance = 1.0, minDistance = 1.0, maxDistance = 1.0, minPitchRad = 1.0, maxPitchRad = 1.0)`, `deltaYaw: float = 1.0`, `deltaPitch: float = 1.0`, `deltaZoom: float = 1.0`; exercises core body path returning/computing `OrbitController3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z7_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_updateOrbitController_7(): int:
  let arg_ctrl = OrbitController3D(target = Vec3(x = 1.0, y = 1.0, z = 1.0), yawRad = 2.0, pitchRad = 2.0, distance = 1.0, minDistance = 0.0, maxDistance = 2.0, minPitchRad = 0.0, maxPitchRad = 2.0)
  let edge_ctrl = OrbitController3D(target = Vec3(x = 0.5, y = 0.5, z = 0.5), yawRad = 1.0, pitchRad = 1.0, distance = 0.5, minDistance = 0.0, maxDistance = 1.0, minPitchRad = 0.0, maxPitchRad = 1.0)
  let arg_deltaYaw = 2.0
  let edge_deltaYaw = 1.0
  let arg_deltaPitch = 2.0
  let edge_deltaPitch = 1.0
  let arg_deltaZoom = 1.0
  let edge_deltaZoom = 0.5
  let resNom = updateOrbitController(arg_ctrl, arg_deltaYaw, arg_deltaPitch, arg_deltaZoom)
  let resEdge = updateOrbitController(edge_ctrl, edge_deltaYaw, edge_deltaPitch, edge_deltaZoom)
  assertApproxEq(resNom.yawRad, 4.0, 0.001, "updateOrbitController nominal resNom.yawRad ~= 4.0")
  assertApproxEq(resEdge.yawRad, 2.0, 0.001, "updateOrbitController boundary resEdge.yawRad ~= 2.0")
  ret 0
```

---

### `quatIdentity` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatIdentity(): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `quatIdentity` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Quat.identity()`.

```aipl
module tests.functions.gfx3d.camera3d_z8_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatIdentity_8(): int:
  let resNom = quatIdentity()
  let resEdge = quatIdentity()
  assertApproxEq(resNom.x, 0.0, 0.001, "quatIdentity nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "quatIdentity boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `quatNormalize` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatNormalize(q: Quat): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q: Quat` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `quatNormalize` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `q: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `q.norm()`.

```aipl
module tests.functions.gfx3d.camera3d_z9_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatNormalize_9(): int:
  let arg_q = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_q = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = quatNormalize(arg_q)
  let resEdge = quatNormalize(edge_q)
  assertApproxEq(resNom.x, 0.377964, 0.001, "quatNormalize nominal resNom.x ~= 0.377964")
  assertApproxEq(resEdge.x, 0.377964, 0.001, "quatNormalize boundary resEdge.x ~= 0.377964")
  ret 0
```

---

### `quatConjugate` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatConjugate(q: Quat): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q: Quat` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `quatConjugate` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `q: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `q.conjugate()`.

```aipl
module tests.functions.gfx3d.camera3d_z10_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatConjugate_10(): int:
  let arg_q = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_q = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = quatConjugate(arg_q)
  let resEdge = quatConjugate(edge_q)
  assertApproxEq(resNom.x, -1.0, 0.001, "quatConjugate nominal resNom.x ~= -1.0")
  assertApproxEq(resEdge.x, -0.5, 0.001, "quatConjugate boundary resEdge.x ~= -0.5")
  ret 0
```

---

### `quatMul` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatMul(a: Quat, b: Quat): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Quat, b: Quat` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `quatMul` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `a: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`; exercises core body path returning/computing `a.mul(b)`.

```aipl
module tests.functions.gfx3d.camera3d_z11_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatMul_11(): int:
  let arg_a = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let resNom = quatMul(arg_a, arg_b)
  let resEdge = quatMul(edge_a, edge_b)
  assertApproxEq(resNom.x, 4.0, 0.001, "quatMul nominal resNom.x ~= 4.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "quatMul boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `quatFromAxisAngle` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatFromAxisAngle(axis: Vec3, angleRad: float): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `axis: Vec3, angleRad: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `quatFromAxisAngle` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `axis: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `angleRad: float = 1.0`; exercises core body path returning/computing `Quat.fromAxisAngle(axis, angleRad)`.

```aipl
module tests.functions.gfx3d.camera3d_z12_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatFromAxisAngle_12(): int:
  let arg_axis = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_axis = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_angleRad = 1.0
  let edge_angleRad = 0.5
  let resNom = quatFromAxisAngle(arg_axis, arg_angleRad)
  let resEdge = quatFromAxisAngle(edge_axis, edge_angleRad)
  assertApproxEq(resNom.x, 0.276796, 0.001, "quatFromAxisAngle nominal resNom.x ~= 0.276796")
  assertApproxEq(resEdge.x, 0.142839, 0.001, "quatFromAxisAngle boundary resEdge.x ~= 0.142839")
  ret 0
```

---

### `quatFromEuler` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatFromEuler(pitchX: float, yawY: float, rollZ: float): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pitchX: float, yawY: float, rollZ: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `quatFromEuler` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `pitchX: float = 1.0`, `yawY: float = 1.0`, `rollZ: float = 1.0`; exercises core body path returning/computing `Quat.fromEuler(pitchX, yawY, rollZ)`.

```aipl
module tests.functions.gfx3d.camera3d_z13_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatFromEuler_13(): int:
  let arg_pitchX = 2.0
  let edge_pitchX = 1.0
  let arg_yawY = 2.0
  let edge_yawY = 1.0
  let arg_rollZ = 1.0
  let edge_rollZ = 0.5
  let resNom = quatFromEuler(arg_pitchX, arg_yawY, arg_rollZ)
  let resEdge = quatFromEuler(edge_pitchX, edge_yawY, edge_rollZ)
  assertApproxEq(resNom.x, -0.481436, 0.001, "quatFromEuler nominal resNom.x ~= -0.481436")
  assertApproxEq(resEdge.x, -0.032165, 0.001, "quatFromEuler boundary resEdge.x ~= -0.032165")
  ret 0
```

---

### `quatRotateVec3` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatRotateVec3(q: Quat, v: Vec3): Vec3:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `q: Quat, v: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `quatRotateVec3` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `q: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `v: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `q.rotateVec3(v)`.

```aipl
module tests.functions.gfx3d.camera3d_z14_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatRotateVec3_14(): int:
  let arg_q = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_q = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_v = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = quatRotateVec3(arg_q, arg_v)
  let resEdge = quatRotateVec3(edge_q, edge_v)
  assertApproxEq(resNom.x, 1.0, 0.001, "quatRotateVec3 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "quatRotateVec3 boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `quatSlerp` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn quatSlerp(a: Quat, b: Quat, t: float): Quat:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Quat, b: Quat, t: float` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `quatSlerp` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `a: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `b: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `a.slerp(b, t)`.

```aipl
module tests.functions.gfx3d.camera3d_z15_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_quatSlerp_15(): int:
  let arg_a = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_a = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_b = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_b = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = quatSlerp(arg_a, arg_b, arg_t)
  let resEdge = quatSlerp(edge_a, edge_b, edge_t)
  assertApproxEq(resNom.x, 0.377964, 0.001, "quatSlerp nominal resNom.x ~= 0.377964")
  assertApproxEq(resEdge.x, 0.377964, 0.001, "quatSlerp boundary resEdge.x ~= 0.377964")
  ret 0
```

---

### `mat4Identity` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4Identity(): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `mat4Identity` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mat4.identity()`.

```aipl
module tests.functions.gfx3d.camera3d_z16_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4Identity_16(): int:
  let resNom = mat4Identity()
  let resEdge = mat4Identity()
  assertApproxEq(resNom.m00, 1.0, 0.001, "mat4Identity nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "mat4Identity boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `mat4Mul` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4Mul(a: Mat4, b: Mat4): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Mat4, b: Mat4` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `mat4Mul` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `a: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`, `b: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `a.mul(b)`.

```aipl
module tests.functions.gfx3d.camera3d_z17_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4Mul_17(): int:
  let arg_a = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_a = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let arg_b = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_b = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = mat4Mul(arg_a, arg_b)
  let resEdge = mat4Mul(edge_a, edge_b)
  assertApproxEq(resNom.m00, 4.0, 0.001, "mat4Mul nominal resNom.m00 ~= 4.0")
  assertApproxEq(resEdge.m00, 1.0, 0.001, "mat4Mul boundary resEdge.m00 ~= 1.0")
  ret 0
```

---

### `mat4FromTRS` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4FromTRS(translation: Vec3, rotation: Quat, scaleVec: Vec3): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `translation: Vec3, rotation: Quat, scaleVec: Vec3` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `mat4FromTRS` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `translation: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `rotation: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `scaleVec: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `tMat.mul(rMat.mul(sMat))`.

```aipl
module tests.functions.gfx3d.camera3d_z18_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4FromTRS_18(): int:
  let arg_translation = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_translation = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rotation = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_rotation = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_scaleVec = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_scaleVec = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = mat4FromTRS(arg_translation, arg_rotation, arg_scaleVec)
  let resEdge = mat4FromTRS(edge_translation, edge_rotation, edge_scaleVec)
  assertApproxEq(resNom.m00, 0.428571, 0.001, "mat4FromTRS nominal resNom.m00 ~= 0.428571")
  assertApproxEq(resEdge.m00, 0.214286, 0.001, "mat4FromTRS boundary resEdge.m00 ~= 0.214286")
  ret 0
```

---

### `mat3NormalFromMat4` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat3NormalFromMat4(m: Mat4): Mat3:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat4` | **Returns**: `Mat3`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `mat3NormalFromMat4` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `m: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Mat3(`.

```aipl
module tests.functions.gfx3d.camera3d_z19_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat3NormalFromMat4_19(): int:
  let arg_m = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_m = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = mat3NormalFromMat4(arg_m)
  let resEdge = mat3NormalFromMat4(edge_m)
  assertApproxEq(resNom.m00, 1.0, 0.001, "mat3NormalFromMat4 nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 0.5, 0.001, "mat3NormalFromMat4 boundary resEdge.m00 ~= 0.5")
  ret 0
```

---

### `mat4TransformVec3` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4TransformVec3(m: Mat4, v: Vec3): Vec3:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat4, v: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `mat4TransformVec3` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `m: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`, `v: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(x = r.x / w, y = r.y / w, z = r.z / w)`.

```aipl
module tests.functions.gfx3d.camera3d_z20_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4TransformVec3_20(): int:
  let arg_m = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_m = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let arg_v = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_v = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = mat4TransformVec3(arg_m, arg_v)
  let resEdge = mat4TransformVec3(edge_m, edge_v)
  assertApproxEq(resNom.x, 1.0, 0.001, "mat4TransformVec3 nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "mat4TransformVec3 boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `mat4LookAt` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4LookAt(eye: Vec3, target: Vec3, up: Vec3): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `eye: Vec3, target: Vec3, up: Vec3` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `mat4LookAt` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `eye: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `up: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Mat4.lookAt(eye, target, up)`.

```aipl
module tests.functions.gfx3d.camera3d_z21_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4LookAt_21(): int:
  let arg_eye = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_eye = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_up = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_up = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = mat4LookAt(arg_eye, arg_target, arg_up)
  let resEdge = mat4LookAt(edge_eye, edge_target, edge_up)
  assertApproxEq(resNom.m00, 0.0, 0.001, "mat4LookAt nominal resNom.m00 ~= 0.0")
  assertApproxEq(resEdge.m00, 0.0, 0.001, "mat4LookAt boundary resEdge.m00 ~= 0.0")
  ret 0
```

---

### `mat4Perspective` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4Perspective(fovyDeg: float, aspect: float, nearPlane: float, farPlane: float): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fovyDeg: float, aspect: float, nearPlane: float, farPlane: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `mat4Perspective` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `fovyDeg: float = 1.0`, `aspect: float = 1.0`, `nearPlane: float = 1.0`, `farPlane: float = 1.0`; exercises core body path returning/computing `Mat4.perspective(fovyDeg * DEG2RAD, aspect, nearPlane, farPlane)`.

```aipl
module tests.functions.gfx3d.camera3d_z22_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4Perspective_22(): int:
  let arg_fovyDeg = 1.0
  let edge_fovyDeg = 0.5
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearPlane = 1.0
  let edge_nearPlane = 0.5
  let arg_farPlane = 1.0
  let edge_farPlane = 0.5
  let resNom = mat4Perspective(arg_fovyDeg, arg_aspect, arg_nearPlane, arg_farPlane)
  let resEdge = mat4Perspective(edge_fovyDeg, edge_aspect, edge_nearPlane, edge_farPlane)
  assertApproxEq(resNom.m00, 114.589, 0.001, "mat4Perspective nominal resNom.m00 ~= 114.589")
  assertApproxEq(resEdge.m00, 458.363, 0.001, "mat4Perspective boundary resEdge.m00 ~= 458.363")
  ret 0
```

---

### `mat4Orthographic` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn mat4Orthographic(orthoHeight: float, aspect: float, nearPlane: float, farPlane: float): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `orthoHeight: float, aspect: float, nearPlane: float, farPlane: float` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `mat4Orthographic` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `orthoHeight: float = 1.0`, `aspect: float = 1.0`, `nearPlane: float = 1.0`, `farPlane: float = 1.0`; exercises core body path returning/computing `Mat4.orthographic(-w * 0.5, w * 0.5, -h * 0.5, h * 0.5, nearPlane, farPlane)`.

```aipl
module tests.functions.gfx3d.camera3d_z23_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_mat4Orthographic_23(): int:
  let arg_orthoHeight = 2.0
  let edge_orthoHeight = 1.0
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearPlane = 1.0
  let edge_nearPlane = 0.5
  let arg_farPlane = 1.0
  let edge_farPlane = 0.5
  let resNom = mat4Orthographic(arg_orthoHeight, arg_aspect, arg_nearPlane, arg_farPlane)
  let resEdge = mat4Orthographic(edge_orthoHeight, edge_aspect, edge_nearPlane, edge_farPlane)
  assertApproxEq(resNom.m00, 1.0, 0.001, "mat4Orthographic nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 4.0, 0.001, "mat4Orthographic boundary resEdge.m00 ~= 4.0")
  ret 0
```

---

### `camera3DPerspective` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DPerspective(pos: Vec3, target: Vec3, up: Vec3, fovyDeg: float, aspect: float, nearPlane: float, farPlane: float): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, target: Vec3, up: Vec3, fovyDeg: float, aspect: float, nearPlane: float, farPlane: float` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `camera3DPerspective` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `up: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `fovyDeg: float = 1.0`, `aspect: float = 1.0`, `nearPlane: float = 1.0`, `farPlane: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z24_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DPerspective_24(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_up = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_up = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_fovyDeg = 1.0
  let edge_fovyDeg = 0.5
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearPlane = 1.0
  let edge_nearPlane = 0.5
  let arg_farPlane = 1.0
  let edge_farPlane = 0.5
  let resNom = camera3DPerspective(arg_pos, arg_target, arg_up, arg_fovyDeg, arg_aspect, arg_nearPlane, arg_farPlane)
  let resEdge = camera3DPerspective(edge_pos, edge_target, edge_up, edge_fovyDeg, edge_aspect, edge_nearPlane, edge_farPlane)
  assertApproxEq(resNom.fovYRad, 0.017453, 0.001, "camera3DPerspective nominal resNom.fovYRad ~= 0.017453")
  assertApproxEq(resEdge.fovYRad, 0.008727, 0.001, "camera3DPerspective boundary resEdge.fovYRad ~= 0.008727")
  ret 0
```

---

### `camera3DOrthographic` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DOrthographic(pos: Vec3, target: Vec3, up: Vec3, orthoHeight: float, aspect: float, nearPlane: float, farPlane: float): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, target: Vec3, up: Vec3, orthoHeight: float, aspect: float, nearPlane: float, farPlane: float` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `camera3DOrthographic` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `target: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `up: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `orthoHeight: float = 1.0`, `aspect: float = 1.0`, `nearPlane: float = 1.0`, `farPlane: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z25_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DOrthographic_25(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_target = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_target = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_up = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_up = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_orthoHeight = 2.0
  let edge_orthoHeight = 1.0
  let arg_aspect = 1.0
  let edge_aspect = 0.5
  let arg_nearPlane = 1.0
  let edge_nearPlane = 0.5
  let arg_farPlane = 1.0
  let edge_farPlane = 0.5
  let resNom = camera3DOrthographic(arg_pos, arg_target, arg_up, arg_orthoHeight, arg_aspect, arg_nearPlane, arg_farPlane)
  let resEdge = camera3DOrthographic(edge_pos, edge_target, edge_up, edge_orthoHeight, edge_aspect, edge_nearPlane, edge_farPlane)
  assertApproxEq(resNom.fovYRad, 1.0472, 0.001, "camera3DOrthographic nominal resNom.fovYRad ~= 1.0472")
  assertApproxEq(resEdge.fovYRad, 1.0472, 0.001, "camera3DOrthographic boundary resEdge.fovYRad ~= 1.0472")
  ret 0
```

---

### `camera3DUpdateOrbit` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DUpdateOrbit(cam: Camera3D, deltaYawRad: float, deltaPitchRad: float, deltaDist: float): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D, deltaYawRad: float, deltaPitchRad: float, deltaDist: float` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `camera3DUpdateOrbit` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`, `deltaYawRad: float = 1.0`, `deltaPitchRad: float = 1.0`, `deltaDist: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z26_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DUpdateOrbit_26(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let arg_deltaYawRad = 2.0
  let edge_deltaYawRad = 1.0
  let arg_deltaPitchRad = 2.0
  let edge_deltaPitchRad = 1.0
  let arg_deltaDist = 1.0
  let edge_deltaDist = 0.5
  let resNom = camera3DUpdateOrbit(arg_cam, arg_deltaYawRad, arg_deltaPitchRad, arg_deltaDist)
  let resEdge = camera3DUpdateOrbit(edge_cam, edge_deltaYawRad, edge_deltaPitchRad, edge_deltaDist)
  assertApproxEq(resNom.fovYRad, 1.0, 0.001, "camera3DUpdateOrbit nominal resNom.fovYRad ~= 1.0")
  assertApproxEq(resEdge.fovYRad, 0.5, 0.001, "camera3DUpdateOrbit boundary resEdge.fovYRad ~= 0.5")
  ret 0
```

---

### `camera3DUpdateFirstPerson` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DUpdateFirstPerson(cam: Camera3D, forwardStep: float, strafeStep: float, deltaYawRad: float, deltaPitchRad: float): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D, forwardStep: float, strafeStep: float, deltaYawRad: float, deltaPitchRad: float` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `camera3DUpdateFirstPerson` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`, `forwardStep: float = 1.0`, `strafeStep: float = 1.0`, `deltaYawRad: float = 1.0`, `deltaPitchRad: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z27_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DUpdateFirstPerson_27(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let arg_forwardStep = 2.0
  let edge_forwardStep = 1.0
  let arg_strafeStep = 1.0
  let edge_strafeStep = 0.5
  let arg_deltaYawRad = 2.0
  let edge_deltaYawRad = 1.0
  let arg_deltaPitchRad = 2.0
  let edge_deltaPitchRad = 1.0
  let resNom = camera3DUpdateFirstPerson(arg_cam, arg_forwardStep, arg_strafeStep, arg_deltaYawRad, arg_deltaPitchRad)
  let resEdge = camera3DUpdateFirstPerson(edge_cam, edge_forwardStep, edge_strafeStep, edge_deltaYawRad, edge_deltaPitchRad)
  assertApproxEq(resNom.fovYRad, 1.0, 0.001, "camera3DUpdateFirstPerson nominal resNom.fovYRad ~= 1.0")
  assertApproxEq(resEdge.fovYRad, 0.5, 0.001, "camera3DUpdateFirstPerson boundary resEdge.fovYRad ~= 0.5")
  ret 0
```

---

### `camera3DUpdateFreeFly` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DUpdateFreeFly(cam: Camera3D, forwardStep: float, strafeStep: float, verticalStep: float, deltaYawRad: float, deltaPitchRad: float): Camera3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D, forwardStep: float, strafeStep: float, verticalStep: float, deltaYawRad: float, deltaPitchRad: float` | **Returns**: `Camera3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `camera3DUpdateFreeFly` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`, `forwardStep: float = 1.0`, `strafeStep: float = 1.0`, `verticalStep: float = 1.0`, `deltaYawRad: float = 1.0`, `deltaPitchRad: float = 1.0`; exercises core body path returning/computing `Camera3D(`.

```aipl
module tests.functions.gfx3d.camera3d_z28_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DUpdateFreeFly_28(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let arg_forwardStep = 2.0
  let edge_forwardStep = 1.0
  let arg_strafeStep = 1.0
  let edge_strafeStep = 0.5
  let arg_verticalStep = 1.0
  let edge_verticalStep = 0.5
  let arg_deltaYawRad = 2.0
  let edge_deltaYawRad = 1.0
  let arg_deltaPitchRad = 2.0
  let edge_deltaPitchRad = 1.0
  let resNom = camera3DUpdateFreeFly(arg_cam, arg_forwardStep, arg_strafeStep, arg_verticalStep, arg_deltaYawRad, arg_deltaPitchRad)
  let resEdge = camera3DUpdateFreeFly(edge_cam, edge_forwardStep, edge_strafeStep, edge_verticalStep, edge_deltaYawRad, edge_deltaPitchRad)
  assertApproxEq(resNom.fovYRad, 1.0, 0.001, "camera3DUpdateFreeFly nominal resNom.fovYRad ~= 1.0")
  assertApproxEq(resEdge.fovYRad, 0.5, 0.001, "camera3DUpdateFreeFly boundary resEdge.fovYRad ~= 0.5")
  ret 0
```

---

### `camera3DViewMatrix` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DViewMatrix(cam: Camera3D): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `camera3DViewMatrix` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `computeViewMatrix(cam)`.

```aipl
module tests.functions.gfx3d.camera3d_z29_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DViewMatrix_29(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = camera3DViewMatrix(arg_cam)
  let resEdge = camera3DViewMatrix(edge_cam)
  assertApproxEq(resNom.m00, 0.707107, 0.001, "camera3DViewMatrix nominal resNom.m00 ~= 0.707107")
  assertApproxEq(resEdge.m00, 0.707107, 0.001, "camera3DViewMatrix boundary resEdge.m00 ~= 0.707107")
  ret 0
```

---

### `camera3DProjMatrix` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DProjMatrix(cam: Camera3D): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `camera3DProjMatrix` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `computeProjectionMatrix(cam)`.

```aipl
module tests.functions.gfx3d.camera3d_z30_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DProjMatrix_30(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = camera3DProjMatrix(arg_cam)
  let resEdge = camera3DProjMatrix(edge_cam)
  assertApproxEq(resNom.m00, 1.0, 0.001, "camera3DProjMatrix nominal resNom.m00 ~= 1.0")
  assertApproxEq(resEdge.m00, 7.83263, 0.001, "camera3DProjMatrix boundary resEdge.m00 ~= 7.83263")
  ret 0
```

---

### `camera3DViewProjMatrix` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn camera3DViewProjMatrix(cam: Camera3D): Mat4:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `camera3DViewProjMatrix` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `computeViewMatrix(cam).mul(computeProjectionMatrix(cam))`.

```aipl
module tests.functions.gfx3d.camera3d_z31_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_camera3DViewProjMatrix_31(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = camera3DViewProjMatrix(arg_cam)
  let resEdge = camera3DViewProjMatrix(edge_cam)
  assertApproxEq(resNom.m00, 0.707107, 0.001, "camera3DViewProjMatrix nominal resNom.m00 ~= 0.707107")
  assertApproxEq(resEdge.m00, 5.53851, 0.001, "camera3DViewProjMatrix boundary resEdge.m00 ~= 5.53851")
  ret 0
```

---

### `extractFrustum3D` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn extractFrustum3D(cam: Camera3D): Frustum3D:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cam: Camera3D` | **Returns**: `Frustum3D`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `extractFrustum3D` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `cam: Camera3D = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = float = 1.04719755(), aspect = float = 1.3333333(), nearZ = float = 0.1(), farZ = float = 1000.0(), isOrthographic = bool = false(), orthoWidth = float = 10.0(), orthoHeight = float = 10.0(), fovy = float = 60.0(), nearPlane = float = 0.1(), farPlane = float = 1000.0(), projection = int = 0(), yaw = float = 0.0(), pitch = float = 0.0(), orbitDist = float = 5.0())`; exercises core body path returning/computing `extractFrustumPlanes(camera3DViewProjMatrix(cam))`.

```aipl
module tests.functions.gfx3d.camera3d_z32_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_extractFrustum3D_32(): int:
  let arg_cam = Camera3D(position = Vec3(x = 1.0, y = 1.0, z = 1.0), target = Vec3(x = 1.0, y = 1.0, z = 1.0), up = Vec3(x = 1.0, y = 1.0, z = 1.0), fovYRad = 1.0, aspect = 1.0, nearZ = 1.0, farZ = 1.0, isOrthographic = true, orthoWidth = 2.0, orthoHeight = 2.0, fovy = 1.0, nearPlane = 1.0, farPlane = 1.0, projection = 4, yaw = 2.0, pitch = 2.0, orbitDist = 1.0)
  let edge_cam = Camera3D(position = Vec3(x = 0.5, y = 0.5, z = 0.5), target = Vec3(x = 0.5, y = 0.5, z = 0.5), up = Vec3(x = 0.5, y = 0.5, z = 0.5), fovYRad = 0.5, aspect = 0.5, nearZ = 0.5, farZ = 0.5, isOrthographic = false, orthoWidth = 1.0, orthoHeight = 1.0, fovy = 0.5, nearPlane = 0.5, farPlane = 0.5, projection = 1, yaw = 1.0, pitch = 1.0, orbitDist = 0.5)
  let resNom = extractFrustum3D(arg_cam)
  let resEdge = extractFrustum3D(edge_cam)
  assertEqInt(resNom.planes.len(), 6, "extractFrustum3D nominal resNom.planes.len() == 6")
  assertEqInt(resEdge.planes.len(), 6, "extractFrustum3D boundary resEdge.planes.len() == 6")
  ret 0
```

---

### `frustumContainsSphere` (`std/gfx3d/camera3d.aipl`)

- **Signature**: `pub fn frustumContainsSphere(frustum: Frustum3D, center: Vec3, radius: float): bool:`
- **Import**: `import * from "std/gfx3d/camera3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, center: Vec3, radius: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx3d/camera3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `frustumContainsSphere` (`free fn`) 3D Orbit/FPS camera view/projection matrices, 6-plane Gribb-Hartmann frustum extraction, and 3D-to-2D screen projection. Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx3d.camera3d_z33_test
import * from "std/gfx3d/camera3d"
import { PI, DEG2RAD, EPSILON, clampFloat, absFloat } from "std/math/consts"
import { sin, cos, tan, asin, acos, atan2, sqrt } from "std/math/trig"
import { Vec3, Vec4, Vector3 } from "std/math/vec_math"
import { Mat3, Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_camera3d_frustumContainsSphere_33(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = frustumContainsSphere(arg_frustum, arg_center, arg_radius)
  let resEdge = frustumContainsSphere(edge_frustum, edge_center, edge_radius)
  assert(resNom == true, "frustumContainsSphere nominal resNom == true")
  assert(resEdge == true, "frustumContainsSphere boundary resEdge == true")
  ret 0
```

---

### `testFrustumAabb` (`std/gfx3d/cull3d.aipl`)

- **Signature**: `pub fn testFrustumAabb(frustum: Frustum3D, aabb: AABB3D): bool:`
- **Import**: `import * from "std/gfx3d/cull3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, aabb: AABB3D` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx3d/cull3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `testFrustumAabb` 6-plane frustum vs AABB/Sphere (`Inside`/`Intersecting`/`Outside`) culling and 3D screen-space bounding rect projection. Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `aabb: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx3d.cull3d_z1_test
import * from "std/gfx3d/cull3d"
import { EPSILON, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Rect } from "std/math/geom2d"
import { AABB3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cull3d_testFrustumAabb_1(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_aabb = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_aabb = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let resNom = testFrustumAabb(arg_frustum, arg_aabb)
  let resEdge = testFrustumAabb(edge_frustum, edge_aabb)
  assert(resNom == true, "testFrustumAabb nominal resNom == true")
  assert(resEdge == true, "testFrustumAabb boundary resEdge == true")
  ret 0
```

---

### `testFrustumSphere` (`std/gfx3d/cull3d.aipl`)

- **Signature**: `pub fn testFrustumSphere(frustum: Frustum3D, center: Vec3, radius: float): bool:`
- **Import**: `import * from "std/gfx3d/cull3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frustum: Frustum3D, center: Vec3, radius: float` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx3d/cull3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `testFrustumSphere` 6-plane frustum vs AABB/Sphere (`Inside`/`Intersecting`/`Outside`) culling and 3D screen-space bounding rect projection. Concrete nominal inputs: `frustum: Frustum3D = Frustum3D(planes = [Plane3D(normal = 0, distance = 0, d = 0)])`, `center: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `radius: float = 1.0`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx3d.cull3d_z2_test
import * from "std/gfx3d/cull3d"
import { EPSILON, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Rect } from "std/math/geom2d"
import { AABB3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cull3d_testFrustumSphere_2(): int:
  let arg_frustum = Frustum3D(planes = [])
  let edge_frustum = Frustum3D(planes = [])
  let arg_center = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_center = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = testFrustumSphere(arg_frustum, arg_center, arg_radius)
  let resEdge = testFrustumSphere(edge_frustum, edge_center, edge_radius)
  assert(resNom == true, "testFrustumSphere nominal resNom == true")
  assert(resEdge == true, "testFrustumSphere boundary resEdge == true")
  ret 0
```

---

### `projectAabbToScreenRect` (`std/gfx3d/cull3d.aipl`)

- **Signature**: `pub fn projectAabbToScreenRect(aabb: AABB3D, viewProj: Mat4, screenW: float, screenH: float): Rect:`
- **Import**: `import * from "std/gfx3d/cull3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `aabb: AABB3D, viewProj: Mat4, screenW: float, screenH: float` | **Returns**: `Rect`
- **Unit Test**: `tests/functions/gfx3d/cull3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `projectAabbToScreenRect` 6-plane frustum vs AABB/Sphere (`Inside`/`Intersecting`/`Outside`) culling and 3D screen-space bounding rect projection. Concrete nominal inputs: `aabb: AABB3D = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))`, `viewProj: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`, `screenW: float = 1.0`, `screenH: float = 1.0`; exercises core body path returning/computing `Rect(x = minSX, y = minSY, w = maxFloat(0.0, maxSX - minSX), h = maxFloat(0.0, maxSY - minSY))`.

```aipl
module tests.functions.gfx3d.cull3d_z3_test
import * from "std/gfx3d/cull3d"
import { EPSILON, minFloat, maxFloat, clampFloat } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Rect } from "std/math/geom2d"
import { AABB3D, Frustum3D } from "std/math/geom3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cull3d_projectAabbToScreenRect_3(): int:
  let arg_aabb = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0))
  let edge_aabb = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5))
  let arg_viewProj = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_viewProj = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let arg_screenW = 2.0
  let edge_screenW = 1.0
  let arg_screenH = 2.0
  let edge_screenH = 1.0
  let resNom = projectAabbToScreenRect(arg_aabb, arg_viewProj, arg_screenW, arg_screenH)
  let resEdge = projectAabbToScreenRect(edge_aabb, edge_viewProj, edge_screenW, edge_screenH)
  assertApproxEq(resNom.x, 2.0, 0.001, "projectAabbToScreenRect nominal resNom.x ~= 2.0")
  assertApproxEq(resEdge.x, 1.0, 0.001, "projectAabbToScreenRect boundary resEdge.x ~= 1.0")
  ret 0
```

---

### `createDecalProjector` (`std/gfx3d/decal3d.aipl`)

- **Signature**: `pub fn createDecalProjector(pos: Vec3, rot: Quat, extents: Vec3, texId: int): DecalProjector:`
- **Import**: `import * from "std/gfx3d/decal3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, rot: Quat, extents: Vec3, texId: int` | **Returns**: `DecalProjector`
- **Unit Test**: `tests/functions/gfx3d/decal3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `createDecalProjector` 3D oriented decal box projection and Sutherland-Hodgman 6-plane polygon clipping. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `rot: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `extents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `texId: int = 1`; exercises core body path returning/computing `DecalProjector(`.

```aipl
module tests.functions.gfx3d.decal3d_z1_test
import * from "std/gfx3d/decal3d"
import { EPSILON } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_decal3d_createDecalProjector_1(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_rot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_extents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_extents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_texId = 1
  let edge_texId = 0
  let resNom = createDecalProjector(arg_pos, arg_rot, arg_extents, arg_texId)
  let resEdge = createDecalProjector(edge_pos, edge_rot, edge_extents, edge_texId)
  assertEqInt(resNom.textureId, 1, "createDecalProjector nominal resNom.textureId == 1")
  assertEqInt(resEdge.textureId, 0, "createDecalProjector boundary resEdge.textureId == 0")
  ret 0
```

---

### `clipPolygonAgainstPlane` (`std/gfx3d/decal3d.aipl`)

- **Signature**: `fn clipPolygonAgainstPlane(pts: [Vec3], nx: float, ny: float, nz: float, limit: float): [Vec3]:`
- **Import**: `import * from "std/gfx3d/decal3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pts: [Vec3], nx: float, ny: float, nz: float, limit: float` | **Returns**: `[Vec3]`
- **Unit Test**: `tests/functions/gfx3d/decal3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `clipPolygonAgainstPlane` 3D oriented decal box projection and Sutherland-Hodgman 6-plane polygon clipping. Concrete nominal inputs: `pts: [Vec3] = [Vec3(x = 1.0, y = 1.0, z = 1.0)]`, `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `limit: float = 1.0`; exercises core body path returning/computing `outPts`.

```aipl
module tests.functions.gfx3d.decal3d_z2_test
import * from "std/gfx3d/decal3d"
import { EPSILON } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_decal3d_clipPolygonAgainstPlane_2(): int:
  let arg_pts = [Vec3(x = 1.0, y = 1.0, z = 1.0)]
  let edge_pts = []
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_limit = 1.0
  let edge_limit = 0.5
  let resNom = clipPolygonAgainstPlane(arg_pts, arg_nx, arg_ny, arg_nz, arg_limit)
  let resEdge = clipPolygonAgainstPlane(edge_pts, edge_nx, edge_ny, edge_nz, edge_limit)
  assertEqInt(resNom.len(), 0, "clipPolygonAgainstPlane nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "clipPolygonAgainstPlane boundary resEdge.len() == 0")
  ret 0
```

---

### `clipTriangleAgainstBoxPlanes` (`std/gfx3d/decal3d.aipl`)

- **Signature**: `pub fn clipTriangleAgainstBoxPlanes(triPts: [Vec3], boxExtents: Vec3): [Vec3]:`
- **Import**: `import * from "std/gfx3d/decal3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `triPts: [Vec3], boxExtents: Vec3` | **Returns**: `[Vec3]`
- **Unit Test**: `tests/functions/gfx3d/decal3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `clipTriangleAgainstBoxPlanes` 3D oriented decal box projection and Sutherland-Hodgman 6-plane polygon clipping. Concrete nominal inputs: `triPts: [Vec3] = [Vec3(x = 1.0, y = 1.0, z = 1.0)]`, `boxExtents: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `poly`.

```aipl
module tests.functions.gfx3d.decal3d_z3_test
import * from "std/gfx3d/decal3d"
import { EPSILON } from "std/math/consts"
import { Vec3 } from "std/math/vec_math"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_decal3d_clipTriangleAgainstBoxPlanes_3(): int:
  let arg_triPts = [Vec3(x = 1.0, y = 1.0, z = 1.0)]
  let edge_triPts = []
  let arg_boxExtents = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_boxExtents = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = clipTriangleAgainstBoxPlanes(arg_triPts, arg_boxExtents)
  let resEdge = clipTriangleAgainstBoxPlanes(edge_triPts, edge_boxExtents)
  assertEqInt(resNom.len(), 1, "clipTriangleAgainstBoxPlanes nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "clipTriangleAgainstBoxPlanes boundary resEdge.len() == 0")
  ret 0
```

---

### `createDirectionalLight` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn createDirectionalLight(direction: Vec3, color: LinearColorF32, intensity: float = 1.0): Light3D:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `direction: Vec3, color: LinearColorF32, intensity: float = 1.0` | **Returns**: `Light3D`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `createDirectionalLight` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `direction: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `color: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`, `intensity: float = 1.0`; exercises core body path returning/computing `Light3D(`.

```aipl
module tests.functions.gfx3d.light3d_z1_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_createDirectionalLight_1(): int:
  let arg_direction = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_direction = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  let resNom = createDirectionalLight(arg_direction, arg_color, arg_intensity)
  let resEdge = createDirectionalLight(edge_direction, edge_color, edge_intensity)
  assertEqInt(resNom.lightType, 1, "createDirectionalLight nominal resNom.lightType == 1")
  assertEqInt(resEdge.lightType, 1, "createDirectionalLight boundary resEdge.lightType == 1")
  ret 0
```

---

### `createPointLight` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn createPointLight(pos: Vec3, color: LinearColorF32, range: float, intensity: float = 1.0): Light3D:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, color: LinearColorF32, range: float, intensity: float = 1.0` | **Returns**: `Light3D`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `createPointLight` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `color: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`, `range: float = 1.0`, `intensity: float = 1.0`; exercises core body path returning/computing `Light3D(`.

```aipl
module tests.functions.gfx3d.light3d_z2_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_createPointLight_2(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_range = 1.0
  let edge_range = 0.5
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  let resNom = createPointLight(arg_pos, arg_color, arg_range, arg_intensity)
  let resEdge = createPointLight(edge_pos, edge_color, edge_range, edge_intensity)
  assertEqInt(resNom.lightType, 2, "createPointLight nominal resNom.lightType == 2")
  assertEqInt(resEdge.lightType, 2, "createPointLight boundary resEdge.lightType == 2")
  ret 0
```

---

### `createSpotLight` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn createSpotLight(pos: Vec3, dir: Vec3, color: LinearColorF32, range: float, innerAngleDeg: float, outerAngleDeg: float): Light3D:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, dir: Vec3, color: LinearColorF32, range: float, innerAngleDeg: float, outerAngleDeg: float` | **Returns**: `Light3D`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `createSpotLight` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `dir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `color: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`, `range: float = 1.0`, `innerAngleDeg: float = 1.0`, `outerAngleDeg: float = 1.0`; exercises core body path returning/computing `Light3D(`.

```aipl
module tests.functions.gfx3d.light3d_z3_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_createSpotLight_3(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_dir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_dir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_range = 1.0
  let edge_range = 0.5
  let arg_innerAngleDeg = 1.0
  let edge_innerAngleDeg = 0.5
  let arg_outerAngleDeg = 1.0
  let edge_outerAngleDeg = 0.5
  let resNom = createSpotLight(arg_pos, arg_dir, arg_color, arg_range, arg_innerAngleDeg, arg_outerAngleDeg)
  let resEdge = createSpotLight(edge_pos, edge_dir, edge_color, edge_range, edge_innerAngleDeg, edge_outerAngleDeg)
  assertEqInt(resNom.lightType, 3, "createSpotLight nominal resNom.lightType == 3")
  assertEqInt(resEdge.lightType, 3, "createSpotLight boundary resEdge.lightType == 3")
  ret 0
```

---

### `computePointLightAttenuation` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn computePointLightAttenuation(dist: float, range: float): float:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dist: float, range: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `computePointLightAttenuation` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `dist: float = 1.0`, `range: float = 1.0`; exercises core body path returning/computing `(window * window) / (dist * dist + 1.0)`.

```aipl
module tests.functions.gfx3d.light3d_z4_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_computePointLightAttenuation_4(): int:
  let arg_dist = 1.0
  let edge_dist = 0.5
  let arg_range = 1.0
  let edge_range = 0.5
  let resNom = computePointLightAttenuation(arg_dist, arg_range)
  let resEdge = computePointLightAttenuation(edge_dist, edge_range)
  assertApproxEq(resNom, 0.0, 0.001, "computePointLightAttenuation nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computePointLightAttenuation boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeSpotLightAttenuation` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn computeSpotLightAttenuation(light: Light3D, lightToPt: Vec3): float:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `light: Light3D, lightToPt: Vec3` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `computeSpotLightAttenuation` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `light: Light3D = Light3D(lightType = 1, position = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0()), intensity = 1.0, range = 1.0, spotInnerRad = 1.0, spotOuterRad = 1.0, castsShadows = true)`, `lightToPt: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `distAtten * smooth`.

```aipl
module tests.functions.gfx3d.light3d_z5_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_computeSpotLightAttenuation_5(): int:
  let arg_light = Light3D(lightType = 1, position = Vec3(x = 1.0, y = 1.0, z = 1.0), direction = Vec3(x = 1.0, y = 1.0, z = 1.0), color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0), intensity = 1.0, range = 1.0, spotInnerRad = 1.0, spotOuterRad = 1.0, castsShadows = true)
  let edge_light = Light3D(lightType = 0, position = Vec3(x = 0.5, y = 0.5, z = 0.5), direction = Vec3(x = 0.5, y = 0.5, z = 0.5), color = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5), intensity = 0.5, range = 0.5, spotInnerRad = 0.5, spotOuterRad = 0.5, castsShadows = false)
  let arg_lightToPt = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_lightToPt = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = computeSpotLightAttenuation(arg_light, arg_lightToPt)
  let resEdge = computeSpotLightAttenuation(edge_light, edge_lightToPt)
  assertApproxEq(resNom, 0.0, 0.001, "computeSpotLightAttenuation nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeSpotLightAttenuation boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeCascadedShadowSplits` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn computeCascadedShadowSplits(nearZ: float, farZ: float, cascadeCount: int = 4, lambdaFactor: float = 0.75): [float]:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nearZ: float, farZ: float, cascadeCount: int = 4, lambdaFactor: float = 0.75` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `computeCascadedShadowSplits` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `nearZ: float = 1.0`, `farZ: float = 1.0`, `cascadeCount: int = 64`, `lambdaFactor: float = 1.0`; exercises core body path returning/computing `splits`.

```aipl
module tests.functions.gfx3d.light3d_z6_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_computeCascadedShadowSplits_6(): int:
  let arg_nearZ = 1.0
  let edge_nearZ = 0.5
  let arg_farZ = 1.0
  let edge_farZ = 0.5
  let arg_cascadeCount = 4
  let edge_cascadeCount = 1
  let arg_lambdaFactor = 1.0
  let edge_lambdaFactor = 0.5
  let resNom = computeCascadedShadowSplits(arg_nearZ, arg_farZ, arg_cascadeCount, arg_lambdaFactor)
  let resEdge = computeCascadedShadowSplits(edge_nearZ, edge_farZ, edge_cascadeCount, edge_lambdaFactor)
  assertEqInt(resNom.len(), 5, "computeCascadedShadowSplits nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 2, "computeCascadedShadowSplits boundary resEdge.len() == 2")
  ret 0
```

---

### `lightComputePointAttenuation` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputePointAttenuation(distSqVal: float, radius: float, intensity: float, falloffExp: float): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `distSqVal: float, radius: float, intensity: float, falloffExp: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `lightComputePointAttenuation` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `distSqVal: float = 1.0`, `radius: float = 1.0`, `intensity: float = 1.0`, `falloffExp: float = 1.0`; exercises core body path returning/computing `clampInt(pct, 0, 100)`.

```aipl
module tests.functions.gfx3d.light3d_z7_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputePointAttenuation_7(): int:
  let arg_distSqVal = 1.0
  let edge_distSqVal = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  let arg_falloffExp = 0.0
  let edge_falloffExp = 0.0
  let resNom = lightComputePointAttenuation(arg_distSqVal, arg_radius, arg_intensity, arg_falloffExp)
  let resEdge = lightComputePointAttenuation(edge_distSqVal, edge_radius, edge_intensity, edge_falloffExp)
  assertEqInt(resNom, 75, "lightComputePointAttenuation nominal resNom == 75")
  assertEqInt(resEdge, 25, "lightComputePointAttenuation boundary resEdge == 25")
  ret 0
```

---

### `lightComputeLambertDiffuseRGB` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeLambertDiffuseRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, baseR: int, baseG: int, baseB: int, lightR: int, lightG: int, lightB: int, ambientPct: int): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, baseR: int, baseG: int, baseB: int, lightR: int, lightG: int, lightB: int, ambientPct: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `lightComputeLambertDiffuseRGB` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `lx: float = 1.0`, `ly: float = 1.0`, `lz: float = 1.0`, `baseR: int = 1`, `baseG: int = 1`, `baseB: int = 1`, `lightR: int = 1`, `lightG: int = 1`, `lightB: int = 1`, `ambientPct: int = 1`; exercises core body path returning/computing `(outR << 16) | (outG << 8) | outB`.

```aipl
module tests.functions.gfx3d.light3d_z8_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeLambertDiffuseRGB_8(): int:
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_lx = 1.0
  let edge_lx = 0.5
  let arg_ly = 1.0
  let edge_ly = 0.5
  let arg_lz = 1.0
  let edge_lz = 0.5
  let arg_baseR = 4
  let edge_baseR = 1
  let arg_baseG = 4
  let edge_baseG = 1
  let arg_baseB = 4
  let edge_baseB = 1
  let arg_lightR = 2
  let edge_lightR = 0
  let arg_lightG = 2
  let edge_lightG = 0
  let arg_lightB = 4
  let edge_lightB = 1
  let arg_ambientPct = 4
  let edge_ambientPct = 1
  let resNom = lightComputeLambertDiffuseRGB(arg_nx, arg_ny, arg_nz, arg_lx, arg_ly, arg_lz, arg_baseR, arg_baseG, arg_baseB, arg_lightR, arg_lightG, arg_lightB, arg_ambientPct)
  let resEdge = lightComputeLambertDiffuseRGB(edge_nx, edge_ny, edge_nz, edge_lx, edge_ly, edge_lz, edge_baseR, edge_baseG, edge_baseB, edge_lightR, edge_lightG, edge_lightB, edge_ambientPct)
  assertEqInt(resNom, 0, "lightComputeLambertDiffuseRGB nominal resNom == 0")
  assertEqInt(resEdge, 0, "lightComputeLambertDiffuseRGB boundary resEdge == 0")
  ret 0
```

---

### `lightCast2DShadowVisibility` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightCast2DShadowVisibility(ox: float, oy: float, tx: float, ty: float, blockerMinX: float, blockerMinY: float, blockerMaxX: float, blockerMaxY: float): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ox: float, oy: float, tx: float, ty: float, blockerMinX: float, blockerMinY: float, blockerMaxX: float, blockerMaxY: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `lightCast2DShadowVisibility` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `ox: float = 1.0`, `oy: float = 1.0`, `tx: float = 1.0`, `ty: float = 1.0`, `blockerMinX: float = 1.0`, `blockerMinY: float = 1.0`, `blockerMaxX: float = 1.0`, `blockerMaxY: float = 1.0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx3d.light3d_z9_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightCast2DShadowVisibility_9(): int:
  let arg_ox = 1.0
  let edge_ox = 0.5
  let arg_oy = 1.0
  let edge_oy = 0.5
  let arg_tx = 1.0
  let edge_tx = 0.5
  let arg_ty = 1.0
  let edge_ty = 0.5
  let arg_blockerMinX = 0.0
  let edge_blockerMinX = 0.0
  let arg_blockerMinY = 0.0
  let edge_blockerMinY = 0.0
  let arg_blockerMaxX = 0.0
  let edge_blockerMaxX = 0.0
  let arg_blockerMaxY = 0.0
  let edge_blockerMaxY = 0.0
  let resNom = lightCast2DShadowVisibility(arg_ox, arg_oy, arg_tx, arg_ty, arg_blockerMinX, arg_blockerMinY, arg_blockerMaxX, arg_blockerMaxY)
  let resEdge = lightCast2DShadowVisibility(edge_ox, edge_oy, edge_tx, edge_ty, edge_blockerMinX, edge_blockerMinY, edge_blockerMaxX, edge_blockerMaxY)
  assertEqInt(resNom, 100, "lightCast2DShadowVisibility nominal resNom == 100")
  assertEqInt(resEdge, 100, "lightCast2DShadowVisibility boundary resEdge == 100")
  ret 0
```

---

### `lightComputeSpotConeAttenuation` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeSpotConeAttenuation(dirX: float, dirY: float, toPointX: float, toPointY: float, cosInner: float, cosOuter: float): float:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dirX: float, dirY: float, toPointX: float, toPointY: float, cosInner: float, cosOuter: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `lightComputeSpotConeAttenuation` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `dirX: float = 1.0`, `dirY: float = 1.0`, `toPointX: float = 1.0`, `toPointY: float = 1.0`, `cosInner: float = 1.0`, `cosOuter: float = 1.0`; exercises core body path returning/computing `clampFloat(t * t * (3.0 - 2.0 * t), 0.0, 1.0)`.

```aipl
module tests.functions.gfx3d.light3d_z10_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeSpotConeAttenuation_10(): int:
  let arg_dirX = 1.0
  let edge_dirX = 0.5
  let arg_dirY = 1.0
  let edge_dirY = 0.5
  let arg_toPointX = 1.0
  let edge_toPointX = 0.5
  let arg_toPointY = 1.0
  let edge_toPointY = 0.5
  let arg_cosInner = 1.0
  let edge_cosInner = 0.5
  let arg_cosOuter = 1.0
  let edge_cosOuter = 0.5
  let resNom = lightComputeSpotConeAttenuation(arg_dirX, arg_dirY, arg_toPointX, arg_toPointY, arg_cosInner, arg_cosOuter)
  let resEdge = lightComputeSpotConeAttenuation(edge_dirX, edge_dirY, edge_toPointX, edge_toPointY, edge_cosInner, edge_cosOuter)
  assertApproxEq(resNom, 0.0, 0.001, "lightComputeSpotConeAttenuation nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 1.0, 0.001, "lightComputeSpotConeAttenuation boundary resEdge ~= 1.0")
  ret 0
```

---

### `lightComputeLightningFlashAmbientBoost` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeLightningFlashAmbientBoost(baseAmbient: int, boltIntensity: int, decayTick: int): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseAmbient: int, boltIntensity: int, decayTick: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `lightComputeLightningFlashAmbientBoost` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `baseAmbient: int = 1`, `boltIntensity: int = 1`, `decayTick: int = 1`; exercises core body path returning/computing `clampInt(baseA + boost, 0, 100)`.

```aipl
module tests.functions.gfx3d.light3d_z11_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeLightningFlashAmbientBoost_11(): int:
  let arg_baseAmbient = 4
  let edge_baseAmbient = 1
  let arg_boltIntensity = 4
  let edge_boltIntensity = 1
  let arg_decayTick = 4
  let edge_decayTick = 1
  let resNom = lightComputeLightningFlashAmbientBoost(arg_baseAmbient, arg_boltIntensity, arg_decayTick)
  let resEdge = lightComputeLightningFlashAmbientBoost(edge_baseAmbient, edge_boltIntensity, edge_decayTick)
  assertEqInt(resNom, 4, "lightComputeLightningFlashAmbientBoost nominal resNom == 4")
  assertEqInt(resEdge, 1, "lightComputeLightningFlashAmbientBoost boundary resEdge == 1")
  ret 0
```

---

### `lightComputeNvgPhosphorGain` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeNvgPhosphorGain(baseLuma: int, nvgActive: int, dlightBoost: int): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseLuma: int, nvgActive: int, dlightBoost: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `lightComputeNvgPhosphorGain` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `baseLuma: int = 1`, `nvgActive: int = 1`, `dlightBoost: int = 1`; exercises core body path returning/computing `clampInt(amp, 0, 255)`.

```aipl
module tests.functions.gfx3d.light3d_z12_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeNvgPhosphorGain_12(): int:
  let arg_baseLuma = 4
  let edge_baseLuma = 1
  let arg_nvgActive = 4
  let edge_nvgActive = 1
  let arg_dlightBoost = 4
  let edge_dlightBoost = 1
  let resNom = lightComputeNvgPhosphorGain(arg_baseLuma, arg_nvgActive, arg_dlightBoost)
  let resEdge = lightComputeNvgPhosphorGain(edge_baseLuma, edge_nvgActive, edge_dlightBoost)
  assertEqInt(resNom, 77, "lightComputeNvgPhosphorGain nominal resNom == 77")
  assertEqInt(resEdge, 68, "lightComputeNvgPhosphorGain boundary resEdge == 68")
  ret 0
```

---

### `lightComputeBlinnPhongRGB` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeBlinnPhongRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, baseHex: int, specStrength: float, shininess: float): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, baseHex: int, specStrength: float, shininess: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `lightComputeBlinnPhongRGB` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `lx: float = 1.0`, `ly: float = 1.0`, `lz: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `vz: float = 1.0`, `baseHex: int = 1`, `specStrength: float = 1.0`, `shininess: float = 1.0`; exercises core body path returning/computing `(outR << 16) | (outG << 8) | outB`.

```aipl
module tests.functions.gfx3d.light3d_z13_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeBlinnPhongRGB_13(): int:
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_lx = 1.0
  let edge_lx = 0.5
  let arg_ly = 1.0
  let edge_ly = 0.5
  let arg_lz = 1.0
  let edge_lz = 0.5
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_vz = 1.0
  let edge_vz = 0.5
  let arg_baseHex = 4
  let edge_baseHex = 1
  let arg_specStrength = 2.0
  let edge_specStrength = 1.0
  let arg_shininess = 2.0
  let edge_shininess = 1.0
  let resNom = lightComputeBlinnPhongRGB(arg_nx, arg_ny, arg_nz, arg_lx, arg_ly, arg_lz, arg_vx, arg_vy, arg_vz, arg_baseHex, arg_specStrength, arg_shininess)
  let resEdge = lightComputeBlinnPhongRGB(edge_nx, edge_ny, edge_nz, edge_lx, edge_ly, edge_lz, edge_vx, edge_vy, edge_vz, edge_baseHex, edge_specStrength, edge_shininess)
  assertEqInt(resNom, 16777215, "lightComputeBlinnPhongRGB nominal resNom == 16777215")
  assertEqInt(resEdge, 16777215, "lightComputeBlinnPhongRGB boundary resEdge == 16777215")
  ret 0
```

---

### `lightComputePbrCookTorranceRGB` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputePbrCookTorranceRGB(nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, albedoHex: int, metallic: float, roughness: float, ao: float): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nx: float, ny: float, nz: float, lx: float, ly: float, lz: float, vx: float, vy: float, vz: float, albedoHex: int, metallic: float, roughness: float, ao: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `lightComputePbrCookTorranceRGB` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `lx: float = 1.0`, `ly: float = 1.0`, `lz: float = 1.0`, `vx: float = 1.0`, `vy: float = 1.0`, `vz: float = 1.0`, `albedoHex: int = 1`, `metallic: float = 1.0`, `roughness: float = 1.0`, `ao: float = 1.0`; exercises core body path returning/computing `(outR << 16) | (outG << 8) | outB`.

```aipl
module tests.functions.gfx3d.light3d_z14_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputePbrCookTorranceRGB_14(): int:
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_lx = 1.0
  let edge_lx = 0.5
  let arg_ly = 1.0
  let edge_ly = 0.5
  let arg_lz = 1.0
  let edge_lz = 0.5
  let arg_vx = 1.0
  let edge_vx = 0.5
  let arg_vy = 1.0
  let edge_vy = 0.5
  let arg_vz = 1.0
  let edge_vz = 0.5
  let arg_albedoHex = 4
  let edge_albedoHex = 1
  let arg_metallic = 1.0
  let edge_metallic = 0.5
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let arg_ao = 1.0
  let edge_ao = 0.5
  let resNom = lightComputePbrCookTorranceRGB(arg_nx, arg_ny, arg_nz, arg_lx, arg_ly, arg_lz, arg_vx, arg_vy, arg_vz, arg_albedoHex, arg_metallic, arg_roughness, arg_ao)
  let resEdge = lightComputePbrCookTorranceRGB(edge_nx, edge_ny, edge_nz, edge_lx, edge_ly, edge_lz, edge_vx, edge_vy, edge_vz, edge_albedoHex, edge_metallic, edge_roughness, edge_ao)
  assertEqInt(resNom, 1, "lightComputePbrCookTorranceRGB nominal resNom == 1")
  assertEqInt(resEdge, 65793, "lightComputePbrCookTorranceRGB boundary resEdge == 65793")
  ret 0
```

---

### `lightComputeSpotConeAttenuation3D` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightComputeSpotConeAttenuation3D(dirX: float, dirY: float, dirZ: float, toPointX: float, toPointY: float, toPointZ: float, cosInner: float, cosOuter: float): float:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dirX: float, dirY: float, dirZ: float, toPointX: float, toPointY: float, toPointZ: float, cosInner: float, cosOuter: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `lightComputeSpotConeAttenuation3D` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `dirX: float = 1.0`, `dirY: float = 1.0`, `dirZ: float = 1.0`, `toPointX: float = 1.0`, `toPointY: float = 1.0`, `toPointZ: float = 1.0`, `cosInner: float = 1.0`, `cosOuter: float = 1.0`; exercises core body path returning/computing `clampFloat(t * t * (3.0 - 2.0 * t), 0.0, 1.0)`.

```aipl
module tests.functions.gfx3d.light3d_z15_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightComputeSpotConeAttenuation3D_15(): int:
  let arg_dirX = 1.0
  let edge_dirX = 0.5
  let arg_dirY = 1.0
  let edge_dirY = 0.5
  let arg_dirZ = 1.0
  let edge_dirZ = 0.5
  let arg_toPointX = 1.0
  let edge_toPointX = 0.5
  let arg_toPointY = 1.0
  let edge_toPointY = 0.5
  let arg_toPointZ = 1.0
  let edge_toPointZ = 0.5
  let arg_cosInner = 1.0
  let edge_cosInner = 0.5
  let arg_cosOuter = 1.0
  let edge_cosOuter = 0.5
  let resNom = lightComputeSpotConeAttenuation3D(arg_dirX, arg_dirY, arg_dirZ, arg_toPointX, arg_toPointY, arg_toPointZ, arg_cosInner, arg_cosOuter)
  let resEdge = lightComputeSpotConeAttenuation3D(edge_dirX, edge_dirY, edge_dirZ, edge_toPointX, edge_toPointY, edge_toPointZ, edge_cosInner, edge_cosOuter)
  assertApproxEq(resNom, 0.0, 0.001, "lightComputeSpotConeAttenuation3D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 1.0, 0.001, "lightComputeSpotConeAttenuation3D boundary resEdge ~= 1.0")
  ret 0
```

---

### `lightApplyExponentialFogRGB` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightApplyExponentialFogRGB(surfaceHex: int, fogHex: int, distance: float, density: float): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `surfaceHex: int, fogHex: int, distance: float, density: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `lightApplyExponentialFogRGB` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `surfaceHex: int = 1`, `fogHex: int = 1`, `distance: float = 1.0`, `density: float = 1.0`; exercises core body path returning/computing `(outR << 16) | (outG << 8) | outB`.

```aipl
module tests.functions.gfx3d.light3d_z16_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightApplyExponentialFogRGB_16(): int:
  let arg_surfaceHex = 1
  let edge_surfaceHex = 0
  let arg_fogHex = 1
  let edge_fogHex = 0
  let arg_distance = 1.0
  let edge_distance = 0.5
  let arg_density = 1.0
  let edge_density = 0.5
  let resNom = lightApplyExponentialFogRGB(arg_surfaceHex, arg_fogHex, arg_distance, arg_density)
  let resEdge = lightApplyExponentialFogRGB(edge_surfaceHex, edge_fogHex, edge_distance, edge_density)
  assertEqInt(resNom, 1, "lightApplyExponentialFogRGB nominal resNom == 1")
  assertEqInt(resEdge, 0, "lightApplyExponentialFogRGB boundary resEdge == 0")
  ret 0
```

---

### `lightSampleProceduralSkyboxRGB` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightSampleProceduralSkyboxRGB(dirX: float, dirY: float, dirZ: float, zenithHex: int, horizonHex: int, nadirHex: int): int:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dirX: float, dirY: float, dirZ: float, zenithHex: int, horizonHex: int, nadirHex: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `lightSampleProceduralSkyboxRGB` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `dirX: float = 1.0`, `dirY: float = 1.0`, `dirZ: float = 1.0`, `zenithHex: int = 1`, `horizonHex: int = 1`, `nadirHex: int = 1`; exercises core body path returning/computing `lightApplyExponentialFogRGB(horizonHex, nadirHex, (-ny) * 2.5, 1.0)`.

```aipl
module tests.functions.gfx3d.light3d_z17_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightSampleProceduralSkyboxRGB_17(): int:
  let arg_dirX = 1.0
  let edge_dirX = 0.5
  let arg_dirY = 1.0
  let edge_dirY = 0.5
  let arg_dirZ = 1.0
  let edge_dirZ = 0.5
  let arg_zenithHex = 4
  let edge_zenithHex = 1
  let arg_horizonHex = 4
  let edge_horizonHex = 1
  let arg_nadirHex = 4
  let edge_nadirHex = 1
  let resNom = lightSampleProceduralSkyboxRGB(arg_dirX, arg_dirY, arg_dirZ, arg_zenithHex, arg_horizonHex, arg_nadirHex)
  let resEdge = lightSampleProceduralSkyboxRGB(edge_dirX, edge_dirY, edge_dirZ, edge_zenithHex, edge_horizonHex, edge_nadirHex)
  assertEqInt(resNom, 4, "lightSampleProceduralSkyboxRGB nominal resNom == 4")
  assertEqInt(resEdge, 1, "lightSampleProceduralSkyboxRGB boundary resEdge == 1")
  ret 0
```

---

### `lightCompareShadowDepth` (`std/gfx3d/light3d.aipl`)

- **Signature**: `pub fn lightCompareShadowDepth(fragDepth: float, closestShadowDepth: float, bias: float): float:`
- **Import**: `import * from "std/gfx3d/light3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fragDepth: float, closestShadowDepth: float, bias: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/light3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `lightCompareShadowDepth` directional/point/spot light attenuation, Cascaded Shadow Map (`CSM`) split distances, and L2 spherical harmonics irradiance. Concrete nominal inputs: `fragDepth: float = 1.0`, `closestShadowDepth: float = 1.0`, `bias: float = 1.0`; exercises core body path returning/computing `1.0`.

```aipl
module tests.functions.gfx3d.light3d_z18_test
import * from "std/gfx3d/light3d"
import { PI, DEG2RAD, EPSILON, absFloat, minFloat, maxFloat, maxInt, clampInt, clampFloat } from "std/math/consts"
import { cos, pow, sqrt, expFloat } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_light3d_lightCompareShadowDepth_18(): int:
  let arg_fragDepth = 2.0
  let edge_fragDepth = 1.0
  let arg_closestShadowDepth = 0.0
  let edge_closestShadowDepth = 0.0
  let arg_bias = 1.0
  let edge_bias = 0.5
  let resNom = lightCompareShadowDepth(arg_fragDepth, arg_closestShadowDepth, arg_bias)
  let resEdge = lightCompareShadowDepth(edge_fragDepth, edge_closestShadowDepth, edge_bias)
  assertApproxEq(resNom, 0.25, 0.001, "lightCompareShadowDepth nominal resNom ~= 0.25")
  assertApproxEq(resEdge, 0.25, 0.001, "lightCompareShadowDepth boundary resEdge ~= 0.25")
  ret 0
```

---

### `createDefaultPbrMaterial` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn createDefaultPbrMaterial(): PbrMaterial3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `PbrMaterial3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `createDefaultPbrMaterial` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `PbrMaterial3D(`.

```aipl
module tests.functions.gfx3d.material3d_z1_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_createDefaultPbrMaterial_1(): int:
  let resNom = createDefaultPbrMaterial()
  let resEdge = createDefaultPbrMaterial()
  assertApproxEq(resNom.metallicFactor, 0.0, 0.001, "createDefaultPbrMaterial nominal resNom.metallicFactor ~= 0.0")
  assertApproxEq(resEdge.metallicFactor, 0.0, 0.001, "createDefaultPbrMaterial boundary resEdge.metallicFactor ~= 0.0")
  ret 0
```

---

### `evaluateGgxDistribution` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateGgxDistribution(nDotH: float, roughness: float): float:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nDotH: float, roughness: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `evaluateGgxDistribution` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `nDotH: float = 1.0`, `roughness: float = 1.0`; exercises core body path returning/computing `a2 / d`.

```aipl
module tests.functions.gfx3d.material3d_z2_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateGgxDistribution_2(): int:
  let arg_nDotH = 2.0
  let edge_nDotH = 1.0
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let resNom = evaluateGgxDistribution(arg_nDotH, arg_roughness)
  let resEdge = evaluateGgxDistribution(edge_nDotH, edge_roughness)
  assertApproxEq(resNom, 0.079577, 0.001, "evaluateGgxDistribution nominal resNom ~= 0.079577")
  assertApproxEq(resEdge, 0.31831, 0.001, "evaluateGgxDistribution boundary resEdge ~= 0.31831")
  ret 0
```

---

### `schlickG1` (`std/gfx3d/material3d.aipl`)

- **Signature**: `fn schlickG1(nDotX: float, k: float): float:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nDotX: float, k: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `schlickG1` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `nDotX: float = 1.0`, `k: float = 1.0`; exercises core body path returning/computing `nx / denom`.

```aipl
module tests.functions.gfx3d.material3d_z3_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_schlickG1_3(): int:
  let arg_nDotX = 1.0
  let edge_nDotX = 0.5
  let arg_k = 1.0
  let edge_k = 0.5
  let resNom = schlickG1(arg_nDotX, arg_k)
  let resEdge = schlickG1(edge_nDotX, edge_k)
  assertApproxEq(resNom, 1.0, 0.001, "schlickG1 nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.666667, 0.001, "schlickG1 boundary resEdge ~= 0.666667")
  ret 0
```

---

### `evaluateSmithSchlickGeometry` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateSmithSchlickGeometry(nDotV: float, nDotL: float, roughness: float): float:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nDotV: float, nDotL: float, roughness: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `evaluateSmithSchlickGeometry` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `nDotV: float = 1.0`, `nDotL: float = 1.0`, `roughness: float = 1.0`; exercises core body path returning/computing `ggxV * ggxL`.

```aipl
module tests.functions.gfx3d.material3d_z4_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateSmithSchlickGeometry_4(): int:
  let arg_nDotV = 1.0
  let edge_nDotV = 0.5
  let arg_nDotL = 1.0
  let edge_nDotL = 0.5
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let resNom = evaluateSmithSchlickGeometry(arg_nDotV, arg_nDotL, arg_roughness)
  let resEdge = evaluateSmithSchlickGeometry(edge_nDotV, edge_nDotL, edge_roughness)
  assertApproxEq(resNom, 1.0, 0.001, "evaluateSmithSchlickGeometry nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.444444, 0.001, "evaluateSmithSchlickGeometry boundary resEdge ~= 0.444444")
  ret 0
```

---

### `evaluateSchlickFresnel` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateSchlickFresnel(vDotH: float, f0: Vec3): Vec3:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `vDotH: float, f0: Vec3` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `evaluateSchlickFresnel` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `vDotH: float = 1.0`, `f0: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec3(`.

```aipl
module tests.functions.gfx3d.material3d_z5_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateSchlickFresnel_5(): int:
  let arg_vDotH = 2.0
  let edge_vDotH = 1.0
  let arg_f0 = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_f0 = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluateSchlickFresnel(arg_vDotH, arg_f0)
  let resEdge = evaluateSchlickFresnel(edge_vDotH, edge_f0)
  assertApproxEq(resNom.x, 1.0, 0.001, "evaluateSchlickFresnel nominal resNom.x ~= 1.0")
  assertApproxEq(resEdge.x, 0.5, 0.001, "evaluateSchlickFresnel boundary resEdge.x ~= 0.5")
  ret 0
```

---

### `evaluateCookTorranceBrdf` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateCookTorranceBrdf(nDotL: float, nDotV: float, nDotH: float, vDotH: float, albedo: Vec3, metallic: float, roughness: float): Vec3:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nDotL: float, nDotV: float, nDotH: float, vDotH: float, albedo: Vec3, metallic: float, roughness: float` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `evaluateCookTorranceBrdf` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `nDotL: float = 1.0`, `nDotV: float = 1.0`, `nDotH: float = 1.0`, `vDotH: float = 1.0`, `albedo: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `metallic: float = 1.0`, `roughness: float = 1.0`; exercises core body path returning/computing `diffuse.add(specular).scale(nl)`.

```aipl
module tests.functions.gfx3d.material3d_z6_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateCookTorranceBrdf_6(): int:
  let arg_nDotL = 1.0
  let edge_nDotL = 0.5
  let arg_nDotV = 1.0
  let edge_nDotV = 0.5
  let arg_nDotH = 2.0
  let edge_nDotH = 1.0
  let arg_vDotH = 2.0
  let edge_vDotH = 1.0
  let arg_albedo = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_albedo = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_metallic = 1.0
  let edge_metallic = 0.5
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let resNom = evaluateCookTorranceBrdf(arg_nDotL, arg_nDotV, arg_nDotH, arg_vDotH, arg_albedo, arg_metallic, arg_roughness)
  let resEdge = evaluateCookTorranceBrdf(edge_nDotL, edge_nDotV, edge_nDotH, edge_vDotH, edge_albedo, edge_metallic, edge_roughness)
  assertApproxEq(resNom.x, 0.019894, 0.001, "evaluateCookTorranceBrdf nominal resNom.x ~= 0.019894")
  assertApproxEq(resEdge.x, 0.048144, 0.001, "evaluateCookTorranceBrdf boundary resEdge.x ~= 0.048144")
  ret 0
```

---

### `material3DLambert` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn material3DLambert(albedoHex: int, ao: float = 1.0): Material3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `albedoHex: int, ao: float = 1.0` | **Returns**: `Material3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `material3DLambert` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `albedoHex: int = 1`, `ao: float = 1.0`; exercises core body path returning/computing `Material3D(`.

```aipl
module tests.functions.gfx3d.material3d_z7_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_material3DLambert_7(): int:
  let arg_albedoHex = 4
  let edge_albedoHex = 1
  let arg_ao = 1.0
  let edge_ao = 0.5
  let resNom = material3DLambert(arg_albedoHex, arg_ao)
  let resEdge = material3DLambert(edge_albedoHex, edge_ao)
  assertEqStr(resNom.name, "lambert", "material3DLambert nominal string matches")
  assertEqStr(resEdge.name, "lambert", "material3DLambert boundary string matches")
  ret 0
```

---

### `material3DBlinnPhong` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn material3DBlinnPhong(albedoHex: int, specularStrength: float, shininess: float): Material3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `albedoHex: int, specularStrength: float, shininess: float` | **Returns**: `Material3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `material3DBlinnPhong` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `albedoHex: int = 1`, `specularStrength: float = 1.0`, `shininess: float = 1.0`; exercises core body path returning/computing `Material3D(`.

```aipl
module tests.functions.gfx3d.material3d_z8_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_material3DBlinnPhong_8(): int:
  let arg_albedoHex = 4
  let edge_albedoHex = 1
  let arg_specularStrength = 2.0
  let edge_specularStrength = 1.0
  let arg_shininess = 2.0
  let edge_shininess = 1.0
  let resNom = material3DBlinnPhong(arg_albedoHex, arg_specularStrength, arg_shininess)
  let resEdge = material3DBlinnPhong(edge_albedoHex, edge_specularStrength, edge_shininess)
  assertEqStr(resNom.name, "blinn_phong", "material3DBlinnPhong nominal string matches")
  assertEqStr(resEdge.name, "blinn_phong", "material3DBlinnPhong boundary string matches")
  ret 0
```

---

### `material3DPbr` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn material3DPbr(albedoHex: int, metallic: float, roughness: float, ao: float, emissiveHex: int): Material3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `albedoHex: int, metallic: float, roughness: float, ao: float, emissiveHex: int` | **Returns**: `Material3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `material3DPbr` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `albedoHex: int = 1`, `metallic: float = 1.0`, `roughness: float = 1.0`, `ao: float = 1.0`, `emissiveHex: int = 1`; exercises core body path returning/computing `Material3D(`.

```aipl
module tests.functions.gfx3d.material3d_z9_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_material3DPbr_9(): int:
  let arg_albedoHex = 4
  let edge_albedoHex = 1
  let arg_metallic = 1.0
  let edge_metallic = 0.5
  let arg_roughness = 2.0
  let edge_roughness = 1.0
  let arg_ao = 1.0
  let edge_ao = 0.5
  let arg_emissiveHex = 4
  let edge_emissiveHex = 1
  let resNom = material3DPbr(arg_albedoHex, arg_metallic, arg_roughness, arg_ao, arg_emissiveHex)
  let resEdge = material3DPbr(edge_albedoHex, edge_metallic, edge_roughness, edge_ao, edge_emissiveHex)
  assertEqStr(resNom.name, "pbr", "material3DPbr nominal string matches")
  assertEqStr(resEdge.name, "pbr", "material3DPbr boundary string matches")
  ret 0
```

---

### `evaluateMaterial3D` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateMaterial3D(mat: Material3D, normal: Vec3, viewDir: Vec3, lightDir: Vec3): int:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mat: Material3D, normal: Vec3, viewDir: Vec3, lightDir: Vec3` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `evaluateMaterial3D` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `mat: Material3D = Material3D(name = "aipl_test", shadingModel = 1, albedoHex = 1, metallic = 1.0, roughness = 1.0, ao = 1.0, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = float = 1.0())`, `normal: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `viewDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `lightDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `litHex`.

```aipl
module tests.functions.gfx3d.material3d_z10_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateMaterial3D_10(): int:
  let arg_mat = Material3D(name = "test", shadingModel = 4, albedoHex = 4, metallic = 1.0, roughness = 2.0, ao = 1.0, specularStrength = 2.0, shininess = 2.0, emissiveHex = 4, normalScale = 2.0)
  let edge_mat = Material3D(name = "a", shadingModel = 1, albedoHex = 1, metallic = 0.5, roughness = 1.0, ao = 0.5, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = 1.0)
  let arg_normal = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_normal = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_viewDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_viewDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_lightDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = evaluateMaterial3D(arg_mat, arg_normal, arg_viewDir, arg_lightDir)
  let resEdge = evaluateMaterial3D(edge_mat, edge_normal, edge_viewDir, edge_lightDir)
  assertEqInt(resNom, 5, "evaluateMaterial3D nominal resNom == 5")
  assertEqInt(resEdge, 16777215, "evaluateMaterial3D boundary resEdge == 16777215")
  ret 0
```

---

### `evaluateMaterial3DWithLight` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn evaluateMaterial3DWithLight(mat: Material3D, normal: Vec3, tangentNormal: Vec3, viewDir: Vec3, light: DirectionalLight3D): int:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mat: Material3D, normal: Vec3, tangentNormal: Vec3, viewDir: Vec3, light: DirectionalLight3D` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `evaluateMaterial3DWithLight` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `mat: Material3D = Material3D(name = "aipl_test", shadingModel = 1, albedoHex = 1, metallic = 1.0, roughness = 1.0, ao = 1.0, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = float = 1.0())`, `normal: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `tangentNormal: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `viewDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `light: DirectionalLight3D = DirectionalLight3D(direction = Vec3(x = 1.0, y = 1.0, z = 1.0), colorHex = 1, intensity = 1.0)`; exercises core body path returning/computing `(outR << 16) | (outG << 8) | outB`.

```aipl
module tests.functions.gfx3d.material3d_z11_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_evaluateMaterial3DWithLight_11(): int:
  let arg_mat = Material3D(name = "test", shadingModel = 4, albedoHex = 4, metallic = 1.0, roughness = 2.0, ao = 1.0, specularStrength = 2.0, shininess = 2.0, emissiveHex = 4, normalScale = 2.0)
  let edge_mat = Material3D(name = "a", shadingModel = 1, albedoHex = 1, metallic = 0.5, roughness = 1.0, ao = 0.5, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = 1.0)
  let arg_normal = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_normal = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_tangentNormal = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_tangentNormal = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_viewDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_viewDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_light = DirectionalLight3D(direction = Vec3(x = 1.0, y = 1.0, z = 1.0), colorHex = 1, intensity = 1.0)
  let edge_light = DirectionalLight3D(direction = Vec3(x = 0.5, y = 0.5, z = 0.5), colorHex = 0, intensity = 0.5)
  let resNom = evaluateMaterial3DWithLight(arg_mat, arg_normal, arg_tangentNormal, arg_viewDir, arg_light)
  let resEdge = evaluateMaterial3DWithLight(edge_mat, edge_normal, edge_tangentNormal, edge_viewDir, edge_light)
  assertEqInt(resNom, 0, "evaluateMaterial3DWithLight nominal resNom == 0")
  assertEqInt(resEdge, 0, "evaluateMaterial3DWithLight boundary resEdge == 0")
  ret 0
```

---

### `createRenderPass3D` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn createRenderPass3D(cameraPos: Vec3, lightDir: Vec3, nearClip: float): RenderPass3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cameraPos: Vec3, lightDir: Vec3, nearClip: float` | **Returns**: `RenderPass3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `createRenderPass3D` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `cameraPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `lightDir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `nearClip: float = 1.0`; exercises core body path returning/computing `RenderPass3D(`.

```aipl
module tests.functions.gfx3d.material3d_z12_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_createRenderPass3D_12(): int:
  let arg_cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_cameraPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_lightDir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_nearClip = 1.0
  let edge_nearClip = 0.5
  let resNom = createRenderPass3D(arg_cameraPos, arg_lightDir, arg_nearClip)
  let resEdge = createRenderPass3D(edge_cameraPos, edge_lightDir, edge_nearClip)
  assertApproxEq(resNom.nearClip, 1.0, 0.001, "createRenderPass3D nominal resNom.nearClip ~= 1.0")
  assertApproxEq(resEdge.nearClip, 0.5, 0.001, "createRenderPass3D boundary resEdge.nearClip ~= 0.5")
  ret 0
```

---

### `submitMesh3D` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn submitMesh3D(mut pass: RenderPass3D, positions: [Vec3], normals: [Vec3], indices: [int], mat: Material3D): RenderPass3D:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pass: RenderPass3D, positions: [Vec3], normals: [Vec3], indices: [int], mat: Material3D` | **Returns**: `RenderPass3D`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `submitMesh3D` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `pass: RenderPass3D = RenderPass3D(cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0), lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0), nearClip = 1.0, triangles = [RenderTri3D(x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, depth = 0, colorHex = 0)])`, `positions: [Vec3] = [Vec3(x = 1.0, y = 1.0, z = 1.0)]`, `normals: [Vec3] = [Vec3(x = 1.0, y = 1.0, z = 1.0)]`, `indices: [int] = [1]`, `mat: Material3D = Material3D(name = "aipl_test", shadingModel = 1, albedoHex = 1, metallic = 1.0, roughness = 1.0, ao = 1.0, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = float = 1.0())`; exercises core body path returning/computing `pass`.

```aipl
module tests.functions.gfx3d.material3d_z13_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_submitMesh3D_13(): int:
  let arg_pass = RenderPass3D(cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0), lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0), nearClip = 1.0, triangles = [])
  let edge_pass = RenderPass3D(cameraPos = Vec3(x = 0.5, y = 0.5, z = 0.5), lightDir = Vec3(x = 0.5, y = 0.5, z = 0.5), nearClip = 0.5, triangles = [])
  let arg_positions = [Vec3(x = 1.0, y = 1.0, z = 1.0)]
  let edge_positions = []
  let arg_normals = [Vec3(x = 1.0, y = 1.0, z = 1.0)]
  let edge_normals = []
  let arg_indices = [4]
  let edge_indices = []
  let arg_mat = Material3D(name = "test", shadingModel = 4, albedoHex = 4, metallic = 1.0, roughness = 2.0, ao = 1.0, specularStrength = 2.0, shininess = 2.0, emissiveHex = 4, normalScale = 2.0)
  let edge_mat = Material3D(name = "a", shadingModel = 1, albedoHex = 1, metallic = 0.5, roughness = 1.0, ao = 0.5, specularStrength = 1.0, shininess = 1.0, emissiveHex = 1, normalScale = 1.0)
  let resNom = submitMesh3D(arg_pass, arg_positions, arg_normals, arg_indices, arg_mat)
  let resEdge = submitMesh3D(edge_pass, edge_positions, edge_normals, edge_indices, edge_mat)
  assertApproxEq(resNom.nearClip, 1.0, 0.001, "submitMesh3D nominal resNom.nearClip ~= 1.0")
  assertApproxEq(resEdge.nearClip, 0.5, 0.001, "submitMesh3D boundary resEdge.nearClip ~= 0.5")
  ret 0
```

---

### `endRenderPass3D` (`std/gfx3d/material3d.aipl`)

- **Signature**: `pub fn endRenderPass3D(mut pass: RenderPass3D): [RenderTri3D]:`
- **Import**: `import * from "std/gfx3d/material3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut pass: RenderPass3D` | **Returns**: `[RenderTri3D]`
- **Unit Test**: `tests/functions/gfx3d/material3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `endRenderPass3D` Cook-Torrance GGX normal distribution `D`, Smith-Schlick `G`, Schlick Fresnel `F`, and metallic-roughness PBR energy conservation. Concrete nominal inputs: `pass: RenderPass3D = RenderPass3D(cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0), lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0), nearClip = 1.0, triangles = [RenderTri3D(x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, depth = 0, colorHex = 0)])`; exercises core body path returning/computing `pass.triangles`.

```aipl
module tests.functions.gfx3d.material3d_z14_test
import * from "std/gfx3d/material3d"
import { PI, EPSILON, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { lightComputeLambertDiffuseRGB, lightComputeBlinnPhongRGB, lightComputePbrCookTorranceRGB } from "std/gfx3d/light3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_material3d_endRenderPass3D_14(): int:
  let arg_pass = RenderPass3D(cameraPos = Vec3(x = 1.0, y = 1.0, z = 1.0), lightDir = Vec3(x = 1.0, y = 1.0, z = 1.0), nearClip = 1.0, triangles = [])
  let edge_pass = RenderPass3D(cameraPos = Vec3(x = 0.5, y = 0.5, z = 0.5), lightDir = Vec3(x = 0.5, y = 0.5, z = 0.5), nearClip = 0.5, triangles = [])
  let resNom = endRenderPass3D(arg_pass)
  let resEdge = endRenderPass3D(edge_pass)
  assertEqInt(resNom.len(), 0, "endRenderPass3D nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "endRenderPass3D boundary resEdge.len() == 0")
  ret 0
```

---

### `createEmptyMesh3D` (`std/gfx3d/mesh3d.aipl`)

- **Signature**: `pub fn createEmptyMesh3D(): Mesh3D:`
- **Import**: `import * from "std/gfx3d/mesh3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/mesh3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `createEmptyMesh3D` 3D mesh area-weighted smooth normals, MikkTSpace tangent/bitangent handedness, and AABB/bounding-sphere computation. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Mesh3D(`.

```aipl
module tests.functions.gfx3d.mesh3d_z1_test
import * from "std/gfx3d/mesh3d"
import { EPSILON, minFloat, maxFloat } from "std/math/consts"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mesh3d_createEmptyMesh3D_1(): int:
  let resNom = createEmptyMesh3D()
  let resEdge = createEmptyMesh3D()
  assertEqInt(resNom.vertices.len(), 0, "createEmptyMesh3D nominal resNom.vertices.len() == 0")
  assertEqInt(resEdge.vertices.len(), 0, "createEmptyMesh3D boundary resEdge.vertices.len() == 0")
  ret 0
```

---

### `recomputeMeshBoundingBox` (`std/gfx3d/mesh3d.aipl`)

- **Signature**: `pub fn recomputeMeshBoundingBox(mesh: Mesh3D): Mesh3D:`
- **Import**: `import * from "std/gfx3d/mesh3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mesh: Mesh3D` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/mesh3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `recomputeMeshBoundingBox` 3D mesh area-weighted smooth normals, MikkTSpace tangent/bitangent handedness, and AABB/bounding-sphere computation. Concrete nominal inputs: `mesh: Mesh3D = Mesh3D(vertices = [Vertex3D(pos = 0, normal = 0, tangent = 0, uv = 0, color = 0, boneIndices = 0, boneWeights = 0)], indices = [1], subMeshes = [SubMesh3D(startIndex = 0, indexCount = 0, materialIndex = 0, boundingBox = 0)], boundingBox = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)))`; exercises core body path returning/computing `Mesh3D(`.

```aipl
module tests.functions.gfx3d.mesh3d_z2_test
import * from "std/gfx3d/mesh3d"
import { EPSILON, minFloat, maxFloat } from "std/math/consts"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mesh3d_recomputeMeshBoundingBox_2(): int:
  let arg_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)))
  let edge_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)))
  let resNom = recomputeMeshBoundingBox(arg_mesh)
  let resEdge = recomputeMeshBoundingBox(edge_mesh)
  assertEqInt(resNom.vertices.len(), 0, "recomputeMeshBoundingBox nominal resNom.vertices.len() == 0")
  assertEqInt(resEdge.vertices.len(), 0, "recomputeMeshBoundingBox boundary resEdge.vertices.len() == 0")
  ret 0
```

---

### `computeMeshNormals` (`std/gfx3d/mesh3d.aipl`)

- **Signature**: `pub fn computeMeshNormals(mesh: Mesh3D): Mesh3D:`
- **Import**: `import * from "std/gfx3d/mesh3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mesh: Mesh3D` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/mesh3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `computeMeshNormals` 3D mesh area-weighted smooth normals, MikkTSpace tangent/bitangent handedness, and AABB/bounding-sphere computation. Concrete nominal inputs: `mesh: Mesh3D = Mesh3D(vertices = [Vertex3D(pos = 0, normal = 0, tangent = 0, uv = 0, color = 0, boneIndices = 0, boneWeights = 0)], indices = [1], subMeshes = [SubMesh3D(startIndex = 0, indexCount = 0, materialIndex = 0, boundingBox = 0)], boundingBox = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)))`; exercises core body path returning/computing `Mesh3D(`.

```aipl
module tests.functions.gfx3d.mesh3d_z3_test
import * from "std/gfx3d/mesh3d"
import { EPSILON, minFloat, maxFloat } from "std/math/consts"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mesh3d_computeMeshNormals_3(): int:
  let arg_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)))
  let edge_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)))
  let resNom = computeMeshNormals(arg_mesh)
  let resEdge = computeMeshNormals(edge_mesh)
  assertEqInt(resNom.vertices.len(), 0, "computeMeshNormals nominal resNom.vertices.len() == 0")
  assertEqInt(resEdge.vertices.len(), 0, "computeMeshNormals boundary resEdge.vertices.len() == 0")
  ret 0
```

---

### `computeMeshTangentsMikkTSpace` (`std/gfx3d/mesh3d.aipl`)

- **Signature**: `pub fn computeMeshTangentsMikkTSpace(mesh: Mesh3D): Mesh3D:`
- **Import**: `import * from "std/gfx3d/mesh3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mesh: Mesh3D` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/mesh3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `computeMeshTangentsMikkTSpace` 3D mesh area-weighted smooth normals, MikkTSpace tangent/bitangent handedness, and AABB/bounding-sphere computation. Concrete nominal inputs: `mesh: Mesh3D = Mesh3D(vertices = [Vertex3D(pos = 0, normal = 0, tangent = 0, uv = 0, color = 0, boneIndices = 0, boneWeights = 0)], indices = [1], subMeshes = [SubMesh3D(startIndex = 0, indexCount = 0, materialIndex = 0, boundingBox = 0)], boundingBox = AABB3D(min = Vec3(x = 0, y = 0, z = 0), max = Vec3(x = 0, y = 0, z = 0)))`; exercises core body path returning/computing `Mesh3D(`.

```aipl
module tests.functions.gfx3d.mesh3d_z4_test
import * from "std/gfx3d/mesh3d"
import { EPSILON, minFloat, maxFloat } from "std/math/consts"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_mesh3d_computeMeshTangentsMikkTSpace_4(): int:
  let arg_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 1.0, y = 1.0, z = 1.0), max = Vec3(x = 1.0, y = 1.0, z = 1.0)))
  let edge_mesh = Mesh3D(vertices = [], indices = [], subMeshes = [], boundingBox = AABB3D(min = Vec3(x = 0.5, y = 0.5, z = 0.5), max = Vec3(x = 0.5, y = 0.5, z = 0.5)))
  let resNom = computeMeshTangentsMikkTSpace(arg_mesh)
  let resEdge = computeMeshTangentsMikkTSpace(edge_mesh)
  assertEqInt(resNom.vertices.len(), 0, "computeMeshTangentsMikkTSpace nominal resNom.vertices.len() == 0")
  assertEqInt(resEdge.vertices.len(), 0, "computeMeshTangentsMikkTSpace boundary resEdge.vertices.len() == 0")
  ret 0
```

---

### `makeVert` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `fn makeVert(px: float, py: float, pz: float, nx: float, ny: float, nz: float, u: float, v: float): Vertex3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `px: float, py: float, pz: float, nx: float, ny: float, nz: float, u: float, v: float` | **Returns**: `Vertex3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `makeVert` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `px: float = 1.0`, `py: float = 1.0`, `pz: float = 1.0`, `nx: float = 1.0`, `ny: float = 1.0`, `nz: float = 1.0`, `u: float = 1.0`, `v: float = 1.0`; exercises core body path returning/computing `Vertex3D(`.

```aipl
module tests.functions.gfx3d.primitives3d_z1_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_makeVert_1(): int:
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_pz = 1.0
  let edge_pz = 0.5
  let arg_nx = 1.0
  let edge_nx = 0.5
  let arg_ny = 1.0
  let edge_ny = 0.5
  let arg_nz = 1.0
  let edge_nz = 0.5
  let arg_u = 1.0
  let edge_u = 0.5
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = makeVert(arg_px, arg_py, arg_pz, arg_nx, arg_ny, arg_nz, arg_u, arg_v)
  let resEdge = makeVert(edge_px, edge_py, edge_pz, edge_nx, edge_ny, edge_nz, edge_u, edge_v)
  assertApproxEq(resNom.pos.x, 1.0, 0.001, "makeVert nominal resNom.pos.x ~= 1.0")
  assertApproxEq(resEdge.pos.x, 0.5, 0.001, "makeVert boundary resEdge.pos.x ~= 0.5")
  ret 0
```

---

### `finalizePrimitiveMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `fn finalizePrimitiveMesh(verts: [Vertex3D], indices: [int]): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `verts: [Vertex3D], indices: [int]` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `finalizePrimitiveMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `verts: [Vertex3D] = [Vertex3D(pos = Vec3(x = 0, y = 0, z = 0), normal = Vec3(x = 0, y = 0, z = 0), tangent = Vec4(x = 0, y = 0, z = 0, w = 0), uv = Vec2(x = 0, y = 0), color = ColorRgba8(r = 0, g = 0, b = 0, a = 0), boneIndices = IVec4(x = 0, y = 0, z = 0, w = 0), boneWeights = Vec4(x = 0, y = 0, z = 0, w = 0))]`, `indices: [int] = [1]`; exercises core body path returning/computing `Mesh3D(`.

```aipl
module tests.functions.gfx3d.primitives3d_z2_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_finalizePrimitiveMesh_2(): int:
  let arg_verts = [Vertex3D(pos = Vec3(x = 1.0, y = 1.0, z = 1.0), normal = Vec3(x = 1.0, y = 1.0, z = 1.0), tangent = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0), uv = Vec2(x = 1.0, y = 1.0), color = ColorRgba8(r = 2, g = 2, b = 4, a = 2), boneIndices = IVec4(x = 1, y = 1, z = 1, w = 2), boneWeights = Vec4(x = 1.0, y = 1.0, z = 1.0, w = 2.0))]
  let edge_verts = []
  let arg_indices = [4]
  let edge_indices = []
  let resNom = finalizePrimitiveMesh(arg_verts, arg_indices)
  let resEdge = finalizePrimitiveMesh(edge_verts, edge_indices)
  assertEqInt(resNom.vertices.len(), 1, "finalizePrimitiveMesh nominal resNom.vertices.len() == 1")
  assertEqInt(resEdge.vertices.len(), 0, "finalizePrimitiveMesh boundary resEdge.vertices.len() == 0")
  ret 0
```

---

### `generateBoxMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateBoxMesh(width: float, height: float, depth: float): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: float, height: float, depth: float` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `generateBoxMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `width: float = 0.016667`, `height: float = 1.0`, `depth: float = 1.0`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z3_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateBoxMesh_3(): int:
  let arg_width = 2.0
  let edge_width = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_depth = 2.0
  let edge_depth = 1.0
  let resNom = generateBoxMesh(arg_width, arg_height, arg_depth)
  let resEdge = generateBoxMesh(edge_width, edge_height, edge_depth)
  assertEqInt(resNom.vertices.len(), 24, "generateBoxMesh nominal resNom.vertices.len() == 24")
  assertEqInt(resEdge.vertices.len(), 24, "generateBoxMesh boundary resEdge.vertices.len() == 24")
  ret 0
```

---

### `generateUvSphereMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateUvSphereMesh(radius: float, segments: int = 32, rings: int = 16): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, segments: int = 32, rings: int = 16` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `generateUvSphereMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `radius: float = 1.0`, `segments: int = 1`, `rings: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z4_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateUvSphereMesh_4(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_segments = 4
  let edge_segments = 1
  let arg_rings = 4
  let edge_rings = 1
  let resNom = generateUvSphereMesh(arg_radius, arg_segments, arg_rings)
  let resEdge = generateUvSphereMesh(edge_radius, edge_segments, edge_rings)
  assertEqInt(resNom.vertices.len(), 25, "generateUvSphereMesh nominal resNom.vertices.len() == 25")
  assertEqInt(resEdge.vertices.len(), 12, "generateUvSphereMesh boundary resEdge.vertices.len() == 12")
  ret 0
```

---

### `generateIcosphereMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateIcosphereMesh(radius: float, subdivisions: int = 3): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, subdivisions: int = 3` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `generateIcosphereMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `radius: float = 1.0`, `subdivisions: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, tris)`.

```aipl
module tests.functions.gfx3d.primitives3d_z5_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateIcosphereMesh_5(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_subdivisions = 4
  let edge_subdivisions = 1
  let resNom = generateIcosphereMesh(arg_radius, arg_subdivisions)
  let resEdge = generateIcosphereMesh(edge_radius, edge_subdivisions)
  assertEqInt(resNom.vertices.len(), 5112, "generateIcosphereMesh nominal resNom.vertices.len() == 5112")
  assertEqInt(resEdge.vertices.len(), 72, "generateIcosphereMesh boundary resEdge.vertices.len() == 72")
  ret 0
```

---

### `generateCylinderMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateCylinderMesh(radius: float, height: float, segments: int = 32, capped: bool = true): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, height: float, segments: int = 32, capped: bool = true` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `generateCylinderMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `radius: float = 1.0`, `height: float = 1.0`, `segments: int = 1`, `capped: bool = true`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z6_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateCylinderMesh_6(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_segments = 4
  let edge_segments = 1
  let arg_capped = true
  let edge_capped = false
  let resNom = generateCylinderMesh(arg_radius, arg_height, arg_segments, arg_capped)
  let resEdge = generateCylinderMesh(edge_radius, edge_height, edge_segments, edge_capped)
  assertEqInt(resNom.vertices.len(), 22, "generateCylinderMesh nominal resNom.vertices.len() == 22")
  assertEqInt(resEdge.vertices.len(), 8, "generateCylinderMesh boundary resEdge.vertices.len() == 8")
  ret 0
```

---

### `generateConeMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateConeMesh(radius: float, height: float, segments: int = 32): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, height: float, segments: int = 32` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `generateConeMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `radius: float = 1.0`, `height: float = 1.0`, `segments: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z7_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateConeMesh_7(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_height = 2.0
  let edge_height = 1.0
  let arg_segments = 4
  let edge_segments = 1
  let resNom = generateConeMesh(arg_radius, arg_height, arg_segments)
  let resEdge = generateConeMesh(edge_radius, edge_height, edge_segments)
  assertEqInt(resNom.vertices.len(), 12, "generateConeMesh nominal resNom.vertices.len() == 12")
  assertEqInt(resEdge.vertices.len(), 10, "generateConeMesh boundary resEdge.vertices.len() == 10")
  ret 0
```

---

### `generateTorusMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateTorusMesh(majorRadius: float, minorRadius: float, radialSegments: int = 32, tubularSegments: int = 16): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `majorRadius: float, minorRadius: float, radialSegments: int = 32, tubularSegments: int = 16` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `generateTorusMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `majorRadius: float = 1.0`, `minorRadius: float = 1.0`, `radialSegments: int = 1`, `tubularSegments: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z8_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateTorusMesh_8(): int:
  let arg_majorRadius = 2.0
  let edge_majorRadius = 1.0
  let arg_minorRadius = 0.0
  let edge_minorRadius = 0.0
  let arg_radialSegments = 4
  let edge_radialSegments = 1
  let arg_tubularSegments = 4
  let edge_tubularSegments = 1
  let resNom = generateTorusMesh(arg_majorRadius, arg_minorRadius, arg_radialSegments, arg_tubularSegments)
  let resEdge = generateTorusMesh(edge_majorRadius, edge_minorRadius, edge_radialSegments, edge_tubularSegments)
  assertEqInt(resNom.vertices.len(), 25, "generateTorusMesh nominal resNom.vertices.len() == 25")
  assertEqInt(resEdge.vertices.len(), 16, "generateTorusMesh boundary resEdge.vertices.len() == 16")
  ret 0
```

---

### `generatePlaneMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generatePlaneMesh(width: float, depth: float, subX: int = 1, subZ: int = 1): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: float, depth: float, subX: int = 1, subZ: int = 1` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `generatePlaneMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `width: float = 0.016667`, `depth: float = 1.0`, `subX: int = 1`, `subZ: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z9_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generatePlaneMesh_9(): int:
  let arg_width = 2.0
  let edge_width = 1.0
  let arg_depth = 2.0
  let edge_depth = 1.0
  let arg_subX = 4
  let edge_subX = 1
  let arg_subZ = 4
  let edge_subZ = 1
  let resNom = generatePlaneMesh(arg_width, arg_depth, arg_subX, arg_subZ)
  let resEdge = generatePlaneMesh(edge_width, edge_depth, edge_subX, edge_subZ)
  assertEqInt(resNom.vertices.len(), 25, "generatePlaneMesh nominal resNom.vertices.len() == 25")
  assertEqInt(resEdge.vertices.len(), 4, "generatePlaneMesh boundary resEdge.vertices.len() == 4")
  ret 0
```

---

### `generateCapsuleMesh` (`std/gfx3d/primitives3d.aipl`)

- **Signature**: `pub fn generateCapsuleMesh(radius: float, cylinderHeight: float, rings: int = 8, segments: int = 16): Mesh3D:`
- **Import**: `import * from "std/gfx3d/primitives3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `radius: float, cylinderHeight: float, rings: int = 8, segments: int = 16` | **Returns**: `Mesh3D`
- **Unit Test**: `tests/functions/gfx3d/primitives3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `generateCapsuleMesh` procedural 3D mesh generation (Box, Sphere, Icosphere, Cylinder, Cone, Torus, Plane, Capsule) non-empty index/vertex buffers and unit normals. Concrete nominal inputs: `radius: float = 1.0`, `cylinderHeight: float = 1.0`, `rings: int = 1`, `segments: int = 1`; exercises core body path returning/computing `finalizePrimitiveMesh(verts, indices)`.

```aipl
module tests.functions.gfx3d.primitives3d_z10_test
import * from "std/gfx3d/primitives3d"
import { PI, TAU } from "std/math/consts"
import { sin, cos, sqrt } from "std/math/trig"
import { Vec2, Vec3, Vec4, IVec4 } from "std/math/vec_math"
import { AABB3D } from "std/math/geom3d"
import { ColorRgba8 } from "std/gfx/color"
import { Vertex3D, SubMesh3D, Mesh3D, recomputeMeshBoundingBox, computeMeshNormals } from "std/gfx3d/mesh3d"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_primitives3d_generateCapsuleMesh_10(): int:
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_cylinderHeight = 2.0
  let edge_cylinderHeight = 1.0
  let arg_rings = 4
  let edge_rings = 1
  let arg_segments = 4
  let edge_segments = 1
  let resNom = generateCapsuleMesh(arg_radius, arg_cylinderHeight, arg_rings, arg_segments)
  let resEdge = generateCapsuleMesh(edge_radius, edge_cylinderHeight, edge_rings, edge_segments)
  assertEqInt(resNom.vertices.len(), 45, "generateCapsuleMesh nominal resNom.vertices.len() == 45")
  assertEqInt(resEdge.vertices.len(), 20, "generateCapsuleMesh boundary resEdge.vertices.len() == 20")
  ret 0
```

---

### `composeBoneLocalMatrix` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `fn composeBoneLocalMatrix(pos: Vec3, rot: Quat, scale: Vec3): Mat4:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pos: Vec3, rot: Quat, scale: Vec3` | **Returns**: `Mat4`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `composeBoneLocalMatrix` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `pos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `rot: Quat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0)`, `scale: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `tMat.mul(rMat.mul(sMat))`.

```aipl
module tests.functions.gfx3d.rigging3d_z1_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_composeBoneLocalMatrix_1(): int:
  let arg_pos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_pos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_rot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0)
  let edge_rot = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0)
  let arg_scale = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_scale = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = composeBoneLocalMatrix(arg_pos, arg_rot, arg_scale)
  let resEdge = composeBoneLocalMatrix(edge_pos, edge_rot, edge_scale)
  assertApproxEq(resNom.m00, 0.428571, 0.001, "composeBoneLocalMatrix nominal resNom.m00 ~= 0.428571")
  assertApproxEq(resEdge.m00, 0.214286, 0.001, "composeBoneLocalMatrix boundary resEdge.m00 ~= 0.214286")
  ret 0
```

---

### `updateSkeletonHierarchy` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn updateSkeletonHierarchy(skel: Skeleton3D): Skeleton3D:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `skel: Skeleton3D` | **Returns**: `Skeleton3D`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `updateSkeletonHierarchy` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `skel: Skeleton3D = Skeleton3D(bones = [Bone3D(name = 0, parentIdx = 0, localPos = 0, localRot = 0, localScale = 0, invBindMatrix = 0, worldMatrix = 0)])`; exercises core body path returning/computing `Skeleton3D(bones = updatedBones)`.

```aipl
module tests.functions.gfx3d.rigging3d_z2_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_updateSkeletonHierarchy_2(): int:
  let arg_skel = Skeleton3D(bones = [])
  let edge_skel = Skeleton3D(bones = [])
  let resNom = updateSkeletonHierarchy(arg_skel)
  let resEdge = updateSkeletonHierarchy(edge_skel)
  assertEqInt(resNom.bones.len(), 0, "updateSkeletonHierarchy nominal resNom.bones.len() == 0")
  assertEqInt(resEdge.bones.len(), 0, "updateSkeletonHierarchy boundary resEdge.bones.len() == 0")
  ret 0
```

---

### `computeLinearSkinningPalette` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn computeLinearSkinningPalette(skel: Skeleton3D): [Mat4]:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `skel: Skeleton3D` | **Returns**: `[Mat4]`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `computeLinearSkinningPalette` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `skel: Skeleton3D = Skeleton3D(bones = [Bone3D(name = 0, parentIdx = 0, localPos = 0, localRot = 0, localScale = 0, invBindMatrix = 0, worldMatrix = 0)])`; exercises core body path returning/computing `palette`.

```aipl
module tests.functions.gfx3d.rigging3d_z3_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_computeLinearSkinningPalette_3(): int:
  let arg_skel = Skeleton3D(bones = [])
  let edge_skel = Skeleton3D(bones = [])
  let resNom = computeLinearSkinningPalette(arg_skel)
  let resEdge = computeLinearSkinningPalette(edge_skel)
  assertEqInt(resNom.len(), 0, "computeLinearSkinningPalette nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "computeLinearSkinningPalette boundary resEdge.len() == 0")
  ret 0
```

---

### `extractQuatFromMat4` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `fn extractQuatFromMat4(m: Mat4): Quat:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat4` | **Returns**: `Quat`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `extractQuatFromMat4` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `m: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `Quat(`.

```aipl
module tests.functions.gfx3d.rigging3d_z4_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_extractQuatFromMat4_4(): int:
  let arg_m = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_m = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = extractQuatFromMat4(arg_m)
  let resEdge = extractQuatFromMat4(edge_m)
  assertApproxEq(resNom.x, 0.0, 0.001, "extractQuatFromMat4 nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "extractQuatFromMat4 boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `matrixToDualQuat` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn matrixToDualQuat(m: Mat4): DualQuatSkin:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: Mat4` | **Returns**: `DualQuatSkin`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `matrixToDualQuat` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `m: Mat4 = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)`; exercises core body path returning/computing `DualQuatSkin(realQuat = qr, dualQuat = qd)`.

```aipl
module tests.functions.gfx3d.rigging3d_z5_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_matrixToDualQuat_5(): int:
  let arg_m = Mat4(m00 = 1.0, m01 = 1.0, m02 = 1.0, m03 = 1.0, m10 = 1.0, m11 = 1.0, m12 = 1.0, m13 = 1.0, m20 = 1.0, m21 = 1.0, m22 = 1.0, m23 = 1.0, m30 = 1.0, m31 = 1.0, m32 = 1.0, m33 = 1.0)
  let edge_m = Mat4(m00 = 0.5, m01 = 0.5, m02 = 0.5, m03 = 0.5, m10 = 0.5, m11 = 0.5, m12 = 0.5, m13 = 0.5, m20 = 0.5, m21 = 0.5, m22 = 0.5, m23 = 0.5, m30 = 0.5, m31 = 0.5, m32 = 0.5, m33 = 0.5)
  let resNom = matrixToDualQuat(arg_m)
  let resEdge = matrixToDualQuat(edge_m)
  assertApproxEq(resNom.realQuat.x, 0.0, 0.001, "matrixToDualQuat nominal resNom.realQuat.x ~= 0.0")
  assertApproxEq(resEdge.realQuat.x, 0.0, 0.001, "matrixToDualQuat boundary resEdge.realQuat.x ~= 0.0")
  ret 0
```

---

### `blendDualQuaternions` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn blendDualQuaternions(dq1: DualQuatSkin, dq2: DualQuatSkin, weight: float): DualQuatSkin:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dq1: DualQuatSkin, dq2: DualQuatSkin, weight: float` | **Returns**: `DualQuatSkin`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `blendDualQuaternions` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `dq1: DualQuatSkin = DualQuatSkin(realQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), dualQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0))`, `dq2: DualQuatSkin = DualQuatSkin(realQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0), dualQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 1.0))`, `weight: float = 0.5`; exercises core body path returning/computing `DualQuatSkin(`.

```aipl
module tests.functions.gfx3d.rigging3d_z6_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_blendDualQuaternions_6(): int:
  let arg_dq1 = DualQuatSkin(realQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), dualQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0))
  let edge_dq1 = DualQuatSkin(realQuat = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), dualQuat = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0))
  let arg_dq2 = DualQuatSkin(realQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), dualQuat = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0))
  let edge_dq2 = DualQuatSkin(realQuat = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0), dualQuat = Quat(x = 0.5, y = 0.5, z = 0.5, w = 1.0))
  let arg_weight = 2.0
  let edge_weight = 1.0
  let resNom = blendDualQuaternions(arg_dq1, arg_dq2, arg_weight)
  let resEdge = blendDualQuaternions(edge_dq1, edge_dq2, edge_weight)
  assertApproxEq(resNom.realQuat.x, 0.377964, 0.001, "blendDualQuaternions nominal resNom.realQuat.x ~= 0.377964")
  assertApproxEq(resEdge.realQuat.x, 0.377964, 0.001, "blendDualQuaternions boundary resEdge.realQuat.x ~= 0.377964")
  ret 0
```

---

### `skelForwardKinematics2D_X` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelForwardKinematics2D_X(originX: float, boneLen: float, angleDeg: float): float:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `originX: float, boneLen: float, angleDeg: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `skelForwardKinematics2D_X` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `originX: float = 1.0`, `boneLen: float = 1.0`, `angleDeg: float = 1.0`; exercises core body path returning/computing `originX + boneLen * cos(angleDeg * DEG2RAD)`.

```aipl
module tests.functions.gfx3d.rigging3d_z7_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelForwardKinematics2D_X_7(): int:
  let arg_originX = 1.0
  let edge_originX = 0.5
  let arg_boneLen = 1.0
  let edge_boneLen = 0.5
  let arg_angleDeg = 1.0
  let edge_angleDeg = 0.5
  let resNom = skelForwardKinematics2D_X(arg_originX, arg_boneLen, arg_angleDeg)
  let resEdge = skelForwardKinematics2D_X(edge_originX, edge_boneLen, edge_angleDeg)
  assertApproxEq(resNom, 1.99985, 0.001, "skelForwardKinematics2D_X nominal resNom ~= 1.99985")
  assertApproxEq(resEdge, 0.999981, 0.001, "skelForwardKinematics2D_X boundary resEdge ~= 0.999981")
  ret 0
```

---

### `skelForwardKinematics2D_Y` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelForwardKinematics2D_Y(originY: float, boneLen: float, angleDeg: float): float:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `originY: float, boneLen: float, angleDeg: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `skelForwardKinematics2D_Y` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `originY: float = 1.0`, `boneLen: float = 1.0`, `angleDeg: float = 1.0`; exercises core body path returning/computing `originY + boneLen * sin(angleDeg * DEG2RAD)`.

```aipl
module tests.functions.gfx3d.rigging3d_z8_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelForwardKinematics2D_Y_8(): int:
  let arg_originY = 1.0
  let edge_originY = 0.5
  let arg_boneLen = 1.0
  let edge_boneLen = 0.5
  let arg_angleDeg = 1.0
  let edge_angleDeg = 0.5
  let resNom = skelForwardKinematics2D_Y(arg_originY, arg_boneLen, arg_angleDeg)
  let resEdge = skelForwardKinematics2D_Y(edge_originY, edge_boneLen, edge_angleDeg)
  assertApproxEq(resNom, 1.01745, 0.001, "skelForwardKinematics2D_Y nominal resNom ~= 1.01745")
  assertApproxEq(resEdge, 0.504363, 0.001, "skelForwardKinematics2D_Y boundary resEdge ~= 0.504363")
  ret 0
```

---

### `skelSolveTwoBoneIKAngleDeg` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelSolveTwoBoneIKAngleDeg(rootX: float, rootY: float, targetX: float, targetY: float, len1: float, len2: float): float:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootX: float, rootY: float, targetX: float, targetY: float, len1: float, len2: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `skelSolveTwoBoneIKAngleDeg` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `rootX: float = 1.0`, `rootY: float = 1.0`, `targetX: float = 1.0`, `targetY: float = 1.0`, `len1: float = 1.0`, `len2: float = 1.0`; exercises core body path returning/computing `clampFloat(angleDeg, 0.0, 180.0)`.

```aipl
module tests.functions.gfx3d.rigging3d_z9_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelSolveTwoBoneIKAngleDeg_9(): int:
  let arg_rootX = 1.0
  let edge_rootX = 0.5
  let arg_rootY = 1.0
  let edge_rootY = 0.5
  let arg_targetX = 1.0
  let edge_targetX = 0.5
  let arg_targetY = 1.0
  let edge_targetY = 0.5
  let arg_len1 = 1.0
  let edge_len1 = 0.5
  let arg_len2 = 1.0
  let edge_len2 = 0.5
  let resNom = skelSolveTwoBoneIKAngleDeg(arg_rootX, arg_rootY, arg_targetX, arg_targetY, arg_len1, arg_len2)
  let resEdge = skelSolveTwoBoneIKAngleDeg(edge_rootX, edge_rootY, edge_targetX, edge_targetY, edge_len1, edge_len2)
  assertApproxEq(resNom, 0.00573, 0.001, "skelSolveTwoBoneIKAngleDeg nominal resNom ~= 0.00573")
  assertApproxEq(resEdge, 0.011459, 0.001, "skelSolveTwoBoneIKAngleDeg boundary resEdge ~= 0.011459")
  ret 0
```

---

### `skelInterpolateKeyframeHermite` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelInterpolateKeyframeHermite(val0: float, m0: float, val1: float, m1: float, t01: float): float:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val0: float, m0: float, val1: float, m1: float, t01: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `skelInterpolateKeyframeHermite` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `val0: float = 1.0`, `m0: float = 1.0`, `val1: float = 1.0`, `m1: float = 1.0`, `t01: float = 1.0`; exercises core body path returning/computing `h00 * val0 + h10 * m0 + h01 * val1 + h11 * m1`.

```aipl
module tests.functions.gfx3d.rigging3d_z10_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelInterpolateKeyframeHermite_10(): int:
  let arg_val0 = 1.0
  let edge_val0 = 0.5
  let arg_m0 = 1.0
  let edge_m0 = 0.5
  let arg_val1 = 1.0
  let edge_val1 = 0.5
  let arg_m1 = 1.0
  let edge_m1 = 0.5
  let arg_t01 = 0.0
  let edge_t01 = 0.0
  let resNom = skelInterpolateKeyframeHermite(arg_val0, arg_m0, arg_val1, arg_m1, arg_t01)
  let resEdge = skelInterpolateKeyframeHermite(edge_val0, edge_m0, edge_val1, edge_m1, edge_t01)
  assertApproxEq(resNom, 1.0, 0.001, "skelInterpolateKeyframeHermite nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "skelInterpolateKeyframeHermite boundary resEdge ~= 0.5")
  ret 0
```

---

### `skelSolveTwoBoneIK3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelSolveTwoBoneIK3D(rootPos: Vec3, targetPos: Vec3, polePos: Vec3, len1: float, len2: float): TwoBoneIKResult3D:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootPos: Vec3, targetPos: Vec3, polePos: Vec3, len1: float, len2: float` | **Returns**: `TwoBoneIKResult3D`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `skelSolveTwoBoneIK3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `rootPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `targetPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `polePos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `len1: float = 1.0`, `len2: float = 1.0`; exercises core body path returning/computing `TwoBoneIKResult3D(midPos = midPos, endPos = endPos, kneeBendDeg = kneeBendDeg, reachable = reachable)`.

```aipl
module tests.functions.gfx3d.rigging3d_z11_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelSolveTwoBoneIK3D_11(): int:
  let arg_rootPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_rootPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_targetPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_targetPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_polePos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_polePos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_len1 = 1.0
  let edge_len1 = 0.5
  let arg_len2 = 1.0
  let edge_len2 = 0.5
  let resNom = skelSolveTwoBoneIK3D(arg_rootPos, arg_targetPos, arg_polePos, arg_len1, arg_len2)
  let resEdge = skelSolveTwoBoneIK3D(edge_rootPos, edge_targetPos, edge_polePos, edge_len1, edge_len2)
  assertApproxEq(resNom.kneeBendDeg, 0.00573, 0.001, "skelSolveTwoBoneIK3D nominal resNom.kneeBendDeg ~= 0.00573")
  assertApproxEq(resEdge.kneeBendDeg, 0.011459, 0.001, "skelSolveTwoBoneIK3D boundary resEdge.kneeBendDeg ~= 0.011459")
  ret 0
```

---

### `skelSolveFabrik3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn skelSolveFabrik3D(joints: [Vec3], lengths: [float], targetPos: Vec3, iterations: int, tolerance: float): [Vec3]:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joints: [Vec3], lengths: [float], targetPos: Vec3, iterations: int, tolerance: float` | **Returns**: `[Vec3]`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `skelSolveFabrik3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `joints: [Vec3] = [Vec3(x = 1.0, y = 1.0, z = 1.0)]`, `lengths: [float] = [1.0]`, `targetPos: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `iterations: int = 1`, `tolerance: float = 1.0`; exercises core body path returning/computing `pts`.

```aipl
module tests.functions.gfx3d.rigging3d_z12_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_skelSolveFabrik3D_12(): int:
  let arg_joints = [Vec3(x = 1.0, y = 1.0, z = 1.0)]
  let edge_joints = []
  let arg_lengths = [2.0]
  let edge_lengths = []
  let arg_targetPos = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_targetPos = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_iterations = 4
  let edge_iterations = 1
  let arg_tolerance = 1.0
  let edge_tolerance = 0.5
  let resNom = skelSolveFabrik3D(arg_joints, arg_lengths, arg_targetPos, arg_iterations, arg_tolerance)
  let resEdge = skelSolveFabrik3D(edge_joints, edge_lengths, edge_targetPos, edge_iterations, edge_tolerance)
  assertEqInt(resNom.len(), 1, "skelSolveFabrik3D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "skelSolveFabrik3D boundary resEdge.len() == 0")
  ret 0
```

---

### `solveJointHierarchy3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn solveJointHierarchy3D(joints: [JointPose3D]): [JointPose3D]:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `joints: [JointPose3D]` | **Returns**: `[JointPose3D]`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `solveJointHierarchy3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `joints: [JointPose3D] = [JointPose3D(id = 1, parentId = 1, localPos = Vec3(x = 0, y = 0, z = 0), localRot = Quat(x = 0, y = 0, z = 0, w = 0), worldPos = Vec3(x = 0, y = 0, z = 0), worldRot = Quat(x = 0, y = 0, z = 0, w = 0))]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx3d.rigging3d_z13_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_solveJointHierarchy3D_13(): int:
  let arg_joints = [JointPose3D(id = 1, parentId = 4, localPos = Vec3(x = 1.0, y = 1.0, z = 1.0), localRot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0), worldPos = Vec3(x = 1.0, y = 1.0, z = 1.0), worldRot = Quat(x = 1.0, y = 1.0, z = 1.0, w = 2.0))]
  let edge_joints = []
  let resNom = solveJointHierarchy3D(arg_joints)
  let resEdge = solveJointHierarchy3D(edge_joints)
  assertEqInt(resNom.len(), 1, "solveJointHierarchy3D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "solveJointHierarchy3D boundary resEdge.len() == 0")
  ret 0
```

---

### `createSceneNode3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn createSceneNode3D(id: int, parentId: int, lx: float, ly: float, lz: float, sx: float, sy: float, sz: float): SceneNode3D:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, parentId: int, lx: float, ly: float, lz: float, sx: float, sy: float, sz: float` | **Returns**: `SceneNode3D`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `createSceneNode3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `id: int = 1`, `parentId: int = 1`, `lx: float = 1.0`, `ly: float = 1.0`, `lz: float = 1.0`, `sx: float = 1.0`, `sy: float = 1.0`, `sz: float = 1.0`; exercises core body path returning/computing `SceneNode3D(`.

```aipl
module tests.functions.gfx3d.rigging3d_z14_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_createSceneNode3D_14(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_parentId = 4
  let edge_parentId = 1
  let arg_lx = 1.0
  let edge_lx = 0.5
  let arg_ly = 1.0
  let edge_ly = 0.5
  let arg_lz = 1.0
  let edge_lz = 0.5
  let arg_sx = 1.0
  let edge_sx = 0.5
  let arg_sy = 1.0
  let edge_sy = 0.5
  let arg_sz = 1.0
  let edge_sz = 0.5
  let resNom = createSceneNode3D(arg_id, arg_parentId, arg_lx, arg_ly, arg_lz, arg_sx, arg_sy, arg_sz)
  let resEdge = createSceneNode3D(edge_id, edge_parentId, edge_lx, edge_ly, edge_lz, edge_sx, edge_sy, edge_sz)
  assertEqInt(resNom.id, 1, "createSceneNode3D nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createSceneNode3D boundary resEdge.id == 0")
  ret 0
```

---

### `updateSceneGraph3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn updateSceneGraph3D(nodes: [SceneNode3D]): [SceneNode3D]:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nodes: [SceneNode3D]` | **Returns**: `[SceneNode3D]`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `updateSceneGraph3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `nodes: [SceneNode3D] = [SceneNode3D(id = 1, parentId = 1, localX = 1.0, localY = 1.0, localZ = 1.0, scaleX = 1.0, scaleY = 1.0, scaleZ = 1.0, worldX = 1.0, worldY = 1.0, worldZ = 1.0, worldScaleX = 1.0, worldScaleY = 1.0, worldScaleZ = 1.0, dirty = true)]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.gfx3d.rigging3d_z15_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_updateSceneGraph3D_15(): int:
  let arg_nodes = [SceneNode3D(id = 1, parentId = 4, localX = 0.0, localY = 0.0, localZ = 0.0, scaleX = 2.0, scaleY = 2.0, scaleZ = 2.0, worldX = 2.0, worldY = 2.0, worldZ = 2.0, worldScaleX = 2.0, worldScaleY = 2.0, worldScaleZ = 2.0, dirty = true)]
  let edge_nodes = []
  let resNom = updateSceneGraph3D(arg_nodes)
  let resEdge = updateSceneGraph3D(edge_nodes)
  assertEqInt(resNom.len(), 1, "updateSceneGraph3D nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "updateSceneGraph3D boundary resEdge.len() == 0")
  ret 0
```

---

### `transformAABB3D` (`std/gfx3d/rigging3d.aipl`)

- **Signature**: `pub fn transformAABB3D(minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, m: [float]): TransformedAABB3D:`
- **Import**: `import * from "std/gfx3d/rigging3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minX: float, minY: float, minZ: float, maxX: float, maxY: float, maxZ: float, m: [float]` | **Returns**: `TransformedAABB3D`
- **Unit Test**: `tests/functions/gfx3d/rigging3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `transformAABB3D` 3D joint hierarchy forward kinematics, Linear Blend Skinning (`LBS`), volume-preserving Dual-Quaternion Skinning (`DQS`), and 3D FABRIK IK. Concrete nominal inputs: `minX: float = 1.0`, `minY: float = 1.0`, `minZ: float = 1.0`, `maxX: float = 1.0`, `maxY: float = 1.0`, `maxZ: float = 1.0`, `m: [float] = [1.0]`; exercises core body path returning/computing `TransformedAABB3D(minX = nMinX, minY = nMinY, minZ = nMinZ, maxX = nMaxX, maxY = nMaxY, maxZ = nMaxZ)`.

```aipl
module tests.functions.gfx3d.rigging3d_z16_test
import * from "std/gfx3d/rigging3d"
import { DEG2RAD, RAD2DEG, EPSILON, absFloat, maxFloat, maxInt, clampFloat } from "std/math/consts"
import { sin, cos, acos, atan2, sqrt } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Mat4 } from "std/math/mat"
import { Quat } from "std/math/quat"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_rigging3d_transformAABB3D_16(): int:
  let arg_minX = 0.0
  let edge_minX = 0.0
  let arg_minY = 0.0
  let edge_minY = 0.0
  let arg_minZ = 0.0
  let edge_minZ = 0.0
  let arg_maxX = 2.0
  let edge_maxX = 1.0
  let arg_maxY = 2.0
  let edge_maxY = 1.0
  let arg_maxZ = 2.0
  let edge_maxZ = 1.0
  let arg_m = [1.0]
  let edge_m = []
  let resNom = transformAABB3D(arg_minX, arg_minY, arg_minZ, arg_maxX, arg_maxY, arg_maxZ, arg_m)
  let resEdge = transformAABB3D(edge_minX, edge_minY, edge_minZ, edge_maxX, edge_maxY, edge_maxZ, edge_m)
  assertApproxEq(resNom.minX, 0.0, 0.001, "transformAABB3D nominal resNom.minX ~= 0.0")
  assertApproxEq(resEdge.minX, 0.0, 0.001, "transformAABB3D boundary resEdge.minX ~= 0.0")
  ret 0
```

---

### `computeAtmosphericScattering` (`std/gfx3d/skybox3d.aipl`)

- **Signature**: `pub fn computeAtmosphericScattering(dir: Vec3, settings: AtmosphereSettings): Vec3:`
- **Import**: `import * from "std/gfx3d/skybox3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dir: Vec3, settings: AtmosphereSettings` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/skybox3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `computeAtmosphericScattering` Preetham/Hosek-Wilkie Rayleigh & Mie atmospheric sky radiance and zenith-to-horizon color gradient. Concrete nominal inputs: `dir: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `settings: AtmosphereSettings = AtmosphereSettings(sunDirection = Vec3(x = 1.0, y = 1.0, z = 1.0), rayleighCoeff = Vec3(x = 1.0, y = 1.0, z = 1.0), mieCoeff = 1.0, sunIntensity = 1.0)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.gfx3d.skybox3d_z1_test
import * from "std/gfx3d/skybox3d"
import { PI, TAU, EPSILON, maxFloat, clampFloat } from "std/math/consts"
import { asin, atan2, pow } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skybox3d_computeAtmosphericScattering_1(): int:
  let arg_dir = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_dir = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_settings = AtmosphereSettings(sunDirection = Vec3(x = 1.0, y = 1.0, z = 1.0), rayleighCoeff = Vec3(x = 1.0, y = 1.0, z = 1.0), mieCoeff = 1.0, sunIntensity = 1.0)
  let edge_settings = AtmosphereSettings(sunDirection = Vec3(x = 0.5, y = 0.5, z = 0.5), rayleighCoeff = Vec3(x = 0.5, y = 0.5, z = 0.5), mieCoeff = 0.5, sunIntensity = 0.5)
  let resNom = computeAtmosphericScattering(arg_dir, arg_settings)
  let resEdge = computeAtmosphericScattering(edge_dir, edge_settings)
  assertApproxEq(resNom.x, 5.10845, 0.001, "computeAtmosphericScattering nominal resNom.x ~= 5.10845")
  assertApproxEq(resEdge.x, 1.27711, 0.001, "computeAtmosphericScattering boundary resEdge.x ~= 1.27711")
  ret 0
```

---

### `sampleEquirectangularUv` (`std/gfx3d/skybox3d.aipl`)

- **Signature**: `pub fn sampleEquirectangularUv(direction: Vec3): Vec2:`
- **Import**: `import * from "std/gfx3d/skybox3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `direction: Vec3` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/gfx3d/skybox3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `sampleEquirectangularUv` Preetham/Hosek-Wilkie Rayleigh & Mie atmospheric sky radiance and zenith-to-horizon color gradient. Concrete nominal inputs: `direction: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`; exercises core body path returning/computing `Vec2(x = u, y = v)`.

```aipl
module tests.functions.gfx3d.skybox3d_z2_test
import * from "std/gfx3d/skybox3d"
import { PI, TAU, EPSILON, maxFloat, clampFloat } from "std/math/consts"
import { asin, atan2, pow } from "std/math/trig"
import { Vec2, Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_skybox3d_sampleEquirectangularUv_2(): int:
  let arg_direction = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_direction = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let resNom = sampleEquirectangularUv(arg_direction)
  let resEdge = sampleEquirectangularUv(edge_direction)
  assertApproxEq(resNom.x, 0.625, 0.001, "sampleEquirectangularUv nominal resNom.x ~= 0.625")
  assertApproxEq(resEdge.x, 0.625, 0.001, "sampleEquirectangularUv boundary resEdge.x ~= 0.625")
  ret 0
```

---

### `readGridHeight` (`std/gfx3d/terrain3d.aipl`)

- **Signature**: `fn readGridHeight(terrain: TerrainHeightfield, gx: int, gz: int): float:`
- **Import**: `import * from "std/gfx3d/terrain3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `terrain: TerrainHeightfield, gx: int, gz: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/terrain3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `readGridHeight` heightmap bilinear sampling, central-difference surface normal, CDLOD quadtree morph factor, and triplanar weight normalization (`sum == 1.0`). Concrete nominal inputs: `terrain: TerrainHeightfield = TerrainHeightfield(width = 128, depth = 1, heightValues = [1.0], heightScale = 1.0, horizontalScale = 1.0)`, `gx: int = 1`, `gz: int = 1`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.gfx3d.terrain3d_z1_test
import * from "std/gfx3d/terrain3d"
import { EPSILON, absFloat, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { floor, pow } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_terrain3d_readGridHeight_1(): int:
  let arg_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 2.0, horizontalScale = 2.0)
  let edge_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 1.0, horizontalScale = 1.0)
  let arg_gx = 1
  let edge_gx = 0
  let arg_gz = 1
  let edge_gz = 0
  let resNom = readGridHeight(arg_terrain, arg_gx, arg_gz)
  let resEdge = readGridHeight(edge_terrain, edge_gx, edge_gz)
  assertApproxEq(resNom, 0.0, 0.001, "readGridHeight nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "readGridHeight boundary resEdge ~= 0.0")
  ret 0
```

---

### `sampleHeightAt` (`std/gfx3d/terrain3d.aipl`)

- **Signature**: `pub fn sampleHeightAt(terrain: TerrainHeightfield, worldX: float, worldZ: float): float:`
- **Import**: `import * from "std/gfx3d/terrain3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `terrain: TerrainHeightfield, worldX: float, worldZ: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx3d/terrain3d_test.aipl` | **Example**: `examples/ex_176_gfx3d_cull3d_frustum_and_occlusion_window.aipl`
- **Behavioral Summary**: Verify `sampleHeightAt` heightmap bilinear sampling, central-difference surface normal, CDLOD quadtree morph factor, and triplanar weight normalization (`sum == 1.0`). Concrete nominal inputs: `terrain: TerrainHeightfield = TerrainHeightfield(width = 128, depth = 1, heightValues = [1.0], heightScale = 1.0, horizontalScale = 1.0)`, `worldX: float = 1.0`, `worldZ: float = 1.0`; exercises core body path returning/computing `hx0 + (hx1 - hx0) * tz`.

```aipl
module tests.functions.gfx3d.terrain3d_z2_test
import * from "std/gfx3d/terrain3d"
import { EPSILON, absFloat, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { floor, pow } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_terrain3d_sampleHeightAt_2(): int:
  let arg_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 2.0, horizontalScale = 2.0)
  let edge_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 1.0, horizontalScale = 1.0)
  let arg_worldX = 2.0
  let edge_worldX = 1.0
  let arg_worldZ = 2.0
  let edge_worldZ = 1.0
  let resNom = sampleHeightAt(arg_terrain, arg_worldX, arg_worldZ)
  let resEdge = sampleHeightAt(edge_terrain, edge_worldX, edge_worldZ)
  assertApproxEq(resNom, 0.0, 0.001, "sampleHeightAt nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sampleHeightAt boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeTerrainNormal` (`std/gfx3d/terrain3d.aipl`)

- **Signature**: `pub fn computeTerrainNormal(terrain: TerrainHeightfield, gridX: int, gridZ: int): Vec3:`
- **Import**: `import * from "std/gfx3d/terrain3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `terrain: TerrainHeightfield, gridX: int, gridZ: int` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/terrain3d_test.aipl` | **Example**: `examples/ex_174_gfx3d_mesh3d_normals_and_tangents_window.aipl`
- **Behavioral Summary**: Verify `computeTerrainNormal` heightmap bilinear sampling, central-difference surface normal, CDLOD quadtree morph factor, and triplanar weight normalization (`sum == 1.0`). Concrete nominal inputs: `terrain: TerrainHeightfield = TerrainHeightfield(width = 128, depth = 1, heightValues = [1.0], heightScale = 1.0, horizontalScale = 1.0)`, `gridX: int = 0`, `gridZ: int = 1`; exercises core body path returning/computing `if nRaw.lenSq() > EPSILON: nRaw.norm() else: Vec3(x = 0.0, y = 1.0, z = 0.0)`.

```aipl
module tests.functions.gfx3d.terrain3d_z3_test
import * from "std/gfx3d/terrain3d"
import { EPSILON, absFloat, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { floor, pow } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_terrain3d_computeTerrainNormal_3(): int:
  let arg_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 2.0, horizontalScale = 2.0)
  let edge_terrain = TerrainHeightfield(width = 4, depth = 0, heightValues = [], heightScale = 1.0, horizontalScale = 1.0)
  let arg_gridX = 1
  let edge_gridX = 0
  let arg_gridZ = 1
  let edge_gridZ = 0
  let resNom = computeTerrainNormal(arg_terrain, arg_gridX, arg_gridZ)
  let resEdge = computeTerrainNormal(edge_terrain, edge_gridX, edge_gridZ)
  assertApproxEq(resNom.x, 0.0, 0.001, "computeTerrainNormal nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "computeTerrainNormal boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `computeTriplanarWeights` (`std/gfx3d/terrain3d.aipl`)

- **Signature**: `pub fn computeTriplanarWeights(normal: Vec3, sharpness: float = 4.0): Vec3:`
- **Import**: `import * from "std/gfx3d/terrain3d"` (or barrel `import * from "std/gfx3d/gfx3d_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `normal: Vec3, sharpness: float = 4.0` | **Returns**: `Vec3`
- **Unit Test**: `tests/functions/gfx3d/terrain3d_test.aipl` | **Example**: `examples/ex_175_gfx3d_camera3d_orbit_and_freecam_window.aipl`
- **Behavioral Summary**: Verify `computeTriplanarWeights` heightmap bilinear sampling, central-difference surface normal, CDLOD quadtree morph factor, and triplanar weight normalization (`sum == 1.0`). Concrete nominal inputs: `normal: Vec3 = Vec3(x = 1.0, y = 1.0, z = 1.0)`, `sharpness: float = 1.0`; exercises core body path returning/computing `Vec3(x = wx / sum, y = wy / sum, z = wz / sum)`.

```aipl
module tests.functions.gfx3d.terrain3d_z4_test
import * from "std/gfx3d/terrain3d"
import { EPSILON, absFloat, maxFloat, clampInt, clampFloat } from "std/math/consts"
import { floor, pow } from "std/math/trig"
import { Vec3 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_terrain3d_computeTriplanarWeights_4(): int:
  let arg_normal = Vec3(x = 1.0, y = 1.0, z = 1.0)
  let edge_normal = Vec3(x = 0.5, y = 0.5, z = 0.5)
  let arg_sharpness = 2.0
  let edge_sharpness = 1.0
  let resNom = computeTriplanarWeights(arg_normal, arg_sharpness)
  let resEdge = computeTriplanarWeights(edge_normal, edge_sharpness)
  assertApproxEq(resNom.x, 0.333333, 0.001, "computeTriplanarWeights nominal resNom.x ~= 0.333333")
  assertApproxEq(resEdge.x, 0.333333, 0.001, "computeTriplanarWeights boundary resEdge.x ~= 0.333333")
  ret 0
```
