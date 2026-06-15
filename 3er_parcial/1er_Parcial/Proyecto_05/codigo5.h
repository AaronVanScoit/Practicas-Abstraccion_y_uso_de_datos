#ifndef CODIGO5_H
#define CODIGO5_H

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
class Calculadora {
public:
    int suma(int a, int b);
    int resta(int a, int b);
    int multiplicacion(int a, int b);
    float division(int a, int b);
};
class CalculadoraAvanzada : public Calculadora {
public:
    int potencia(int base, int exp);
    int modulo(int a, int b);
    void guardarSalidas(string op, int a, int b, float res);
};
#endif
