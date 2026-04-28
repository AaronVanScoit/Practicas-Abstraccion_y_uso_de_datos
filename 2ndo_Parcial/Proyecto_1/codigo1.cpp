#include "codigo1.h"
#include <iostream>
using namespace std;

Pila::Pila() {
    tope = -1;
}

bool Pila::estaVacia() {
    return tope == -1;
}

bool Pila::estaLlena() {
    return tope == MAX - 1;
}

void Pila::push(int valor) {
    if (estaLlena()) {
        cout << "Error: La pila esta llena." << endl;
        return;
    }
    datos[++tope] = valor;
    cout << "Se inserto: " << valor << endl;
}

int Pila::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    return datos[tope--];
}

int Pila::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    return datos[tope];
}

void Pila::mostrar() {
    if (estaVacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    cout << "Pila (tope -> fondo): ";
    for (int i = tope; i >= 0; i--) {
        cout << datos[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}
