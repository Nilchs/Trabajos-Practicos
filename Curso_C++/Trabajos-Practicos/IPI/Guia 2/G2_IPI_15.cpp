/*Calcular el promedio de los valores ingresados por teclado. La entrada de datos finaliza cuando se
ingresa un 0 (cero).*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main () {
    int numero;
    int cantidadNumeros = 0;
    int sumatoria = 0;

    cout<< "ingrese una lista de numeros enteros(finalizar ingresando 0): "<< endl;
    while (true)
    {
        cin>> numero;

         // Verificar si se ingresó un 0
        if (numero == 0) {
            break; // Salir del bucle si se ingresa un 0
        }
        
        // Agregar el número a la suma y aumentar el contador
        sumatoria += numero;
        cantidadNumeros++;
    }

    // Verificar si se ingresó al menos un número
    if (cantidadNumeros > 0) {
        // Calcular el promedio
        double promedio = static_cast<double>(sumatoria) / cantidadNumeros;
        // Mostrar el promedio
        cout << "El promedio de los numeros ingresados es: " << promedio << endl;
    } else {
        // Informar al usuario si no se ingresó ningún número
        cout << "No se ingresaron numeros para calcular el promedio." << endl;
    }

    return 0;
}