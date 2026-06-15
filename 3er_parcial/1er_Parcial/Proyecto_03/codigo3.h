#ifndef CODIGO3_H
#define CODIGO3_H

#include <iostream>
#include <fstream>
using namespace std;
class Calculadora {
public:
    int suma(int a, int b);
    int resta(int a, int b);
    int multiplicacion(int a, int b);
    float division(int a, int b);
    void guardarSalidas(int op, int a, int b, float resultado);
};
#endif
