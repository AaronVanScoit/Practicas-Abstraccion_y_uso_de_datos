#include "codigo1.h"

Saludo::Saludo() {
    cout << "Salida vacia" << endl;
}

Saludo::~Saludo() {
    cout << "Salida vacia" << endl;
}

void Saludo::Hola() {
    cout << "Ingresa tu nombre por favor: ";
    cin >> nombre;
    cout << "HOLA " << nombre << " TE DOY LA BIENVENIDA A MI PROYECTO" << endl << endl;

    cout << "TAMAÑO DE UN char: "    << sizeof(char)   << " bytes" << endl;
    cout << "TAMAÑO DE UN float: "   << sizeof(float)  << " bytes" << endl;
    cout << "TAMAÑO DE UN boolean: " << sizeof(bool)   << " bytes" << endl;
    cout << "TAMAÑO DE UN double: "  << sizeof(double) << " bytes" << endl;
    cout << "TAMAÑO DE UN long: "    << sizeof(long)   << " bytes" << endl;
    cout << "TAMAÑO DE UN short: "   << sizeof(short)  << " bytes" << endl;

    guardarSalidas(nombre);
}

void Saludo::guardarSalidas(const string& nom) {
    // TXT
    ofstream txt("salida.txt");
    txt << "HOLA MUNDO" << endl;
    txt << "Nombre: " << nom << endl;
    txt << "HOLA " << nom << " UPIICSA TE DA LA BIENVENIDA...." << endl;
    txt << "TAMANO DE UN char: "    << sizeof(char)   << " bytes" << endl;
    txt << "TAMANO DE UN float: "   << sizeof(float)  << " bytes" << endl;
    txt << "TAMANO DE UN boolean: " << sizeof(bool)   << " bytes" << endl;
    txt << "TAMANO DE UN double: "  << sizeof(double) << " bytes" << endl;
    txt << "TAMANO DE UN long: "    << sizeof(long)   << " bytes" << endl;
    txt << "TAMANO DE UN short: "   << sizeof(short)  << " bytes" << endl;
    txt.close();

    // CSV
    ofstream csv("salida.csv");
    csv << "campo,valor" << endl;
    csv << "nombre," << nom << endl;
    csv << "char," << sizeof(char) << endl;
    csv << "float," << sizeof(float) << endl;
    csv << "boolean," << sizeof(bool) << endl;
    csv << "double," << sizeof(double) << endl;
    csv << "long," << sizeof(long) << endl;
    csv << "short," << sizeof(short) << endl;
    csv.close();

    // JSON
    ofstream json("salida.json");
    json << "{" << endl;
    json << "  \"programa\": \"Hola Mundo\"," << endl;
    json << "  \"nombre\": \"" << nom << "\"," << endl;
    json << "  \"tipos\": {" << endl;
    json << "    \"char\": " << sizeof(char) << "," << endl;
    json << "    \"float\": " << sizeof(float) << "," << endl;
    json << "    \"boolean\": " << sizeof(bool) << "," << endl;
    json << "    \"double\": " << sizeof(double) << "," << endl;
    json << "    \"long\": " << sizeof(long) << "," << endl;
    json << "    \"short\": " << sizeof(short) << endl;
    json << "  }" << endl;
    json << "}" << endl;
    json.close();

    // XML
    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
    xml << "<holamundo>" << endl;
    xml << "  <nombre>" << nom << "</nombre>" << endl;
    xml << "  <tipos>" << endl;
    xml << "    <char>" << sizeof(char) << "</char>" << endl;
    xml << "    <float>" << sizeof(float) << "</float>" << endl;
    xml << "    <boolean>" << sizeof(bool) << "</boolean>" << endl;
    xml << "    <double>" << sizeof(double) << "</double>" << endl;
    xml << "    <long>" << sizeof(long) << "</long>" << endl;
    xml << "    <short>" << sizeof(short) << "</short>" << endl;
    xml << "  </tipos>" << endl;
    xml << "</holamundo>" << endl;
    xml.close();

    cout << "\n[Salidas guardadas: salida.txt, salida.csv, salida.json, salida.xml]" << endl;
}
