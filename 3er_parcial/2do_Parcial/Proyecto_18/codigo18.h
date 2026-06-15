#ifndef CODIGO18_H
#define CODIGO18_H
#include <iostream>
#include <fstream>
#include <deque>
#include <string>
using namespace std;
class FilaLibStr {
private:
    deque<string> fila;
public:
    void insertarFrente(string val);void insertarFinal(string val);
    string eliminarFrente();string eliminarFinal();
    string verFrente();string verFinal();
    void mostrar();bool estaVacia();void guardarSalidas();
};
#endif
