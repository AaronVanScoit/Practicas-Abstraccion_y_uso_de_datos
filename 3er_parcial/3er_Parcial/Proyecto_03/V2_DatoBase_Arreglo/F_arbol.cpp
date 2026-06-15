#include "Lib_arbol.h"
Arbol::Arbol():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++){datos[i]=0;existe[i]=false;}}
void Arbol::insertar(int idx,int val){
    if(idx>=MAXN)return;
    datos[idx]=val; existe[idx]=true; nNodos++;
}
void Arbol::inorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    inorden(2*idx+1); cout<<datos[idx]<<" "; inorden(2*idx+2);
}
void Arbol::preorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    cout<<datos[idx]<<" "; preorden(2*idx+1); preorden(2*idx+2);
}
void Arbol::posorden(int idx){
    if(idx>=MAXN||!existe[idx])return;
    posorden(2*idx+1); posorden(2*idx+2); cout<<datos[idx]<<" ";
}
void Arbol::mostrar(){
    cout<<"=== ARBOL (int arreglo) | Nodos: "<<nNodos<<" ==="<<endl;
    cout<<"Arreglo: ";for(int i=0;i<MAXN;i++) if(existe[i]) cout<<"["<<i<<"]="<<datos[i]<<" ";cout<<endl;
    cout<<"Inorden:  "; inorden(0); cout<<endl;
    cout<<"Preorden: "; preorden(0); cout<<endl;
    cout<<"Posorden: "; posorden(0); cout<<endl;
}
void Arbol::dijkstra(int origen){
    // Distancias nivel a nivel en arreglo heap
    cout<<"Distancias desde indice "<<origen<<" (datos["<<origen<<"]="<<datos[origen]<<"):"<<endl;
    int dist[MAXN]; bool vis[MAXN];
    for(int i=0;i<MAXN;i++){dist[i]=INT_MAX;vis[i]=false;}
    dist[origen]=0;
    int cola[MAXN];int fr=0,fi=0;
    cola[fi++]=origen; vis[origen]=true;
    while(fr<fi){
        int u=cola[fr++];
        int vecinos[]={2*u+1,2*u+2,(u-1)/2};
        for(int k=0;k<3;k++){
            int v=vecinos[k];
            if(v>=0&&v<MAXN&&existe[v]&&!vis[v]){
                dist[v]=dist[u]+1; vis[v]=true; cola[fi++]=v;
            }
        }
    }
    for(int i=0;i<MAXN;i++) if(existe[i]) cout<<"  ["<<i<<"]="<<datos[i]<<": "<<(dist[i]==INT_MAX?"INF":to_string(dist[i]))<<endl;
}
void Arbol::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(int i=0;i<MAXN;i++){datos[i]=0;existe[i]=false;} nNodos=0;
    for(size_t i=0;i<conns.size();i++){
        if(!existe[conns[i].nodoInicial]){insertar(conns[i].nodoInicial,conns[i].nodoInicial);}
        if(!existe[conns[i].nodoFinal]){insertar(conns[i].nodoFinal,conns[i].nodoFinal);}
        aristas[nAristas++]=conns[i];
    }
    cout<<"Arbol cargado con "<<nNodos<<" nodos."<<endl;
}
void Arbol::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<MAXN;i++) if(existe[i]){Lugar l;l.id=i;l.etiqueta="Nodo["+to_string(i)+"]="+to_string(datos[i]);nds.push_back(l);}
    vector<conexionNodo2Nodo> arr;
    for(int i=0;i<MAXN;i++) if(existe[i]){
        if(2*i+1<MAXN&&existe[2*i+1]){conexionNodo2Nodo c;c.nodoInicial=i;c.nodoFinal=2*i+1;c.aristaConexion="izq";c.tiempo=1;c.costo=1;arr.push_back(c);}
        if(2*i+2<MAXN&&existe[2*i+2]){conexionNodo2Nodo c;c.nodoInicial=i;c.nodoFinal=2*i+2;c.aristaConexion="der";c.tiempo=1;c.costo=1;arr.push_back(c);}
    }
    guardarSalidaGrafo("Arbol_V2_DatoBase_Arreglo",nds,arr);
}
