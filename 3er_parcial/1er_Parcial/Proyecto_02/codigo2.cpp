#include "codigo2.h"

int Operaciones::suma(int a, int b) {
    return a + b;
}

void Operaciones::guardarSalidas(int a, int b, int resultado) {
    ofstream txt("salida.txt");
    txt << "=== SUMA DE DOS VALORES ===" << endl;
    txt << "Valor 1: " << a << endl;
    txt << "Valor 2: " << b << endl;
    txt << "Resultado: " << resultado << endl;
    txt.close();

    ofstream csv("salida.csv");
    csv << "campo,valor" << endl;
    csv << "valor1," << a << endl;
    csv << "valor2," << b << endl;
    csv << "resultado," << resultado << endl;
    csv.close();

    ofstream json("salida.json");
    json << "{" << endl;
    json << "  \"programa\": \"Suma de dos valores\"," << endl;
    json << "  \"valor1\": " << a << "," << endl;
    json << "  \"valor2\": " << b << "," << endl;
    json << "  \"resultado\": " << resultado << endl;
    json << "}" << endl;
    json.close();

    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<suma>" << endl;
    xml << "  <valor1>" << a << "</valor1>" << endl;
    xml << "  <valor2>" << b << "</valor2>" << endl;
    xml << "  <resultado>" << resultado << "</resultado>" << endl;
    xml << "</suma>" << endl;
    xml.close();

    cout << "[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]" << endl;
}
