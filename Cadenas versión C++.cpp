#include <iostream>
#include <string>
using namespace std;

// Prototipo de la funcion
bool Palindromo(const string& cadena);

int main() {
    string palabra;

    cout << "Ingresa una cadena: ";
    getline(cin, palabra);

    if (Palindromo(palabra)) {
        cout << "La cadena es un palíndromo." << endl;
    } else {
        cout << "La cadena NO es un palíndromo." << endl;
    }

    return 0;
}

bool Palindromo(const string& cadena) {
    // Creamos un arreglo vacio para almacenar los caracteres de la cadena
    string array; // Para almacena los caracteres alfabéticos en minúsculas

    // En este bucle convertir la cadena a minúsculas y eliminar caracteres no alfabéticos
    for (int i = 0; i < cadena.size(); i++) { 
        char c = cadena[i];
        // Verificar manualmente si es una letra alfabética (mayúscula o minúscula)
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { 
            // Convertir mayúsculas a minúsculas manualmente
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A'); // Convertir a minúscula
            }
            array += c;
        }
    }
    
    // Comparar los caracteres en el arreglo con los anteriores
    int inicio = 0;
    int fin = array.size() - 1;

    while (inicio < fin) {
        if (array[inicio] != array[fin]) {
            return false; // Si hay una diferencia, no es un palíndromo
        }
        inicio++;
        fin--;
    }

    return true; // Es un palíndromo si no se encontró ninguna diferencia
}