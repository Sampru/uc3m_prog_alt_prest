//
// Created by sampru on 2/01/19.
//

#ifndef INC_03_CLASIF_MARKET_DATA_FILE_UTIL_H
#define INC_03_CLASIF_MARKET_DATA_FILE_UTIL_H


#include <map>
#include <fstream>
#include "Precio.h"

namespace fut {

    void read(const std::string &nombre, std::map<std::string, std::map<time_t, std::vector<Precio>>> &precios);

    void write(std::string nombre, std::map<std::string, std::map<time_t, Precio>> preciosSeparados);
}

#endif //INC_03_CLASIF_MARKET_DATA_FILE_UTIL_H
