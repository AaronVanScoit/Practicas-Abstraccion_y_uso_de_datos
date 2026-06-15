#include "codigo11.h"

int Promedio::suma(int* v, int n)       { int s=0; for(int i=0;i<n;i++) s+=*(v+i); return s; }
float Promedio::promedio(int* v, int n) { return suma(v,n)/(float)n; }
float Promedio::media(int* v, int n)    { return suma(v,n)/(float)n; }
int Promedio::maximo(int* v, int n)     { int mx=*(v); for(int i=1;i<n;i++) if(*(v+i)>mx) mx=*(v+i); return mx; }
int Promedio::minimo(int* v, int n)     { int mn=*(v); for(int i=1;i<n;i++) if(*(v+i)<mn) mn=*(v+i); return mn; }
void Promedio::guardarSalidas(int* v, int n, int s, float p, float m, int mx, int mn) {
    ofstream txt("salida.txt");
    txt<<"=== PROMEDIO CON ARREGLO ==="<<endl<<"Calificaciones: ";
    for(int i=0;i<n;i++) txt<<*(v+i)<<" "; txt<<endl;
    txt<<"Suma: "<<s<<"\nPromedio: "<<p<<"\nMedia: "<<m<<"\nMaximo: "<<mx<<"\nMinimo: "<<mn<<endl;
    txt.close();
    ofstream csv("salida.csv");
    csv<<"campo,valor\nsuma,"<<s<<"\npromedio,"<<p<<"\nmedia,"<<m<<"\nmaximo,"<<mx<<"\nminimo,"<<mn<<endl;
    csv.close();
    ofstream json("salida.json");
    json<<"{\n  \"suma\":"<<s<<",\n  \"promedio\":"<<p<<",\n  \"media\":"<<m<<",\n  \"maximo\":"<<mx<<",\n  \"minimo\":"<<mn<<"\n}"<<endl;
    json.close();
    ofstream xml("salida.xml");
    xml<<"<?xml version=\"1.0\"?>\n<promedio>\n  <suma>"<<s<<"</suma>\n  <promedio>"<<p<<"</promedio>\n";
    xml<<"  <media>"<<m<<"</media>\n  <maximo>"<<mx<<"</maximo>\n  <minimo>"<<mn<<"</minimo>\n</promedio>"<<endl;
    xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
