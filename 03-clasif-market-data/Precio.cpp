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

    anyo = stoi(datos.at(index).substr(0, 4), nullptr);
    mes = stoi(datos.at(index).substr(5, 2), nullptr);
    dia = stoi(datos.at(index).substr(8, 2), nullptr);

    hora = stoi(datos.at(++index).substr(0, 2), nullptr);
    minuto = stoi(datos.at(index).substr(3, 2), nullptr);
    int segundo = stoi(datos.at(index).substr(6, 2), nullptr);
    nano = stol(datos.at(index).substr(9, 6), nullptr);
    nano += (segundo * 1000000);

    while (instrumento.back() != '"') instrumento.append(datos.at(++index));
    instrumento.erase(remove_if(instrumento.begin(), instrumento.end(),
                                [](auto const &c) -> bool { return !isalpha(c); }), instrumento.end());
    transform(instrumento.begin(), instrumento.end(), instrumento.begin(), ::tolower);

    precio = stod(datos.back());
}

std::ostream &operator<<(std::ostream &os, Precio &precio) {
    char out[22];

    sprintf(out, "%02d-%02d-%02d %02d:%02d %.2f", precio.dia, precio.mes, precio.anyo, precio.hora, precio.minuto, precio.precio);

    os << out << std::endl;

    return os;
}