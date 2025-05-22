#include "Polynomial.hpp"
namespace {
    int BUFSIZE = 1024;
}

namespace polynomial {
    namespace term {
        void Term::writeToStream(std::ostream& out, bool as_sequence) const {
            if (this->coefficient == 0) {
                return;
            }

            if (as_sequence) {
                out << (this->coefficient < 0 ? "-" : "+") << " ";
            } else if (this->coefficient < 0) {
                out << "-";
            }

            int k = std::abs(this->coefficient);

            if (this->exponent == 0) {
                // Для свободного члена выводим коэффициент полностью (включая -1 и 1)
                out << k;
            } else {
                if (k > 1) {
                    out << k;
                }
            }

            switch (this->exponent) {
                case 0:
                    break;
                case 1:
                    out << "x";
                    break;
                default:
                    out << "x^" << this->exponent;
                    break;
            }

            out << " ";

            return;
        }

        Term Term::parse(char*& el) {
            while (*el == ' ') {
                ++el;
            };

            int sign = 1;
            if (*el == '+' || *el == '-') {
                if (*el == '-') {
                    sign = -1;
                }
                ++el;
            }

            while (*el == ' ') {
                ++el;
            }

            int coefficient = 0;
            bool has_digits = false;
            if (std::isdigit(*el)) {
                while (std::isdigit(*el)) {
                    coefficient = coefficient * 10 + (*el - '0');
                    ++el;
                    has_digits = true;
                }
            }
            if (!has_digits) {
                coefficient = 1;  // Если коэффициент не указан, он равен 1
            }
            coefficient *= sign;

            if (*el != 'x') {
                return {coefficient};
            }
            ++el;  // Пропуск символа 'x'

            while (*el == ' ') {
                ++el;
            }

            if (*el != '^') {
                return {coefficient, 1};
            }
            ++el;  // Пропуск символа '^'

            int exponent = 0;
            bool exp_digits = false;
            if (std::isdigit(*el)) {
                while (std::isdigit(*el)) {
                    exponent = exponent * 10 + (*el - '0');
                    ++el;
                    exp_digits = true;
                }
            }
            if (!exp_digits) {
                exponent = 1;  // Если степень не указана, она равна 1
            }

            return {coefficient, exponent};
        }

        Term::Term(int coefficient, int exponent) {
            this->coefficient = coefficient;
            this->exponent = exponent;
        }

        bool Term::isZero() const {
            return this->coefficient == 0;
        }

        bool Term::operator==(const Term& other) const {
            return this->exponent == other.exponent;
        }

        bool Term::operator<(const Term& other) const {
            return this->exponent < other.exponent;
        }

        Term Term::operator+(const Term& other) const {
            if (this->exponent != other.exponent) {
                throw std::invalid_argument("Terms have different exponents");
            }
            return {this->coefficient + other.coefficient, this->exponent};
        }

        Term Term::operator*(const Term& other) const {
            return {this->coefficient * other.coefficient, this->exponent + other.exponent};
        }

        std::ostream& operator<<(std::ostream& out, const Term& term) {
            term.writeToStream(out);
            return out;
        }

        std::istream& operator>>(std::istream& is, Term& term) {
            char* buffer = new char[BUFSIZE];
            is.getline(buffer, BUFSIZE);

            char* el = buffer;
            term = Term::parse(el);

            delete[] buffer;
            return is;
        }
    }  // namespace term

    Polynomial::Polynomial(int n) {
        this->poly.push_back(term::Term(n));
    }

    Polynomial::Polynomial(term::Term term) {
        this->poly.push_back(term);
    }

    Polynomial::Polynomial(const Polynomial& other) {
        this->poly = other.poly; // Копируем вектор
        this->ascending = other.ascending; // Копируем порядок сортировки
    }

    void Polynomial::operator+=(const Polynomial& other) {
        *this = *this + other;
    }

    void Polynomial::operator*=(const Polynomial& other) {
        *this = *this * other;
    }

    Polynomial operator+(const Polynomial& left, const Polynomial& right) {
        Polynomial result = left;

        Polynomial rightCopy = right;
        for (int i = 0; i < rightCopy.poly.size(); ++i) {
            int idx = result.poly.binary_search(rightCopy.poly[i], result.ascending);

            if (idx != -1) {
                result.poly[idx] = result.poly[idx] + rightCopy.poly[i];
                rightCopy.poly.remove(rightCopy.poly[i]);
                --i;
            }
        }

        for (int i = 0; i < rightCopy.poly.size(); ++i) {
            result.poly.push_back(rightCopy.poly[i]);
        }
        if (rightCopy.poly.size() == 0) {
            result.poly.sort(result.ascending);
        }

        // Удаляем нулевые члены из результата
        for (int i = 0; i < result.poly.size(); ++i) {
            if (result.poly[i].isZero()) {
                result.poly.remove(i);
                --i;
            }
        }

        // Сортируем и объединяем одинаковые степени
        result.poly.sort(result.ascending);
        for (int i = 1; i < result.poly.size(); ++i) {
            if (result.poly[i].getExponent() == result.poly[i-1].getExponent()) {
                result.poly[i-1] = result.poly[i-1] + result.poly[i];
                result.poly.remove(i);
                --i;
            }
        }
        // Удаляем нулевые члены после объединения
        for (int i = 0; i < result.poly.size(); ++i) {
            if (result.poly[i].isZero()) {
                result.poly.remove(i);
                --i;
            }
        }

        return result;
    }

    Polynomial operator*(const Polynomial& left, const Polynomial& right) {
        Polynomial polynomial = {};

        for (int i = 0; i < left.poly.size(); ++i) {
            for (int j = 0; j < right.poly.size(); ++j) {
                polynomial += left.poly[i] * right.poly[j];
            }
        }

        return polynomial;
    }

    std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial) {
        // `Poly` should be sorted
        bool has_nonzero = false;
        for (int i = 0; i < polynomial.poly.size(); ++i) {
            if (!polynomial.poly[i].isZero()) {
                polynomial.poly[i].writeToStream(out, has_nonzero);
                has_nonzero = true;
            }
        }
        // Если не было ни одного ненулевого члена, выводим 0
        if (!has_nonzero) {
            out << "0 ";
        }
        return out;
    }

    std::istream& operator>>(std::istream& is, Polynomial& polynomial) {
        char* buffer = new char[BUFSIZE];
        is.getline(buffer, BUFSIZE);

        char* el = buffer;
        while (*el != '\0') {
            term::Term t = term::Term::parse(el);
            if (!t.isZero()) {
                polynomial += t;
            }
            // Пропуск лишних символов между членами (например, '+', '-')
            while (*el == ' ' || *el == '+' || *el == '-') {
                // Если это знак, не пропускаем, чтобы парсер увидел его
                if (*el == '+' || *el == '-') break;
                ++el;
            }
        }

        delete[] buffer;
        return is;
    }
}  // namespace polynomial
