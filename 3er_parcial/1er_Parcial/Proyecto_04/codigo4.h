#ifndef CODIGO4_H
#define CODIGO4_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Calculadora {
public:
    int suma();
    int suma(int a, int b);
    int suma(int a, int b, int c);
    int resta();
    int resta(int a, int b);
    int resta(int a, int b, int c);
    int multiplicacion();
    int multiplicacion(int a, int b);
    int multiplicacion(int a, int b, int c);
    float division();
    float division(int a, int b);
    float division(int a, int b, int c);
    void guardarSalidas(string operacion, string params, float resultado);
};
#endif
