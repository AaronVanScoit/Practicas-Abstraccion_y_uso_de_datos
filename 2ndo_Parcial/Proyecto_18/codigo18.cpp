#include "codigo18.h"
#include <iostream>
using namespace std;

bool FilaLibStr::estaVacia() {
    return fila.empty();
}

void FilaLibStr::insertarFrente(string valor) {
    fila.push_front(valor);
    cout << "Insertado al frente: " << valor << endl;
}

void FilaLibStr::insertarFinal(string valor) {
    fila.push_back(valor);
    cout << "Insertado al final: " << valor << endl;
}

string FilaLibStr::eliminarFrente() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    string valor = fila.front();
    fila.pop_front();
    return valor;
}

string FilaLibStr::eliminarFinal() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    string valor = fila.back();
    fila.pop_back();
    return valor;
}

string FilaLibStr::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return fila.front();
}

string FilaLibStr::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return fila.back();
}

void FilaLibStr::mostrar() {
    if (estaVacia()) { cout << "La fila esta vacia." << endl; return; }
    cout << "Fila (frente -> final): ";
    for (int i = 0; i < (int)fila.size(); i++) {
        cout << fila[i];
        if (i < (int)fila.size() - 1) cout << " -> ";
    }
    cout << endl;
}
