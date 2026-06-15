#include <iostream>
#include "codigo12.h"
using namespace std;
int main(){
    Matrices op; int A[3][3],B[3][3],RC[3][3],RM[3][3],k;
    cout<<"Ingresa matriz A (3x3):"<<endl;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>A[i][j];
    cout<<"Ingresa matriz B (3x3):"<<endl;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) cin>>B[i][j];
    cout<<"Ingresa constante: "; cin>>k;
    op.multConstante(A,k,RC);
    cout<<"\nResultado A * constante"<<endl;
    for(int i=0;i<3;i++){for(int j=0;j<3;j++) cout<<RC[i][j]<<" "; cout<<endl;}
    op.multMatrices(A,B,RM);
    cout<<"\nResultado A * B"<<endl;
    for(int i=0;i<3;i++){for(int j=0;j<3;j++) cout<<RM[i][j]<<" "; cout<<endl;}
    op.guardarSalidas(A,B,RC,RM,k);
    return 0;
}
