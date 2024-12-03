#include <iostream>

class SudokuSolver {
private:
    static const int SIZE = 9;
    int board[SIZE][SIZE];

    // Verifica si un número es válido en la celda (row, col)
    bool isValid(int row, int col, int num) {
        for (int i = 0; i < SIZE; i++) {
            if (board[row][i] == num || board[i][col] == num || 
                board[row - row % 3 + i / 3][col - col % 3 + i % 3] == num) {
                return false;
            }
        }
        return true;
    }

    // Resuelve el Sudoku usando backtracking
    bool solve(int row = 0, int col = 0) {
        if (row == SIZE) return true; // Caso base: todo resuelto
        if (col == SIZE) return solve(row + 1, 0); // Cambiar de fila
        if (board[row][col] != 0) return solve(row, col + 1); // Celda llena

        for (int num = 1; num <= SIZE; num++) {
            if (isValid(row, col, num)) {
                board[row][col] = num;
                if (solve(row, col + 1)) return true;
                board[row][col] = 0; // Backtrack
            }
        }
        return false;
    }

public:
    SudokuSolver(int inputBoard[SIZE][SIZE]) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = inputBoard[i][j];
            }
        }
    }

    void solveSudoku() {
        if (solve()) printBoard();
        else std::cout << "No se puede resolver este Sudoku.\n";
    }

    void printBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                std::cout << board[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    int board[9][9] = {
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

    SudokuSolver solver(board);
    solver.solveSudoku();

    return 0;
}


