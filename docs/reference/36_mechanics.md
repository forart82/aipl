[Home](../../README.md) | [Docs Index](../INDEX.md) | [Tutorials](../TUTORIAL.md) | [Cookbook](../COOKBOOK.md) | [Stdlib Reference](STDLIB_REFERENCE.md) | [CLI Reference](../CLI_REFERENCE.md)

# Domain 36: `mechanics` API Reference

> Complete API reference manual for AIPL standard library domain `mechanics` (95 callable functions & methods across ["std/mechanics/attribute_pipeline.aipl", "std/mechanics/dialogue_dag.aipl", "std/mechanics/economy_ledger.aipl", "std/mechanics/inventory_container.aipl", "std/mechanics/mechanics_mod.aipl"]).

## 1. Domain Overview & Source Modules

- **Domain Name**: `mechanics`
- **Target Source Modules**: ["std/mechanics/attribute_pipeline.aipl", "std/mechanics/dialogue_dag.aipl", "std/mechanics/economy_ledger.aipl", "std/mechanics/inventory_container.aipl", "std/mechanics/mechanics_mod.aipl"]
- **Total Callable Functions & Methods**: 95
- **Total Data Types (`struct` & `enum`)**: 23
- **Master Reference Hub**: [STDLIB_REFERENCE.md](STDLIB_REFERENCE.md)

---

## 2. Domain Data Types (`struct` & `enum`)

(23 public types declared across this domain's modules)

| Type Name | Kind | Source Module | Fields / Variants | Default Constructor / Description |
| :--- | :--- | :--- | :--- | :--- |
| `ModifierStage` | `pub enum` | `std/mechanics/attribute_pipeline.aipl` | `FlatAdd`, `PercentAdd`, `FinalMultiply` | Algebraic Enum (3 variants) |
| `StatModifier` | `pub struct` | `std/mechanics/attribute_pipeline.aipl` | `id: int`, `statTag: str`, `stage: ModifierStage`, `value: float`, `durationRemaining: float`, `isPermanent: bool` | `StatModifier(id, statTag, stage, value, durationRemaining, isPermanent)` |
| `AttributePool` | `pub struct` | `std/mechanics/attribute_pipeline.aipl` | `current: float`, `baseMax: float`, `regenRatePerSec: float` | `AttributePool(current, baseMax, regenRatePerSec)` |
| `StatusEffectTicker` | `pub struct` | `std/mechanics/attribute_pipeline.aipl` | `effectTag: str`, `tickInterval: float`, `tickTimer: float`, `totalDuration: float`, `valuePerTick: float` | `StatusEffectTicker(effectTag, tickInterval, tickTimer, totalDuration, valuePerTick)` |
| `DagNode` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `id: int`, `rank: int`, `maxRank: int`, `prereqId: int`, `prereqMinRank: int`, `unlocked: bool` | `DagNode(id, rank, maxRank, prereqId, prereqMinRank, unlocked)` |
| `DialogueChoice` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `choiceId: int`, `text: str`, `targetNodeId: int`, `requiredFlags: [str]` | `DialogueChoice(choiceId, text, targetNodeId, requiredFlags)` |
| `DialogueNode` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `nodeId: int`, `speaker: str`, `content: str`, `choices: [DialogueChoice]` | `DialogueNode(nodeId, speaker, content, choices)` |
| `DialogueGraph` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `startNodeId: int`, `nodes: [DialogueNode]` | `DialogueGraph(startNodeId, nodes)` |
| `ObjectivePrereqLink` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `task: str`, `requiredPrereq: str` | `ObjectivePrereqLink(task, requiredPrereq)` |
| `ObjectiveDependencyDAG` | `pub struct` | `std/mechanics/dialogue_dag.aipl` | `links: [ObjectivePrereqLink]`, `completedTasks: [str]` | `ObjectiveDependencyDAG(links, completedTasks)` |
| `ResourceLedger` | `pub struct` | `std/mechanics/economy_ledger.aipl` | `accounts: Map[str`, `int]` | `ResourceLedger(accounts, int])` |
| `TaxBracketTier` | `pub struct` | `std/mechanics/economy_ledger.aipl` | `threshold: int`, `ratePct: float` | `TaxBracketTier(threshold, ratePct)` |
| `ProgressiveTaxBracket` | `pub struct` | `std/mechanics/economy_ledger.aipl` | `tiers: [TaxBracketTier]` | `ProgressiveTaxBracket(tiers)` |
| `CraftingIngredient` | `pub struct` | `std/mechanics/economy_ledger.aipl` | `itemTag: str`, `amount: int` | `CraftingIngredient(itemTag, amount)` |
| `CraftingRecipe` | `pub struct` | `std/mechanics/economy_ledger.aipl` | `recipeId: str`, `inputs: [CraftingIngredient]`, `outputs: [CraftingIngredient]`, `craftDurationSec: float` | `CraftingRecipe(recipeId, inputs, outputs, craftDurationSec)` |
| `InventorySlot` | `pub struct` | `std/mechanics/inventory_container.aipl` | `itemId: int`, `quantity: int`, `maxStack: int`, `flags: int` | `InventorySlot(itemId, quantity, maxStack, flags)` |
| `InventoryContainer` | `pub struct` | `std/mechanics/inventory_container.aipl` | `width: int`, `height: int`, `slots: [InventorySlot]` | `InventoryContainer(width, height, slots)` |
| `ModifierPoolEntry` | `pub struct` | `std/mechanics/inventory_container.aipl` | `id: int`, `weight: int`, `minValue: int`, `maxValue: int` | `ModifierPoolEntry(id, weight, minValue, maxValue)` |
| `InventoryItem` | `pub struct` | `std/mechanics/inventory_container.aipl` | `id: int`, `itemTag: str`, `quantity: int`, `maxStack: int`, `gridWidth: int`, `gridHeight: int`, `unitWeight: float` | `InventoryItem(id, itemTag, quantity, maxStack, gridWidth, gridHeight, unitWeight)` |
| `SlotListContainer` | `pub struct` | `std/mechanics/inventory_container.aipl` | `capacity: int`, `slots: [InventoryItem]` | `SlotListContainer(capacity, slots)` |
| `SpatialMatrixContainer2D` | `pub struct` | `std/mechanics/inventory_container.aipl` | `cols: int`, `rows: int`, `occupiedGrid: [int]`, `items: [InventoryItem]` | `SpatialMatrixContainer2D(cols, rows, occupiedGrid, items)` |
| `WeightedLootEntry` | `pub struct` | `std/mechanics/inventory_container.aipl` | `itemTag: str`, `weight: float`, `minQuantity: int`, `maxQuantity: int` | `WeightedLootEntry(itemTag, weight, minQuantity, maxQuantity)` |
| `WeightedLootTable` | `pub struct` | `std/mechanics/inventory_container.aipl` | `entries: [WeightedLootEntry]`, `totalWeight: float` | `WeightedLootTable(entries, totalWeight)` |

## 3. Quick-Lookup Function Index


| # | Source Module | Function / Method | Exact Signature | Unit Test File |
| :--- | :--- | :--- | :--- | :--- |
| `1` | `std/mechanics/attribute_pipeline.aipl` | `evalStatModifierStack` | `pub fn evalStatModifierStack(baseValue: float, modifiers: [StatModifier]): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `2` | `std/mechanics/attribute_pipeline.aipl` | `computeFractionalCurrentHpDamage` | `pub fn computeFractionalCurrentHpDamage(currentHp: float, fraction: float): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `3` | `std/mechanics/attribute_pipeline.aipl` | `computeDamageOverTimeTick` | `pub fn computeDamageOverTimeTick(baseDps: float, dt: float): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `4` | `std/mechanics/attribute_pipeline.aipl` | `computeCooldownWithReduction` | `pub fn computeCooldownWithReduction(baseCooldown: float, cdrPercent: float): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `5` | `std/mechanics/attribute_pipeline.aipl` | `computeLinearScaledCost` | `pub fn computeLinearScaledCost(baseCost: int, scaleLevel: int, growthFactor: float): int:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `6` | `std/mechanics/attribute_pipeline.aipl` | `attributePoolNew` | `pub fn attributePoolNew(baseMax: float, regenRatePerSec: float = 0.0): AttributePool:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `7` | `std/mechanics/attribute_pipeline.aipl` | `attributePoolStepRegen` | `pub fn attributePoolStepRegen(pool: AttributePool, dt: float): AttributePool:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `8` | `std/mechanics/attribute_pipeline.aipl` | `attributePoolSpend` | `pub fn attributePoolSpend(pool: AttributePool, cost: float): (AttributePool, bool):` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `9` | `std/mechanics/attribute_pipeline.aipl` | `attributePoolRestore` | `pub fn attributePoolRestore(pool: AttributePool, amount: float): AttributePool:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `10` | `std/mechanics/attribute_pipeline.aipl` | `attributePoolRatio` | `pub fn attributePoolRatio(pool: AttributePool): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `11` | `std/mechanics/attribute_pipeline.aipl` | `statusEffectTickerNew` | `pub fn statusEffectTickerNew(effectTag: str, tickInterval: float, totalDuration: float, valuePerTick: float): StatusEffectTicker:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `12` | `std/mechanics/attribute_pipeline.aipl` | `statusEffectTickerStep` | `pub fn statusEffectTickerStep(ticker: StatusEffectTicker, dt: float): (StatusEffectTicker, int, float):` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `13` | `std/mechanics/attribute_pipeline.aipl` | `statusEffectIsExpired` | `pub fn statusEffectIsExpired(ticker: StatusEffectTicker): bool:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `14` | `std/mechanics/attribute_pipeline.aipl` | `stepStatModifierDurations` | `pub fn stepStatModifierDurations(modifiers: [StatModifier], dt: float): [StatModifier]:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `15` | `std/mechanics/attribute_pipeline.aipl` | `filterStatModifiersByTag` | `pub fn filterStatModifiersByTag(modifiers: [StatModifier], statTag: str): [StatModifier]:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `16` | `std/mechanics/attribute_pipeline.aipl` | `computeArmorMitigationRatio` | `pub fn computeArmorMitigationRatio(armorRating: float, halfMitigationConstant: float = 100.0): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `17` | `std/mechanics/attribute_pipeline.aipl` | `applyMitigatedDamage` | `pub fn applyMitigatedDamage(rawDamage: float, armorRating: float, flatBlock: float = 0.0): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `18` | `std/mechanics/attribute_pipeline.aipl` | `computeCriticalStrikeMultiplier` | `pub fn computeCriticalStrikeMultiplier(baseDamage: float, isCrit: bool, critBonusRatio: float = 1.0): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `19` | `std/mechanics/attribute_pipeline.aipl` | `computeDiminishingReturns` | `pub fn computeDiminishingReturns(rawBonus: float, softCap: float): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `20` | `std/mechanics/attribute_pipeline.aipl` | `computeExponentialLevelXp` | `pub fn computeExponentialLevelXp(level: int, baseXp: int, growthRate: float = 0.25): int:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `21` | `std/mechanics/attribute_pipeline.aipl` | `computeAttributeSoftCap` | `pub fn computeAttributeSoftCap(val: float, capThreshold: float, postCapEfficiency: float = 0.5): float:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `22` | `std/mechanics/attribute_pipeline.aipl` | `rollWeightedIndex` | `pub fn rollWeightedIndex(weights: [int], rollVal: int): int:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `23` | `std/mechanics/attribute_pipeline.aipl` | `rollAttributeRange` | `pub fn rollAttributeRange(minValue: int, maxValue: int, rollRatio: float): int:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `24` | `std/mechanics/attribute_pipeline.aipl` | `rollItemAffixBonus` | `pub fn rollItemAffixBonus(baseStat: int, tier: int, qualityMult: float): int:` | `tests/functions/mechanics/attribute_pipeline_test.aipl` |
| `25` | `std/mechanics/dialogue_dag.aipl` | `dialogueGraphNew` | `pub fn dialogueGraphNew(startNodeId: int): DialogueGraph:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `26` | `std/mechanics/dialogue_dag.aipl` | `dialogueAddNode` | `pub fn dialogueAddNode(mut graph: DialogueGraph, node: DialogueNode): void:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `27` | `std/mechanics/dialogue_dag.aipl` | `dialogueNodeCount` | `pub fn dialogueNodeCount(graph: DialogueGraph): int:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `28` | `std/mechanics/dialogue_dag.aipl` | `dialogueFindNode` | `pub fn dialogueFindNode(graph: DialogueGraph, nodeId: int): Option[DialogueNode]:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `29` | `std/mechanics/dialogue_dag.aipl` | `hasFlagInSlice` | `fn hasFlagInSlice(flags: [str], target: str): bool:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `30` | `std/mechanics/dialogue_dag.aipl` | `dialogueGetAvailableChoices` | `pub fn dialogueGetAvailableChoices(graph: DialogueGraph, nodeId: int, activeFlags: [str]): [DialogueChoice]:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `31` | `std/mechanics/dialogue_dag.aipl` | `dialogueAdvanceChoice` | `pub fn dialogueAdvanceChoice(graph: DialogueGraph, currentNodeId: int, choiceId: int, activeFlags: [str]): Option[DialogueNode]:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `32` | `std/mechanics/dialogue_dag.aipl` | `objectiveDagNew` | `pub fn objectiveDagNew(): ObjectiveDependencyDAG:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `33` | `std/mechanics/dialogue_dag.aipl` | `objectiveAddPrerequisite` | `pub fn objectiveAddPrerequisite(mut dag: ObjectiveDependencyDAG, task: str, requiredPrereq: str): void:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `34` | `std/mechanics/dialogue_dag.aipl` | `objectiveIsUnlocked` | `pub fn objectiveIsUnlocked(dag: ObjectiveDependencyDAG, task: str): bool:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `35` | `std/mechanics/dialogue_dag.aipl` | `objectiveComplete` | `pub fn objectiveComplete(mut dag: ObjectiveDependencyDAG, task: str): void:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `36` | `std/mechanics/dialogue_dag.aipl` | `objectiveIsCompleted` | `pub fn objectiveIsCompleted(dag: ObjectiveDependencyDAG, task: str): bool:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `37` | `std/mechanics/dialogue_dag.aipl` | `objectiveGetPrerequisites` | `pub fn objectiveGetPrerequisites(dag: ObjectiveDependencyDAG, task: str): [str]:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `38` | `std/mechanics/dialogue_dag.aipl` | `objectiveGetAvailableTasks` | `pub fn objectiveGetAvailableTasks(dag: ObjectiveDependencyDAG, allTasks: [str]): [str]:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `39` | `std/mechanics/dialogue_dag.aipl` | `objectiveCompletionRatio` | `pub fn objectiveCompletionRatio(dag: ObjectiveDependencyDAG, totalTaskCount: int): float:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `40` | `std/mechanics/dialogue_dag.aipl` | `dagCanUnlockNode` | `pub fn dagCanUnlockNode(node: DagNode, prereqRank: int): bool:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `41` | `std/mechanics/dialogue_dag.aipl` | `dagAdvanceNodeRank` | `pub fn dagAdvanceNodeRank(node: DagNode, pointsAvailable: int, prereqRank: int): (DagNode, int):` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `42` | `std/mechanics/dialogue_dag.aipl` | `dagCalculateTotalInvested` | `pub fn dagCalculateTotalInvested(ranks: [int]): int:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `43` | `std/mechanics/dialogue_dag.aipl` | `computeSm2NextEasiness` | `pub fn computeSm2NextEasiness(ef: float, quality: int): float:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `44` | `std/mechanics/dialogue_dag.aipl` | `computeSm2NextIntervalDays` | `pub fn computeSm2NextIntervalDays(repetition: int, prevIntervalDays: int, ef: float, quality: int): int:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `45` | `std/mechanics/dialogue_dag.aipl` | `computeApmCounter` | `pub fn computeApmCounter(validActions: int, elapsedMs: int): int:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `46` | `std/mechanics/dialogue_dag.aipl` | `selectZoneWithHysteresis` | `pub fn selectZoneWithHysteresis(currentZone: int, entityX: float, entityY: float, zonesMinX: [float], zonesMinY: [float], zonesMaxX: [float], zonesMaxY: [float], margin: float): int:` | `tests/functions/mechanics/dialogue_dag_test.aipl` |
| `47` | `std/mechanics/economy_ledger.aipl` | `resourceLedgerNew` | `pub fn resourceLedgerNew(): ResourceLedger:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `48` | `std/mechanics/economy_ledger.aipl` | `ledgerDeposit` | `pub fn ledgerDeposit(mut ledger: ResourceLedger, account: str, amount: int): void:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `49` | `std/mechanics/economy_ledger.aipl` | `ledgerGetBalance` | `pub fn ledgerGetBalance(ledger: ResourceLedger, account: str): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `50` | `std/mechanics/economy_ledger.aipl` | `ledgerHasFunds` | `pub fn ledgerHasFunds(ledger: ResourceLedger, account: str, required: int): bool:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `51` | `std/mechanics/economy_ledger.aipl` | `ledgerWithdraw` | `pub fn ledgerWithdraw(mut ledger: ResourceLedger, account: str, amount: int): bool:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `52` | `std/mechanics/economy_ledger.aipl` | `ledgerTotalSupply` | `pub fn ledgerTotalSupply(ledger: ResourceLedger): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `53` | `std/mechanics/economy_ledger.aipl` | `ledgerTransfer` | `pub fn ledgerTransfer(mut ledger: ResourceLedger, fromAccount: str, toAccount: str, amount: int): bool:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `54` | `std/mechanics/economy_ledger.aipl` | `computeTieredBracketRatePct` | `pub fn computeTieredBracketRatePct(bracket: ProgressiveTaxBracket, totalWealth: int): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `55` | `std/mechanics/economy_ledger.aipl` | `computeProgressiveTaxAmount` | `pub fn computeProgressiveTaxAmount(bracket: ProgressiveTaxBracket, grossAmount: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `56` | `std/mechanics/economy_ledger.aipl` | `computeNetAfterTax` | `pub fn computeNetAfterTax(bracket: ProgressiveTaxBracket, grossAmount: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `57` | `std/mechanics/economy_ledger.aipl` | `computeCompoundInterest` | `pub fn computeCompoundInterest(principal: float, ratePerPeriod: float, periods: int): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `58` | `std/mechanics/economy_ledger.aipl` | `computeSupplyDemandPrice` | `pub fn computeSupplyDemandPrice(basePrice: float, supply: int, demand: int, elasticity: float = 0.5): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `59` | `std/mechanics/economy_ledger.aipl` | `craftingCanFulfill` | `pub fn craftingCanFulfill(ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): bool:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `60` | `std/mechanics/economy_ledger.aipl` | `craftingMaxBatchCount` | `pub fn craftingMaxBatchCount(ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `61` | `std/mechanics/economy_ledger.aipl` | `craftingExecute` | `pub fn craftingExecute(mut ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): bool:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `62` | `std/mechanics/economy_ledger.aipl` | `computeEloRatingDelta` | `pub fn computeEloRatingDelta(ratingA: float, ratingB: float, scoreA: float, kFactor: float): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `63` | `std/mechanics/economy_ledger.aipl` | `recipeKeyCommutative2` | `pub fn recipeKeyCommutative2(idA: int, idB: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `64` | `std/mechanics/economy_ledger.aipl` | `recipeKeyCommutative3` | `pub fn recipeKeyCommutative3(idA: int, idB: int, idC: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `65` | `std/mechanics/economy_ledger.aipl` | `recipeCombinatorCommutative2` | `pub fn recipeCombinatorCommutative2(idA: int, idB: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `66` | `std/mechanics/economy_ledger.aipl` | `computeItemCombineRecipeId` | `pub fn computeItemCombineRecipeId(itemIdA: int, itemIdB: int): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `67` | `std/mechanics/economy_ledger.aipl` | `recipeOutputLevel` | `pub fn recipeOutputLevel(charLevel: int, itemLevel: int, biasRatio: float = 0.5): int:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `68` | `std/mechanics/economy_ledger.aipl` | `rateScaledCapacityPerSec` | `pub fn rateScaledCapacityPerSec(assignedUnits: int, unitRate: float, tierMult: float): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `69` | `std/mechanics/economy_ledger.aipl` | `forecastMonteCarloQuantile` | `pub fn forecastMonteCarloQuantile(p50Base: float, volatilityPct: float, zScore: float): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `70` | `std/mechanics/economy_ledger.aipl` | `computeMonteCarloPercentile` | `pub fn computeMonteCarloPercentile(p50Base: float, volatilityPct: float, zScore: float): float:` | `tests/functions/mechanics/economy_ledger_test.aipl` |
| `71` | `std/mechanics/inventory_container.aipl` | `slotListNew` | `pub fn slotListNew(capacity: int): SlotListContainer:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `72` | `std/mechanics/inventory_container.aipl` | `slotListInsert` | `pub fn slotListInsert(mut container: SlotListContainer, item: InventoryItem): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `73` | `std/mechanics/inventory_container.aipl` | `slotListCountTag` | `pub fn slotListCountTag(container: SlotListContainer, itemTag: str): int:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `74` | `std/mechanics/inventory_container.aipl` | `slotListRemoveQuantity` | `pub fn slotListRemoveQuantity(mut container: SlotListContainer, itemTag: str, quantity: int): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `75` | `std/mechanics/inventory_container.aipl` | `slotListTotalWeight` | `pub fn slotListTotalWeight(container: SlotListContainer): float:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `76` | `std/mechanics/inventory_container.aipl` | `slotListFreeSlotCount` | `pub fn slotListFreeSlotCount(container: SlotListContainer): int:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `77` | `std/mechanics/inventory_container.aipl` | `spatialMatrixNew` | `pub fn spatialMatrixNew(cols: int, rows: int): SpatialMatrixContainer2D:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `78` | `std/mechanics/inventory_container.aipl` | `spatialMatrixCanFit` | `pub fn spatialMatrixCanFit(container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `79` | `std/mechanics/inventory_container.aipl` | `spatialMatrixInsert` | `pub fn spatialMatrixInsert(mut container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `80` | `std/mechanics/inventory_container.aipl` | `spatialMatrixRemoveAt` | `pub fn spatialMatrixRemoveAt(mut container: SpatialMatrixContainer2D, col: int, row: int): SpatialMatrixContainer2D:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `81` | `std/mechanics/inventory_container.aipl` | `spatialMatrixOccupiedCells` | `pub fn spatialMatrixOccupiedCells(container: SpatialMatrixContainer2D): int:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `82` | `std/mechanics/inventory_container.aipl` | `spatialMatrixTotalWeight` | `pub fn spatialMatrixTotalWeight(container: SpatialMatrixContainer2D): float:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `83` | `std/mechanics/inventory_container.aipl` | `weightedLootTableNew` | `pub fn weightedLootTableNew(entries: [WeightedLootEntry]): WeightedLootTable:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `84` | `std/mechanics/inventory_container.aipl` | `weightedLootTableRoll` | `pub fn weightedLootTableRoll(table: WeightedLootTable, roll01: float): Option[WeightedLootEntry]:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `85` | `std/mechanics/inventory_container.aipl` | `weightedLootRollQuantity` | `pub fn weightedLootRollQuantity(entry: WeightedLootEntry, roll01: float): int:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `86` | `std/mechanics/inventory_container.aipl` | `inventorySlotNew` | `pub fn inventorySlotNew(itemId: int = 0, quantity: int = 0, maxStack: int = 99, flags: int = 0): InventorySlot:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `87` | `std/mechanics/inventory_container.aipl` | `inventorySlotIsEmpty` | `pub fn inventorySlotIsEmpty(slot: InventorySlot): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `88` | `std/mechanics/inventory_container.aipl` | `inventoryContainerNew` | `pub fn inventoryContainerNew(width: int, height: int, defaultMaxStack: int = 99): InventoryContainer:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `89` | `std/mechanics/inventory_container.aipl` | `inventorySlotCanAccept` | `pub fn inventorySlotCanAccept(slot: InventorySlot, itemId: int, qty: int): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `90` | `std/mechanics/inventory_container.aipl` | `inventoryContainerGetSlot` | `pub fn inventoryContainerGetSlot(container: InventoryContainer, x: int, y: int): InventorySlot:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `91` | `std/mechanics/inventory_container.aipl` | `inventoryContainerSetSlot` | `pub fn inventoryContainerSetSlot(mut container: InventoryContainer, x: int, y: int, slot: InventorySlot): InventoryContainer:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `92` | `std/mechanics/inventory_container.aipl` | `inventoryContainerAddItem` | `pub fn inventoryContainerAddItem(mut container: InventoryContainer, itemId: int, quantity: int): (InventoryContainer, int):` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `93` | `std/mechanics/inventory_container.aipl` | `inventoryContainerCountItem` | `pub fn inventoryContainerCountItem(container: InventoryContainer, itemId: int): int:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `94` | `std/mechanics/inventory_container.aipl` | `inventoryCanPlaceItem2D` | `pub fn inventoryCanPlaceItem2D(container: InventoryContainer, itemW: int, itemH: int, startX: int, startY: int): bool:` | `tests/functions/mechanics/inventory_container_test.aipl` |
| `95` | `std/mechanics/inventory_container.aipl` | `inventoryPackItem2D` | `pub fn inventoryPackItem2D(mut container: InventoryContainer, itemW: int, itemH: int, itemId: int): (InventoryContainer, bool, int, int):` | `tests/functions/mechanics/inventory_container_test.aipl` |

---

## 4. Detailed API Reference & Runnable Verification Snippets

### `evalStatModifierStack` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn evalStatModifierStack(baseValue: float, modifiers: [StatModifier]): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseValue: float, modifiers: [StatModifier]` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `evalStatModifierStack`. Concrete nominal inputs: `baseValue: float = 1.0`, `modifiers: [StatModifier] = [StatModifier(id = 1, statTag = "aipl_test", stage = ModifierStage(), value = 1.0, durationRemaining = 0.5, isPermanent = true)]`; exercises core body path returning/computing `((baseValue + sumFlat) * (1.0 + sumPct)) * prodMult`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z1_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_evalStatModifierStack_1(): int:
  let arg_baseValue = 1.0
  let edge_baseValue = 0.5
  let arg_modifiers = [StatModifier(id = 1, statTag = "test", stage = ModifierStage.FlatAdd, value = 1.0, durationRemaining = 1.0, isPermanent = true)]
  let edge_modifiers = []
  let resNom = evalStatModifierStack(arg_baseValue, arg_modifiers)
  let resEdge = evalStatModifierStack(edge_baseValue, edge_modifiers)
  assertApproxEq(resNom, 2.0, 0.001, "evalStatModifierStack nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "evalStatModifierStack boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeFractionalCurrentHpDamage` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeFractionalCurrentHpDamage(currentHp: float, fraction: float): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `currentHp: float, fraction: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeFractionalCurrentHpDamage`. Concrete nominal inputs: `currentHp: float = 1.0`, `fraction: float = 1.0`; exercises core body path returning/computing `maxFloat(0.0, currentHp) * f`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z2_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeFractionalCurrentHpDamage_2(): int:
  let arg_currentHp = 2.0
  let edge_currentHp = 1.0
  let arg_fraction = 1.0
  let edge_fraction = 0.5
  let resNom = computeFractionalCurrentHpDamage(arg_currentHp, arg_fraction)
  let resEdge = computeFractionalCurrentHpDamage(edge_currentHp, edge_fraction)
  assertApproxEq(resNom, 2.0, 0.001, "computeFractionalCurrentHpDamage nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeFractionalCurrentHpDamage boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeDamageOverTimeTick` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeDamageOverTimeTick(baseDps: float, dt: float): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseDps: float, dt: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeDamageOverTimeTick`. Concrete nominal inputs: `baseDps: float = 1.0`, `dt: float = 0.016667`; exercises core body path returning/computing `maxFloat(0.0, baseDps) * maxFloat(0.0, dt)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z3_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeDamageOverTimeTick_3(): int:
  let arg_baseDps = 1.0
  let edge_baseDps = 0.5
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = computeDamageOverTimeTick(arg_baseDps, arg_dt)
  let resEdge = computeDamageOverTimeTick(edge_baseDps, edge_dt)
  assertApproxEq(resNom, 2.0, 0.001, "computeDamageOverTimeTick nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeDamageOverTimeTick boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeCooldownWithReduction` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeCooldownWithReduction(baseCooldown: float, cdrPercent: float): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseCooldown: float, cdrPercent: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeCooldownWithReduction`. Concrete nominal inputs: `baseCooldown: float = 1.0`, `cdrPercent: float = 1.0`; exercises core body path returning/computing `maxFloat(0.05, baseCooldown * factor)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z4_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeCooldownWithReduction_4(): int:
  let arg_baseCooldown = 2.0
  let edge_baseCooldown = 1.0
  let arg_cdrPercent = 1.0
  let edge_cdrPercent = 0.5
  let resNom = computeCooldownWithReduction(arg_baseCooldown, arg_cdrPercent)
  let resEdge = computeCooldownWithReduction(edge_baseCooldown, edge_cdrPercent)
  assertApproxEq(resNom, 1.98, 0.001, "computeCooldownWithReduction nominal resNom ~= 1.98")
  assertApproxEq(resEdge, 0.995, 0.001, "computeCooldownWithReduction boundary resEdge ~= 0.995")
  ret 0
```

---

### `computeLinearScaledCost` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeLinearScaledCost(baseCost: int, scaleLevel: int, growthFactor: float): int:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseCost: int, scaleLevel: int, growthFactor: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeLinearScaledCost`. Concrete nominal inputs: `baseCost: int = 1`, `scaleLevel: int = 1`, `growthFactor: float = 1.0`; exercises core body path returning/computing `int(scaled + 0.5)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z5_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeLinearScaledCost_5(): int:
  let arg_baseCost = 4
  let edge_baseCost = 1
  let arg_scaleLevel = 2
  let edge_scaleLevel = 0
  let arg_growthFactor = 2.0
  let edge_growthFactor = 1.0
  let resNom = computeLinearScaledCost(arg_baseCost, arg_scaleLevel, arg_growthFactor)
  let resEdge = computeLinearScaledCost(edge_baseCost, edge_scaleLevel, edge_growthFactor)
  assertEqInt(resNom, 20, "computeLinearScaledCost nominal resNom == 20")
  assertEqInt(resEdge, 1, "computeLinearScaledCost boundary resEdge == 1")
  ret 0
```

---

### `attributePoolNew` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn attributePoolNew(baseMax: float, regenRatePerSec: float = 0.0): AttributePool:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseMax: float, regenRatePerSec: float = 0.0` | **Returns**: `AttributePool`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `attributePoolNew`. Concrete nominal inputs: `baseMax: float = 1.0`, `regenRatePerSec: float = 1.0`; exercises core body path returning/computing `AttributePool(current = m, baseMax = m, regenRatePerSec = regenRatePerSec)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z6_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_attributePoolNew_6(): int:
  let arg_baseMax = 2.0
  let edge_baseMax = 1.0
  let arg_regenRatePerSec = 2.0
  let edge_regenRatePerSec = 1.0
  let resNom = attributePoolNew(arg_baseMax, arg_regenRatePerSec)
  let resEdge = attributePoolNew(edge_baseMax, edge_regenRatePerSec)
  assertApproxEq(resNom.current, 2.0, 0.001, "attributePoolNew nominal resNom.current ~= 2.0")
  assertApproxEq(resEdge.current, 1.0, 0.001, "attributePoolNew boundary resEdge.current ~= 1.0")
  ret 0
```

---

### `attributePoolStepRegen` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn attributePoolStepRegen(pool: AttributePool, dt: float): AttributePool:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: AttributePool, dt: float` | **Returns**: `AttributePool`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `attributePoolStepRegen`. Concrete nominal inputs: `pool: AttributePool = AttributePool(current = 1.0, baseMax = 1.0, regenRatePerSec = 1.0)`, `dt: float = 0.016667`; exercises core body path returning/computing `AttributePool(current = nextVal, baseMax = pool.baseMax, regenRatePerSec = pool.regenRatePerSec)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z7_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_attributePoolStepRegen_7(): int:
  let arg_pool = AttributePool(current = 1.0, baseMax = 2.0, regenRatePerSec = 2.0)
  let edge_pool = AttributePool(current = 0.5, baseMax = 1.0, regenRatePerSec = 1.0)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = attributePoolStepRegen(arg_pool, arg_dt)
  let resEdge = attributePoolStepRegen(edge_pool, edge_dt)
  assertApproxEq(resNom.current, 2.0, 0.001, "attributePoolStepRegen nominal resNom.current ~= 2.0")
  assertApproxEq(resEdge.current, 1.0, 0.001, "attributePoolStepRegen boundary resEdge.current ~= 1.0")
  ret 0
```

---

### `attributePoolSpend` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn attributePoolSpend(pool: AttributePool, cost: float): (AttributePool, bool):`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: AttributePool, cost: float` | **Returns**: `(AttributePool, bool)`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `attributePoolSpend`. Concrete nominal inputs: `pool: AttributePool = AttributePool(current = 1.0, baseMax = 1.0, regenRatePerSec = 1.0)`, `cost: float): (AttributePool = float): (AttributePool()`, `bool: any = 42`; exercises core body path returning/computing `(AttributePool(current = pool.current - cost, baseMax = pool.baseMax, regenRatePerSec = pool.regenRatePerSec), true)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z8_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_attributePoolSpend_8(): int:
  let arg_pool = AttributePool(current = 1.0, baseMax = 2.0, regenRatePerSec = 2.0)
  let edge_pool = AttributePool(current = 0.5, baseMax = 1.0, regenRatePerSec = 1.0)
  let arg_cost = 1.0
  let edge_cost = 0.5
  let resNom = attributePoolSpend(arg_pool, arg_cost)
  let resEdge = attributePoolSpend(edge_pool, edge_cost)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertApproxEq(n_t0.current, 0.0, 0.001, "attributePoolSpend nominal n_t0.current ~= 0.0")
  assertApproxEq(e_t0.current, 0.0, 0.001, "attributePoolSpend boundary e_t0.current ~= 0.0")
  ret 0
```

---

### `attributePoolRestore` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn attributePoolRestore(pool: AttributePool, amount: float): AttributePool:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: AttributePool, amount: float` | **Returns**: `AttributePool`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `attributePoolRestore`. Concrete nominal inputs: `pool: AttributePool = AttributePool(current = 1.0, baseMax = 1.0, regenRatePerSec = 1.0)`, `amount: float = 1.0`; exercises core body path returning/computing `AttributePool(current = nextVal, baseMax = pool.baseMax, regenRatePerSec = pool.regenRatePerSec)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z9_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_attributePoolRestore_9(): int:
  let arg_pool = AttributePool(current = 1.0, baseMax = 2.0, regenRatePerSec = 2.0)
  let edge_pool = AttributePool(current = 0.5, baseMax = 1.0, regenRatePerSec = 1.0)
  let arg_amount = 1.0
  let edge_amount = 0.5
  let resNom = attributePoolRestore(arg_pool, arg_amount)
  let resEdge = attributePoolRestore(edge_pool, edge_amount)
  assertApproxEq(resNom.current, 2.0, 0.001, "attributePoolRestore nominal resNom.current ~= 2.0")
  assertApproxEq(resEdge.current, 1.0, 0.001, "attributePoolRestore boundary resEdge.current ~= 1.0")
  ret 0
```

---

### `attributePoolRatio` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn attributePoolRatio(pool: AttributePool): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `pool: AttributePool` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `attributePoolRatio`. Concrete nominal inputs: `pool: AttributePool = AttributePool(current = 1.0, baseMax = 1.0, regenRatePerSec = 1.0)`; exercises core body path returning/computing `clampFloat(pool.current / pool.baseMax, 0.0, 1.0)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z10_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_attributePoolRatio_10(): int:
  let arg_pool = AttributePool(current = 1.0, baseMax = 2.0, regenRatePerSec = 2.0)
  let edge_pool = AttributePool(current = 0.5, baseMax = 1.0, regenRatePerSec = 1.0)
  let resNom = attributePoolRatio(arg_pool)
  let resEdge = attributePoolRatio(edge_pool)
  assertApproxEq(resNom, 0.5, 0.001, "attributePoolRatio nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.5, 0.001, "attributePoolRatio boundary resEdge ~= 0.5")
  ret 0
```

---

### `statusEffectTickerNew` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn statusEffectTickerNew(effectTag: str, tickInterval: float, totalDuration: float, valuePerTick: float): StatusEffectTicker:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `effectTag: str, tickInterval: float, totalDuration: float, valuePerTick: float` | **Returns**: `StatusEffectTicker`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `statusEffectTickerNew`. Concrete nominal inputs: `effectTag: str = "aipl_test"`, `tickInterval: float = 1.0`, `totalDuration: float = 0.5`, `valuePerTick: float = 1.0`; exercises core body path returning/computing `StatusEffectTicker(`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z11_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_statusEffectTickerNew_11(): int:
  let arg_effectTag = "test"
  let edge_effectTag = "a"
  let arg_tickInterval = 1.0
  let edge_tickInterval = 0.5
  let arg_totalDuration = 1.0
  let edge_totalDuration = 0.5
  let arg_valuePerTick = 1.0
  let edge_valuePerTick = 0.5
  let resNom = statusEffectTickerNew(arg_effectTag, arg_tickInterval, arg_totalDuration, arg_valuePerTick)
  let resEdge = statusEffectTickerNew(edge_effectTag, edge_tickInterval, edge_totalDuration, edge_valuePerTick)
  assertEqStr(resNom.effectTag, "test", "statusEffectTickerNew nominal string matches")
  assertEqStr(resEdge.effectTag, "a", "statusEffectTickerNew boundary string matches")
  ret 0
```

---

### `statusEffectTickerStep` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn statusEffectTickerStep(ticker: StatusEffectTicker, dt: float): (StatusEffectTicker, int, float):`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ticker: StatusEffectTicker, dt: float` | **Returns**: `(StatusEffectTicker, int, float)`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `statusEffectTickerStep`. Concrete nominal inputs: `ticker: StatusEffectTicker = StatusEffectTicker(effectTag = "aipl_test", tickInterval = 1.0, tickTimer = 1.0, totalDuration = 0.5, valuePerTick = 1.0)`, `dt: float): (StatusEffectTicker = float): (StatusEffectTicker()`, `int: any = 42`, `float: any = 42`; exercises core body path returning/computing `(nextTicker, ticks, float(ticks) * ticker.valuePerTick)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z12_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_statusEffectTickerStep_12(): int:
  let arg_ticker = StatusEffectTicker(effectTag = "test", tickInterval = 1.0, tickTimer = 1.0, totalDuration = 1.0, valuePerTick = 1.0)
  let edge_ticker = StatusEffectTicker(effectTag = "a", tickInterval = 0.5, tickTimer = 0.5, totalDuration = 0.5, valuePerTick = 0.5)
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = statusEffectTickerStep(arg_ticker, arg_dt)
  let resEdge = statusEffectTickerStep(edge_ticker, edge_dt)
  let (n_t0, n_t1, n_t2) = resNom
  let (e_t0, e_t1, e_t2) = resEdge
  assertEqStr(n_t0.effectTag, "test", "statusEffectTickerStep nominal string matches")
  assertEqStr(e_t0.effectTag, "a", "statusEffectTickerStep boundary string matches")
  ret 0
```

---

### `statusEffectIsExpired` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn statusEffectIsExpired(ticker: StatusEffectTicker): bool:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ticker: StatusEffectTicker` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `statusEffectIsExpired`. Concrete nominal inputs: `ticker: StatusEffectTicker = StatusEffectTicker(effectTag = "aipl_test", tickInterval = 1.0, tickTimer = 1.0, totalDuration = 0.5, valuePerTick = 1.0)`; exercises core body path returning/computing `ticker.totalDuration <= 0.0`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z13_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_statusEffectIsExpired_13(): int:
  let arg_ticker = StatusEffectTicker(effectTag = "test", tickInterval = 1.0, tickTimer = 1.0, totalDuration = 1.0, valuePerTick = 1.0)
  let edge_ticker = StatusEffectTicker(effectTag = "a", tickInterval = 0.5, tickTimer = 0.5, totalDuration = 0.5, valuePerTick = 0.5)
  let resNom = statusEffectIsExpired(arg_ticker)
  let resEdge = statusEffectIsExpired(edge_ticker)
  assert(resNom == false, "statusEffectIsExpired nominal resNom == false")
  assert(resEdge == false, "statusEffectIsExpired boundary resEdge == false")
  ret 0
```

---

### `stepStatModifierDurations` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn stepStatModifierDurations(modifiers: [StatModifier], dt: float): [StatModifier]:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `modifiers: [StatModifier], dt: float` | **Returns**: `[StatModifier]`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `stepStatModifierDurations`. Concrete nominal inputs: `modifiers: [StatModifier] = [StatModifier(id = 1, statTag = "aipl_test", stage = ModifierStage(), value = 1.0, durationRemaining = 0.5, isPermanent = true)]`, `dt: float = 0.016667`; exercises core body path returning/computing `active`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z14_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_stepStatModifierDurations_14(): int:
  let arg_modifiers = [StatModifier(id = 1, statTag = "test", stage = ModifierStage.FlatAdd, value = 1.0, durationRemaining = 1.0, isPermanent = true)]
  let edge_modifiers = []
  let arg_dt = 2.0
  let edge_dt = 1.0
  let resNom = stepStatModifierDurations(arg_modifiers, arg_dt)
  let resEdge = stepStatModifierDurations(edge_modifiers, edge_dt)
  assertEqInt(resNom.len(), 1, "stepStatModifierDurations nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "stepStatModifierDurations boundary resEdge.len() == 0")
  ret 0
```

---

### `filterStatModifiersByTag` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn filterStatModifiersByTag(modifiers: [StatModifier], statTag: str): [StatModifier]:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `modifiers: [StatModifier], statTag: str` | **Returns**: `[StatModifier]`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `filterStatModifiersByTag`. Concrete nominal inputs: `modifiers: [StatModifier] = [StatModifier(id = 1, statTag = "aipl_test", stage = ModifierStage(), value = 1.0, durationRemaining = 0.5, isPermanent = true)]`, `statTag: str = "aipl_test"`; exercises core body path returning/computing `out`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z15_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_filterStatModifiersByTag_15(): int:
  let arg_modifiers = [StatModifier(id = 1, statTag = "test", stage = ModifierStage.FlatAdd, value = 1.0, durationRemaining = 1.0, isPermanent = true)]
  let edge_modifiers = []
  let arg_statTag = "test"
  let edge_statTag = "a"
  let resNom = filterStatModifiersByTag(arg_modifiers, arg_statTag)
  let resEdge = filterStatModifiersByTag(edge_modifiers, edge_statTag)
  assertEqInt(resNom.len(), 1, "filterStatModifiersByTag nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "filterStatModifiersByTag boundary resEdge.len() == 0")
  ret 0
```

---

### `computeArmorMitigationRatio` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeArmorMitigationRatio(armorRating: float, halfMitigationConstant: float = 100.0): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `armorRating: float, halfMitigationConstant: float = 100.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeArmorMitigationRatio`. Concrete nominal inputs: `armorRating: float = 1.0`, `halfMitigationConstant: float = 1.0`; exercises core body path returning/computing `a / (a + k)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z16_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeArmorMitigationRatio_16(): int:
  let arg_armorRating = 1.0
  let edge_armorRating = 0.5
  let arg_halfMitigationConstant = 2.0
  let edge_halfMitigationConstant = 1.0
  let resNom = computeArmorMitigationRatio(arg_armorRating, arg_halfMitigationConstant)
  let resEdge = computeArmorMitigationRatio(edge_armorRating, edge_halfMitigationConstant)
  assertApproxEq(resNom, 0.333333, 0.001, "computeArmorMitigationRatio nominal resNom ~= 0.333333")
  assertApproxEq(resEdge, 0.333333, 0.001, "computeArmorMitigationRatio boundary resEdge ~= 0.333333")
  ret 0
```

---

### `applyMitigatedDamage` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn applyMitigatedDamage(rawDamage: float, armorRating: float, flatBlock: float = 0.0): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawDamage: float, armorRating: float, flatBlock: float = 0.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `applyMitigatedDamage`. Concrete nominal inputs: `rawDamage: float = 1.0`, `armorRating: float = 1.0`, `flatBlock: float = 1.0`; exercises core body path returning/computing `afterBlock * (1.0 - mit)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z17_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_applyMitigatedDamage_17(): int:
  let arg_rawDamage = 2.0
  let edge_rawDamage = 1.0
  let arg_armorRating = 1.0
  let edge_armorRating = 0.5
  let arg_flatBlock = 0.0
  let edge_flatBlock = 0.0
  let resNom = applyMitigatedDamage(arg_rawDamage, arg_armorRating, arg_flatBlock)
  let resEdge = applyMitigatedDamage(edge_rawDamage, edge_armorRating, edge_flatBlock)
  assertApproxEq(resNom, 1.9802, 0.001, "applyMitigatedDamage nominal resNom ~= 1.9802")
  assertApproxEq(resEdge, 0.995025, 0.001, "applyMitigatedDamage boundary resEdge ~= 0.995025")
  ret 0
```

---

### `computeCriticalStrikeMultiplier` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeCriticalStrikeMultiplier(baseDamage: float, isCrit: bool, critBonusRatio: float = 1.0): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseDamage: float, isCrit: bool, critBonusRatio: float = 1.0` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeCriticalStrikeMultiplier`. Concrete nominal inputs: `baseDamage: float = 1.0`, `isCrit: bool = true`, `critBonusRatio: float = 0.5`; exercises core body path returning/computing `d * (1.0 + maxFloat(0.0, critBonusRatio))`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z18_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeCriticalStrikeMultiplier_18(): int:
  let arg_baseDamage = 1.0
  let edge_baseDamage = 0.5
  let arg_isCrit = true
  let edge_isCrit = false
  let arg_critBonusRatio = 1.0
  let edge_critBonusRatio = 0.5
  let resNom = computeCriticalStrikeMultiplier(arg_baseDamage, arg_isCrit, arg_critBonusRatio)
  let resEdge = computeCriticalStrikeMultiplier(edge_baseDamage, edge_isCrit, edge_critBonusRatio)
  assertApproxEq(resNom, 2.0, 0.001, "computeCriticalStrikeMultiplier nominal resNom ~= 2.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeCriticalStrikeMultiplier boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeDiminishingReturns` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeDiminishingReturns(rawBonus: float, softCap: float): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `rawBonus: float, softCap: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeDiminishingReturns`. Concrete nominal inputs: `rawBonus: float = 1.0`, `softCap: float = 1.0`; exercises core body path returning/computing `(b * c) / (b + c)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z19_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeDiminishingReturns_19(): int:
  let arg_rawBonus = 2.0
  let edge_rawBonus = 1.0
  let arg_softCap = 1.0
  let edge_softCap = 0.5
  let resNom = computeDiminishingReturns(arg_rawBonus, arg_softCap)
  let resEdge = computeDiminishingReturns(edge_rawBonus, edge_softCap)
  assertApproxEq(resNom, 0.666667, 0.001, "computeDiminishingReturns nominal resNom ~= 0.666667")
  assertApproxEq(resEdge, 0.5, 0.001, "computeDiminishingReturns boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeExponentialLevelXp` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeExponentialLevelXp(level: int, baseXp: int, growthRate: float = 0.25): int:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `level: int, baseXp: int, growthRate: float = 0.25` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeExponentialLevelXp`. Concrete nominal inputs: `level: int = 1`, `baseXp: int = 1`, `growthRate: float = 1.0`; exercises core body path returning/computing `int(xp + 0.5)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z20_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeExponentialLevelXp_20(): int:
  let arg_level = 2
  let edge_level = 0
  let arg_baseXp = 4
  let edge_baseXp = 1
  let arg_growthRate = 2.0
  let edge_growthRate = 1.0
  let resNom = computeExponentialLevelXp(arg_level, arg_baseXp, arg_growthRate)
  let resEdge = computeExponentialLevelXp(edge_level, edge_baseXp, edge_growthRate)
  assertEqInt(resNom, 12, "computeExponentialLevelXp nominal resNom == 12")
  assertEqInt(resEdge, 1, "computeExponentialLevelXp boundary resEdge == 1")
  ret 0
```

---

### `computeAttributeSoftCap` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn computeAttributeSoftCap(val: float, capThreshold: float, postCapEfficiency: float = 0.5): float:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `val: float, capThreshold: float, postCapEfficiency: float = 0.5` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `computeAttributeSoftCap`. Concrete nominal inputs: `val: float = 1.0`, `capThreshold: float = 1.0`, `postCapEfficiency: float = 1.0`; exercises core body path returning/computing `capThreshold + excess * clampFloat(postCapEfficiency, 0.0, 1.0)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z21_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_computeAttributeSoftCap_21(): int:
  let arg_val = 1.0
  let edge_val = 0.5
  let arg_capThreshold = 2.0
  let edge_capThreshold = 1.0
  let arg_postCapEfficiency = 1.0
  let edge_postCapEfficiency = 0.5
  let resNom = computeAttributeSoftCap(arg_val, arg_capThreshold, arg_postCapEfficiency)
  let resEdge = computeAttributeSoftCap(edge_val, edge_capThreshold, edge_postCapEfficiency)
  assertApproxEq(resNom, 1.0, 0.001, "computeAttributeSoftCap nominal resNom ~= 1.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeAttributeSoftCap boundary resEdge ~= 0.5")
  ret 0
```

---

### `rollWeightedIndex` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn rollWeightedIndex(weights: [int], rollVal: int): int:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `weights: [int], rollVal: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `rollWeightedIndex`. Concrete nominal inputs: `weights: [int] = [1]`, `rollVal: int = 1`; exercises core body path returning/computing `maxInt(0, weights.len - 1)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z22_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_rollWeightedIndex_22(): int:
  let arg_weights = [2]
  let edge_weights = []
  let arg_rollVal = 2
  let edge_rollVal = 0
  let resNom = rollWeightedIndex(arg_weights, arg_rollVal)
  let resEdge = rollWeightedIndex(edge_weights, edge_rollVal)
  assertEqInt(resNom, 0, "rollWeightedIndex nominal resNom == 0")
  assertEqInt(resEdge, 0, "rollWeightedIndex boundary resEdge == 0")
  ret 0
```

---

### `rollAttributeRange` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn rollAttributeRange(minValue: int, maxValue: int, rollRatio: float): int:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `minValue: int, maxValue: int, rollRatio: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `rollAttributeRange`. Concrete nominal inputs: `minValue: int = 1`, `maxValue: int = 1`, `rollRatio: float = 0.5`; exercises core body path returning/computing `lo + int(span * r + 0.5)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z23_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_rollAttributeRange_23(): int:
  let arg_minValue = 4
  let edge_minValue = 1
  let arg_maxValue = 4
  let edge_maxValue = 1
  let arg_rollRatio = 1.0
  let edge_rollRatio = 0.5
  let resNom = rollAttributeRange(arg_minValue, arg_maxValue, arg_rollRatio)
  let resEdge = rollAttributeRange(edge_minValue, edge_maxValue, edge_rollRatio)
  assertEqInt(resNom, 4, "rollAttributeRange nominal resNom == 4")
  assertEqInt(resEdge, 1, "rollAttributeRange boundary resEdge == 1")
  ret 0
```

---

### `rollItemAffixBonus` (`std/mechanics/attribute_pipeline.aipl`)

- **Signature**: `pub fn rollItemAffixBonus(baseStat: int, tier: int, qualityMult: float): int:`
- **Import**: `import * from "std/mechanics/attribute_pipeline"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `baseStat: int, tier: int, qualityMult: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/attribute_pipeline_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests 4-stage RPG stat modifier pipeline, HP/Mana regen pools, DoT status tickers, hyperbolic armor mitigation, and crit/diminishing returns in `rollItemAffixBonus`. Concrete nominal inputs: `baseStat: int = 1`, `tier: int = 1`, `qualityMult: float = 1.0`; exercises core body path returning/computing `int(float(b + t * 5) * q + 0.5)`.

```aipl
module tests.functions.mechanics.attribute_pipeline_z24_test
import * from "std/mechanics/attribute_pipeline"
import { clampFloat, maxFloat, minFloat, minInt, maxInt } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_attribute_pipeline_rollItemAffixBonus_24(): int:
  let arg_baseStat = 4
  let edge_baseStat = 1
  let arg_tier = 2
  let edge_tier = 0
  let arg_qualityMult = 1.0
  let edge_qualityMult = 0.5
  let resNom = rollItemAffixBonus(arg_baseStat, arg_tier, arg_qualityMult)
  let resEdge = rollItemAffixBonus(edge_baseStat, edge_tier, edge_qualityMult)
  assertEqInt(resNom, 14, "rollItemAffixBonus nominal resNom == 14")
  assertEqInt(resEdge, 6, "rollItemAffixBonus boundary resEdge == 6")
  ret 0
```

---

### `dialogueGraphNew` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueGraphNew(startNodeId: int): DialogueGraph:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `startNodeId: int` | **Returns**: `DialogueGraph`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueGraphNew`. Concrete nominal inputs: `startNodeId: int = 1`; exercises core body path returning/computing `DialogueGraph(startNodeId = startNodeId, nodes = ns)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z1_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueGraphNew_1(): int:
  let arg_startNodeId = 4
  let edge_startNodeId = 1
  let resNom = dialogueGraphNew(arg_startNodeId)
  let resEdge = dialogueGraphNew(edge_startNodeId)
  assertEqInt(resNom.startNodeId, 4, "dialogueGraphNew nominal resNom.startNodeId == 4")
  assertEqInt(resEdge.startNodeId, 1, "dialogueGraphNew boundary resEdge.startNodeId == 1")
  ret 0
```

---

### `dialogueAddNode` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueAddNode(mut graph: DialogueGraph, node: DialogueNode): void:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut graph: DialogueGraph, node: DialogueNode` | **Returns**: `void`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueAddNode`. Concrete nominal inputs: `graph: DialogueGraph = DialogueGraph(startNodeId = 1, nodes = [DialogueNode(nodeId = 0, speaker = 0, content = 0, choices = 0)])`, `node: DialogueNode = DialogueNode(nodeId = 1, speaker = "aipl_test", content = "aipl_test", choices = [DialogueChoice(choiceId = 0, text = 0, targetNodeId = 0, requiredFlags = 0)])`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.mechanics.dialogue_dag_z2_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueAddNode_2(): int:
  let arg_graph = DialogueGraph(startNodeId = 4, nodes = [])
  let edge_graph = DialogueGraph(startNodeId = 1, nodes = [])
  let arg_node = DialogueNode(nodeId = 4, speaker = "test", content = "test", choices = [])
  let edge_node = DialogueNode(nodeId = 1, speaker = "a", content = "a", choices = [])
  dialogueAddNode(arg_graph, arg_node)
  dialogueAddNode(edge_graph, edge_node)
  assertEqInt(arg_graph.nodes.len(), 1, "dialogueAddNode nominal arg_graph.nodes.len() == 1")
  assertEqInt(edge_graph.nodes.len(), 1, "dialogueAddNode boundary edge_graph.nodes.len() == 1")
  ret 0
```

---

### `dialogueNodeCount` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueNodeCount(graph: DialogueGraph): int:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `graph: DialogueGraph` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueNodeCount`. Concrete nominal inputs: `graph: DialogueGraph = DialogueGraph(startNodeId = 1, nodes = [DialogueNode(nodeId = 0, speaker = 0, content = 0, choices = 0)])`; exercises core body path returning/computing `graph.nodes.len`.

```aipl
module tests.functions.mechanics.dialogue_dag_z3_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueNodeCount_3(): int:
  let arg_graph = DialogueGraph(startNodeId = 4, nodes = [])
  let edge_graph = DialogueGraph(startNodeId = 1, nodes = [])
  let resNom = dialogueNodeCount(arg_graph)
  let resEdge = dialogueNodeCount(edge_graph)
  assertEqInt(resNom, 0, "dialogueNodeCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "dialogueNodeCount boundary resEdge == 0")
  ret 0
```

---

### `dialogueFindNode` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueFindNode(graph: DialogueGraph, nodeId: int): Option[DialogueNode]:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `graph: DialogueGraph, nodeId: int` | **Returns**: `Option[DialogueNode]`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueFindNode`. Concrete nominal inputs: `graph: DialogueGraph = DialogueGraph(startNodeId = 1, nodes = [DialogueNode(nodeId = 0, speaker = 0, content = 0, choices = 0)])`, `nodeId: int = 1`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.mechanics.dialogue_dag_z4_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueFindNode_4(): int:
  let arg_graph = DialogueGraph(startNodeId = 4, nodes = [])
  let edge_graph = DialogueGraph(startNodeId = 1, nodes = [])
  let arg_nodeId = 4
  let edge_nodeId = 1
  let resNom = dialogueFindNode(arg_graph, arg_nodeId)
  let resEdge = dialogueFindNode(edge_graph, edge_nodeId)
  assert(resNom.isSome() == false, "dialogueFindNode nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dialogueFindNode boundary resEdge.isSome() == false")
  ret 0
```

---

### `hasFlagInSlice` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `fn hasFlagInSlice(flags: [str], target: str): bool:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `flags: [str], target: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `hasFlagInSlice`. Concrete nominal inputs: `flags: [str] = ["aipl_test"]`, `target: str = "aipl_test"`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.mechanics.dialogue_dag_z5_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_hasFlagInSlice_5(): int:
  let arg_flags = ["test"]
  let edge_flags = []
  let arg_target = "test"
  let edge_target = "a"
  let resNom = hasFlagInSlice(arg_flags, arg_target)
  let resEdge = hasFlagInSlice(edge_flags, edge_target)
  assert(resNom == true, "hasFlagInSlice nominal resNom == true")
  assert(resEdge == false, "hasFlagInSlice boundary resEdge == false")
  ret 0
```

---

### `dialogueGetAvailableChoices` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueGetAvailableChoices(graph: DialogueGraph, nodeId: int, activeFlags: [str]): [DialogueChoice]:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `graph: DialogueGraph, nodeId: int, activeFlags: [str]` | **Returns**: `[DialogueChoice]`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueGetAvailableChoices`. Concrete nominal inputs: `graph: DialogueGraph = DialogueGraph(startNodeId = 1, nodes = [DialogueNode(nodeId = 0, speaker = 0, content = 0, choices = 0)])`, `nodeId: int = 1`, `activeFlags: [str] = ["aipl_test"]`; exercises core body path returning/computing `avail`.

```aipl
module tests.functions.mechanics.dialogue_dag_z6_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueGetAvailableChoices_6(): int:
  let arg_graph = DialogueGraph(startNodeId = 4, nodes = [])
  let edge_graph = DialogueGraph(startNodeId = 1, nodes = [])
  let arg_nodeId = 4
  let edge_nodeId = 1
  let arg_activeFlags = ["test"]
  let edge_activeFlags = []
  let resNom = dialogueGetAvailableChoices(arg_graph, arg_nodeId, arg_activeFlags)
  let resEdge = dialogueGetAvailableChoices(edge_graph, edge_nodeId, edge_activeFlags)
  assertEqInt(resNom.len(), 0, "dialogueGetAvailableChoices nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "dialogueGetAvailableChoices boundary resEdge.len() == 0")
  ret 0
```

---

### `dialogueAdvanceChoice` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dialogueAdvanceChoice(graph: DialogueGraph, currentNodeId: int, choiceId: int, activeFlags: [str]): Option[DialogueNode]:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `graph: DialogueGraph, currentNodeId: int, choiceId: int, activeFlags: [str]` | **Returns**: `Option[DialogueNode]`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dialogueAdvanceChoice`. Concrete nominal inputs: `graph: DialogueGraph = DialogueGraph(startNodeId = 1, nodes = [DialogueNode(nodeId = 0, speaker = 0, content = 0, choices = 0)])`, `currentNodeId: int = 1`, `choiceId: int = 1`, `activeFlags: [str] = ["aipl_test"]`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.mechanics.dialogue_dag_z7_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dialogueAdvanceChoice_7(): int:
  let arg_graph = DialogueGraph(startNodeId = 4, nodes = [])
  let edge_graph = DialogueGraph(startNodeId = 1, nodes = [])
  let arg_currentNodeId = 4
  let edge_currentNodeId = 1
  let arg_choiceId = 1
  let edge_choiceId = 0
  let arg_activeFlags = ["test"]
  let edge_activeFlags = []
  let resNom = dialogueAdvanceChoice(arg_graph, arg_currentNodeId, arg_choiceId, arg_activeFlags)
  let resEdge = dialogueAdvanceChoice(edge_graph, edge_currentNodeId, edge_choiceId, edge_activeFlags)
  assert(resNom.isSome() == false, "dialogueAdvanceChoice nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "dialogueAdvanceChoice boundary resEdge.isSome() == false")
  ret 0
```

---

### `objectiveDagNew` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveDagNew(): ObjectiveDependencyDAG:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ObjectiveDependencyDAG`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveDagNew`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ObjectiveDependencyDAG(links = ls, completedTasks = done)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z8_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveDagNew_8(): int:
  let resNom = objectiveDagNew()
  let resEdge = objectiveDagNew()
  assertEqInt(resNom.links.len(), 0, "objectiveDagNew nominal resNom.links.len() == 0")
  assertEqInt(resEdge.links.len(), 0, "objectiveDagNew boundary resEdge.links.len() == 0")
  ret 0
```

---

### `objectiveAddPrerequisite` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveAddPrerequisite(mut dag: ObjectiveDependencyDAG, task: str, requiredPrereq: str): void:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut dag: ObjectiveDependencyDAG, task: str, requiredPrereq: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveAddPrerequisite`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `task: str = "aipl_test"`, `requiredPrereq: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.mechanics.dialogue_dag_z9_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveAddPrerequisite_9(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_task = "test"
  let edge_task = "a"
  let arg_requiredPrereq = "test"
  let edge_requiredPrereq = "a"
  objectiveAddPrerequisite(arg_dag, arg_task, arg_requiredPrereq)
  objectiveAddPrerequisite(edge_dag, edge_task, edge_requiredPrereq)
  assertEqInt(arg_dag.links.len(), 1, "objectiveAddPrerequisite nominal arg_dag.links.len() == 1")
  assertEqInt(edge_dag.links.len(), 1, "objectiveAddPrerequisite boundary edge_dag.links.len() == 1")
  ret 0
```

---

### `objectiveIsUnlocked` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveIsUnlocked(dag: ObjectiveDependencyDAG, task: str): bool:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dag: ObjectiveDependencyDAG, task: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveIsUnlocked`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `task: str = "aipl_test"`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.dialogue_dag_z10_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveIsUnlocked_10(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_task = "test"
  let edge_task = "a"
  let resNom = objectiveIsUnlocked(arg_dag, arg_task)
  let resEdge = objectiveIsUnlocked(edge_dag, edge_task)
  assert(resNom == true, "objectiveIsUnlocked nominal resNom == true")
  assert(resEdge == true, "objectiveIsUnlocked boundary resEdge == true")
  ret 0
```

---

### `objectiveComplete` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveComplete(mut dag: ObjectiveDependencyDAG, task: str): void:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut dag: ObjectiveDependencyDAG, task: str` | **Returns**: `void`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveComplete`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `task: str = "aipl_test"`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.mechanics.dialogue_dag_z11_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveComplete_11(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_task = "test"
  let edge_task = "a"
  objectiveComplete(arg_dag, arg_task)
  objectiveComplete(edge_dag, edge_task)
  assertEqInt(arg_dag.completedTasks.len(), 1, "objectiveComplete nominal arg_dag.completedTasks.len() == 1")
  assertEqInt(edge_dag.completedTasks.len(), 1, "objectiveComplete boundary edge_dag.completedTasks.len() == 1")
  ret 0
```

---

### `objectiveIsCompleted` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveIsCompleted(dag: ObjectiveDependencyDAG, task: str): bool:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dag: ObjectiveDependencyDAG, task: str` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveIsCompleted`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `task: str = "aipl_test"`; exercises core body path returning/computing `hasFlagInSlice(dag.completedTasks, task)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z12_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveIsCompleted_12(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_task = "test"
  let edge_task = "a"
  let resNom = objectiveIsCompleted(arg_dag, arg_task)
  let resEdge = objectiveIsCompleted(edge_dag, edge_task)
  assert(resNom == false, "objectiveIsCompleted nominal resNom == false")
  assert(resEdge == false, "objectiveIsCompleted boundary resEdge == false")
  ret 0
```

---

### `objectiveGetPrerequisites` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveGetPrerequisites(dag: ObjectiveDependencyDAG, task: str): [str]:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dag: ObjectiveDependencyDAG, task: str` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveGetPrerequisites`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `task: str = "aipl_test"`; exercises core body path returning/computing `prereqs`.

```aipl
module tests.functions.mechanics.dialogue_dag_z13_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveGetPrerequisites_13(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_task = "test"
  let edge_task = "a"
  let resNom = objectiveGetPrerequisites(arg_dag, arg_task)
  let resEdge = objectiveGetPrerequisites(edge_dag, edge_task)
  assertEqInt(resNom.len(), 0, "objectiveGetPrerequisites nominal resNom.len() == 0")
  assertEqInt(resEdge.len(), 0, "objectiveGetPrerequisites boundary resEdge.len() == 0")
  ret 0
```

---

### `objectiveGetAvailableTasks` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveGetAvailableTasks(dag: ObjectiveDependencyDAG, allTasks: [str]): [str]:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dag: ObjectiveDependencyDAG, allTasks: [str]` | **Returns**: `[str]`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveGetAvailableTasks`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `allTasks: [str] = ["aipl_test"]`; exercises core body path returning/computing `avail`.

```aipl
module tests.functions.mechanics.dialogue_dag_z14_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveGetAvailableTasks_14(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_allTasks = ["test"]
  let edge_allTasks = []
  let resNom = objectiveGetAvailableTasks(arg_dag, arg_allTasks)
  let resEdge = objectiveGetAvailableTasks(edge_dag, edge_allTasks)
  assertEqInt(resNom.len(), 1, "objectiveGetAvailableTasks nominal resNom.len() == 1")
  assertEqInt(resEdge.len(), 0, "objectiveGetAvailableTasks boundary resEdge.len() == 0")
  ret 0
```

---

### `objectiveCompletionRatio` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn objectiveCompletionRatio(dag: ObjectiveDependencyDAG, totalTaskCount: int): float:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `dag: ObjectiveDependencyDAG, totalTaskCount: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `objectiveCompletionRatio`. Concrete nominal inputs: `dag: ObjectiveDependencyDAG = ObjectiveDependencyDAG(links = [ObjectivePrereqLink(task = 0, requiredPrereq = 0)], completedTasks = ["aipl_test"])`, `totalTaskCount: int = 64`; exercises core body path returning/computing `clampFloat(float(dag.completedTasks.len) / float(totalTaskCount), 0.0, 1.0)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z15_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_objectiveCompletionRatio_15(): int:
  let arg_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let edge_dag = ObjectiveDependencyDAG(links = [], completedTasks = [])
  let arg_totalTaskCount = 4
  let edge_totalTaskCount = 1
  let resNom = objectiveCompletionRatio(arg_dag, arg_totalTaskCount)
  let resEdge = objectiveCompletionRatio(edge_dag, edge_totalTaskCount)
  assertApproxEq(resNom, 0.0, 0.001, "objectiveCompletionRatio nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "objectiveCompletionRatio boundary resEdge ~= 0.0")
  ret 0
```

---

### `dagCanUnlockNode` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dagCanUnlockNode(node: DagNode, prereqRank: int): bool:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: DagNode, prereqRank: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dagCanUnlockNode`. Concrete nominal inputs: `node: DagNode = DagNode(id = 1, rank = 1, maxRank = 1, prereqId = 1, prereqMinRank = 1, unlocked = true)`, `prereqRank: int = 1`; exercises core body path returning/computing `prereqRank >= node.prereqMinRank`.

```aipl
module tests.functions.mechanics.dialogue_dag_z16_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dagCanUnlockNode_16(): int:
  let arg_node = DagNode(id = 1, rank = 4, maxRank = 4, prereqId = 1, prereqMinRank = 4, unlocked = true)
  let edge_node = DagNode(id = 0, rank = 1, maxRank = 1, prereqId = 0, prereqMinRank = 1, unlocked = false)
  let arg_prereqRank = 4
  let edge_prereqRank = 1
  let resNom = dagCanUnlockNode(arg_node, arg_prereqRank)
  let resEdge = dagCanUnlockNode(edge_node, edge_prereqRank)
  assert(resNom == true, "dagCanUnlockNode nominal resNom == true")
  assert(resEdge == true, "dagCanUnlockNode boundary resEdge == true")
  ret 0
```

---

### `dagAdvanceNodeRank` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dagAdvanceNodeRank(node: DagNode, pointsAvailable: int, prereqRank: int): (DagNode, int):`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `node: DagNode, pointsAvailable: int, prereqRank: int` | **Returns**: `(DagNode, int)`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dagAdvanceNodeRank`. Concrete nominal inputs: `node: DagNode = DagNode(id = 1, rank = 1, maxRank = 1, prereqId = 1, prereqMinRank = 1, unlocked = true)`, `pointsAvailable: int = 1`, `prereqRank: int): (DagNode = int): (DagNode()`, `int: any = 42`; exercises core body path returning/computing `(updated, pointsAvailable - 1)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z17_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dagAdvanceNodeRank_17(): int:
  let arg_node = DagNode(id = 1, rank = 4, maxRank = 4, prereqId = 1, prereqMinRank = 4, unlocked = true)
  let edge_node = DagNode(id = 0, rank = 1, maxRank = 1, prereqId = 0, prereqMinRank = 1, unlocked = false)
  let arg_pointsAvailable = 4
  let edge_pointsAvailable = 1
  let arg_prereqRank = 4
  let edge_prereqRank = 1
  let resNom = dagAdvanceNodeRank(arg_node, arg_pointsAvailable, arg_prereqRank)
  let resEdge = dagAdvanceNodeRank(edge_node, edge_pointsAvailable, edge_prereqRank)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.id, 1, "dagAdvanceNodeRank nominal n_t0.id == 1")
  assertEqInt(e_t0.id, 0, "dagAdvanceNodeRank boundary e_t0.id == 0")
  ret 0
```

---

### `dagCalculateTotalInvested` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn dagCalculateTotalInvested(ranks: [int]): int:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ranks: [int]` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `dagCalculateTotalInvested`. Concrete nominal inputs: `ranks: [int] = [1]`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.mechanics.dialogue_dag_z18_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_dagCalculateTotalInvested_18(): int:
  let arg_ranks = [4]
  let edge_ranks = []
  let resNom = dagCalculateTotalInvested(arg_ranks)
  let resEdge = dagCalculateTotalInvested(edge_ranks)
  assertEqInt(resNom, 4, "dagCalculateTotalInvested nominal resNom == 4")
  assertEqInt(resEdge, 0, "dagCalculateTotalInvested boundary resEdge == 0")
  ret 0
```

---

### `computeSm2NextEasiness` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn computeSm2NextEasiness(ef: float, quality: int): float:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ef: float, quality: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `computeSm2NextEasiness`. Concrete nominal inputs: `ef: float = 1.0`, `quality: int = 1`; exercises core body path returning/computing `maxFloat(1.30, safeEf + delta)`.

```aipl
module tests.functions.mechanics.dialogue_dag_z19_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_computeSm2NextEasiness_19(): int:
  let arg_ef = 1.0
  let edge_ef = 0.5
  let arg_quality = 1
  let edge_quality = 0
  let resNom = computeSm2NextEasiness(arg_ef, arg_quality)
  let resEdge = computeSm2NextEasiness(edge_ef, edge_quality)
  assertApproxEq(resNom, 1.3, 0.001, "computeSm2NextEasiness nominal resNom ~= 1.3")
  assertApproxEq(resEdge, 1.3, 0.001, "computeSm2NextEasiness boundary resEdge ~= 1.3")
  ret 0
```

---

### `computeSm2NextIntervalDays` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn computeSm2NextIntervalDays(repetition: int, prevIntervalDays: int, ef: float, quality: int): int:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `repetition: int, prevIntervalDays: int, ef: float, quality: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `computeSm2NextIntervalDays`. Concrete nominal inputs: `repetition: int = 1`, `prevIntervalDays: int = 1`, `ef: float = 1.0`, `quality: int = 1`; exercises core body path returning/computing `maxInt(1, int(float(prev) * safeEf + 0.5))`.

```aipl
module tests.functions.mechanics.dialogue_dag_z20_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_computeSm2NextIntervalDays_20(): int:
  let arg_repetition = 4
  let edge_repetition = 1
  let arg_prevIntervalDays = 4
  let edge_prevIntervalDays = 1
  let arg_ef = 1.0
  let edge_ef = 0.5
  let arg_quality = 1
  let edge_quality = 0
  let resNom = computeSm2NextIntervalDays(arg_repetition, arg_prevIntervalDays, arg_ef, arg_quality)
  let resEdge = computeSm2NextIntervalDays(edge_repetition, edge_prevIntervalDays, edge_ef, edge_quality)
  assertEqInt(resNom, 1, "computeSm2NextIntervalDays nominal resNom == 1")
  assertEqInt(resEdge, 1, "computeSm2NextIntervalDays boundary resEdge == 1")
  ret 0
```

---

### `computeApmCounter` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn computeApmCounter(validActions: int, elapsedMs: int): int:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `validActions: int, elapsedMs: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `computeApmCounter`. Concrete nominal inputs: `validActions: int = 1`, `elapsedMs: int = 1`; exercises core body path returning/computing `(validActions * 60000) / elapsedMs`.

```aipl
module tests.functions.mechanics.dialogue_dag_z21_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_computeApmCounter_21(): int:
  let arg_validActions = 4
  let edge_validActions = 1
  let arg_elapsedMs = 4
  let edge_elapsedMs = 1
  let resNom = computeApmCounter(arg_validActions, arg_elapsedMs)
  let resEdge = computeApmCounter(edge_validActions, edge_elapsedMs)
  assertEqInt(resNom, 60000, "computeApmCounter nominal resNom == 60000")
  assertEqInt(resEdge, 60000, "computeApmCounter boundary resEdge == 60000")
  ret 0
```

---

### `selectZoneWithHysteresis` (`std/mechanics/dialogue_dag.aipl`)

- **Signature**: `pub fn selectZoneWithHysteresis(currentZone: int, entityX: float, entityY: float, zonesMinX: [float], zonesMinY: [float], zonesMaxX: [float], zonesMaxY: [float], margin: float): int:`
- **Import**: `import * from "std/mechanics/dialogue_dag"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `currentZone: int, entityX: float, entityY: float, zonesMinX: [float], zonesMinY: [float], zonesMaxX: [float], zonesMaxY: [float], margin: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/dialogue_dag_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies branching dialogue choice gating, prerequisite quest DAG unlocking, skill tree rank investment, SM-2 spaced repetition, and Schmitt-trigger hysteresis in `selectZoneWithHysteresis`. Concrete nominal inputs: `currentZone: int = 1`, `entityX: float = 1.0`, `entityY: float = 1.0`, `zonesMinX: [float] = [1.0]`, `zonesMinY: [float] = [1.0]`, `zonesMaxX: [float] = [1.0]`, `zonesMaxY: [float] = [1.0]`, `margin: float = 1.0`; exercises core body path returning/computing `if currentZone >= 0: currentZone else: 0`.

```aipl
module tests.functions.mechanics.dialogue_dag_z22_test
import * from "std/mechanics/dialogue_dag"
import { minInt, maxInt, clampInt, maxFloat, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_dialogue_dag_selectZoneWithHysteresis_22(): int:
  let arg_currentZone = 4
  let edge_currentZone = 1
  let arg_entityX = 1.0
  let edge_entityX = 0.5
  let arg_entityY = 1.0
  let edge_entityY = 0.5
  let arg_zonesMinX = [0.0]
  let edge_zonesMinX = []
  let arg_zonesMinY = [0.0]
  let edge_zonesMinY = []
  let arg_zonesMaxX = [2.0]
  let edge_zonesMaxX = []
  let arg_zonesMaxY = [2.0]
  let edge_zonesMaxY = []
  let arg_margin = 1.0
  let edge_margin = 0.5
  let resNom = selectZoneWithHysteresis(arg_currentZone, arg_entityX, arg_entityY, arg_zonesMinX, arg_zonesMinY, arg_zonesMaxX, arg_zonesMaxY, arg_margin)
  let resEdge = selectZoneWithHysteresis(edge_currentZone, edge_entityX, edge_entityY, edge_zonesMinX, edge_zonesMinY, edge_zonesMaxX, edge_zonesMaxY, edge_margin)
  assertEqInt(resNom, 0, "selectZoneWithHysteresis nominal resNom == 0")
  assertEqInt(resEdge, -1, "selectZoneWithHysteresis boundary resEdge == -1")
  ret 0
```

---

### `resourceLedgerNew` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn resourceLedgerNew(): ResourceLedger:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `none` | **Returns**: `ResourceLedger`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `resourceLedgerNew`. Concrete nominal inputs: zero arguments (`()`); exercises core body path returning/computing `ResourceLedger(accounts = acc)`.

```aipl
module tests.functions.mechanics.economy_ledger_z1_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_resourceLedgerNew_1(): int:
  let resNom = resourceLedgerNew()
  let resEdge = resourceLedgerNew()
  assertEqInt(resNom.accounts.len(), 0, "resourceLedgerNew nominal resNom.accounts.len() == 0")
  assertEqInt(resEdge.accounts.len(), 0, "resourceLedgerNew boundary resEdge.accounts.len() == 0")
  ret 0
```

---

### `ledgerDeposit` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerDeposit(mut ledger: ResourceLedger, account: str, amount: int): void:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ledger: ResourceLedger, account: str, amount: int` | **Returns**: `void`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerDeposit`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `account: str = "aipl_test"`, `amount: int = 1`; exercises core body path returning/computing `void state update`.

```aipl
module tests.functions.mechanics.economy_ledger_z2_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerDeposit_2(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_account = "test"
  let edge_account = "a"
  let arg_amount = 4
  let edge_amount = 1
  ledgerDeposit(arg_ledger, arg_account, arg_amount)
  ledgerDeposit(edge_ledger, edge_account, edge_amount)
  assertEqInt(arg_ledger.accounts.keys().len(), 1, "ledgerDeposit nominal arg_ledger.accounts.keys().len() == 1")
  assertEqInt(edge_ledger.accounts.keys().len(), 1, "ledgerDeposit boundary edge_ledger.accounts.keys().len() == 1")
  ret 0
```

---

### `ledgerGetBalance` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerGetBalance(ledger: ResourceLedger, account: str): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ledger: ResourceLedger, account: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerGetBalance`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `account: str = "aipl_test"`; exercises core body path returning/computing `0`.

```aipl
module tests.functions.mechanics.economy_ledger_z3_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerGetBalance_3(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_account = "test"
  let edge_account = "a"
  let resNom = ledgerGetBalance(arg_ledger, arg_account)
  let resEdge = ledgerGetBalance(edge_ledger, edge_account)
  assertEqInt(resNom, 0, "ledgerGetBalance nominal resNom == 0")
  assertEqInt(resEdge, 0, "ledgerGetBalance boundary resEdge == 0")
  ret 0
```

---

### `ledgerHasFunds` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerHasFunds(ledger: ResourceLedger, account: str, required: int): bool:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ledger: ResourceLedger, account: str, required: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerHasFunds`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `account: str = "aipl_test"`, `required: int = 1`; exercises core body path returning/computing `ledgerGetBalance(ledger, account) >= required`.

```aipl
module tests.functions.mechanics.economy_ledger_z4_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerHasFunds_4(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_account = "test"
  let edge_account = "a"
  let arg_required = 2
  let edge_required = 0
  let resNom = ledgerHasFunds(arg_ledger, arg_account, arg_required)
  let resEdge = ledgerHasFunds(edge_ledger, edge_account, edge_required)
  assert(resNom == false, "ledgerHasFunds nominal resNom == false")
  assert(resEdge == true, "ledgerHasFunds boundary resEdge == true")
  ret 0
```

---

### `ledgerWithdraw` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerWithdraw(mut ledger: ResourceLedger, account: str, amount: int): bool:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ledger: ResourceLedger, account: str, amount: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerWithdraw`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `account: str = "aipl_test"`, `amount: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.economy_ledger_z5_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerWithdraw_5(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_account = "test"
  let edge_account = "a"
  let arg_amount = 4
  let edge_amount = 1
  let resNom = ledgerWithdraw(arg_ledger, arg_account, arg_amount)
  let resEdge = ledgerWithdraw(edge_ledger, edge_account, edge_amount)
  assert(resNom == false, "ledgerWithdraw nominal resNom == false")
  assert(resEdge == false, "ledgerWithdraw boundary resEdge == false")
  ret 0
```

---

### `ledgerTotalSupply` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerTotalSupply(ledger: ResourceLedger): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ledger: ResourceLedger` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerTotalSupply`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.mechanics.economy_ledger_z6_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerTotalSupply_6(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let resNom = ledgerTotalSupply(arg_ledger)
  let resEdge = ledgerTotalSupply(edge_ledger)
  assertEqInt(resNom, 0, "ledgerTotalSupply nominal resNom == 0")
  assertEqInt(resEdge, 0, "ledgerTotalSupply boundary resEdge == 0")
  ret 0
```

---

### `ledgerTransfer` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn ledgerTransfer(mut ledger: ResourceLedger, fromAccount: str, toAccount: str, amount: int): bool:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ledger: ResourceLedger, fromAccount: str, toAccount: str, amount: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `ledgerTransfer`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `fromAccount: str = "aipl_test"`, `toAccount: str = "aipl_test"`, `amount: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.economy_ledger_z7_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_ledgerTransfer_7(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_fromAccount = "test"
  let edge_fromAccount = "a"
  let arg_toAccount = "test"
  let edge_toAccount = "a"
  let arg_amount = 4
  let edge_amount = 1
  let resNom = ledgerTransfer(arg_ledger, arg_fromAccount, arg_toAccount, arg_amount)
  let resEdge = ledgerTransfer(edge_ledger, edge_fromAccount, edge_toAccount, edge_amount)
  assert(resNom == false, "ledgerTransfer nominal resNom == false")
  assert(resEdge == false, "ledgerTransfer boundary resEdge == false")
  ret 0
```

---

### `computeTieredBracketRatePct` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeTieredBracketRatePct(bracket: ProgressiveTaxBracket, totalWealth: int): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bracket: ProgressiveTaxBracket, totalWealth: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeTieredBracketRatePct`. Concrete nominal inputs: `bracket: ProgressiveTaxBracket = ProgressiveTaxBracket(tiers = [TaxBracketTier(threshold = 0, ratePct = 0)])`, `totalWealth: int = 1`; exercises core body path returning/computing `lastTier.ratePct`.

```aipl
module tests.functions.mechanics.economy_ledger_z8_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeTieredBracketRatePct_8(): int:
  let arg_bracket = ProgressiveTaxBracket(tiers = [])
  let edge_bracket = ProgressiveTaxBracket(tiers = [])
  let arg_totalWealth = 2
  let edge_totalWealth = 0
  let resNom = computeTieredBracketRatePct(arg_bracket, arg_totalWealth)
  let resEdge = computeTieredBracketRatePct(edge_bracket, edge_totalWealth)
  assertApproxEq(resNom, 0.0, 0.001, "computeTieredBracketRatePct nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "computeTieredBracketRatePct boundary resEdge ~= 0.0")
  ret 0
```

---

### `computeProgressiveTaxAmount` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeProgressiveTaxAmount(bracket: ProgressiveTaxBracket, grossAmount: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bracket: ProgressiveTaxBracket, grossAmount: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeProgressiveTaxAmount`. Concrete nominal inputs: `bracket: ProgressiveTaxBracket = ProgressiveTaxBracket(tiers = [TaxBracketTier(threshold = 0, ratePct = 0)])`, `grossAmount: int = 1`; exercises core body path returning/computing `int((float(grossAmount) * ratePct) / 100.0 + 0.5)`.

```aipl
module tests.functions.mechanics.economy_ledger_z9_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeProgressiveTaxAmount_9(): int:
  let arg_bracket = ProgressiveTaxBracket(tiers = [])
  let edge_bracket = ProgressiveTaxBracket(tiers = [])
  let arg_grossAmount = 4
  let edge_grossAmount = 1
  let resNom = computeProgressiveTaxAmount(arg_bracket, arg_grossAmount)
  let resEdge = computeProgressiveTaxAmount(edge_bracket, edge_grossAmount)
  assertEqInt(resNom, 0, "computeProgressiveTaxAmount nominal resNom == 0")
  assertEqInt(resEdge, 0, "computeProgressiveTaxAmount boundary resEdge == 0")
  ret 0
```

---

### `computeNetAfterTax` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeNetAfterTax(bracket: ProgressiveTaxBracket, grossAmount: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `bracket: ProgressiveTaxBracket, grossAmount: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeNetAfterTax`. Concrete nominal inputs: `bracket: ProgressiveTaxBracket = ProgressiveTaxBracket(tiers = [TaxBracketTier(threshold = 0, ratePct = 0)])`, `grossAmount: int = 1`; exercises core body path returning/computing `grossAmount - computeProgressiveTaxAmount(bracket, grossAmount)`.

```aipl
module tests.functions.mechanics.economy_ledger_z10_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeNetAfterTax_10(): int:
  let arg_bracket = ProgressiveTaxBracket(tiers = [])
  let edge_bracket = ProgressiveTaxBracket(tiers = [])
  let arg_grossAmount = 4
  let edge_grossAmount = 1
  let resNom = computeNetAfterTax(arg_bracket, arg_grossAmount)
  let resEdge = computeNetAfterTax(edge_bracket, edge_grossAmount)
  assertEqInt(resNom, 4, "computeNetAfterTax nominal resNom == 4")
  assertEqInt(resEdge, 1, "computeNetAfterTax boundary resEdge == 1")
  ret 0
```

---

### `computeCompoundInterest` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeCompoundInterest(principal: float, ratePerPeriod: float, periods: int): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `principal: float, ratePerPeriod: float, periods: int` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeCompoundInterest`. Concrete nominal inputs: `principal: float = 1.0`, `ratePerPeriod: float = 1.0`, `periods: int = 1`; exercises core body path returning/computing `amt`.

```aipl
module tests.functions.mechanics.economy_ledger_z11_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeCompoundInterest_11(): int:
  let arg_principal = 1.0
  let edge_principal = 0.5
  let arg_ratePerPeriod = 2.0
  let edge_ratePerPeriod = 1.0
  let arg_periods = 2
  let edge_periods = 0
  let resNom = computeCompoundInterest(arg_principal, arg_ratePerPeriod, arg_periods)
  let resEdge = computeCompoundInterest(edge_principal, edge_ratePerPeriod, edge_periods)
  assertApproxEq(resNom, 9.0, 0.001, "computeCompoundInterest nominal resNom ~= 9.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeCompoundInterest boundary resEdge ~= 0.5")
  ret 0
```

---

### `computeSupplyDemandPrice` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeSupplyDemandPrice(basePrice: float, supply: int, demand: int, elasticity: float = 0.5): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `basePrice: float, supply: int, demand: int, elasticity: float = 0.5` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeSupplyDemandPrice`. Concrete nominal inputs: `basePrice: float = 1.0`, `supply: int = 1`, `demand: int = 1`, `elasticity: float = 1.0`; exercises core body path returning/computing `maxFloat(0.01, basePrice * clampFloat(adj, 0.1, 10.0))`.

```aipl
module tests.functions.mechanics.economy_ledger_z12_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeSupplyDemandPrice_12(): int:
  let arg_basePrice = 1.0
  let edge_basePrice = 0.5
  let arg_supply = 1
  let edge_supply = 0
  let arg_demand = 4
  let edge_demand = 1
  let arg_elasticity = 1.0
  let edge_elasticity = 0.5
  let resNom = computeSupplyDemandPrice(arg_basePrice, arg_supply, arg_demand, arg_elasticity)
  let resEdge = computeSupplyDemandPrice(edge_basePrice, edge_supply, edge_demand, edge_elasticity)
  assertApproxEq(resNom, 4.0, 0.001, "computeSupplyDemandPrice nominal resNom ~= 4.0")
  assertApproxEq(resEdge, 0.5, 0.001, "computeSupplyDemandPrice boundary resEdge ~= 0.5")
  ret 0
```

---

### `craftingCanFulfill` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn craftingCanFulfill(ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): bool:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `craftingCanFulfill`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `accountPrefix: str = "aipl_test"`, `recipe: CraftingRecipe = CraftingRecipe(recipeId = "127.0.0.1", inputs = [CraftingIngredient(itemTag = 0, amount = 0)], outputs = [CraftingIngredient(itemTag = 0, amount = 0)], craftDurationSec = 0.5)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.economy_ledger_z13_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_craftingCanFulfill_13(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_accountPrefix = "test"
  let edge_accountPrefix = "a"
  let arg_recipe = CraftingRecipe(recipeId = "test", inputs = [], outputs = [], craftDurationSec = 1.0)
  let edge_recipe = CraftingRecipe(recipeId = "a", inputs = [], outputs = [], craftDurationSec = 0.5)
  let resNom = craftingCanFulfill(arg_ledger, arg_accountPrefix, arg_recipe)
  let resEdge = craftingCanFulfill(edge_ledger, edge_accountPrefix, edge_recipe)
  assert(resNom == true, "craftingCanFulfill nominal resNom == true")
  assert(resEdge == true, "craftingCanFulfill boundary resEdge == true")
  ret 0
```

---

### `craftingMaxBatchCount` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn craftingMaxBatchCount(ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `craftingMaxBatchCount`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `accountPrefix: str = "aipl_test"`, `recipe: CraftingRecipe = CraftingRecipe(recipeId = "127.0.0.1", inputs = [CraftingIngredient(itemTag = 0, amount = 0)], outputs = [CraftingIngredient(itemTag = 0, amount = 0)], craftDurationSec = 0.5)`; exercises core body path returning/computing `maxBatches`.

```aipl
module tests.functions.mechanics.economy_ledger_z14_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_craftingMaxBatchCount_14(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_accountPrefix = "test"
  let edge_accountPrefix = "a"
  let arg_recipe = CraftingRecipe(recipeId = "test", inputs = [], outputs = [], craftDurationSec = 1.0)
  let edge_recipe = CraftingRecipe(recipeId = "a", inputs = [], outputs = [], craftDurationSec = 0.5)
  let resNom = craftingMaxBatchCount(arg_ledger, arg_accountPrefix, arg_recipe)
  let resEdge = craftingMaxBatchCount(edge_ledger, edge_accountPrefix, edge_recipe)
  assertEqInt(resNom, 0, "craftingMaxBatchCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "craftingMaxBatchCount boundary resEdge == 0")
  ret 0
```

---

### `craftingExecute` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn craftingExecute(mut ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe): bool:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut ledger: ResourceLedger, accountPrefix: str, recipe: CraftingRecipe` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `craftingExecute`. Concrete nominal inputs: `ledger: ResourceLedger = ResourceLedger(accounts = Map())`, `accountPrefix: str = "aipl_test"`, `recipe: CraftingRecipe = CraftingRecipe(recipeId = "127.0.0.1", inputs = [CraftingIngredient(itemTag = 0, amount = 0)], outputs = [CraftingIngredient(itemTag = 0, amount = 0)], craftDurationSec = 0.5)`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.economy_ledger_z15_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_craftingExecute_15(): int:
  let arg_ledger = ResourceLedger(accounts = {})
  let edge_ledger = ResourceLedger(accounts = {})
  let arg_accountPrefix = "test"
  let edge_accountPrefix = "a"
  let arg_recipe = CraftingRecipe(recipeId = "test", inputs = [], outputs = [], craftDurationSec = 1.0)
  let edge_recipe = CraftingRecipe(recipeId = "a", inputs = [], outputs = [], craftDurationSec = 0.5)
  let resNom = craftingExecute(arg_ledger, arg_accountPrefix, arg_recipe)
  let resEdge = craftingExecute(edge_ledger, edge_accountPrefix, edge_recipe)
  assert(resNom == true, "craftingExecute nominal resNom == true")
  assert(resEdge == true, "craftingExecute boundary resEdge == true")
  ret 0
```

---

### `computeEloRatingDelta` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeEloRatingDelta(ratingA: float, ratingB: float, scoreA: float, kFactor: float): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `ratingA: float, ratingB: float, scoreA: float, kFactor: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeEloRatingDelta`. Concrete nominal inputs: `ratingA: float = 1.0`, `ratingB: float = 1.0`, `scoreA: float = 1.0`, `kFactor: float = 1.0`; exercises core body path returning/computing `kFactor * (scoreA - expectedA)`.

```aipl
module tests.functions.mechanics.economy_ledger_z16_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeEloRatingDelta_16(): int:
  let arg_ratingA = 1.0
  let edge_ratingA = 0.5
  let arg_ratingB = 1.0
  let edge_ratingB = 0.5
  let arg_scoreA = 1.0
  let edge_scoreA = 0.5
  let arg_kFactor = 1.0
  let edge_kFactor = 0.5
  let resNom = computeEloRatingDelta(arg_ratingA, arg_ratingB, arg_scoreA, arg_kFactor)
  let resEdge = computeEloRatingDelta(edge_ratingA, edge_ratingB, edge_scoreA, edge_kFactor)
  assertApproxEq(resNom, 0.5, 0.001, "computeEloRatingDelta nominal resNom ~= 0.5")
  assertApproxEq(resEdge, 0.0, 0.001, "computeEloRatingDelta boundary resEdge ~= 0.0")
  ret 0
```

---

### `recipeKeyCommutative2` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn recipeKeyCommutative2(idA: int, idB: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `idA: int, idB: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `recipeKeyCommutative2`. Concrete nominal inputs: `idA: int = 1`, `idB: int = 1`; exercises core body path returning/computing `lo * 1000 + hi`.

```aipl
module tests.functions.mechanics.economy_ledger_z17_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_recipeKeyCommutative2_17(): int:
  let arg_idA = 1
  let edge_idA = 0
  let arg_idB = 4
  let edge_idB = 1
  let resNom = recipeKeyCommutative2(arg_idA, arg_idB)
  let resEdge = recipeKeyCommutative2(edge_idA, edge_idB)
  assertEqInt(resNom, 1004, "recipeKeyCommutative2 nominal resNom == 1004")
  assertEqInt(resEdge, 1, "recipeKeyCommutative2 boundary resEdge == 1")
  ret 0
```

---

### `recipeKeyCommutative3` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn recipeKeyCommutative3(idA: int, idB: int, idC: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `idA: int, idB: int, idC: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `recipeKeyCommutative3`. Concrete nominal inputs: `idA: int = 1`, `idB: int = 1`, `idC: int = 1`; exercises core body path returning/computing `a * 1000000 + b * 1000 + c`.

```aipl
module tests.functions.mechanics.economy_ledger_z18_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_recipeKeyCommutative3_18(): int:
  let arg_idA = 1
  let edge_idA = 0
  let arg_idB = 4
  let edge_idB = 1
  let arg_idC = 1
  let edge_idC = 0
  let resNom = recipeKeyCommutative3(arg_idA, arg_idB, arg_idC)
  let resEdge = recipeKeyCommutative3(edge_idA, edge_idB, edge_idC)
  assertEqInt(resNom, 1001004, "recipeKeyCommutative3 nominal resNom == 1001004")
  assertEqInt(resEdge, 1, "recipeKeyCommutative3 boundary resEdge == 1")
  ret 0
```

---

### `recipeCombinatorCommutative2` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn recipeCombinatorCommutative2(idA: int, idB: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `idA: int, idB: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `recipeCombinatorCommutative2`. Concrete nominal inputs: `idA: int = 1`, `idB: int = 1`; exercises core body path returning/computing `recipeKeyCommutative2(idA, idB)`.

```aipl
module tests.functions.mechanics.economy_ledger_z19_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_recipeCombinatorCommutative2_19(): int:
  let arg_idA = 1
  let edge_idA = 0
  let arg_idB = 4
  let edge_idB = 1
  let resNom = recipeCombinatorCommutative2(arg_idA, arg_idB)
  let resEdge = recipeCombinatorCommutative2(edge_idA, edge_idB)
  assertEqInt(resNom, 1004, "recipeCombinatorCommutative2 nominal resNom == 1004")
  assertEqInt(resEdge, 1, "recipeCombinatorCommutative2 boundary resEdge == 1")
  ret 0
```

---

### `computeItemCombineRecipeId` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeItemCombineRecipeId(itemIdA: int, itemIdB: int): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `itemIdA: int, itemIdB: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeItemCombineRecipeId`. Concrete nominal inputs: `itemIdA: int = 1`, `itemIdB: int = 1`; exercises core body path returning/computing `recipeKeyCommutative2(itemIdA, itemIdB)`.

```aipl
module tests.functions.mechanics.economy_ledger_z20_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeItemCombineRecipeId_20(): int:
  let arg_itemIdA = 4
  let edge_itemIdA = 1
  let arg_itemIdB = 4
  let edge_itemIdB = 1
  let resNom = computeItemCombineRecipeId(arg_itemIdA, arg_itemIdB)
  let resEdge = computeItemCombineRecipeId(edge_itemIdA, edge_itemIdB)
  assertEqInt(resNom, 4004, "computeItemCombineRecipeId nominal resNom == 4004")
  assertEqInt(resEdge, 1001, "computeItemCombineRecipeId boundary resEdge == 1001")
  ret 0
```

---

### `recipeOutputLevel` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn recipeOutputLevel(charLevel: int, itemLevel: int, biasRatio: float = 0.5): int:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `charLevel: int, itemLevel: int, biasRatio: float = 0.5` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `recipeOutputLevel`. Concrete nominal inputs: `charLevel: int = 1`, `itemLevel: int = 1`, `biasRatio: float = 0.5`; exercises core body path returning/computing `int(float(clvl) * (1.0 - bias) + float(ilvl) * bias)`.

```aipl
module tests.functions.mechanics.economy_ledger_z21_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_recipeOutputLevel_21(): int:
  let arg_charLevel = 2
  let edge_charLevel = 0
  let arg_itemLevel = 4
  let edge_itemLevel = 1
  let arg_biasRatio = 1.0
  let edge_biasRatio = 0.5
  let resNom = recipeOutputLevel(arg_charLevel, arg_itemLevel, arg_biasRatio)
  let resEdge = recipeOutputLevel(edge_charLevel, edge_itemLevel, edge_biasRatio)
  assertEqInt(resNom, 4, "recipeOutputLevel nominal resNom == 4")
  assertEqInt(resEdge, 1, "recipeOutputLevel boundary resEdge == 1")
  ret 0
```

---

### `rateScaledCapacityPerSec` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn rateScaledCapacityPerSec(assignedUnits: int, unitRate: float, tierMult: float): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `assignedUnits: int, unitRate: float, tierMult: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `rateScaledCapacityPerSec`. Concrete nominal inputs: `assignedUnits: int = 1`, `unitRate: float = 1.0`, `tierMult: float = 1.0`; exercises core body path returning/computing `basePerSec * tierMult`.

```aipl
module tests.functions.mechanics.economy_ledger_z22_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_rateScaledCapacityPerSec_22(): int:
  let arg_assignedUnits = 4
  let edge_assignedUnits = 1
  let arg_unitRate = 2.0
  let edge_unitRate = 1.0
  let arg_tierMult = 1.0
  let edge_tierMult = 0.5
  let resNom = rateScaledCapacityPerSec(arg_assignedUnits, arg_unitRate, arg_tierMult)
  let resEdge = rateScaledCapacityPerSec(edge_assignedUnits, edge_unitRate, edge_tierMult)
  assertApproxEq(resNom, 8.0, 0.001, "rateScaledCapacityPerSec nominal resNom ~= 8.0")
  assertApproxEq(resEdge, 0.5, 0.001, "rateScaledCapacityPerSec boundary resEdge ~= 0.5")
  ret 0
```

---

### `forecastMonteCarloQuantile` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn forecastMonteCarloQuantile(p50Base: float, volatilityPct: float, zScore: float): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p50Base: float, volatilityPct: float, zScore: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `forecastMonteCarloQuantile`. Concrete nominal inputs: `p50Base: float = 1.0`, `volatilityPct: float = 1.0`, `zScore: float = 1.0`; exercises core body path returning/computing `maxFloat(0.0, p50Base * (1.0 + vol * zScore))`.

```aipl
module tests.functions.mechanics.economy_ledger_z23_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_forecastMonteCarloQuantile_23(): int:
  let arg_p50Base = 1.0
  let edge_p50Base = 0.5
  let arg_volatilityPct = 1.0
  let edge_volatilityPct = 0.5
  let arg_zScore = 1.0
  let edge_zScore = 0.5
  let resNom = forecastMonteCarloQuantile(arg_p50Base, arg_volatilityPct, arg_zScore)
  let resEdge = forecastMonteCarloQuantile(edge_p50Base, edge_volatilityPct, edge_zScore)
  assertApproxEq(resNom, 1.01, 0.001, "forecastMonteCarloQuantile nominal resNom ~= 1.01")
  assertApproxEq(resEdge, 0.50125, 0.001, "forecastMonteCarloQuantile boundary resEdge ~= 0.50125")
  ret 0
```

---

### `computeMonteCarloPercentile` (`std/mechanics/economy_ledger.aipl`)

- **Signature**: `pub fn computeMonteCarloPercentile(p50Base: float, volatilityPct: float, zScore: float): float:`
- **Import**: `import * from "std/mechanics/economy_ledger"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `p50Base: float, volatilityPct: float, zScore: float` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/economy_ledger_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Tests double-entry resource ledger supply conservation, progressive tax brackets, supply/demand pricing, batch crafting, and Elo rating deltas in `computeMonteCarloPercentile`. Concrete nominal inputs: `p50Base: float = 1.0`, `volatilityPct: float = 1.0`, `zScore: float = 1.0`; exercises core body path returning/computing `forecastMonteCarloQuantile(p50Base, volatilityPct, zScore)`.

```aipl
module tests.functions.mechanics.economy_ledger_z24_test
import * from "std/mechanics/economy_ledger"
import { LN10, clampInt, clampFloat, maxFloat, minInt } from "std/math/consts"
import { exp } from "std/math/trig"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_economy_ledger_computeMonteCarloPercentile_24(): int:
  let arg_p50Base = 1.0
  let edge_p50Base = 0.5
  let arg_volatilityPct = 1.0
  let edge_volatilityPct = 0.5
  let arg_zScore = 1.0
  let edge_zScore = 0.5
  let resNom = computeMonteCarloPercentile(arg_p50Base, arg_volatilityPct, arg_zScore)
  let resEdge = computeMonteCarloPercentile(edge_p50Base, edge_volatilityPct, edge_zScore)
  assertApproxEq(resNom, 1.01, 0.001, "computeMonteCarloPercentile nominal resNom ~= 1.01")
  assertApproxEq(resEdge, 0.50125, 0.001, "computeMonteCarloPercentile boundary resEdge ~= 0.50125")
  ret 0
```

---

### `slotListNew` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListNew(capacity: int): SlotListContainer:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `capacity: int` | **Returns**: `SlotListContainer`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListNew`. Concrete nominal inputs: `capacity: int = 64`; exercises core body path returning/computing `SlotListContainer(capacity = capacity, slots = s)`.

```aipl
module tests.functions.mechanics.inventory_container_z1_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListNew_1(): int:
  let arg_capacity = 4
  let edge_capacity = 1
  let resNom = slotListNew(arg_capacity)
  let resEdge = slotListNew(edge_capacity)
  assertEqInt(resNom.capacity, 4, "slotListNew nominal resNom.capacity == 4")
  assertEqInt(resEdge.capacity, 1, "slotListNew boundary resEdge.capacity == 1")
  ret 0
```

---

### `slotListInsert` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListInsert(mut container: SlotListContainer, item: InventoryItem): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: SlotListContainer, item: InventoryItem` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListInsert`. Concrete nominal inputs: `container: SlotListContainer = SlotListContainer(capacity = 64, slots = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `item: InventoryItem = InventoryItem(id = 1, itemTag = "aipl_test", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 0.5)`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.mechanics.inventory_container_z2_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListInsert_2(): int:
  let arg_container = SlotListContainer(capacity = 4, slots = [])
  let edge_container = SlotListContainer(capacity = 4, slots = [])
  let arg_item = InventoryItem(id = 1, itemTag = "test", quantity = 4, maxStack = 4, gridWidth = 4, gridHeight = 4, unitWeight = 2.0)
  let edge_item = InventoryItem(id = 0, itemTag = "a", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 1.0)
  let resNom = slotListInsert(arg_container, arg_item)
  let resEdge = slotListInsert(edge_container, edge_item)
  assert(resNom == true, "slotListInsert nominal resNom == true")
  assert(resEdge == true, "slotListInsert boundary resEdge == true")
  ret 0
```

---

### `slotListCountTag` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListCountTag(container: SlotListContainer, itemTag: str): int:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SlotListContainer, itemTag: str` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListCountTag`. Concrete nominal inputs: `container: SlotListContainer = SlotListContainer(capacity = 64, slots = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `itemTag: str = "aipl_test"`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.mechanics.inventory_container_z3_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListCountTag_3(): int:
  let arg_container = SlotListContainer(capacity = 4, slots = [])
  let edge_container = SlotListContainer(capacity = 4, slots = [])
  let arg_itemTag = "test"
  let edge_itemTag = "a"
  let resNom = slotListCountTag(arg_container, arg_itemTag)
  let resEdge = slotListCountTag(edge_container, edge_itemTag)
  assertEqInt(resNom, 0, "slotListCountTag nominal resNom == 0")
  assertEqInt(resEdge, 0, "slotListCountTag boundary resEdge == 0")
  ret 0
```

---

### `slotListRemoveQuantity` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListRemoveQuantity(mut container: SlotListContainer, itemTag: str, quantity: int): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: SlotListContainer, itemTag: str, quantity: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListRemoveQuantity`. Concrete nominal inputs: `container: SlotListContainer = SlotListContainer(capacity = 64, slots = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `itemTag: str = "aipl_test"`, `quantity: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.inventory_container_z4_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListRemoveQuantity_4(): int:
  let arg_container = SlotListContainer(capacity = 4, slots = [])
  let edge_container = SlotListContainer(capacity = 4, slots = [])
  let arg_itemTag = "test"
  let edge_itemTag = "a"
  let arg_quantity = 4
  let edge_quantity = 1
  let resNom = slotListRemoveQuantity(arg_container, arg_itemTag, arg_quantity)
  let resEdge = slotListRemoveQuantity(edge_container, edge_itemTag, edge_quantity)
  assert(resNom == false, "slotListRemoveQuantity nominal resNom == false")
  assert(resEdge == false, "slotListRemoveQuantity boundary resEdge == false")
  ret 0
```

---

### `slotListTotalWeight` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListTotalWeight(container: SlotListContainer): float:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SlotListContainer` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListTotalWeight`. Concrete nominal inputs: `container: SlotListContainer = SlotListContainer(capacity = 64, slots = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`; exercises core body path returning/computing `w`.

```aipl
module tests.functions.mechanics.inventory_container_z5_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListTotalWeight_5(): int:
  let arg_container = SlotListContainer(capacity = 4, slots = [])
  let edge_container = SlotListContainer(capacity = 4, slots = [])
  let resNom = slotListTotalWeight(arg_container)
  let resEdge = slotListTotalWeight(edge_container)
  assertApproxEq(resNom, 0.0, 0.001, "slotListTotalWeight nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "slotListTotalWeight boundary resEdge ~= 0.0")
  ret 0
```

---

### `slotListFreeSlotCount` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn slotListFreeSlotCount(container: SlotListContainer): int:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SlotListContainer` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `slotListFreeSlotCount`. Concrete nominal inputs: `container: SlotListContainer = SlotListContainer(capacity = 64, slots = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`; exercises core body path returning/computing `freeCount`.

```aipl
module tests.functions.mechanics.inventory_container_z6_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_slotListFreeSlotCount_6(): int:
  let arg_container = SlotListContainer(capacity = 4, slots = [])
  let edge_container = SlotListContainer(capacity = 4, slots = [])
  let resNom = slotListFreeSlotCount(arg_container)
  let resEdge = slotListFreeSlotCount(edge_container)
  assertEqInt(resNom, 0, "slotListFreeSlotCount nominal resNom == 0")
  assertEqInt(resEdge, 0, "slotListFreeSlotCount boundary resEdge == 0")
  ret 0
```

---

### `spatialMatrixNew` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixNew(cols: int, rows: int): SpatialMatrixContainer2D:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `cols: int, rows: int` | **Returns**: `SpatialMatrixContainer2D`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixNew`. Concrete nominal inputs: `cols: int = 1`, `rows: int = 1`; exercises core body path returning/computing `SpatialMatrixContainer2D(cols = cols, rows = rows, occupiedGrid = grid, items = items)`.

```aipl
module tests.functions.mechanics.inventory_container_z7_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixNew_7(): int:
  let arg_cols = 4
  let edge_cols = 1
  let arg_rows = 4
  let edge_rows = 1
  let resNom = spatialMatrixNew(arg_cols, arg_rows)
  let resEdge = spatialMatrixNew(edge_cols, edge_rows)
  assertEqInt(resNom.cols, 4, "spatialMatrixNew nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 1, "spatialMatrixNew boundary resEdge.cols == 1")
  ret 0
```

---

### `spatialMatrixCanFit` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixCanFit(container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixCanFit`. Concrete nominal inputs: `container: SpatialMatrixContainer2D = SpatialMatrixContainer2D(cols = 1, rows = 1, occupiedGrid = [1], items = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `item: InventoryItem = InventoryItem(id = 1, itemTag = "aipl_test", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 0.5)`, `col: int = 1`, `row: int = 1`, `rotated: bool = true`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.inventory_container_z8_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixCanFit_8(): int:
  let arg_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let edge_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let arg_item = InventoryItem(id = 1, itemTag = "test", quantity = 4, maxStack = 4, gridWidth = 4, gridHeight = 4, unitWeight = 2.0)
  let edge_item = InventoryItem(id = 0, itemTag = "a", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_rotated = true
  let edge_rotated = false
  let resNom = spatialMatrixCanFit(arg_container, arg_item, arg_col, arg_row, arg_rotated)
  let resEdge = spatialMatrixCanFit(edge_container, edge_item, edge_col, edge_row, edge_rotated)
  assert(resNom == false, "spatialMatrixCanFit nominal resNom == false")
  assert(resEdge == false, "spatialMatrixCanFit boundary resEdge == false")
  ret 0
```

---

### `spatialMatrixInsert` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixInsert(mut container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: SpatialMatrixContainer2D, item: InventoryItem, col: int, row: int, rotated: bool` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixInsert`. Concrete nominal inputs: `container: SpatialMatrixContainer2D = SpatialMatrixContainer2D(cols = 1, rows = 1, occupiedGrid = [1], items = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `item: InventoryItem = InventoryItem(id = 1, itemTag = "aipl_test", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 0.5)`, `col: int = 1`, `row: int = 1`, `rotated: bool = true`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.inventory_container_z9_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixInsert_9(): int:
  let arg_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let edge_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let arg_item = InventoryItem(id = 1, itemTag = "test", quantity = 4, maxStack = 4, gridWidth = 4, gridHeight = 4, unitWeight = 2.0)
  let edge_item = InventoryItem(id = 0, itemTag = "a", quantity = 1, maxStack = 1, gridWidth = 1, gridHeight = 1, unitWeight = 1.0)
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let arg_rotated = true
  let edge_rotated = false
  let resNom = spatialMatrixInsert(arg_container, arg_item, arg_col, arg_row, arg_rotated)
  let resEdge = spatialMatrixInsert(edge_container, edge_item, edge_col, edge_row, edge_rotated)
  assert(resNom == false, "spatialMatrixInsert nominal resNom == false")
  assert(resEdge == false, "spatialMatrixInsert boundary resEdge == false")
  ret 0
```

---

### `spatialMatrixRemoveAt` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixRemoveAt(mut container: SpatialMatrixContainer2D, col: int, row: int): SpatialMatrixContainer2D:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: SpatialMatrixContainer2D, col: int, row: int` | **Returns**: `SpatialMatrixContainer2D`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixRemoveAt`. Concrete nominal inputs: `container: SpatialMatrixContainer2D = SpatialMatrixContainer2D(cols = 1, rows = 1, occupiedGrid = [1], items = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`, `col: int = 1`, `row: int = 1`; exercises core body path returning/computing `container`.

```aipl
module tests.functions.mechanics.inventory_container_z10_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixRemoveAt_10(): int:
  let arg_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let edge_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let arg_col = 1
  let edge_col = 0
  let arg_row = 1
  let edge_row = 0
  let resNom = spatialMatrixRemoveAt(arg_container, arg_col, arg_row)
  let resEdge = spatialMatrixRemoveAt(edge_container, edge_col, edge_row)
  assertEqInt(resNom.cols, 4, "spatialMatrixRemoveAt nominal resNom.cols == 4")
  assertEqInt(resEdge.cols, 4, "spatialMatrixRemoveAt boundary resEdge.cols == 4")
  ret 0
```

---

### `spatialMatrixOccupiedCells` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixOccupiedCells(container: SpatialMatrixContainer2D): int:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SpatialMatrixContainer2D` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixOccupiedCells`. Concrete nominal inputs: `container: SpatialMatrixContainer2D = SpatialMatrixContainer2D(cols = 1, rows = 1, occupiedGrid = [1], items = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.mechanics.inventory_container_z11_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixOccupiedCells_11(): int:
  let arg_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let edge_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let resNom = spatialMatrixOccupiedCells(arg_container)
  let resEdge = spatialMatrixOccupiedCells(edge_container)
  assertEqInt(resNom, 0, "spatialMatrixOccupiedCells nominal resNom == 0")
  assertEqInt(resEdge, 0, "spatialMatrixOccupiedCells boundary resEdge == 0")
  ret 0
```

---

### `spatialMatrixTotalWeight` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn spatialMatrixTotalWeight(container: SpatialMatrixContainer2D): float:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: SpatialMatrixContainer2D` | **Returns**: `float`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `spatialMatrixTotalWeight`. Concrete nominal inputs: `container: SpatialMatrixContainer2D = SpatialMatrixContainer2D(cols = 1, rows = 1, occupiedGrid = [1], items = [InventoryItem(id = 0, itemTag = 0, quantity = 0, maxStack = 0, gridWidth = 0, gridHeight = 0, unitWeight = 0)])`; exercises core body path returning/computing `total`.

```aipl
module tests.functions.mechanics.inventory_container_z12_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_spatialMatrixTotalWeight_12(): int:
  let arg_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let edge_container = SpatialMatrixContainer2D(cols = 4, rows = 4, occupiedGrid = [], items = [])
  let resNom = spatialMatrixTotalWeight(arg_container)
  let resEdge = spatialMatrixTotalWeight(edge_container)
  assertApproxEq(resNom, 0.0, 0.001, "spatialMatrixTotalWeight nominal resNom ~= 0.0")
  assertApproxEq(resEdge, 0.0, 0.001, "spatialMatrixTotalWeight boundary resEdge ~= 0.0")
  ret 0
```

---

### `weightedLootTableNew` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn weightedLootTableNew(entries: [WeightedLootEntry]): WeightedLootTable:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entries: [WeightedLootEntry]` | **Returns**: `WeightedLootTable`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `weightedLootTableNew`. Concrete nominal inputs: `entries: [WeightedLootEntry] = [WeightedLootEntry(itemTag = "aipl_test", weight = 0.5, minQuantity = 1, maxQuantity = 1)]`; exercises core body path returning/computing `WeightedLootTable(entries = entries, totalWeight = sumW)`.

```aipl
module tests.functions.mechanics.inventory_container_z13_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_weightedLootTableNew_13(): int:
  let arg_entries = [WeightedLootEntry(itemTag = "test", weight = 2.0, minQuantity = 4, maxQuantity = 4)]
  let edge_entries = []
  let resNom = weightedLootTableNew(arg_entries)
  let resEdge = weightedLootTableNew(edge_entries)
  assertApproxEq(resNom.totalWeight, 2.0, 0.001, "weightedLootTableNew nominal resNom.totalWeight ~= 2.0")
  assertApproxEq(resEdge.totalWeight, 0.0, 0.001, "weightedLootTableNew boundary resEdge.totalWeight ~= 0.0")
  ret 0
```

---

### `weightedLootTableRoll` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn weightedLootTableRoll(table: WeightedLootTable, roll01: float): Option[WeightedLootEntry]:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `table: WeightedLootTable, roll01: float` | **Returns**: `Option[WeightedLootEntry]`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `weightedLootTableRoll`. Concrete nominal inputs: `table: WeightedLootTable = WeightedLootTable(entries = [WeightedLootEntry(itemTag = 0, weight = 0, minQuantity = 0, maxQuantity = 0)], totalWeight = 0.5)`, `roll01: float = 1.0`; exercises core body path returning/computing `None`.

```aipl
module tests.functions.mechanics.inventory_container_z14_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_weightedLootTableRoll_14(): int:
  let arg_table = WeightedLootTable(entries = [], totalWeight = 2.0)
  let edge_table = WeightedLootTable(entries = [], totalWeight = 1.0)
  let arg_roll01 = 1.0
  let edge_roll01 = 0.5
  let resNom = weightedLootTableRoll(arg_table, arg_roll01)
  let resEdge = weightedLootTableRoll(edge_table, edge_roll01)
  assert(resNom.isSome() == false, "weightedLootTableRoll nominal resNom.isSome() == false")
  assert(resEdge.isSome() == false, "weightedLootTableRoll boundary resEdge.isSome() == false")
  ret 0
```

---

### `weightedLootRollQuantity` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn weightedLootRollQuantity(entry: WeightedLootEntry, roll01: float): int:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `entry: WeightedLootEntry, roll01: float` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `weightedLootRollQuantity`. Concrete nominal inputs: `entry: WeightedLootEntry = WeightedLootEntry(itemTag = "aipl_test", weight = 0.5, minQuantity = 1, maxQuantity = 1)`, `roll01: float = 1.0`; exercises core body path returning/computing `lo + int(float(hi - lo) * r + 0.5)`.

```aipl
module tests.functions.mechanics.inventory_container_z15_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_weightedLootRollQuantity_15(): int:
  let arg_entry = WeightedLootEntry(itemTag = "test", weight = 2.0, minQuantity = 4, maxQuantity = 4)
  let edge_entry = WeightedLootEntry(itemTag = "a", weight = 1.0, minQuantity = 1, maxQuantity = 1)
  let arg_roll01 = 1.0
  let edge_roll01 = 0.5
  let resNom = weightedLootRollQuantity(arg_entry, arg_roll01)
  let resEdge = weightedLootRollQuantity(edge_entry, edge_roll01)
  assertEqInt(resNom, 4, "weightedLootRollQuantity nominal resNom == 4")
  assertEqInt(resEdge, 1, "weightedLootRollQuantity boundary resEdge == 1")
  ret 0
```

---

### `inventorySlotNew` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventorySlotNew(itemId: int = 0, quantity: int = 0, maxStack: int = 99, flags: int = 0): InventorySlot:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `itemId: int = 0, quantity: int = 0, maxStack: int = 99, flags: int = 0` | **Returns**: `InventorySlot`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventorySlotNew`. Concrete nominal inputs: `itemId: int = 1`, `quantity: int = 1`, `maxStack: int = 1`, `flags: int = 1`; exercises core body path returning/computing `InventorySlot(itemId = itemId, quantity = quantity, maxStack = maxStack, flags = flags)`.

```aipl
module tests.functions.mechanics.inventory_container_z16_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventorySlotNew_16(): int:
  let arg_itemId = 4
  let edge_itemId = 1
  let arg_quantity = 4
  let edge_quantity = 1
  let arg_maxStack = 4
  let edge_maxStack = 1
  let arg_flags = 1
  let edge_flags = 0
  let resNom = inventorySlotNew(arg_itemId, arg_quantity, arg_maxStack, arg_flags)
  let resEdge = inventorySlotNew(edge_itemId, edge_quantity, edge_maxStack, edge_flags)
  assertEqInt(resNom.itemId, 4, "inventorySlotNew nominal resNom.itemId == 4")
  assertEqInt(resEdge.itemId, 1, "inventorySlotNew boundary resEdge.itemId == 1")
  ret 0
```

---

### `inventorySlotIsEmpty` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventorySlotIsEmpty(slot: InventorySlot): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `slot: InventorySlot` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventorySlotIsEmpty`. Concrete nominal inputs: `slot: InventorySlot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 1)`; exercises core body path returning/computing `slot.itemId <= 0 or slot.quantity <= 0`.

```aipl
module tests.functions.mechanics.inventory_container_z17_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventorySlotIsEmpty_17(): int:
  let arg_slot = InventorySlot(itemId = 4, quantity = 4, maxStack = 4, flags = 0)
  let edge_slot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 0)
  let resNom = inventorySlotIsEmpty(arg_slot)
  let resEdge = inventorySlotIsEmpty(edge_slot)
  assert(resNom == false, "inventorySlotIsEmpty nominal resNom == false")
  assert(resEdge == false, "inventorySlotIsEmpty boundary resEdge == false")
  ret 0
```

---

### `inventoryContainerNew` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryContainerNew(width: int, height: int, defaultMaxStack: int = 99): InventoryContainer:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `width: int, height: int, defaultMaxStack: int = 99` | **Returns**: `InventoryContainer`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryContainerNew`. Concrete nominal inputs: `width: int = 128`, `height: int = 128`, `defaultMaxStack: int = 1`; exercises core body path returning/computing `InventoryContainer(width = w, height = h, slots = s)`.

```aipl
module tests.functions.mechanics.inventory_container_z18_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryContainerNew_18(): int:
  let arg_width = 4
  let edge_width = 1
  let arg_height = 4
  let edge_height = 1
  let arg_defaultMaxStack = 4
  let edge_defaultMaxStack = 1
  let resNom = inventoryContainerNew(arg_width, arg_height, arg_defaultMaxStack)
  let resEdge = inventoryContainerNew(edge_width, edge_height, edge_defaultMaxStack)
  assertEqInt(resNom.width, 4, "inventoryContainerNew nominal resNom.width == 4")
  assertEqInt(resEdge.width, 1, "inventoryContainerNew boundary resEdge.width == 1")
  ret 0
```

---

### `inventorySlotCanAccept` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventorySlotCanAccept(slot: InventorySlot, itemId: int, qty: int): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `slot: InventorySlot, itemId: int, qty: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventorySlotCanAccept`. Concrete nominal inputs: `slot: InventorySlot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 1)`, `itemId: int = 1`, `qty: int = 1`; exercises core body path returning/computing `false`.

```aipl
module tests.functions.mechanics.inventory_container_z19_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventorySlotCanAccept_19(): int:
  let arg_slot = InventorySlot(itemId = 4, quantity = 4, maxStack = 4, flags = 0)
  let edge_slot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 0)
  let arg_itemId = 4
  let edge_itemId = 1
  let arg_qty = 1
  let edge_qty = 0
  let resNom = inventorySlotCanAccept(arg_slot, arg_itemId, arg_qty)
  let resEdge = inventorySlotCanAccept(edge_slot, edge_itemId, edge_qty)
  assert(resNom == false, "inventorySlotCanAccept nominal resNom == false")
  assert(resEdge == false, "inventorySlotCanAccept boundary resEdge == false")
  ret 0
```

---

### `inventoryContainerGetSlot` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryContainerGetSlot(container: InventoryContainer, x: int, y: int): InventorySlot:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: InventoryContainer, x: int, y: int` | **Returns**: `InventorySlot`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryContainerGetSlot`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `x: int = 1`, `y: int = 1`; exercises core body path returning/computing `container.slots[y * container.width + x]`.

```aipl
module tests.functions.mechanics.inventory_container_z20_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryContainerGetSlot_20(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let resNom = inventoryContainerGetSlot(arg_container, arg_x, arg_y)
  let resEdge = inventoryContainerGetSlot(edge_container, edge_x, edge_y)
  assertEqStr(str(resNom.itemId), "nil", "inventoryContainerGetSlot nominal str(resNom.itemId) == nil")
  assertEqStr(str(resEdge.itemId), "nil", "inventoryContainerGetSlot boundary str(resEdge.itemId) == nil")
  ret 0
```

---

### `inventoryContainerSetSlot` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryContainerSetSlot(mut container: InventoryContainer, x: int, y: int, slot: InventorySlot): InventoryContainer:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: InventoryContainer, x: int, y: int, slot: InventorySlot` | **Returns**: `InventoryContainer`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryContainerSetSlot`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `x: int = 1`, `y: int = 1`, `slot: InventorySlot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 1)`; exercises core body path returning/computing `container`.

```aipl
module tests.functions.mechanics.inventory_container_z21_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryContainerSetSlot_21(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_x = 1
  let edge_x = 0
  let arg_y = 1
  let edge_y = 0
  let arg_slot = InventorySlot(itemId = 4, quantity = 4, maxStack = 4, flags = 0)
  let edge_slot = InventorySlot(itemId = 1, quantity = 1, maxStack = 1, flags = 0)
  let resNom = inventoryContainerSetSlot(arg_container, arg_x, arg_y, arg_slot)
  let resEdge = inventoryContainerSetSlot(edge_container, edge_x, edge_y, edge_slot)
  assertEqInt(resNom.width, 4, "inventoryContainerSetSlot nominal resNom.width == 4")
  assertEqInt(resEdge.width, 4, "inventoryContainerSetSlot boundary resEdge.width == 4")
  ret 0
```

---

### `inventoryContainerAddItem` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryContainerAddItem(mut container: InventoryContainer, itemId: int, quantity: int): (InventoryContainer, int):`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: InventoryContainer, itemId: int, quantity: int` | **Returns**: `(InventoryContainer, int)`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryContainerAddItem`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `itemId: int = 1`, `quantity: int): (InventoryContainer = int): (InventoryContainer()`, `int: any = 42`; exercises core body path returning/computing `(container, remaining)`.

```aipl
module tests.functions.mechanics.inventory_container_z22_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryContainerAddItem_22(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_itemId = 4
  let edge_itemId = 1
  let arg_quantity = 4
  let edge_quantity = 1
  let resNom = inventoryContainerAddItem(arg_container, arg_itemId, arg_quantity)
  let resEdge = inventoryContainerAddItem(edge_container, edge_itemId, edge_quantity)
  let (n_t0, n_t1) = resNom
  let (e_t0, e_t1) = resEdge
  assertEqInt(n_t0.width, 4, "inventoryContainerAddItem nominal n_t0.width == 4")
  assertEqInt(e_t0.width, 4, "inventoryContainerAddItem boundary e_t0.width == 4")
  ret 0
```

---

### `inventoryContainerCountItem` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryContainerCountItem(container: InventoryContainer, itemId: int): int:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: InventoryContainer, itemId: int` | **Returns**: `int`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_246_mechanics_attribute_modifier_sheet_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryContainerCountItem`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `itemId: int = 1`; exercises core body path returning/computing `count`.

```aipl
module tests.functions.mechanics.inventory_container_z23_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryContainerCountItem_23(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_itemId = 4
  let edge_itemId = 1
  let resNom = inventoryContainerCountItem(arg_container, arg_itemId)
  let resEdge = inventoryContainerCountItem(edge_container, edge_itemId)
  assertEqInt(resNom, 0, "inventoryContainerCountItem nominal resNom == 0")
  assertEqInt(resEdge, 0, "inventoryContainerCountItem boundary resEdge == 0")
  ret 0
```

---

### `inventoryCanPlaceItem2D` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryCanPlaceItem2D(container: InventoryContainer, itemW: int, itemH: int, startX: int, startY: int): bool:`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `container: InventoryContainer, itemW: int, itemH: int, startX: int, startY: int` | **Returns**: `bool`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_244_ai_vector_embedding_rag_search_cli.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryCanPlaceItem2D`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `itemW: int = 1`, `itemH: int = 1`, `startX: int = 1`, `startY: int = 1`; exercises core body path returning/computing `true`.

```aipl
module tests.functions.mechanics.inventory_container_z24_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryCanPlaceItem2D_24(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_itemW = 4
  let edge_itemW = 1
  let arg_itemH = 4
  let edge_itemH = 1
  let arg_startX = 1
  let edge_startX = 0
  let arg_startY = 1
  let edge_startY = 0
  let resNom = inventoryCanPlaceItem2D(arg_container, arg_itemW, arg_itemH, arg_startX, arg_startY)
  let resEdge = inventoryCanPlaceItem2D(edge_container, edge_itemW, edge_itemH, edge_startX, edge_startY)
  assert(resNom == false, "inventoryCanPlaceItem2D nominal resNom == false")
  assert(resEdge == true, "inventoryCanPlaceItem2D boundary resEdge == true")
  ret 0
```

---

### `inventoryPackItem2D` (`std/mechanics/inventory_container.aipl`)

- **Signature**: `pub fn inventoryPackItem2D(mut container: InventoryContainer, itemW: int, itemH: int, itemId: int): (InventoryContainer, bool, int, int):`
- **Import**: `import * from "std/mechanics/inventory_container"` (or barrel `import * from "std/mechanics/mechanics_mod"`)
- **Receiver**: `None (free function)` | **Parameters**: `mut container: InventoryContainer, itemW: int, itemH: int, itemId: int` | **Returns**: `(InventoryContainer, bool, int, int)`
- **Unit Test**: `tests/functions/mechanics/inventory_container_test.aipl` | **Example**: `examples/ex_245_ai_hebar_referee_flow_corridor_window.aipl`
- **Behavioral Summary**: Verifies 1D slot lists, 2D spatial matrix item packing/rotation, stack overflow splitting, and weighted loot table rolls in `inventoryPackItem2D`. Concrete nominal inputs: `container: InventoryContainer = InventoryContainer(width = 128, height = 128, slots = [InventorySlot(itemId = 0, quantity = 0, maxStack = 0, flags = 0)])`, `itemW: int = 1`, `itemH: int = 1`, `itemId: int): (InventoryContainer = int): (InventoryContainer()`, `bool: any = 42`, `int: any = 42`, `int: any = 42`; exercises core body path returning/computing `(container, false, -1, -1)`.

```aipl
module tests.functions.mechanics.inventory_container_z25_test
import * from "std/mechanics/inventory_container"
import { minInt, maxInt, clampFloat } from "std/math/consts"
import { Option, Result, Some, None, Ok, Err, assert, assertEqInt, assertEqStr, assertApproxEq } from "std/prelude"
pub fn test_inventory_container_inventoryPackItem2D_25(): int:
  let arg_container = InventoryContainer(width = 4, height = 4, slots = [])
  let edge_container = InventoryContainer(width = 4, height = 4, slots = [])
  let arg_itemW = 4
  let edge_itemW = 1
  let arg_itemH = 4
  let edge_itemH = 1
  let arg_itemId = 4
  let edge_itemId = 1
  let resNom = inventoryPackItem2D(arg_container, arg_itemW, arg_itemH, arg_itemId)
  let resEdge = inventoryPackItem2D(edge_container, edge_itemW, edge_itemH, edge_itemId)
  let (n_t0, n_t1, n_t2, n_t3) = resNom
  let (e_t0, e_t1, e_t2, e_t3) = resEdge
  assertEqInt(n_t0.width, 4, "inventoryPackItem2D nominal n_t0.width == 4")
  assertEqInt(e_t0.width, 4, "inventoryPackItem2D boundary e_t0.width == 4")
  ret 0
```
