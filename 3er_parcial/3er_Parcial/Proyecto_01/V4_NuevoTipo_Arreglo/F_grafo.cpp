#include "Lib_grafo.h"
#include <climits>
Grafo::Grafo():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
void Grafo::agregarNodo(Lugar l){nodosArr[nNodos++]=l;}
int Grafo::buscarNodo(int id){for(int i=0;i<nNodos;i++)if(nodosArr[i].id==id)return i;return -1;}
void Grafo::agregarArista(int u,int v,float w){matAdj[u][v]=w;matAdj[v][u]=w;}
void Grafo::mostrar(){
    cout<<"=== GRAFO (Lugar arreglo) ==="<<endl;
    cout<<"Nodos["<<nNodos<<"]: ";for(int i=0;i<nNodos;i++)cout<<"["<<nodosArr[i].id<<":"<<nodosArr[i].etiqueta<<"] ";cout<<endl;
    cout<<"Matriz:"<<endl;for(int i=0;i<nNodos;i++){for(int j=0;j<nNodos;j++)cout<<matAdj[i][j]<<"\t";cout<<endl;}
}
void Grafo::dijkstra(int origen){
    float dist[MAXN]; bool vis[MAXN];
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
        if(buscarNodo(c.nodoInicial)<0){Lugar l;l.id=c.nodoInicial;l.etiqueta="Nodo_"+to_string(c.nodoInicial);agregarNodo(l);}
        if(buscarNodo(c.nodoFinal)<0){Lugar l;l.id=c.nodoFinal;l.etiqueta="Nodo_"+to_string(c.nodoFinal);agregarNodo(l);}
        int u=buscarNodo(c.nodoInicial),v=buscarNodo(c.nodoFinal);
        agregarArista(u,v,c.costo);aristas[nAristas++]=c;
    }
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Grafo::guardarSalidas(){
    vector<Lugar> nds(nodosArr,nodosArr+nNodos);
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Grafo_V4_NuevoTipo_Arreglo",nds,arr);
}
