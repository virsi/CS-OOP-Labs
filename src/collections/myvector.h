#ifndef INHERITANCE_MYVECTOR_H
#define INHERITANCE_MYVECTOR_H

#include <iostream>
#include <cstring>

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
        T* new_data = new T[this->max_size];

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
    MyVector() {
        this->data = new T[DEFAULT_CAPACITY];
        this->max_size = DEFAULT_CAPACITY;
    }

    MyVector(const MyVector& v) {
        this->size = v.size;
        this->max_size = v.max_size;
        this->data = new T[this->max_size];

        for (unsigned i = 0; i < this->size; ++i) {
            if constexpr (std::is_same<T, char*>::value) {
                this->data[i] = new char[strlen(v.data[i]) + 1];
                strcpy(this->data[i], v.data[i]);
            } else {
                this->data[i] = v.data[i];
            }
        }
    }

    ~MyVector() {
        if constexpr (std::is_same<T, char*>::value) {
            for (unsigned i = 0; i < this->size; ++i) {
                if (this->data[i] != nullptr) {
                    delete[] this->data[i];
                    this->data[i] = nullptr;
                }
            }
        }
        delete[] this->data;
    }

    int get_size() const { return size; }
    int get_max_size() const { return max_size; }

    void add_element(T value) {
        this->resize_grow_if_needed();
        if constexpr (std::is_same<T, char*>::value) {
            this->data[this->size] = new char[strlen(value) + 1];
            strcpy(this->data[this->size], value);
        } else {
            this->data[this->size] = value;
        }
        this->size++;
    }

    void delete_element(T value) {
        for (unsigned i = 0; i < this->size; ++i) {
            if constexpr (std::is_same<T, char*>::value) {
                if (strcmp(this->data[i], value) == 0) {
                    delete[] this->data[i];
                    this->data[i] = this->data[this->size - 1];
                    this->data[this->size - 1] = nullptr; // Обнуляем последний элемент
                    this->size--;
                    break;
                }
            } else {
                if (this->data[i] == value) {
                    this->data[i] = this->data[this->size - 1];
                    this->size--;
                    break;
                }
            }
        }
        this->resize_shrink_if_needed();
    }

    int find(T value) const {
        for (unsigned i = 0; i < this->size; ++i) {
            if constexpr (std::is_same<T, char*>::value) {
                if (strcmp(this->data[i], value) == 0) {
                    return i;
                }
            } else {
                if (this->data[i] == value) {
                    return i;
                }
            }
        }
        return -1;
    }

    MyVector& operator=(const MyVector& v) {
        if (this == &v) {
            return *this;
        }

        if constexpr (std::is_same<T, char*>::value) {
            for (unsigned i = 0; i < this->size; ++i) {
                if (this->data[i] != nullptr) {
                    delete[] this->data[i];
                    this->data[i] = nullptr;
                }
            }
        }
        delete[] this->data;

        this->size = v.size;
        this->max_size = v.max_size;
        this->data = new T[this->max_size];

        for (unsigned i = 0; i < this->size; ++i) {
            if constexpr (std::is_same<T, char*>::value) {
                this->data[i] = new char[strlen(v.data[i]) + 1];
                strcpy(this->data[i], v.data[i]);
            } else {
                this->data[i] = v.data[i];
            }
        }
        return *this;
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= this->size) {
            throw std::out_of_range("Индекс убежал");
        }
        return this->data[index];
    }

    friend std::ostream& operator<<(std::ostream& out, MyVector& v) {
        if (v.size == 0) {
            out << "Пустой вектор";
        } else {
            out << "[";
            for (unsigned i = 0; i < v.size; ++i) {
                if constexpr (std::is_same<T, char*>::value) {
                    out << v.data[i];
                } else {
                    out << v.data[i];
                }
                if (i < v.size - 1) out << ", ";
            }
            out << "]";
        }
        return out;
    }
};

#endif // INHERITANCE_MYVECTOR_H
