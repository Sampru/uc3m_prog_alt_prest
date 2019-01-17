//
// Created by sampru on 31/12/18.
//

#include "Precio.h"

Precio::Precio(std::string input) {
    using namespace std;
    unsigned long index = 0;

    istringstream stream(input);
    vector<string> datos(istream_iterator<string>{stream},
                         istream_iterator<string>());

    string tiempoStr = datos.at(index);
    tiempoStr.append(" ");
    tiempoStr.append(datos.at(++index));
    strptime(tiempoStr.c_str(), "%Y-%m-%d %H:%M:%S", &tm_tiempo);

    int sec = tm_tiempo.tm_sec;
    tm_tiempo.tm_sec = 0;
    tt_tiempo = mktime(&tm_tiempo);
    tm_tiempo.tm_sec = sec;

    micro = stol(datos.at(index).substr(9, 6), nullptr);

    while (instrumento.back() != '"') instrumento.append(datos.at(++index));
    instrumento.erase(remove_if(instrumento.begin(), instrumento.end(),
                                [](auto const &c) -> bool { return !isalpha(c); }), instrumento.end());
    transform(instrumento.begin(), instrumento.end(), instrumento.begin(), ::tolower);

    precio = stod(datos.back());
}

Precio &Precio::operator=(const Precio &precio) {
    this->precio = precio.precio;
    this->instrumento = precio.instrumento;
    this->tt_tiempo = precio.tt_tiempo;
    this->tm_tiempo = precio.tm_tiempo;
    this->micro = 0l;
}

std::ostream &operator<<(std::ostream &os, Precio &precio) {
    char out[22];

    std::string year = std::to_string(precio.tm_tiempo.tm_year + 1900);
    sprintf(out, "%02d-%02d-%s %02d:%02d %.2f", precio.tm_tiempo.tm_mday, precio.tm_tiempo.tm_mon + 1,
            year.substr(year.length() - 2, 2).c_str(), precio.tm_tiempo.tm_hour, precio.tm_tiempo.tm_min,
            precio.precio);

    os << out << std::endl;

    return os;
}

void emparejarPrecios(std::map<int, Precio> precios,
                      std::map<std::string, std::map<time_t, std::vector<Precio>>> &preciosSeparados) {
    using namespace std;
    for (pair<int, Precio> precio : precios) {
        preciosSeparados[precio.second.instrumento][precio.second.tt_tiempo].push_back(precio.second);
    }
}

void agruparPrecios(std::map<std::string, std::map<time_t, std::vector<Precio>>> preciosSeparados,
                    std::map<std::string, std::map<time_t, Precio>> &preciosAgrupados) {
    using namespace std;

    for (pair<string, map<time_t, vector<Precio>>> precioMap : preciosSeparados) {
        vector<Precio> calculado{};
        calculado.reserve(precioMap.second.size());

        for (pair<time_t, vector<Precio>> precioVector : precioMap.second) {
            calculado.push_back(mediaRegresionLineal(precioVector.second));
        }

        for (const Precio &p : calculado) {
            preciosAgrupados[precioMap.first][p.tt_tiempo] = p;
        }
    }
}

Precio mediaRegresionLineal(std::vector<Precio> precios) {
    Precio ret{};

    if (precios.size() == 1) {
        ret = precios.at(0);
    } else {
        double x{0}, y{0}, xy{0}, xx{0}, n{0};
        for (Precio &precio : precios) {
            double micro = (precio.tm_tiempo.tm_sec * 1000000) + precio.micro;
            x += micro;
            y += precio.precio;
            xy += micro * precio.precio;
            xx += micro * micro;
            n++;
        }

        ret = precios.at(0);

        double m = lin::valorM(x, y, xy, xx, n);
        double y0 = lin::valorY0(x, y, m, n);
        ret.precio = lin::precioMedio(y0, m);
    }

    return ret;
}


