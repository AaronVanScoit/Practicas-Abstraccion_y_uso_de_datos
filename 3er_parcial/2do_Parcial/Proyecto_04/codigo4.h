#ifndef CODIGO4_H
#define CODIGO4_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct NodoPilaStr { string dato; NodoPilaStr* siguiente; };
class PilaPtrStr {
private:
    NodoPilaStr* tope;
public:
    PilaPtrStr(); ~PilaPtrStr();
    void push(string val); string pop(); string peek();
    void mostrar(); bool estaVacia(); void guardarSalidas();
};
#endif
