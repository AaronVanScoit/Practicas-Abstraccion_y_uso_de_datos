#include <iostream>
#include "codigo4.h"

using namespace std;
int main() {
    Calculadora op;
    int a, b, c, opcion;
    float resultado = 0;
    string params = "";
    string operacion = "";
    cout << "CALCULADORA BASICA\n";
    cout << "1. Suma de 1 valor\n2. Suma de 2 valores\n3. Suma de 3 valores\n\n";
    cout << "4. Resta de 1 valor\n5. Resta de 2 valores\n6. Resta de 3 valores\n\n";
    cout << "7. Multiplicacion de 1 valor\n8. Multiplicacion de 2 valores\n9. Multiplicacion de 3 valores\n\n";
    cout << "10. Division de 1 valor\n11. Division de 2 valores\n12. Division de 3 valores\n\n";
    cout << "Selecciona una opcion: "; cin >> opcion;
    int nParams = ((opcion-1)%3)+1;
    cout << "Ingresa el primer numero: "; cin >> a; params += to_string(a);
    if(nParams>=2){ cout << "Ingresa el segundo numero: "; cin >> b; params += "," + to_string(b); }
    if(nParams==3){ cout << "Ingresa el tercer numero: ";  cin >> c; params += "," + to_string(c); }
    if(opcion<=3)  { operacion="Suma";           if(nParams==1) resultado=op.suma(); else if(nParams==2) resultado=op.suma(a,b); else resultado=op.suma(a,b,c); }
    else if(opcion<=6)  { operacion="Resta";          if(nParams==1) resultado=op.resta(); else if(nParams==2) resultado=op.resta(a,b); else resultado=op.resta(a,b,c); }
    else if(opcion<=9)  { operacion="Multiplicacion";  if(nParams==1) resultado=op.multiplicacion(); else if(nParams==2) resultado=op.multiplicacion(a,b); else resultado=op.multiplicacion(a,b,c); }
    else                { operacion="Division";        if(nParams==1) resultado=op.division(); else if(nParams==2) resultado=op.division(a,b); else resultado=op.division(a,b,c); }
    cout << "Resultado: " << resultado << endl;
    op.guardarSalidas(operacion, params, resultado);
    return 0;
}
