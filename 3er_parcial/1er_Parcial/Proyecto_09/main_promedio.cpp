#include <iostream>
#include "codigo9.h"
using namespace std;
int main() {
    Promedio op;
    int a,b,c,d,e;
    cout<<"Ingresa tus 5 calificaiones redondedadas (ej. 10,9,8)\n";
    cout<<"1er Calif:: "; cin>>a;
    cout<<"2nd Calif:: "; cin>>b;
    cout<<"3th Calif:: "; cin>>c;
    cout<<"4th Calif:: "; cin>>d;
    cout<<"5th Calif:: "; cin>>e;
    int s=op.suma(a,b,c,d,e);
    float p=op.promedio(a,b,c,d,e), m=op.media(a,b,c,d,e);
    int mx=op.maximo(a,b,c,d,e), mn=op.minimo(a,b,c,d,e);
    cout<<"\nResultados\nSuma: "<<s<<"\nPromedio: "<<p<<"\nMedia: "<<m<<"\nMaxima Calif: "<<mx<<"\nMinima Calif: "<<mn<<endl;
    op.guardarSalidas(a,b,c,d,e,s,p,m,mx,mn);
    return 0;
}
