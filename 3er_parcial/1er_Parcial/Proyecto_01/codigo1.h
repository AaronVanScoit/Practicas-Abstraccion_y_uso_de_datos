#ifndef CODIGO1_H
#define CODIGO1_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Saludo {
public:
    string nombre;
    Saludo();
    ~Saludo();
    void Hola();
    void guardarSalidas(const string& nombre);
};

#endif
