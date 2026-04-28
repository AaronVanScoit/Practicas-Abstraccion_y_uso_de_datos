#include "codigo2.h"
#include <iostream>
using namespace std;

PilaString::PilaString() {
    tope = -1;
}

bool PilaString::estaVacia() {
    return tope == -1;
}

bool PilaString::estaLlena() {
    return tope == MAX - 1;
}

void PilaString::push(string valor) {
    if (estaLlena()) {
        cout << "Error: La pila esta llena." << endl;
        return;
    }
    datos[++tope] = valor;
    cout << "Se inserto: " << valor << endl;
}

string PilaString::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    return datos[tope--];
}

string PilaString::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    return datos[tope];
}

void PilaString::mostrar() {
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
