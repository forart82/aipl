[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 24: `audio` API Reference

> Complete API reference manual for AIPL standard library domain `audio` (159 callable functions & methods across ["std/audio/audio_codec.aipl", "std/audio/audio_device.aipl", "std/audio/audio_dsp.aipl", "std/audio/audio_mixer.aipl", "std/audio/audio_mod.aipl", "std/audio/audio_spatial.aipl", "std/audio/audio_synth.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `audio`
- **Target Source Modules**: ["std/audio/audio_codec.aipl", "std/audio/audio_device.aipl", "std/audio/audio_dsp.aipl", "std/audio/audio_mixer.aipl", "std/audio/audio_mod.aipl", "std/audio/audio_spatial.aipl", "std/audio/audio_synth.aipl"]
- **Total Callable Functions & Methods**: 159
- **Total Data Types (`struct` & `enum`)**: 25
- **Multi-Backend Hardware Audio & Polyphonic Synthesizer (`runtime/rt_gui_audio.c`, `runtime/rt_sys.c`, `std/audio/audio_device.aipl`)**:
  - Dynamically connects to `libpulse-simple.so.0` (PulseAudio), falling back automatically to `libasound.so.2` (ALSA `snd_pcm_open` / `snd_pcm_writei`) and `libSDL2-2.0.so.0` (`SDL_OpenAudioDevice` / `SDL_QueueAudio`), with deterministic headless/WAV capture via `AIPL_AUDIO_WAV_PATH`.
  - Bridges `playTone`, `playToneEx`, `playNote`, `playChord`, `playSound`, `playSoundEx`, `playPcmBuffer`, `writeAudioPcmInterleaved`, `setMasterVolume`, and `stopAllSounds` directly to the 32-voice C runtime mixer with exponential anti-click ADSR envelopes, 1-pole low-pass warmth filtering, 9 timbres (`sine`, `square`, `saw`, `triangle`, `warm_pad`, `fm_epiano`, `bell`, `pluck`, `synth_lead`), stereo chorus, and soft `tanh` master limiting (`examples/ex_256_audio_polyphonic_synthwave_sequencer_window.aipl`..`examples/ex_258_audio_interactive_fm_piano_and_chords_window.aipl`).
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(25 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `PcmAudioBuffer` | `pub struct` | `std/audio/audio_codec.aipl` | `sampleRate: int`, `channels: int`, `totalFrames: int`, `samples: [float]` | `PcmAudioBuffer(sampleRate, channels, totalFrames, samples)` |
| `WavHeader` | `pub struct` | `std/audio/audio_codec.aipl` | `audioFormat: int`, `numChannels: int`, `sampleRate: int`, `byteRate: int`, `blockAlign: int`, `bitsPerSample: int`, `dataSize: int` | `WavHeader(audioFormat, numChannels, sampleRate, byteRate, blockAlign, bitsPerSample, dataSize)` |
| `AudioDeviceConfig` | `pub struct` | `std/audio/audio_device.aipl` | `sampleRate: int`, `bufferSizeFrames: int`, `channels: int`, `bitDepth: int` | `AudioDeviceConfig(sampleRate, bufferSizeFrames, channels, bitDepth)` |
| `AudioDevice` | `pub struct` | `std/audio/audio_device.aipl` | `config: AudioDeviceConfig`, `isRunning: bool`, `deviceHandle: int`, `underrunCount: int` | `AudioDevice(config, isRunning, deviceHandle, underrunCount)` |
| `AudioEngine` | `pub struct` | `std/audio/audio_device.aipl` | `activeVoices: int`, `nextVoiceId: int`, `masterVolume: float`, `energy: float` | `AudioEngine(activeVoices, nextVoiceId, masterVolume, energy)` |
| `AudioMockSink` | `pub struct` | `std/audio/audio_device.aipl` | `toneCount: int`, `lastFrequency: float`, `lastDuration: float`, `lastWaveform: str` | `AudioMockSink(toneCount, lastFrequency, lastDuration, lastWaveform)` |
| `BiquadFilter` | `pub struct` | `std/audio/audio_dsp.aipl` | `filterType: int`, `b0: float`, `b1: float`, `b2: float`, `a1: float`, `a2: float`, `x1: float`, `x2: float`, `y1: float`, `y2: float` | `BiquadFilter(filterType, b0, b1, b2, a1, a2, x1, x2, y1, y2)` |
| `SchroederReverb` | `pub struct` | `std/audio/audio_dsp.aipl` | `combDelays: [int]`, `allpassDelays: [int]`, `combBuffers: [[float]]`, `allpassBuffers: [[float]]`, `feedback: float`, `wetDry: float` | `SchroederReverb(combDelays, allpassDelays, combBuffers, allpassBuffers, feedback, wetDry)` |
| `CompressorConfig` | `pub struct` | `std/audio/audio_dsp.aipl` | `thresholdDb: float`, `ratio: float`, `attackMs: float`, `releaseMs: float`, `makeupGainDb: float` | `CompressorConfig(thresholdDb, ratio, attackMs, releaseMs, makeupGainDb)` |
| `CytomicSvf` | `pub struct` | `std/audio/audio_dsp.aipl` | `ic1eq: float`, `ic2eq: float`, `a1: float`, `a2: float`, `a3: float`, `k: float` | `CytomicSvf(ic1eq, ic2eq, a1, a2, a3, k)` |
| `AudioBus` | `pub struct` | `std/audio/audio_mixer.aipl` | `id: int`, `name: str`, `volume: float`, `mute: bool`, `parentBusId: int`, `duckingFactor: float`, `peakLevelLeft: float`, `peakLevelRight: float` | `AudioBus(id, name, volume, mute, parentBusId, duckingFactor, peakLevelLeft, peakLevelRight)` |
| `AudioVoice` | `pub struct` | `std/audio/audio_mixer.aipl` | `id: int`, `bufferId: int`, `busId: int`, `playbackPositionSamples: int`, `totalSamples: int`, `pitch: float`, `volume: float`, `isLooping: bool`, `isPlaying: bool` | `AudioVoice(id, bufferId, busId, playbackPositionSamples, totalSamples, pitch, volume, isLooping, isPlaying)` |
| `AudioMixer` | `pub struct` | `std/audio/audio_mixer.aipl` | `buses: [AudioBus]`, `voices: [AudioVoice]`, `maxVoices: int`, `masterVolume: float` | `AudioMixer(buses, voices, maxVoices, masterVolume)` |
| `StepSequencer` | `pub struct` | `std/audio/audio_mixer.aipl` | `bpm: float`, `stepIndex: int`, `accumMs: float`, `pattern: [int]`, `noteRatio: float`, `playing: bool` | `StepSequencer(bpm, stepIndex, accumMs, pattern, noteRatio, playing)` |
| `AudioListener3D` | `pub struct` | `std/audio/audio_spatial.aipl` | `x: float`, `y: float`, `z: float`, `forwardX: float`, `forwardY: float`, `forwardZ: float`, `upX: float`, `upY: float`, `upZ: float`, `velX: float = 0.0`, `velY: float = 0.0`, `velZ: float = 0.0`, `vx: float = 0.0`, `vy: float = 0.0`, `vz: float = 0.0`, `rightX: float = 1.0`, `rightY: float = 0.0`, `rightZ: float = 0.0` | `AudioListener3D(x, y, z, forwardX, forwardY, forwardZ, upX, upY, upZ, velX, velY, velZ, vx, vy, vz, rightX, rightY, rightZ)` |
| `SoundEmitter3D` | `pub struct` | `std/audio/audio_spatial.aipl` | `x: float`, `y: float`, `z: float`, `vx: float`, `vy: float`, `vz: float`, `baseFreqHz: float`, `maxRadius: float`, `baseGain: float` | `SoundEmitter3D(x, y, z, vx, vy, vz, baseFreqHz, maxRadius, baseGain)` |
| `AudioEmitter3D` | `pub struct` | `std/audio/audio_spatial.aipl` | `x: float`, `y: float`, `z: float`, `velX: float`, `velY: float`, `velZ: float`, `minDistance: float`, `maxDistance: float`, `rolloffFactor: float`, `coneInnerAngleDeg: float`, `coneOuterAngleDeg: float`, `coneOuterGain: float` | `AudioEmitter3D(x, y, z, velX, velY, velZ, minDistance, maxDistance, rolloffFactor, coneInnerAngleDeg, coneOuterAngleDeg, coneOuterGain)` |
| `SpatialGain` | `pub struct` | `std/audio/audio_spatial.aipl` | `gainLeft: float`, `gainRight: float`, `dopplerPitchShift: float` | `SpatialGain(gainLeft, gainRight, dopplerPitchShift)` |
| `AdsrEnvelope` | `pub struct` | `std/audio/audio_synth.aipl` | `attackSec: float`, `decaySec: float`, `sustainLevel: float`, `releaseSec: float`, `antiClickRampSec: float` | `AdsrEnvelope(attackSec, decaySec, sustainLevel, releaseSec, antiClickRampSec)` |
| `FmOperator` | `pub struct` | `std/audio/audio_synth.aipl` | `ratio: float`, `modulationIndex: float`, `phase: float`, `detuneHz: float` | `FmOperator(ratio, modulationIndex, phase, detuneHz)` |
| `PinkNoiseState` | `pub struct` | `std/audio/audio_synth.aipl` | `seed: int`, `b0: float`, `b1: float`, `b2: float`, `b3: float`, `b4: float`, `b5: float`, `b6: float`, `brownLast: float` | `PinkNoiseState(seed, b0, b1, b2, b3, b4, b5, b6, brownLast)` |
| `AhdsrEnvelope` | `pub struct` | `std/audio/audio_synth.aipl` | `attackSec: float`, `holdSec: float`, `decaySec: float`, `sustainLevel: float`, `releaseSec: float`, `curvePower: float` | `AhdsrEnvelope(attackSec, holdSec, decaySec, sustainLevel, releaseSec, curvePower)` |
| `FmOperatorPatch` | `pub struct` | `std/audio/audio_synth.aipl` | `ratio: float`, `modIndex: float`, `feedback: float`, `attackSec: float`, `decaySec: float`, `sustainLevel: float`, `releaseSec: float` | `FmOperatorPatch(ratio, modIndex, feedback, attackSec, decaySec, sustainLevel, releaseSec)` |
| `Fm4OpPatch` | `pub struct` | `std/audio/audio_synth.aipl` | `algorithm: int`, `op1: FmOperatorPatch`, `op2: FmOperatorPatch`, `op3: FmOperatorPatch`, `op4: FmOperatorPatch` | `Fm4OpPatch(algorithm, op1, op2, op3, op4)` |
| `SfxPatch` | `pub struct` | `std/audio/audio_synth.aipl` | `waveform: str`, `volume: float`, `baseFreqHz: float`, `freqLimitHz: float`, `freqSlide: float`, `freqDeltaSlide: float`, `attackSec: float`, `holdSec: float`, `decaySec: float`, `sustainLevel: float`, `vibratoDepth: float`, `vibratoSpeedHz: float`, `arpModMult: float`, `arpSpeedSec: float`, `dutyCycle: float`, `dutySweep: float`, `phaserOffset: float`, `lpfCutoffHz: float`, `hpfCutoffHz: float`, `bitCrushBits: int` | `SfxPatch(waveform, volume, baseFreqHz, freqLimitHz, freqSlide, freqDeltaSlide, attackSec, holdSec, decaySec, sustainLevel, vibratoDepth, vibratoSpeedHz, arpModMult, arpSpeedSec, dutyCycle, dutySweep, phaserOffset, lpfCutoffHz, hpfCutoffHz, bitCrushBits)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/audio/audio_codec.aipl` | `readU16LEWav` | `fn readU16LEWav(b: [int], off: int): int:` | `tests/functions/audio/audio_codec_test.aipl` |
| `2` | `std/audio/audio_codec.aipl` | `readI16LEWav` | `fn readI16LEWav(b: [int], off: int): int:` | `tests/functions/audio/audio_codec_test.aipl` |
| `3` | `std/audio/audio_codec.aipl` | `readU32LEWav` | `fn readU32LEWav(b: [int], off: int): int:` | `tests/functions/audio/audio_codec_test.aipl` |
| `4` | `std/audio/audio_codec.aipl` | `pushU16LEWav` | `fn pushU16LEWav(mut out: [int], val: int): [int]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `5` | `std/audio/audio_codec.aipl` | `pushU32LEWav` | `fn pushU32LEWav(mut out: [int], val: int): [int]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `6` | `std/audio/audio_codec.aipl` | `decodeWav` | `pub fn decodeWav(bytes: [int]): Option[PcmAudioBuffer]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `7` | `std/audio/audio_codec.aipl` | `encodeWav` | `pub fn encodeWav(buffer: PcmAudioBuffer): [int]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `8` | `std/audio/audio_codec.aipl` | `resamplePcmLinear` | `pub fn resamplePcmLinear(buffer: PcmAudioBuffer, targetSampleRate: int): PcmAudioBuffer:` | `tests/functions/audio/audio_codec_test.aipl` |
| `9` | `std/audio/audio_codec.aipl` | `resamplePcmCubic` | `pub fn resamplePcmCubic(buffer: PcmAudioBuffer, targetSampleRate: int): PcmAudioBuffer:` | `tests/functions/audio/audio_codec_test.aipl` |
| `10` | `std/audio/audio_codec.aipl` | `encodeWavPcm16` | `pub fn encodeWavPcm16(samples: [float], sampleRate: int = 44100, numChannels: int = 1): bytes:` | `tests/functions/audio/audio_codec_test.aipl` |
| `11` | `std/audio/audio_codec.aipl` | `decodeWavPcm16` | `pub fn decodeWavPcm16(data: bytes): Result[[float], str]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `12` | `std/audio/audio_codec.aipl` | `writeWavFilePcm16` | `pub fn writeWavFilePcm16(path: str, samples: [int], sampleRate: int = 44100, channels: int = 1): Result[bool, str]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `13` | `std/audio/audio_codec.aipl` | `writeWavFilePcm16Float` | `pub fn writeWavFilePcm16Float(path: str, samples: [float], sampleRate: int = 44100, channels: int = 1): Result[bool, str]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `14` | `std/audio/audio_codec.aipl` | `inspectPcmBuffer` | `pub fn inspectPcmBuffer(samples: [float]): [float]:` | `tests/functions/audio/audio_codec_test.aipl` |
| `15` | `std/audio/audio_device.aipl` | `createAudioDevice` | `pub fn createAudioDevice(sampleRate: int = 44100, bufferSize: int = 512, channels: int = 2): AudioDevice:` | `tests/functions/audio/audio_device_test.aipl` |
| `16` | `std/audio/audio_device.aipl` | `startAudioDevice` | `pub fn startAudioDevice(device: AudioDevice): AudioDevice:` | `tests/functions/audio/audio_device_test.aipl` |
| `17` | `std/audio/audio_device.aipl` | `stopAudioDevice` | `pub fn stopAudioDevice(device: AudioDevice): AudioDevice:` | `tests/functions/audio/audio_device_test.aipl` |
| `18` | `std/audio/audio_device.aipl` | `writeAudioPcmInterleaved` | `pub fn writeAudioPcmInterleaved(device: AudioDevice, pcm: [float]): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `19` | `std/audio/audio_device.aipl` | `getAudioLatencyMs` | `pub fn getAudioLatencyMs(device: AudioDevice): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `20` | `std/audio/audio_device.aipl` | `destroyAudioDevice` | `pub fn destroyAudioDevice(device: AudioDevice): AudioDevice:` | `tests/functions/audio/audio_device_test.aipl` |
| `21` | `std/audio/audio_device.aipl` | `audioGetEnvOr` | `fn audioGetEnvOr(key: str, fallback: str): str:` | `tests/functions/audio/audio_device_test.aipl` |
| `22` | `std/audio/audio_device.aipl` | `stopAllSounds` | `pub fn stopAllSounds(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `23` | `std/audio/audio_device.aipl` | `audioInit` | `pub fn audioInit(sampleRate: int = 44100, channels: int = 2): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `24` | `std/audio/audio_device.aipl` | `audioShutdown` | `pub fn audioShutdown(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `25` | `std/audio/audio_device.aipl` | `getAudioEnergy` | `pub fn getAudioEnergy(): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `26` | `std/audio/audio_device.aipl` | `getAudioBand` | `pub fn getAudioBand(band: int): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `27` | `std/audio/audio_device.aipl` | `setMasterVolume` | `pub fn setMasterVolume(volume: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `28` | `std/audio/audio_device.aipl` | `getMasterVolume` | `pub fn getMasterVolume(): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `29` | `std/audio/audio_device.aipl` | `loadSound` | `pub fn loadSound(path: str): Result[int, str]:` | `tests/functions/audio/audio_device_test.aipl` |
| `30` | `std/audio/audio_device.aipl` | `decodeSound` | `pub fn decodeSound(data: bytes): Result[int, str]:` | `tests/functions/audio/audio_device_test.aipl` |
| `31` | `std/audio/audio_device.aipl` | `unloadSound` | `pub fn unloadSound(soundId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `32` | `std/audio/audio_device.aipl` | `audioEngineNew` | `pub fn audioEngineNew(): AudioEngine:` | `tests/functions/audio/audio_device_test.aipl` |
| `33` | `std/audio/audio_device.aipl` | `playSoundEx` | `pub fn playSoundEx(soundId: int, volume: float, pitch: float, pan: float, loopSound: bool): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `34` | `std/audio/audio_device.aipl` | `playSound` | `pub fn playSound(soundId: int): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `35` | `std/audio/audio_device.aipl` | `pauseVoice` | `pub fn pauseVoice(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `36` | `std/audio/audio_device.aipl` | `resumeVoice` | `pub fn resumeVoice(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `37` | `std/audio/audio_device.aipl` | `stopVoice` | `pub fn stopVoice(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `38` | `std/audio/audio_device.aipl` | `isVoicePlaying` | `pub fn isVoicePlaying(voiceId: int): bool:` | `tests/functions/audio/audio_device_test.aipl` |
| `39` | `std/audio/audio_device.aipl` | `seekVoice` | `pub fn seekVoice(voiceId: int, seconds: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `40` | `std/audio/audio_device.aipl` | `getVoicePosition` | `pub fn getVoicePosition(voiceId: int): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `41` | `std/audio/audio_device.aipl` | `getSoundDuration` | `pub fn getSoundDuration(soundId: int): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `42` | `std/audio/audio_device.aipl` | `setVoiceVolume` | `pub fn setVoiceVolume(voiceId: int, volume: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `43` | `std/audio/audio_device.aipl` | `setVoicePitch` | `pub fn setVoicePitch(voiceId: int, pitch: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `44` | `std/audio/audio_device.aipl` | `setVoicePan` | `pub fn setVoicePan(voiceId: int, pan: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `45` | `std/audio/audio_device.aipl` | `play` | `pub fn (self: AudioEngine) play(soundId: int, volume: float = 1.0, pitch: float = 1.0, pan: float = 0.0, loopSound: bool = false): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `46` | `std/audio/audio_device.aipl` | `isPlaying` | `pub fn (self: AudioEngine) isPlaying(voiceId: int): bool:` | `tests/functions/audio/audio_device_test.aipl` |
| `47` | `std/audio/audio_device.aipl` | `audioTime` | `pub fn audioTime(): float:` | `tests/functions/audio/audio_device_test.aipl` |
| `48` | `std/audio/audio_device.aipl` | `playPcmBuffer` | `pub fn playPcmBuffer(samples: [float], sampleRate: int): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `49` | `std/audio/audio_device.aipl` | `playToneEx` | `pub fn playToneEx(frequency: float, durationMs: float, volume: float = 1.0, waveform: str = "sine"): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `50` | `std/audio/audio_device.aipl` | `playTone` | `pub fn playTone(frequency: float, durationMs: float, volume: float = 0.5): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `51` | `std/audio/audio_device.aipl` | `beep` | `pub fn beep(frequency: float = 880.0, durationMs: float = 80.0, waveform: str = "sine"): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `52` | `std/audio/audio_device.aipl` | `playBounce` | `pub fn playBounce(intensity: float = 0.5): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `53` | `std/audio/audio_device.aipl` | `playImpact` | `pub fn playImpact(force: float = 0.5): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `54` | `std/audio/audio_device.aipl` | `playExplosion` | `pub fn playExplosion(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `55` | `std/audio/audio_device.aipl` | `playCoin` | `pub fn playCoin(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `56` | `std/audio/audio_device.aipl` | `playJump` | `pub fn playJump(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `57` | `std/audio/audio_device.aipl` | `playLaser` | `pub fn playLaser(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `58` | `std/audio/audio_device.aipl` | `playPowerup` | `pub fn playPowerup(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `59` | `std/audio/audio_device.aipl` | `playHit` | `pub fn playHit(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `60` | `std/audio/audio_device.aipl` | `playBossAlert` | `pub fn playBossAlert(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `61` | `std/audio/audio_device.aipl` | `playVictory` | `pub fn playVictory(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `62` | `std/audio/audio_device.aipl` | `playGameOver` | `pub fn playGameOver(): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `63` | `std/audio/audio_device.aipl` | `playNote` | `pub fn playNote(midiNote: int, durationMs: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `64` | `std/audio/audio_device.aipl` | `playNoise` | `pub fn playNoise(durationMs: float, volume: float = 0.5): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `65` | `std/audio/audio_device.aipl` | `loadMusicStream` | `pub fn loadMusicStream(path: str): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `66` | `std/audio/audio_device.aipl` | `playMusicStream` | `pub fn playMusicStream(musicId: int): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `67` | `std/audio/audio_device.aipl` | `stopMusicStream` | `pub fn stopMusicStream(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `68` | `std/audio/audio_device.aipl` | `pauseMusicStream` | `pub fn pauseMusicStream(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `69` | `std/audio/audio_device.aipl` | `resumeMusicStream` | `pub fn resumeMusicStream(voiceId: int): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `70` | `std/audio/audio_device.aipl` | `setMusicVolume` | `pub fn setMusicVolume(voiceId: int, volume: float): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `71` | `std/audio/audio_device.aipl` | `playProceduralChime` | `pub fn playProceduralChime(kind: str, pitch: float = 1.0): int:` | `tests/functions/audio/audio_device_test.aipl` |
| `72` | `std/audio/audio_device.aipl` | `audioMockSinkNew` | `pub fn audioMockSinkNew(): AudioMockSink:` | `tests/functions/audio/audio_device_test.aipl` |
| `73` | `std/audio/audio_device.aipl` | `audioMockSinkPlay` | `pub fn audioMockSinkPlay(sink: AudioMockSink, freq: float, dur: float, wave: str): AudioMockSink:` | `tests/functions/audio/audio_device_test.aipl` |
| `74` | `std/audio/audio_device.aipl` | `playChord` | `pub fn playChord(midiNotes: [int], durationMs: float, volume: float = 0.35): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `75` | `std/audio/audio_device.aipl` | `playSpatialTone` | `pub fn playSpatialTone(freq: float, durationMs: float, listenerX: float, listenerY: float, sourceX: float, sourceY: float, maxDist: float, baseVol: float = 0.6): void:` | `tests/functions/audio/audio_device_test.aipl` |
| `76` | `std/audio/audio_dsp.aipl` | `createBiquadLowPass` | `pub fn createBiquadLowPass(sampleRate: float, cutoffHz: float, q: float = 0.7071): BiquadFilter:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `77` | `std/audio/audio_dsp.aipl` | `createBiquadHighPass` | `pub fn createBiquadHighPass(sampleRate: float, cutoffHz: float, q: float = 0.7071): BiquadFilter:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `78` | `std/audio/audio_dsp.aipl` | `processBiquadSample` | `pub fn processBiquadSample(filter: BiquadFilter, sample: float): (BiquadFilter, float):` | `tests/functions/audio/audio_dsp_test.aipl` |
| `79` | `std/audio/audio_dsp.aipl` | `createSchroederReverb` | `pub fn createSchroederReverb(sampleRate: int, roomSize: float, damp: float): SchroederReverb:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `80` | `std/audio/audio_dsp.aipl` | `processReverbBlock` | `pub fn processReverbBlock(reverb: SchroederReverb, samples: [float]): (SchroederReverb, [float]):` | `tests/functions/audio/audio_dsp_test.aipl` |
| `81` | `std/audio/audio_dsp.aipl` | `absFloatDsp` | `fn absFloatDsp(v: float): float:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `82` | `std/audio/audio_dsp.aipl` | `applyDynamicCompression` | `pub fn applyDynamicCompression(samples: [float], config: CompressorConfig, sampleRate: float): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `83` | `std/audio/audio_dsp.aipl` | `pcmApplyEcho` | `pub fn pcmApplyEcho(samples: [int], delaySamples: int, decay: float): [int]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `84` | `std/audio/audio_dsp.aipl` | `pcmLowPassFilter` | `pub fn pcmLowPassFilter(samples: [int], alpha: float): [int]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `85` | `std/audio/audio_dsp.aipl` | `pcmComputeRms` | `pub fn pcmComputeRms(samples: [int]): float:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `86` | `std/audio/audio_dsp.aipl` | `svfNew` | `pub fn svfNew(cutoffHz: float, q: float, sampleRate: int): CytomicSvf:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `87` | `std/audio/audio_dsp.aipl` | `fxApplySvf` | `pub fn fxApplySvf(samples: [float], filterMode: str, cutoffHz: float, q: float, sampleRate: int): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `88` | `std/audio/audio_dsp.aipl` | `fxApplyPhaser` | `pub fn fxApplyPhaser(samples: [float], lfoRateHz: float, depth: float, feedback: float, mix: float, sampleRate: int): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `89` | `std/audio/audio_dsp.aipl` | `fxApplyModulatedDelay` | `pub fn fxApplyModulatedDelay(samples: [float], baseDelayMs: float, modDepthMs: float, modRateHz: float, feedback: float, mix: float, sampleRate: int): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `90` | `std/audio/audio_dsp.aipl` | `fxApplyFreeverb` | `pub fn fxApplyFreeverb(samples: [float], roomSize: float, damping: float, wetMix: float): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `91` | `std/audio/audio_dsp.aipl` | `fxApplyCompressor` | `pub fn fxApplyCompressor(samples: [float], thresholdLin: float, ratio: float, attackMs: float, releaseMs: float, makeupGain: float, sampleRate: int): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `92` | `std/audio/audio_dsp.aipl` | `pcmApplyEchoFloat` | `pub fn pcmApplyEchoFloat(samples: [float], delaySamples: int, decay: float): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `93` | `std/audio/audio_dsp.aipl` | `pcmLowPassFilterFloat` | `pub fn pcmLowPassFilterFloat(samples: [float], alpha: float): [float]:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `94` | `std/audio/audio_dsp.aipl` | `pcmComputeRmsFloat` | `pub fn pcmComputeRmsFloat(samples: [float]): float:` | `tests/functions/audio/audio_dsp_test.aipl` |
| `95` | `std/audio/audio_mixer.aipl` | `clampMix01` | `fn clampMix01(v: float): float:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `96` | `std/audio/audio_mixer.aipl` | `createAudioMixer` | `pub fn createAudioMixer(maxVoices: int = 32): AudioMixer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `97` | `std/audio/audio_mixer.aipl` | `addMixerBus` | `pub fn addMixerBus(mixer: AudioMixer, name: str, parentBusId: int = 0): (AudioMixer, int):` | `tests/functions/audio/audio_mixer_test.aipl` |
| `98` | `std/audio/audio_mixer.aipl` | `setBusVolume` | `pub fn setBusVolume(mixer: AudioMixer, busId: int, volume: float): AudioMixer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `99` | `std/audio/audio_mixer.aipl` | `setBusDucking` | `pub fn setBusDucking(mixer: AudioMixer, busId: int, targetBusId: int, duckingDb: float): AudioMixer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `100` | `std/audio/audio_mixer.aipl` | `playAudioVoice` | `pub fn playAudioVoice(mixer: AudioMixer, bufferId: int, busId: int, volume: float = 1.0, pitch: float = 1.0, loop: bool = false): (AudioMixer, int):` | `tests/functions/audio/audio_mixer_test.aipl` |
| `101` | `std/audio/audio_mixer.aipl` | `stopAudioVoice` | `pub fn stopAudioVoice(mixer: AudioMixer, voiceId: int): AudioMixer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `102` | `std/audio/audio_mixer.aipl` | `mixAudioBlock` | `pub fn mixAudioBlock(mixer: AudioMixer, mut outBuffer: [float], framesToRender: int): AudioMixer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `103` | `std/audio/audio_mixer.aipl` | `noteNameToMidi` | `pub fn noteNameToMidi(noteName: str): int:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `104` | `std/audio/audio_mixer.aipl` | `midiToFrequency` | `pub fn midiToFrequency(midiNote: int): float:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `105` | `std/audio/audio_mixer.aipl` | `sequencerNew` | `pub fn sequencerNew(bpm: float, pattern: [int]): StepSequencer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `106` | `std/audio/audio_mixer.aipl` | `sequencerStep` | `pub fn sequencerStep(seq: StepSequencer, dtMs: float): StepSequencer:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `107` | `std/audio/audio_mixer.aipl` | `euclideanRhythm` | `pub fn euclideanRhythm(pulses: int, steps: int): [int]:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `108` | `std/audio/audio_mixer.aipl` | `scaleIntervals` | `pub fn scaleIntervals(scaleName: str): [int]:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `109` | `std/audio/audio_mixer.aipl` | `scaleDegreeToMidi` | `pub fn scaleDegreeToMidi(rootMidi: int, scaleName: str, degree: int): int:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `110` | `std/audio/audio_mixer.aipl` | `buildChordMidi` | `pub fn buildChordMidi(rootMidi: int, chordKind: str): [int]:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `111` | `std/audio/audio_mixer.aipl` | `mixBufferAt` | `pub fn mixBufferAt(dst: [float], src: [float], startSample: int, gain: float): [float]:` | `tests/functions/audio/audio_mixer_test.aipl` |
| `112` | `std/audio/audio_spatial.aipl` | `createAudioListener3D` | `pub fn createAudioListener3D(): AudioListener3D:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `113` | `std/audio/audio_spatial.aipl` | `createAudioEmitter3D` | `pub fn createAudioEmitter3D(minDist: float = 1.0, maxDist: float = 50.0): AudioEmitter3D:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `114` | `std/audio/audio_spatial.aipl` | `computeInverseDistanceAttenuation` | `pub fn computeInverseDistanceAttenuation(distance: float, minDist: float, maxDist: float, rolloff: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `115` | `std/audio/audio_spatial.aipl` | `computeDopplerFactor` | `pub fn computeDopplerFactor(listenerVel: float, emitterVel: float, speedOfSound: float = 343.0): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `116` | `std/audio/audio_spatial.aipl` | `computeSpatialGain` | `pub fn computeSpatialGain(listener: AudioListener3D, emitter: AudioEmitter3D, speedOfSound: float = 343.0): SpatialGain:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `117` | `std/audio/audio_spatial.aipl` | `computeStereoPan` | `pub fn computeStereoPan(listenerX: float, sourceX: float, maxSpread: float): [float]:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `118` | `std/audio/audio_spatial.aipl` | `computeDopplerPitch` | `pub fn computeDopplerPitch(baseFreq: float, relVelocityTowardListener: float, soundSpeed: float = 343.0): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `119` | `std/audio/audio_spatial.aipl` | `spatial3dAttenuation` | `pub fn spatial3dAttenuation(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float = 1.0, maxDist: float = 100.0, rollOff: float = 1.0): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `120` | `std/audio/audio_spatial.aipl` | `spatial3dPan` | `pub fn spatial3dPan(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, lisYawRad: float = 0.0, maxSpread: float = 0.0): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `121` | `std/audio/audio_spatial.aipl` | `audioComputeDistanceGain` | `pub fn audioComputeDistanceGain(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float, maxDist: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `122` | `std/audio/audio_spatial.aipl` | `audioComputeStereoPan2D` | `pub fn audioComputeStereoPan2D(srcX: float, srcY: float, lisX: float, lisY: float, lisYawRad: float, maxPanDist: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `123` | `std/audio/audio_spatial.aipl` | `audioComputeDopplerPitchMultiplier` | `pub fn audioComputeDopplerPitchMultiplier(srcX: float, srcY: float, srcVx: float, srcVy: float, lisX: float, lisY: float, lisVx: float, lisVy: float, speedOfSound: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `124` | `std/audio/audio_spatial.aipl` | `audioComputeWallOcclusionLowpass` | `pub fn audioComputeWallOcclusionLowpass(wallHits: int, baseCutoffHz: float, attenuationPerWall: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `125` | `std/audio/audio_spatial.aipl` | `audioComputeReverbDecayGain` | `pub fn audioComputeReverbDecayGain(elapsedMs: float, rt60Ms: float, wetMix: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `126` | `std/audio/audio_spatial.aipl` | `audioComputeThunderDelaySeconds` | `pub fn audioComputeThunderDelaySeconds(distanceMeters: float): float:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `127` | `std/audio/audio_spatial.aipl` | `audioComputeCountdownBeepIntervalMs` | `pub fn audioComputeCountdownBeepIntervalMs(remainingSec: float): int:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `128` | `std/audio/audio_spatial.aipl` | `audioListener3DDefault` | `pub fn audioListener3DDefault(): AudioListener3D:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `129` | `std/audio/audio_spatial.aipl` | `computeSpatialAudioListener3D` | `pub fn computeSpatialAudioListener3D(emitter: SoundEmitter3D, listener: AudioListener3D, wallHitsOrMinDist: float, minDistOrWallHits: float = 5.0): [float]:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `130` | `std/audio/audio_spatial.aipl` | `applySpatialAudioDsp3D` | `pub fn applySpatialAudioDsp3D(samples: [float], emitter: SoundEmitter3D, listener: AudioListener3D, wallHits: int, sampleRate: int = 22050, minDist: float = 5.0): [float]:` | `tests/functions/audio/audio_spatial_test.aipl` |
| `131` | `std/audio/audio_synth.aipl` | `createAdsr` | `pub fn createAdsr(attack: float, decay: float, sustain: float, release: float, antiClickRamp: float = 0.005): AdsrEnvelope:` | `tests/functions/audio/audio_synth_test.aipl` |
| `132` | `std/audio/audio_synth.aipl` | `evaluateNoteOnLevel` | `fn evaluateNoteOnLevel(adsr: AdsrEnvelope, t: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `133` | `std/audio/audio_synth.aipl` | `adsrDefault` | `pub fn adsrDefault(): AdsrEnvelope:` | `tests/functions/audio/audio_synth_test.aipl` |
| `134` | `std/audio/audio_synth.aipl` | `evaluateAdsr` | `pub fn evaluateAdsr(adsr: AdsrEnvelope, timeSec: float, isNoteOnOrTotalDur: any = true, noteReleaseTimeSec: float = -1.0): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `135` | `std/audio/audio_synth.aipl` | `generateWaveformSample` | `pub fn generateWaveformSample(oscType: int, phase: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `136` | `std/audio/audio_synth.aipl` | `absFloatSynth` | `fn absFloatSynth(v: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `137` | `std/audio/audio_synth.aipl` | `quantizeToPentatonicLadder` | `pub fn quantizeToPentatonicLadder(continuousFreqHz: float, baseKeyNoteHz: float = 261.63): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `138` | `std/audio/audio_synth.aipl` | `synthesizeToneBuffer` | `pub fn synthesizeToneBuffer(frequency: float, durationMs: float, volume: float = 0.5, oscTypeOrWaveform: any = 0, sampleRate: int = 44100): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `139` | `std/audio/audio_synth.aipl` | `renderFmPatch4Op` | `pub fn renderFmPatch4Op(baseFreq: float, durationSec: float, ops: [FmOperator], sampleRate: int = 44100): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `140` | `std/audio/audio_synth.aipl` | `midiNoteToFreqHz` | `pub fn midiNoteToFreqHz(midiNote: int): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `141` | `std/audio/audio_synth.aipl` | `freqHzToMidiNote` | `pub fn freqHzToMidiNote(freqHz: float): int:` | `tests/functions/audio/audio_synth_test.aipl` |
| `142` | `std/audio/audio_synth.aipl` | `evalAdsrEnvelope` | `pub fn evalAdsrEnvelope(t: float, attack: float, decay: float, sustainLevel: float, releaseTime: float, noteDuration: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `143` | `std/audio/audio_synth.aipl` | `polyBlep` | `pub fn polyBlep(t: float, dt: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `144` | `std/audio/audio_synth.aipl` | `oscSamplePolyBlep` | `pub fn oscSamplePolyBlep(waveform: str, phase: float, dt: float, pulseWidth: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `145` | `std/audio/audio_synth.aipl` | `renderOscillatorBuffer` | `pub fn renderOscillatorBuffer(waveform: str, freqHz: float, durationSec: float, sampleRate: int, pulseWidth: float): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `146` | `std/audio/audio_synth.aipl` | `pinkNoiseStateNew` | `pub fn pinkNoiseStateNew(seed: int): PinkNoiseState:` | `tests/functions/audio/audio_synth_test.aipl` |
| `147` | `std/audio/audio_synth.aipl` | `nextWhiteNoise` | `pub fn nextWhiteNoise(seed: int): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `148` | `std/audio/audio_synth.aipl` | `renderNoiseBuffer` | `pub fn renderNoiseBuffer(kind: str, numSamples: int, seed: int): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `149` | `std/audio/audio_synth.aipl` | `ahdsrNew` | `pub fn ahdsrNew(attackSec: float, holdSec: float, decaySec: float, sustainLevel: float, releaseSec: float, curvePower: float): AhdsrEnvelope:` | `tests/functions/audio/audio_synth_test.aipl` |
| `150` | `std/audio/audio_synth.aipl` | `evalAhdsrEnvelope` | `pub fn evalAhdsrEnvelope(env: AhdsrEnvelope, t: float, noteOnDuration: float): float:` | `tests/functions/audio/audio_synth_test.aipl` |
| `151` | `std/audio/audio_synth.aipl` | `renderFm4OpNote` | `pub fn renderFm4OpNote(patch: Fm4OpPatch, baseFreqHz: float, durationSec: float, sampleRate: int): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `152` | `std/audio/audio_synth.aipl` | `renderKarplusStrong` | `pub fn renderKarplusStrong(freqHz: float, durationSec: float, damping: float, brightness: float, sampleRate: int, seed: int): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `153` | `std/audio/audio_synth.aipl` | `sfxPatchDefault` | `pub fn sfxPatchDefault(): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |
| `154` | `std/audio/audio_synth.aipl` | `mutateSfxPatch` | `pub fn mutateSfxPatch(p: SfxPatch, amount: float, seed: int): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |
| `155` | `std/audio/audio_synth.aipl` | `renderSfxPatch` | `pub fn renderSfxPatch(p: SfxPatch, sampleRate: int): [float]:` | `tests/functions/audio/audio_synth_test.aipl` |
| `156` | `std/audio/audio_synth.aipl` | `sfxCoin` | `pub fn sfxCoin(): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |
| `157` | `std/audio/audio_synth.aipl` | `sfxLaser` | `pub fn sfxLaser(): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |
| `158` | `std/audio/audio_synth.aipl` | `sfxExplosion` | `pub fn sfxExplosion(): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |
| `159` | `std/audio/audio_synth.aipl` | `sfxJump` | `pub fn sfxJump(): SfxPatch:` | `tests/functions/audio/audio_synth_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `readU16LEWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `fn readU16LEWav(b: [int], off: int): int:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `readU16LEWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `(b[off] & 255) | ((b[off + 1] & 255) << 8)`.

```aipl
module tests.functions.audio.audio_codec_z1_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_readU16LEWav_1(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU16LEWav(arg_b, arg_off)
  let resEdge = readU16LEWav(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU16LEWav nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU16LEWav boundary resEdge == 0")
  ret 0
```

---

### `readI16LEWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `fn readI16LEWav(b: [int], off: int): int:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `readI16LEWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `u`.

```aipl
module tests.functions.audio.audio_codec_z2_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_readI16LEWav_2(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readI16LEWav(arg_b, arg_off)
  let resEdge = readI16LEWav(edge_b, edge_off)
  assertEqInt(resNom, 0, "readI16LEWav nominal resNom == 0")
  assertEqInt(resEdge, 0, "readI16LEWav boundary resEdge == 0")
  ret 0
```

---

### `readU32LEWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `fn readU32LEWav(b: [int], off: int): int:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `b: [int], off: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `readU32LEWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `b: [int] = [1]`, `off: int = 1`; exercises core body path returning/computing `(b[off] & 255) | ((b[off + 1] & 255) << 8) | ((b[off + 2] & 255) << 16) | ((b[off + 3] & 255) << 24)`.

```aipl
module tests.functions.audio.audio_codec_z3_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_readU32LEWav_3(): int:
  let arg_b = [4]
  let edge_b = []
  let arg_off = 2
  let edge_off = 0
  let resNom = readU32LEWav(arg_b, arg_off)
  let resEdge = readU32LEWav(edge_b, edge_off)
  assertEqInt(resNom, 0, "readU32LEWav nominal resNom == 0")
  assertEqInt(resEdge, 0, "readU32LEWav boundary resEdge == 0")
  ret 0
```

---

### `pushU16LEWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `fn pushU16LEWav(mut out: [int], val: int): [int]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut out: [int], val: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `pushU16LEWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `out: [int] = [1]`, `val: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_codec_z4_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_pushU16LEWav_4(): int:
  let arg_out = [2]
  let edge_out = []
  let arg_val = 2
  let edge_val = 0
  let resNom = pushU16LEWav(arg_out, arg_val)
  let resEdge = pushU16LEWav(edge_out, edge_val)
  assertEqInt(resNom.len(), 3, "pushU16LEWav nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 2, "pushU16LEWav boundary resEdge.len() == 2")
  ret 0
```

---

### `pushU32LEWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `fn pushU32LEWav(mut out: [int], val: int): [int]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut out: [int], val: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pushU32LEWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `out: [int] = [1]`, `val: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_codec_z5_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_pushU32LEWav_5(): int:
  let arg_out = [2]
  let edge_out = []
  let arg_val = 2
  let edge_val = 0
  let resNom = pushU32LEWav(arg_out, arg_val)
  let resEdge = pushU32LEWav(edge_out, edge_val)
  assertEqInt(resNom.len(), 5, "pushU32LEWav nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 4, "pushU32LEWav boundary resEdge.len() == 4")
  ret 0
```

---

### `decodeWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn decodeWav(bytes: [int]): Option[PcmAudioBuffer]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bytes: [int]` | **Returns**: `Option[PcmAudioBuffer]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `decodeWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `bytes: [int] = [64]`; exercises core body path returning/computing `Some(PcmAudioBuffer(`.

```aipl
module tests.functions.audio.audio_codec_z6_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_decodeWav_6(): int:
  let arg_bytes = [4]
  let edge_bytes = []
  let resNom = decodeWav(arg_bytes)
  let resEdge = decodeWav(edge_bytes)
  assert(resNom.isSome() == false, "decodeWav nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "decodeWav boundary resEdge.isSome() == false")
  ret 0
```

---

### `encodeWav` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn encodeWav(buffer: PcmAudioBuffer): [int]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buffer: PcmAudioBuffer` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `encodeWav` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `buffer: PcmAudioBuffer = PcmAudioBuffer(sampleRate = 48000, channels = 2, totalFrames = 64, samples = [1.0])`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_codec_z7_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_encodeWav_7(): int:
  let arg_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 4, samples = [])
  let edge_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 1, samples = [])
  let resNom = encodeWav(arg_buffer)
  let resEdge = encodeWav(edge_buffer)
  assertEqInt(resNom.len(), 44, "encodeWav nominal resNom.len() == 44")
  assertEqInt(resEdge.len(), 44, "encodeWav boundary resEdge.len() == 44")
  ret 0
```

---

### `resamplePcmLinear` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn resamplePcmLinear(buffer: PcmAudioBuffer, targetSampleRate: int): PcmAudioBuffer:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buffer: PcmAudioBuffer, targetSampleRate: int` | **Returns**: `PcmAudioBuffer`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `resamplePcmLinear` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `buffer: PcmAudioBuffer = PcmAudioBuffer(sampleRate = 48000, channels = 2, totalFrames = 64, samples = [1.0])`, `targetSampleRate: int = 48000`; exercises core body path returning/computing `PcmAudioBuffer(`.

```aipl
module tests.functions.audio.audio_codec_z8_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_resamplePcmLinear_8(): int:
  let arg_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 4, samples = [])
  let edge_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 1, samples = [])
  let arg_targetSampleRate = 4
  let edge_targetSampleRate = 1
  let resNom = resamplePcmLinear(arg_buffer, arg_targetSampleRate)
  let resEdge = resamplePcmLinear(edge_buffer, edge_targetSampleRate)
  assertEqInt(resNom.sampleRate, 4, "resamplePcmLinear nominal resNom.sampleRate == 4")
  assertEqInt(resEdge.sampleRate, 1, "resamplePcmLinear boundary resEdge.sampleRate == 1")
  ret 0
```

---

### `resamplePcmCubic` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn resamplePcmCubic(buffer: PcmAudioBuffer, targetSampleRate: int): PcmAudioBuffer:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buffer: PcmAudioBuffer, targetSampleRate: int` | **Returns**: `PcmAudioBuffer`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `resamplePcmCubic` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `buffer: PcmAudioBuffer = PcmAudioBuffer(sampleRate = 48000, channels = 2, totalFrames = 64, samples = [1.0])`, `targetSampleRate: int = 48000`; exercises core body path returning/computing `PcmAudioBuffer(`.

```aipl
module tests.functions.audio.audio_codec_z9_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_resamplePcmCubic_9(): int:
  let arg_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 4, samples = [])
  let edge_buffer = PcmAudioBuffer(sampleRate = 4, channels = 4, totalFrames = 1, samples = [])
  let arg_targetSampleRate = 4
  let edge_targetSampleRate = 1
  let resNom = resamplePcmCubic(arg_buffer, arg_targetSampleRate)
  let resEdge = resamplePcmCubic(edge_buffer, edge_targetSampleRate)
  assertEqInt(resNom.sampleRate, 4, "resamplePcmCubic nominal resNom.sampleRate == 4")
  assertEqInt(resEdge.sampleRate, 1, "resamplePcmCubic boundary resEdge.sampleRate == 1")
  ret 0
```

---

### `encodeWavPcm16` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn encodeWavPcm16(samples: [float], sampleRate: int = 44100, numChannels: int = 1): bytes:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], sampleRate: int = 44100, numChannels: int = 1` | **Returns**: `bytes`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `encodeWavPcm16` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `samples: [float] = [1.0]`, `sampleRate: int = 48000`, `numChannels: int = 2`; exercises core body path returning/computing `bytesFromArray(out)`.

```aipl
module tests.functions.audio.audio_codec_z10_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_encodeWavPcm16_10(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_numChannels = 4
  let edge_numChannels = 1
  let resNom = encodeWavPcm16(arg_samples, arg_sampleRate, arg_numChannels)
  let resEdge = encodeWavPcm16(edge_samples, edge_sampleRate, edge_numChannels)
  assertEqInt(resNom.len(), 46, "encodeWavPcm16 nominal resNom.len() == 46")
  assertEqInt(resEdge.len(), 44, "encodeWavPcm16 boundary resEdge.len() == 44")
  ret 0
```

---

### `decodeWavPcm16` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn decodeWavPcm16(data: bytes): Result[[float], str]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[[float], str]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `decodeWavPcm16` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(samples)`.

```aipl
module tests.functions.audio.audio_codec_z11_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_decodeWavPcm16_11(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodeWavPcm16(arg_data)
  let resEdge = decodeWavPcm16(edge_data)
  assert(resNom.isOk() == false, "decodeWavPcm16 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "decodeWavPcm16 boundary resEdge.isOk() == false")
  ret 0
```

---

### `writeWavFilePcm16` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn writeWavFilePcm16(path: str, samples: [int], sampleRate: int = 44100, channels: int = 1): Result[bool, str]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, samples: [int], sampleRate: int = 44100, channels: int = 1` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `writeWavFilePcm16` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `samples: [int] = [1]`, `sampleRate: int = 48000`, `channels: int = 2`; exercises core body path returning/computing `writeBytes(path, wavBytes)`.

```aipl
module tests.functions.audio.audio_codec_z12_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_writeWavFilePcm16_12(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_samples = [4]
  let edge_samples = []
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_channels = 4
  let edge_channels = 1
  let resNom = writeWavFilePcm16(arg_path, arg_samples, arg_sampleRate, arg_channels)
  let resEdge = writeWavFilePcm16(edge_path, edge_samples, edge_sampleRate, edge_channels)
  assert(resNom.isOk() == true, "writeWavFilePcm16 nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "writeWavFilePcm16 boundary resEdge.isOk() == true")
  ret 0
```

---

### `writeWavFilePcm16Float` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn writeWavFilePcm16Float(path: str, samples: [float], sampleRate: int = 44100, channels: int = 1): Result[bool, str]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str, samples: [float], sampleRate: int = 44100, channels: int = 1` | **Returns**: `Result[bool, str]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `writeWavFilePcm16Float` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`, `samples: [float] = [1.0]`, `sampleRate: int = 48000`, `channels: int = 2`; exercises core body path returning/computing `writeBytes(path, wavBytes)`.

```aipl
module tests.functions.audio.audio_codec_z13_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_writeWavFilePcm16Float_13(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_channels = 4
  let edge_channels = 1
  let resNom = writeWavFilePcm16Float(arg_path, arg_samples, arg_sampleRate, arg_channels)
  let resEdge = writeWavFilePcm16Float(edge_path, edge_samples, edge_sampleRate, edge_channels)
  assert(resNom.isOk() == true, "writeWavFilePcm16Float nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "writeWavFilePcm16Float boundary resEdge.isOk() == true")
  ret 0
```

---

### `inspectPcmBuffer` (`std/audio/audio_codec.aipl`)

- **Signature**: `pub fn inspectPcmBuffer(samples: [float]): [float]:`
- **Import**: `import * from "std/audio/audio_codec"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float]` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_codec_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `inspectPcmBuffer` 16-bit RIFF/WAVE PCM encoding/decoding, peak/RMS buffer inspection, and linear/cubic sample-rate conversion. Concrete nominal inputs: `samples: [float] = [1.0]`; exercises core body path returning/computing `[sqrt(sumSq / float(n)), peak, float(zc)]`.

```aipl
module tests.functions.audio.audio_codec_z14_test
import * from "std/audio/audio_codec"
import { absFloat } from "std/math/consts"
import { sqrt } from "std/math/trig"
import { writeBytes } from "std/fs/file"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_codec_inspectPcmBuffer_14(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let resNom = inspectPcmBuffer(arg_samples)
  let resEdge = inspectPcmBuffer(edge_samples)
  assertEqInt(resNom.len(), 3, "inspectPcmBuffer nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 3, "inspectPcmBuffer boundary resEdge.len() == 3")
  ret 0
```

---

### `createAudioDevice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn createAudioDevice(sampleRate: int = 44100, bufferSize: int = 512, channels: int = 2): AudioDevice:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sampleRate: int = 44100, bufferSize: int = 512, channels: int = 2` | **Returns**: `AudioDevice`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `createAudioDevice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `sampleRate: int = 48000`, `bufferSize: int = 64`, `channels: int = 2`; exercises core body path returning/computing `AudioDevice(`.

```aipl
module tests.functions.audio.audio_device_z1_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_createAudioDevice_1(): int:
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_bufferSize = 4
  let edge_bufferSize = 1
  let arg_channels = 4
  let edge_channels = 1
  let resNom = createAudioDevice(arg_sampleRate, arg_bufferSize, arg_channels)
  let resEdge = createAudioDevice(edge_sampleRate, edge_bufferSize, edge_channels)
  assert(resNom.isRunning == false, "createAudioDevice nominal resNom.isRunning == false")
  assert(resEdge.isRunning == false, "createAudioDevice boundary resEdge.isRunning == false")
  ret 0
```

---

### `startAudioDevice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn startAudioDevice(device: AudioDevice): AudioDevice:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `device: AudioDevice` | **Returns**: `AudioDevice`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `startAudioDevice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `device: AudioDevice = AudioDevice(config = AudioDeviceConfig(sampleRate = 48000, bufferSizeFrames = 64, channels = 2, bitDepth = 1), isRunning = true, deviceHandle = 1, underrunCount = 64)`; exercises core body path returning/computing `AudioDevice(`.

```aipl
module tests.functions.audio.audio_device_z2_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_startAudioDevice_2(): int:
  let arg_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 4, channels = 4, bitDepth = 4), isRunning = true, deviceHandle = 4, underrunCount = 4)
  let edge_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 1, channels = 4, bitDepth = 1), isRunning = false, deviceHandle = 1, underrunCount = 1)
  let resNom = startAudioDevice(arg_device)
  let resEdge = startAudioDevice(edge_device)
  assert(resNom.isRunning == true, "startAudioDevice nominal resNom.isRunning == true")
  assert(resEdge.isRunning == true, "startAudioDevice boundary resEdge.isRunning == true")
  ret 0
```

---

### `stopAudioDevice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn stopAudioDevice(device: AudioDevice): AudioDevice:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `device: AudioDevice` | **Returns**: `AudioDevice`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `stopAudioDevice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `device: AudioDevice = AudioDevice(config = AudioDeviceConfig(sampleRate = 48000, bufferSizeFrames = 64, channels = 2, bitDepth = 1), isRunning = true, deviceHandle = 1, underrunCount = 64)`; exercises core body path returning/computing `AudioDevice(`.

```aipl
module tests.functions.audio.audio_device_z3_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_stopAudioDevice_3(): int:
  let arg_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 4, channels = 4, bitDepth = 4), isRunning = true, deviceHandle = 4, underrunCount = 4)
  let edge_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 1, channels = 4, bitDepth = 1), isRunning = false, deviceHandle = 1, underrunCount = 1)
  let resNom = stopAudioDevice(arg_device)
  let resEdge = stopAudioDevice(edge_device)
  assert(resNom.isRunning == false, "stopAudioDevice nominal resNom.isRunning == false")
  assert(resEdge.isRunning == false, "stopAudioDevice boundary resEdge.isRunning == false")
  ret 0
```

---

### `writeAudioPcmInterleaved` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn writeAudioPcmInterleaved(device: AudioDevice, pcm: [float]): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `device: AudioDevice, pcm: [float]` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `writeAudioPcmInterleaved` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `device: AudioDevice = AudioDevice(config = AudioDeviceConfig(sampleRate = 48000, bufferSizeFrames = 64, channels = 2, bitDepth = 1), isRunning = true, deviceHandle = 1, underrunCount = 64)`, `pcm: [float] = [1.0]`; exercises core body path returning/computing `pcm.len / ch`.

```aipl
module tests.functions.audio.audio_device_z4_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_writeAudioPcmInterleaved_4(): int:
  let arg_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 4, channels = 4, bitDepth = 4), isRunning = true, deviceHandle = 4, underrunCount = 4)
  let edge_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 1, channels = 4, bitDepth = 1), isRunning = false, deviceHandle = 1, underrunCount = 1)
  let arg_pcm = [1.0]
  let edge_pcm = []
  let resNom = writeAudioPcmInterleaved(arg_device, arg_pcm)
  let resEdge = writeAudioPcmInterleaved(edge_device, edge_pcm)
  assertEqInt(resNom, 0, "writeAudioPcmInterleaved nominal resNom == 0")
  assertEqInt(resEdge, 0, "writeAudioPcmInterleaved boundary resEdge == 0")
  ret 0
```

---

### `getAudioLatencyMs` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getAudioLatencyMs(device: AudioDevice): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `device: AudioDevice` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `getAudioLatencyMs` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `device: AudioDevice = AudioDevice(config = AudioDeviceConfig(sampleRate = 48000, bufferSizeFrames = 64, channels = 2, bitDepth = 1), isRunning = true, deviceHandle = 1, underrunCount = 64)`; exercises core body path returning/computing `(float(device.config.bufferSizeFrames) / float(device.config.sampleRate)) * 1000.0`.

```aipl
module tests.functions.audio.audio_device_z5_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getAudioLatencyMs_5(): int:
  let arg_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 4, channels = 4, bitDepth = 4), isRunning = true, deviceHandle = 4, underrunCount = 4)
  let edge_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 1, channels = 4, bitDepth = 1), isRunning = false, deviceHandle = 1, underrunCount = 1)
  let resNom = getAudioLatencyMs(arg_device)
  let resEdge = getAudioLatencyMs(edge_device)
  assertApproxEq(resNom, 1000.0, 0.001, "getAudioLatencyMs nominal resNom ~= 1000.0")
  assertApproxEq(resEdge, 250.0, 0.001, "getAudioLatencyMs boundary resEdge ~= 250.0")
  ret 0
```

---

### `destroyAudioDevice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn destroyAudioDevice(device: AudioDevice): AudioDevice:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `device: AudioDevice` | **Returns**: `AudioDevice`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `destroyAudioDevice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `device: AudioDevice = AudioDevice(config = AudioDeviceConfig(sampleRate = 48000, bufferSizeFrames = 64, channels = 2, bitDepth = 1), isRunning = true, deviceHandle = 1, underrunCount = 64)`; exercises core body path returning/computing `AudioDevice(`.

```aipl
module tests.functions.audio.audio_device_z6_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_destroyAudioDevice_6(): int:
  let arg_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 4, channels = 4, bitDepth = 4), isRunning = true, deviceHandle = 4, underrunCount = 4)
  let edge_device = AudioDevice(config = AudioDeviceConfig(sampleRate = 4, bufferSizeFrames = 1, channels = 4, bitDepth = 1), isRunning = false, deviceHandle = 1, underrunCount = 1)
  let resNom = destroyAudioDevice(arg_device)
  let resEdge = destroyAudioDevice(edge_device)
  assert(resNom.isRunning == false, "destroyAudioDevice nominal resNom.isRunning == false")
  assert(resEdge.isRunning == false, "destroyAudioDevice boundary resEdge.isRunning == false")
  ret 0
```

---

### `audioGetEnvOr` (`std/audio/audio_device.aipl`)

- **Signature**: `fn audioGetEnvOr(key: str, fallback: str): str:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `key: str, fallback: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `audioGetEnvOr` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `key: str = "aipl_test"`, `fallback: str = "aipl_test"`; exercises core body path returning/computing `fallback`.

```aipl
module tests.functions.audio.audio_device_z7_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioGetEnvOr_7(): int:
  let arg_key = "test"
  let edge_key = "a"
  let arg_fallback = "test"
  let edge_fallback = "a"
  let resNom = audioGetEnvOr(arg_key, arg_fallback)
  let resEdge = audioGetEnvOr(edge_key, edge_fallback)
  assertEqStr(resNom, "test", "audioGetEnvOr nominal string matches")
  assertEqStr(resEdge, "a", "audioGetEnvOr boundary string matches")
  ret 0
```

---

### `stopAllSounds` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn stopAllSounds(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `stopAllSounds` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z8_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_stopAllSounds_8(): int:
  mut completedCalls = 0
  stopAllSounds()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "stopAllSounds nominal and boundary void calls completed")
  ret 0
```

---

### `audioInit` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioInit(sampleRate: int = 44100, channels: int = 2): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sampleRate: int = 44100, channels: int = 2` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioInit` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `sampleRate: int = 48000`, `channels: int = 2`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z9_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioInit_9(): int:
  mut completedCalls = 0
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_channels = 4
  let edge_channels = 1
  audioInit(arg_sampleRate, arg_channels)
  audioInit(edge_sampleRate, edge_channels)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "audioInit nominal and boundary void calls completed")
  ret 0
```

---

### `audioShutdown` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioShutdown(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `audioShutdown` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z10_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioShutdown_10(): int:
  mut completedCalls = 0
  audioShutdown()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "audioShutdown nominal and boundary void calls completed")
  ret 0
```

---

### `getAudioEnergy` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getAudioEnergy(): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `getAudioEnergy` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `clampFloat(parseFloat(s), 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_device_z11_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getAudioEnergy_11(): int:
  let resNom = getAudioEnergy()
  let resEdge = getAudioEnergy()
  assertApproxEq(resNom, 0.0, 0.001, "getAudioEnergy nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getAudioEnergy boundary resEdge ~= 0.0")
  ret 0
```

---

### `getAudioBand` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getAudioBand(band: int): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `band: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `getAudioBand` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `band: int = 1`; exercises core body path returning/computing `clampFloat(parseFloat(s), 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_device_z12_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getAudioBand_12(): int:
  let arg_band = 4
  let edge_band = 1
  let resNom = getAudioBand(arg_band)
  let resEdge = getAudioBand(edge_band)
  assertApproxEq(resNom, 0.0, 0.001, "getAudioBand nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getAudioBand boundary resEdge ~= 0.0")
  ret 0
```

---

### `setMasterVolume` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn setMasterVolume(volume: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `volume: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `setMasterVolume` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z13_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_setMasterVolume_13(): int:
  mut completedCalls = 0
  let arg_volume = 1.0
  let edge_volume = 0.5
  setMasterVolume(arg_volume)
  setMasterVolume(edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setMasterVolume nominal and boundary void calls completed")
  ret 0
```

---

### `getMasterVolume` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getMasterVolume(): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `getMasterVolume` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `clampFloat(parseFloat(s), 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_device_z14_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getMasterVolume_14(): int:
  let resNom = getMasterVolume()
  let resEdge = getMasterVolume()
  assertApproxEq(resNom, 0.5, 0.001, "getMasterVolume nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.5, 0.001, "getMasterVolume boundary resEdge ~= 0.5")
  ret 0
```

---

### `loadSound` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn loadSound(path: str): Result[int, str]:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `loadSound` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `Ok(sid)`.

```aipl
module tests.functions.audio.audio_device_z15_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_loadSound_15(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadSound(arg_path)
  let resEdge = loadSound(edge_path)
  assert(resNom.isOk() == true, "loadSound nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "loadSound boundary resEdge.isOk() == true")
  ret 0
```

---

### `decodeSound` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn decodeSound(data: bytes): Result[int, str]:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `data: bytes` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `decodeSound` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `data: bytes = [65, 73, 80, 76]`; exercises core body path returning/computing `Ok(sid)`.

```aipl
module tests.functions.audio.audio_device_z16_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_decodeSound_16(): int:
  let arg_data = [65, 73, 80, 76]
  let edge_data = [65]
  let resNom = decodeSound(arg_data)
  let resEdge = decodeSound(edge_data)
  assert(resNom.isOk() == true, "decodeSound nominal resNom.isOk() == true")
  assert(resEdge.isOk() == true, "decodeSound boundary resEdge.isOk() == true")
  ret 0
```

---

### `unloadSound` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn unloadSound(soundId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `soundId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `unloadSound` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `soundId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z17_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_unloadSound_17(): int:
  mut completedCalls = 0
  let arg_soundId = 4
  let edge_soundId = 1
  unloadSound(arg_soundId)
  unloadSound(edge_soundId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "unloadSound nominal and boundary void calls completed")
  ret 0
```

---

### `audioEngineNew` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioEngineNew(): AudioEngine:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `AudioEngine`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioEngineNew` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `AudioEngine(activeVoices = 0, nextVoiceId = 1, masterVolume = 1.0, energy = 0.0)`.

```aipl
module tests.functions.audio.audio_device_z18_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioEngineNew_18(): int:
  let resNom = audioEngineNew()
  let resEdge = audioEngineNew()
  assertEqInt(resNom.activeVoices, 0, "audioEngineNew nominal resNom.activeVoices == 0")
  assertEqInt(resEdge.activeVoices, 0, "audioEngineNew boundary resEdge.activeVoices == 0")
  ret 0
```

---

### `playSoundEx` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playSoundEx(soundId: int, volume: float, pitch: float, pan: float, loopSound: bool): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `soundId: int, volume: float, pitch: float, pan: float, loopSound: bool` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playSoundEx` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `soundId: int = 1`, `volume: float = 1.0`, `pitch: float = 1.0`, `pan: float = 1.0`, `loopSound: bool = true`; exercises core body path returning/computing `vid`.

```aipl
module tests.functions.audio.audio_device_z19_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playSoundEx_19(): int:
  let arg_soundId = 4
  let edge_soundId = 1
  let arg_volume = 1.0
  let edge_volume = 0.5
  let arg_pitch = 2.0
  let edge_pitch = 1.0
  let arg_pan = 1.0
  let edge_pan = 0.5
  let arg_loopSound = true
  let edge_loopSound = false
  let resNom = playSoundEx(arg_soundId, arg_volume, arg_pitch, arg_pan, arg_loopSound)
  let resEdge = playSoundEx(edge_soundId, edge_volume, edge_pitch, edge_pan, edge_loopSound)
  assertEqInt(resNom, 1, "playSoundEx nominal resNom == 1")
  assertEqInt(resEdge, 2, "playSoundEx boundary resEdge == 2")
  ret 0
```

---

### `playSound` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playSound(soundId: int): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `soundId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playSound` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `soundId: int = 1`; exercises core body path returning/computing `playSoundEx(soundId, 1.0, 1.0, 0.0, false)`.

```aipl
module tests.functions.audio.audio_device_z20_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playSound_20(): int:
  let arg_soundId = 4
  let edge_soundId = 1
  let resNom = playSound(arg_soundId)
  let resEdge = playSound(edge_soundId)
  assertEqInt(resNom, 3, "playSound nominal resNom == 3")
  assertEqInt(resEdge, 4, "playSound boundary resEdge == 4")
  ret 0
```

---

### `pauseVoice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn pauseVoice(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pauseVoice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z21_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_pauseVoice_21(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  pauseVoice(arg_voiceId)
  pauseVoice(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "pauseVoice nominal and boundary void calls completed")
  ret 0
```

---

### `resumeVoice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn resumeVoice(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `resumeVoice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z22_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_resumeVoice_22(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  resumeVoice(arg_voiceId)
  resumeVoice(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "resumeVoice nominal and boundary void calls completed")
  ret 0
```

---

### `stopVoice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn stopVoice(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `stopVoice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z23_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_stopVoice_23(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  stopVoice(arg_voiceId)
  stopVoice(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "stopVoice nominal and boundary void calls completed")
  ret 0
```

---

### `isVoicePlaying` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn isVoicePlaying(voiceId: int): bool:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `isVoicePlaying` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `st == "playing" or st == "loop"`.

```aipl
module tests.functions.audio.audio_device_z24_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_isVoicePlaying_24(): int:
  let arg_voiceId = 1
  let edge_voiceId = 0
  let resNom = isVoicePlaying(arg_voiceId)
  let resEdge = isVoicePlaying(edge_voiceId)
  assert(resNom == false, "isVoicePlaying nominal resNom == false")
  assert(resEdge == false, "isVoicePlaying boundary resEdge == false")
  ret 0
```

---

### `seekVoice` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn seekVoice(voiceId: int, seconds: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int, seconds: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `seekVoice` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`, `seconds: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z25_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_seekVoice_25(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  let arg_seconds = 1.0
  let edge_seconds = 0.5
  seekVoice(arg_voiceId, arg_seconds)
  seekVoice(edge_voiceId, edge_seconds)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "seekVoice nominal and boundary void calls completed")
  ret 0
```

---

### `getVoicePosition` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getVoicePosition(voiceId: int): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `getVoicePosition` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `maxFloat(0.0, parseFloat(s))`.

```aipl
module tests.functions.audio.audio_device_z26_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getVoicePosition_26(): int:
  let arg_voiceId = 1
  let edge_voiceId = 0
  let resNom = getVoicePosition(arg_voiceId)
  let resEdge = getVoicePosition(edge_voiceId)
  assertApproxEq(resNom, 0.0, 0.001, "getVoicePosition nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "getVoicePosition boundary resEdge ~= 0.0")
  ret 0
```

---

### `getSoundDuration` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn getSoundDuration(soundId: int): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `soundId: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `getSoundDuration` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `soundId: int = 1`; exercises core body path returning/computing `maxFloat(0.0, parseFloat(s))`.

```aipl
module tests.functions.audio.audio_device_z27_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_getSoundDuration_27(): int:
  let arg_soundId = 4
  let edge_soundId = 1
  let resNom = getSoundDuration(arg_soundId)
  let resEdge = getSoundDuration(edge_soundId)
  assertApproxEq(resNom, 0.5, 0.001, "getSoundDuration nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.0, 0.001, "getSoundDuration boundary resEdge ~= 0.0")
  ret 0
```

---

### `setVoiceVolume` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn setVoiceVolume(voiceId: int, volume: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int, volume: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `setVoiceVolume` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`, `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z28_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_setVoiceVolume_28(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  let arg_volume = 1.0
  let edge_volume = 0.5
  setVoiceVolume(arg_voiceId, arg_volume)
  setVoiceVolume(edge_voiceId, edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setVoiceVolume nominal and boundary void calls completed")
  ret 0
```

---

### `setVoicePitch` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn setVoicePitch(voiceId: int, pitch: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int, pitch: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `setVoicePitch` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`, `pitch: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z29_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_setVoicePitch_29(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  let arg_pitch = 2.0
  let edge_pitch = 1.0
  setVoicePitch(arg_voiceId, arg_pitch)
  setVoicePitch(edge_voiceId, edge_pitch)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setVoicePitch nominal and boundary void calls completed")
  ret 0
```

---

### `setVoicePan` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn setVoicePan(voiceId: int, pan: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int, pan: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `setVoicePan` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`, `pan: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z30_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_setVoicePan_30(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  let arg_pan = 1.0
  let edge_pan = 0.5
  setVoicePan(arg_voiceId, arg_pan)
  setVoicePan(edge_voiceId, edge_pan)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setVoicePan nominal and boundary void calls completed")
  ret 0
```

---

### `play` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn (self: AudioEngine) play(soundId: int, volume: float = 1.0, pitch: float = 1.0, pan: float = 0.0, loopSound: bool = false): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `self: AudioEngine` | **Parameters**: `soundId: int, volume: float = 1.0, pitch: float = 1.0, pan: float = 0.0, loopSound: bool = false` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `play` (`self: AudioEngine`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: receiver `recvObj: AudioEngine = AudioEngine(activeVoices = 1, nextVoiceId = 1, masterVolume = 1.0, energy = 1.0)`, `soundId: int = 1`, `volume: float = 1.0`, `pitch: float = 1.0`, `pan: float = 1.0`, `loopSound: bool = true`; exercises core body path returning/computing `playSoundEx(soundId, volume * self.masterVolume, pitch, pan, loopSound)`.

```aipl
module tests.functions.audio.audio_device_z31_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_AudioEngine_play_31(): int:
  let recv_self = AudioEngine(activeVoices = 2, nextVoiceId = 4, masterVolume = 1.0, energy = 1.0)
  let edge_self = AudioEngine(activeVoices = 0, nextVoiceId = 1, masterVolume = 0.5, energy = 0.5)
  let arg_soundId = 4
  let edge_soundId = 1
  let arg_volume = 1.0
  let edge_volume = 0.5
  let arg_pitch = 2.0
  let edge_pitch = 1.0
  let arg_pan = 1.0
  let edge_pan = 0.5
  let arg_loopSound = true
  let edge_loopSound = false
  let resNom = recv_self.play(arg_soundId, arg_volume, arg_pitch, arg_pan, arg_loopSound)
  let resEdge = edge_self.play(edge_soundId, edge_volume, edge_pitch, edge_pan, edge_loopSound)
  assertEqInt(resNom, 5, "play nominal resNom == 5")
  assertEqInt(resEdge, 6, "play boundary resEdge == 6")
  ret 0
```

---

### `isPlaying` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn (self: AudioEngine) isPlaying(voiceId: int): bool:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `self: AudioEngine` | **Parameters**: `voiceId: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `isPlaying` (`self: AudioEngine`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: receiver `recvObj: AudioEngine = AudioEngine(activeVoices = 1, nextVoiceId = 1, masterVolume = 1.0, energy = 1.0)`, `voiceId: int = 1`; exercises core body path returning/computing `self.activeVoices >= 0 and isVoicePlaying(voiceId)`.

```aipl
module tests.functions.audio.audio_device_z32_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_AudioEngine_isPlaying_32(): int:
  let recv_self = AudioEngine(activeVoices = 2, nextVoiceId = 4, masterVolume = 1.0, energy = 1.0)
  let edge_self = AudioEngine(activeVoices = 0, nextVoiceId = 1, masterVolume = 0.5, energy = 0.5)
  let arg_voiceId = 1
  let edge_voiceId = 0
  let resNom = recv_self.isPlaying(arg_voiceId)
  let resEdge = edge_self.isPlaying(edge_voiceId)
  assert(resNom == false, "isPlaying nominal resNom == false")
  assert(resEdge == false, "isPlaying boundary resEdge == false")
  ret 0
```

---

### `audioTime` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioTime(): float:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioTime` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `maxFloat(0.0, parseFloat(s))`.

```aipl
module tests.functions.audio.audio_device_z33_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioTime_33(): int:
  let resNom = audioTime()
  let resEdge = audioTime()
  assertApproxEq(resNom, 0.0, 0.001, "audioTime nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "audioTime boundary resEdge ~= 0.0")
  ret 0
```

---

### `playPcmBuffer` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playPcmBuffer(samples: [float], sampleRate: int): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], sampleRate: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playPcmBuffer` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `samples: [float] = [1.0]`, `sampleRate: int = 48000`; exercises core body path returning/computing `samples.len`.

```aipl
module tests.functions.audio.audio_device_z34_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playPcmBuffer_34(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = playPcmBuffer(arg_samples, arg_sampleRate)
  let resEdge = playPcmBuffer(edge_samples, edge_sampleRate)
  assertEqInt(resNom, 7, "playPcmBuffer nominal resNom == 7")
  assertEqInt(resEdge, 0, "playPcmBuffer boundary resEdge == 0")
  ret 0
```

---

### `playToneEx` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playToneEx(frequency: float, durationMs: float, volume: float = 1.0, waveform: str = "sine"): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frequency: float, durationMs: float, volume: float = 1.0, waveform: str = "sine"` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playToneEx` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `frequency: float = 1.0`, `durationMs: float = 0.5`, `volume: float = 1.0`, `waveform: str = "aipl_test"`; exercises core body path returning/computing `playPcmBuffer(pcm, 22050)`.

```aipl
module tests.functions.audio.audio_device_z35_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playToneEx_35(): int:
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_volume = 1.0
  let edge_volume = 0.5
  let arg_waveform = "test"
  let edge_waveform = "a"
  let resNom = playToneEx(arg_frequency, arg_durationMs, arg_volume, arg_waveform)
  let resEdge = playToneEx(edge_frequency, edge_durationMs, edge_volume, edge_waveform)
  assertEqInt(resNom, 8, "playToneEx nominal resNom == 8")
  assertEqInt(resEdge, 9, "playToneEx boundary resEdge == 9")
  ret 0
```

---

### `playTone` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playTone(frequency: float, durationMs: float, volume: float = 0.5): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frequency: float, durationMs: float, volume: float = 0.5` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playTone` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `frequency: float = 1.0`, `durationMs: float = 0.5`, `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z36_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playTone_36(): int:
  mut completedCalls = 0
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_volume = 1.0
  let edge_volume = 0.5
  playTone(arg_frequency, arg_durationMs, arg_volume)
  playTone(edge_frequency, edge_durationMs, edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playTone nominal and boundary void calls completed")
  ret 0
```

---

### `beep` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn beep(frequency: float = 880.0, durationMs: float = 80.0, waveform: str = "sine"): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frequency: float = 880.0, durationMs: float = 80.0, waveform: str = "sine"` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `beep` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `frequency: float = 1.0`, `durationMs: float = 0.5`, `waveform: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z37_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_beep_37(): int:
  mut completedCalls = 0
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_waveform = "test"
  let edge_waveform = "a"
  beep(arg_frequency, arg_durationMs, arg_waveform)
  beep(edge_frequency, edge_durationMs, edge_waveform)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "beep nominal and boundary void calls completed")
  ret 0
```

---

### `playBounce` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playBounce(intensity: float = 0.5): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `intensity: float = 0.5` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playBounce` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `intensity: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z38_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playBounce_38(): int:
  mut completedCalls = 0
  let arg_intensity = 1.0
  let edge_intensity = 0.5
  playBounce(arg_intensity)
  playBounce(edge_intensity)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playBounce nominal and boundary void calls completed")
  ret 0
```

---

### `playImpact` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playImpact(force: float = 0.5): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `force: float = 0.5` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playImpact` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `force: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z39_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playImpact_39(): int:
  mut completedCalls = 0
  let arg_force = 1.0
  let edge_force = 0.5
  playImpact(arg_force)
  playImpact(edge_force)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playImpact nominal and boundary void calls completed")
  ret 0
```

---

### `playExplosion` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playExplosion(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playExplosion` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z40_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playExplosion_40(): int:
  mut completedCalls = 0
  playExplosion()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playExplosion nominal and boundary void calls completed")
  ret 0
```

---

### `playCoin` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playCoin(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playCoin` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z41_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playCoin_41(): int:
  mut completedCalls = 0
  playCoin()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playCoin nominal and boundary void calls completed")
  ret 0
```

---

### `playJump` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playJump(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playJump` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z42_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playJump_42(): int:
  mut completedCalls = 0
  playJump()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playJump nominal and boundary void calls completed")
  ret 0
```

---

### `playLaser` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playLaser(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playLaser` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z43_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playLaser_43(): int:
  mut completedCalls = 0
  playLaser()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playLaser nominal and boundary void calls completed")
  ret 0
```

---

### `playPowerup` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playPowerup(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playPowerup` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z44_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playPowerup_44(): int:
  mut completedCalls = 0
  playPowerup()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playPowerup nominal and boundary void calls completed")
  ret 0
```

---

### `playHit` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playHit(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playHit` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z45_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playHit_45(): int:
  mut completedCalls = 0
  playHit()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playHit nominal and boundary void calls completed")
  ret 0
```

---

### `playBossAlert` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playBossAlert(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playBossAlert` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z46_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playBossAlert_46(): int:
  mut completedCalls = 0
  playBossAlert()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playBossAlert nominal and boundary void calls completed")
  ret 0
```

---

### `playVictory` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playVictory(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playVictory` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z47_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playVictory_47(): int:
  mut completedCalls = 0
  playVictory()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playVictory nominal and boundary void calls completed")
  ret 0
```

---

### `playGameOver` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playGameOver(): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playGameOver` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z48_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playGameOver_48(): int:
  mut completedCalls = 0
  playGameOver()
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playGameOver nominal and boundary void calls completed")
  ret 0
```

---

### `playNote` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playNote(midiNote: int, durationMs: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `midiNote: int, durationMs: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playNote` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `midiNote: int = 1`, `durationMs: float = 0.5`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z49_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playNote_49(): int:
  mut completedCalls = 0
  let arg_midiNote = 4
  let edge_midiNote = 1
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  playNote(arg_midiNote, arg_durationMs)
  playNote(edge_midiNote, edge_durationMs)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playNote nominal and boundary void calls completed")
  ret 0
```

---

### `playNoise` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playNoise(durationMs: float, volume: float = 0.5): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `durationMs: float, volume: float = 0.5` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playNoise` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `durationMs: float = 0.5`, `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z50_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playNoise_50(): int:
  mut completedCalls = 0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_volume = 1.0
  let edge_volume = 0.5
  playNoise(arg_durationMs, arg_volume)
  playNoise(edge_durationMs, edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playNoise nominal and boundary void calls completed")
  ret 0
```

---

### `loadMusicStream` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn loadMusicStream(path: str): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `path: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `loadMusicStream` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `path: str = "/tmp/aipl_test_artifact.tmp"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.audio.audio_device_z51_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_loadMusicStream_51(): int:
  let arg_path = "/tmp/aipl_test_path"
  let edge_path = "/tmp/aipl_test_path"
  let resNom = loadMusicStream(arg_path)
  let resEdge = loadMusicStream(edge_path)
  assertEqInt(resNom, 1, "loadMusicStream nominal resNom == 1")
  assertEqInt(resEdge, 1, "loadMusicStream boundary resEdge == 1")
  ret 0
```

---

### `playMusicStream` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playMusicStream(musicId: int): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `musicId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playMusicStream` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `musicId: int = 1`; exercises core body path returning/computing `playSoundEx(musicId, 1.0, 1.0, 0.0, true)`.

```aipl
module tests.functions.audio.audio_device_z52_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playMusicStream_52(): int:
  let arg_musicId = 4
  let edge_musicId = 1
  let resNom = playMusicStream(arg_musicId)
  let resEdge = playMusicStream(edge_musicId)
  assertEqInt(resNom, 40, "playMusicStream nominal resNom == 40")
  assertEqInt(resEdge, 41, "playMusicStream boundary resEdge == 41")
  ret 0
```

---

### `stopMusicStream` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn stopMusicStream(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `stopMusicStream` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z53_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_stopMusicStream_53(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  stopMusicStream(arg_voiceId)
  stopMusicStream(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "stopMusicStream nominal and boundary void calls completed")
  ret 0
```

---

### `pauseMusicStream` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn pauseMusicStream(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pauseMusicStream` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z54_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_pauseMusicStream_54(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  pauseMusicStream(arg_voiceId)
  pauseMusicStream(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "pauseMusicStream nominal and boundary void calls completed")
  ret 0
```

---

### `resumeMusicStream` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn resumeMusicStream(voiceId: int): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `resumeMusicStream` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z55_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_resumeMusicStream_55(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  resumeMusicStream(arg_voiceId)
  resumeMusicStream(edge_voiceId)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "resumeMusicStream nominal and boundary void calls completed")
  ret 0
```

---

### `setMusicVolume` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn setMusicVolume(voiceId: int, volume: float): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `voiceId: int, volume: float` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `setMusicVolume` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `voiceId: int = 1`, `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z56_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_setMusicVolume_56(): int:
  mut completedCalls = 0
  let arg_voiceId = 1
  let edge_voiceId = 0
  let arg_volume = 1.0
  let edge_volume = 0.5
  setMusicVolume(arg_voiceId, arg_volume)
  setMusicVolume(edge_voiceId, edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "setMusicVolume nominal and boundary void calls completed")
  ret 0
```

---

### `playProceduralChime` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playProceduralChime(kind: str, pitch: float = 1.0): int:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `kind: str, pitch: float = 1.0` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playProceduralChime` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `kind: str = "aipl_test"`, `pitch: float = 1.0`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.audio.audio_device_z57_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playProceduralChime_57(): int:
  let arg_kind = "test"
  let edge_kind = "a"
  let arg_pitch = 2.0
  let edge_pitch = 1.0
  let resNom = playProceduralChime(arg_kind, arg_pitch)
  let resEdge = playProceduralChime(edge_kind, edge_pitch)
  assertEqInt(resNom, 0, "playProceduralChime nominal resNom == 0")
  assertEqInt(resEdge, 0, "playProceduralChime boundary resEdge == 0")
  ret 0
```

---

### `audioMockSinkNew` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioMockSinkNew(): AudioMockSink:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `AudioMockSink`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `audioMockSinkNew` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `AudioMockSink(toneCount = 0, lastFrequency = 0.0, lastDuration = 0.0, lastWaveform = "")`.

```aipl
module tests.functions.audio.audio_device_z58_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioMockSinkNew_58(): int:
  let resNom = audioMockSinkNew()
  let resEdge = audioMockSinkNew()
  assertEqInt(resNom.toneCount, 0, "audioMockSinkNew nominal resNom.toneCount == 0")
  assertEqInt(resEdge.toneCount, 0, "audioMockSinkNew boundary resEdge.toneCount == 0")
  ret 0
```

---

### `audioMockSinkPlay` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn audioMockSinkPlay(sink: AudioMockSink, freq: float, dur: float, wave: str): AudioMockSink:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sink: AudioMockSink, freq: float, dur: float, wave: str` | **Returns**: `AudioMockSink`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `audioMockSinkPlay` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `sink: AudioMockSink = AudioMockSink(toneCount = 64, lastFrequency = 1.0, lastDuration = 0.5, lastWaveform = "aipl_test")`, `freq: float = 1.0`, `dur: float = 1.0`, `wave: str = "aipl_test"`; exercises core body path returning/computing `AudioMockSink(`.

```aipl
module tests.functions.audio.audio_device_z59_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_audioMockSinkPlay_59(): int:
  let arg_sink = AudioMockSink(toneCount = 4, lastFrequency = 2.0, lastDuration = 1.0, lastWaveform = "test")
  let edge_sink = AudioMockSink(toneCount = 1, lastFrequency = 1.0, lastDuration = 0.5, lastWaveform = "a")
  let arg_freq = 2.0
  let edge_freq = 1.0
  let arg_dur = 1.0
  let edge_dur = 0.5
  let arg_wave = "test"
  let edge_wave = "a"
  let resNom = audioMockSinkPlay(arg_sink, arg_freq, arg_dur, arg_wave)
  let resEdge = audioMockSinkPlay(edge_sink, edge_freq, edge_dur, edge_wave)
  assertEqInt(resNom.toneCount, 5, "audioMockSinkPlay nominal resNom.toneCount == 5")
  assertEqInt(resEdge.toneCount, 2, "audioMockSinkPlay boundary resEdge.toneCount == 2")
  ret 0
```

---

### `playChord` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playChord(midiNotes: [int], durationMs: float, volume: float = 0.35): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `midiNotes: [int], durationMs: float, volume: float = 0.35` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `playChord` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `midiNotes: [int] = [1]`, `durationMs: float = 0.5`, `volume: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z60_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playChord_60(): int:
  mut completedCalls = 0
  let arg_midiNotes = [4]
  let edge_midiNotes = []
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_volume = 1.0
  let edge_volume = 0.5
  playChord(arg_midiNotes, arg_durationMs, arg_volume)
  playChord(edge_midiNotes, edge_durationMs, edge_volume)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playChord nominal and boundary void calls completed")
  ret 0
```

---

### `playSpatialTone` (`std/audio/audio_device.aipl`)

- **Signature**: `pub fn playSpatialTone(freq: float, durationMs: float, listenerX: float, listenerY: float, sourceX: float, sourceY: float, maxDist: float, baseVol: float = 0.6): void:`
- **Import**: `import * from "std/audio/audio_device"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `freq: float, durationMs: float, listenerX: float, listenerY: float, sourceX: float, sourceY: float, maxDist: float, baseVol: float = 0.6` | **Returns**: `void`
- **Unit Test**: `tests/functions/audio/audio_device_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `playSpatialTone` (`free fn`) voice pool allocation, play/pause/resume/stop/seek/volume/pitch/pan controls, procedural SFX triggers, and `AudioMockSink` capture. Concrete nominal inputs: `freq: float = 1.0`, `durationMs: float = 0.5`, `listenerX: float = 1.0`, `listenerY: float = 1.0`, `sourceX: float = 1.0`, `sourceY: float = 1.0`, `maxDist: float = 1.0`, `baseVol: float = 1.0`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.audio.audio_device_z61_test
import * from "std/audio/audio_device"
import { clampFloat, clampInt, maxFloat, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { getEnv, setEnv } from "std/os/env"
import { decodeWavPcm16, inspectPcmBuffer } from "std/audio/audio_codec"
import { synthesizeToneBuffer, renderNoiseBuffer, renderSfxPatch, sfxCoin, sfxLaser, sfxExplosion, sfxJump } from "std/audio/audio_synth"
import { mixBufferAt, midiToFrequency } from "std/audio/audio_mixer"
import { audioComputeDistanceGain } from "std/audio/audio_spatial"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_device_playSpatialTone_61(): int:
  mut completedCalls = 0
  let arg_freq = 2.0
  let edge_freq = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_listenerX = 1.0
  let edge_listenerX = 0.5
  let arg_listenerY = 1.0
  let edge_listenerY = 0.5
  let arg_sourceX = 1.0
  let edge_sourceX = 0.5
  let arg_sourceY = 1.0
  let edge_sourceY = 0.5
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let arg_baseVol = 1.0
  let edge_baseVol = 0.5
  playSpatialTone(arg_freq, arg_durationMs, arg_listenerX, arg_listenerY, arg_sourceX, arg_sourceY, arg_maxDist, arg_baseVol)
  playSpatialTone(edge_freq, edge_durationMs, edge_listenerX, edge_listenerY, edge_sourceX, edge_sourceY, edge_maxDist, edge_baseVol)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "playSpatialTone nominal and boundary void calls completed")
  ret 0
```

---

### `createBiquadLowPass` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn createBiquadLowPass(sampleRate: float, cutoffHz: float, q: float = 0.7071): BiquadFilter:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sampleRate: float, cutoffHz: float, q: float = 0.7071` | **Returns**: `BiquadFilter`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `createBiquadLowPass` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `sampleRate: float = 1.0`, `cutoffHz: float = 1.0`, `q: float = 1.0`; exercises core body path returning/computing `BiquadFilter(`.

```aipl
module tests.functions.audio.audio_dsp_z1_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_createBiquadLowPass_1(): int:
  let arg_sampleRate = 2.0
  let edge_sampleRate = 1.0
  let arg_cutoffHz = 2.0
  let edge_cutoffHz = 1.0
  let arg_q = 1.0
  let edge_q = 0.5
  let resNom = createBiquadLowPass(arg_sampleRate, arg_cutoffHz, arg_q)
  let resEdge = createBiquadLowPass(edge_sampleRate, edge_cutoffHz, edge_q)
  assertEqInt(resNom.filterType, 0, "createBiquadLowPass nominal resNom.filterType == 0")
  assertEqInt(resEdge.filterType, 0, "createBiquadLowPass boundary resEdge.filterType == 0")
  ret 0
```

---

### `createBiquadHighPass` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn createBiquadHighPass(sampleRate: float, cutoffHz: float, q: float = 0.7071): BiquadFilter:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sampleRate: float, cutoffHz: float, q: float = 0.7071` | **Returns**: `BiquadFilter`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `createBiquadHighPass` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `sampleRate: float = 1.0`, `cutoffHz: float = 1.0`, `q: float = 1.0`; exercises core body path returning/computing `BiquadFilter(`.

```aipl
module tests.functions.audio.audio_dsp_z2_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_createBiquadHighPass_2(): int:
  let arg_sampleRate = 2.0
  let edge_sampleRate = 1.0
  let arg_cutoffHz = 2.0
  let edge_cutoffHz = 1.0
  let arg_q = 1.0
  let edge_q = 0.5
  let resNom = createBiquadHighPass(arg_sampleRate, arg_cutoffHz, arg_q)
  let resEdge = createBiquadHighPass(edge_sampleRate, edge_cutoffHz, edge_q)
  assertEqInt(resNom.filterType, 1, "createBiquadHighPass nominal resNom.filterType == 1")
  assertEqInt(resEdge.filterType, 1, "createBiquadHighPass boundary resEdge.filterType == 1")
  ret 0
```

---

### `processBiquadSample` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn processBiquadSample(filter: BiquadFilter, sample: float): (BiquadFilter, float):`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `filter: BiquadFilter, sample: float` | **Returns**: `(BiquadFilter, float)`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `processBiquadSample` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `filter: BiquadFilter = BiquadFilter(filterType = 1, b0 = 1.0, b1 = 1.0, b2 = 1.0, a1 = 1.0, a2 = 1.0, x1 = 1.0, x2 = 1.0, y1 = 1.0, y2 = 1.0)`, `sample: float): (BiquadFilter = float): (BiquadFilter()`, `float: any = 42`; exercises core body path returning/computing `(nextFilter, out)`.

```aipl
module tests.functions.audio.audio_dsp_z3_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_processBiquadSample_3(): int:
  let arg_filter = BiquadFilter(filterType = 1, b0 = 1.0, b1 = 1.0, b2 = 1.0, a1 = 1.0, a2 = 1.0, x1 = 1.0, x2 = 1.0, y1 = 1.0, y2 = 1.0)
  let edge_filter = BiquadFilter(filterType = 0, b0 = 0.5, b1 = 0.5, b2 = 0.5, a1 = 0.5, a2 = 0.5, x1 = 0.5, x2 = 0.5, y1 = 0.5, y2 = 0.5)
  let arg_sample = 1.0
  let edge_sample = 0.5
  let resNom = processBiquadSample(arg_filter, arg_sample)
  let resEdge = processBiquadSample(edge_filter, edge_sample)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.filterType, 1, "processBiquadSample nominal n_t0.filterType == 1")
  assertEqInt(e_t0.filterType, 0, "processBiquadSample boundary e_t0.filterType == 0")
  ret 0
```

---

### `createSchroederReverb` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn createSchroederReverb(sampleRate: int, roomSize: float, damp: float): SchroederReverb:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sampleRate: int, roomSize: float, damp: float` | **Returns**: `SchroederReverb`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `createSchroederReverb` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `sampleRate: int = 48000`, `roomSize: float = 1.0`, `damp: float = 1.0`; exercises core body path returning/computing `SchroederReverb(`.

```aipl
module tests.functions.audio.audio_dsp_z4_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_createSchroederReverb_4(): int:
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_roomSize = 1.0
  let edge_roomSize = 0.5
  let arg_damp = 1.0
  let edge_damp = 0.5
  let resNom = createSchroederReverb(arg_sampleRate, arg_roomSize, arg_damp)
  let resEdge = createSchroederReverb(edge_sampleRate, edge_roomSize, edge_damp)
  assertEqInt(resNom.combDelays.len(), 4, "createSchroederReverb nominal resNom.combDelays.len() == 4")
  assertEqInt(resEdge.combDelays.len(), 4, "createSchroederReverb boundary resEdge.combDelays.len() == 4")
  ret 0
```

---

### `processReverbBlock` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn processReverbBlock(reverb: SchroederReverb, samples: [float]): (SchroederReverb, [float]):`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `reverb: SchroederReverb, samples: [float]` | **Returns**: `(SchroederReverb, [float])`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `processReverbBlock` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `reverb: SchroederReverb = SchroederReverb(combDelays = [1], allpassDelays = [1], combBuffers = [[0]], allpassBuffers = [[0]], feedback = 1.0, wetDry = 1.0)`, `samples: [float]): (SchroederReverb = [float]): (SchroederReverb()`, `[float]: any = 42`; exercises core body path returning/computing `(nextRev, out)`.

```aipl
module tests.functions.audio.audio_dsp_z5_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_processReverbBlock_5(): int:
  let arg_reverb = SchroederReverb(combDelays = [], allpassDelays = [], combBuffers = [], allpassBuffers = [], feedback = 1.0, wetDry = 2.0)
  let edge_reverb = SchroederReverb(combDelays = [], allpassDelays = [], combBuffers = [], allpassBuffers = [], feedback = 0.5, wetDry = 1.0)
  let arg_samples = [1.0]
  let edge_samples = []
  let resNom = processReverbBlock(arg_reverb, arg_samples)
  let resEdge = processReverbBlock(edge_reverb, edge_samples)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.combDelays.len(), 0, "processReverbBlock nominal n_t0.combDelays.len() == 0")
  assertEqInt(e_t0.combDelays.len(), 0, "processReverbBlock boundary e_t0.combDelays.len() == 0")
  ret 0
```

---

### `absFloatDsp` (`std/audio/audio_dsp.aipl`)

- **Signature**: `fn absFloatDsp(v: float): float:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `absFloatDsp` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.audio.audio_dsp_z6_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_absFloatDsp_6(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = absFloatDsp(arg_v)
  let resEdge = absFloatDsp(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "absFloatDsp nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "absFloatDsp boundary resEdge ~= 0.5")
  ret 0
```

---

### `applyDynamicCompression` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn applyDynamicCompression(samples: [float], config: CompressorConfig, sampleRate: float): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], config: CompressorConfig, sampleRate: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `applyDynamicCompression` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `config: CompressorConfig = CompressorConfig(thresholdDb = 1.0, ratio = 0.5, attackMs = 1.0, releaseMs = 1.0, makeupGainDb = 1.0)`, `sampleRate: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z7_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_applyDynamicCompression_7(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_config = CompressorConfig(thresholdDb = 2.0, ratio = 1.0, attackMs = 1.0, releaseMs = 1.0, makeupGainDb = 1.0)
  let edge_config = CompressorConfig(thresholdDb = 1.0, ratio = 0.5, attackMs = 0.5, releaseMs = 0.5, makeupGainDb = 0.5)
  let arg_sampleRate = 2.0
  let edge_sampleRate = 1.0
  let resNom = applyDynamicCompression(arg_samples, arg_config, arg_sampleRate)
  let resEdge = applyDynamicCompression(edge_samples, edge_config, edge_sampleRate)
  assertEqInt(resNom.len(), 1, "applyDynamicCompression nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "applyDynamicCompression boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmApplyEcho` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmApplyEcho(samples: [int], delaySamples: int, decay: float): [int]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int], delaySamples: int, decay: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pcmApplyEcho` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [int] = [1]`, `delaySamples: int = 1`, `decay: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z8_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmApplyEcho_8(): int:
  let arg_samples = [4]
  let edge_samples = []
  let arg_delaySamples = 4
  let edge_delaySamples = 1
  let arg_decay = 1.0
  let edge_decay = 0.5
  let resNom = pcmApplyEcho(arg_samples, arg_delaySamples, arg_decay)
  let resEdge = pcmApplyEcho(edge_samples, edge_delaySamples, edge_decay)
  assertEqInt(resNom.len(), 1, "pcmApplyEcho nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "pcmApplyEcho boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmLowPassFilter` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmLowPassFilter(samples: [int], alpha: float): [int]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int], alpha: float` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `pcmLowPassFilter` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [int] = [1]`, `alpha: float = 0.5`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z9_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmLowPassFilter_9(): int:
  let arg_samples = [4]
  let edge_samples = []
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let resNom = pcmLowPassFilter(arg_samples, arg_alpha)
  let resEdge = pcmLowPassFilter(edge_samples, edge_alpha)
  assertEqInt(resNom.len(), 1, "pcmLowPassFilter nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "pcmLowPassFilter boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmComputeRms` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmComputeRms(samples: [int]): float:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [int]` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `pcmComputeRms` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [int] = [1]`; exercises core body path returning/computing `sqrt(sumSq / float(n))`.

```aipl
module tests.functions.audio.audio_dsp_z10_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmComputeRms_10(): int:
  let arg_samples = [4]
  let edge_samples = []
  let resNom = pcmComputeRms(arg_samples)
  let resEdge = pcmComputeRms(edge_samples)
  assertApproxEq(resNom, 4.0, 0.001, "pcmComputeRms nominal resNom ~= 4.0")
  assertApproxEq(resEdge, 0.0, 0.001, "pcmComputeRms boundary resEdge ~= 0.0")
  ret 0
```

---

### `svfNew` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn svfNew(cutoffHz: float, q: float, sampleRate: int): CytomicSvf:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cutoffHz: float, q: float, sampleRate: int` | **Returns**: `CytomicSvf`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `svfNew` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `cutoffHz: float = 1.0`, `q: float = 1.0`, `sampleRate: int = 48000`; exercises core body path returning/computing `CytomicSvf(ic1eq = 0.0, ic2eq = 0.0, a1 = a1, a2 = a2, a3 = a3, k = k)`.

```aipl
module tests.functions.audio.audio_dsp_z11_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_svfNew_11(): int:
  let arg_cutoffHz = 2.0
  let edge_cutoffHz = 1.0
  let arg_q = 1.0
  let edge_q = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = svfNew(arg_cutoffHz, arg_q, arg_sampleRate)
  let resEdge = svfNew(edge_cutoffHz, edge_q, edge_sampleRate)
  assertApproxEq(resNom.ic1eq, 0.0, 0.001, "svfNew nominal resNom.ic1eq ~= 0.0")
  assertApproxEq(resEdge.ic1eq, 0.0, 0.001, "svfNew boundary resEdge.ic1eq ~= 0.0")
  ret 0
```

---

### `fxApplySvf` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn fxApplySvf(samples: [float], filterMode: str, cutoffHz: float, q: float, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], filterMode: str, cutoffHz: float, q: float, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `fxApplySvf` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `filterMode: str = "aipl_test"`, `cutoffHz: float = 1.0`, `q: float = 1.0`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z12_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_fxApplySvf_12(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_filterMode = "test"
  let edge_filterMode = "a"
  let arg_cutoffHz = 2.0
  let edge_cutoffHz = 1.0
  let arg_q = 1.0
  let edge_q = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = fxApplySvf(arg_samples, arg_filterMode, arg_cutoffHz, arg_q, arg_sampleRate)
  let resEdge = fxApplySvf(edge_samples, edge_filterMode, edge_cutoffHz, edge_q, edge_sampleRate)
  assertEqInt(resNom.len(), 1, "fxApplySvf nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "fxApplySvf boundary resEdge.len() == 0")
  ret 0
```

---

### `fxApplyPhaser` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn fxApplyPhaser(samples: [float], lfoRateHz: float, depth: float, feedback: float, mix: float, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], lfoRateHz: float, depth: float, feedback: float, mix: float, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `fxApplyPhaser` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `lfoRateHz: float = 1.0`, `depth: float = 1.0`, `feedback: float = 1.0`, `mix: float = 1.0`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z13_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_fxApplyPhaser_13(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_lfoRateHz = 2.0
  let edge_lfoRateHz = 1.0
  let arg_depth = 2.0
  let edge_depth = 1.0
  let arg_feedback = 1.0
  let edge_feedback = 0.5
  let arg_mix = 1.0
  let edge_mix = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = fxApplyPhaser(arg_samples, arg_lfoRateHz, arg_depth, arg_feedback, arg_mix, arg_sampleRate)
  let resEdge = fxApplyPhaser(edge_samples, edge_lfoRateHz, edge_depth, edge_feedback, edge_mix, edge_sampleRate)
  assertEqInt(resNom.len(), 1, "fxApplyPhaser nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "fxApplyPhaser boundary resEdge.len() == 0")
  ret 0
```

---

### `fxApplyModulatedDelay` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn fxApplyModulatedDelay(samples: [float], baseDelayMs: float, modDepthMs: float, modRateHz: float, feedback: float, mix: float, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], baseDelayMs: float, modDepthMs: float, modRateHz: float, feedback: float, mix: float, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `fxApplyModulatedDelay` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `baseDelayMs: float = 1.0`, `modDepthMs: float = 1.0`, `modRateHz: float = 1.0`, `feedback: float = 1.0`, `mix: float = 1.0`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z14_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_fxApplyModulatedDelay_14(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_baseDelayMs = 1.0
  let edge_baseDelayMs = 0.5
  let arg_modDepthMs = 2.0
  let edge_modDepthMs = 1.0
  let arg_modRateHz = 2.0
  let edge_modRateHz = 1.0
  let arg_feedback = 1.0
  let edge_feedback = 0.5
  let arg_mix = 1.0
  let edge_mix = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = fxApplyModulatedDelay(arg_samples, arg_baseDelayMs, arg_modDepthMs, arg_modRateHz, arg_feedback, arg_mix, arg_sampleRate)
  let resEdge = fxApplyModulatedDelay(edge_samples, edge_baseDelayMs, edge_modDepthMs, edge_modRateHz, edge_feedback, edge_mix, edge_sampleRate)
  assertEqInt(resNom.len(), 1, "fxApplyModulatedDelay nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "fxApplyModulatedDelay boundary resEdge.len() == 0")
  ret 0
```

---

### `fxApplyFreeverb` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn fxApplyFreeverb(samples: [float], roomSize: float, damping: float, wetMix: float): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], roomSize: float, damping: float, wetMix: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `fxApplyFreeverb` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `roomSize: float = 1.0`, `damping: float = 1.0`, `wetMix: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z15_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_fxApplyFreeverb_15(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_roomSize = 1.0
  let edge_roomSize = 0.5
  let arg_damping = 1.0
  let edge_damping = 0.5
  let arg_wetMix = 2.0
  let edge_wetMix = 1.0
  let resNom = fxApplyFreeverb(arg_samples, arg_roomSize, arg_damping, arg_wetMix)
  let resEdge = fxApplyFreeverb(edge_samples, edge_roomSize, edge_damping, edge_wetMix)
  assertEqInt(resNom.len(), 1, "fxApplyFreeverb nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "fxApplyFreeverb boundary resEdge.len() == 0")
  ret 0
```

---

### `fxApplyCompressor` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn fxApplyCompressor(samples: [float], thresholdLin: float, ratio: float, attackMs: float, releaseMs: float, makeupGain: float, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], thresholdLin: float, ratio: float, attackMs: float, releaseMs: float, makeupGain: float, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `fxApplyCompressor` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `thresholdLin: float = 1.0`, `ratio: float = 0.5`, `attackMs: float = 1.0`, `releaseMs: float = 1.0`, `makeupGain: float = 1.0`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z16_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_fxApplyCompressor_16(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_thresholdLin = 2.0
  let edge_thresholdLin = 1.0
  let arg_ratio = 1.0
  let edge_ratio = 0.5
  let arg_attackMs = 1.0
  let edge_attackMs = 0.5
  let arg_releaseMs = 1.0
  let edge_releaseMs = 0.5
  let arg_makeupGain = 1.0
  let edge_makeupGain = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = fxApplyCompressor(arg_samples, arg_thresholdLin, arg_ratio, arg_attackMs, arg_releaseMs, arg_makeupGain, arg_sampleRate)
  let resEdge = fxApplyCompressor(edge_samples, edge_thresholdLin, edge_ratio, edge_attackMs, edge_releaseMs, edge_makeupGain, edge_sampleRate)
  assertEqInt(resNom.len(), 1, "fxApplyCompressor nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "fxApplyCompressor boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmApplyEchoFloat` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmApplyEchoFloat(samples: [float], delaySamples: int, decay: float): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], delaySamples: int, decay: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pcmApplyEchoFloat` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `delaySamples: int = 1`, `decay: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z17_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmApplyEchoFloat_17(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_delaySamples = 4
  let edge_delaySamples = 1
  let arg_decay = 1.0
  let edge_decay = 0.5
  let resNom = pcmApplyEchoFloat(arg_samples, arg_delaySamples, arg_decay)
  let resEdge = pcmApplyEchoFloat(edge_samples, edge_delaySamples, edge_decay)
  assertEqInt(resNom.len(), 1, "pcmApplyEchoFloat nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "pcmApplyEchoFloat boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmLowPassFilterFloat` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmLowPassFilterFloat(samples: [float], alpha: float): [float]:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], alpha: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `pcmLowPassFilterFloat` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`, `alpha: float = 0.5`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_dsp_z18_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmLowPassFilterFloat_18(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_alpha = 2.0
  let edge_alpha = 1.0
  let resNom = pcmLowPassFilterFloat(arg_samples, arg_alpha)
  let resEdge = pcmLowPassFilterFloat(edge_samples, edge_alpha)
  assertEqInt(resNom.len(), 1, "pcmLowPassFilterFloat nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "pcmLowPassFilterFloat boundary resEdge.len() == 0")
  ret 0
```

---

### `pcmComputeRmsFloat` (`std/audio/audio_dsp.aipl`)

- **Signature**: `pub fn pcmComputeRmsFloat(samples: [float]): float:`
- **Import**: `import * from "std/audio/audio_dsp"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float]` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_dsp_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `pcmComputeRmsFloat` biquad low-pass/high-pass filtering, state-variable filter, Schroeder reverb, phaser, delay, and dynamic range compression without NaN/Inf. Concrete nominal inputs: `samples: [float] = [1.0]`; exercises core body path returning/computing `sqrt(sumSq / float(n))`.

```aipl
module tests.functions.audio.audio_dsp_z19_test
import * from "std/audio/audio_dsp"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, tan, sqrt, pow, expFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_dsp_pcmComputeRmsFloat_19(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let resNom = pcmComputeRmsFloat(arg_samples)
  let resEdge = pcmComputeRmsFloat(edge_samples)
  assertApproxEq(resNom, 1.0, 0.001, "pcmComputeRmsFloat nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "pcmComputeRmsFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `clampMix01` (`std/audio/audio_mixer.aipl`)

- **Signature**: `fn clampMix01(v: float): float:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `clampMix01` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.audio.audio_mixer_z1_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_clampMix01_1(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = clampMix01(arg_v)
  let resEdge = clampMix01(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "clampMix01 nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "clampMix01 boundary resEdge ~= 0.5")
  ret 0
```

---

### `createAudioMixer` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn createAudioMixer(maxVoices: int = 32): AudioMixer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `maxVoices: int = 32` | **Returns**: `AudioMixer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `createAudioMixer` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `maxVoices: int = 1`; exercises core body path returning/computing `AudioMixer(`.

```aipl
module tests.functions.audio.audio_mixer_z2_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_createAudioMixer_2(): int:
  let arg_maxVoices = 4
  let edge_maxVoices = 1
  let resNom = createAudioMixer(arg_maxVoices)
  let resEdge = createAudioMixer(edge_maxVoices)
  assertEqInt(resNom.buses.len(), 1, "createAudioMixer nominal resNom.buses.len() == 1")
  assertEqInt(resEdge.buses.len(), 1, "createAudioMixer boundary resEdge.buses.len() == 1")
  ret 0
```

---

### `addMixerBus` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn addMixerBus(mixer: AudioMixer, name: str, parentBusId: int = 0): (AudioMixer, int):`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, name: str, parentBusId: int = 0` | **Returns**: `(AudioMixer, int)`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `addMixerBus` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `name: str = "aipl_test"`, `parentBusId: int = 1`, `int: any = 42`; exercises core body path returning/computing `(nextMixer, newId)`.

```aipl
module tests.functions.audio.audio_mixer_z3_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_addMixerBus_3(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_name = "test"
  let edge_name = "a"
  let arg_parentBusId = 4
  let edge_parentBusId = 1
  let resNom = addMixerBus(arg_mixer, arg_name, arg_parentBusId)
  let resEdge = addMixerBus(edge_mixer, edge_name, edge_parentBusId)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.buses.len(), 1, "addMixerBus nominal n_t0.buses.len() == 1")
  assertEqInt(e_t0.buses.len(), 1, "addMixerBus boundary e_t0.buses.len() == 1")
  ret 0
```

---

### `setBusVolume` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn setBusVolume(mixer: AudioMixer, busId: int, volume: float): AudioMixer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, busId: int, volume: float` | **Returns**: `AudioMixer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `setBusVolume` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `busId: int = 1`, `volume: float = 1.0`; exercises core body path returning/computing `AudioMixer(`.

```aipl
module tests.functions.audio.audio_mixer_z4_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_setBusVolume_4(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_busId = 4
  let edge_busId = 1
  let arg_volume = 1.0
  let edge_volume = 0.5
  let resNom = setBusVolume(arg_mixer, arg_busId, arg_volume)
  let resEdge = setBusVolume(edge_mixer, edge_busId, edge_volume)
  assertEqInt(resNom.buses.len(), 0, "setBusVolume nominal resNom.buses.len() == 0")
  assertEqInt(resEdge.buses.len(), 0, "setBusVolume boundary resEdge.buses.len() == 0")
  ret 0
```

---

### `setBusDucking` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn setBusDucking(mixer: AudioMixer, busId: int, targetBusId: int, duckingDb: float): AudioMixer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, busId: int, targetBusId: int, duckingDb: float` | **Returns**: `AudioMixer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `setBusDucking` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `busId: int = 1`, `targetBusId: int = 1`, `duckingDb: float = 1.0`; exercises core body path returning/computing `AudioMixer(`.

```aipl
module tests.functions.audio.audio_mixer_z5_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_setBusDucking_5(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_busId = 4
  let edge_busId = 1
  let arg_targetBusId = 4
  let edge_targetBusId = 1
  let arg_duckingDb = 1.0
  let edge_duckingDb = 0.5
  let resNom = setBusDucking(arg_mixer, arg_busId, arg_targetBusId, arg_duckingDb)
  let resEdge = setBusDucking(edge_mixer, edge_busId, edge_targetBusId, edge_duckingDb)
  assertEqInt(resNom.buses.len(), 0, "setBusDucking nominal resNom.buses.len() == 0")
  assertEqInt(resEdge.buses.len(), 0, "setBusDucking boundary resEdge.buses.len() == 0")
  ret 0
```

---

### `playAudioVoice` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn playAudioVoice(mixer: AudioMixer, bufferId: int, busId: int, volume: float = 1.0, pitch: float = 1.0, loop: bool = false): (AudioMixer, int):`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, bufferId: int, busId: int, volume: float = 1.0, pitch: float = 1.0, loop: bool = false` | **Returns**: `(AudioMixer, int)`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `playAudioVoice` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `bufferId: int = 1`, `busId: int = 1`, `volume: float = 1.0`, `pitch: float = 1.0`, `loop: bool = true`, `int: any = 42`; exercises core body path returning/computing `(nextMixer, voiceId)`.

```aipl
module tests.functions.audio.audio_mixer_z6_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_playAudioVoice_6(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_bufferId = 4
  let edge_bufferId = 1
  let arg_busId = 4
  let edge_busId = 1
  let arg_volume = 1.0
  let edge_volume = 0.5
  let arg_pitch = 2.0
  let edge_pitch = 1.0
  let arg_loop = true
  let edge_loop = false
  let resNom = playAudioVoice(arg_mixer, arg_bufferId, arg_busId, arg_volume, arg_pitch, arg_loop)
  let resEdge = playAudioVoice(edge_mixer, edge_bufferId, edge_busId, edge_volume, edge_pitch, edge_loop)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.buses.len(), 0, "playAudioVoice nominal n_t0.buses.len() == 0")
  assertEqInt(e_t0.buses.len(), 0, "playAudioVoice boundary e_t0.buses.len() == 0")
  ret 0
```

---

### `stopAudioVoice` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn stopAudioVoice(mixer: AudioMixer, voiceId: int): AudioMixer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, voiceId: int` | **Returns**: `AudioMixer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `stopAudioVoice` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `voiceId: int = 1`; exercises core body path returning/computing `AudioMixer(`.

```aipl
module tests.functions.audio.audio_mixer_z7_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_stopAudioVoice_7(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_voiceId = 1
  let edge_voiceId = 0
  let resNom = stopAudioVoice(arg_mixer, arg_voiceId)
  let resEdge = stopAudioVoice(edge_mixer, edge_voiceId)
  assertEqInt(resNom.buses.len(), 0, "stopAudioVoice nominal resNom.buses.len() == 0")
  assertEqInt(resEdge.buses.len(), 0, "stopAudioVoice boundary resEdge.buses.len() == 0")
  ret 0
```

---

### `mixAudioBlock` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn mixAudioBlock(mixer: AudioMixer, mut outBuffer: [float], framesToRender: int): AudioMixer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mixer: AudioMixer, mut outBuffer: [float], framesToRender: int` | **Returns**: `AudioMixer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `mixAudioBlock` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `mixer: AudioMixer = AudioMixer(buses = [AudioBus(id = 0, name = 0, volume = 0, mute = 0, parentBusId = 0, duckingFactor = 0, peakLevelLeft = 0, peakLevelRight = 0)], voices = [AudioVoice(id = 0, bufferId = 0, busId = 0, playbackPositionSamples = 0, totalSamples = 0, pitch = 0, volume = 0, isLooping = 0, isPlaying = 0)], maxVoices = 1, masterVolume = 1.0)`, `outBuffer: [float] = [1.0]`, `framesToRender: int = 64`; exercises core body path returning/computing `AudioMixer(`.

```aipl
module tests.functions.audio.audio_mixer_z8_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_mixAudioBlock_8(): int:
  let arg_mixer = AudioMixer(buses = [], voices = [], maxVoices = 4, masterVolume = 1.0)
  let edge_mixer = AudioMixer(buses = [], voices = [], maxVoices = 1, masterVolume = 0.5)
  let arg_outBuffer = [1.0]
  let edge_outBuffer = []
  let arg_framesToRender = 4
  let edge_framesToRender = 1
  let resNom = mixAudioBlock(arg_mixer, arg_outBuffer, arg_framesToRender)
  let resEdge = mixAudioBlock(edge_mixer, edge_outBuffer, edge_framesToRender)
  assertEqInt(resNom.buses.len(), 0, "mixAudioBlock nominal resNom.buses.len() == 0")
  assertEqInt(resEdge.buses.len(), 0, "mixAudioBlock boundary resEdge.buses.len() == 0")
  ret 0
```

---

### `noteNameToMidi` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn noteNameToMidi(noteName: str): int:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `noteName: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `noteNameToMidi` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `noteName: str = "aipl_test"`; exercises core body path returning/computing `(octave + 1) * 12 + base + accidental`.

```aipl
module tests.functions.audio.audio_mixer_z9_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_noteNameToMidi_9(): int:
  let arg_noteName = "test"
  let edge_noteName = "a"
  let resNom = noteNameToMidi(arg_noteName)
  let resEdge = noteNameToMidi(edge_noteName)
  assertEqInt(resNom, 0, "noteNameToMidi nominal resNom == 0")
  assertEqInt(resEdge, 69, "noteNameToMidi boundary resEdge == 69")
  ret 0
```

---

### `midiToFrequency` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn midiToFrequency(midiNote: int): float:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `midiNote: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `midiToFrequency` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `midiNote: int = 1`; exercises core body path returning/computing `440.0 * pow(2.0, float(midiNote - 69) / 12.0)`.

```aipl
module tests.functions.audio.audio_mixer_z10_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_midiToFrequency_10(): int:
  let arg_midiNote = 4
  let edge_midiNote = 1
  let resNom = midiToFrequency(arg_midiNote)
  let resEdge = midiToFrequency(edge_midiNote)
  assertApproxEq(resNom, 10.3009, 0.001, "midiToFrequency nominal resNom ~= 10.3009")
  assertApproxEq(resEdge, 8.66196, 0.001, "midiToFrequency boundary resEdge ~= 8.66196")
  ret 0
```

---

### `sequencerNew` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn sequencerNew(bpm: float, pattern: [int]): StepSequencer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bpm: float, pattern: [int]` | **Returns**: `StepSequencer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `sequencerNew` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `bpm: float = 1.0`, `pattern: [int] = [1]`; exercises core body path returning/computing `StepSequencer(`.

```aipl
module tests.functions.audio.audio_mixer_z11_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_sequencerNew_11(): int:
  let arg_bpm = 1.0
  let edge_bpm = 0.5
  let arg_pattern = [4]
  let edge_pattern = []
  let resNom = sequencerNew(arg_bpm, arg_pattern)
  let resEdge = sequencerNew(edge_bpm, edge_pattern)
  assertApproxEq(resNom.bpm, 1.0, 0.001, "sequencerNew nominal resNom.bpm ~= 1.0")
  assertApproxEq(resEdge.bpm, 0.5, 0.001, "sequencerNew boundary resEdge.bpm ~= 0.5")
  ret 0
```

---

### `sequencerStep` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn sequencerStep(seq: StepSequencer, dtMs: float): StepSequencer:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seq: StepSequencer, dtMs: float` | **Returns**: `StepSequencer`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `sequencerStep` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `seq: StepSequencer = StepSequencer(bpm = 1.0, stepIndex = 0, accumMs = 1.0, pattern = [1], noteRatio = 0.5, playing = true)`, `dtMs: float = 0.016667`; exercises core body path returning/computing `StepSequencer(`.

```aipl
module tests.functions.audio.audio_mixer_z12_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_sequencerStep_12(): int:
  let arg_seq = StepSequencer(bpm = 1.0, stepIndex = 4, accumMs = 1.0, pattern = [], noteRatio = 1.0, playing = true)
  let edge_seq = StepSequencer(bpm = 0.5, stepIndex = 1, accumMs = 0.5, pattern = [], noteRatio = 0.5, playing = false)
  let arg_dtMs = 2.0
  let edge_dtMs = 1.0
  let resNom = sequencerStep(arg_seq, arg_dtMs)
  let resEdge = sequencerStep(edge_seq, edge_dtMs)
  assertApproxEq(resNom.bpm, 1.0, 0.001, "sequencerStep nominal resNom.bpm ~= 1.0")
  assertApproxEq(resEdge.bpm, 0.5, 0.001, "sequencerStep boundary resEdge.bpm ~= 0.5")
  ret 0
```

---

### `euclideanRhythm` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn euclideanRhythm(pulses: int, steps: int): [int]:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pulses: int, steps: int` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `euclideanRhythm` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `pulses: int = 1`, `steps: int = 1`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_mixer_z13_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_euclideanRhythm_13(): int:
  let arg_pulses = 2
  let edge_pulses = 0
  let arg_steps = 4
  let edge_steps = 1
  let resNom = euclideanRhythm(arg_pulses, arg_steps)
  let resEdge = euclideanRhythm(edge_pulses, edge_steps)
  assertEqInt(resNom.len(), 4, "euclideanRhythm nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "euclideanRhythm boundary resEdge.len() == 1")
  ret 0
```

---

### `scaleIntervals` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn scaleIntervals(scaleName: str): [int]:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `scaleName: str` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `scaleIntervals` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `scaleName: str = "aipl_test"`; exercises core body path returning/computing `[0, 2, 4, 5, 7, 9, 11]`.

```aipl
module tests.functions.audio.audio_mixer_z14_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_scaleIntervals_14(): int:
  let arg_scaleName = "42"
  let edge_scaleName = "0"
  let resNom = scaleIntervals(arg_scaleName)
  let resEdge = scaleIntervals(edge_scaleName)
  assertEqInt(resNom.len(), 7, "scaleIntervals nominal resNom.len() == 7")
  assertEqInt(resEdge.len(), 7, "scaleIntervals boundary resEdge.len() == 7")
  ret 0
```

---

### `scaleDegreeToMidi` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn scaleDegreeToMidi(rootMidi: int, scaleName: str, degree: int): int:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootMidi: int, scaleName: str, degree: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `scaleDegreeToMidi` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `rootMidi: int = 1`, `scaleName: str = "aipl_test"`, `degree: int = 1`; exercises core body path returning/computing `rootMidi + oct * 12 + intervals[idx]`.

```aipl
module tests.functions.audio.audio_mixer_z15_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_scaleDegreeToMidi_15(): int:
  let arg_rootMidi = 4
  let edge_rootMidi = 1
  let arg_scaleName = "test"
  let edge_scaleName = "a"
  let arg_degree = 2
  let edge_degree = 0
  let resNom = scaleDegreeToMidi(arg_rootMidi, arg_scaleName, arg_degree)
  let resEdge = scaleDegreeToMidi(edge_rootMidi, edge_scaleName, edge_degree)
  assertEqInt(resNom, 8, "scaleDegreeToMidi nominal resNom == 8")
  assertEqInt(resEdge, 1, "scaleDegreeToMidi boundary resEdge == 1")
  ret 0
```

---

### `buildChordMidi` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn buildChordMidi(rootMidi: int, chordKind: str): [int]:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rootMidi: int, chordKind: str` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `buildChordMidi` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `rootMidi: int = 1`, `chordKind: str = "aipl_test"`; exercises core body path returning/computing `[rootMidi, rootMidi + 4, rootMidi + 7]`.

```aipl
module tests.functions.audio.audio_mixer_z16_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_buildChordMidi_16(): int:
  let arg_rootMidi = 4
  let edge_rootMidi = 1
  let arg_chordKind = "test"
  let edge_chordKind = "a"
  let resNom = buildChordMidi(arg_rootMidi, arg_chordKind)
  let resEdge = buildChordMidi(edge_rootMidi, edge_chordKind)
  assertEqInt(resNom.len(), 3, "buildChordMidi nominal resNom.len() == 3")
  assertEqInt(resEdge.len(), 3, "buildChordMidi boundary resEdge.len() == 3")
  ret 0
```

---

### `mixBufferAt` (`std/audio/audio_mixer.aipl`)

- **Signature**: `pub fn mixBufferAt(dst: [float], src: [float], startSample: int, gain: float): [float]:`
- **Import**: `import * from "std/audio/audio_mixer"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dst: [float], src: [float], startSample: int, gain: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_mixer_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `mixBufferAt` multi-bus gain mixing, sidechain ducking attenuation, MIDI-to-Hz (`A4 = 69 -> 440.0 Hz`), and Bjorklund Euclidean rhythm generation. Concrete nominal inputs: `dst: [float] = [1.0]`, `src: [float] = [1.0]`, `startSample: int = 1`, `gain: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_mixer_z17_test
import * from "std/audio/audio_mixer"
import { clampFloat, clampInt, maxInt } from "std/math/consts"
import { pow } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_mixer_mixBufferAt_17(): int:
  let arg_dst = [1.0]
  let edge_dst = []
  let arg_src = [1.0]
  let edge_src = []
  let arg_startSample = 4
  let edge_startSample = 1
  let arg_gain = 1.0
  let edge_gain = 0.5
  let resNom = mixBufferAt(arg_dst, arg_src, arg_startSample, arg_gain)
  let resEdge = mixBufferAt(edge_dst, edge_src, edge_startSample, edge_gain)
  assertEqInt(resNom.len(), 5, "mixBufferAt nominal resNom.len() == 5")
  assertEqInt(resEdge.len(), 1, "mixBufferAt boundary resEdge.len() == 1")
  ret 0
```

---

### `createAudioListener3D` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn createAudioListener3D(): AudioListener3D:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `AudioListener3D`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `createAudioListener3D` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `AudioListener3D(`.

```aipl
module tests.functions.audio.audio_spatial_z1_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_createAudioListener3D_1(): int:
  let resNom = createAudioListener3D()
  let resEdge = createAudioListener3D()
  assertApproxEq(resNom.x, 0.0, 0.001, "createAudioListener3D nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "createAudioListener3D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `createAudioEmitter3D` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn createAudioEmitter3D(minDist: float = 1.0, maxDist: float = 50.0): AudioEmitter3D:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minDist: float = 1.0, maxDist: float = 50.0` | **Returns**: `AudioEmitter3D`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `createAudioEmitter3D` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `minDist: float = 1.0`, `maxDist: float = 1.0`; exercises core body path returning/computing `AudioEmitter3D(`.

```aipl
module tests.functions.audio.audio_spatial_z2_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_createAudioEmitter3D_2(): int:
  let arg_minDist = 0.0
  let edge_minDist = 0.0
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let resNom = createAudioEmitter3D(arg_minDist, arg_maxDist)
  let resEdge = createAudioEmitter3D(edge_minDist, edge_maxDist)
  assertApproxEq(resNom.x, 0.0, 0.001, "createAudioEmitter3D nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "createAudioEmitter3D boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `computeInverseDistanceAttenuation` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeInverseDistanceAttenuation(distance: float, minDist: float, maxDist: float, rolloff: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `distance: float, minDist: float, maxDist: float, rolloff: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `computeInverseDistanceAttenuation` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `distance: float = 1.0`, `minDist: float = 1.0`, `maxDist: float = 1.0`, `rolloff: float = 1.0`; exercises core body path returning/computing `dMin / denom`.

```aipl
module tests.functions.audio.audio_spatial_z3_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeInverseDistanceAttenuation_3(): int:
  let arg_distance = 1.0
  let edge_distance = 0.5
  let arg_minDist = 0.0
  let edge_minDist = 0.0
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let arg_rolloff = 0.0
  let edge_rolloff = 0.0
  let resNom = computeInverseDistanceAttenuation(arg_distance, arg_minDist, arg_maxDist, arg_rolloff)
  let resEdge = computeInverseDistanceAttenuation(edge_distance, edge_minDist, edge_maxDist, edge_rolloff)
  assertApproxEq(resNom, 1.0, 0.001, "computeInverseDistanceAttenuation nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "computeInverseDistanceAttenuation boundary resEdge ~= 1.0")
  ret 0
```

---

### `computeDopplerFactor` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeDopplerFactor(listenerVel: float, emitterVel: float, speedOfSound: float = 343.0): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `listenerVel: float, emitterVel: float, speedOfSound: float = 343.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `computeDopplerFactor` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `listenerVel: float = 1.0`, `emitterVel: float = 1.0`, `speedOfSound: float = 1.0`; exercises core body path returning/computing `(c + vl) / (c - vs)`.

```aipl
module tests.functions.audio.audio_spatial_z4_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeDopplerFactor_4(): int:
  let arg_listenerVel = 1.0
  let edge_listenerVel = 0.5
  let arg_emitterVel = 1.0
  let edge_emitterVel = 0.5
  let arg_speedOfSound = 1.0
  let edge_speedOfSound = 0.5
  let resNom = computeDopplerFactor(arg_listenerVel, arg_emitterVel, arg_speedOfSound)
  let resEdge = computeDopplerFactor(edge_listenerVel, edge_emitterVel, edge_speedOfSound)
  assertApproxEq(resNom, 1.00585, 0.001, "computeDopplerFactor nominal resNom ~= 1.00585")
  assertApproxEq(resEdge, 1.00292, 0.001, "computeDopplerFactor boundary resEdge ~= 1.00292")
  ret 0
```

---

### `computeSpatialGain` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeSpatialGain(listener: AudioListener3D, emitter: AudioEmitter3D, speedOfSound: float = 343.0): SpatialGain:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `listener: AudioListener3D, emitter: AudioEmitter3D, speedOfSound: float = 343.0` | **Returns**: `SpatialGain`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `computeSpatialGain` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `listener: AudioListener3D = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = float = 0.0(), velY = float = 0.0(), velZ = float = 0.0(), vx = float = 0.0(), vy = float = 0.0(), vz = float = 0.0(), rightX = float = 1.0(), rightY = float = 0.0(), rightZ = float = 0.0())`, `emitter: AudioEmitter3D = AudioEmitter3D(x = 1.0, y = 1.0, z = 1.0, velX = 1.0, velY = 1.0, velZ = 1.0, minDistance = 1.0, maxDistance = 1.0, rolloffFactor = 1.0, coneInnerAngleDeg = 1.0, coneOuterAngleDeg = 1.0, coneOuterGain = 1.0)`, `speedOfSound: float = 1.0`; exercises core body path returning/computing `SpatialGain(gainLeft = gainL, gainRight = gainR, dopplerPitchShift = doppler)`.

```aipl
module tests.functions.audio.audio_spatial_z5_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeSpatialGain_5(): int:
  let arg_listener = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 2.0, forwardY = 2.0, forwardZ = 2.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = 1.0, velY = 1.0, velZ = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, rightX = 2.0, rightY = 2.0, rightZ = 2.0)
  let edge_listener = AudioListener3D(x = 0.5, y = 0.5, z = 0.5, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 0.5, upY = 0.5, upZ = 0.5, velX = 0.5, velY = 0.5, velZ = 0.5, vx = 0.5, vy = 0.5, vz = 0.5, rightX = 1.0, rightY = 1.0, rightZ = 1.0)
  let arg_emitter = AudioEmitter3D(x = 1.0, y = 1.0, z = 1.0, velX = 1.0, velY = 1.0, velZ = 1.0, minDistance = 0.0, maxDistance = 2.0, rolloffFactor = 0.0, coneInnerAngleDeg = 1.0, coneOuterAngleDeg = 1.0, coneOuterGain = 1.0)
  let edge_emitter = AudioEmitter3D(x = 0.5, y = 0.5, z = 0.5, velX = 0.5, velY = 0.5, velZ = 0.5, minDistance = 0.0, maxDistance = 1.0, rolloffFactor = 0.0, coneInnerAngleDeg = 0.5, coneOuterAngleDeg = 0.5, coneOuterGain = 0.5)
  let arg_speedOfSound = 1.0
  let edge_speedOfSound = 0.5
  let resNom = computeSpatialGain(arg_listener, arg_emitter, arg_speedOfSound)
  let resEdge = computeSpatialGain(edge_listener, edge_emitter, edge_speedOfSound)
  assertApproxEq(resNom.gainLeft, 0.7071, 0.001, "computeSpatialGain nominal resNom.gainLeft ~= 0.7071")
  assertApproxEq(resEdge.gainLeft, 0.7071, 0.001, "computeSpatialGain boundary resEdge.gainLeft ~= 0.7071")
  ret 0
```

---

### `computeStereoPan` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeStereoPan(listenerX: float, sourceX: float, maxSpread: float): [float]:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `listenerX: float, sourceX: float, maxSpread: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `computeStereoPan` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `listenerX: float = 1.0`, `sourceX: float = 1.0`, `maxSpread: float = 1.0`; exercises core body path returning/computing `[cos(angle), sin(angle)]`.

```aipl
module tests.functions.audio.audio_spatial_z6_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeStereoPan_6(): int:
  let arg_listenerX = 1.0
  let edge_listenerX = 0.5
  let arg_sourceX = 1.0
  let edge_sourceX = 0.5
  let arg_maxSpread = 2.0
  let edge_maxSpread = 1.0
  let resNom = computeStereoPan(arg_listenerX, arg_sourceX, arg_maxSpread)
  let resEdge = computeStereoPan(edge_listenerX, edge_sourceX, edge_maxSpread)
  assertEqInt(resNom.len(), 2, "computeStereoPan nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "computeStereoPan boundary resEdge.len() == 2")
  ret 0
```

---

### `computeDopplerPitch` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeDopplerPitch(baseFreq: float, relVelocityTowardListener: float, soundSpeed: float = 343.0): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseFreq: float, relVelocityTowardListener: float, soundSpeed: float = 343.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `computeDopplerPitch` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `baseFreq: float = 1.0`, `relVelocityTowardListener: float = 1.0`, `soundSpeed: float = 1.0`; exercises core body path returning/computing `baseFreq * (soundSpeed / safeDenom)`.

```aipl
module tests.functions.audio.audio_spatial_z7_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeDopplerPitch_7(): int:
  let arg_baseFreq = 2.0
  let edge_baseFreq = 1.0
  let arg_relVelocityTowardListener = 0.0
  let edge_relVelocityTowardListener = 0.0
  let arg_soundSpeed = 1.0
  let edge_soundSpeed = 0.5
  let resNom = computeDopplerPitch(arg_baseFreq, arg_relVelocityTowardListener, arg_soundSpeed)
  let resEdge = computeDopplerPitch(edge_baseFreq, edge_relVelocityTowardListener, edge_soundSpeed)
  assertApproxEq(resNom, 0.2, 0.001, "computeDopplerPitch nominal resNom ~= 0.2")
  assertApproxEq(resEdge, 0.05, 0.001, "computeDopplerPitch boundary resEdge ~= 0.05")
  ret 0
```

---

### `spatial3dAttenuation` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn spatial3dAttenuation(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float = 1.0, maxDist: float = 100.0, rollOff: float = 1.0): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float = 1.0, maxDist: float = 100.0, rollOff: float = 1.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `spatial3dAttenuation` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `srcX: float = 1.0`, `srcY: float = 1.0`, `srcZ: float = 1.0`, `lisX: float = 1.0`, `lisY: float = 1.0`, `lisZ: float = 1.0`, `minDist: float = 1.0`, `maxDist: float = 1.0`, `rollOff: float = 1.0`; exercises core body path returning/computing `clampFloat(gain, 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_spatial_z8_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_spatial3dAttenuation_8(): int:
  let arg_srcX = 1.0
  let edge_srcX = 0.5
  let arg_srcY = 1.0
  let edge_srcY = 0.5
  let arg_srcZ = 1.0
  let edge_srcZ = 0.5
  let arg_lisX = 1.0
  let edge_lisX = 0.5
  let arg_lisY = 1.0
  let edge_lisY = 0.5
  let arg_lisZ = 1.0
  let edge_lisZ = 0.5
  let arg_minDist = 0.0
  let edge_minDist = 0.0
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let arg_rollOff = 0.0
  let edge_rollOff = 0.0
  let resNom = spatial3dAttenuation(arg_srcX, arg_srcY, arg_srcZ, arg_lisX, arg_lisY, arg_lisZ, arg_minDist, arg_maxDist, arg_rollOff)
  let resEdge = spatial3dAttenuation(edge_srcX, edge_srcY, edge_srcZ, edge_lisX, edge_lisY, edge_lisZ, edge_minDist, edge_maxDist, edge_rollOff)
  assertApproxEq(resNom, 1.0, 0.001, "spatial3dAttenuation nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "spatial3dAttenuation boundary resEdge ~= 1.0")
  ret 0
```

---

### `spatial3dPan` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn spatial3dPan(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, lisYawRad: float = 0.0, maxSpread: float = 0.0): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, lisYawRad: float = 0.0, maxSpread: float = 0.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `spatial3dPan` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `srcX: float = 1.0`, `srcY: float = 1.0`, `srcZ: float = 1.0`, `lisX: float = 1.0`, `lisY: float = 1.0`, `lisZ: float = 1.0`, `lisYawRad: float = 1.0`, `maxSpread: float = 1.0`; exercises core body path returning/computing `clampFloat(float(relX) / float(distH), -1.0, 1.0)`.

```aipl
module tests.functions.audio.audio_spatial_z9_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_spatial3dPan_9(): int:
  let arg_srcX = 1.0
  let edge_srcX = 0.5
  let arg_srcY = 1.0
  let edge_srcY = 0.5
  let arg_srcZ = 1.0
  let edge_srcZ = 0.5
  let arg_lisX = 1.0
  let edge_lisX = 0.5
  let arg_lisY = 1.0
  let edge_lisY = 0.5
  let arg_lisZ = 1.0
  let edge_lisZ = 0.5
  let arg_lisYawRad = 2.0
  let edge_lisYawRad = 1.0
  let arg_maxSpread = 2.0
  let edge_maxSpread = 1.0
  let resNom = spatial3dPan(arg_srcX, arg_srcY, arg_srcZ, arg_lisX, arg_lisY, arg_lisZ, arg_lisYawRad, arg_maxSpread)
  let resEdge = spatial3dPan(edge_srcX, edge_srcY, edge_srcZ, edge_lisX, edge_lisY, edge_lisZ, edge_lisYawRad, edge_maxSpread)
  assertApproxEq(resNom, 0.0, 0.001, "spatial3dPan nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "spatial3dPan boundary resEdge ~= 0.0")
  ret 0
```

---

### `audioComputeDistanceGain` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeDistanceGain(srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float, maxDist: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `srcX: float, srcY: float, srcZ: float, lisX: float, lisY: float, lisZ: float, minDist: float, maxDist: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `audioComputeDistanceGain` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `srcX: float = 1.0`, `srcY: float = 1.0`, `srcZ: float = 1.0`, `lisX: float = 1.0`, `lisY: float = 1.0`, `lisZ: float = 1.0`, `minDist: float = 1.0`, `maxDist: float = 1.0`; exercises core body path returning/computing `clampFloat(invLin * invLin, 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_spatial_z10_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeDistanceGain_10(): int:
  let arg_srcX = 1.0
  let edge_srcX = 0.5
  let arg_srcY = 1.0
  let edge_srcY = 0.5
  let arg_srcZ = 1.0
  let edge_srcZ = 0.5
  let arg_lisX = 1.0
  let edge_lisX = 0.5
  let arg_lisY = 1.0
  let edge_lisY = 0.5
  let arg_lisZ = 1.0
  let edge_lisZ = 0.5
  let arg_minDist = 0.0
  let edge_minDist = 0.0
  let arg_maxDist = 2.0
  let edge_maxDist = 1.0
  let resNom = audioComputeDistanceGain(arg_srcX, arg_srcY, arg_srcZ, arg_lisX, arg_lisY, arg_lisZ, arg_minDist, arg_maxDist)
  let resEdge = audioComputeDistanceGain(edge_srcX, edge_srcY, edge_srcZ, edge_lisX, edge_lisY, edge_lisZ, edge_minDist, edge_maxDist)
  assertApproxEq(resNom, 1.0, 0.001, "audioComputeDistanceGain nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "audioComputeDistanceGain boundary resEdge ~= 1.0")
  ret 0
```

---

### `audioComputeStereoPan2D` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeStereoPan2D(srcX: float, srcY: float, lisX: float, lisY: float, lisYawRad: float, maxPanDist: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `srcX: float, srcY: float, lisX: float, lisY: float, lisYawRad: float, maxPanDist: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioComputeStereoPan2D` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `srcX: float = 1.0`, `srcY: float = 1.0`, `lisX: float = 1.0`, `lisY: float = 1.0`, `lisYawRad: float = 1.0`, `maxPanDist: float = 1.0`; exercises core body path returning/computing `clampFloat(float(rightProj) / float(safeMax), -1.0, 1.0)`.

```aipl
module tests.functions.audio.audio_spatial_z11_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeStereoPan2D_11(): int:
  let arg_srcX = 1.0
  let edge_srcX = 0.5
  let arg_srcY = 1.0
  let edge_srcY = 0.5
  let arg_lisX = 1.0
  let edge_lisX = 0.5
  let arg_lisY = 1.0
  let edge_lisY = 0.5
  let arg_lisYawRad = 2.0
  let edge_lisYawRad = 1.0
  let arg_maxPanDist = 2.0
  let edge_maxPanDist = 1.0
  let resNom = audioComputeStereoPan2D(arg_srcX, arg_srcY, arg_lisX, arg_lisY, arg_lisYawRad, arg_maxPanDist)
  let resEdge = audioComputeStereoPan2D(edge_srcX, edge_srcY, edge_lisX, edge_lisY, edge_lisYawRad, edge_maxPanDist)
  assertApproxEq(resNom, 0.0, 0.001, "audioComputeStereoPan2D nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "audioComputeStereoPan2D boundary resEdge ~= 0.0")
  ret 0
```

---

### `audioComputeDopplerPitchMultiplier` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeDopplerPitchMultiplier(srcX: float, srcY: float, srcVx: float, srcVy: float, lisX: float, lisY: float, lisVx: float, lisVy: float, speedOfSound: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `srcX: float, srcY: float, srcVx: float, srcVy: float, lisX: float, lisY: float, lisVx: float, lisVy: float, speedOfSound: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `audioComputeDopplerPitchMultiplier` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `srcX: float = 1.0`, `srcY: float = 1.0`, `srcVx: float = 1.0`, `srcVy: float = 1.0`, `lisX: float = 1.0`, `lisY: float = 1.0`, `lisVx: float = 1.0`, `lisVy: float = 1.0`, `speedOfSound: float = 1.0`; exercises core body path returning/computing `clampFloat(float(num) / float(den), 0.5, 2.0)`.

```aipl
module tests.functions.audio.audio_spatial_z12_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeDopplerPitchMultiplier_12(): int:
  let arg_srcX = 1.0
  let edge_srcX = 0.5
  let arg_srcY = 1.0
  let edge_srcY = 0.5
  let arg_srcVx = 1.0
  let edge_srcVx = 0.5
  let arg_srcVy = 1.0
  let edge_srcVy = 0.5
  let arg_lisX = 1.0
  let edge_lisX = 0.5
  let arg_lisY = 1.0
  let edge_lisY = 0.5
  let arg_lisVx = 1.0
  let edge_lisVx = 0.5
  let arg_lisVy = 1.0
  let edge_lisVy = 0.5
  let arg_speedOfSound = 1.0
  let edge_speedOfSound = 0.5
  let resNom = audioComputeDopplerPitchMultiplier(arg_srcX, arg_srcY, arg_srcVx, arg_srcVy, arg_lisX, arg_lisY, arg_lisVx, arg_lisVy, arg_speedOfSound)
  let resEdge = audioComputeDopplerPitchMultiplier(edge_srcX, edge_srcY, edge_srcVx, edge_srcVy, edge_lisX, edge_lisY, edge_lisVx, edge_lisVy, edge_speedOfSound)
  assertApproxEq(resNom, 1.0, 0.001, "audioComputeDopplerPitchMultiplier nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "audioComputeDopplerPitchMultiplier boundary resEdge ~= 1.0")
  ret 0
```

---

### `audioComputeWallOcclusionLowpass` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeWallOcclusionLowpass(wallHits: int, baseCutoffHz: float, attenuationPerWall: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `wallHits: int, baseCutoffHz: float, attenuationPerWall: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `audioComputeWallOcclusionLowpass` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `wallHits: int = 1`, `baseCutoffHz: float = 1.0`, `attenuationPerWall: float = 1.0`; exercises core body path returning/computing `maxFloat(120.0, droppedHz)`.

```aipl
module tests.functions.audio.audio_spatial_z13_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeWallOcclusionLowpass_13(): int:
  let arg_wallHits = 2
  let edge_wallHits = 0
  let arg_baseCutoffHz = 2.0
  let edge_baseCutoffHz = 1.0
  let arg_attenuationPerWall = 2.0
  let edge_attenuationPerWall = 1.0
  let resNom = audioComputeWallOcclusionLowpass(arg_wallHits, arg_baseCutoffHz, arg_attenuationPerWall)
  let resEdge = audioComputeWallOcclusionLowpass(edge_wallHits, edge_baseCutoffHz, edge_attenuationPerWall)
  assertApproxEq(resNom, 120.0, 0.001, "audioComputeWallOcclusionLowpass nominal resNom ~= 120.0")
  assertApproxEq(resEdge, 120.0, 0.001, "audioComputeWallOcclusionLowpass boundary resEdge ~= 120.0")
  ret 0
```

---

### `audioComputeReverbDecayGain` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeReverbDecayGain(elapsedMs: float, rt60Ms: float, wetMix: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `elapsedMs: float, rt60Ms: float, wetMix: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioComputeReverbDecayGain` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `elapsedMs: float = 1.0`, `rt60Ms: float = 1.0`, `wetMix: float = 1.0`; exercises core body path returning/computing `clampFloat(envelope * mix, 0.0, 1.0)`.

```aipl
module tests.functions.audio.audio_spatial_z14_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeReverbDecayGain_14(): int:
  let arg_elapsedMs = 1.0
  let edge_elapsedMs = 0.5
  let arg_rt60Ms = 1.0
  let edge_rt60Ms = 0.5
  let arg_wetMix = 2.0
  let edge_wetMix = 1.0
  let resNom = audioComputeReverbDecayGain(arg_elapsedMs, arg_rt60Ms, arg_wetMix)
  let resEdge = audioComputeReverbDecayGain(edge_elapsedMs, edge_rt60Ms, edge_wetMix)
  assertApproxEq(resNom, 0.0, 0.001, "audioComputeReverbDecayGain nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.125, 0.001, "audioComputeReverbDecayGain boundary resEdge ~= 0.125")
  ret 0
```

---

### `audioComputeThunderDelaySeconds` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeThunderDelaySeconds(distanceMeters: float): float:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `distanceMeters: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `audioComputeThunderDelaySeconds` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `distanceMeters: float = 1.0`; exercises core body path returning/computing `d / 343.0`.

```aipl
module tests.functions.audio.audio_spatial_z15_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeThunderDelaySeconds_15(): int:
  let arg_distanceMeters = 1.0
  let edge_distanceMeters = 0.5
  let resNom = audioComputeThunderDelaySeconds(arg_distanceMeters)
  let resEdge = audioComputeThunderDelaySeconds(edge_distanceMeters)
  assertApproxEq(resNom, 0.002915, 0.001, "audioComputeThunderDelaySeconds nominal resNom ~= 0.002915")
  assertApproxEq(resEdge, 0.001458, 0.001, "audioComputeThunderDelaySeconds boundary resEdge ~= 0.001458")
  ret 0
```

---

### `audioComputeCountdownBeepIntervalMs` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioComputeCountdownBeepIntervalMs(remainingSec: float): int:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `remainingSec: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `audioComputeCountdownBeepIntervalMs` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `remainingSec: float = 1.0`; exercises core body path returning/computing `125`.

```aipl
module tests.functions.audio.audio_spatial_z16_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioComputeCountdownBeepIntervalMs_16(): int:
  let arg_remainingSec = 1.0
  let edge_remainingSec = 0.5
  let resNom = audioComputeCountdownBeepIntervalMs(arg_remainingSec)
  let resEdge = audioComputeCountdownBeepIntervalMs(edge_remainingSec)
  assertEqInt(resNom, 125, "audioComputeCountdownBeepIntervalMs nominal resNom == 125")
  assertEqInt(resEdge, 125, "audioComputeCountdownBeepIntervalMs boundary resEdge == 125")
  ret 0
```

---

### `audioListener3DDefault` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn audioListener3DDefault(): AudioListener3D:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `AudioListener3D`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `audioListener3DDefault` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `AudioListener3D(`.

```aipl
module tests.functions.audio.audio_spatial_z17_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_audioListener3DDefault_17(): int:
  let resNom = audioListener3DDefault()
  let resEdge = audioListener3DDefault()
  assertApproxEq(resNom.x, 0.0, 0.001, "audioListener3DDefault nominal resNom.x ~= 0.0")
  assertApproxEq(resEdge.x, 0.0, 0.001, "audioListener3DDefault boundary resEdge.x ~= 0.0")
  ret 0
```

---

### `computeSpatialAudioListener3D` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn computeSpatialAudioListener3D(emitter: SoundEmitter3D, listener: AudioListener3D, wallHitsOrMinDist: float, minDistOrWallHits: float = 5.0): [float]:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `emitter: SoundEmitter3D, listener: AudioListener3D, wallHitsOrMinDist: float, minDistOrWallHits: float = 5.0` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `computeSpatialAudioListener3D` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `emitter: SoundEmitter3D = SoundEmitter3D(x = 1.0, y = 1.0, z = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, baseFreqHz = 1.0, maxRadius = 1.0, baseGain = 1.0)`, `listener: AudioListener3D = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = float = 0.0(), velY = float = 0.0(), velZ = float = 0.0(), vx = float = 0.0(), vy = float = 0.0(), vz = float = 0.0(), rightX = float = 1.0(), rightY = float = 0.0(), rightZ = float = 0.0())`, `wallHitsOrMinDist: float = 1.0`, `minDistOrWallHits: float = 1.0`; exercises core body path returning/computing `[distGain, leftGain, rightGain, doppler, cutoffHz, leftItdMs, rightItdMs]`.

```aipl
module tests.functions.audio.audio_spatial_z18_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_computeSpatialAudioListener3D_18(): int:
  let arg_emitter = SoundEmitter3D(x = 1.0, y = 1.0, z = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, baseFreqHz = 2.0, maxRadius = 2.0, baseGain = 1.0)
  let edge_emitter = SoundEmitter3D(x = 0.5, y = 0.5, z = 0.5, vx = 0.5, vy = 0.5, vz = 0.5, baseFreqHz = 1.0, maxRadius = 1.0, baseGain = 0.5)
  let arg_listener = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 2.0, forwardY = 2.0, forwardZ = 2.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = 1.0, velY = 1.0, velZ = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, rightX = 2.0, rightY = 2.0, rightZ = 2.0)
  let edge_listener = AudioListener3D(x = 0.5, y = 0.5, z = 0.5, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 0.5, upY = 0.5, upZ = 0.5, velX = 0.5, velY = 0.5, velZ = 0.5, vx = 0.5, vy = 0.5, vz = 0.5, rightX = 1.0, rightY = 1.0, rightZ = 1.0)
  let arg_wallHitsOrMinDist = 0.0
  let edge_wallHitsOrMinDist = 0.0
  let arg_minDistOrWallHits = 0.0
  let edge_minDistOrWallHits = 0.0
  let resNom = computeSpatialAudioListener3D(arg_emitter, arg_listener, arg_wallHitsOrMinDist, arg_minDistOrWallHits)
  let resEdge = computeSpatialAudioListener3D(edge_emitter, edge_listener, edge_wallHitsOrMinDist, edge_minDistOrWallHits)
  assertEqInt(resNom.len(), 7, "computeSpatialAudioListener3D nominal resNom.len() == 7")
  assertEqInt(resEdge.len(), 7, "computeSpatialAudioListener3D boundary resEdge.len() == 7")
  ret 0
```

---

### `applySpatialAudioDsp3D` (`std/audio/audio_spatial.aipl`)

- **Signature**: `pub fn applySpatialAudioDsp3D(samples: [float], emitter: SoundEmitter3D, listener: AudioListener3D, wallHits: int, sampleRate: int = 22050, minDist: float = 5.0): [float]:`
- **Import**: `import * from "std/audio/audio_spatial"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `samples: [float], emitter: SoundEmitter3D, listener: AudioListener3D, wallHits: int, sampleRate: int = 22050, minDist: float = 5.0` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_spatial_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `applySpatialAudioDsp3D` 3D inverse-distance gain falloff, stereo pan (`[-1.0, 1.0]`), approaching/receding Doppler pitch shift, and wall occlusion low-pass cutoff. Concrete nominal inputs: `samples: [float] = [1.0]`, `emitter: SoundEmitter3D = SoundEmitter3D(x = 1.0, y = 1.0, z = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, baseFreqHz = 1.0, maxRadius = 1.0, baseGain = 1.0)`, `listener: AudioListener3D = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = float = 0.0(), velY = float = 0.0(), velZ = float = 0.0(), vx = float = 0.0(), vy = float = 0.0(), vz = float = 0.0(), rightX = float = 1.0(), rightY = float = 0.0(), rightZ = float = 0.0())`, `wallHits: int = 1`, `sampleRate: int = 48000`, `minDist: float = 1.0`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_spatial_z19_test
import * from "std/audio/audio_spatial"
import { absFloat, clampFloat, clampInt, maxFloat } from "std/math/consts"
import { sin, cos, tan, sqrt } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_spatial_applySpatialAudioDsp3D_19(): int:
  let arg_samples = [1.0]
  let edge_samples = []
  let arg_emitter = SoundEmitter3D(x = 1.0, y = 1.0, z = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, baseFreqHz = 2.0, maxRadius = 2.0, baseGain = 1.0)
  let edge_emitter = SoundEmitter3D(x = 0.5, y = 0.5, z = 0.5, vx = 0.5, vy = 0.5, vz = 0.5, baseFreqHz = 1.0, maxRadius = 1.0, baseGain = 0.5)
  let arg_listener = AudioListener3D(x = 1.0, y = 1.0, z = 1.0, forwardX = 2.0, forwardY = 2.0, forwardZ = 2.0, upX = 1.0, upY = 1.0, upZ = 1.0, velX = 1.0, velY = 1.0, velZ = 1.0, vx = 1.0, vy = 1.0, vz = 1.0, rightX = 2.0, rightY = 2.0, rightZ = 2.0)
  let edge_listener = AudioListener3D(x = 0.5, y = 0.5, z = 0.5, forwardX = 1.0, forwardY = 1.0, forwardZ = 1.0, upX = 0.5, upY = 0.5, upZ = 0.5, velX = 0.5, velY = 0.5, velZ = 0.5, vx = 0.5, vy = 0.5, vz = 0.5, rightX = 1.0, rightY = 1.0, rightZ = 1.0)
  let arg_wallHits = 2
  let edge_wallHits = 0
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_minDist = 0.0
  let edge_minDist = 0.0
  let resNom = applySpatialAudioDsp3D(arg_samples, arg_emitter, arg_listener, arg_wallHits, arg_sampleRate, arg_minDist)
  let resEdge = applySpatialAudioDsp3D(edge_samples, edge_emitter, edge_listener, edge_wallHits, edge_sampleRate, edge_minDist)
  assertEqInt(resNom.len(), 2, "applySpatialAudioDsp3D nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 0, "applySpatialAudioDsp3D boundary resEdge.len() == 0")
  ret 0
```

---

### `createAdsr` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn createAdsr(attack: float, decay: float, sustain: float, release: float, antiClickRamp: float = 0.005): AdsrEnvelope:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `attack: float, decay: float, sustain: float, release: float, antiClickRamp: float = 0.005` | **Returns**: `AdsrEnvelope`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `createAdsr` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `attack: float = 1.0`, `decay: float = 1.0`, `sustain: float = 1.0`, `release: float = 1.0`, `antiClickRamp: float = 1.0`; exercises core body path returning/computing `AdsrEnvelope(`.

```aipl
module tests.functions.audio.audio_synth_z1_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_createAdsr_1(): int:
  let arg_attack = 1.0
  let edge_attack = 0.5
  let arg_decay = 1.0
  let edge_decay = 0.5
  let arg_sustain = 1.0
  let edge_sustain = 0.5
  let arg_release = 1.0
  let edge_release = 0.5
  let arg_antiClickRamp = 1.0
  let edge_antiClickRamp = 0.5
  let resNom = createAdsr(arg_attack, arg_decay, arg_sustain, arg_release, arg_antiClickRamp)
  let resEdge = createAdsr(edge_attack, edge_decay, edge_sustain, edge_release, edge_antiClickRamp)
  assertApproxEq(resNom.attackSec, 1.0, 0.001, "createAdsr nominal resNom.attackSec ~= 1.0")
  assertApproxEq(resEdge.attackSec, 0.5, 0.001, "createAdsr boundary resEdge.attackSec ~= 0.5")
  ret 0
```

---

### `evaluateNoteOnLevel` (`std/audio/audio_synth.aipl`)

- **Signature**: `fn evaluateNoteOnLevel(adsr: AdsrEnvelope, t: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `adsr: AdsrEnvelope, t: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `evaluateNoteOnLevel` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `adsr: AdsrEnvelope = AdsrEnvelope(attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, antiClickRampSec = 1.0)`, `t: float = 0.5`; exercises core body path returning/computing `adsr.sustainLevel`.

```aipl
module tests.functions.audio.audio_synth_z2_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_evaluateNoteOnLevel_2(): int:
  let arg_adsr = AdsrEnvelope(attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, antiClickRampSec = 1.0)
  let edge_adsr = AdsrEnvelope(attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5, antiClickRampSec = 0.5)
  let arg_t = 1.0
  let edge_t = 0.5
  let resNom = evaluateNoteOnLevel(arg_adsr, arg_t)
  let resEdge = evaluateNoteOnLevel(edge_adsr, edge_t)
  assertApproxEq(resNom, 1.0, 0.001, "evaluateNoteOnLevel nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "evaluateNoteOnLevel boundary resEdge ~= 1.0")
  ret 0
```

---

### `adsrDefault` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn adsrDefault(): AdsrEnvelope:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `AdsrEnvelope`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `adsrDefault` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `AdsrEnvelope(`.

```aipl
module tests.functions.audio.audio_synth_z3_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_adsrDefault_3(): int:
  let resNom = adsrDefault()
  let resEdge = adsrDefault()
  assertApproxEq(resNom.attackSec, 0.01, 0.001, "adsrDefault nominal resNom.attackSec ~= 0.01")
  assertApproxEq(resEdge.attackSec, 0.01, 0.001, "adsrDefault boundary resEdge.attackSec ~= 0.01")
  ret 0
```

---

### `evaluateAdsr` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn evaluateAdsr(adsr: AdsrEnvelope, timeSec: float, isNoteOnOrTotalDur: any = true, noteReleaseTimeSec: float = -1.0): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `adsr: AdsrEnvelope, timeSec: float, isNoteOnOrTotalDur: any = true, noteReleaseTimeSec: float = -1.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `evaluateAdsr` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `adsr: AdsrEnvelope = AdsrEnvelope(attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, antiClickRampSec = 1.0)`, `timeSec: float = 1.0`, `isNoteOnOrTotalDur: any = 42`, `noteReleaseTimeSec: float = 1.0`; exercises core body path returning/computing `levelAtRelease * (1.0 - (relElapsed / adsr.releaseSec))`.

```aipl
module tests.functions.audio.audio_synth_z4_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_evaluateAdsr_4(): int:
  let arg_adsr = AdsrEnvelope(attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, antiClickRampSec = 1.0)
  let edge_adsr = AdsrEnvelope(attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5, antiClickRampSec = 0.5)
  let arg_timeSec = 1.0
  let edge_timeSec = 0.5
  let arg_isNoteOnOrTotalDur = 1
  let edge_isNoteOnOrTotalDur = 0
  let arg_noteReleaseTimeSec = 1.0
  let edge_noteReleaseTimeSec = 0.5
  let resNom = evaluateAdsr(arg_adsr, arg_timeSec, arg_isNoteOnOrTotalDur, arg_noteReleaseTimeSec)
  let resEdge = evaluateAdsr(edge_adsr, edge_timeSec, edge_isNoteOnOrTotalDur, edge_noteReleaseTimeSec)
  assertApproxEq(resNom, 1.0, 0.001, "evaluateAdsr nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "evaluateAdsr boundary resEdge ~= 1.0")
  ret 0
```

---

### `generateWaveformSample` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn generateWaveformSample(oscType: int, phase: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `oscType: int, phase: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `generateWaveformSample` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `oscType: int = 1`, `phase: float = 1.0`; exercises core body path returning/computing `2.0 * (if frac < 0.0: -frac else: frac) - 1.0`.

```aipl
module tests.functions.audio.audio_synth_z5_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_generateWaveformSample_5(): int:
  let arg_oscType = 1
  let edge_oscType = 0
  let arg_phase = 2.0
  let edge_phase = 1.0
  let resNom = generateWaveformSample(arg_oscType, arg_phase)
  let resEdge = generateWaveformSample(edge_oscType, edge_phase)
  assertApproxEq(resNom, 1.0, 0.001, "generateWaveformSample nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "generateWaveformSample boundary resEdge ~= 0.0")
  ret 0
```

---

### `absFloatSynth` (`std/audio/audio_synth.aipl`)

- **Signature**: `fn absFloatSynth(v: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `v: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `absFloatSynth` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `v: float = 1.0`; exercises core body path returning/computing `v`.

```aipl
module tests.functions.audio.audio_synth_z6_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_absFloatSynth_6(): int:
  let arg_v = 1.0
  let edge_v = 0.5
  let resNom = absFloatSynth(arg_v)
  let resEdge = absFloatSynth(edge_v)
  assertApproxEq(resNom, 1.0, 0.001, "absFloatSynth nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "absFloatSynth boundary resEdge ~= 0.5")
  ret 0
```

---

### `quantizeToPentatonicLadder` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn quantizeToPentatonicLadder(continuousFreqHz: float, baseKeyNoteHz: float = 261.63): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `continuousFreqHz: float, baseKeyNoteHz: float = 261.63` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `quantizeToPentatonicLadder` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `continuousFreqHz: float = 1.0`, `baseKeyNoteHz: float = 1.0`; exercises core body path returning/computing `bestFreq`.

```aipl
module tests.functions.audio.audio_synth_z7_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_quantizeToPentatonicLadder_7(): int:
  let arg_continuousFreqHz = 2.0
  let edge_continuousFreqHz = 1.0
  let arg_baseKeyNoteHz = 2.0
  let edge_baseKeyNoteHz = 1.0
  let resNom = quantizeToPentatonicLadder(arg_continuousFreqHz, arg_baseKeyNoteHz)
  let resEdge = quantizeToPentatonicLadder(edge_continuousFreqHz, edge_baseKeyNoteHz)
  assertApproxEq(resNom, 65.4075, 0.001, "quantizeToPentatonicLadder nominal resNom ~= 65.4075")
  assertApproxEq(resEdge, 65.4075, 0.001, "quantizeToPentatonicLadder boundary resEdge ~= 65.4075")
  ret 0
```

---

### `synthesizeToneBuffer` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn synthesizeToneBuffer(frequency: float, durationMs: float, volume: float = 0.5, oscTypeOrWaveform: any = 0, sampleRate: int = 44100): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `frequency: float, durationMs: float, volume: float = 0.5, oscTypeOrWaveform: any = 0, sampleRate: int = 44100` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `synthesizeToneBuffer` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `frequency: float = 1.0`, `durationMs: float = 0.5`, `volume: float = 1.0`, `oscTypeOrWaveform: any = 42`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z8_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_synthesizeToneBuffer_8(): int:
  let arg_frequency = 2.0
  let edge_frequency = 1.0
  let arg_durationMs = 1.0
  let edge_durationMs = 0.5
  let arg_volume = 1.0
  let edge_volume = 0.5
  let arg_oscTypeOrWaveform = 1
  let edge_oscTypeOrWaveform = 0
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = synthesizeToneBuffer(arg_frequency, arg_durationMs, arg_volume, arg_oscTypeOrWaveform, arg_sampleRate)
  let resEdge = synthesizeToneBuffer(edge_frequency, edge_durationMs, edge_volume, edge_oscTypeOrWaveform, edge_sampleRate)
  assertEqInt(resNom.len(), 0, "synthesizeToneBuffer nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "synthesizeToneBuffer boundary resEdge.len() == 0")
  ret 0
```

---

### `renderFmPatch4Op` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderFmPatch4Op(baseFreq: float, durationSec: float, ops: [FmOperator], sampleRate: int = 44100): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseFreq: float, durationSec: float, ops: [FmOperator], sampleRate: int = 44100` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `renderFmPatch4Op` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `baseFreq: float = 1.0`, `durationSec: float = 0.5`, `ops: [FmOperator] = [FmOperator(ratio = 0.5, modulationIndex = 1.0, phase = 1.0, detuneHz = 1.0)]`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z9_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderFmPatch4Op_9(): int:
  let arg_baseFreq = 2.0
  let edge_baseFreq = 1.0
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_ops = [FmOperator(ratio = 1.0, modulationIndex = 1.0, phase = 2.0, detuneHz = 2.0)]
  let edge_ops = []
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = renderFmPatch4Op(arg_baseFreq, arg_durationSec, arg_ops, arg_sampleRate)
  let resEdge = renderFmPatch4Op(edge_baseFreq, edge_durationSec, edge_ops, edge_sampleRate)
  assertEqInt(resNom.len(), 4, "renderFmPatch4Op nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 0, "renderFmPatch4Op boundary resEdge.len() == 0")
  ret 0
```

---

### `midiNoteToFreqHz` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn midiNoteToFreqHz(midiNote: int): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `midiNote: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `midiNoteToFreqHz` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `midiNote: int = 1`; exercises core body path returning/computing `440.0 * pow(2.0, diff / 12.0)`.

```aipl
module tests.functions.audio.audio_synth_z10_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_midiNoteToFreqHz_10(): int:
  let arg_midiNote = 4
  let edge_midiNote = 1
  let resNom = midiNoteToFreqHz(arg_midiNote)
  let resEdge = midiNoteToFreqHz(edge_midiNote)
  assertApproxEq(resNom, 10.3009, 0.001, "midiNoteToFreqHz nominal resNom ~= 10.3009")
  assertApproxEq(resEdge, 8.66196, 0.001, "midiNoteToFreqHz boundary resEdge ~= 8.66196")
  ret 0
```

---

### `freqHzToMidiNote` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn freqHzToMidiNote(freqHz: float): int:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `freqHz: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `freqHzToMidiNote` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `freqHz: float = 1.0`; exercises core body path returning/computing `int(69.0 + semi + 0.5)`.

```aipl
module tests.functions.audio.audio_synth_z11_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_freqHzToMidiNote_11(): int:
  let arg_freqHz = 2.0
  let edge_freqHz = 1.0
  let resNom = freqHzToMidiNote(arg_freqHz)
  let resEdge = freqHzToMidiNote(edge_freqHz)
  assertEqInt(resNom, -23, "freqHzToMidiNote nominal resNom == -23")
  assertEqInt(resEdge, 69, "freqHzToMidiNote boundary resEdge == 69")
  ret 0
```

---

### `evalAdsrEnvelope` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn evalAdsrEnvelope(t: float, attack: float, decay: float, sustainLevel: float, releaseTime: float, noteDuration: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float, attack: float, decay: float, sustainLevel: float, releaseTime: float, noteDuration: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `evalAdsrEnvelope` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `t: float = 0.5`, `attack: float = 1.0`, `decay: float = 1.0`, `sustainLevel: float = 1.0`, `releaseTime: float = 1.0`, `noteDuration: float = 0.5`; exercises core body path returning/computing `sustainLevel * (1.0 - rt / (if releaseTime > 0.0001: releaseTime else: 0.0001))`.

```aipl
module tests.functions.audio.audio_synth_z12_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_evalAdsrEnvelope_12(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_attack = 1.0
  let edge_attack = 0.5
  let arg_decay = 1.0
  let edge_decay = 0.5
  let arg_sustainLevel = 1.0
  let edge_sustainLevel = 0.5
  let arg_releaseTime = 1.0
  let edge_releaseTime = 0.5
  let arg_noteDuration = 1.0
  let edge_noteDuration = 0.5
  let resNom = evalAdsrEnvelope(arg_t, arg_attack, arg_decay, arg_sustainLevel, arg_releaseTime, arg_noteDuration)
  let resEdge = evalAdsrEnvelope(edge_t, edge_attack, edge_decay, edge_sustainLevel, edge_releaseTime, edge_noteDuration)
  assertApproxEq(resNom, 1.0, 0.001, "evalAdsrEnvelope nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "evalAdsrEnvelope boundary resEdge ~= 1.0")
  ret 0
```

---

### `polyBlep` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn polyBlep(t: float, dt: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: float, dt: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `polyBlep` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `t: float = 0.5`, `dt: float = 0.016667`; exercises core body path returning/computing `0.0`.

```aipl
module tests.functions.audio.audio_synth_z13_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_polyBlep_13(): int:
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = polyBlep(arg_t, arg_dt)
  let resEdge = polyBlep(edge_t, edge_dt)
  assertApproxEq(resNom, -0.25, 0.001, "polyBlep nominal resNom ~= -0.25")
  assertApproxEq(resEdge, -0.25, 0.001, "polyBlep boundary resEdge ~= -0.25")
  ret 0
```

---

### `oscSamplePolyBlep` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn oscSamplePolyBlep(waveform: str, phase: float, dt: float, pulseWidth: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `waveform: str, phase: float, dt: float, pulseWidth: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `oscSamplePolyBlep` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `waveform: str = "aipl_test"`, `phase: float = 1.0`, `dt: float = 0.016667`, `pulseWidth: float = 0.016667`; exercises core body path returning/computing `sin(p * 6.283185307179586)`.

```aipl
module tests.functions.audio.audio_synth_z14_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_oscSamplePolyBlep_14(): int:
  let arg_waveform = "test"
  let edge_waveform = "a"
  let arg_phase = 2.0
  let edge_phase = 1.0
  let arg_dt = 2.0
  let edge_dt = 1.0
  let arg_pulseWidth = 2.0
  let edge_pulseWidth = 1.0
  let resNom = oscSamplePolyBlep(arg_waveform, arg_phase, arg_dt, arg_pulseWidth)
  let resEdge = oscSamplePolyBlep(edge_waveform, edge_phase, edge_dt, edge_pulseWidth)
  assertApproxEq(resNom, 0.0, 0.001, "oscSamplePolyBlep nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "oscSamplePolyBlep boundary resEdge ~= 0.0")
  ret 0
```

---

### `renderOscillatorBuffer` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderOscillatorBuffer(waveform: str, freqHz: float, durationSec: float, sampleRate: int, pulseWidth: float): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `waveform: str, freqHz: float, durationSec: float, sampleRate: int, pulseWidth: float` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `renderOscillatorBuffer` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `waveform: str = "aipl_test"`, `freqHz: float = 1.0`, `durationSec: float = 0.5`, `sampleRate: int = 48000`, `pulseWidth: float = 0.016667`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z15_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderOscillatorBuffer_15(): int:
  let arg_waveform = "test"
  let edge_waveform = "a"
  let arg_freqHz = 2.0
  let edge_freqHz = 1.0
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_pulseWidth = 2.0
  let edge_pulseWidth = 1.0
  let resNom = renderOscillatorBuffer(arg_waveform, arg_freqHz, arg_durationSec, arg_sampleRate, arg_pulseWidth)
  let resEdge = renderOscillatorBuffer(edge_waveform, edge_freqHz, edge_durationSec, edge_sampleRate, edge_pulseWidth)
  assertEqInt(resNom.len(), 4, "renderOscillatorBuffer nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 0, "renderOscillatorBuffer boundary resEdge.len() == 0")
  ret 0
```

---

### `pinkNoiseStateNew` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn pinkNoiseStateNew(seed: int): PinkNoiseState:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `PinkNoiseState`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `pinkNoiseStateNew` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `PinkNoiseState(`.

```aipl
module tests.functions.audio.audio_synth_z16_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_pinkNoiseStateNew_16(): int:
  let arg_seed = 1
  let edge_seed = 0
  let resNom = pinkNoiseStateNew(arg_seed)
  let resEdge = pinkNoiseStateNew(edge_seed)
  assertEqInt(resNom.seed, 1, "pinkNoiseStateNew nominal resNom.seed == 1")
  assertEqInt(resEdge.seed, 1234567, "pinkNoiseStateNew boundary resEdge.seed == 1234567")
  ret 0
```

---

### `nextWhiteNoise` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn nextWhiteNoise(seed: int): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `seed: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `nextWhiteNoise` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `seed: int = 42`; exercises core body path returning/computing `[val, float(s)]`.

```aipl
module tests.functions.audio.audio_synth_z17_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_nextWhiteNoise_17(): int:
  let arg_seed = 1
  let edge_seed = 0
  let resNom = nextWhiteNoise(arg_seed)
  let resEdge = nextWhiteNoise(edge_seed)
  assertEqInt(resNom.len(), 2, "nextWhiteNoise nominal resNom.len() == 2")
  assertEqInt(resEdge.len(), 2, "nextWhiteNoise boundary resEdge.len() == 2")
  ret 0
```

---

### `renderNoiseBuffer` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderNoiseBuffer(kind: str, numSamples: int, seed: int): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `kind: str, numSamples: int, seed: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `renderNoiseBuffer` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `kind: str = "aipl_test"`, `numSamples: int = 1`, `seed: int = 42`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z18_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderNoiseBuffer_18(): int:
  let arg_kind = "test"
  let edge_kind = "a"
  let arg_numSamples = 4
  let edge_numSamples = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = renderNoiseBuffer(arg_kind, arg_numSamples, arg_seed)
  let resEdge = renderNoiseBuffer(edge_kind, edge_numSamples, edge_seed)
  assertEqInt(resNom.len(), 4, "renderNoiseBuffer nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 1, "renderNoiseBuffer boundary resEdge.len() == 1")
  ret 0
```

---

### `ahdsrNew` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn ahdsrNew(attackSec: float, holdSec: float, decaySec: float, sustainLevel: float, releaseSec: float, curvePower: float): AhdsrEnvelope:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `attackSec: float, holdSec: float, decaySec: float, sustainLevel: float, releaseSec: float, curvePower: float` | **Returns**: `AhdsrEnvelope`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `ahdsrNew` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `attackSec: float = 1.0`, `holdSec: float = 1.0`, `decaySec: float = 1.0`, `sustainLevel: float = 1.0`, `releaseSec: float = 1.0`, `curvePower: float = 1.0`; exercises core body path returning/computing `AhdsrEnvelope(`.

```aipl
module tests.functions.audio.audio_synth_z19_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_ahdsrNew_19(): int:
  let arg_attackSec = 1.0
  let edge_attackSec = 0.5
  let arg_holdSec = 2.0
  let edge_holdSec = 1.0
  let arg_decaySec = 1.0
  let edge_decaySec = 0.5
  let arg_sustainLevel = 1.0
  let edge_sustainLevel = 0.5
  let arg_releaseSec = 1.0
  let edge_releaseSec = 0.5
  let arg_curvePower = 2.0
  let edge_curvePower = 1.0
  let resNom = ahdsrNew(arg_attackSec, arg_holdSec, arg_decaySec, arg_sustainLevel, arg_releaseSec, arg_curvePower)
  let resEdge = ahdsrNew(edge_attackSec, edge_holdSec, edge_decaySec, edge_sustainLevel, edge_releaseSec, edge_curvePower)
  assertApproxEq(resNom.attackSec, 1.0, 0.001, "ahdsrNew nominal resNom.attackSec ~= 1.0")
  assertApproxEq(resEdge.attackSec, 0.5, 0.001, "ahdsrNew boundary resEdge.attackSec ~= 0.5")
  ret 0
```

---

### `evalAhdsrEnvelope` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn evalAhdsrEnvelope(env: AhdsrEnvelope, t: float, noteOnDuration: float): float:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `env: AhdsrEnvelope, t: float, noteOnDuration: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `evalAhdsrEnvelope` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `env: AhdsrEnvelope = AhdsrEnvelope(attackSec = 1.0, holdSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, curvePower = 1.0)`, `t: float = 0.5`, `noteOnDuration: float = 0.5`; exercises core body path returning/computing `env.sustainLevel * (1.0 - pow(u, env.curvePower))`.

```aipl
module tests.functions.audio.audio_synth_z20_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_evalAhdsrEnvelope_20(): int:
  let arg_env = AhdsrEnvelope(attackSec = 1.0, holdSec = 2.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0, curvePower = 2.0)
  let edge_env = AhdsrEnvelope(attackSec = 0.5, holdSec = 1.0, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5, curvePower = 1.0)
  let arg_t = 1.0
  let edge_t = 0.5
  let arg_noteOnDuration = 1.0
  let edge_noteOnDuration = 0.5
  let resNom = evalAhdsrEnvelope(arg_env, arg_t, arg_noteOnDuration)
  let resEdge = evalAhdsrEnvelope(edge_env, edge_t, edge_noteOnDuration)
  assertApproxEq(resNom, 1.0, 0.001, "evalAhdsrEnvelope nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "evalAhdsrEnvelope boundary resEdge ~= 1.0")
  ret 0
```

---

### `renderFm4OpNote` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderFm4OpNote(patch: Fm4OpPatch, baseFreqHz: float, durationSec: float, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `patch: Fm4OpPatch, baseFreqHz: float, durationSec: float, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `renderFm4OpNote` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `patch: Fm4OpPatch = Fm4OpPatch(algorithm = 1, op1 = FmOperatorPatch(ratio = 0.5, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op2 = FmOperatorPatch(ratio = 0.5, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op3 = FmOperatorPatch(ratio = 0.5, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op4 = FmOperatorPatch(ratio = 0.5, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0))`, `baseFreqHz: float = 1.0`, `durationSec: float = 0.5`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z21_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderFm4OpNote_21(): int:
  let arg_patch = Fm4OpPatch(algorithm = 4, op1 = FmOperatorPatch(ratio = 1.0, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op2 = FmOperatorPatch(ratio = 1.0, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op3 = FmOperatorPatch(ratio = 1.0, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0), op4 = FmOperatorPatch(ratio = 1.0, modIndex = 1.0, feedback = 1.0, attackSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, releaseSec = 1.0))
  let edge_patch = Fm4OpPatch(algorithm = 1, op1 = FmOperatorPatch(ratio = 0.5, modIndex = 0.5, feedback = 0.5, attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5), op2 = FmOperatorPatch(ratio = 0.5, modIndex = 0.5, feedback = 0.5, attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5), op3 = FmOperatorPatch(ratio = 0.5, modIndex = 0.5, feedback = 0.5, attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5), op4 = FmOperatorPatch(ratio = 0.5, modIndex = 0.5, feedback = 0.5, attackSec = 0.5, decaySec = 0.5, sustainLevel = 0.5, releaseSec = 0.5))
  let arg_baseFreqHz = 2.0
  let edge_baseFreqHz = 1.0
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = renderFm4OpNote(arg_patch, arg_baseFreqHz, arg_durationSec, arg_sampleRate)
  let resEdge = renderFm4OpNote(edge_patch, edge_baseFreqHz, edge_durationSec, edge_sampleRate)
  assertEqInt(resNom.len(), 4, "renderFm4OpNote nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 0, "renderFm4OpNote boundary resEdge.len() == 0")
  ret 0
```

---

### `renderKarplusStrong` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderKarplusStrong(freqHz: float, durationSec: float, damping: float, brightness: float, sampleRate: int, seed: int): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `freqHz: float, durationSec: float, damping: float, brightness: float, sampleRate: int, seed: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `renderKarplusStrong` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `freqHz: float = 1.0`, `durationSec: float = 0.5`, `damping: float = 1.0`, `brightness: float = 1.0`, `sampleRate: int = 48000`, `seed: int = 42`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z22_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderKarplusStrong_22(): int:
  let arg_freqHz = 2.0
  let edge_freqHz = 1.0
  let arg_durationSec = 1.0
  let edge_durationSec = 0.5
  let arg_damping = 1.0
  let edge_damping = 0.5
  let arg_brightness = 2.0
  let edge_brightness = 1.0
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let arg_seed = 1
  let edge_seed = 0
  let resNom = renderKarplusStrong(arg_freqHz, arg_durationSec, arg_damping, arg_brightness, arg_sampleRate, arg_seed)
  let resEdge = renderKarplusStrong(edge_freqHz, edge_durationSec, edge_damping, edge_brightness, edge_sampleRate, edge_seed)
  assertEqInt(resNom.len(), 4, "renderKarplusStrong nominal resNom.len() == 4")
  assertEqInt(resEdge.len(), 2, "renderKarplusStrong boundary resEdge.len() == 2")
  ret 0
```

---

### `sfxPatchDefault` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn sfxPatchDefault(): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `sfxPatchDefault` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z23_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_sfxPatchDefault_23(): int:
  let resNom = sfxPatchDefault()
  let resEdge = sfxPatchDefault()
  assertEqStr(resNom.waveform, "square", "sfxPatchDefault nominal string matches")
  assertEqStr(resEdge.waveform, "square", "sfxPatchDefault boundary string matches")
  ret 0
```

---

### `mutateSfxPatch` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn mutateSfxPatch(p: SfxPatch, amount: float, seed: int): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: SfxPatch, amount: float, seed: int` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `mutateSfxPatch` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `p: SfxPatch = SfxPatch(waveform = "aipl_test", volume = 1.0, baseFreqHz = 1.0, freqLimitHz = 1.0, freqSlide = 1.0, freqDeltaSlide = 1.0, attackSec = 1.0, holdSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, vibratoDepth = 1.0, vibratoSpeedHz = 1.0, arpModMult = 1.0, arpSpeedSec = 1.0, dutyCycle = 1.0, dutySweep = 1.0, phaserOffset = 1.0, lpfCutoffHz = 1.0, hpfCutoffHz = 1.0, bitCrushBits = 1)`, `amount: float = 1.0`, `seed: int = 42`; exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z24_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_mutateSfxPatch_24(): int:
  let arg_p = SfxPatch(waveform = "test", volume = 1.0, baseFreqHz = 2.0, freqLimitHz = 2.0, freqSlide = 2.0, freqDeltaSlide = 2.0, attackSec = 1.0, holdSec = 2.0, decaySec = 1.0, sustainLevel = 1.0, vibratoDepth = 2.0, vibratoSpeedHz = 2.0, arpModMult = 1.0, arpSpeedSec = 1.0, dutyCycle = 1.0, dutySweep = 2.0, phaserOffset = 2.0, lpfCutoffHz = 2.0, hpfCutoffHz = 2.0, bitCrushBits = 4)
  let edge_p = SfxPatch(waveform = "a", volume = 0.5, baseFreqHz = 1.0, freqLimitHz = 1.0, freqSlide = 1.0, freqDeltaSlide = 1.0, attackSec = 0.5, holdSec = 1.0, decaySec = 0.5, sustainLevel = 0.5, vibratoDepth = 1.0, vibratoSpeedHz = 1.0, arpModMult = 0.5, arpSpeedSec = 0.5, dutyCycle = 0.5, dutySweep = 1.0, phaserOffset = 1.0, lpfCutoffHz = 1.0, hpfCutoffHz = 1.0, bitCrushBits = 1)
  let arg_amount = 1.0
  let edge_amount = 0.5
  let arg_seed = 1
  let edge_seed = 0
  let resNom = mutateSfxPatch(arg_p, arg_amount, arg_seed)
  let resEdge = mutateSfxPatch(edge_p, edge_amount, edge_seed)
  assertEqStr(resNom.waveform, "test", "mutateSfxPatch nominal string matches")
  assertEqStr(resEdge.waveform, "a", "mutateSfxPatch boundary string matches")
  ret 0
```

---

### `renderSfxPatch` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn renderSfxPatch(p: SfxPatch, sampleRate: int): [float]:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p: SfxPatch, sampleRate: int` | **Returns**: `[float]`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `renderSfxPatch` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: `p: SfxPatch = SfxPatch(waveform = "aipl_test", volume = 1.0, baseFreqHz = 1.0, freqLimitHz = 1.0, freqSlide = 1.0, freqDeltaSlide = 1.0, attackSec = 1.0, holdSec = 1.0, decaySec = 1.0, sustainLevel = 1.0, vibratoDepth = 1.0, vibratoSpeedHz = 1.0, arpModMult = 1.0, arpSpeedSec = 1.0, dutyCycle = 1.0, dutySweep = 1.0, phaserOffset = 1.0, lpfCutoffHz = 1.0, hpfCutoffHz = 1.0, bitCrushBits = 1)`, `sampleRate: int = 48000`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.audio.audio_synth_z25_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_renderSfxPatch_25(): int:
  let arg_p = SfxPatch(waveform = "test", volume = 1.0, baseFreqHz = 2.0, freqLimitHz = 2.0, freqSlide = 2.0, freqDeltaSlide = 2.0, attackSec = 1.0, holdSec = 2.0, decaySec = 1.0, sustainLevel = 1.0, vibratoDepth = 2.0, vibratoSpeedHz = 2.0, arpModMult = 1.0, arpSpeedSec = 1.0, dutyCycle = 1.0, dutySweep = 2.0, phaserOffset = 2.0, lpfCutoffHz = 2.0, hpfCutoffHz = 2.0, bitCrushBits = 4)
  let edge_p = SfxPatch(waveform = "a", volume = 0.5, baseFreqHz = 1.0, freqLimitHz = 1.0, freqSlide = 1.0, freqDeltaSlide = 1.0, attackSec = 0.5, holdSec = 1.0, decaySec = 0.5, sustainLevel = 0.5, vibratoDepth = 1.0, vibratoSpeedHz = 1.0, arpModMult = 0.5, arpSpeedSec = 0.5, dutyCycle = 0.5, dutySweep = 1.0, phaserOffset = 1.0, lpfCutoffHz = 1.0, hpfCutoffHz = 1.0, bitCrushBits = 1)
  let arg_sampleRate = 4
  let edge_sampleRate = 1
  let resNom = renderSfxPatch(arg_p, arg_sampleRate)
  let resEdge = renderSfxPatch(edge_p, edge_sampleRate)
  assertEqInt(resNom.len(), 16, "renderSfxPatch nominal resNom.len() == 16")
  assertEqInt(resEdge.len(), 16, "renderSfxPatch boundary resEdge.len() == 16")
  ret 0
```

---

### `sfxCoin` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn sfxCoin(): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `sfxCoin` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z26_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_sfxCoin_26(): int:
  let resNom = sfxCoin()
  let resEdge = sfxCoin()
  assertEqStr(resNom.waveform, "square", "sfxCoin nominal string matches")
  assertEqStr(resEdge.waveform, "square", "sfxCoin boundary string matches")
  ret 0
```

---

### `sfxLaser` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn sfxLaser(): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_149_audio_dsp_biquad_filter_eq_window.aipl`
- **Behavioral Summary**: Verify `sfxLaser` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z27_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_sfxLaser_27(): int:
  let resNom = sfxLaser()
  let resEdge = sfxLaser()
  assertEqStr(resNom.waveform, "saw", "sfxLaser nominal string matches")
  assertEqStr(resEdge.waveform, "saw", "sfxLaser boundary string matches")
  ret 0
```

---

### `sfxExplosion` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn sfxExplosion(): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_150_audio_mixer_multitrack_vu_meter_window.aipl`
- **Behavioral Summary**: Verify `sfxExplosion` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z28_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_sfxExplosion_28(): int:
  let resNom = sfxExplosion()
  let resEdge = sfxExplosion()
  assertEqStr(resNom.waveform, "noise", "sfxExplosion nominal string matches")
  assertEqStr(resEdge.waveform, "noise", "sfxExplosion boundary string matches")
  ret 0
```

---

### `sfxJump` (`std/audio/audio_synth.aipl`)

- **Signature**: `pub fn sfxJump(): SfxPatch:`
- **Import**: `import * from "std/audio/audio_synth"` (or barrel `import * from "std/audio/audio_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `SfxPatch`
- **Unit Test**: `tests/functions/audio/audio_synth_test.aipl` | **Example**: `examples/ex_151_audio_spatial_3d_doppler_radar_window.aipl`
- **Behavioral Summary**: Verify `sfxJump` anti-click zero-crossing ADSR/AHDSR envelopes, PolyBLEP band-limited oscillators, 4-op FM synthesis, Karplus-Strong string decay, and pentatonic pitch quantization. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `SfxPatch(`.

```aipl
module tests.functions.audio.audio_synth_z29_test
import * from "std/audio/audio_synth"
import { absFloat, clampFloat, maxFloat, maxInt, floor } from "std/math/consts"
import { sin, pow, lnFloat } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_audio_synth_sfxJump_29(): int:
  let resNom = sfxJump()
  let resEdge = sfxJump()
  assertEqStr(resNom.waveform, "square", "sfxJump nominal string matches")
  assertEqStr(resEdge.waveform, "square", "sfxJump boundary string matches")
  ret 0
```
