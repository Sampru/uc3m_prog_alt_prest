//
// Created by sampru on 24/09/18.
//

#ifndef MATRIZ_MATRIZ_H
#define MATRIZ_MATRIZ_H

#include <iostream>

class matriz {
public:
    /* Constructors */
    matriz ();
    matriz (int fil_, int col_);
    matriz (matriz&& m) noexcept;
    matriz& operator =(const matriz&);
    ~matriz();

    /* Operators */
    double& operator ()(int fil_, int col_) const;
    double& operator ()(int idx) const;

    /* Requisites */
    double calculate_diagonal();

    /* Datamembers */
    double *mat;
    int  fil {0};
    int  col {0};
};


/* Operators */
std::ostream & operator<<(std::ostream &os, matriz &m);
matriz operator +(const matriz &m1,const matriz &m2);
matriz operator *(const matriz &m1,const matriz &m2);


#endif //MATRIZ_MATRIZ_H
