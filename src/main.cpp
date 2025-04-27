#include "./StringTask/tasks.h"
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
    std::wstring str3 = L"мой ник в игре WarThunder Нагибатор228";
    std::wcout << L"Original string: " << str3 << std::endl;

    std::wstring result3 = task2(str3);
    std::wcout << L"Processed string: " << result3 << '\n' << std::endl;

    task3();
    return 0;
}
