#include "codigo4.h"
PilaPtrStr::PilaPtrStr():tope(nullptr){}
PilaPtrStr::~PilaPtrStr(){while(tope){NodoPilaStr*t=tope;tope=tope->siguiente;delete t;}}
bool PilaPtrStr::estaVacia(){return tope==nullptr;}
void PilaPtrStr::push(string val){NodoPilaStr*n=new NodoPilaStr();n->dato=val;n->siguiente=tope;tope=n;cout<<"Insertado: "<<val<<endl;}
string PilaPtrStr::pop(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}string v=tope->dato;NodoPilaStr*t=tope;tope=tope->siguiente;delete t;return v;}
string PilaPtrStr::peek(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}return tope->dato;}
void PilaPtrStr::mostrar(){if(estaVacia()){cout<<"Pila vacia"<<endl;return;}NodoPilaStr*a=tope;cout<<"Pila: ";while(a){cout<<"\""<<a->dato<<"\" ";a=a->siguiente;}cout<<endl;}
void PilaPtrStr::guardarSalidas(){
    string arr[100];int n=0;NodoPilaStr*a=tope;while(a){arr[n++]=a->dato;a=a->siguiente;}
    ofstream txt("salida.txt");txt<<"=== PILA PUNTEROS STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<pila>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</pila>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
