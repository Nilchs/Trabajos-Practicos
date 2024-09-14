/*Escribí un programa que solicite el ingreso de números enteros positivos. Se deberán analizar los
dígitos que componen a cada número ingresado informando:
a) La cantidad de dígitos pares e impares que posee cada número ingresado.
b) Cuántas veces apareció en total el dígito 5 en todos los números procesados.
La lectura de números finaliza al leer el valor -1.*/

#include <iostream>

using namespace std;

int main() {
    int numero;
    int digitosPares, digitosImpares, digitosCinco, totalCinco;

    // Inicializar variables
    digitosPares = digitosImpares = digitosCinco = totalCinco = 0;

    // Solicitar al usuario el ingreso de números enteros positivos
    cout << "Ingrese numeros enteros positivos (-1 para finalizar):" << endl;

    // Leer los números hasta que se ingrese -1
    while (true) {
        cin >> numero;

        // Verificar si se ingresó -1 para finalizar la lectura de números
        if (numero == -1) {
            break;
        }

        // Procesar cada dígito del número
        while (numero > 0) {
            int digito = numero % 10; // Obtener el último dígito del número

            // Verificar si el dígito es par o impar
            if (digito % 2 == 0) {
                digitosPares++;
            } else {
                digitosImpares++;
            }

            // Verificar si el dígito es igual a 5
            if (digito == 5) {
                digitosCinco++;
            }

            numero /= 10; // Eliminar el último dígito del número
        }

        // Sumar la cantidad de veces que apareció el dígito 5 en el número actual al total
        totalCinco += digitosCinco;

        // Reiniciar el contador de dígitos 5 para el próximo número
        digitosCinco = 0;
    }

    // Mostrar resultados
    cout << "Cantidad de digitos pares: " << digitosPares << endl;
    cout << "Cantidad de digitos impares: " << digitosImpares << endl;
    cout << "Cantidad total de veces que aparecio el digito 5: " << totalCinco << endl;

    return 0;
}

