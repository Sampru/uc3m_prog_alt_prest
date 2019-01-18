//
// Created by sampru on 31/12/18.
//

#ifndef INC_03_CLASIF_MARKET_DATA_PRECIO_H
#define INC_03_CLASIF_MARKET_DATA_PRECIO_H


#include <algorithm>
#include <time.h>
#include <iterator>
#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include "regresion_lineal.h"

class Precio {
public:
    long micro{0l};
    std::string instrumento{""};
    time_t tt_tiempo{};
    struct tm tm_tiempo{};
    double precio{0.0};

    Precio() = default;

    explicit Precio(std::string input);

    Precio &operator=(const Precio &);

    ~Precio() = default;
};

std::ostream &operator<<(std::ostream &os, Precio &precio);

void agruparPrecios(std::map<std::string, std::map<time_t, std::vector<Precio>>> preciosSeparados,
                    std::map<std::string, std::map<time_t, Precio>> &preciosAgrupados);

Precio mediaRegresionLineal(std::vector<Precio> precios);

#endif //INC_03_CLASIF_MARKET_DATA_PRECIO_H
