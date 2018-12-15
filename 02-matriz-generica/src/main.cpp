#include <iostream>
#include <chrono>
#include <cstring>
#include <complex.h>

#include "../lib/Racional.h"
#include "../lib/Matriz.h"

int main(int argc, char *argv[]) {
    using namespace std;
    auto start = chrono::high_resolution_clock::now();

    int DIMENSION = 10;
    bool PRINT = false;
    /* Parse arguments */
    if (argc > 1) {
        DIMENSION = stoi(argv[1]);
    }
    if (argc > 2) {
        PRINT = (strcmp(argv[2], "-p") == 0);
    }

    Matriz<Racional<int>> A{DIMENSION, DIMENSION};
    Matriz<Racional<int>> B{DIMENSION, DIMENSION};
    Matriz<Racional<int>> C{DIMENSION, DIMENSION};
    Matriz<Racional<int>> D{};

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

    auto diagonal = D.diagonal();
    cout << "Diagonal: " << diagonal << endl;

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Total time: " << diff.count() << "s" << endl;

    return 0;
}
