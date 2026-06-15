#include <iostream>
#include "Lib_grafo.h"
using namespace std;
int main(){
    Grafo g; int op;
    g.agregarArista(0,1,10); g.agregarArista(1,2,8);
    g.agregarArista(2,3,12); g.agregarArista(3,4,7);
    g.agregarArista(4,5,5);  g.agregarArista(5,6,8);
    conexionNodo2Nodo ex[]={
        {0,1,"Casa-Insurgentes",10.0f,10.0f},
        {1,2,"Insurgentes-Vasconcelos",8.0f,0.0f},
        {2,3,"Vasconcelos-Churubusco",12.0f,0.0f},
        {3,4,"Churubusco-Anil",7.0f,0.0f},
        {4,5,"Anil-Iztacalco",5.0f,0.0f},
        {5,6,"Iztacalco-UPIICSA",8.0f,50.0f}};
    for(int i=0;i<6;i++) g.aristas[i]=ex[i]; g.nAristas=6;
    do{
        cout<<"\n=== GRAFO V2: DatoBase int arreglo ===\n1.Mostrar\n2.Dijkstra\n3.Cargar XML\n4.Cargar JSON\n5.Guardar\n0.Salir\nOpcion: ";cin>>op;
        switch(op){case 1:g.mostrar();break;case 2:{int o;cout<<"Origen: ";cin>>o;g.dijkstra(o);}break;
        case 3:{string f;cin>>f;g.cargar(f,"xml");}break;case 4:{string f;cin>>f;g.cargar(f,"json");}break;
        case 5:g.guardarSalidas();break;}
    }while(op!=0);
    return 0;
}
