#ifndef CODIGO3_H
#define CODIGO3_H
#include <iostream>
#include <fstream>
using namespace std;
struct NodoPila { int dato; NodoPila* siguiente; };
class PilaPtr {
private:
    NodoPila* tope;
public:
    PilaPtr();
    ~PilaPtr();
    void push(int val);
    int pop();
    int peek();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
