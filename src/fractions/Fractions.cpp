#include "Fractions.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <tuple>
#include <cmath>

namespace
{
    const char SPACE = ' ';
    const char MINUS = '-';
    const char FRACTION_DELIM = '/';
    const int N_PRECISION = 4;
    const int MAX_INPUT_LEN = 40;

    int greatest_common_divisor(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

} // namespace

namespace fraction {
    struct DoubleResult {
        int value;
        int factor;
    };

    DoubleResult from_double(double number) {
        int factor = std::pow(10, N_PRECISION);
        return {static_cast<int>(number * factor), factor};
    }

    Fraction* ParseFraction(char* input) {
        int integer = 0, numerator = 0, denominator = 1;

        char* fractionPart = strchr(input, ' '); // Ищем пробел
        if (fractionPart) {
            *fractionPart = '\0';  // Разделяем строку на две части
            integer = std::atoi(input); // Преобразуем целую часть в число
            input = fractionPart + 1; // Переходим к дробной части
        }

        char* slashPos = strchr(input, '/'); // Ищем '/'
        if (slashPos) {
            *slashPos = '\0';  // Разделяем дробь
            numerator = std::atoi(input);
            denominator = std::atoi(slashPos + 1);
        } else if (!fractionPart) {
            integer = std::atoi(input); // Если нет дроби, это просто целое число
        }

        return new Fraction(integer, numerator, denominator);
    }

    Fraction::Fraction(int integer, int numerator, int denominator) {
        if (denominator == 0) {
            std::cout << "Detected division by zero" << std::endl;
            exit(1);
        }

        this->integer = integer;
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction::Fraction(int numerator, int denominator) {
        this->integer = 0;
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction::Fraction(char* input) {
        Fraction* parsedFraction = ParseFraction(input);

        this->integer = parsedFraction->integer;
        this->numerator = parsedFraction->numerator;
        this->denominator = parsedFraction->denominator;
    }

    Fraction::Fraction(double number) {
        DoubleResult obj = from_double(number);

        this->numerator = obj.value;
        this->denominator = obj.factor;

        this->simplify();
    }

    void Fraction::simplify() {
        if (this->numerator == 0) {
            this->denominator = 1;
            return;
        }

        int gcd = greatest_common_divisor(this->numerator, this->denominator);

        this->numerator /= gcd;
        this->denominator /= gcd;

        bool isMinus = (this->integer < 0) ^ (this->numerator < 0);
        this->numerator = std::abs(this->numerator);
        // Нормализация дроби
        if (this->numerator >= this->denominator) {
            int integerDelta = this->numerator / this->denominator;
            this->integer += isMinus ? -integerDelta : integerDelta;

            this->numerator %= this->denominator;
        }
    }

    Fraction Fraction::operator+(const Fraction& other) const {
        int numerator = this->numerator * other.denominator + this->denominator * other.numerator;
        int denominator = this->denominator * other.denominator;

        auto instance = Fraction(this->integer + other.integer, numerator, denominator);
        instance.simplify();

        return instance;
    }

    Fraction Fraction::operator+(double number) const {
        return *this + Fraction(number);
    }
    Fraction Fraction::operator+(int number) const {
        return *this + Fraction(number);
    }

    void Fraction::operator+=(const Fraction& other) {
        *this = *this + other;
    }

    void Fraction::operator+=(double number) {
        *this += Fraction(number);
    }

    Fraction operator+(double number, const Fraction& other) {
        return other + number;
    }

    Fraction operator+(int number, const Fraction& other) {
        return other + number;
    }

    std::istream& operator>>(std::istream& s, Fraction& f) {
        char input[MAX_INPUT_LEN];

        if (!s.getline(input, MAX_INPUT_LEN)) {
            std::cerr << "Input buffer overflow detected" << std::endl;
            s.clear(std::istream::failbit);
            exit(1);
        }

        Fraction* parsedFraction = ParseFraction(input);
        f = *parsedFraction;
        delete parsedFraction;

        return s;
    }

    std::ostream& operator<<(std::ostream& s, Fraction& f) {
        f.simplify();

        if ((f.integer < 0) ^ (f.numerator < 0)) {
            s << MINUS;
        }

        if (f.integer != 0) {
            s << std::abs(f.integer);
        }

        if (f.numerator != 0) {
            if (f.integer != 0) {
                s << SPACE;
            }
            s << std::abs(f.numerator) << FRACTION_DELIM << std::abs(f.denominator);
        }

        if (f.integer == 0 && f.numerator == 0) {
            s << "0";
        }

        std::cout << std::endl;

        return s;
    }
}  // namespace fraction
