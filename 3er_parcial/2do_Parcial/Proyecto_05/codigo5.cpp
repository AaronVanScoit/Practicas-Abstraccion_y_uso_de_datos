#include "codigo5.h"
bool PilaLib::estaVacia(){return pila.empty();}
void PilaLib::push(int val){pila.push(val);cout<<"Insertado: "<<val<<endl;}
int PilaLib::pop(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=pila.top();pila.pop();return v;}
int PilaLib::peek(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}return pila.top();}
void PilaLib::mostrar(){if(estaVacia()){cout<<"Pila vacia"<<endl;return;}stack<int>tmp=pila;cout<<"Pila: ";while(!tmp.empty()){cout<<tmp.top()<<" ";tmp.pop();}cout<<endl;}
void PilaLib::guardarSalidas(){
    stack<int>tmp=pila;int arr[100];int n=0;while(!tmp.empty()){arr[n++]=tmp.top();tmp.pop();}
    ofstream txt("salida.txt");txt<<"=== PILA STL INT ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Pila\",\"implementacion\":\"STL\",\"tipo\":\"int\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<pila>\n  <implementacion>STL</implementacion>\n  <tipo>int</tipo>\n  <elementos>\n";for(int i=0;i<n;i++)xml<<"    <elemento>"<<arr[i]<<"</elemento>\n";xml<<"  </elementos>\n</pila>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
