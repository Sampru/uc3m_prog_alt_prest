//
// Created by sampru on 24/09/18.
//

/* Globals */
extern int DIMENSION;
extern bool MODE;
extern bool PRINT;

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H

#include <iostream>
#include <random>
#include <type_traits>
#include "Racional.h"

// Forward declarations.
template<template<class> class H, class S>
class Matriz<H<S>>;

template<typename T, typename = typename std::enable_if<std::is_signed<T>::value, T>::type>
class Matriz;


/************************************************/
/** Template especifico para numeros con signo **/
/************************************************/

template<typename T, typename>
class Matriz {
public:
    /* Empty constructor */
    Matriz() = default;

    /* Size constructor */
    Matriz(int fil_, int col_) : fil{fil_}, col{col_}, mat{new T[fil_ * col_]{}} {
        if (fil_ != col_)
            std::cerr << "*** Wrong dimensions for a square matrix :S ***" << std::endl
                      << "***        Expect unexpected output         ***" << std::endl;
    }

    /* Move operator */
    Matriz(Matriz &&m) noexcept : col{m.col}, fil{m.fil} {
        this->mat = m.mat;
    }

    /* Copy operator */
    Matriz &operator=(const Matriz &m) {
        this->fil = m.fil;
        this->col = m.col;
        this->mat = new T[this->fil * this->col];
        std::copy(m.mat, m.mat + (m.fil * m.col), this->mat);
        return *this;
    }

    /* Destructor */
    ~Matriz() {
        delete[]this->mat;
    }

    /* 2 params parenthesis operator */
    T &operator()(const int fil_, const int col_) const {
        return mat[fil_ * col + col_];
    }

    /* Calculate the diagonal value */
    T &diagonal() {
        T &ret = *new T;
        for (int i = 0; i < this->fil; i++)
            ret += this->operator()(i, i);
        return ret;
    }

    /* Fill with random values */
    void fill_random(double mean, double sig) {
        using namespace std;
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<double> rand(mean, sig);
        for (int i = 0; i < this->fil * this->col; i++) {
            this->mat[i] = rand(gen);
        }
    }

    /* Datamembers */
    T *mat{nullptr};
    int fil{0};
    int col{0};
};


/* << Matriz operator */
template<typename T>
std::ostream &operator<<(std::ostream &os, Matriz<T> &m) {
    for (int i = 0; i < m.fil; i++) {
        for (int j = 0; j < m.col; j++) {
            os << m(i, j) << "\t";
        }
        os << std::endl;
    }
    return os;
}

/* matriz1 + matriz2 operator */
template<typename T>
Matriz<T> operator+(const Matriz<T> &m1, const Matriz<T> &m2) {
    int max = m1.fil * m1.col;
    Matriz<T> m3{m1.fil, m1.col};
    for (int i = 0; i < max; ++i) {
        m3.mat[i] = m1.mat[i] + m2.mat[i];
    }
    return m3;
}

/* matriz1 * matriz2 operator */
template<typename T>
Matriz<T> operator*(const Matriz<T> &m1, const Matriz<T> &m2) {
    Matriz<T> m3{m1.fil, m2.col};
    int size = m3.col;
    if (MODE) {
        int bsize = size < 4 ? 1 : size < 1000 ? (size / 2) - 1 : 100;


        for (int bj = 0; bj < size; bj += bsize) {
            for (int bk = 0; bk < size; bk += bsize) {
                for (int i = 0; i < size; i++) {
                    for (int j = bj; j < std::min(bj + bsize, size); j++) {
                        T &sum = *new T;
                        for (int k = bk; k < std::min(bk + bsize, size); k++) {
                            sum += m1(i, k) * m2(k, j);
                        }
                        m3(i, j) += sum;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                T &sum = *new T;
                for (int k = 0; k < size; k++) {
                    sum += m1(i, k) * m2(k, j);
                }
                m3(i, j) += sum;
            }
        }
    }

    return m3;
}

/*****************************************/
/** Template especifico para Racionales **/
/*****************************************/

template<template<class> class H, class S>
class Matriz<H<S>> {
public:
    /* Empty constructor */
    Matriz() = default;

    /* Size constructor */
    Matriz(int fil_, int col_) : fil{fil_}, col{col_}, mat{new H<S>[fil_ * col_]{}} {
        if (fil_ != col_)
            std::cerr << "*** Wrong dimensions for a square matrix :S ***" << std::endl
                      << "***        Expect unexpected output         ***" << std::endl;
    }

    /* Move operator */
    Matriz(Matriz &&m) noexcept : col{m.col}, fil{m.fil} {
        this->mat = m.mat;
    }

    /* Copy operator */
    Matriz &operator=(const Matriz &m) {
        this->fil = m.fil;
        this->col = m.col;
        this->mat = new H<S>[this->fil * this->col];
        std::copy(m.mat, m.mat + (m.fil * m.col), this->mat);
        return *this;
    }

    /* Destructor */
    ~Matriz() {
        delete[]this->mat;
    }

    /* 2 params parenthesis operator */
    H<S> &operator()(const int fil_, const int col_) const {
        return mat[fil_ * col + col_];
    }

    /* Calculate the diagonal value */
    H<S> &diagonal() {
        H<S> &ret = *new H<S>;
        for (int i = 0; i < this->fil; i++)
            ret += this->operator()(i, i);
        return ret;
    }

    /* Fill with random values */
    void fill_random(double mean, double sig) {
        using namespace std;
        H<S> r;
        random_device rd;
        mt19937 gen(rd());
        normal_distribution<double> rand(mean, sig);
        for (int i = 0; i < this->fil * this->col; i++) {
            this->mat[i] = H<S>{rand(gen), rand(gen)};
        }
    }

    /* Datamembers */
    H<S> *mat{nullptr};
    int fil{0};
    int col{0};
};


/* << Matriz operator */
template<template<class> class H, class S>
std::ostream &operator<<(std::ostream &os, Matriz<H<S>> &m) {
    for (int i = 0; i < m.fil; i++) {
        for (int j = 0; j < m.col; j++) {
            os << m(i, j) << "\t";
        }
        os << std::endl;
    }
    return os;
}

/* matriz1 + matriz2 operator */
template<template<class> class H, class S>
Matriz<H<S>> operator+(const Matriz<H<S>> &m1, const Matriz<H<S>> &m2) {
    int max = m1.fil * m1.col;
    Matriz<H<S>> m3{m1.fil, m1.col};
    for (int i = 0; i < max; ++i) {
        m3.mat[i] = m1.mat[i] + m2.mat[i];
    }
    return m3;
}

/* matriz1 * matriz2 operator */
template<template<class> class H, class S>
Matriz<H<S>> operator*(const Matriz<H<S>> &m1, const Matriz<H<S>> &m2) {
    Matriz<H<S>> m3{m1.fil, m2.col};
    int size = m3.col;
    if (MODE) {
        int bsize = size < 4 ? 1 : size < 1000 ? (size / 2) - 1 : 100;


        for (int bj = 0; bj < size; bj += bsize) {
            for (int bk = 0; bk < size; bk += bsize) {
                for (int i = 0; i < size; i++) {
                    for (int j = bj; j < std::min(bj + bsize, size); j++) {
                        H<S> &sum = *new H<S>;
                        for (int k = bk; k < std::min(bk + bsize, size); k++) {
                            sum += m1(i, k) * m2(k, j);
                        }
                        m3(i, j) += sum;
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                H<S> &sum = *new H<S>;
                for (int k = 0; k < size; k++) {
                    sum += m1(i, k) * m2(k, j);
                }
                m3(i, j) += sum;
            }
        }
    }

    return m3;
}


#endif //MATRIZ_MATRIZ_H
