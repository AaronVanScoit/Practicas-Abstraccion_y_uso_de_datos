#include <iostream>
#include "codigo11.h"
using namespace std;

int main() {
    Promedio op; int numeros[5]; int *p;
    p = numeros;
    cout<<"Ingresa 5 Calif:\n";
    for(int i=0;i<5;i++){ cout<<"Calif:  "<<i+1<<": "; cin>>*(p+i); }
    int s=op.suma(p,5); float prom=op.promedio(p,5),m=op.media(p,5);
    int mx=op.maximo(p,5),mn=op.minimo(p,5);
    cout<<"\nResultados\nSuma: "<<s<<"\nPromedio: "<<prom<<"\nMedia: "<<m<<"\nMaximo: "<<mx<<"\nMinimo: "<<mn<<endl;
    op.guardarSalidas(p,5,s,prom,m,mx,mn);
    return 0;
}
