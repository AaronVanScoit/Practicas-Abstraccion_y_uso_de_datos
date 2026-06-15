#include <iostream>
#include "codigo2.h"
using namespace std;
int main() {
    Operaciones op;
    int a, b, resultado;
    cout << "Ingresa el primer numero: ";
    cin >> a;
    cout << "Ingresa el segundo numero: ";
    cin >> b;
    resultado = op.suma(a, b);
    cout << "La suma es: " << resultado << endl;
    op.guardarSalidas(a, b, resultado);
    return 0;
}
