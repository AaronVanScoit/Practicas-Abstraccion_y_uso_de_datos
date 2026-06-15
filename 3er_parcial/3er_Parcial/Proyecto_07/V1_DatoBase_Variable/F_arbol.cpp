#include "Lib_arbol.h"
#include <climits>

Arbol::Arbol():nNodos(0),raiz(-1),nAristas(0){}

void Arbol::insertar(int val){
    int idx=nNodos;
    nodos[idx].dato=val; nodos[idx].izq=-1; nodos[idx].der=-1; nodos[idx].padre=-1;
    nNodos++;
    if(raiz==-1){raiz=idx;return;}
    int cur=raiz;
    while(true){
        if(val<nodos[cur].dato){
            if(nodos[cur].izq==-1){nodos[cur].izq=idx;nodos[idx].padre=cur;break;}
            else cur=nodos[cur].izq;
        } else {
            if(nodos[cur].der==-1){nodos[cur].der=idx;nodos[idx].padre=cur;break;}
            else cur=nodos[cur].der;
        }
    }
}

void Arbol::inorden(int idx){
    if(idx==-1)return;
    inorden(nodos[idx].izq);
    cout<<nodos[idx].dato<<" ";
    inorden(nodos[idx].der);
}
void Arbol::preorden(int idx){
    if(idx==-1)return;
    cout<<nodos[idx].dato<<" ";
    preorden(nodos[idx].izq);
    preorden(nodos[idx].der);
}
void Arbol::posorden(int idx){
    if(idx==-1)return;
    posorden(nodos[idx].izq);
    posorden(nodos[idx].der);
    cout<<nodos[idx].dato<<" ";
}

void Arbol::mostrar(){
    cout<<"=== ARBOL BST (int variable) | Nodos: "<<nNodos<<" ==="<<endl;
    cout<<"Inorden:   "; inorden(raiz); cout<<endl;
    cout<<"Preorden:  "; preorden(raiz); cout<<endl;
    cout<<"Posorden:  "; posorden(raiz); cout<<endl;
}

void Arbol::dijkstra(int origen){
    // En arbol: camino mas corto es el camino unico (sin ciclos)
    // Usamos BFS con distancias desde raiz
    float dist[MAXN]; bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=1e9;vis[i]=false;}
    dist[origen]=0;
    // Cola BFS simple
    int cola[MAXN]; int frente=0,fin=0;
    cola[fin++]=origen; vis[origen]=true;
    while(frente<fin){
        int u=cola[frente++];
        int vecinos[]={nodos[u].izq,nodos[u].der,nodos[u].padre};
        float pesos[]={1.0f,1.0f,1.0f};
        for(int k=0;k<3;k++){
            int v=vecinos[k];
            if(v!=-1&&!vis[v]){
                dist[v]=dist[u]+pesos[k];
                vis[v]=true; cola[fin++]=v;
            }
        }
    }
    cout<<"Dijkstra (BFS) desde nodo["<<origen<<"]="<<nodos[origen].dato<<":"<<endl;
    for(int i=0;i<nNodos;i++)
        cout<<"  Nodo["<<i<<"]="<<nodos[i].dato<<": "<<(dist[i]>=1e9?"INF":to_string((int)dist[i]))<<endl;
}

void Arbol::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    // Reconstruir arbol desde conexiones (nodoFinal es hijo de nodoInicial)
    nNodos=0; raiz=-1;
    // Primero determinar nodos unicos
    bool existe[MAXN]={};
    for(auto&c:conns){
        if(!existe[c.nodoInicial]){existe[c.nodoInicial]=true;}
        if(!existe[c.nodoFinal]){existe[c.nodoFinal]=true;}
    }
    for(int i=0;i<MAXN;i++) if(existe[i]) insertar(i);
    for(auto&c:conns) aristas[nAristas++]=c;
    cout<<"Arbol cargado con "<<nNodos<<" nodos."<<endl;
}

void Arbol::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<nNodos;i++){Lugar l;l.id=i;l.etiqueta="Nodo_"+to_string(nodos[i].dato);nds.push_back(l);}
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    // Generar aristas desde estructura si no hay
    if(nAristas==0){
        for(int i=0;i<nNodos;i++){
            if(nodos[i].izq!=-1){conexionNodo2Nodo c;c.nodoInicial=i;c.nodoFinal=nodos[i].izq;c.aristaConexion="padre-hijoIzq";c.tiempo=1;c.costo=1;arr.push_back(c);}
            if(nodos[i].der!=-1){conexionNodo2Nodo c;c.nodoInicial=i;c.nodoFinal=nodos[i].der;c.aristaConexion="padre-hijoDer";c.tiempo=1;c.costo=1;arr.push_back(c);}
        }
    }
    guardarSalidaGrafo("Arbol_V1_DatoBase_Variable",nds,arr);
}
