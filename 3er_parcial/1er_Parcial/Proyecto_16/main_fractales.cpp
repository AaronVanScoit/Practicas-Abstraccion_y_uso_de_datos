#include <iostream>
#include "codigo16.h"
using namespace std;

int main(){
    Fractales f; int n;
    cout<<"Nivel de fractal: "; cin>>n;
    cout<<"\nTriangulo de Sierpinski:"<<endl; f.sierpinski(n);
    cout<<"\n\nPolvo de Cantor:"<<endl; f.cantor(n,27);
    f.guardarSalidas(n);
    return 0;
}
