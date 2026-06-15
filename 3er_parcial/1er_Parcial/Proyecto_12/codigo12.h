#ifndef CODIGO12_H
#define CODIGO12_H
#include <iostream>
#include <fstream>
using namespace std;
class Matrices {
public:
    void multConstante(int A[3][3], int k, int R[3][3]);
    void multMatrices(int A[3][3], int B[3][3], int R[3][3]);
    void guardarSalidas(int A[3][3], int B[3][3], int RC[3][3], int RM[3][3], int k);
};
#endif
