#ifndef CODIGO9_H
#define CODIGO9_H

struct NodoCola {
    int dato;
    NodoCola* siguiente;
};

class ColaPtr {
private:
    NodoCola* frente;
    NodoCola* final;
    int tamanio;
public:
    ColaPtr();
    ~ColaPtr();
    bool estaVacia();
    void enqueue(int valor);
    int dequeue();
    int verFrente();
    void mostrar();
};

#endif
