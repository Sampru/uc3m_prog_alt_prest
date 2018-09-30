#include <iostream>
#include <random>
#include <chrono>
#include "lib/matriz.h"

void rellenarMatriz(Matriz &m);

const int DIMENSION = 1000;


int main() {
    Matriz A{DIMENSION, DIMENSION},
           B{DIMENSION, DIMENSION},
           C{DIMENSION, DIMENSION},
           D{};

    rellenarMatriz(A);
    rellenarMatriz(B);
    rellenarMatriz(C);

    auto start = std::chrono::high_resolution_clock::now();
    D = A * B + C;
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << A << std::endl;
    std::cout << "*" << std::endl;
    std::cout << B << std::endl;
    std::cout << "+" << std::endl;
    std::cout << C << std::endl;
    std::cout << "=" << std::endl;
    std::cout << D << std::endl;
    std::chrono::duration<double> diff = end-start;
    std::cout << "Resolution time: " << diff.count() << "s" << std::endl;
    return 0;
}

void rellenarMatriz(Matriz &m) {
    using namespace std;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> rand (2.5, 5.0);
    for (int i = 0; i < m.filas() * m.columnas(); i++) {
            m(i) = rand(gen);
    }
}