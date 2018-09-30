//
// Created by sampru on 24/09/18.
//

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H

#include <iostream>

class Matriz {
public:
    /* Constructores */
    Matriz ();
    Matriz (int fil_, int col_);


    /* Copia y movimiento */
    Matriz& operator =(const Matriz&);

    /* Acceso a 01-matriz */
    double& operator ()(int fil_, int col_) const;
    double& operator ()(int idx) const;

    /* Getters */
    int filas () const;
    int columnas () const;
    double* matriz () const;

private:
    /* Miembros */
    double *mat;
    int  fil {0};
    int  col {0};

};


/* Operadores */
std::ostream & operator<<(std::ostream &os, Matriz &m);
Matriz operator +(const Matriz &m1,const Matriz &m2);
Matriz operator *(const Matriz &m1,const Matriz &m2);


#endif //MATRIZ_MATRIZ_H
