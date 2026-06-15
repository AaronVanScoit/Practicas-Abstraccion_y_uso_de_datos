#include "codigo14.h"
void ListaPersonas::capturar(Persona* p, int n) {
    for(int i=0;i<n;i++){
        cout<<"Nombre: ";cin>>(p+i)->nombre;
        cout<<"Apellido paterno: ";cin>>(p+i)->ap;
        cout<<"Apellido materno: ";cin>>(p+i)->am;
        cout<<"Genero: ";cin>>(p+i)->genero;
        cout<<"Edad: ";cin>>(p+i)->edad;
    }
}
void ListaPersonas::mostrar(Persona* p, int n) {
    cout<<"\nLista de Personas"<<endl;
    for(int i=0;i<n;i++)
        cout<<(p+i)->nombre<<" "<<(p+i)->ap<<" Genero: "<<(p+i)->genero<<" Edad: "<<(p+i)->edad<<endl;
    // guardar salidas
    ofstream txt("salida.txt"); txt<<"=== LISTA PERSONAS CON PUNTERO ==="<<endl;
    for(int i=0;i<n;i++) txt<<(p+i)->nombre<<" "<<(p+i)->ap<<" Edad:"<<(p+i)->edad<<endl; txt.close();
    ofstream csv("salida.csv"); csv<<"nombre,ap,am,genero,edad"<<endl;
    for(int i=0;i<n;i++) csv<<(p+i)->nombre<<","<<(p+i)->ap<<","<<(p+i)->am<<","<<(p+i)->genero<<","<<(p+i)->edad<<endl; csv.close();
    ofstream json("salida.json"); json<<"{\n  \"personas\":[\n";
    for(int i=0;i<n;i++){json<<"    {\"nombre\":\""<<(p+i)->nombre<<" "<<(p+i)->ap<<"\",\"edad\":"<<(p+i)->edad<<"}";if(i<n-1)json<<",";json<<"\n";}
    json<<"  ]\n}"<<endl; json.close();
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<personas>\n";
    for(int i=0;i<n;i++) xml<<"  <persona><nombre>"<<(p+i)->nombre<<" "<<(p+i)->ap<<"</nombre><edad>"<<(p+i)->edad<<"</edad></persona>\n";
    xml<<"</personas>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
