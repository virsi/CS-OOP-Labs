#include <iostream>
#include "planet/dbplanets.hpp"
#include "computer/dbcomputers.hpp"
#include "interaction/interaction.hpp"
#include "planet/planet.hpp"
#include "computer/computer.hpp"

int main() {
    auto interactionEntity = interaction::ReadEntityInteractionType();
    char* filepath = interaction::ReadFilepath(interactionEntity);

    bool shouldExit = false;
    while (!shouldExit) {
        if (interactionEntity == interaction::EntityType::Planet) {
            switch (interaction::ReadDatabaseInteractionType()) {
                case interaction::DatabaseInteractionType::Print:
                    dbplanets::Print(filepath);
                    break;
                case interaction::DatabaseInteractionType::Write: {
                    int n = 0;
                    planet::Planet** planets = interaction::ReadMultiplePlanetEntity(n);

                    dbplanets::Write(filepath, planets, n);
                    delete[] planets;
                    break;
                }
                case interaction::DatabaseInteractionType::Append:
                    dbplanets::Append(filepath, interaction::ReadPlanetEntity());
                    break;
                case interaction::DatabaseInteractionType::Remove:
                    dbplanets::Remove(filepath, interaction::ReadEntityId());
                    break;
                case interaction::DatabaseInteractionType::Sort:
                    dbplanets::Sort(filepath);
                    std::cout << "Таблицы отсортированы" << std::endl;
                    break;
                case interaction::DatabaseInteractionType::Exit:
                    std::cout << "Завершение программы" << std::endl;
                    shouldExit = true;
            }

            continue;
        }

        if (interactionEntity == interaction::EntityType::Computer) {
            switch (interaction::ReadDatabaseInteractionType()) {
                case interaction::DatabaseInteractionType::Print:
                    dbcomputers::Print(filepath);
                    break;
                case interaction::DatabaseInteractionType::Write: {
                    int n = 0;
                    computer::Computer** computers = interaction::ReadMultipleShopEntity(n);

                    dbcomputers::Write(filepath, computers, n);
                    delete[] computers;

                    break;
                }
                case interaction::DatabaseInteractionType::Append:
                    dbcomputers::Append(filepath, interaction::ReadComputerEntity());
                    break;
                case interaction::DatabaseInteractionType::Remove:
                    dbcomputers::Remove(filepath, interaction::ReadEntityId());
                    break;
                case interaction::DatabaseInteractionType::Sort:
                    dbcomputers::Sort(filepath);
                    break;
                case interaction::DatabaseInteractionType::Exit:
                    std::cout << "Завершение программы" << std::endl;
                    shouldExit = true;
            }
        }
    }

    delete[] filepath;
}
