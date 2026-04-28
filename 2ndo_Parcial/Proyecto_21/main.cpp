#include <iostream>
#include "codigo21.h"
using namespace std;

#define MAX 100

int main() {
    int arr[MAX];
    int n = 0;
    int opcion;

    do {
        cout << "\n=== ORDENAMIENTO QUICK SORT ===" << endl;
        cout << "1. Ingresar arreglo" << endl;
        cout << "2. Mostrar arreglo actual" << endl;
        cout << "3. Ordenar (Quick Sort)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                llenarArreglo(arr, n);
                cout << "Arreglo ingresado." << endl;
                break;
            case 2:
                if (n == 0) { cout << "No hay arreglo ingresado." << endl; break; }
                cout << "Arreglo: ";
                mostrarArreglo(arr, n);
                break;
            case 3:
                if (n == 0) { cout << "Primero ingrese un arreglo." << endl; break; }
                cout << "Antes: "; mostrarArreglo(arr, n);
                quickSort(arr, 0, n - 1);
                cout << "Despues: "; mostrarArreglo(arr, n);
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
