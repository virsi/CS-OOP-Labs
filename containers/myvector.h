#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>

namespace {
    unsigned DEFAULT_CAPACITY = 16;
    unsigned GROWTH_FACTOR = 2;
    unsigned SHRINK_FACTOR = 4;
    unsigned MAX_SIZE = 5;
} // namespace

template <typename T>
class MyVector {
protected:
    int max_size = 0;
    int size = 0;
    T* data = nullptr;

    void resize_grow_if_needed() {
        if (this->size < this->max_size) {
            return;
        }

        this->max_size *= GROWTH_FACTOR;
        T *new_data = new T[this->max_size];

        for (unsigned i = 0; i < this->size; ++i) {
            new_data[i] = this->data[i];
        }

        delete[] this->data;
        this->data = new_data;
    }

    void resize_shrink_if_needed() {
        if (this->size >= this->max_size / SHRINK_FACTOR) {
            return;
        }

        this->max_size /= GROWTH_FACTOR;
        T* new_data = new T[this->max_size];
        for (unsigned i = 0; i < this->size; ++i) {
            new_data[i] = this->data[i];
        }
        delete[] this->data;
        this->data = new_data;
    }

public:

    MyVector(){this->data = new T[DEFAULT_CAPACITY]; this->max_size = DEFAULT_CAPACITY;}

    MyVector(const MyVector &v) {
        this->size = v.size;
        this->max_size = v.max_size;
        this->data = new T[this->max_size];

        for (unsigned i = 0; i < this->size; ++i) {
            this->data[i] = v.data[i];
        }
    }

    ~MyVector(){delete[] this->data;}

    int get_size() const { return size; }
    int get_max_size() const { return max_size; }

    void add_element(T value) {
        this->resize_grow_if_needed();
        this->data[this->size++] = value;
    }

    void delete_element(T value) {
        for (unsigned i = 0; i < this->size; ++i) {
            if (this->data[i] == value) {
                this->data[i] = this->data[this->size - 1];
                this->size--;
                break;
            }
        }

        this->resize_shrink_if_needed();
    }

    int find(T value) const {
        for (unsigned i = 0; i < this->size; ++i) {
            if (this->data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    MyVector &operator=(MyVector &v) {
        if (this == &v) { // Исправлено: сравнение указателя this с адресом v
            return *this;
        }

        this->size = v.size;
        this->max_size = v.max_size;
        delete[] this->data;
        this->data = new T[this->max_size];

        for (unsigned i = 0; i < this->size; ++i) {
            this->data[i] = v.data[i];
        }
        return *this;
    };

    T& operator[](int index) {
        if (index < 0 || index >= this->size) {
            throw std::out_of_range("Индекс убежал");
        }
        return this->data[index];
    }

    friend std::ostream &operator<<(std::ostream &out, MyVector &v) {
        if (v.size == 0) {
            out << "Пустой вектор";
        } else {
            out << "[";
            for (unsigned i = 0; i < v.size; ++i) {
                out << v.data[i];
                if (i < v.size - 1) out << ", ";
            }
            out << "]";
        }
        return out;
    }
};

#endif // INHERITANCE_MYVECTOR_H
