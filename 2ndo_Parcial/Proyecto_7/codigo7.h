#ifndef CODIGO7_H
#define CODIGO7_H

#define MAX 100

class Cola {
private:
    int datos[MAX];
    int frente;
    int final;
    int tamanio;
public:
    Cola();
    bool estaVacia();
    bool estaLlena();
    void enqueue(int valor);
    int dequeue();
    int verFrente();
    void mostrar();
};

#endif
