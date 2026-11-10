# ADR-0034: Native Android NDK NativeActivity, ANativeWindow RGBA Blitter, AAudio & Touch Bridge

## Status
Accepted

## Date
2026-11-07

## Deciders
AIPL Architecture & Core Systems Team

## Context
Running AIPL applications on modern Android devices requires addressing several structural requirements:
1. **Zero Java/Kotlin JVM Dependency**: To ensure pure native compilation and avoid heavy JVM/ART runtime overhead or Gradle toolchain requirements, AIPL runs directly inside Android's native execution container via `ANativeActivity`.
2. **Hardware Direct Surface Blitting**: Rendering the AIPL software/GPU framebuffer efficiently on Android screens demands direct integration with `ANativeWindow` (`ANativeWindow_setBuffersGeometry` and `ANativeWindow_lock`/`unlockAndPost`) with scanline stride alignment.
3. **Low-Latency Audio Streaming**: Audio synthesis requires direct integration with Android's modern C `AAudio` API in `LOW_LATENCY` performance mode using double-buffered burst sizes to prevent audio glitches and underruns.
4. **Isolated Multi-Touch & Gesture Ergonomics**: Multi-touch mobile input requires translation from `AInputQueue` / `AMotionEvent` to pointer-isolated touch tracking (`TouchTracker`, `VirtualJoystick`, and `PinchGesture`) with robust anti-sticking gesture cancellation.
5. **Universal HTML5 WebView Delivery**: As an alternative to native binaries, single-file HTML5 bundles must adapt for mobile viewports using `viewport-fit=cover`, `touch-action:none`, and DOM touch/PointerEvent interception.

## Decision Drivers
- **Pure Native Execution**: Zero Java runtime glue code required; entry via standard `ANativeActivity_onCreate`.
- **ANativeWindow RGBA_8888 Surface**: 32-bit hardware framebuffer blitting with 16-pixel scanline stride alignment.
- **Low-Latency AAudio Stream**: AAudio low-latency shared PCM stream (`AAUDIO_PERFORMANCE_MODE_LOW_LATENCY = 12`).
- **Pointer-Isolated Touch Input**: `TouchTracker` with pointer ID isolation and anti-sticking cancel event recovery.
- **Cross-Compilation Toolchain Driver**: `--target android-arm64` cross-compiler emitting verified C99/shared libraries (`libaipl_app.so`).
- **Deterministic Host Fallback**: Seamless C99 verification fallback when the Android NDK toolchain is not present in CI.

## Considered Options
### Option 1: Full JNI + Java Activity Bridge
Implement a Java/Kotlin `Activity` that calls into AIPL via custom JNI wrappers.
- *Pros*: Standard Android UI toolkit integration.
- *Cons*: **Rejected**. Requires Android SDK, Gradle, and JVM runtime; breaks standalone native compilation and self-hosting simplicity.

### Option 2: SDL2 / Third-Party Native Wrapper
Link against SDL2 Android port as an intermediate runtime layer.
- *Pros*: Existing cross-platform abstractions.
- *Cons*: **Rejected**. Introduces large third-party runtime dependency, adds latency, and increases binary size.

### Option 3: Direct NativeActivity, ANativeWindow & AAudio Bridge
Direct pure-AIPL bindings and C runtime wrappers for `ANativeActivity`, `ANativeWindow`, `AAudio`, and `AInputQueue`.
- *Pros*: **Accepted**. Zero external dependencies beyond the NDK sysroot, optimal latency, lean binary footprint, and complete architectural consistency with AIPL's systems programming model.

## Decision Outcome & Rationale
**Chosen: Option 3 - Direct NativeActivity, ANativeWindow & AAudio Bridge.**

### Architectural Components
1. **Lifecycle State Machine (`std/sys/sys_android.aipl`)**:
   Tracks `APP_CMD_INIT_WINDOW`, `APP_CMD_TERM_WINDOW`, `APP_CMD_GAINED_FOCUS`, `APP_CMD_LOST_FOCUS`, and `APP_CMD_CONFIG_CHANGED`. Animation loops run strictly when `windowReady && hasFocus`.
2. **Surface Descriptor & Scanline Blitter (`runtime/rt_gui_audio.c`)**:
   Manages 32-bit RGBA buffers (`WINDOW_FORMAT_RGBA_8888`), hardware stride alignment, safe-area insets, and zero-allocation scanline copying.
3. **Multi-Touch & Virtual Controls (`runtime/rt_sys.c` + `std/input/`)**:
   Translates raw `AMotionEvent` actions into `TouchTracker`, `VirtualJoystick`, and `PinchGesture` with strict `pointerId` isolation and anti-sticking cancel handling.
4. **HTML5 WebView Bundle (`compiler/codegen_ts.aipl`)**:
   Emits `viewport-fit=cover`, disables browser zoom hijacking, and registers non-passive touch listeners.
5. **NDK Driver & Host Fallback (`compiler/codegen_c_or_ir.aipl`)**:
   Emits `aarch64-linux-android29-clang` command line with `-shared -fPIC -landroid -llog -laaudio -lm`, providing clean host verification fallback.

## Metadata & Contract Verification
The metadata contract for ADR-0034 is verified by:
- ADR Number: `34`
- Status: `"Accepted"`
- NDK Surface Coverage: `true`
- Touch Isolation Coverage: `true`
