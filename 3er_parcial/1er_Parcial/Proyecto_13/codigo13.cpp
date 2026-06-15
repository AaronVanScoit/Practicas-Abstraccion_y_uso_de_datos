#include "codigo13.h"
void Registro::capturarPersonas(Persona p[], int n) {
    for(int i=0;i<n;i++){
        cout<<"Persona "<<i+1<<":"<<endl;
        cout<<"Nombre: ";cin>>p[i].nombre; cout<<"Apellido paterno: ";cin>>p[i].ap;
        cout<<"Apellido materno: ";cin>>p[i].am; cout<<"Genero: ";cin>>p[i].genero;
        cout<<"Edad: ";cin>>p[i].edad;
    }
}
void Registro::capturarAutos(Auto a[], int n) {
    for(int i=0;i<n;i++){
        cout<<"Auto "<<i+1<<":"<<endl;
        cout<<"Precio: ";cin>>a[i].precio; cout<<"Anio: ";cin>>a[i].anio;
    }
}
void Registro::mostrarPersonas(Persona p[], int n) {
    cout<<"\nLista de Personas"<<endl;
    for(int i=0;i<n;i++) cout<<p[i].nombre<<" "<<p[i].ap<<" "<<p[i].am<<" Genero: "<<p[i].genero<<" Edad: "<<p[i].edad<<endl;
}
void Registro::mostrarAutos(Auto a[], int n) {
    cout<<"\nLista de Autos"<<endl;
    for(int i=0;i<n;i++) cout<<"Auto "<<i+1<<" -> Precio: "<<a[i].precio<<" Anio: "<<a[i].anio<<endl;
}
void Registro::guardarSalidas(Persona p[], Auto a[], int n) {
    ofstream txt("salida.txt"); txt<<"=== LISTA PERSONAS Y AUTOS ==="<<endl;
    for(int i=0;i<n;i++) txt<<"Persona "<<i+1<<": "<<p[i].nombre<<" "<<p[i].ap<<" Edad:"<<p[i].edad<<endl;
    for(int i=0;i<n;i++) txt<<"Auto "<<i+1<<": Precio:"<<a[i].precio<<" Anio:"<<a[i].anio<<endl;
    txt.close();
    ofstream csv("salida.csv"); csv<<"tipo,nombre,ap,am,genero,edad,precio,anio"<<endl;
    for(int i=0;i<n;i++) csv<<"Persona,"<<p[i].nombre<<","<<p[i].ap<<","<<p[i].am<<","<<p[i].genero<<","<<p[i].edad<<",,,"<<endl;
    for(int i=0;i<n;i++) csv<<"Auto,,,,,,"<<a[i].precio<<","<<a[i].anio<<endl;
    csv.close();
    ofstream json("salida.json"); json<<"{\n  \"personas\":[\n";
    for(int i=0;i<n;i++){json<<"    {\"nombre\":\""<<p[i].nombre<<" "<<p[i].ap<<"\",\"edad\":"<<p[i].edad<<"}";if(i<n-1)json<<",";json<<"\n";}
    json<<"  ],\n  \"autos\":[\n";
    for(int i=0;i<n;i++){json<<"    {\"precio\":"<<a[i].precio<<",\"anio\":"<<a[i].anio<<"}";if(i<n-1)json<<",";json<<"\n";}
    json<<"  ]\n}"<<endl; json.close();
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<registro>\n  <personas>\n";
    for(int i=0;i<n;i++) xml<<"    <persona><nombre>"<<p[i].nombre<<" "<<p[i].ap<<"</nombre><edad>"<<p[i].edad<<"</edad></persona>\n";
    xml<<"  </personas>\n  <autos>\n";
    for(int i=0;i<n;i++) xml<<"    <auto><precio>"<<a[i].precio<<"</precio><anio>"<<a[i].anio<<"</anio></auto>\n";
    xml<<"  </autos>\n</registro>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
