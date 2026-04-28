#include "codigo12.h"
#include <iostream>
#include <queue>
using namespace std;

bool ColaLibStr::estaVacia() {
    return cola.empty();
}

void ColaLibStr::enqueue(string valor) {
    cola.push(valor);
    cout << "Se inserto: " << valor << endl;
}

string ColaLibStr::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    string valor = cola.front();
    cola.pop();
    return valor;
}

string ColaLibStr::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    return cola.front();
}

void ColaLibStr::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    queue<string> copia = cola;
    cout << "Cola (frente -> final): ";
    bool primero = true;
    while (!copia.empty()) {
        if (!primero) cout << " -> ";
        cout << copia.front();
        copia.pop();
        primero = false;
    }
    cout << endl;
}
