#include "codigo16.h"
#include <iostream>
using namespace std;

FilaPtrStr::FilaPtrStr() { frente = nullptr; final = nullptr; }

FilaPtrStr::~FilaPtrStr() { while (!estaVacia()) eliminarFrente(); }

bool FilaPtrStr::estaVacia() { return frente == nullptr; }

void FilaPtrStr::insertarFrente(string valor) {
    NodoDequeStr* nuevo = new NodoDequeStr();
    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = frente;
    if (estaVacia()) { frente = nuevo; final = nuevo; }
    else { frente->anterior = nuevo; frente = nuevo; }
    cout << "Insertado al frente: " << valor << endl;
}

void FilaPtrStr::insertarFinal(string valor) {
    NodoDequeStr* nuevo = new NodoDequeStr();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    nuevo->anterior = final;
    if (estaVacia()) { frente = nuevo; final = nuevo; }
    else { final->siguiente = nuevo; final = nuevo; }
    cout << "Insertado al final: " << valor << endl;
}

string FilaPtrStr::eliminarFrente() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    NodoDequeStr* temp = frente;
    string valor = temp->dato;
    frente = frente->siguiente;
    if (frente) frente->anterior = nullptr;
    else final = nullptr;
    delete temp;
    return valor;
}

string FilaPtrStr::eliminarFinal() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    NodoDequeStr* temp = final;
    string valor = temp->dato;
    final = final->anterior;
    if (final) final->siguiente = nullptr;
    else frente = nullptr;
    delete temp;
    return valor;
}

string FilaPtrStr::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return frente->dato;
}

string FilaPtrStr::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return final->dato;
}

void FilaPtrStr::mostrar() {
    if (estaVacia()) { cout << "La fila esta vacia." << endl; return; }
    NodoDequeStr* actual = frente;
    cout << "Fila (frente -> final): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
