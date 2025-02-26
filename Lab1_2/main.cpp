#include <iostream>
#include "mymath.h"


int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею считать факториал! Зацени, 6! = ";
    std::cout << mymath::factorial(6)<< std::endl;

    return 0;
}
