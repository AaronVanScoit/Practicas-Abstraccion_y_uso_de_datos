#include <iostream>
#include "Lib_arbol.h"
using namespace std;

int main() {
    Arbol a;

    agregarNodo(a, 0, "Casa");
    agregarNodo(a, 1, "Insurgentes-Sur");
    agregarNodo(a, 2, "Vasconcelos");
    agregarNodo(a, 3, "Tlalpan");
    agregarNodo(a, 4, "Churubusco");
    agregarNodo(a, 5, "Periferico");
    agregarNodo(a, 6, "Ermita-Iztapalapa");
    agregarNodo(a, 7, "Taxquena");
    agregarNodo(a, 8, "Iztacalco");
    agregarNodo(a, 9, "UPIICSA");

    agregarConexion(a, 0, 1, "Casa-InsurgentesSur",        10.0f,  0.0f);
    agregarConexion(a, 1, 2, "InsurgentesSur-Vasconcelos", 15.0f,  0.0f);
    agregarConexion(a, 2, 4, "Vasconcelos-Churubusco",     10.0f,  0.0f);
    agregarConexion(a, 0, 3, "Casa-Tlalpan",                8.0f,  0.0f);
    agregarConexion(a, 3, 4, "Tlalpan-Churubusco",         20.0f,  0.0f);
    agregarConexion(a, 4, 9, "Churubusco-UPIICSA",         12.0f,  0.0f);
    agregarConexion(a, 0, 5, "Casa-Periferico",            12.0f, 35.0f);
    agregarConexion(a, 5, 6, "Periferico-Ermita",          25.0f,  0.0f);
    agregarConexion(a, 6, 9, "Ermita-UPIICSA",             10.0f,  0.0f);
    agregarConexion(a, 3, 7, "Tlalpan-Taxquena",           12.0f,  0.0f);
    agregarConexion(a, 7, 8, "Taxquena-Iztacalco",         15.0f,  0.0f);
    agregarConexion(a, 8, 9, "Iztacalco-UPIICSA",           8.0f,  0.0f);

    int opcion;
    do {
        cout << "\n" << endl;
        cout << "    ARBOL — 4 Rutas Casa->UPIICSA      " << endl;
        cout << "\n" << endl;
        cout << "1. Mostrar arbol (nodos, aristas, rutas y recorridos)" << endl;
        cout << "2. Ruta mas corta con Dijkstra" << endl;
        cout << "3. Ruta mas larga" << endl;
        cout << "4. Cargar desde XML" << endl;
        cout << "5. Cargar desde JSON" << endl;
        cout << "6. Guardar salidas (TXT, CSV, JSON, XML)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: mostrarArbol(a); break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa, 9=UPIICSA): "; cin >> origen;
                dijkstra(a, origen);
                break;
            }
            case 3: {
                int origen, destino;
                cout << "Nodo origen  (0=Casa ... 9=UPIICSA): "; cin >> origen;
                cout << "Nodo destino (0=Casa ... 9=UPIICSA): "; cin >> destino;
                rutaMasLarga(a, origen, destino);
                break;
            }
            case 4: { string f; cout << "Archivo XML: "; cin >> f; leerDesdeXML(a, f); break; }
            case 5: { string f; cout << "Archivo JSON: "; cin >> f; leerDesdeJSON(a, f); break; }
            case 6: guardarSalidas(a); break;
            case 0: cout << "Saliendo del programa, el trabajo es para un diez" << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
    return 0;
}
