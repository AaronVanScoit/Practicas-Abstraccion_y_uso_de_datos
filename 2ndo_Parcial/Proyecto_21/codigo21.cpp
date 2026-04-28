#include "codigo21.h"
#include <iostream>
using namespace std;

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto]; // Pivote: ultimo elemento
    int i = bajo - 1;       // Indice del elemento mas pequeño

    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            // Intercambiar arr[i] y arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Colocar el pivote en su posicion correcta
    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;

    return i + 1;
}

void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);  // Subarreglo izquierdo
        quickSort(arr, pi + 1, alto);  // Subarreglo derecho
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
