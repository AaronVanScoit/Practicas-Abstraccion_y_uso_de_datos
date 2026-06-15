#ifndef CODIGO9_H
#define CODIGO9_H
#include <iostream>
#include <fstream>
using namespace std;
class Promedio {
public:
    int suma(int a,int b,int c,int d,int e);
    float promedio(int a,int b,int c,int d,int e);
    float media(int a,int b,int c,int d,int e);
    int maximo(int a,int b,int c,int d,int e);
    int minimo(int a,int b,int c,int d,int e);
    void guardarSalidas(int a,int b,int c,int d,int e,int s,float p,float m,int mx,int mn);
};
#endif
