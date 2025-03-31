#include "./mystack/MyStack.h"

int main() {
    int number;
    MyStack<int> stack;

    Multipliers(number, stack);

    if (stack.empty()) {
        std::cout << "Число не имеет простых множителей." << std::endl;
    } else {
        std::cout << number << "=";

        // Печать по убыванию (LIFO)
        MyStack<int> tempStack = stack; // Копия для сохранения исходных данных
        while (!tempStack.empty()) {
            std::cout << tempStack.top_inf();
            tempStack.pop();
            if (!tempStack.empty()) std::cout << " * ";
        }

        std::cout << std::endl << number << "=";

        // Печать по возрастанию (разворачиваем стек)
        MyStack<int> reverseStack;
        while (!stack.empty()) {
            reverseStack.push(stack.top_inf());
            stack.pop();
        }

        while (!reverseStack.empty()) {
            std::cout << reverseStack.top_inf();
            reverseStack.pop();
            if (!reverseStack.empty()) std::cout << " * ";
        }
        std::cout << std::endl;
    }

    return 0;

}
