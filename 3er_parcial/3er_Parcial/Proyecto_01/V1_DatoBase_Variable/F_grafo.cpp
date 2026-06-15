#include "Lib_grafo.h"
#include <climits>
Grafo::Grafo():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
void Grafo::agregarArista(int u,int v,float w){
    nNodos=max(nNodos,max(u,v)+1);
    matAdj[u][v]=(int)w; matAdj[v][u]=(int)w;
}
void Grafo::mostrar(){
    cout<<"=== GRAFO (int variable) | Nodos: "<<nNodos<<" ==="<<endl;
    for(int i=0;i<nNodos;i++){for(int j=0;j<nNodos;j++)cout<<matAdj[i][j]<<"\t";cout<<endl;}
}
void Grafo::dijkstra(int origen){
    int dist[MAXN]; bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=INT_MAX;vis[i]=false;}
    dist[origen]=0;
    for(int c=0;c<nNodos-1;c++){
        int u=-1,mn=INT_MAX;
        for(int i=0;i<nNodos;i++) if(!vis[i]&&dist[i]<mn){mn=dist[i];u=i;}
        if(u==-1)break; vis[u]=true;
        for(int v=0;v<nNodos;v++)
            if(matAdj[u][v]&&!vis[v]&&dist[u]+matAdj[u][v]<dist[v]) dist[v]=dist[u]+matAdj[u][v];
    }
    cout<<"Dijkstra desde "<<origen<<":"<<endl;
    for(int i=0;i<nNodos;i++) cout<<"  Nodo "<<i<<": "<<(dist[i]==INT_MAX?"INF":to_string(dist[i]))<<endl;
}
void Grafo::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(auto&c:conns){agregarArista(c.nodoInicial,c.nodoFinal,c.costo);aristas[nAristas++]=c;}
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Grafo::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<nNodos;i++){Lugar l;l.id=i;l.etiqueta="Nodo_"+to_string(i);nds.push_back(l);}
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Grafo_V1_DatoBase_Variable",nds,arr);
}
