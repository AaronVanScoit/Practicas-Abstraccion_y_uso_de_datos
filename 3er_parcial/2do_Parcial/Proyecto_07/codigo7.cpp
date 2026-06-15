#include "codigo7.h"

void Cola::enqueue(int val){
    if(estaLlena()){cout<<"Cola llena"<<endl;return;}
    datos[final_]=val; final_=(final_+1)%MAX_C; tam++;
    cout<<"Enqueue: "<<val<<endl;
}
int Cola::dequeue(){
    if(estaVacia()){cout<<"Cola vacia"<<endl;return -1;}
    int v=datos[frente]; frente=(frente+1)%MAX_C; tam--; return v;
}
int Cola::verFrente(){
    if(estaVacia()){cout<<"Cola vacia"<<endl;return -1;}
    return datos[frente];
}
void Cola::mostrar(){
    if(estaVacia()){cout<<"Cola vacia"<<endl;return;}
    cout<<"Cola (frente->final): ";
    for(int i=0;i<tam;i++) cout<<datos[(frente+i)%MAX_C]<<" ";
    cout<<endl;
}
void Cola::guardarSalida(){
    ofstream txt("salida.txt");txt<<"=== COLA ARREGLOS INT ==="<<endl;
    ofstream csv("salida.csv");csv<<"posicion,valor"<<endl;
    ofstream json("salida.json");json<<"{\n  \"tipo\": \"Cola-Arreglo-Int\",\n  \"elementos\": [";
    ofstream xml("salida.xml");xml<<"<?xml version=\"1.0\"?>\n<cola tipo=\"arreglo\" dato=\"int\">\n";
    bool first=true;
    for(int i=0;i<tam;i++){
        int v=datos[(frente+i)%MAX_C];
        txt<<v<<" ";csv<<i<<","<<v<<endl;
        if(!first)json<<",";json<<v;first=false;
        xml<<"  <elemento pos=\""<<i<<"\">"<<v<<"</elemento>\n";
    }
    txt<<endl;txt.close();csv.close();json<<"]\n}"<<endl;json.close();xml<<"</cola>"<<endl;xml.close();
    cout<<"Salida guardada."<<endl;
}
