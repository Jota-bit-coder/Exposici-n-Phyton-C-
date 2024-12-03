#include <iostream>
using namespace std;

// Función para buscar una celda vacía
bool busca_celda_libre(int sudoku[9][9], int &fila, int &columna) {
    for (fila = 0; fila < 9; fila++) {
        for (columna = 0; columna < 9; columna++) {
            if (sudoku[fila][columna] == 0) { // Celda vacía encontrada
                return true;
            }
        }
    }
    return false; // No hay celdas vacías
}

// Función para verificar si un número es válido
bool numero_valido(int sudoku[9][9], int numero, int fila, int columna) {
    // Verificar fila
    for (int columna_actual = 0; columna_actual < 9; columna_actual++) {
        if (sudoku[fila][columna_actual] == numero) {
            return false;
        }
    }

    // Verificar columna
    for (int fila_actual = 0; fila_actual < 9; fila_actual++) {
        if (sudoku[fila_actual][columna] == numero) {
            return false;
        }
    }

    // Verificar subcuadro 3x3
    int inicio_fila = (fila / 3) * 3;
    int inicio_columna = (columna / 3) * 3;
    for (int fila_actual = inicio_fila; fila_actual < inicio_fila + 3; fila_actual++) {
        for (int columna_actual = inicio_columna; columna_actual < inicio_columna + 3; columna_actual++) {
            if (sudoku[fila_actual][columna_actual] == numero) {
                return false;
            }
        }
    }

    return true; // Si no hay conflictos, el número es válido
}

// Función para resolver el Sudoku usando backtracking
bool resolver(int sudoku[9][9]) {
    int fila, columna;

    // Buscar una celda vacía
    if (!busca_celda_libre(sudoku, fila, columna)) {
        return true; // No hay más celdas vacías, Sudoku resuelto
    }

    // Probar números del 1 al 9
    for (int numero = 1; numero <= 9; numero++) {
        if (numero_valido(sudoku, numero, fila, columna)) {
            sudoku[fila][columna] = numero; // Colocar el número provisionalmente

            if (resolver(sudoku)) {
                return true; // Si se resuelve, finalizamos
            }

            sudoku[fila][columna] = 0; // Deshacer si no funcionó
        }
    }

    return false; // No hay solución
}

// Función para imprimir el tablero de Sudoku
void imprimir_solucion(int sudoku[9][9]) {
    for (int fila = 0; fila < 9; fila++) {
        if (fila % 3 == 0 && fila != 0) { // Línea divisoria entre subcuadros
            cout << "---------------------" << endl;
        }

        for (int columna = 0; columna < 9; columna++) {
            if (columna % 3 == 0 && columna != 0) { // Línea divisoria entre subcuadros
                cout << "| ";
            }

            cout << (sudoku[fila][columna] == 0 ? "." : to_string(sudoku[fila][columna])) << " ";
        }

        cout << endl; // Nueva línea al final de cada fila
    }
}

int main() {
    // Tablero inicial de Sudoku
    int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (resolver(sudoku)) {
        cout << "Solución encontrada:" << endl;
        imprimir_solucion(sudoku);
    } else {
        cout << "No hay solución para este tablero." << endl;
    }

    return 0;
}

