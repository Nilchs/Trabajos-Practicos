/*21) Escribe un programa que solicite al usuario un numero entero y luego imprima las tablas de multiplicar
desde el 1 hasta ese número (del 1 al 10), con el siguiente formato: Tabla de multiplicar del (numero):
numero x 1 = resultado
numero x 2 = resultado
.
.
numero x 10 = resultado*/

#include <iostream>
using namespace std;

int main () {
    int n;

    cout<<"ingrese un numero: ";
    cin>>n;

    for (int i = 1; i <= 10; i++)
    {
        cout<<"\n"<<n<<" x "<<i<<" = "<<n*i;
    }
    
    return 0;
}