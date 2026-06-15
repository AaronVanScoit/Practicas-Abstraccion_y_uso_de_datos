#ifndef CODIGO19_H
#define CODIGO19_H
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
class Ordenamiento {
public:
    int n;
    int datos[MAX];
    void llenarArreglo();
    void mostrarArreglo();
    void bubbleSort();
    void guardarSalidas();
};
#endif
