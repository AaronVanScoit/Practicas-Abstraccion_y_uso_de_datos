#ifndef CODIGO15_H
#define CODIGO15_H

struct NodoDeque {
    int dato;
    NodoDeque* anterior;
    NodoDeque* siguiente;
};

class FilaPtr {
private:
    NodoDeque* frente;
    NodoDeque* final;
    int tamanio;
public:
    FilaPtr();
    ~FilaPtr();
    bool estaVacia();
    void insertarFrente(int valor);
    void insertarFinal(int valor);
    int eliminarFrente();
    int eliminarFinal();
    int verFrente();
    int verFinal();
    void mostrar();
};

#endif
