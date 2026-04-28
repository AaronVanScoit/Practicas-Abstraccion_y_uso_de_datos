#ifndef CODIGO18_H
#define CODIGO18_H

#include <deque>
#include <string>

class FilaLibStr {
private:
    std::deque<std::string> fila;
public:
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
