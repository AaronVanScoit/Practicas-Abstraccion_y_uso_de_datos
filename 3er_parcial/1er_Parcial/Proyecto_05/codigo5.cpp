#include "codigo5.h"
int Calculadora::suma(int a, int b)           { return a + b; }
int Calculadora::resta(int a, int b)          { return a - b; }
int Calculadora::multiplicacion(int a, int b) { return a * b; }
float Calculadora::division(int a, int b)     { return static_cast<float>(a)/b; }
int CalculadoraAvanzada::potencia(int base, int exp) { return (int)pow(base, exp); }
int CalculadoraAvanzada::modulo(int a, int b) { return a % b; }

void CalculadoraAvanzada::guardarSalidas(string op, int a, int b, float res) {
    ofstream txt("salida.txt");
    txt << "=== CALCULADORA CON HERENCIA ===" << endl;
    txt << "Operacion: " << op << "\nValor1: " << a << "\nValor2: " << b << "\nResultado: " << res << endl;
    txt.close();
    ofstream csv("salida.csv");
    csv << "operacion,valor1,valor2,resultado\n" << op << "," << a << "," << b << "," << res << endl;
    csv.close();
    ofstream json("salida.json");
    json << "{\n  \"programa\":\"Calculadora Herencia\",\n  \"operacion\":\"" << op << "\",\n";
    json << "  \"valor1\":" << a << ",\n  \"valor2\":" << b << ",\n  \"resultado\":" << res << "\n}" << endl;
    json.close();
    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\"?>\n<calculadora>\n  <operacion>" << op << "</operacion>\n";
    xml << "  <valor1>" << a << "</valor1>\n  <valor2>" << b << "</valor2>\n";
    xml << "  <resultado>" << res << "</resultado>\n</calculadora>" << endl;
    xml.close();
    cout << "[Salidas guardadas]" << endl;
}
