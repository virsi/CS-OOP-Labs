#include "../containers/myset.h"
#include <cassert>
#include <iostream>
#include <sstream>

void test_add_element() {
    MySet<int> s;
    s.add_element(10);
    s.add_element(20);
    s.add_element(10); // Дубликат, не должен добавиться
    assert(s.get_size() == 2);
    std::cout << "test_add_element passed\n";
}

void test_delete_element() {
    MySet<int> s;
    s.add_element(10);
    s.add_element(20);
    s.delete_element(10);
    assert(s.get_size() == 1);
    assert(s.q_find(10) == -1);
    std::cout << "test_delete_element passed\n";
}

void test_union() {
    MySet<int> s1, s2;
    s1.add_element(10);
    s1.add_element(20);
    s2.add_element(20);
    s2.add_element(30);
    MySet<int> result = s1 + s2;
    assert(result.get_size() == 3);
    assert(result.q_find(10) != -1);
    assert(result.q_find(20) != -1);
    assert(result.q_find(30) != -1);
    std::cout << "test_union passed\n";
}

void test_intersection() {
    MySet<int> s1, s2;
    s1.add_element(10);
    s1.add_element(20);
    s2.add_element(20);
    s2.add_element(30);
    MySet<int> result = s1 * s2;
    assert(result.get_size() == 1);
    assert(result.q_find(20) != -1);
    std::cout << "test_intersection passed\n";
}

void test_difference() {
    MySet<int> s1, s2;
    s1.add_element(10);
    s1.add_element(20);
    s2.add_element(20);
    s2.add_element(30);
    MySet<int> result = s1 - s2;
    assert(result.get_size() == 1);
    assert(result.q_find(10) != -1);
    assert(result.q_find(20) == -1);
    std::cout << "test_difference passed\n";
}

void test_equality() {
    MySet<int> s1, s2;
    s1.add_element(10);
    s1.add_element(20);
    s2.add_element(20);
    s2.add_element(10);
    assert(s1 == s2);
    s2.add_element(30);
    assert(!(s1 == s2));
    std::cout << "test_equality passed\n";
}

void test_output_operator() {
    MySet<int> s;
    std::ostringstream out;
    out << s;
    assert(out.str() == "Пустое множество");

    s.add_element(10);
    s.add_element(20);
    out.str("");
    out << s;
    assert(out.str() == "[10, 20]");
    std::cout << "test_output_operator passed\n";
}

int main() {
    test_add_element();
    test_delete_element();
    test_union();
    test_intersection();
    test_difference();
    test_equality();
    test_output_operator();
    std::cout << "All MySet tests passed!\n";
    return 0;
}
