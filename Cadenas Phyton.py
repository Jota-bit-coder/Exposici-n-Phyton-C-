def palindromo(cadena):
    # Creamos un arreglo vacio para almacenar los caracteres de la cadena
    array = []  
    
    # Paso 1: Convertir la cadena a minúsculas y eliminar caracteres no alfabéticos
    for caracter in cadena:  # Recorrer cada carácter en la cadena original
        if 'a' <= caracter.lower() <= 'z':  # Verificar si es una letra alfabética
            array.append(caracter.lower())  # Convertir a minúscula y agregar a la lista

    # Paso 2: Verificar si es un palíndromo manualmente
    inicio = 0
    fin = len(array) - 1
    while inicio < fin:  # Compara los caracteres desde los extremos hacia el centro
        if array[inicio] != array[fin]:
            return False  # Si hay una diferencia, no es un palíndromo
        inicio += 1
        fin -= 1

    return True  # Si se recorren todos los caracteres sin diferencias, es un palíndromo


palabra = input("Ingresa una cadena: ")

if palindromo(palabra):
    print("La cadena es un palíndromo.")
else:
    print("La cadena NO es un palíndromo.")











