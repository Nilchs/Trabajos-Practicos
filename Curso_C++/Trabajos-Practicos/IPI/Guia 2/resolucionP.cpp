/*Escribir un programa en C++ que solicite al usuario el ingreso por teclado de una serie de números enteros. El ingreso de datos finaliza cuando el usuario ingresa el número "0" (cero). (2 ptos)
El algoritmo deberá procesar los datos ingresados y calcular el promedio de los números positivos múltiplos de 5. (2 ptos)
Finalmente, se deberá imprimir en pantalla el valor obtenido como resultado del procesamiento. (1 pto)
Importante: incluir comentarios en el código fuente, para describir qué hace cada parte o bloque de código. (1 pto)*/

#include <iostream>
#include <string>
using namespace std;

int main () {

    int numero;
    float contador = 0;
    int sumatoria = 0;

    cout <<"ingresar un numero: ";
    cin >> numero;

    while (numero != 0)
    {
        if (numero > 0 && numero%5== 0)
        {
            contador++;
            sumatoria+=numero;
        }
        
        cout<< "ingresar otro numero: ";
        cin>> numero;
    }
    
    if (contador != 0)
    {
        float promedio = sumatoria/contador;
        cout<<"el promedio es: "<< promedio <<endl;
    }
    else
    {
        cout<<"no se ingresaron numeros.";
    }
    
    return 0;
}