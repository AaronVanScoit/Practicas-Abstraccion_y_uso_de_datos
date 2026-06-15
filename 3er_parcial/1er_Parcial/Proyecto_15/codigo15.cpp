#include "codigo15.h"
int Series::factorial(int n) {
    int fact=1;
    for(int i=1;i<=n;i++) fact=fact*i;
    return fact;
}
int Series::fibonacci(int n) {
    if(n<=1) return n;
    else return fibonacci(n-1)+fibonacci(n-2);
}
void Series::fibo2(int n) {
    for(int i=0;i<n;i++) cout<<fibonacci(i)<<" ";
    cout<<endl;
}
void Series::guardarSalidas(int n, int fact) {
    ofstream txt("salida.txt"); txt<<"=== FACTORIAL Y FIBONACCI ==="<<endl;
    txt<<"N: "<<n<<"\nFactorial: "<<fact<<"\nSerie Fibonacci: ";
    for(int i=0;i<n;i++) txt<<fibonacci(i)<<" "; txt<<endl; txt.close();
    ofstream csv("salida.csv"); csv<<"campo,valor\nn,"<<n<<"\nfactorial,"<<fact<<"\nfibonacci_n,"<<fibonacci(n)<<endl; csv.close();
    ofstream json("salida.json");
    json<<"{\n  \"n\":"<<n<<",\n  \"factorial\":"<<fact<<",\n  \"fibonacci_serie\":[";
    for(int i=0;i<n;i++){json<<fibonacci(i);if(i<n-1)json<<",";}
    json<<"]\n}"<<endl; json.close();
    ofstream xml("salida.xml");
    xml<<"<?xml version=\"1.0\"?>\n<series>\n  <n>"<<n<<"</n>\n  <factorial>"<<fact<<"</factorial>\n  <fibonacci>";
    for(int i=0;i<n;i++) xml<<fibonacci(i)<<" ";
    xml<<"</fibonacci>\n</series>"<<endl; xml.close();
    cout<<"[Salidas guardadas]"<<endl;
}
