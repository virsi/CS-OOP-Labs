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

    Computer::Computer(){
        this->os = new char[BUF_SIZE];
        this->serialNumber = new char[BUF_SIZE];

        std::strcpy(os, " ");
        std::strcpy(os, " ");
    }

    Computer::Computer(const Computer& obj): frequencyCPU(obj.frequencyCPU), ram(obj.ram), rom(obj.rom) {
        SetOS(obj.os);
        SetSerialNumber(obj.serialNumber);
    }

    Computer::~Computer() {
        delete[] this->os;
        delete[] this->serialNumber;
    }

    int Computer::GetId() const {
        return this->id;
    }

    void Computer::PrettyPrint() const {
        int width = 15; // Ширина каждого столбца
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

    Computer& Computer::operator=(const Computer& obj) {
        if (this == &obj) {
            return *this;
        }

        delete[] this->os;
        delete[] this->serialNumber;

        this->id = obj.id;
        this->frequencyCPU = obj.frequencyCPU;
        this->ram = obj.ram;
        this->rom = obj.rom;

        this->os = new char[std::strlen(obj.os) + 1];
        std::strncpy(this->os, obj.os, std::strlen(obj.os) + 1);

        this->serialNumber = new char[std::strlen(obj.serialNumber) + 1];
        std::strncpy(this->serialNumber, obj.serialNumber, std::strlen(obj.serialNumber) + 1);

        return *this;
    }

    bool operator==(const Computer& e1, const Computer& e2) {
        return e1.frequencyCPU == e2.frequencyCPU;
    }

    bool operator<(const Computer& e1, const Computer& e2) {
        return e1.frequencyCPU < e2.frequencyCPU;
    }

    void Computer::SetOS(char* os_){delete[] os; os = new char[std::strlen(os_) + 1]; std::strcpy(os, os_);}
    void Computer::SetSerialNumber(char* sN_){delete[] serialNumber; serialNumber = new char[std::strlen(sN_) + 1]; std::strcpy(serialNumber, sN_);}
}  // namespace computer


//редактирование, очистка памяти после выхода,
//редактирование, очистка памяти после выхода, таблица вывода
