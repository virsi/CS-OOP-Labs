#pragma once
#include <vector>

// Создание вектора из 5 случайных чисел
std::vector<int> createRandomVector();

// Удвоение каждого элемента вектора
void doubleVectorElements(std::vector<int> &vec);

// Печать вектора
void printVector(const std::vector<int> &vec);

// Удаление элемента с индексом 2
void removeElementAtIndex(std::vector<int> &vec, size_t index);
