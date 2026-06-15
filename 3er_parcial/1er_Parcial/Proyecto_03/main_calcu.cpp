#include <iostream>
#include "codigo3.h"
using namespace std;
int main() {
    Calculadora op;
    int a, b, opcion;
    cout << "CALCULADORA BASICA" << endl;
    cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division" << endl;
    cout << "Selecciona una opcion: "; cin >> opcion;
    cout << "Ingresa el primer numero: ";  cin >> a;
    cout << "Ingresa el segundo numero: "; cin >> b;
    float resultado = 0;
    if(opcion==1) resultado = op.suma(a,b);
    else if(opcion==2) resultado = op.resta(a,b);
    else if(opcion==3) resultado = op.multiplicacion(a,b);
    else if(opcion==4) resultado = op.division(a,b);
    cout << "Resultado: " << resultado << endl;
    op.guardarSalidas(opcion, a, b, resultado);
    return 0;
}
