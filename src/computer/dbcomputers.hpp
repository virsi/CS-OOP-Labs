#pragma once
#include "computer.hpp"

namespace dbcomputers {
    int Read(char* filepath, computer::Computer** shops);
    void Write(char* filepath, computer::Computer** shops, int size);
    void Append(char* filepath, computer::Computer* computer);
    void Remove(char* filepath, int shopId);
    void Sort(char* filepath);
    void Print(char* filepath);
}  // namespace dbcomputers
