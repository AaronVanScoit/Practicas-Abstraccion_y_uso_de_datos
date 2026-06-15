#include "codigo6.h"
int Calculadora::suma(int a, int b)           { return a + b; }
int Calculadora::resta(int a, int b)          { return a - b; }
int Calculadora::multiplicacion(int a, int b) { return a * b; }
float Calculadora::division(int a, int b)     { return static_cast<float>(a)/b; }

// Sobreescritura: multiplicacion como sumas repetidas
int CalculadoraNueva::multiplicacion(int a, int b) {
    int resultado = 0;
    for(int i = 0; i < b; i++) resultado = resultado + a;
    return resultado;
}
// Sobreescritura: division como restas repetidas
float CalculadoraNueva::division(int a, int b) {
    int contador = 0;
    while(a >= b){ a = a - b; contador++; }
    return contador;
}

void CalculadoraNueva::guardarSalidas(string op, int a, int b, float res) {
    ofstream txt("salida.txt");
    txt << "=== CALCULADORA HERENCIA + SOBREESCRITURA ===" << endl;
    txt << "Operacion: " << op << "\nValor1: " << a << "\nValor2: " << b << "\nResultado: " << res << endl;
    txt.close();
    ofstream csv("salida.csv");
    csv << "operacion,valor1,valor2,resultado\n" << op << "," << a << "," << b << "," << res << endl;
    csv.close();
    ofstream json("salida.json");
    json << "{\n  \"programa\":\"Calculadora Sobreescritura\",\n  \"operacion\":\"" << op << "\",\n";
    json << "  \"valor1\":" << a << ",\n  \"valor2\":" << b << ",\n  \"resultado\":" << res << "\n}" << endl;
    json.close();
    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\"?>\n<calculadora>\n  <operacion>" << op << "</operacion>\n";
    xml << "  <valor1>" << a << "</valor1>\n  <valor2>" << b << "</valor2>\n";
    xml << "  <resultado>" << res << "</resultado>\n</calculadora>" << endl;
    xml.close();
    cout << "[Salidas guardadas]" << endl;
}
