#include "codigo12.h"
#include <queue>
static queue<string> cola;
bool ColaLibStr::estaVacia(){return cola.empty();}
void ColaLibStr::enqueue(string val){cola.push(val);cout<<"Enqueue: "<<val<<endl;}
string ColaLibStr::dequeue(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}string v=cola.front();cola.pop();return v;}
string ColaLibStr::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}return cola.front();}
void ColaLibStr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}queue<string>tmp=cola;cout<<"Cola: ";while(!tmp.empty()){cout<<"\""<<tmp.front()<<"\" ";tmp.pop();}cout<<endl;}
void ColaLibStr::guardarSalidas(){
    queue<string>tmp=cola;string arr[100];int n=0;while(!tmp.empty()){arr[n++]=tmp.front();tmp.pop();}
    ofstream txt("salida.txt");txt<<"=== COLA STL STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</cola>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
