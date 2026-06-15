#include "codigo6.h"
bool PilaLibStr::estaVacia(){return pila.empty();}
void PilaLibStr::push(string val){pila.push(val);cout<<"Insertado: "<<val<<endl;}
string PilaLibStr::pop(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}string v=pila.top();pila.pop();return v;}
string PilaLibStr::peek(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}return pila.top();}
void PilaLibStr::mostrar(){if(estaVacia()){cout<<"Pila vacia"<<endl;return;}stack<string>tmp=pila;cout<<"Pila: ";while(!tmp.empty()){cout<<"\""<<tmp.top()<<"\" ";tmp.pop();}cout<<endl;}
void PilaLibStr::guardarSalidas(){
    stack<string>tmp=pila;string arr[100];int n=0;while(!tmp.empty()){arr[n++]=tmp.top();tmp.pop();}
    ofstream txt("salida.txt");txt<<"=== PILA STL STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<pila>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</pila>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
