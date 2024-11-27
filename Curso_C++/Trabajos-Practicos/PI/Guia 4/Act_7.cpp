#include <iostream>
using namespace std;

/*
Escribir una función recursiva para calcular la potencia de un número. La función recibirá como parámetros al
número y un exponente (ambos enteros positivos), y retornará la potencia:
*/

int potencia(int base, int exponente) {
    if(exponente == 0) {
        return 1;
    }
    if(base == 0) {
        return 0;
    }
    return base * potencia(base, exponente - 1);
}

int main () {
    int num, exp;
    cout << "Ingrese un numero: ";
    cin >> num;
    cout << "Ingrese un exponente: ";
    cin >> exp;
    cout << "La potencia es: " << potencia(num, exp);
    return 0;
}