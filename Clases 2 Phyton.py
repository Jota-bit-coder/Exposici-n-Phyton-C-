class CuentaBancaria:
    def __init__(self, saldo_inicial=0.0):
        self.saldo = saldo_inicial #Inicializa el saldo actual

    def depositar(self, cantidad):
        if cantidad > 0: #Agrega dinero a la cuenta.
            self.saldo += cantidad
            print(f"Has depositado ${cantidad:.2f}. Saldo actual: ${self.saldo:.2f}")
        else:
            print("Cantidad inválida para depositar.")

    def retirar(self, cantidad): #Resta el dinero si hay saldo suficiente.
        if 0 < cantidad <= self.saldo:
            self.saldo -= cantidad
            print(f"Has retirado ${cantidad:.2f}. Saldo actual: ${self.saldo:.2f}")
        else:
            print("Cantidad inválida o saldo insuficiente.")

    def consultar_saldo(self):
        print(f"Saldo actual: ${self.saldo:.2f}") #Resuelve el saldo actual.


#Función interactiva
print("Cuenta Bancaria")
saldo_inicial = float(input("Ingrese su saldo inicial: "))
cuenta = CuentaBancaria(saldo_inicial)

while True:
    print("\nSeleccione una opción:")
    print("1. Depositar dinero")
    print("2. Retirar dinero")
    print("3. Consultar saldo")
    print("4. Salir")

    opcion = input("Opción: ")

    if opcion == "1":
        cantidad = float(input("Ingrese la cantidad a depositar: "))
        cuenta.depositar(cantidad)
    elif opcion == "2":
        cantidad = float(input("Ingrese la cantidad a retirar: "))
        cuenta.retirar(cantidad)
    elif opcion == "3":
        cuenta.consultar_saldo()
    elif opcion == "4":
        print("¡Gracias por usar nuestra aplicación bancaria!")
        break
    else:
        print("Opción inválida. Intente nuevamente.")