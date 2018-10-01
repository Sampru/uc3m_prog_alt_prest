#include <iostream>
#include <random>
#include <chrono>
#include "lib/matriz.h"

void rellenarMatriz(matriz &m);

const int DIMENSION = 100;
const int LEAF_SIZE= 750;


int main() {
    using namespace std;
    auto start = chrono::high_resolution_clock::now();
    matriz A{DIMENSION, DIMENSION},
           B{DIMENSION, DIMENSION},
           C{DIMENSION, DIMENSION},
           D{};

    rellenarMatriz(A);
    rellenarMatriz(B);
    rellenarMatriz(C);

    auto calc_start = chrono::high_resolution_clock::now();
    D = A * B + C;
    auto calc_end = chrono::high_resolution_clock::now();

    /*
     * cout << A << endl;
     * cout << "*" << endl;
     * cout << B << endl;
     * cout << "+" << endl;
     * cout << C << endl;
     * cout << "=" << endl;
     * cout << D << endl;
     */
    chrono::duration<double> calc_diff = calc_end - calc_start;
    cout << "Calculation time: " << calc_diff.count() << "s" << endl;

    chrono::duration<double> diff = chrono::high_resolution_clock::now() - start;
    cout << "Total time: " << diff.count() << "s" << endl;

    return 0;
}

void rellenarMatriz(matriz &m) {
    using namespace std;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> rand (2.5, 5.0);
    for (int i = 0; i < m.filas() * m.columnas(); i++) {
            m(i) = rand(gen);
    }
}