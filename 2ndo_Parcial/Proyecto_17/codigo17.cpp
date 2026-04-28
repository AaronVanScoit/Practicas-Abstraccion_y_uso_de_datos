#include "codigo17.h"
#include <iostream>
using namespace std;

bool FilaLib::estaVacia() {
    return fila.empty();
}

void FilaLib::insertarFrente(int valor) {
    fila.push_front(valor);
    cout << "Insertado al frente: " << valor << endl;
}

void FilaLib::insertarFinal(int valor) {
    fila.push_back(valor);
    cout << "Insertado al final: " << valor << endl;
}

int FilaLib::eliminarFrente() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return -1; }
    int valor = fila.front();
    fila.pop_front();
    return valor;
}

int FilaLib::eliminarFinal() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return -1; }
    int valor = fila.back();
    fila.pop_back();
    return valor;
}

int FilaLib::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return fila.front();
}

int FilaLib::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return fila.back();
}

void FilaLib::mostrar() {
    if (estaVacia()) { cout << "La fila esta vacia." << endl; return; }
    cout << "Fila (frente -> final): ";
    for (int i = 0; i < (int)fila.size(); i++) {
        cout << fila[i];
        if (i < (int)fila.size() - 1) cout << " -> ";
    }
    cout << endl;
}
