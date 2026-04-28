#ifndef CODIGO3_H
#define CODIGO3_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class PilaPtr {
private:
    Nodo* tope;
    int tamanio;
public:
    PilaPtr();
    ~PilaPtr();
    bool estaVacia();
    void push(int valor);
    int pop();
    int peek();
    void mostrar();
};

#endif
