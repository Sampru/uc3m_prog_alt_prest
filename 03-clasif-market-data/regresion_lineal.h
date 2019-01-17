//
// Created by sampru on 1/12/19.
//

#ifndef INC_03_CLASIF_MARKET_DATA_REGRESION_LINEAL_H
#define INC_03_CLASIF_MARKET_DATA_REGRESION_LINEAL_H

#include <vector>
#include "Precio.h"

namespace lin {

    inline double valorM(double x, double y, double xy, double xx, double n) {
        return ((n * xy) - (x * y)) / ((n * xx) - (x * x));
    }

    inline double valorY0(double x, double y, double m, double n) {
        return (y - (m * x)) / n;
    }


    inline double precioMedio(double y0, double m) {
        return (y0 + m * 30000000);
    }
}

#endif //INC_03_CLASIF_MARKET_DATA_REGRESION_LINEAL_H
