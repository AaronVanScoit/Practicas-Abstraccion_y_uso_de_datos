#include <iostream>
#include "codigo1.h"
using namespace std;
int main(){
    Pila p; int opcion, val;
    do {
        cout<<"\n=== PILA (ARREGLOS - INT) ===\n1.Push\n2.Pop\n3.Peek\n4.Mostrar\n5.Guardar salidas\n0.Salir\nOpcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: cout<<"Valor: ";cin>>val; p.push(val); break;
            case 2: val=p.pop(); if(val!=-1) cout<<"Pop: "<<val<<endl; break;
            case 3: val=p.peek(); if(val!=-1) cout<<"Tope: "<<val<<endl; break;
            case 4: p.mostrar(); break;
            case 5: p.guardarSalidas(); break;
        }
    } while(opcion!=0);
    return 0;
}
