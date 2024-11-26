#include <iostream>
using namespace std;

/*
Escribir una función recursiva que, dado un número entero, lo imprima en orden inverso.
Ejemplo: si el número es 5182, la función debe imprimir 2815.
*/

int funcionInvertir(int a) {
    // Caso base
    if(a == 0)
    {
        return 0;
    }
    // Caso recursivo
    else
    {
        int b = a % 10; // b contiene el ultimo digito del numero a invertir
        cout << b; // Imprime el ultimo digito
        return funcionInvertir(a / 10); // Se llama a la funcion recursivamente con el numero sin el ultimo digito
    }
}
int main () {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;

    cout << "El numero invertido es: ";
    funcionInvertir(numero);

    return 0;
}