# Bird Simulator

## Birds
### Area #1 : North America
* Bird #1: Golden Eagle
    - Builds nests using twigs, grass, and feathers.
    - Exhibits seasonal behaviors: courtship, raising chicks, and migration.
* Bird #2: White-tailed Eagle
    - Builds nests using twigs, bark, and leaves.
    - Exhibits seasonal behaviors: courtship, raising chicks, and migration.

### Area #2: New Zealand (or Oceania)
* Bird #1: Kea
    - Builds nests using roots, moss, and feathers.
    - Exhibits seasonal behaviors: finding mates, raising fledglings, and storing energy.
* Bird #2: Kākāriki
    - Builds nests using twigs, leaves, and grass.
    - Exhibits seasonal behaviors: breeding, raising fledglings, and survival strategies.

## Activities
### Spring
* Activity:
    - Golden Eagle: Begins courtship and nesting.
    - White-tailed Eagle: Starts courtship and lays eggs.
    - Kea: Breeds and builds nests under rocks.
    - Kākāriki: Breeds and nests in tree cavities.

### Summer
* Activity:
    - Golden Eagle: Raises chicks and feeds them.
    - White-tailed Eagle: Feeds and raises young chicks.
    - Kea: Forages for fruits and feeds chicks.
    - Kākāriki: Feeds fledglings with seeds and nectar.

### Fall
* Activity:
    - Golden Eagle: Migrates to warmer regions.
    - White-tailed Eagle: Prepares for migration to coastal areas.
    - Kea: Moves to lower altitudes to forage.
    - Kākāriki: Focuses on storing energy for winter.


### Winter
* Activity:
    Golden Eagle: Hunts small mammals in wintering grounds.
    White-tailed Eagle: Maintains its territory and hunts.
    Kea: Scavenges for food in harsh conditions.
    Kākāriki: Relies on stored seeds and forages opportunistically.

## Design Patterns
### Pattern 1: Factory Pattern
* Role : BirdFactoryBase
    - BirdFactoryBase.createBird() : Creates Bird objects dynamically based on JSON data.
* Implementation:
    - EagleFactory and ParrotFactory extend BirdFactoryBase.
### Pattern 2: Builder Pattern
* Role: NestBuilder
    - Bird.buildNest(NestBuilder) : Calls ConcreteNestBuilder.addMaterial() to construct the nest.
* Implementation:
    - ConcreteNestBuilder handles material addition and nest finalization.
### Pattern 3: Strategy Pattern

* Role: SeasonalBehavior
    - Bird.performSeasonalActivity(season) : Calls SeasonalBehavior.execute() dynamically based on the season.
* Implementation:
    - EagleSpringBehavior, ParrotWinterBehavior, etc., provide specific behavior implementations.



