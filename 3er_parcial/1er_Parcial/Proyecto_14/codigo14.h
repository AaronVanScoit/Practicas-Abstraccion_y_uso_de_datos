#ifndef CODIGO14_H
#define CODIGO14_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Persona {
public:
    string nombre,ap,am,genero;
    int edad;
};
class Auto {
public:
    float precio;
    int anio;
};
class Registro {
public:
    void capturarPersonas(Persona personas[], int n);
    void capturarAutos(Auto autos[], int n);
    void mostrarPersonas(Persona personas[], int n);
    void mostrarAutos(Auto autos[], int n);
    void guardarSalidas(Persona personas[], Auto autos[], int n);
};
#endif
class ListaPersonas {
public:
    void capturar(Persona* p, int n);
    void mostrar(Persona* p, int n);
};
