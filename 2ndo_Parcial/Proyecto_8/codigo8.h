#ifndef CODIGO8_H
#define CODIGO8_H

#include <string>
#define MAX 100

class ColaStr {
private:
    std::string datos[MAX];
    int frente;
    int final;
    int tamanio;
public:
    ColaStr();
    bool estaVacia();
    bool estaLlena();
    void enqueue(std::string valor);
    std::string dequeue();
    std::string verFrente();
    void mostrar();
};

#endif
