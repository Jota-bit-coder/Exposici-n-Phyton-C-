class Punto:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def raiz_cuadrada(self, numero):

        if numero < 0: #Calcula la raíz cuadrada usando el método de Newton-Raphson.
            raise ValueError("El número debe ser positivo o cero.")

        tolerancia = 1e-10
        aproximacion = numero / 2.0

        while abs(aproximacion**2 - numero) > tolerancia:
            aproximacion = (aproximacion + numero / aproximacion) / 2.0

        return aproximacion

    def calcular_distancia(self, otro_punto): #Calcula la distancia.
        dx = otro_punto.x - self.x
        dy = otro_punto.y - self.y
        return self.raiz_cuadrada(dx**2 + dy**2)

#Ejemplo
p1 = Punto(3.0, 4.0)
p2 = Punto(7.0, 1.0)
distancia = p1.calcular_distancia(p2)
print(f"La distancia entre los puntos ({p1.x}, {p1.y}) y ({p2.x}, {p2.y}) es: {distancia}")