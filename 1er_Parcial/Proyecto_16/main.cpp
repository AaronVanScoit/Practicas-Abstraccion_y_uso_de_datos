#include "codigo15.h"
#include <iostream>
using namespace std;

int main(){
    int n, d; 
    Codigo15 tri; 
    Codigos15 can; 
    cout << "Ingresa el Nivel del triángulo: " << endl; 
    cin  >> n;  
    cout << "Resultado para n = " << n << " es: " << tri.triangulo_cantor(n) << endl;
    cout << "Ingresa el Nivel de cantor: " << endl; 
    cin  >> n;  
    cout << "Ingresa el dimension de cantor: " << endl; 
    cin  >> d;  
    cout << "Elementos: " << can.triangulo_cantor(n, d) << endl;
    
}
