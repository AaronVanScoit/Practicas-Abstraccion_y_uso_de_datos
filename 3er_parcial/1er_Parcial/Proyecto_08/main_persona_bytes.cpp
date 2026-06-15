#include <iostream>
#include "codigo8.h"

using namespace std;
int main() {
    Persona op; Auto carro;
    cout << "Nombre: ";   cin >> op.nombre;
    cout << "Apellido paterno: "; cin >> op.ap;
    cout << "Apellido materno: "; cin >> op.am;
    cout << "Genero: ";   cin >> op.genero;
    cout << "Edad: ";     cin >> op.edad;
    cout << "Ingresa el precio del auto: "; cin >> carro.precio;
    cout << "Ingresa el anio del auto: ";   cin >> carro.anio;
    op.mostrar();
    cout << "Precio: " << carro.precio << "\nAnio: " << carro.anio << endl;
    op.guardarSalidas(carro);
    return 0;
}
