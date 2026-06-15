#include "codigo16.h"
FilaPtrStr::FilaPtrStr():frente(nullptr),fin(nullptr){}
FilaPtrStr::~FilaPtrStr(){while(frente){NodoFilaStr*t=frente;frente=frente->sig;delete t;}}
bool FilaPtrStr::estaVacia(){return frente==nullptr;}
void FilaPtrStr::insertarFrente(string val){NodoFilaStr*n=new NodoFilaStr();n->dato=val;n->ant=nullptr;n->sig=frente;if(frente)frente->ant=n;else fin=n;frente=n;}
void FilaPtrStr::insertarFinal(string val){NodoFilaStr*n=new NodoFilaStr();n->dato=val;n->sig=nullptr;n->ant=fin;if(fin)fin->sig=n;else frente=n;fin=n;}
string FilaPtrStr::eliminarFrente(){if(estaVacia()){return "";}string v=frente->dato;NodoFilaStr*t=frente;frente=frente->sig;if(frente)frente->ant=nullptr;else fin=nullptr;delete t;return v;}
string FilaPtrStr::eliminarFinal(){if(estaVacia()){return "";}string v=fin->dato;NodoFilaStr*t=fin;fin=fin->ant;if(fin)fin->sig=nullptr;else frente=nullptr;delete t;return v;}
string FilaPtrStr::verFrente(){if(estaVacia())return "";return frente->dato;}
string FilaPtrStr::verFinal(){if(estaVacia())return "";return fin->dato;}
void FilaPtrStr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}NodoFilaStr*a=frente;cout<<"Fila: ";while(a){cout<<"\""<<a->dato<<"\" ";a=a->sig;}cout<<endl;}
void FilaPtrStr::guardarSalidas(){
    string arr[100];int n=0;NodoFilaStr*a=frente;while(a){arr[n++]=a->dato;a=a->sig;}
    ofstream txt("salida.txt");txt<<"=== FILA DEQUE PUNTEROS STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
