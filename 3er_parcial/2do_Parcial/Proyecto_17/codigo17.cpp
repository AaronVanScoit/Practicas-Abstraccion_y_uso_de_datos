#include "codigo17.h"
bool FilaLib::estaVacia(){return fila.empty();}
void FilaLib::insertarFrente(int val){fila.push_front(val);cout<<"InsFrente: "<<val<<endl;}
void FilaLib::insertarFinal(int val){fila.push_back(val);cout<<"InsFinal: "<<val<<endl;}
int FilaLib::eliminarFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=fila.front();fila.pop_front();return v;}
int FilaLib::eliminarFinal(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=fila.back();fila.pop_back();return v;}
int FilaLib::verFrente(){if(estaVacia())return -1;return fila.front();}
int FilaLib::verFinal(){if(estaVacia())return -1;return fila.back();}
void FilaLib::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}cout<<"Fila: ";for(auto x:fila)cout<<x<<" ";cout<<endl;}
void FilaLib::guardarSalidas(){
    ofstream txt("salida.txt");txt<<"=== FILA DEQUE STL INT ==="<<endl;for(auto x:fila)txt<<x<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";int i=0;for(auto x:fila){csv<<i++<<","<<x<<"\n";}csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Deque\",\"implementacion\":\"STL\",\"tipo\":\"int\",\n  \"elementos\":[";bool first=true;for(auto x:fila){if(!first)json<<",";json<<x;first=false;}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque><implementacion>STL</implementacion><tipo>int</tipo><elementos>\n";for(auto x:fila)xml<<"  <elemento>"<<x<<"</elemento>\n";xml<<"</elementos></deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
