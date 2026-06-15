#include <iostream>
#include "codigo11.h"
using namespace std;
int main(){ColaLib c;int op,v;
do{cout<<"\n=== COLA STL INT ===\n1.Enqueue\n2.Dequeue\n3.Frente\n4.Mostrar\n5.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:cout<<"Val: ";cin>>v;c.enqueue(v);break;case 2:v=c.dequeue();if(v!=-1)cout<<"Dequeue: "<<v<<endl;break;
case 3:v=c.verFrente();if(v!=-1)cout<<"Frente: "<<v<<endl;break;case 4:c.mostrar();break;case 5:c.guardarSalidas();break;}}while(op!=0);return 0;}
