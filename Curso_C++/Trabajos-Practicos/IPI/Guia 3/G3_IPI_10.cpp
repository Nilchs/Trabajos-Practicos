/*Escribí un programa que solicite el ingreso de números enteros, finalizando luego de
leer un número para el cual la suma de sus dígitos sea menor que 10 o mayor que 50.
Informar la cantidad de números impares leídos. Utilizá las funciones es_par(número) y
suma_dígitos(número) implementadas anteriormente.*/

#include <iostream>
#include <string>
using namespace std;

int suma_digito(int numero){
    int suma = 0;
    while (numero != 0)
    {
        int resto = numero%10;
        suma += resto;
        numero = numero/10;
    }
    return suma;
}

int es_par(int numero){
    if (numero %2==0) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int numero; 
    int contador_impares = 0;

    while (true) { // Bucle infinito, se romperá cuando se cumpla la condición de salida
        cout << "Ingrese un numero entero: ";
        cin >> numero; 

        int suma = suma_digito(numero); 
        if (suma < 10 || suma > 50) { // Verifica si la suma de los dígitos es menor que 10 o mayor que 50
            break; // Sale del bucle si se cumple la condición
        }

        if (numero != es_par(numero)) { // Verifica si el número es impar
            contador_impares++; // Incrementa el contador de números impares
        }
    }

    cout << "Cantidad de numeros impares leidos: " << contador_impares << endl;

    return 0;
}