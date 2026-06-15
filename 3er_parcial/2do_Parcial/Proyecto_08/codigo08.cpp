#include "codigo08.h"
static string datos[MAX]; static int frente=0,fin=0,tam=0;
bool ColaStr::estaVacia(){return tam==0;}
void ColaStr::enqueue(string val){if(tam==MAX){cout<<"Cola llena"<<endl;return;}datos[fin]=val;fin=(fin+1)%MAX;tam++;cout<<"Enqueue: "<<val<<endl;}
string ColaStr::dequeue(){if(estaVacia()){cout<<"Cola vacia"<<endl;return "";}string v=datos[frente];frente=(frente+1)%MAX;tam--;return v;}
string ColaStr::verFrente(){if(estaVacia()){cout<<"Vacia"<<endl;return "";}return datos[frente];}
void ColaStr::mostrar(){if(estaVacia()){cout<<"Cola vacia"<<endl;return;}cout<<"Cola: ";for(int c=0;c<tam;c++)cout<<"\""<<datos[(frente+c)%MAX]<<"\" ";cout<<endl;}
void ColaStr::guardarSalidas(){
    string arr[MAX];int n=0;for(int c=0;c<tam;c++)arr[n++]=datos[(frente+c)%MAX];
    ofstream txt("salida.txt");txt<<"=== COLA ARREGLOS STRING ==="<<endl;for(int i=0;i<n;i++)txt<<arr[i]<<"\n";txt.close();
    ofstream csv("salida.csv");csv<<"posicion,valor\n";for(int i=0;i<n;i++)csv<<i<<","<<arr[i]<<"\n";csv.close();
    ofstream json("salida.json");json<<"{\n  \"elementos\":[";for(int i=0;i<n;i++){json<<"\""<<arr[i]<<"\"";if(i<n-1)json<<",";}json<<"]\n}\n";json.close();
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola>\n";for(int i=0;i<n;i++)xml<<"  <elemento>"<<arr[i]<<"</elemento>\n";xml<<"</cola>\n";xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
