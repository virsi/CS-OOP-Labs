#pragma once
#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    void setReal(double r) { real = r; }
    void setImag(double i) { imag = i; }

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    friend std::ostream &operator<<(std::ostream &os, const Complex &c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + i * " << c.imag;
        } else {
            os << " - i * " << -c.imag;
        }
        return os;
    }
};
