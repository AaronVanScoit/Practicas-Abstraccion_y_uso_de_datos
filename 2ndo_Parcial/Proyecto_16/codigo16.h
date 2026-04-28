#ifndef CODIGO16_H
#define CODIGO16_H

#include <string>

struct NodoDequeStr {
    std::string dato;
    NodoDequeStr* anterior;
    NodoDequeStr* siguiente;
};

class FilaPtrStr {
private:
    NodoDequeStr* frente;
    NodoDequeStr* final;
public:
    FilaPtrStr();
    ~FilaPtrStr();
    bool estaVacia();
    void insertarFrente(std::string valor);
    void insertarFinal(std::string valor);
    std::string eliminarFrente();
    std::string eliminarFinal();
    std::string verFrente();
    std::string verFinal();
    void mostrar();
};

#endif
