#include "codigo19.h"
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool intercambio;
    for (int i = 0; i < n - 1; i++) {
        intercambio = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                intercambio = true;
            }
        }
        // Optimizacion: si no hubo intercambios, ya esta ordenado
        if (!intercambio) break;
    }
}

void mostrarArreglo(int arr[], int n) {
    cout << "[ ";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

void llenarArreglo(int arr[], int& n) {
    cout << "Cuantos elementos desea ingresar? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }
}
