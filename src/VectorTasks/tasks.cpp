#include "tasks.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> createRandomVector() {
    std::srand(std::time(nullptr));
    std::vector<int> vec(5);
    for (int &num : vec) {
        num = std::rand() % 100; // Диапазон [0, 100]
    }
    return vec;
}

void doubleVectorElements(std::vector<int> &vec) {
    for (int &num : vec) {
        num *= 2;
    }
}

void printVector(const std::vector<int> &vec) {
    for (const int &num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void removeElementAtIndex(std::vector<int> &vec, size_t index) {
    if (index < vec.size()) {
        vec.erase(vec.begin() + index);
    }
}
