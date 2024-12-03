#include <iostream>
using namespace std;

class CuentaBancaria { // Clase para representar una cuenta bancaria
private:
    float saldo;  

public:
    
    CuentaBancaria() { //Constructor
        saldo = 0.0f;  
    }

    void depositar(float cantidad) {  // Método para depositar dinero en la cuenta
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "Has depositado " << cantidad << ". Saldo actual: " << saldo << endl;
        } else {
            cout << "La cantidad a depositar debe ser mayor que 0." << endl;
        }
    }

    void retirar(float cantidad) {    // Método para retirar dinero de la cuenta
        if (cantidad > 0) {
            if (cantidad <= saldo) {
                saldo -= cantidad;
                cout << "Has retirado " << cantidad << ". Saldo actual: " << saldo << endl;
            } else {
                cout << "No tienes suficiente saldo para realizar este retiro." << endl;
            }
        } else {
            cout << "La cantidad a retirar debe ser mayor que 0." << endl;
        }
    }

    void mostrarSaldo() const {     // Método para retirar dinero de la cuenta
        cout << "Saldo actual: " << saldo << endl;
    }
};

//Función interactiva
int main() {
    CuentaBancaria cuenta;  
    int opcion;  

    do {
        // Menú interactivo
        cout << "\nCuenta Bancaria\n";
        cout << "1. Depositar dinero\n";
        cout << "2. Retirar dinero\n";
        cout << "3. Ver saldo\n";
        cout << "4. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        float cantidad;  

        switch (opcion) {
            case 1:
                cout << "Ingresa la cantidad a depositar: ";
                cin >> cantidad;
                cuenta.depositar(cantidad);  
                break;
            case 2:
                cout << "Ingresa la cantidad a retirar: ";
                cin >> cantidad;
                cuenta.retirar(cantidad); 
                break;
            case 3:
                cuenta.mostrarSaldo(); 
                break;
            case 4:
                cout << "Operaciones Finalizadas" << endl;
                break;
            default:
                cout << "Opción no válida. Por favor elige una opción válida." << endl;
        }
    } while (opcion != 4);  

    return 0;
}

