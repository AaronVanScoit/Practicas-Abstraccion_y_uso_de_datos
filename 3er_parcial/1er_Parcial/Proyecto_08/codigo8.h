#ifndef CODIGO8_H
#define CODIGO8_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Auto { float precio; int anio; };
class Persona {
public:
    string nombre, ap, am, genero;
    int edad;
    void mostrar();
    void guardarSalidas(Auto carro);
};
#endif
