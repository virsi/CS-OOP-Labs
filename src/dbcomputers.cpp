#include "dbcomputers.hpp"
#include <iostream>
#include "fstream"

namespace {
    int BUF_SIZE = 512;

    void quickSort(computer::Computer** computers, int low, int high) {
        if (low < high) {
            computer::Computer* pivot = computers[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (*computers[j] < *pivot) {
                    std::swap(computers[++i], computers[j]);
                }
            }

            std::swap(computers[++i], computers[high]);

            quickSort(computers, low, i - 1);
            quickSort(computers, i + 1, high);
        }
    }
}  // namespace

int dbcomputers::Read(char* filepath, computer::Computer** computers) {
    std::fstream file(filepath, std::ios::binary | std::ios::in);

    int i = 0;
    while (file >> computers[i]) {
        // computer::Shop::UpdateLastId(computers[i]->id);
        computer::Computer::lastId = std::max(computer::Computer::lastId, computers[i]->GetId());
        i++;
    }

    return i;
}

void dbcomputers::Write(char* filepath, computer::Computer** computers, int size) {
    std::fstream file(filepath, std::ios::out | std::ios::trunc);

    for (int i = 0; i < size; ++i) {
        file << computers[i] << std::endl;
    }
}

void dbcomputers::Append(char* filepath, computer::Computer* computer) {
    std::fstream file(filepath, std::ios::out | std::ios::app);

    file << computer << std::endl;
    delete computer;
}

void dbcomputers::Remove(char* filepath, int computerId) {
    computer::Computer** computers = new computer::Computer*[BUF_SIZE];

    int n = dbcomputers::Read(filepath, computers);
    for (int i = 0; i < n; ++i) {
        if (computers[i]->GetId() == computerId) {
            delete computers[i];
            for (int j = i; j < n - 1; ++j) {
                computers[j] = computers[j + 1];
            }
            n--;
            break;
        }
        //можно добавить предупреждение что нет такого айди
    }

    dbcomputers::Write(filepath, computers, n);

    delete[] computers;
}

void dbcomputers::Sort(char* filepath) {
    computer::Computer** computers = new computer::Computer*[BUF_SIZE];

    int n = dbcomputers::Read(filepath, computers);

    quickSort(computers, 0, n - 1);

    dbcomputers::Write(filepath, computers, n);

    delete[] computers;
}

void dbcomputers::Print(char* filepath) {
    computer::Computer** computers = new computer::Computer*[BUF_SIZE];

    int n = dbcomputers::Read(filepath, computers);
    if (n == 0) {
        std::cout << "Таблица пуста!" << std::endl;
        return;
    }

    for (int i = 0; i < n; ++i) {
        computers[i]->PrettyPrint();
    }

    delete[] computers;
}
