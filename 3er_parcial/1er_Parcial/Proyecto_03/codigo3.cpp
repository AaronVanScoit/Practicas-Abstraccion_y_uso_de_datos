#include "codigo3.h"
int Calculadora::suma(int a, int b)           { return a + b; }
int Calculadora::resta(int a, int b)          { return a - b; }
int Calculadora::multiplicacion(int a, int b) { return a * b; }
float Calculadora::division(int a, int b)     { return static_cast<float>(a) / b; }

void Calculadora::guardarSalidas(int op, int a, int b, float resultado) {
    string ops[] = {"", "Suma", "Resta", "Multiplicacion", "Division"};
    ofstream txt("salida.txt");
    txt << "=== CALCULADORA BASICA ===" << endl;
    txt << "Operacion: " << ops[op] << endl;
    txt << "Valor 1: " << a << endl << "Valor 2: " << b << endl;
    txt << "Resultado: " << resultado << endl;
    txt.close();

    ofstream csv("salida.csv");
    csv << "operacion,valor1,valor2,resultado" << endl;
    csv << ops[op] << "," << a << "," << b << "," << resultado << endl;
    csv.close();

    ofstream json("salida.json");
    json << "{\n  \"programa\": \"Calculadora Basica\",\n";
    json << "  \"operacion\": \"" << ops[op] << "\",\n";
    json << "  \"valor1\": " << a << ",\n  \"valor2\": " << b << ",\n";
    json << "  \"resultado\": " << resultado << "\n}" << endl;
    json.close();

    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<calculadora>\n";
    xml << "  <operacion>" << ops[op] << "</operacion>\n";
    xml << "  <valor1>" << a << "</valor1>\n  <valor2>" << b << "</valor2>\n";
    xml << "  <resultado>" << resultado << "</resultado>\n</calculadora>" << endl;
    xml.close();
    cout << "[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]" << endl;
}
