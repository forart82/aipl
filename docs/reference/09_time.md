[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 09: `time` API Reference

> Complete API reference manual for AIPL standard library domain `time` (165 callable functions & methods across ["std/time/cooldown_timer.aipl", "std/time/cron_schedule.aipl", "std/time/datetime.aipl", "std/time/duration.aipl", "std/time/frame_pacer.aipl", "std/time/instant.aipl", "std/time/time_mod.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `time`
- **Target Source Modules**: ["std/time/cooldown_timer.aipl", "std/time/cron_schedule.aipl", "std/time/datetime.aipl", "std/time/duration.aipl", "std/time/frame_pacer.aipl", "std/time/instant.aipl", "std/time/time_mod.aipl"]
- **Total Callable Functions & Methods**: 165
- **Total Data Types (`struct` & `enum`)**: 17
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(17 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `CooldownTimer` | `pub struct` | `std/time/cooldown_timer.aipl` | `duration: Duration`, `lastTrigger: Instant`, `isReady: bool` | `CooldownTimer(duration, lastTrigger, isReady)` |
| `RepeatingTicker` | `pub struct` | `std/time/cooldown_timer.aipl` | `interval: Duration`, `lastTick: Instant`, `ticksPending: int` | `RepeatingTicker(interval, lastTick, ticksPending)` |
| `Stopwatch` | `pub struct` | `std/time/cooldown_timer.aipl` | `startInstant: Instant`, `accumulated: Duration`, `isRunning: bool` | `Stopwatch(startInstant, accumulated, isRunning)` |
| `DebounceTimer` | `pub struct` | `std/time/cooldown_timer.aipl` | `delay: Duration`, `pendingInstant: Instant`, `hasPending: bool` | `DebounceTimer(delay, pendingInstant, hasPending)` |
| `CronSchedule` | `pub struct` | `std/time/cron_schedule.aipl` | `minuteBitset: int`, `hourBitset: int`, `dayOfMonthBitset: int`, `monthBitset: int`, `dayOfWeekBitset: int`, `hasSeconds: bool`, `secondBitset: int` | `CronSchedule(minuteBitset, hourBitset, dayOfMonthBitset, monthBitset, dayOfWeekBitset, hasSeconds, secondBitset)` |
| `CivilDate` | `pub struct` | `std/time/datetime.aipl` | `year: int`, `month: int`, `day: int` | `CivilDate(year, month, day)` |
| `CivilTime` | `pub struct` | `std/time/datetime.aipl` | `hour: int`, `minute: int`, `second: int`, `nanosecond: int` | `CivilTime(hour, minute, second, nanosecond)` |
| `TimeZoneOffset` | `pub struct` | `std/time/datetime.aipl` | `offsetMinutes: int`, `name: str` | `TimeZoneOffset(offsetMinutes, name)` |
| `DateTimeUtc` | `pub struct` | `std/time/datetime.aipl` | `date: CivilDate`, `time: CivilTime`, `offset: TimeZoneOffset`, `unixNanos: int`, `year: int = 0`, `month: int = 0`, `day: int = 0`, `hour: int = 0`, `minute: int = 0`, `second: int = 0` | `DateTimeUtc(date, time, offset, unixNanos, year, month, day, hour, minute, second)` |
| `Date` | `pub struct` | `std/time/datetime.aipl` | `year: int`, `month: int`, `day: int` | `Date(year, month, day)` |
| `Time` | `pub struct` | `std/time/datetime.aipl` | `hour: int`, `minute: int` | `Time(hour, minute)` |
| `CivilDateTime` | `pub struct` | `std/time/datetime.aipl` | `year: int`, `month: int`, `day: int`, `hour: int`, `minute: int`, `second: int` | `CivilDateTime(year, month, day, hour, minute, second)` |
| `DateTime` | `pub struct` | `std/time/datetime.aipl` | `year: int`, `month: int`, `day: int`, `hour: int`, `minute: int`, `second: int` | `DateTime(year, month, day, hour, minute, second)` |
| `Duration` | `pub struct` | `std/time/duration.aipl` | `nanos: int` | `Duration(nanos)` |
| `FixedTimestepAccumulator` | `pub struct` | `std/time/frame_pacer.aipl` | `targetDt: Duration`, `maxSubSteps: int`, `accumulator: Duration`, `lastTime: Instant` | `FixedTimestepAccumulator(targetDt, maxSubSteps, accumulator, lastTime)` |
| `FrameRateGovernor` | `pub struct` | `std/time/frame_pacer.aipl` | `targetFps: int`, `targetFrameDuration: Duration`, `lastFrameTime: Instant`, `currentFps: float` | `FrameRateGovernor(targetFps, targetFrameDuration, lastFrameTime, currentFps)` |
| `Instant` | `pub struct` | `std/time/instant.aipl` | `nanos: int` | `Instant(nanos)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/time/cooldown_timer.aipl` | `cooldownTimerNew` | `pub fn cooldownTimerNew(d: Duration): CooldownTimer:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `2` | `std/time/cooldown_timer.aipl` | `trigger` | `pub fn (mut self: CooldownTimer) trigger(): bool:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `3` | `std/time/cooldown_timer.aipl` | `triggerAt` | `pub fn (mut self: CooldownTimer) triggerAt(now: Instant): bool:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `4` | `std/time/cooldown_timer.aipl` | `reset` | `pub fn (mut self: CooldownTimer) reset(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `5` | `std/time/cooldown_timer.aipl` | `remainingAt` | `pub fn (self: CooldownTimer) remainingAt(now: Instant): Duration:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `6` | `std/time/cooldown_timer.aipl` | `remaining` | `pub fn (self: CooldownTimer) remaining(): Duration:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `7` | `std/time/cooldown_timer.aipl` | `progressAt` | `pub fn (self: CooldownTimer) progressAt(now: Instant): float:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `8` | `std/time/cooldown_timer.aipl` | `progress` | `pub fn (self: CooldownTimer) progress(): float:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `9` | `std/time/cooldown_timer.aipl` | `repeatingTickerNew` | `pub fn repeatingTickerNew(interval: Duration): RepeatingTicker:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `10` | `std/time/cooldown_timer.aipl` | `repeatingTickerNewAt` | `pub fn repeatingTickerNewAt(interval: Duration, start: Instant): RepeatingTicker:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `11` | `std/time/cooldown_timer.aipl` | `pollTicks` | `pub fn (mut self: RepeatingTicker) pollTicks(now: Instant): int:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `12` | `std/time/cooldown_timer.aipl` | `resetAt` | `pub fn (mut self: RepeatingTicker) resetAt(now: Instant): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `13` | `std/time/cooldown_timer.aipl` | `stopwatchNew` | `pub fn stopwatchNew(): Stopwatch:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `14` | `std/time/cooldown_timer.aipl` | `start` | `pub fn (mut self: Stopwatch) start(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `15` | `std/time/cooldown_timer.aipl` | `startAt` | `pub fn (mut self: Stopwatch) startAt(now: Instant): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `16` | `std/time/cooldown_timer.aipl` | `stop` | `pub fn (mut self: Stopwatch) stop(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `17` | `std/time/cooldown_timer.aipl` | `stopAt` | `pub fn (mut self: Stopwatch) stopAt(now: Instant): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `18` | `std/time/cooldown_timer.aipl` | `reset` | `pub fn (mut self: Stopwatch) reset(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `19` | `std/time/cooldown_timer.aipl` | `restart` | `pub fn (mut self: Stopwatch) restart(): Duration:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `20` | `std/time/cooldown_timer.aipl` | `elapsedAt` | `pub fn (self: Stopwatch) elapsedAt(now: Instant): Duration:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `21` | `std/time/cooldown_timer.aipl` | `elapsed` | `pub fn (self: Stopwatch) elapsed(): Duration:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `22` | `std/time/cooldown_timer.aipl` | `elapsedMs` | `pub fn (self: Stopwatch) elapsedMs(): int:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `23` | `std/time/cooldown_timer.aipl` | `debounceTimerNew` | `pub fn debounceTimerNew(delay: Duration): DebounceTimer:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `24` | `std/time/cooldown_timer.aipl` | `trigger` | `pub fn (mut self: DebounceTimer) trigger(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `25` | `std/time/cooldown_timer.aipl` | `triggerAt` | `pub fn (mut self: DebounceTimer) triggerAt(now: Instant): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `26` | `std/time/cooldown_timer.aipl` | `cancel` | `pub fn (mut self: DebounceTimer) cancel(): void:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `27` | `std/time/cooldown_timer.aipl` | `isReady` | `pub fn (mut self: DebounceTimer) isReady(now: Instant): bool:` | `tests/functions/time/cooldown_timer_test.aipl` |
| `28` | `std/time/cron_schedule.aipl` | `parseCronUint` | `fn parseCronUint(s: str): Option[int]:` | `tests/functions/time/cron_schedule_test.aipl` |
| `29` | `std/time/cron_schedule.aipl` | `parseCronFieldBitset` | `fn parseCronFieldBitset(fieldStr: str, minVal: int, maxVal: int): Result[int, str]:` | `tests/functions/time/cron_schedule_test.aipl` |
| `30` | `std/time/cron_schedule.aipl` | `parseCron` | `pub fn parseCron(expression: str): Result[CronSchedule, str]:` | `tests/functions/time/cron_schedule_test.aipl` |
| `31` | `std/time/cron_schedule.aipl` | `isMatch` | `pub fn (self: CronSchedule) isMatch(dt: DateTimeUtc): bool:` | `tests/functions/time/cron_schedule_test.aipl` |
| `32` | `std/time/cron_schedule.aipl` | `nextFireAfter` | `pub fn (self: CronSchedule) nextFireAfter(dt: DateTimeUtc): Option[DateTimeUtc]:` | `tests/functions/time/cron_schedule_test.aipl` |
| `33` | `std/time/cron_schedule.aipl` | `explainCronToken` | `fn explainCronToken(rawField: str, unitName: str): str:` | `tests/functions/time/cron_schedule_test.aipl` |
| `34` | `std/time/cron_schedule.aipl` | `explainCron` | `pub fn explainCron(expr: str): Result[str, str]:` | `tests/functions/time/cron_schedule_test.aipl` |
| `35` | `std/time/cron_schedule.aipl` | `cronMatches` | `pub fn cronMatches(expr: str, minute: int, hour: int, dom: int, month: int, dow: int): bool:` | `tests/functions/time/cron_schedule_test.aipl` |
| `36` | `std/time/datetime.aipl` | `timeZoneUtc` | `pub fn timeZoneUtc(): TimeZoneOffset:` | `tests/functions/time/datetime_test.aipl` |
| `37` | `std/time/datetime.aipl` | `timeZoneOffsetNew` | `pub fn timeZoneOffsetNew(offsetMinutes: int, name: str = ""): TimeZoneOffset:` | `tests/functions/time/datetime_test.aipl` |
| `38` | `std/time/datetime.aipl` | `civilDateNew` | `pub fn civilDateNew(year: int, month: int, day: int): CivilDate:` | `tests/functions/time/datetime_test.aipl` |
| `39` | `std/time/datetime.aipl` | `civilTimeNew` | `pub fn civilTimeNew(hour: int, minute: int, second: int = 0, nanosecond: int = 0): CivilTime:` | `tests/functions/time/datetime_test.aipl` |
| `40` | `std/time/datetime.aipl` | `createDate` | `pub fn createDate(year: int, month: int, day: int): Date:` | `tests/functions/time/datetime_test.aipl` |
| `41` | `std/time/datetime.aipl` | `createTime` | `pub fn createTime(hour: int, minute: int): Time:` | `tests/functions/time/datetime_test.aipl` |
| `42` | `std/time/datetime.aipl` | `isLeapYear` | `pub fn isLeapYear(year: int): bool:` | `tests/functions/time/datetime_test.aipl` |
| `43` | `std/time/datetime.aipl` | `daysInMonth` | `pub fn daysInMonth(year: int, month: int): int:` | `tests/functions/time/datetime_test.aipl` |
| `44` | `std/time/datetime.aipl` | `daysInYear` | `pub fn daysInYear(year: int): int:` | `tests/functions/time/datetime_test.aipl` |
| `45` | `std/time/datetime.aipl` | `dayOfWeek` | `pub fn dayOfWeek(year: int, month: int = 1, day: int = 1): int:` | `tests/functions/time/datetime_test.aipl` |
| `46` | `std/time/datetime.aipl` | `dayOfYear` | `pub fn dayOfYear(year: int, month: int, day: int): int:` | `tests/functions/time/datetime_test.aipl` |
| `47` | `std/time/datetime.aipl` | `isValidCivilDate` | `pub fn isValidCivilDate(year: int, month: int, day: int): bool:` | `tests/functions/time/datetime_test.aipl` |
| `48` | `std/time/datetime.aipl` | `isValidCivilTime` | `pub fn isValidCivilTime(hour: int, minute: int, second: int, nanosecond: int = 0): bool:` | `tests/functions/time/datetime_test.aipl` |
| `49` | `std/time/datetime.aipl` | `monthName` | `pub fn monthName(m: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `50` | `std/time/datetime.aipl` | `monthShortName` | `pub fn monthShortName(m: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `51` | `std/time/datetime.aipl` | `dayOfWeekName` | `pub fn dayOfWeekName(dow: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `52` | `std/time/datetime.aipl` | `dayOfWeekShortName` | `pub fn dayOfWeekShortName(dow: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `53` | `std/time/datetime.aipl` | `dateDayOfWeek` | `pub fn dateDayOfWeek(d: Date): int:` | `tests/functions/time/datetime_test.aipl` |
| `54` | `std/time/datetime.aipl` | `unixToCivil` | `pub fn unixToCivil(unixSec: int): CivilDateTime:` | `tests/functions/time/datetime_test.aipl` |
| `55` | `std/time/datetime.aipl` | `civilToUnix` | `pub fn civilToUnix(dt: CivilDateTime): int:` | `tests/functions/time/datetime_test.aipl` |
| `56` | `std/time/datetime.aipl` | `unixToDateTimeUtc` | `pub fn unixToDateTimeUtc(unixSec: int, unixNano: int = 0): DateTimeUtc:` | `tests/functions/time/datetime_test.aipl` |
| `57` | `std/time/datetime.aipl` | `dateTimeUtcToUnix` | `pub fn dateTimeUtcToUnix(dt: DateTimeUtc): int:` | `tests/functions/time/datetime_test.aipl` |
| `58` | `std/time/datetime.aipl` | `toUnixSeconds` | `pub fn (self: DateTimeUtc) toUnixSeconds(): int:` | `tests/functions/time/datetime_test.aipl` |
| `59` | `std/time/datetime.aipl` | `toUnixMillis` | `pub fn (self: DateTimeUtc) toUnixMillis(): int:` | `tests/functions/time/datetime_test.aipl` |
| `60` | `std/time/datetime.aipl` | `toLocal` | `pub fn (self: DateTimeUtc) toLocal(offset: TimeZoneOffset): DateTimeUtc:` | `tests/functions/time/datetime_test.aipl` |
| `61` | `std/time/datetime.aipl` | `pad2` | `fn pad2(n: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `62` | `std/time/datetime.aipl` | `pad3` | `fn pad3(n: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `63` | `std/time/datetime.aipl` | `pad4` | `fn pad4(n: int): str:` | `tests/functions/time/datetime_test.aipl` |
| `64` | `std/time/datetime.aipl` | `parseDigitsRange` | `fn parseDigitsRange(s: str, start: int, end: int): Result[int, str]:` | `tests/functions/time/datetime_test.aipl` |
| `65` | `std/time/datetime.aipl` | `parseIso8601` | `pub fn parseIso8601(s: str): Result[DateTimeUtc, str]:` | `tests/functions/time/datetime_test.aipl` |
| `66` | `std/time/datetime.aipl` | `formatIso8601` | `pub fn formatIso8601(dt: DateTimeUtc): str:` | `tests/functions/time/datetime_test.aipl` |
| `67` | `std/time/datetime.aipl` | `parseMonthAbbrev` | `fn parseMonthAbbrev(mon: str): int:` | `tests/functions/time/datetime_test.aipl` |
| `68` | `std/time/datetime.aipl` | `formatRfc2822` | `pub fn formatRfc2822(dt: DateTimeUtc): str:` | `tests/functions/time/datetime_test.aipl` |
| `69` | `std/time/datetime.aipl` | `formatRfc822` | `pub fn formatRfc822(dt: DateTimeUtc): str:` | `tests/functions/time/datetime_test.aipl` |
| `70` | `std/time/datetime.aipl` | `parseRfc2822` | `pub fn parseRfc2822(s: str): Result[DateTimeUtc, str]:` | `tests/functions/time/datetime_test.aipl` |
| `71` | `std/time/datetime.aipl` | `parseRfc822` | `pub fn parseRfc822(s: str): Result[DateTimeUtc, str]:` | `tests/functions/time/datetime_test.aipl` |
| `72` | `std/time/datetime.aipl` | `formatDate` | `pub fn formatDate(d: Date): str:` | `tests/functions/time/datetime_test.aipl` |
| `73` | `std/time/datetime.aipl` | `formatTime` | `pub fn formatTime(t: Time): str:` | `tests/functions/time/datetime_test.aipl` |
| `74` | `std/time/datetime.aipl` | `compareDates` | `pub fn compareDates(a: Date, b: Date): int:` | `tests/functions/time/datetime_test.aipl` |
| `75` | `std/time/datetime.aipl` | `isDateBefore` | `pub fn isDateBefore(a: Date, b: Date): bool:` | `tests/functions/time/datetime_test.aipl` |
| `76` | `std/time/datetime.aipl` | `isDateAfter` | `pub fn isDateAfter(a: Date, b: Date): bool:` | `tests/functions/time/datetime_test.aipl` |
| `77` | `std/time/datetime.aipl` | `isDateEqual` | `pub fn isDateEqual(a: Date, b: Date): bool:` | `tests/functions/time/datetime_test.aipl` |
| `78` | `std/time/datetime.aipl` | `dateToDays` | `pub fn dateToDays(d: Date): int:` | `tests/functions/time/datetime_test.aipl` |
| `79` | `std/time/datetime.aipl` | `daysBetween` | `pub fn daysBetween(a: Date, b: Date): int:` | `tests/functions/time/datetime_test.aipl` |
| `80` | `std/time/duration.aipl` | `durationZero` | `pub fn durationZero(): Duration:` | `tests/functions/time/duration_test.aipl` |
| `81` | `std/time/duration.aipl` | `durationFromNanos` | `pub fn durationFromNanos(nanos: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `82` | `std/time/duration.aipl` | `durationFromMicros` | `pub fn durationFromMicros(micros: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `83` | `std/time/duration.aipl` | `durationFromMillis` | `pub fn durationFromMillis(millis: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `84` | `std/time/duration.aipl` | `durationFromMs` | `pub fn durationFromMs(ms: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `85` | `std/time/duration.aipl` | `durationFromSeconds` | `pub fn durationFromSeconds(secs: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `86` | `std/time/duration.aipl` | `durationFromSecondsFloat` | `pub fn durationFromSecondsFloat(secs: float): Duration:` | `tests/functions/time/duration_test.aipl` |
| `87` | `std/time/duration.aipl` | `durationFromMinutes` | `pub fn durationFromMinutes(mins: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `88` | `std/time/duration.aipl` | `durationFromHours` | `pub fn durationFromHours(hours: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `89` | `std/time/duration.aipl` | `durationFromDays` | `pub fn durationFromDays(days: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `90` | `std/time/duration.aipl` | `toNanos` | `pub fn (self: Duration) toNanos(): int:` | `tests/functions/time/duration_test.aipl` |
| `91` | `std/time/duration.aipl` | `toMicros` | `pub fn (self: Duration) toMicros(): int:` | `tests/functions/time/duration_test.aipl` |
| `92` | `std/time/duration.aipl` | `toMillis` | `pub fn (self: Duration) toMillis(): int:` | `tests/functions/time/duration_test.aipl` |
| `93` | `std/time/duration.aipl` | `toMs` | `pub fn (self: Duration) toMs(): int:` | `tests/functions/time/duration_test.aipl` |
| `94` | `std/time/duration.aipl` | `toSeconds` | `pub fn (self: Duration) toSeconds(): int:` | `tests/functions/time/duration_test.aipl` |
| `95` | `std/time/duration.aipl` | `toSecondsFloat` | `pub fn (self: Duration) toSecondsFloat(): float:` | `tests/functions/time/duration_test.aipl` |
| `96` | `std/time/duration.aipl` | `toMinutes` | `pub fn (self: Duration) toMinutes(): int:` | `tests/functions/time/duration_test.aipl` |
| `97` | `std/time/duration.aipl` | `toHours` | `pub fn (self: Duration) toHours(): int:` | `tests/functions/time/duration_test.aipl` |
| `98` | `std/time/duration.aipl` | `subsecNanos` | `pub fn (self: Duration) subsecNanos(): int:` | `tests/functions/time/duration_test.aipl` |
| `99` | `std/time/duration.aipl` | `subsecMillis` | `pub fn (self: Duration) subsecMillis(): int:` | `tests/functions/time/duration_test.aipl` |
| `100` | `std/time/duration.aipl` | `subsecMicros` | `pub fn (self: Duration) subsecMicros(): int:` | `tests/functions/time/duration_test.aipl` |
| `101` | `std/time/duration.aipl` | `isZero` | `pub fn (self: Duration) isZero(): bool:` | `tests/functions/time/duration_test.aipl` |
| `102` | `std/time/duration.aipl` | `isNegative` | `pub fn (self: Duration) isNegative(): bool:` | `tests/functions/time/duration_test.aipl` |
| `103` | `std/time/duration.aipl` | `isPositive` | `pub fn (self: Duration) isPositive(): bool:` | `tests/functions/time/duration_test.aipl` |
| `104` | `std/time/duration.aipl` | `abs` | `pub fn (self: Duration) abs(): Duration:` | `tests/functions/time/duration_test.aipl` |
| `105` | `std/time/duration.aipl` | `add` | `pub fn (self: Duration) add(other: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `106` | `std/time/duration.aipl` | `sub` | `pub fn (self: Duration) sub(other: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `107` | `std/time/duration.aipl` | `saturatingSub` | `pub fn (self: Duration) saturatingSub(other: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `108` | `std/time/duration.aipl` | `mul` | `pub fn (self: Duration) mul(factor: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `109` | `std/time/duration.aipl` | `mulFloat` | `pub fn (self: Duration) mulFloat(factor: float): Duration:` | `tests/functions/time/duration_test.aipl` |
| `110` | `std/time/duration.aipl` | `div` | `pub fn (self: Duration) div(divisor: int): Duration:` | `tests/functions/time/duration_test.aipl` |
| `111` | `std/time/duration.aipl` | `clamp` | `pub fn (self: Duration) clamp(minDur: Duration, maxDur: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `112` | `std/time/duration.aipl` | `min` | `pub fn (self: Duration) min(other: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `113` | `std/time/duration.aipl` | `max` | `pub fn (self: Duration) max(other: Duration): Duration:` | `tests/functions/time/duration_test.aipl` |
| `114` | `std/time/duration.aipl` | `format` | `pub fn (self: Duration) format(): str:` | `tests/functions/time/duration_test.aipl` |
| `115` | `std/time/duration.aipl` | `parseUnsignedDigits` | `fn parseUnsignedDigits(s: str): Result[int, str]:` | `tests/functions/time/duration_test.aipl` |
| `116` | `std/time/duration.aipl` | `parseDuration` | `pub fn parseDuration(spec: str): Result[Duration, str]:` | `tests/functions/time/duration_test.aipl` |
| `117` | `std/time/duration.aipl` | `parseDurationMs` | `pub fn parseDurationMs(spec: str): Result[int, str]:` | `tests/functions/time/duration_test.aipl` |
| `118` | `std/time/duration.aipl` | `formatDurationMs` | `pub fn formatDurationMs(ms: int): str:` | `tests/functions/time/duration_test.aipl` |
| `119` | `std/time/duration.aipl` | `formatDuration` | `pub fn formatDuration(ms: int): str:` | `tests/functions/time/duration_test.aipl` |
| `120` | `std/time/duration.aipl` | `formatMmSs` | `pub fn formatMmSs(sec: int): str:` | `tests/functions/time/duration_test.aipl` |
| `121` | `std/time/duration.aipl` | `formatDurationMS` | `pub fn formatDurationMS(totalSeconds: int): str:` | `tests/functions/time/duration_test.aipl` |
| `122` | `std/time/duration.aipl` | `formatDurationHMS` | `pub fn formatDurationHMS(totalSeconds: int): str:` | `tests/functions/time/duration_test.aipl` |
| `123` | `std/time/duration.aipl` | `formatDurationHhMmSsMs` | `pub fn formatDurationHhMmSsMs(ms: int): str:` | `tests/functions/time/duration_test.aipl` |
| `124` | `std/time/frame_pacer.aipl` | `fixedTimestepAccumulatorNew` | `pub fn fixedTimestepAccumulatorNew(targetHertz: int = 60, maxSubSteps: int = 5): FixedTimestepAccumulator:` | `tests/functions/time/frame_pacer_test.aipl` |
| `125` | `std/time/frame_pacer.aipl` | `advance` | `pub fn (mut self: FixedTimestepAccumulator) advance(currentTime: Instant): int:` | `tests/functions/time/frame_pacer_test.aipl` |
| `126` | `std/time/frame_pacer.aipl` | `alpha` | `pub fn (self: FixedTimestepAccumulator) alpha(): float:` | `tests/functions/time/frame_pacer_test.aipl` |
| `127` | `std/time/frame_pacer.aipl` | `stepSeconds` | `pub fn (self: FixedTimestepAccumulator) stepSeconds(): float:` | `tests/functions/time/frame_pacer_test.aipl` |
| `128` | `std/time/frame_pacer.aipl` | `reset` | `pub fn (mut self: FixedTimestepAccumulator) reset(now: Instant): void:` | `tests/functions/time/frame_pacer_test.aipl` |
| `129` | `std/time/frame_pacer.aipl` | `frameRateGovernorNew` | `pub fn frameRateGovernorNew(targetFps: int = 60): FrameRateGovernor:` | `tests/functions/time/frame_pacer_test.aipl` |
| `130` | `std/time/frame_pacer.aipl` | `beginFrame` | `pub fn (mut self: FrameRateGovernor) beginFrame(): void:` | `tests/functions/time/frame_pacer_test.aipl` |
| `131` | `std/time/frame_pacer.aipl` | `endFrameAndSleep` | `pub fn (mut self: FrameRateGovernor) endFrameAndSleep(): Duration:` | `tests/functions/time/frame_pacer_test.aipl` |
| `132` | `std/time/frame_pacer.aipl` | `setTargetFps` | `pub fn (mut self: FrameRateGovernor) setTargetFps(targetFps: int): void:` | `tests/functions/time/frame_pacer_test.aipl` |
| `133` | `std/time/instant.aipl` | `nowMonoNs` | `pub fn nowMonoNs(): int:` | `tests/functions/time/instant_test.aipl` |
| `134` | `std/time/instant.aipl` | `nowUnixMs` | `pub fn nowUnixMs(): int:` | `tests/functions/time/instant_test.aipl` |
| `135` | `std/time/instant.aipl` | `sleepMs` | `pub fn sleepMs(ms: int): void:` | `tests/functions/time/instant_test.aipl` |
| `136` | `std/time/instant.aipl` | `nowMs` | `pub fn nowMs(): int:` | `tests/functions/time/instant_test.aipl` |
| `137` | `std/time/instant.aipl` | `nowEpochSeconds` | `pub fn nowEpochSeconds(): int:` | `tests/functions/time/instant_test.aipl` |
| `138` | `std/time/instant.aipl` | `nowMicros` | `pub fn nowMicros(): int:` | `tests/functions/time/instant_test.aipl` |
| `139` | `std/time/instant.aipl` | `instantFromNanos` | `pub fn instantFromNanos(nanos: int): Instant:` | `tests/functions/time/instant_test.aipl` |
| `140` | `std/time/instant.aipl` | `instantFromMillis` | `pub fn instantFromMillis(millis: int): Instant:` | `tests/functions/time/instant_test.aipl` |
| `141` | `std/time/instant.aipl` | `instantNow` | `pub fn instantNow(): Instant:` | `tests/functions/time/instant_test.aipl` |
| `142` | `std/time/instant.aipl` | `toNanos` | `pub fn (self: Instant) toNanos(): int:` | `tests/functions/time/instant_test.aipl` |
| `143` | `std/time/instant.aipl` | `toMillis` | `pub fn (self: Instant) toMillis(): int:` | `tests/functions/time/instant_test.aipl` |
| `144` | `std/time/instant.aipl` | `toMicros` | `pub fn (self: Instant) toMicros(): int:` | `tests/functions/time/instant_test.aipl` |
| `145` | `std/time/instant.aipl` | `durationSince` | `pub fn (self: Instant) durationSince(earlier: Instant): Duration:` | `tests/functions/time/instant_test.aipl` |
| `146` | `std/time/instant.aipl` | `signedDurationSince` | `pub fn (self: Instant) signedDurationSince(earlier: Instant): Duration:` | `tests/functions/time/instant_test.aipl` |
| `147` | `std/time/instant.aipl` | `checkedDurationSince` | `pub fn (self: Instant) checkedDurationSince(earlier: Instant): Option[Duration]:` | `tests/functions/time/instant_test.aipl` |
| `148` | `std/time/instant.aipl` | `saturatingDurationSince` | `pub fn (self: Instant) saturatingDurationSince(earlier: Instant): Duration:` | `tests/functions/time/instant_test.aipl` |
| `149` | `std/time/instant.aipl` | `elapsed` | `pub fn (self: Instant) elapsed(): Duration:` | `tests/functions/time/instant_test.aipl` |
| `150` | `std/time/instant.aipl` | `elapsedMs` | `pub fn (self: Instant) elapsedMs(): int:` | `tests/functions/time/instant_test.aipl` |
| `151` | `std/time/instant.aipl` | `elapsedMicros` | `pub fn (self: Instant) elapsedMicros(): int:` | `tests/functions/time/instant_test.aipl` |
| `152` | `std/time/instant.aipl` | `elapsedNanos` | `pub fn (self: Instant) elapsedNanos(): int:` | `tests/functions/time/instant_test.aipl` |
| `153` | `std/time/instant.aipl` | `addDuration` | `pub fn (self: Instant) addDuration(d: Duration): Instant:` | `tests/functions/time/instant_test.aipl` |
| `154` | `std/time/instant.aipl` | `subDuration` | `pub fn (self: Instant) subDuration(d: Duration): Instant:` | `tests/functions/time/instant_test.aipl` |
| `155` | `std/time/instant.aipl` | `isAfter` | `pub fn (self: Instant) isAfter(other: Instant): bool:` | `tests/functions/time/instant_test.aipl` |
| `156` | `std/time/instant.aipl` | `isBefore` | `pub fn (self: Instant) isBefore(other: Instant): bool:` | `tests/functions/time/instant_test.aipl` |
| `157` | `std/time/instant.aipl` | `equals` | `pub fn (self: Instant) equals(other: Instant): bool:` | `tests/functions/time/instant_test.aipl` |
| `158` | `std/time/instant.aipl` | `min` | `pub fn (self: Instant) min(other: Instant): Instant:` | `tests/functions/time/instant_test.aipl` |
| `159` | `std/time/instant.aipl` | `max` | `pub fn (self: Instant) max(other: Instant): Instant:` | `tests/functions/time/instant_test.aipl` |
| `160` | `std/time/instant.aipl` | `clamp` | `pub fn (self: Instant) clamp(minInst: Instant, maxInst: Instant): Instant:` | `tests/functions/time/instant_test.aipl` |
| `161` | `std/time/time_mod.aipl` | `epochSeconds` | `pub fn epochSeconds(): int:` | `tests/functions/time/time_mod_test.aipl` |
| `162` | `std/time/time_mod.aipl` | `epochMillis` | `pub fn epochMillis(): int:` | `tests/functions/time/time_mod_test.aipl` |
| `163` | `std/time/time_mod.aipl` | `epochNanos` | `pub fn epochNanos(): int:` | `tests/functions/time/time_mod_test.aipl` |
| `164` | `std/time/time_mod.aipl` | `nowUtc` | `pub fn nowUtc(): DateTimeUtc:` | `tests/functions/time/time_mod_test.aipl` |
| `165` | `std/time/time_mod.aipl` | `sleep` | `pub fn sleep(duration: Duration): void:` | `tests/functions/time/time_mod_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `cooldownTimerNew` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn cooldownTimerNew(d: Duration): CooldownTimer:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Duration` | **Returns**: `CooldownTimer`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `cooldownTimerNew` (`free fn`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: `d: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `CooldownTimer(`.

```aipl
module tests.functions.time.cooldown_timer_z1_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_cooldownTimerNew_1(): int:
  let arg_d = Duration(nanos = 4)
  let edge_d = Duration(nanos = 1)
  let resNom = cooldownTimerNew(arg_d)
  let resEdge = cooldownTimerNew(edge_d)
  assert(resNom.isReady == true, "cooldownTimerNew nominal resNom.isReady == true")
  assert(resEdge.isReady == true, "cooldownTimerNew boundary resEdge.isReady == true")
  ret 0
```

---

### `trigger` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: CooldownTimer) trigger(): bool:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: CooldownTimer` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `trigger` (`mut self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.time.cooldown_timer_z2_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_trigger_2(): int:
  let mut recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let mut edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let resNom = recv_self.trigger()
  let resEdge = edge_self.trigger()
  assert(resNom == true, "trigger nominal resNom == true")
  assert(resEdge == true, "trigger boundary resEdge == true")
  ret 0
```

---

### `triggerAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: CooldownTimer) triggerAt(now: Instant): bool:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: CooldownTimer` | **Parameters**: `now: Instant` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `triggerAt` (`mut self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.time.cooldown_timer_z3_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_triggerAt_3(): int:
  let mut recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let mut edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.triggerAt(arg_now)
  let resEdge = edge_self.triggerAt(edge_now)
  assert(resNom == true, "triggerAt nominal resNom == true")
  assert(resEdge == false, "triggerAt boundary resEdge == false")
  ret 0
```

---

### `reset` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: CooldownTimer) reset(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: CooldownTimer` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `reset` (`mut self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z4_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_reset_4(): int:
  let mut recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let mut edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  recv_self.reset()
  edge_self.reset()
  assertEqInt(recv_self.lastTrigger.nanos, 0, "reset nominal recv_self.lastTrigger.nanos == 0")
  assertEqInt(edge_self.lastTrigger.nanos, 0, "reset boundary edge_self.lastTrigger.nanos == 0")
  ret 0
```

---

### `remainingAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: CooldownTimer) remainingAt(now: Instant): Duration:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CooldownTimer` | **Parameters**: `now: Instant` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `remainingAt` (`self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `durationFromNanos(remNs)`.

```aipl
module tests.functions.time.cooldown_timer_z5_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_remainingAt_5(): int:
  let recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.remainingAt(arg_now)
  let resEdge = edge_self.remainingAt(edge_now)
  assertEqInt(resNom.nanos, 0, "remainingAt nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 1, "remainingAt boundary resEdge.nanos == 1")
  ret 0
```

---

### `remaining` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: CooldownTimer) remaining(): Duration:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CooldownTimer` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `remaining` (`self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`; exercises core body path returning/computing `self.remainingAt(instantNow())`.

```aipl
module tests.functions.time.cooldown_timer_z6_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_remaining_6(): int:
  let recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let resNom = recv_self.remaining()
  let resEdge = edge_self.remaining()
  assertEqInt(resNom.nanos, 0, "remaining nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "remaining boundary resEdge.nanos == 0")
  ret 0
```

---

### `progressAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: CooldownTimer) progressAt(now: Instant): float:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CooldownTimer` | **Parameters**: `now: Instant` | **Returns**: `float`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `progressAt` (`self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `float(elapsedNs) / float(totalNs)`.

```aipl
module tests.functions.time.cooldown_timer_z7_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_progressAt_7(): int:
  let recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.progressAt(arg_now)
  let resEdge = edge_self.progressAt(edge_now)
  assertApproxEq(resNom, 1.0, 0.001, "progressAt nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.0, 0.001, "progressAt boundary resEdge ~= 0.0")
  ret 0
```

---

### `progress` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: CooldownTimer) progress(): float:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CooldownTimer` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `progress` (`self: CooldownTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: CooldownTimer = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = true)`; exercises core body path returning/computing `self.progressAt(instantNow())`.

```aipl
module tests.functions.time.cooldown_timer_z8_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_CooldownTimer_progress_8(): int:
  let recv_self = CooldownTimer(duration = Duration(nanos = 4), lastTrigger = Instant(nanos = 4), isReady = true)
  let edge_self = CooldownTimer(duration = Duration(nanos = 1), lastTrigger = Instant(nanos = 1), isReady = false)
  let resNom = recv_self.progress()
  let resEdge = edge_self.progress()
  assertApproxEq(resNom, 1.0, 0.001, "progress nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "progress boundary resEdge ~= 1.0")
  ret 0
```

---

### `repeatingTickerNew` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn repeatingTickerNew(interval: Duration): RepeatingTicker:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `interval: Duration` | **Returns**: `RepeatingTicker`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `repeatingTickerNew` (`free fn`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: `interval: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `RepeatingTicker(`.

```aipl
module tests.functions.time.cooldown_timer_z9_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_repeatingTickerNew_9(): int:
  let arg_interval = Duration(nanos = 4)
  let edge_interval = Duration(nanos = 1)
  let resNom = repeatingTickerNew(arg_interval)
  let resEdge = repeatingTickerNew(edge_interval)
  assertEqInt(resNom.ticksPending, 0, "repeatingTickerNew nominal resNom.ticksPending == 0")
  assertEqInt(resEdge.ticksPending, 0, "repeatingTickerNew boundary resEdge.ticksPending == 0")
  ret 0
```

---

### `repeatingTickerNewAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn repeatingTickerNewAt(interval: Duration, start: Instant): RepeatingTicker:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `interval: Duration, start: Instant` | **Returns**: `RepeatingTicker`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `repeatingTickerNewAt` (`free fn`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: `interval: Duration = Duration(nanos = 1)`, `start: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `RepeatingTicker(`.

```aipl
module tests.functions.time.cooldown_timer_z10_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_repeatingTickerNewAt_10(): int:
  let arg_interval = Duration(nanos = 4)
  let edge_interval = Duration(nanos = 1)
  let arg_start = Instant(nanos = 4)
  let edge_start = Instant(nanos = 1)
  let resNom = repeatingTickerNewAt(arg_interval, arg_start)
  let resEdge = repeatingTickerNewAt(edge_interval, edge_start)
  assertEqInt(resNom.ticksPending, 0, "repeatingTickerNewAt nominal resNom.ticksPending == 0")
  assertEqInt(resEdge.ticksPending, 0, "repeatingTickerNewAt boundary resEdge.ticksPending == 0")
  ret 0
```

---

### `pollTicks` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: RepeatingTicker) pollTicks(now: Instant): int:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: RepeatingTicker` | **Parameters**: `now: Instant` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `pollTicks` (`mut self: RepeatingTicker`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: RepeatingTicker = RepeatingTicker(interval = Duration(nanos = 1), lastTick = Instant(nanos = 1), ticksPending = 1)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.time.cooldown_timer_z11_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_RepeatingTicker_pollTicks_11(): int:
  let mut recv_self = RepeatingTicker(interval = Duration(nanos = 4), lastTick = Instant(nanos = 4), ticksPending = 4)
  let mut edge_self = RepeatingTicker(interval = Duration(nanos = 1), lastTick = Instant(nanos = 1), ticksPending = 1)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.pollTicks(arg_now)
  let resEdge = edge_self.pollTicks(edge_now)
  assertEqInt(resNom, 0, "pollTicks nominal resNom == 0")
  assertEqInt(resEdge, 0, "pollTicks boundary resEdge == 0")
  ret 0
```

---

### `resetAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: RepeatingTicker) resetAt(now: Instant): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: RepeatingTicker` | **Parameters**: `now: Instant` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `resetAt` (`mut self: RepeatingTicker`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: RepeatingTicker = RepeatingTicker(interval = Duration(nanos = 1), lastTick = Instant(nanos = 1), ticksPending = 1)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z12_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_RepeatingTicker_resetAt_12(): int:
  let mut recv_self = RepeatingTicker(interval = Duration(nanos = 4), lastTick = Instant(nanos = 4), ticksPending = 4)
  let mut edge_self = RepeatingTicker(interval = Duration(nanos = 1), lastTick = Instant(nanos = 1), ticksPending = 1)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  recv_self.resetAt(arg_now)
  edge_self.resetAt(edge_now)
  assertEqInt(recv_self.ticksPending, 0, "resetAt nominal recv_self.ticksPending == 0")
  assertEqInt(edge_self.ticksPending, 0, "resetAt boundary edge_self.ticksPending == 0")
  ret 0
```

---

### `stopwatchNew` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn stopwatchNew(): Stopwatch:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Stopwatch`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `stopwatchNew` (`free fn`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Stopwatch(`.

```aipl
module tests.functions.time.cooldown_timer_z13_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_stopwatchNew_13(): int:
  let resNom = stopwatchNew()
  let resEdge = stopwatchNew()
  assert(resNom.isRunning == false, "stopwatchNew nominal resNom.isRunning == false")
  assert(resEdge.isRunning == false, "stopwatchNew boundary resEdge.isRunning == false")
  ret 0
```

---

### `start` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) start(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `start` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z14_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_start_14(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  recv_self.start()
  edge_self.start()
  assert(recv_self.isRunning == true, "start nominal recv_self.isRunning == true")
  assert(edge_self.isRunning == true, "start boundary edge_self.isRunning == true")
  ret 0
```

---

### `startAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) startAt(now: Instant): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `now: Instant` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `startAt` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z15_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_startAt_15(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  recv_self.startAt(arg_now)
  edge_self.startAt(edge_now)
  assert(recv_self.isRunning == true, "startAt nominal recv_self.isRunning == true")
  assert(edge_self.isRunning == true, "startAt boundary edge_self.isRunning == true")
  ret 0
```

---

### `stop` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) stop(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `stop` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z16_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_stop_16(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  recv_self.stop()
  edge_self.stop()
  assert(recv_self.isRunning == false, "stop nominal recv_self.isRunning == false")
  assert(edge_self.isRunning == false, "stop boundary edge_self.isRunning == false")
  ret 0
```

---

### `stopAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) stopAt(now: Instant): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `now: Instant` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `stopAt` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z17_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_stopAt_17(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  recv_self.stopAt(arg_now)
  edge_self.stopAt(edge_now)
  assert(recv_self.isRunning == false, "stopAt nominal recv_self.isRunning == false")
  assert(edge_self.isRunning == false, "stopAt boundary edge_self.isRunning == false")
  ret 0
```

---

### `reset` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) reset(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `reset` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z18_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_reset_18(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  recv_self.reset()
  edge_self.reset()
  assertEqInt(recv_self.startInstant.nanos, 0, "reset nominal recv_self.startInstant.nanos == 0")
  assertEqInt(edge_self.startInstant.nanos, 0, "reset boundary edge_self.startInstant.nanos == 0")
  ret 0
```

---

### `restart` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: Stopwatch) restart(): Duration:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: Stopwatch` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `restart` (`mut self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.time.cooldown_timer_z19_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_restart_19(): int:
  let mut recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let mut edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let resNom = recv_self.restart()
  let resEdge = edge_self.restart()
  assert(resNom.nanos > 0, "restart nominal resNom.nanos > 0")
  assertEqInt(resEdge.nanos, 1, "restart boundary resEdge.nanos == 1")
  ret 0
```

---

### `elapsedAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: Stopwatch) elapsedAt(now: Instant): Duration:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Stopwatch` | **Parameters**: `now: Instant` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `elapsedAt` (`self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.accumulated.add(active)`.

```aipl
module tests.functions.time.cooldown_timer_z20_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_elapsedAt_20(): int:
  let recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.elapsedAt(arg_now)
  let resEdge = edge_self.elapsedAt(edge_now)
  assertEqInt(resNom.nanos, 4, "elapsedAt nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "elapsedAt boundary resEdge.nanos == 1")
  ret 0
```

---

### `elapsed` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: Stopwatch) elapsed(): Duration:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Stopwatch` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `elapsed` (`self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `self.elapsedAt(instantNow())`.

```aipl
module tests.functions.time.cooldown_timer_z21_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_elapsed_21(): int:
  let recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let resNom = recv_self.elapsed()
  let resEdge = edge_self.elapsed()
  assert(resNom.nanos > 0, "elapsed nominal resNom.nanos > 0")
  assertEqInt(resEdge.nanos, 1, "elapsed boundary resEdge.nanos == 1")
  ret 0
```

---

### `elapsedMs` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (self: Stopwatch) elapsedMs(): int:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Stopwatch` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `elapsedMs` (`self: Stopwatch`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: Stopwatch = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = true)`; exercises core body path returning/computing `self.elapsed().toMillis()`.

```aipl
module tests.functions.time.cooldown_timer_z22_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_Stopwatch_elapsedMs_22(): int:
  let recv_self = Stopwatch(startInstant = Instant(nanos = 4), accumulated = Duration(nanos = 4), isRunning = true)
  let edge_self = Stopwatch(startInstant = Instant(nanos = 1), accumulated = Duration(nanos = 1), isRunning = false)
  let resNom = recv_self.elapsedMs()
  let resEdge = edge_self.elapsedMs()
  assert(resNom > 0, "elapsedMs nominal resNom > 0")
  assertEqInt(resEdge, 0, "elapsedMs boundary resEdge == 0")
  ret 0
```

---

### `debounceTimerNew` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn debounceTimerNew(delay: Duration): DebounceTimer:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `delay: Duration` | **Returns**: `DebounceTimer`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `debounceTimerNew` (`free fn`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: `delay: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `DebounceTimer(`.

```aipl
module tests.functions.time.cooldown_timer_z23_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_debounceTimerNew_23(): int:
  let arg_delay = Duration(nanos = 4)
  let edge_delay = Duration(nanos = 1)
  let resNom = debounceTimerNew(arg_delay)
  let resEdge = debounceTimerNew(edge_delay)
  assert(resNom.hasPending == false, "debounceTimerNew nominal resNom.hasPending == false")
  assert(resEdge.hasPending == false, "debounceTimerNew boundary resEdge.hasPending == false")
  ret 0
```

---

### `trigger` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: DebounceTimer) trigger(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: DebounceTimer` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `trigger` (`mut self: DebounceTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: DebounceTimer = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z24_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_DebounceTimer_trigger_24(): int:
  let mut recv_self = DebounceTimer(delay = Duration(nanos = 4), pendingInstant = Instant(nanos = 4), hasPending = true)
  let mut edge_self = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = false)
  recv_self.trigger()
  edge_self.trigger()
  assert(recv_self.hasPending == true, "trigger nominal recv_self.hasPending == true")
  assert(edge_self.hasPending == true, "trigger boundary edge_self.hasPending == true")
  ret 0
```

---

### `triggerAt` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: DebounceTimer) triggerAt(now: Instant): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: DebounceTimer` | **Parameters**: `now: Instant` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `triggerAt` (`mut self: DebounceTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: DebounceTimer = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z25_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_DebounceTimer_triggerAt_25(): int:
  let mut recv_self = DebounceTimer(delay = Duration(nanos = 4), pendingInstant = Instant(nanos = 4), hasPending = true)
  let mut edge_self = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  recv_self.triggerAt(arg_now)
  edge_self.triggerAt(edge_now)
  assert(recv_self.hasPending == true, "triggerAt nominal recv_self.hasPending == true")
  assert(edge_self.hasPending == true, "triggerAt boundary edge_self.hasPending == true")
  ret 0
```

---

### `cancel` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: DebounceTimer) cancel(): void:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: DebounceTimer` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `cancel` (`mut self: DebounceTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: DebounceTimer = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = true)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.cooldown_timer_z26_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_DebounceTimer_cancel_26(): int:
  let mut recv_self = DebounceTimer(delay = Duration(nanos = 4), pendingInstant = Instant(nanos = 4), hasPending = true)
  let mut edge_self = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = false)
  recv_self.cancel()
  edge_self.cancel()
  assert(recv_self.hasPending == false, "cancel nominal recv_self.hasPending == false")
  assert(edge_self.hasPending == false, "cancel boundary edge_self.hasPending == false")
  ret 0
```

---

### `isReady` (`std/time/cooldown_timer.aipl`)

- **Signature**: `pub fn (mut self: DebounceTimer) isReady(now: Instant): bool:`
- **Import**: `import * from "std/time/cooldown_timer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: DebounceTimer` | **Parameters**: `now: Instant` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/cooldown_timer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify game timer / ticker / stopwatch / debounce function `isReady` (`mut self: DebounceTimer`) across cooldown readiness gates, normalized `[0.0, 1.0]` progress, multi-tick catch-up, and rapid-trigger debounce resets. Concrete nominal inputs: receiver `recvObj: DebounceTimer = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = true)`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.time.cooldown_timer_z27_test
import * from "std/time/cooldown_timer"
import { Duration, durationZero, durationFromNanos } from "std/time/duration"
import { Instant, instantNow, instantFromNanos } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cooldown_timer_DebounceTimer_isReady_27(): int:
  let mut recv_self = DebounceTimer(delay = Duration(nanos = 4), pendingInstant = Instant(nanos = 4), hasPending = true)
  let mut edge_self = DebounceTimer(delay = Duration(nanos = 1), pendingInstant = Instant(nanos = 1), hasPending = false)
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  let resNom = recv_self.isReady(arg_now)
  let resEdge = edge_self.isReady(edge_now)
  assert(resNom == false, "isReady nominal resNom == false")
  assert(resEdge == false, "isReady boundary resEdge == false")
  ret 0
```

---

### `parseCronUint` (`std/time/cron_schedule.aipl`)

- **Signature**: `fn parseCronUint(s: str): Option[int]:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Option[int]`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `parseCronUint` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Some(acc)`.

```aipl
module tests.functions.time.cron_schedule_z1_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_parseCronUint_1(): int:
  let arg_s = "42"
  let edge_s = "0"
  let resNom = parseCronUint(arg_s)
  let resEdge = parseCronUint(edge_s)
  assert(resNom.isSome() == true, "parseCronUint nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "parseCronUint boundary resEdge.isSome() == true")
  ret 0
```

---

### `parseCronFieldBitset` (`std/time/cron_schedule.aipl`)

- **Signature**: `fn parseCronFieldBitset(fieldStr: str, minVal: int, maxVal: int): Result[int, str]:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `fieldStr: str, minVal: int, maxVal: int` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `parseCronFieldBitset` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `fieldStr: str = "aipl_test"`, `minVal: int = 1`, `maxVal: int = 1`; exercises core body path returning/computing `Ok(mask)`.

```aipl
module tests.functions.time.cron_schedule_z2_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_parseCronFieldBitset_2(): int:
  let arg_fieldStr = "test"
  let edge_fieldStr = "a"
  let arg_minVal = 4
  let edge_minVal = 1
  let arg_maxVal = 4
  let edge_maxVal = 1
  let resNom = parseCronFieldBitset(arg_fieldStr, arg_minVal, arg_maxVal)
  let resEdge = parseCronFieldBitset(edge_fieldStr, edge_minVal, edge_maxVal)
  assert(resNom.isOk() == false, "parseCronFieldBitset nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseCronFieldBitset boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseCron` (`std/time/cron_schedule.aipl`)

- **Signature**: `pub fn parseCron(expression: str): Result[CronSchedule, str]:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `expression: str` | **Returns**: `Result[CronSchedule, str]`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `parseCron` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `expression: str = "aipl_test"`; exercises core body path returning/computing `Ok(CronSchedule(`.

```aipl
module tests.functions.time.cron_schedule_z3_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_parseCron_3(): int:
  let arg_expression = "test"
  let edge_expression = "a"
  let resNom = parseCron(arg_expression)
  let resEdge = parseCron(edge_expression)
  assert(resNom.isOk() == false, "parseCron nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseCron boundary resEdge.isOk() == false")
  ret 0
```

---

### `isMatch` (`std/time/cron_schedule.aipl`)

- **Signature**: `pub fn (self: CronSchedule) isMatch(dt: DateTimeUtc): bool:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CronSchedule` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `isMatch` (`self: CronSchedule`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: receiver `recvObj: CronSchedule = CronSchedule(minuteBitset = 1, hourBitset = 1, dayOfMonthBitset = 1, monthBitset = 1, dayOfWeekBitset = 1, hasSeconds = true, secondBitset = 1)`, `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.time.cron_schedule_z4_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_CronSchedule_isMatch_4(): int:
  let recv_self = CronSchedule(minuteBitset = 4, hourBitset = 4, dayOfMonthBitset = 4, monthBitset = 4, dayOfWeekBitset = 4, hasSeconds = true, secondBitset = 4)
  let edge_self = CronSchedule(minuteBitset = 1, hourBitset = 1, dayOfMonthBitset = 1, monthBitset = 1, dayOfWeekBitset = 1, hasSeconds = false, secondBitset = 1)
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = recv_self.isMatch(arg_dt)
  let resEdge = edge_self.isMatch(edge_dt)
  assert(resNom == false, "isMatch nominal resNom == false")
  assert(resEdge == false, "isMatch boundary resEdge == false")
  ret 0
```

---

### `nextFireAfter` (`std/time/cron_schedule.aipl`)

- **Signature**: `pub fn (self: CronSchedule) nextFireAfter(dt: DateTimeUtc): Option[DateTimeUtc]:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: CronSchedule` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `Option[DateTimeUtc]`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `nextFireAfter` (`self: CronSchedule`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: receiver `recvObj: CronSchedule = CronSchedule(minuteBitset = 1, hourBitset = 1, dayOfMonthBitset = 1, monthBitset = 1, dayOfWeekBitset = 1, hasSeconds = true, secondBitset = 1)`, `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.time.cron_schedule_z5_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_CronSchedule_nextFireAfter_5(): int:
  let recv_self = CronSchedule(minuteBitset = 4, hourBitset = 4, dayOfMonthBitset = 4, monthBitset = 4, dayOfWeekBitset = 4, hasSeconds = true, secondBitset = 4)
  let edge_self = CronSchedule(minuteBitset = 1, hourBitset = 1, dayOfMonthBitset = 1, monthBitset = 1, dayOfWeekBitset = 1, hasSeconds = false, secondBitset = 1)
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = recv_self.nextFireAfter(arg_dt)
  let resEdge = edge_self.nextFireAfter(edge_dt)
  assert(resNom.isSome() == false, "nextFireAfter nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "nextFireAfter boundary resEdge.isSome() == false")
  ret 0
```

---

### `explainCronToken` (`std/time/cron_schedule.aipl`)

- **Signature**: `fn explainCronToken(rawField: str, unitName: str): str:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawField: str, unitName: str` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `explainCronToken` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `rawField: str = "aipl_test"`, `unitName: str = "aipl_test"`; exercises core body path returning/computing `"{unitName} {rawField}"`.

```aipl
module tests.functions.time.cron_schedule_z6_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_explainCronToken_6(): int:
  let arg_rawField = "test"
  let edge_rawField = "a"
  let arg_unitName = "test"
  let edge_unitName = "a"
  let resNom = explainCronToken(arg_rawField, arg_unitName)
  let resEdge = explainCronToken(edge_rawField, edge_unitName)
  assertEqStr(resNom, "test test", "explainCronToken nominal string matches")
  assertEqStr(resEdge, "a a", "explainCronToken boundary string matches")
  ret 0
```

---

### `explainCron` (`std/time/cron_schedule.aipl`)

- **Signature**: `pub fn explainCron(expr: str): Result[str, str]:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `expr: str` | **Returns**: `Result[str, str]`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `explainCron` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `expr: str = "aipl_test"`; exercises core body path returning/computing `Ok("At {minDesc}, {hrDesc}, on {domDesc}, in {monDesc} ({dowDesc})")`.

```aipl
module tests.functions.time.cron_schedule_z7_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_explainCron_7(): int:
  let arg_expr = "test"
  let edge_expr = "a"
  let resNom = explainCron(arg_expr)
  let resEdge = explainCron(edge_expr)
  assert(resNom.isOk() == false, "explainCron nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "explainCron boundary resEdge.isOk() == false")
  ret 0
```

---

### `cronMatches` (`std/time/cron_schedule.aipl`)

- **Signature**: `pub fn cronMatches(expr: str, minute: int, hour: int, dom: int, month: int, dow: int): bool:`
- **Import**: `import * from "std/time/cron_schedule"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `expr: str, minute: int, hour: int, dom: int, month: int, dow: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/cron_schedule_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify 5-field POSIX cron parser/matcher `cronMatches` (`free fn`) across step `*/15`, range `9-17`, list `1,3,5`, wildcard `*`, and `nextFireAfter` rollover across day/month boundaries. Concrete nominal inputs: `expr: str = "aipl_test"`, `minute: int = 1`, `hour: int = 1`, `dom: int = 1`, `month: int = 1`, `dow: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.time.cron_schedule_z8_test
import * from "std/time/cron_schedule"
import { DateTimeUtc, dayOfWeek, dateTimeUtcToUnix, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_cron_schedule_cronMatches_8(): int:
  let arg_expr = "test"
  let edge_expr = "a"
  let arg_minute = 4
  let edge_minute = 1
  let arg_hour = 2
  let edge_hour = 0
  let arg_dom = 4
  let edge_dom = 1
  let arg_month = 4
  let edge_month = 1
  let arg_dow = 2
  let edge_dow = 0
  let resNom = cronMatches(arg_expr, arg_minute, arg_hour, arg_dom, arg_month, arg_dow)
  let resEdge = cronMatches(edge_expr, edge_minute, edge_hour, edge_dom, edge_month, edge_dow)
  assert(resNom == false, "cronMatches nominal resNom == false")
  assert(resEdge == false, "cronMatches boundary resEdge == false")
  ret 0
```

---

### `timeZoneUtc` (`std/time/datetime.aipl`)

- **Signature**: `pub fn timeZoneUtc(): TimeZoneOffset:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `TimeZoneOffset`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `timeZoneUtc` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `TimeZoneOffset(offsetMinutes = 0, name = "UTC")`.

```aipl
module tests.functions.time.datetime_z1_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_timeZoneUtc_1(): int:
  let resNom = timeZoneUtc()
  let resEdge = timeZoneUtc()
  assertEqInt(resNom.offsetMinutes, 0, "timeZoneUtc nominal resNom.offsetMinutes == 0")
  assertEqInt(resEdge.offsetMinutes, 0, "timeZoneUtc boundary resEdge.offsetMinutes == 0")
  ret 0
```

---

### `timeZoneOffsetNew` (`std/time/datetime.aipl`)

- **Signature**: `pub fn timeZoneOffsetNew(offsetMinutes: int, name: str = ""): TimeZoneOffset:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `offsetMinutes: int, name: str = ""` | **Returns**: `TimeZoneOffset`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `timeZoneOffsetNew` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `offsetMinutes: int = 0`, `name: str = "aipl_test"`; exercises core body path returning/computing `TimeZoneOffset(offsetMinutes = offsetMinutes, name = label)`.

```aipl
module tests.functions.time.datetime_z2_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_timeZoneOffsetNew_2(): int:
  let arg_offsetMinutes = 4
  let edge_offsetMinutes = 1
  let arg_name = "test"
  let edge_name = "a"
  let resNom = timeZoneOffsetNew(arg_offsetMinutes, arg_name)
  let resEdge = timeZoneOffsetNew(edge_offsetMinutes, edge_name)
  assertEqInt(resNom.offsetMinutes, 4, "timeZoneOffsetNew nominal resNom.offsetMinutes == 4")
  assertEqInt(resEdge.offsetMinutes, 1, "timeZoneOffsetNew boundary resEdge.offsetMinutes == 1")
  ret 0
```

---

### `civilDateNew` (`std/time/datetime.aipl`)

- **Signature**: `pub fn civilDateNew(year: int, month: int, day: int): CivilDate:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int, day: int` | **Returns**: `CivilDate`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `civilDateNew` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`, `day: int = 1`; exercises core body path returning/computing `CivilDate(year = year, month = month, day = day)`.

```aipl
module tests.functions.time.datetime_z3_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_civilDateNew_3(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let arg_day = 1
  let edge_day = 0
  let resNom = civilDateNew(arg_year, arg_month, arg_day)
  let resEdge = civilDateNew(edge_year, edge_month, edge_day)
  assertEqInt(resNom.year, 1, "civilDateNew nominal resNom.year == 1")
  assertEqInt(resEdge.year, 0, "civilDateNew boundary resEdge.year == 0")
  ret 0
```

---

### `civilTimeNew` (`std/time/datetime.aipl`)

- **Signature**: `pub fn civilTimeNew(hour: int, minute: int, second: int = 0, nanosecond: int = 0): CivilTime:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hour: int, minute: int, second: int = 0, nanosecond: int = 0` | **Returns**: `CivilTime`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `civilTimeNew` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `hour: int = 1`, `minute: int = 1`, `second: int = 1`, `nanosecond: int = 1`; exercises core body path returning/computing `CivilTime(hour = hour, minute = minute, second = second, nanosecond = nanosecond)`.

```aipl
module tests.functions.time.datetime_z4_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_civilTimeNew_4(): int:
  let arg_hour = 2
  let edge_hour = 0
  let arg_minute = 4
  let edge_minute = 1
  let arg_second = 4
  let edge_second = 1
  let arg_nanosecond = 4
  let edge_nanosecond = 1
  let resNom = civilTimeNew(arg_hour, arg_minute, arg_second, arg_nanosecond)
  let resEdge = civilTimeNew(edge_hour, edge_minute, edge_second, edge_nanosecond)
  assertEqInt(resNom.hour, 2, "civilTimeNew nominal resNom.hour == 2")
  assertEqInt(resEdge.hour, 0, "civilTimeNew boundary resEdge.hour == 0")
  ret 0
```

---

### `createDate` (`std/time/datetime.aipl`)

- **Signature**: `pub fn createDate(year: int, month: int, day: int): Date:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int, day: int` | **Returns**: `Date`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `createDate` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`, `day: int = 1`; exercises core body path returning/computing `Date(year = year, month = month, day = day)`.

```aipl
module tests.functions.time.datetime_z5_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_createDate_5(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let arg_day = 1
  let edge_day = 0
  let resNom = createDate(arg_year, arg_month, arg_day)
  let resEdge = createDate(edge_year, edge_month, edge_day)
  assertEqInt(resNom.year, 1, "createDate nominal resNom.year == 1")
  assertEqInt(resEdge.year, 0, "createDate boundary resEdge.year == 0")
  ret 0
```

---

### `createTime` (`std/time/datetime.aipl`)

- **Signature**: `pub fn createTime(hour: int, minute: int): Time:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hour: int, minute: int` | **Returns**: `Time`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `createTime` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `hour: int = 1`, `minute: int = 1`; exercises core body path returning/computing `Time(hour = hour, minute = minute)`.

```aipl
module tests.functions.time.datetime_z6_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_createTime_6(): int:
  let arg_hour = 2
  let edge_hour = 0
  let arg_minute = 4
  let edge_minute = 1
  let resNom = createTime(arg_hour, arg_minute)
  let resEdge = createTime(edge_hour, edge_minute)
  assertEqInt(resNom.hour, 2, "createTime nominal resNom.hour == 2")
  assertEqInt(resEdge.hour, 0, "createTime boundary resEdge.hour == 0")
  ret 0
```

---

### `isLeapYear` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isLeapYear(year: int): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isLeapYear` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`; exercises core body path returning/computing `(year % 4) == 0`.

```aipl
module tests.functions.time.datetime_z7_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isLeapYear_7(): int:
  let arg_year = 1
  let edge_year = 0
  let resNom = isLeapYear(arg_year)
  let resEdge = isLeapYear(edge_year)
  assert(resNom == false, "isLeapYear nominal resNom == false")
  assert(resEdge == true, "isLeapYear boundary resEdge == true")
  ret 0
```

---

### `daysInMonth` (`std/time/datetime.aipl`)

- **Signature**: `pub fn daysInMonth(year: int, month: int): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `daysInMonth` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`; exercises core body path returning/computing `31`.

```aipl
module tests.functions.time.datetime_z8_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_daysInMonth_8(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let resNom = daysInMonth(arg_year, arg_month)
  let resEdge = daysInMonth(edge_year, edge_month)
  assertEqInt(resNom, 30, "daysInMonth nominal resNom == 30")
  assertEqInt(resEdge, 31, "daysInMonth boundary resEdge == 31")
  ret 0
```

---

### `daysInYear` (`std/time/datetime.aipl`)

- **Signature**: `pub fn daysInYear(year: int): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `daysInYear` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`; exercises core body path returning/computing `365`.

```aipl
module tests.functions.time.datetime_z9_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_daysInYear_9(): int:
  let arg_year = 1
  let edge_year = 0
  let resNom = daysInYear(arg_year)
  let resEdge = daysInYear(edge_year)
  assertEqInt(resNom, 365, "daysInYear nominal resNom == 365")
  assertEqInt(resEdge, 366, "daysInYear boundary resEdge == 366")
  ret 0
```

---

### `dayOfWeek` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dayOfWeek(year: int, month: int = 1, day: int = 1): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int = 1, day: int = 1` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dayOfWeek` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`, `day: int = 1`; exercises core body path returning/computing `raw`.

```aipl
module tests.functions.time.datetime_z10_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dayOfWeek_10(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let arg_day = 1
  let edge_day = 0
  let resNom = dayOfWeek(arg_year, arg_month, arg_day)
  let resEdge = dayOfWeek(edge_year, edge_month, edge_day)
  assertEqInt(resNom, 0, "dayOfWeek nominal resNom == 0")
  assertEqInt(resEdge, 6, "dayOfWeek boundary resEdge == 6")
  ret 0
```

---

### `dayOfYear` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dayOfYear(year: int, month: int, day: int): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int, day: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dayOfYear` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`, `day: int = 1`; exercises core body path returning/computing `total + day`.

```aipl
module tests.functions.time.datetime_z11_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dayOfYear_11(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let arg_day = 1
  let edge_day = 0
  let resNom = dayOfYear(arg_year, arg_month, arg_day)
  let resEdge = dayOfYear(edge_year, edge_month, edge_day)
  assertEqInt(resNom, 91, "dayOfYear nominal resNom == 91")
  assertEqInt(resEdge, 0, "dayOfYear boundary resEdge == 0")
  ret 0
```

---

### `isValidCivilDate` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isValidCivilDate(year: int, month: int, day: int): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `year: int, month: int, day: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isValidCivilDate` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `year: int = 1`, `month: int = 1`, `day: int = 1`; exercises core body path returning/computing `day >= 1 and day <= dim`.

```aipl
module tests.functions.time.datetime_z12_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isValidCivilDate_12(): int:
  let arg_year = 1
  let edge_year = 0
  let arg_month = 4
  let edge_month = 1
  let arg_day = 1
  let edge_day = 0
  let resNom = isValidCivilDate(arg_year, arg_month, arg_day)
  let resEdge = isValidCivilDate(edge_year, edge_month, edge_day)
  assert(resNom == true, "isValidCivilDate nominal resNom == true")
  assert(resEdge == false, "isValidCivilDate boundary resEdge == false")
  ret 0
```

---

### `isValidCivilTime` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isValidCivilTime(hour: int, minute: int, second: int, nanosecond: int = 0): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hour: int, minute: int, second: int, nanosecond: int = 0` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isValidCivilTime` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `hour: int = 1`, `minute: int = 1`, `second: int = 1`, `nanosecond: int = 1`; exercises core body path returning/computing `nanosecond >= 0 and nanosecond < 1000000000`.

```aipl
module tests.functions.time.datetime_z13_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isValidCivilTime_13(): int:
  let arg_hour = 2
  let edge_hour = 0
  let arg_minute = 4
  let edge_minute = 1
  let arg_second = 4
  let edge_second = 1
  let arg_nanosecond = 4
  let edge_nanosecond = 1
  let resNom = isValidCivilTime(arg_hour, arg_minute, arg_second, arg_nanosecond)
  let resEdge = isValidCivilTime(edge_hour, edge_minute, edge_second, edge_nanosecond)
  assert(resNom == true, "isValidCivilTime nominal resNom == true")
  assert(resEdge == true, "isValidCivilTime boundary resEdge == true")
  ret 0
```

---

### `monthName` (`std/time/datetime.aipl`)

- **Signature**: `pub fn monthName(m: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `monthName` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `m: int = 1`; exercises core body path returning/computing `"Unknown"`.

```aipl
module tests.functions.time.datetime_z14_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_monthName_14(): int:
  let arg_m = 4
  let edge_m = 1
  let resNom = monthName(arg_m)
  let resEdge = monthName(edge_m)
  assertEqStr(resNom, "April", "monthName nominal string matches")
  assertEqStr(resEdge, "January", "monthName boundary string matches")
  ret 0
```

---

### `monthShortName` (`std/time/datetime.aipl`)

- **Signature**: `pub fn monthShortName(m: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `m: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `monthShortName` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `m: int = 1`; exercises core body path returning/computing `"Unk"`.

```aipl
module tests.functions.time.datetime_z15_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_monthShortName_15(): int:
  let arg_m = 4
  let edge_m = 1
  let resNom = monthShortName(arg_m)
  let resEdge = monthShortName(edge_m)
  assertEqStr(resNom, "Apr", "monthShortName nominal string matches")
  assertEqStr(resEdge, "Jan", "monthShortName boundary string matches")
  ret 0
```

---

### `dayOfWeekName` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dayOfWeekName(dow: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dow: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dayOfWeekName` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dow: int = 1`; exercises core body path returning/computing `"Unknown"`.

```aipl
module tests.functions.time.datetime_z16_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dayOfWeekName_16(): int:
  let arg_dow = 2
  let edge_dow = 0
  let resNom = dayOfWeekName(arg_dow)
  let resEdge = dayOfWeekName(edge_dow)
  assertEqStr(resNom, "Tuesday", "dayOfWeekName nominal string matches")
  assertEqStr(resEdge, "Sunday", "dayOfWeekName boundary string matches")
  ret 0
```

---

### `dayOfWeekShortName` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dayOfWeekShortName(dow: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dow: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dayOfWeekShortName` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dow: int = 1`; exercises core body path returning/computing `"Unk"`.

```aipl
module tests.functions.time.datetime_z17_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dayOfWeekShortName_17(): int:
  let arg_dow = 2
  let edge_dow = 0
  let resNom = dayOfWeekShortName(arg_dow)
  let resEdge = dayOfWeekShortName(edge_dow)
  assertEqStr(resNom, "Tue", "dayOfWeekShortName nominal string matches")
  assertEqStr(resEdge, "Sun", "dayOfWeekShortName boundary string matches")
  ret 0
```

---

### `dateDayOfWeek` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dateDayOfWeek(d: Date): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Date` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dateDayOfWeek` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `d: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `dow`.

```aipl
module tests.functions.time.datetime_z18_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dateDayOfWeek_18(): int:
  let arg_d = Date(year = 1, month = 4, day = 1)
  let edge_d = Date(year = 0, month = 1, day = 0)
  let resNom = dateDayOfWeek(arg_d)
  let resEdge = dateDayOfWeek(edge_d)
  assertEqInt(resNom, 7, "dateDayOfWeek nominal resNom == 7")
  assertEqInt(resEdge, 6, "dateDayOfWeek boundary resEdge == 6")
  ret 0
```

---

### `unixToCivil` (`std/time/datetime.aipl`)

- **Signature**: `pub fn unixToCivil(unixSec: int): CivilDateTime:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `unixSec: int` | **Returns**: `CivilDateTime`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `unixToCivil` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `unixSec: int = 1`; exercises core body path returning/computing `CivilDateTime(year = y, month = m, day = d, hour = hour, minute = minute, second = second)`.

```aipl
module tests.functions.time.datetime_z19_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_unixToCivil_19(): int:
  let arg_unixSec = 4
  let edge_unixSec = 1
  let resNom = unixToCivil(arg_unixSec)
  let resEdge = unixToCivil(edge_unixSec)
  assertEqInt(resNom.year, 1970, "unixToCivil nominal resNom.year == 1970")
  assertEqInt(resEdge.year, 1970, "unixToCivil boundary resEdge.year == 1970")
  ret 0
```

---

### `civilToUnix` (`std/time/datetime.aipl`)

- **Signature**: `pub fn civilToUnix(dt: CivilDateTime): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: CivilDateTime` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `civilToUnix` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dt: CivilDateTime = CivilDateTime(year = 1, month = 1, day = 1, hour = 1, minute = 1, second = 1)`; exercises core body path returning/computing `days * 86400 + dt.hour * 3600 + dt.minute * 60 + dt.second`.

```aipl
module tests.functions.time.datetime_z20_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_civilToUnix_20(): int:
  let arg_dt = CivilDateTime(year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = CivilDateTime(year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = civilToUnix(arg_dt)
  let resEdge = civilToUnix(edge_dt)
  assertEqInt(resNom, -62127813356, "civilToUnix nominal resNom == -62127813356")
  assertEqInt(resEdge, -62167305539, "civilToUnix boundary resEdge == -62167305539")
  ret 0
```

---

### `unixToDateTimeUtc` (`std/time/datetime.aipl`)

- **Signature**: `pub fn unixToDateTimeUtc(unixSec: int, unixNano: int = 0): DateTimeUtc:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `unixSec: int, unixNano: int = 0` | **Returns**: `DateTimeUtc`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `unixToDateTimeUtc` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `unixSec: int = 1`, `unixNano: int = 1`; exercises core body path returning/computing `DateTimeUtc(`.

```aipl
module tests.functions.time.datetime_z21_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_unixToDateTimeUtc_21(): int:
  let arg_unixSec = 4
  let edge_unixSec = 1
  let arg_unixNano = 4
  let edge_unixNano = 1
  let resNom = unixToDateTimeUtc(arg_unixSec, arg_unixNano)
  let resEdge = unixToDateTimeUtc(edge_unixSec, edge_unixNano)
  assertEqInt(resNom.unixNanos, 4000000004, "unixToDateTimeUtc nominal resNom.unixNanos == 4000000004")
  assertEqInt(resEdge.unixNanos, 1000000001, "unixToDateTimeUtc boundary resEdge.unixNanos == 1000000001")
  ret 0
```

---

### `dateTimeUtcToUnix` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dateTimeUtcToUnix(dt: DateTimeUtc): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dateTimeUtcToUnix` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `localSec - (dt.offset.offsetMinutes * 60)`.

```aipl
module tests.functions.time.datetime_z22_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dateTimeUtcToUnix_22(): int:
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = dateTimeUtcToUnix(arg_dt)
  let resEdge = dateTimeUtcToUnix(edge_dt)
  assertEqInt(resNom, -62127813596, "dateTimeUtcToUnix nominal resNom == -62127813596")
  assertEqInt(resEdge, -62167305599, "dateTimeUtcToUnix boundary resEdge == -62167305599")
  ret 0
```

---

### `toUnixSeconds` (`std/time/datetime.aipl`)

- **Signature**: `pub fn (self: DateTimeUtc) toUnixSeconds(): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: DateTimeUtc` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `toUnixSeconds` (`self: DateTimeUtc`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: receiver `recvObj: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `dateTimeUtcToUnix(self)`.

```aipl
module tests.functions.time.datetime_z23_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_DateTimeUtc_toUnixSeconds_23(): int:
  let recv_self = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_self = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = recv_self.toUnixSeconds()
  let resEdge = edge_self.toUnixSeconds()
  assertEqInt(resNom, -62127813596, "toUnixSeconds nominal resNom == -62127813596")
  assertEqInt(resEdge, -62167305599, "toUnixSeconds boundary resEdge == -62167305599")
  ret 0
```

---

### `toUnixMillis` (`std/time/datetime.aipl`)

- **Signature**: `pub fn (self: DateTimeUtc) toUnixMillis(): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: DateTimeUtc` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `toUnixMillis` (`self: DateTimeUtc`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: receiver `recvObj: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `dateTimeUtcToUnix(self) * 1000 + (self.time.nanosecond / 1000000)`.

```aipl
module tests.functions.time.datetime_z24_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_DateTimeUtc_toUnixMillis_24(): int:
  let recv_self = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_self = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = recv_self.toUnixMillis()
  let resEdge = edge_self.toUnixMillis()
  assertEqInt(resNom, -62127813596000, "toUnixMillis nominal resNom == -62127813596000")
  assertEqInt(resEdge, -62167305599000, "toUnixMillis boundary resEdge == -62167305599000")
  ret 0
```

---

### `toLocal` (`std/time/datetime.aipl`)

- **Signature**: `pub fn (self: DateTimeUtc) toLocal(offset: TimeZoneOffset): DateTimeUtc:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: DateTimeUtc` | **Parameters**: `offset: TimeZoneOffset` | **Returns**: `DateTimeUtc`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `toLocal` (`self: DateTimeUtc`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: receiver `recvObj: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`, `offset: TimeZoneOffset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test")`; exercises core body path returning/computing `DateTimeUtc(`.

```aipl
module tests.functions.time.datetime_z25_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_DateTimeUtc_toLocal_25(): int:
  let recv_self = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_self = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let arg_offset = TimeZoneOffset(offsetMinutes = 4, name = "test")
  let edge_offset = TimeZoneOffset(offsetMinutes = 1, name = "a")
  let resNom = recv_self.toLocal(arg_offset)
  let resEdge = edge_self.toLocal(edge_offset)
  assertEqInt(resNom.unixNanos, 4, "toLocal nominal resNom.unixNanos == 4")
  assertEqInt(resEdge.unixNanos, 1, "toLocal boundary resEdge.unixNanos == 1")
  ret 0
```

---

### `pad2` (`std/time/datetime.aipl`)

- **Signature**: `fn pad2(n: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `pad2` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `"{n}"`.

```aipl
module tests.functions.time.datetime_z26_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_pad2_26(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = pad2(arg_n)
  let resEdge = pad2(edge_n)
  assertEqStr(resNom, "04", "pad2 nominal string matches")
  assertEqStr(resEdge, "01", "pad2 boundary string matches")
  ret 0
```

---

### `pad3` (`std/time/datetime.aipl`)

- **Signature**: `fn pad3(n: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `pad3` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `"{n}"`.

```aipl
module tests.functions.time.datetime_z27_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_pad3_27(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = pad3(arg_n)
  let resEdge = pad3(edge_n)
  assertEqStr(resNom, "004", "pad3 nominal string matches")
  assertEqStr(resEdge, "001", "pad3 boundary string matches")
  ret 0
```

---

### `pad4` (`std/time/datetime.aipl`)

- **Signature**: `fn pad4(n: int): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `n: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `pad4` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `n: int = 1`; exercises core body path returning/computing `"{n}"`.

```aipl
module tests.functions.time.datetime_z28_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_pad4_28(): int:
  let arg_n = 4
  let edge_n = 1
  let resNom = pad4(arg_n)
  let resEdge = pad4(edge_n)
  assertEqStr(resNom, "0004", "pad4 nominal string matches")
  assertEqStr(resEdge, "0001", "pad4 boundary string matches")
  ret 0
```

---

### `parseDigitsRange` (`std/time/datetime.aipl`)

- **Signature**: `fn parseDigitsRange(s: str, start: int, end: int): Result[int, str]:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str, start: int, end: int` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `parseDigitsRange` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `s: str = "aipl_test"`, `start: int = 1`, `end: int = 1`; exercises core body path returning/computing `Ok(acc)`.

```aipl
module tests.functions.time.datetime_z29_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_parseDigitsRange_29(): int:
  let arg_s = "test"
  let edge_s = "a"
  let arg_start = 1
  let edge_start = 0
  let arg_end = 4
  let edge_end = 1
  let resNom = parseDigitsRange(arg_s, arg_start, arg_end)
  let resEdge = parseDigitsRange(edge_s, edge_start, edge_end)
  assert(resNom.isOk() == false, "parseDigitsRange nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseDigitsRange boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseIso8601` (`std/time/datetime.aipl`)

- **Signature**: `pub fn parseIso8601(s: str): Result[DateTimeUtc, str]:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[DateTimeUtc, str]`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `parseIso8601` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(DateTimeUtc(`.

```aipl
module tests.functions.time.datetime_z30_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_parseIso8601_30(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseIso8601(arg_s)
  let resEdge = parseIso8601(edge_s)
  assert(resNom.isOk() == false, "parseIso8601 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseIso8601 boundary resEdge.isOk() == false")
  ret 0
```

---

### `formatIso8601` (`std/time/datetime.aipl`)

- **Signature**: `pub fn formatIso8601(dt: DateTimeUtc): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `formatIso8601` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `"{ys}-{ms}-{ds}T{hs}:{mins}:{secs}{signCh}{tzh}:{tzm}"`.

```aipl
module tests.functions.time.datetime_z31_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_formatIso8601_31(): int:
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = formatIso8601(arg_dt)
  let resEdge = formatIso8601(edge_dt)
  assertEqStr(resNom, "0001-04-01T02:04:04+00:04", "formatIso8601 nominal string matches")
  assertEqStr(resEdge, "0000-01-00T00:01:01+00:01", "formatIso8601 boundary string matches")
  ret 0
```

---

### `parseMonthAbbrev` (`std/time/datetime.aipl`)

- **Signature**: `fn parseMonthAbbrev(mon: str): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mon: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `parseMonthAbbrev` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `mon: str = "aipl_test"`; exercises core body path returning/computing `-1`.

```aipl
module tests.functions.time.datetime_z32_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_parseMonthAbbrev_32(): int:
  let arg_mon = "test"
  let edge_mon = "a"
  let resNom = parseMonthAbbrev(arg_mon)
  let resEdge = parseMonthAbbrev(edge_mon)
  assertEqInt(resNom, -1, "parseMonthAbbrev nominal resNom == -1")
  assertEqInt(resEdge, -1, "parseMonthAbbrev boundary resEdge == -1")
  ret 0
```

---

### `formatRfc2822` (`std/time/datetime.aipl`)

- **Signature**: `pub fn formatRfc2822(dt: DateTimeUtc): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `formatRfc2822` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `"{wName}, {dStr} {mName} {yStr} {hStr}:{minStr}:{secStr} {signCh}{tzh}{tzm}"`.

```aipl
module tests.functions.time.datetime_z33_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_formatRfc2822_33(): int:
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = formatRfc2822(arg_dt)
  let resEdge = formatRfc2822(edge_dt)
  assertEqStr(resNom, "Sun, 01 Apr 0001 02:04:04 +0004", "formatRfc2822 nominal string matches")
  assertEqStr(resEdge, "Sat, 00 Jan 0000 00:01:01 +0001", "formatRfc2822 boundary string matches")
  ret 0
```

---

### `formatRfc822` (`std/time/datetime.aipl`)

- **Signature**: `pub fn formatRfc822(dt: DateTimeUtc): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dt: DateTimeUtc` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `formatRfc822` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `dt: DateTimeUtc = DateTimeUtc(date = CivilDate(year = 1, month = 1, day = 1), time = CivilTime(hour = 1, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 0, name = "aipl_test"), unixNanos = 1, year = int = 0(), month = int = 0(), day = int = 0(), hour = int = 0(), minute = int = 0(), second = int = 0())`; exercises core body path returning/computing `formatRfc2822(dt)`.

```aipl
module tests.functions.time.datetime_z34_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_formatRfc822_34(): int:
  let arg_dt = DateTimeUtc(date = CivilDate(year = 1, month = 4, day = 1), time = CivilTime(hour = 2, minute = 4, second = 4, nanosecond = 4), offset = TimeZoneOffset(offsetMinutes = 4, name = "test"), unixNanos = 4, year = 1, month = 4, day = 1, hour = 2, minute = 4, second = 4)
  let edge_dt = DateTimeUtc(date = CivilDate(year = 0, month = 1, day = 0), time = CivilTime(hour = 0, minute = 1, second = 1, nanosecond = 1), offset = TimeZoneOffset(offsetMinutes = 1, name = "a"), unixNanos = 1, year = 0, month = 1, day = 0, hour = 0, minute = 1, second = 1)
  let resNom = formatRfc822(arg_dt)
  let resEdge = formatRfc822(edge_dt)
  assertEqStr(resNom, "Sun, 01 Apr 0001 02:04:04 +0004", "formatRfc822 nominal string matches")
  assertEqStr(resEdge, "Sat, 00 Jan 0000 00:01:01 +0001", "formatRfc822 boundary string matches")
  ret 0
```

---

### `parseRfc2822` (`std/time/datetime.aipl`)

- **Signature**: `pub fn parseRfc2822(s: str): Result[DateTimeUtc, str]:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[DateTimeUtc, str]`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `parseRfc2822` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(unixToDateTimeUtc(uSec, 0))`.

```aipl
module tests.functions.time.datetime_z35_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_parseRfc2822_35(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseRfc2822(arg_s)
  let resEdge = parseRfc2822(edge_s)
  assert(resNom.isOk() == false, "parseRfc2822 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseRfc2822 boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseRfc822` (`std/time/datetime.aipl`)

- **Signature**: `pub fn parseRfc822(s: str): Result[DateTimeUtc, str]:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[DateTimeUtc, str]`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `parseRfc822` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `parseRfc2822(s)`.

```aipl
module tests.functions.time.datetime_z36_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_parseRfc822_36(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseRfc822(arg_s)
  let resEdge = parseRfc822(edge_s)
  assert(resNom.isOk() == false, "parseRfc822 nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseRfc822 boundary resEdge.isOk() == false")
  ret 0
```

---

### `formatDate` (`std/time/datetime.aipl`)

- **Signature**: `pub fn formatDate(d: Date): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Date` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `formatDate` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `d: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `"{d.year}-{mStr}-{dStr}"`.

```aipl
module tests.functions.time.datetime_z37_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_formatDate_37(): int:
  let arg_d = Date(year = 1, month = 4, day = 1)
  let edge_d = Date(year = 0, month = 1, day = 0)
  let resNom = formatDate(arg_d)
  let resEdge = formatDate(edge_d)
  assertEqStr(resNom, "1-04-01", "formatDate nominal string matches")
  assertEqStr(resEdge, "0-01-00", "formatDate boundary string matches")
  ret 0
```

---

### `formatTime` (`std/time/datetime.aipl`)

- **Signature**: `pub fn formatTime(t: Time): str:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `t: Time` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `formatTime` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `t: Time = Time(hour = 1, minute = 1)`; exercises core body path returning/computing `"{hStr}:{mStr}"`.

```aipl
module tests.functions.time.datetime_z38_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_formatTime_38(): int:
  let arg_t = Time(hour = 2, minute = 4)
  let edge_t = Time(hour = 0, minute = 1)
  let resNom = formatTime(arg_t)
  let resEdge = formatTime(edge_t)
  assertEqStr(resNom, "02:04", "formatTime nominal string matches")
  assertEqStr(resEdge, "00:01", "formatTime boundary string matches")
  ret 0
```

---

### `compareDates` (`std/time/datetime.aipl`)

- **Signature**: `pub fn compareDates(a: Date, b: Date): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Date, b: Date` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `compareDates` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `a: Date = Date(year = 1, month = 1, day = 1)`, `b: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.time.datetime_z39_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_compareDates_39(): int:
  let arg_a = Date(year = 1, month = 4, day = 1)
  let edge_a = Date(year = 0, month = 1, day = 0)
  let arg_b = Date(year = 1, month = 4, day = 1)
  let edge_b = Date(year = 0, month = 1, day = 0)
  let resNom = compareDates(arg_a, arg_b)
  let resEdge = compareDates(edge_a, edge_b)
  assertEqInt(resNom, 0, "compareDates nominal resNom == 0")
  assertEqInt(resEdge, 0, "compareDates boundary resEdge == 0")
  ret 0
```

---

### `isDateBefore` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isDateBefore(a: Date, b: Date): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Date, b: Date` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isDateBefore` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `a: Date = Date(year = 1, month = 1, day = 1)`, `b: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `compareDates(a, b) < 0`.

```aipl
module tests.functions.time.datetime_z40_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isDateBefore_40(): int:
  let arg_a = Date(year = 1, month = 4, day = 1)
  let edge_a = Date(year = 0, month = 1, day = 0)
  let arg_b = Date(year = 1, month = 4, day = 1)
  let edge_b = Date(year = 0, month = 1, day = 0)
  let resNom = isDateBefore(arg_a, arg_b)
  let resEdge = isDateBefore(edge_a, edge_b)
  assert(resNom == false, "isDateBefore nominal resNom == false")
  assert(resEdge == false, "isDateBefore boundary resEdge == false")
  ret 0
```

---

### `isDateAfter` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isDateAfter(a: Date, b: Date): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Date, b: Date` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isDateAfter` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `a: Date = Date(year = 1, month = 1, day = 1)`, `b: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `compareDates(a, b) > 0`.

```aipl
module tests.functions.time.datetime_z41_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isDateAfter_41(): int:
  let arg_a = Date(year = 1, month = 4, day = 1)
  let edge_a = Date(year = 0, month = 1, day = 0)
  let arg_b = Date(year = 1, month = 4, day = 1)
  let edge_b = Date(year = 0, month = 1, day = 0)
  let resNom = isDateAfter(arg_a, arg_b)
  let resEdge = isDateAfter(edge_a, edge_b)
  assert(resNom == false, "isDateAfter nominal resNom == false")
  assert(resEdge == false, "isDateAfter boundary resEdge == false")
  ret 0
```

---

### `isDateEqual` (`std/time/datetime.aipl`)

- **Signature**: `pub fn isDateEqual(a: Date, b: Date): bool:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Date, b: Date` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `isDateEqual` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `a: Date = Date(year = 1, month = 1, day = 1)`, `b: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `compareDates(a, b) == 0`.

```aipl
module tests.functions.time.datetime_z42_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_isDateEqual_42(): int:
  let arg_a = Date(year = 1, month = 4, day = 1)
  let edge_a = Date(year = 0, month = 1, day = 0)
  let arg_b = Date(year = 1, month = 4, day = 1)
  let edge_b = Date(year = 0, month = 1, day = 0)
  let resNom = isDateEqual(arg_a, arg_b)
  let resEdge = isDateEqual(edge_a, edge_b)
  assert(resNom == true, "isDateEqual nominal resNom == true")
  assert(resEdge == true, "isDateEqual boundary resEdge == true")
  ret 0
```

---

### `dateToDays` (`std/time/datetime.aipl`)

- **Signature**: `pub fn dateToDays(d: Date): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `d: Date` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `dateToDays` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `d: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `365 * y + (y / 4) - (y / 100) + (y / 400) + ((153 * (m - 3) + 2) / 5) + d.day - 1`.

```aipl
module tests.functions.time.datetime_z43_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_dateToDays_43(): int:
  let arg_d = Date(year = 1, month = 4, day = 1)
  let edge_d = Date(year = 0, month = 1, day = 0)
  let resNom = dateToDays(arg_d)
  let resEdge = dateToDays(edge_d)
  assertEqInt(resNom, 396, "dateToDays nominal resNom == 396")
  assertEqInt(resEdge, -60, "dateToDays boundary resEdge == -60")
  ret 0
```

---

### `daysBetween` (`std/time/datetime.aipl`)

- **Signature**: `pub fn daysBetween(a: Date, b: Date): int:`
- **Import**: `import * from "std/time/datetime"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: Date, b: Date` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/datetime_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify civil calendar / UTC / ISO-8601 / RFC-2822 function `daysBetween` (`free fn`) across Gregorian leap-year boundaries (`1970-01-01`, `2000-02-29`, `1900-02-28`, `2024-02-29`) and timezone offsets. Concrete nominal inputs: `a: Date = Date(year = 1, month = 1, day = 1)`, `b: Date = Date(year = 1, month = 1, day = 1)`; exercises core body path returning/computing `da - db`.

```aipl
module tests.functions.time.datetime_z44_test
import * from "std/time/datetime"
import { NANOS_PER_SECOND } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_datetime_daysBetween_44(): int:
  let arg_a = Date(year = 1, month = 4, day = 1)
  let edge_a = Date(year = 0, month = 1, day = 0)
  let arg_b = Date(year = 1, month = 4, day = 1)
  let edge_b = Date(year = 0, month = 1, day = 0)
  let resNom = daysBetween(arg_a, arg_b)
  let resEdge = daysBetween(edge_a, edge_b)
  assertEqInt(resNom, 0, "daysBetween nominal resNom == 0")
  assertEqInt(resEdge, 0, "daysBetween boundary resEdge == 0")
  ret 0
```

---

### `durationZero` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationZero(): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationZero` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Duration(nanos = 0)`.

```aipl
module tests.functions.time.duration_z1_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationZero_1(): int:
  let resNom = durationZero()
  let resEdge = durationZero()
  assertEqInt(resNom.nanos, 0, "durationZero nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "durationZero boundary resEdge.nanos == 0")
  ret 0
```

---

### `durationFromNanos` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromNanos(nanos: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nanos: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromNanos` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `nanos: int = 1`; exercises core body path returning/computing `Duration(nanos = nanos)`.

```aipl
module tests.functions.time.duration_z2_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromNanos_2(): int:
  let arg_nanos = 4
  let edge_nanos = 1
  let resNom = durationFromNanos(arg_nanos)
  let resEdge = durationFromNanos(edge_nanos)
  assertEqInt(resNom.nanos, 4, "durationFromNanos nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "durationFromNanos boundary resEdge.nanos == 1")
  ret 0
```

---

### `durationFromMicros` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromMicros(micros: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `micros: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromMicros` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `micros: int = 1`; exercises core body path returning/computing `Duration(nanos = micros * NANOS_PER_MICRO)`.

```aipl
module tests.functions.time.duration_z3_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromMicros_3(): int:
  let arg_micros = 4
  let edge_micros = 1
  let resNom = durationFromMicros(arg_micros)
  let resEdge = durationFromMicros(edge_micros)
  assertEqInt(resNom.nanos, 4000, "durationFromMicros nominal resNom.nanos == 4000")
  assertEqInt(resEdge.nanos, 1000, "durationFromMicros boundary resEdge.nanos == 1000")
  ret 0
```

---

### `durationFromMillis` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromMillis(millis: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `millis: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromMillis` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `millis: int = 1`; exercises core body path returning/computing `Duration(nanos = millis * NANOS_PER_MILLI)`.

```aipl
module tests.functions.time.duration_z4_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromMillis_4(): int:
  let arg_millis = 4
  let edge_millis = 1
  let resNom = durationFromMillis(arg_millis)
  let resEdge = durationFromMillis(edge_millis)
  assertEqInt(resNom.nanos, 4000000, "durationFromMillis nominal resNom.nanos == 4000000")
  assertEqInt(resEdge.nanos, 1000000, "durationFromMillis boundary resEdge.nanos == 1000000")
  ret 0
```

---

### `durationFromMs` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromMs(ms: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromMs` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `Duration(nanos = ms * NANOS_PER_MILLI)`.

```aipl
module tests.functions.time.duration_z5_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromMs_5(): int:
  let arg_ms = 4
  let edge_ms = 1
  let resNom = durationFromMs(arg_ms)
  let resEdge = durationFromMs(edge_ms)
  assertEqInt(resNom.nanos, 4000000, "durationFromMs nominal resNom.nanos == 4000000")
  assertEqInt(resEdge.nanos, 1000000, "durationFromMs boundary resEdge.nanos == 1000000")
  ret 0
```

---

### `durationFromSeconds` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromSeconds(secs: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `secs: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromSeconds` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `secs: int = 1`; exercises core body path returning/computing `Duration(nanos = secs * NANOS_PER_SECOND)`.

```aipl
module tests.functions.time.duration_z6_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromSeconds_6(): int:
  let arg_secs = 2
  let edge_secs = 0
  let resNom = durationFromSeconds(arg_secs)
  let resEdge = durationFromSeconds(edge_secs)
  assertEqInt(resNom.nanos, 2000000000, "durationFromSeconds nominal resNom.nanos == 2000000000")
  assertEqInt(resEdge.nanos, 0, "durationFromSeconds boundary resEdge.nanos == 0")
  ret 0
```

---

### `durationFromSecondsFloat` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromSecondsFloat(secs: float): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `secs: float` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromSecondsFloat` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `secs: float = 1.0`; exercises core body path returning/computing `Duration(nanos = ns)`.

```aipl
module tests.functions.time.duration_z7_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromSecondsFloat_7(): int:
  let arg_secs = 1.0
  let edge_secs = 0.5
  let resNom = durationFromSecondsFloat(arg_secs)
  let resEdge = durationFromSecondsFloat(edge_secs)
  assertEqInt(resNom.nanos, 1000000000, "durationFromSecondsFloat nominal resNom.nanos == 1000000000")
  assertEqInt(resEdge.nanos, 500000000, "durationFromSecondsFloat boundary resEdge.nanos == 500000000")
  ret 0
```

---

### `durationFromMinutes` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromMinutes(mins: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mins: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromMinutes` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `mins: int = 1`; exercises core body path returning/computing `Duration(nanos = mins * NANOS_PER_MINUTE)`.

```aipl
module tests.functions.time.duration_z8_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromMinutes_8(): int:
  let arg_mins = 4
  let edge_mins = 1
  let resNom = durationFromMinutes(arg_mins)
  let resEdge = durationFromMinutes(edge_mins)
  assertEqInt(resNom.nanos, 240000000000, "durationFromMinutes nominal resNom.nanos == 240000000000")
  assertEqInt(resEdge.nanos, 60000000000, "durationFromMinutes boundary resEdge.nanos == 60000000000")
  ret 0
```

---

### `durationFromHours` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromHours(hours: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `hours: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromHours` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `hours: int = 1`; exercises core body path returning/computing `Duration(nanos = hours * NANOS_PER_HOUR)`.

```aipl
module tests.functions.time.duration_z9_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromHours_9(): int:
  let arg_hours = 2
  let edge_hours = 0
  let resNom = durationFromHours(arg_hours)
  let resEdge = durationFromHours(edge_hours)
  assertEqInt(resNom.nanos, 7200000000000, "durationFromHours nominal resNom.nanos == 7200000000000")
  assertEqInt(resEdge.nanos, 0, "durationFromHours boundary resEdge.nanos == 0")
  ret 0
```

---

### `durationFromDays` (`std/time/duration.aipl`)

- **Signature**: `pub fn durationFromDays(days: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `days: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `durationFromDays` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `days: int = 1`; exercises core body path returning/computing `Duration(nanos = days * NANOS_PER_DAY)`.

```aipl
module tests.functions.time.duration_z10_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_durationFromDays_10(): int:
  let arg_days = 1
  let edge_days = 0
  let resNom = durationFromDays(arg_days)
  let resEdge = durationFromDays(edge_days)
  assertEqInt(resNom.nanos, 86400000000000, "durationFromDays nominal resNom.nanos == 86400000000000")
  assertEqInt(resEdge.nanos, 0, "durationFromDays boundary resEdge.nanos == 0")
  ret 0
```

---

### `toNanos` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toNanos(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toNanos` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos`.

```aipl
module tests.functions.time.duration_z11_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toNanos_11(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toNanos()
  let resEdge = edge_self.toNanos()
  assertEqInt(resNom, 4, "toNanos nominal resNom == 4")
  assertEqInt(resEdge, 1, "toNanos boundary resEdge == 1")
  ret 0
```

---

### `toMicros` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toMicros(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toMicros` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MICRO`.

```aipl
module tests.functions.time.duration_z12_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toMicros_12(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toMicros()
  let resEdge = edge_self.toMicros()
  assertEqInt(resNom, 0, "toMicros nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMicros boundary resEdge == 0")
  ret 0
```

---

### `toMillis` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toMillis(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toMillis` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MILLI`.

```aipl
module tests.functions.time.duration_z13_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toMillis_13(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toMillis()
  let resEdge = edge_self.toMillis()
  assertEqInt(resNom, 0, "toMillis nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMillis boundary resEdge == 0")
  ret 0
```

---

### `toMs` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toMs(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toMs` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MILLI`.

```aipl
module tests.functions.time.duration_z14_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toMs_14(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toMs()
  let resEdge = edge_self.toMs()
  assertEqInt(resNom, 0, "toMs nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMs boundary resEdge == 0")
  ret 0
```

---

### `toSeconds` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toSeconds(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toSeconds` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_SECOND`.

```aipl
module tests.functions.time.duration_z15_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toSeconds_15(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toSeconds()
  let resEdge = edge_self.toSeconds()
  assertEqInt(resNom, 0, "toSeconds nominal resNom == 0")
  assertEqInt(resEdge, 0, "toSeconds boundary resEdge == 0")
  ret 0
```

---

### `toSecondsFloat` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toSecondsFloat(): float:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toSecondsFloat` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `float(self.nanos) / 1000000000.0`.

```aipl
module tests.functions.time.duration_z16_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toSecondsFloat_16(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toSecondsFloat()
  let resEdge = edge_self.toSecondsFloat()
  assertApproxEq(resNom, 0.0, 0.001, "toSecondsFloat nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "toSecondsFloat boundary resEdge ~= 0.0")
  ret 0
```

---

### `toMinutes` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toMinutes(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toMinutes` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MINUTE`.

```aipl
module tests.functions.time.duration_z17_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toMinutes_17(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toMinutes()
  let resEdge = edge_self.toMinutes()
  assertEqInt(resNom, 0, "toMinutes nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMinutes boundary resEdge == 0")
  ret 0
```

---

### `toHours` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) toHours(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `toHours` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_HOUR`.

```aipl
module tests.functions.time.duration_z18_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_toHours_18(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.toHours()
  let resEdge = edge_self.toHours()
  assertEqInt(resNom, 0, "toHours nominal resNom == 0")
  assertEqInt(resEdge, 0, "toHours boundary resEdge == 0")
  ret 0
```

---

### `subsecNanos` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) subsecNanos(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `subsecNanos` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `r`.

```aipl
module tests.functions.time.duration_z19_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_subsecNanos_19(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.subsecNanos()
  let resEdge = edge_self.subsecNanos()
  assertEqInt(resNom, 4, "subsecNanos nominal resNom == 4")
  assertEqInt(resEdge, 1, "subsecNanos boundary resEdge == 1")
  ret 0
```

---

### `subsecMillis` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) subsecMillis(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `subsecMillis` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.subsecNanos() / NANOS_PER_MILLI`.

```aipl
module tests.functions.time.duration_z20_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_subsecMillis_20(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.subsecMillis()
  let resEdge = edge_self.subsecMillis()
  assertEqInt(resNom, 0, "subsecMillis nominal resNom == 0")
  assertEqInt(resEdge, 0, "subsecMillis boundary resEdge == 0")
  ret 0
```

---

### `subsecMicros` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) subsecMicros(): int:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `subsecMicros` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.subsecNanos() / NANOS_PER_MICRO`.

```aipl
module tests.functions.time.duration_z21_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_subsecMicros_21(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.subsecMicros()
  let resEdge = edge_self.subsecMicros()
  assertEqInt(resNom, 0, "subsecMicros nominal resNom == 0")
  assertEqInt(resEdge, 0, "subsecMicros boundary resEdge == 0")
  ret 0
```

---

### `isZero` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) isZero(): bool:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `isZero` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos == 0`.

```aipl
module tests.functions.time.duration_z22_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_isZero_22(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.isZero()
  let resEdge = edge_self.isZero()
  assert(resNom == false, "isZero nominal resNom == false")
  assert(resEdge == false, "isZero boundary resEdge == false")
  ret 0
```

---

### `isNegative` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) isNegative(): bool:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `isNegative` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos < 0`.

```aipl
module tests.functions.time.duration_z23_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_isNegative_23(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.isNegative()
  let resEdge = edge_self.isNegative()
  assert(resNom == false, "isNegative nominal resNom == false")
  assert(resEdge == false, "isNegative boundary resEdge == false")
  ret 0
```

---

### `isPositive` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) isPositive(): bool:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `isPositive` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self.nanos > 0`.

```aipl
module tests.functions.time.duration_z24_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_isPositive_24(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.isPositive()
  let resEdge = edge_self.isPositive()
  assert(resNom == true, "isPositive nominal resNom == true")
  assert(resEdge == true, "isPositive boundary resEdge == true")
  ret 0
```

---

### `abs` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) abs(): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `abs` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.time.duration_z25_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_abs_25(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.abs()
  let resEdge = edge_self.abs()
  assertEqInt(resNom.nanos, 4, "abs nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "abs boundary resEdge.nanos == 1")
  ret 0
```

---

### `add` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) add(other: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `other: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `add` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `other: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `Duration(nanos = self.nanos + other.nanos)`.

```aipl
module tests.functions.time.duration_z26_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_add_26(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_other = Duration(nanos = 4)
  let edge_other = Duration(nanos = 1)
  let resNom = recv_self.add(arg_other)
  let resEdge = edge_self.add(edge_other)
  assertEqInt(resNom.nanos, 8, "add nominal resNom.nanos == 8")
  assertEqInt(resEdge.nanos, 2, "add boundary resEdge.nanos == 2")
  ret 0
```

---

### `sub` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) sub(other: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `other: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `sub` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `other: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `Duration(nanos = self.nanos - other.nanos)`.

```aipl
module tests.functions.time.duration_z27_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_sub_27(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_other = Duration(nanos = 4)
  let edge_other = Duration(nanos = 1)
  let resNom = recv_self.sub(arg_other)
  let resEdge = edge_self.sub(edge_other)
  assertEqInt(resNom.nanos, 0, "sub nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "sub boundary resEdge.nanos == 0")
  ret 0
```

---

### `saturatingSub` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) saturatingSub(other: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `other: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `saturatingSub` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `other: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `Duration(nanos = diff)`.

```aipl
module tests.functions.time.duration_z28_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_saturatingSub_28(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_other = Duration(nanos = 4)
  let edge_other = Duration(nanos = 1)
  let resNom = recv_self.saturatingSub(arg_other)
  let resEdge = edge_self.saturatingSub(edge_other)
  assertEqInt(resNom.nanos, 0, "saturatingSub nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "saturatingSub boundary resEdge.nanos == 0")
  ret 0
```

---

### `mul` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) mul(factor: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `factor: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `mul` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `factor: int = 1`; exercises core body path returning/computing `Duration(nanos = self.nanos * factor)`.

```aipl
module tests.functions.time.duration_z29_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_mul_29(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_factor = 2
  let edge_factor = 0
  let resNom = recv_self.mul(arg_factor)
  let resEdge = edge_self.mul(edge_factor)
  assertEqInt(resNom.nanos, 8, "mul nominal resNom.nanos == 8")
  assertEqInt(resEdge.nanos, 0, "mul boundary resEdge.nanos == 0")
  ret 0
```

---

### `mulFloat` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) mulFloat(factor: float): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `factor: float` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `mulFloat` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `factor: float = 1.0`; exercises core body path returning/computing `Duration(nanos = int(float(self.nanos) * factor))`.

```aipl
module tests.functions.time.duration_z30_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_mulFloat_30(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_factor = 1.0
  let edge_factor = 0.5
  let resNom = recv_self.mulFloat(arg_factor)
  let resEdge = edge_self.mulFloat(edge_factor)
  assertEqInt(resNom.nanos, 4, "mulFloat nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 0, "mulFloat boundary resEdge.nanos == 0")
  ret 0
```

---

### `div` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) div(divisor: int): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `divisor: int` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `div` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `divisor: int = 1`; exercises core body path returning/computing `Duration(nanos = self.nanos / divisor)`.

```aipl
module tests.functions.time.duration_z31_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_div_31(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_divisor = 2
  let edge_divisor = 0
  let resNom = recv_self.div(arg_divisor)
  let resEdge = edge_self.div(edge_divisor)
  assertEqInt(resNom.nanos, 2, "div nominal resNom.nanos == 2")
  assertEqInt(resEdge.nanos, 0, "div boundary resEdge.nanos == 0")
  ret 0
```

---

### `clamp` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) clamp(minDur: Duration, maxDur: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `minDur: Duration, maxDur: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `clamp` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `minDur: Duration = Duration(nanos = 1)`, `maxDur: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.time.duration_z32_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_clamp_32(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_minDur = Duration(nanos = 4)
  let edge_minDur = Duration(nanos = 1)
  let arg_maxDur = Duration(nanos = 4)
  let edge_maxDur = Duration(nanos = 1)
  let resNom = recv_self.clamp(arg_minDur, arg_maxDur)
  let resEdge = edge_self.clamp(edge_minDur, edge_maxDur)
  assertEqInt(resNom.nanos, 4, "clamp nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "clamp boundary resEdge.nanos == 1")
  ret 0
```

---

### `min` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) min(other: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `other: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `min` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `other: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `other`.

```aipl
module tests.functions.time.duration_z33_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_min_33(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_other = Duration(nanos = 4)
  let edge_other = Duration(nanos = 1)
  let resNom = recv_self.min(arg_other)
  let resEdge = edge_self.min(edge_other)
  assertEqInt(resNom.nanos, 4, "min nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "min boundary resEdge.nanos == 1")
  ret 0
```

---

### `max` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) max(other: Duration): Duration:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `other: Duration` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `max` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`, `other: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `other`.

```aipl
module tests.functions.time.duration_z34_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_max_34(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let arg_other = Duration(nanos = 4)
  let edge_other = Duration(nanos = 1)
  let resNom = recv_self.max(arg_other)
  let resEdge = edge_self.max(edge_other)
  assertEqInt(resNom.nanos, 4, "max nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "max boundary resEdge.nanos == 1")
  ret 0
```

---

### `format` (`std/time/duration.aipl`)

- **Signature**: `pub fn (self: Duration) format(): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Duration` | **Parameters**: `none` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `format` (`self: Duration`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: receiver `recvObj: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `"{prefix}{hrs}h {mins}m"`.

```aipl
module tests.functions.time.duration_z35_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_Duration_format_35(): int:
  let recv_self = Duration(nanos = 4)
  let edge_self = Duration(nanos = 1)
  let resNom = recv_self.format()
  let resEdge = edge_self.format()
  assertEqStr(resNom, "4ns", "format nominal string matches")
  assertEqStr(resEdge, "1ns", "format boundary string matches")
  ret 0
```

---

### `parseUnsignedDigits` (`std/time/duration.aipl`)

- **Signature**: `fn parseUnsignedDigits(s: str): Result[int, str]:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `s: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `parseUnsignedDigits` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `s: str = "aipl_test"`; exercises core body path returning/computing `Ok(acc)`.

```aipl
module tests.functions.time.duration_z36_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_parseUnsignedDigits_36(): int:
  let arg_s = "test"
  let edge_s = "a"
  let resNom = parseUnsignedDigits(arg_s)
  let resEdge = parseUnsignedDigits(edge_s)
  assert(resNom.isOk() == false, "parseUnsignedDigits nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseUnsignedDigits boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseDuration` (`std/time/duration.aipl`)

- **Signature**: `pub fn parseDuration(spec: str): Result[Duration, str]:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `spec: str` | **Returns**: `Result[Duration, str]`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `parseDuration` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `spec: str = "aipl_test"`; exercises core body path returning/computing `Err("Empty duration specifier")`.

```aipl
module tests.functions.time.duration_z37_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_parseDuration_37(): int:
  let arg_spec = "test"
  let edge_spec = "a"
  let resNom = parseDuration(arg_spec)
  let resEdge = parseDuration(edge_spec)
  assert(resNom.isOk() == false, "parseDuration nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseDuration boundary resEdge.isOk() == false")
  ret 0
```

---

### `parseDurationMs` (`std/time/duration.aipl`)

- **Signature**: `pub fn parseDurationMs(spec: str): Result[int, str]:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `spec: str` | **Returns**: `Result[int, str]`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `parseDurationMs` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `spec: str = "aipl_test"`; exercises core body path returning/computing `computed `Result[int, str]` value`.

```aipl
module tests.functions.time.duration_z38_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_parseDurationMs_38(): int:
  let arg_spec = "test"
  let edge_spec = "a"
  let resNom = parseDurationMs(arg_spec)
  let resEdge = parseDurationMs(edge_spec)
  assert(resNom.isOk() == false, "parseDurationMs nominal resNom.isOk() == false")
  assert(resEdge.isOk() == false, "parseDurationMs boundary resEdge.isOk() == false")
  ret 0
```

---

### `formatDurationMs` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatDurationMs(ms: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatDurationMs` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `"{hrs}h {mins}m"`.

```aipl
module tests.functions.time.duration_z39_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatDurationMs_39(): int:
  let arg_ms = 4
  let edge_ms = 1
  let resNom = formatDurationMs(arg_ms)
  let resEdge = formatDurationMs(edge_ms)
  assertEqStr(resNom, "4ms", "formatDurationMs nominal string matches")
  assertEqStr(resEdge, "1ms", "formatDurationMs boundary string matches")
  ret 0
```

---

### `formatDuration` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatDuration(ms: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatDuration` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `formatDurationMs(ms)`.

```aipl
module tests.functions.time.duration_z40_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatDuration_40(): int:
  let arg_ms = 4
  let edge_ms = 1
  let resNom = formatDuration(arg_ms)
  let resEdge = formatDuration(edge_ms)
  assertEqStr(resNom, "4ms", "formatDuration nominal string matches")
  assertEqStr(resEdge, "1ms", "formatDuration boundary string matches")
  ret 0
```

---

### `formatMmSs` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatMmSs(sec: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sec: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatMmSs` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `sec: int = 1`; exercises core body path returning/computing `"{mStr}:{sStr}"`.

```aipl
module tests.functions.time.duration_z41_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatMmSs_41(): int:
  let arg_sec = 2
  let edge_sec = 0
  let resNom = formatMmSs(arg_sec)
  let resEdge = formatMmSs(edge_sec)
  assertEqStr(resNom, "00:02", "formatMmSs nominal string matches")
  assertEqStr(resEdge, "00:00", "formatMmSs boundary string matches")
  ret 0
```

---

### `formatDurationMS` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatDurationMS(totalSeconds: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `totalSeconds: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatDurationMS` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `totalSeconds: int = 1`; exercises core body path returning/computing `formatMmSs(totalSeconds)`.

```aipl
module tests.functions.time.duration_z42_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatDurationMS_42(): int:
  let arg_totalSeconds = 4
  let edge_totalSeconds = 1
  let resNom = formatDurationMS(arg_totalSeconds)
  let resEdge = formatDurationMS(edge_totalSeconds)
  assertEqStr(resNom, "00:04", "formatDurationMS nominal string matches")
  assertEqStr(resEdge, "00:01", "formatDurationMS boundary string matches")
  ret 0
```

---

### `formatDurationHMS` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatDurationHMS(totalSeconds: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `totalSeconds: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatDurationHMS` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `totalSeconds: int = 1`; exercises core body path returning/computing `"{hStr}:{mStr}:{sStr}"`.

```aipl
module tests.functions.time.duration_z43_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatDurationHMS_43(): int:
  let arg_totalSeconds = 4
  let edge_totalSeconds = 1
  let resNom = formatDurationHMS(arg_totalSeconds)
  let resEdge = formatDurationHMS(edge_totalSeconds)
  assertEqStr(resNom, "00:00:04", "formatDurationHMS nominal string matches")
  assertEqStr(resEdge, "00:00:01", "formatDurationHMS boundary string matches")
  ret 0
```

---

### `formatDurationHhMmSsMs` (`std/time/duration.aipl`)

- **Signature**: `pub fn formatDurationHhMmSsMs(ms: int): str:`
- **Import**: `import * from "std/time/duration"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `str`
- **Unit Test**: `tests/functions/time/duration_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify `Duration` constructor/method `formatDurationHhMmSsMs` (`free fn`) across ns/us/ms/s/min/h/day unit conversions, saturating subtraction at zero, and human-readable HMS parsing/formatting. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `"{hms}.{msStr}"`.

```aipl
module tests.functions.time.duration_z44_test
import * from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_duration_formatDurationHhMmSsMs_44(): int:
  let arg_ms = 4
  let edge_ms = 1
  let resNom = formatDurationHhMmSsMs(arg_ms)
  let resEdge = formatDurationHhMmSsMs(edge_ms)
  assertEqStr(resNom, "00:00:00.004", "formatDurationHhMmSsMs nominal string matches")
  assertEqStr(resEdge, "00:00:00.001", "formatDurationHhMmSsMs boundary string matches")
  ret 0
```

---

### `fixedTimestepAccumulatorNew` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn fixedTimestepAccumulatorNew(targetHertz: int = 60, maxSubSteps: int = 5): FixedTimestepAccumulator:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `targetHertz: int = 60, maxSubSteps: int = 5` | **Returns**: `FixedTimestepAccumulator`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `fixedTimestepAccumulatorNew` (`free fn`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: `targetHertz: int = 1`, `maxSubSteps: int = 1`; exercises core body path returning/computing `FixedTimestepAccumulator(`.

```aipl
module tests.functions.time.frame_pacer_z1_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_fixedTimestepAccumulatorNew_1(): int:
  let arg_targetHertz = 1
  let edge_targetHertz = 0
  let arg_maxSubSteps = 4
  let edge_maxSubSteps = 1
  let resNom = fixedTimestepAccumulatorNew(arg_targetHertz, arg_maxSubSteps)
  let resEdge = fixedTimestepAccumulatorNew(edge_targetHertz, edge_maxSubSteps)
  assertEqInt(resNom.maxSubSteps, 4, "fixedTimestepAccumulatorNew nominal resNom.maxSubSteps == 4")
  assertEqInt(resEdge.maxSubSteps, 1, "fixedTimestepAccumulatorNew boundary resEdge.maxSubSteps == 1")
  ret 0
```

---

### `advance` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (mut self: FixedTimestepAccumulator) advance(currentTime: Instant): int:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: FixedTimestepAccumulator` | **Parameters**: `currentTime: Instant` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `advance` (`mut self: FixedTimestepAccumulator`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FixedTimestepAccumulator = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))`, `currentTime: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `steps`.

```aipl
module tests.functions.time.frame_pacer_z2_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FixedTimestepAccumulator_advance_2(): int:
  let mut recv_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 4), maxSubSteps = 4, accumulator = Duration(nanos = 4), lastTime = Instant(nanos = 4))
  let mut edge_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))
  let arg_currentTime = Instant(nanos = 4)
  let edge_currentTime = Instant(nanos = 1)
  let resNom = recv_self.advance(arg_currentTime)
  let resEdge = edge_self.advance(edge_currentTime)
  assertEqInt(resNom, 1, "advance nominal resNom == 1")
  assertEqInt(resEdge, 1, "advance boundary resEdge == 1")
  ret 0
```

---

### `alpha` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (self: FixedTimestepAccumulator) alpha(): float:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: FixedTimestepAccumulator` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `alpha` (`self: FixedTimestepAccumulator`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FixedTimestepAccumulator = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))`; exercises core body path returning/computing `float(accNs) / float(dtNs)`.

```aipl
module tests.functions.time.frame_pacer_z3_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FixedTimestepAccumulator_alpha_3(): int:
  let recv_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 4), maxSubSteps = 4, accumulator = Duration(nanos = 4), lastTime = Instant(nanos = 4))
  let edge_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))
  let resNom = recv_self.alpha()
  let resEdge = edge_self.alpha()
  assertApproxEq(resNom, 1.0, 0.001, "alpha nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 1.0, 0.001, "alpha boundary resEdge ~= 1.0")
  ret 0
```

---

### `stepSeconds` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (self: FixedTimestepAccumulator) stepSeconds(): float:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: FixedTimestepAccumulator` | **Parameters**: `none` | **Returns**: `float`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `stepSeconds` (`self: FixedTimestepAccumulator`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FixedTimestepAccumulator = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))`; exercises core body path returning/computing `self.targetDt.toSecondsFloat()`.

```aipl
module tests.functions.time.frame_pacer_z4_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FixedTimestepAccumulator_stepSeconds_4(): int:
  let recv_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 4), maxSubSteps = 4, accumulator = Duration(nanos = 4), lastTime = Instant(nanos = 4))
  let edge_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))
  let resNom = recv_self.stepSeconds()
  let resEdge = edge_self.stepSeconds()
  assertApproxEq(resNom, 0.0, 0.001, "stepSeconds nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "stepSeconds boundary resEdge ~= 0.0")
  ret 0
```

---

### `reset` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (mut self: FixedTimestepAccumulator) reset(now: Instant): void:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: FixedTimestepAccumulator` | **Parameters**: `now: Instant` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `reset` (`mut self: FixedTimestepAccumulator`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FixedTimestepAccumulator = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))`, `now: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.frame_pacer_z5_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FixedTimestepAccumulator_reset_5(): int:
  let mut recv_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 4), maxSubSteps = 4, accumulator = Duration(nanos = 4), lastTime = Instant(nanos = 4))
  let mut edge_self = FixedTimestepAccumulator(targetDt = Duration(nanos = 1), maxSubSteps = 1, accumulator = Duration(nanos = 1), lastTime = Instant(nanos = 1))
  let arg_now = Instant(nanos = 4)
  let edge_now = Instant(nanos = 1)
  recv_self.reset(arg_now)
  edge_self.reset(edge_now)
  assertEqInt(recv_self.maxSubSteps, 4, "reset nominal recv_self.maxSubSteps == 4")
  assertEqInt(edge_self.maxSubSteps, 1, "reset boundary edge_self.maxSubSteps == 1")
  ret 0
```

---

### `frameRateGovernorNew` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn frameRateGovernorNew(targetFps: int = 60): FrameRateGovernor:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `targetFps: int = 60` | **Returns**: `FrameRateGovernor`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `frameRateGovernorNew` (`free fn`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: `targetFps: int = 1`; exercises core body path returning/computing `FrameRateGovernor(`.

```aipl
module tests.functions.time.frame_pacer_z6_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_frameRateGovernorNew_6(): int:
  let arg_targetFps = 2
  let edge_targetFps = 0
  let resNom = frameRateGovernorNew(arg_targetFps)
  let resEdge = frameRateGovernorNew(edge_targetFps)
  assertEqInt(resNom.targetFps, 2, "frameRateGovernorNew nominal resNom.targetFps == 2")
  assertEqInt(resEdge.targetFps, 60, "frameRateGovernorNew boundary resEdge.targetFps == 60")
  ret 0
```

---

### `beginFrame` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (mut self: FrameRateGovernor) beginFrame(): void:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: FrameRateGovernor` | **Parameters**: `none` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `beginFrame` (`mut self: FrameRateGovernor`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FrameRateGovernor = FrameRateGovernor(targetFps = 1, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 1.0)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.frame_pacer_z7_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FrameRateGovernor_beginFrame_7(): int:
  let mut recv_self = FrameRateGovernor(targetFps = 2, targetFrameDuration = Duration(nanos = 4), lastFrameTime = Instant(nanos = 4), currentFps = 1.0)
  let mut edge_self = FrameRateGovernor(targetFps = 0, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 0.5)
  recv_self.beginFrame()
  edge_self.beginFrame()
  assertEqInt(recv_self.targetFps, 2, "beginFrame nominal recv_self.targetFps == 2")
  assertEqInt(edge_self.targetFps, 0, "beginFrame boundary edge_self.targetFps == 0")
  ret 0
```

---

### `endFrameAndSleep` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (mut self: FrameRateGovernor) endFrameAndSleep(): Duration:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: FrameRateGovernor` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `endFrameAndSleep` (`mut self: FrameRateGovernor`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FrameRateGovernor = FrameRateGovernor(targetFps = 1, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 1.0)`; exercises core body path returning/computing `durationZero()`.

```aipl
module tests.functions.time.frame_pacer_z8_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FrameRateGovernor_endFrameAndSleep_8(): int:
  let mut recv_self = FrameRateGovernor(targetFps = 2, targetFrameDuration = Duration(nanos = 4), lastFrameTime = Instant(nanos = 4), currentFps = 1.0)
  let mut edge_self = FrameRateGovernor(targetFps = 0, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 0.5)
  let resNom = recv_self.endFrameAndSleep()
  let resEdge = edge_self.endFrameAndSleep()
  assertEqInt(resNom.nanos, 0, "endFrameAndSleep nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "endFrameAndSleep boundary resEdge.nanos == 0")
  ret 0
```

---

### `setTargetFps` (`std/time/frame_pacer.aipl`)

- **Signature**: `pub fn (mut self: FrameRateGovernor) setTargetFps(targetFps: int): void:`
- **Import**: `import * from "std/time/frame_pacer"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `mut self: FrameRateGovernor` | **Parameters**: `targetFps: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/frame_pacer_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify fixed-timestep accumulator / frame governor `setTargetFps` (`mut self: FrameRateGovernor`) spiral-of-death `maxStepsPerFrame` clamping and interpolation `.alpha()` in `[0.0, 1.0)`. Concrete nominal inputs: receiver `recvObj: FrameRateGovernor = FrameRateGovernor(targetFps = 1, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 1.0)`, `targetFps: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.frame_pacer_z9_test
import * from "std/time/frame_pacer"
import { Duration, durationZero, durationFromNanos, NANOS_PER_SECOND, NANOS_PER_MILLI } from "std/time/duration"
import { Instant, instantNow, sleepMs } from "std/time/instant"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_frame_pacer_FrameRateGovernor_setTargetFps_9(): int:
  let mut recv_self = FrameRateGovernor(targetFps = 2, targetFrameDuration = Duration(nanos = 4), lastFrameTime = Instant(nanos = 4), currentFps = 1.0)
  let mut edge_self = FrameRateGovernor(targetFps = 0, targetFrameDuration = Duration(nanos = 1), lastFrameTime = Instant(nanos = 1), currentFps = 0.5)
  let arg_targetFps = 2
  let edge_targetFps = 0
  recv_self.setTargetFps(arg_targetFps)
  edge_self.setTargetFps(edge_targetFps)
  assertEqInt(recv_self.targetFps, 2, "setTargetFps nominal recv_self.targetFps == 2")
  assertEqInt(edge_self.targetFps, 60, "setTargetFps boundary edge_self.targetFps == 60")
  ret 0
```

---

### `nowMonoNs` (`std/time/instant.aipl`)

- **Signature**: `pub fn nowMonoNs(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `nowMonoNs` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.time.instant_z1_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_nowMonoNs_1(): int:
  let resNom = nowMonoNs()
  let resEdge = nowMonoNs()
  assert(resNom > 0, "nowMonoNs nominal resNom > 0")
  assert(resEdge > 0, "nowMonoNs boundary resEdge > 0")
  ret 0
```

---

### `nowUnixMs` (`std/time/instant.aipl`)

- **Signature**: `pub fn nowUnixMs(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `nowUnixMs` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `0`.

```aipl
module tests.functions.time.instant_z2_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_nowUnixMs_2(): int:
  let resNom = nowUnixMs()
  let resEdge = nowUnixMs()
  assert(resNom > 0, "nowUnixMs nominal resNom > 0")
  assert(resEdge > 0, "nowUnixMs boundary resEdge > 0")
  ret 0
```

---

### `sleepMs` (`std/time/instant.aipl`)

- **Signature**: `pub fn sleepMs(ms: int): void:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ms: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `sleepMs` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: `ms: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.instant_z3_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_sleepMs_3(): int:
  mut completedCalls = 0
  let arg_ms = 4
  let edge_ms = 1
  sleepMs(arg_ms)
  sleepMs(edge_ms)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sleepMs nominal and boundary void calls completed")
  ret 0
```

---

### `nowMs` (`std/time/instant.aipl`)

- **Signature**: `pub fn nowMs(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `nowMs` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `nowUnixMs()`.

```aipl
module tests.functions.time.instant_z4_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_nowMs_4(): int:
  let resNom = nowMs()
  let resEdge = nowMs()
  assert(resNom > 0, "nowMs nominal resNom > 0")
  assert(resEdge > 0, "nowMs boundary resEdge > 0")
  ret 0
```

---

### `nowEpochSeconds` (`std/time/instant.aipl`)

- **Signature**: `pub fn nowEpochSeconds(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `nowEpochSeconds` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `nowUnixMs() / 1000`.

```aipl
module tests.functions.time.instant_z5_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_nowEpochSeconds_5(): int:
  let resNom = nowEpochSeconds()
  let resEdge = nowEpochSeconds()
  assert(resNom > 0, "nowEpochSeconds nominal resNom > 0")
  assert(resEdge > 0, "nowEpochSeconds boundary resEdge > 0")
  ret 0
```

---

### `nowMicros` (`std/time/instant.aipl`)

- **Signature**: `pub fn nowMicros(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `nowMicros` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `nowUnixMs() * 1000`.

```aipl
module tests.functions.time.instant_z6_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_nowMicros_6(): int:
  let resNom = nowMicros()
  let resEdge = nowMicros()
  assert(resNom > 0, "nowMicros nominal resNom > 0")
  assert(resEdge > 0, "nowMicros boundary resEdge > 0")
  ret 0
```

---

### `instantFromNanos` (`std/time/instant.aipl`)

- **Signature**: `pub fn instantFromNanos(nanos: int): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `nanos: int` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `instantFromNanos` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: `nanos: int = 1`; exercises core body path returning/computing `Instant(nanos = nanos)`.

```aipl
module tests.functions.time.instant_z7_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_instantFromNanos_7(): int:
  let arg_nanos = 4
  let edge_nanos = 1
  let resNom = instantFromNanos(arg_nanos)
  let resEdge = instantFromNanos(edge_nanos)
  assertEqInt(resNom.nanos, 4, "instantFromNanos nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "instantFromNanos boundary resEdge.nanos == 1")
  ret 0
```

---

### `instantFromMillis` (`std/time/instant.aipl`)

- **Signature**: `pub fn instantFromMillis(millis: int): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `millis: int` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `instantFromMillis` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: `millis: int = 1`; exercises core body path returning/computing `Instant(nanos = millis * NANOS_PER_MILLI)`.

```aipl
module tests.functions.time.instant_z8_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_instantFromMillis_8(): int:
  let arg_millis = 4
  let edge_millis = 1
  let resNom = instantFromMillis(arg_millis)
  let resEdge = instantFromMillis(edge_millis)
  assertEqInt(resNom.nanos, 4000000, "instantFromMillis nominal resNom.nanos == 4000000")
  assertEqInt(resEdge.nanos, 1000000, "instantFromMillis boundary resEdge.nanos == 1000000")
  ret 0
```

---

### `instantNow` (`std/time/instant.aipl`)

- **Signature**: `pub fn instantNow(): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `instantNow` (`free fn`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `Instant(nanos = nowUnixMs() * NANOS_PER_MILLI)`.

```aipl
module tests.functions.time.instant_z9_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_instantNow_9(): int:
  let resNom = instantNow()
  let resEdge = instantNow()
  assert(resNom.nanos > 0, "instantNow nominal resNom.nanos > 0")
  assert(resEdge.nanos > 0, "instantNow boundary resEdge.nanos > 0")
  ret 0
```

---

### `toNanos` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) toNanos(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `toNanos` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos`.

```aipl
module tests.functions.time.instant_z10_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_toNanos_10(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.toNanos()
  let resEdge = edge_self.toNanos()
  assertEqInt(resNom, 4, "toNanos nominal resNom == 4")
  assertEqInt(resEdge, 1, "toNanos boundary resEdge == 1")
  ret 0
```

---

### `toMillis` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) toMillis(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `toMillis` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MILLI`.

```aipl
module tests.functions.time.instant_z11_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_toMillis_11(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.toMillis()
  let resEdge = edge_self.toMillis()
  assertEqInt(resNom, 0, "toMillis nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMillis boundary resEdge == 0")
  ret 0
```

---

### `toMicros` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) toMicros(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `toMicros` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos / NANOS_PER_MICRO`.

```aipl
module tests.functions.time.instant_z12_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_toMicros_12(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.toMicros()
  let resEdge = edge_self.toMicros()
  assertEqInt(resNom, 0, "toMicros nominal resNom == 0")
  assertEqInt(resEdge, 0, "toMicros boundary resEdge == 0")
  ret 0
```

---

### `durationSince` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) durationSince(earlier: Instant): Duration:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `earlier: Instant` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `durationSince` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `earlier: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `durationFromNanos(diff)`.

```aipl
module tests.functions.time.instant_z13_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_durationSince_13(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_earlier = Instant(nanos = 4)
  let edge_earlier = Instant(nanos = 1)
  let resNom = recv_self.durationSince(arg_earlier)
  let resEdge = edge_self.durationSince(edge_earlier)
  assertEqInt(resNom.nanos, 0, "durationSince nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "durationSince boundary resEdge.nanos == 0")
  ret 0
```

---

### `signedDurationSince` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) signedDurationSince(earlier: Instant): Duration:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `earlier: Instant` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `signedDurationSince` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `earlier: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `durationFromNanos(self.nanos - earlier.nanos)`.

```aipl
module tests.functions.time.instant_z14_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_signedDurationSince_14(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_earlier = Instant(nanos = 4)
  let edge_earlier = Instant(nanos = 1)
  let resNom = recv_self.signedDurationSince(arg_earlier)
  let resEdge = edge_self.signedDurationSince(edge_earlier)
  assertEqInt(resNom.nanos, 0, "signedDurationSince nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "signedDurationSince boundary resEdge.nanos == 0")
  ret 0
```

---

### `checkedDurationSince` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) checkedDurationSince(earlier: Instant): Option[Duration]:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `earlier: Instant` | **Returns**: `Option[Duration]`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `checkedDurationSince` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `earlier: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `Some(durationFromNanos(self.nanos - earlier.nanos))`.

```aipl
module tests.functions.time.instant_z15_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_checkedDurationSince_15(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_earlier = Instant(nanos = 4)
  let edge_earlier = Instant(nanos = 1)
  let resNom = recv_self.checkedDurationSince(arg_earlier)
  let resEdge = edge_self.checkedDurationSince(edge_earlier)
  assert(resNom.isSome() == true, "checkedDurationSince nominal resNom.isSome() == true")
  assert(resEdge.isSome() == true, "checkedDurationSince boundary resEdge.isSome() == true")
  ret 0
```

---

### `saturatingDurationSince` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) saturatingDurationSince(earlier: Instant): Duration:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `earlier: Instant` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `saturatingDurationSince` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `earlier: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `durationFromNanos(self.nanos - earlier.nanos)`.

```aipl
module tests.functions.time.instant_z16_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_saturatingDurationSince_16(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_earlier = Instant(nanos = 4)
  let edge_earlier = Instant(nanos = 1)
  let resNom = recv_self.saturatingDurationSince(arg_earlier)
  let resEdge = edge_self.saturatingDurationSince(edge_earlier)
  assertEqInt(resNom.nanos, 0, "saturatingDurationSince nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "saturatingDurationSince boundary resEdge.nanos == 0")
  ret 0
```

---

### `elapsed` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) elapsed(): Duration:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `Duration`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `elapsed` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `cur.durationSince(self)`.

```aipl
module tests.functions.time.instant_z17_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_elapsed_17(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.elapsed()
  let resEdge = edge_self.elapsed()
  assert(resNom.nanos > 0, "elapsed nominal resNom.nanos > 0")
  assert(resEdge.nanos > 0, "elapsed boundary resEdge.nanos > 0")
  ret 0
```

---

### `elapsedMs` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) elapsedMs(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `elapsedMs` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.elapsed().toMillis()`.

```aipl
module tests.functions.time.instant_z18_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_elapsedMs_18(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.elapsedMs()
  let resEdge = edge_self.elapsedMs()
  assert(resNom > 0, "elapsedMs nominal resNom > 0")
  assert(resEdge > 0, "elapsedMs boundary resEdge > 0")
  ret 0
```

---

### `elapsedMicros` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) elapsedMicros(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `elapsedMicros` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.elapsed().toMicros()`.

```aipl
module tests.functions.time.instant_z19_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_elapsedMicros_19(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.elapsedMicros()
  let resEdge = edge_self.elapsedMicros()
  assert(resNom > 0, "elapsedMicros nominal resNom > 0")
  assert(resEdge > 0, "elapsedMicros boundary resEdge > 0")
  ret 0
```

---

### `elapsedNanos` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) elapsedNanos(): int:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `elapsedNanos` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.elapsed().toNanos()`.

```aipl
module tests.functions.time.instant_z20_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_elapsedNanos_20(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let resNom = recv_self.elapsedNanos()
  let resEdge = edge_self.elapsedNanos()
  assert(resNom > 0, "elapsedNanos nominal resNom > 0")
  assert(resEdge > 0, "elapsedNanos boundary resEdge > 0")
  ret 0
```

---

### `addDuration` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) addDuration(d: Duration): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `d: Duration` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `addDuration` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `d: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `Instant(nanos = self.nanos + d.nanos)`.

```aipl
module tests.functions.time.instant_z21_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_addDuration_21(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_d = Duration(nanos = 4)
  let edge_d = Duration(nanos = 1)
  let resNom = recv_self.addDuration(arg_d)
  let resEdge = edge_self.addDuration(edge_d)
  assertEqInt(resNom.nanos, 8, "addDuration nominal resNom.nanos == 8")
  assertEqInt(resEdge.nanos, 2, "addDuration boundary resEdge.nanos == 2")
  ret 0
```

---

### `subDuration` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) subDuration(d: Duration): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `d: Duration` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `subDuration` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `d: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `Instant(nanos = self.nanos - d.nanos)`.

```aipl
module tests.functions.time.instant_z22_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_subDuration_22(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_d = Duration(nanos = 4)
  let edge_d = Duration(nanos = 1)
  let resNom = recv_self.subDuration(arg_d)
  let resEdge = edge_self.subDuration(edge_d)
  assertEqInt(resNom.nanos, 0, "subDuration nominal resNom.nanos == 0")
  assertEqInt(resEdge.nanos, 0, "subDuration boundary resEdge.nanos == 0")
  ret 0
```

---

### `isAfter` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) isAfter(other: Instant): bool:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `other: Instant` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `isAfter` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `other: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos > other.nanos`.

```aipl
module tests.functions.time.instant_z23_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_isAfter_23(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_other = Instant(nanos = 4)
  let edge_other = Instant(nanos = 1)
  let resNom = recv_self.isAfter(arg_other)
  let resEdge = edge_self.isAfter(edge_other)
  assert(resNom == false, "isAfter nominal resNom == false")
  assert(resEdge == false, "isAfter boundary resEdge == false")
  ret 0
```

---

### `isBefore` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) isBefore(other: Instant): bool:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `other: Instant` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `isBefore` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `other: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos < other.nanos`.

```aipl
module tests.functions.time.instant_z24_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_isBefore_24(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_other = Instant(nanos = 4)
  let edge_other = Instant(nanos = 1)
  let resNom = recv_self.isBefore(arg_other)
  let resEdge = edge_self.isBefore(edge_other)
  assert(resNom == false, "isBefore nominal resNom == false")
  assert(resEdge == false, "isBefore boundary resEdge == false")
  ret 0
```

---

### `equals` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) equals(other: Instant): bool:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `other: Instant` | **Returns**: `bool`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `equals` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `other: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self.nanos == other.nanos`.

```aipl
module tests.functions.time.instant_z25_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_equals_25(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_other = Instant(nanos = 4)
  let edge_other = Instant(nanos = 1)
  let resNom = recv_self.equals(arg_other)
  let resEdge = edge_self.equals(edge_other)
  assert(resNom == true, "equals nominal resNom == true")
  assert(resEdge == true, "equals boundary resEdge == true")
  ret 0
```

---

### `min` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) min(other: Instant): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `other: Instant` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `min` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `other: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `other`.

```aipl
module tests.functions.time.instant_z26_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_min_26(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_other = Instant(nanos = 4)
  let edge_other = Instant(nanos = 1)
  let resNom = recv_self.min(arg_other)
  let resEdge = edge_self.min(edge_other)
  assertEqInt(resNom.nanos, 4, "min nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "min boundary resEdge.nanos == 1")
  ret 0
```

---

### `max` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) max(other: Instant): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `other: Instant` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `max` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `other: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `other`.

```aipl
module tests.functions.time.instant_z27_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_max_27(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_other = Instant(nanos = 4)
  let edge_other = Instant(nanos = 1)
  let resNom = recv_self.max(arg_other)
  let resEdge = edge_self.max(edge_other)
  assertEqInt(resNom.nanos, 4, "max nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "max boundary resEdge.nanos == 1")
  ret 0
```

---

### `clamp` (`std/time/instant.aipl`)

- **Signature**: `pub fn (self: Instant) clamp(minInst: Instant, maxInst: Instant): Instant:`
- **Import**: `import * from "std/time/instant"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `self: Instant` | **Parameters**: `minInst: Instant, maxInst: Instant` | **Returns**: `Instant`
- **Unit Test**: `tests/functions/time/instant_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify monotonic clock / `Instant` function `clamp` (`self: Instant`) ordering invariants (`t2.isAfter(t1)`), checked vs saturating duration deltas, and duration addition/subtraction. Concrete nominal inputs: receiver `recvObj: Instant = Instant(nanos = 1)`, `minInst: Instant = Instant(nanos = 1)`, `maxInst: Instant = Instant(nanos = 1)`; exercises core body path returning/computing `self`.

```aipl
module tests.functions.time.instant_z28_test
import * from "std/time/instant"
import { Duration, durationFromNanos, durationFromMillis, NANOS_PER_MILLI, NANOS_PER_MICRO } from "std/time/duration"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_instant_Instant_clamp_28(): int:
  let recv_self = Instant(nanos = 4)
  let edge_self = Instant(nanos = 1)
  let arg_minInst = Instant(nanos = 4)
  let edge_minInst = Instant(nanos = 1)
  let arg_maxInst = Instant(nanos = 4)
  let edge_maxInst = Instant(nanos = 1)
  let resNom = recv_self.clamp(arg_minInst, arg_maxInst)
  let resEdge = edge_self.clamp(edge_minInst, edge_maxInst)
  assertEqInt(resNom.nanos, 4, "clamp nominal resNom.nanos == 4")
  assertEqInt(resEdge.nanos, 1, "clamp boundary resEdge.nanos == 1")
  ret 0
```

---

### `epochSeconds` (`std/time/time_mod.aipl`)

- **Signature**: `pub fn epochSeconds(): int:`
- **Import**: `import * from "std/time/time_mod"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/time_mod_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify top-level clock/sleep facade `epochSeconds` monotonic and epoch timestamp progression. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `nowUnixMs() / 1000`.

```aipl
module tests.functions.time.time_mod_z1_test
import * from "std/time/time_mod"
import { nowUnixMs, nowMonoNs, sleepMs } from "std/time/instant"
import { Duration, NANOS_PER_MILLI } from "std/time/duration"
import { DateTimeUtc, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_time_mod_epochSeconds_1(): int:
  let resNom = epochSeconds()
  let resEdge = epochSeconds()
  assert(resNom > 0, "epochSeconds nominal resNom > 0")
  assert(resEdge > 0, "epochSeconds boundary resEdge > 0")
  ret 0
```

---

### `epochMillis` (`std/time/time_mod.aipl`)

- **Signature**: `pub fn epochMillis(): int:`
- **Import**: `import * from "std/time/time_mod"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/time_mod_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify top-level clock/sleep facade `epochMillis` monotonic and epoch timestamp progression. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `nowUnixMs()`.

```aipl
module tests.functions.time.time_mod_z2_test
import * from "std/time/time_mod"
import { nowUnixMs, nowMonoNs, sleepMs } from "std/time/instant"
import { Duration, NANOS_PER_MILLI } from "std/time/duration"
import { DateTimeUtc, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_time_mod_epochMillis_2(): int:
  let resNom = epochMillis()
  let resEdge = epochMillis()
  assert(resNom > 0, "epochMillis nominal resNom > 0")
  assert(resEdge > 0, "epochMillis boundary resEdge > 0")
  ret 0
```

---

### `epochNanos` (`std/time/time_mod.aipl`)

- **Signature**: `pub fn epochNanos(): int:`
- **Import**: `import * from "std/time/time_mod"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `int`
- **Unit Test**: `tests/functions/time/time_mod_test.aipl` | **Example**: `examples/ex_065_time_duration_humanizer_cli.aipl`
- **Behavioral Summary**: Verify top-level clock/sleep facade `epochNanos` monotonic and epoch timestamp progression. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `mono`.

```aipl
module tests.functions.time.time_mod_z3_test
import * from "std/time/time_mod"
import { nowUnixMs, nowMonoNs, sleepMs } from "std/time/instant"
import { Duration, NANOS_PER_MILLI } from "std/time/duration"
import { DateTimeUtc, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_time_mod_epochNanos_3(): int:
  let resNom = epochNanos()
  let resEdge = epochNanos()
  assert(resNom > 0, "epochNanos nominal resNom > 0")
  assert(resEdge > 0, "epochNanos boundary resEdge > 0")
  ret 0
```

---

### `nowUtc` (`std/time/time_mod.aipl`)

- **Signature**: `pub fn nowUtc(): DateTimeUtc:`
- **Import**: `import * from "std/time/time_mod"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `DateTimeUtc`
- **Unit Test**: `tests/functions/time/time_mod_test.aipl` | **Example**: `examples/ex_066_time_datetime_iso8601_calendar_cli.aipl`
- **Behavioral Summary**: Verify top-level clock/sleep facade `nowUtc` monotonic and epoch timestamp progression. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `unixToDateTimeUtc(sec, remNs)`.

```aipl
module tests.functions.time.time_mod_z4_test
import * from "std/time/time_mod"
import { nowUnixMs, nowMonoNs, sleepMs } from "std/time/instant"
import { Duration, NANOS_PER_MILLI } from "std/time/duration"
import { DateTimeUtc, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_time_mod_nowUtc_4(): int:
  let resNom = nowUtc()
  let resEdge = nowUtc()
  assert(resNom.unixNanos > 0, "nowUtc nominal resNom.unixNanos > 0")
  assert(resEdge.unixNanos > 0, "nowUtc boundary resEdge.unixNanos > 0")
  ret 0
```

---

### `sleep` (`std/time/time_mod.aipl`)

- **Signature**: `pub fn sleep(duration: Duration): void:`
- **Import**: `import * from "std/time/time_mod"` (or barrel `import * from "std/time/time_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `duration: Duration` | **Returns**: `void`
- **Unit Test**: `tests/functions/time/time_mod_test.aipl` | **Example**: `examples/ex_067_time_cron_schedule_planner_cli.aipl`
- **Behavioral Summary**: Verify top-level clock/sleep facade `sleep` monotonic and epoch timestamp progression. Concrete nominal inputs: `duration: Duration = Duration(nanos = 1)`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.time.time_mod_z5_test
import * from "std/time/time_mod"
import { nowUnixMs, nowMonoNs, sleepMs } from "std/time/instant"
import { Duration, NANOS_PER_MILLI } from "std/time/duration"
import { DateTimeUtc, unixToDateTimeUtc } from "std/time/datetime"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_time_mod_sleep_5(): int:
  mut completedCalls = 0
  let arg_duration = Duration(nanos = 4)
  let edge_duration = Duration(nanos = 1)
  sleep(arg_duration)
  sleep(edge_duration)
  completedCalls = completedCalls + 2
  assertEqInt(completedCalls, 2, "sleep nominal and boundary void calls completed")
  ret 0
```
