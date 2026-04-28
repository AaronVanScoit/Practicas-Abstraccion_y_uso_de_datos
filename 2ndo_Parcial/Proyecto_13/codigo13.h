#ifndef CODIGO13_H
#define CODIGO13_H

#define MAX 100

// Fila = Deque (Double Ended Queue): inserta y elimina por ambos extremos
class Fila {
private:
    int datos[MAX];
    int frente;
    int final;
    int tamanio;
public:
    Fila();
    bool estaVacia();
    bool estaLlena();
    void insertarFrente(int valor);
    void insertarFinal(int valor);
    int eliminarFrente();
    int eliminarFinal();
    int verFrente();
    int verFinal();
    void mostrar();
};

#endif
