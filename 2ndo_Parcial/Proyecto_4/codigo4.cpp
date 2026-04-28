#include "codigo4.h"
#include <iostream>
using namespace std;

PilaPtrStr::PilaPtrStr() {
    tope = nullptr;
}

PilaPtrStr::~PilaPtrStr() {
    while (!estaVacia()) pop();
}

bool PilaPtrStr::estaVacia() {
    return tope == nullptr;
}

void PilaPtrStr::push(string valor) {
    NodoStr* nuevo = new NodoStr();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    cout << "Se inserto: " << valor << endl;
}

string PilaPtrStr::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    NodoStr* temp = tope;
    string valor = temp->dato;
    tope = tope->siguiente;
    delete temp;
    return valor;
}

string PilaPtrStr::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    return tope->dato;
}

void PilaPtrStr::mostrar() {
    if (estaVacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    NodoStr* actual = tope;
    cout << "Pila (tope -> fondo): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
