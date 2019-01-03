
#include "Precio.h"
#include "file_util.h"

int main() {
    using namespace std;
    map<int, Precio> precios;
    map<string, map<int, Precio>> preciosSeparados;

    fut::read("./resources/default_data.txt", precios);

    for (pair<int, Precio> precio : precios)
        preciosSeparados[precio.second.instrumento][precio.first] = precio.second;

    fut::write("./out/", preciosSeparados);
}