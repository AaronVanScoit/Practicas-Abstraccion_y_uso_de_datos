#include "codigo2.h"
PilaString::PilaString() : tope(-1) {}
bool PilaString::estaLlena() { return tope==MAX-1; }
bool PilaString::estaVacia() { return tope==-1; }
void PilaString::push(string val) {
    if(estaLlena()){cout<<"[ERROR] Pila llena"<<endl;return;}
    datos[++tope]=val; cout<<"Elemento \""<<val<<"\" insertado."<<endl;
}
string PilaString::pop() {
    if(estaVacia()){cout<<"[ERROR] Pila vacia"<<endl;return "";}
    return datos[tope--];
}
string PilaString::peek() {
    if(estaVacia()){cout<<"[ERROR] Pila vacia"<<endl;return "";}
    return datos[tope];
}
void PilaString::mostrar() {
    if(estaVacia()){cout<<"Pila vacia"<<endl;return;}
    cout<<"Pila (tope->base): ";
    for(int i=tope;i>=0;i--) cout<<"\""<<datos[i]<<"\" "; cout<<endl;
}
void PilaString::guardarSalidas() {
    ofstream txt("salida.txt"); txt<<"=== PILA CON ARREGLOS (STRING) ==="<<endl;
    txt<<"Elementos (tope->base): ";
    for(int i=tope;i>=0;i--) txt<<"\""<<datos[i]<<"\" "; txt<<endl; txt.close();
    ofstream csv("salida.csv"); csv<<"posicion,valor"<<endl;
    for(int i=tope;i>=0;i--) csv<<(tope-i)<<","<<datos[i]<<endl; csv.close();
    ofstream json("salida.json"); json<<"{\n  \"estructura\":\"Pila\",\n  \"tipo\":\"string\",\n  \"elementos\":[";
    for(int i=tope;i>=0;i--){json<<"\""<<datos[i]<<"\"";if(i>0)json<<",";}
    json<<"]\n}"<<endl; json.close();
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<pila>\n  <tipo>string</tipo>\n  <elementos>\n";
    for(int i=tope;i>=0;i--) xml<<"    <elemento>"<<datos[i]<<"</elemento>\n";
    xml<<"  </elementos>\n</pila>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
