#include "codigo9.h"
int Promedio::suma(int a,int b,int c,int d,int e)       { return a+b+c+d+e; }
float Promedio::promedio(int a,int b,int c,int d,int e) { return (a+b+c+d+e)/5.0f; }
float Promedio::media(int a,int b,int c,int d,int e)    { return (a+b+c+d+e)/5.0f; }
int Promedio::maximo(int a,int b,int c,int d,int e) {
    int mx=a; if(b>mx)mx=b; if(c>mx)mx=c; if(d>mx)mx=d; if(e>mx)mx=e; return mx;
}
int Promedio::minimo(int a,int b,int c,int d,int e) {
    int mn=a; if(b<mn)mn=b; if(c<mn)mn=c; if(d<mn)mn=d; if(e<mn)mn=e; return mn;
}
void Promedio::guardarSalidas(int a,int b,int c,int d,int e,int s,float p,float m,int mx,int mn) {
    ofstream txt("salida.txt");
    txt<<"=== PROMEDIO ==="<<endl<<"Calificaciones: "<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
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
