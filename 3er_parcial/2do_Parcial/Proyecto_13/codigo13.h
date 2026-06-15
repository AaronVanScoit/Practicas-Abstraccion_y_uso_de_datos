#ifndef CODIGO13_H
#define CODIGO13_H
#include <iostream>
#include <fstream>
#define MAX 10
using namespace std;
class Fila {
private:
    int datos[MAX]; int frente, fin, tam;
public:
    Fila();
    void insertarFrente(int val); void insertarFinal(int val);
    int eliminarFrente(); int eliminarFinal();
    int verFrente(); int verFinal();
    void mostrar(); bool estaVacia(); bool estaLlena();
    void guardarSalidas();
};
#endif
