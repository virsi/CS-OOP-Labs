#include "interaction.hpp"
#include <cstring>
#include <iostream>
#include <limits>


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
            std::cout << "Введите сущность \n 1 - планета, \n 2 - компьтер ";
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
        // Проверка на кириллицу
        while (!std::isalpha(os[0])) {
            std::cout << "Некорректный ввод. Пожалуйста, введите имя операционной системы снова: ";
            std::cin >> os;
        }

        std::cout << "Серийный номер компьютера: ";
        std::cin >> serialNumber;
        // Проверка на кириллицу
        while (!std::isalnum(serialNumber[0])) {
            std::cout << "Некорректный ввод. Пожалуйста, введите серийный номер снова: ";
            std::cin >> serialNumber;
        }

        std::cout << "Тактовая частота процессора: ";
        while (!(std::cin >> frequencyCPU)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число для тактовой частоты процессора: ";
            std::cin.clear(); // Очистка флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Игнорируем неправильный ввод
        }

        std::cout << "Объем оперативной памяти: ";
        while (!(std::cin >> ram)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число для объема оперативной памяти: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Объем накопителя: ";
        while (!(std::cin >> rom)) {
            std::cout << "Некорректный ввод. Пожалуйста, введите целое число для объема накопителя: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

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

        // Цикл продолжается, пока не будет введен корректный тип действия
        while (!isValidDatabaseInteractionType(type)) {
            std::cout << "Введите тип действия\n"
                      << "1 - прочитать базу данных,\n"
                      << "2 - перезаписать,\n"
                      << "3 - добавить,\n"
                      << "4 - удалить,\n"
                      << "5 - сортировать,\n"
                      << "6 - выйти\n";

            // Очистка буфера cin перед каждым новым вводом
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Проверяем, успешно ли считан целый тип
            if (!(std::cin >> type)) {
                std::cout << "Некорректный ввод! Пожалуйста, введите число.\n";
                continue;
            }

            // Проверяем валидность значения после успешного чтения числа
            if (!isValidDatabaseInteractionType(type)) {
                std::cout << "Некорректный тип действия!\n";
            }
        }

        return static_cast<DatabaseInteractionType>(type);
    }

    int ReadEntityId() {
        int id = 0;

        while (true) {
            std::cout << "Введите ID сущности, или '-1', чтобы выбрать все сущности: ";

            // Сбрасываем возможные ошибки и очищаем буфер ввода
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Проверяем успешность ввода целого числа
            if (std::cin >> id) {
                return id;
            }

            // Сообщаем пользователю о некорректном вводе
            std::cout << "Ошибка ввода. Попробуйте еще раз." << std::endl;
        }
    }
}  // namespace interaction
