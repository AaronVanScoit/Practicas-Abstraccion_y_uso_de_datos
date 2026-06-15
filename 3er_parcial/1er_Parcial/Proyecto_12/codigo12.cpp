#include "codigo12.h"
void Matrices::multConstante(int A[3][3], int k, int R[3][3]) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) R[i][j]=A[i][j]*k;
}
void Matrices::multMatrices(int A[3][3], int B[3][3], int R[3][3]) {
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        R[i][j]=0;
        for(int k=0;k<3;k++) R[i][j]+=A[i][k]*B[k][j];
    }
}
void Matrices::guardarSalidas(int A[3][3], int B[3][3], int RC[3][3], int RM[3][3], int k) {
    auto writeMatrix=[](ofstream& f, int M[3][3], string label){
        f<<label<<":"<<endl;
        for(int i=0;i<3;i++){for(int j=0;j<3;j++) f<<M[i][j]<<" "; f<<endl;}
    };
    ofstream txt("salida.txt");
    txt<<"=== MULTIPLICACION DE MATRICES ==="<<endl;
    writeMatrix(txt,A,"Matriz A"); writeMatrix(txt,B,"Matriz B");
    txt<<"Constante: "<<k<<endl;
    writeMatrix(txt,RC,"A*constante"); writeMatrix(txt,RM,"A*B");
    txt.close();

    ofstream csv("salida.csv");
    csv<<"tipo,fila,col0,col1,col2"<<endl;
    for(int i=0;i<3;i++) csv<<"AxK,"<<i<<","<<RC[i][0]<<","<<RC[i][1]<<","<<RC[i][2]<<endl;
    for(int i=0;i<3;i++) csv<<"AxB,"<<i<<","<<RM[i][0]<<","<<RM[i][1]<<","<<RM[i][2]<<endl;
    csv.close();

    ofstream json("salida.json"); json<<"{\n  \"AxK\":[\n";
    for(int i=0;i<3;i++){json<<"    ["<<RC[i][0]<<","<<RC[i][1]<<","<<RC[i][2]<<"]";if(i<2)json<<",";json<<"\n";}
    json<<"  ],\n  \"AxB\":[\n";
    for(int i=0;i<3;i++){json<<"    ["<<RM[i][0]<<","<<RM[i][1]<<","<<RM[i][2]<<"]";if(i<2)json<<",";json<<"\n";}
    json<<"  ]\n}"<<endl; json.close();

    ofstream xml("salida.xml"); xml<<"<?xml version=\"1.0\"?>\n<matrices>\n  <AxK>\n";
    for(int i=0;i<3;i++){xml<<"    <fila>"<<RC[i][0]<<" "<<RC[i][1]<<" "<<RC[i][2]<<"</fila>\n";}
    xml<<"  </AxK>\n  <AxB>\n";
    for(int i=0;i<3;i++){xml<<"    <fila>"<<RM[i][0]<<" "<<RM[i][1]<<" "<<RM[i][2]<<"</fila>\n";}
    xml<<"  </AxB>\n</matrices>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
