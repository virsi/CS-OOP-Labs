#pragma once
#include "../planet/planet.hpp"
#include "../computer/computer.hpp"

namespace interaction {
    enum class EntityType { Planet = 1, Computer = 2 };
    EntityType ReadEntityInteractionType();
    char* ReadFilepath(EntityType);

    planet::Planet* ReadPlanetEntity();
    planet::Planet** ReadMultiplePlanetEntity(int& n);
    computer::Computer* ReadComputerEntity();
    computer::Computer** ReadMultipleShopEntity(int& n);

    enum class DatabaseInteractionType {
        Print = 1,
        Write = 2,
        Append = 3,
        Remove = 4,
        Sort = 5,
        Exit = 6
    };

    DatabaseInteractionType ReadDatabaseInteractionType();
    int ReadEntityId();
}  // namespace interaction
