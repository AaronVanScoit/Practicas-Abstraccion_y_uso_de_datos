#include "codigo9.h"
#include <iostream>
using namespace std;

ColaPtr::ColaPtr() {
    frente = nullptr;
    final = nullptr;
    tamanio = 0;
}

ColaPtr::~ColaPtr() {
    while (!estaVacia()) dequeue();
}

bool ColaPtr::estaVacia() {
    return frente == nullptr;
}

void ColaPtr::enqueue(int valor) {
    NodoCola* nuevo = new NodoCola();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (estaVacia()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }
    tamanio++;
    cout << "Se inserto: " << valor << endl;
}

int ColaPtr::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    NodoCola* temp = frente;
    int valor = temp->dato;
    frente = frente->siguiente;
    if (frente == nullptr) final = nullptr;
    delete temp;
    tamanio--;
    return valor;
}

int ColaPtr::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    return frente->dato;
}

void ColaPtr::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    NodoCola* actual = frente;
    cout << "Cola (frente -> final): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
