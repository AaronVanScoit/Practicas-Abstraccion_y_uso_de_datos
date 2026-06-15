#include <iostream>
#include "Lib_arbol.h"
using namespace std;
int main(){
    Arbol a; int op;
    // Paradas de la ruta insertas como Lugar en BST (por ID)
    // Churubusco(3) como raiz para arbol balanceado
    Lugar paradas[]={{3,"Churubusco"},{1,"Insurgentes"},{5,"Iztacalco"},{0,"Casa"},{2,"Vasconcelos"},{4,"Anil"},{6,"UPIICSA"}};
    for(int i=0;i<7;i++) a.insertar(paradas[i]);
    do{
        cout<<"\n=== ARBOL | Ruta Casa->UPIICSA ===\n1.Mostrar\n2.Insertar Lugar\n3.Dijkstra\n4.Cargar XML\n5.Cargar JSON\n6.Guardar\n0.Salir\nOpcion: ";cin>>op;
        switch(op){
            case 1: a.mostrar(); break;
            case 2:{Lugar l;cout<<"ID: ";cin>>l.id;cout<<"Etiqueta: ";cin>>l.etiqueta;a.insertar(l);}break;
            case 3:{int o;cout<<"Indice: ";cin>>o;a.dijkstra(o);}break;
            case 4:{string f;cout<<"Archivo: ";cin>>f;a.cargar(f,"xml");}break;
            case 5:{string f;cout<<"Archivo: ";cin>>f;a.cargar(f,"json");}break;
            case 6: a.guardarSalidas(); break;
        }
    }while(op!=0); return 0;
}
