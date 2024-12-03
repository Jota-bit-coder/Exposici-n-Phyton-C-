# Inicializamos el contador en cero
cont=0 
def torre_de_hanoi(n, origen, destino, auxiliar):
    global cont # Para que python entienda que estamos trabajando con la variable global
    if n == 1:
        # Caso base: mover el unico disco de origen a destino
        print(f"Mover disco 1 de {origen} a {destino}")
        cont += 1
        return
    
    # Mover n-1 discos de origen a auxiliar
    torre_de_hanoi(n - 1, origen, auxiliar, destino) #(..,O = ori, D = aux, A = des)
    
    # Mover el disco n de origen a destino
    print(f"Mover disco {n} de {origen} a {destino}")
    cont += 1
    
    # Mover n-1 discos de auxiliar a destino
    torre_de_hanoi(n - 1, auxiliar, destino, origen) #(..,O = aux, D = des, A = ori)

    
# Ejemplo 
n_discos = 4
torre_de_hanoi(n_discos, 'O', 'D', 'A')
print(f"Numero de movimiento: {cont}")