# Función para buscar una celda libre
def busca_celda_libre(sudoku):
    for fila in range(9):          
        for columna in range(9):   
            if sudoku[fila][columna] == 0:  # Compara cual esta libre
                return (fila, columna)      # Devuelve la posición de la celda libre
    return None  # Si no hay celdas vacías, retorna None

# Función para verificar si un número es válido
def numero_valido(sudoku, numero, fila, columna):
    
    for columna_actual in range(9):  
        if sudoku[fila][columna_actual] == numero:
            return False  # Número ya está en la fila

    # Verificar si el número ya está en la columna
    for fila_actual in range(9):  
        if sudoku[fila_actual][columna] == numero:
            return False  # Número ya está en la columna

    # Verificar si el número ya está en el subcuadro (3x3)
    inicio_fila = (fila // 3) * 3  
    inicio_columna = (columna // 3) * 3  
    for fila_actual in range(inicio_fila, inicio_fila + 3):
        for columna_actual in range(inicio_columna, inicio_columna + 3):
            if sudoku[fila_actual][columna_actual] == numero:
                return False  # Número ya está en el subcuadro

    # Si no hay conflictos, el número es válido
    return True

# Función para resolver el Sudoku usando backtracking
def resolver(sudoku):
    # Buscar una celda vacía
    celda = busca_celda_libre(sudoku)
    if not celda:  # Si no hay más celdas vacías, está resuelto
        return True
    fila, columna = celda

    # Probar números del 1 al 9
    for numero in range(1, 10):
        if numero_valido(sudoku, numero, fila, columna):  # Comprobar si es válido
            sudoku[fila][columna] = numero  # Colocar el número provisionalmente

            if resolver(sudoku):  # Llamada recursiva para resolver el resto del tablero
                return True  # Si se resuelve, finalizamos

            sudoku[fila][columna] = 0  # Deshacer si no funcionó

    return False  # Si ningún número es válido, no hay solución

# Función para imprimir el tablero de Sudoku
def imprimir_solucion(sudoku):
    for fila in range(9):
        if fila % 3 == 0 and fila != 0:  # Línea divisoria entre subcuadros
            print("-" * 21)
        
        for columna in range(9):
            if columna % 3 == 0 and columna != 0:  # Línea divisoria entre subcuadros
                print("| ", end="")
            
            print(sudoku[fila][columna] if sudoku[fila][columna] != 0 else ".", end=" ")
        
        print()  # Nueva línea al final de cada fila

#Resulve el siguiente sudoku
sudoku = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]


if resolver(sudoku):
    print("Solución encontrada:")
    imprimir_solucion(sudoku)
else:
    print("No hay solución para este tablero.")

    

    
    

    
    