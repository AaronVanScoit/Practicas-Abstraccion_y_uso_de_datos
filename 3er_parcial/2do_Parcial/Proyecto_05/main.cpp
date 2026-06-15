#include <iostream>
#include "codigo5.h"
using namespace std;
int main(){PilaLib p;int op,v;
do{cout<<"\n=== PILA STL INT ===\n1.Push\n2.Pop\n3.Peek\n4.Mostrar\n5.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:cout<<"Valor: ";cin>>v;p.push(v);break;case 2:v=p.pop();if(v!=-1)cout<<"Pop: "<<v<<endl;break;
case 3:v=p.peek();if(v!=-1)cout<<"Tope: "<<v<<endl;break;case 4:p.mostrar();break;case 5:p.guardarSalidas();break;}}while(op!=0);return 0;}
