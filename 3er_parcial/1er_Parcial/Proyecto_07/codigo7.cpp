#include "codigo7.h"
Persona::Persona()  { cout << "Salida vacia" << endl; }
Persona::~Persona() { cout << "Salida vacia" << endl; }
void Persona::mostrar() {
    cout << "\nDatos de la persona" << endl;
    cout << nombre << " " << ap << " " << am << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad: " << edad << endl;
}
void Persona::guardarSalidas(Auto carro) {
    ofstream txt("salida.txt");
    txt << "=== TIPO DE DATO PERSONA Y AUTO ===" << endl;
    txt << "Nombre: " << nombre << " " << ap << " " << am << "\nGenero: " << genero << "\nEdad: " << edad << endl;
    txt << "Auto - Precio: " << carro.precio << " Anio: " << carro.anio << endl;
    txt.close();
    ofstream csv("salida.csv");
    csv << "tipo,campo,valor\n";
    csv << "Persona,nombre," << nombre << " " << ap << " " << am << "\n";
    csv << "Persona,genero," << genero << "\nPersona,edad," << edad << "\n";
    csv << "Auto,precio," << carro.precio << "\nAuto,anio," << carro.anio << endl;
    csv.close();
    ofstream json("salida.json");
    json << "{\n  \"persona\":{\n    \"nombre\":\"" << nombre << " " << ap << " " << am << "\",\n";
    json << "    \"genero\":\"" << genero << "\",\n    \"edad\":" << edad << "\n  },\n";
    json << "  \"auto\":{\n    \"precio\":" << carro.precio << ",\n    \"anio\":" << carro.anio << "\n  }\n}" << endl;
    json.close();
    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\"?>\n<registro>\n  <persona>\n";
    xml << "    <nombre>" << nombre << " " << ap << " " << am << "</nombre>\n";
    xml << "    <genero>" << genero << "</genero>\n    <edad>" << edad << "</edad>\n  </persona>\n";
    xml << "  <auto>\n    <precio>" << carro.precio << "</precio>\n    <anio>" << carro.anio << "</anio>\n  </auto>\n</registro>" << endl;
    xml.close();
    cout << "[Salidas guardadas]" << endl;
}
