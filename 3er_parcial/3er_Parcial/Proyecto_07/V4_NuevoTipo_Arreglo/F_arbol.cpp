#include "Lib_arbol.h"
Arbol::Arbol():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++)existe[i]=false;}
void Arbol::insertar(int idx,Lugar l){if(idx>=MAXN)return;nodosArr[idx]=l;existe[idx]=true;nNodos++;}
void Arbol::inorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    inorden(2*idx+1);
    cout<<"["<<nodosArr[idx].id<<":"<<nodosArr[idx].etiqueta<<"] ";
    inorden(2*idx+2);
}
void Arbol::preorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    cout<<"["<<nodosArr[idx].id<<":"<<nodosArr[idx].etiqueta<<"] ";
    preorden(2*idx+1);preorden(2*idx+2);
}
void Arbol::posorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    posorden(2*idx+1);posorden(2*idx+2);
    cout<<"["<<nodosArr[idx].id<<":"<<nodosArr[idx].etiqueta<<"] ";
}
void Arbol::mostrar(){
    cout<<"=== ARBOL (Lugar arreglo) | Nodos: "<<nNodos<<" ==="<<endl;
    cout<<"Inorden:  "; inorden(0); cout<<endl;
    cout<<"Preorden: "; preorden(0); cout<<endl;
    cout<<"Posorden: "; posorden(0); cout<<endl;
}
void Arbol::dijkstra(int origen){
    int dist[MAXN];bool vis[MAXN];
    for(int i=0;i<MAXN;i++){dist[i]=INT_MAX;vis[i]=false;}
    dist[origen]=0;
    int cola[MAXN];int fr=0,fi=0;cola[fi++]=origen;vis[origen]=true;
    while(fr<fi){
        int u=cola[fr++];
        int vec[]={2*u+1,2*u+2,(u-1)/2};
        for(int k=0;k<3;k++){int v=vec[k];if(v>=0&&v<MAXN&&existe[v]&&!vis[v]){dist[v]=dist[u]+1;vis[v]=true;cola[fi++]=v;}}
    }
    cout<<"Dijkstra desde ["<<origen<<"]"<<nodosArr[origen].etiqueta<<":"<<endl;
    for(int i=0;i<MAXN;i++) if(existe[i]) cout<<"  ["<<i<<"]"<<nodosArr[i].etiqueta<<": "<<(dist[i]==INT_MAX?"INF":to_string(dist[i]))<<endl;
}
void Arbol::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(int i=0;i<MAXN;i++)existe[i]=false; nNodos=0;
    for(size_t i=0;i<conns.size();i++){
        if(!existe[conns[i].nodoInicial]){Lugar l;l.id=conns[i].nodoInicial;l.etiqueta="Lugar_"+to_string(conns[i].nodoInicial);insertar(conns[i].nodoInicial,l);}
        if(!existe[conns[i].nodoFinal]){Lugar l;l.id=conns[i].nodoFinal;l.etiqueta="Lugar_"+to_string(conns[i].nodoFinal);insertar(conns[i].nodoFinal,l);}
        aristas[nAristas++]=conns[i];
    }
    cout<<"Arbol cargado con "<<nNodos<<" nodos."<<endl;
}
void Arbol::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<MAXN;i++) if(existe[i]) nds.push_back(nodosArr[i]);
    vector<conexionNodo2Nodo> arr;
    for(int i=0;i<MAXN;i++) if(existe[i]){
        if(2*i+1<MAXN&&existe[2*i+1]){conexionNodo2Nodo c;c.nodoInicial=nodosArr[i].id;c.nodoFinal=nodosArr[2*i+1].id;c.aristaConexion="izq";c.tiempo=1;c.costo=1;arr.push_back(c);}
        if(2*i+2<MAXN&&existe[2*i+2]){conexionNodo2Nodo c;c.nodoInicial=nodosArr[i].id;c.nodoFinal=nodosArr[2*i+2].id;c.aristaConexion="der";c.tiempo=1;c.costo=1;arr.push_back(c);}
    }
    guardarSalidaGrafo("Arbol_V4_NuevoTipo_Arreglo",nds,arr);
}
