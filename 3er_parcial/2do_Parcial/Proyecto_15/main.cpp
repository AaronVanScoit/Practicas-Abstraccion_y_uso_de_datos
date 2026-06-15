#include <iostream>
#include "codigo15.h"
using namespace std;
int main(){FilaPtr f;int op,v;
do{cout<<"\n=== FILA DEQUE PUNTEROS INT ===\n1.InsFrente\n2.InsFinal\n3.ElimFrente\n4.ElimFinal\n5.VerFrente\n6.VerFinal\n7.Mostrar\n8.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:cout<<"Val: ";cin>>v;f.insertarFrente(v);break;case 2:cout<<"Val: ";cin>>v;f.insertarFinal(v);break;
case 3:v=f.eliminarFrente();if(v!=-1)cout<<"ElimFrente: "<<v<<endl;break;case 4:v=f.eliminarFinal();if(v!=-1)cout<<"ElimFinal: "<<v<<endl;break;
case 5:v=f.verFrente();if(v!=-1)cout<<"Frente: "<<v<<endl;break;case 6:v=f.verFinal();if(v!=-1)cout<<"Final: "<<v<<endl;break;
case 7:f.mostrar();break;case 8:f.guardarSalidas();break;}}while(op!=0);return 0;}
