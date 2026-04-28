#include <iostream>
#include "codigo9.h"
using namespace std;

int main() {
    ColaPtr cola;
    int opcion, valor;

    do {
        cout << "\n=== COLA CON PUNTEROS (int) ===" << endl;
        cout << "1. Enqueue (insertar)" << endl;
        cout << "2. Dequeue (extraer)" << endl;
        cout << "3. Ver frente" << endl;
        cout << "4. Mostrar cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Valor a insertar: ";
                cin >> valor;
                cola.enqueue(valor);
                break;
            case 2:
                valor = cola.dequeue();
                if (valor != -1)
                    cout << "Se extrajo: " << valor << endl;
                break;
            case 3:
                valor = cola.verFrente();
                if (valor != -1)
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
