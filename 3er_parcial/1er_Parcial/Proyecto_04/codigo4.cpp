#include "codigo4.h"

int Calculadora::suma()                       { return 0; }
int Calculadora::suma(int a, int b)           { return a + b; }
int Calculadora::suma(int a, int b, int c)    { return a + b + c; }
int Calculadora::resta()                      { return 0; }
int Calculadora::resta(int a, int b)          { return a - b; }
int Calculadora::resta(int a, int b, int c)   { return a - b - c; }
int Calculadora::multiplicacion()             { return 0; }
int Calculadora::multiplicacion(int a, int b) { return a * b; }
int Calculadora::multiplicacion(int a, int b, int c) { return a * b * c; }
float Calculadora::division()                 { return 0; }
float Calculadora::division(int a, int b)     { return static_cast<float>(a)/b; }
float Calculadora::division(int a, int b, int c) { return static_cast<float>(a)/b/c; }

void Calculadora::guardarSalidas(string operacion, string params, float resultado) {
    ofstream txt("salida.txt");
    txt << "=== CALCULADORA CON SOBRECARGA ===" << endl;
    txt << "Operacion: " << operacion << endl;
    txt << "Parametros: " << params << endl;
    txt << "Resultado: " << resultado << endl;
    txt.close();

    ofstream csv("salida.csv");
    csv << "operacion,parametros,resultado" << endl;
    csv << operacion << "," << params << "," << resultado << endl;
    csv.close();

    ofstream json("salida.json");
    json << "{\n  \"programa\": \"Calculadora Sobrecarga\",\n";
    json << "  \"operacion\": \"" << operacion << "\",\n";
    json << "  \"parametros\": \"" << params << "\",\n";
    json << "  \"resultado\": " << resultado << "\n}" << endl;
    json.close();

    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<calculadora>\n";
    xml << "  <operacion>" << operacion << "</operacion>\n";
    xml << "  <parametros>" << params << "</parametros>\n";
    xml << "  <resultado>" << resultado << "</resultado>\n</calculadora>" << endl;
    xml.close();
    cout << "[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]" << endl;
}
