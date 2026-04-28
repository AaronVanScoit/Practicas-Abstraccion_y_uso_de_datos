#ifndef CODIGO1_H
#define CODIGO1_H

#define MAX 100

class Pila {
private:
    int datos[MAX];
    int tope;
public:
    Pila();
    bool estaVacia();
    bool estaLlena();
    void push(int valor);
    int pop();
    int peek();
    void mostrar();
};

#endif
