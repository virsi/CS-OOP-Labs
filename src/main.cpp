#include "./StringTasks/tasks.h"
#include "./VectorTasks/tasks.h"
#include "./VectorTasks/Complex.h"
#include "./ListTasks/tasks.h"
#include "./MapTasks/tasks.h"
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>
#include <map>

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

    // task 5
    std::cout << "TASK 5" << std::endl;
    std::vector<Complex> complexVec = {
        Complex(-1.2, 6.3),
        Complex(4.0, 0.7),
        Complex(7.2, -0.8),
        Complex(5.3, 3.0),
        Complex(-4.9, 6.6),
        Complex(-9.3, 0.2)
    };

    std::cout << "Complex vector:" << std::endl;
    for (const auto &c : complexVec) {
        std::cout << c << std::endl;
    }

    Complex sum;
    for (const auto &c : complexVec) {
        sum = sum + c;
    }

    std::cout << "Sum of all complex numbers: " << sum << std::endl;

    // task 6
    std::cout << "TASK 6" << std::endl;
    std::list<int> lst = createRandomList();
    std::cout << "Initial list: ";
    printList(lst);

    doubleListElements(lst);
    std::cout << "Doubled list: ";
    printList(lst);

    auto it = lst.begin();
    std::advance(it, 2);
    lst.erase(it);
    std::cout << "List after removing element at index 2: ";
    printList(lst);

    // task 7
    std::cout << "TASK 7" << std::endl;
    std::list<Rectangle> rectangles = {
        Rectangle(1.2, 6.3),
        Rectangle(4.0, 0.7),
        Rectangle(7.2, 0.8),
        Rectangle(5.3, 3.0),
        Rectangle(4.9, 6.6),
        Rectangle(9.3, 0.2)
    };

    std::cout << "List of rectangles:" << std::endl;
    printRectangleList(rectangles);

    Rectangle largest = findLargestRectangle(rectangles);
    std::cout << "Rectangle with the largest area: " << largest << std::endl;

    // task 8
    std::cout << "TASK 8" << std::endl;
    std::map<std::string, int> myMap = createMap();

    std::cout << "Initial map:" << std::endl;
    printMap(myMap);

    removeKeys(myMap, {"five", "six"});
    std::cout << "Map after removing keys 'five' and 'six':" << std::endl;
    printMap(myMap);

    // task 9
    std::cout << "PHONE BOOK TASK" << std::endl;
    std::map<std::string, std::string> phoneBook;

    std::cout << "Enter subscribers (name and phone number). Type 'end' to stop." << std::endl;
    while (true) {
        std::string name, number;
        std::cout << "Name: ";
        std::cin >> name;
        if (name == "end") break;
        std::cout << "Phone number: ";
        std::cin >> number;
        addSubscriber(phoneBook, name, number);
    }

    std::cout << "Phone book:" << std::endl;
    printMap(phoneBook);

    std::cout << "Enter a name to search and remove: ";
    std::string searchName;
    std::cin >> searchName;
    std::string foundNumber = findNumberByName(phoneBook, searchName);
    if (!foundNumber.empty()) {
        std::cout << "Found: " << searchName << " - " << foundNumber << std::endl;
        removeSubscriber(phoneBook, searchName);
    } else {
        std::cout << "Subscriber not found." << std::endl;
    }

    std::cout << "Updated phone book:" << std::endl;
    printMap(phoneBook);

    return 0;
}
