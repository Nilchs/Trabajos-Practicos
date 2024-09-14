/*Escribir una función llamada cantidad_ocurrencias que reciba como parámetro un arreglo de tipo int, su
dimensión lógica y un parámetro con un valor de tipo int también. La función debe retornar la cantidad de
ocurrencias del valor en el arreglo.*/

#include <iostream>
#include <string>
using namespace std;

const int dimFis = 5;

int cantidad_ocurrencias(int arreglo[], int dimLog, int numero) {

    int contador = 0;

    for(int i = 0; i <= dimLog; i++)
    {
        if(arreglo[i] == numero)
        {
            contador++;
        }
    }
    return contador;
}

int main () {
    int arreglo[dimFis], dimLog, numero, h;

    cout << "Ingrese numeros para el arreglo (ingrese un valor negativo para finalizar): ";
    for(int j = 0; j <= dimFis; j++)
    {
        cin >> arreglo[j];
        if(arreglo[j] < 0) // Usar un número negativo para finalizar
        {
            break;
        }
    }

    // Ingresar el numero a buscar en el arreglo
    cout << "Ingrese un numero a buscar en el arreglo: ";
    cin >> numero;

    // Averiguar la dimensión lógica
    h = 0;
    while (h < dimFis && arreglo[h] >= 0)
    {  // Verifica hasta llegar al final del arreglo o encontrar un número negativo
        h++;
    }
    dimLog = h;

    cout << "el numero: "<<numero<< " aparece: "<<cantidad_ocurrencias<< "veces en el arreglo";

    return 0;
}