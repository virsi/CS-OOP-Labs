#pragma once
#include <iostream>
#include "../MyVector/MyVector.hpp"

class Term {
private:
    int coefficient;
    int exponent;
    friend Polynomial;
public:
    Term();
    Term(int coef): coefficient(coef) {};
    Term(int coeff, int exp): coefficient(coeff), exponent(exp) {};
    ~Term();

    static Term parse(char*& el);
    void writeToStream(std::ostream& out, bool as_sequence = false) const;

    bool isZero() const;

    bool operator==(const Term& other) const;
    bool operator<(const Term& other) const;
    Term operator+(const Term& other) const;
    Term operator*(const Term& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Term& term);
    friend std::istream& operator>>(std::istream& in, Term& term);
};


class Polynomial {
private:
    MyVector<Term> poly;
    int exponent;

public:
    Polynomial();
    Polynomial(int n);
    Polynomial(Term term);
    Polynomial(Polynomial& p) {poly = p.poly; exponent = p.exponent;}
    ~Polynomial();

    void operator+=(const Polynomial& other);
    void operator*=(const Polynomial& other);
    void operator==(const Polynomial& other);

    friend Polynomial operator+(const Polynomial& left, const Polynomial& right);
    friend Polynomial operator*(const Polynomial& left, const Polynomial& right);

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
    friend std::istream& operator>>(std::istream& is, Polynomial& poly);



};
