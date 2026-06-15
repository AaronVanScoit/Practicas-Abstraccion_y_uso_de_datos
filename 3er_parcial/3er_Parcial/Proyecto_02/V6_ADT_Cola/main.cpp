#include <iostream>
#include "Lib_digrafo.h"
using namespace std;
int main(){
    Digrafo g; int op;
    Lugar lugares[]={{0,"Casa"},{1,"Insurgentes"},{2,"Vasconcelos"},{3,"Churubusco"},{4,"Anil"},{5,"Iztacalco"},{6,"UPIICSA"}};
    for(int i=0;i<7;i++) g.insertarNodo(lugares[i]);
    g.matAdj[0][1]=10;g.matAdj[1][2]=8;g.matAdj[2][3]=12;
    g.matAdj[3][4]=7;g.matAdj[4][5]=5;g.matAdj[5][6]=8;
    conexionNodo2Nodo ex[]={
        {0,1,"Casa-Insurgentes",10.0f,10.0f},
        {1,2,"Insurgentes-Vasconcelos",8.0f,0.0f},
        {2,3,"Vasconcelos-Churubusco",12.0f,0.0f},
        {3,4,"Churubusco-Anil",7.0f,0.0f},
        {4,5,"Anil-Iztacalco",5.0f,0.0f},
        {5,6,"Iztacalco-UPIICSA",8.0f,50.0f}};
    for(int i=0;i<6;i++) g.aristas[i]=ex[i]; g.nAristas=6;
    do{
        cout<<"\n=== DIGRAFO ADT ===\n1.Mostrar\n2.Dijkstra\n3.Insertar nodo\n4.Eliminar nodo\n5.Cargar XML\n6.Cargar JSON\n7.Guardar\n0.Salir\nOpcion: ";cin>>op;
        switch(op){case 1:g.mostrar();break;case 2:{int o;cout<<"Origen: ";cin>>o;g.dijkstra(o);}break;
        case 3:{Lugar l;cout<<"ID: ";cin>>l.id;cout<<"Etiqueta: ";cin>>l.etiqueta;g.insertarNodo(l);}break;
        case 4:{int id;cout<<"ID: ";cin>>id;g.eliminarNodo(id);}break;
        case 5:{string f;cin>>f;g.cargar(f,"xml");}break;case 6:{string f;cin>>f;g.cargar(f,"json");}break;
        case 7:g.guardarSalidas();break;}
    }while(op!=0); return 0;
}
