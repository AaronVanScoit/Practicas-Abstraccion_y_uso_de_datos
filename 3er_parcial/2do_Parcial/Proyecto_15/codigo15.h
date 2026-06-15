#ifndef CODIGO15_H
#define CODIGO15_H
#include <iostream>
#include <fstream>
using namespace std;
struct NodoFila{int dato;NodoFila*ant;NodoFila*sig;};
class FilaPtr {
private:
    NodoFila*frente;NodoFila*fin;
public:
    FilaPtr();~FilaPtr();
    void insertarFrente(int val);void insertarFinal(int val);
    int eliminarFrente();int eliminarFinal();
    int verFrente();int verFinal();
    void mostrar();bool estaVacia();void guardarSalidas();
};
#endif
