#include "../containers/myvector.h"
#include "../containers/myvector.cpp"
#include <cassert>
#include <iostream>
#include <sstream>

void test_add_element() {
    MyVector<int> v;
    v.add_element(10);
    v.add_element(20);
    assert(v.get_size() == 2);
    assert(v[0] == 10);
    assert(v[1] == 20);
    std::cout << "test_add_element passed\n";
}

void test_delete_element() {
    MyVector<int> v;
    v.add_element(10);
    v.add_element(20);
    v.delete_element(10);
    assert(v.get_size() == 1);
    assert(v[0] == 20);
    std::cout << "test_delete_element passed\n";
}

void test_find() {
    MyVector<int> v;
    v.add_element(10);
    v.add_element(20);
    assert(v.find(10) == 0);
    assert(v.find(20) == 1);
    assert(v.find(30) == -1);
    std::cout << "test_find passed\n";
}

void test_operator_assignment() {
    MyVector<int> v1;
    v1.add_element(10);
    v1.add_element(20);
    MyVector<int> v2;
    v2 = v1;
    assert(v2.get_size() == 2);
    assert(v2[0] == 10);
    assert(v2[1] == 20);
    std::cout << "test_operator_assignment passed\n";
}

void test_operator_index() {
    MyVector<int> v;
    v.add_element(10);
    v.add_element(20);
    assert(v[0] == 10);
    assert(v[1] == 20);
    try {
        v[2];
        assert(false);
    } catch (const std::out_of_range&) {
        std::cout << "test_operator_index passed\n";
    }
}

void test_resize() {
    MyVector<int> v;
    for (int i = 0; i < 20; ++i) {
        v.add_element(i);
    }
    assert(v.get_size() == 20);
    assert(v.get_max_size() >= 20);
    for (int i = 0; i < 20; ++i) {
        v.delete_element(i);
    }
    assert(v.get_size() == 0);
    std::cout << "test_resize passed\n";
}

void test_output_operator() {
    MyVector<int> v;
    std::ostringstream out;
    out << v;
    assert(out.str() == "Пустой вектор");

    v.add_element(10);
    v.add_element(20);
    out.str("");
    out << v;
    assert(out.str() == "[10, 20]");
    std::cout << "test_output_operator passed\n";
}

int main() {
    test_add_element();
    test_delete_element();
    test_find();
    test_operator_assignment();
    test_operator_index();
    test_resize();
    test_output_operator();
    std::cout << "All tests passed!\n";
    return 0;
}
