//
// Created by sampru on 31/12/18.
//

#ifndef INC_03_CLASIF_MARKET_DATA_PRECIO_H
#define INC_03_CLASIF_MARKET_DATA_PRECIO_H


#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

class Precio {
public:
    int anyo = 0;
    int mes = 0;
    int dia = 0;
    int hora = 0;
    int minuto = 0;
    long nano = 0;
    std::string instrumento = "";
    std::string tiempo = "";
    double precio = 0.0;

    Precio() = default;

    explicit Precio(std::string);

    ~Precio() = default;
};

std::ostream &operator<<(std::ostream &os, Precio &precio);

#endif //INC_03_CLASIF_MARKET_DATA_PRECIO_H
