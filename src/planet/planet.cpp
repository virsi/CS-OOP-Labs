#include "planet.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>

namespace {
    int BUF_SIZE = 512;
}

namespace planet {
    int Planet::lastId = 0;

    Planet::Planet(int id, char* name, int diameter, bool hasLife, int satellites) {
        if (id == -1) {
            this->id = ++lastId;
            id = this->id;
        }

        this->id = id;
        this->diameter = diameter;
        this->hasLife = hasLife;
        this->satellites = satellites;

        this->name = new char[std::strlen(name) + 1];
        std::strncpy(this->name, name, std::strlen(name) + 1);
    }

    Planet::Planet(){
        this->name = new char[BUF_SIZE];
        std::strcpy(name, " ");
    }

    Planet::Planet(const Planet& obj): diameter(obj.diameter), hasLife(obj.hasLife), satellites(obj.satellites) {
        SetName(obj.name);
    }

    Planet::~Planet() {
        delete[] this->name;
    }

    int Planet::GetId() const {
        return this->id;
    }

    void Planet::PrettyPrint() const {
        int width = 15; // Ширина каждого столбца
        std::cout << std::setw(width) << this->id << std::setw(width) << this->name << std::setw(width)
            << this->diameter << std::setw(width) << this->hasLife << std::setw(width) << this->satellites << '\n';;
    }

    std::istream& operator>>(std::istream& s, Planet*& p) {
        int id = 0;
        char* name = new char[BUF_SIZE];
        int diameter = 0;
        bool hasLife = false;
        int satellites = 0;

        if (!(s >> id >> name >> diameter >> hasLife >> satellites)) {
            delete[] name;
            s.setstate(std::ios::failbit);
            return s;
        }

        p = new Planet(id, name, diameter, hasLife, satellites);
        delete[] name;
        return s;
    }

    std::ostream& operator<<(std::ostream& s, Planet* p) {
        s << p->id << " " << p->name << " " << p->diameter << " " << p->hasLife << " " << p->satellites;
        return s;
    }

    Planet& Planet::operator=(const Planet& obj) {
        if (this == &obj) {
            return *this;
        }

        delete[] this->name;

        this->id = obj.id;
        this->diameter = obj.diameter;
        this->hasLife = obj.hasLife;
        this->satellites = obj.satellites;

        this->name = new char[std::strlen(obj.name) + 1];
        std::strncpy(this->name, obj.name, std::strlen(obj.name) + 1);

        return *this;
    }

    bool operator==(const Planet& e1, const Planet& e2) {
        return e1.diameter == e2.diameter;
    }

    bool operator<(const Planet& e1, const Planet& e2) {
        return e1.diameter < e2.diameter;
    }

    void Planet::SetName(char* n){delete[] name; name = new char[std::strlen(n) + 1]; std::strcpy(name, n);}

}  // namespace planet
