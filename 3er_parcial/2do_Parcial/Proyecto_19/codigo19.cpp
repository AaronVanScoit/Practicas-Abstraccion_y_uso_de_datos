#include "codigo19.h"
void Ordenamiento::llenarArreglo(){
    cout<<"Cuantos elementos (max "<<MAX<<"): ";cin>>n;
    for(int i=0;i<n;i++){cout<<"Elemento["<<i+1<<"]: ";cin>>datos[i];}
}
void Ordenamiento::mostrarArreglo(){
    cout<<"Arreglo: ";for(int i=0;i<n;i++)cout<<datos[i]<<" ";cout<<endl;
}
void Ordenamiento::bubbleSort(){
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(datos[j]>datos[j+1]){int tmp=datos[j];datos[j]=datos[j+1];datos[j+1]=tmp;}
    cout<<"Ordenado con Bubble Sort: ";mostrarArreglo();
}
void Ordenamiento::guardarSalidas(){
    ofstream txt("salida.txt");txt<<"=== BUBBLE SORT ==="<<endl<<"Ordenado: ";for(int i=0;i<n;i++)txt<<datos[i]<<" ";txt<<endl;txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<datos[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"algoritmo\":\"BubbleSort\",\n  \"ordenado\":[";for(int i=0;i<n;i++){json<<datos[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<sort><algoritmo>BubbleSort</algoritmo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<datos[i]<<"</elemento>\n";xml<<"</elementos></sort>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
