#include "codigo3.h"
#include <iostream>
using namespace std;

PilaPtr::PilaPtr() {
    tope = nullptr;
    tamanio = 0;
}

PilaPtr::~PilaPtr() {
    while (!estaVacia()) pop();
}

bool PilaPtr::estaVacia() {
    return tope == nullptr;
}

void PilaPtr::push(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;
    tamanio++;
    cout << "Se inserto: " << valor << endl;
}

int PilaPtr::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    Nodo* temp = tope;
    int valor = temp->dato;
    tope = tope->siguiente;
    delete temp;
    tamanio--;
    return valor;
}

int PilaPtr::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    return tope->dato;
}

void PilaPtr::mostrar() {
    if (estaVacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    Nodo* actual = tope;
    cout << "Pila (tope -> fondo): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
