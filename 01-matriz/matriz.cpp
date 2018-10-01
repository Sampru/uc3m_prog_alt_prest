//
// Created by sampru on 25/09/18.
//

#include "lib/matriz.h"

/* Constructores */
matriz::matriz () : fil{0}, col{0}, mat{nullptr} {}
matriz::matriz (int fil_, int col_) : fil{fil_}, col{col_}, mat{new double[fil_ * col_] {}} {}

/* Getters */
inline int matriz::filas() const { return this->fil;}
inline int matriz::columnas() const { return this->col;}
inline double* matriz::matrix() const { return this->mat;}

/* Operadores */
double& matriz::operator ()(const int fil_, const int col_) const {
    return mat[fil_ * col + col_];
}

double& matriz::operator ()(const int idx) const {
    return mat[idx];
}

matriz& matriz::operator =(const matriz &m) {
    this->fil = m.filas();
    this->col = m.columnas();
    this->mat = new double [this->fil * this->col];
    std::copy(m.matrix(), m.matrix() + (m.filas() * m.columnas()), this->mat);
    return *this;
}

matriz::matriz(matriz&& m) noexcept : col{m.columnas()}, fil{m.filas()} {
    this->mat = m.matrix();
}

matriz::~matriz() {
    delete []this->mat;
}

/* Funciones */
matriz operator +(const matriz &m1,const matriz &m2) {
    int max = m1.filas() * m1.columnas();
    matriz m3{m1.filas(), m1.columnas()};
    for (int i = 0; i < max; ++i) {
        m3(i) = m1(i) + m2(i);
    }
    return m3;
}

matriz operator *(const matriz &m1,const matriz &m2) {
    matriz m3{m1.filas(), m1.columnas()};
    for (int i = 0; i < (m1.filas() * m1.columnas()); i++) {
        double sum{0.0};
        for (int j = 0; j < m1.columnas(); j++) {
            sum += m1(j + ((i / m1.columnas()) * m1.columnas())) * m2((j * m2.columnas()) + (i % m2.filas()));
        }
        m3(i) = sum;
    }
    return m3;
}

std::ostream& operator <<(std::ostream &os, matriz &m) {
    for (int i = 0; i < m.filas(); i++) {
        for (int j = 0; j < m.columnas(); j++) {
            os << m(i, j) << "\t";
        }
        os << std::endl;
    }
    return  os;
}
