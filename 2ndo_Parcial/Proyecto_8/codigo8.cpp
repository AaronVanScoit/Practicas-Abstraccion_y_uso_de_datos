#include "codigo8.h"
#include <iostream>
using namespace std;

ColaStr::ColaStr() {
    frente = 0;
    final = -1;
    tamanio = 0;
}

bool ColaStr::estaVacia() {
    return tamanio == 0;
}

bool ColaStr::estaLlena() {
    return tamanio == MAX;
}

void ColaStr::enqueue(string valor) {
    if (estaLlena()) {
        cout << "Error: La cola esta llena." << endl;
        return;
    }
    final = (final + 1) % MAX;
    datos[final] = valor;
    tamanio++;
    cout << "Se inserto: " << valor << endl;
}

string ColaStr::dequeue() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    string valor = datos[frente];
    frente = (frente + 1) % MAX;
    tamanio--;
    return valor;
}

string ColaStr::verFrente() {
    if (estaVacia()) {
        cout << "Error: La cola esta vacia." << endl;
        return "";
    }
    return datos[frente];
}

void ColaStr::mostrar() {
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
