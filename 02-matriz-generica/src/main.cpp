#include <iostream>
#include <chrono>
#include <cstring>
#include <complex.h>

#include "../lib/Matriz.h"
#include "../lib/Racional.h"

/* Globals */
int DIMENSION;
bool MODE;
bool PRINT;


int main(int argc, char *argv[]) {
    using namespace std;
    auto start = chrono::high_resolution_clock::now();

    DIMENSION = 100;
    MODE = false;
    PRINT = false;
    /* Parse arguments */
    if (argc > 1) {
        DIMENSION = stoi(argv[1]);
    }
    if (argc > 2) {
        MODE = (strcmp(argv[2], "-b") == 0);
    }
    if (argc > 3) {
        PRINT = (strcmp(argv[3], "-d") == 0);
    }

    Matriz<Racional<double>> A{DIMENSION, DIMENSION};
    Matriz<Racional<double>> B{DIMENSION, DIMENSION};
    Matriz<Racional<double>> C{DIMENSION, DIMENSION};
    Matriz<Racional<double>> D{};

    A.fill_random(2.5, 5.0);
    B.fill_random(2.5, 5.0);
    C.fill_random(2.5, 5.0);

    auto calc_start = chrono::high_resolution_clock::now();
    D = A * B + C;
    auto calc_end = chrono::high_resolution_clock::now();

    chrono::duration<double> calc_diff = calc_end - calc_start;

    if (PRINT) {
        cout << A << endl;
        cout << "*" << endl;
        cout << B << endl;
        cout << "+" << endl;
        cout << C << endl;
        cout << "=" << endl;
        cout << D << endl;
    }

    cout << "Calculation time: " << calc_diff.count() << "s" << endl;

    cout << "Diagonal: " << D.diagonal() << endl;

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Total time: " << diff.count() << "s" << endl;

    return 0;
}
