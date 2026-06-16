#ifndef TIPOS_COMUNES_H
#define TIPOS_COMUNES_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
using namespace std;

// Tipo de dato del nodo
struct Lugar {
    int id;
    string etiqueta;
};

// Conexion entre nodos (arista)
struct conexionNodo2Nodo {
    int nodoInicial;
    int nodoFinal;
    string aristaConexion;
    float tiempo;
    float costo;
};

// Leer conexiones desde XML
inline vector<conexionNodo2Nodo> leerDesdeXML(const string& archivo) {
    vector<conexionNodo2Nodo> conexiones;
    ifstream f(archivo);
    if(!f.is_open()){cout<<"[ERROR] No se pudo abrir "<<archivo<<endl;return conexiones;}
    string linea;
    conexionNodo2Nodo c;
    bool enConexion=false;
    while(getline(f,linea)){
        if(linea.find("<conexionNodo2Nodo>")!=string::npos){enConexion=true;c={};}
        else if(linea.find("</conexionNodo2Nodo>")!=string::npos){if(enConexion)conexiones.push_back(c);enConexion=false;}
        else if(enConexion){
            auto ext=[&](string tag)->string{
                string open="<"+tag+">",close="</"+tag+">";
                size_t s=linea.find(open),e=linea.find(close);
                if(s!=string::npos&&e!=string::npos)return linea.substr(s+open.size(),e-s-open.size());
                return "";
            };
            string v;
            if(!(v=ext("nodoInicial")).empty())c.nodoInicial=stoi(v);
            if(!(v=ext("nodoFinal")).empty())c.nodoFinal=stoi(v);
            if(!(v=ext("aristaConexion")).empty())c.aristaConexion=v;
            if(!(v=ext("tiempo")).empty())c.tiempo=stof(v);
            if(!(v=ext("costo")).empty())c.costo=stof(v);
        }
    }
    f.close();
    return conexiones;
}

// Leer conexiones desde JSON
inline vector<conexionNodo2Nodo> leerDesdeJSON(const string& archivo) {
    vector<conexionNodo2Nodo> conexiones;
    ifstream f(archivo);
    if(!f.is_open()){cout<<"[ERROR] No se pudo abrir "<<archivo<<endl;return conexiones;}
    string content((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());
    f.close();
    // Parse simple: buscar bloques {}
    size_t pos=0;
    while((pos=content.find("{",pos))!=string::npos){
        size_t end=content.find("}",pos);
        if(end==string::npos)break;
        string bloque=content.substr(pos,end-pos+1);
        conexionNodo2Nodo c; bool valid=false;
        auto ext=[&](string key)->string{
            size_t k=bloque.find("\""+key+"\"");
            if(k==string::npos)return "";
            size_t col=bloque.find(":",k);
            if(col==string::npos)return "";
            size_t vs=col+1;
            while(vs<bloque.size()&&(bloque[vs]==' '||bloque[vs]=='\t'||bloque[vs]=='\n'))vs++;
            if(bloque[vs]=='"'){
                size_t ve=bloque.find("\"",vs+1);
                return bloque.substr(vs+1,ve-vs-1);
            } else {
                size_t ve=vs;
                while(ve<bloque.size()&&bloque[ve]!=','&&bloque[ve]!='}')ve++;
                return bloque.substr(vs,ve-vs);
            }
        };
        string v;
        if(!(v=ext("nodoInicial")).empty()){c.nodoInicial=stoi(v);valid=true;}
        if(!(v=ext("nodoFinal")).empty())c.nodoFinal=stoi(v);
        if(!(v=ext("aristaConexion")).empty())c.aristaConexion=v;
        if(!(v=ext("tiempo")).empty())c.tiempo=stof(v);
        if(!(v=ext("costo")).empty())c.costo=stof(v);
        if(valid)conexiones.push_back(c);
        pos=end+1;
    }
    return conexiones;
}

// Guardar 4 formatos
inline void guardarSalidaGrafo(const string& titulo, const vector<Lugar>& nodos, const vector<conexionNodo2Nodo>& aristas) {
    // TXT
    ofstream txt("salida.txt");
    txt<<"=== "<<titulo<<" ==="<<endl;
    txt<<"NODOS:"<<endl;
    for(auto& n:nodos) txt<<"  ID:"<<n.id<<" Etiqueta:"<<n.etiqueta<<endl;
    txt<<"ARISTAS:"<<endl;
    for(auto& a:aristas) txt<<"  "<<a.nodoInicial<<" -["<<a.aristaConexion<<"]-> "<<a.nodoFinal<<" | t:"<<a.tiempo<<" c:"<<a.costo<<endl;
    txt.close();
    // CSV
    ofstream csv("salida.csv");
    csv<<"tipo,id,etiqueta,nodoInicial,nodoFinal,arista,tiempo,costo"<<endl;
    for(auto& n:nodos) csv<<"nodo,"<<n.id<<","<<n.etiqueta<<",,,,,\n";
    for(auto& a:aristas) csv<<"arista,,,"<<a.nodoInicial<<","<<a.nodoFinal<<","<<a.aristaConexion<<","<<a.tiempo<<","<<a.costo<<"\n";
    csv.close();
    // JSON
    ofstream json("salida.json");
    json<<"{\n  \"grafo\":\""<<titulo<<"\",\n  \"nodos\":[\n";
    for(size_t i=0;i<nodos.size();i++){json<<"    {\"id\":"<<nodos[i].id<<",\"etiqueta\":\""<<nodos[i].etiqueta<<"\"}";if(i<nodos.size()-1)json<<",";json<<"\n";}
    json<<"  ],\n  \"aristas\":[\n";
    for(size_t i=0;i<aristas.size();i++){
        json<<"    {\"nodoInicial\":"<<aristas[i].nodoInicial<<",\"nodoFinal\":"<<aristas[i].nodoFinal;
        json<<",\"arista\":\""<<aristas[i].aristaConexion<<"\",\"tiempo\":"<<aristas[i].tiempo<<",\"costo\":"<<aristas[i].costo<<"}";
        if(i<aristas.size()-1)json<<",";json<<"\n";
    }
    json<<"  ]\n}"<<endl;
    json.close();
    // XML
    ofstream xml("salida.xml");
    xml<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<grafo nombre=\""<<titulo<<"\">\n  <nodos>\n";
    for(auto& n:nodos) xml<<"    <nodo><id>"<<n.id<<"</id><etiqueta>"<<n.etiqueta<<"</etiqueta></nodo>\n";
    xml<<"  </nodos>\n  <aristas>\n";
    for(auto& a:aristas){
        xml<<"    <conexionNodo2Nodo>\n";
        xml<<"      <nodoInicial>"<<a.nodoInicial<<"</nodoInicial>\n";
        xml<<"      <nodoFinal>"<<a.nodoFinal<<"</nodoFinal>\n";
        xml<<"      <aristaConexion>"<<a.aristaConexion<<"</aristaConexion>\n";
        xml<<"      <tiempo>"<<a.tiempo<<"</tiempo>\n";
        xml<<"      <costo>"<<a.costo<<"</costo>\n";
        xml<<"    </conexionNodo2Nodo>\n";
    }
    xml<<"  </aristas>\n</grafo>"<<endl;
    xml.close();
    cout<<"[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]"<<endl;
}

#endif
