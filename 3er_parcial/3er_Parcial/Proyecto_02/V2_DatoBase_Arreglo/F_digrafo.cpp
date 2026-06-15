#include "Lib_digrafo.h"
#include <climits>
Digrafo::Digrafo():nNodos(0),nAristas(0){
    for(int i=0;i<MAXN;i++){nodosArr[i]=-1;for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
}
void Digrafo::agregarArista(int u,int v,float w){
    while(nNodos<=max(u,v)){nodosArr[nNodos]=nNodos;nNodos++;}
    matAdj[u][v]=(int)w;
}
void Digrafo::mostrar(){
    cout<<"=== DIGRAFO (int arreglo) | Nodos: [";
    for(int i=0;i<nNodos;i++){cout<<nodosArr[i];if(i<nNodos-1)cout<<",";}cout<<"] ==="<<endl;
    for(int i=0;i<nNodos;i++){for(int j=0;j<nNodos;j++)cout<<matAdj[i][j]<<"\t";cout<<endl;}
    for(int i=0;i<nAristas;i++)
        cout<<"  "<<aristas[i].nodoInicial<<" --> "<<aristas[i].nodoFinal<<" costo:"<<aristas[i].costo<<endl;
}
void Digrafo::dijkstra(int origen){
    int dist[MAXN];bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=INT_MAX;vis[i]=false;}
    dist[origen]=0;
    for(int c=0;c<nNodos-1;c++){
        int u=-1,mn=INT_MAX;
        for(int i=0;i<nNodos;i++) if(!vis[i]&&dist[i]<mn){mn=dist[i];u=i;}
        if(u==-1)break;vis[u]=true;
        for(int v=0;v<nNodos;v++)
            if(matAdj[u][v]&&!vis[v]&&dist[u]!=INT_MAX&&dist[u]+matAdj[u][v]<dist[v])
                dist[v]=dist[u]+matAdj[u][v];
    }
    cout<<"Dijkstra desde "<<origen<<":"<<endl;
    for(int i=0;i<nNodos;i++)
        cout<<"  Nodo "<<nodosArr[i]<<": "<<(dist[i]==INT_MAX?"INF":to_string(dist[i]))<<endl;
}
void Digrafo::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(auto&c:conns){agregarArista(c.nodoInicial,c.nodoFinal,c.costo);aristas[nAristas++]=c;}
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Digrafo::guardarSalidas(){
    vector<Lugar> nds;
    for(int i=0;i<nNodos;i++){Lugar l;l.id=nodosArr[i];l.etiqueta="Nodo_"+to_string(nodosArr[i]);nds.push_back(l);}
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Digrafo_V2_DatoBase_Arreglo",nds,arr);
}
