#include "tasks.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <random>
#include <cmath>
#include <iterator>

std::list<int> createRandomList() {
    std::list<int> lst;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 10; ++i) {
        lst.push_back(dis(gen));
    }
    return lst;
}

void doubleListElements(std::list<int>& lst) {
    for (auto& elem : lst) {
        elem *= 2;
    }
}

void printList(const std::list<int>& lst) {
    for (const auto& elem : lst) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void printRectangleList(const std::list<Rectangle>& lst) {
    for (const auto& rect : lst) {
        std::cout << rect << std::endl;
    }
}

Rectangle findLargestRectangle(const std::list<Rectangle>& lst) {
    return *std::max_element(lst.begin(), lst.end());
}

Rectangle::Rectangle() : a(0), b(0) {}

Rectangle::Rectangle(double a, double b) : a(a), b(b) {}

double Rectangle::area() const {
    return a * b;
}

bool Rectangle::operator<(const Rectangle& other) const {
    return this->area() < other.area();
}

bool Rectangle::operator==(const Rectangle& other) const {
    return this->a == other.a && this->b == other.b;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rect) {
    os << "Rectangle(" << rect.a << ", " << rect.b << ")";
    return os;
}
