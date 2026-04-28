#include <iostream>
#include "codigo12.h"
using namespace std;

int main() {
    ColaLibStr cola;
    int opcion;
    string valor;

    do {
        cout << "\n=== COLA CON LIBRERIA STL (string) ===" << endl;
        cout << "1. Enqueue (insertar)" << endl;
        cout << "2. Dequeue (extraer)" << endl;
        cout << "3. Ver frente" << endl;
        cout << "4. Mostrar cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Texto a insertar: ";
                cin >> valor;
                cola.enqueue(valor);
                break;
            case 2:
                valor = cola.dequeue();
                if (!valor.empty())
                    cout << "Se extrajo: " << valor << endl;
                break;
            case 3:
                valor = cola.verFrente();
                if (!valor.empty())
                    cout << "Frente: " << valor << endl;
                break;
            case 4:
                cola.mostrar();
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
