#include <iostream>
#include "codigo5.h"
using namespace std;
int main() {
    CalculadoraAvanzada op;
    int a, b, opcion; float resultado = 0; string sOp = "";
    cout << "CALCULADORA BASICA\n1.Suma\n2.Resta\n3.Multiplicacion\n4.Division\n5.Potencia\n6.Modulo\n";
    cout << "Selecciona una opcion: "; cin >> opcion;
    cout << "Ingresa el primer numero: ";  cin >> a;
    cout << "Ingresa el segundo numero: "; cin >> b;
    if(opcion==1){sOp="Suma";           resultado=op.suma(a,b);}
    else if(opcion==2){sOp="Resta";     resultado=op.resta(a,b);}
    else if(opcion==3){sOp="Mult";      resultado=op.multiplicacion(a,b);}
    else if(opcion==4){sOp="Division";  resultado=op.division(a,b);}
    else if(opcion==5){sOp="Potencia";  resultado=op.potencia(a,b);}
    else if(opcion==6){sOp="Modulo";    resultado=op.modulo(a,b);}
    cout << "Resultado: " << resultado << endl;
    op.guardarSalidas(sOp, a, b, resultado);
    return 0;
}
