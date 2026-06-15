#include "codigo09.h"
struct Nodo{int dato;Nodo*sig;};
static Nodo*frente=nullptr,*fin=nullptr;
bool ColaPtr::estaVacia(){return frente==nullptr;}
void ColaPtr::enqueue(int val){Nodo*n=new Nodo();n->dato=val;n->sig=nullptr;if(fin)fin->sig=n;else frente=n;fin=n;cout<<"Enqueue: "<<val<<endl;}
int ColaPtr::dequeue(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=frente->dato;Nodo*t=frente;frente=frente->sig;if(!frente)fin=nullptr;delete t;return v;}
int ColaPtr::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}return frente->dato;}
void ColaPtr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}Nodo*a=frente;cout<<"Cola: ";while(a){cout<<a->dato<<" ";a=a->sig;}cout<<endl;}
void ColaPtr::guardarSalidas(){
    int arr[100];int n=0;Nodo*a=frente;while(a){arr[n++]=a->dato;a=a->sig;}
    ofstream txt("salida.txt");txt<<"=== COLA PUNTEROS INT ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Cola\",\"implementacion\":\"punteros\",\"tipo\":\"int\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola><implementacion>punteros</implementacion><tipo>int</tipo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</elementos></cola>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
