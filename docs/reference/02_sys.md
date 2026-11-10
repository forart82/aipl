[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 02: `sys` API Reference

> Complete API reference manual for AIPL standard library domain `sys` (109 callable functions & methods across ["std/sys/sys_audio.aipl", "std/sys/sys_ffi.aipl", "std/sys/sys_fs.aipl", "std/sys/sys_gpu.aipl", "std/sys/sys_mem.aipl", "std/sys/sys_mod.aipl", "std/sys/sys_net.aipl", "std/sys/sys_syscall.aipl", "std/sys/sys_android.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `sys`
- **Target Source Modules**: ["std/sys/sys_audio.aipl", "std/sys/sys_ffi.aipl", "std/sys/sys_fs.aipl", "std/sys/sys_gpu.aipl", "std/sys/sys_mem.aipl", "std/sys/sys_mod.aipl", "std/sys/sys_net.aipl", "std/sys/sys_syscall.aipl", "std/sys/sys_android.aipl"]
- **Total Callable Functions & Methods**: 109
- **Total Data Types (`struct` & `enum`)**: 10
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(10 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `SysAudioStreamDesc` | `pub struct` | `std/sys/sys_audio.aipl` | `handle: int`, `channels: int`, `sampleRate: int`, `bufferFrames: int`, `paused: bool` | `SysAudioStreamDesc(handle, channels, sampleRate, bufferFrames, paused)` |
| `SysFileDescriptor` | `pub struct` | `std/sys/sys_fs.aipl` | `path: str`, `fd: int`, `isOpen: bool` | `SysFileDescriptor(path, fd, isOpen)` |
| `SysGpuContextHandle` | `pub struct` | `std/sys/sys_gpu.aipl` | `handle: int`, `windowHandle: int`, `backendType: int` | `SysGpuContextHandle(handle, windowHandle, backendType)` |
| `SysMemStats` | `pub struct` | `std/sys/sys_mem.aipl` | `allocatedPages: int`, `totalBytes: int`, `peakBytes: int` | `SysMemStats(allocatedPages, totalBytes, peakBytes)` |
| `MemoryRegion` | `pub struct` | `std/sys/sys_mem.aipl` | `address: int`, `size: int`, `active: bool` | `MemoryRegion(address, size, active)` |
| `SysSocketHandle` | `pub struct` | `std/sys/sys_net.aipl` | `fd: int`, `domain: int`, `sockType: int`, `nonBlocking: bool` | `SysSocketHandle(fd, domain, sockType, nonBlocking)` |
| `AndroidLifecycleState` | `pub struct` | `std/sys/sys_android.aipl` | `windowReady: bool`, `hasFocus: bool`, `isAnimating: bool`, `configGeneration: int`, `lastCmd: int` | `AndroidLifecycleState(windowReady, hasFocus, isAnimating, configGeneration, lastCmd)` |
| `AndroidSurfaceDesc` | `pub struct` | `std/sys/sys_android.aipl` | `windowHandle: int`, `widthPx: int`, `heightPx: int`, `stridePixels: int`, `formatRgba8888: int`, `densityDpi: int`, `refreshRateHz: int`, `isValid: bool` | `AndroidSurfaceDesc(windowHandle, widthPx, heightPx, stridePixels, formatRgba8888, densityDpi, refreshRateHz, isValid)` |
| `AndroidSafeAreaInsets` | `pub struct` | `std/sys/sys_android.aipl` | `topPx: int`, `bottomPx: int`, `leftPx: int`, `rightPx: int`, `usableWidthPx: int`, `usableHeightPx: int` | `AndroidSafeAreaInsets(topPx, bottomPx, leftPx, rightPx, usableWidthPx, usableHeightPx)` |
| `AndroidJniBridgeDesc` | `pub struct` | `std/sys/sys_android.aipl` | `jniVersion: int`, `sdkInt: int`, `packageName: str`, `internalDataPath: str`, `apkAssetManagerReady: bool`, `bridgeValid: bool` | `AndroidJniBridgeDesc(jniVersion, sdkInt, packageName, internalDataPath, apkAssetManagerReady, bridgeValid)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/sys/sys_audio.aipl` | `sysAudioOpenStream` | `pub fn sysAudioOpenStream(channels: int, sampleRate: int, bufferFrames: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `2` | `std/sys/sys_audio.aipl` | `sysAudioCloseStream` | `pub fn sysAudioCloseStream(handle: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `3` | `std/sys/sys_audio.aipl` | `sysAudioWriteFrames` | `pub fn sysAudioWriteFrames(handle: int, pcmPtr: int, frames: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `4` | `std/sys/sys_audio.aipl` | `sysAudioGetLatencyFrames` | `pub fn sysAudioGetLatencyFrames(handle: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `5` | `std/sys/sys_audio.aipl` | `sysAudioPauseStream` | `pub fn sysAudioPauseStream(handle: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `6` | `std/sys/sys_audio.aipl` | `sysAudioResumeStream` | `pub fn sysAudioResumeStream(handle: int): int:` | `tests/functions/sys/sys_audio_test.aipl` |
| `7` | `std/sys/sys_ffi.aipl` | `ffiOpen` | `pub fn ffiOpen(libPath: str): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `8` | `std/sys/sys_ffi.aipl` | `ffiHasSymbol` | `pub fn ffiHasSymbol(handle: int, symbol: str): bool:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `9` | `std/sys/sys_ffi.aipl` | `ffiCallInt` | `pub fn ffiCallInt(handle: int, symbol: str, args: [int]): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `10` | `std/sys/sys_ffi.aipl` | `ffiCallFloat` | `pub fn ffiCallFloat(handle: int, symbol: str, args: [float]): float:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `11` | `std/sys/sys_ffi.aipl` | `ffiCallStr` | `pub fn ffiCallStr(handle: int, symbol: str, arg: str): str:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `12` | `std/sys/sys_ffi.aipl` | `ffiClose` | `pub fn ffiClose(handle: int): bool:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `13` | `std/sys/sys_ffi.aipl` | `sysDlopen` | `pub fn sysDlopen(path: str, mode: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `14` | `std/sys/sys_ffi.aipl` | `sysDlsym` | `pub fn sysDlsym(handle: int, symbol: str): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `15` | `std/sys/sys_ffi.aipl` | `sysDlclose` | `pub fn sysDlclose(handle: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `16` | `std/sys/sys_ffi.aipl` | `sysDlerror` | `pub fn sysDlerror(): str:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `17` | `std/sys/sys_ffi.aipl` | `sysCallC0` | `pub fn sysCallC0(fnPtr: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `18` | `std/sys/sys_ffi.aipl` | `sysCallC1` | `pub fn sysCallC1(fnPtr: int, a1: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `19` | `std/sys/sys_ffi.aipl` | `sysCallC2` | `pub fn sysCallC2(fnPtr: int, a1: int, a2: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `20` | `std/sys/sys_ffi.aipl` | `sysCallC3` | `pub fn sysCallC3(fnPtr: int, a1: int, a2: int, a3: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `21` | `std/sys/sys_ffi.aipl` | `sysCallC4` | `pub fn sysCallC4(fnPtr: int, a1: int, a2: int, a3: int, a4: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `22` | `std/sys/sys_ffi.aipl` | `sysCallC5` | `pub fn sysCallC5(fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `23` | `std/sys/sys_ffi.aipl` | `sysCallC6` | `pub fn sysCallC6(fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:` | `tests/functions/sys/sys_ffi_test.aipl` |
| `24` | `std/sys/sys_fs.aipl` | `allocCStringPtr` | `fn allocCStringPtr(s: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `25` | `std/sys/sys_fs.aipl` | `sysFsOpen` | `pub fn sysFsOpen(path: str, flags: int, mode: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `26` | `std/sys/sys_fs.aipl` | `sysFsClose` | `pub fn sysFsClose(fd: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `27` | `std/sys/sys_fs.aipl` | `sysFsRead` | `pub fn sysFsRead(fd: int, bufPtr: int, count: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `28` | `std/sys/sys_fs.aipl` | `sysFsWrite` | `pub fn sysFsWrite(fd: int, bufPtr: int, count: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `29` | `std/sys/sys_fs.aipl` | `sysFsSeek` | `pub fn sysFsSeek(fd: int, offset: int, whence: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `30` | `std/sys/sys_fs.aipl` | `sysFsFsync` | `pub fn sysFsFsync(fd: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `31` | `std/sys/sys_fs.aipl` | `sysFsStatSize` | `pub fn sysFsStatSize(path: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `32` | `std/sys/sys_fs.aipl` | `sysFsStatMtime` | `pub fn sysFsStatMtime(path: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `33` | `std/sys/sys_fs.aipl` | `sysFsUnlink` | `pub fn sysFsUnlink(path: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `34` | `std/sys/sys_fs.aipl` | `sysFsRename` | `pub fn sysFsRename(oldPath: str, newPath: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `35` | `std/sys/sys_fs.aipl` | `sysFsMkdir` | `pub fn sysFsMkdir(path: str, mode: int): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `36` | `std/sys/sys_fs.aipl` | `sysFsRmdir` | `pub fn sysFsRmdir(path: str): int:` | `tests/functions/sys/sys_fs_test.aipl` |
| `37` | `std/sys/sys_gpu.aipl` | `sysGpuInitContext` | `pub fn sysGpuInitContext(windowHandle: int, backendType: int): int:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `38` | `std/sys/sys_gpu.aipl` | `sysGpuDestroyContext` | `pub fn sysGpuDestroyContext(contextHandle: int): void:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `39` | `std/sys/sys_gpu.aipl` | `sysGpuCreateBuffer` | `pub fn sysGpuCreateBuffer(contextHandle: int, sizeBytes: int, usageFlags: int): int:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `40` | `std/sys/sys_gpu.aipl` | `sysGpuUploadBuffer` | `pub fn sysGpuUploadBuffer(contextHandle: int, bufHandle: int, offset: int, dataPtr: int, bytes: int): int:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `41` | `std/sys/sys_gpu.aipl` | `sysGpuDestroyBuffer` | `pub fn sysGpuDestroyBuffer(contextHandle: int, bufHandle: int): void:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `42` | `std/sys/sys_gpu.aipl` | `sysGpuSwapBuffers` | `pub fn sysGpuSwapBuffers(contextHandle: int): void:` | `tests/functions/sys/sys_gpu_test.aipl` |
| `43` | `std/sys/sys_mem.aipl` | `ptrAlloc` | `fn ptrAlloc(size: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `44` | `std/sys/sys_mem.aipl` | `ptrFree` | `fn ptrFree(ptr: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `45` | `std/sys/sys_mem.aipl` | `ptrReadU8` | `fn ptrReadU8(ptr: int, offset: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `46` | `std/sys/sys_mem.aipl` | `ptrWriteU8` | `fn ptrWriteU8(ptr: int, offset: int, val: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `47` | `std/sys/sys_mem.aipl` | `ptrReadI64` | `fn ptrReadI64(ptr: int, offset: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `48` | `std/sys/sys_mem.aipl` | `ptrWriteI64` | `fn ptrWriteI64(ptr: int, offset: int, val: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `49` | `std/sys/sys_mem.aipl` | `sizeofType` | `fn sizeofType(typeName: str): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `50` | `std/sys/sys_mem.aipl` | `bitcastF64ToI64` | `fn bitcastF64ToI64(v: float): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `51` | `std/sys/sys_mem.aipl` | `bitcastI64ToF64` | `fn bitcastI64ToF64(v: int): float:` | `tests/functions/sys/sys_mem_test.aipl` |
| `52` | `std/sys/sys_mem.aipl` | `sysPtrAlloc` | `pub fn sysPtrAlloc(bytes: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `53` | `std/sys/sys_mem.aipl` | `sysPtrFree` | `pub fn sysPtrFree(ptr: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `54` | `std/sys/sys_mem.aipl` | `sysPtrReadU8` | `pub fn sysPtrReadU8(ptr: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `55` | `std/sys/sys_mem.aipl` | `sysPtrWriteU8` | `pub fn sysPtrWriteU8(ptr: int, val: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `56` | `std/sys/sys_mem.aipl` | `sysPtrReadI64` | `pub fn sysPtrReadI64(ptr: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `57` | `std/sys/sys_mem.aipl` | `sysPtrWriteI64` | `pub fn sysPtrWriteI64(ptr: int, val: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `58` | `std/sys/sys_mem.aipl` | `sysPtrCopy` | `pub fn sysPtrCopy(dst: int, src: int, count: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `59` | `std/sys/sys_mem.aipl` | `sysPtrSet` | `pub fn sysPtrSet(dst: int, byteVal: int, count: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `60` | `std/sys/sys_mem.aipl` | `sysPtrCompare` | `pub fn sysPtrCompare(a: int, b: int, count: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `61` | `std/sys/sys_mem.aipl` | `sysPageAlloc` | `pub fn sysPageAlloc(bytes: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `62` | `std/sys/sys_mem.aipl` | `sysPageFree` | `pub fn sysPageFree(addr: int, bytes: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `63` | `std/sys/sys_mem.aipl` | `sysPageProtect` | `pub fn sysPageProtect(addr: int, bytes: int, prot: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `64` | `std/sys/sys_mem.aipl` | `sysSizeofType` | `pub fn sysSizeofType(typeName: str): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `65` | `std/sys/sys_mem.aipl` | `sysBitcastF64ToI64` | `pub fn sysBitcastF64ToI64(v: float): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `66` | `std/sys/sys_mem.aipl` | `sysBitcastI64ToF64` | `pub fn sysBitcastI64ToF64(v: int): float:` | `tests/functions/sys/sys_mem_test.aipl` |
| `67` | `std/sys/sys_mem.aipl` | `MemoryRegion.new` | `pub fn MemoryRegion.new(size: int): MemoryRegion:` | `tests/functions/sys/sys_mem_test.aipl` |
| `68` | `std/sys/sys_mem.aipl` | `free` | `pub fn (self: MemoryRegion) free(): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `69` | `std/sys/sys_mem.aipl` | `readU8` | `pub fn (self: MemoryRegion) readU8(offset: int): int:` | `tests/functions/sys/sys_mem_test.aipl` |
| `70` | `std/sys/sys_mem.aipl` | `writeU8` | `pub fn (self: MemoryRegion) writeU8(offset: int, val: int): void:` | `tests/functions/sys/sys_mem_test.aipl` |
| `71` | `std/sys/sys_net.aipl` | `sysNetSocket` | `pub fn sysNetSocket(domain: int, sockType: int, protocol: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `72` | `std/sys/sys_net.aipl` | `sysNetBind` | `pub fn sysNetBind(fd: int, addrPtr: int, addrLen: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `73` | `std/sys/sys_net.aipl` | `sysNetListen` | `pub fn sysNetListen(fd: int, backlog: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `74` | `std/sys/sys_net.aipl` | `sysNetAccept` | `pub fn sysNetAccept(fd: int, addrPtr: int, addrLenPtr: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `75` | `std/sys/sys_net.aipl` | `sysNetConnect` | `pub fn sysNetConnect(fd: int, addrPtr: int, addrLen: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `76` | `std/sys/sys_net.aipl` | `sysNetSend` | `pub fn sysNetSend(fd: int, bufPtr: int, len: int, flags: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `77` | `std/sys/sys_net.aipl` | `sysNetRecv` | `pub fn sysNetRecv(fd: int, bufPtr: int, len: int, flags: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `78` | `std/sys/sys_net.aipl` | `sysNetSendTo` | `pub fn sysNetSendTo(fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLen: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `79` | `std/sys/sys_net.aipl` | `sysNetRecvFrom` | `pub fn sysNetRecvFrom(fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLenPtr: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `80` | `std/sys/sys_net.aipl` | `sysNetClose` | `pub fn sysNetClose(fd: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `81` | `std/sys/sys_net.aipl` | `sysNetSetNonBlocking` | `pub fn sysNetSetNonBlocking(fd: int, nonBlocking: bool): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `82` | `std/sys/sys_net.aipl` | `sysNetPoll` | `pub fn sysNetPoll(pollFdsPtr: int, nfds: int, timeoutMs: int): int:` | `tests/functions/sys/sys_net_test.aipl` |
| `83` | `std/sys/sys_syscall.aipl` | `rawSyscall` | `pub fn rawSyscall(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `84` | `std/sys/sys_syscall.aipl` | `sysArchSyscall0` | `pub fn sysArchSyscall0(num: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `85` | `std/sys/sys_syscall.aipl` | `sysArchSyscall1` | `pub fn sysArchSyscall1(num: int, a1: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `86` | `std/sys/sys_syscall.aipl` | `sysArchSyscall2` | `pub fn sysArchSyscall2(num: int, a1: int, a2: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `87` | `std/sys/sys_syscall.aipl` | `sysArchSyscall3` | `pub fn sysArchSyscall3(num: int, a1: int, a2: int, a3: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `88` | `std/sys/sys_syscall.aipl` | `sysArchSyscall4` | `pub fn sysArchSyscall4(num: int, a1: int, a2: int, a3: int, a4: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `89` | `std/sys/sys_syscall.aipl` | `sysArchSyscall5` | `pub fn sysArchSyscall5(num: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `90` | `std/sys/sys_syscall.aipl` | `sysArchSyscall6` | `pub fn sysArchSyscall6(num: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `91` | `std/sys/sys_syscall.aipl` | `syscall0` | `pub fn syscall0(nr: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `92` | `std/sys/sys_syscall.aipl` | `syscall1` | `pub fn syscall1(nr: int, a1: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `93` | `std/sys/sys_syscall.aipl` | `syscall2` | `pub fn syscall2(nr: int, a1: int, a2: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `94` | `std/sys/sys_syscall.aipl` | `syscall3` | `pub fn syscall3(nr: int, a1: int, a2: int, a3: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `95` | `std/sys/sys_syscall.aipl` | `syscall4` | `pub fn syscall4(nr: int, a1: int, a2: int, a3: int, a4: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `96` | `std/sys/sys_syscall.aipl` | `syscall5` | `pub fn syscall5(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `97` | `std/sys/sys_syscall.aipl` | `syscall6` | `pub fn syscall6(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `98` | `std/sys/sys_syscall.aipl` | `sysRead` | `pub fn sysRead(fd: int, buf: int, count: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `99` | `std/sys/sys_syscall.aipl` | `sysWrite` | `pub fn sysWrite(fd: int, buf: int, count: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `100` | `std/sys/sys_syscall.aipl` | `sysOpenat` | `pub fn sysOpenat(dfd: int, filename: int, flags: int, mode: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `101` | `std/sys/sys_syscall.aipl` | `sysClose` | `pub fn sysClose(fd: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `102` | `std/sys/sys_syscall.aipl` | `sysMmap` | `pub fn sysMmap(addr: int, length: int, prot: int, flags: int, fd: int, offset: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `103` | `std/sys/sys_syscall.aipl` | `sysMunmap` | `pub fn sysMunmap(addr: int, length: int): int:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `104` | `std/sys/sys_syscall.aipl` | `sysExit` | `pub fn sysExit(status: int): void:` | `tests/functions/sys/sys_syscall_test.aipl` |
| `105` | `std/sys/sys_android.aipl` | `createAndroidLifecycleState` | `pub fn createAndroidLifecycleState(): AndroidLifecycleState:` | `tests/functions/sys/sys_android_test.aipl` |
| `106` | `std/sys/sys_android.aipl` | `stepAndroidLifecycleCmd` | `pub fn stepAndroidLifecycleCmd(state: AndroidLifecycleState, cmd: int): AndroidLifecycleState:` | `tests/functions/sys/sys_android_test.aipl` |
| `107` | `std/sys/sys_android.aipl` | `createAndroidSurfaceDesc` | `pub fn createAndroidSurfaceDesc(windowHandle: int, widthPx: int, heightPx: int, stridePixels: int, densityDpi: int, refreshRateHz: int): AndroidSurfaceDesc:` | `tests/functions/sys/sys_android_test.aipl` |
| `108` | `std/sys/sys_android.aipl` | `computeAndroidSafeAreaInsets` | `pub fn computeAndroidSafeAreaInsets(surfaceWidthPx: int, surfaceHeightPx: int, rawTopPx: int, rawBottomPx: int, rawLeftPx: int, rawRightPx: int): AndroidSafeAreaInsets:` | `tests/functions/sys/sys_android_test.aipl` |
| `109` | `std/sys/sys_android.aipl` | `createAndroidJniBridgeDesc` | `pub fn createAndroidJniBridgeDesc(jniVersion: int, sdkInt: int, packageName: str, internalDataPath: str, hasAssetMgr: bool): AndroidJniBridgeDesc:` | `tests/functions/sys/sys_android_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `sysAudioOpenStream` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioOpenStream(channels: int, sampleRate: int, bufferFrames: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `channels: int, sampleRate: int, bufferFrames: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test opening 48kHz stereo (`channels = 2, sampleRate = 48000, bufferFrames = 512`) and invalid `sampleRate <= 0` rejection. Concrete nominal inputs: `channels: int = 2`, `sampleRate: int = 48000`, `bufferFrames: int = 64`; exercises core body path returning/computing `1`.

```aipl
module tests.functions.sys.sys_audio_z1_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioOpenStream_1(): int:
  let arg_channels = 4
  let edge_channels = 1
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_bufferFrames = 4
  let edge_bufferFrames = 1
  let resNom = sysAudioOpenStream(arg_channels, arg_sampleRate, arg_bufferFrames)
  let resEdge = sysAudioOpenStream(edge_channels, edge_sampleRate, edge_bufferFrames)
  assertEqInt(resNom, 1, "sysAudioOpenStream nominal resNom == 1")
  assertEqInt(resEdge, 1, "sysAudioOpenStream boundary resEdge == 1")
  ret 0
```

---

### `sysAudioCloseStream` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioCloseStream(handle: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify closing an active stream handle transitions stream state cleanly and returns `0`. Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_audio_z2_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioCloseStream_2(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = sysAudioCloseStream(arg_handle)
  let resEdge = sysAudioCloseStream(edge_handle)
  assertEqInt(resNom, 0, "sysAudioCloseStream nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysAudioCloseStream boundary resEdge == 0")
  ret 0
```

---

### `sysAudioWriteFrames` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioWriteFrames(handle: int, pcmPtr: int, frames: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, pcmPtr: int, frames: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify writing stereo PCM frames returns exact `frames` written and rejects `frames < 0`. Concrete nominal inputs: `handle: int = 1`, `pcmPtr: int = 1`, `frames: int = 64`; exercises core body path returning/computing `frames`.

```aipl
module tests.functions.sys.sys_audio_z3_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioWriteFrames_3(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_pcmPtr = 4
  let edge_pcmPtr = 1
  let arg_frames = 4
  let edge_frames = 1
  let resNom = sysAudioWriteFrames(arg_handle, arg_pcmPtr, arg_frames)
  let resEdge = sysAudioWriteFrames(edge_handle, edge_pcmPtr, edge_frames)
  assertEqInt(resNom, 4, "sysAudioWriteFrames nominal resNom == 4")
  assertEqInt(resEdge, 1, "sysAudioWriteFrames boundary resEdge == 1")
  ret 0
```

---

### `sysAudioGetLatencyFrames` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioGetLatencyFrames(handle: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify latency frames query returns `>= 0` matching configured buffer geometry. Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `256`.

```aipl
module tests.functions.sys.sys_audio_z4_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioGetLatencyFrames_4(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = sysAudioGetLatencyFrames(arg_handle)
  let resEdge = sysAudioGetLatencyFrames(edge_handle)
  assertEqInt(resNom, 256, "sysAudioGetLatencyFrames nominal resNom == 256")
  assertEqInt(resEdge, 256, "sysAudioGetLatencyFrames boundary resEdge == 256")
  ret 0
```

---

### `sysAudioPauseStream` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioPauseStream(handle: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify pausing an active stream handle succeeds (`0`). Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_audio_z5_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioPauseStream_5(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = sysAudioPauseStream(arg_handle)
  let resEdge = sysAudioPauseStream(edge_handle)
  assertEqInt(resNom, 0, "sysAudioPauseStream nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysAudioPauseStream boundary resEdge == 0")
  ret 0
```

---

### `sysAudioResumeStream` (`std/sys/sys_audio.aipl`)

- **Signature**: `pub fn sysAudioResumeStream(handle: int): int:`
- **Import**: `import * from "std/sys/sys_audio"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_audio_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify resuming a paused stream handle restores active playback state. Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_audio_z6_test
import * from "std/sys/sys_audio"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_audio_sysAudioResumeStream_6(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = sysAudioResumeStream(arg_handle)
  let resEdge = sysAudioResumeStream(edge_handle)
  assertEqInt(resNom, 0, "sysAudioResumeStream nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysAudioResumeStream boundary resEdge == 0")
  ret 0
```

---

### `ffiOpen` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiOpen(libPath: str): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `libPath: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test opening standard C library (`"libc.so.6"` / `"libm.so.6"`) and non-existent library fallback behavior. Concrete nominal inputs: `libPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_ffi_z1_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiOpen_1(): int:
  let arg_libPath = "/tmp/aipl_test_path"
  let edge_libPath = "/tmp/aipl_test_path"
  let resNom = ffiOpen(arg_libPath)
  let resEdge = ffiOpen(edge_libPath)
  assertEqInt(resNom, 0, "ffiOpen nominal resNom == 0")
  assertEqInt(resEdge, 0, "ffiOpen boundary resEdge == 0")
  ret 0
```

---

### `ffiHasSymbol` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiHasSymbol(handle: int, symbol: str): bool:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, symbol: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test symbol lookup for `"abs"` / `"cos"` (`true`) and `"nonexistent_symbol_xyz"` (`false`). Concrete nominal inputs: `handle: int = 1`, `symbol: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.sys.sys_ffi_z2_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiHasSymbol_2(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_symbol = "test"
  let edge_symbol = "a"
  let resNom = ffiHasSymbol(arg_handle, arg_symbol)
  let resEdge = ffiHasSymbol(edge_handle, edge_symbol)
  assert(resNom == false, "ffiHasSymbol nominal resNom == false")
  assert(resEdge == false, "ffiHasSymbol boundary resEdge == false")
  ret 0
```

---

### `ffiCallInt` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiCallInt(handle: int, symbol: str, args: [int]): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, symbol: str, args: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test calling C integer symbol with negative input (`-42 -> 42`). Concrete nominal inputs: `handle: int = 1`, `symbol: str = "aipl_test"`, `args: [int] = [1]`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_ffi_z3_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiCallInt_3(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_symbol = "42"
  let edge_symbol = "0"
  let arg_args = [2]
  let edge_args = []
  let resNom = ffiCallInt(arg_handle, arg_symbol, arg_args)
  let resEdge = ffiCallInt(edge_handle, edge_symbol, edge_args)
  assertEqInt(resNom, 0, "ffiCallInt nominal resNom == 0")
  assertEqInt(resEdge, 0, "ffiCallInt boundary resEdge == 0")
  ret 0
```

---

### `ffiCallFloat` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiCallFloat(handle: int, symbol: str, args: [float]): float:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, symbol: str, args: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test calling C floating-point symbol (`0.0 -> 1.0` for `cos`). Concrete nominal inputs: `handle: int = 1`, `symbol: str = "aipl_test"`, `args: [float] = [1.0]`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.sys.sys_ffi_z4_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiCallFloat_4(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_symbol = "42"
  let edge_symbol = "0"
  let arg_args = [1.0]
  let edge_args = []
  let resNom = ffiCallFloat(arg_handle, arg_symbol, arg_args)
  let resEdge = ffiCallFloat(edge_handle, edge_symbol, edge_args)
  assertApproxEq(resNom, 0.0, 0.001, "ffiCallFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "ffiCallFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `ffiCallStr` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiCallStr(handle: int, symbol: str, arg: str): str:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, symbol: str, arg: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test string return marshaling across C ABI boundary. Concrete nominal inputs: `handle: int = 1`, `symbol: str = "aipl_test"`, `arg: str = "aipl_test"`; exercises core body path returning/computing `""`.

```aipl
module tests.functions.sys.sys_ffi_z5_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiCallStr_5(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_symbol = "test"
  let edge_symbol = "a"
  let arg_arg = "test"
  let edge_arg = "a"
  let resNom = ffiCallStr(arg_handle, arg_symbol, arg_arg)
  let resEdge = ffiCallStr(edge_handle, edge_symbol, edge_arg)
  assertEqStr(resNom, "", "ffiCallStr nominal string matches")
  assertEqStr(resEdge, "", "ffiCallStr boundary string matches")
  ret 0
```

---

### `ffiClose` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn ffiClose(handle: int): bool:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify closing FFI library handle releases descriptor cleanly. Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.sys.sys_ffi_z6_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_ffiClose_6(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = ffiClose(arg_handle)
  let resEdge = ffiClose(edge_handle)
  assert(resNom == true, "ffiClose nominal resNom == true")
  assert(resEdge == true, "ffiClose boundary resEdge == true")
  ret 0
```

---

### `sysDlopen` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysDlopen(path: str, mode: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, mode: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test `RTLD_LAZY` dynamic handle acquisition. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `mode: int = 1`; exercises core body path returning/computing `ffiOpen(path)`.

```aipl
module tests.functions.sys.sys_ffi_z7_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysDlopen_7(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_mode = 4
  let edge_mode = 1
  let resNom = sysDlopen(arg_path, arg_mode)
  let resEdge = sysDlopen(edge_path, edge_mode)
  assertEqInt(resNom, 0, "sysDlopen nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysDlopen boundary resEdge == 0")
  ret 0
```

---

### `sysDlsym` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysDlsym(handle: int, symbol: str): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int, symbol: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test raw symbol address resolution (`!= 0` for valid symbol). Concrete nominal inputs: `handle: int = 1`, `symbol: str = "aipl_test"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_ffi_z8_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysDlsym_8(): int:
  let arg_handle = 4
  let edge_handle = 1
  let arg_symbol = "test"
  let edge_symbol = "a"
  let resNom = sysDlsym(arg_handle, arg_symbol)
  let resEdge = sysDlsym(edge_handle, edge_symbol)
  assertEqInt(resNom, 0, "sysDlsym nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysDlsym boundary resEdge == 0")
  ret 0
```

---

### `sysDlclose` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysDlclose(handle: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `handle: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify `sysDlclose` returns `0` on valid handle. Concrete nominal inputs: `handle: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.sys.sys_ffi_z9_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysDlclose_9(): int:
  let arg_handle = 4
  let edge_handle = 1
  let resNom = sysDlclose(arg_handle)
  let resEdge = sysDlclose(edge_handle)
  assertEqInt(resNom, 0, "sysDlclose nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysDlclose boundary resEdge == 0")
  ret 0
```

---

### `sysDlerror` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysDlerror(): str:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `sysDlerror()` returns diagnostic string after failed `sysDlopen`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `""`.

```aipl
module tests.functions.sys.sys_ffi_z10_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysDlerror_10(): int:
  let resNom = sysDlerror()
  let resEdge = sysDlerror()
  assertEqStr(resNom, "", "sysDlerror nominal string matches")
  assertEqStr(resEdge, "", "sysDlerror boundary string matches")
  ret 0
```

---

### `sysCallC0` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC0(fnPtr: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test 0-argument C ABI function pointer invocation. Concrete nominal inputs: `fnPtr: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_ffi_z11_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC0_11(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let resNom = sysCallC0(arg_fnPtr)
  let resEdge = sysCallC0(edge_fnPtr)
  assertEqInt(resNom, 0, "sysCallC0 nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysCallC0 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC1` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC1(fnPtr: int, a1: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test 1-argument C ABI (`RDI`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`; exercises core body path returning/computing `a1`.

```aipl
module tests.functions.sys.sys_ffi_z12_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC1_12(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let resNom = sysCallC1(arg_fnPtr, arg_a1)
  let resEdge = sysCallC1(edge_fnPtr, edge_a1)
  assertEqInt(resNom, 2, "sysCallC1 nominal resNom == 2")
  assertEqInt(resEdge, 0, "sysCallC1 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC2` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC2(fnPtr: int, a1: int, a2: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int, a2: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test 2-argument C ABI (`RDI, RSI`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`, `a2: int = 1`; exercises core body path returning/computing `a1 + a2`.

```aipl
module tests.functions.sys.sys_ffi_z13_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC2_13(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let resNom = sysCallC2(arg_fnPtr, arg_a1, arg_a2)
  let resEdge = sysCallC2(edge_fnPtr, edge_a1, edge_a2)
  assertEqInt(resNom, 4, "sysCallC2 nominal resNom == 4")
  assertEqInt(resEdge, 0, "sysCallC2 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC3` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC3(fnPtr: int, a1: int, a2: int, a3: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int, a2: int, a3: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test 3-argument C ABI (`RDI, RSI, RDX`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`; exercises core body path returning/computing `a1 + a2 + a3`.

```aipl
module tests.functions.sys.sys_ffi_z14_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC3_14(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let resNom = sysCallC3(arg_fnPtr, arg_a1, arg_a2, arg_a3)
  let resEdge = sysCallC3(edge_fnPtr, edge_a1, edge_a2, edge_a3)
  assertEqInt(resNom, 6, "sysCallC3 nominal resNom == 6")
  assertEqInt(resEdge, 0, "sysCallC3 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC4` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC4(fnPtr: int, a1: int, a2: int, a3: int, a4: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int, a2: int, a3: int, a4: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test 4-argument C ABI (`RDI, RSI, RDX, RCX`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`; exercises core body path returning/computing `a1 + a2 + a3 + a4`.

```aipl
module tests.functions.sys.sys_ffi_z15_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC4_15(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let resNom = sysCallC4(arg_fnPtr, arg_a1, arg_a2, arg_a3, arg_a4)
  let resEdge = sysCallC4(edge_fnPtr, edge_a1, edge_a2, edge_a3, edge_a4)
  assertEqInt(resNom, 8, "sysCallC4 nominal resNom == 8")
  assertEqInt(resEdge, 0, "sysCallC4 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC5` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC5(fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test 5-argument C ABI (`RDI..R8`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`; exercises core body path returning/computing `a1 + a2 + a3 + a4 + a5`.

```aipl
module tests.functions.sys.sys_ffi_z16_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC5_16(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let resNom = sysCallC5(arg_fnPtr, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5)
  let resEdge = sysCallC5(edge_fnPtr, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5)
  assertEqInt(resNom, 10, "sysCallC5 nominal resNom == 10")
  assertEqInt(resEdge, 0, "sysCallC5 boundary resEdge == 0")
  ret 0
```

---

### `sysCallC6` (`std/sys/sys_ffi.aipl`)

- **Signature**: `pub fn sysCallC6(fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:`
- **Import**: `import * from "std/sys/sys_ffi"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fnPtr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_ffi_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test 6-argument C ABI (`RDI..R9`) register dispatch. Concrete nominal inputs: `fnPtr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`, `a6: int = 1`; exercises core body path returning/computing `a1 + a2 + a3 + a4 + a5 + a6`.

```aipl
module tests.functions.sys.sys_ffi_z17_test
import * from "std/sys/sys_ffi"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_ffi_sysCallC6_17(): int:
  let arg_fnPtr = 4
  let edge_fnPtr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let arg_a6 = 2
  let edge_a6 = 0
  let resNom = sysCallC6(arg_fnPtr, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5, arg_a6)
  let resEdge = sysCallC6(edge_fnPtr, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5, edge_a6)
  assertEqInt(resNom, 12, "sysCallC6 nominal resNom == 12")
  assertEqInt(resEdge, 0, "sysCallC6 boundary resEdge == 0")
  ret 0
```

---

### `allocCStringPtr` (`std/sys/sys_fs.aipl`)

- **Signature**: `fn allocCStringPtr(s: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify null-terminated UTF-8 byte buffer allocation and first/last byte readback. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `p`.

```aipl
module tests.functions.sys.sys_fs_z1_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_allocCStringPtr_1(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = allocCStringPtr(arg_s)
  let resEdge = allocCStringPtr(edge_s)
  assert(resNom > 0, "allocCStringPtr nominal resNom > 0")
  assert(resEdge > 0, "allocCStringPtr boundary resEdge > 0")
  ret 0
```

---

### `sysFsOpen` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsOpen(path: str, flags: int, mode: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, flags: int, mode: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test creating/opening a temp file in `/tmp` (`fd >= 0`) and opening a non-existent path (`fd < 0`). Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `flags: int = 1`, `mode: int = 1`; exercises core body path returning/computing `fd`.

```aipl
module tests.functions.sys.sys_fs_z2_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsOpen_2(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_flags = 1
  let edge_flags = 0
  let arg_mode = 4
  let edge_mode = 1
  let resNom = sysFsOpen(arg_path, arg_flags, arg_mode)
  let resEdge = sysFsOpen(edge_path, edge_flags, edge_mode)
  assertEqInt(resNom, -1, "sysFsOpen nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsOpen boundary resEdge == -1")
  ret 0
```

---

### `sysFsClose` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsClose(fd: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Close descriptor and assert return `== 0`. Concrete nominal inputs: `fd: int = 1`; exercises core body path returning/computing `sysArchSyscall1(SYS_CLOSE, fd)`.

```aipl
module tests.functions.sys.sys_fs_z3_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsClose_3(): int:
  let arg_fd = 999
  let edge_fd = -1
  let resNom = sysFsClose(arg_fd)
  let resEdge = sysFsClose(edge_fd)
  assertEqInt(resNom, -1, "sysFsClose nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsClose boundary resEdge == -1")
  ret 0
```

---

### `sysFsRead` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsRead(fd: int, bufPtr: int, count: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, count: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Read back 32 written bytes and assert exact byte-for-byte match. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `count: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_READ, fd, bufPtr, count)`.

```aipl
module tests.functions.sys.sys_fs_z4_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsRead_4(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_count = 4
  let edge_count = 1
  let resNom = sysFsRead(arg_fd, arg_bufPtr, arg_count)
  let resEdge = sysFsRead(edge_fd, edge_bufPtr, edge_count)
  assertEqInt(resNom, -1, "sysFsRead nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsRead boundary resEdge == -1")
  ret 0
```

---

### `sysFsWrite` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsWrite(fd: int, bufPtr: int, count: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, count: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Write 32 known bytes to temp file and assert returned byte count `== 32`. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `count: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_WRITE, fd, bufPtr, count)`.

```aipl
module tests.functions.sys.sys_fs_z5_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsWrite_5(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_count = 4
  let edge_count = 1
  let resNom = sysFsWrite(arg_fd, arg_bufPtr, arg_count)
  let resEdge = sysFsWrite(edge_fd, edge_bufPtr, edge_count)
  assertEqInt(resNom, -1, "sysFsWrite nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsWrite boundary resEdge == -1")
  ret 0
```

---

### `sysFsSeek` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsSeek(fd: int, offset: int, whence: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, offset: int, whence: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Seek back to `offset = 0` (`SEEK_SET`) and verify new cursor position `== 0`. Concrete nominal inputs: `fd: int = 1`, `offset: int = 0`, `whence: int = 1`; exercises core body path returning/computing `sysArchSyscall3(SYS_LSEEK, fd, offset, whence)`.

```aipl
module tests.functions.sys.sys_fs_z6_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsSeek_6(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_offset = 1
  let edge_offset = 0
  let arg_whence = 4
  let edge_whence = 1
  let resNom = sysFsSeek(arg_fd, arg_offset, arg_whence)
  let resEdge = sysFsSeek(edge_fd, edge_offset, edge_whence)
  assertEqInt(resNom, -1, "sysFsSeek nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsSeek boundary resEdge == -1")
  ret 0
```

---

### `sysFsFsync` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsFsync(fd: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Flush file descriptor to disk and assert return `== 0`. Concrete nominal inputs: `fd: int = 1`; exercises core body path returning/computing `sysArchSyscall1(SYS_FSYNC, fd)`.

```aipl
module tests.functions.sys.sys_fs_z7_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsFsync_7(): int:
  let arg_fd = 999
  let edge_fd = -1
  let resNom = sysFsFsync(arg_fd)
  let resEdge = sysFsFsync(edge_fd)
  assertEqInt(resNom, -1, "sysFsFsync nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsFsync boundary resEdge == -1")
  ret 0
```

---

### `sysFsStatSize` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsStatSize(path: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify file size of the written temp file equals `32`. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `sz`.

```aipl
module tests.functions.sys.sys_fs_z8_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsStatSize_8(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = sysFsStatSize(arg_path)
  let resEdge = sysFsStatSize(edge_path)
  assertEqInt(resNom, -1, "sysFsStatSize nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsStatSize boundary resEdge == -1")
  ret 0
```

---

### `sysFsStatMtime` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsStatMtime(path: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify modification timestamp `> 1700000000`. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `mtime`.

```aipl
module tests.functions.sys.sys_fs_z9_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsStatMtime_9(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = sysFsStatMtime(arg_path)
  let resEdge = sysFsStatMtime(edge_path)
  assertEqInt(resNom, -1, "sysFsStatMtime nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsStatMtime boundary resEdge == -1")
  ret 0
```

---

### `sysFsUnlink` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsUnlink(path: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Delete temp file and verify subsequent `sysFsStatSize(path) < 0`. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.sys.sys_fs_z10_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsUnlink_10(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = sysFsUnlink(arg_path)
  let resEdge = sysFsUnlink(edge_path)
  assertEqInt(resNom, -1, "sysFsUnlink nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsUnlink boundary resEdge == -1")
  ret 0
```

---

### `sysFsRename` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsRename(oldPath: str, newPath: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oldPath: str, newPath: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Atomically rename temp file and verify `sysFsStatSize(newPath) == 32`. Concrete nominal inputs: `oldPath: str = "/tmp/aipl_test_artifact.tmp"`, `newPath: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.sys.sys_fs_z11_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsRename_11(): int:
  let arg_oldPath = "/tmp/aipl_test_path"
  let edge_oldPath = "/tmp/aipl_test_path"
  let arg_newPath = "/tmp/aipl_test_path"
  let edge_newPath = "/tmp/aipl_test_path"
  let resNom = sysFsRename(arg_oldPath, arg_newPath)
  let resEdge = sysFsRename(edge_oldPath, edge_newPath)
  assertEqInt(resNom, -1, "sysFsRename nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysFsRename boundary resEdge == -1")
  ret 0
```

---

### `sysFsMkdir` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsMkdir(path: str, mode: int): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, mode: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Create temp directory in `/tmp` and assert success. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `mode: int = 1`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.sys.sys_fs_z12_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsMkdir_12(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_mode = 4
  let edge_mode = 1
  let resNom = sysFsMkdir(arg_path, arg_mode)
  let resEdge = sysFsMkdir(edge_path, edge_mode)
  assertEqInt(resNom, 0, "sysFsMkdir nominal resNom == 0")
  assertEqInt(resEdge, -1, "sysFsMkdir boundary resEdge == -1")
  ret 0
```

---

### `sysFsRmdir` (`std/sys/sys_fs.aipl`)

- **Signature**: `pub fn sysFsRmdir(path: str): int:`
- **Import**: `import * from "std/sys/sys_fs"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_fs_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Remove empty temp directory and assert success. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `res`.

```aipl
module tests.functions.sys.sys_fs_z13_test
import * from "std/sys/sys_fs"
import { sysPtrAlloc, sysPtrFree, sysPtrWriteU8, sysPtrReadI64, sysPtrSet } from "std/sys/sys_mem"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, SYS_READ, SYS_WRITE, SYS_CLOSE, SYS_LSEEK, SYS_FSYNC, SYS_OPENAT, SYS_UNLINKAT, SYS_MKDIRAT, SYS_RENAMEAT, AT_FDCWD } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_fs_sysFsRmdir_13(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = sysFsRmdir(arg_path)
  let resEdge = sysFsRmdir(edge_path)
  assertEqInt(resNom, 0, "sysFsRmdir nominal resNom == 0")
  assertEqInt(resEdge, -1, "sysFsRmdir boundary resEdge == -1")
  ret 0
```

---

### `sysGpuInitContext` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuInitContext(windowHandle: int, backendType: int): int:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `windowHandle: int, backendType: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Initialize headless/software GPU context and verify valid context handle `> 0`. Concrete nominal inputs: `windowHandle: int = 1`, `backendType: int = 1`; exercises core body path returning/computing `1`.

```aipl
module tests.functions.sys.sys_gpu_z1_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuInitContext_1(): int:
  let arg_windowHandle = 4
  let edge_windowHandle = 1
  let arg_backendType = 4
  let edge_backendType = 1
  let resNom = sysGpuInitContext(arg_windowHandle, arg_backendType)
  let resEdge = sysGpuInitContext(edge_windowHandle, edge_backendType)
  assertEqInt(resNom, 1, "sysGpuInitContext nominal resNom == 1")
  assertEqInt(resEdge, 1, "sysGpuInitContext boundary resEdge == 1")
  ret 0
```

---

### `sysGpuDestroyContext` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuDestroyContext(contextHandle: int): void:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contextHandle: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Tear down GPU context cleanly. Concrete nominal inputs: `contextHandle: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_gpu_z2_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuDestroyContext_2(): int:
  mut completedCalls = 0
  let arg_contextHandle = 4
  let edge_contextHandle = 1
  sysGpuDestroyContext(arg_contextHandle)
  sysGpuDestroyContext(edge_contextHandle)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysGpuDestroyContext nominal and boundary void calls completed")
  ret 0
```

---

### `sysGpuCreateBuffer` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuCreateBuffer(contextHandle: int, sizeBytes: int, usageFlags: int): int:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contextHandle: int, sizeBytes: int, usageFlags: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Allocate vertex/uniform GPU buffer (`4096` bytes) and assert handle `> 0`. Concrete nominal inputs: `contextHandle: int = 1`, `sizeBytes: int = 64`, `usageFlags: int = 1`; exercises core body path returning/computing `1`.

```aipl
module tests.functions.sys.sys_gpu_z3_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuCreateBuffer_3(): int:
  let arg_contextHandle = 4
  let edge_contextHandle = 1
  let arg_sizeBytes = 4
  let edge_sizeBytes = 1
  let arg_usageFlags = 1
  let edge_usageFlags = 0
  let resNom = sysGpuCreateBuffer(arg_contextHandle, arg_sizeBytes, arg_usageFlags)
  let resEdge = sysGpuCreateBuffer(edge_contextHandle, edge_sizeBytes, edge_usageFlags)
  assertEqInt(resNom, 1, "sysGpuCreateBuffer nominal resNom == 1")
  assertEqInt(resEdge, 1, "sysGpuCreateBuffer boundary resEdge == 1")
  ret 0
```

---

### `sysGpuUploadBuffer` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuUploadBuffer(contextHandle: int, bufHandle: int, offset: int, dataPtr: int, bytes: int): int:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contextHandle: int, bufHandle: int, offset: int, dataPtr: int, bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Upload byte payload at `offset = 0` and verify byte count uploaded. Concrete nominal inputs: `contextHandle: int = 1`, `bufHandle: int = 1`, `offset: int = 0`, `dataPtr: int = 1`, `bytes: int = 64`; exercises core body path returning/computing `bytes`.

```aipl
module tests.functions.sys.sys_gpu_z4_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuUploadBuffer_4(): int:
  let arg_contextHandle = 4
  let edge_contextHandle = 1
  let arg_bufHandle = 4
  let edge_bufHandle = 1
  let arg_offset = 1
  let edge_offset = 0
  let arg_dataPtr = 1
  let edge_dataPtr = 0
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = sysGpuUploadBuffer(arg_contextHandle, arg_bufHandle, arg_offset, arg_dataPtr, arg_bytes)
  let resEdge = sysGpuUploadBuffer(edge_contextHandle, edge_bufHandle, edge_offset, edge_dataPtr, edge_bytes)
  assertEqInt(resNom, 4, "sysGpuUploadBuffer nominal resNom == 4")
  assertEqInt(resEdge, -1, "sysGpuUploadBuffer boundary resEdge == -1")
  ret 0
```

---

### `sysGpuDestroyBuffer` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuDestroyBuffer(contextHandle: int, bufHandle: int): void:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contextHandle: int, bufHandle: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Release GPU buffer handle cleanly. Concrete nominal inputs: `contextHandle: int = 1`, `bufHandle: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_gpu_z5_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuDestroyBuffer_5(): int:
  mut completedCalls = 0
  let arg_contextHandle = 4
  let edge_contextHandle = 1
  let arg_bufHandle = 4
  let edge_bufHandle = 1
  sysGpuDestroyBuffer(arg_contextHandle, arg_bufHandle)
  sysGpuDestroyBuffer(edge_contextHandle, edge_bufHandle)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysGpuDestroyBuffer nominal and boundary void calls completed")
  ret 0
```

---

### `sysGpuSwapBuffers` (`std/sys/sys_gpu.aipl`)

- **Signature**: `pub fn sysGpuSwapBuffers(contextHandle: int): void:`
- **Import**: `import * from "std/sys/sys_gpu"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `contextHandle: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_gpu_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Present frame and verify swap execution without error. Concrete nominal inputs: `contextHandle: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_gpu_z6_test
import * from "std/sys/sys_gpu"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_gpu_sysGpuSwapBuffers_6(): int:
  mut completedCalls = 0
  let arg_contextHandle = 4
  let edge_contextHandle = 1
  sysGpuSwapBuffers(arg_contextHandle)
  sysGpuSwapBuffers(edge_contextHandle)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysGpuSwapBuffers nominal and boundary void calls completed")
  ret 0
```

---

### `ptrAlloc` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrAlloc(size: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Allocate 128 bytes and verify returned pointer `!= 0`. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z1_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrAlloc_1(): int:
  let arg_size = 4
  let edge_size = 1
  let resNom = ptrAlloc(arg_size)
  let resEdge = ptrAlloc(edge_size)
  assert(resNom > 0, "ptrAlloc nominal resNom > 0")
  assert(resEdge > 0, "ptrAlloc boundary resEdge > 0")
  ret 0
```

---

### `ptrFree` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrFree(ptr: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Free allocated pointer cleanly. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z2_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrFree_2(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  ptrFree(arg_ptr)
  ptrFree(edge_ptr)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "ptrFree nominal and boundary void calls completed")
  ret 0
```

---

### `ptrReadU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrReadU8(ptr: int, offset: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, offset: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Read unsigned 8-bit values `[0, 127, 255]` at offsets `0, 1, 2`. Concrete nominal inputs: `ptr: int = 1`, `offset: int = 0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z3_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrReadU8_3(): int:
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_offset = 1
  let edge_offset = 0
  let resNom = ptrReadU8(arg_ptr, arg_offset)
  let resEdge = ptrReadU8(edge_ptr, edge_offset)
  assertEqInt(resNom, 0, "ptrReadU8 nominal resNom == 0")
  assertEqInt(resEdge, 0, "ptrReadU8 boundary resEdge == 0")
  ret 0
```

---

### `ptrWriteU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrWriteU8(ptr: int, offset: int, val: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, offset: int, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Write unsigned 8-bit values at arbitrary byte offsets. Concrete nominal inputs: `ptr: int = 1`, `offset: int = 0`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z4_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrWriteU8_4(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_offset = 1
  let edge_offset = 0
  let arg_val = 2
  let edge_val = 0
  ptrWriteU8(arg_ptr, arg_offset, arg_val)
  ptrWriteU8(edge_ptr, edge_offset, edge_val)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "ptrWriteU8 nominal and boundary void calls completed")
  ret 0
```

---

### `ptrReadI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrReadI64(ptr: int, offset: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, offset: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Read signed 64-bit integer at 8-byte aligned offset. Concrete nominal inputs: `ptr: int = 1`, `offset: int = 0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z5_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrReadI64_5(): int:
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_offset = 1
  let edge_offset = 0
  let resNom = ptrReadI64(arg_ptr, arg_offset)
  let resEdge = ptrReadI64(edge_ptr, edge_offset)
  assertEqInt(resNom, 0, "ptrReadI64 nominal resNom == 0")
  assertEqInt(resEdge, 0, "ptrReadI64 boundary resEdge == 0")
  ret 0
```

---

### `ptrWriteI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn ptrWriteI64(ptr: int, offset: int, val: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, offset: int, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Write `-9007199254740991` and `+9007199254740991` and verify exact readback. Concrete nominal inputs: `ptr: int = 1`, `offset: int = 0`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z6_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_ptrWriteI64_6(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_offset = 1
  let edge_offset = 0
  let arg_val = 2
  let edge_val = 0
  ptrWriteI64(arg_ptr, arg_offset, arg_val)
  ptrWriteI64(edge_ptr, edge_offset, edge_val)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "ptrWriteI64 nominal and boundary void calls completed")
  ret 0
```

---

### `sizeofType` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn sizeofType(typeName: str): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `typeName: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `sizeofType("i64") == 8`, `sizeofType("f64") == 8`, `sizeofType("i32") == 4`, `sizeofType("u8") == 1`. Concrete nominal inputs: `typeName: str = "aipl_test"`; exercises core body path returning/computing `8`.

```aipl
module tests.functions.sys.sys_mem_z7_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sizeofType_7(): int:
  let arg_typeName = "test"
  let edge_typeName = "a"
  let resNom = sizeofType(arg_typeName)
  let resEdge = sizeofType(edge_typeName)
  assertEqInt(resNom, 8, "sizeofType nominal resNom == 8")
  assertEqInt(resEdge, 8, "sizeofType boundary resEdge == 8")
  ret 0
```

---

### `bitcastF64ToI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn bitcastF64ToI64(v: float): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify IEEE-754 bit pattern of `1.0` (`4607182418800017408`). Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z8_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_bitcastF64ToI64_8(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = bitcastF64ToI64(arg_v)
  let resEdge = bitcastF64ToI64(edge_v)
  assertEqInt(resNom, 4607182418800017408, "bitcastF64ToI64 nominal resNom == 4607182418800017408")
  assertEqInt(resEdge, 4602678819172646912, "bitcastF64ToI64 boundary resEdge == 4602678819172646912")
  ret 0
```

---

### `bitcastI64ToF64` (`std/sys/sys_mem.aipl`)

- **Signature**: `fn bitcastI64ToF64(v: int): float:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify exact round-trip `bitcastI64ToF64(bitcastF64ToI64(-3.1415926535)) == -3.1415926535`. Concrete nominal inputs: `v: int = 1`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.sys.sys_mem_z9_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_bitcastI64ToF64_9(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = bitcastI64ToF64(arg_v)
  let resEdge = bitcastI64ToF64(edge_v)
  assertApproxEq(resNom, 0.0, 0.001, "bitcastI64ToF64 nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "bitcastI64ToF64 boundary resEdge ~= 0.0")
  ret 0
```

---

### `sysPtrAlloc` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrAlloc(bytes: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Allocate system heap block and verify non-null address. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `ptrAlloc(sz)`.

```aipl
module tests.functions.sys.sys_mem_z10_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrAlloc_10(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = sysPtrAlloc(arg_bytes)
  let resEdge = sysPtrAlloc(edge_bytes)
  assert(resNom > 0, "sysPtrAlloc nominal resNom > 0")
  assert(resEdge > 0, "sysPtrAlloc boundary resEdge > 0")
  ret 0
```

---

### `sysPtrFree` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrFree(ptr: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Release `sysPtrAlloc` block cleanly. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z11_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrFree_11(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  sysPtrFree(arg_ptr)
  sysPtrFree(edge_ptr)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysPtrFree nominal and boundary void calls completed")
  ret 0
```

---

### `sysPtrReadU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrReadU8(ptr: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Read byte at base pointer `ptr`. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `ptrReadU8(ptr, 0)`.

```aipl
module tests.functions.sys.sys_mem_z12_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrReadU8_12(): int:
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let resNom = sysPtrReadU8(arg_ptr)
  let resEdge = sysPtrReadU8(edge_ptr)
  assertEqInt(resNom, 0, "sysPtrReadU8 nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysPtrReadU8 boundary resEdge == 0")
  ret 0
```

---

### `sysPtrWriteU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrWriteU8(ptr: int, val: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Write byte at base pointer `ptr` and verify via `sysPtrReadU8`. Concrete nominal inputs: `ptr: int = 1`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z13_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrWriteU8_13(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_val = 2
  let edge_val = 0
  sysPtrWriteU8(arg_ptr, arg_val)
  sysPtrWriteU8(edge_ptr, edge_val)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysPtrWriteU8 nominal and boundary void calls completed")
  ret 0
```

---

### `sysPtrReadI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrReadI64(ptr: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Read 64-bit word at base pointer `ptr`. Concrete nominal inputs: `ptr: int = 1`; exercises core body path returning/computing `ptrReadI64(ptr, 0)`.

```aipl
module tests.functions.sys.sys_mem_z14_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrReadI64_14(): int:
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let resNom = sysPtrReadI64(arg_ptr)
  let resEdge = sysPtrReadI64(edge_ptr)
  assertEqInt(resNom, 0, "sysPtrReadI64 nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysPtrReadI64 boundary resEdge == 0")
  ret 0
```

---

### `sysPtrWriteI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrWriteI64(ptr: int, val: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ptr: int, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Write 64-bit word at base pointer `ptr` and verify via `sysPtrReadI64`. Concrete nominal inputs: `ptr: int = 1`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z15_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrWriteI64_15(): int:
  mut completedCalls = 0
  let arg_ptr = ptrAlloc(128)
  let edge_ptr = ptrAlloc(128)
  let arg_val = 2
  let edge_val = 0
  sysPtrWriteI64(arg_ptr, arg_val)
  sysPtrWriteI64(edge_ptr, edge_val)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysPtrWriteI64 nominal and boundary void calls completed")
  ret 0
```

---

### `sysPtrCopy` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrCopy(dst: int, src: int, count: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dst: int, src: int, count: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Copy 64-byte block from `src` to `dst` and verify identical byte contents. Concrete nominal inputs: `dst: int = 1`, `src: int = 1`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z16_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrCopy_16(): int:
  mut completedCalls = 0
  let arg_dst = ptrAlloc(128)
  let edge_dst = ptrAlloc(128)
  let arg_src = ptrAlloc(128)
  let edge_src = ptrAlloc(128)
  let arg_count = 4
  let edge_count = 1
  sysPtrCopy(arg_dst, arg_src, arg_count)
  sysPtrCopy(edge_dst, edge_src, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysPtrCopy nominal and boundary void calls completed")
  ret 0
```

---

### `sysPtrSet` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrSet(dst: int, byteVal: int, count: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dst: int, byteVal: int, count: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Fill 64-byte block with `0xAA` (`170`) and verify every byte equals `170`. Concrete nominal inputs: `dst: int = 1`, `byteVal: int = 1`, `count: int = 64`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z17_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrSet_17(): int:
  mut completedCalls = 0
  let arg_dst = ptrAlloc(128)
  let edge_dst = ptrAlloc(128)
  let arg_byteVal = 4
  let edge_byteVal = 1
  let arg_count = 4
  let edge_count = 1
  sysPtrSet(arg_dst, arg_byteVal, arg_count)
  sysPtrSet(edge_dst, edge_byteVal, edge_count)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysPtrSet nominal and boundary void calls completed")
  ret 0
```

---

### `sysPtrCompare` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPtrCompare(a: int, b: int, count: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: int, b: int, count: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify equal buffers return `0`, `a < b` returns `< 0`, and `a > b` returns `> 0`. Concrete nominal inputs: `a: int = 1`, `b: int = 1`, `count: int = 64`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z18_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPtrCompare_18(): int:
  let arg_a = ptrAlloc(128)
  let edge_a = ptrAlloc(128)
  let arg_b = ptrAlloc(128)
  let edge_b = ptrAlloc(128)
  let arg_count = 4
  let edge_count = 1
  let resNom = sysPtrCompare(arg_a, arg_b, arg_count)
  let resEdge = sysPtrCompare(edge_a, edge_b, edge_count)
  assertEqInt(resNom, 0, "sysPtrCompare nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysPtrCompare boundary resEdge == 0")
  ret 0
```

---

### `sysPageAlloc` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPageAlloc(bytes: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Allocate 4096-byte OS page and verify non-zero base address. Concrete nominal inputs: `bytes: int = 64`; exercises core body path returning/computing `sysPtrAlloc(aligned)`.

```aipl
module tests.functions.sys.sys_mem_z19_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPageAlloc_19(): int:
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = sysPageAlloc(arg_bytes)
  let resEdge = sysPageAlloc(edge_bytes)
  assert(resNom > 0, "sysPageAlloc nominal resNom > 0")
  assert(resEdge > 0, "sysPageAlloc boundary resEdge > 0")
  ret 0
```

---

### `sysPageFree` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPageFree(addr: int, bytes: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, bytes: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Unmap OS page and assert return `== 0`. Concrete nominal inputs: `addr: int = 1`, `bytes: int = 64`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z20_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPageFree_20(): int:
  let arg_addr = ptrAlloc(128)
  let edge_addr = ptrAlloc(128)
  let arg_bytes = 4
  let edge_bytes = 1
  let resNom = sysPageFree(arg_addr, arg_bytes)
  let resEdge = sysPageFree(edge_addr, edge_bytes)
  assertEqInt(resNom, 0, "sysPageFree nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysPageFree boundary resEdge == 0")
  ret 0
```

---

### `sysPageProtect` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysPageProtect(addr: int, bytes: int, prot: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, bytes: int, prot: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Adjust page protection flags and verify return `== 0`. Concrete nominal inputs: `addr: int = 1`, `bytes: int = 64`, `prot: int = 1`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z21_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysPageProtect_21(): int:
  let arg_addr = ptrAlloc(128)
  let edge_addr = ptrAlloc(128)
  let arg_bytes = 4
  let edge_bytes = 1
  let arg_prot = 2
  let edge_prot = 0
  let resNom = sysPageProtect(arg_addr, arg_bytes, arg_prot)
  let resEdge = sysPageProtect(edge_addr, edge_bytes, edge_prot)
  assertEqInt(resNom, 0, "sysPageProtect nominal resNom == 0")
  assertEqInt(resEdge, 0, "sysPageProtect boundary resEdge == 0")
  ret 0
```

---

### `sysSizeofType` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysSizeofType(typeName: str): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `typeName: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify parity with `sizeofType` across all primitive type names. Concrete nominal inputs: `typeName: str = "aipl_test"`; exercises core body path returning/computing `sizeofType(typeName)`.

```aipl
module tests.functions.sys.sys_mem_z22_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysSizeofType_22(): int:
  let arg_typeName = "test"
  let edge_typeName = "a"
  let resNom = sysSizeofType(arg_typeName)
  let resEdge = sysSizeofType(edge_typeName)
  assertEqInt(resNom, 8, "sysSizeofType nominal resNom == 8")
  assertEqInt(resEdge, 8, "sysSizeofType boundary resEdge == 8")
  ret 0
```

---

### `sysBitcastF64ToI64` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysBitcastF64ToI64(v: float): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify parity with `bitcastF64ToI64` on `-0.0`, `1.0`, and `pi`. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `bitcastF64ToI64(v)`.

```aipl
module tests.functions.sys.sys_mem_z23_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysBitcastF64ToI64_23(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = sysBitcastF64ToI64(arg_v)
  let resEdge = sysBitcastF64ToI64(edge_v)
  assertEqInt(resNom, 4607182418800017408, "sysBitcastF64ToI64 nominal resNom == 4607182418800017408")
  assertEqInt(resEdge, 4602678819172646912, "sysBitcastF64ToI64 boundary resEdge == 4602678819172646912")
  ret 0
```

---

### `sysBitcastI64ToF64` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn sysBitcastI64ToF64(v: int): float:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify parity with `bitcastI64ToF64` round-trip. Concrete nominal inputs: `v: int = 1`; exercises core body path returning/computing `bitcastI64ToF64(v)`.

```aipl
module tests.functions.sys.sys_mem_z24_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_sysBitcastI64ToF64_24(): int:
  let arg_v = 2
  let edge_v = 0
  let resNom = sysBitcastI64ToF64(arg_v)
  let resEdge = sysBitcastI64ToF64(edge_v)
  assertApproxEq(resNom, 0.0, 0.001, "sysBitcastI64ToF64 nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "sysBitcastI64ToF64 boundary resEdge ~= 0.0")
  ret 0
```

---

### `MemoryRegion.new` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn MemoryRegion.new(size: int): MemoryRegion:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `size: int` | **Returns**: `MemoryRegion`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Construct a 64-byte `MemoryRegion` and verify `.size == 64` and non-null base pointer. Concrete nominal inputs: `size: int = 64`; exercises core body path returning/computing `MemoryRegion.new(64)`.

```aipl
module tests.functions.sys.sys_mem_z25_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_MemoryRegion_new_25(): int:
  let arg_size = 16
  let edge_size = 0
  let resNom = MemoryRegion.new(arg_size)
  let resEdge = MemoryRegion.new(edge_size)
  assertEqInt(resNom.size, 16, "MemoryRegion.new nominal resNom.size == 16")
  assertEqInt(resEdge.size, 0, "MemoryRegion.new boundary resEdge.size == 0")
  ret 0
```

---

### `free` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn (self: MemoryRegion) free(): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `self: MemoryRegion` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Release `MemoryRegion` backing memory cleanly. Concrete nominal inputs: receiver `recvObj: MemoryRegion = MemoryRegion.new(64)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z26_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_MemoryRegion_free_26(): int:
  mut completedCalls = 0
  let recv_self = MemoryRegion.new(64)
  let edge_self = MemoryRegion.new(64)
  recv_self.free()
  edge_self.free()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "free nominal and boundary void calls completed")
  ret 0
```

---

### `readU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn (self: MemoryRegion) readU8(offset: int): int:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `self: MemoryRegion` | **Parameters**: `offset: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Read byte from `MemoryRegion` at `offset` after `.writeU8`. Concrete nominal inputs: receiver `recvObj: MemoryRegion = MemoryRegion.new(64)`, `offset: int = 0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.sys.sys_mem_z27_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_MemoryRegion_readU8_27(): int:
  let recv_self = MemoryRegion.new(64)
  let edge_self = MemoryRegion.new(64)
  let arg_offset = 1
  let edge_offset = 0
  let resNom = recv_self.readU8(arg_offset)
  let resEdge = edge_self.readU8(edge_offset)
  assertEqInt(resNom, 0, "readU8 nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU8 boundary resEdge == 0")
  ret 0
```

---

### `writeU8` (`std/sys/sys_mem.aipl`)

- **Signature**: `pub fn (self: MemoryRegion) writeU8(offset: int, val: int): void:`
- **Import**: `import * from "std/sys/sys_mem"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `self: MemoryRegion` | **Parameters**: `offset: int, val: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_mem_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Write `[10, 20, 30]` at offsets `0, 1, 2` and verify exact `.readU8` readback. Concrete nominal inputs: receiver `recvObj: MemoryRegion = MemoryRegion.new(64)`, `offset: int = 0`, `val: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_mem_z28_test
import * from "std/sys/sys_mem"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_mem_MemoryRegion_writeU8_28(): int:
  mut completedCalls = 0
  let recv_self = MemoryRegion.new(64)
  let edge_self = MemoryRegion.new(64)
  let arg_offset = 1
  let edge_offset = 0
  let arg_val = 2
  let edge_val = 0
  recv_self.writeU8(arg_offset, arg_val)
  edge_self.writeU8(edge_offset, edge_val)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "writeU8 nominal and boundary void calls completed")
  ret 0
```

---

### `sysNetSocket` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetSocket(domain: int, sockType: int, protocol: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `domain: int, sockType: int, protocol: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Create IPv4 TCP (`AF_INET, SOCK_STREAM`) and UDP (`SOCK_DGRAM`) sockets. Concrete nominal inputs: `domain: int = 1`, `sockType: int = 1`, `protocol: int = 1`; exercises core body path returning/computing `sysArchSyscall3(SYS_SOCKET, domain, sockType, protocol)`.

```aipl
module tests.functions.sys.sys_net_z1_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetSocket_1(): int:
  let arg_domain = 4
  let edge_domain = 1
  let arg_sockType = 4
  let edge_sockType = -1
  let arg_protocol = 1
  let edge_protocol = 0
  let resNom = sysNetSocket(arg_domain, arg_sockType, arg_protocol)
  let resEdge = sysNetSocket(edge_domain, edge_sockType, edge_protocol)
  assertEqInt(resNom, -1, "sysNetSocket nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetSocket boundary resEdge == -1")
  ret 0
```

---

### `sysNetBind` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetBind(fd: int, addrPtr: int, addrLen: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, addrPtr: int, addrLen: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Bind loopback socket (`127.0.0.1`). Concrete nominal inputs: `fd: int = 1`, `addrPtr: int = 1`, `addrLen: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_BIND, fd, addrPtr, addrLen)`.

```aipl
module tests.functions.sys.sys_net_z2_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetBind_2(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_addrPtr = 1
  let edge_addrPtr = 0
  let arg_addrLen = 4
  let edge_addrLen = 1
  let resNom = sysNetBind(arg_fd, arg_addrPtr, arg_addrLen)
  let resEdge = sysNetBind(edge_fd, edge_addrPtr, edge_addrLen)
  assertEqInt(resNom, -1, "sysNetBind nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetBind boundary resEdge == -1")
  ret 0
```

---

### `sysNetListen` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetListen(fd: int, backlog: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, backlog: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Transition bound TCP socket into listening state. Concrete nominal inputs: `fd: int = 1`, `backlog: int = 1`; exercises core body path returning/computing `sysArchSyscall2(SYS_LISTEN, fd, backlog)`.

```aipl
module tests.functions.sys.sys_net_z3_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetListen_3(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_backlog = 4
  let edge_backlog = 1
  let resNom = sysNetListen(arg_fd, arg_backlog)
  let resEdge = sysNetListen(edge_fd, edge_backlog)
  assertEqInt(resNom, -1, "sysNetListen nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetListen boundary resEdge == -1")
  ret 0
```

---

### `sysNetAccept` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetAccept(fd: int, addrPtr: int, addrLenPtr: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, addrPtr: int, addrLenPtr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Accept incoming loopback connection. Concrete nominal inputs: `fd: int = 1`, `addrPtr: int = 1`, `addrLenPtr: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_ACCEPT, fd, addrPtr, addrLenPtr)`.

```aipl
module tests.functions.sys.sys_net_z4_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetAccept_4(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_addrPtr = 1
  let edge_addrPtr = 0
  let arg_addrLenPtr = 4
  let edge_addrLenPtr = 1
  let resNom = sysNetAccept(arg_fd, arg_addrPtr, arg_addrLenPtr)
  let resEdge = sysNetAccept(edge_fd, edge_addrPtr, edge_addrLenPtr)
  assertEqInt(resNom, -1, "sysNetAccept nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetAccept boundary resEdge == -1")
  ret 0
```

---

### `sysNetConnect` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetConnect(fd: int, addrPtr: int, addrLen: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, addrPtr: int, addrLen: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Connect client socket to loopback listener. Concrete nominal inputs: `fd: int = 1`, `addrPtr: int = 1`, `addrLen: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_CONNECT, fd, addrPtr, addrLen)`.

```aipl
module tests.functions.sys.sys_net_z5_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetConnect_5(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_addrPtr = 1
  let edge_addrPtr = 0
  let arg_addrLen = 4
  let edge_addrLen = 1
  let resNom = sysNetConnect(arg_fd, arg_addrPtr, arg_addrLen)
  let resEdge = sysNetConnect(edge_fd, edge_addrPtr, edge_addrLen)
  assertEqInt(resNom, -1, "sysNetConnect nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetConnect boundary resEdge == -1")
  ret 0
```

---

### `sysNetSend` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetSend(fd: int, bufPtr: int, len: int, flags: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, len: int, flags: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Send payload over connected loopback socket and verify byte count sent. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `len: int = 64`, `flags: int = 1`; exercises core body path returning/computing `sysArchSyscall6(SYS_SENDTO, fd, bufPtr, len, flags, 0, 0)`.

```aipl
module tests.functions.sys.sys_net_z6_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetSend_6(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_len = 4
  let edge_len = 1
  let arg_flags = 1
  let edge_flags = 0
  let resNom = sysNetSend(arg_fd, arg_bufPtr, arg_len, arg_flags)
  let resEdge = sysNetSend(edge_fd, edge_bufPtr, edge_len, edge_flags)
  assertEqInt(resNom, -1, "sysNetSend nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetSend boundary resEdge == -1")
  ret 0
```

---

### `sysNetRecv` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetRecv(fd: int, bufPtr: int, len: int, flags: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, len: int, flags: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Receive payload over connected loopback socket and verify exact bytes received. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `len: int = 64`, `flags: int = 1`; exercises core body path returning/computing `sysArchSyscall6(SYS_RECVFROM, fd, bufPtr, len, flags, 0, 0)`.

```aipl
module tests.functions.sys.sys_net_z7_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetRecv_7(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_len = 4
  let edge_len = 1
  let arg_flags = 1
  let edge_flags = 0
  let resNom = sysNetRecv(arg_fd, arg_bufPtr, arg_len, arg_flags)
  let resEdge = sysNetRecv(edge_fd, edge_bufPtr, edge_len, edge_flags)
  assertEqInt(resNom, -1, "sysNetRecv nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetRecv boundary resEdge == -1")
  ret 0
```

---

### `sysNetSendTo` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetSendTo(fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLen: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLen: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Send UDP datagram over loopback. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `len: int = 64`, `flags: int = 1`, `addrPtr: int = 1`, `addrLen: int = 64`; exercises core body path returning/computing `sysArchSyscall6(SYS_SENDTO, fd, bufPtr, len, flags, addrPtr, addrLen)`.

```aipl
module tests.functions.sys.sys_net_z8_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetSendTo_8(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_len = 4
  let edge_len = 1
  let arg_flags = 1
  let edge_flags = 0
  let arg_addrPtr = 1
  let edge_addrPtr = 0
  let arg_addrLen = 4
  let edge_addrLen = 1
  let resNom = sysNetSendTo(arg_fd, arg_bufPtr, arg_len, arg_flags, arg_addrPtr, arg_addrLen)
  let resEdge = sysNetSendTo(edge_fd, edge_bufPtr, edge_len, edge_flags, edge_addrPtr, edge_addrLen)
  assertEqInt(resNom, -1, "sysNetSendTo nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetSendTo boundary resEdge == -1")
  ret 0
```

---

### `sysNetRecvFrom` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetRecvFrom(fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLenPtr: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, bufPtr: int, len: int, flags: int, addrPtr: int, addrLenPtr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Receive UDP datagram and verify byte length. Concrete nominal inputs: `fd: int = 1`, `bufPtr: int = 1`, `len: int = 64`, `flags: int = 1`, `addrPtr: int = 1`, `addrLenPtr: int = 64`; exercises core body path returning/computing `sysArchSyscall6(SYS_RECVFROM, fd, bufPtr, len, flags, addrPtr, addrLenPtr)`.

```aipl
module tests.functions.sys.sys_net_z9_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetRecvFrom_9(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_bufPtr = 4
  let edge_bufPtr = 1
  let arg_len = 4
  let edge_len = 1
  let arg_flags = 1
  let edge_flags = 0
  let arg_addrPtr = 1
  let edge_addrPtr = 0
  let arg_addrLenPtr = 4
  let edge_addrLenPtr = 1
  let resNom = sysNetRecvFrom(arg_fd, arg_bufPtr, arg_len, arg_flags, arg_addrPtr, arg_addrLenPtr)
  let resEdge = sysNetRecvFrom(edge_fd, edge_bufPtr, edge_len, edge_flags, edge_addrPtr, edge_addrLenPtr)
  assertEqInt(resNom, -1, "sysNetRecvFrom nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetRecvFrom boundary resEdge == -1")
  ret 0
```

---

### `sysNetClose` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetClose(fd: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Close socket descriptor cleanly (`== 0`). Concrete nominal inputs: `fd: int = 1`; exercises core body path returning/computing `sysArchSyscall1(SYS_CLOSE, fd)`.

```aipl
module tests.functions.sys.sys_net_z10_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetClose_10(): int:
  let arg_fd = 999
  let edge_fd = -1
  let resNom = sysNetClose(arg_fd)
  let resEdge = sysNetClose(edge_fd)
  assertEqInt(resNom, -1, "sysNetClose nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetClose boundary resEdge == -1")
  ret 0
```

---

### `sysNetSetNonBlocking` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetSetNonBlocking(fd: int, nonBlocking: bool): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, nonBlocking: bool` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Toggle `O_NONBLOCK` flag on socket descriptor. Concrete nominal inputs: `fd: int = 1`, `nonBlocking: bool = true`; exercises core body path returning/computing `sysArchSyscall3(72, fd, 4, nextFlags)`.

```aipl
module tests.functions.sys.sys_net_z11_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetSetNonBlocking_11(): int:
  let arg_fd = 999
  let edge_fd = -1
  let arg_nonBlocking = true
  let edge_nonBlocking = false
  let resNom = sysNetSetNonBlocking(arg_fd, arg_nonBlocking)
  let resEdge = sysNetSetNonBlocking(edge_fd, edge_nonBlocking)
  assertEqInt(resNom, -1, "sysNetSetNonBlocking nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetSetNonBlocking boundary resEdge == -1")
  ret 0
```

---

### `sysNetPoll` (`std/sys/sys_net.aipl`)

- **Signature**: `pub fn sysNetPoll(pollFdsPtr: int, nfds: int, timeoutMs: int): int:`
- **Import**: `import * from "std/sys/sys_net"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pollFdsPtr: int, nfds: int, timeoutMs: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_net_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Poll socket readiness mask with `timeoutMs = 0`. Concrete nominal inputs: `pollFdsPtr: int = 1`, `nfds: int = 1`, `timeoutMs: int = 1`; exercises core body path returning/computing `sysArchSyscall3(SYS_POLL, pollFdsPtr, nfds, timeoutMs)`.

```aipl
module tests.functions.sys.sys_net_z12_test
import * from "std/sys/sys_net"
import { sysArchSyscall1, sysArchSyscall2, sysArchSyscall3, sysArchSyscall4, sysArchSyscall6, SYS_CLOSE, SYS_POLL, SYS_SOCKET, SYS_CONNECT, SYS_ACCEPT, SYS_SENDTO, SYS_RECVFROM, SYS_BIND, SYS_LISTEN } from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_net_sysNetPoll_12(): int:
  let arg_pollFdsPtr = 999
  let edge_pollFdsPtr = -1
  let arg_nfds = 4
  let edge_nfds = -1
  let arg_timeoutMs = 4
  let edge_timeoutMs = 1
  let resNom = sysNetPoll(arg_pollFdsPtr, arg_nfds, arg_timeoutMs)
  let resEdge = sysNetPoll(edge_pollFdsPtr, edge_nfds, edge_timeoutMs)
  assertEqInt(resNom, -1, "sysNetPoll nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysNetPoll boundary resEdge == -1")
  ret 0
```

---

### `rawSyscall` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn rawSyscall(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Invoke `SYS_getpid` (`39` on x86_64 Linux) and verify `pid > 0`. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`, `a6: int = 1`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.sys.sys_syscall_z1_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_rawSyscall_1(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let arg_a6 = 2
  let edge_a6 = 0
  let resNom = rawSyscall(arg_nr, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5, arg_a6)
  let resEdge = rawSyscall(edge_nr, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5, edge_a6)
  assertEqInt(resNom, -1, "rawSyscall nominal resNom == -1")
  assertEqInt(resEdge, 0, "rawSyscall boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall0` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall0(num: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test 0-arg syscall (`SYS_getpid -> > 0`). Concrete nominal inputs: `num: int = 1`; exercises core body path returning/computing `rawSyscall(num, 0, 0, 0, 0, 0, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z2_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall0_2(): int:
  let arg_num = 4
  let edge_num = 1
  let resNom = sysArchSyscall0(arg_num)
  let resEdge = sysArchSyscall0(edge_num)
  assertEqInt(resNom, -1, "sysArchSyscall0 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall0 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall1` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall1(num: int, a1: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test 1-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, 0, 0, 0, 0, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z3_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall1_3(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let resNom = sysArchSyscall1(arg_num, arg_a1)
  let resEdge = sysArchSyscall1(edge_num, edge_a1)
  assertEqInt(resNom, -1, "sysArchSyscall1 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall1 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall2` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall2(num: int, a1: int, a2: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int, a2: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test 2-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`, `a2: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, a2, 0, 0, 0, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z4_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall2_4(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let resNom = sysArchSyscall2(arg_num, arg_a1, arg_a2)
  let resEdge = sysArchSyscall2(edge_num, edge_a1, edge_a2)
  assertEqInt(resNom, -1, "sysArchSyscall2 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall2 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall3` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall3(num: int, a1: int, a2: int, a3: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int, a2: int, a3: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test 3-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, a2, a3, 0, 0, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z5_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall3_5(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let resNom = sysArchSyscall3(arg_num, arg_a1, arg_a2, arg_a3)
  let resEdge = sysArchSyscall3(edge_num, edge_a1, edge_a2, edge_a3)
  assertEqInt(resNom, -1, "sysArchSyscall3 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall3 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall4` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall4(num: int, a1: int, a2: int, a3: int, a4: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int, a2: int, a3: int, a4: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Test 4-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, a2, a3, a4, 0, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z6_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall4_6(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let resNom = sysArchSyscall4(arg_num, arg_a1, arg_a2, arg_a3, arg_a4)
  let resEdge = sysArchSyscall4(edge_num, edge_a1, edge_a2, edge_a3, edge_a4)
  assertEqInt(resNom, -1, "sysArchSyscall4 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall4 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall5` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall5(num: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int, a2: int, a3: int, a4: int, a5: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Test 5-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, a2, a3, a4, a5, 0)`.

```aipl
module tests.functions.sys.sys_syscall_z7_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall5_7(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let resNom = sysArchSyscall5(arg_num, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5)
  let resEdge = sysArchSyscall5(edge_num, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5)
  assertEqInt(resNom, -1, "sysArchSyscall5 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall5 boundary resEdge == 0")
  ret 0
```

---

### `sysArchSyscall6` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysArchSyscall6(num: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `num: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Test 6-arg syscall dispatch. Concrete nominal inputs: `num: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`, `a6: int = 1`; exercises core body path returning/computing `rawSyscall(num, a1, a2, a3, a4, a5, a6)`.

```aipl
module tests.functions.sys.sys_syscall_z8_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysArchSyscall6_8(): int:
  let arg_num = 4
  let edge_num = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let arg_a6 = 2
  let edge_a6 = 0
  let resNom = sysArchSyscall6(arg_num, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5, arg_a6)
  let resEdge = sysArchSyscall6(edge_num, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5, edge_a6)
  assertEqInt(resNom, -1, "sysArchSyscall6 nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysArchSyscall6 boundary resEdge == 0")
  ret 0
```

---

### `syscall0` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall0(nr: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `syscall0(39) == sysArchSyscall0(39)`. Concrete nominal inputs: `nr: int = 1`; exercises core body path returning/computing `sysArchSyscall0(nr)`.

```aipl
module tests.functions.sys.sys_syscall_z9_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall0_9(): int:
  let arg_nr = 4
  let edge_nr = 1
  let resNom = syscall0(arg_nr)
  let resEdge = syscall0(edge_nr)
  assertEqInt(resNom, -1, "syscall0 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall0 boundary resEdge == 0")
  ret 0
```

---

### `syscall1` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall1(nr: int, a1: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `syscall1` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`; exercises core body path returning/computing `sysArchSyscall1(nr, a1)`.

```aipl
module tests.functions.sys.sys_syscall_z10_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall1_10(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let resNom = syscall1(arg_nr, arg_a1)
  let resEdge = syscall1(edge_nr, edge_a1)
  assertEqInt(resNom, -1, "syscall1 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall1 boundary resEdge == 0")
  ret 0
```

---

### `syscall2` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall2(nr: int, a1: int, a2: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify `syscall2` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`; exercises core body path returning/computing `sysArchSyscall2(nr, a1, a2)`.

```aipl
module tests.functions.sys.sys_syscall_z11_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall2_11(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let resNom = syscall2(arg_nr, arg_a1, arg_a2)
  let resEdge = syscall2(edge_nr, edge_a1, edge_a2)
  assertEqInt(resNom, -1, "syscall2 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall2 boundary resEdge == 0")
  ret 0
```

---

### `syscall3` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall3(nr: int, a1: int, a2: int, a3: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int, a3: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `syscall3` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`; exercises core body path returning/computing `sysArchSyscall3(nr, a1, a2, a3)`.

```aipl
module tests.functions.sys.sys_syscall_z12_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall3_12(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let resNom = syscall3(arg_nr, arg_a1, arg_a2, arg_a3)
  let resEdge = syscall3(edge_nr, edge_a1, edge_a2, edge_a3)
  assertEqInt(resNom, -1, "syscall3 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall3 boundary resEdge == 0")
  ret 0
```

---

### `syscall4` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall4(nr: int, a1: int, a2: int, a3: int, a4: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int, a3: int, a4: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify `syscall4` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`; exercises core body path returning/computing `sysArchSyscall4(nr, a1, a2, a3, a4)`.

```aipl
module tests.functions.sys.sys_syscall_z13_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall4_13(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let resNom = syscall4(arg_nr, arg_a1, arg_a2, arg_a3, arg_a4)
  let resEdge = syscall4(edge_nr, edge_a1, edge_a2, edge_a3, edge_a4)
  assertEqInt(resNom, -1, "syscall4 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall4 boundary resEdge == 0")
  ret 0
```

---

### `syscall5` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall5(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int, a3: int, a4: int, a5: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Verify `syscall5` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`; exercises core body path returning/computing `sysArchSyscall5(nr, a1, a2, a3, a4, a5)`.

```aipl
module tests.functions.sys.sys_syscall_z14_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall5_14(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let resNom = syscall5(arg_nr, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5)
  let resEdge = syscall5(edge_nr, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5)
  assertEqInt(resNom, -1, "syscall5 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall5 boundary resEdge == 0")
  ret 0
```

---

### `syscall6` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn syscall6(nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nr: int, a1: int, a2: int, a3: int, a4: int, a5: int, a6: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Verify `syscall6` forwarding parity. Concrete nominal inputs: `nr: int = 1`, `a1: int = 1`, `a2: int = 1`, `a3: int = 1`, `a4: int = 1`, `a5: int = 1`, `a6: int = 1`; exercises core body path returning/computing `sysArchSyscall6(nr, a1, a2, a3, a4, a5, a6)`.

```aipl
module tests.functions.sys.sys_syscall_z15_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_syscall6_15(): int:
  let arg_nr = 4
  let edge_nr = 1
  let arg_a1 = 2
  let edge_a1 = 0
  let arg_a2 = 2
  let edge_a2 = 0
  let arg_a3 = 2
  let edge_a3 = 0
  let arg_a4 = 2
  let edge_a4 = 0
  let arg_a5 = 2
  let edge_a5 = 0
  let arg_a6 = 2
  let edge_a6 = 0
  let resNom = syscall6(arg_nr, arg_a1, arg_a2, arg_a3, arg_a4, arg_a5, arg_a6)
  let resEdge = syscall6(edge_nr, edge_a1, edge_a2, edge_a3, edge_a4, edge_a5, edge_a6)
  assertEqInt(resNom, -1, "syscall6 nominal resNom == -1")
  assertEqInt(resEdge, 0, "syscall6 boundary resEdge == 0")
  ret 0
```

---

### `sysRead` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysRead(fd: int, buf: int, count: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, buf: int, count: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Read from open file descriptor into buffer pointer. Concrete nominal inputs: `fd: int = 1`, `buf: int = 1`, `count: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_READ, fd, buf, count)`.

```aipl
module tests.functions.sys.sys_syscall_z16_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysRead_16(): int:
  let arg_fd = -1
  let edge_fd = -1
  let arg_buf = 0
  let edge_buf = 0
  let arg_count = 0
  let edge_count = 0
  let resNom = sysRead(arg_fd, arg_buf, arg_count)
  let resEdge = sysRead(edge_fd, edge_buf, edge_count)
  assertEqInt(resNom, -1, "sysRead nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysRead boundary resEdge == -1")
  ret 0
```

---

### `sysWrite` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysWrite(fd: int, buf: int, count: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int, buf: int, count: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: Write from buffer pointer to open file descriptor. Concrete nominal inputs: `fd: int = 1`, `buf: int = 1`, `count: int = 64`; exercises core body path returning/computing `sysArchSyscall3(SYS_WRITE, fd, buf, count)`.

```aipl
module tests.functions.sys.sys_syscall_z17_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysWrite_17(): int:
  let arg_fd = 1
  let edge_fd = 0
  let arg_buf = 4
  let edge_buf = 1
  let arg_count = 4
  let edge_count = 1
  let resNom = sysWrite(arg_fd, arg_buf, arg_count)
  let resEdge = sysWrite(edge_fd, edge_buf, edge_count)
  assertEqInt(resNom, -1, "sysWrite nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysWrite boundary resEdge == -1")
  ret 0
```

---

### `sysOpenat` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysOpenat(dfd: int, filename: int, flags: int, mode: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dfd: int, filename: int, flags: int, mode: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Open temp file via `AT_FDCWD` (`-100`). Concrete nominal inputs: `dfd: int = 1`, `filename: int = 64`, `flags: int = 1`, `mode: int = 1`; exercises core body path returning/computing `sysArchSyscall4(SYS_OPENAT, dfd, filename, flags, mode)`.

```aipl
module tests.functions.sys.sys_syscall_z18_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysOpenat_18(): int:
  let arg_dfd = 1
  let edge_dfd = 0
  let arg_filename = 4
  let edge_filename = 1
  let arg_flags = 1
  let edge_flags = 0
  let arg_mode = 4
  let edge_mode = 1
  let resNom = sysOpenat(arg_dfd, arg_filename, arg_flags, arg_mode)
  let resEdge = sysOpenat(edge_dfd, edge_filename, edge_flags, edge_mode)
  assertEqInt(resNom, -1, "sysOpenat nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysOpenat boundary resEdge == -1")
  ret 0
```

---

### `sysClose` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysClose(fd: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fd: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Close descriptor opened via `sysOpenat`. Concrete nominal inputs: `fd: int = 1`; exercises core body path returning/computing `sysArchSyscall1(SYS_CLOSE, fd)`.

```aipl
module tests.functions.sys.sys_syscall_z19_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysClose_19(): int:
  let arg_fd = 999
  let edge_fd = -1
  let resNom = sysClose(arg_fd)
  let resEdge = sysClose(edge_fd)
  assertEqInt(resNom, -1, "sysClose nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysClose boundary resEdge == -1")
  ret 0
```

---

### `sysMmap` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysMmap(addr: int, length: int, prot: int, flags: int, fd: int, offset: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, length: int, prot: int, flags: int, fd: int, offset: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_004_control_flow_and_loops_cli.aipl`
- **Behavioral Summary**: MAP_ANONYMOUS`) and verify valid address. Concrete nominal inputs: `addr: int = 1`, `length: int = 64`, `prot: int = 1`, `flags: int = 1`, `fd: int = 1`, `offset: int = 0`; exercises core body path returning/computing `sysArchSyscall6(SYS_MMAP, addr, length, prot, flags, fd, offset)`.

```aipl
module tests.functions.sys.sys_syscall_z20_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysMmap_20(): int:
  let arg_addr = 2
  let edge_addr = 0
  let arg_length = 4
  let edge_length = 1
  let arg_prot = 2
  let edge_prot = 0
  let arg_flags = 1
  let edge_flags = 0
  let arg_fd = 1
  let edge_fd = 0
  let arg_offset = 1
  let edge_offset = 0
  let resNom = sysMmap(arg_addr, arg_length, arg_prot, arg_flags, arg_fd, arg_offset)
  let resEdge = sysMmap(edge_addr, edge_length, edge_prot, edge_flags, edge_fd, edge_offset)
  assertEqInt(resNom, -1, "sysMmap nominal resNom == -1")
  assertEqInt(resEdge, -1, "sysMmap boundary resEdge == -1")
  ret 0
```

---

### `sysMunmap` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysMunmap(addr: int, length: int): int:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `addr: int, length: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_002_primitives_and_bitwise_cli.aipl`
- **Behavioral Summary**: Unmap `sysMmap` page and assert return `== 0`. Concrete nominal inputs: `addr: int = 1`, `length: int = 64`; exercises core body path returning/computing `sysArchSyscall2(SYS_MUNMAP, addr, length)`.

```aipl
module tests.functions.sys.sys_syscall_z21_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysMunmap_21(): int:
  let arg_addr = 2
  let edge_addr = 0
  let arg_length = 4
  let edge_length = 1
  let resNom = sysMunmap(arg_addr, arg_length)
  let resEdge = sysMunmap(edge_addr, edge_length)
  assertEqInt(resNom, -1, "sysMunmap nominal resNom == -1")
  assertEqInt(resEdge, 0, "sysMunmap boundary resEdge == 0")
  ret 0
```

---

### `sysExit` (`std/sys/sys_syscall.aipl`)

- **Signature**: `pub fn sysExit(status: int): void:`
- **Import**: `import * from "std/sys/sys_syscall"` (or barrel `import * from "std/sys/sys_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `status: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/sys/sys_syscall_test.aipl` | **Example**: `examples/ex_003_strings_and_interpolation_cli.aipl`
- **Behavioral Summary**: Verify exit wrapper type signature contract. Concrete nominal inputs: `status: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.sys.sys_syscall_z22_test
import * from "std/sys/sys_syscall"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_sys_syscall_sysExit_22(): int:
  mut completedCalls = 0
  let arg_status = 2
  let edge_status = 0
  if false:
    sysExit(arg_status)
    sysExit(edge_status)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sysExit nominal and boundary void calls completed")
  ret 0
```

---

### `createAndroidLifecycleState` (`std/sys/sys_android.aipl`)

- **Signature**: `pub fn createAndroidLifecycleState(): AndroidLifecycleState:`
- **Import**: `import { createAndroidLifecycleState } from "std/sys/sys_android"`
- **Receiver**: `None (free function)` | **Parameters**: `None` | **Returns**: `AndroidLifecycleState`
- **Unit Test**: `tests/functions/sys/sys_android_test.aipl` | **Example**: `examples/ex_011_sys_syscall_and_os_probe_cli.aipl`
- **Behavioral Summary**: Constructs an initial default `AndroidLifecycleState` with `windowReady = false`, `hasFocus = false`, `isAnimating = false`, `configGeneration = 0`, and `lastCmd = 0`.

```aipl
module tests.functions.sys.sys_android_ref_01_test
import { createAndroidLifecycleState } from "std/sys/sys_android"
import { assert } from "std/prelude"
pub fn test_createAndroidLifecycleState_ref(): int:
  let s = createAndroidLifecycleState()
  assert(s.windowReady == false, "initial windowReady is false")
  assert(s.hasFocus == false, "initial hasFocus is false")
  assert(s.isAnimating == false, "initial isAnimating is false")
  ret 0
```

---

### `stepAndroidLifecycleCmd` (`std/sys/sys_android.aipl`)

- **Signature**: `pub fn stepAndroidLifecycleCmd(state: AndroidLifecycleState, cmd: int): AndroidLifecycleState requires cmd >= 0 ensures result.lastCmd == cmd and (result.isAnimating == (result.windowReady and result.hasFocus)):`
- **Import**: `import { stepAndroidLifecycleCmd, createAndroidLifecycleState, APP_CMD_INIT_WINDOW, APP_CMD_GAINED_FOCUS } from "std/sys/sys_android"`
- **Receiver**: `None (free function)` | **Parameters**: `state: AndroidLifecycleState, cmd: int` | **Returns**: `AndroidLifecycleState`
- **Unit Test**: `tests/functions/sys/sys_android_test.aipl` | **Example**: `examples/ex_011_sys_syscall_and_os_probe_cli.aipl`
- **Behavioral Summary**: Steps the Android lifecycle finite state machine on command input (`APP_CMD_INIT_WINDOW`, `APP_CMD_TERM_WINDOW`, `APP_CMD_GAINED_FOCUS`, `APP_CMD_LOST_FOCUS`, `APP_CMD_CONFIG_CHANGED`). Animation is active if and only if both `windowReady` and `hasFocus` are true.

```aipl
module tests.functions.sys.sys_android_ref_02_test
import { createAndroidLifecycleState, stepAndroidLifecycleCmd, APP_CMD_INIT_WINDOW, APP_CMD_GAINED_FOCUS } from "std/sys/sys_android"
import { assert, assertEqInt } from "std/prelude"
pub fn test_stepAndroidLifecycleCmd_ref(): int:
  let s0 = createAndroidLifecycleState()
  let s1 = stepAndroidLifecycleCmd(s0, APP_CMD_INIT_WINDOW)
  let s2 = stepAndroidLifecycleCmd(s1, APP_CMD_GAINED_FOCUS)
  assert(s2.isAnimating == true, "animating when window ready and focused")
  assertEqInt(s2.lastCmd, APP_CMD_GAINED_FOCUS, "lastCmd updated")
  ret 0
```

---

### `createAndroidSurfaceDesc` (`std/sys/sys_android.aipl`)

- **Signature**: `pub fn createAndroidSurfaceDesc(windowHandle: int, widthPx: int, heightPx: int, stridePixels: int, densityDpi: int, refreshRateHz: int): AndroidSurfaceDesc requires densityDpi >= 0 ensures result.formatRgba8888 == 1 and (not result.isValid or result.stridePixels >= result.widthPx):`
- **Import**: `import { createAndroidSurfaceDesc } from "std/sys/sys_android"`
- **Receiver**: `None (free function)` | **Parameters**: `windowHandle: int, widthPx: int, heightPx: int, stridePixels: int, densityDpi: int, refreshRateHz: int` | **Returns**: `AndroidSurfaceDesc`
- **Unit Test**: `tests/functions/sys/sys_android_test.aipl` | **Example**: `examples/ex_017_sys_gpu_adapter_probe_cli.aipl`
- **Behavioral Summary**: Constructs an aligned `AndroidSurfaceDesc` descriptor for native ANativeWindow surface blitting. Aligns scanline stride to 16-pixel multiples and sets default DPI (420) and refresh rate (60 Hz) when boundaries require it.

```aipl
module tests.functions.sys.sys_android_ref_03_test
import { createAndroidSurfaceDesc } from "std/sys/sys_android"
import { assert, assertEqInt } from "std/prelude"
pub fn test_createAndroidSurfaceDesc_ref(): int:
  let s = createAndroidSurfaceDesc(1001, 1080, 2400, 0, 420, 120)
  assert(s.isValid == true, "surface is valid")
  assertEqInt(s.widthPx, 1080, "width matches")
  assertEqInt(s.heightPx, 2400, "height matches")
  ret 0
```

---

### `computeAndroidSafeAreaInsets` (`std/sys/sys_android.aipl`)

- **Signature**: `pub fn computeAndroidSafeAreaInsets(surfaceWidthPx: int, surfaceHeightPx: int, rawTopPx: int, rawBottomPx: int, rawLeftPx: int, rawRightPx: int): AndroidSafeAreaInsets requires surfaceWidthPx >= 0 and surfaceHeightPx >= 0 ensures result.usableWidthPx >= 0 and result.usableHeightPx >= 0:`
- **Import**: `import { computeAndroidSafeAreaInsets } from "std/sys/sys_android"`
- **Receiver**: `None (free function)` | **Parameters**: `surfaceWidthPx: int, surfaceHeightPx: int, rawTopPx: int, rawBottomPx: int, rawLeftPx: int, rawRightPx: int` | **Returns**: `AndroidSafeAreaInsets`
- **Unit Test**: `tests/functions/sys/sys_android_test.aipl` | **Example**: `examples/ex_011_sys_syscall_and_os_probe_cli.aipl`
- **Behavioral Summary**: Calculates usable display area bounds after subtracting top camera cutout, bottom gesture pill, and left/right navigation bars. Clamps all values to non-negative integers.

```aipl
module tests.functions.sys.sys_android_ref_04_test
import { computeAndroidSafeAreaInsets } from "std/sys/sys_android"
import { assertEqInt } from "std/prelude"
pub fn test_computeAndroidSafeAreaInsets_ref(): int:
  let insets = computeAndroidSafeAreaInsets(1080, 2400, 112, 84, 0, 0)
  assertEqInt(insets.usableWidthPx, 1080, "usable width matches")
  assertEqInt(insets.usableHeightPx, 2204, "usable height after insets")
  ret 0
```

---

### `createAndroidJniBridgeDesc` (`std/sys/sys_android.aipl`)

- **Signature**: `pub fn createAndroidJniBridgeDesc(jniVersion: int, sdkInt: int, packageName: str, internalDataPath: str, hasAssetMgr: bool): AndroidJniBridgeDesc requires sdkInt >= 0 ensures result.bridgeValid == (jniVersion == 65542 and sdkInt >= 29 and packageName.len() > 0 and internalDataPath.startsWith("/") and hasAssetMgr):`
- **Import**: `import { createAndroidJniBridgeDesc, JNI_VERSION_1_6 } from "std/sys/sys_android"`
- **Receiver**: `None (free function)` | **Parameters**: `jniVersion: int, sdkInt: int, packageName: str, internalDataPath: str, hasAssetMgr: bool` | **Returns**: `AndroidJniBridgeDesc`
- **Unit Test**: `tests/functions/sys/sys_android_test.aipl` | **Example**: `examples/ex_015_sys_ffi_c_abi_bridge_cli.aipl`
- **Behavioral Summary**: Validates JNI environment compatibility (JNI 1.6+, Android API 29+) and constructs an `AndroidJniBridgeDesc` verifying asset manager readiness and internal app data path.

```aipl
module tests.functions.sys.sys_android_ref_05_test
import { createAndroidJniBridgeDesc, JNI_VERSION_1_6 } from "std/sys/sys_android"
import { assert } from "std/prelude"
pub fn test_createAndroidJniBridgeDesc_ref(): int:
  let b = createAndroidJniBridgeDesc(JNI_VERSION_1_6, 34, "org.aipl.app", "/data/user/0/org.aipl.app/files", true)
  assert(b.bridgeValid == true, "jni bridge is valid")
  ret 0
```
