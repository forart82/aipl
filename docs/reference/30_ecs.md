[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 30: `ecs` API Reference

> Complete API reference manual for AIPL standard library domain `ecs` (29 callable functions & methods across ["std/ecs/archetype.aipl", "std/ecs/ecs_command.aipl", "std/ecs/ecs_event.aipl", "std/ecs/ecs_mod.aipl", "std/ecs/ecs_query.aipl", "std/ecs/ecs_schedule.aipl", "std/ecs/ecs_world.aipl", "std/ecs/entity.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `ecs`
- **Target Source Modules**: ["std/ecs/archetype.aipl", "std/ecs/ecs_command.aipl", "std/ecs/ecs_event.aipl", "std/ecs/ecs_mod.aipl", "std/ecs/ecs_query.aipl", "std/ecs/ecs_schedule.aipl", "std/ecs/ecs_world.aipl", "std/ecs/entity.aipl"]
- **Total Callable Functions & Methods**: 29
- **Total Data Types (`struct` & `enum`)**: 13
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(13 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ComponentColumn` | `pub struct` | `std/ecs/archetype.aipl` | `componentId: int`, `values: [float]` | `ComponentColumn(componentId, values)` |
| `ArchetypeTable` | `pub struct` | `std/ecs/archetype.aipl` | `signatureMask: int`, `entities: [EntityId]`, `columns: [ComponentColumn]` | `ArchetypeTable(signatureMask, entities, columns)` |
| `EcsCommand` | `pub struct` | `std/ecs/ecs_command.aipl` | `cmdType: int`, `targetEntity: EntityId`, `paramId: int`, `paramValue: float` | `EcsCommand(cmdType, targetEntity, paramId, paramValue)` |
| `EcsCommandBuffer` | `pub struct` | `std/ecs/ecs_command.aipl` | `commands: [EcsCommand]` | `EcsCommandBuffer(commands)` |
| `EventEnvelope` | `pub struct` | `std/ecs/ecs_event.aipl` | `eventTypeId: int`, `sourceEntityIndex: int`, `payloadA: float`, `payloadB: float` | `EventEnvelope(eventTypeId, sourceEntityIndex, payloadA, payloadB)` |
| `EventBus` | `pub struct` | `std/ecs/ecs_event.aipl` | `currentQueue: [EventEnvelope]`, `previousQueue: [EventEnvelope]` | `EventBus(currentQueue, previousQueue)` |
| `EventReader` | `pub struct` | `std/ecs/ecs_event.aipl` | `readCursorPrev: int`, `readCursorCurr: int` | `EventReader(readCursorPrev, readCursorCurr)` |
| `QueryFilter` | `pub struct` | `std/ecs/ecs_query.aipl` | `withMask: int`, `withoutMask: int` | `QueryFilter(withMask, withoutMask)` |
| `SystemDescriptor` | `pub struct` | `std/ecs/ecs_schedule.aipl` | `systemId: int`, `stage: int`, `readComponentMask: int`, `writeComponentMask: int`, `priority: int` | `SystemDescriptor(systemId, stage, readComponentMask, writeComponentMask, priority)` |
| `EntityLocation` | `pub struct` | `std/ecs/ecs_world.aipl` | `archetypeIndex: int`, `rowIndex: int` | `EntityLocation(archetypeIndex, rowIndex)` |
| `EcsWorld` | `pub struct` | `std/ecs/ecs_world.aipl` | `entityPool: EntityPool`, `archetypes: [ArchetypeTable]`, `locations: [EntityLocation]`, `resources: [float]` | `EcsWorld(entityPool, archetypes, locations, resources)` |
| `EntityId` | `pub struct` | `std/ecs/entity.aipl` | `index: int`, `generation: int` | `EntityId(index, generation)` |
| `EntityPool` | `pub struct` | `std/ecs/entity.aipl` | `generations: [int]`, `alive: [bool]`, `freeIndices: [int]` | `EntityPool(generations, alive, freeIndices)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/ecs/archetype.aipl` | `createArchetypeTable` | `pub fn createArchetypeTable(signatureMask: int, componentIds: [int]): ArchetypeTable:` | `tests/functions/ecs/archetype_test.aipl` |
| `2` | `std/ecs/archetype.aipl` | `insertArchetypeRow` | `pub fn insertArchetypeRow(table: ArchetypeTable, entity: EntityId, initialValues: [float]): ArchetypeTable:` | `tests/functions/ecs/archetype_test.aipl` |
| `3` | `std/ecs/archetype.aipl` | `swapRemoveArchetypeRow` | `pub fn swapRemoveArchetypeRow(table: ArchetypeTable, rowIndex: int): ArchetypeTable:` | `tests/functions/ecs/archetype_test.aipl` |
| `4` | `std/ecs/archetype.aipl` | `migrateEntityBetweenArchetypes` | `pub fn migrateEntityBetweenArchetypes(src: ArchetypeTable, dst: ArchetypeTable, rowIndex: int): (ArchetypeTable, ArchetypeTable, int):` | `tests/functions/ecs/archetype_test.aipl` |
| `5` | `std/ecs/ecs_command.aipl` | `createCommandBuffer` | `pub fn createCommandBuffer(): EcsCommandBuffer:` | `tests/functions/ecs/ecs_command_test.aipl` |
| `6` | `std/ecs/ecs_command.aipl` | `recordSpawnCommand` | `pub fn recordSpawnCommand(buf: EcsCommandBuffer): EcsCommandBuffer:` | `tests/functions/ecs/ecs_command_test.aipl` |
| `7` | `std/ecs/ecs_command.aipl` | `recordDespawnCommand` | `pub fn recordDespawnCommand(buf: EcsCommandBuffer, entity: EntityId): EcsCommandBuffer:` | `tests/functions/ecs/ecs_command_test.aipl` |
| `8` | `std/ecs/ecs_command.aipl` | `flushCommandBuffer` | `pub fn flushCommandBuffer(world: EcsWorld, buf: EcsCommandBuffer): EcsWorld:` | `tests/functions/ecs/ecs_command_test.aipl` |
| `9` | `std/ecs/ecs_event.aipl` | `createEventBus` | `pub fn createEventBus(): EventBus:` | `tests/functions/ecs/ecs_event_test.aipl` |
| `10` | `std/ecs/ecs_event.aipl` | `publishEvent` | `pub fn publishEvent(bus: EventBus, ev: EventEnvelope): EventBus:` | `tests/functions/ecs/ecs_event_test.aipl` |
| `11` | `std/ecs/ecs_event.aipl` | `swapEventBuffers` | `pub fn swapEventBuffers(bus: EventBus): EventBus:` | `tests/functions/ecs/ecs_event_test.aipl` |
| `12` | `std/ecs/ecs_event.aipl` | `readNewEvents` | `pub fn readNewEvents(bus: EventBus, reader: EventReader, eventTypeId: int): ([EventEnvelope], EventReader):` | `tests/functions/ecs/ecs_event_test.aipl` |
| `13` | `std/ecs/ecs_query.aipl` | `matchesQueryFilter` | `pub fn matchesQueryFilter(archetypeMask: int, filter: QueryFilter): bool:` | `tests/functions/ecs/ecs_query_test.aipl` |
| `14` | `std/ecs/ecs_query.aipl` | `findMatchingArchetypes` | `pub fn findMatchingArchetypes(world: EcsWorld, filter: QueryFilter): [int]:` | `tests/functions/ecs/ecs_query_test.aipl` |
| `15` | `std/ecs/ecs_query.aipl` | `queryEntities` | `pub fn queryEntities(world: EcsWorld, filter: QueryFilter): [EntityId]:` | `tests/functions/ecs/ecs_query_test.aipl` |
| `16` | `std/ecs/ecs_schedule.aipl` | `systemsConflict` | `pub fn systemsConflict(a: SystemDescriptor, b: SystemDescriptor): bool:` | `tests/functions/ecs/ecs_schedule_test.aipl` |
| `17` | `std/ecs/ecs_schedule.aipl` | `sortSystemsByPriority` | `pub fn sortSystemsByPriority(systems: [SystemDescriptor], stage: int): [SystemDescriptor]:` | `tests/functions/ecs/ecs_schedule_test.aipl` |
| `18` | `std/ecs/ecs_schedule.aipl` | `buildParallelBatches` | `pub fn buildParallelBatches(sortedSystems: [SystemDescriptor]): [[int]]:` | `tests/functions/ecs/ecs_schedule_test.aipl` |
| `19` | `std/ecs/ecs_world.aipl` | `createEcsWorld` | `pub fn createEcsWorld(): EcsWorld:` | `tests/functions/ecs/ecs_world_test.aipl` |
| `20` | `std/ecs/ecs_world.aipl` | `spawnEntity` | `pub fn spawnEntity(world: EcsWorld): (EcsWorld, EntityId):` | `tests/functions/ecs/ecs_world_test.aipl` |
| `21` | `std/ecs/ecs_world.aipl` | `despawnEntity` | `pub fn despawnEntity(world: EcsWorld, entity: EntityId): EcsWorld:` | `tests/functions/ecs/ecs_world_test.aipl` |
| `22` | `std/ecs/ecs_world.aipl` | `setWorldResource` | `pub fn setWorldResource(world: EcsWorld, resourceId: int, value: float): EcsWorld:` | `tests/functions/ecs/ecs_world_test.aipl` |
| `23` | `std/ecs/ecs_world.aipl` | `getWorldResource` | `pub fn getWorldResource(world: EcsWorld, resourceId: int): Option[float]:` | `tests/functions/ecs/ecs_world_test.aipl` |
| `24` | `std/ecs/entity.aipl` | `createEntityPool` | `pub fn createEntityPool(): EntityPool:` | `tests/functions/ecs/entity_test.aipl` |
| `25` | `std/ecs/entity.aipl` | `allocateEntity` | `pub fn allocateEntity(pool: EntityPool): (EntityPool, EntityId):` | `tests/functions/ecs/entity_test.aipl` |
| `26` | `std/ecs/entity.aipl` | `recycleEntity` | `pub fn recycleEntity(pool: EntityPool, id: EntityId): EntityPool:` | `tests/functions/ecs/entity_test.aipl` |
| `27` | `std/ecs/entity.aipl` | `isEntityAlive` | `pub fn isEntityAlive(pool: EntityPool, id: EntityId): bool:` | `tests/functions/ecs/entity_test.aipl` |
| `28` | `std/ecs/entity.aipl` | `packEntityU64` | `pub fn packEntityU64(id: EntityId): int:` | `tests/functions/ecs/entity_test.aipl` |
| `29` | `std/ecs/entity.aipl` | `unpackEntityU64` | `pub fn unpackEntityU64(packed: int): EntityId:` | `tests/functions/ecs/entity_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `createArchetypeTable` (`std/ecs/archetype.aipl`)

- **Signature**: `pub fn createArchetypeTable(signatureMask: int, componentIds: [int]): ArchetypeTable:`
- **Import**: `import * from "std/ecs/archetype"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `signatureMask: int, componentIds: [int]` | **Returns**: `ArchetypeTable`
- **Unit Test**: `tests/functions/ecs/archetype_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Verifies SoA archetype table row insertion, swap-remove compaction, and cross-archetype entity migration in `createArchetypeTable`. Concrete nominal inputs: `signatureMask: int = 1`, `componentIds: [int] = [1]`; exercises core body path returning/computing `ArchetypeTable(signatureMask = signatureMask, entities = ents, columns = cols)`.

```aipl
module tests.functions.ecs.archetype_z1_test
import * from "std/ecs/archetype"
import { EntityId } from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_archetype_createArchetypeTable_1(): int:
  let arg_signatureMask = 4
  let edge_signatureMask = 1
  let arg_componentIds = [4]
  let edge_componentIds = []
  let resNom = createArchetypeTable(arg_signatureMask, arg_componentIds)
  let resEdge = createArchetypeTable(edge_signatureMask, edge_componentIds)
  assertEqInt(resNom.signatureMask, 4, "createArchetypeTable nominal resNom.signatureMask == 4")
  assertEqInt(resEdge.signatureMask, 1, "createArchetypeTable boundary resEdge.signatureMask == 1")
  ret 0
```

---

### `insertArchetypeRow` (`std/ecs/archetype.aipl`)

- **Signature**: `pub fn insertArchetypeRow(table: ArchetypeTable, entity: EntityId, initialValues: [float]): ArchetypeTable:`
- **Import**: `import * from "std/ecs/archetype"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `table: ArchetypeTable, entity: EntityId, initialValues: [float]` | **Returns**: `ArchetypeTable`
- **Unit Test**: `tests/functions/ecs/archetype_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Verifies SoA archetype table row insertion, swap-remove compaction, and cross-archetype entity migration in `insertArchetypeRow`. Concrete nominal inputs: `table: ArchetypeTable = ArchetypeTable(signatureMask = 1, entities = [EntityId(index = 0, generation = 0)], columns = [ComponentColumn(componentId = 0, values = 0)])`, `entity: EntityId = EntityId(index = 0, generation = 1)`, `initialValues: [float] = [1.0]`; exercises core body path returning/computing `ArchetypeTable(signatureMask = table.signatureMask, entities = ents, columns = cols)`.

```aipl
module tests.functions.ecs.archetype_z2_test
import * from "std/ecs/archetype"
import { EntityId } from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_archetype_insertArchetypeRow_2(): int:
  let arg_table = ArchetypeTable(signatureMask = 4, entities = [], columns = [])
  let edge_table = ArchetypeTable(signatureMask = 1, entities = [], columns = [])
  let arg_entity = EntityId(index = 0, generation = 4)
  let edge_entity = EntityId(index = 0, generation = 1)
  let arg_initialValues = [1.0]
  let edge_initialValues = []
  let resNom = insertArchetypeRow(arg_table, arg_entity, arg_initialValues)
  let resEdge = insertArchetypeRow(edge_table, edge_entity, edge_initialValues)
  assertEqInt(resNom.signatureMask, 4, "insertArchetypeRow nominal resNom.signatureMask == 4")
  assertEqInt(resEdge.signatureMask, 1, "insertArchetypeRow boundary resEdge.signatureMask == 1")
  ret 0
```

---

### `swapRemoveArchetypeRow` (`std/ecs/archetype.aipl`)

- **Signature**: `pub fn swapRemoveArchetypeRow(table: ArchetypeTable, rowIndex: int): ArchetypeTable:`
- **Import**: `import * from "std/ecs/archetype"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `table: ArchetypeTable, rowIndex: int` | **Returns**: `ArchetypeTable`
- **Unit Test**: `tests/functions/ecs/archetype_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Verifies SoA archetype table row insertion, swap-remove compaction, and cross-archetype entity migration in `swapRemoveArchetypeRow`. Concrete nominal inputs: `table: ArchetypeTable = ArchetypeTable(signatureMask = 1, entities = [EntityId(index = 0, generation = 0)], columns = [ComponentColumn(componentId = 0, values = 0)])`, `rowIndex: int = 0`; exercises core body path returning/computing `ArchetypeTable(signatureMask = table.signatureMask, entities = nextEnts, columns = nextCols)`.

```aipl
module tests.functions.ecs.archetype_z3_test
import * from "std/ecs/archetype"
import { EntityId } from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_archetype_swapRemoveArchetypeRow_3(): int:
  let arg_table = ArchetypeTable(signatureMask = 4, entities = [], columns = [])
  let edge_table = ArchetypeTable(signatureMask = 1, entities = [], columns = [])
  let arg_rowIndex = 4
  let edge_rowIndex = 1
  let resNom = swapRemoveArchetypeRow(arg_table, arg_rowIndex)
  let resEdge = swapRemoveArchetypeRow(edge_table, edge_rowIndex)
  assertEqInt(resNom.signatureMask, 4, "swapRemoveArchetypeRow nominal resNom.signatureMask == 4")
  assertEqInt(resEdge.signatureMask, 1, "swapRemoveArchetypeRow boundary resEdge.signatureMask == 1")
  ret 0
```

---

### `migrateEntityBetweenArchetypes` (`std/ecs/archetype.aipl`)

- **Signature**: `pub fn migrateEntityBetweenArchetypes(src: ArchetypeTable, dst: ArchetypeTable, rowIndex: int): (ArchetypeTable, ArchetypeTable, int):`
- **Import**: `import * from "std/ecs/archetype"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `src: ArchetypeTable, dst: ArchetypeTable, rowIndex: int` | **Returns**: `(ArchetypeTable, ArchetypeTable, int)`
- **Unit Test**: `tests/functions/ecs/archetype_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Verifies SoA archetype table row insertion, swap-remove compaction, and cross-archetype entity migration in `migrateEntityBetweenArchetypes`. Concrete nominal inputs: `src: ArchetypeTable = ArchetypeTable(signatureMask = 1, entities = [EntityId(index = 0, generation = 0)], columns = [ComponentColumn(componentId = 0, values = 0)])`, `dst: ArchetypeTable = ArchetypeTable(signatureMask = 1, entities = [EntityId(index = 0, generation = 0)], columns = [ComponentColumn(componentId = 0, values = 0)])`, `rowIndex: int): (ArchetypeTable = int): (ArchetypeTable()`, `ArchetypeTable: any = 42`, `int: any = 42`; exercises core body path returning/computing `(nextSrc, nextDst, newDstRow)`.

```aipl
module tests.functions.ecs.archetype_z4_test
import * from "std/ecs/archetype"
import { EntityId } from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_archetype_migrateEntityBetweenArchetypes_4(): int:
  let arg_src = ArchetypeTable(signatureMask = 4, entities = [], columns = [])
  let edge_src = ArchetypeTable(signatureMask = 1, entities = [], columns = [])
  let arg_dst = ArchetypeTable(signatureMask = 4, entities = [], columns = [])
  let edge_dst = ArchetypeTable(signatureMask = 1, entities = [], columns = [])
  let arg_rowIndex = 4
  let edge_rowIndex = 1
  let resNom = migrateEntityBetweenArchetypes(arg_src, arg_dst, arg_rowIndex)
  let resEdge = migrateEntityBetweenArchetypes(edge_src, edge_dst, edge_rowIndex)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqInt(n_t0.signatureMask, 4, "migrateEntityBetweenArchetypes nominal n_t0.signatureMask == 4")
  assertEqInt(e_t0.signatureMask, 1, "migrateEntityBetweenArchetypes boundary e_t0.signatureMask == 1")
  ret 0
```

---

### `createCommandBuffer` (`std/ecs/ecs_command.aipl`)

- **Signature**: `pub fn createCommandBuffer(): EcsCommandBuffer:`
- **Import**: `import * from "std/ecs/ecs_command"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `EcsCommandBuffer`
- **Unit Test**: `tests/functions/ecs/ecs_command_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests deferred ECS command buffering (`spawn`, `despawn`, `addComponent`) and end-of-stage `flushCommandBuffer` execution in `createCommandBuffer`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `EcsCommandBuffer(commands = cmds)`.

```aipl
module tests.functions.ecs.ecs_command_z1_test
import * from "std/ecs/ecs_command"
import { EntityId } from "std/ecs/entity"
import { EcsWorld, spawnEntity, despawnEntity } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_command_createCommandBuffer_1(): int:
  let resNom = createCommandBuffer()
  let resEdge = createCommandBuffer()
  assertEqInt(resNom.commands.len(), 0, "createCommandBuffer nominal resNom.commands.len() == 0")
  assertEqInt(resEdge.commands.len(), 0, "createCommandBuffer boundary resEdge.commands.len() == 0")
  ret 0
```

---

### `recordSpawnCommand` (`std/ecs/ecs_command.aipl`)

- **Signature**: `pub fn recordSpawnCommand(buf: EcsCommandBuffer): EcsCommandBuffer:`
- **Import**: `import * from "std/ecs/ecs_command"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: EcsCommandBuffer` | **Returns**: `EcsCommandBuffer`
- **Unit Test**: `tests/functions/ecs/ecs_command_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Tests deferred ECS command buffering (`spawn`, `despawn`, `addComponent`) and end-of-stage `flushCommandBuffer` execution in `recordSpawnCommand`. Concrete nominal inputs: `buf: EcsCommandBuffer = EcsCommandBuffer(commands = [EcsCommand(cmdType = 0, targetEntity = 0, paramId = 0, paramValue = 0)])`; exercises core body path returning/computing `EcsCommandBuffer(commands = cmds)`.

```aipl
module tests.functions.ecs.ecs_command_z2_test
import * from "std/ecs/ecs_command"
import { EntityId } from "std/ecs/entity"
import { EcsWorld, spawnEntity, despawnEntity } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_command_recordSpawnCommand_2(): int:
  let arg_buf = EcsCommandBuffer(commands = [])
  let edge_buf = EcsCommandBuffer(commands = [])
  let resNom = recordSpawnCommand(arg_buf)
  let resEdge = recordSpawnCommand(edge_buf)
  assertEqInt(resNom.commands.len(), 1, "recordSpawnCommand nominal resNom.commands.len() == 1")
  assertEqInt(resEdge.commands.len(), 1, "recordSpawnCommand boundary resEdge.commands.len() == 1")
  ret 0
```

---

### `recordDespawnCommand` (`std/ecs/ecs_command.aipl`)

- **Signature**: `pub fn recordDespawnCommand(buf: EcsCommandBuffer, entity: EntityId): EcsCommandBuffer:`
- **Import**: `import * from "std/ecs/ecs_command"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `buf: EcsCommandBuffer, entity: EntityId` | **Returns**: `EcsCommandBuffer`
- **Unit Test**: `tests/functions/ecs/ecs_command_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests deferred ECS command buffering (`spawn`, `despawn`, `addComponent`) and end-of-stage `flushCommandBuffer` execution in `recordDespawnCommand`. Concrete nominal inputs: `buf: EcsCommandBuffer = EcsCommandBuffer(commands = [EcsCommand(cmdType = 0, targetEntity = 0, paramId = 0, paramValue = 0)])`, `entity: EntityId = EntityId(index = 0, generation = 1)`; exercises core body path returning/computing `EcsCommandBuffer(commands = cmds)`.

```aipl
module tests.functions.ecs.ecs_command_z3_test
import * from "std/ecs/ecs_command"
import { EntityId } from "std/ecs/entity"
import { EcsWorld, spawnEntity, despawnEntity } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_command_recordDespawnCommand_3(): int:
  let arg_buf = EcsCommandBuffer(commands = [])
  let edge_buf = EcsCommandBuffer(commands = [])
  let arg_entity = EntityId(index = 0, generation = 4)
  let edge_entity = EntityId(index = 0, generation = 1)
  let resNom = recordDespawnCommand(arg_buf, arg_entity)
  let resEdge = recordDespawnCommand(edge_buf, edge_entity)
  assertEqInt(resNom.commands.len(), 1, "recordDespawnCommand nominal resNom.commands.len() == 1")
  assertEqInt(resEdge.commands.len(), 1, "recordDespawnCommand boundary resEdge.commands.len() == 1")
  ret 0
```

---

### `flushCommandBuffer` (`std/ecs/ecs_command.aipl`)

- **Signature**: `pub fn flushCommandBuffer(world: EcsWorld, buf: EcsCommandBuffer): EcsWorld:`
- **Import**: `import * from "std/ecs/ecs_command"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, buf: EcsCommandBuffer` | **Returns**: `EcsWorld`
- **Unit Test**: `tests/functions/ecs/ecs_command_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests deferred ECS command buffering (`spawn`, `despawn`, `addComponent`) and end-of-stage `flushCommandBuffer` execution in `flushCommandBuffer`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `buf: EcsCommandBuffer = EcsCommandBuffer(commands = [EcsCommand(cmdType = 0, targetEntity = 0, paramId = 0, paramValue = 0)])`; exercises core body path returning/computing `curWorld`.

```aipl
module tests.functions.ecs.ecs_command_z4_test
import * from "std/ecs/ecs_command"
import { EntityId } from "std/ecs/entity"
import { EcsWorld, spawnEntity, despawnEntity } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_command_flushCommandBuffer_4(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_buf = EcsCommandBuffer(commands = [])
  let edge_buf = EcsCommandBuffer(commands = [])
  let resNom = flushCommandBuffer(arg_world, arg_buf)
  let resEdge = flushCommandBuffer(edge_world, edge_buf)
  assertEqInt(resNom.archetypes.len(), 0, "flushCommandBuffer nominal resNom.archetypes.len() == 0")
  assertEqInt(resEdge.archetypes.len(), 0, "flushCommandBuffer boundary resEdge.archetypes.len() == 0")
  ret 0
```

---

### `createEventBus` (`std/ecs/ecs_event.aipl`)

- **Signature**: `pub fn createEventBus(): EventBus:`
- **Import**: `import * from "std/ecs/ecs_event"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `EventBus`
- **Unit Test**: `tests/functions/ecs/ecs_event_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Verifies double-buffered ECS event bus publishing, reading, and frame-boundary queue swapping in `createEventBus`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `EventBus(currentQueue = curr, previousQueue = prev)`.

```aipl
module tests.functions.ecs.ecs_event_z1_test
import * from "std/ecs/ecs_event"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_event_createEventBus_1(): int:
  let resNom = createEventBus()
  let resEdge = createEventBus()
  assertEqInt(resNom.currentQueue.len(), 0, "createEventBus nominal resNom.currentQueue.len() == 0")
  assertEqInt(resEdge.currentQueue.len(), 0, "createEventBus boundary resEdge.currentQueue.len() == 0")
  ret 0
```

---

### `publishEvent` (`std/ecs/ecs_event.aipl`)

- **Signature**: `pub fn publishEvent(bus: EventBus, ev: EventEnvelope): EventBus:`
- **Import**: `import * from "std/ecs/ecs_event"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bus: EventBus, ev: EventEnvelope` | **Returns**: `EventBus`
- **Unit Test**: `tests/functions/ecs/ecs_event_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Verifies double-buffered ECS event bus publishing, reading, and frame-boundary queue swapping in `publishEvent`. Concrete nominal inputs: `bus: EventBus = EventBus(currentQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)], previousQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)])`, `ev: EventEnvelope = EventEnvelope(eventTypeId = 1, sourceEntityIndex = 0, payloadA = 1.0, payloadB = 1.0)`; exercises core body path returning/computing `EventBus(currentQueue = curr, previousQueue = bus.previousQueue)`.

```aipl
module tests.functions.ecs.ecs_event_z2_test
import * from "std/ecs/ecs_event"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_event_publishEvent_2(): int:
  let arg_bus = EventBus(currentQueue = [], previousQueue = [])
  let edge_bus = EventBus(currentQueue = [], previousQueue = [])
  let arg_ev = EventEnvelope(eventTypeId = 4, sourceEntityIndex = 4, payloadA = 0.0, payloadB = 0.0)
  let edge_ev = EventEnvelope(eventTypeId = 1, sourceEntityIndex = 1, payloadA = 0.0, payloadB = 0.0)
  let resNom = publishEvent(arg_bus, arg_ev)
  let resEdge = publishEvent(edge_bus, edge_ev)
  assertEqInt(resNom.currentQueue.len(), 1, "publishEvent nominal resNom.currentQueue.len() == 1")
  assertEqInt(resEdge.currentQueue.len(), 1, "publishEvent boundary resEdge.currentQueue.len() == 1")
  ret 0
```

---

### `swapEventBuffers` (`std/ecs/ecs_event.aipl`)

- **Signature**: `pub fn swapEventBuffers(bus: EventBus): EventBus:`
- **Import**: `import * from "std/ecs/ecs_event"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bus: EventBus` | **Returns**: `EventBus`
- **Unit Test**: `tests/functions/ecs/ecs_event_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Verifies double-buffered ECS event bus publishing, reading, and frame-boundary queue swapping in `swapEventBuffers`. Concrete nominal inputs: `bus: EventBus = EventBus(currentQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)], previousQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)])`; exercises core body path returning/computing `EventBus(currentQueue = freshCurr, previousQueue = bus.currentQueue)`.

```aipl
module tests.functions.ecs.ecs_event_z3_test
import * from "std/ecs/ecs_event"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_event_swapEventBuffers_3(): int:
  let arg_bus = EventBus(currentQueue = [], previousQueue = [])
  let edge_bus = EventBus(currentQueue = [], previousQueue = [])
  let resNom = swapEventBuffers(arg_bus)
  let resEdge = swapEventBuffers(edge_bus)
  assertEqInt(resNom.currentQueue.len(), 0, "swapEventBuffers nominal resNom.currentQueue.len() == 0")
  assertEqInt(resEdge.currentQueue.len(), 0, "swapEventBuffers boundary resEdge.currentQueue.len() == 0")
  ret 0
```

---

### `readNewEvents` (`std/ecs/ecs_event.aipl`)

- **Signature**: `pub fn readNewEvents(bus: EventBus, reader: EventReader, eventTypeId: int): ([EventEnvelope], EventReader):`
- **Import**: `import * from "std/ecs/ecs_event"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bus: EventBus, reader: EventReader, eventTypeId: int` | **Returns**: `([EventEnvelope], EventReader)`
- **Unit Test**: `tests/functions/ecs/ecs_event_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Verifies double-buffered ECS event bus publishing, reading, and frame-boundary queue swapping in `readNewEvents`. Concrete nominal inputs: `bus: EventBus = EventBus(currentQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)], previousQueue = [EventEnvelope(eventTypeId = 0, sourceEntityIndex = 0, payloadA = 0, payloadB = 0)])`, `reader: EventReader = EventReader(readCursorPrev = 1, readCursorCurr = 1)`, `eventTypeId: int): ([EventEnvelope] = int): (()`, `EventReader: any = 42`; exercises core body path returning/computing `(`.

```aipl
module tests.functions.ecs.ecs_event_z4_test
import * from "std/ecs/ecs_event"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_event_readNewEvents_4(): int:
  let arg_bus = EventBus(currentQueue = [], previousQueue = [])
  let edge_bus = EventBus(currentQueue = [], previousQueue = [])
  let arg_reader = EventReader(readCursorPrev = 2, readCursorCurr = 2)
  let edge_reader = EventReader(readCursorPrev = 0, readCursorCurr = 0)
  let arg_eventTypeId = 4
  let edge_eventTypeId = 1
  let resNom = readNewEvents(arg_bus, arg_reader, arg_eventTypeId)
  let resEdge = readNewEvents(edge_bus, edge_reader, edge_eventTypeId)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.len(), 0, "readNewEvents nominal n_t0.len() == 0")
  assertEqInt(e_t0.len(), 0, "readNewEvents boundary e_t0.len() == 0")
  ret 0
```

---

### `matchesQueryFilter` (`std/ecs/ecs_query.aipl`)

- **Signature**: `pub fn matchesQueryFilter(archetypeMask: int, filter: QueryFilter): bool:`
- **Import**: `import * from "std/ecs/ecs_query"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `archetypeMask: int, filter: QueryFilter` | **Returns**: `bool`
- **Unit Test**: `tests/functions/ecs/ecs_query_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Verifies bitmask component query matching (`withMask` inclusion and `withoutMask` exclusion) in `matchesQueryFilter`. Concrete nominal inputs: `archetypeMask: int = 1`, `filter: QueryFilter = QueryFilter(withMask = 1, withoutMask = 1)`; exercises core body path returning/computing `hasAllWith and (not hasAnyWithout)`.

```aipl
module tests.functions.ecs.ecs_query_z1_test
import * from "std/ecs/ecs_query"
import { EntityId } from "std/ecs/entity"
import { ArchetypeTable } from "std/ecs/archetype"
import { EcsWorld } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_query_matchesQueryFilter_1(): int:
  let arg_archetypeMask = 4
  let edge_archetypeMask = 1
  let arg_filter = QueryFilter(withMask = 4, withoutMask = 4)
  let edge_filter = QueryFilter(withMask = 1, withoutMask = 1)
  let resNom = matchesQueryFilter(arg_archetypeMask, arg_filter)
  let resEdge = matchesQueryFilter(edge_archetypeMask, edge_filter)
  assert(resNom == false, "matchesQueryFilter nominal resNom == false")
  assert(resEdge == false, "matchesQueryFilter boundary resEdge == false")
  ret 0
```

---

### `findMatchingArchetypes` (`std/ecs/ecs_query.aipl`)

- **Signature**: `pub fn findMatchingArchetypes(world: EcsWorld, filter: QueryFilter): [int]:`
- **Import**: `import * from "std/ecs/ecs_query"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, filter: QueryFilter` | **Returns**: `[int]`
- **Unit Test**: `tests/functions/ecs/ecs_query_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Verifies bitmask component query matching (`withMask` inclusion and `withoutMask` exclusion) in `findMatchingArchetypes`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `filter: QueryFilter = QueryFilter(withMask = 1, withoutMask = 1)`; exercises core body path returning/computing `matched`.

```aipl
module tests.functions.ecs.ecs_query_z2_test
import * from "std/ecs/ecs_query"
import { EntityId } from "std/ecs/entity"
import { ArchetypeTable } from "std/ecs/archetype"
import { EcsWorld } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_query_findMatchingArchetypes_2(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_filter = QueryFilter(withMask = 4, withoutMask = 4)
  let edge_filter = QueryFilter(withMask = 1, withoutMask = 1)
  let resNom = findMatchingArchetypes(arg_world, arg_filter)
  let resEdge = findMatchingArchetypes(edge_world, edge_filter)
  assertEqInt(resNom.len(), 0, "findMatchingArchetypes nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "findMatchingArchetypes boundary resEdge.len() == 0")
  ret 0
```

---

### `queryEntities` (`std/ecs/ecs_query.aipl`)

- **Signature**: `pub fn queryEntities(world: EcsWorld, filter: QueryFilter): [EntityId]:`
- **Import**: `import * from "std/ecs/ecs_query"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, filter: QueryFilter` | **Returns**: `[EntityId]`
- **Unit Test**: `tests/functions/ecs/ecs_query_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Verifies bitmask component query matching (`withMask` inclusion and `withoutMask` exclusion) in `queryEntities`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `filter: QueryFilter = QueryFilter(withMask = 1, withoutMask = 1)`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.ecs.ecs_query_z3_test
import * from "std/ecs/ecs_query"
import { EntityId } from "std/ecs/entity"
import { ArchetypeTable } from "std/ecs/archetype"
import { EcsWorld } from "std/ecs/ecs_world"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_query_queryEntities_3(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_filter = QueryFilter(withMask = 4, withoutMask = 4)
  let edge_filter = QueryFilter(withMask = 1, withoutMask = 1)
  let resNom = queryEntities(arg_world, arg_filter)
  let resEdge = queryEntities(edge_world, edge_filter)
  assertEqInt(resNom.len(), 0, "queryEntities nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "queryEntities boundary resEdge.len() == 0")
  ret 0
```

---

### `systemsConflict` (`std/ecs/ecs_schedule.aipl`)

- **Signature**: `pub fn systemsConflict(a: SystemDescriptor, b: SystemDescriptor): bool:`
- **Import**: `import * from "std/ecs/ecs_schedule"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `a: SystemDescriptor, b: SystemDescriptor` | **Returns**: `bool`
- **Unit Test**: `tests/functions/ecs/ecs_schedule_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests conflict-free parallel system batch scheduling (detecting read/write and write/write component hazards) in `systemsConflict`. Concrete nominal inputs: `a: SystemDescriptor = SystemDescriptor(systemId = 1, stage = 1, readComponentMask = 1, writeComponentMask = 1, priority = 1)`, `b: SystemDescriptor = SystemDescriptor(systemId = 1, stage = 1, readComponentMask = 1, writeComponentMask = 1, priority = 1)`; exercises core body path returning/computing `aWritesWhatBReadsOrWrites or bWritesWhatAReadsOrWrites`.

```aipl
module tests.functions.ecs.ecs_schedule_z1_test
import * from "std/ecs/ecs_schedule"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_schedule_systemsConflict_1(): int:
  let arg_a = SystemDescriptor(systemId = 4, stage = 2, readComponentMask = 4, writeComponentMask = 4, priority = 1)
  let edge_a = SystemDescriptor(systemId = 1, stage = 0, readComponentMask = 1, writeComponentMask = 1, priority = 0)
  let arg_b = SystemDescriptor(systemId = 4, stage = 2, readComponentMask = 4, writeComponentMask = 4, priority = 1)
  let edge_b = SystemDescriptor(systemId = 1, stage = 0, readComponentMask = 1, writeComponentMask = 1, priority = 0)
  let resNom = systemsConflict(arg_a, arg_b)
  let resEdge = systemsConflict(edge_a, edge_b)
  assert(resNom == true, "systemsConflict nominal resNom == true")
  assert(resEdge == true, "systemsConflict boundary resEdge == true")
  ret 0
```

---

### `sortSystemsByPriority` (`std/ecs/ecs_schedule.aipl`)

- **Signature**: `pub fn sortSystemsByPriority(systems: [SystemDescriptor], stage: int): [SystemDescriptor]:`
- **Import**: `import * from "std/ecs/ecs_schedule"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `systems: [SystemDescriptor], stage: int` | **Returns**: `[SystemDescriptor]`
- **Unit Test**: `tests/functions/ecs/ecs_schedule_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests conflict-free parallel system batch scheduling (detecting read/write and write/write component hazards) in `sortSystemsByPriority`. Concrete nominal inputs: `systems: [SystemDescriptor] = [SystemDescriptor(systemId = 1, stage = 1, readComponentMask = 1, writeComponentMask = 1, priority = 1)]`, `stage: int = 1`; exercises core body path returning/computing `stageSys`.

```aipl
module tests.functions.ecs.ecs_schedule_z2_test
import * from "std/ecs/ecs_schedule"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_schedule_sortSystemsByPriority_2(): int:
  let arg_systems = [SystemDescriptor(systemId = 4, stage = 2, readComponentMask = 4, writeComponentMask = 4, priority = 1)]
  let edge_systems = []
  let arg_stage = 2
  let edge_stage = 0
  let resNom = sortSystemsByPriority(arg_systems, arg_stage)
  let resEdge = sortSystemsByPriority(edge_systems, edge_stage)
  assertEqInt(resNom.len(), 1, "sortSystemsByPriority nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "sortSystemsByPriority boundary resEdge.len() == 0")
  ret 0
```

---

### `buildParallelBatches` (`std/ecs/ecs_schedule.aipl`)

- **Signature**: `pub fn buildParallelBatches(sortedSystems: [SystemDescriptor]): [[int]]:`
- **Import**: `import * from "std/ecs/ecs_schedule"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `sortedSystems: [SystemDescriptor]` | **Returns**: `[[int]]`
- **Unit Test**: `tests/functions/ecs/ecs_schedule_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Tests conflict-free parallel system batch scheduling (detecting read/write and write/write component hazards) in `buildParallelBatches`. Concrete nominal inputs: `sortedSystems: [SystemDescriptor] = [SystemDescriptor(systemId = 1, stage = 1, readComponentMask = 1, writeComponentMask = 1, priority = 1)]`; exercises core body path returning/computing `batches`.

```aipl
module tests.functions.ecs.ecs_schedule_z3_test
import * from "std/ecs/ecs_schedule"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_schedule_buildParallelBatches_3(): int:
  let arg_sortedSystems = [SystemDescriptor(systemId = 4, stage = 2, readComponentMask = 4, writeComponentMask = 4, priority = 1)]
  let edge_sortedSystems = []
  let resNom = buildParallelBatches(arg_sortedSystems)
  let resEdge = buildParallelBatches(edge_sortedSystems)
  assertEqInt(resNom.len(), 1, "buildParallelBatches nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "buildParallelBatches boundary resEdge.len() == 0")
  ret 0
```

---

### `createEcsWorld` (`std/ecs/ecs_world.aipl`)

- **Signature**: `pub fn createEcsWorld(): EcsWorld:`
- **Import**: `import * from "std/ecs/ecs_world"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `EcsWorld`
- **Unit Test**: `tests/functions/ecs/ecs_world_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests ECS world entity lifecycle, component mask assignment, and global resource registry in `createEcsWorld`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `EcsWorld(entityPool = pool, archetypes = archs, locations = locs, resources = res)`.

```aipl
module tests.functions.ecs.ecs_world_z1_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_createEcsWorld_1(): int:
  let resNom = createEcsWorld()
  let resEdge = createEcsWorld()
  assertEqInt(resNom.archetypes.len(), 1, "createEcsWorld nominal resNom.archetypes.len() == 1")
  assertEqInt(resEdge.archetypes.len(), 1, "createEcsWorld boundary resEdge.archetypes.len() == 1")
  ret 0
```

---

### `spawnEntity` (`std/ecs/ecs_world.aipl`)

- **Signature**: `pub fn spawnEntity(world: EcsWorld): (EcsWorld, EntityId):`
- **Import**: `import * from "std/ecs/ecs_world"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld` | **Returns**: `(EcsWorld, EntityId)`
- **Unit Test**: `tests/functions/ecs/ecs_world_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests ECS world entity lifecycle, component mask assignment, and global resource registry in `spawnEntity`. Concrete nominal inputs: `world: EcsWorld): (EcsWorld = EcsWorld): (EcsWorld()`, `EntityId: any = 42`; exercises core body path returning/computing `(`.

```aipl
module tests.functions.ecs.ecs_world_z2_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_spawnEntity_2(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let resNom = spawnEntity(arg_world)
  let resEdge = spawnEntity(edge_world)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.archetypes.len(), 0, "spawnEntity nominal n_t0.archetypes.len() == 0")
  assertEqInt(e_t0.archetypes.len(), 0, "spawnEntity boundary e_t0.archetypes.len() == 0")
  ret 0
```

---

### `despawnEntity` (`std/ecs/ecs_world.aipl`)

- **Signature**: `pub fn despawnEntity(world: EcsWorld, entity: EntityId): EcsWorld:`
- **Import**: `import * from "std/ecs/ecs_world"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, entity: EntityId` | **Returns**: `EcsWorld`
- **Unit Test**: `tests/functions/ecs/ecs_world_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Tests ECS world entity lifecycle, component mask assignment, and global resource registry in `despawnEntity`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `entity: EntityId = EntityId(index = 0, generation = 1)`; exercises core body path returning/computing `EcsWorld(`.

```aipl
module tests.functions.ecs.ecs_world_z3_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_despawnEntity_3(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_entity = EntityId(index = 0, generation = 4)
  let edge_entity = EntityId(index = 0, generation = 1)
  let resNom = despawnEntity(arg_world, arg_entity)
  let resEdge = despawnEntity(edge_world, edge_entity)
  assertEqInt(resNom.archetypes.len(), 0, "despawnEntity nominal resNom.archetypes.len() == 0")
  assertEqInt(resEdge.archetypes.len(), 0, "despawnEntity boundary resEdge.archetypes.len() == 0")
  ret 0
```

---

### `setWorldResource` (`std/ecs/ecs_world.aipl`)

- **Signature**: `pub fn setWorldResource(world: EcsWorld, resourceId: int, value: float): EcsWorld:`
- **Import**: `import * from "std/ecs/ecs_world"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, resourceId: int, value: float` | **Returns**: `EcsWorld`
- **Unit Test**: `tests/functions/ecs/ecs_world_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests ECS world entity lifecycle, component mask assignment, and global resource registry in `setWorldResource`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `resourceId: int = 1`, `value: float = 1.0`; exercises core body path returning/computing `EcsWorld(`.

```aipl
module tests.functions.ecs.ecs_world_z4_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_setWorldResource_4(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_resourceId = 1
  let edge_resourceId = 0
  let arg_value = 1.0
  let edge_value = 0.5
  let resNom = setWorldResource(arg_world, arg_resourceId, arg_value)
  let resEdge = setWorldResource(edge_world, edge_resourceId, edge_value)
  assertEqInt(resNom.archetypes.len(), 0, "setWorldResource nominal resNom.archetypes.len() == 0")
  assertEqInt(resEdge.archetypes.len(), 0, "setWorldResource boundary resEdge.archetypes.len() == 0")
  ret 0
```

---

### `getWorldResource` (`std/ecs/ecs_world.aipl`)

- **Signature**: `pub fn getWorldResource(world: EcsWorld, resourceId: int): Option[float]:`
- **Import**: `import * from "std/ecs/ecs_world"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `world: EcsWorld, resourceId: int` | **Returns**: `Option[float]`
- **Unit Test**: `tests/functions/ecs/ecs_world_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests ECS world entity lifecycle, component mask assignment, and global resource registry in `getWorldResource`. Concrete nominal inputs: `world: EcsWorld = EcsWorld(entityPool = EntityPool(generations = [0], alive = [0], freeIndices = [0]), archetypes = [ArchetypeTable(signatureMask = 0, entities = 0, columns = 0)], locations = [EntityLocation(archetypeIndex = 0, rowIndex = 0)], resources = [1.0])`, `resourceId: int = 1`; exercises core body path returning/computing `Some(world.resources[resourceId])`.

```aipl
module tests.functions.ecs.ecs_world_z5_test
import * from "std/ecs/ecs_world"
import { EntityId, EntityPool, createEntityPool, allocateEntity, recycleEntity, isEntityAlive } from "std/ecs/entity"
import { ArchetypeTable, createArchetypeTable, insertArchetypeRow, swapRemoveArchetypeRow } from "std/ecs/archetype"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_ecs_world_getWorldResource_5(): int:
  let arg_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let edge_world = EcsWorld(entityPool = EntityPool(generations = [], alive = [], freeIndices = []), archetypes = [], locations = [], resources = [])
  let arg_resourceId = 1
  let edge_resourceId = 0
  let resNom = getWorldResource(arg_world, arg_resourceId)
  let resEdge = getWorldResource(edge_world, edge_resourceId)
  assert(resNom.isSome() == false, "getWorldResource nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "getWorldResource boundary resEdge.isSome() == false")
  ret 0
```

---

### `createEntityPool` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn createEntityPool(): EntityPool:`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `EntityPool`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `createEntityPool`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `EntityPool(generations = gens, alive = alv, freeIndices = free)`.

```aipl
module tests.functions.ecs.entity_z1_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_createEntityPool_1(): int:
  let resNom = createEntityPool()
  let resEdge = createEntityPool()
  assertEqInt(resNom.generations.len(), 0, "createEntityPool nominal resNom.generations.len() == 0")
  assertEqInt(resEdge.generations.len(), 0, "createEntityPool boundary resEdge.generations.len() == 0")
  ret 0
```

---

### `allocateEntity` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn allocateEntity(pool: EntityPool): (EntityPool, EntityId):`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: EntityPool` | **Returns**: `(EntityPool, EntityId)`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `allocateEntity`. Concrete nominal inputs: `pool: EntityPool): (EntityPool = EntityPool): (EntityPool()`, `EntityId: any = 42`; exercises core body path returning/computing `(`.

```aipl
module tests.functions.ecs.entity_z2_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_allocateEntity_2(): int:
  let arg_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let edge_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let resNom = allocateEntity(arg_pool)
  let resEdge = allocateEntity(edge_pool)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.generations.len(), 1, "allocateEntity nominal n_t0.generations.len() == 1")
  assertEqInt(e_t0.generations.len(), 1, "allocateEntity boundary e_t0.generations.len() == 1")
  ret 0
```

---

### `recycleEntity` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn recycleEntity(pool: EntityPool, id: EntityId): EntityPool:`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: EntityPool, id: EntityId` | **Returns**: `EntityPool`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `recycleEntity`. Concrete nominal inputs: `pool: EntityPool = EntityPool(generations = [1], alive = [true], freeIndices = [1])`, `id: EntityId = EntityId(index = 0, generation = 1)`; exercises core body path returning/computing `EntityPool(generations = gens, alive = alv, freeIndices = free)`.

```aipl
module tests.functions.ecs.entity_z3_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_recycleEntity_3(): int:
  let arg_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let edge_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let arg_id = EntityId(index = 0, generation = 4)
  let edge_id = EntityId(index = 0, generation = 1)
  let resNom = recycleEntity(arg_pool, arg_id)
  let resEdge = recycleEntity(edge_pool, edge_id)
  assertEqInt(resNom.generations.len(), 0, "recycleEntity nominal resNom.generations.len() == 0")
  assertEqInt(resEdge.generations.len(), 0, "recycleEntity boundary resEdge.generations.len() == 0")
  ret 0
```

---

### `isEntityAlive` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn isEntityAlive(pool: EntityPool, id: EntityId): bool:`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: EntityPool, id: EntityId` | **Returns**: `bool`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_204_ecs_query_filter_radar_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `isEntityAlive`. Concrete nominal inputs: `pool: EntityPool = EntityPool(generations = [1], alive = [true], freeIndices = [1])`, `id: EntityId = EntityId(index = 0, generation = 1)`; exercises core body path returning/computing `pool.alive[id.index] and pool.generations[id.index] == id.generation`.

```aipl
module tests.functions.ecs.entity_z4_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_isEntityAlive_4(): int:
  let arg_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let edge_pool = EntityPool(generations = [], alive = [], freeIndices = [])
  let arg_id = EntityId(index = 0, generation = 4)
  let edge_id = EntityId(index = 0, generation = 1)
  let resNom = isEntityAlive(arg_pool, arg_id)
  let resEdge = isEntityAlive(edge_pool, edge_id)
  assert(resNom == false, "isEntityAlive nominal resNom == false")
  assert(resEdge == false, "isEntityAlive boundary resEdge == false")
  ret 0
```

---

### `packEntityU64` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn packEntityU64(id: EntityId): int:`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `id: EntityId` | **Returns**: `int`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_202_ecs_entity_generational_arena_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `packEntityU64`. Concrete nominal inputs: `id: EntityId = EntityId(index = 0, generation = 1)`; exercises core body path returning/computing `(id.generation << 32) | (id.index & 4294967295)`.

```aipl
module tests.functions.ecs.entity_z5_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_packEntityU64_5(): int:
  let arg_id = EntityId(index = 0, generation = 4)
  let edge_id = EntityId(index = 0, generation = 1)
  let resNom = packEntityU64(arg_id)
  let resEdge = packEntityU64(edge_id)
  assertEqInt(resNom, 17179869184, "packEntityU64 nominal resNom == 17179869184")
  assertEqInt(resEdge, 4294967296, "packEntityU64 boundary resEdge == 4294967296")
  ret 0
```

---

### `unpackEntityU64` (`std/ecs/entity.aipl`)

- **Signature**: `pub fn unpackEntityU64(packed: int): EntityId:`
- **Import**: `import * from "std/ecs/entity"` (or barrel `import * from "std/ecs/ecs_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `packed: int` | **Returns**: `EntityId`
- **Unit Test**: `tests/functions/ecs/entity_test.aipl` | **Example**: `examples/ex_203_ecs_archetype_table_migration_window.aipl`
- **Behavioral Summary**: Tests generational entity handle allocation, recycling, liveness checking, and 64-bit bit-packing in `unpackEntityU64`. Concrete nominal inputs: `packed: int = 1`; exercises core body path returning/computing `EntityId(index = idx, generation = gen)`.

```aipl
module tests.functions.ecs.entity_z6_test
import * from "std/ecs/entity"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_entity_unpackEntityU64_6(): int:
  let arg_packed = 4
  let edge_packed = 1
  let resNom = unpackEntityU64(arg_packed)
  let resEdge = unpackEntityU64(edge_packed)
  assertEqInt(resNom.index, 4, "unpackEntityU64 nominal resNom.index == 4")
  assertEqInt(resEdge.index, 1, "unpackEntityU64 boundary resEdge.index == 1")
  ret 0
```
