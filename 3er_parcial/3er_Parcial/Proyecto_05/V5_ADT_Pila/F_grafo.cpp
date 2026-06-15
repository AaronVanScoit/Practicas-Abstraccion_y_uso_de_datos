#include "Lib_grafo.h"
#include <climits>
Grafo::Grafo():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
void Grafo::pushNodo(Lugar l){pilaNodos.push(l);nodosArr[nNodos++]=l;cout<<"Push nodo: "<<l.etiqueta<<endl;}
Lugar Grafo::popNodo(){if(pilaNodos.empty()){Lugar l={-1,"VACIA"};return l;}Lugar l=pilaNodos.top();pilaNodos.pop();return l;}
void Grafo::agregarArista(int u,int v,float w){matAdj[u][v]=w;matAdj[v][u]=w;}
void Grafo::mostrar(){
    cout<<"=== GRAFO (ADT Pila de Lugares) | Tope: ";
    if(!pilaNodos.empty())cout<<pilaNodos.top().etiqueta;else cout<<"VACIA";
    cout<<" | Nodos: "<<nNodos<<" ==="<<endl;
    for(int i=0;i<nNodos;i++)cout<<"  ["<<nodosArr[i].id<<":"<<nodosArr[i].etiqueta<<"]"<<endl;
}
void Grafo::dijkstra(int origen){
    float dist[MAXN];bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=1e9;vis[i]=false;}
    dist[origen]=0;
    for(int c=0;c<nNodos-1;c++){
        int u=-1;float mn=1e9;
        for(int i=0;i<nNodos;i++)if(!vis[i]&&dist[i]<mn){mn=dist[i];u=i;}
        if(u==-1)break;vis[u]=true;
        for(int v=0;v<nNodos;v++)if(matAdj[u][v]>0&&!vis[v]&&dist[u]+matAdj[u][v]<dist[v])dist[v]=dist[u]+matAdj[u][v];
    }
    cout<<"Dijkstra desde "<<nodosArr[origen].etiqueta<<":"<<endl;
    for(int i=0;i<nNodos;i++)cout<<"  "<<nodosArr[i].etiqueta<<": "<<(dist[i]>=1e9?"INF":to_string(dist[i]))<<endl;
}
void Grafo::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(auto&c:conns){
        bool hayU=false,hayV=false;
        for(int i=0;i<nNodos;i++){if(nodosArr[i].id==c.nodoInicial)hayU=true;if(nodosArr[i].id==c.nodoFinal)hayV=true;}
        if(!hayU){Lugar l;l.id=c.nodoInicial;l.etiqueta="Lugar_"+to_string(c.nodoInicial);pushNodo(l);}
        if(!hayV){Lugar l;l.id=c.nodoFinal;l.etiqueta="Lugar_"+to_string(c.nodoFinal);pushNodo(l);}
        agregarArista(c.nodoInicial,c.nodoFinal,c.costo);aristas[nAristas++]=c;
    }
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Grafo::guardarSalidas(){
    vector<Lugar> nds(nodosArr,nodosArr+nNodos);
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Grafo_V5_ADT_Pila",nds,arr);
}
