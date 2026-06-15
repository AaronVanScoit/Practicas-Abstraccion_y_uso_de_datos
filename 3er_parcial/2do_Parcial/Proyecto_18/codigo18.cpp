#include "codigo18.h"
bool FilaLibStr::estaVacia(){return fila.empty();}
void FilaLibStr::insertarFrente(string val){fila.push_front(val);}
void FilaLibStr::insertarFinal(string val){fila.push_back(val);}
string FilaLibStr::eliminarFrente(){if(estaVacia())return "";string v=fila.front();fila.pop_front();return v;}
string FilaLibStr::eliminarFinal(){if(estaVacia())return "";string v=fila.back();fila.pop_back();return v;}
string FilaLibStr::verFrente(){if(estaVacia())return "";return fila.front();}
string FilaLibStr::verFinal(){if(estaVacia())return "";return fila.back();}
void FilaLibStr::mostrar(){if(estaVacia()){cout<<"Vacia"<<endl;return;}cout<<"Fila: ";for(auto x:fila)cout<<"\""<<x<<"\" ";cout<<endl;}
void FilaLibStr::guardarSalidas(){
    ofstream txt("salida.txt");txt<<"=== FILA DEQUE STL STRING ==="<<endl;for(auto x:fila)txt<<x<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";int i=0;for(auto x:fila){csv<<i++<<","<<x<<"\n";}csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";bool first=true;for(auto x:fila){if(!first)json<<",";json<<"\""<<x<<"\"";first=false;}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque>\n";for(auto x:fila)xml<<"  <elemento>"<<x<<"</elemento>\n";xml<<"</deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
