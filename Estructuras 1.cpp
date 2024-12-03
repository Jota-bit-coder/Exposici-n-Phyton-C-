#include <iostream>
using namespace std;

struct Punto { // Estructura para representar un punto en el plano
    float x; 
    float y;  
};

float valorAbsoluto(float num) { // Funci�n para calcular el valor absoluto
    return (num < 0) ? -num : num;  
}

float calcularDistancia(const Punto& p1, const Punto& p2) { // Funci�n para calcular la distancia entre dos puntos

    float dx = p2.x - p1.x;  
    float dy = p2.y - p1.y;  

    float distanciaCuadrada = dx * dx + dy * dy;

    float raiz = distanciaCuadrada / 2.0f;  // Aproximaci�n inicial
    float tolerancia = 1e-10;  // Precisi�n de la ra�z cuadrada

    while (valorAbsoluto(raiz * raiz - distanciaCuadrada) > tolerancia) { // M�todo de Newton-Raphson para calcular la ra�z cuadrada
        raiz = (raiz + distanciaCuadrada / raiz) / 2.0f;
    }

    return raiz;
}

int main() {
    Punto p1, p2;

    cout << "Ingrese las coordenadas del primer punto (x1, y1): ";
    cin >> p1.x >> p1.y;

    cout << "Ingrese las coordenadas del segundo punto (x2, y2): ";
    cin >> p2.x >> p2.y;

    float distancia = calcularDistancia(p1, p2);
    cout << "La distancia entre los puntos es: " << distancia << endl;

    return 0;
}

