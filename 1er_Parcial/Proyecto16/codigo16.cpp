#include <iostream>
#include <math.h>


#include "codigo15.h"
#include <iostream>
using namespace std;


int Codigo15 :: triangulo_cantor(int n){
    if(n == 0){
            return 1;
        }else{
            return triangulo_cantor(n-1) + (4*pow(3, n-1));
        }
}

int Codigos15 :: triangulo_cantor(int n, int d){
    if (n<0){
        return 0; 
    }
    if(n == 0) {
        return 1;
    }
    return pow(2, d) * triangulo_cantor(n-1, d); 
}
