[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 25: `gfx` API Reference

> Complete API reference manual for AIPL standard library domain `gfx` (55 callable functions & methods across ["std/gfx/color.aipl", "std/gfx/framebuffer.aipl", "std/gfx/gfx_mod.aipl", "std/gfx/gpu_buffer.aipl", "std/gfx/gpu_command.aipl", "std/gfx/gpu_device.aipl", "std/gfx/gpu_pipeline.aipl", "std/gfx/gpu_shader.aipl", "std/gfx/gpu_texture.aipl", "std/gfx/postfx_pass.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `gfx`
- **Target Source Modules**: ["std/gfx/color.aipl", "std/gfx/framebuffer.aipl", "std/gfx/gfx_mod.aipl", "std/gfx/gpu_buffer.aipl", "std/gfx/gpu_command.aipl", "std/gfx/gpu_device.aipl", "std/gfx/gpu_pipeline.aipl", "std/gfx/gpu_shader.aipl", "std/gfx/gpu_texture.aipl", "std/gfx/postfx_pass.aipl"]
- **Total Callable Functions & Methods**: 55
- **Total Data Types (`struct` & `enum`)**: 32
- **Hardware & Software Framebuffer Integration**: Native 32-bit BGRA X11 MIT-SHM framebuffer (`setWindowMode("x11")`), `libGL.so.1` GLX hardware batch renderer (`setWindowMode("glx")`), and fast 256-entry sRGB relative luminance lookup table (`examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`, `examples/ex_251`–`ex_255`).
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(32 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ColorRgba8` | `pub struct` | `std/gfx/color.aipl` | `r: int`, `g: int`, `b: int`, `a: int = 255` | `ColorRgba8(r, g, b, a)` |
| `LinearColorF32` | `pub struct` | `std/gfx/color.aipl` | `r: float`, `g: float`, `b: float`, `a: float = 1.0` | `LinearColorF32(r, g, b, a)` |
| `ColorHsla` | `pub struct` | `std/gfx/color.aipl` | `h: float`, `s: float`, `l: float`, `a: float = 1.0` | `ColorHsla(h, s, l, a)` |
| `ColorOklab` | `pub struct` | `std/gfx/color.aipl` | `l: float`, `a: float`, `b: float`, `alpha: float = 1.0` | `ColorOklab(l, a, b, alpha)` |
| `ColorOklch` | `pub struct` | `std/gfx/color.aipl` | `l: float`, `c: float`, `h: float`, `alpha: float = 1.0` | `ColorOklch(l, c, h, alpha)` |
| `ColorLut3D` | `pub struct` | `std/gfx/color.aipl` | `size: int`, `table: [LinearColorF32]` | `ColorLut3D(size, table)` |
| `RadixScale12` | `pub struct` | `std/gfx/color.aipl` | `s1: int`, `s2: int`, `s3: int`, `s4: int`, `s5: int`, `s6: int`, `s7: int`, `s8: int`, `s9: int`, `s10: int`, `s11: int`, `s12: int` | `RadixScale12(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12)` |
| `Framebuffer` | `pub struct` | `std/gfx/framebuffer.aipl` | `width: int`, `height: int`, `colorAttachment: GpuTexture`, `depthAttachment: GpuTexture`, `sampleCount: int` | `Framebuffer(width, height, colorAttachment, depthAttachment, sampleCount)` |
| `GpuBuffer` | `pub struct` | `std/gfx/gpu_buffer.aipl` | `bufferId: int`, `sizeBytes: int`, `usageFlags: int`, `isMapped: bool` | `GpuBuffer(bufferId, sizeBytes, usageFlags, isMapped)` |
| `StagingRingBuffer` | `pub struct` | `std/gfx/gpu_buffer.aipl` | `capacityBytes: int`, `writeSlot: int`, `readSlot: int`, `frameId: int` | `StagingRingBuffer(capacityBytes, writeSlot, readSlot, frameId)` |
| `ClearColor` | `pub struct` | `std/gfx/gpu_command.aipl` | `r: float`, `g: float`, `b: float`, `a: float = 1.0` | `ClearColor(r, g, b, a)` |
| `RenderPassDescriptor` | `pub struct` | `std/gfx/gpu_command.aipl` | `colorBuffer: GpuTexture`, `clearColor: ClearColor`, `depthBuffer: GpuTexture`, `clearDepth: float` | `RenderPassDescriptor(colorBuffer, clearColor, depthBuffer, clearDepth)` |
| `DrawCommand` | `pub struct` | `std/gfx/gpu_command.aipl` | `pipelineId: int`, `vertexCount: int`, `instanceCount: int`, `firstVertex: int`, `firstInstance: int` | `DrawCommand(pipelineId, vertexCount, instanceCount, firstVertex, firstInstance)` |
| `CommandEncoder` | `pub struct` | `std/gfx/gpu_command.aipl` | `commandQueue: [DrawCommand]`, `isEnded: bool` | `CommandEncoder(commandQueue, isEnded)` |
| `CommandBuffer` | `pub struct` | `std/gfx/gpu_command.aipl` | `bufferId: int`, `commands: [DrawCommand]` | `CommandBuffer(bufferId, commands)` |
| `GpuAdapterInfo` | `pub struct` | `std/gfx/gpu_device.aipl` | `name: str`, `vendorId: int`, `deviceId: int`, `backendType: int`, `isSoftware: bool` | `GpuAdapterInfo(name, vendorId, deviceId, backendType, isSoftware)` |
| `GpuDeviceLimits` | `pub struct` | `std/gfx/gpu_device.aipl` | `maxTextureDimension2D: int`, `maxTextureDimension3D: int`, `maxUniformBufferBindingSize: int`, `maxStorageBufferBindingSize: int`, `maxVertexBuffers: int`, `maxComputeWorkgroupStorageSize: int` | `GpuDeviceLimits(maxTextureDimension2D, maxTextureDimension3D, maxUniformBufferBindingSize, maxStorageBufferBindingSize, maxVertexBuffers, maxComputeWorkgroupStorageSize)` |
| `GpuDevice` | `pub struct` | `std/gfx/gpu_device.aipl` | `adapter: GpuAdapterInfo`, `limits: GpuDeviceLimits`, `deviceHandle: int`, `isAlive: bool` | `GpuDevice(adapter, limits, deviceHandle, isAlive)` |
| `BlendMode` | `pub struct` | `std/gfx/gpu_pipeline.aipl` | `enabled: bool`, `srcColor: int`, `dstColor: int`, `opColor: int`, `srcAlpha: int`, `dstAlpha: int`, `opAlpha: int` | `BlendMode(enabled, srcColor, dstColor, opColor, srcAlpha, dstAlpha, opAlpha)` |
| `DepthStencilState` | `pub struct` | `std/gfx/gpu_pipeline.aipl` | `depthTest: bool`, `depthWrite: bool`, `depthCompareOp: int` | `DepthStencilState(depthTest, depthWrite, depthCompareOp)` |
| `VertexAttribute` | `pub struct` | `std/gfx/gpu_pipeline.aipl` | `location: int`, `offsetBytes: int`, `formatSize: int` | `VertexAttribute(location, offsetBytes, formatSize)` |
| `VertexLayout` | `pub struct` | `std/gfx/gpu_pipeline.aipl` | `strideBytes: int`, `attributes: [VertexAttribute]` | `VertexLayout(strideBytes, attributes)` |
| `RenderPipelineState` | `pub struct` | `std/gfx/gpu_pipeline.aipl` | `pipelineId: int`, `shader: ShaderModule`, `blend: BlendMode`, `depth: DepthStencilState`, `vertexLayout: VertexLayout` | `RenderPipelineState(pipelineId, shader, blend, depth, vertexLayout)` |
| `ShaderUniformBinding` | `pub struct` | `std/gfx/gpu_shader.aipl` | `name: str`, `bindingSlot: int`, `groupSlot: int`, `sizeBytes: int`, `offsetBytes: int` | `ShaderUniformBinding(name, bindingSlot, groupSlot, sizeBytes, offsetBytes)` |
| `ShaderModule` | `pub struct` | `std/gfx/gpu_shader.aipl` | `shaderId: int`, `stage: int`, `entryPoint: str`, `wgslSource: str`, `uniformBindings: [ShaderUniformBinding]` | `ShaderModule(shaderId, stage, entryPoint, wgslSource, uniformBindings)` |
| `TextureFormat` | `pub struct` | `std/gfx/gpu_texture.aipl` | `id: int`, `bytesPerPixel: int`, `hasAlpha: bool`, `isDepth: bool`, `isCompressed: bool` | `TextureFormat(id, bytesPerPixel, hasAlpha, isDepth, isCompressed)` |
| `SamplerState` | `pub struct` | `std/gfx/gpu_texture.aipl` | `filterMin: int`, `filterMag: int`, `filterMip: int`, `wrapU: int`, `wrapV: int`, `wrapW: int`, `maxAnisotropy: int` | `SamplerState(filterMin, filterMag, filterMip, wrapU, wrapV, wrapW, maxAnisotropy)` |
| `GpuTexture` | `pub struct` | `std/gfx/gpu_texture.aipl` | `textureId: int`, `width: int`, `height: int`, `depth: int`, `mipLevels: int`, `format: TextureFormat`, `dimension: int` | `GpuTexture(textureId, width, height, depth, mipLevels, format, dimension)` |
| `BloomSettings` | `pub struct` | `std/gfx/postfx_pass.aipl` | `threshold: float`, `intensity: float`, `knee: float`, `radius: float` | `BloomSettings(threshold, intensity, knee, radius)` |
| `TonemapSettings` | `pub struct` | `std/gfx/postfx_pass.aipl` | `operator: int`, `exposure: float`, `whitePoint: float` | `TonemapSettings(operator, exposure, whitePoint)` |
| `VignetteSettings` | `pub struct` | `std/gfx/postfx_pass.aipl` | `radius: float`, `softness: float`, `color: ColorRgba8` | `VignetteSettings(radius, softness, color)` |
| `PostFxChain` | `pub struct` | `std/gfx/postfx_pass.aipl` | `bloom: BloomSettings`, `tonemap: TonemapSettings`, `vignette: VignetteSettings`, `enabled: bool` | `PostFxChain(bloom, tonemap, vignette, enabled)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/gfx/color.aipl` | `clampByte8` | `fn clampByte8(v: int): int:` | `tests/functions/gfx/color_test.aipl` |
| `2` | `std/gfx/color.aipl` | `clampUnit01` | `fn clampUnit01(v: float): float:` | `tests/functions/gfx/color_test.aipl` |
| `3` | `std/gfx/color.aipl` | `rgba8` | `pub fn rgba8(r: int, g: int, b: int, a: int = 255): ColorRgba8:` | `tests/functions/gfx/color_test.aipl` |
| `4` | `std/gfx/color.aipl` | `linearRgb` | `pub fn linearRgb(r: float, g: float, b: float, a: float = 1.0): LinearColorF32:` | `tests/functions/gfx/color_test.aipl` |
| `5` | `std/gfx/color.aipl` | `srgbChanToLinear` | `fn srgbChanToLinear(c: float): float:` | `tests/functions/gfx/color_test.aipl` |
| `6` | `std/gfx/color.aipl` | `linearChanToSrgb` | `fn linearChanToSrgb(c: float): float:` | `tests/functions/gfx/color_test.aipl` |
| `7` | `std/gfx/color.aipl` | `srgbToLinear` | `pub fn srgbToLinear(c: ColorRgba8): LinearColorF32:` | `tests/functions/gfx/color_test.aipl` |
| `8` | `std/gfx/color.aipl` | `linearToSrgb` | `pub fn linearToSrgb(c: LinearColorF32): ColorRgba8:` | `tests/functions/gfx/color_test.aipl` |
| `9` | `std/gfx/color.aipl` | `cbrtPos` | `fn cbrtPos(x: float): float:` | `tests/functions/gfx/color_test.aipl` |
| `10` | `std/gfx/color.aipl` | `rgba8ToOklab` | `pub fn rgba8ToOklab(c: ColorRgba8): ColorOklab:` | `tests/functions/gfx/color_test.aipl` |
| `11` | `std/gfx/color.aipl` | `oklabToRgba8` | `pub fn oklabToRgba8(lab: ColorOklab): ColorRgba8:` | `tests/functions/gfx/color_test.aipl` |
| `12` | `std/gfx/color.aipl` | `oklabToOklch` | `pub fn oklabToOklch(lab: ColorOklab): ColorOklch:` | `tests/functions/gfx/color_test.aipl` |
| `13` | `std/gfx/color.aipl` | `oklchToOklab` | `pub fn oklchToOklab(lch: ColorOklch): ColorOklab:` | `tests/functions/gfx/color_test.aipl` |
| `14` | `std/gfx/color.aipl` | `lerpOklab` | `pub fn lerpOklab(c1: ColorRgba8, c2: ColorRgba8, t: float): ColorRgba8:` | `tests/functions/gfx/color_test.aipl` |
| `15` | `std/gfx/color.aipl` | `wcagRelativeLuminance` | `pub fn wcagRelativeLuminance(c: ColorRgba8): float:` | `tests/functions/gfx/color_test.aipl` |
| `16` | `std/gfx/color.aipl` | `wcagContrastRatio` | `pub fn wcagContrastRatio(fg: ColorRgba8, bg: ColorRgba8): float:` | `tests/functions/gfx/color_test.aipl` |
| `17` | `std/gfx/color.aipl` | `apcaLuminance` | `fn apcaLuminance(c: ColorRgba8): float:` | `tests/functions/gfx/color_test.aipl` |
| `18` | `std/gfx/color.aipl` | `apcaContrast` | `pub fn apcaContrast(text: ColorRgba8, bg: ColorRgba8): float:` | `tests/functions/gfx/color_test.aipl` |
| `19` | `std/gfx/color.aipl` | `hexNibble` | `fn hexNibble(code: int): int:` | `tests/functions/gfx/color_test.aipl` |
| `20` | `std/gfx/color.aipl` | `hexByteAt` | `fn hexByteAt(s: str, pos: int): int:` | `tests/functions/gfx/color_test.aipl` |
| `21` | `std/gfx/color.aipl` | `parseHexColor` | `pub fn parseHexColor(hexStr: str): ColorRgba8:` | `tests/functions/gfx/color_test.aipl` |
| `22` | `std/gfx/color.aipl` | `byteToHexUpper` | `fn byteToHexUpper(v: int): str:` | `tests/functions/gfx/color_test.aipl` |
| `23` | `std/gfx/color.aipl` | `toHexColor` | `pub fn toHexColor(c: ColorRgba8): str:` | `tests/functions/gfx/color_test.aipl` |
| `24` | `std/gfx/color.aipl` | `sampleColorLut3D` | `pub fn sampleColorLut3D(lut: ColorLut3D, inColor: LinearColorF32): LinearColorF32:` | `tests/functions/gfx/color_test.aipl` |
| `25` | `std/gfx/framebuffer.aipl` | `createFramebuffer` | `pub fn createFramebuffer(dev: GpuDevice, w: int, h: int, hasDepth: bool = true, samples: int = 1): Framebuffer:` | `tests/functions/gfx/framebuffer_test.aipl` |
| `26` | `std/gfx/framebuffer.aipl` | `resizeFramebuffer` | `pub fn resizeFramebuffer(dev: GpuDevice, fb: Framebuffer, newW: int, newH: int): Framebuffer:` | `tests/functions/gfx/framebuffer_test.aipl` |
| `27` | `std/gfx/gpu_buffer.aipl` | `createGpuBuffer` | `pub fn createGpuBuffer(dev: GpuDevice, sizeBytes: int, usage: int): GpuBuffer:` | `tests/functions/gfx/gpu_buffer_test.aipl` |
| `28` | `std/gfx/gpu_buffer.aipl` | `writeGpuBuffer` | `pub fn writeGpuBuffer(dev: GpuDevice, buf: GpuBuffer, byteOffset: int, dataBytes: [int]): bool:` | `tests/functions/gfx/gpu_buffer_test.aipl` |
| `29` | `std/gfx/gpu_buffer.aipl` | `alignOffsetStd140` | `pub fn alignOffsetStd140(currentOffset: int, baseAlignmentBytes: int): int:` | `tests/functions/gfx/gpu_buffer_test.aipl` |
| `30` | `std/gfx/gpu_buffer.aipl` | `createStagingRingBuffer` | `pub fn createStagingRingBuffer(capacityBytes: int): StagingRingBuffer:` | `tests/functions/gfx/gpu_buffer_test.aipl` |
| `31` | `std/gfx/gpu_buffer.aipl` | `advanceStagingRing` | `pub fn advanceStagingRing(ring: StagingRingBuffer): StagingRingBuffer:` | `tests/functions/gfx/gpu_buffer_test.aipl` |
| `32` | `std/gfx/gpu_command.aipl` | `createCommandEncoder` | `pub fn createCommandEncoder(): CommandEncoder:` | `tests/functions/gfx/gpu_command_test.aipl` |
| `33` | `std/gfx/gpu_command.aipl` | `recordDraw` | `pub fn recordDraw(encoder: CommandEncoder, pipeline: RenderPipelineState, vertexCount: int, instanceCount: int = 1): CommandEncoder:` | `tests/functions/gfx/gpu_command_test.aipl` |
| `34` | `std/gfx/gpu_command.aipl` | `finishCommandBuffer` | `pub fn finishCommandBuffer(encoder: CommandEncoder): CommandBuffer:` | `tests/functions/gfx/gpu_command_test.aipl` |
| `35` | `std/gfx/gpu_command.aipl` | `submitCommandBuffer` | `pub fn submitCommandBuffer(dev: GpuDevice, cmd: CommandBuffer): int:` | `tests/functions/gfx/gpu_command_test.aipl` |
| `36` | `std/gfx/gpu_device.aipl` | `getStandardGpuLimits` | `pub fn getStandardGpuLimits(): GpuDeviceLimits:` | `tests/functions/gfx/gpu_device_test.aipl` |
| `37` | `std/gfx/gpu_device.aipl` | `createGpuDevice` | `pub fn createGpuDevice(backendPreference: int = 0): GpuDevice:` | `tests/functions/gfx/gpu_device_test.aipl` |
| `38` | `std/gfx/gpu_device.aipl` | `isDeviceLost` | `pub fn isDeviceLost(dev: GpuDevice): bool:` | `tests/functions/gfx/gpu_device_test.aipl` |
| `39` | `std/gfx/gpu_device.aipl` | `destroyGpuDevice` | `pub fn destroyGpuDevice(dev: GpuDevice): GpuDevice:` | `tests/functions/gfx/gpu_device_test.aipl` |
| `40` | `std/gfx/gpu_pipeline.aipl` | `blendModeAlpha` | `pub fn blendModeAlpha(): BlendMode:` | `tests/functions/gfx/gpu_pipeline_test.aipl` |
| `41` | `std/gfx/gpu_pipeline.aipl` | `blendModeAdditive` | `pub fn blendModeAdditive(): BlendMode:` | `tests/functions/gfx/gpu_pipeline_test.aipl` |
| `42` | `std/gfx/gpu_pipeline.aipl` | `blendModeOpaque` | `pub fn blendModeOpaque(): BlendMode:` | `tests/functions/gfx/gpu_pipeline_test.aipl` |
| `43` | `std/gfx/gpu_pipeline.aipl` | `createRenderPipeline` | `pub fn createRenderPipeline(dev: GpuDevice, shader: ShaderModule, layout: VertexLayout, blend: BlendMode, depth: DepthStencilState): RenderPipelineState:` | `tests/functions/gfx/gpu_pipeline_test.aipl` |
| `44` | `std/gfx/gpu_shader.aipl` | `reflectUniformBlock` | `pub fn reflectUniformBlock(wgslSource: str): [ShaderUniformBinding]:` | `tests/functions/gfx/gpu_shader_test.aipl` |
| `45` | `std/gfx/gpu_shader.aipl` | `compileShaderModule` | `pub fn compileShaderModule(dev: GpuDevice, stage: int, source: str, entryPoint: str = "main"): ShaderModule:` | `tests/functions/gfx/gpu_shader_test.aipl` |
| `46` | `std/gfx/gpu_texture.aipl` | `createTexture2D` | `pub fn createTexture2D(dev: GpuDevice, w: int, h: int, fmt: TextureFormat, mipLevels: int = 1): GpuTexture:` | `tests/functions/gfx/gpu_texture_test.aipl` |
| `47` | `std/gfx/gpu_texture.aipl` | `computeMaxMipLevels` | `pub fn computeMaxMipLevels(w: int, h: int): int:` | `tests/functions/gfx/gpu_texture_test.aipl` |
| `48` | `std/gfx/gpu_texture.aipl` | `computeMipDimension` | `pub fn computeMipDimension(baseDim: int, mipLevel: int): int:` | `tests/functions/gfx/gpu_texture_test.aipl` |
| `49` | `std/gfx/gpu_texture.aipl` | `createLinearSampler` | `pub fn createLinearSampler(): SamplerState:` | `tests/functions/gfx/gpu_texture_test.aipl` |
| `50` | `std/gfx/gpu_texture.aipl` | `createAnisotropicSampler` | `pub fn createAnisotropicSampler(maxAniso: int = 16): SamplerState:` | `tests/functions/gfx/gpu_texture_test.aipl` |
| `51` | `std/gfx/postfx_pass.aipl` | `createDefaultPostFxChain` | `pub fn createDefaultPostFxChain(): PostFxChain:` | `tests/functions/gfx/postfx_pass_test.aipl` |
| `52` | `std/gfx/postfx_pass.aipl` | `acesChannel` | `fn acesChannel(x: float): float:` | `tests/functions/gfx/postfx_pass_test.aipl` |
| `53` | `std/gfx/postfx_pass.aipl` | `evaluateAcesTonemap` | `pub fn evaluateAcesTonemap(linearColor: LinearColorF32, exposure: float): LinearColorF32:` | `tests/functions/gfx/postfx_pass_test.aipl` |
| `54` | `std/gfx/postfx_pass.aipl` | `computeBloomThreshold` | `pub fn computeBloomThreshold(color: LinearColorF32, threshold: float, knee: float): LinearColorF32:` | `tests/functions/gfx/postfx_pass_test.aipl` |
| `55` | `std/gfx/postfx_pass.aipl` | `evaluateVignette` | `pub fn evaluateVignette(uvX: float, uvY: float, radius: float, softness: float): float:` | `tests/functions/gfx/postfx_pass_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `clampByte8` (`std/gfx/color.aipl`)

- **Signature**: `fn clampByte8(v: int): int:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `clampByte8` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `v: int = 1`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.gfx.color_z1_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_clampByte8_1(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = clampByte8(arg_v)
  let resEdge = clampByte8(edge_v)
  assertEqInt(resNom, 2, "clampByte8 nominal resNom == 2")
  assertEqInt(resEdge, 0, "clampByte8 boundary resEdge == 0")
  ret 0
```

---

### `clampUnit01` (`std/gfx/color.aipl`)

- **Signature**: `fn clampUnit01(v: float): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `clampUnit01` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.gfx.color_z2_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_clampUnit01_2(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = clampUnit01(arg_v)
  let resEdge = clampUnit01(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "clampUnit01 nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "clampUnit01 boundary resEdge ~= 0.5")
  ret 0
```

---

### `rgba8` (`std/gfx/color.aipl`)

- **Signature**: `pub fn rgba8(r: int, g: int, b: int, a: int = 255): ColorRgba8:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: int, g: int, b: int, a: int = 255` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `rgba8` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `r: int = 1`, `g: int = 1`, `b: int = 1`, `a: int = 1`; exercises core body path returning/computing `ColorRgba8(`.

```aipl
module tests.functions.gfx.color_z3_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_rgba8_3(): int:
  let arg_r = 2
  let edge_r = 0
  let arg_g = 2
  let edge_g = 0
  let arg_b = 4
  let edge_b = 1
  let arg_a = 2
  let edge_a = 0
  let resNom = rgba8(arg_r, arg_g, arg_b, arg_a)
  let resEdge = rgba8(edge_r, edge_g, edge_b, edge_a)
  assertEqInt(resNom.r, 2, "rgba8 nominal resNom.r == 2")
  assertEqInt(resEdge.r, 0, "rgba8 boundary resEdge.r == 0")
  ret 0
```

---

### `linearRgb` (`std/gfx/color.aipl`)

- **Signature**: `pub fn linearRgb(r: float, g: float, b: float, a: float = 1.0): LinearColorF32:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `r: float, g: float, b: float, a: float = 1.0` | **Returns**: `LinearColorF32`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `linearRgb` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `r: float = 1.0`, `g: float = 1.0`, `b: float = 1.0`, `a: float = 1.0`; exercises core body path returning/computing `LinearColorF32(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.gfx.color_z4_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_linearRgb_4(): int:
  let arg_r = 1.0
  let edge_r = 0.5
  let arg_g = 1.0
  let edge_g = 0.5
  let arg_b = 1.0
  let edge_b = 0.5
  let arg_a = 1.0
  let edge_a = 0.5
  let resNom = linearRgb(arg_r, arg_g, arg_b, arg_a)
  let resEdge = linearRgb(edge_r, edge_g, edge_b, edge_a)
  assertApproxEq(resNom.r, 1.0, 0.001, "linearRgb nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "linearRgb boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `srgbChanToLinear` (`std/gfx/color.aipl`)

- **Signature**: `fn srgbChanToLinear(c: float): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `srgbChanToLinear` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: float = 1.0`; exercises core body path returning/computing `pow((c + 0.055) / 1.055, 2.4)`.

```aipl
module tests.functions.gfx.color_z5_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_srgbChanToLinear_5(): int:
  let arg_c = 1.0
  let edge_c = 0.5
  let resNom = srgbChanToLinear(arg_c)
  let resEdge = srgbChanToLinear(edge_c)
  assertApproxEq(resNom, 1.0, 0.001, "srgbChanToLinear nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.214041, 0.001, "srgbChanToLinear boundary resEdge ~= 0.214041")
  ret 0
```

---

### `linearChanToSrgb` (`std/gfx/color.aipl`)

- **Signature**: `fn linearChanToSrgb(c: float): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `linearChanToSrgb` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: float = 1.0`; exercises core body path returning/computing `1.055 * pow(u, 1.0 / 2.4) - 0.055`.

```aipl
module tests.functions.gfx.color_z6_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_linearChanToSrgb_6(): int:
  let arg_c = 1.0
  let edge_c = 0.5
  let resNom = linearChanToSrgb(arg_c)
  let resEdge = linearChanToSrgb(edge_c)
  assertApproxEq(resNom, 1.0, 0.001, "linearChanToSrgb nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.735357, 0.001, "linearChanToSrgb boundary resEdge ~= 0.735357")
  ret 0
```

---

### `srgbToLinear` (`std/gfx/color.aipl`)

- **Signature**: `pub fn srgbToLinear(c: ColorRgba8): LinearColorF32:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `LinearColorF32`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `srgbToLinear` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `LinearColorF32(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.gfx.color_z7_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_srgbToLinear_7(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = srgbToLinear(arg_c)
  let resEdge = srgbToLinear(edge_c)
  assertApproxEq(resNom.r, 0.000607, 0.001, "srgbToLinear nominal resNom.r ~= 0.000607")
  assertApproxEq(resEdge.r, 0.0, 0.001, "srgbToLinear boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `linearToSrgb` (`std/gfx/color.aipl`)

- **Signature**: `pub fn linearToSrgb(c: LinearColorF32): ColorRgba8:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: LinearColorF32` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `linearToSrgb` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`; exercises core body path returning/computing `ColorRgba8(r = r, g = g, b = b, a = a)`.

```aipl
module tests.functions.gfx.color_z8_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_linearToSrgb_8(): int:
  let arg_c = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_c = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = linearToSrgb(arg_c)
  let resEdge = linearToSrgb(edge_c)
  assertEqInt(resNom.r, 255, "linearToSrgb nominal resNom.r == 255")
  assertEqInt(resEdge.r, 188, "linearToSrgb boundary resEdge.r == 188")
  ret 0
```

---

### `cbrtPos` (`std/gfx/color.aipl`)

- **Signature**: `fn cbrtPos(x: float): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `cbrtPos` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `pow(x, 1.0 / 3.0)`.

```aipl
module tests.functions.gfx.color_z9_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_cbrtPos_9(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = cbrtPos(arg_x)
  let resEdge = cbrtPos(edge_x)
  assertApproxEq(resNom, 1.0, 0.001, "cbrtPos nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.793701, 0.001, "cbrtPos boundary resEdge ~= 0.793701")
  ret 0
```

---

### `rgba8ToOklab` (`std/gfx/color.aipl`)

- **Signature**: `pub fn rgba8ToOklab(c: ColorRgba8): ColorOklab:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `ColorOklab`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `rgba8ToOklab` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `ColorOklab(l = L, a = A, b = B, alpha = lin.a)`.

```aipl
module tests.functions.gfx.color_z10_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_rgba8ToOklab_10(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = rgba8ToOklab(arg_c)
  let resEdge = rgba8ToOklab(edge_c)
  assertApproxEq(resNom.l, 0.087236, 0.001, "rgba8ToOklab nominal resNom.l ~= 0.087236")
  assertApproxEq(resEdge.l, 0.030377, 0.001, "rgba8ToOklab boundary resEdge.l ~= 0.030377")
  ret 0
```

---

### `oklabToRgba8` (`std/gfx/color.aipl`)

- **Signature**: `pub fn oklabToRgba8(lab: ColorOklab): ColorRgba8:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lab: ColorOklab` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `oklabToRgba8` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `lab: ColorOklab = ColorOklab(l = 1.0, a = 1.0, b = 1.0, alpha = float = 1.0())`; exercises core body path returning/computing `linearToSrgb(LinearColorF32(r = rLin, g = gLin, b = bLin, a = lab.alpha))`.

```aipl
module tests.functions.gfx.color_z11_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_oklabToRgba8_11(): int:
  let arg_lab = ColorOklab(l = 1.0, a = 1.0, b = 1.0, alpha = 2.0)
  let edge_lab = ColorOklab(l = 0.5, a = 0.5, b = 0.5, alpha = 1.0)
  let resNom = oklabToRgba8(arg_lab)
  let resEdge = oklabToRgba8(edge_lab)
  assertEqInt(resNom.r, 255, "oklabToRgba8 nominal resNom.r == 255")
  assertEqInt(resEdge.r, 255, "oklabToRgba8 boundary resEdge.r == 255")
  ret 0
```

---

### `oklabToOklch` (`std/gfx/color.aipl`)

- **Signature**: `pub fn oklabToOklch(lab: ColorOklab): ColorOklch:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lab: ColorOklab` | **Returns**: `ColorOklch`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `oklabToOklch` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `lab: ColorOklab = ColorOklab(l = 1.0, a = 1.0, b = 1.0, alpha = float = 1.0())`; exercises core body path returning/computing `ColorOklch(l = lab.l, c = ch, h = deg, alpha = lab.alpha)`.

```aipl
module tests.functions.gfx.color_z12_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_oklabToOklch_12(): int:
  let arg_lab = ColorOklab(l = 1.0, a = 1.0, b = 1.0, alpha = 2.0)
  let edge_lab = ColorOklab(l = 0.5, a = 0.5, b = 0.5, alpha = 1.0)
  let resNom = oklabToOklch(arg_lab)
  let resEdge = oklabToOklch(edge_lab)
  assertApproxEq(resNom.l, 1.0, 0.001, "oklabToOklch nominal resNom.l ~= 1.0")
  assertApproxEq(resEdge.l, 0.5, 0.001, "oklabToOklch boundary resEdge.l ~= 0.5")
  ret 0
```

---

### `oklchToOklab` (`std/gfx/color.aipl`)

- **Signature**: `pub fn oklchToOklab(lch: ColorOklch): ColorOklab:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lch: ColorOklch` | **Returns**: `ColorOklab`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `oklchToOklab` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `lch: ColorOklch = ColorOklch(l = 1.0, c = 1.0, h = 1.0, alpha = float = 1.0())`; exercises core body path returning/computing `ColorOklab(`.

```aipl
module tests.functions.gfx.color_z13_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_oklchToOklab_13(): int:
  let arg_lch = ColorOklch(l = 1.0, c = 1.0, h = 2.0, alpha = 2.0)
  let edge_lch = ColorOklch(l = 0.5, c = 0.5, h = 1.0, alpha = 1.0)
  let resNom = oklchToOklab(arg_lch)
  let resEdge = oklchToOklab(edge_lch)
  assertApproxEq(resNom.l, 1.0, 0.001, "oklchToOklab nominal resNom.l ~= 1.0")
  assertApproxEq(resEdge.l, 0.5, 0.001, "oklchToOklab boundary resEdge.l ~= 0.5")
  ret 0
```

---

### `lerpOklab` (`std/gfx/color.aipl`)

- **Signature**: `pub fn lerpOklab(c1: ColorRgba8, c2: ColorRgba8, t: float): ColorRgba8:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c1: ColorRgba8, c2: ColorRgba8, t: float` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `lerpOklab` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c1: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `c2: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `t: float = 0.5`; exercises core body path returning/computing `oklabToRgba8(mid)`.

```aipl
module tests.functions.gfx.color_z14_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_lerpOklab_14(): int:
  let arg_c1 = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c1 = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_c2 = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c2 = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = lerpOklab(arg_c1, arg_c2, arg_t)
  let resEdge = lerpOklab(edge_c1, edge_c2, edge_t)
  assertEqInt(resNom.r, 2, "lerpOklab nominal resNom.r == 2")
  assertEqInt(resEdge.r, 0, "lerpOklab boundary resEdge.r == 0")
  ret 0
```

---

### `wcagRelativeLuminance` (`std/gfx/color.aipl`)

- **Signature**: `pub fn wcagRelativeLuminance(c: ColorRgba8): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `wcagRelativeLuminance` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `0.2126 * lin.r + 0.7152 * lin.g + 0.0722 * lin.b`.

```aipl
module tests.functions.gfx.color_z15_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_wcagRelativeLuminance_15(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = wcagRelativeLuminance(arg_c)
  let resEdge = wcagRelativeLuminance(edge_c)
  assertApproxEq(resNom, 0.000651, 0.001, "wcagRelativeLuminance nominal resNom ~= 0.000651")
  assertApproxEq(resEdge, 0.000022, 0.001, "wcagRelativeLuminance boundary resEdge ~= 0.000022")
  ret 0
```

---

### `wcagContrastRatio` (`std/gfx/color.aipl`)

- **Signature**: `pub fn wcagContrastRatio(fg: ColorRgba8, bg: ColorRgba8): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fg: ColorRgba8, bg: ColorRgba8` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `wcagContrastRatio` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `fg: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `bg: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `(lighter + 0.05) / (darker + 0.05)`.

```aipl
module tests.functions.gfx.color_z16_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_wcagContrastRatio_16(): int:
  let arg_fg = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_fg = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_bg = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_bg = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = wcagContrastRatio(arg_fg, arg_bg)
  let resEdge = wcagContrastRatio(edge_fg, edge_bg)
  assertApproxEq(resNom, 1.0, 0.001, "wcagContrastRatio nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "wcagContrastRatio boundary resEdge ~= 1.0")
  ret 0
```

---

### `apcaLuminance` (`std/gfx/color.aipl`)

- **Signature**: `fn apcaLuminance(c: ColorRgba8): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `apcaLuminance` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `y`.

```aipl
module tests.functions.gfx.color_z17_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_apcaLuminance_17(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = apcaLuminance(arg_c)
  let resEdge = apcaLuminance(edge_c)
  assertApproxEq(resNom, 0.004539, 0.001, "apcaLuminance nominal resNom ~= 0.004539")
  assertApproxEq(resEdge, 0.004531, 0.001, "apcaLuminance boundary resEdge ~= 0.004531")
  ret 0
```

---

### `apcaContrast` (`std/gfx/color.aipl`)

- **Signature**: `pub fn apcaContrast(text: ColorRgba8, bg: ColorRgba8): float:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `text: ColorRgba8, bg: ColorRgba8` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `apcaContrast` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `text: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`, `bg: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `(sapc + 0.027) * 100.0`.

```aipl
module tests.functions.gfx.color_z18_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_apcaContrast_18(): int:
  let arg_text = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_text = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let arg_bg = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_bg = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = apcaContrast(arg_text, arg_bg)
  let resEdge = apcaContrast(edge_text, edge_bg)
  assertApproxEq(resNom, 0.0, 0.001, "apcaContrast nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "apcaContrast boundary resEdge ~= 0.0")
  ret 0
```

---

### `hexNibble` (`std/gfx/color.aipl`)

- **Signature**: `fn hexNibble(code: int): int:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `code: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `hexNibble` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `code: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.gfx.color_z19_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_hexNibble_19(): int:
  let arg_code = 2
  let edge_code = 0
  let resNom = hexNibble(arg_code)
  let resEdge = hexNibble(edge_code)
  assertEqInt(resNom, 0, "hexNibble nominal resNom == 0")
  assertEqInt(resEdge, 0, "hexNibble boundary resEdge == 0")
  ret 0
```

---

### `hexByteAt` (`std/gfx/color.aipl`)

- **Signature**: `fn hexByteAt(s: str, pos: int): int:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, pos: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `hexByteAt` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `s: str = "aipl_test"`, `pos: int = 0`; exercises core body path returning/computing `(hexNibble(s.charCodeAt(pos)) << 4) | hexNibble(s.charCodeAt(pos + 1))`.

```aipl
module tests.functions.gfx.color_z20_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_hexByteAt_20(): int:
  let arg_s = "4142"
  let edge_s = "00"
  let arg_pos = 1
  let edge_pos = 0
  let resNom = hexByteAt(arg_s, arg_pos)
  let resEdge = hexByteAt(edge_s, edge_pos)
  assertEqInt(resNom, 20, "hexByteAt nominal resNom == 20")
  assertEqInt(resEdge, 0, "hexByteAt boundary resEdge == 0")
  ret 0
```

---

### `parseHexColor` (`std/gfx/color.aipl`)

- **Signature**: `pub fn parseHexColor(hexStr: str): ColorRgba8:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hexStr: str` | **Returns**: `ColorRgba8`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `parseHexColor` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `hexStr: str = "aipl_test"`; exercises core body path returning/computing `ColorRgba8(r = 0, g = 0, b = 0, a = 255)`.

```aipl
module tests.functions.gfx.color_z21_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_parseHexColor_21(): int:
  let arg_hexStr = "4142"
  let edge_hexStr = "00"
  let resNom = parseHexColor(arg_hexStr)
  let resEdge = parseHexColor(edge_hexStr)
  assertEqInt(resNom.r, 68, "parseHexColor nominal resNom.r == 68")
  assertEqInt(resEdge.r, 0, "parseHexColor boundary resEdge.r == 0")
  ret 0
```

---

### `byteToHexUpper` (`std/gfx/color.aipl`)

- **Signature**: `fn byteToHexUpper(v: int): str:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `byteToHexUpper` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `v: int = 1`; exercises core body path returning/computing `digits.slice(hi, hi + 1) + digits.slice(lo, lo + 1)`.

```aipl
module tests.functions.gfx.color_z22_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_byteToHexUpper_22(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = byteToHexUpper(arg_v)
  let resEdge = byteToHexUpper(edge_v)
  assertEqStr(resNom, "02", "byteToHexUpper nominal string matches")
  assertEqStr(resEdge, "00", "byteToHexUpper boundary string matches")
  ret 0
```

---

### `toHexColor` (`std/gfx/color.aipl`)

- **Signature**: `pub fn toHexColor(c: ColorRgba8): str:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `c: ColorRgba8` | **Returns**: `str`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `toHexColor` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `c: ColorRgba8 = ColorRgba8(r = 1, g = 1, b = 1, a = int = 255())`; exercises core body path returning/computing `"#" + byteToHexUpper(c.r) + byteToHexUpper(c.g) + byteToHexUpper(c.b) + byteToHexUpper(c.a)`.

```aipl
module tests.functions.gfx.color_z23_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_toHexColor_23(): int:
  let arg_c = ColorRgba8(r = 2, g = 2, b = 4, a = 2)
  let edge_c = ColorRgba8(r = 0, g = 0, b = 1, a = 0)
  let resNom = toHexColor(arg_c)
  let resEdge = toHexColor(edge_c)
  assertEqStr(resNom, "#02020402", "toHexColor nominal string matches")
  assertEqStr(resEdge, "#00000100", "toHexColor boundary string matches")
  ret 0
```

---

### `sampleColorLut3D` (`std/gfx/color.aipl`)

- **Signature**: `pub fn sampleColorLut3D(lut: ColorLut3D, inColor: LinearColorF32): LinearColorF32:`
- **Import**: `import * from "std/gfx/color"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `lut: ColorLut3D, inColor: LinearColorF32` | **Returns**: `LinearColorF32`
- **Unit Test**: `tests/functions/gfx/color_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `sampleColorLut3D` sRGB <-> Linear gamma 2.4 transfer, Oklab/Oklch perceptual round-trip, WCAG 2.1 contrast (`21.0` black/white), APCA polarity, or 3D LUT trilinear sampling. Concrete nominal inputs: `lut: ColorLut3D = ColorLut3D(size = 64, table = [LinearColorF32(r = 0, g = 0, b = 0, a = 0)])`, `inColor: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`; exercises core body path returning/computing `inColor`.

```aipl
module tests.functions.gfx.color_z24_test
import * from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_color_sampleColorLut3D_24(): int:
  let arg_lut = ColorLut3D(size = 0, table = [])
  let edge_lut = ColorLut3D(size = 0, table = [])
  let arg_inColor = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_inColor = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let resNom = sampleColorLut3D(arg_lut, arg_inColor)
  let resEdge = sampleColorLut3D(edge_lut, edge_inColor)
  assertApproxEq(resNom.r, 1.0, 0.001, "sampleColorLut3D nominal resNom.r ~= 1.0")
  assertApproxEq(resEdge.r, 0.5, 0.001, "sampleColorLut3D boundary resEdge.r ~= 0.5")
  ret 0
```

---

### `createFramebuffer` (`std/gfx/framebuffer.aipl`)

- **Signature**: `pub fn createFramebuffer(dev: GpuDevice, w: int, h: int, hasDepth: bool = true, samples: int = 1): Framebuffer:`
- **Import**: `import * from "std/gfx/framebuffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, w: int, h: int, hasDepth: bool = true, samples: int = 1` | **Returns**: `Framebuffer`
- **Unit Test**: `tests/functions/gfx/framebuffer_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `createFramebuffer` offscreen render-target color/depth attachment validation and resize state. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `w: int = 128`, `h: int = 128`, `hasDepth: bool = true`, `samples: int = 1`; exercises core body path returning/computing `Framebuffer(`.

```aipl
module tests.functions.gfx.framebuffer_z1_test
import * from "std/gfx/framebuffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { TextureFormat, GpuTexture, createTexture2D } from "std/gfx/gpu_texture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_framebuffer_createFramebuffer_1(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_hasDepth = true
  let edge_hasDepth = false
  let arg_samples = 4
  let edge_samples = 1
  let resNom = createFramebuffer(arg_dev, arg_w, arg_h, arg_hasDepth, arg_samples)
  let resEdge = createFramebuffer(edge_dev, edge_w, edge_h, edge_hasDepth, edge_samples)
  assertEqInt(resNom.width, 2, "createFramebuffer nominal resNom.width == 2")
  assertEqInt(resEdge.width, 0, "createFramebuffer boundary resEdge.width == 0")
  ret 0
```

---

### `resizeFramebuffer` (`std/gfx/framebuffer.aipl`)

- **Signature**: `pub fn resizeFramebuffer(dev: GpuDevice, fb: Framebuffer, newW: int, newH: int): Framebuffer:`
- **Import**: `import * from "std/gfx/framebuffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, fb: Framebuffer, newW: int, newH: int` | **Returns**: `Framebuffer`
- **Unit Test**: `tests/functions/gfx/framebuffer_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `resizeFramebuffer` offscreen render-target color/depth attachment validation and resize state. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `fb: Framebuffer = Framebuffer(width = 128, height = 128, colorAttachment = GpuTexture(textureId = 1, width = 128, height = 128, depth = 1, mipLevels = 1, format = TextureFormat(id = 0, bytesPerPixel = 0, hasAlpha = 0, isDepth = 0, isCompressed = 0), dimension = 1), depthAttachment = GpuTexture(textureId = 1, width = 128, height = 128, depth = 1, mipLevels = 1, format = TextureFormat(id = 0, bytesPerPixel = 0, hasAlpha = 0, isDepth = 0, isCompressed = 0), dimension = 1), sampleCount = 64)`, `newW: int = 1`, `newH: int = 1`; exercises core body path returning/computing `createFramebuffer(dev, newW, newH, hasDepth, fb.sampleCount)`.

```aipl
module tests.functions.gfx.framebuffer_z2_test
import * from "std/gfx/framebuffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { TextureFormat, GpuTexture, createTexture2D } from "std/gfx/gpu_texture"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_framebuffer_resizeFramebuffer_2(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_fb = Framebuffer(width = 4, height = 4, colorAttachment = GpuTexture(textureId = 1, width = 4, height = 4, depth = 0, mipLevels = 4, format = TextureFormat(id = 1, bytesPerPixel = 4, hasAlpha = true, isDepth = true, isCompressed = true), dimension = 4), depthAttachment = GpuTexture(textureId = 1, width = 4, height = 4, depth = 0, mipLevels = 4, format = TextureFormat(id = 1, bytesPerPixel = 4, hasAlpha = true, isDepth = true, isCompressed = true), dimension = 4), sampleCount = 4)
  let edge_fb = Framebuffer(width = 4, height = 4, colorAttachment = GpuTexture(textureId = 0, width = 4, height = 4, depth = 0, mipLevels = 1, format = TextureFormat(id = 0, bytesPerPixel = 1, hasAlpha = false, isDepth = false, isCompressed = false), dimension = 1), depthAttachment = GpuTexture(textureId = 0, width = 4, height = 4, depth = 0, mipLevels = 1, format = TextureFormat(id = 0, bytesPerPixel = 1, hasAlpha = false, isDepth = false, isCompressed = false), dimension = 1), sampleCount = 1)
  let arg_newW = 4
  let edge_newW = 1
  let arg_newH = 4
  let edge_newH = 1
  let resNom = resizeFramebuffer(arg_dev, arg_fb, arg_newW, arg_newH)
  let resEdge = resizeFramebuffer(edge_dev, edge_fb, edge_newW, edge_newH)
  assertEqInt(resNom.width, 4, "resizeFramebuffer nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "resizeFramebuffer boundary resEdge.width == 1")
  ret 0
```

---

### `createGpuBuffer` (`std/gfx/gpu_buffer.aipl`)

- **Signature**: `pub fn createGpuBuffer(dev: GpuDevice, sizeBytes: int, usage: int): GpuBuffer:`
- **Import**: `import * from "std/gfx/gpu_buffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, sizeBytes: int, usage: int` | **Returns**: `GpuBuffer`
- **Unit Test**: `tests/functions/gfx/gpu_buffer_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `createGpuBuffer` GPU buffer allocation, 16-byte `std140` alignment rounding, and dirty range upload tracking. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `sizeBytes: int = 64`, `usage: int = 1`; exercises core body path returning/computing `GpuBuffer(`.

```aipl
module tests.functions.gfx.gpu_buffer_z1_test
import * from "std/gfx/gpu_buffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_buffer_createGpuBuffer_1(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_sizeBytes = 4
  let edge_sizeBytes = 1
  let arg_usage = 2
  let edge_usage = 0
  let resNom = createGpuBuffer(arg_dev, arg_sizeBytes, arg_usage)
  let resEdge = createGpuBuffer(edge_dev, edge_sizeBytes, edge_usage)
  assertEqInt(resNom.bufferId, 1, "createGpuBuffer nominal resNom.bufferId == 1")
  assertEqInt(resEdge.bufferId, 0, "createGpuBuffer boundary resEdge.bufferId == 0")
  ret 0
```

---

### `writeGpuBuffer` (`std/gfx/gpu_buffer.aipl`)

- **Signature**: `pub fn writeGpuBuffer(dev: GpuDevice, buf: GpuBuffer, byteOffset: int, dataBytes: [int]): bool:`
- **Import**: `import * from "std/gfx/gpu_buffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, buf: GpuBuffer, byteOffset: int, dataBytes: [int]` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx/gpu_buffer_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `writeGpuBuffer` GPU buffer allocation, 16-byte `std140` alignment rounding, and dirty range upload tracking. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `buf: GpuBuffer = GpuBuffer(bufferId = 1, sizeBytes = 64, usageFlags = 1, isMapped = true)`, `byteOffset: int = 0`, `dataBytes: [int] = [64]`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.gfx.gpu_buffer_z2_test
import * from "std/gfx/gpu_buffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_buffer_writeGpuBuffer_2(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_buf = GpuBuffer(bufferId = 4, sizeBytes = 4, usageFlags = 1, isMapped = true)
  let edge_buf = GpuBuffer(bufferId = 1, sizeBytes = 1, usageFlags = 0, isMapped = false)
  let arg_byteOffset = 4
  let edge_byteOffset = 1
  let arg_dataBytes = [4]
  let edge_dataBytes = []
  let resNom = writeGpuBuffer(arg_dev, arg_buf, arg_byteOffset, arg_dataBytes)
  let resEdge = writeGpuBuffer(edge_dev, edge_buf, edge_byteOffset, edge_dataBytes)
  assert(resNom == false, "writeGpuBuffer nominal resNom == false")
  assert(resEdge == false, "writeGpuBuffer boundary resEdge == false")
  ret 0
```

---

### `alignOffsetStd140` (`std/gfx/gpu_buffer.aipl`)

- **Signature**: `pub fn alignOffsetStd140(currentOffset: int, baseAlignmentBytes: int): int:`
- **Import**: `import * from "std/gfx/gpu_buffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `currentOffset: int, baseAlignmentBytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/gpu_buffer_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `alignOffsetStd140` GPU buffer allocation, 16-byte `std140` alignment rounding, and dirty range upload tracking. Concrete nominal inputs: `currentOffset: int = 0`, `baseAlignmentBytes: int = 64`; exercises core body path returning/computing `(currentOffset + mask) & (~mask)`.

```aipl
module tests.functions.gfx.gpu_buffer_z3_test
import * from "std/gfx/gpu_buffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_buffer_alignOffsetStd140_3(): int:
  let arg_currentOffset = 4
  let edge_currentOffset = 1
  let arg_baseAlignmentBytes = 4
  let edge_baseAlignmentBytes = 1
  let resNom = alignOffsetStd140(arg_currentOffset, arg_baseAlignmentBytes)
  let resEdge = alignOffsetStd140(edge_currentOffset, edge_baseAlignmentBytes)
  assertEqInt(resNom, 4, "alignOffsetStd140 nominal resNom == 4")
  assertEqInt(resEdge, 1, "alignOffsetStd140 boundary resEdge == 1")
  ret 0
```

---

### `createStagingRingBuffer` (`std/gfx/gpu_buffer.aipl`)

- **Signature**: `pub fn createStagingRingBuffer(capacityBytes: int): StagingRingBuffer:`
- **Import**: `import * from "std/gfx/gpu_buffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacityBytes: int` | **Returns**: `StagingRingBuffer`
- **Unit Test**: `tests/functions/gfx/gpu_buffer_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `createStagingRingBuffer` GPU buffer allocation, 16-byte `std140` alignment rounding, and dirty range upload tracking. Concrete nominal inputs: `capacityBytes: int = 64`; exercises core body path returning/computing `StagingRingBuffer(`.

```aipl
module tests.functions.gfx.gpu_buffer_z4_test
import * from "std/gfx/gpu_buffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_buffer_createStagingRingBuffer_4(): int:
  let arg_capacityBytes = 4
  let edge_capacityBytes = 1
  let resNom = createStagingRingBuffer(arg_capacityBytes)
  let resEdge = createStagingRingBuffer(edge_capacityBytes)
  assertEqInt(resNom.capacityBytes, 4, "createStagingRingBuffer nominal resNom.capacityBytes == 4")
  assertEqInt(resEdge.capacityBytes, 1, "createStagingRingBuffer boundary resEdge.capacityBytes == 1")
  ret 0
```

---

### `advanceStagingRing` (`std/gfx/gpu_buffer.aipl`)

- **Signature**: `pub fn advanceStagingRing(ring: StagingRingBuffer): StagingRingBuffer:`
- **Import**: `import * from "std/gfx/gpu_buffer"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ring: StagingRingBuffer` | **Returns**: `StagingRingBuffer`
- **Unit Test**: `tests/functions/gfx/gpu_buffer_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `advanceStagingRing` GPU buffer allocation, 16-byte `std140` alignment rounding, and dirty range upload tracking. Concrete nominal inputs: `ring: StagingRingBuffer = StagingRingBuffer(capacityBytes = 64, writeSlot = 1, readSlot = 1, frameId = 1)`; exercises core body path returning/computing `StagingRingBuffer(`.

```aipl
module tests.functions.gfx.gpu_buffer_z5_test
import * from "std/gfx/gpu_buffer"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_buffer_advanceStagingRing_5(): int:
  let arg_ring = StagingRingBuffer(capacityBytes = 4, writeSlot = 1, readSlot = 1, frameId = 4)
  let edge_ring = StagingRingBuffer(capacityBytes = 1, writeSlot = 0, readSlot = 0, frameId = 1)
  let resNom = advanceStagingRing(arg_ring)
  let resEdge = advanceStagingRing(edge_ring)
  assertEqInt(resNom.capacityBytes, 4, "advanceStagingRing nominal resNom.capacityBytes == 4")
  assertEqInt(resEdge.capacityBytes, 1, "advanceStagingRing boundary resEdge.capacityBytes == 1")
  ret 0
```

---

### `createCommandEncoder` (`std/gfx/gpu_command.aipl`)

- **Signature**: `pub fn createCommandEncoder(): CommandEncoder:`
- **Import**: `import * from "std/gfx/gpu_command"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `CommandEncoder`
- **Unit Test**: `tests/functions/gfx/gpu_command_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `createCommandEncoder` command encoder draw/compute dispatch recording and state-sorted submission. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `CommandEncoder(commandQueue = q, isEnded = false)`.

```aipl
module tests.functions.gfx.gpu_command_z1_test
import * from "std/gfx/gpu_command"
import { GpuDevice } from "std/gfx/gpu_device"
import { GpuTexture } from "std/gfx/gpu_texture"
import { RenderPipelineState } from "std/gfx/gpu_pipeline"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_command_createCommandEncoder_1(): int:
  let resNom = createCommandEncoder()
  let resEdge = createCommandEncoder()
  assertEqInt(resNom.commandQueue.len(), 0, "createCommandEncoder nominal resNom.commandQueue.len() == 0")
  assertEqInt(resEdge.commandQueue.len(), 0, "createCommandEncoder boundary resEdge.commandQueue.len() == 0")
  ret 0
```

---

### `recordDraw` (`std/gfx/gpu_command.aipl`)

- **Signature**: `pub fn recordDraw(encoder: CommandEncoder, pipeline: RenderPipelineState, vertexCount: int, instanceCount: int = 1): CommandEncoder:`
- **Import**: `import * from "std/gfx/gpu_command"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `encoder: CommandEncoder, pipeline: RenderPipelineState, vertexCount: int, instanceCount: int = 1` | **Returns**: `CommandEncoder`
- **Unit Test**: `tests/functions/gfx/gpu_command_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `recordDraw` command encoder draw/compute dispatch recording and state-sorted submission. Concrete nominal inputs: `encoder: CommandEncoder = CommandEncoder(commandQueue = [DrawCommand(pipelineId = 0, vertexCount = 0, instanceCount = 0, firstVertex = 0, firstInstance = 0)], isEnded = true)`, `pipeline: RenderPipelineState = RenderPipelineState(pipelineId = 1, shader = ShaderModule(shaderId = 1, stage = 1, entryPoint = "aipl_test", wgslSource = "aipl_test", uniformBindings = [0]), blend = BlendMode(enabled = true, srcColor = 1, dstColor = 1, opColor = 1, srcAlpha = 1, dstAlpha = 1, opAlpha = 1), depth = DepthStencilState(depthTest = true, depthWrite = true, depthCompareOp = 1), vertexLayout = VertexLayout(strideBytes = 64, attributes = [0]))`, `vertexCount: int = 64`, `instanceCount: int = 64`; exercises core body path returning/computing `CommandEncoder(commandQueue = nextQ, isEnded = false)`.

```aipl
module tests.functions.gfx.gpu_command_z2_test
import * from "std/gfx/gpu_command"
import { GpuDevice } from "std/gfx/gpu_device"
import { GpuTexture } from "std/gfx/gpu_texture"
import { RenderPipelineState } from "std/gfx/gpu_pipeline"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_command_recordDraw_2(): int:
  let arg_encoder = CommandEncoder(commandQueue = [], isEnded = true)
  let edge_encoder = CommandEncoder(commandQueue = [], isEnded = false)
  let arg_pipeline = RenderPipelineState(pipelineId = 4, shader = ShaderModule(shaderId = 1, stage = 2, entryPoint = "test", wgslSource = "test", uniformBindings = []), blend = BlendMode(enabled = true, srcColor = 1, dstColor = 1, opColor = 1, srcAlpha = 2, dstAlpha = 2, opAlpha = 2), depth = DepthStencilState(depthTest = true, depthWrite = true, depthCompareOp = 4), vertexLayout = VertexLayout(strideBytes = 4, attributes = []))
  let edge_pipeline = RenderPipelineState(pipelineId = 1, shader = ShaderModule(shaderId = 0, stage = 0, entryPoint = "a", wgslSource = "a", uniformBindings = []), blend = BlendMode(enabled = false, srcColor = 0, dstColor = 0, opColor = 0, srcAlpha = 0, dstAlpha = 0, opAlpha = 0), depth = DepthStencilState(depthTest = false, depthWrite = false, depthCompareOp = 1), vertexLayout = VertexLayout(strideBytes = 1, attributes = []))
  let arg_vertexCount = 4
  let edge_vertexCount = 1
  let arg_instanceCount = 4
  let edge_instanceCount = 1
  let resNom = recordDraw(arg_encoder, arg_pipeline, arg_vertexCount, arg_instanceCount)
  let resEdge = recordDraw(edge_encoder, edge_pipeline, edge_vertexCount, edge_instanceCount)
  assertEqInt(resNom.commandQueue.len(), 0, "recordDraw nominal resNom.commandQueue.len() == 0")
  assertEqInt(resEdge.commandQueue.len(), 1, "recordDraw boundary resEdge.commandQueue.len() == 1")
  ret 0
```

---

### `finishCommandBuffer` (`std/gfx/gpu_command.aipl`)

- **Signature**: `pub fn finishCommandBuffer(encoder: CommandEncoder): CommandBuffer:`
- **Import**: `import * from "std/gfx/gpu_command"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `encoder: CommandEncoder` | **Returns**: `CommandBuffer`
- **Unit Test**: `tests/functions/gfx/gpu_command_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `finishCommandBuffer` command encoder draw/compute dispatch recording and state-sorted submission. Concrete nominal inputs: `encoder: CommandEncoder = CommandEncoder(commandQueue = [DrawCommand(pipelineId = 0, vertexCount = 0, instanceCount = 0, firstVertex = 0, firstInstance = 0)], isEnded = true)`; exercises core body path returning/computing `CommandBuffer(bufferId = 1, commands = encoder.commandQueue)`.

```aipl
module tests.functions.gfx.gpu_command_z3_test
import * from "std/gfx/gpu_command"
import { GpuDevice } from "std/gfx/gpu_device"
import { GpuTexture } from "std/gfx/gpu_texture"
import { RenderPipelineState } from "std/gfx/gpu_pipeline"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_command_finishCommandBuffer_3(): int:
  let arg_encoder = CommandEncoder(commandQueue = [], isEnded = true)
  let edge_encoder = CommandEncoder(commandQueue = [], isEnded = false)
  let resNom = finishCommandBuffer(arg_encoder)
  let resEdge = finishCommandBuffer(edge_encoder)
  assertEqInt(resNom.bufferId, 1, "finishCommandBuffer nominal resNom.bufferId == 1")
  assertEqInt(resEdge.bufferId, 1, "finishCommandBuffer boundary resEdge.bufferId == 1")
  ret 0
```

---

### `submitCommandBuffer` (`std/gfx/gpu_command.aipl`)

- **Signature**: `pub fn submitCommandBuffer(dev: GpuDevice, cmd: CommandBuffer): int:`
- **Import**: `import * from "std/gfx/gpu_command"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, cmd: CommandBuffer` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/gpu_command_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `submitCommandBuffer` command encoder draw/compute dispatch recording and state-sorted submission. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `cmd: CommandBuffer = CommandBuffer(bufferId = 1, commands = [DrawCommand(pipelineId = 0, vertexCount = 0, instanceCount = 0, firstVertex = 0, firstInstance = 0)])`; exercises core body path returning/computing `cmd.commands.len + 1`.

```aipl
module tests.functions.gfx.gpu_command_z4_test
import * from "std/gfx/gpu_command"
import { GpuDevice } from "std/gfx/gpu_device"
import { GpuTexture } from "std/gfx/gpu_texture"
import { RenderPipelineState } from "std/gfx/gpu_pipeline"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_command_submitCommandBuffer_4(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_cmd = CommandBuffer(bufferId = 4, commands = [])
  let edge_cmd = CommandBuffer(bufferId = 1, commands = [])
  let resNom = submitCommandBuffer(arg_dev, arg_cmd)
  let resEdge = submitCommandBuffer(edge_dev, edge_cmd)
  assertEqInt(resNom, 1, "submitCommandBuffer nominal resNom == 1")
  assertEqInt(resEdge, 0, "submitCommandBuffer boundary resEdge == 0")
  ret 0
```

---

### `getStandardGpuLimits` (`std/gfx/gpu_device.aipl`)

- **Signature**: `pub fn getStandardGpuLimits(): GpuDeviceLimits:`
- **Import**: `import * from "std/gfx/gpu_device"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `GpuDeviceLimits`
- **Unit Test**: `tests/functions/gfx/gpu_device_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `getStandardGpuLimits` GPU adapter enumeration, discrete GPU preference scoring, and logical device limits. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `GpuDeviceLimits(`.

```aipl
module tests.functions.gfx.gpu_device_z1_test
import * from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_device_getStandardGpuLimits_1(): int:
  let resNom = getStandardGpuLimits()
  let resEdge = getStandardGpuLimits()
  assertEqInt(resNom.maxTextureDimension2D, 8192, "getStandardGpuLimits nominal resNom.maxTextureDimension2D == 8192")
  assertEqInt(resEdge.maxTextureDimension2D, 8192, "getStandardGpuLimits boundary resEdge.maxTextureDimension2D == 8192")
  ret 0
```

---

### `createGpuDevice` (`std/gfx/gpu_device.aipl`)

- **Signature**: `pub fn createGpuDevice(backendPreference: int = 0): GpuDevice:`
- **Import**: `import * from "std/gfx/gpu_device"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `backendPreference: int = 0` | **Returns**: `GpuDevice`
- **Unit Test**: `tests/functions/gfx/gpu_device_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `createGpuDevice` GPU adapter enumeration, discrete GPU preference scoring, and logical device limits. Concrete nominal inputs: `backendPreference: int = 1`; exercises core body path returning/computing `GpuDevice(`.

```aipl
module tests.functions.gfx.gpu_device_z2_test
import * from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_device_createGpuDevice_2(): int:
  let arg_backendPreference = 4
  let edge_backendPreference = 1
  let resNom = createGpuDevice(arg_backendPreference)
  let resEdge = createGpuDevice(edge_backendPreference)
  assertEqInt(resNom.deviceHandle, 1, "createGpuDevice nominal resNom.deviceHandle == 1")
  assertEqInt(resEdge.deviceHandle, 1, "createGpuDevice boundary resEdge.deviceHandle == 1")
  ret 0
```

---

### `isDeviceLost` (`std/gfx/gpu_device.aipl`)

- **Signature**: `pub fn isDeviceLost(dev: GpuDevice): bool:`
- **Import**: `import * from "std/gfx/gpu_device"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice` | **Returns**: `bool`
- **Unit Test**: `tests/functions/gfx/gpu_device_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `isDeviceLost` GPU adapter enumeration, discrete GPU preference scoring, and logical device limits. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`; exercises core body path returning/computing `not dev.isAlive or dev.deviceHandle <= 0`.

```aipl
module tests.functions.gfx.gpu_device_z3_test
import * from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_device_isDeviceLost_3(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let resNom = isDeviceLost(arg_dev)
  let resEdge = isDeviceLost(edge_dev)
  assert(resNom == false, "isDeviceLost nominal resNom == false")
  assert(resEdge == true, "isDeviceLost boundary resEdge == true")
  ret 0
```

---

### `destroyGpuDevice` (`std/gfx/gpu_device.aipl`)

- **Signature**: `pub fn destroyGpuDevice(dev: GpuDevice): GpuDevice:`
- **Import**: `import * from "std/gfx/gpu_device"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice` | **Returns**: `GpuDevice`
- **Unit Test**: `tests/functions/gfx/gpu_device_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `destroyGpuDevice` GPU adapter enumeration, discrete GPU preference scoring, and logical device limits. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`; exercises core body path returning/computing `GpuDevice(`.

```aipl
module tests.functions.gfx.gpu_device_z4_test
import * from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_device_destroyGpuDevice_4(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let resNom = destroyGpuDevice(arg_dev)
  let resEdge = destroyGpuDevice(edge_dev)
  assertEqInt(resNom.deviceHandle, 0, "destroyGpuDevice nominal resNom.deviceHandle == 0")
  assertEqInt(resEdge.deviceHandle, 0, "destroyGpuDevice boundary resEdge.deviceHandle == 0")
  ret 0
```

---

### `blendModeAlpha` (`std/gfx/gpu_pipeline.aipl`)

- **Signature**: `pub fn blendModeAlpha(): BlendMode:`
- **Import**: `import * from "std/gfx/gpu_pipeline"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BlendMode`
- **Unit Test**: `tests/functions/gfx/gpu_pipeline_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `blendModeAlpha` render/compute pipeline descriptor hashing, blend mode presets, and PSO cache hits. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BlendMode(`.

```aipl
module tests.functions.gfx.gpu_pipeline_z1_test
import * from "std/gfx/gpu_pipeline"
import { GpuDevice } from "std/gfx/gpu_device"
import { ShaderModule } from "std/gfx/gpu_shader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_pipeline_blendModeAlpha_1(): int:
  let resNom = blendModeAlpha()
  let resEdge = blendModeAlpha()
  assert(resNom.enabled == true, "blendModeAlpha nominal resNom.enabled == true")
  assert(resEdge.enabled == true, "blendModeAlpha boundary resEdge.enabled == true")
  ret 0
```

---

### `blendModeAdditive` (`std/gfx/gpu_pipeline.aipl`)

- **Signature**: `pub fn blendModeAdditive(): BlendMode:`
- **Import**: `import * from "std/gfx/gpu_pipeline"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BlendMode`
- **Unit Test**: `tests/functions/gfx/gpu_pipeline_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `blendModeAdditive` render/compute pipeline descriptor hashing, blend mode presets, and PSO cache hits. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BlendMode(`.

```aipl
module tests.functions.gfx.gpu_pipeline_z2_test
import * from "std/gfx/gpu_pipeline"
import { GpuDevice } from "std/gfx/gpu_device"
import { ShaderModule } from "std/gfx/gpu_shader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_pipeline_blendModeAdditive_2(): int:
  let resNom = blendModeAdditive()
  let resEdge = blendModeAdditive()
  assert(resNom.enabled == true, "blendModeAdditive nominal resNom.enabled == true")
  assert(resEdge.enabled == true, "blendModeAdditive boundary resEdge.enabled == true")
  ret 0
```

---

### `blendModeOpaque` (`std/gfx/gpu_pipeline.aipl`)

- **Signature**: `pub fn blendModeOpaque(): BlendMode:`
- **Import**: `import * from "std/gfx/gpu_pipeline"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `BlendMode`
- **Unit Test**: `tests/functions/gfx/gpu_pipeline_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `blendModeOpaque` render/compute pipeline descriptor hashing, blend mode presets, and PSO cache hits. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `BlendMode(`.

```aipl
module tests.functions.gfx.gpu_pipeline_z3_test
import * from "std/gfx/gpu_pipeline"
import { GpuDevice } from "std/gfx/gpu_device"
import { ShaderModule } from "std/gfx/gpu_shader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_pipeline_blendModeOpaque_3(): int:
  let resNom = blendModeOpaque()
  let resEdge = blendModeOpaque()
  assert(resNom.enabled == false, "blendModeOpaque nominal resNom.enabled == false")
  assert(resEdge.enabled == false, "blendModeOpaque boundary resEdge.enabled == false")
  ret 0
```

---

### `createRenderPipeline` (`std/gfx/gpu_pipeline.aipl`)

- **Signature**: `pub fn createRenderPipeline(dev: GpuDevice, shader: ShaderModule, layout: VertexLayout, blend: BlendMode, depth: DepthStencilState): RenderPipelineState:`
- **Import**: `import * from "std/gfx/gpu_pipeline"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, shader: ShaderModule, layout: VertexLayout, blend: BlendMode, depth: DepthStencilState` | **Returns**: `RenderPipelineState`
- **Unit Test**: `tests/functions/gfx/gpu_pipeline_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `createRenderPipeline` render/compute pipeline descriptor hashing, blend mode presets, and PSO cache hits. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `shader: ShaderModule = ShaderModule(shaderId = 1, stage = 1, entryPoint = "aipl_test", wgslSource = "aipl_test", uniformBindings = [ShaderUniformBinding(name = 0, bindingSlot = 0, groupSlot = 0, sizeBytes = 0, offsetBytes = 0)])`, `layout: VertexLayout = VertexLayout(strideBytes = 64, attributes = [VertexAttribute(location = 0, offsetBytes = 0, formatSize = 0)])`, `blend: BlendMode = BlendMode(enabled = true, srcColor = 1, dstColor = 1, opColor = 1, srcAlpha = 1, dstAlpha = 1, opAlpha = 1)`, `depth: DepthStencilState = DepthStencilState(depthTest = true, depthWrite = true, depthCompareOp = 1)`; exercises core body path returning/computing `RenderPipelineState(`.

```aipl
module tests.functions.gfx.gpu_pipeline_z4_test
import * from "std/gfx/gpu_pipeline"
import { GpuDevice } from "std/gfx/gpu_device"
import { ShaderModule } from "std/gfx/gpu_shader"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_pipeline_createRenderPipeline_4(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "127.0.0.1", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "127.0.0.1", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_shader = ShaderModule(shaderId = 1, stage = 2, entryPoint = "127.0.0.1", wgslSource = "127.0.0.1", uniformBindings = [])
  let edge_shader = ShaderModule(shaderId = 0, stage = 0, entryPoint = "127.0.0.1", wgslSource = "127.0.0.1", uniformBindings = [])
  let arg_layout = VertexLayout(strideBytes = 4, attributes = [])
  let edge_layout = VertexLayout(strideBytes = 1, attributes = [])
  let arg_blend = BlendMode(enabled = true, srcColor = 1, dstColor = 1, opColor = 1, srcAlpha = 2, dstAlpha = 2, opAlpha = 2)
  let edge_blend = BlendMode(enabled = false, srcColor = 0, dstColor = 0, opColor = 0, srcAlpha = 0, dstAlpha = 0, opAlpha = 0)
  let arg_depth = DepthStencilState(depthTest = true, depthWrite = true, depthCompareOp = 4)
  let edge_depth = DepthStencilState(depthTest = false, depthWrite = false, depthCompareOp = 1)
  let resNom = createRenderPipeline(arg_dev, arg_shader, arg_layout, arg_blend, arg_depth)
  let resEdge = createRenderPipeline(edge_dev, edge_shader, edge_layout, edge_blend, edge_depth)
  assertEqInt(resNom.pipelineId, 1, "createRenderPipeline nominal resNom.pipelineId == 1")
  assertEqInt(resEdge.pipelineId, 0, "createRenderPipeline boundary resEdge.pipelineId == 0")
  ret 0
```

---

### `reflectUniformBlock` (`std/gfx/gpu_shader.aipl`)

- **Signature**: `pub fn reflectUniformBlock(wgslSource: str): [ShaderUniformBinding]:`
- **Import**: `import * from "std/gfx/gpu_shader"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wgslSource: str` | **Returns**: `[ShaderUniformBinding]`
- **Unit Test**: `tests/functions/gfx/gpu_shader_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `reflectUniformBlock` WGSL/GLSL `@group/@binding` uniform block reflection and shader module compilation status. Concrete nominal inputs: `wgslSource: str = "aipl_test"`; exercises core body path returning/computing `bindings`.

```aipl
module tests.functions.gfx.gpu_shader_z1_test
import * from "std/gfx/gpu_shader"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_shader_reflectUniformBlock_1(): int:
  let arg_wgslSource = "test"
  let edge_wgslSource = "a"
  let resNom = reflectUniformBlock(arg_wgslSource)
  let resEdge = reflectUniformBlock(edge_wgslSource)
  assertEqInt(resNom.len(), 0, "reflectUniformBlock nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "reflectUniformBlock boundary resEdge.len() == 0")
  ret 0
```

---

### `compileShaderModule` (`std/gfx/gpu_shader.aipl`)

- **Signature**: `pub fn compileShaderModule(dev: GpuDevice, stage: int, source: str, entryPoint: str = "main"): ShaderModule:`
- **Import**: `import * from "std/gfx/gpu_shader"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, stage: int, source: str, entryPoint: str = "main"` | **Returns**: `ShaderModule`
- **Unit Test**: `tests/functions/gfx/gpu_shader_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `compileShaderModule` WGSL/GLSL `@group/@binding` uniform block reflection and shader module compilation status. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `stage: int = 1`, `source: str = "aipl_test"`, `entryPoint: str = "aipl_test"`; exercises core body path returning/computing `ShaderModule(`.

```aipl
module tests.functions.gfx.gpu_shader_z2_test
import * from "std/gfx/gpu_shader"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_shader_compileShaderModule_2(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_stage = 2
  let edge_stage = 0
  let arg_source = "test"
  let edge_source = "a"
  let arg_entryPoint = "test"
  let edge_entryPoint = "a"
  let resNom = compileShaderModule(arg_dev, arg_stage, arg_source, arg_entryPoint)
  let resEdge = compileShaderModule(edge_dev, edge_stage, edge_source, edge_entryPoint)
  assertEqInt(resNom.shaderId, 1, "compileShaderModule nominal resNom.shaderId == 1")
  assertEqInt(resEdge.shaderId, 0, "compileShaderModule boundary resEdge.shaderId == 0")
  ret 0
```

---

### `createTexture2D` (`std/gfx/gpu_texture.aipl`)

- **Signature**: `pub fn createTexture2D(dev: GpuDevice, w: int, h: int, fmt: TextureFormat, mipLevels: int = 1): GpuTexture:`
- **Import**: `import * from "std/gfx/gpu_texture"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dev: GpuDevice, w: int, h: int, fmt: TextureFormat, mipLevels: int = 1` | **Returns**: `GpuTexture`
- **Unit Test**: `tests/functions/gfx/gpu_texture_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `createTexture2D` texture descriptor creation, mip-chain level calculation (`computeMaxMipLevels`), and byte footprint. Concrete nominal inputs: `dev: GpuDevice = GpuDevice(adapter = GpuAdapterInfo(name = "aipl_test", vendorId = 1, deviceId = 1, backendType = 1, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 64, maxStorageBufferBindingSize = 64, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 64), deviceHandle = 1, isAlive = true)`, `w: int = 128`, `h: int = 128`, `fmt: TextureFormat = TextureFormat(id = 1, bytesPerPixel = 64, hasAlpha = true, isDepth = true, isCompressed = true)`, `mipLevels: int = 1`; exercises core body path returning/computing `GpuTexture(`.

```aipl
module tests.functions.gfx.gpu_texture_z1_test
import * from "std/gfx/gpu_texture"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_texture_createTexture2D_1(): int:
  let arg_dev = GpuDevice(adapter = GpuAdapterInfo(name = "test", vendorId = 4, deviceId = 1, backendType = 4, isSoftware = true), limits = GpuDeviceLimits(maxTextureDimension2D = 4, maxTextureDimension3D = 4, maxUniformBufferBindingSize = 4, maxStorageBufferBindingSize = 4, maxVertexBuffers = 4, maxComputeWorkgroupStorageSize = 4), deviceHandle = 4, isAlive = true)
  let edge_dev = GpuDevice(adapter = GpuAdapterInfo(name = "a", vendorId = 1, deviceId = 0, backendType = 1, isSoftware = false), limits = GpuDeviceLimits(maxTextureDimension2D = 1, maxTextureDimension3D = 1, maxUniformBufferBindingSize = 1, maxStorageBufferBindingSize = 1, maxVertexBuffers = 1, maxComputeWorkgroupStorageSize = 1), deviceHandle = 1, isAlive = false)
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let arg_fmt = TextureFormat(id = 1, bytesPerPixel = 4, hasAlpha = true, isDepth = true, isCompressed = true)
  let edge_fmt = TextureFormat(id = 0, bytesPerPixel = 1, hasAlpha = false, isDepth = false, isCompressed = false)
  let arg_mipLevels = 4
  let edge_mipLevels = 1
  let resNom = createTexture2D(arg_dev, arg_w, arg_h, arg_fmt, arg_mipLevels)
  let resEdge = createTexture2D(edge_dev, edge_w, edge_h, edge_fmt, edge_mipLevels)
  assertEqInt(resNom.textureId, 1, "createTexture2D nominal resNom.textureId == 1")
  assertEqInt(resEdge.textureId, 0, "createTexture2D boundary resEdge.textureId == 0")
  ret 0
```

---

### `computeMaxMipLevels` (`std/gfx/gpu_texture.aipl`)

- **Signature**: `pub fn computeMaxMipLevels(w: int, h: int): int:`
- **Import**: `import * from "std/gfx/gpu_texture"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `w: int, h: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/gpu_texture_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `computeMaxMipLevels` texture descriptor creation, mip-chain level calculation (`computeMaxMipLevels`), and byte footprint. Concrete nominal inputs: `w: int = 128`, `h: int = 128`; exercises core body path returning/computing `levels`.

```aipl
module tests.functions.gfx.gpu_texture_z2_test
import * from "std/gfx/gpu_texture"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_texture_computeMaxMipLevels_2(): int:
  let arg_w = 2
  let edge_w = 0
  let arg_h = 2
  let edge_h = 0
  let resNom = computeMaxMipLevels(arg_w, arg_h)
  let resEdge = computeMaxMipLevels(edge_w, edge_h)
  assertEqInt(resNom, 2, "computeMaxMipLevels nominal resNom == 2")
  assertEqInt(resEdge, 1, "computeMaxMipLevels boundary resEdge == 1")
  ret 0
```

---

### `computeMipDimension` (`std/gfx/gpu_texture.aipl`)

- **Signature**: `pub fn computeMipDimension(baseDim: int, mipLevel: int): int:`
- **Import**: `import * from "std/gfx/gpu_texture"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseDim: int, mipLevel: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/gfx/gpu_texture_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `computeMipDimension` texture descriptor creation, mip-chain level calculation (`computeMaxMipLevels`), and byte footprint. Concrete nominal inputs: `baseDim: int = 1`, `mipLevel: int = 1`; exercises core body path returning/computing `if shifted > 1: shifted else: 1`.

```aipl
module tests.functions.gfx.gpu_texture_z3_test
import * from "std/gfx/gpu_texture"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_texture_computeMipDimension_3(): int:
  let arg_baseDim = 4
  let edge_baseDim = 1
  let arg_mipLevel = 4
  let edge_mipLevel = 1
  let resNom = computeMipDimension(arg_baseDim, arg_mipLevel)
  let resEdge = computeMipDimension(edge_baseDim, edge_mipLevel)
  assertEqInt(resNom, 1, "computeMipDimension nominal resNom == 1")
  assertEqInt(resEdge, 1, "computeMipDimension boundary resEdge == 1")
  ret 0
```

---

### `createLinearSampler` (`std/gfx/gpu_texture.aipl`)

- **Signature**: `pub fn createLinearSampler(): SamplerState:`
- **Import**: `import * from "std/gfx/gpu_texture"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SamplerState`
- **Unit Test**: `tests/functions/gfx/gpu_texture_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `createLinearSampler` texture descriptor creation, mip-chain level calculation (`computeMaxMipLevels`), and byte footprint. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SamplerState(`.

```aipl
module tests.functions.gfx.gpu_texture_z4_test
import * from "std/gfx/gpu_texture"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_texture_createLinearSampler_4(): int:
  let resNom = createLinearSampler()
  let resEdge = createLinearSampler()
  assertEqInt(resNom.filterMin, 1, "createLinearSampler nominal resNom.filterMin == 1")
  assertEqInt(resEdge.filterMin, 1, "createLinearSampler boundary resEdge.filterMin == 1")
  ret 0
```

---

### `createAnisotropicSampler` (`std/gfx/gpu_texture.aipl`)

- **Signature**: `pub fn createAnisotropicSampler(maxAniso: int = 16): SamplerState:`
- **Import**: `import * from "std/gfx/gpu_texture"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxAniso: int = 16` | **Returns**: `SamplerState`
- **Unit Test**: `tests/functions/gfx/gpu_texture_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `createAnisotropicSampler` texture descriptor creation, mip-chain level calculation (`computeMaxMipLevels`), and byte footprint. Concrete nominal inputs: `maxAniso: int = 1`; exercises core body path returning/computing `SamplerState(`.

```aipl
module tests.functions.gfx.gpu_texture_z5_test
import * from "std/gfx/gpu_texture"
import { GpuDevice } from "std/gfx/gpu_device"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_gpu_texture_createAnisotropicSampler_5(): int:
  let arg_maxAniso = 4
  let edge_maxAniso = 1
  let resNom = createAnisotropicSampler(arg_maxAniso)
  let resEdge = createAnisotropicSampler(edge_maxAniso)
  assertEqInt(resNom.filterMin, 1, "createAnisotropicSampler nominal resNom.filterMin == 1")
  assertEqInt(resEdge.filterMin, 1, "createAnisotropicSampler boundary resEdge.filterMin == 1")
  ret 0
```

---

### `createDefaultPostFxChain` (`std/gfx/postfx_pass.aipl`)

- **Signature**: `pub fn createDefaultPostFxChain(): PostFxChain:`
- **Import**: `import * from "std/gfx/postfx_pass"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `PostFxChain`
- **Unit Test**: `tests/functions/gfx/postfx_pass_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `createDefaultPostFxChain` ACES Filmic/Reinhard tonemapping monotonicity, bloom knee extraction, vignette, and FXAA luma edge contrast. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `PostFxChain(bloom = bloom, tonemap = tonemap, vignette = vig, enabled = true)`.

```aipl
module tests.functions.gfx.postfx_pass_z1_test
import * from "std/gfx/postfx_pass"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_postfx_pass_createDefaultPostFxChain_1(): int:
  let resNom = createDefaultPostFxChain()
  let resEdge = createDefaultPostFxChain()
  assert(resNom.enabled == true, "createDefaultPostFxChain nominal resNom.enabled == true")
  assert(resEdge.enabled == true, "createDefaultPostFxChain boundary resEdge.enabled == true")
  ret 0
```

---

### `acesChannel` (`std/gfx/postfx_pass.aipl`)

- **Signature**: `fn acesChannel(x: float): float:`
- **Import**: `import * from "std/gfx/postfx_pass"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `x: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/postfx_pass_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `acesChannel` ACES Filmic/Reinhard tonemapping monotonicity, bloom knee extraction, vignette, and FXAA luma edge contrast. Concrete nominal inputs: `x: float = 1.0`; exercises core body path returning/computing `mapped`.

```aipl
module tests.functions.gfx.postfx_pass_z2_test
import * from "std/gfx/postfx_pass"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_postfx_pass_acesChannel_2(): int:
  let arg_x = 1.0
  let edge_x = 0.5
  let resNom = acesChannel(arg_x)
  let resEdge = acesChannel(edge_x)
  assertApproxEq(resNom, 0.803797, 0.001, "acesChannel nominal resNom ~= 0.803797")
  assertApproxEq(resEdge, 0.616307, 0.001, "acesChannel boundary resEdge ~= 0.616307")
  ret 0
```

---

### `evaluateAcesTonemap` (`std/gfx/postfx_pass.aipl`)

- **Signature**: `pub fn evaluateAcesTonemap(linearColor: LinearColorF32, exposure: float): LinearColorF32:`
- **Import**: `import * from "std/gfx/postfx_pass"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `linearColor: LinearColorF32, exposure: float` | **Returns**: `LinearColorF32`
- **Unit Test**: `tests/functions/gfx/postfx_pass_test.aipl` | **Example**: `examples/ex_155_gfx_framebuffer_software_rasterizer_window.aipl`
- **Behavioral Summary**: Verify `evaluateAcesTonemap` ACES Filmic/Reinhard tonemapping monotonicity, bloom knee extraction, vignette, and FXAA luma edge contrast. Concrete nominal inputs: `linearColor: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`, `exposure: float = 1.0`; exercises core body path returning/computing `LinearColorF32(`.

```aipl
module tests.functions.gfx.postfx_pass_z3_test
import * from "std/gfx/postfx_pass"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_postfx_pass_evaluateAcesTonemap_3(): int:
  let arg_linearColor = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_linearColor = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_exposure = 1.0
  let edge_exposure = 0.5
  let resNom = evaluateAcesTonemap(arg_linearColor, arg_exposure)
  let resEdge = evaluateAcesTonemap(edge_linearColor, edge_exposure)
  assertApproxEq(resNom.r, 0.803797, 0.001, "evaluateAcesTonemap nominal resNom.r ~= 0.803797")
  assertApproxEq(resEdge.r, 0.374111, 0.001, "evaluateAcesTonemap boundary resEdge.r ~= 0.374111")
  ret 0
```

---

### `computeBloomThreshold` (`std/gfx/postfx_pass.aipl`)

- **Signature**: `pub fn computeBloomThreshold(color: LinearColorF32, threshold: float, knee: float): LinearColorF32:`
- **Import**: `import * from "std/gfx/postfx_pass"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `color: LinearColorF32, threshold: float, knee: float` | **Returns**: `LinearColorF32`
- **Unit Test**: `tests/functions/gfx/postfx_pass_test.aipl` | **Example**: `examples/ex_156_gfx_gpu_device_and_swapchain_window.aipl`
- **Behavioral Summary**: Verify `computeBloomThreshold` ACES Filmic/Reinhard tonemapping monotonicity, bloom knee extraction, vignette, and FXAA luma edge contrast. Concrete nominal inputs: `color: LinearColorF32 = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = float = 1.0())`, `threshold: float = 1.0`, `knee: float = 1.0`; exercises core body path returning/computing `LinearColorF32(`.

```aipl
module tests.functions.gfx.postfx_pass_z4_test
import * from "std/gfx/postfx_pass"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_postfx_pass_computeBloomThreshold_4(): int:
  let arg_color = LinearColorF32(r = 1.0, g = 1.0, b = 1.0, a = 1.0)
  let edge_color = LinearColorF32(r = 0.5, g = 0.5, b = 0.5, a = 0.5)
  let arg_threshold = 2.0
  let edge_threshold = 1.0
  let arg_knee = 1.0
  let edge_knee = 0.5
  let resNom = computeBloomThreshold(arg_color, arg_threshold, arg_knee)
  let resEdge = computeBloomThreshold(edge_color, edge_threshold, edge_knee)
  assertApproxEq(resNom.r, 0.125, 0.001, "computeBloomThreshold nominal resNom.r ~= 0.125")
  assertApproxEq(resEdge.r, 0.0, 0.001, "computeBloomThreshold boundary resEdge.r ~= 0.0")
  ret 0
```

---

### `evaluateVignette` (`std/gfx/postfx_pass.aipl`)

- **Signature**: `pub fn evaluateVignette(uvX: float, uvY: float, radius: float, softness: float): float:`
- **Import**: `import * from "std/gfx/postfx_pass"` (or barrel `import * from "std/gfx/gfx_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `uvX: float, uvY: float, radius: float, softness: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/gfx/postfx_pass_test.aipl` | **Example**: `examples/ex_154_gfx_color_spaces_and_wcag_palette_window.aipl`
- **Behavioral Summary**: Verify `evaluateVignette` ACES Filmic/Reinhard tonemapping monotonicity, bloom knee extraction, vignette, and FXAA luma edge contrast. Concrete nominal inputs: `uvX: float = 1.0`, `uvY: float = 1.0`, `radius: float = 1.0`, `softness: float = 1.0`; exercises core body path returning/computing `t * t * (3.0 - 2.0 * t)`.

```aipl
module tests.functions.gfx.postfx_pass_z5_test
import * from "std/gfx/postfx_pass"
import { ColorRgba8, LinearColorF32 } from "std/gfx/color"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_postfx_pass_evaluateVignette_5(): int:
  let arg_uvX = 1.0
  let edge_uvX = 0.5
  let arg_uvY = 1.0
  let edge_uvY = 0.5
  let arg_radius = 2.0
  let edge_radius = 1.0
  let arg_softness = 1.0
  let edge_softness = 0.5
  let resNom = evaluateVignette(arg_uvX, arg_uvY, arg_radius, arg_softness)
  let resEdge = evaluateVignette(edge_uvX, edge_uvY, edge_radius, edge_softness)
  assertApproxEq(resNom, 1.0, 0.001, "evaluateVignette nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "evaluateVignette boundary resEdge ~= 1.0")
  ret 0
```
