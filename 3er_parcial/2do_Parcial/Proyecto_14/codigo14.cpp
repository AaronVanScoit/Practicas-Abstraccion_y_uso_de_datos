#include "codigo14.h"
FilaStr::FilaStr():frente(0),fin(0),tam(0){}
bool FilaStr::estaVacia(){return tam==0;}
bool FilaStr::estaLlena(){return tam==MAX;}
void FilaStr::insertarFrente(string val){if(estaLlena()){cout<<"Llena"<<endl;return;}frente=(frente-1+MAX)%MAX;datos[frente]=val;tam++;}
void FilaStr::insertarFinal(string val){if(estaLlena()){cout<<"Llena"<<endl;return;}datos[fin]=val;fin=(fin+1)%MAX;tam++;}
string FilaStr::eliminarFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}string v=datos[frente];frente=(frente+1)%MAX;tam--;return v;}
string FilaStr::eliminarFinal(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}fin=(fin-1+MAX)%MAX;string v=datos[fin];tam--;return v;}
string FilaStr::verFrente(){if(estaVacia()){return "";}return datos[frente];}
string FilaStr::verFinal(){if(estaVacia()){return "";}return datos[(fin-1+MAX)%MAX];}
void FilaStr::mostrar(){if(estaVacia()){cout<<"Fila vacia"<<endl;return;}cout<<"Fila: ";for(int c=0;c<tam;c++)cout<<"\""<<datos[(frente+c)%MAX]<<"\" ";cout<<endl;}
void FilaStr::guardarSalidas(){
    string arr[MAX];int n=0;for(int c=0;c<tam;c++)arr[n++]=datos[(frente+c)%MAX];
    ofstream txt("salida.txt");txt<<"=== FILA DEQUE ARREGLOS STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Deque\",\"tipo\":\"string\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
