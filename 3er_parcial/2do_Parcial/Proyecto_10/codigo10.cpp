#include "codigo10.h"
struct NodoS{string dato;NodoS*sig;};
static NodoS*frente=nullptr,*fin=nullptr;
bool ColaPtrStr::estaVacia(){return frente==nullptr;}
void ColaPtrStr::enqueue(string val){NodoS*n=new NodoS();n->dato=val;n->sig=nullptr;if(fin)fin->sig=n;else frente=n;fin=n;cout<<"Enqueue: "<<val<<endl;}
string ColaPtrStr::dequeue(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}string v=frente->dato;NodoS*t=frente;frente=frente->sig;if(!frente)fin=nullptr;delete t;return v;}
string ColaPtrStr::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}return frente->dato;}
void ColaPtrStr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}NodoS*a=frente;cout<<"Cola: ";while(a){cout<<"\""<<a->dato<<"\" ";a=a->sig;}cout<<endl;}
void ColaPtrStr::guardarSalidas(){
    string arr[100];int n=0;NodoS*a=frente;while(a){arr[n++]=a->dato;a=a->sig;}
    ofstream txt("salida.txt");txt<<"=== COLA PUNTEROS STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</cola>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
