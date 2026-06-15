#include "codigo16.h"

void Fractales::sierpinski(int n) {
    if(n==0){ cout<<"*"; return; }
    sierpinski(n-1); cout<<" "; sierpinski(n-1); cout<<endl;
    for(int i=0;i<(1<<(n-1));i++) cout<<"* ";
    cout<<endl;
}
void Fractales::cantor(int n, int len) {
    if(n==0) return;
    for(int i=0;i<len;i++) cout<<"- ";
    cout<<endl;
    cantor(n-1, len/3);
    cout<<endl;
    cantor(n-1, len/3);
}
void Fractales::guardarSalidas(int n) {
    ofstream txt("salida.txt"); txt<<"=== FRACTALES ==="<<endl;
    txt<<"Nivel: "<<n<<"\nTriangulo Sierpinski y Polvo de Cantor generados en consola."<<endl; txt.close();
    ofstream csv("salida.csv"); csv<<"fractal,nivel\nSierpinski,"<<n<<"\nCantor,"<<n<<endl; csv.close();
    ofstream json("salida.json"); json<<"{\n  \"fractales\":[{\"nombre\":\"Sierpinski\",\"nivel\":"<<n<<"},{\"nombre\":\"Cantor\",\"nivel\":"<<n<<"}]\n}"<<endl; json.close();
    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<fractales>\n  <fractal><nombre>Sierpinski</nombre><nivel>"<<n<<"</nivel></fractal>\n";
    xml<<"  <fractal><nombre>Cantor</nombre><nivel>"<<n<<"</nivel></fractal>\n</fractales>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
