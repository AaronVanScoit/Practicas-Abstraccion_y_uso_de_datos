#include "codigo7.h"
#include <iostream>
using namespace std;

Cola::Cola() {
    frente = 0;
    final = -1;
    tamanio = 0;
}

bool Cola::estaVacia() {
    return tamanio == 0;
}

bool Cola::estaLlena() {
    return tamanio == MAX;
}

void Cola::enqueue(int valor) {
    if (estaLlena()) {
        cout << "Error: La cola esta llena." << endl;
        return;
    }
    final = (final + 1) % MAX;
    datos[final] = valor;
    tamanio++;
    cout << "Se inserto: " << valor << endl;
}

int Cola::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    int valor = datos[frente];
    frente = (frente + 1) % MAX;
    tamanio--;
    return valor;
}

int Cola::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return -1;
    }
    return datos[frente];
}

void Cola::mostrar() {
    if (estaVacia()) {
        cout << "La cola esta vacia." << endl;
        return;
    }
    cout << "Cola (frente -> final): ";
    for (int i = 0; i < tamanio; i++) {
        cout << datos[(frente + i) % MAX];
        if (i < tamanio - 1) cout << " -> ";
    }
    cout << endl;
}
