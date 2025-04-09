#ifndef INHERITANCE_MYSET_H
#define INHERITANCE_MYSET_H

#include <iostream>
#include <string>
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
        if constexpr (std::is_same_v<T, std::string>) {
            return left.compare(right); // Используем метод compare для строк
        } else {
            return left - right; // Для остальных типов
        }
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

    if (compare(data[mid], value) == 0) {
        return mid;
    }

    if (compare(data[mid], value) < 0) {
        return binary_search(data, mid + 1, right, value);
    }

    return binary_search(data, left, mid - 1, value);
}

template <typename T>
void quick_sort(T* data, int left, int right) {
    if (left >= right) {
        return;
    }

    T pivot = data[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
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
    MySet() : MyVector<T>() {};

    bool operator==(MySet &s) {
        if (this->size != s.size) return false;
        for (int i = 0; i < this->size; ++i) {
            if (s.q_find(this->data[i]) == -1) return false;
        }
        return true;
    }

    MySet &operator+=(MySet &s) {
        for (int i = 0; i < s.size; ++i) {
            if (this->q_find(s.data[i]) == -1) {
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
            if (s.q_find(this->data[i]) == -1) {
                this->delete_element(this->data[i]);
                --i;
            }
        }
        return *this;
    }

    MySet &operator=(const MySet &s) {
        if (this == &s) return *this;
        MyVector<T>::operator=(s);
        return *this;
    }

    void q_sort() { quick_sort(this->data, 0, this->size - 1); }
    int q_find(T value) const { return binary_search(this->data, 0, this->size - 1, value); }

    void add_element(T el) {
        if (this->q_find(el) == -1) {
            MyVector<T>::add_element(el);
            q_sort();
        }
    }

    void delete_element(T el) {
        MyVector<T>::delete_element(el);
        q_sort();
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
