#ifndef CODIGO20_H
#define CODIGO20_H
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
class Ordenamiento {
public:
    int n; int datos[MAX];
    void llenarArreglo(); void mostrarArreglo();
    void merge(int izq, int mid, int der);
    void mergeSort(int izq, int der);
    void guardarSalidas();
};
#endif
