#include <iostream>
using namespace std;

int suma_elementos(int* arreglo, int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; ++i) { // Recorre los índices del arreglo
        suma += arreglo[i]; // Suma el elemento en la posición i
    }
    return suma;
}

int main() { // Función principal
    int tamaño;
    cout << "Ingresa el tamaño del arreglo: ";
    cin >> tamaño; // Lee el tamaño del arreglo
    
    // Crear un arreglo dinámicamente
    int* arreglo = new int[tamaño];
    
    cout << "Ingresa los elementos del arreglo:\n";
    for (int i = 0; i < tamaño; ++i) { // Recorre los índices del arreglo
        cin >> arreglo[i]; // Lee y almacena cada valor en el arreglo
    }
    
    // Llamar a la función y mostrar la suma
    int suma = suma_elementos(arreglo, tamaño);
    cout << "La suma de los elementos es: " << suma << endl;
    
    // Liberar la memoria reservada dinámicamente
    delete[] arreglo;

    return 0;
}
