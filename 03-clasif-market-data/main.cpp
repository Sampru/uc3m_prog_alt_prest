
#include <chrono>
#include "Precio.h"
#include "file_util.h"

int main(int argc, char *argv[]) {
    using namespace std;
    auto tiempoInicio = chrono::high_resolution_clock::now();
    map<string, map<time_t, vector<Precio>>> preciosSeparados{};
    map<string, map<time_t, Precio>> preciosAgrupados{};
    string input{}, output{};
    string defaultInput = "res/default_data.txt";
    string defaultOutput = "out/";

    for (int i = 1; i < argc; i++) {
        switch (argv[i][1]) {
            case 'i':
                input = argv[++i];
                break;
            case 'o':
                output = argv[++i];
                break;
            default:
                cerr << "Opcion no soportada." << endl;
                return 0;
        }

    }

    if (input.empty()) input = defaultInput;
    if (output.empty()) output = defaultOutput;

    cout << "Fichero de entrada: " << input << endl;
    cout << "Directorio de salida: " << output << endl;

    fut::read(input, preciosSeparados);

    agruparPrecios(preciosSeparados, preciosAgrupados);

    fut::write(output, preciosAgrupados);

    auto tiempoFinal = chrono::high_resolution_clock::now();

    chrono::duration<double> tiempo = tiempoFinal - tiempoInicio;

    cout << "Tiempo total: " << tiempo.count() << "s" << endl;
}