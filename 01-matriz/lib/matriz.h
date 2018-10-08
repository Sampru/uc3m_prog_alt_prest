//
// Created by sampru on 24/09/18.
//

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H

#include <iostream>

class matriz {
public:
    /* Constructores */
    matriz ();
    matriz (int fil_, int col_);
    matriz (matriz&& m) noexcept;
    matriz& operator =(const matriz&);
    ~matriz();

    /* Acceso a matriz */
    double& operator ()(int fil_, int col_) const;
    double& operator ()(int idx) const;

    /* Requisitos */
    double calcular_diagonal();
    double calcular_diagonal_loop();

    /* Datamembers */
    double *mat;
    int  fil {0};
    int  col {0};

private:
    double calcular_diagonal(int i);
};


/* Operadores */
std::ostream & operator<<(std::ostream &os, matriz &m);
matriz operator +(const matriz &m1,const matriz &m2);
matriz operator *(const matriz &m1,const matriz &m2);


#endif //MATRIZ_MATRIZ_H
