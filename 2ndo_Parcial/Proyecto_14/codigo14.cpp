#include "codigo14.h"
#include <iostream>
using namespace std;

FilaStr::FilaStr() {
    frente = 0;
    final = -1;
    tamanio = 0;
}

bool FilaStr::estaVacia() { return tamanio == 0; }
bool FilaStr::estaLlena() { return tamanio == MAX; }

void FilaStr::insertarFrente(string valor) {
    if (estaLlena()) { cout << "Error: La fila esta llena." << endl; return; }
    frente = (frente - 1 + MAX) % MAX;
    datos[frente] = valor;
    tamanio++;
    cout << "Insertado al frente: " << valor << endl;
}

void FilaStr::insertarFinal(string valor) {
    if (estaLlena()) { cout << "Error: La fila esta llena." << endl; return; }
    final = (final + 1) % MAX;
    datos[final] = valor;
    tamanio++;
    cout << "Insertado al final: " << valor << endl;
}

string FilaStr::eliminarFrente() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    string valor = datos[frente];
    frente = (frente + 1) % MAX;
    tamanio--;
    return valor;
}

string FilaStr::eliminarFinal() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return ""; }
    string valor = datos[final];
    final = (final - 1 + MAX) % MAX;
    tamanio--;
    return valor;
}

string FilaStr::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return datos[frente];
}

string FilaStr::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return ""; }
    return datos[final];
}

void FilaStr::mostrar() {
    if (estaVacia()) { cout << "La fila esta vacia." << endl; return; }
    cout << "Fila (frente -> final): ";
    for (int i = 0; i < tamanio; i++) {
        cout << datos[(frente + i) % MAX];
        if (i < tamanio - 1) cout << " -> ";
    }
    cout << endl;
}
