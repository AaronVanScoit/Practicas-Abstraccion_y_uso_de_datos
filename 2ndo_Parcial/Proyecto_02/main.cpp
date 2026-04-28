#include <iostream>
#include "codigo2.h"
using namespace std;

int main() {
    PilaString pila;
    int opcion;
    string valor;

    do {
        cout << "\n=== PILA CON ARREGLOS (string) ===" << endl;
        cout << "1. Push (insertar)" << endl;
        cout << "2. Pop (extraer)" << endl;
        cout << "3. Peek (ver tope)" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Texto a insertar: ";
                cin >> valor;
                pila.push(valor);
                break;
            case 2:
                valor = pila.pop();
                if (!valor.empty())
                    cout << "Se extrajo: " << valor << endl;
                break;
            case 3:
                valor = pila.peek();
                if (!valor.empty())
                    cout << "Tope: " << valor << endl;
                break;
            case 4:
                pila.mostrar();
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
