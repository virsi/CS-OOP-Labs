#include <iostream>
#include "MyStack.h"

template<class INF>
MyStack<INF>::MyStack(void) : top(nullptr) {} // конструктор

template<class INF>
MyStack<INF>::~MyStack(void) {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Глобальная функция для разложения числа на простые множители
void Multipliers(int n, MyStack<int> &stack) {
    if (n < 2) {
        std::cout << "Число должно быть больше 1." << std::endl;
        return;
    }

    int divisor = 2;
    while (n > 1) {
        while (n % divisor == 0) {
            stack.push(divisor);
            n /= divisor;
        }
        divisor++;
    }
}

