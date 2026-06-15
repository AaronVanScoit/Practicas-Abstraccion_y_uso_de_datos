#ifndef CODIGO21_H
#define CODIGO21_H
#include <iostream>
#include <fstream>
#define MAX 20
using namespace std;
class Ordenamiento {
public:
    int n; int datos[MAX];
    void llenarArreglo(); void mostrarArreglo();
    int particion(int izq, int der);
    void quickSort(int izq, int der);
    void guardarSalidas();
};
#endif
