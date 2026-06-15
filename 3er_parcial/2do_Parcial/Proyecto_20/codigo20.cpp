#include "codigo20.h"
void Ordenamiento::llenarArreglo(){cout<<"Cuantos elementos: ";cin>>n;for(int i=0;i<n;i++){cout<<"Elemento["<<i+1<<"]: ";cin>>datos[i];}}
void Ordenamiento::mostrarArreglo(){cout<<"Arreglo: ";for(int i=0;i<n;i++)cout<<datos[i]<<" ";cout<<endl;}
void Ordenamiento::merge(int izq,int mid,int der){
    int n1=mid-izq+1,n2=der-mid;
    int L[MAX],R[MAX];
    for(int i=0;i<n1;i++)L[i]=datos[izq+i];
    for(int j=0;j<n2;j++)R[j]=datos[mid+1+j];
    int i=0,j=0,k=izq;
    while(i<n1&&j<n2){if(L[i]<=R[j]){datos[k]=L[i];i++;}else{datos[k]=R[j];j++;}k++;}
    while(i<n1){datos[k]=L[i];i++;k++;}
    while(j<n2){datos[k]=R[j];j++;k++;}
}
void Ordenamiento::mergeSort(int izq,int der){if(izq<der){int mid=(izq+der)/2;mergeSort(izq,mid);mergeSort(mid+1,der);merge(izq,mid,der);}}
void Ordenamiento::guardarSalidas(){
    ofstream txt("salida.txt");txt<<"=== MERGE SORT ==="<<endl<<"Ordenado: ";for(int i=0;i<n;i++)txt<<datos[i]<<" ";txt<<endl;txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<datos[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"algoritmo\":\"MergeSort\",\n  \"ordenado\":[";for(int i=0;i<n;i++){json<<datos[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<sort><algoritmo>MergeSort</algoritmo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<datos[i]<<"</elemento>\n";xml<<"</elementos></sort>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
