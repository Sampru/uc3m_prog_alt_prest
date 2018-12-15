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

    DIMENSION = 5;
    MODE = false;
    PRINT = true;
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

    Matriz<long int> A{DIMENSION, DIMENSION};
    Matriz<long int> B{DIMENSION, DIMENSION};
    Matriz<long int> C{DIMENSION, DIMENSION};
    Matriz<long int> D{};

    A.fill_random(2.5, 5.0);
    B.fill_random(2.5, 5.0);
    C.fill_random(2.5, 5.0);

    auto calc_start = chrono::high_resolution_clock::now();
    D = A * B + C;
    auto calc_end = chrono::high_resolution_clock::now();

    chrono::duration<double> calc_diff = calc_end - calc_start;

    if (PRINT) {
        cout << A << endl;
        cout << "*" << endl << endl;
        cout << B << endl;
        cout << "+" << endl << endl;
        cout << C << endl;
        cout << "=" << endl << endl;
        cout << D << endl;
    }

    cout << "Calculation time: " << calc_diff.count() << "s" << endl;

    cout << "Diagonal: " << D.diagonal() << endl;

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Total time: " << diff.count() << "s" << endl;

    return 0;
}