//
// Created by sampru on 25/09/18.
//

#include "lib/matriz.h"

/* Constructores */
Matriz::Matriz () : fil{0}, col{0}, mat{nullptr} {}
Matriz::Matriz (int fil_, int col_) : fil{fil_}, col{col_}, mat{new double[fil_ * col_] {}} {}

/* Getters */
inline int Matriz::filas() const { return this->fil;}
inline int Matriz::columnas() const { return this->col;}
inline double* Matriz::matriz() const { return this->mat;}

/* Operadores */
double& Matriz::operator ()(const int fil_, const int col_) const {
    return mat[fil_ * col + col_];
}

double& Matriz::operator ()(const int idx) const {
    return mat[idx];
}

Matriz& Matriz::operator =(const Matriz &m) {
    this->fil = m.filas();
    this->col = m.columnas();
    this->mat = new double [this->fil * this->col];
    std::copy(m.matriz(), m.matriz() + (m.filas() * m.columnas()), this->mat);
    return *this;
}

/* Funciones */
Matriz operator +(const Matriz &m1,const Matriz &m2) {
    int max = m1.filas() * m1.columnas();
    Matriz m3{m1.filas(), m1.columnas()};
    for (int i = 0; i < max; ++i) {
        m3(i) = m1(i) + m2(i);
    }
    return m3;
}

Matriz operator *(const Matriz &m1,const Matriz &m2) {
    Matriz m3{m1.filas(), m1.columnas()};
    for (int i = 0; i < (m1.filas() * m1.columnas()); i++) {
        double sum{0.0};
        for (int j = 0; j < m1.columnas(); j++) {
            sum += m1(j + ((i / m1.columnas()) * m1.columnas())) * m2((j * m2.columnas()) + (i % m2.filas()));
        }
        m3(i) = sum;
    }
    return m3;
}

std::ostream& operator <<(std::ostream &os, Matriz &m) {
    for (int i = 0; i < m.filas(); i++) {
        for (int j = 0; j < m.columnas(); j++) {
            os << m(i, j) << "\t";
        }
        os << std::endl;
    }
    return  os;
}
