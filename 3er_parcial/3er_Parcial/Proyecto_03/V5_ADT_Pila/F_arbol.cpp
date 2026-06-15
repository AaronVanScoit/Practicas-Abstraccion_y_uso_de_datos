#include "Lib_arbol.h"
Arbol::Arbol():nNodos(0),raiz(-1),nAristas(0){}
void Arbol::insertar(Lugar l){
    int idx=nNodos;
    nodos[idx].dato=l;nodos[idx].izq=-1;nodos[idx].der=-1;nodos[idx].padre=-1;nNodos++;
    if(raiz==-1){raiz=idx;return;}
    int cur=raiz;
    while(true){
        if(l.id<nodos[cur].dato.id){if(nodos[cur].izq==-1){nodos[cur].izq=idx;nodos[idx].padre=cur;break;}else cur=nodos[cur].izq;}
        else{if(nodos[cur].der==-1){nodos[cur].der=idx;nodos[idx].padre=cur;break;}else cur=nodos[cur].der;}
    }
}
void Arbol::recorridoPila(){
    // Preorden iterativo con ADT Pila
    if(raiz==-1){cout<<"Arbol vacio"<<endl;return;}
    while(!pilaRecorrido.empty()) pilaRecorrido.pop();
    Lugar inicio=nodos[raiz].dato; pilaRecorrido.push(inicio);
    cout<<"Recorrido Preorden (ADT Pila): ";
    stack<int> s; s.push(raiz);
    while(!s.empty()){
        int u=s.top(); s.pop();
        pilaRecorrido.push(nodos[u].dato);
        cout<<"["<<nodos[u].dato.id<<":"<<nodos[u].dato.etiqueta<<"] ";
        if(nodos[u].der!=-1) s.push(nodos[u].der);
        if(nodos[u].izq!=-1) s.push(nodos[u].izq);
    }
    cout<<endl<<"Pila de recorrido (tope): "<<pilaRecorrido.top().etiqueta<<endl;
}
void Arbol::mostrar(){
    cout<<"=== ARBOL (ADT Pila) | Nodos: "<<nNodos<<" ==="<<endl;
    recorridoPila();
}
void Arbol::dijkstra(int origen){
    float dist[MAXN];bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=1e9;vis[i]=false;}
    dist[origen]=0;
    int cola[MAXN];int fr=0,fi=0;cola[fi++]=origen;vis[origen]=true;
    while(fr<fi){int u=cola[fr++];int vec[]={nodos[u].izq,nodos[u].der,nodos[u].padre};for(int k=0;k<3;k++){int v=vec[k];if(v!=-1&&!vis[v]){dist[v]=dist[u]+1;vis[v]=true;cola[fi++]=v;}}}
    cout<<"Dijkstra desde "<<nodos[origen].dato.etiqueta<<":"<<endl;
    for(int i=0;i<nNodos;i++) cout<<"  "<<nodos[i].dato.etiqueta<<": "<<(dist[i]>=1e9?"INF":to_string((int)dist[i]))<<endl;
}
void Arbol::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    nNodos=0;raiz=-1;
    bool existe[MAXN]={};
    for(auto&c:conns){existe[c.nodoInicial]=true;existe[c.nodoFinal]=true;}
    for(int i=0;i<MAXN;i++) if(existe[i]){Lugar l;l.id=i;l.etiqueta="Lugar_"+to_string(i);insertar(l);}
    for(auto&c:conns) aristas[nAristas++]=c;
    cout<<"Cargado con "<<nNodos<<" nodos."<<endl;
}
void Arbol::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<nNodos;i++) nds.push_back(nodos[i].dato);
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    if(nAristas==0) for(int i=0;i<nNodos;i++){
        if(nodos[i].izq!=-1){conexionNodo2Nodo c;c.nodoInicial=nodos[i].dato.id;c.nodoFinal=nodos[nodos[i].izq].dato.id;c.aristaConexion="izq";c.tiempo=1;c.costo=1;arr.push_back(c);}
        if(nodos[i].der!=-1){conexionNodo2Nodo c;c.nodoInicial=nodos[i].dato.id;c.nodoFinal=nodos[nodos[i].der].dato.id;c.aristaConexion="der";c.tiempo=1;c.costo=1;arr.push_back(c);}
    }
    guardarSalidaGrafo("Arbol_V5_ADT_Pila",nds,arr);
}
