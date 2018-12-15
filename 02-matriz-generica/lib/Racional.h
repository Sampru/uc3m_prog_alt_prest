//
// Created by sampru on 27/11/18.
//

#ifndef MATRIZ_RACIONAL_H
#define MATRIZ_RACIONAL_H

#include <iostream>
#include <cmath>
#include <sstream>
#include <type_traits>


template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
class Racional {
private:

    T euclidean(T a, T b) const {
        if (b == 0.0) throw -1;
        else {
            T aux = a % b;
            while (aux != 0.0) {
                a = b;
                b = aux;
                aux = a % b;
            }
            return (b);
        }
    }

public:
    Racional() = default;

    Racional(T num, T den) {
        T gcd = euclidean(std::max(num, den), std::min(num, den));
        numerador = (num / gcd);
        denominador = (den / gcd);
    }

    ~Racional() = default;

    Racional &operator=(const Racional &r) {
        this->numerador = r.numerador;
        this->denominador = r.denominador;
        return *this;
    }

    Racional(Racional &&r) noexcept {
        T gcd = euclidean(std::max(r.numerador, r.denominador), std::min(r.numerador, r.denominador));
        T num = (r.numerador / gcd);
        T den = (r.denominador / gcd);
        this->numerador = num;
        this->denominador = den;
    }

    void operator()(const T num, const T den) {
        T gcd = euclidean(std::max(num, den), std::min(num, den));
        numerador = (num / gcd);
        denominador = (den / gcd);
    }

    T numerador{0};
    T denominador{1};
};

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
Racional<T> operator+(const Racional<T> &r1, const Racional<T> &r2) {
    Racional<T> r3{};

    r3((r1.numerador * r2.denominador + r2.numerador * r1.denominador), (r1.denominador * r2.denominador));

    return r3;
}

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
Racional<T> operator+=(const Racional<T> &r1, const Racional<T> &r2) {
    Racional<T> r3{};

    r3((r1.numerador * r2.denominador + r2.numerador * r1.denominador), (r1.denominador * r2.denominador));

    return r3;
}

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
Racional<T> operator*(const Racional<T> &r1, const Racional<T> &r2) {
    Racional<T> r3{};

    r3((r1.numerador * r2.numerador), (r1.denominador * r2.denominador));

    return r3;
}

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
Racional<T> operator*=(const Racional<T> &r1, const Racional<T> &r2) {
    Racional<T> r3{};

    r3((r1.numerador * r2.numerador), (r1.denominador * r2.denominador));

    return r3;
}

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
std::ostream &operator<<(std::ostream &os, Racional<T> &r) {

    os << r.numerador << "/" << r.denominador;

    return os;
}

#endif //MATRIZ_RACIONAL_H
