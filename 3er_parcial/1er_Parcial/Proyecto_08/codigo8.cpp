#include "codigo8.h"
void Persona::mostrar() {
    cout << "\nDatos de la persona\n" << nombre << " " << ap << " " << am;
    cout << "\nGenero: " << genero << "\nEdad: " << edad << endl;
    cout << "\nDatos del carro\n";
}
void Persona::guardarSalidas(Auto carro) {
    size_t sAuto = sizeof(Auto), sPersona = sizeof(Persona);
    ofstream txt("salida.txt");
    txt << "=== SIZEOF PERSONA Y AUTO ===" << endl;
    txt << "Nombre: " << nombre << " " << ap << " " << am << "\nEdad: " << edad << endl;
    txt << "Precio: " << carro.precio << "\nAnio: " << carro.anio << endl;
    txt << "Struct auto: " << sAuto << " bytes\nClass Persona: " << sPersona << " bytes" << endl;
    txt.close();
    ofstream csv("salida.csv");
    csv << "tipo,bytes\nStruct_Auto," << sAuto << "\nClass_Persona," << sPersona << endl;
    csv.close();
    ofstream json("salida.json");
    json << "{\n  \"sizeof\":{\n    \"Struct_Auto\":" << sAuto << ",\n    \"Class_Persona\":" << sPersona << "\n  }\n}" << endl;
    json.close();
    ofstream xml("salida.xml");
    xml << "<?xml version=\"1.0\"?>\n<sizeof>\n  <Struct_Auto>" << sAuto << "</Struct_Auto>\n";
    xml << "  <Class_Persona>" << sPersona << "</Class_Persona>\n</sizeof>" << endl;
    xml.close();
    cout << "\nStruct auto: " << sAuto << " bytes\nClass Persona: " << sPersona << " bytes" << endl;
    cout << "[Salidas guardadas]" << endl;
}
