// Modificar el programa anterior para que, si se ingresa un número negativo, no se procese, pero continúe
// la ejecución. Finalmente, mostrar por separado la suma de los números positivos pares e impares
// ingresados.

#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int cantidadNumeros;
    int sumaPares = 0;
    int sumaImpares = 0;
    
    // Solicitar al usuario que ingrese la cantidad de números a procesar
    cout << "Ingrese la cantidad de numeros a procesar: ";
    cin >> cantidadNumeros;
    
    // Verificar si la cantidad ingresada es válida
    if (cantidadNumeros <= 0)
    {
        cout << "La cantidad de numeros ingresada no es valida." << endl;
        return 1; // Salir del programa con código de error
    }
    
    // Solicitar al usuario que ingrese los números uno a uno y calcular la suma
    for (int i = 0; i < cantidadNumeros; i++)
    {
        int numero;
        cout << "Ingrese el numero " << i + 1 << ": ";
        cin >> numero;
        
        // Verificar si el número es negativo, si lo es, continuar con la siguiente iteración
        if (numero < 0)
        {
            cout << "El numero ingresado es negativo, no se procesara." << endl;
            continue;
        }
        
        // Verificar si el número es par o impar y sumarlo a la suma correspondiente
        if (numero % 2 == 0)
        {
            sumaPares += numero;
        }
        else
        {
            sumaImpares += numero;
        }
    }
    
    // Mostrar la suma total de los números positivos pares e impares ingresados
    cout << "La suma total de los numeros pares ingresados es: " << sumaPares << endl;
    cout << "La suma total de los numeros impares ingresados es: " << sumaImpares << endl;
    
    return 0;
}