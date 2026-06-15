#ifndef CODIGO7_H
#define CODIGO7_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Auto {
    float precio;
    int anio;
};
class Persona {
public:
    string nombre, ap, am, genero;
    int edad;
    Persona();
    ~Persona();
    void mostrar();
    void guardarSalidas(Auto carro);
};
#endif
