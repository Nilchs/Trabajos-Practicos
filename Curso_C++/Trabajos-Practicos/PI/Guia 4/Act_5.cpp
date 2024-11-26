#include <iostream>
using namespace std;

/*
Escribir una función recursiva que calcule la suma de los cuadrados de los N primeros números positivos.
Ejemplo: si N = 4 la suma es  1^2 + 2^2 + 3^2 + 4^2 = 30.
*/

int sumaCuadrados(int n) {
    if (n == 0) {
        return 0; // Caso base
    }
    return (n * n) + sumaCuadrados(n - 1); // Caso recursivo
}

int main () {
    int N;
    cout << "Ingrese un numero: ";
    cin >> N;

    cout << "La suma de los cuadrados de los " << N << " primeros numeros positivos es: " << sumaCuadrados(N);

    return 0;
}