#include <iostream>
#include "../containers/myvector.h"
#include "../containers/myset.h"

int main() {
    setlocale(LC_ALL, "Russian");

    MyVector<std::string> v;
    v.add_element("Hello!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    v.add_element("Привет!");
    v.add_element("Привет!");
    v.add_element("Привет!");
    std::cout << "Вектор v: " << v << std::endl;
    MyVector<std::string> v1 = v;
    std::cout << "Вектор v1: " << v1 << std::endl;
    for (int i = 0; i < MAX_SIZE; i++)
        v1.delete_element("Привет!");
    std::cout << "Вектор v1: " << v1 << std::endl;

    MySet<std::string> s, s1, s2;
    s.add_element("Yes");
    s.add_element("Привет!");
    s.add_element("No");
    s.add_element("Hello!");
    std::cout << "Множество s: " << s << std::endl;

    s1.add_element("Cat");
    s1.add_element("No");
    s1.add_element("Привет!");
    std::cout << "Множество s1: " << s1 << std::endl;

    s2 = s1 - s;
    std::cout << "Множество s2=s1-s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s - s1;
    std::cout << "Множество s2=s-s1: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s1 + s;
    std::cout << "Множество s2=s1+s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    s2 = s1 * s;
    std::cout << "Множество s2=s1*s: " << s2 << std::endl;
    std::cout << "Множество s1: " << s1 << std::endl;
    std::cout << "Множество s: " << s << std::endl;

    MySet<std::string> s3 = s2;
    std::cout << "Множество s3=s2: " << s3 << std::endl;

    if (s3 == s2)
        std::cout << "Множество s3=s2\n";
    else
        std::cout << "Множество s3!=s2\n";

    if (s3 == s1)
        std::cout << "Множество s3=s1\n";
    else
        std::cout << "Множество s3!=s1\n";

    if (s1 == s3)
        std::cout << "Множество s1=s3\n";
    else
        std::cout << "Множество s1!=s3\n";


    char* wert = new char[5]{"wert"};
    char* wert1  = new char[6]{"wert3"};
    MyVector<char*> v3;
    v3.add_element(wert);
    v3.add_element(wert1);
    std::cout << v3 << std::endl;
    delete [] wert;
    delete [] wert1;
    MyVector<char*> v2 = v3;
    v2.add_element("de");

    std::cout << v3 << std::endl;
    std::cout << v2 << std::endl;


    return 0;
}
