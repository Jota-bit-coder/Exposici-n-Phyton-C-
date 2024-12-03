/******************************************************************************

Implementa una función recursiva torresDeHanoi que resuelva el problema de las
Torres de Hanoi para n discos. La función debe imprimir cada movimiento necesario.



*******************************************************************************/
#include <iostream>
using namespace std;

void Hanoi(int n, char origen, char destino, char auxiliar){
    //basic case
    if (n == 1){
        //Mover del origen al destino
        cout<<" Mover disco 1 de "<<origen<<" a "<<destino<<endl;
        return;
    }
    Hanoi(n-1,origen, auxiliar, destino);
    cout<<" Mover disco "<<n<<" de "<<origen<<" a "<<destino<<endl;
    Hanoi(n-1,auxiliar,destino,origen);
}
int main()
{
    int n;
    char origen, destino, auxiliar;
    cout<<" Ingrese el numero de discos: ";
    cin>>n;
    Hanoi(n, 'O', 'D', 'A');

    return 0;
}