//
// Created by sampru on 31/12/18.
//

#include "file_util.h"

void fut::read(const std::string &nombre, std::map<std::string, std::map<time_t, std::vector<Precio>>> &precios) {
    using namespace std;
    string linea;

    ifstream fichero{nombre, ios::in};

    if (fichero.is_open()) {
        while (getline(fichero, linea)) {
            Precio precio{linea};
            precios[precio.instrumento][precio.tt_tiempo].push_back(precio);
        }
    }
    fichero.close();
}

void fut::write(std::string nombre, std::map<std::string, std::map<time_t, Precio>> preciosSeparados) {
    using namespace std;
    string linea, txt;

    for (pair<string, map<time_t , Precio>> lista : preciosSeparados) {
        txt = nombre;
        txt.append(lista.first);
        txt.append(".txt");

        cout << "Generando " << txt << endl;

        ofstream fichero{txt, ios::out};

        for (pair<int, Precio> precio : lista.second)
            fichero << precio.second;

        fichero.close();
    }

}