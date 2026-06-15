#include "codigo3.h"
PilaPtr::PilaPtr() : tope(nullptr) {}
PilaPtr::~PilaPtr() { while(tope){NodoPila*t=tope;tope=tope->siguiente;delete t;} }
bool PilaPtr::estaVacia() { return tope==nullptr; }
void PilaPtr::push(int val) {
    NodoPila* nuevo=new NodoPila(); nuevo->dato=val; nuevo->siguiente=tope; tope=nuevo;
    cout<<"Elemento "<<val<<" insertado."<<endl;
}
int PilaPtr::pop() {
    if(estaVacia()){cout<<"[ERROR] Pila vacia"<<endl;return -1;}
    int val=tope->dato; NodoPila*t=tope; tope=tope->siguiente; delete t; return val;
}
int PilaPtr::peek() {
    if(estaVacia()){cout<<"[ERROR] Pila vacia"<<endl;return -1;}
    return tope->dato;
}
void PilaPtr::mostrar() {
    if(estaVacia()){cout<<"Pila vacia"<<endl;return;}
    NodoPila* aux=tope; cout<<"Pila (tope->base): ";
    while(aux){cout<<aux->dato<<" ";aux=aux->siguiente;} cout<<endl;
}
void PilaPtr::guardarSalidas() {
    // collect elements
    int arr[100]; int n=0; NodoPila* aux=tope;
    while(aux){arr[n++]=aux->dato;aux=aux->siguiente;}
    ofstream txt("salida.txt"); txt<<"=== PILA CON PUNTEROS (INT) ==="<<endl<<"Elementos: ";
    for(int i=0;i<n;i++) txt<<arr[i]<<" "; txt<<endl; txt.close();
    ofstream csv("salida.csv"); csv<<"posicion,valor"<<endl;
    for(int i=0;i<n;i++) csv<<i<<","<<arr[i]<<endl; csv.close();
    ofstream json("salida.json"); json<<"{\n  \"estructura\":\"Pila\",\n  \"implementacion\":\"punteros\",\n  \"tipo\":\"int\",\n  \"elementos\":[";
    for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}
    json<<"]\n}"<<endl; json.close();
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<pila>\n  <implementacion>punteros</implementacion>\n  <elementos>\n";
    for(int i=0;i<n;i++) xml<<"    <elemento>"<<arr[i]<<"</elemento>\n";
    xml<<"  </elementos>\n</pila>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
