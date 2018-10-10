//
// Created by sampru on 25/09/18.
//

#include <random>

#include "../lib/matriz.h"

/****************
 * Constructors *
 ****************/
matriz::matriz () : fil{0}, col{0}, mat{nullptr} {}

matriz::matriz (int fil_, int col_) : fil{fil_}, col{col_}, mat{new double[fil_ * col_] {}} {
    if (fil_ != col_) std::cerr << "*** Wrong dimensions for a square matrix :S ***" << std::endl
                                << "***        Expect unexpected output         ***" << std::endl;
}

/*************
 * Operators *
 *************/
double& matriz::operator ()(const int fil_, const int col_) const {
    return mat[fil_ * col + col_];
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

/****************
 * Requirements *
 ****************/
double matriz::diagonal() {
    double ret = 0.0;
    for (int i = 0; i < this->fil ; i++)
        ret += this->operator()(i, i);
    return ret;
}

void matriz::fill_random() {
    using namespace std;
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> rand (2.5, 5.0);
    for (int i = 0; i < this->fil * this->col; i++) {
        this->mat[i] = rand(gen);
    }
}


/************
 * Overload *
 ************/
matriz operator +(const matriz &m1,const matriz &m2) {
    int max = m1.fil * m1.col;
    matriz m3{m1.fil, m1.col};
    for (int i = 0; i < max; ++i) {
        m3.mat[i] = m1.mat[i] + m2.mat[i];
    }
    return m3;
}

matriz operator *(const matriz &m1, const matriz &m2) {
    matriz m3{m1.fil, m2.col};
    int size = m3.col;
    if (MODE) {
        int bsize = size < 4 ? 1 : size < 1000 ? (size / 2) - 1 : 100;


        for (int bj = 0; bj < size; bj += bsize) {
            for (int bk = 0; bk < size; bk += bsize) {
                for (int i = 0; i < size; i++) {
                    for (int j = bj; j < std::min(bj + bsize, size); j++) {
                        double sum = 0.0;
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
                double sum = 0.0;
                for (int k = 0; k < size; k++) {
                    sum += m1(i, k) * m2(k, j);
                }
                m3(i, j) += sum;
            }
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