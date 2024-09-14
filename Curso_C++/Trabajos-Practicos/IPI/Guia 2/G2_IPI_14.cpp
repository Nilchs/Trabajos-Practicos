/*Calcular la sumatoria de una lista de números enteros ingresados por teclado. La entrada de datos
finaliza cuando se ingresa un valor negativo.*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    int numero;
    int sumatoria = 0;

    // Solicitar al usuario que ingrese números enteros
    cout << "Ingrese una lista de numeros enteros (ingrese un numero negativo para terminar):" << endl;
    
    // Leer los números hasta que se ingrese un valor negativo
    while (true) {
        cin >> numero;
        
        // Verificar si el número ingresado es negativo
        if (numero < 0) {
            break; // Salir del bucle si se ingresa un número negativo
        }
        
        // Agregar el número a la sumatoria
        sumatoria += numero;
    }

    // Mostrar la sumatoria de los números ingresados
    cout << "La sumatoria de los numeros ingresados es: " << sumatoria << endl;
        
    return 0;
}