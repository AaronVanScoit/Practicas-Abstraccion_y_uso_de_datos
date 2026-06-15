#ifndef CODIGO16_H
#define CODIGO16_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct NodoFilaStr{string dato;NodoFilaStr*ant;NodoFilaStr*sig;};
class FilaPtrStr {
private:
    NodoFilaStr*frente;NodoFilaStr*fin;
public:
    FilaPtrStr();~FilaPtrStr();
    void insertarFrente(string val);void insertarFinal(string val);
    string eliminarFrente();string eliminarFinal();
    string verFrente();string verFinal();
    void mostrar();bool estaVacia();void guardarSalidas();
};
#endif
