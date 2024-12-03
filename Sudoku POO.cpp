#include <iostream>
using namespace std;

class ResolucionSudoku {
private:
    static const int TAMANO = 9;
    int tablero[TAMANO][TAMANO];

    // Verifica si un numero es valido en la celda (fila, columna)
    bool esValido(int fila, int columna, int num) {
        for (int i = 0; i < TAMANO; i++) {
            if (tablero[fila][i] == num || tablero[i][columna] == num || 
                tablero[fila - fila % 3 + i / 3][columna - columna % 3 + i % 3] == num) {
                return false;
            }
        }
        return true;
    }

    // Resuelve el Sudoku usando backtracking
    bool resolver(int fila = 0, int columna = 0) {
        if (fila == TAMANO) return true; // Caso base: todo resuelto
        if (columna == TAMANO) return resolver(fila + 1, 0); // Cambiar de fila
        if (tablero[fila][columna] != 0) return resolver(fila, columna + 1); // Celda llena

        for (int num = 1; num <= TAMANO; num++) {
            if (esValido(fila, columna, num)) {
                tablero[fila][columna] = num;
                if (resolver(fila, columna + 1)) return true;
                tablero[fila][columna] = 0; // Retroceso
            }
        }
        return false;
    }

public:
    ResolucionSudoku(int tableroInicial[TAMANO][TAMANO]) {
        for (int i = 0; i < TAMANO; i++) {
            for (int j = 0; j < TAMANO; j++) {
                tablero[i][j] = tableroInicial[i][j];
            }
        }
    }

    void resolverSudoku() {
        if (resolver()) imprimirTablero();
        else cout << "No se puede resolver este Sudoku.\n";
    }

    void imprimirTablero() {
        for (int i = 0; i < TAMANO; i++) {
            for (int j = 0; j < TAMANO; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int tablero[9][9] = {
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

    ResolucionSudoku solucion(tablero);
    solucion.resolverSudoku();

    return 0;
}



