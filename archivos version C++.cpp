#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string leer_archivo(const string& nombre_archivo) {//pasa la variable por referencia y asegura que no cambiará su valor
    ifstream archivo(nombre_archivo); // Abrir el archivo en modo lectura
    string contenido, linea;//crea dos variables de tipo string

    if (archivo.is_open()) {//si la condicion es verdadera se ejecuta 
        while (getline(archivo, linea)) { // mientras haya lineas por leer en archivo guardará cada linea en la variable linea
            contenido += linea + "\n"; // guarda cada linea en la variable contenido
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }

    return contenido;
}

void escribir_archivo(const string& nombre_archivo, const string& datos) {
    ofstream archivo(nombre_archivo); // Abrir el archivo en modo escritura

    if (archivo.is_open()) {
        archivo << datos; // Escribir los datos en el archivo
        archivo.close();
        cout << "Datos escritos en el archivo " << nombre_archivo << "." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
}

void agregar_a_archivo(const string& nombre_archivo, const string& datos) {
    ofstream archivo(nombre_archivo, ios::app); // Abrir el archivo en modo anexar

    if (archivo.is_open()) {
        archivo << datos; // Escribir los datos en el archivo
        archivo.close();
        cout << "Datos agregados al archivo " << nombre_archivo << "." << endl;
    } else {
        cout << "No se pudo abrir el archivo para agregar datos." << endl;
    }
}

int main() {
    string datos_a_escribir = "Este es el primer contenido que se escribe en el archivo.\n"; // Datos a escribir
    escribir_archivo("ejemplo.txt", datos_a_escribir); // Llamar a la función para escribir

    cout << "Contenido del archivo:" << endl;
    cout << leer_archivo("ejemplo.txt"); // Leer y mostrar el contenido del archivo

    string datos_a_agregar = "Este es el contenido adicional que se agrega al archivo.\n"; // Datos a agregar
    agregar_a_archivo("ejemplo.txt", datos_a_agregar); // Llamar a la función para agregar

    cout << "\nContenido del archivo después de agregar más datos:" << endl;
    cout << leer_archivo("ejemplo.txt"); // Leer y mostrar el contenido actualizado

    return 0;
}

