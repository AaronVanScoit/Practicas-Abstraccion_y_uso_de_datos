#include "codigo5.h"
#include <iostream>
#include <stack>
using namespace std;

bool PilaLib::estaVacia() {
    return pila.empty();
}

void PilaLib::push(int valor) {
    pila.push(valor);
    cout << "Se inserto: " << valor << endl;
}

int PilaLib::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    int valor = pila.top();
    pila.pop();
    return valor;
}

int PilaLib::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return -1;
    }
    return pila.top();
}

void PilaLib::mostrar() {
    if (estaVacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    stack<int> copia = pila;
    cout << "Pila (tope -> fondo): ";
    bool primero = true;
    while (!copia.empty()) {
        if (!primero) cout << " -> ";
        cout << copia.top();
        copia.pop();
        primero = false;
    }
    cout << endl;
}
