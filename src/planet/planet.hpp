#pragma once
#include <fstream>

namespace planet {
    class Planet {
        private:
            int id;
            char* name;
            int diameter;
            bool hasLife;
            int satellites;

        public:
            static int lastId;

            Planet(int id, char* name, int diameter, bool hasLife, int satellites);
            Planet();
            Planet(const Planet& obj);
            ~Planet();

            int GetId() const;
            void SetName(char* n);
            void PrettyPrint() const;

            friend std::istream& operator>>(std::istream& s, Planet*& p);
            friend std::ostream& operator<<(std::ostream& s, Planet* p);
            Planet& operator=(const Planet& obj);
            friend bool operator<(const Planet& e1, const Planet& e2);
            friend bool operator==(const Planet& e1, const Planet& e2);
    };
}  // namespace planet
