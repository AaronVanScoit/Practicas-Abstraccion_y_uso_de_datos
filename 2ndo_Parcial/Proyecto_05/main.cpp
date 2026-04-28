#include <iostream>
#include "codigo5.h"
using namespace std;

int main() {
    PilaLib pila;
    int opcion, valor;

    do {
        cout << "\n=== PILA CON LIBRERIA STL (int) ===" << endl;
        cout << "1. Push (insertar)" << endl;
        cout << "2. Pop (extraer)" << endl;
        cout << "3. Peek (ver tope)" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                pila.push(valor);
                break;
            case 2:
                valor = pila.pop();
                if (valor != -1)
                    cout << "Se extrajo: " << valor << endl;
                break;
            case 3:
                valor = pila.peek();
                if (valor != -1)
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
