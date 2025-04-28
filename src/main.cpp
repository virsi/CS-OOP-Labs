#include "./StringTasks/tasks.h"
#include "./VectorTasks/tasks.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

int main() {
    std::wcout.imbue(std::locale(""));

    // task 1
    std::cout << "TASK 1" << std::endl;
    std::wstring str1 = L"фак си";
    std::wcout << L"Original string: " << str1 << std::endl;

    std::wstring result1 = task1(str1);
    std::wcout << L"Processed string: " << result1 << '\n' << std::endl;

    // task 2
    std::cout << "TASK 2" << std::endl;
    std::wstring str2 = L"мой ник в игре WarThunder Нагибатор228";
    std::wcout << L"Original string: " << str2 << std::endl;

    std::wstring result2 = task2(str2);
    std::wcout << L"Processed string: " << result2 << '\n' << std::endl;

    // task 3
    std::cout << "TASK 3" << std::endl;
    try {
        task3();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    // task 4
    std::vector<int> vec = createRandomVector();
    std::cout << "Initial vector: ";
    printVector(vec);

    doubleVectorElements(vec);
    std::cout << "Doubled vector: ";
    printVector(vec);

    removeElementAtIndex(vec, 2);
    std::cout << "Vector after removing element at index 2: ";
    printVector(vec);

    return 0;
}
