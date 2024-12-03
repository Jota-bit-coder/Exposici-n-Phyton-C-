def suma_elementos(arreglo): #define una funcion que recibe de argumento un arreglo
    suma = 0
    for elemento in arreglo: #recorre elemento por elemento del arreglo, trabaja con el contenido no con los indices
        suma += elemento
    return suma

def main(): #definicion de la funcion principal
    tamaño = int(input("Ingresa el tamaño del arreglo: ")) #imput devuelve un valor como texto por eso es necesario convertirlo a entero
    
    # Crear arreglo (lista) dinámicamente
    arreglo = []
    
    print("Ingresa los elementos del arreglo:")
    for i in range(tamaño): #en este caso si trabaja con los indices
        elemento = int(input()) #input lee string, por eso es necesario convertirlo
        arreglo.append(elemento) #agrega el valor de elemento al arreglo
    
    # Llamar a la función y mostrar la suma
    suma = suma_elementos(arreglo)
    print("La suma de los elementos es:", suma)

# Llamar a la función principal
if __name__ == "__main__": #esta verificacion sirve para indicar que al importar el codigo solo se ejecute los programas declarados y no todos los que esten en main.
    main()
