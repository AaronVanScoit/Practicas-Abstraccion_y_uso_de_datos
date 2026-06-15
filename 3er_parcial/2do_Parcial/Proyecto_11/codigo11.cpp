#include "codigo11.h"
#include <queue>
static queue<int> cola;
bool ColaLib::estaVacia(){return cola.empty();}
void ColaLib::enqueue(int val){cola.push(val);cout<<"Enqueue: "<<val<<endl;}
int ColaLib::dequeue(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=cola.front();cola.pop();return v;}
int ColaLib::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}return cola.front();}
void ColaLib::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}queue<int>tmp=cola;cout<<"Cola: ";while(!tmp.empty()){cout<<tmp.front()<<" ";tmp.pop();}cout<<endl;}
void ColaLib::guardarSalidas(){
    queue<int>tmp=cola;int arr[100];int n=0;while(!tmp.empty()){arr[n++]=tmp.front();tmp.pop();}
    ofstream txt("salida.txt");txt<<"=== COLA STL INT ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Cola\",\"implementacion\":\"STL\",\"tipo\":\"int\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola><implementacion>STL</implementacion><tipo>int</tipo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</elementos></cola>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
