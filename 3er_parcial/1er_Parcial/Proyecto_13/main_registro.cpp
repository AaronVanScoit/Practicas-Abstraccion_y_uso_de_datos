#include <iostream>
#include "codigo13.h"
using namespace std;
int main(){
    Registro r; Persona personas[3]; Auto autos[3];
    r.capturarPersonas(personas,3);
    r.capturarAutos(autos,3);
    r.mostrarPersonas(personas,3);
    r.mostrarAutos(autos,3);
    r.guardarSalidas(personas,autos,3);
    return 0;
}
