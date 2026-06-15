#include <iostream>
#include "codigo15.h"
using namespace std;
int main(){
    Series op; int n;
    cout<<"Ingresa un numero: "; cin>>n;
    int fact=op.factorial(n);
    cout<<"Factorial: "<<fact<<endl;
    cout<<"Serie Fibonacci:"<<endl; op.fibo2(n);
    op.guardarSalidas(n,fact);
    return 0;
}
