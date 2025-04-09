#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>

#include "myvector.h"

template <typename T>
    T transform(char* token) {
        return T(token);
    }

    template <>
    int transform(char* token) {
        return std::atoi(token);
    }

    template <typename T>
    int compare(const T& left, const T& right) {
        return left - right;
    }

    template <>
    int compare(char* const& left, char* const& right) {
        return std::strcmp(left, right);
    }

template <typename T>
int binary_search(T* data, int left, int right, T value) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;

    // If matches.
    if (compare(data[mid], value) == 0) {
        return mid;
    }

    // Left side.
    if (compare(data[mid], value) < 0) {
        return binary_search(data, mid + 1, right, value);
    }

    // Right side.
    return binary_search(data, left, mid - 1, value);
}

template <typename T>
void quick_sort(T* data, int left, int right) {
    if (left >= right) {
        return;
    }

    T pivot = data[right];
    int i = left - 1;

    // Array partition.
    for (int j = left; j < right; ++j) {
        // Similar to `if (data[j] < pivot)`.
        if (compare(data[j], pivot) < 0) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[right]);

    quick_sort(data, left, i);
    quick_sort(data, i + 2, right);
}

template <typename T>
class MySet : public MyVector<T> {
public:
    MySet() : MyVector<T>() {}; // Убрали аргумент el

    bool operator==(MySet &s) {
        if (this->size != s.size) return false;
        for (int i = 0; i < this->size; ++i) {
            if (s.q_find(this->data[i]) == -1) return false; // Используем q_find
        }
        return true;
    }

    MySet &operator+=(MySet &s) {
        for (int i = 0; i < s.size; ++i) {
            if (this->q_find(s.data[i]) == -1) { // Используем q_find
                this->add_element(s.data[i]);
            }
        }
        return *this;
    }

    MySet &operator-=(MySet &s) {
        for (int i = 0; i < s.size; ++i) {
            this->delete_element(s.data[i]);
        }
        return *this;
    }

    MySet &operator*=(MySet &s) {
        for (int i = 0; i < this->size; ++i) {
            if (s.q_find(this->data[i]) == -1) { // Используем q_find
                this->delete_element(this->data[i]);
                --i; // Корректируем индекс после удаления
            }
        }
        return *this;
    }

    void q_sort() { quick_sort(this->data, 0, this->size - 1); }
    int q_find(T value) const { return binary_search(this->data, 0, this->size - 1, value); }

    void add_element(T el) {
        if (this->q_find(el) == -1) { // Используем q_find для быстрого поиска
            MyVector<T>::add_element(el);
            q_sort(); // Сортируем после добавления
        }
    }

    void delete_element(T el) {
        MyVector<T>::delete_element(el);
        q_sort(); // Сортируем после удаления
    }

    friend std::ostream &operator<<(std::ostream &out, MySet<T> &s) {
        if (s.get_size() == 0) {
            out << "Пустое множество";
            return out;
        }

        out << "[";
        for (int i = 0; i < s.get_size(); ++i) {
            out << s.data[i];
            if (i != s.get_size() - 1) {
                out << ", ";
            }
        }
        out << "]";
        return out;
    }

    friend MySet operator+(MySet &s1, MySet &s2) {
        MySet result = s1;
        result += s2;
        return result;
    }

    friend MySet operator-(MySet &s1, MySet &s2) {
        MySet result = s1;
        result -= s2;
        return result;
    }

    friend MySet operator*(MySet &s1, MySet &s2) {
        MySet result = s1;
        result *= s2;
        return result;
    }
};

#endif // INHERITANCE_MYSET_H
