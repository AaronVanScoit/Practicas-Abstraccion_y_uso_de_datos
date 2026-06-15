#include "Lib_digrafo.h"
Digrafo::Digrafo():nNodos(0),nAristas(0){for(int i=0;i<MAXN;i++)for(int j=0;j<MAXN;j++)matAdj[i][j]=0;}
void Digrafo::insertarNodo(Lugar l){listaNodos.push_back(l);nodosArr[nNodos++]=l;cout<<"Insertado: "<<l.etiqueta<<endl;}
void Digrafo::eliminarNodo(int id){listaNodos.remove_if([id](Lugar l){return l.id==id;});}
void Digrafo::agregarArista(int u,int v,float w){matAdj[u][v]=w;}
void Digrafo::mostrar(){
    cout<<"=== DIGRAFO (ADT Lista) | Nodos["<<listaNodos.size()<<"]: "<<endl;
    for(auto&l:listaNodos)cout<<"  ["<<l.id<<":"<<l.etiqueta<<"]"<<endl;
    for(int i=0;i<nAristas;i++) cout<<"  "<<aristas[i].nodoInicial<<" --> "<<aristas[i].nodoFinal<<" costo:"<<aristas[i].costo<<endl;
}
void Digrafo::dijkstra(int origen){
    float dist[MAXN];bool vis[MAXN];
    for(int i=0;i<nNodos;i++){dist[i]=1e9;vis[i]=false;}
    dist[origen]=0;
    for(int c=0;c<nNodos-1;c++){
        int u=-1;float mn=1e9;
        for(int i=0;i<nNodos;i++) if(!vis[i]&&dist[i]<mn){mn=dist[i];u=i;}
        if(u==-1)break;vis[u]=true;
        for(int v=0;v<nNodos;v++) if(matAdj[u][v]>0&&!vis[v]&&dist[u]+matAdj[u][v]<dist[v]) dist[v]=dist[u]+matAdj[u][v];
    }
    cout<<"Dijkstra desde "<<nodosArr[origen].etiqueta<<":"<<endl;
    for(int i=0;i<nNodos;i++) cout<<"  "<<nodosArr[i].etiqueta<<": "<<(dist[i]>=1e9?"INF":to_string(dist[i]))<<endl;
}
void Digrafo::cargar(string arch,string fmt){
    vector<conexionNodo2Nodo> conns=(fmt=="xml")?leerDesdeXML(arch):leerDesdeJSON(arch);
    for(auto&c:conns){
        bool hayU=false,hayV=false;
        for(auto&n:listaNodos){if(n.id==c.nodoInicial)hayU=true;if(n.id==c.nodoFinal)hayV=true;}
        if(!hayU){Lugar l;l.id=c.nodoInicial;l.etiqueta="Lugar_"+to_string(c.nodoInicial);insertarNodo(l);}
        if(!hayV){Lugar l;l.id=c.nodoFinal;l.etiqueta="Lugar_"+to_string(c.nodoFinal);insertarNodo(l);}
        matAdj[c.nodoInicial][c.nodoFinal]=c.costo;aristas[nAristas++]=c;
    }
    cout<<"Cargadas "<<conns.size()<<" conexiones."<<endl;
}
void Digrafo::guardarSalidas(){
    vector<Lugar> nds(listaNodos.begin(),listaNodos.end());
    vector<conexionNodo2Nodo> arr(aristas,aristas+nAristas);
    guardarSalidaGrafo("Digrafo_V7_ADT_Lista",nds,arr);
}
