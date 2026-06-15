#ifndef CODIGO6_H
#define CODIGO6_H

#include <iostream>
#include <fstream>
using namespace std;
class Calculadora {
public:
    virtual int suma(int a, int b);
    virtual int resta(int a, int b);
    virtual int multiplicacion(int a, int b);
    virtual float division(int a, int b);
};
class CalculadoraNueva : public Calculadora {
public:
    int multiplicacion(int a, int b) override;
    float division(int a, int b) override;
    void guardarSalidas(string op, int a, int b, float res);
};
#endif
