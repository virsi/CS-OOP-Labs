#include <iostream>
#include "mymath/mymath.h"
#include "myoutput/myoutput.h"

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "Я умею считать факториал! Зацени, 5! = ";
    std::cout << mymath::factorial(5)<< std::endl;

    std::cout << "Посмотри какой пончик!\n";
    myoutput::donut();

    return 0;
}
