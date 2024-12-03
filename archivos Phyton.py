
def leer_archivo(nombre_archivo):
    archivo = open(nombre_archivo, 'r') # r siginifica abrir en modo lectura y reserva espacio de memoria
    contenido = archivo.read() #lee el contenido como si fuera una cadena, exiten otros tipos como leer una linea o todas las líneas
    archivo.close()
    return contenido


def escribir_archivo(nombre_archivo, datos):
    archivo = open(nombre_archivo, 'w') # w es para abrir el modo escritura y reserva espacio de memoria
    archivo.write(datos) #escribe el contenido de la variable datos en la variable archivo
    archivo.close()
    print(f"Datos escritos en el archivo {nombre_archivo}.") # el f sirve para indicar que lo que está entre llaves es un marcador no un texto literal


def agregar_a_archivo(nombre_archivo, datos):
    archivo = open(nombre_archivo, 'a') # a es para abrir el modo anexar y reserva espacio de memoria
    archivo.write(datos)#escribe el contenido de la variable datos en la variable archivo
    archivo.close()
    print(f"Datos agregados al archivo {nombre_archivo}.")# el f sirve para indicar que lo que está entre llaves es un marcador no un texto literal


def main():
    
    datos_a_escribir = "Este es el primer contenido que se escribe en el archivo.\n" #crea una variable
    escribir_archivo("ejemplo.txt", datos_a_escribir) #llama a la funcion correspondiende y escribe nombre de archivo y contenido

  
    print("Contenido del archivo:")
    print(leer_archivo("ejemplo.txt"))

    
    datos_a_agregar = "Este es el contenido adicional que se agrega al archivo.\n" #crea una variable
    agregar_a_archivo("ejemplo.txt", datos_a_agregar) #llama a la funcion correspondiente y anexa

   
    print("\nContenido del archivo después de agregar más datos:")
    print(leer_archivo("ejemplo.txt"))


if __name__ == "__main__":#esta verificacion sirve para indicar que al importar el codigo solo se ejecute los programas declarados y no todos los que esten en main.
    main()
