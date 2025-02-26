#pragma once
#include "planet/planet.hpp"

namespace dbplanets {
    int Read(char* filepath, planet::Planet** planets);
    void Write(char* filepath, planet::Planet** planets, int size);
    void Append(char* filepath, planet::Planet* planet);
    void Remove(char* filepath, int planetId);
    void Sort(char* filepath);
    void Print(char* filepath);
}  // namespace dbplanets
