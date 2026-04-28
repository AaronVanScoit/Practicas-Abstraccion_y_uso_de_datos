#include <iostream>
#include "codigo14.h"
using namespace std;

int main() {
    FilaStr fila;
    int opcion;
    string valor;

    do {
        cout << "\n=== FILA/DEQUE CON ARREGLOS (string) ===" << endl;
        cout << "1. Insertar al frente" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Eliminar del frente" << endl;
        cout << "4. Eliminar del final" << endl;
        cout << "5. Ver frente" << endl;
        cout << "6. Ver final" << endl;
        cout << "7. Mostrar fila" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Texto: "; cin >> valor;
                fila.insertarFrente(valor);
                break;
            case 2:
                cout << "Texto: "; cin >> valor;
                fila.insertarFinal(valor);
                break;
            case 3:
                valor = fila.eliminarFrente();
                if (!valor.empty()) cout << "Eliminado del frente: " << valor << endl;
                break;
            case 4:
                valor = fila.eliminarFinal();
                if (!valor.empty()) cout << "Eliminado del final: " << valor << endl;
                break;
            case 5:
                valor = fila.verFrente();
                if (!valor.empty()) cout << "Frente: " << valor << endl;
                break;
            case 6:
                valor = fila.verFinal();
                if (!valor.empty()) cout << "Final: " << valor << endl;
                break;
            case 7:
                fila.mostrar();
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
