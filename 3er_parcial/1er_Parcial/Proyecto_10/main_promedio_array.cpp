#include <iostream>
#include "codigo10.h"
using namespace std;

int main() {
    Promedio op; int numeros[5];
    cout<<"Ingresa 5 Calif:\n";
    for(int i=0;i<5;i++){ cout<<"Calif: "<<i+1<<": "; cin>>numeros[i]; }
    int s=op.suma(numeros,5); float p=op.promedio(numeros,5),m=op.media(numeros,5);
    int mx=op.maximo(numeros,5),mn=op.minimo(numeros,5);
    cout<<"\nResultados\nSuma: "<<s<<"\nPromedio: "<<p<<"\nMedia: "<<m<<"\nMaximo: "<<mx<<"\nMinimo: "<<mn<<endl;
    op.guardarSalidas(numeros,5,s,p,m,mx,mn);
    return 0;
}
