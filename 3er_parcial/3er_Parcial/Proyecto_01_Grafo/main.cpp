#include <iostream>
#include "Lib_grafo.h"
using namespace std;

int main() {
    Grafo g;

    // Nodos: paradas de la ruta 
    agregarNodo(g, 0, "Casa");
    agregarNodo(g, 1, "Insurgentes");
    agregarNodo(g, 2, "Vasconcelos");
    agregarNodo(g, 3, "Churubusco");
    agregarNodo(g, 4, "Anil");
    agregarNodo(g, 5, "Iztacalco");
    agregarNodo(g, 6, "UPIICSA");

    // Rutas / conexionNodo2Nodo
    // Grafo NO dirigido: las conexiones van en ambos sentidos
    agregarConexion(g, 0, 1, "Casa-Insurgentes",       10.0f, 10.0f);
    agregarConexion(g, 1, 2, "Insurgentes-Vasconcelos", 8.0f,  0.0f);
    agregarConexion(g, 2, 3, "Vasconcelos-Churubusco", 12.0f,  0.0f);
    agregarConexion(g, 3, 4, "Churubusco-Anil",         7.0f,  0.0f);
    agregarConexion(g, 4, 5, "Anil-Iztacalco",          5.0f,  0.0f);
    agregarConexion(g, 5, 6, "Iztacalco-UPIICSA",       8.0f, 50.0f);

    int opcion;
    do {
        cout << "\n========================================" << endl;
        cout << "         GRAFO — Ruta Casa->UPIICSA    " << endl;
        cout << "========================================" << endl;
        cout << "1. Mostrar grafo" << endl;
        cout << "2. Ejecutar Dijkstra" << endl;
        cout << "3. Cargar desde XML" << endl;
        cout << "4. Cargar desde JSON" << endl;
        cout << "5. Guardar salidas (TXT, CSV, JSON, XML)" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarGrafo(g);
                break;
            case 2: {
                int origen;
                cout << "Nodo origen (0=Casa, 6=UPIICSA): ";
                cin >> origen;
                dijkstra(g, origen);
                break;
            }
            case 3: {
                string archivo;
                cout << "Nombre del archivo XML: ";
                cin >> archivo;
                leerDesdeXML(g, archivo);
                break;
            }
            case 4: {
                string archivo;
                cout << "Nombre del archivo JSON: ";
                cin >> archivo;
                leerDesdeJSON(g, archivo);
                break;
            }
            case 5:
                guardarSalidas(g);
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
