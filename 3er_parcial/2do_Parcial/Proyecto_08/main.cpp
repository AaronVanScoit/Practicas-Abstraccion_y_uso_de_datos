#include <iostream>
#include "codigo08.h"
using namespace std;
int main(){ColaStr c;int op;string v;
do{cout<<"\n=== COLA ARREGLOS STRING ===\n1.Enqueue\n2.Dequeue\n3.Frente\n4.Mostrar\n5.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:cout<<"Val: ";cin>>v;c.enqueue(v);break;case 2:v=c.dequeue();if(!v.empty())cout<<"Dequeue: "<<v<<endl;break;
case 3:v=c.verFrente();if(!v.empty())cout<<"Frente: "<<v<<endl;break;case 4:c.mostrar();break;case 5:c.guardarSalidas();break;}}while(op!=0);return 0;}
