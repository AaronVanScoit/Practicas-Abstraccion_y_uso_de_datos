#ifndef CODIGO14_H
#define CODIGO14_H

#include <string>
#define MAX 100

class FilaStr {
private:
    std::string datos[MAX];
    int frente;
    int final;
    int tamanio;
public:
    FilaStr();
    bool estaVacia();
    bool estaLlena();
    void insertarFrente(std::string valor);
    void insertarFinal(std::string valor);
    std::string eliminarFrente();
    std::string eliminarFinal();
    std::string verFrente();
    std::string verFinal();
    void mostrar();
};

#endif
