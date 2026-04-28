#include "codigo15.h"
#include <iostream>
using namespace std;

FilaPtr::FilaPtr() {
    frente = nullptr;
    final = nullptr;
    tamanio = 0;
}

FilaPtr::~FilaPtr() {
    while (!estaVacia()) eliminarFrente();
}

bool FilaPtr::estaVacia() {
    return frente == nullptr;
}

void FilaPtr::insertarFrente(int valor) {
    NodoDeque* nuevo = new NodoDeque();
    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = frente;
    if (estaVacia()) { frente = nuevo; final = nuevo; }
    else { frente->anterior = nuevo; frente = nuevo; }
    tamanio++;
    cout << "Insertado al frente: " << valor << endl;
}

void FilaPtr::insertarFinal(int valor) {
    NodoDeque* nuevo = new NodoDeque();
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    nuevo->anterior = final;
    if (estaVacia()) { frente = nuevo; final = nuevo; }
    else { final->siguiente = nuevo; final = nuevo; }
    tamanio++;
    cout << "Insertado al final: " << valor << endl;
}

int FilaPtr::eliminarFrente() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return -1; }
    NodoDeque* temp = frente;
    int valor = temp->dato;
    frente = frente->siguiente;
    if (frente) frente->anterior = nullptr;
    else final = nullptr;
    delete temp;
    tamanio--;
    return valor;
}

int FilaPtr::eliminarFinal() {
    if (estaVacia()) { cout << "Error: La fila esta vacia." << endl; return -1; }
    NodoDeque* temp = final;
    int valor = temp->dato;
    final = final->anterior;
    if (final) final->siguiente = nullptr;
    else frente = nullptr;
    delete temp;
    tamanio--;
    return valor;
}

int FilaPtr::verFrente() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return frente->dato;
}

int FilaPtr::verFinal() {
    if (estaVacia()) { cout << "Fila vacia." << endl; return -1; }
    return final->dato;
}

void FilaPtr::mostrar() {
    if (estaVacia()) { cout << "La fila esta vacia." << endl; return; }
    NodoDeque* actual = frente;
    cout << "Fila (frente -> final): ";
    while (actual != nullptr) {
        cout << actual->dato;
        if (actual->siguiente != nullptr) cout << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}
