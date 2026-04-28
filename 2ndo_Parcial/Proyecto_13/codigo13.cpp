#include "codigo13.h"
#include <iostream>
using namespace std;

Fila::Fila() {
    frente = 0;
    final = -1;
    tamanio = 0;
}

bool Fila::estaVacia() {
    return tamanio == 0;
}

bool Fila::estaLlena() {
    return tamanio == MAX;
}

void Fila::insertarFrente(int valor) {
    if (estaLlena()) {
        cout << "Error: La fila esta llena." << endl;
        return;
    }
    frente = (frente - 1 + MAX) % MAX;
    datos[frente] = valor;
    tamanio++;
    cout << "Insertado al frente: " << valor << endl;
}

void Fila::insertarFinal(int valor) {
    if (estaLlena()) {
        cout << "Error: La fila esta llena." << endl;
        return;
    }
    final = (final + 1) % MAX;
    datos[final] = valor;
    tamanio++;
    cout << "Insertado al final: " << valor << endl;
}

int Fila::eliminarFrente() {
    if (estaVacia()) {
        cout << "Error: La fila esta vacia." << endl;
        return -1;
    }
    int valor = datos[frente];
    frente = (frente + 1) % MAX;
    tamanio--;
    return valor;
}

int Fila::eliminarFinal() {
    if (estaVacia()) {
        cout << "Error: La fila esta vacia." << endl;
        return -1;
    }
    int valor = datos[final];
    final = (final - 1 + MAX) % MAX;
    tamanio--;
    return valor;
}

int Fila::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return datos[frente];
}

int Fila::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return datos[final];
}

void Fila::mostrar() {
    if (estaVacia()) {
        cout << "La fila esta vacia." << endl;
        return;
    }
    cout << "Fila (frente -> final): ";
    for (int i = 0; i < tamanio; i++) {
        cout << datos[(frente + i) % MAX];
        if (i < tamanio - 1) cout << " -> ";
    }
    cout << endl;
}
