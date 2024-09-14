// Solicitar el ingreso de un número entero. Si el número ingresado es impar, se deberán imprimir los
// números correlativos desde el ingresado hasta el doble de este. Si el número ingresado es par, se deberán
// mostrar los números pares desde el ingresado hasta el doble del ingresado. Por ejemplo, si se ingresa un
// 8, se mostrará 8, 10, 12, 14, 16. Si se ingresa un 5, se mostrarán 5, 6, 7, 8, 9, 10.

#include <iostream>
#include <string>
using namespace std;

int main () {
    int numero;
    cout << "ingrese un numero ";
    cin >> numero;

    if (numero % 2 == 0)
    {
        for (int i = numero; i <= numero * 2; i += 2)
            cout << i << " ";
    }
    else
    {
        for (int i = numero; i <= numero * 2; i++)
            cout << i << " ";
    }
    
    return 0;
}