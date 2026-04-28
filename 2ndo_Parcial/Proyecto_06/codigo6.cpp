#include "codigo6.h"
#include <iostream>
#include <stack>
using namespace std;

bool PilaLibStr::estaVacia() {
    return pila.empty();
}

void PilaLibStr::push(string valor) {
    pila.push(valor);
    cout << "Se inserto: " << valor << endl;
}

string PilaLibStr::pop() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    string valor = pila.top();
    pila.pop();
    return valor;
}

string PilaLibStr::peek() {
    if (estaVacia()) {
        cout << "Error: La pila esta vacia." << endl;
        return "";
    }
    return pila.top();
}

void PilaLibStr::mostrar() {
    if (estaVacia()) {
        cout << "La pila esta vacia." << endl;
        return;
    }
    stack<string> copia = pila;
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
