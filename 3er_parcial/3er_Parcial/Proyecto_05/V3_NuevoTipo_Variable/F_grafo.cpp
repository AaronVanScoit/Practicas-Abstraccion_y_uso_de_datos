#include "Lib_grafo.h"
#include <climits>
Grafo::Grafo():nNodos(0),nAristas(0){nodo={0,"Ninguno"};for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
void Grafo::agregarNodo(Lugar l){nodosLista[nNodos++]=l;nodo=l;}
void Grafo::agregarArista(int u,int v,float w,string nombre,float t){
    while(nNodos<=max(u,v)){Lugar l;l.id=nNodos;l.etiqueta="Nodo_"+to_string(nNodos);agregarNodo(l);}
    matAdj[u][v]=w; matAdj[v][u]=w;
}
void Grafo::mostrar(){
    cout<<"=== GRAFO (Lugar variable) | Ultimo nodo: ID="<<nodo.id<<" Etiqueta="<<nodo.etiqueta<<" ==="<<endl;
    cout<<"Nodos: ";for(int i=0;i<nNodos;i++)cout<<"["<<nodosLista[i].id<<":"<<nodosLista[i].etiqueta<<"] ";cout<<endl;
    cout<<"Matriz de adyacencia:"<<endl;
    for(int i=0;i<nNodos;i++){for(int j=0;j<nNodos;j++)cout<<matAdj[i][j]<<"\t";cout<<endl;}
}
void Grafo::dijkstra(int origen){
    float dist[MAXN]; bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=1e9;vis[i]=false;}
    dist[origen]=0;
    for(int c=0;c<nNodos-1;c++){
        int u=-1; float mn=1e9;
        for(int i=0;i<nNodos;i++) if(!vis[i]&&dist[i]<mn){mn=dist[i];u=i;}
        if(u==-1)break; vis[u]=true;
        for(int v=0;v<nNodos;v++) if(matAdj[u][v]>0&&!vis[v]&&dist[u]+matAdj[u][v]<dist[v]) dist[v]=dist[u]+matAdj[u][v];
    }
    cout<<"Dijkstra desde "<<nodosLista[origen].etiqueta<<":"<<endl;
    for(int i=0;i<nNodos;i++) cout<<"  "<<nodosLista[i].etiqueta<<": "<<(dist[i]>=1e9?"INF":to_string(dist[i]))<<endl;
}
void Grafo::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(auto&c:conns){agregarArista(c.nodoInicial,c.nodoFinal,c.costo,c.aristaConexion,c.tiempo);aristas[nAristas++]=c;}
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Grafo::guardarSalidas(){
    vector<Lugar> nds(nodosLista,nodosLista+nNodos);
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Grafo_V3_NuevoTipo_Variable",nds,arr);
}
