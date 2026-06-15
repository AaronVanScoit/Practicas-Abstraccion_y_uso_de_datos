#include <iostream>
#include "codigo6.h"
using namespace std;
int main() {
    CalculadoraNueva op;
    int a, b, opcion; float resultado = 0; string sOp = "";
    cout << "CALCULADORA BASICA\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n";
    cout << "Selecciona una opcion: "; cin >> opcion;
    cout << "Ingresa el primer numero: ";  cin >> a;
    cout << "Ingresa el segundo numero: "; cin >> b;
    if(opcion==1){sOp="Suma";         resultado=op.suma(a,b);}
    else if(opcion==2){sOp="Resta";   resultado=op.resta(a,b);}
    else if(opcion==3){sOp="Mult";    resultado=op.multiplicacion(a,b);}
    else if(opcion==4){sOp="Division";resultado=op.division(a,b);}
    cout << "Resultado: " << resultado << endl;
    op.guardarSalidas(sOp, a, b, resultado);
    return 0;
}
