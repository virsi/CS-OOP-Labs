#pragma once
#include <fstream>

namespace computer {
    class Computer {
        private:
            int id;
            char* os;
            char* serialNumber;
            int frequencyCPU;
            int ram;
            int rom;

        public:
            static int lastId;
            Computer(int id, char* os, char* serialNumber, int frequencyCPU, int ram, int rom);
            //Computer();
            ~Computer();

            int GetId() const;
            void PrettyPrint() const;

            friend std::istream& operator>>(std::istream& s, Computer*& p);
            friend std::ostream& operator<<(std::ostream& s, const Computer* p);
            friend bool operator<(const Computer& e1, const Computer& e2);
            friend bool operator==(const Computer& e1, const Computer& e2);
    };
}  // namespace computer
