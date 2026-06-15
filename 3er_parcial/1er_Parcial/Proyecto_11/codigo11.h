#ifndef CODIGO11_H
#define CODIGO11_H
#include <iostream>
#include <fstream>
using namespace std;

class Promedio {
public:
    int suma(int* v, int n);
    float promedio(int* v, int n);
    float media(int* v, int n);
    int maximo(int* v, int n);
    int minimo(int* v, int n);
    void guardarSalidas(int* v, int n, int s, float p, float m, int mx, int mn);
};
#endif
