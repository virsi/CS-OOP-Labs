#ifndef TASKS_H
#define TASKS_H

#include <list>
#include <iostream>

class Rectangle {
    double a;
    double b;
public:
    Rectangle();
    Rectangle(double a, double b);
    double area() const;
    bool operator<(const Rectangle& other) const;
    bool operator==(const Rectangle& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rectangle& rect);
};

std::list<int> createRandomList();
void doubleListElements(std::list<int>& lst);
void printList(const std::list<int>& lst);

void printRectangleList(const std::list<Rectangle>& lst);
Rectangle findLargestRectangle(const std::list<Rectangle>& lst);

#endif // TASKS_H
