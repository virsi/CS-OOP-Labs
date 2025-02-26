#include "interaction.hpp"
#include <cstring>
#include <iostream>

namespace {
    const int BUF_SIZE = 512;

    bool isValidEntityType(int v) {
        return v > 0 && v < 3;
    }

    bool isValidDatabaseInteractionType(int v) {
        return v > 0 && v < 7;
    }
}  // namespace

namespace interaction {
    EntityType ReadEntityInteractionType() {
        int type = 0;
        while (!isValidEntityType(type)) {
            std::cout << "Введите тип сущности (1 - планета, 2 - компьтер): ";
            std::cin >> type;

            if (!isValidEntityType(type)) {
                std::cout << "Некорректный тип сущности!" << std::endl;
            }
        }

        return static_cast<EntityType>(type);
    }

    char* ReadFilepath(EntityType entityType) {
        char filepath[BUF_SIZE];

        switch (entityType) {
            case EntityType::Planet:
                std::cout << "Введите путь к базе данных планет: ";
                break;
            case EntityType::Computer:
                std::cout << "Введите путь к базе данных компьютеров: ";
                break;
        }

        std::cin >> filepath;

        char* filepathCopy = new char[std::strlen(filepath) + 1];
        std::strncpy(filepathCopy, filepath, std::strlen(filepath) + 1);

        return filepathCopy;
    }

    planet::Planet* ReadPlanetEntity() {
        int id = -1;

        char name[BUF_SIZE];
        int diameter = 0;
        bool hasLife = false;
        int satellites = 0;

        std::cout << "Название планеты: ";
        std::cin >> name;
        std::cout << "Диаметр: ";
        std::cin >> diameter;
        std::cout << "Есть жизнь? (1 - да, 0 - нет): ";
        std::cin >> hasLife;
        std::cout << "Кол-во спутников: ";
        std::cin >> satellites;

        return new planet::Planet(id, name, diameter, hasLife, satellites);
    }

    planet::Planet** ReadMultiplePlanetEntity(int& n) {
        std::cout << "Введите количество сущностей: ";
        std::cin >> n;

        planet::Planet** planets = new planet::Planet*[n];
        for (int i = 0; i < n; ++i) {
            std::cout << '\n' << "Сущность №" << i + 1 << '\n';
            planets[i] = interaction::ReadPlanetEntity();
        }

        return planets;
    }

    computer::Computer* ReadComputerEntity() {
        char os[BUF_SIZE];
        char serialNumber[BUF_SIZE];
        int frequencyCPU = 0;
        int ram = 0;
        int rom = 0;

        std::cout << "Операционная система: ";
        std::cin >> os;
        std::cout << "Серийный номер компьютера: ";
        std::cin >> serialNumber;
        std::cout << "Тактовая частота процессора: ";
        std::cin >> frequencyCPU;
        std::cout << "Объем оперативной памяти: ";
        std::cin >> ram;
        std::cout << "Объем накопителя: ";
        std::cin >> rom;

        return new computer::Computer(-1, os, serialNumber, frequencyCPU, ram, rom);
    }

    computer::Computer** ReadMultipleShopEntity(int& n) {
        std::cout << "Введите количество сущностей: ";
        std::cin >> n;

        computer::Computer** computers = new computer::Computer*[n];
        for (int i = 0; i < n; ++i) {
            std::cout << '\n' << "Сущность №" << i + 1 << '\n';
            computers[i] = interaction::ReadComputerEntity();
        }

        return computers;
    }

    DatabaseInteractionType ReadDatabaseInteractionType() {
        int type = 0;
        while (!isValidDatabaseInteractionType(type)) {
            std::cout << "Введите тип действия (1 - прочитать базу данных, 2 - перезаписать, 3 - "
                         "добавить, 4 - "
                         "удалить, 5 - сортировать, 6 - выйти): ";
            std::cin >> type;

            if (!isValidDatabaseInteractionType(type)) {
                std::cout << "Некорректный тип действия!" << std::endl;
            }
        }

        return static_cast<DatabaseInteractionType>(type);
    }

    int ReadEntityId() {
        int id = 0;
        std::cout << "Введите ID сущности: ";
        std::cin >> id;
        return id;
    }
}  // namespace interaction
