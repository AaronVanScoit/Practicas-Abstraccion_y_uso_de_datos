#include "codigo21.h"
void Ordenamiento::llenarArreglo(){cout<<"Cuantos elementos: ";cin>>n;for(int i=0;i<n;i++){cout<<"Elemento["<<i+1<<"]: ";cin>>datos[i];}}
void Ordenamiento::mostrarArreglo(){cout<<"Arreglo: ";for(int i=0;i<n;i++)cout<<datos[i]<<" ";cout<<endl;}
int Ordenamiento::particion(int izq,int der){
    int pivote=datos[der],i=izq-1;
    for(int j=izq;j<der;j++)if(datos[j]<=pivote){i++;int tmp=datos[i];datos[i]=datos[j];datos[j]=tmp;}
    int tmp=datos[i+1];datos[i+1]=datos[der];datos[der]=tmp;
    return i+1;
}
void Ordenamiento::quickSort(int izq,int der){if(izq<der){int pi=particion(izq,der);quickSort(izq,pi-1);quickSort(pi+1,der);}}
void Ordenamiento::guardarSalidas(){
    ofstream txt("salida.txt");txt<<"=== QUICK SORT ==="<<endl<<"Ordenado: ";for(int i=0;i<n;i++)txt<<datos[i]<<" ";txt<<endl;txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<datos[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"algoritmo\":\"QuickSort\",\n  \"ordenado\":[";for(int i=0;i<n;i++){json<<datos[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<sort><algoritmo>QuickSort</algoritmo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<datos[i]<<"</elemento>\n";xml<<"</elementos></sort>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
