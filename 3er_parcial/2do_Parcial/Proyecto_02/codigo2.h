#ifndef CODIGO2_H
#define CODIGO2_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class PilaString {
private:
    string datos[MAX];
    int tope;
public:
    PilaString();
    void push(string val);
    string pop();
    string peek();
    void mostrar();
    bool estaLlena();
    bool estaVacia();
    void guardarSalidas();
};
#endif
