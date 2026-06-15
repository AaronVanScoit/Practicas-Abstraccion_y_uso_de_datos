#include <iostream>
#include "codigo14.h"
using namespace std;
int main(){
    ListaPersonas lista; Persona personas[3]; Persona *p; p=personas;
    lista.capturar(p,3);
    lista.mostrar(p,3);
    return 0;
}
