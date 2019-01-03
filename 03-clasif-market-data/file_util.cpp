//
// Created by sampru on 31/12/18.
//

#include "file_util.h"

void fut::read(std::string nombre, std::map<int, Precio> &precios) {
    using namespace std;
    string linea;
    ifstream fichero;
    int id{0};

    fichero.open(nombre, ios::in);

    if (fichero.is_open()) {
        while (getline(fichero, linea)) {
            precios[id++] = Precio{linea};
        }
    }
    fichero.close();
}

void fut::write(std::string nombre, std::map<std::string, std::map<int, Precio>> preciosSeparados) {
    using namespace std;
    string linea, txt;
    ofstream fichero;

    for (pair<string, map<int, Precio>> lista : preciosSeparados) {
        txt = nombre;
        txt.append(lista.first);
        txt.append(".txt");

        fichero.open(txt, ios::out);

        for (pair<int, Precio> precio : lista.second)
            fichero << precio.second;

        fichero.close();
    }

}