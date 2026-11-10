[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 23: `asset` API Reference

> Complete API reference manual for AIPL standard library domain `asset` (159 callable functions & methods across ["std/asset/asset_bundle.aipl", "std/asset/asset_manager.aipl", "std/asset/asset_mod.aipl", "std/asset/atlas_packer.aipl", "std/asset/font_sdf.aipl", "std/asset/gltf_mesh_loader.aipl", "std/asset/image_decoder.aipl", "std/asset/apk_container_format.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `asset`
- **Target Source Modules**: ["std/asset/asset_bundle.aipl", "std/asset/asset_manager.aipl", "std/asset/asset_mod.aipl", "std/asset/atlas_packer.aipl", "std/asset/font_sdf.aipl", "std/asset/gltf_mesh_loader.aipl", "std/asset/image_decoder.aipl", "std/asset/apk_container_format.aipl"]
- **Total Callable Functions & Methods**: 159
- **Total Data Types (`struct` & `enum`)**: 25
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(25 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `BundleHeader` | `pub struct` | `std/asset/asset_bundle.aipl` | `magic: int`, `version: int`, `fileCount: int`, `tocOffset: int`, `tocSizeBytes: int` | `BundleHeader(magic, version, fileCount, tocOffset, tocSizeBytes)` |
| `BundleEntry` | `pub struct` | `std/asset/asset_bundle.aipl` | `pathHash: int`, `virtualPath: str`, `offsetBytes: int`, `compressedSize: int`, `uncompressedSize: int`, `compressionMethod: int` | `BundleEntry(pathHash, virtualPath, offsetBytes, compressedSize, uncompressedSize, compressionMethod)` |
| `AssetBundle` | `pub struct` | `std/asset/asset_bundle.aipl` | `header: BundleHeader`, `entries: Map[str`, `BundleEntry]`, `archiveData: [int]` | `AssetBundle(header, entries, BundleEntry], archiveData)` |
| `AssetHandle[T]` | `pub struct` | `std/asset/asset_manager.aipl` | `id: int`, `path: str`, `status: int`, `refCount: int`, `data: Option[T]`, `errorMessage: str` | `AssetHandle(id, path, status, refCount, data, errorMessage)` |
| `AssetManager` | `pub struct` | `std/asset/asset_manager.aipl` | `assets: Map[str`, `int]`, `nextId: int`, `hotReloadEnabled: bool`, `imagePaths: [str]`, `imageIds: [int]`, `soundPaths: [str]`, `soundIds: [int]` | `AssetManager(assets, int], nextId, hotReloadEnabled, imagePaths, imageIds, soundPaths, soundIds)` |
| `ImageHandle` | `pub struct` | `std/asset/asset_manager.aipl` | `id: int`, `width: int`, `height: int`, `path: str` | `ImageHandle(id, width, height, path)` |
| `SoundHandle` | `pub struct` | `std/asset/asset_manager.aipl` | `id: int`, `duration: float`, `path: str` | `SoundHandle(id, duration, path)` |
| `FontHandle` | `pub struct` | `std/asset/asset_manager.aipl` | `id: int`, `path: str` | `FontHandle(id, path)` |
| `SpriteSheet` | `pub struct` | `std/asset/asset_manager.aipl` | `imageId: int`, `frameWidth: int`, `frameHeight: int`, `columns: int`, `totalFrames: int` | `SpriteSheet(imageId, frameWidth, frameHeight, columns, totalFrames)` |
| `AnimationClip` | `pub struct` | `std/asset/asset_manager.aipl` | `startFrame: int`, `frameCount: int`, `fps: float`, `loopClip: bool` | `AnimationClip(startFrame, frameCount, fps, loopClip)` |
| `VideoSession` | `pub struct` | `std/asset/asset_manager.aipl` | `path: str`, `fps: int`, `frameCount: int`, `active: bool` | `VideoSession(path, fps, frameCount, active)` |
| `PackRect` | `pub struct` | `std/asset/atlas_packer.aipl` | `id: int`, `width: int`, `height: int`, `x: int`, `y: int`, `isRotated: bool`, `isPacked: bool` | `PackRect(id, width, height, x, y, isRotated, isPacked)` |
| `AtlasBin` | `pub struct` | `std/asset/atlas_packer.aipl` | `width: int`, `height: int`, `paddingGutter: int`, `freeRects: [PackRect]`, `packedRects: [PackRect]`, `occupancyRatio: float` | `AtlasBin(width, height, paddingGutter, freeRects, packedRects, occupancyRatio)` |
| `GlyphMetric` | `pub struct` | `std/asset/font_sdf.aipl` | `codepoint: int`, `advanceX: float`, `bearingX: float`, `bearingY: float`, `width: float`, `height: float`, `uvMinX: float`, `uvMinY: float`, `uvMaxX: float`, `uvMaxY: float` | `GlyphMetric(codepoint, advanceX, bearingX, bearingY, width, height, uvMinX, uvMinY, uvMaxX, uvMaxY)` |
| `FontSdfAtlas` | `pub struct` | `std/asset/font_sdf.aipl` | `textureWidth: int`, `textureHeight: int`, `sdfRadiusPx: float`, `glyphs: Map[int`, `GlyphMetric]`, `distanceFieldBytes: [int]` | `FontSdfAtlas(textureWidth, textureHeight, sdfRadiusPx, glyphs, GlyphMetric], distanceFieldBytes)` |
| `GltfAccessor` | `pub struct` | `std/asset/gltf_mesh_loader.aipl` | `componentType: int`, `count: int`, `typeString: str`, `byteOffset: int`, `bufferViewIndex: int` | `GltfAccessor(componentType, count, typeString, byteOffset, bufferViewIndex)` |
| `GltfPrimitive` | `pub struct` | `std/asset/gltf_mesh_loader.aipl` | `positions: [float]`, `normals: [float]`, `uvs: [float]`, `indices: [int]`, `materialIndex: int` | `GltfPrimitive(positions, normals, uvs, indices, materialIndex)` |
| `GltfMesh` | `pub struct` | `std/asset/gltf_mesh_loader.aipl` | `name: str`, `primitives: [GltfPrimitive]` | `GltfMesh(name, primitives)` |
| `GltfNode` | `pub struct` | `std/asset/gltf_mesh_loader.aipl` | `name: str`, `translation: [float]`, `rotation: [float]`, `scale: [float]`, `meshIndex: int`, `children: [int]` | `GltfNode(name, translation, rotation, scale, meshIndex, children)` |
| `GltfScene` | `pub struct` | `std/asset/gltf_mesh_loader.aipl` | `meshes: [GltfMesh]`, `nodes: [GltfNode]`, `rootNodes: [int]` | `GltfScene(meshes, nodes, rootNodes)` |
| `DecodedImage` | `pub struct` | `std/asset/image_decoder.aipl` | `width: int`, `height: int`, `channels: int`, `pixelsRgba: [int]`, `format: int`, `pixels: [int]` | `DecodedImage(width, height, channels, pixelsRgba, format, pixels)` |
| `Pixel` | `pub struct` | `std/asset/image_decoder.aipl` | `r: int`, `g: int`, `b: int`, `a: int` | `Pixel(r, g, b, a)` |
| `SvgBuilder` | `pub struct` | `std/asset/image_decoder.aipl` | `width: int`, `height: int`, `elements: [str]` | `SvgBuilder(width, height, elements)` |
| `TextureAtlasGrid` | `pub struct` | `std/asset/image_decoder.aipl` | `cols: int`, `rows: int`, `cellW: int`, `cellH: int`, `padding: int` | `TextureAtlasGrid(cols, rows, cellW, cellH, padding)` |
| `AiplApkPayloadHeader` | `pub struct` | `std/asset/apk_container_format.aipl` | `magic: str`, `formatVersion: int`, `bootMode: int`, `codeByteLen: int`, `assetCount: int`, `payloadCrc32: int`, `magicValid: int` | `AiplApkPayloadHeader(magic, formatVersion, bootMode, codeByteLen, assetCount, payloadCrc32, magicValid)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/asset/asset_bundle.aipl` | `createAssetBundle` | `pub fn createAssetBundle(entries: [BundleEntry], data: [int]): AssetBundle:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `2` | `std/asset/asset_bundle.aipl` | `readU32BEAt` | `fn readU32BEAt(b: [int], off: int): int:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `3` | `std/asset/asset_bundle.aipl` | `openAssetBundle` | `pub fn openAssetBundle(archiveBytes: [int]): Option[AssetBundle]:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `4` | `std/asset/asset_bundle.aipl` | `hasBundleFile` | `pub fn hasBundleFile(bundle: AssetBundle, virtualPath: str): bool:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `5` | `std/asset/asset_bundle.aipl` | `extractBundleEntry` | `pub fn extractBundleEntry(bundle: AssetBundle, entry: BundleEntry): [int]:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `6` | `std/asset/asset_bundle.aipl` | `readBundleFile` | `pub fn readBundleFile(bundle: AssetBundle, virtualPath: str): Option[[int]]:` | `tests/functions/asset/asset_bundle_test.aipl` |
| `7` | `std/asset/asset_manager.aipl` | `createAssetManager` | `pub fn createAssetManager(hotReload: bool = false): AssetManager:` | `tests/functions/asset/asset_manager_test.aipl` |
| `8` | `std/asset/asset_manager.aipl` | `registerAsset` | `pub fn registerAsset[T](mgr: AssetManager, path: str, initialData: T): (AssetManager, AssetHandle[T]):` | `tests/functions/asset/asset_manager_test.aipl` |
| `9` | `std/asset/asset_manager.aipl` | `getAssetStatus` | `pub fn getAssetStatus[T](handle: AssetHandle[T]): int:` | `tests/functions/asset/asset_manager_test.aipl` |
| `10` | `std/asset/asset_manager.aipl` | `retainAsset` | `pub fn retainAsset[T](handle: AssetHandle[T]): AssetHandle[T]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `11` | `std/asset/asset_manager.aipl` | `releaseAsset` | `pub fn releaseAsset[T](handle: AssetHandle[T]): AssetHandle[T]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `12` | `std/asset/asset_manager.aipl` | `notifyAssetFileChanged` | `pub fn notifyAssetFileChanged(mgr: AssetManager, changedPath: str): AssetManager:` | `tests/functions/asset/asset_manager_test.aipl` |
| `13` | `std/asset/asset_manager.aipl` | `createImageHandle` | `pub fn createImageHandle(id: int, path: str): ImageHandle:` | `tests/functions/asset/asset_manager_test.aipl` |
| `14` | `std/asset/asset_manager.aipl` | `loadImageHandle` | `pub fn loadImageHandle(path: str): Result[ImageHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `15` | `std/asset/asset_manager.aipl` | `decodeImageHandle` | `pub fn decodeImageHandle(data: bytes, label: str): Result[ImageHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `16` | `std/asset/asset_manager.aipl` | `createSoundHandle` | `pub fn createSoundHandle(id: int, path: str): SoundHandle:` | `tests/functions/asset/asset_manager_test.aipl` |
| `17` | `std/asset/asset_manager.aipl` | `loadSoundHandle` | `pub fn loadSoundHandle(path: str): Result[SoundHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `18` | `std/asset/asset_manager.aipl` | `decodeSoundHandle` | `pub fn decodeSoundHandle(data: bytes, label: str): Result[SoundHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `19` | `std/asset/asset_manager.aipl` | `createFontHandle` | `pub fn createFontHandle(id: int, path: str): FontHandle:` | `tests/functions/asset/asset_manager_test.aipl` |
| `20` | `std/asset/asset_manager.aipl` | `loadFontHandle` | `pub fn loadFontHandle(path: str): Result[FontHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `21` | `std/asset/asset_manager.aipl` | `decodeFontHandle` | `pub fn decodeFontHandle(data: bytes, label: str): Result[FontHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `22` | `std/asset/asset_manager.aipl` | `createSpriteSheet` | `pub fn createSpriteSheet(imageId: int, frameWidth: int, frameHeight: int, columns: int, totalFrames: int): SpriteSheet:` | `tests/functions/asset/asset_manager_test.aipl` |
| `23` | `std/asset/asset_manager.aipl` | `createAnimationClip` | `pub fn createAnimationClip(startFrame: int, frameCount: int, fps: float, loopClip: bool): AnimationClip:` | `tests/functions/asset/asset_manager_test.aipl` |
| `24` | `std/asset/asset_manager.aipl` | `sampleAnimationFrame` | `pub fn sampleAnimationFrame(clip: AnimationClip, elapsedSec: float): int:` | `tests/functions/asset/asset_manager_test.aipl` |
| `25` | `std/asset/asset_manager.aipl` | `drawSpriteFrame` | `pub fn drawSpriteFrame(sheet: SpriteSheet, frameIndex: int, dx: float, dy: float, dw: float, dh: float):` | `tests/functions/asset/asset_manager_test.aipl` |
| `26` | `std/asset/asset_manager.aipl` | `drawAnimatedSprite` | `pub fn drawAnimatedSprite(sheet: SpriteSheet, clip: AnimationClip, elapsedSec: float, dx: float, dy: float, dw: float, dh: float):` | `tests/functions/asset/asset_manager_test.aipl` |
| `27` | `std/asset/asset_manager.aipl` | `measureLabel` | `pub fn measureLabel(font: FontHandle, text: str, size: float): Vec2:` | `tests/functions/asset/asset_manager_test.aipl` |
| `28` | `std/asset/asset_manager.aipl` | `drawLabel` | `pub fn drawLabel(font: FontHandle, x: float, y: float, text: str, size: float, color: int):` | `tests/functions/asset/asset_manager_test.aipl` |
| `29` | `std/asset/asset_manager.aipl` | `findCachedId` | `pub fn findCachedId(paths: [str], ids: [int], targetPath: str): int:` | `tests/functions/asset/asset_manager_test.aipl` |
| `30` | `std/asset/asset_manager.aipl` | `getCachedImage` | `pub fn getCachedImage(mgr: AssetManager, path: str): int:` | `tests/functions/asset/asset_manager_test.aipl` |
| `31` | `std/asset/asset_manager.aipl` | `getCachedSound` | `pub fn getCachedSound(mgr: AssetManager, path: str): int:` | `tests/functions/asset/asset_manager_test.aipl` |
| `32` | `std/asset/asset_manager.aipl` | `cacheImage` | `pub fn cacheImage(mgr: AssetManager, path: str, imageId: int): AssetManager:` | `tests/functions/asset/asset_manager_test.aipl` |
| `33` | `std/asset/asset_manager.aipl` | `cacheSound` | `pub fn cacheSound(mgr: AssetManager, path: str, soundId: int): AssetManager:` | `tests/functions/asset/asset_manager_test.aipl` |
| `34` | `std/asset/asset_manager.aipl` | `createVideoSession` | `pub fn createVideoSession(path: str, fps: int = 30): VideoSession:` | `tests/functions/asset/asset_manager_test.aipl` |
| `35` | `std/asset/asset_manager.aipl` | `startVideoCapture` | `pub fn startVideoCapture(mut session: VideoSession): Result[VideoSession, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `36` | `std/asset/asset_manager.aipl` | `captureVideoFrame` | `pub fn captureVideoFrame(mut session: VideoSession): VideoSession:` | `tests/functions/asset/asset_manager_test.aipl` |
| `37` | `std/asset/asset_manager.aipl` | `stopVideoCapture` | `pub fn stopVideoCapture(mut session: VideoSession): Result[int, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `38` | `std/asset/asset_manager.aipl` | `isVideoCaptureActive` | `pub fn isVideoCaptureActive(session: VideoSession): bool:` | `tests/functions/asset/asset_manager_test.aipl` |
| `39` | `std/asset/asset_manager.aipl` | `takeScreenshot` | `pub fn takeScreenshot(path: str): bool:` | `tests/functions/asset/asset_manager_test.aipl` |
| `40` | `std/asset/asset_manager.aipl` | `captureScreenshotHandle` | `pub fn captureScreenshotHandle(path: str): Result[ImageHandle, str]:` | `tests/functions/asset/asset_manager_test.aipl` |
| `41` | `std/asset/atlas_packer.aipl` | `createAtlasBin` | `pub fn createAtlasBin(width: int, height: int, gutterPx: int = 2): AtlasBin:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `42` | `std/asset/atlas_packer.aipl` | `minIntPack` | `fn minIntPack(a: int, b: int): int:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `43` | `std/asset/atlas_packer.aipl` | `maxIntPack` | `fn maxIntPack(a: int, b: int): int:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `44` | `std/asset/atlas_packer.aipl` | `rectsIntersect` | `fn rectsIntersect(a: PackRect, b: PackRect): bool:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `45` | `std/asset/atlas_packer.aipl` | `isContainedIn` | `fn isContainedIn(a: PackRect, b: PackRect): bool:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `46` | `std/asset/atlas_packer.aipl` | `calculateAtlasOccupancy` | `pub fn calculateAtlasOccupancy(bin: AtlasBin): float:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `47` | `std/asset/atlas_packer.aipl` | `packRectMaxRects` | `pub fn packRectMaxRects(bin: AtlasBin, rect: PackRect, allowRotation: bool = false): (AtlasBin, Option[PackRect]):` | `tests/functions/asset/atlas_packer_test.aipl` |
| `48` | `std/asset/atlas_packer.aipl` | `packRectangles` | `pub fn packRectangles(bin: AtlasBin, rects: [PackRect], allowRotation: bool = false): (AtlasBin, [PackRect]):` | `tests/functions/asset/atlas_packer_test.aipl` |
| `49` | `std/asset/atlas_packer.aipl` | `checkBleedGutters` | `pub fn checkBleedGutters(bin: AtlasBin, minGutterPx: int): bool:` | `tests/functions/asset/atlas_packer_test.aipl` |
| `50` | `std/asset/font_sdf.aipl` | `parseTtfTables` | `pub fn parseTtfTables(fontFileBytes: [int]): bool:` | `tests/functions/asset/font_sdf_test.aipl` |
| `51` | `std/asset/font_sdf.aipl` | `computeSignedDistance` | `pub fn computeSignedDistance(px: float, py: float, curvePoints: [float]): float:` | `tests/functions/asset/font_sdf_test.aipl` |
| `52` | `std/asset/font_sdf.aipl` | `generateSdfGlyph` | `pub fn generateSdfGlyph(glyphCurves: [float], width: int, height: int, radius: float): [int]:` | `tests/functions/asset/font_sdf_test.aipl` |
| `53` | `std/asset/font_sdf.aipl` | `sampleSdfAtlas` | `pub fn sampleSdfAtlas(atlas: FontSdfAtlas, codepoint: int): Option[GlyphMetric]:` | `tests/functions/asset/font_sdf_test.aipl` |
| `54` | `std/asset/gltf_mesh_loader.aipl` | `parseGltfJson` | `pub fn parseGltfJson(jsonStr: str, binBuffer: [int]): Option[GltfScene]:` | `tests/functions/asset/gltf_mesh_loader_test.aipl` |
| `55` | `std/asset/gltf_mesh_loader.aipl` | `readGlbU32LE` | `fn readGlbU32LE(b: [int], off: int): int:` | `tests/functions/asset/gltf_mesh_loader_test.aipl` |
| `56` | `std/asset/gltf_mesh_loader.aipl` | `parseGlbBinary` | `pub fn parseGlbBinary(glbBytes: [int]): Option[GltfScene]:` | `tests/functions/asset/gltf_mesh_loader_test.aipl` |
| `57` | `std/asset/gltf_mesh_loader.aipl` | `extractMeshVertices` | `pub fn extractMeshVertices(prim: GltfPrimitive): [float]:` | `tests/functions/asset/gltf_mesh_loader_test.aipl` |
| `58` | `std/asset/gltf_mesh_loader.aipl` | `extractMeshIndices` | `pub fn extractMeshIndices(prim: GltfPrimitive): [int]:` | `tests/functions/asset/gltf_mesh_loader_test.aipl` |
| `59` | `std/asset/image_decoder.aipl` | `pixelRgb` | `pub fn pixelRgb(r: int, g: int, b: int): Pixel:` | `tests/functions/asset/image_decoder_test.aipl` |
| `60` | `std/asset/image_decoder.aipl` | `pixelRgba` | `pub fn pixelRgba(r: int, g: int, b: int, a: int): Pixel:` | `tests/functions/asset/image_decoder_test.aipl` |
| `61` | `std/asset/image_decoder.aipl` | `pixelToInt` | `pub fn pixelToInt(p: Pixel): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `62` | `std/asset/image_decoder.aipl` | `intToPixel` | `pub fn intToPixel(c: int): Pixel:` | `tests/functions/asset/image_decoder_test.aipl` |
| `63` | `std/asset/image_decoder.aipl` | `imageBufferNew` | `pub fn imageBufferNew(width: int, height: int, fillColor: int = 0): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `64` | `std/asset/image_decoder.aipl` | `imageNew` | `pub fn imageNew(width: int, height: int, fillColor: int = 0): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `65` | `std/asset/image_decoder.aipl` | `imageGetPixel` | `pub fn imageGetPixel(img: DecodedImage, x: int, y: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `66` | `std/asset/image_decoder.aipl` | `imageSetPixel` | `pub fn imageSetPixel(mut img: DecodedImage, x: int, y: int, color: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `67` | `std/asset/image_decoder.aipl` | `readU16LEImg` | `fn readU16LEImg(b: [int], off: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `68` | `std/asset/image_decoder.aipl` | `readU32LEImg` | `fn readU32LEImg(b: [int], off: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `69` | `std/asset/image_decoder.aipl` | `readU32BEImg` | `fn readU32BEImg(b: [int], off: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `70` | `std/asset/image_decoder.aipl` | `detectImageFormat` | `pub fn detectImageFormat(headerBytes: [int]): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `71` | `std/asset/image_decoder.aipl` | `decodeBmp` | `pub fn decodeBmp(bytes: [int]): Option[DecodedImage]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `72` | `std/asset/image_decoder.aipl` | `decodeQoi` | `pub fn decodeQoi(bytes: [int]): Option[DecodedImage]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `73` | `std/asset/image_decoder.aipl` | `decodePngHeader` | `pub fn decodePngHeader(bytes: [int], checkMagic: bool = true): Option[(int, int, int)]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `74` | `std/asset/image_decoder.aipl` | `decodeTga` | `pub fn decodeTga(bytes: [int]): Option[DecodedImage]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `75` | `std/asset/image_decoder.aipl` | `absDiffInt` | `fn absDiffInt(a: int, b: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `76` | `std/asset/image_decoder.aipl` | `matchesKeyColor` | `fn matchesKeyColor(pixels: [int], idx4: int, kr: int, kg: int, kb: int, tol: int): bool:` | `tests/functions/asset/image_decoder_test.aipl` |
| `77` | `std/asset/image_decoder.aipl` | `applyBorderFloodAlphaKey` | `pub fn applyBorderFloodAlphaKey(image: DecodedImage, keyColorR: int, keyColorG: int, keyColorB: int, tolerance: int = 0): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `78` | `std/asset/image_decoder.aipl` | `getPixelRgba` | `pub fn getPixelRgba(img: DecodedImage, x: int, y: int): (int, int, int, int):` | `tests/functions/asset/image_decoder_test.aipl` |
| `79` | `std/asset/image_decoder.aipl` | `setPixelRgba` | `pub fn setPixelRgba(img: DecodedImage, x: int, y: int, r: int, g: int, b: int, a: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `80` | `std/asset/image_decoder.aipl` | `imageResizeNearest` | `pub fn imageResizeNearest(img: DecodedImage, newWidth: int, newHeight: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `81` | `std/asset/image_decoder.aipl` | `lerpChannel` | `fn lerpChannel(c00: int, c10: int, c01: int, c11: int, fx: float, fy: float): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `82` | `std/asset/image_decoder.aipl` | `imageResizeBilinear` | `pub fn imageResizeBilinear(img: DecodedImage, newWidth: int, newHeight: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `83` | `std/asset/image_decoder.aipl` | `imageCrop` | `pub fn imageCrop(img: DecodedImage, cropX: int, cropY: int, cropW: int, cropH: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `84` | `std/asset/image_decoder.aipl` | `imageFlipH` | `pub fn imageFlipH(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `85` | `std/asset/image_decoder.aipl` | `imageFlipV` | `pub fn imageFlipV(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `86` | `std/asset/image_decoder.aipl` | `imageFlipHorizontal` | `pub fn imageFlipHorizontal(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `87` | `std/asset/image_decoder.aipl` | `imageFlipVertical` | `pub fn imageFlipVertical(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `88` | `std/asset/image_decoder.aipl` | `imageRotate90` | `pub fn imageRotate90(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `89` | `std/asset/image_decoder.aipl` | `imageGrayscale` | `pub fn imageGrayscale(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `90` | `std/asset/image_decoder.aipl` | `imageInvert` | `pub fn imageInvert(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `91` | `std/asset/image_decoder.aipl` | `imageSepia` | `pub fn imageSepia(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `92` | `std/asset/image_decoder.aipl` | `clampChannel` | `fn clampChannel(val: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `93` | `std/asset/image_decoder.aipl` | `imageAdjustBrightnessContrast` | `pub fn imageAdjustBrightnessContrast(img: DecodedImage, brightness: float, contrast: float): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `94` | `std/asset/image_decoder.aipl` | `imageBoxBlurSeparable` | `pub fn imageBoxBlurSeparable(img: DecodedImage, radius: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `95` | `std/asset/image_decoder.aipl` | `imageBoxBlur` | `pub fn imageBoxBlur(img: DecodedImage, radius: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `96` | `std/asset/image_decoder.aipl` | `imageSliceSpriteSheet` | `pub fn imageSliceSpriteSheet(img: DecodedImage, frameW: int, frameH: int): [DecodedImage]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `97` | `std/asset/image_decoder.aipl` | `imageToAsciiArt` | `pub fn imageToAsciiArt(img: DecodedImage, cols: int, rows: int): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `98` | `std/asset/image_decoder.aipl` | `imageBlit` | `pub fn imageBlit(mut dst: DecodedImage, src: DecodedImage, dx: int, dy: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `99` | `std/asset/image_decoder.aipl` | `imageDrawLine` | `pub fn imageDrawLine(mut img: DecodedImage, x0: int, y0: int, x1: int, y1: int, color: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `100` | `std/asset/image_decoder.aipl` | `imageDrawCircle` | `pub fn imageDrawCircle(mut img: DecodedImage, cx: int, cy: int, radius: int, color: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `101` | `std/asset/image_decoder.aipl` | `imageDrawCirclePixel` | `pub fn imageDrawCirclePixel(img: DecodedImage, cx: int, cy: int, r: int, col: Pixel): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `102` | `std/asset/image_decoder.aipl` | `imageFillRectColor` | `pub fn imageFillRectColor(mut img: DecodedImage, x: int, y: int, w: int, h: int, color: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `103` | `std/asset/image_decoder.aipl` | `imageFillRect` | `pub fn imageFillRect(mut img: DecodedImage, rx: int, ry: int, rw: int, rh: int, r: int, g: int, b: int, a: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `104` | `std/asset/image_decoder.aipl` | `imageFloodFill` | `pub fn imageFloodFill(mut img: DecodedImage, startX: int, startY: int, newColor: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `105` | `std/asset/image_decoder.aipl` | `imageToPpm` | `pub fn imageToPpm(img: DecodedImage): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `106` | `std/asset/image_decoder.aipl` | `encodePpm` | `pub fn encodePpm(img: DecodedImage): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `107` | `std/asset/image_decoder.aipl` | `encodePpmP3` | `pub fn encodePpmP3(img: DecodedImage): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `108` | `std/asset/image_decoder.aipl` | `encodePpmP6` | `pub fn encodePpmP6(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `109` | `std/asset/image_decoder.aipl` | `encodePgmP2` | `pub fn encodePgmP2(img: DecodedImage): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `110` | `std/asset/image_decoder.aipl` | `encodePgmP5` | `pub fn encodePgmP5(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `111` | `std/asset/image_decoder.aipl` | `hexColor6` | `fn hexColor6(c: int): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `112` | `std/asset/image_decoder.aipl` | `imageToSvgRle` | `pub fn imageToSvgRle(img: DecodedImage, scale: int = 1): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `113` | `std/asset/image_decoder.aipl` | `imageToSvg` | `pub fn imageToSvg(img: DecodedImage, scale: int = 1): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `114` | `std/asset/image_decoder.aipl` | `encodeSvg` | `pub fn encodeSvg(img: DecodedImage, scale: int = 1): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `115` | `std/asset/image_decoder.aipl` | `svgNew` | `pub fn svgNew(width: int, height: int): SvgBuilder:` | `tests/functions/asset/image_decoder_test.aipl` |
| `116` | `std/asset/image_decoder.aipl` | `svgAddRect` | `pub fn svgAddRect(mut b: SvgBuilder, x: int, y: int, w: int, h: int, fill: str, stroke: str = "none"): SvgBuilder:` | `tests/functions/asset/image_decoder_test.aipl` |
| `117` | `std/asset/image_decoder.aipl` | `svgAddCircle` | `pub fn svgAddCircle(mut b: SvgBuilder, cx: int, cy: int, r: int, fill: str, stroke: str = "none"): SvgBuilder:` | `tests/functions/asset/image_decoder_test.aipl` |
| `118` | `std/asset/image_decoder.aipl` | `svgAddLine` | `pub fn svgAddLine(mut b: SvgBuilder, x1: int, y1: int, x2: int, y2: int, stroke: str, strokeWidth: int = 1): SvgBuilder:` | `tests/functions/asset/image_decoder_test.aipl` |
| `119` | `std/asset/image_decoder.aipl` | `svgAddText` | `pub fn svgAddText(mut b: SvgBuilder, x: int, y: int, text: str, fontSize: int = 14, fill: str = "#000000"): SvgBuilder:` | `tests/functions/asset/image_decoder_test.aipl` |
| `120` | `std/asset/image_decoder.aipl` | `svgRender` | `pub fn svgRender(b: SvgBuilder): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `121` | `std/asset/image_decoder.aipl` | `stripJpegExif` | `pub fn stripJpegExif(jpegData: bytes): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `122` | `std/asset/image_decoder.aipl` | `decodePpm` | `pub fn decodePpm(ppmStr: str): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `123` | `std/asset/image_decoder.aipl` | `decodePpmP3` | `pub fn decodePpmP3(ppmStr: str): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `124` | `std/asset/image_decoder.aipl` | `decodePpmBytes` | `pub fn decodePpmBytes(data: bytes): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `125` | `std/asset/image_decoder.aipl` | `decodePgm` | `pub fn decodePgm(pgmStr: str): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `126` | `std/asset/image_decoder.aipl` | `decodePgmBytes` | `pub fn decodePgmBytes(data: bytes): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `127` | `std/asset/image_decoder.aipl` | `encodeBmp` | `pub fn encodeBmp(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `128` | `std/asset/image_decoder.aipl` | `encodeBmp32` | `pub fn encodeBmp32(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `129` | `std/asset/image_decoder.aipl` | `encodeTga` | `pub fn encodeTga(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `130` | `std/asset/image_decoder.aipl` | `encodeTga32` | `pub fn encodeTga32(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `131` | `std/asset/image_decoder.aipl` | `qoiColorHash` | `fn qoiColorHash(r: int, g: int, b: int, a: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `132` | `std/asset/image_decoder.aipl` | `qoiWrapDelta` | `fn qoiWrapDelta(d: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `133` | `std/asset/image_decoder.aipl` | `encodeQoi` | `pub fn encodeQoi(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `134` | `std/asset/image_decoder.aipl` | `detectImageFormatByPath` | `pub fn detectImageFormatByPath(path: str): str:` | `tests/functions/asset/image_decoder_test.aipl` |
| `135` | `std/asset/image_decoder.aipl` | `readImageFile` | `pub fn readImageFile(path: str): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `136` | `std/asset/image_decoder.aipl` | `writeImageFile` | `pub fn writeImageFile(img: DecodedImage, path: str): Result[bool, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `137` | `std/asset/image_decoder.aipl` | `imageCheckerboard` | `pub fn imageCheckerboard(w: int, h: int, cellSize: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `138` | `std/asset/image_decoder.aipl` | `imageLinearGradient` | `pub fn imageLinearGradient(w: int, h: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int, vertical: bool): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `139` | `std/asset/image_decoder.aipl` | `posterizeChannel` | `fn posterizeChannel(val: int, levels: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `140` | `std/asset/image_decoder.aipl` | `imagePosterize` | `pub fn imagePosterize(img: DecodedImage, levels: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `141` | `std/asset/image_decoder.aipl` | `edgeDetectSqrt` | `fn edgeDetectSqrt(n: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `142` | `std/asset/image_decoder.aipl` | `getPixelLuminanceClamped` | `fn getPixelLuminanceClamped(img: DecodedImage, x: int, y: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `143` | `std/asset/image_decoder.aipl` | `imageEdgeDetect` | `pub fn imageEdgeDetect(img: DecodedImage): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `144` | `std/asset/image_decoder.aipl` | `pngCrc32` | `fn pngCrc32(chunkTypeAndData: [int]): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `145` | `std/asset/image_decoder.aipl` | `pngAdler32` | `fn pngAdler32(raw: [int]): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `146` | `std/asset/image_decoder.aipl` | `pngPushU32BE` | `fn pngPushU32BE(mut out: [int], val: int): [int]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `147` | `std/asset/image_decoder.aipl` | `pngAppendChunk` | `fn pngAppendChunk(mut out: [int], t0: int, t1: int, t2: int, t3: int, payload: [int]): [int]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `148` | `std/asset/image_decoder.aipl` | `encodePng` | `pub fn encodePng(img: DecodedImage): bytes:` | `tests/functions/asset/image_decoder_test.aipl` |
| `149` | `std/asset/image_decoder.aipl` | `decodePng` | `pub fn decodePng(data: bytes): Result[DecodedImage, str]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `150` | `std/asset/image_decoder.aipl` | `textureAtlasGridNew` | `pub fn textureAtlasGridNew(cols: int, rows: int, cellW: int, cellH: int, padding: int = 0): TextureAtlasGrid:` | `tests/functions/asset/image_decoder_test.aipl` |
| `151` | `std/asset/image_decoder.aipl` | `atlasGridRegion` | `pub fn atlasGridRegion(grid: TextureAtlasGrid, index: int): [int]:` | `tests/functions/asset/image_decoder_test.aipl` |
| `152` | `std/asset/image_decoder.aipl` | `imageBlitEx` | `pub fn imageBlitEx(mut dst: DecodedImage, src: DecodedImage, sx: int, sy: int, sw: int, sh: int, dx: int, dy: int, dw: int, dh: int, flipX: bool = false, flipY: bool = false): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `153` | `std/asset/image_decoder.aipl` | `imageBlitNinePatch` | `pub fn imageBlitNinePatch(mut dst: DecodedImage, src: DecodedImage, left: int, top: int, right: int, bottom: int, dx: int, dy: int, dw: int, dh: int): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `154` | `std/asset/image_decoder.aipl` | `glyphRowMask5x7` | `fn glyphRowMask5x7(code: int, row: int): int:` | `tests/functions/asset/image_decoder_test.aipl` |
| `155` | `std/asset/image_decoder.aipl` | `imageDrawText` | `pub fn imageDrawText(mut img: DecodedImage, x: int, y: int, text: str, color: int, scale: int = 1): DecodedImage:` | `tests/functions/asset/image_decoder_test.aipl` |
| `156` | `std/asset/apk_container_format.aipl` | `createAiplApkPayloadHeader` | `pub fn createAiplApkPayloadHeader(codePayload: str, assetCount: int): AiplApkPayloadHeader:` | `tests/functions/asset/apk_container_format_test.aipl` |
| `157` | `std/asset/apk_container_format.aipl` | `serializeAiplApkPayload` | `pub fn serializeAiplApkPayload(codePayload: str, assetCount: int): str:` | `tests/functions/asset/apk_container_format_test.aipl` |
| `158` | `std/asset/apk_container_format.aipl` | `parseAndVerifyAiplApkPayload` | `pub fn parseAndVerifyAiplApkPayload(rawImage: str): Result[str, str]:` | `tests/functions/asset/apk_container_format_test.aipl` |
| `159` | `std/asset/apk_container_format.aipl` | `appendApkEmbeddedAssetEntry` | `pub fn appendApkEmbeddedAssetEntry(mut assetTable: Map[str, int], relPath: str, content: str): (Map[str, int], int):` | `tests/functions/asset/apk_container_format_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createAssetBundle` (`std/asset/asset_bundle.aipl`)

- **Signature**: `pub fn createAssetBundle(entries: [BundleEntry], data: [int]): AssetBundle:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entries: [BundleEntry], data: [int]` | **Returns**: `AssetBundle`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createAssetBundle` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `entries: [BundleEntry] = [BundleEntry(pathHash = 1, virtualPath = "/tmp/aipl_test_artifact.tmp", offsetBytes = 64, compressedSize = 64, uncompressedSize = 64, compressionMethod = 1)]`, `data: [int] = [1]`; exercises core body path returning/computing `AssetBundle(header = hdr, entries = m, archiveData = data)`.

```aipl
module tests.functions.asset.asset_bundle_z1_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_createAssetBundle_1(): int:
  let arg_entries = [BundleEntry(pathHash = 2, virtualPath = "/tmp/aipl_test_path", offsetBytes = 4, compressedSize = 4, uncompressedSize = 4, compressionMethod = 4)]
  let edge_entries = []
  let arg_data = [2]
  let edge_data = []
  let resNom = createAssetBundle(arg_entries, arg_data)
  let resEdge = createAssetBundle(edge_entries, edge_data)
  assertEqInt(resNom.archiveData.len(), 1, "createAssetBundle nominal resNom.archiveData.len() == 1")
  assertEqInt(resEdge.archiveData.len(), 0, "createAssetBundle boundary resEdge.archiveData.len() == 0")
  ret 0
```

---

### `readU32BEAt` (`std/asset/asset_bundle.aipl`)

- **Signature**: `fn readU32BEAt(b: [int], off: int): int:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `readU32BEAt` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `((b[off] & 255) << 24) | ((b[off + 1] & 255) << 16) | ((b[off + 2] & 255) << 8) | (b[off + 3] & 255)`.

```aipl
module tests.functions.asset.asset_bundle_z2_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_readU32BEAt_2(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU32BEAt(arg_b, arg_off)
  let resEdge = readU32BEAt(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU32BEAt nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU32BEAt boundary resEdge == 0")
  ret 0
```

---

### `openAssetBundle` (`std/asset/asset_bundle.aipl`)

- **Signature**: `pub fn openAssetBundle(archiveBytes: [int]): Option[AssetBundle]:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `archiveBytes: [int]` | **Returns**: `Option[AssetBundle]`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `openAssetBundle` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `archiveBytes: [int] = [64]`; exercises core body path returning/computing `Some(AssetBundle(header = hdr, entries = m, archiveData = archiveBytes))`.

```aipl
module tests.functions.asset.asset_bundle_z3_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_openAssetBundle_3(): int:
  let arg_archiveBytes = [4]
  let edge_archiveBytes = []
  let resNom = openAssetBundle(arg_archiveBytes)
  let resEdge = openAssetBundle(edge_archiveBytes)
  assert(resNom.isSome() == false, "openAssetBundle nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "openAssetBundle boundary resEdge.isSome() == false")
  ret 0
```

---

### `hasBundleFile` (`std/asset/asset_bundle.aipl`)

- **Signature**: `pub fn hasBundleFile(bundle: AssetBundle, virtualPath: str): bool:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bundle: AssetBundle, virtualPath: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `hasBundleFile` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `bundle: AssetBundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 64, tocOffset = 0, tocSizeBytes = 64), entries = Map(), archiveData = [1])`, `virtualPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `bundle.entries.containsKey(virtualPath)`.

```aipl
module tests.functions.asset.asset_bundle_z4_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_hasBundleFile_4(): int:
  let arg_bundle = AssetBundle(header = BundleHeader(magic = 4, version = 4, fileCount = 4, tocOffset = 1, tocSizeBytes = 4), entries = {}, archiveData = [])
  let edge_bundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 1, tocOffset = 0, tocSizeBytes = 1), entries = {}, archiveData = [])
  let arg_virtualPath = "/tmp/aipl_test_path"
  let edge_virtualPath = "/tmp/aipl_test_path"
  let resNom = hasBundleFile(arg_bundle, arg_virtualPath)
  let resEdge = hasBundleFile(edge_bundle, edge_virtualPath)
  assert(resNom == false, "hasBundleFile nominal resNom == false")
  assert(resEdge == false, "hasBundleFile boundary resEdge == false")
  ret 0
```

---

### `extractBundleEntry` (`std/asset/asset_bundle.aipl`)

- **Signature**: `pub fn extractBundleEntry(bundle: AssetBundle, entry: BundleEntry): [int]:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bundle: AssetBundle, entry: BundleEntry` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `extractBundleEntry` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `bundle: AssetBundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 64, tocOffset = 0, tocSizeBytes = 64), entries = Map(), archiveData = [1])`, `entry: BundleEntry = BundleEntry(pathHash = 1, virtualPath = "/tmp/aipl_test_artifact.tmp", offsetBytes = 64, compressedSize = 64, uncompressedSize = 64, compressionMethod = 1)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.asset_bundle_z5_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_extractBundleEntry_5(): int:
  let arg_bundle = AssetBundle(header = BundleHeader(magic = 4, version = 4, fileCount = 4, tocOffset = 1, tocSizeBytes = 4), entries = {}, archiveData = [])
  let edge_bundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 1, tocOffset = 0, tocSizeBytes = 1), entries = {}, archiveData = [])
  let arg_entry = BundleEntry(pathHash = 2, virtualPath = "/tmp/aipl_test_path", offsetBytes = 4, compressedSize = 4, uncompressedSize = 4, compressionMethod = 4)
  let edge_entry = BundleEntry(pathHash = 0, virtualPath = "/tmp/aipl_test_path", offsetBytes = 1, compressedSize = 1, uncompressedSize = 1, compressionMethod = 1)
  let resNom = extractBundleEntry(arg_bundle, arg_entry)
  let resEdge = extractBundleEntry(edge_bundle, edge_entry)
  assertEqInt(resNom.len(), 0, "extractBundleEntry nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractBundleEntry boundary resEdge.len() == 0")
  ret 0
```

---

### `readBundleFile` (`std/asset/asset_bundle.aipl`)

- **Signature**: `pub fn readBundleFile(bundle: AssetBundle, virtualPath: str): Option[[int]]:`
- **Import**: `import * from "std/asset/asset_bundle"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bundle: AssetBundle, virtualPath: str` | **Returns**: `Option[[int]]`
- **Unit Test**: `tests/functions/asset/asset_bundle_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `readBundleFile` binary asset bundle packing, big-endian directory table lookup, and exact byte-slice extraction. Concrete nominal inputs: `bundle: AssetBundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 64, tocOffset = 0, tocSizeBytes = 64), entries = Map(), archiveData = [1])`, `virtualPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Some(extractBundleEntry(bundle, entry))`.

```aipl
module tests.functions.asset.asset_bundle_z6_test
import * from "std/asset/asset_bundle"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_bundle_readBundleFile_6(): int:
  let arg_bundle = AssetBundle(header = BundleHeader(magic = 4, version = 4, fileCount = 4, tocOffset = 1, tocSizeBytes = 4), entries = {}, archiveData = [])
  let edge_bundle = AssetBundle(header = BundleHeader(magic = 1, version = 1, fileCount = 1, tocOffset = 0, tocSizeBytes = 1), entries = {}, archiveData = [])
  let arg_virtualPath = "/tmp/aipl_test_path"
  let edge_virtualPath = "/tmp/aipl_test_path"
  let resNom = readBundleFile(arg_bundle, arg_virtualPath)
  let resEdge = readBundleFile(edge_bundle, edge_virtualPath)
  assert(resNom.isSome() == false, "readBundleFile nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "readBundleFile boundary resEdge.isSome() == false")
  ret 0
```

---

### `createAssetManager` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createAssetManager(hotReload: bool = false): AssetManager:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hotReload: bool = false` | **Returns**: `AssetManager`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createAssetManager` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `hotReload: bool = true`; exercises core body path returning/computing `AssetManager(assets = m, nextId = 1, hotReloadEnabled = hotReload, imagePaths = ip, imageIds = ii, soundPaths = sp, soundIds = si)`.

```aipl
module tests.functions.asset.asset_manager_z1_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createAssetManager_1(): int:
  let arg_hotReload = true
  let edge_hotReload = false
  let resNom = createAssetManager(arg_hotReload)
  let resEdge = createAssetManager(edge_hotReload)
  assertEqInt(resNom.assets.len(), 0, "createAssetManager nominal resNom.assets.len() == 0")
  assertEqInt(resEdge.assets.len(), 0, "createAssetManager boundary resEdge.assets.len() == 0")
  ret 0
```

---

### `registerAsset` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn registerAsset[T](mgr: AssetManager, path: str, initialData: T): (AssetManager, AssetHandle[T]):`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, path: str, initialData: T` | **Returns**: `(AssetManager, AssetHandle[T])`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `registerAsset` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `initialData: T): (AssetManager = T): (AssetManager()`, `AssetHandle[T]: any = 42`; exercises core body path returning/computing `(nextMgr, handle)`.

```aipl
module tests.functions.asset.asset_manager_z2_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_registerAsset_2(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_initialData = 1
  let edge_initialData = 0
  let resNom = registerAsset(arg_mgr, arg_path, arg_initialData)
  let resEdge = registerAsset(edge_mgr, edge_path, edge_initialData)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t1.id, 4, "registerAsset nominal n_t1.id == 4")
  assertEqInt(e_t1.id, 1, "registerAsset boundary e_t1.id == 1")
  ret 0
```

---

### `getAssetStatus` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn getAssetStatus[T](handle: AssetHandle[T]): int:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: AssetHandle[T]` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `getAssetStatus` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `handle: AssetHandle[T] = AssetHandle(id = 1, path = "/tmp/aipl_test_artifact.tmp", status = 1, refCount = 64, data = Some(42), errorMessage = "aipl_test")`; exercises core body path returning/computing `handle.status`.

```aipl
module tests.functions.asset.asset_manager_z3_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_getAssetStatus_3(): int:
  let arg_handle = AssetHandle(id = 1, path = "/tmp/aipl_test_path", status = 2, refCount = 4, data = None(), errorMessage = "test")
  let edge_handle = AssetHandle(id = 0, path = "/tmp/aipl_test_path", status = 0, refCount = 1, data = None(), errorMessage = "a")
  let resNom = getAssetStatus(arg_handle)
  let resEdge = getAssetStatus(edge_handle)
  assertEqInt(resNom, 2, "getAssetStatus nominal resNom == 2")
  assertEqInt(resEdge, 0, "getAssetStatus boundary resEdge == 0")
  ret 0
```

---

### `retainAsset` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn retainAsset[T](handle: AssetHandle[T]): AssetHandle[T]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: AssetHandle[T]` | **Returns**: `AssetHandle[T]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `retainAsset` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `handle: AssetHandle[T] = AssetHandle(id = 1, path = "/tmp/aipl_test_artifact.tmp", status = 1, refCount = 64, data = Some(42), errorMessage = "aipl_test")`; exercises core body path returning/computing `AssetHandle(`.

```aipl
module tests.functions.asset.asset_manager_z4_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_retainAsset_4(): int:
  let arg_handle = AssetHandle(id = 1, path = "/tmp/aipl_test_path", status = 2, refCount = 4, data = None(), errorMessage = "test")
  let edge_handle = AssetHandle(id = 0, path = "/tmp/aipl_test_path", status = 0, refCount = 1, data = None(), errorMessage = "a")
  let resNom = retainAsset(arg_handle)
  let resEdge = retainAsset(edge_handle)
  assertEqInt(resNom.id, 1, "retainAsset nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "retainAsset boundary resEdge.id == 0")
  ret 0
```

---

### `releaseAsset` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn releaseAsset[T](handle: AssetHandle[T]): AssetHandle[T]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: AssetHandle[T]` | **Returns**: `AssetHandle[T]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `releaseAsset` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `handle: AssetHandle[T] = AssetHandle(id = 1, path = "/tmp/aipl_test_artifact.tmp", status = 1, refCount = 64, data = Some(42), errorMessage = "aipl_test")`; exercises core body path returning/computing `AssetHandle(`.

```aipl
module tests.functions.asset.asset_manager_z5_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_releaseAsset_5(): int:
  let arg_handle = AssetHandle(id = 1, path = "/tmp/aipl_test_path", status = 2, refCount = 4, data = None(), errorMessage = "test")
  let edge_handle = AssetHandle(id = 0, path = "/tmp/aipl_test_path", status = 0, refCount = 1, data = None(), errorMessage = "a")
  let resNom = releaseAsset(arg_handle)
  let resEdge = releaseAsset(edge_handle)
  assertEqInt(resNom.id, 1, "releaseAsset nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "releaseAsset boundary resEdge.id == 0")
  ret 0
```

---

### `notifyAssetFileChanged` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn notifyAssetFileChanged(mgr: AssetManager, changedPath: str): AssetManager:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, changedPath: str` | **Returns**: `AssetManager`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `notifyAssetFileChanged` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `changedPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `AssetManager(assets = m, nextId = mgr.nextId, hotReloadEnabled = mgr.hotReloadEnabled, imagePaths = mgr.imagePaths, imageIds = mgr.imageIds, soundPaths = mgr.soundPaths, soundIds = mgr.soundIds)`.

```aipl
module tests.functions.asset.asset_manager_z6_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_notifyAssetFileChanged_6(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_changedPath = "/tmp/aipl_test_path"
  let edge_changedPath = "/tmp/aipl_test_path"
  let resNom = notifyAssetFileChanged(arg_mgr, arg_changedPath)
  let resEdge = notifyAssetFileChanged(edge_mgr, edge_changedPath)
  assertEqInt(resNom.assets.len(), 0, "notifyAssetFileChanged nominal resNom.assets.len() == 0")
  assertEqInt(resEdge.assets.len(), 0, "notifyAssetFileChanged boundary resEdge.assets.len() == 0")
  ret 0
```

---

### `createImageHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createImageHandle(id: int, path: str): ImageHandle:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, path: str` | **Returns**: `ImageHandle`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createImageHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `id: int = 1`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `ImageHandle(id = id, width = w, height = h, path = path)`.

```aipl
module tests.functions.asset.asset_manager_z7_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createImageHandle_7(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = createImageHandle(arg_id, arg_path)
  let resEdge = createImageHandle(edge_id, edge_path)
  assertEqInt(resNom.id, 1, "createImageHandle nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createImageHandle boundary resEdge.id == 0")
  ret 0
```

---

### `loadImageHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn loadImageHandle(path: str): Result[ImageHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[ImageHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `loadImageHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z8_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_loadImageHandle_8(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadImageHandle(arg_path)
  let resEdge = loadImageHandle(edge_path)
  assert(resNom.isOk() == false, "loadImageHandle nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "loadImageHandle boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodeImageHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn decodeImageHandle(data: bytes, label: str): Result[ImageHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, label: str` | **Returns**: `Result[ImageHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodeImageHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `label: str = "aipl_test"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z9_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_decodeImageHandle_9(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_label = "test"
  let edge_label = "a"
  let resNom = decodeImageHandle(arg_data, arg_label)
  let resEdge = decodeImageHandle(edge_data, edge_label)
  assert(resNom.isOk() == true, "decodeImageHandle nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeImageHandle boundary resEdge.isOk() == true")
  ret 0
```

---

### `createSoundHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createSoundHandle(id: int, path: str): SoundHandle:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, path: str` | **Returns**: `SoundHandle`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createSoundHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `id: int = 1`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `SoundHandle(id = id, duration = dur, path = path)`.

```aipl
module tests.functions.asset.asset_manager_z10_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createSoundHandle_10(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = createSoundHandle(arg_id, arg_path)
  let resEdge = createSoundHandle(edge_id, edge_path)
  assertEqInt(resNom.id, 1, "createSoundHandle nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createSoundHandle boundary resEdge.id == 0")
  ret 0
```

---

### `loadSoundHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn loadSoundHandle(path: str): Result[SoundHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[SoundHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `loadSoundHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z11_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_loadSoundHandle_11(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadSoundHandle(arg_path)
  let resEdge = loadSoundHandle(edge_path)
  assert(resNom.isOk() == true, "loadSoundHandle nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "loadSoundHandle boundary resEdge.isOk() == true")
  ret 0
```

---

### `decodeSoundHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn decodeSoundHandle(data: bytes, label: str): Result[SoundHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, label: str` | **Returns**: `Result[SoundHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodeSoundHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `label: str = "aipl_test"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z12_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_decodeSoundHandle_12(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_label = "test"
  let edge_label = "a"
  let resNom = decodeSoundHandle(arg_data, arg_label)
  let resEdge = decodeSoundHandle(edge_data, edge_label)
  assert(resNom.isOk() == true, "decodeSoundHandle nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeSoundHandle boundary resEdge.isOk() == true")
  ret 0
```

---

### `createFontHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createFontHandle(id: int, path: str): FontHandle:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: int, path: str` | **Returns**: `FontHandle`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createFontHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `id: int = 1`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `FontHandle(id = id, path = path)`.

```aipl
module tests.functions.asset.asset_manager_z13_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createFontHandle_13(): int:
  let arg_id = 1
  let edge_id = 0
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = createFontHandle(arg_id, arg_path)
  let resEdge = createFontHandle(edge_id, edge_path)
  assertEqInt(resNom.id, 1, "createFontHandle nominal resNom.id == 1")
  assertEqInt(resEdge.id, 0, "createFontHandle boundary resEdge.id == 0")
  ret 0
```

---

### `loadFontHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn loadFontHandle(path: str): Result[FontHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[FontHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `loadFontHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z14_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_loadFontHandle_14(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadFontHandle(arg_path)
  let resEdge = loadFontHandle(edge_path)
  assert(resNom.isOk() == false, "loadFontHandle nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "loadFontHandle boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodeFontHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn decodeFontHandle(data: bytes, label: str): Result[FontHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes, label: str` | **Returns**: `Result[FontHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodeFontHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`, `label: str = "aipl_test"`; exercises core body path returning/computing `Err(res.unwrapErr())`.

```aipl
module tests.functions.asset.asset_manager_z15_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_decodeFontHandle_15(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let arg_label = "test"
  let edge_label = "a"
  let resNom = decodeFontHandle(arg_data, arg_label)
  let resEdge = decodeFontHandle(edge_data, edge_label)
  assert(resNom.isOk() == true, "decodeFontHandle nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeFontHandle boundary resEdge.isOk() == true")
  ret 0
```

---

### `createSpriteSheet` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createSpriteSheet(imageId: int, frameWidth: int, frameHeight: int, columns: int, totalFrames: int): SpriteSheet:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `imageId: int, frameWidth: int, frameHeight: int, columns: int, totalFrames: int` | **Returns**: `SpriteSheet`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createSpriteSheet` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `imageId: int = 1`, `frameWidth: int = 1`, `frameHeight: int = 1`, `columns: int = 1`, `totalFrames: int = 64`; exercises core body path returning/computing `SpriteSheet(`.

```aipl
module tests.functions.asset.asset_manager_z16_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createSpriteSheet_16(): int:
  let arg_imageId = 4
  let edge_imageId = 1
  let arg_frameWidth = 4
  let edge_frameWidth = 1
  let arg_frameHeight = 4
  let edge_frameHeight = 1
  let arg_columns = 4
  let edge_columns = 1
  let arg_totalFrames = 4
  let edge_totalFrames = 1
  let resNom = createSpriteSheet(arg_imageId, arg_frameWidth, arg_frameHeight, arg_columns, arg_totalFrames)
  let resEdge = createSpriteSheet(edge_imageId, edge_frameWidth, edge_frameHeight, edge_columns, edge_totalFrames)
  assertEqInt(resNom.imageId, 4, "createSpriteSheet nominal resNom.imageId == 4")
  assertEqInt(resEdge.imageId, 1, "createSpriteSheet boundary resEdge.imageId == 1")
  ret 0
```

---

### `createAnimationClip` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createAnimationClip(startFrame: int, frameCount: int, fps: float, loopClip: bool): AnimationClip:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startFrame: int, frameCount: int, fps: float, loopClip: bool` | **Returns**: `AnimationClip`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `createAnimationClip` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `startFrame: int = 1`, `frameCount: int = 64`, `fps: float = 1.0`, `loopClip: bool = true`; exercises core body path returning/computing `AnimationClip(`.

```aipl
module tests.functions.asset.asset_manager_z17_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createAnimationClip_17(): int:
  let arg_startFrame = 4
  let edge_startFrame = 1
  let arg_frameCount = 4
  let edge_frameCount = 1
  let arg_fps = 1.0
  let edge_fps = 0.5
  let arg_loopClip = true
  let edge_loopClip = false
  let resNom = createAnimationClip(arg_startFrame, arg_frameCount, arg_fps, arg_loopClip)
  let resEdge = createAnimationClip(edge_startFrame, edge_frameCount, edge_fps, edge_loopClip)
  assertEqInt(resNom.startFrame, 4, "createAnimationClip nominal resNom.startFrame == 4")
  assertEqInt(resEdge.startFrame, 1, "createAnimationClip boundary resEdge.startFrame == 1")
  ret 0
```

---

### `sampleAnimationFrame` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn sampleAnimationFrame(clip: AnimationClip, elapsedSec: float): int:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `clip: AnimationClip, elapsedSec: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `sampleAnimationFrame` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `clip: AnimationClip = AnimationClip(startFrame = 1, frameCount = 64, fps = 1.0, loopClip = true)`, `elapsedSec: float = 1.0`; exercises core body path returning/computing `clip.startFrame + rawIdx`.

```aipl
module tests.functions.asset.asset_manager_z18_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_sampleAnimationFrame_18(): int:
  let arg_clip = AnimationClip(startFrame = 4, frameCount = 4, fps = 1.0, loopClip = true)
  let edge_clip = AnimationClip(startFrame = 1, frameCount = 1, fps = 0.5, loopClip = false)
  let arg_elapsedSec = 1.0
  let edge_elapsedSec = 0.5
  let resNom = sampleAnimationFrame(arg_clip, arg_elapsedSec)
  let resEdge = sampleAnimationFrame(edge_clip, edge_elapsedSec)
  assertEqInt(resNom, 6, "sampleAnimationFrame nominal resNom == 6")
  assertEqInt(resEdge, 1, "sampleAnimationFrame boundary resEdge == 1")
  ret 0
```

---

### `drawSpriteFrame` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn drawSpriteFrame(sheet: SpriteSheet, frameIndex: int, dx: float, dy: float, dw: float, dh: float):`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `drawSpriteFrame` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `sheet: SpriteSheet = SpriteSheet(imageId = 1, frameWidth = 1, frameHeight = 1, columns = 1, totalFrames = 64)`, `frameIndex: int = 0`, `dx: float = 1.0`, `dy: float = 1.0`, `dw: float = 1.0`, `dh: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.asset.asset_manager_z19_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_drawSpriteFrame_19(): int:
  mut completedCalls = 0
  let arg_sheet = SpriteSheet(imageId = 4, frameWidth = 4, frameHeight = 4, columns = 4, totalFrames = 4)
  let edge_sheet = SpriteSheet(imageId = 1, frameWidth = 1, frameHeight = 1, columns = 1, totalFrames = 1)
  let arg_frameIndex = 4
  let edge_frameIndex = 1
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dw = 2.0
  let edge_dw = 1.0
  let arg_dh = 2.0
  let edge_dh = 1.0
  drawSpriteFrame(arg_sheet, arg_frameIndex, arg_dx, arg_dy, arg_dw, arg_dh)
  drawSpriteFrame(edge_sheet, edge_frameIndex, edge_dx, edge_dy, edge_dw, edge_dh)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawSpriteFrame nominal and boundary void calls completed")
  ret 0
```

---

### `drawAnimatedSprite` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn drawAnimatedSprite(sheet: SpriteSheet, clip: AnimationClip, elapsedSec: float, dx: float, dy: float, dw: float, dh: float):`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `drawAnimatedSprite` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `sheet: SpriteSheet = SpriteSheet(imageId = 1, frameWidth = 1, frameHeight = 1, columns = 1, totalFrames = 64)`, `clip: AnimationClip = AnimationClip(startFrame = 1, frameCount = 64, fps = 1.0, loopClip = true)`, `elapsedSec: float = 1.0`, `dx: float = 1.0`, `dy: float = 1.0`, `dw: float = 1.0`, `dh: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.asset.asset_manager_z20_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_drawAnimatedSprite_20(): int:
  mut completedCalls = 0
  let arg_sheet = SpriteSheet(imageId = 4, frameWidth = 4, frameHeight = 4, columns = 4, totalFrames = 4)
  let edge_sheet = SpriteSheet(imageId = 1, frameWidth = 1, frameHeight = 1, columns = 1, totalFrames = 1)
  let arg_clip = AnimationClip(startFrame = 4, frameCount = 4, fps = 1.0, loopClip = true)
  let edge_clip = AnimationClip(startFrame = 1, frameCount = 1, fps = 0.5, loopClip = false)
  let arg_elapsedSec = 1.0
  let edge_elapsedSec = 0.5
  let arg_dx = 1.0
  let edge_dx = 0.5
  let arg_dy = 1.0
  let edge_dy = 0.5
  let arg_dw = 2.0
  let edge_dw = 1.0
  let arg_dh = 2.0
  let edge_dh = 1.0
  drawAnimatedSprite(arg_sheet, arg_clip, arg_elapsedSec, arg_dx, arg_dy, arg_dw, arg_dh)
  drawAnimatedSprite(edge_sheet, edge_clip, edge_elapsedSec, edge_dx, edge_dy, edge_dw, edge_dh)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawAnimatedSprite nominal and boundary void calls completed")
  ret 0
```

---

### `measureLabel` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn measureLabel(font: FontHandle, text: str, size: float): Vec2:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `font: FontHandle, text: str, size: float` | **Returns**: `Vec2`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `measureLabel` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `font: FontHandle = FontHandle(id = 1, path = "/tmp/aipl_test_artifact.tmp")`, `text: str = "aipl_test"`, `size: float = 1.0`; exercises core body path returning/computing `measureText(text, size)`.

```aipl
module tests.functions.asset.asset_manager_z21_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_measureLabel_21(): int:
  let arg_font = FontHandle(id = 1, path = "/tmp/aipl_test_path")
  let edge_font = FontHandle(id = 0, path = "/tmp/aipl_test_path")
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let resNom = measureLabel(arg_font, arg_text, arg_size)
  let resEdge = measureLabel(edge_font, edge_text, edge_size)
  assertApproxEq(resNom.x, 25.0, 0.001, "measureLabel nominal resNom.x ~= 25.0")
  assertApproxEq(resEdge.x, 6.0, 0.001, "measureLabel boundary resEdge.x ~= 6.0")
  ret 0
```

---

### `drawLabel` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn drawLabel(font: FontHandle, x: float, y: float, text: str, size: float, color: int):`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `drawLabel` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `font: FontHandle = FontHandle(id = 1, path = "/tmp/aipl_test_artifact.tmp")`, `x: float = 1.0`, `y: float = 1.0`, `text: str = "aipl_test"`, `size: float = 1.0`, `color: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.asset.asset_manager_z22_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_drawLabel_22(): int:
  mut completedCalls = 0
  let arg_font = FontHandle(id = 1, path = "/tmp/aipl_test_path")
  let edge_font = FontHandle(id = 0, path = "/tmp/aipl_test_path")
  let arg_x = 1.0
  let edge_x = 0.5
  let arg_y = 1.0
  let edge_y = 0.5
  let arg_text = "test"
  let edge_text = "a"
  let arg_size = 1.0
  let edge_size = 0.5
  let arg_color = 1
  let edge_color = 0
  drawLabel(arg_font, arg_x, arg_y, arg_text, arg_size, arg_color)
  drawLabel(edge_font, edge_x, edge_y, edge_text, edge_size, edge_color)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "drawLabel nominal and boundary void calls completed")
  ret 0
```

---

### `findCachedId` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn findCachedId(paths: [str], ids: [int], targetPath: str): int:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `paths: [str], ids: [int], targetPath: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `findCachedId` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `paths: [str] = ["/tmp/aipl_test_artifact.tmp"]`, `ids: [int] = [1]`, `targetPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.asset.asset_manager_z23_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_findCachedId_23(): int:
  let arg_paths = ["/tmp/aipl_test_path"]
  let edge_paths = []
  let arg_ids = [1]
  let edge_ids = []
  let arg_targetPath = "/tmp/aipl_test_path"
  let edge_targetPath = "/tmp/aipl_test_path"
  let resNom = findCachedId(arg_paths, arg_ids, arg_targetPath)
  let resEdge = findCachedId(edge_paths, edge_ids, edge_targetPath)
  assertEqInt(resNom, 1, "findCachedId nominal resNom == 1")
  assertEqInt(resEdge, 0, "findCachedId boundary resEdge == 0")
  ret 0
```

---

### `getCachedImage` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn getCachedImage(mgr: AssetManager, path: str): int:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `getCachedImage` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.asset.asset_manager_z24_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_getCachedImage_24(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = getCachedImage(arg_mgr, arg_path)
  let resEdge = getCachedImage(edge_mgr, edge_path)
  assertEqInt(resNom, 100, "getCachedImage nominal resNom == 100")
  assertEqInt(resEdge, 100, "getCachedImage boundary resEdge == 100")
  ret 0
```

---

### `getCachedSound` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn getCachedSound(mgr: AssetManager, path: str): int:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `getCachedSound` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.asset.asset_manager_z25_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_getCachedSound_25(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = getCachedSound(arg_mgr, arg_path)
  let resEdge = getCachedSound(edge_mgr, edge_path)
  assertEqInt(resNom, 20, "getCachedSound nominal resNom == 20")
  assertEqInt(resEdge, 20, "getCachedSound boundary resEdge == 20")
  ret 0
```

---

### `cacheImage` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn cacheImage(mgr: AssetManager, path: str, imageId: int): AssetManager:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, path: str, imageId: int` | **Returns**: `AssetManager`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `cacheImage` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `imageId: int = 1`; exercises core body path returning/computing `AssetManager(assets = m, nextId = mgr.nextId, hotReloadEnabled = mgr.hotReloadEnabled, imagePaths = nextPaths, imageIds = nextIds, soundPaths = mgr.soundPaths, soundIds = mgr.soundIds)`.

```aipl
module tests.functions.asset.asset_manager_z26_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_cacheImage_26(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_imageId = 4
  let edge_imageId = 1
  let resNom = cacheImage(arg_mgr, arg_path, arg_imageId)
  let resEdge = cacheImage(edge_mgr, edge_path, edge_imageId)
  assertEqInt(resNom.assets.len(), 0, "cacheImage nominal resNom.assets.len() == 0")
  assertEqInt(resEdge.assets.len(), 0, "cacheImage boundary resEdge.assets.len() == 0")
  ret 0
```

---

### `cacheSound` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn cacheSound(mgr: AssetManager, path: str, soundId: int): AssetManager:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mgr: AssetManager, path: str, soundId: int` | **Returns**: `AssetManager`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `cacheSound` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `mgr: AssetManager = AssetManager(assets = Map(), nextId = 1, hotReloadEnabled = true, imagePaths = ["/tmp/aipl_test_artifact.tmp"], imageIds = [1], soundPaths = ["/tmp/aipl_test_artifact.tmp"], soundIds = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`, `soundId: int = 1`; exercises core body path returning/computing `AssetManager(assets = m, nextId = mgr.nextId, hotReloadEnabled = mgr.hotReloadEnabled, imagePaths = mgr.imagePaths, imageIds = mgr.imageIds, soundPaths = nextPaths, soundIds = nextIds)`.

```aipl
module tests.functions.asset.asset_manager_z27_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_cacheSound_27(): int:
  let arg_mgr = AssetManager(assets = {}, nextId = 4, hotReloadEnabled = true, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let edge_mgr = AssetManager(assets = {}, nextId = 1, hotReloadEnabled = false, imagePaths = [], imageIds = [], soundPaths = [], soundIds = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_soundId = 4
  let edge_soundId = 1
  let resNom = cacheSound(arg_mgr, arg_path, arg_soundId)
  let resEdge = cacheSound(edge_mgr, edge_path, edge_soundId)
  assertEqInt(resNom.assets.len(), 0, "cacheSound nominal resNom.assets.len() == 0")
  assertEqInt(resEdge.assets.len(), 0, "cacheSound boundary resEdge.assets.len() == 0")
  ret 0
```

---

### `createVideoSession` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn createVideoSession(path: str, fps: int = 30): VideoSession:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, fps: int = 30` | **Returns**: `VideoSession`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `createVideoSession` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `fps: int = 1`; exercises core body path returning/computing `VideoSession(path = path, fps = safeFps, frameCount = 0, active = false)`.

```aipl
module tests.functions.asset.asset_manager_z28_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_createVideoSession_28(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_fps = 2
  let edge_fps = 0
  let resNom = createVideoSession(arg_path, arg_fps)
  let resEdge = createVideoSession(edge_path, edge_fps)
  assertEqStr(resNom.path, "/tmp/aipl_test_path", "createVideoSession nominal string matches")
  assertEqStr(resEdge.path, "/tmp/aipl_test_path", "createVideoSession boundary string matches")
  ret 0
```

---

### `startVideoCapture` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn startVideoCapture(mut session: VideoSession): Result[VideoSession, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut session: VideoSession` | **Returns**: `Result[VideoSession, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `startVideoCapture` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `session: VideoSession = VideoSession(path = "/tmp/aipl_test_artifact.tmp", fps = 1, frameCount = 64, active = true)`; exercises core body path returning/computing `Ok(session)`.

```aipl
module tests.functions.asset.asset_manager_z29_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_startVideoCapture_29(): int:
  let arg_session = VideoSession(path = "/tmp/aipl_test_path", fps = 2, frameCount = 4, active = true)
  let edge_session = VideoSession(path = "/tmp/aipl_test_path", fps = 0, frameCount = 1, active = false)
  let resNom = startVideoCapture(arg_session)
  let resEdge = startVideoCapture(edge_session)
  assert(resNom.isOk() == true, "startVideoCapture nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "startVideoCapture boundary resEdge.isOk() == true")
  ret 0
```

---

### `captureVideoFrame` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn captureVideoFrame(mut session: VideoSession): VideoSession:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut session: VideoSession` | **Returns**: `VideoSession`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `captureVideoFrame` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `session: VideoSession = VideoSession(path = "/tmp/aipl_test_artifact.tmp", fps = 1, frameCount = 64, active = true)`; exercises core body path returning/computing `session`.

```aipl
module tests.functions.asset.asset_manager_z30_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_captureVideoFrame_30(): int:
  let arg_session = VideoSession(path = "/tmp/aipl_test_path", fps = 2, frameCount = 4, active = true)
  let edge_session = VideoSession(path = "/tmp/aipl_test_path", fps = 0, frameCount = 1, active = false)
  let resNom = captureVideoFrame(arg_session)
  let resEdge = captureVideoFrame(edge_session)
  assertEqStr(resNom.path, "/tmp/aipl_test_path", "captureVideoFrame nominal string matches")
  assertEqStr(resEdge.path, "/tmp/aipl_test_path", "captureVideoFrame boundary string matches")
  ret 0
```

---

### `stopVideoCapture` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn stopVideoCapture(mut session: VideoSession): Result[int, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut session: VideoSession` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `stopVideoCapture` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `session: VideoSession = VideoSession(path = "/tmp/aipl_test_artifact.tmp", fps = 1, frameCount = 64, active = true)`; exercises core body path returning/computing `Ok(session.frameCount)`.

```aipl
module tests.functions.asset.asset_manager_z31_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_stopVideoCapture_31(): int:
  let arg_session = VideoSession(path = "/tmp/aipl_test_path", fps = 2, frameCount = 4, active = true)
  let edge_session = VideoSession(path = "/tmp/aipl_test_path", fps = 0, frameCount = 1, active = false)
  let resNom = stopVideoCapture(arg_session)
  let resEdge = stopVideoCapture(edge_session)
  assert(resNom.isOk() == true, "stopVideoCapture nominal resNom.isOk() == true")
  assert(resEdge.isOk() == false, "stopVideoCapture boundary resEdge.isOk() == false")
  ret 0
```

---

### `isVideoCaptureActive` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn isVideoCaptureActive(session: VideoSession): bool:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `session: VideoSession` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `isVideoCaptureActive` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `session: VideoSession = VideoSession(path = "/tmp/aipl_test_artifact.tmp", fps = 1, frameCount = 64, active = true)`; exercises core body path returning/computing `session.active and isRecordingVideo()`.

```aipl
module tests.functions.asset.asset_manager_z32_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_isVideoCaptureActive_32(): int:
  let arg_session = VideoSession(path = "/tmp/aipl_test_path", fps = 2, frameCount = 4, active = true)
  let edge_session = VideoSession(path = "/tmp/aipl_test_path", fps = 0, frameCount = 1, active = false)
  let resNom = isVideoCaptureActive(arg_session)
  let resEdge = isVideoCaptureActive(edge_session)
  assert(resNom == false, "isVideoCaptureActive nominal resNom == false")
  assert(resEdge == false, "isVideoCaptureActive boundary resEdge == false")
  ret 0
```

---

### `takeScreenshot` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn takeScreenshot(path: str): bool:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `takeScreenshot` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `saveScreenshot(path)`.

```aipl
module tests.functions.asset.asset_manager_z33_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_takeScreenshot_33(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = takeScreenshot(arg_path)
  let resEdge = takeScreenshot(edge_path)
  assert(resNom == false, "takeScreenshot nominal resNom == false")
  assert(resEdge == false, "takeScreenshot boundary resEdge == false")
  ret 0
```

---

### `captureScreenshotHandle` (`std/asset/asset_manager.aipl`)

- **Signature**: `pub fn captureScreenshotHandle(path: str): Result[ImageHandle, str]:`
- **Import**: `import * from "std/asset/asset_manager"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[ImageHandle, str]`
- **Unit Test**: `tests/functions/asset/asset_manager_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `captureScreenshotHandle` reference-counted asset loading (`retainAsset`/`releaseAsset`), hot-reload version bumps, and sprite sheet animation frame sampling. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `loadImageHandle(path)`.

```aipl
module tests.functions.asset.asset_manager_z34_test
import * from "std/asset/asset_manager"
import { Vec2 } from "std/math/vec_math"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_asset_manager_captureScreenshotHandle_34(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = captureScreenshotHandle(arg_path)
  let resEdge = captureScreenshotHandle(edge_path)
  assert(resNom.isOk() == false, "captureScreenshotHandle nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "captureScreenshotHandle boundary resEdge.isOk() == false")
  ret 0
```

---

### `createAtlasBin` (`std/asset/atlas_packer.aipl`)

- **Signature**: `pub fn createAtlasBin(width: int, height: int, gutterPx: int = 2): AtlasBin:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, gutterPx: int = 2` | **Returns**: `AtlasBin`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `createAtlasBin` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `gutterPx: int = 1`; exercises core body path returning/computing `AtlasBin(`.

```aipl
module tests.functions.asset.atlas_packer_z1_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_createAtlasBin_1(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_gutterPx = 1
  let edge_gutterPx = 0
  let resNom = createAtlasBin(arg_width, arg_height, arg_gutterPx)
  let resEdge = createAtlasBin(edge_width, edge_height, edge_gutterPx)
  assertEqInt(resNom.width, 4, "createAtlasBin nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "createAtlasBin boundary resEdge.width == 1")
  ret 0
```

---

### `minIntPack` (`std/asset/atlas_packer.aipl`)

- **Signature**: `fn minIntPack(a: int, b: int): int:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `minIntPack` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.atlas_packer_z2_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_minIntPack_2(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = minIntPack(arg_a, arg_b)
  let resEdge = minIntPack(edge_a, edge_b)
  assertEqInt(resNom, 2, "minIntPack nominal resNom == 2")
  assertEqInt(resEdge, 0, "minIntPack boundary resEdge == 0")
  ret 0
```

---

### `maxIntPack` (`std/asset/atlas_packer.aipl`)

- **Signature**: `fn maxIntPack(a: int, b: int): int:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `maxIntPack` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.atlas_packer_z3_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_maxIntPack_3(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = maxIntPack(arg_a, arg_b)
  let resEdge = maxIntPack(edge_a, edge_b)
  assertEqInt(resNom, 4, "maxIntPack nominal resNom == 4")
  assertEqInt(resEdge, 1, "maxIntPack boundary resEdge == 1")
  ret 0
```

---

### `rectsIntersect` (`std/asset/atlas_packer.aipl`)

- **Signature**: `fn rectsIntersect(a: PackRect, b: PackRect): bool:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: PackRect, b: PackRect` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `rectsIntersect` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `a: PackRect = PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)`, `b: PackRect = PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.asset.atlas_packer_z4_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_rectsIntersect_4(): int:
  let arg_a = PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)
  let edge_a = PackRect(id = 0, width = 4, height = 4, x = 0, y = 0, isRotated = false, isPacked = false)
  let arg_b = PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)
  let edge_b = PackRect(id = 0, width = 4, height = 4, x = 0, y = 0, isRotated = false, isPacked = false)
  let resNom = rectsIntersect(arg_a, arg_b)
  let resEdge = rectsIntersect(edge_a, edge_b)
  assert(resNom == true, "rectsIntersect nominal resNom == true")
  assert(resEdge == true, "rectsIntersect boundary resEdge == true")
  ret 0
```

---

### `isContainedIn` (`std/asset/atlas_packer.aipl`)

- **Signature**: `fn isContainedIn(a: PackRect, b: PackRect): bool:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: PackRect, b: PackRect` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `isContainedIn` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `a: PackRect = PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)`, `b: PackRect = PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)`; exercises core body path returning/computing `a.x >= b.x and a.y >= b.y and (a.x + a.width <= b.x + b.width) and (a.y + a.height <= b.y + b.height)`.

```aipl
module tests.functions.asset.atlas_packer_z5_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_isContainedIn_5(): int:
  let arg_a = PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)
  let edge_a = PackRect(id = 0, width = 4, height = 4, x = 0, y = 0, isRotated = false, isPacked = false)
  let arg_b = PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)
  let edge_b = PackRect(id = 0, width = 4, height = 4, x = 0, y = 0, isRotated = false, isPacked = false)
  let resNom = isContainedIn(arg_a, arg_b)
  let resEdge = isContainedIn(edge_a, edge_b)
  assert(resNom == true, "isContainedIn nominal resNom == true")
  assert(resEdge == true, "isContainedIn boundary resEdge == true")
  ret 0
```

---

### `calculateAtlasOccupancy` (`std/asset/atlas_packer.aipl`)

- **Signature**: `pub fn calculateAtlasOccupancy(bin: AtlasBin): float:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bin: AtlasBin` | **Returns**: `float`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `calculateAtlasOccupancy` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `bin: AtlasBin = AtlasBin(width = 128, height = 128, paddingGutter = 1, freeRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], packedRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], occupancyRatio = 0.5)`; exercises core body path returning/computing `float(usedArea) / float(totalArea)`.

```aipl
module tests.functions.asset.atlas_packer_z6_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_calculateAtlasOccupancy_6(): int:
  let arg_bin = AtlasBin(width = 4, height = 4, paddingGutter = 4, freeRects = [], packedRects = [], occupancyRatio = 1.0)
  let edge_bin = AtlasBin(width = 4, height = 4, paddingGutter = 1, freeRects = [], packedRects = [], occupancyRatio = 0.5)
  let resNom = calculateAtlasOccupancy(arg_bin)
  let resEdge = calculateAtlasOccupancy(edge_bin)
  assertApproxEq(resNom, 0.0, 0.001, "calculateAtlasOccupancy nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "calculateAtlasOccupancy boundary resEdge ~= 0.0")
  ret 0
```

---

### `packRectMaxRects` (`std/asset/atlas_packer.aipl`)

- **Signature**: `pub fn packRectMaxRects(bin: AtlasBin, rect: PackRect, allowRotation: bool = false): (AtlasBin, Option[PackRect]):`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bin: AtlasBin, rect: PackRect, allowRotation: bool = false` | **Returns**: `(AtlasBin, Option[PackRect])`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `packRectMaxRects` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `bin: AtlasBin = AtlasBin(width = 128, height = 128, paddingGutter = 1, freeRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], packedRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], occupancyRatio = 0.5)`, `rect: PackRect = PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)`, `allowRotation: bool = true`, `Option[PackRect]: any = 42`; exercises core body path returning/computing `(finalBin, Some(placed))`.

```aipl
module tests.functions.asset.atlas_packer_z7_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_packRectMaxRects_7(): int:
  let arg_bin = AtlasBin(width = 4, height = 4, paddingGutter = 4, freeRects = [], packedRects = [], occupancyRatio = 1.0)
  let edge_bin = AtlasBin(width = 4, height = 4, paddingGutter = 1, freeRects = [], packedRects = [], occupancyRatio = 0.5)
  let arg_rect = PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)
  let edge_rect = PackRect(id = 0, width = 4, height = 4, x = 0, y = 0, isRotated = false, isPacked = false)
  let arg_allowRotation = true
  let edge_allowRotation = false
  let resNom = packRectMaxRects(arg_bin, arg_rect, arg_allowRotation)
  let resEdge = packRectMaxRects(edge_bin, edge_rect, edge_allowRotation)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.width, 4, "packRectMaxRects nominal n_t0.width == 4")
  assertEqInt(e_t0.width, 4, "packRectMaxRects boundary e_t0.width == 4")
  ret 0
```

---

### `packRectangles` (`std/asset/atlas_packer.aipl`)

- **Signature**: `pub fn packRectangles(bin: AtlasBin, rects: [PackRect], allowRotation: bool = false): (AtlasBin, [PackRect]):`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bin: AtlasBin, rects: [PackRect], allowRotation: bool = false` | **Returns**: `(AtlasBin, [PackRect])`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `packRectangles` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `bin: AtlasBin = AtlasBin(width = 128, height = 128, paddingGutter = 1, freeRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], packedRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], occupancyRatio = 0.5)`, `rects: [PackRect] = [PackRect(id = 1, width = 128, height = 128, x = 1, y = 1, isRotated = true, isPacked = true)]`, `allowRotation: bool = true`, `[PackRect]: any = 42`; exercises core body path returning/computing `(curBin, outList)`.

```aipl
module tests.functions.asset.atlas_packer_z8_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_packRectangles_8(): int:
  let arg_bin = AtlasBin(width = 4, height = 4, paddingGutter = 4, freeRects = [], packedRects = [], occupancyRatio = 1.0)
  let edge_bin = AtlasBin(width = 4, height = 4, paddingGutter = 1, freeRects = [], packedRects = [], occupancyRatio = 0.5)
  let arg_rects = [PackRect(id = 1, width = 4, height = 4, x = 1, y = 1, isRotated = true, isPacked = true)]
  let edge_rects = []
  let arg_allowRotation = true
  let edge_allowRotation = false
  let resNom = packRectangles(arg_bin, arg_rects, arg_allowRotation)
  let resEdge = packRectangles(edge_bin, edge_rects, edge_allowRotation)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.width, 4, "packRectangles nominal n_t0.width == 4")
  assertEqInt(e_t0.width, 4, "packRectangles boundary e_t0.width == 4")
  ret 0
```

---

### `checkBleedGutters` (`std/asset/atlas_packer.aipl`)

- **Signature**: `pub fn checkBleedGutters(bin: AtlasBin, minGutterPx: int): bool:`
- **Import**: `import * from "std/asset/atlas_packer"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bin: AtlasBin, minGutterPx: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/atlas_packer_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `checkBleedGutters` MaxRects bin packing occupancy, zero rectangle overlap, and >= 2px bleed gutter verification (`checkBleedGutters`). Concrete nominal inputs: `bin: AtlasBin = AtlasBin(width = 128, height = 128, paddingGutter = 1, freeRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], packedRects = [PackRect(id = 0, width = 0, height = 0, x = 0, y = 0, isRotated = 0, isPacked = 0)], occupancyRatio = 0.5)`, `minGutterPx: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.asset.atlas_packer_z9_test
import * from "std/asset/atlas_packer"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_atlas_packer_checkBleedGutters_9(): int:
  let arg_bin = AtlasBin(width = 4, height = 4, paddingGutter = 4, freeRects = [], packedRects = [], occupancyRatio = 1.0)
  let edge_bin = AtlasBin(width = 4, height = 4, paddingGutter = 1, freeRects = [], packedRects = [], occupancyRatio = 0.5)
  let arg_minGutterPx = 4
  let edge_minGutterPx = 1
  let resNom = checkBleedGutters(arg_bin, arg_minGutterPx)
  let resEdge = checkBleedGutters(edge_bin, edge_minGutterPx)
  assert(resNom == true, "checkBleedGutters nominal resNom == true")
  assert(resEdge == true, "checkBleedGutters boundary resEdge == true")
  ret 0
```

---

### `parseTtfTables` (`std/asset/font_sdf.aipl`)

- **Signature**: `pub fn parseTtfTables(fontFileBytes: [int]): bool:`
- **Import**: `import * from "std/asset/font_sdf"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fontFileBytes: [int]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/font_sdf_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `parseTtfTables` Signed Distance Field glyph generation, inside (`> 0.5`) vs outside (`< 0.5`) bilinear sampling, and kerning advance layout. Concrete nominal inputs: `fontFileBytes: [int] = [64]`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.asset.font_sdf_z1_test
import * from "std/asset/font_sdf"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_font_sdf_parseTtfTables_1(): int:
  let arg_fontFileBytes = [4]
  let edge_fontFileBytes = []
  let resNom = parseTtfTables(arg_fontFileBytes)
  let resEdge = parseTtfTables(edge_fontFileBytes)
  assert(resNom == false, "parseTtfTables nominal resNom == false")
  assert(resEdge == false, "parseTtfTables boundary resEdge == false")
  ret 0
```

---

### `computeSignedDistance` (`std/asset/font_sdf.aipl`)

- **Signature**: `pub fn computeSignedDistance(px: float, py: float, curvePoints: [float]): float:`
- **Import**: `import * from "std/asset/font_sdf"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `px: float, py: float, curvePoints: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/asset/font_sdf_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `computeSignedDistance` Signed Distance Field glyph generation, inside (`> 0.5`) vs outside (`< 0.5`) bilinear sampling, and kerning advance layout. Concrete nominal inputs: `px: float = 1.0`, `py: float = 1.0`, `curvePoints: [float] = [1.0]`; exercises core body path returning/computing `if inside: -minDist else: minDist`.

```aipl
module tests.functions.asset.font_sdf_z2_test
import * from "std/asset/font_sdf"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_font_sdf_computeSignedDistance_2(): int:
  let arg_px = 1.0
  let edge_px = 0.5
  let arg_py = 1.0
  let edge_py = 0.5
  let arg_curvePoints = [1.0]
  let edge_curvePoints = []
  let resNom = computeSignedDistance(arg_px, arg_py, arg_curvePoints)
  let resEdge = computeSignedDistance(edge_px, edge_py, edge_curvePoints)
  assertApproxEq(resNom, 1000.0, 0.001, "computeSignedDistance nominal resNom ~= 1000.0")
  assertApproxEq(resEdge, 1000.0, 0.001, "computeSignedDistance boundary resEdge ~= 1000.0")
  ret 0
```

---

### `generateSdfGlyph` (`std/asset/font_sdf.aipl`)

- **Signature**: `pub fn generateSdfGlyph(glyphCurves: [float], width: int, height: int, radius: float): [int]:`
- **Import**: `import * from "std/asset/font_sdf"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `glyphCurves: [float], width: int, height: int, radius: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/font_sdf_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `generateSdfGlyph` Signed Distance Field glyph generation, inside (`> 0.5`) vs outside (`< 0.5`) bilinear sampling, and kerning advance layout. Concrete nominal inputs: `glyphCurves: [float] = [1.0]`, `width: int = 128`, `height: int = 128`, `radius: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.font_sdf_z3_test
import * from "std/asset/font_sdf"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_font_sdf_generateSdfGlyph_3(): int:
  let arg_glyphCurves = [2.0]
  let edge_glyphCurves = []
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_radius = 2.0
  let edge_radius = 1.0
  let resNom = generateSdfGlyph(arg_glyphCurves, arg_width, arg_height, arg_radius)
  let resEdge = generateSdfGlyph(edge_glyphCurves, edge_width, edge_height, edge_radius)
  assertEqInt(resNom.len(), 16, "generateSdfGlyph nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 1, "generateSdfGlyph boundary resEdge.len() == 1")
  ret 0
```

---

### `sampleSdfAtlas` (`std/asset/font_sdf.aipl`)

- **Signature**: `pub fn sampleSdfAtlas(atlas: FontSdfAtlas, codepoint: int): Option[GlyphMetric]:`
- **Import**: `import * from "std/asset/font_sdf"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `atlas: FontSdfAtlas, codepoint: int` | **Returns**: `Option[GlyphMetric]`
- **Unit Test**: `tests/functions/asset/font_sdf_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `sampleSdfAtlas` Signed Distance Field glyph generation, inside (`> 0.5`) vs outside (`< 0.5`) bilinear sampling, and kerning advance layout. Concrete nominal inputs: `atlas: FontSdfAtlas = FontSdfAtlas(textureWidth = 1, textureHeight = 1, sdfRadiusPx = 1.0, glyphs = Map(), distanceFieldBytes = [64])`, `codepoint: int = 1`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.asset.font_sdf_z4_test
import * from "std/asset/font_sdf"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_font_sdf_sampleSdfAtlas_4(): int:
  let arg_atlas = FontSdfAtlas(textureWidth = 4, textureHeight = 4, sdfRadiusPx = 2.0, glyphs = {}, distanceFieldBytes = [])
  let edge_atlas = FontSdfAtlas(textureWidth = 1, textureHeight = 1, sdfRadiusPx = 1.0, glyphs = {}, distanceFieldBytes = [])
  let arg_codepoint = 4
  let edge_codepoint = 1
  let resNom = sampleSdfAtlas(arg_atlas, arg_codepoint)
  let resEdge = sampleSdfAtlas(edge_atlas, edge_codepoint)
  assert(resNom.isSome() == false, "sampleSdfAtlas nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "sampleSdfAtlas boundary resEdge.isSome() == false")
  ret 0
```

---

### `parseGltfJson` (`std/asset/gltf_mesh_loader.aipl`)

- **Signature**: `pub fn parseGltfJson(jsonStr: str, binBuffer: [int]): Option[GltfScene]:`
- **Import**: `import * from "std/asset/gltf_mesh_loader"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jsonStr: str, binBuffer: [int]` | **Returns**: `Option[GltfScene]`
- **Unit Test**: `tests/functions/asset/gltf_mesh_loader_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `parseGltfJson` glTF 2.0 `.glb` magic `0x46546C67` header validation, JSON/BIN chunk extraction, and float/index buffer decoding. Concrete nominal inputs: `jsonStr: str = "{\"ok\":true}"`, `binBuffer: [int] = [1]`; exercises core body path returning/computing `Some(GltfScene(meshes = [mesh], nodes = [node], rootNodes = [0]))`.

```aipl
module tests.functions.asset.gltf_mesh_loader_z1_test
import * from "std/asset/gltf_mesh_loader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gltf_mesh_loader_parseGltfJson_1(): int:
  let arg_jsonStr = "{\"a\":1}"
  let edge_jsonStr = "{}"
  let arg_binBuffer = [4]
  let edge_binBuffer = []
  let resNom = parseGltfJson(arg_jsonStr, arg_binBuffer)
  let resEdge = parseGltfJson(edge_jsonStr, edge_binBuffer)
  assert(resNom.isSome() == false, "parseGltfJson nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "parseGltfJson boundary resEdge.isSome() == false")
  ret 0
```

---

### `readGlbU32LE` (`std/asset/gltf_mesh_loader.aipl`)

- **Signature**: `fn readGlbU32LE(b: [int], off: int): int:`
- **Import**: `import * from "std/asset/gltf_mesh_loader"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/gltf_mesh_loader_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `readGlbU32LE` glTF 2.0 `.glb` magic `0x46546C67` header validation, JSON/BIN chunk extraction, and float/index buffer decoding. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `(b[off] & 255) | ((b[off + 1] & 255) << 8) | ((b[off + 2] & 255) << 16) | ((b[off + 3] & 255) << 24)`.

```aipl
module tests.functions.asset.gltf_mesh_loader_z2_test
import * from "std/asset/gltf_mesh_loader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gltf_mesh_loader_readGlbU32LE_2(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readGlbU32LE(arg_b, arg_off)
  let resEdge = readGlbU32LE(edge_b, edge_off)
  assertEqInt(resNom, 0, "readGlbU32LE nominal resNom == 0")
  assertEqInt(resEdge, 0, "readGlbU32LE boundary resEdge == 0")
  ret 0
```

---

### `parseGlbBinary` (`std/asset/gltf_mesh_loader.aipl`)

- **Signature**: `pub fn parseGlbBinary(glbBytes: [int]): Option[GltfScene]:`
- **Import**: `import * from "std/asset/gltf_mesh_loader"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `glbBytes: [int]` | **Returns**: `Option[GltfScene]`
- **Unit Test**: `tests/functions/asset/gltf_mesh_loader_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `parseGlbBinary` glTF 2.0 `.glb` magic `0x46546C67` header validation, JSON/BIN chunk extraction, and float/index buffer decoding. Concrete nominal inputs: `glbBytes: [int] = [64]`; exercises core body path returning/computing `parseGltfJson(jsonChunkStr, binChunk)`.

```aipl
module tests.functions.asset.gltf_mesh_loader_z3_test
import * from "std/asset/gltf_mesh_loader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gltf_mesh_loader_parseGlbBinary_3(): int:
  let arg_glbBytes = [4]
  let edge_glbBytes = []
  let resNom = parseGlbBinary(arg_glbBytes)
  let resEdge = parseGlbBinary(edge_glbBytes)
  assert(resNom.isSome() == false, "parseGlbBinary nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "parseGlbBinary boundary resEdge.isSome() == false")
  ret 0
```

---

### `extractMeshVertices` (`std/asset/gltf_mesh_loader.aipl`)

- **Signature**: `pub fn extractMeshVertices(prim: GltfPrimitive): [float]:`
- **Import**: `import * from "std/asset/gltf_mesh_loader"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prim: GltfPrimitive` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/asset/gltf_mesh_loader_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `extractMeshVertices` glTF 2.0 `.glb` magic `0x46546C67` header validation, JSON/BIN chunk extraction, and float/index buffer decoding. Concrete nominal inputs: `prim: GltfPrimitive = GltfPrimitive(positions = [1.0], normals = [1.0], uvs = [1.0], indices = [1], materialIndex = 0)`; exercises core body path returning/computing `prim.positions`.

```aipl
module tests.functions.asset.gltf_mesh_loader_z4_test
import * from "std/asset/gltf_mesh_loader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gltf_mesh_loader_extractMeshVertices_4(): int:
  let arg_prim = GltfPrimitive(positions = [], normals = [], uvs = [], indices = [], materialIndex = 4)
  let edge_prim = GltfPrimitive(positions = [], normals = [], uvs = [], indices = [], materialIndex = 1)
  let resNom = extractMeshVertices(arg_prim)
  let resEdge = extractMeshVertices(edge_prim)
  assertEqInt(resNom.len(), 0, "extractMeshVertices nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractMeshVertices boundary resEdge.len() == 0")
  ret 0
```

---

### `extractMeshIndices` (`std/asset/gltf_mesh_loader.aipl`)

- **Signature**: `pub fn extractMeshIndices(prim: GltfPrimitive): [int]:`
- **Import**: `import * from "std/asset/gltf_mesh_loader"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `prim: GltfPrimitive` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/gltf_mesh_loader_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `extractMeshIndices` glTF 2.0 `.glb` magic `0x46546C67` header validation, JSON/BIN chunk extraction, and float/index buffer decoding. Concrete nominal inputs: `prim: GltfPrimitive = GltfPrimitive(positions = [1.0], normals = [1.0], uvs = [1.0], indices = [1], materialIndex = 0)`; exercises core body path returning/computing `prim.indices`.

```aipl
module tests.functions.asset.gltf_mesh_loader_z5_test
import * from "std/asset/gltf_mesh_loader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gltf_mesh_loader_extractMeshIndices_5(): int:
  let arg_prim = GltfPrimitive(positions = [], normals = [], uvs = [], indices = [], materialIndex = 4)
  let edge_prim = GltfPrimitive(positions = [], normals = [], uvs = [], indices = [], materialIndex = 1)
  let resNom = extractMeshIndices(arg_prim)
  let resEdge = extractMeshIndices(edge_prim)
  assertEqInt(resNom.len(), 0, "extractMeshIndices nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "extractMeshIndices boundary resEdge.len() == 0")
  ret 0
```

---

### `pixelRgb` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn pixelRgb(r: int, g: int, b: int): Pixel:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int` | **Returns**: `Pixel`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `pixelRgb` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`; exercises core body path returning/computing `Pixel(r = r, g = g, b = b, a = 255)`.

```aipl
module tests.functions.asset.image_decoder_z1_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pixelRgb_1(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = pixelRgb(arg_r, arg_g, arg_b)
  let resEdge = pixelRgb(edge_r, edge_g, edge_b)
  assertEqInt(resNom.r, 2, "pixelRgb nominal resNom.r == 2")
  assertEqInt(resEdge.r, 0, "pixelRgb boundary resEdge.r == 0")
  ret 0
```

---

### `pixelRgba` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn pixelRgba(r: int, g: int, b: int, a: int): Pixel:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int, a: int` | **Returns**: `Pixel`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `pixelRgba` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `Pixel(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.asset.image_decoder_z2_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pixelRgba_2(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = pixelRgba(arg_r, arg_g, arg_b, arg_a)
  let resEdge = pixelRgba(edge_r, edge_g, edge_b, edge_a)
  assertEqInt(resNom.r, 2, "pixelRgba nominal resNom.r == 2")
  assertEqInt(resEdge.r, 0, "pixelRgba boundary resEdge.r == 0")
  ret 0
```

---

### `pixelToInt` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn pixelToInt(p: Pixel): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: Pixel` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `pixelToInt` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `p: Pixel = Pixel(r = 1, g = 1, b = 1, a = 1)`; exercises core body path returning/computing `((p.a & 255) << 24) | ((p.r & 255) << 16) | ((p.g & 255) << 8) | (p.b & 255)`.

```aipl
module tests.functions.asset.image_decoder_z3_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pixelToInt_3(): int:
  let arg_p = Pixel(r = 2, g = 2, b = 4, a = 2)
  let edge_p = Pixel(r = 0, g = 0, b = 1, a = 0)
  let resNom = pixelToInt(arg_p)
  let resEdge = pixelToInt(edge_p)
  assertEqInt(resNom, 33686020, "pixelToInt nominal resNom == 33686020")
  assertEqInt(resEdge, 1, "pixelToInt boundary resEdge == 1")
  ret 0
```

---

### `intToPixel` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn intToPixel(c: int): Pixel:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: int` | **Returns**: `Pixel`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `intToPixel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `c: int = 1`; exercises core body path returning/computing `Pixel(r = r, g = g, b = b, a = if a == 0 and c != 0: 255 else: a)`.

```aipl
module tests.functions.asset.image_decoder_z4_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_intToPixel_4(): int:
  let arg_c = 2
  let edge_c = 0
  let resNom = intToPixel(arg_c)
  let resEdge = intToPixel(edge_c)
  assertEqInt(resNom.r, 0, "intToPixel nominal resNom.r == 0")
  assertEqInt(resEdge.r, 0, "intToPixel boundary resEdge.r == 0")
  ret 0
```

---

### `imageBufferNew` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBufferNew(width: int, height: int, fillColor: int = 0): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, fillColor: int = 0` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageBufferNew` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `fillColor: int = 1`; exercises core body path returning/computing `DecodedImage(width = width, height = height, channels = 4, pixelsRgba = rgba, format = FORMAT_UNKNOWN, pixels = px)`.

```aipl
module tests.functions.asset.image_decoder_z5_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBufferNew_5(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_fillColor = 1
  let edge_fillColor = 0
  let resNom = imageBufferNew(arg_width, arg_height, arg_fillColor)
  let resEdge = imageBufferNew(edge_width, edge_height, edge_fillColor)
  assertEqInt(resNom.width, 4, "imageBufferNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "imageBufferNew boundary resEdge.width == 1")
  ret 0
```

---

### `imageNew` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageNew(width: int, height: int, fillColor: int = 0): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, fillColor: int = 0` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageNew` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `fillColor: int = 1`; exercises core body path returning/computing `imageBufferNew(width, height, fillColor)`.

```aipl
module tests.functions.asset.image_decoder_z6_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageNew_6(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_fillColor = 1
  let edge_fillColor = 0
  let resNom = imageNew(arg_width, arg_height, arg_fillColor)
  let resEdge = imageNew(edge_width, edge_height, edge_fillColor)
  assertEqInt(resNom.width, 4, "imageNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "imageNew boundary resEdge.width == 1")
  ret 0
```

---

### `imageGetPixel` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageGetPixel(img: DecodedImage, x: int, y: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, x: int, y: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageGetPixel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.asset.image_decoder_z7_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageGetPixel_7(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = imageGetPixel(arg_img, arg_x, arg_y)
  let resEdge = imageGetPixel(edge_img, edge_x, edge_y)
  assertEqInt(resNom, 0, "imageGetPixel nominal resNom == 0")
  assertEqInt(resEdge, 0, "imageGetPixel boundary resEdge == 0")
  ret 0
```

---

### `imageSetPixel` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageSetPixel(mut img: DecodedImage, x: int, y: int, color: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, x: int, y: int, color: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageSetPixel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`, `color: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z8_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageSetPixel_8(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_color = 1
  let edge_color = 0
  let resNom = imageSetPixel(arg_img, arg_x, arg_y, arg_color)
  let resEdge = imageSetPixel(edge_img, edge_x, edge_y, edge_color)
  assertEqInt(resNom.width, 4, "imageSetPixel nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageSetPixel boundary resEdge.width == 4")
  ret 0
```

---

### `readU16LEImg` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn readU16LEImg(b: [int], off: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `readU16LEImg` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `(b[off] & 255) | ((b[off + 1] & 255) << 8)`.

```aipl
module tests.functions.asset.image_decoder_z9_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_readU16LEImg_9(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU16LEImg(arg_b, arg_off)
  let resEdge = readU16LEImg(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU16LEImg nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU16LEImg boundary resEdge == 0")
  ret 0
```

---

### `readU32LEImg` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn readU32LEImg(b: [int], off: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `readU32LEImg` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `(b[off] & 255) | ((b[off + 1] & 255) << 8) | ((b[off + 2] & 255) << 16) | ((b[off + 3] & 255) << 24)`.

```aipl
module tests.functions.asset.image_decoder_z10_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_readU32LEImg_10(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU32LEImg(arg_b, arg_off)
  let resEdge = readU32LEImg(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU32LEImg nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU32LEImg boundary resEdge == 0")
  ret 0
```

---

### `readU32BEImg` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn readU32BEImg(b: [int], off: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `readU32BEImg` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `((b[off] & 255) << 24) | ((b[off + 1] & 255) << 16) | ((b[off + 2] & 255) << 8) | (b[off + 3] & 255)`.

```aipl
module tests.functions.asset.image_decoder_z11_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_readU32BEImg_11(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU32BEImg(arg_b, arg_off)
  let resEdge = readU32BEImg(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU32BEImg nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU32BEImg boundary resEdge == 0")
  ret 0
```

---

### `detectImageFormat` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn detectImageFormat(headerBytes: [int]): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `headerBytes: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `detectImageFormat` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `headerBytes: [int] = [64]`; exercises core body path returning/computing `FORMAT_UNKNOWN`.

```aipl
module tests.functions.asset.image_decoder_z12_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_detectImageFormat_12(): int:
  let arg_headerBytes = [4]
  let edge_headerBytes = []
  let resNom = detectImageFormat(arg_headerBytes)
  let resEdge = detectImageFormat(edge_headerBytes)
  assertEqInt(resNom, 0, "detectImageFormat nominal resNom == 0")
  assertEqInt(resEdge, 0, "detectImageFormat boundary resEdge == 0")
  ret 0
```

---

### `decodeBmp` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodeBmp(bytes: [int]): Option[DecodedImage]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[DecodedImage]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `decodeBmp` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(DecodedImage(`.

```aipl
module tests.functions.asset.image_decoder_z13_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodeBmp_13(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = decodeBmp(arg_bytes)
  let resEdge = decodeBmp(edge_bytes)
  assert(resNom.isSome() == false, "decodeBmp nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeBmp boundary resEdge.isSome() == false")
  ret 0
```

---

### `decodeQoi` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodeQoi(bytes: [int]): Option[DecodedImage]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[DecodedImage]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodeQoi` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(DecodedImage(`.

```aipl
module tests.functions.asset.image_decoder_z14_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodeQoi_14(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = decodeQoi(arg_bytes)
  let resEdge = decodeQoi(edge_bytes)
  assert(resNom.isSome() == false, "decodeQoi nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeQoi boundary resEdge.isSome() == false")
  ret 0
```

---

### `decodePngHeader` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePngHeader(bytes: [int], checkMagic: bool = true): Option[(int, int, int)]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int], checkMagic: bool = true` | **Returns**: `Option[(int, int, int)]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `decodePngHeader` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `bytes: [int] = [64]`, `checkMagic: bool = true`; exercises core body path returning/computing `Some((width, height, bitDepth))`.

```aipl
module tests.functions.asset.image_decoder_z15_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePngHeader_15(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let arg_checkMagic = true
  let edge_checkMagic = false
  let resNom = decodePngHeader(arg_bytes, arg_checkMagic)
  let resEdge = decodePngHeader(edge_bytes, edge_checkMagic)
  assert(resNom.isSome() == false, "decodePngHeader nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodePngHeader boundary resEdge.isSome() == false")
  ret 0
```

---

### `decodeTga` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodeTga(bytes: [int]): Option[DecodedImage]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[DecodedImage]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `decodeTga` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(DecodedImage(width = width, height = height, channels = 4, pixelsRgba = rgba, format = FORMAT_TGA, pixels = px))`.

```aipl
module tests.functions.asset.image_decoder_z16_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodeTga_16(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = decodeTga(arg_bytes)
  let resEdge = decodeTga(edge_bytes)
  assert(resNom.isSome() == false, "decodeTga nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeTga boundary resEdge.isSome() == false")
  ret 0
```

---

### `absDiffInt` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn absDiffInt(a: int, b: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `absDiffInt` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `a: int = 1`, `b: int = 1`; exercises core body path returning/computing `b - a`.

```aipl
module tests.functions.asset.image_decoder_z17_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_absDiffInt_17(): int:
  let arg_a = 2
  let edge_a = 0
  let arg_b = 4
  let edge_b = 1
  let resNom = absDiffInt(arg_a, arg_b)
  let resEdge = absDiffInt(edge_a, edge_b)
  assertEqInt(resNom, 2, "absDiffInt nominal resNom == 2")
  assertEqInt(resEdge, 1, "absDiffInt boundary resEdge == 1")
  ret 0
```

---

### `matchesKeyColor` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn matchesKeyColor(pixels: [int], idx4: int, kr: int, kg: int, kb: int, tol: int): bool:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pixels: [int], idx4: int, kr: int, kg: int, kb: int, tol: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `matchesKeyColor` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `pixels: [int] = [1]`, `idx4: int = 0`, `kr: int = 1`, `kg: int = 1`, `kb: int = 1`, `tol: int = 1`; exercises core body path returning/computing `absDiffInt(r, kr) <= tol and absDiffInt(g, kg) <= tol and absDiffInt(b, kb) <= tol`.

```aipl
module tests.functions.asset.image_decoder_z18_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_matchesKeyColor_18(): int:
  let arg_pixels = [1]
  let edge_pixels = []
  let arg_idx4 = 1
  let edge_idx4 = 0
  let arg_kr = 4
  let edge_kr = 1
  let arg_kg = 4
  let edge_kg = 1
  let arg_kb = 4
  let edge_kb = 1
  let arg_tol = 2
  let edge_tol = 0
  let resNom = matchesKeyColor(arg_pixels, arg_idx4, arg_kr, arg_kg, arg_kb, arg_tol)
  let resEdge = matchesKeyColor(edge_pixels, edge_idx4, edge_kr, edge_kg, edge_kb, edge_tol)
  assert(resNom == false, "matchesKeyColor nominal resNom == false")
  assert(resEdge == false, "matchesKeyColor boundary resEdge == false")
  ret 0
```

---

### `applyBorderFloodAlphaKey` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn applyBorderFloodAlphaKey(image: DecodedImage, keyColorR: int, keyColorG: int, keyColorB: int, tolerance: int = 0): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `image: DecodedImage, keyColorR: int, keyColorG: int, keyColorB: int, tolerance: int = 0` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `applyBorderFloodAlphaKey` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `image: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `keyColorR: int = 1`, `keyColorG: int = 1`, `keyColorB: int = 1`, `tolerance: int = 1`; exercises core body path returning/computing `DecodedImage(`.

```aipl
module tests.functions.asset.image_decoder_z19_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_applyBorderFloodAlphaKey_19(): int:
  let arg_image = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_image = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_keyColorR = 4
  let edge_keyColorR = 1
  let arg_keyColorG = 4
  let edge_keyColorG = 1
  let arg_keyColorB = 4
  let edge_keyColorB = 1
  let arg_tolerance = 4
  let edge_tolerance = 1
  let resNom = applyBorderFloodAlphaKey(arg_image, arg_keyColorR, arg_keyColorG, arg_keyColorB, arg_tolerance)
  let resEdge = applyBorderFloodAlphaKey(edge_image, edge_keyColorR, edge_keyColorG, edge_keyColorB, edge_tolerance)
  assertEqInt(resNom.width, 4, "applyBorderFloodAlphaKey nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "applyBorderFloodAlphaKey boundary resEdge.width == 4")
  ret 0
```

---

### `getPixelRgba` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn getPixelRgba(img: DecodedImage, x: int, y: int): (int, int, int, int):`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, x: int, y: int` | **Returns**: `(int, int, int, int)`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `getPixelRgba` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int): (int = int): (int()`, `int: any = 42`, `int: any = 42`, `int: any = 42`; exercises core body path returning/computing `(img.pixelsRgba[idx], img.pixelsRgba[idx + 1], img.pixelsRgba[idx + 2], img.pixelsRgba[idx + 3])`.

```aipl
module tests.functions.asset.image_decoder_z20_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_getPixelRgba_20(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = getPixelRgba(arg_img, arg_x, arg_y)
  let resEdge = getPixelRgba(edge_img, edge_x, edge_y)
  let (n_t0, n_t1, n_t2, n_t3) = resNom
  let (e_t0, e_t1, e_t2, e_t3) = resEdge
  assertEqInt(n_t0, 0, "getPixelRgba nominal n_t0 == 0")
  assertEqInt(e_t0, 0, "getPixelRgba boundary e_t0 == 0")
  ret 0
```

---

### `setPixelRgba` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn setPixelRgba(img: DecodedImage, x: int, y: int, r: int, g: int, b: int, a: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, x: int, y: int, r: int, g: int, b: int, a: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `setPixelRgba` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`, `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `DecodedImage(`.

```aipl
module tests.functions.asset.image_decoder_z21_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_setPixelRgba_21(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = setPixelRgba(arg_img, arg_x, arg_y, arg_r, arg_g, arg_b, arg_a)
  let resEdge = setPixelRgba(edge_img, edge_x, edge_y, edge_r, edge_g, edge_b, edge_a)
  assertEqInt(resNom.width, 4, "setPixelRgba nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "setPixelRgba boundary resEdge.width == 4")
  ret 0
```

---

### `imageResizeNearest` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageResizeNearest(img: DecodedImage, newWidth: int, newHeight: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, newWidth: int, newHeight: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageResizeNearest` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `newWidth: int = 1`, `newHeight: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z22_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageResizeNearest_22(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_newWidth = 4
  let edge_newWidth = 1
  let arg_newHeight = 4
  let edge_newHeight = 1
  let resNom = imageResizeNearest(arg_img, arg_newWidth, arg_newHeight)
  let resEdge = imageResizeNearest(edge_img, edge_newWidth, edge_newHeight)
  assertEqInt(resNom.width, 4, "imageResizeNearest nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "imageResizeNearest boundary resEdge.width == 1")
  ret 0
```

---

### `lerpChannel` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn lerpChannel(c00: int, c10: int, c01: int, c11: int, fx: float, fy: float): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c00: int, c10: int, c01: int, c11: int, fx: float, fy: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `lerpChannel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `c00: int = 1`, `c10: int = 1`, `c01: int = 1`, `c11: int = 1`, `fx: float = 1.0`, `fy: float = 1.0`; exercises core body path returning/computing `val`.

```aipl
module tests.functions.asset.image_decoder_z23_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_lerpChannel_23(): int:
  let arg_c00 = 2
  let edge_c00 = 0
  let arg_c10 = 2
  let edge_c10 = 0
  let arg_c01 = 2
  let edge_c01 = 0
  let arg_c11 = 2
  let edge_c11 = 0
  let arg_fx = 1.0
  let edge_fx = 0.5
  let arg_fy = 1.0
  let edge_fy = 0.5
  let resNom = lerpChannel(arg_c00, arg_c10, arg_c01, arg_c11, arg_fx, arg_fy)
  let resEdge = lerpChannel(edge_c00, edge_c10, edge_c01, edge_c11, edge_fx, edge_fy)
  assertEqInt(resNom, 2, "lerpChannel nominal resNom == 2")
  assertEqInt(resEdge, 0, "lerpChannel boundary resEdge == 0")
  ret 0
```

---

### `imageResizeBilinear` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageResizeBilinear(img: DecodedImage, newWidth: int, newHeight: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, newWidth: int, newHeight: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageResizeBilinear` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `newWidth: int = 1`, `newHeight: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z24_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageResizeBilinear_24(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_newWidth = 4
  let edge_newWidth = 1
  let arg_newHeight = 4
  let edge_newHeight = 1
  let resNom = imageResizeBilinear(arg_img, arg_newWidth, arg_newHeight)
  let resEdge = imageResizeBilinear(edge_img, edge_newWidth, edge_newHeight)
  assertEqInt(resNom.width, 4, "imageResizeBilinear nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "imageResizeBilinear boundary resEdge.width == 1")
  ret 0
```

---

### `imageCrop` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageCrop(img: DecodedImage, cropX: int, cropY: int, cropW: int, cropH: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, cropX: int, cropY: int, cropW: int, cropH: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageCrop` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `cropX: int = 1`, `cropY: int = 1`, `cropW: int = 1`, `cropH: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z25_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageCrop_25(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_cropX = 1
  let edge_cropX = 0
  let arg_cropY = 1
  let edge_cropY = 0
  let arg_cropW = 2
  let edge_cropW = 0
  let arg_cropH = 2
  let edge_cropH = 0
  let resNom = imageCrop(arg_img, arg_cropX, arg_cropY, arg_cropW, arg_cropH)
  let resEdge = imageCrop(edge_img, edge_cropX, edge_cropY, edge_cropW, edge_cropH)
  assertEqInt(resNom.width, 2, "imageCrop nominal resNom.width == 2")
  assertEqInt(resEdge.width, 0, "imageCrop boundary resEdge.width == 0")
  ret 0
```

---

### `imageFlipH` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFlipH(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageFlipH` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z26_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFlipH_26(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageFlipH(arg_img)
  let resEdge = imageFlipH(edge_img)
  assertEqInt(resNom.width, 4, "imageFlipH nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFlipH boundary resEdge.width == 4")
  ret 0
```

---

### `imageFlipV` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFlipV(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageFlipV` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z27_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFlipV_27(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageFlipV(arg_img)
  let resEdge = imageFlipV(edge_img)
  assertEqInt(resNom.width, 4, "imageFlipV nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFlipV boundary resEdge.width == 4")
  ret 0
```

---

### `imageFlipHorizontal` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFlipHorizontal(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageFlipHorizontal` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `imageFlipH(img)`.

```aipl
module tests.functions.asset.image_decoder_z28_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFlipHorizontal_28(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageFlipHorizontal(arg_img)
  let resEdge = imageFlipHorizontal(edge_img)
  assertEqInt(resNom.width, 4, "imageFlipHorizontal nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFlipHorizontal boundary resEdge.width == 4")
  ret 0
```

---

### `imageFlipVertical` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFlipVertical(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageFlipVertical` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `imageFlipV(img)`.

```aipl
module tests.functions.asset.image_decoder_z29_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFlipVertical_29(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageFlipVertical(arg_img)
  let resEdge = imageFlipVertical(edge_img)
  assertEqInt(resNom.width, 4, "imageFlipVertical nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFlipVertical boundary resEdge.width == 4")
  ret 0
```

---

### `imageRotate90` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageRotate90(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageRotate90` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z30_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageRotate90_30(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageRotate90(arg_img)
  let resEdge = imageRotate90(edge_img)
  assertEqInt(resNom.width, 4, "imageRotate90 nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageRotate90 boundary resEdge.width == 4")
  ret 0
```

---

### `imageGrayscale` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageGrayscale(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageGrayscale` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z31_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageGrayscale_31(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageGrayscale(arg_img)
  let resEdge = imageGrayscale(edge_img)
  assertEqInt(resNom.width, 4, "imageGrayscale nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageGrayscale boundary resEdge.width == 4")
  ret 0
```

---

### `imageInvert` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageInvert(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageInvert` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z32_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageInvert_32(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageInvert(arg_img)
  let resEdge = imageInvert(edge_img)
  assertEqInt(resNom.width, 4, "imageInvert nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageInvert boundary resEdge.width == 4")
  ret 0
```

---

### `imageSepia` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageSepia(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageSepia` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z33_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageSepia_33(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageSepia(arg_img)
  let resEdge = imageSepia(edge_img)
  assertEqInt(resNom.width, 4, "imageSepia nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageSepia boundary resEdge.width == 4")
  ret 0
```

---

### `clampChannel` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn clampChannel(val: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `clampChannel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `val: int = 1`; exercises core body path returning/computing `val`.

```aipl
module tests.functions.asset.image_decoder_z34_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_clampChannel_34(): int:
  let arg_val = 2
  let edge_val = 0
  let resNom = clampChannel(arg_val)
  let resEdge = clampChannel(edge_val)
  assertEqInt(resNom, 2, "clampChannel nominal resNom == 2")
  assertEqInt(resEdge, 0, "clampChannel boundary resEdge == 0")
  ret 0
```

---

### `imageAdjustBrightnessContrast` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageAdjustBrightnessContrast(img: DecodedImage, brightness: float, contrast: float): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, brightness: float, contrast: float` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageAdjustBrightnessContrast` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `brightness: float = 1.0`, `contrast: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z35_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageAdjustBrightnessContrast_35(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_brightness = 2.0
  let edge_brightness = 1.0
  let arg_contrast = 1.0
  let edge_contrast = 0.5
  let resNom = imageAdjustBrightnessContrast(arg_img, arg_brightness, arg_contrast)
  let resEdge = imageAdjustBrightnessContrast(edge_img, edge_brightness, edge_contrast)
  assertEqInt(resNom.width, 4, "imageAdjustBrightnessContrast nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageAdjustBrightnessContrast boundary resEdge.width == 4")
  ret 0
```

---

### `imageBoxBlurSeparable` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBoxBlurSeparable(img: DecodedImage, radius: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, radius: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageBoxBlurSeparable` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `radius: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z36_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBoxBlurSeparable_36(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_radius = 2
  let edge_radius = 0
  let resNom = imageBoxBlurSeparable(arg_img, arg_radius)
  let resEdge = imageBoxBlurSeparable(edge_img, edge_radius)
  assertEqInt(resNom.width, 4, "imageBoxBlurSeparable nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageBoxBlurSeparable boundary resEdge.width == 4")
  ret 0
```

---

### `imageBoxBlur` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBoxBlur(img: DecodedImage, radius: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, radius: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageBoxBlur` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `radius: int = 1`; exercises core body path returning/computing `imageBoxBlurSeparable(img, radius)`.

```aipl
module tests.functions.asset.image_decoder_z37_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBoxBlur_37(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_radius = 2
  let edge_radius = 0
  let resNom = imageBoxBlur(arg_img, arg_radius)
  let resEdge = imageBoxBlur(edge_img, edge_radius)
  assertEqInt(resNom.width, 4, "imageBoxBlur nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageBoxBlur boundary resEdge.width == 4")
  ret 0
```

---

### `imageSliceSpriteSheet` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageSliceSpriteSheet(img: DecodedImage, frameW: int, frameH: int): [DecodedImage]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, frameW: int, frameH: int` | **Returns**: `[DecodedImage]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageSliceSpriteSheet` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `frameW: int = 1`, `frameH: int = 1`; exercises core body path returning/computing `frames`.

```aipl
module tests.functions.asset.image_decoder_z38_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageSliceSpriteSheet_38(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_frameW = 4
  let edge_frameW = 1
  let arg_frameH = 4
  let edge_frameH = 1
  let resNom = imageSliceSpriteSheet(arg_img, arg_frameW, arg_frameH)
  let resEdge = imageSliceSpriteSheet(edge_img, edge_frameW, edge_frameH)
  assertEqInt(resNom.len(), 1, "imageSliceSpriteSheet nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 16, "imageSliceSpriteSheet boundary resEdge.len() == 16")
  ret 0
```

---

### `imageToAsciiArt` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageToAsciiArt(img: DecodedImage, cols: int, rows: int): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, cols: int, rows: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageToAsciiArt` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `cols: int = 1`, `rows: int = 1`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.asset.image_decoder_z39_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageToAsciiArt_39(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let resNom = imageToAsciiArt(arg_img, arg_cols, arg_rows)
  let resEdge = imageToAsciiArt(edge_img, edge_cols, edge_rows)
  assertEqInt(resNom.len(), 19, "imageToAsciiArt nominal string length == 19")
  assertEqStr(resEdge, " ", "imageToAsciiArt boundary string matches")
  ret 0
```

---

### `imageBlit` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBlit(mut dst: DecodedImage, src: DecodedImage, dx: int, dy: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut dst: DecodedImage, src: DecodedImage, dx: int, dy: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageBlit` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `dst: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `src: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `dx: int = 1`, `dy: int = 1`; exercises core body path returning/computing `dst`.

```aipl
module tests.functions.asset.image_decoder_z40_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBlit_40(): int:
  let arg_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_dx = 1
  let edge_dx = 0
  let arg_dy = 1
  let edge_dy = 0
  let resNom = imageBlit(arg_dst, arg_src, arg_dx, arg_dy)
  let resEdge = imageBlit(edge_dst, edge_src, edge_dx, edge_dy)
  assertEqInt(resNom.width, 4, "imageBlit nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageBlit boundary resEdge.width == 4")
  ret 0
```

---

### `imageDrawLine` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageDrawLine(mut img: DecodedImage, x0: int, y0: int, x1: int, y1: int, color: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, x0: int, y0: int, x1: int, y1: int, color: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageDrawLine` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x0: int = 1`, `y0: int = 1`, `x1: int = 1`, `y1: int = 1`, `color: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z41_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageDrawLine_41(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x0 = 1
  let edge_x0 = 0
  let arg_y0 = 1
  let edge_y0 = 0
  let arg_x1 = 1
  let edge_x1 = 0
  let arg_y1 = 1
  let edge_y1 = 0
  let arg_color = 1
  let edge_color = 0
  let resNom = imageDrawLine(arg_img, arg_x0, arg_y0, arg_x1, arg_y1, arg_color)
  let resEdge = imageDrawLine(edge_img, edge_x0, edge_y0, edge_x1, edge_y1, edge_color)
  assertEqInt(resNom.width, 4, "imageDrawLine nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageDrawLine boundary resEdge.width == 4")
  ret 0
```

---

### `imageDrawCircle` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageDrawCircle(mut img: DecodedImage, cx: int, cy: int, radius: int, color: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, cx: int, cy: int, radius: int, color: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageDrawCircle` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `cx: int = 1`, `cy: int = 1`, `radius: int = 1`, `color: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z42_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageDrawCircle_42(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let arg_radius = 2
  let edge_radius = 0
  let arg_color = 1
  let edge_color = 0
  let resNom = imageDrawCircle(arg_img, arg_cx, arg_cy, arg_radius, arg_color)
  let resEdge = imageDrawCircle(edge_img, edge_cx, edge_cy, edge_radius, edge_color)
  assertEqInt(resNom.width, 4, "imageDrawCircle nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageDrawCircle boundary resEdge.width == 4")
  ret 0
```

---

### `imageDrawCirclePixel` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageDrawCirclePixel(img: DecodedImage, cx: int, cy: int, r: int, col: Pixel): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, cx: int, cy: int, r: int, col: Pixel` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageDrawCirclePixel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `cx: int = 1`, `cy: int = 1`, `r: int = 1`, `col: Pixel = Pixel(r = 1, g = 1, b = 1, a = 1)`; exercises core body path returning/computing `imageDrawCircle(img, cx, cy, r, c)`.

```aipl
module tests.functions.asset.image_decoder_z43_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageDrawCirclePixel_43(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let arg_r = 2
  let edge_r = 0
  let arg_col = Pixel(r = 2, g = 2, b = 4, a = 2)
  let edge_col = Pixel(r = 0, g = 0, b = 1, a = 0)
  let resNom = imageDrawCirclePixel(arg_img, arg_cx, arg_cy, arg_r, arg_col)
  let resEdge = imageDrawCirclePixel(edge_img, edge_cx, edge_cy, edge_r, edge_col)
  assertEqInt(resNom.width, 4, "imageDrawCirclePixel nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageDrawCirclePixel boundary resEdge.width == 4")
  ret 0
```

---

### `imageFillRectColor` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFillRectColor(mut img: DecodedImage, x: int, y: int, w: int, h: int, color: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, x: int, y: int, w: int, h: int, color: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageFillRectColor` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`, `w: int = 128`, `h: int = 128`, `color: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z44_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFillRectColor_44(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_color = 1
  let edge_color = 0
  let resNom = imageFillRectColor(arg_img, arg_x, arg_y, arg_w, arg_h, arg_color)
  let resEdge = imageFillRectColor(edge_img, edge_x, edge_y, edge_w, edge_h, edge_color)
  assertEqInt(resNom.width, 4, "imageFillRectColor nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFillRectColor boundary resEdge.width == 4")
  ret 0
```

---

### `imageFillRect` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFillRect(mut img: DecodedImage, rx: int, ry: int, rw: int, rh: int, r: int, g: int, b: int, a: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, rx: int, ry: int, rw: int, rh: int, r: int, g: int, b: int, a: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageFillRect` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `rx: int = 1`, `ry: int = 1`, `rw: int = 1`, `rh: int = 1`, `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z45_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFillRect_45(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_rx = 1
  let edge_rx = 0
  let arg_ry = 1
  let edge_ry = 0
  let arg_rw = 2
  let edge_rw = 0
  let arg_rh = 2
  let edge_rh = 0
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = imageFillRect(arg_img, arg_rx, arg_ry, arg_rw, arg_rh, arg_r, arg_g, arg_b, arg_a)
  let resEdge = imageFillRect(edge_img, edge_rx, edge_ry, edge_rw, edge_rh, edge_r, edge_g, edge_b, edge_a)
  assertEqInt(resNom.width, 4, "imageFillRect nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageFillRect boundary resEdge.width == 4")
  ret 0
```

---

### `imageFloodFill` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageFloodFill(mut img: DecodedImage, startX: int, startY: int, newColor: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, startX: int, startY: int, newColor: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageFloodFill` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `startX: int = 1`, `startY: int = 1`, `newColor: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z46_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageFloodFill_46(): int:
  let arg_img = DecodedImage(width = 1, height = 1, channels = 4, pixelsRgba = [0], format = 1, pixels = [0])
  let edge_img = DecodedImage(width = 0, height = 0, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_startX = 1
  let edge_startX = 0
  let arg_startY = 1
  let edge_startY = 0
  let arg_newColor = 4
  let edge_newColor = 1
  let resNom = imageFloodFill(arg_img, arg_startX, arg_startY, arg_newColor)
  let resEdge = imageFloodFill(edge_img, edge_startX, edge_startY, edge_newColor)
  assertEqInt(resNom.width, 1, "imageFloodFill nominal resNom.width == 1")
  assertEqInt(resEdge.width, 0, "imageFloodFill boundary resEdge.width == 0")
  ret 0
```

---

### `imageToPpm` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageToPpm(img: DecodedImage): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageToPpm` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.asset.image_decoder_z47_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageToPpm_47(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageToPpm(arg_img)
  let resEdge = imageToPpm(edge_img)
  assertEqInt(resNom.len(), 106, "imageToPpm nominal string length == 106")
  assertEqInt(resEdge.len(), 106, "imageToPpm boundary string length == 106")
  ret 0
```

---

### `encodePpm` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePpm(img: DecodedImage): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodePpm` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `imageToPpm(img)`.

```aipl
module tests.functions.asset.image_decoder_z48_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePpm_48(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePpm(arg_img)
  let resEdge = encodePpm(edge_img)
  assertEqInt(resNom.len(), 106, "encodePpm nominal string length == 106")
  assertEqInt(resEdge.len(), 106, "encodePpm boundary string length == 106")
  ret 0
```

---

### `encodePpmP3` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePpmP3(img: DecodedImage): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `encodePpmP3` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `encodePpm(img)`.

```aipl
module tests.functions.asset.image_decoder_z49_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePpmP3_49(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePpmP3(arg_img)
  let resEdge = encodePpmP3(edge_img)
  assertEqInt(resNom.len(), 106, "encodePpmP3 nominal string length == 106")
  assertEqInt(resEdge.len(), 106, "encodePpmP3 boundary string length == 106")
  ret 0
```

---

### `encodePpmP6` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePpmP6(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `encodePpmP6` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z50_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePpmP6_50(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePpmP6(arg_img)
  let resEdge = encodePpmP6(edge_img)
  assertEqInt(resNom.len(), 59, "encodePpmP6 nominal resNom.len() == 59")
  assertEqInt(resEdge.len(), 59, "encodePpmP6 boundary resEdge.len() == 59")
  ret 0
```

---

### `encodePgmP2` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePgmP2(img: DecodedImage): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodePgmP2` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `lines.join("\n")`.

```aipl
module tests.functions.asset.image_decoder_z51_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePgmP2_51(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePgmP2(arg_img)
  let resEdge = encodePgmP2(edge_img)
  assertEqInt(resNom.len(), 42, "encodePgmP2 nominal string length == 42")
  assertEqInt(resEdge.len(), 42, "encodePgmP2 boundary string length == 42")
  ret 0
```

---

### `encodePgmP5` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePgmP5(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `encodePgmP5` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z52_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePgmP5_52(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePgmP5(arg_img)
  let resEdge = encodePgmP5(edge_img)
  assertEqInt(resNom.len(), 27, "encodePgmP5 nominal resNom.len() == 27")
  assertEqInt(resEdge.len(), 27, "encodePgmP5 boundary resEdge.len() == 27")
  ret 0
```

---

### `hexColor6` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn hexColor6(c: int): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `hexColor6` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `c: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z53_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_hexColor6_53(): int:
  let arg_c = 2
  let edge_c = 0
  let resNom = hexColor6(arg_c)
  let resEdge = hexColor6(edge_c)
  assertEqStr(resNom, "#000002", "hexColor6 nominal string matches")
  assertEqStr(resEdge, "#000000", "hexColor6 boundary string matches")
  ret 0
```

---

### `imageToSvgRle` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageToSvgRle(img: DecodedImage, scale: int = 1): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, scale: int = 1` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `imageToSvgRle` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `scale: int = 1`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.asset.image_decoder_z54_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageToSvgRle_54(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_scale = 2
  let edge_scale = 0
  let resNom = imageToSvgRle(arg_img, arg_scale)
  let resEdge = imageToSvgRle(edge_img, edge_scale)
  assertEqInt(resNom.len(), 305, "imageToSvgRle nominal string length == 305")
  assertEqInt(resEdge.len(), 305, "imageToSvgRle boundary string length == 305")
  ret 0
```

---

### `imageToSvg` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageToSvg(img: DecodedImage, scale: int = 1): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, scale: int = 1` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageToSvg` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `scale: int = 1`; exercises core body path returning/computing `imageToSvgRle(img, scale)`.

```aipl
module tests.functions.asset.image_decoder_z55_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageToSvg_55(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_scale = 2
  let edge_scale = 0
  let resNom = imageToSvg(arg_img, arg_scale)
  let resEdge = imageToSvg(edge_img, edge_scale)
  assertEqInt(resNom.len(), 305, "imageToSvg nominal string length == 305")
  assertEqInt(resEdge.len(), 305, "imageToSvg boundary string length == 305")
  ret 0
```

---

### `encodeSvg` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeSvg(img: DecodedImage, scale: int = 1): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, scale: int = 1` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `encodeSvg` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `scale: int = 1`; exercises core body path returning/computing `imageToSvgRle(img, scale)`.

```aipl
module tests.functions.asset.image_decoder_z56_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeSvg_56(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_scale = 2
  let edge_scale = 0
  let resNom = encodeSvg(arg_img, arg_scale)
  let resEdge = encodeSvg(edge_img, edge_scale)
  assertEqInt(resNom.len(), 305, "encodeSvg nominal string length == 305")
  assertEqInt(resEdge.len(), 305, "encodeSvg boundary string length == 305")
  ret 0
```

---

### `svgNew` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgNew(width: int, height: int): SvgBuilder:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int` | **Returns**: `SvgBuilder`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `svgNew` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `width: int = 128`, `height: int = 128`; exercises core body path returning/computing `SvgBuilder(width = width, height = height, elements = els)`.

```aipl
module tests.functions.asset.image_decoder_z57_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgNew_57(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let resNom = svgNew(arg_width, arg_height)
  let resEdge = svgNew(edge_width, edge_height)
  assertEqInt(resNom.width, 4, "svgNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "svgNew boundary resEdge.width == 1")
  ret 0
```

---

### `svgAddRect` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgAddRect(mut b: SvgBuilder, x: int, y: int, w: int, h: int, fill: str, stroke: str = "none"): SvgBuilder:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut b: SvgBuilder, x: int, y: int, w: int, h: int, fill: str, stroke: str = "none"` | **Returns**: `SvgBuilder`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `svgAddRect` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: SvgBuilder = SvgBuilder(width = 128, height = 128, elements = ["aipl_test"])`, `x: int = 1`, `y: int = 1`, `w: int = 128`, `h: int = 128`, `fill: str = "aipl_test"`, `stroke: str = "aipl_test"`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.image_decoder_z58_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgAddRect_58(): int:
  let arg_b = SvgBuilder(width = 4, height = 4, elements = [])
  let edge_b = SvgBuilder(width = 4, height = 4, elements = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_fill = "test"
  let edge_fill = "a"
  let arg_stroke = "test"
  let edge_stroke = "a"
  let resNom = svgAddRect(arg_b, arg_x, arg_y, arg_w, arg_h, arg_fill, arg_stroke)
  let resEdge = svgAddRect(edge_b, edge_x, edge_y, edge_w, edge_h, edge_fill, edge_stroke)
  assertEqInt(resNom.width, 4, "svgAddRect nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "svgAddRect boundary resEdge.width == 4")
  ret 0
```

---

### `svgAddCircle` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgAddCircle(mut b: SvgBuilder, cx: int, cy: int, r: int, fill: str, stroke: str = "none"): SvgBuilder:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut b: SvgBuilder, cx: int, cy: int, r: int, fill: str, stroke: str = "none"` | **Returns**: `SvgBuilder`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `svgAddCircle` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: SvgBuilder = SvgBuilder(width = 128, height = 128, elements = ["aipl_test"])`, `cx: int = 1`, `cy: int = 1`, `r: int = 1`, `fill: str = "aipl_test"`, `stroke: str = "aipl_test"`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.image_decoder_z59_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgAddCircle_59(): int:
  let arg_b = SvgBuilder(width = 4, height = 4, elements = [])
  let edge_b = SvgBuilder(width = 4, height = 4, elements = [])
  let arg_cx = 1
  let edge_cx = 0
  let arg_cy = 1
  let edge_cy = 0
  let arg_r = 2
  let edge_r = 0
  let arg_fill = "test"
  let edge_fill = "a"
  let arg_stroke = "test"
  let edge_stroke = "a"
  let resNom = svgAddCircle(arg_b, arg_cx, arg_cy, arg_r, arg_fill, arg_stroke)
  let resEdge = svgAddCircle(edge_b, edge_cx, edge_cy, edge_r, edge_fill, edge_stroke)
  assertEqInt(resNom.width, 4, "svgAddCircle nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "svgAddCircle boundary resEdge.width == 4")
  ret 0
```

---

### `svgAddLine` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgAddLine(mut b: SvgBuilder, x1: int, y1: int, x2: int, y2: int, stroke: str, strokeWidth: int = 1): SvgBuilder:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut b: SvgBuilder, x1: int, y1: int, x2: int, y2: int, stroke: str, strokeWidth: int = 1` | **Returns**: `SvgBuilder`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `svgAddLine` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: SvgBuilder = SvgBuilder(width = 128, height = 128, elements = ["aipl_test"])`, `x1: int = 1`, `y1: int = 1`, `x2: int = 1`, `y2: int = 1`, `stroke: str = "aipl_test"`, `strokeWidth: int = 1`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.image_decoder_z60_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgAddLine_60(): int:
  let arg_b = SvgBuilder(width = 4, height = 4, elements = [])
  let edge_b = SvgBuilder(width = 4, height = 4, elements = [])
  let arg_x1 = 1
  let edge_x1 = 0
  let arg_y1 = 1
  let edge_y1 = 0
  let arg_x2 = 1
  let edge_x2 = 0
  let arg_y2 = 1
  let edge_y2 = 0
  let arg_stroke = "test"
  let edge_stroke = "a"
  let arg_strokeWidth = 4
  let edge_strokeWidth = 1
  let resNom = svgAddLine(arg_b, arg_x1, arg_y1, arg_x2, arg_y2, arg_stroke, arg_strokeWidth)
  let resEdge = svgAddLine(edge_b, edge_x1, edge_y1, edge_x2, edge_y2, edge_stroke, edge_strokeWidth)
  assertEqInt(resNom.width, 4, "svgAddLine nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "svgAddLine boundary resEdge.width == 4")
  ret 0
```

---

### `svgAddText` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgAddText(mut b: SvgBuilder, x: int, y: int, text: str, fontSize: int = 14, fill: str = "#000000"): SvgBuilder:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut b: SvgBuilder, x: int, y: int, text: str, fontSize: int = 14, fill: str = "#000000"` | **Returns**: `SvgBuilder`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `svgAddText` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: SvgBuilder = SvgBuilder(width = 128, height = 128, elements = ["aipl_test"])`, `x: int = 1`, `y: int = 1`, `text: str = "aipl_test"`, `fontSize: int = 64`, `fill: str = "aipl_test"`; exercises core body path returning/computing `b`.

```aipl
module tests.functions.asset.image_decoder_z61_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgAddText_61(): int:
  let arg_b = SvgBuilder(width = 4, height = 4, elements = [])
  let edge_b = SvgBuilder(width = 4, height = 4, elements = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_fontSize = 4
  let edge_fontSize = 1
  let arg_fill = "test"
  let edge_fill = "a"
  let resNom = svgAddText(arg_b, arg_x, arg_y, arg_text, arg_fontSize, arg_fill)
  let resEdge = svgAddText(edge_b, edge_x, edge_y, edge_text, edge_fontSize, edge_fill)
  assertEqInt(resNom.width, 4, "svgAddText nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "svgAddText boundary resEdge.width == 4")
  ret 0
```

---

### `svgRender` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn svgRender(b: SvgBuilder): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: SvgBuilder` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `svgRender` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `b: SvgBuilder = SvgBuilder(width = 128, height = 128, elements = ["aipl_test"])`; exercises core body path returning/computing `parts.join("")`.

```aipl
module tests.functions.asset.image_decoder_z62_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_svgRender_62(): int:
  let arg_b = SvgBuilder(width = 4, height = 4, elements = [])
  let edge_b = SvgBuilder(width = 4, height = 4, elements = [])
  let resNom = svgRender(arg_b)
  let resEdge = svgRender(edge_b)
  assertEqInt(resNom.len(), 85, "svgRender nominal string length == 85")
  assertEqInt(resEdge.len(), 85, "svgRender boundary string length == 85")
  ret 0
```

---

### `stripJpegExif` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn stripJpegExif(jpegData: bytes): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `jpegData: bytes` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `stripJpegExif` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `jpegData: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z63_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_stripJpegExif_63(): int:
  let arg_jpegData = [65, 73, 80, 76]
  let edge_jpegData = [65]
  let resNom = stripJpegExif(arg_jpegData)
  let resEdge = stripJpegExif(edge_jpegData)
  assertEqInt(resNom.len(), 4, "stripJpegExif nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "stripJpegExif boundary resEdge.len() == 1")
  ret 0
```

---

### `decodePpm` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePpm(ppmStr: str): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ppmStr: str` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `decodePpm` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `ppmStr: str = "aipl_test"`; exercises core body path returning/computing `Ok(img)`.

```aipl
module tests.functions.asset.image_decoder_z64_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePpm_64(): int:
  let arg_ppmStr = "test"
  let edge_ppmStr = "a"
  let resNom = decodePpm(arg_ppmStr)
  let resEdge = decodePpm(edge_ppmStr)
  assert(resNom.isOk() == false, "decodePpm nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePpm boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodePpmP3` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePpmP3(ppmStr: str): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ppmStr: str` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodePpmP3` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `ppmStr: str = "aipl_test"`; exercises core body path returning/computing `decodePpm(ppmStr)`.

```aipl
module tests.functions.asset.image_decoder_z65_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePpmP3_65(): int:
  let arg_ppmStr = "test"
  let edge_ppmStr = "a"
  let resNom = decodePpmP3(arg_ppmStr)
  let resEdge = decodePpmP3(edge_ppmStr)
  assert(resNom.isOk() == false, "decodePpmP3 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePpmP3 boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodePpmBytes` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePpmBytes(data: bytes): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `decodePpmBytes` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(img)`.

```aipl
module tests.functions.asset.image_decoder_z66_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePpmBytes_66(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodePpmBytes(arg_data)
  let resEdge = decodePpmBytes(edge_data)
  assert(resNom.isOk() == false, "decodePpmBytes nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePpmBytes boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodePgm` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePgm(pgmStr: str): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pgmStr: str` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `decodePgm` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `pgmStr: str = "aipl_test"`; exercises core body path returning/computing `Ok(img)`.

```aipl
module tests.functions.asset.image_decoder_z67_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePgm_67(): int:
  let arg_pgmStr = "test"
  let edge_pgmStr = "a"
  let resNom = decodePgm(arg_pgmStr)
  let resEdge = decodePgm(edge_pgmStr)
  assert(resNom.isOk() == false, "decodePgm nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePgm boundary resEdge.isOk() == false")
  ret 0
```

---

### `decodePgmBytes` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePgmBytes(data: bytes): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `decodePgmBytes` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(img)`.

```aipl
module tests.functions.asset.image_decoder_z68_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePgmBytes_68(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodePgmBytes(arg_data)
  let resEdge = decodePgmBytes(edge_data)
  assert(resNom.isOk() == false, "decodePgmBytes nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePgmBytes boundary resEdge.isOk() == false")
  ret 0
```

---

### `encodeBmp` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeBmp(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodeBmp` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z69_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeBmp_69(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodeBmp(arg_img)
  let resEdge = encodeBmp(edge_img)
  assertEqInt(resNom.len(), 102, "encodeBmp nominal resNom.len() == 102")
  assertEqInt(resEdge.len(), 102, "encodeBmp boundary resEdge.len() == 102")
  ret 0
```

---

### `encodeBmp32` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeBmp32(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `encodeBmp32` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z70_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeBmp32_70(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodeBmp32(arg_img)
  let resEdge = encodeBmp32(edge_img)
  assertEqInt(resNom.len(), 118, "encodeBmp32 nominal resNom.len() == 118")
  assertEqInt(resEdge.len(), 118, "encodeBmp32 boundary resEdge.len() == 118")
  ret 0
```

---

### `encodeTga` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeTga(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `encodeTga` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z71_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeTga_71(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodeTga(arg_img)
  let resEdge = encodeTga(edge_img)
  assertEqInt(resNom.len(), 66, "encodeTga nominal resNom.len() == 66")
  assertEqInt(resEdge.len(), 66, "encodeTga boundary resEdge.len() == 66")
  ret 0
```

---

### `encodeTga32` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeTga32(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodeTga32` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z72_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeTga32_72(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodeTga32(arg_img)
  let resEdge = encodeTga32(edge_img)
  assertEqInt(resNom.len(), 82, "encodeTga32 nominal resNom.len() == 82")
  assertEqInt(resEdge.len(), 82, "encodeTga32 boundary resEdge.len() == 82")
  ret 0
```

---

### `qoiColorHash` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn qoiColorHash(r: int, g: int, b: int, a: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int, a: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `qoiColorHash` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `(r * 3 + g * 5 + b * 7 + a * 11) & 63`.

```aipl
module tests.functions.asset.image_decoder_z73_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_qoiColorHash_73(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = qoiColorHash(arg_r, arg_g, arg_b, arg_a)
  let resEdge = qoiColorHash(edge_r, edge_g, edge_b, edge_a)
  assertEqInt(resNom, 2, "qoiColorHash nominal resNom == 2")
  assertEqInt(resEdge, 7, "qoiColorHash boundary resEdge == 7")
  ret 0
```

---

### `qoiWrapDelta` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn qoiWrapDelta(d: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `qoiWrapDelta` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `d: int = 1`; exercises core body path returning/computing `if m >= 128: m - 256 else: m`.

```aipl
module tests.functions.asset.image_decoder_z74_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_qoiWrapDelta_74(): int:
  let arg_d = 2
  let edge_d = 0
  let resNom = qoiWrapDelta(arg_d)
  let resEdge = qoiWrapDelta(edge_d)
  assertEqInt(resNom, 2, "qoiWrapDelta nominal resNom == 2")
  assertEqInt(resEdge, 0, "qoiWrapDelta boundary resEdge == 0")
  ret 0
```

---

### `encodeQoi` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodeQoi(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodeQoi` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z75_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodeQoi_75(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodeQoi(arg_img)
  let resEdge = encodeQoi(edge_img)
  assertEqInt(resNom.len(), 23, "encodeQoi nominal resNom.len() == 23")
  assertEqInt(resEdge.len(), 23, "encodeQoi boundary resEdge.len() == 23")
  ret 0
```

---

### `detectImageFormatByPath` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn detectImageFormatByPath(path: str): str:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `detectImageFormatByPath` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `"UNKNOWN"`.

```aipl
module tests.functions.asset.image_decoder_z76_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_detectImageFormatByPath_76(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = detectImageFormatByPath(arg_path)
  let resEdge = detectImageFormatByPath(edge_path)
  assertEqStr(resNom, "UNKNOWN", "detectImageFormatByPath nominal string matches")
  assertEqStr(resEdge, "UNKNOWN", "detectImageFormatByPath boundary string matches")
  ret 0
```

---

### `readImageFile` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn readImageFile(path: str): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `readImageFile` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err("Unsupported format for " + path)`.

```aipl
module tests.functions.asset.image_decoder_z77_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_readImageFile_77(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = readImageFile(arg_path)
  let resEdge = readImageFile(edge_path)
  assert(resNom.isOk() == false, "readImageFile nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "readImageFile boundary resEdge.isOk() == false")
  ret 0
```

---

### `writeImageFile` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn writeImageFile(img: DecodedImage, path: str): Result[bool, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, path: str` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `writeImageFile` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Err("Unsupported format for " + path)`.

```aipl
module tests.functions.asset.image_decoder_z78_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_writeImageFile_78(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = writeImageFile(arg_img, arg_path)
  let resEdge = writeImageFile(edge_img, edge_path)
  assert(resNom.isOk() == false, "writeImageFile nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "writeImageFile boundary resEdge.isOk() == false")
  ret 0
```

---

### `imageCheckerboard` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageCheckerboard(w: int, h: int, cellSize: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `w: int, h: int, cellSize: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageCheckerboard` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `w: int = 128`, `h: int = 128`, `cellSize: int = 64`, `r1: int = 1`, `g1: int = 1`, `b1: int = 1`, `r2: int = 1`, `g2: int = 1`, `b2: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z79_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageCheckerboard_79(): int:
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_cellSize = 4
  let edge_cellSize = 1
  let arg_r1 = 2
  let edge_r1 = 0
  let arg_g1 = 2
  let edge_g1 = 0
  let arg_b1 = 4
  let edge_b1 = 1
  let arg_r2 = 2
  let edge_r2 = 0
  let arg_g2 = 2
  let edge_g2 = 0
  let arg_b2 = 4
  let edge_b2 = 1
  let resNom = imageCheckerboard(arg_w, arg_h, arg_cellSize, arg_r1, arg_g1, arg_b1, arg_r2, arg_g2, arg_b2)
  let resEdge = imageCheckerboard(edge_w, edge_h, edge_cellSize, edge_r1, edge_g1, edge_b1, edge_r2, edge_g2, edge_b2)
  assertEqInt(resNom.width, 2, "imageCheckerboard nominal resNom.width == 2")
  assertEqInt(resEdge.width, 0, "imageCheckerboard boundary resEdge.width == 0")
  ret 0
```

---

### `imageLinearGradient` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageLinearGradient(w: int, h: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int, vertical: bool): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `w: int, h: int, r1: int, g1: int, b1: int, r2: int, g2: int, b2: int, vertical: bool` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageLinearGradient` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `w: int = 128`, `h: int = 128`, `r1: int = 1`, `g1: int = 1`, `b1: int = 1`, `r2: int = 1`, `g2: int = 1`, `b2: int = 1`, `vertical: bool = true`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z80_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageLinearGradient_80(): int:
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_r1 = 2
  let edge_r1 = 0
  let arg_g1 = 2
  let edge_g1 = 0
  let arg_b1 = 4
  let edge_b1 = 1
  let arg_r2 = 2
  let edge_r2 = 0
  let arg_g2 = 2
  let edge_g2 = 0
  let arg_b2 = 4
  let edge_b2 = 1
  let arg_vertical = true
  let edge_vertical = false
  let resNom = imageLinearGradient(arg_w, arg_h, arg_r1, arg_g1, arg_b1, arg_r2, arg_g2, arg_b2, arg_vertical)
  let resEdge = imageLinearGradient(edge_w, edge_h, edge_r1, edge_g1, edge_b1, edge_r2, edge_g2, edge_b2, edge_vertical)
  assertEqInt(resNom.width, 2, "imageLinearGradient nominal resNom.width == 2")
  assertEqInt(resEdge.width, 0, "imageLinearGradient boundary resEdge.width == 0")
  ret 0
```

---

### `posterizeChannel` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn posterizeChannel(val: int, levels: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: int, levels: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `posterizeChannel` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `val: int = 1`, `levels: int = 1`; exercises core body path returning/computing `quantized`.

```aipl
module tests.functions.asset.image_decoder_z81_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_posterizeChannel_81(): int:
  let arg_val = 2
  let edge_val = 0
  let arg_levels = 2
  let edge_levels = 0
  let resNom = posterizeChannel(arg_val, arg_levels)
  let resEdge = posterizeChannel(edge_val, edge_levels)
  assertEqInt(resNom, 0, "posterizeChannel nominal resNom == 0")
  assertEqInt(resEdge, 0, "posterizeChannel boundary resEdge == 0")
  ret 0
```

---

### `imagePosterize` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imagePosterize(img: DecodedImage, levels: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, levels: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imagePosterize` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `levels: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z82_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imagePosterize_82(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_levels = 2
  let edge_levels = 0
  let resNom = imagePosterize(arg_img, arg_levels)
  let resEdge = imagePosterize(edge_img, edge_levels)
  assertEqInt(resNom.width, 4, "imagePosterize nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imagePosterize boundary resEdge.width == 4")
  ret 0
```

---

### `edgeDetectSqrt` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn edgeDetectSqrt(n: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `edgeDetectSqrt` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `x`.

```aipl
module tests.functions.asset.image_decoder_z83_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_edgeDetectSqrt_83(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = edgeDetectSqrt(arg_n)
  let resEdge = edgeDetectSqrt(edge_n)
  assertEqInt(resNom, 2, "edgeDetectSqrt nominal resNom == 2")
  assertEqInt(resEdge, 1, "edgeDetectSqrt boundary resEdge == 1")
  ret 0
```

---

### `getPixelLuminanceClamped` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn getPixelLuminanceClamped(img: DecodedImage, x: int, y: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage, x: int, y: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `getPixelLuminanceClamped` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `(r * 77 + g * 150 + b * 29) >> 8`.

```aipl
module tests.functions.asset.image_decoder_z84_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_getPixelLuminanceClamped_84(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = getPixelLuminanceClamped(arg_img, arg_x, arg_y)
  let resEdge = getPixelLuminanceClamped(edge_img, edge_x, edge_y)
  assertEqInt(resNom, 0, "getPixelLuminanceClamped nominal resNom == 0")
  assertEqInt(resEdge, 0, "getPixelLuminanceClamped boundary resEdge == 0")
  ret 0
```

---

### `imageEdgeDetect` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageEdgeDetect(img: DecodedImage): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageEdgeDetect` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z85_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageEdgeDetect_85(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = imageEdgeDetect(arg_img)
  let resEdge = imageEdgeDetect(edge_img)
  assertEqInt(resNom.width, 4, "imageEdgeDetect nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageEdgeDetect boundary resEdge.width == 4")
  ret 0
```

---

### `pngCrc32` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn pngCrc32(chunkTypeAndData: [int]): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `chunkTypeAndData: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `pngCrc32` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `chunkTypeAndData: [int] = [1]`; exercises core body path returning/computing `(crc ^ 0xFFFFFFFF) & 0xFFFFFFFF`.

```aipl
module tests.functions.asset.image_decoder_z86_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pngCrc32_86(): int:
  let arg_chunkTypeAndData = [4]
  let edge_chunkTypeAndData = []
  let resNom = pngCrc32(arg_chunkTypeAndData)
  let resEdge = pngCrc32(edge_chunkTypeAndData)
  assertEqInt(resNom, 3580832660, "pngCrc32 nominal resNom == 3580832660")
  assertEqInt(resEdge, 0, "pngCrc32 boundary resEdge == 0")
  ret 0
```

---

### `pngAdler32` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn pngAdler32(raw: [int]): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `raw: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `pngAdler32` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `raw: [int] = [1]`; exercises core body path returning/computing `((s2 << 16) | s1) & 0xFFFFFFFF`.

```aipl
module tests.functions.asset.image_decoder_z87_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pngAdler32_87(): int:
  let arg_raw = [2]
  let edge_raw = []
  let resNom = pngAdler32(arg_raw)
  let resEdge = pngAdler32(edge_raw)
  assertEqInt(resNom, 196611, "pngAdler32 nominal resNom == 196611")
  assertEqInt(resEdge, 1, "pngAdler32 boundary resEdge == 1")
  ret 0
```

---

### `pngPushU32BE` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn pngPushU32BE(mut out: [int], val: int): [int]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut out: [int], val: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `pngPushU32BE` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `out: [int] = [1]`, `val: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z88_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pngPushU32BE_88(): int:
  let arg_out = [2]
  let edge_out = []
  let arg_val = 2
  let edge_val = 0
  let resNom = pngPushU32BE(arg_out, arg_val)
  let resEdge = pngPushU32BE(edge_out, edge_val)
  assertEqInt(resNom.len(), 5, "pngPushU32BE nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 4, "pngPushU32BE boundary resEdge.len() == 4")
  ret 0
```

---

### `pngAppendChunk` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn pngAppendChunk(mut out: [int], t0: int, t1: int, t2: int, t3: int, payload: [int]): [int]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut out: [int], t0: int, t1: int, t2: int, t3: int, payload: [int]` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `pngAppendChunk` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `out: [int] = [1]`, `t0: int = 1`, `t1: int = 1`, `t2: int = 1`, `t3: int = 1`, `payload: [int] = [1]`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.asset.image_decoder_z89_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_pngAppendChunk_89(): int:
  let arg_out = [2]
  let edge_out = []
  let arg_t0 = 2
  let edge_t0 = 0
  let arg_t1 = 2
  let edge_t1 = 0
  let arg_t2 = 2
  let edge_t2 = 0
  let arg_t3 = 2
  let edge_t3 = 0
  let arg_payload = [1]
  let edge_payload = []
  let resNom = pngAppendChunk(arg_out, arg_t0, arg_t1, arg_t2, arg_t3, arg_payload)
  let resEdge = pngAppendChunk(edge_out, edge_t0, edge_t1, edge_t2, edge_t3, edge_payload)
  assertEqInt(resNom.len(), 14, "pngAppendChunk nominal resNom.len() == 14")
  assertEqInt(resEdge.len(), 12, "pngAppendChunk boundary resEdge.len() == 12")
  ret 0
```

---

### `encodePng` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn encodePng(img: DecodedImage): bytes:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `img: DecodedImage` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `encodePng` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.asset.image_decoder_z90_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_encodePng_90(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let resNom = encodePng(arg_img)
  let resEdge = encodePng(edge_img)
  assertEqInt(resNom.len(), 136, "encodePng nominal resNom.len() == 136")
  assertEqInt(resEdge.len(), 136, "encodePng boundary resEdge.len() == 136")
  ret 0
```

---

### `decodePng` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn decodePng(data: bytes): Result[DecodedImage, str]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[DecodedImage, str]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `decodePng` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(img)`.

```aipl
module tests.functions.asset.image_decoder_z91_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_decodePng_91(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodePng(arg_data)
  let resEdge = decodePng(edge_data)
  assert(resNom.isOk() == false, "decodePng nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodePng boundary resEdge.isOk() == false")
  ret 0
```

---

### `textureAtlasGridNew` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn textureAtlasGridNew(cols: int, rows: int, cellW: int, cellH: int, padding: int = 0): TextureAtlasGrid:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cols: int, rows: int, cellW: int, cellH: int, padding: int = 0` | **Returns**: `TextureAtlasGrid`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `textureAtlasGridNew` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `cols: int = 1`, `rows: int = 1`, `cellW: int = 1`, `cellH: int = 1`, `padding: int = 1`; exercises core body path returning/computing `TextureAtlasGrid(cols = maxInt(1, cols), rows = maxInt(1, rows), cellW = maxInt(1, cellW), cellH = maxInt(1, cellH), padding = maxInt(0, padding))`.

```aipl
module tests.functions.asset.image_decoder_z92_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_textureAtlasGridNew_92(): int:
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let arg_cellW = 2
  let edge_cellW = 0
  let arg_cellH = 2
  let edge_cellH = 0
  let arg_padding = 4
  let edge_padding = 1
  let resNom = textureAtlasGridNew(arg_cols, arg_rows, arg_cellW, arg_cellH, arg_padding)
  let resEdge = textureAtlasGridNew(edge_cols, edge_rows, edge_cellW, edge_cellH, edge_padding)
  assertEqInt(resNom.cols, 4, "textureAtlasGridNew nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 1, "textureAtlasGridNew boundary resEdge.cols == 1")
  ret 0
```

---

### `atlasGridRegion` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn atlasGridRegion(grid: TextureAtlasGrid, index: int): [int]:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `grid: TextureAtlasGrid, index: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `atlasGridRegion` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `grid: TextureAtlasGrid = TextureAtlasGrid(cols = 1, rows = 1, cellW = 1, cellH = 1, padding = 1)`, `index: int = 0`; exercises core body path returning/computing `[x, y, grid.cellW, grid.cellH]`.

```aipl
module tests.functions.asset.image_decoder_z93_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_atlasGridRegion_93(): int:
  let arg_grid = TextureAtlasGrid(cols = 4, rows = 4, cellW = 2, cellH = 2, padding = 4)
  let edge_grid = TextureAtlasGrid(cols = 4, rows = 4, cellW = 0, cellH = 0, padding = 1)
  let arg_index = 4
  let edge_index = 1
  let resNom = atlasGridRegion(arg_grid, arg_index)
  let resEdge = atlasGridRegion(edge_grid, edge_index)
  assertEqInt(resNom.len(), 4, "atlasGridRegion nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 4, "atlasGridRegion boundary resEdge.len() == 4")
  ret 0
```

---

### `imageBlitEx` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBlitEx(mut dst: DecodedImage, src: DecodedImage, sx: int, sy: int, sw: int, sh: int, dx: int, dy: int, dw: int, dh: int, flipX: bool = false, flipY: bool = false): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut dst: DecodedImage, src: DecodedImage, sx: int, sy: int, sw: int, sh: int, dx: int, dy: int, dw: int, dh: int, flipX: bool = false, flipY: bool = false` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageBlitEx` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `dst: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `src: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `sx: int = 1`, `sy: int = 1`, `sw: int = 1`, `sh: int = 1`, `dx: int = 1`, `dy: int = 1`, `dw: int = 1`, `dh: int = 1`, `flipX: bool = true`, `flipY: bool = true`; exercises core body path returning/computing `dst`.

```aipl
module tests.functions.asset.image_decoder_z94_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBlitEx_94(): int:
  let arg_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_sx = 1
  let edge_sx = 0
  let arg_sy = 1
  let edge_sy = 0
  let arg_sw = 2
  let edge_sw = 0
  let arg_sh = 2
  let edge_sh = 0
  let arg_dx = 1
  let edge_dx = 0
  let arg_dy = 1
  let edge_dy = 0
  let arg_dw = 2
  let edge_dw = 0
  let arg_dh = 2
  let edge_dh = 0
  let arg_flipX = true
  let edge_flipX = false
  let arg_flipY = true
  let edge_flipY = false
  let resNom = imageBlitEx(arg_dst, arg_src, arg_sx, arg_sy, arg_sw, arg_sh, arg_dx, arg_dy, arg_dw, arg_dh, arg_flipX, arg_flipY)
  let resEdge = imageBlitEx(edge_dst, edge_src, edge_sx, edge_sy, edge_sw, edge_sh, edge_dx, edge_dy, edge_dw, edge_dh, edge_flipX, edge_flipY)
  assertEqInt(resNom.width, 4, "imageBlitEx nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageBlitEx boundary resEdge.width == 4")
  ret 0
```

---

### `imageBlitNinePatch` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageBlitNinePatch(mut dst: DecodedImage, src: DecodedImage, left: int, top: int, right: int, bottom: int, dx: int, dy: int, dw: int, dh: int): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut dst: DecodedImage, src: DecodedImage, left: int, top: int, right: int, bottom: int, dx: int, dy: int, dw: int, dh: int` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_144_asset_font_sdf_text_renderer_window.aipl`
- **Behavioral Summary**: Verify `imageBlitNinePatch` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `dst: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `src: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `left: int = 1`, `top: int = 1`, `right: int = 1`, `bottom: int = 1`, `dx: int = 1`, `dy: int = 1`, `dw: int = 1`, `dh: int = 1`; exercises core body path returning/computing `dst`.

```aipl
module tests.functions.asset.image_decoder_z95_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageBlitNinePatch_95(): int:
  let arg_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_dst = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_src = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_left = 2
  let edge_left = 0
  let arg_top = 2
  let edge_top = 0
  let arg_right = 2
  let edge_right = 0
  let arg_bottom = 4
  let edge_bottom = 1
  let arg_dx = 1
  let edge_dx = 0
  let arg_dy = 1
  let edge_dy = 0
  let arg_dw = 2
  let edge_dw = 0
  let arg_dh = 2
  let edge_dh = 0
  let resNom = imageBlitNinePatch(arg_dst, arg_src, arg_left, arg_top, arg_right, arg_bottom, arg_dx, arg_dy, arg_dw, arg_dh)
  let resEdge = imageBlitNinePatch(edge_dst, edge_src, edge_left, edge_top, edge_right, edge_bottom, edge_dx, edge_dy, edge_dw, edge_dh)
  assertEqInt(resNom.width, 4, "imageBlitNinePatch nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageBlitNinePatch boundary resEdge.width == 4")
  ret 0
```

---

### `glyphRowMask5x7` (`std/asset/image_decoder.aipl`)

- **Signature**: `fn glyphRowMask5x7(code: int, row: int): int:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int, row: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_142_asset_image_decoder_qoi_bmp_ppm_window.aipl`
- **Behavioral Summary**: Verify `glyphRowMask5x7` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `code: int = 1`, `row: int = 1`; exercises core body path returning/computing `17   // 10001`.

```aipl
module tests.functions.asset.image_decoder_z96_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_glyphRowMask5x7_96(): int:
  let arg_code = 2
  let edge_code = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = glyphRowMask5x7(arg_code, arg_row)
  let resEdge = glyphRowMask5x7(edge_code, edge_row)
  assertEqInt(resNom, 0, "glyphRowMask5x7 nominal resNom == 0")
  assertEqInt(resEdge, 14, "glyphRowMask5x7 boundary resEdge == 14")
  ret 0
```

---

### `imageDrawText` (`std/asset/image_decoder.aipl`)

- **Signature**: `pub fn imageDrawText(mut img: DecodedImage, x: int, y: int, text: str, color: int, scale: int = 1): DecodedImage:`
- **Import**: `import * from "std/asset/image_decoder"` (or barrel `import * from "std/asset/asset_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut img: DecodedImage, x: int, y: int, text: str, color: int, scale: int = 1` | **Returns**: `DecodedImage`
- **Unit Test**: `tests/functions/asset/image_decoder_test.aipl` | **Example**: `examples/ex_143_asset_atlas_packer_shelf_maxrects_window.aipl`
- **Behavioral Summary**: Verify `imageDrawText` lossless codec round-trips (PNG/QOI/BMP/TGA/PPM/PGM/SVG), border flood-fill alpha keying (`applyBorderFloodAlphaKey`), geometric transforms, convolution filters, and 9-patch blitting. Concrete nominal inputs: `img: DecodedImage = DecodedImage(width = 128, height = 128, channels = 2, pixelsRgba = [1], format = 1, pixels = [1])`, `x: int = 1`, `y: int = 1`, `text: str = "aipl_test"`, `color: int = 1`, `scale: int = 1`; exercises core body path returning/computing `img`.

```aipl
module tests.functions.asset.image_decoder_z97_test
import * from "std/asset/image_decoder"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_image_decoder_imageDrawText_97(): int:
  let arg_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 4, pixels = [])
  let edge_img = DecodedImage(width = 4, height = 4, channels = 4, pixelsRgba = [], format = 1, pixels = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_text = "test"
  let edge_text = "a"
  let arg_color = 1
  let edge_color = 0
  let arg_scale = 2
  let edge_scale = 0
  let resNom = imageDrawText(arg_img, arg_x, arg_y, arg_text, arg_color, arg_scale)
  let resEdge = imageDrawText(edge_img, edge_x, edge_y, edge_text, edge_color, edge_scale)
  assertEqInt(resNom.width, 4, "imageDrawText nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "imageDrawText boundary resEdge.width == 4")
  ret 0
```

---

### `createAiplApkPayloadHeader` (`std/asset/apk_container_format.aipl`)

- **Signature**: `pub fn createAiplApkPayloadHeader(codePayload: str, assetCount: int): AiplApkPayloadHeader requires assetCount >= 0 ensures result.magic == "AIPLAPK1" and result.bootMode == 1:`
- **Import**: `import { createAiplApkPayloadHeader, BOOT_LOCKED_SINGLE_APP } from "std/asset/apk_container_format"`
- **Receiver**: `None (free function)` | **Parameters**: `codePayload: str, assetCount: int` | **Returns**: `AiplApkPayloadHeader`
- **Unit Test**: `tests/functions/asset/apk_container_format_test.aipl` | **Example**: `examples/ex_150_asset_bundle_vfs_mount_cli.aipl`
- **Behavioral Summary**: Constructs an `AiplApkPayloadHeader` with magic `"AIPLAPK1"`, version `1`, `bootMode = BOOT_LOCKED_SINGLE_APP` (1), and calculates the payload CRC32 checksum.

```aipl
module tests.functions.asset.apk_format_ref_01_test
import { createAiplApkPayloadHeader, BOOT_LOCKED_SINGLE_APP } from "std/asset/apk_container_format"
import { assert, assertEqInt, assertEqStr } from "std/prelude"
pub fn test_createAiplApkPayloadHeader_ref(): int:
  let h = createAiplApkPayloadHeader("fn main(): int:\n  ret 0", 2)
  assert(h.magicValid == 1, "header is valid")
  assertEqStr(h.magic, "AIPLAPK1", "magic matches")
  assertEqInt(h.bootMode, BOOT_LOCKED_SINGLE_APP, "boot mode is locked single app")
  ret 0
```

---

### `serializeAiplApkPayload` (`std/asset/apk_container_format.aipl`)

- **Signature**: `pub fn serializeAiplApkPayload(codePayload: str, assetCount: int): str requires assetCount >= 0 ensures result == "" or result.startsWith("AIPLAPK1|"):`
- **Import**: `import { serializeAiplApkPayload } from "std/asset/apk_container_format"`
- **Receiver**: `None (free function)` | **Parameters**: `codePayload: str, assetCount: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/asset/apk_container_format_test.aipl` | **Example**: `examples/ex_150_asset_bundle_vfs_mount_cli.aipl`
- **Behavioral Summary**: Serializes the application code payload into a single-file APK asset stream (`"AIPLAPK1|1|1|<len>|<assetCount>|<crc>|<code>"`).

```aipl
module tests.functions.asset.apk_format_ref_02_test
import { serializeAiplApkPayload } from "std/asset/apk_container_format"
import { assert } from "std/prelude"
pub fn test_serializeAiplApkPayload_ref(): int:
  let s = serializeAiplApkPayload("let val = 42", 0)
  assert(s.startsWith("AIPLAPK1|1|1|12|0|"), "payload formatted with header and crc")
  ret 0
```

---

### `parseAndVerifyAiplApkPayload` (`std/asset/apk_container_format.aipl`)

- **Signature**: `pub fn parseAndVerifyAiplApkPayload(rawImage: str): Result[str, str] requires rawImage.len() >= 0 ensures rawImage.startsWith("AIPLAPK1|") or result.isErr():`
- **Import**: `import { parseAndVerifyAiplApkPayload, serializeAiplApkPayload } from "std/asset/apk_container_format"`
- **Receiver**: `None (free function)` | **Parameters**: `rawImage: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/asset/apk_container_format_test.aipl` | **Example**: `examples/ex_150_asset_bundle_vfs_mount_cli.aipl`
- **Behavioral Summary**: Unpacks an APK container payload image, asserting `"AIPLAPK1"` magic, single-app boot lock, byte length equality, and CRC32 payload verification.

```aipl
module tests.functions.asset.apk_format_ref_03_test
import { parseAndVerifyAiplApkPayload, serializeAiplApkPayload } from "std/asset/apk_container_format"
import { assert, assertEqStr } from "std/prelude"
pub fn test_parseAndVerifyAiplApkPayload_ref(): int:
  let raw = serializeAiplApkPayload("let answer = 42", 1)
  let res = parseAndVerifyAiplApkPayload(raw)
  assert(res.isOk() == true, "payload verified")
  assertEqStr(res.unwrap(), "let answer = 42", "payload content matches")
  ret 0
```

---

### `appendApkEmbeddedAssetEntry` (`std/asset/apk_container_format.aipl`)

- **Signature**: `pub fn appendApkEmbeddedAssetEntry(mut assetTable: Map[str, int], relPath: str, content: str): (Map[str, int], int) requires relPath.len() >= 0 and content.len() >= 0 ensures result[1] >= 0:`
- **Import**: `import { appendApkEmbeddedAssetEntry } from "std/asset/apk_container_format"`
- **Receiver**: `None (free function)` | **Parameters**: `mut assetTable: Map[str, int], relPath: str, content: str` | **Returns**: `(Map[str, int], int)`
- **Unit Test**: `tests/functions/asset/apk_container_format_test.aipl` | **Example**: `examples/ex_150_asset_bundle_vfs_mount_cli.aipl`
- **Behavioral Summary**: Registers an embedded asset relative path and content into the APK asset table, calculating its CRC32 checksum and rejecting path traversal (`".."`) attempts.

```aipl
module tests.functions.asset.apk_format_ref_04_test
import { appendApkEmbeddedAssetEntry } from "std/asset/apk_container_format"
import { assert } from "std/prelude"
pub fn test_appendApkEmbeddedAssetEntry_ref(): int:
  mut t: Map[str, int] = Map.new()
  let (updated, crc) = appendApkEmbeddedAssetEntry(t, "assets/icon.png", "PNG_DATA")
  assert(updated.containsKey("assets/icon.png"), "asset registered")
  ret 0
```
