#include "codigo10.h"
#include <iostream>
using namespace std;

ColaPtrStr::ColaPtrStr() {
    frente = nullptr;
    final = nullptr;
}

ColaPtrStr::~ColaPtrStr() {
    while (!estaVacia()) dequeue();
}

bool ColaPtrStr::estaVacia() {
    return frente == nullptr;
}

void ColaPtrStr::enqueue(string valor) {
    NodoColaStr* nuevo = new NodoColaStr();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (estaVacia()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    cout << "Se inserto: " << valor << endl;
}

string ColaPtrStr::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    NodoColaStr* temp = frente;
    string valor = temp->dato;
    frente = frente->siguiente;
    if (frente == nullptr) final = nullptr;
    delete temp;
    return valor;
}

string ColaPtrStr::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    return frente->dato;
}

void ColaPtrStr::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    NodoColaStr* actual = frente;
    cout << "Cola (frente -> final): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
