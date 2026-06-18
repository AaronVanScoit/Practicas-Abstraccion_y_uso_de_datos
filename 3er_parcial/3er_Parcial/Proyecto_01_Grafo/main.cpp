#include <iostream>
#include "Lib_grafo.h"
using namespace std;

int main() {
    Grafo g;

    // Nodos: 4 rutas Casa (Bosque de Tlalpan) -> UPIICSA
    agregarNodo(g, 0, "Casa");
    agregarNodo(g, 1, "Insurgentes-Sur");
    agregarNodo(g, 2, "Vasconcelos");
    agregarNodo(g, 3, "Tlalpan");
    agregarNodo(g, 4, "Churubusco");
    agregarNodo(g, 5, "Periferico");
    agregarNodo(g, 6, "Ermita-Iztapalapa");
    agregarNodo(g, 7, "Taxquena");
    agregarNodo(g, 8, "Iztacalco");
    agregarNodo(g, 9, "UPIICSA");

    // Ruta 1: Casa -> Insurgentes -> Vasconcelos -> Churubusco -> UPIICSA
    agregarConexion(g, 0, 1, "Casa-InsurgentesSur",       10.0f,  0.0f);
    agregarConexion(g, 1, 2, "InsurgentesSur-Vasconcelos",15.0f,  0.0f);
    agregarConexion(g, 2, 4, "Vasconcelos-Churubusco",    10.0f,  0.0f);

    // Ruta 2: Casa -> Tlalpan -> Churubusco -> UPIICSA
    agregarConexion(g, 0, 3, "Casa-Tlalpan",               8.0f,  0.0f);
    agregarConexion(g, 3, 4, "Tlalpan-Churubusco",         20.0f, 0.0f);

    // Nodo final compartido rutas 1 y 2
    agregarConexion(g, 4, 9, "Churubusco-UPIICSA",         12.0f, 0.0f);

    // Ruta 3: Casa -> Periferico -> Ermita -> UPIICSA
    agregarConexion(g, 0, 5, "Casa-Periferico",            12.0f, 35.0f);
    agregarConexion(g, 5, 6, "Periferico-Ermita",          25.0f, 0.0f);
    agregarConexion(g, 6, 9, "Ermita-UPIICSA",             10.0f, 0.0f);

    // Ruta 4: Casa -> Tlalpan -> Taxquena -> Iztacalco -> UPIICSA
    agregarConexion(g, 3, 7, "Tlalpan-Taxquena",           12.0f, 0.0f);
    agregarConexion(g, 7, 8, "Taxquena-Iztacalco",         15.0f, 0.0f);
    agregarConexion(g, 8, 9, "Iztacalco-UPIICSA",           8.0f, 0.0f);

    int opcion;
    do {
        cout << "\n" << endl;
        cout << "    GRAFO — 4 Rutas Casa->UPIICSA      " << endl;
        cout << "\n" << endl;
        cout << "1. Mostrar grafo" << endl;
        cout << "2. Ruta mas corta con Dijkstra" << endl;
        cout << "3. Ruta mas larga" << endl;
        cout << "4. Cargar desde XML" << endl;
        cout << "5. Cargar desde JSON" << endl;
        cout << "6. Guardar salidas (TXT, CSV, JSON, XML)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: mostrarGrafo(g); break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa, 9=UPIICSA): "; cin >> origen;
                dijkstra(g, origen);
                break;
            }
            case 3: {
                int origen, destino;
                cout << "Nodo origen  (0=Casa ... 9=UPIICSA): "; cin >> origen;
                cout << "Nodo destino (0=Casa ... 9=UPIICSA): "; cin >> destino;
                rutaMasLarga(g, origen, destino);
                break;
            }
            case 4: { string f; cout << "Archivo XML: "; cin >> f; leerDesdeXML(g, f); break; }
            case 5: { string f; cout << "Archivo JSON: "; cin >> f; leerDesdeJSON(g, f); break; }
            case 6: guardarSalidas(g); break;
            case 0: cout << "Saliendo del programa, el trabajo es para un diez" << endl; break;
            default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);
    return 0;
}
