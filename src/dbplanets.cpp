#include "dbplanets.hpp"
#include <iostream>
#include "fstream"

namespace {
    const int BUF_SIZE = 128;

    // Быстрая сортировка (рекурсивная)
    void quickSort(planet::Planet** planets, int low, int high) {
        if (low < high) {
            planet::Planet* pivot = planets[high];
            int i = low - 1;

            for (int j = low; j < high; ++j) {
                if (*planets[j] < *pivot) {
                    std::swap(planets[++i], planets[j]);
                }
            }

            std::swap(planets[++i], planets[high]);

            quickSort(planets, low, i - 1);
            quickSort(planets, i + 1, high);
        }
    }
}  // namespace

int dbplanets::Read(char* filepath, planet::Planet** planets) {
    std::fstream file(filepath, std::ios::binary | std::ios::in);

    int i = 0;
    while (file >> planets[i]) {
        planet::Planet::lastId = std::max(planet::Planet::lastId, planets[i]->GetId());
        i++;
    }

    return i;
}

void dbplanets::Write(char* filepath, planet::Planet** planets, int size) {
    std::fstream file(filepath, std::ios::out | std::ios::trunc);

    for (int i = 0; i < size; ++i) {
        file << planets[i] << std::endl;
    }
}

void dbplanets::Append(char* filepath, planet::Planet* planet) {
    std::fstream file(filepath, std::ios::out | std::ios::app);

    file << planet << std::endl;
    delete planet;
}

void dbplanets::Remove(char* filepath, int planetId) {
    planet::Planet** planets = new planet::Planet*[BUF_SIZE];

    int n = dbplanets::Read(filepath, planets);
    for (int i = 0; i < n; ++i) {
        if (planets[i]->GetId() == planetId) {
            delete planets[i];
            for (int j = i; j < n - 1; ++j) {
                planets[j] = planets[j + 1];
            }
            n--;
            break;
        }
    }

    dbplanets::Write(filepath, planets, n);

    delete[] planets;
}

void dbplanets::Sort(char* filepath) {
    planet::Planet** planets = new planet::Planet*[BUF_SIZE];

    int n = dbplanets::Read(filepath, planets);

    quickSort(planets, 0, n - 1);

    dbplanets::Write(filepath, planets, n);

    delete[] planets;
}

void dbplanets::Print(char* filepath) {
    planet::Planet** planets = new planet::Planet*[BUF_SIZE];

    int n = dbplanets::Read(filepath, planets);
    if (n == 0) {
        std::cout << "Таблица планет пуста!" << std::endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        planets[i]->PrettyPrint();
    }

    delete[] planets;
}
