#ifndef CODIGO7_H
#define CODIGO7_H
#include <iostream>
#include <fstream>
using namespace std;
#define MAX_C 10

class Cola {
private:
    int datos[MAX_C];
    int frente, final_, tam;
public:
    Cola():frente(0),final_(0),tam(0){}
    void enqueue(int val);
    int dequeue();
    int verFrente();
    void mostrar();
    bool estaVacia(){return tam==0;}
    bool estaLlena(){return tam==MAX_C;}
    void guardarSalida();
};
#endif
