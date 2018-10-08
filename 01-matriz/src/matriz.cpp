//
// Created by sampru on 25/09/18.
//

#include "../lib/matriz.h"

/* Constructors */
matriz::matriz () : fil{0}, col{0}, mat{nullptr} {}
matriz::matriz (int fil_, int col_) : fil{fil_}, col{col_}, mat{new double[fil_ * col_] {}} {
    if (fil_ != col_) std::cerr << "*** Wrong dimensions for a square matrix :S ***" << std::endl
                                << "***        Expect unexpected output         ***" << std::endl;
}

/* Operators */
double& matriz::operator ()(const int fil_, const int col_) const {
    return mat[fil_ * col + col_];
}

double& matriz::operator ()(const int idx) const {
    return mat[idx];
}

matriz& matriz::operator =(const matriz &m) {
    this->fil = m.fil;
    this->col = m.col;
    this->mat = new double [this->fil * this->col];
    std::copy(m.mat, m.mat + (m.fil * m.col), this->mat);
    return *this;
}

matriz::matriz(matriz&& m) noexcept : col{m.col}, fil{m.fil} {
    this->mat = m.mat;
}

matriz::~matriz() {
    delete []this->mat;
}

 /* Requisites */
double matriz::calculate_diagonal() {
    double ret = 0.0;
    for (int i = 0; i < this->fil ; i++)
        ret += this->operator()(i, i);
    return ret;
}



/* Overload */
matriz operator +(const matriz &m1,const matriz &m2) {
    int max = m1.fil * m1.col;
    matriz m3{m1.fil, m1.col};
    for (int i = 0; i < max; ++i) {
        m3(i) = m1(i) + m2(i);
    }
    return m3;
}

matriz operator *(const matriz &m1, const matriz &m2) {
    matriz m3{m1.fil, m2.col};

    for (int i = 0; i < m1.fil; i++) {
        for (int j = 0; j < m2.col; j++) {
            double sum = 0.0;
            for (int k = 0; k < m3.fil; k++) {
                sum += m1(i, k) * m2(k, j);
            }
            m3(i,j) = sum;
        }
    }
    return m3;
}

std::ostream& operator <<(std::ostream &os, matriz &m) {
    for (int i = 0; i < m.fil; i++) {
        for (int j = 0; j < m.col; j++) {
            os << m(i, j) << "\t";
        }
        os << std::endl;
    }
    return  os;
}
