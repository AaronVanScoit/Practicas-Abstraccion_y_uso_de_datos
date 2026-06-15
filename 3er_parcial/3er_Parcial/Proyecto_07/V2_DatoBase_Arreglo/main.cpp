#include <iostream>
#include "Lib_arbol.h"
using namespace std;
int main(){
    Arbol a; int op, val;
    // Insertar paradas de la ruta como BST
    int datos[]={3,1,5,0,2,4,6}; // Churubusco como raiz para arbol balanceado
    for(int i=0;i<7;i++) a.insertar(datos[i]);
    do{
        cout<<"\n=== ARBOL BST | Ruta Casa->UPIICSA ===\n1.Mostrar recorridos\n2.Insertar\n3.Dijkstra\n4.Cargar XML\n5.Cargar JSON\n6.Guardar\n0.Salir\nOpcion: ";cin>>op;
        switch(op){
            case 1: a.mostrar(); break;
            case 2: cout<<"Valor: ";cin>>val;a.insertar(val);break;
            case 3:{int o;cout<<"Indice: ";cin>>o;a.dijkstra(o);}break;
            case 4:{string f;cout<<"Archivo: ";cin>>f;a.cargar(f,"xml");}break;
            case 5:{string f;cout<<"Archivo: ";cin>>f;a.cargar(f,"json");}break;
            case 6: a.guardarSalidas(); break;
        }
    }while(op!=0); return 0;
}
