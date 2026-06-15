#include <iostream>
#include "codigo19.h"
using namespace std;
int main(){Ordenamiento o;int op;
do{cout<<"\n=== BUBBLE SORT ===\n1.Llenar arreglo\n2.Mostrar\n3.Ordenar\n4.Guardar\n0.Salir\nOpcion: ";cin>>op;
switch(op){case 1:o.llenarArreglo();break;case 2:o.mostrarArreglo();break;case 3:o.bubbleSort();break;case 4:o.guardarSalidas();break;}}while(op!=0);return 0;}
