#include "codigo11.h"
#include <iostream>
#include <queue>
using namespace std;

bool ColaLib::estaVacia() {
    return cola.empty();
}

void ColaLib::enqueue(int valor) {
    cola.push(valor);
    cout << "Se inserto: " << valor << endl;
}

int ColaLib::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    int valor = cola.front();
    cola.pop();
    return valor;
}

int ColaLib::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    return cola.front();
}

void ColaLib::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    queue<int> copia = cola;
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
