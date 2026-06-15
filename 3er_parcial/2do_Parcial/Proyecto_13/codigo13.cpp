#include "codigo13.h"
Fila::Fila():frente(0),fin(0),tam(0){}
bool Fila::estaVacia(){return tam==0;}
bool Fila::estaLlena(){return tam==MAX;}
void Fila::insertarFrente(int val){if(estaLlena()){cout<<"Llena"<<endl;return;}frente=(frente-1+MAX)%MAX;datos[frente]=val;tam++;cout<<"InsertarFrente: "<<val<<endl;}
void Fila::insertarFinal(int val){if(estaLlena()){cout<<"Llena"<<endl;return;}datos[fin]=val;fin=(fin+1)%MAX;tam++;cout<<"InsertarFinal: "<<val<<endl;}
int Fila::eliminarFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}int v=datos[frente];frente=(frente+1)%MAX;tam--;return v;}
int Fila::eliminarFinal(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}fin=(fin-1+MAX)%MAX;int v=datos[fin];tam--;return v;}
int Fila::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}return datos[frente];}
int Fila::verFinal(){if(estaVacia()){cout<<"Vacia"<<endl;return -1;}return datos[(fin-1+MAX)%MAX];}
void Fila::mostrar(){if(estaVacia()){cout<<"Fila vacia"<<endl;return;}cout<<"Fila: ";for(int c=0;c<tam;c++)cout<<datos[(frente+c)%MAX]<<" ";cout<<endl;}
void Fila::guardarSalidas(){
    int arr[MAX];int n=0;for(int c=0;c<tam;c++)arr[n++]=datos[(frente+c)%MAX];
    ofstream txt("salida.txt");txt<<"=== FILA (DEQUE) ARREGLOS INT ==="<<endl<<"Elementos: ";for(int i=0;i<n;i++)txt<<arr[i]<<" ";txt<<endl;txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"estructura\":\"Deque\",\"implementacion\":\"arreglo\",\"tipo\":\"int\",\n  \"elementos\":[";for(int i=0;i<n;i++){json<<arr[i];if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<deque><implementacion>arreglo</implementacion><tipo>int</tipo><elementos>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</elementos></deque>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
