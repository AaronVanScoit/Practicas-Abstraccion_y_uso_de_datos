#ifndef CODIGO14_H
#define CODIGO14_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class FilaStr {
private:
    string datos[MAX]; int frente,fin,tam;
public:
    FilaStr();
    void insertarFrente(string val); void insertarFinal(string val);
    string eliminarFrente(); string eliminarFinal();
    string verFrente(); string verFinal();
    void mostrar(); bool estaVacia(); bool estaLlena();
    void guardarSalidas();
};
#endif
