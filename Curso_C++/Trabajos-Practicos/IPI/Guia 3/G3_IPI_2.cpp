/*a) Implementar la función suma_digitos(numero) que, dado un número entero
como argumento, retorne la suma de sus dígitos. Por ejemplo, si el argumento de
la función es 438, deberá retornar 15 (pues 4+3+8=15).
b) Escribir un programa que solicite al usuario el ingreso de un número entero, y que
utilizando la función del ejercicio anterior, muestre en pantalla un mensaje que
informe al usuario la suma de los dígitos del número ingresado.*/

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

int main () {
    int num1;
    cout<<"ingrese un numero: ";
    cin>>num1;

    cout<<"la suma de los digitos es: "<<suma_digito(num1);
}