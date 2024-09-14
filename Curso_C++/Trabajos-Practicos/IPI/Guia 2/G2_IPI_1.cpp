// Solicitar el ingreso de un número entero. Si el número leído es par, imprimir la leyenda 'El número es
// PAR'. En caso contrario, deberá mostrar el texto 'El número es IMPAR'. Un número es par si el resto de
// dividirlo por 2 es 0.

#include <iostream>
#include <string>
using namespace std;

int main () {
    
    int numero;
    cout << "ingrese un numero ";
    cin >> numero;

    if (numero % 2 == 0)
    {
        cout << "el numero" <<numero<< "es par";
    }
    else
    {
        cout << "el numero" <<numero<< "es impar";
    }
    
    return 0;
}