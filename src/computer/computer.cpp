#include "computer.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>

namespace {
    int BUF_SIZE = 128;
}

namespace computer {
    int Computer::lastId = 0;

    Computer::Computer(int id, char* os, char* serialNumber, int frequencyCPU, int ram, int rom) {
        if (id == -1) {
            this->id = ++lastId;
            id = this->id;
        }

        this->id = id;
        this->frequencyCPU = frequencyCPU;
        this->ram = ram;
        this->rom = rom;

        this->os = new char[std::strlen(os) + 1];
        std::strncpy(this->os, os, std::strlen(os) + 1);

        this->serialNumber = new char[std::strlen(serialNumber) + 1];
        std::strncpy(this->serialNumber, serialNumber, std::strlen(serialNumber) + 1);
    }

    Computer::~Computer() {
        delete[] this->os;
        delete[] this->serialNumber;
    }

    int Computer::GetId() const {
        return this->id;
    }

    // void Computer::PrettyPrint() const {
    //     std::cout << "{ID: '" << this->id << "', OS: '" << this->os << "', Serial Number: '"
    //               << this->serialNumber << "', CPU Frequency: '" << this->frequencyCPU << "', RAM: '"
    //               << this->ram << "GB', ROM: '" << rom << "GB' }" << std::endl;
    // }

    void Computer::PrettyPrint() const {
        int width = 15; // Ширина каждого столбца
        //std::cout << std::left; // Выравнивание по левому кра
        std::cout << std::setw(width) << this->id << std::setw(width) << this->os << std::setw(width) << this->serialNumber<< std::setw(width)
            << this->frequencyCPU << std::setw(width) << this->ram << std::setw(width) << this->rom << '\n';;
    }


    std::istream& operator>>(std::istream& s, Computer*& p) {
        int id = 0;
        char* os = new char[BUF_SIZE];
        char* serialNumber = new char[BUF_SIZE];
        int frequencyCPU = 0;
        int ram = 0;
        int rom = 0;

        if (!(s >> id >> os >> serialNumber >> frequencyCPU >> ram >> rom)) {
            delete[] os;
            delete[] serialNumber;
            s.setstate(std::ios::failbit);
            return s;
        }

        p = new Computer(id, os, serialNumber, frequencyCPU, ram, rom);
        delete[] os;
        delete[] serialNumber;

        return s;
    }

    std::ostream& operator<<(std::ostream& s, const Computer* p) {
        s << p->id << " " << p->os << " " << p->serialNumber << " " << p->frequencyCPU << " "
          << p->ram << " " << p->rom;
        return s;
    }

    bool operator==(const Computer& e1, const Computer& e2) {
        return e1.frequencyCPU == e2.frequencyCPU;
    }

    bool operator<(const Computer& e1, const Computer& e2) {
        return e1.frequencyCPU < e2.frequencyCPU;
    }
}  // namespace computer


//конструктор копирования, редактирование, перегрузка присваивания, конструктор без параметров, очистка памяти после выхода, табличный вывод
