#include "codigo15.h"
FilaPtr::FilaPtr():frente(nullptr),fin(nullptr){}
FilaPtr::~FilaPtr(){while(frente){NodoFila*t=frente;frente=frente->sig;delete t;}}
bool FilaPtr::estaVacia(){return frente==nullptr;}
void FilaPtr::insertarFrente(int val){NodoFila*n=new NodoFila();n->dato=val;n->ant=nullptr;n->sig=frente;if(frente)frente->ant=n;else fin=n;frente=n;cout<<"InsFrente: "<<val<<endl;}
void FilaPtr::insertarFinal(int val){NodoFila*n=new NodoFila();n->dato=val;n->sig=nullptr;n->ant=fin;if(fin)fin->sig=n;else frente=n;fin=n;cout<<"InsFinal: "<<val<<endl;}
int FilaPtr::eliminarFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=frente->dato;NodoFila*t=frente;frente=frente->sig;if(frente)frente->ant=nullptr;else fin=nullptr;delete t;return v;}
int FilaPtr::eliminarFinal(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=fin->dato;NodoFila*t=fin;fin=fin->ant;if(fin)fin->sig=nullptr;else frente=nullptr;delete t;return v;}
int FilaPtr::verFrente(){if(estaVacia())return -1;return frente->dato;}
int FilaPtr::verFinal(){if(estaVacia())return -1;return fin->dato;}
void FilaPtr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}NodoFila*a=frente;cout<<"Fila: ";while(a){cout<<a->dato<<" ";a=a->sig;}cout<<endl;}
void FilaPtr::guardarSalidas(){
    int arr[100];int n=0;NodoFila*a=frente;while(a){arr[n++]=a->dato;a=a->sig;}
    ofstream txt("salida.txt");txt<<"=== FILA DEQUE PUNTEROS INT ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Deque\",\"implementacion\":\"punteros\",\"tipo\":\"int\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque><implementacion>punteros</implementacion><tipo>int</tipo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</elementos></deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
