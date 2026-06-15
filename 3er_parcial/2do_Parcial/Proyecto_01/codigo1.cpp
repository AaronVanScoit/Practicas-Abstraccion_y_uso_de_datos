#include "codigo1.h"
Pila::Pila() : tope(-1) {}
bool Pila::estaLlena()  { return tope == MAX-1; }
bool Pila::estaVacia()  { return tope == -1; }
void Pila::push(int val) {
    if(estaLlena()) { cout<<"[ERROR] Pila llena"<<endl; return; }
    datos[++tope]=val;
    cout<<"Elemento "<<val<<" insertado."<<endl;
}
int Pila::pop() {
    if(estaVacia()) { cout<<"[ERROR] Pila vacia"<<endl; return -1; }
    return datos[tope--];
}
int Pila::peek() {
    if(estaVacia()) { cout<<"[ERROR] Pila vacia"<<endl; return -1; }
    return datos[tope];
}
void Pila::mostrar() {
    if(estaVacia()){ cout<<"Pila vacia"<<endl; return; }
    cout<<"Pila (tope->base): ";
    for(int i=tope;i>=0;i--) cout<<datos[i]<<" ";
    cout<<endl;
}
void Pila::guardarSalidas() {
    // TXT
    ofstream txt("salida.txt"); txt<<"=== PILA CON ARREGLOS (INT) ==="<<endl;
    txt<<"Tope: "<<(estaVacia()?-1:datos[tope])<<"\nElementos (tope->base): ";
    for(int i=tope;i>=0;i--) txt<<datos[i]<<" "; txt<<endl; txt.close();
    // CSV
    ofstream csv("salida.csv"); csv<<"posicion,valor"<<endl;
    for(int i=tope;i>=0;i--) csv<<(tope-i)<<","<<datos[i]<<endl; csv.close();
    // JSON
    ofstream json("salida.json"); json<<"{\n  \"estructura\":\"Pila\",\n  \"implementacion\":\"arreglo\",\n  \"tipo\":\"int\",\n  \"elementos\":[";
    for(int i=tope;i>=0;i--){json<<datos[i];if(i>0)json<<",";}
    json<<"]\n}"<<endl; json.close();
    // XML
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<pila>\n  <implementacion>arreglo</implementacion>\n  <tipo>int</tipo>\n  <elementos>\n";
    for(int i=tope;i>=0;i--) xml<<"    <elemento posicion=\""<<(tope-i)<<"\">"<<datos[i]<<"</elemento>\n";
    xml<<"  </elementos>\n</pila>"<<endl; xml.close();
    cout<<"[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]"<<endl;
}
