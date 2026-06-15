#include <iostream>
#include "codigo4.h"
using namespace std;
int main(){PilaPtrStr p;int op;string v;
do{cout<<"\n=== PILA PUNTEROS STRING ===\n1.Push\n2.Pop\n3.Peek\n4.Mostrar\n5.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:cout<<"Texto: ";cin>>v;p.push(v);break;case 2:v=p.pop();if(!v.empty())cout<<"Pop: "<<v<<endl;break;
case 3:v=p.peek();if(!v.empty())cout<<"Tope: "<<v<<endl;break;case 4:p.mostrar();break;case 5:p.guardarSalidas();break;}}while(op!=0);return 0;}
