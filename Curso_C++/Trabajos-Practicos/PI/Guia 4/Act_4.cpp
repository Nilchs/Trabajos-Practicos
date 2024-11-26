#include <iostream>
using namespace std;

/*
Escribir una función recursiva que, dado un número entero, retorne la cantidad de dígitos que tiene.
Ejemplo: si el número es 650, la función debe retornar 3.
*/

int cantidad_digitos(int n) {
     int contador = 0;
    if(n == 0) // Caso base: Si el número es 0, retorna 0, indicando que no hay dígitos
    {
        return 0;
    }
    // Caso recursivo
    n = n / 10; // Elimina el último dígito del número al dividirlo por 10
    contador++;
    return 1 + cantidad_digitos(n); // Retorna 1 más el resultado de llamar recursivamente la función con el número modificado
}

int main () {
    int numero;
    cout << "Ingrese un numero entero: ";
    cin >> numero;

    cout << "La cantidad de digitos del numero " << numero << " es: " << cantidad_digitos(numero) << endl;
        
    return 0;
}