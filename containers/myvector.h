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
            this->data[i] = v.data[i]
        }
    }

    ~MyVector(){delete[] this->data;}
    
    void add_element(char *el);
    bool delete_element(int i);
    char *operator[](int i);
    void sort();
    int get_size() { return size; }
    int get_max_size() { return max_size; }
    int find(char *el);
    MyVector &operator=(MyVector &v);
    friend std::ostream &operator<<(std::ostream &out, MyVector &v);
};

#endif // INHERITANCE_MYVECTOR_H
