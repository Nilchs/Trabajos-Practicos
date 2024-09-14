/*
Escribir un programa que permita al usuario ingresar números enteros positivos (los números ingresados no
deben almacenarse). Al finalizar, informar la cantidad de veces que apareció cada dígito (del 0 al 9) en todos los
números.
Ejemplo: Si el usuario ingresa los números 1156, 23, 73364, 988, 1003, 5, se debe informar que el 0 apareció 2
veces, el 1 apareció 3 veces, el 2 apareció 1 vez, el 3 apareció 4 veces, etc.
*/

#include <iostream>
#include <string>
using namespace std;

const int dimFis = 10; //Números del 0 al 9.

int main () {
    int arreglo[dimFis] = {0}; //Inicializar cada elemento con el valor 0.
    int numero;

    cout<<"Ingrese numeros enteros positivos(ingrese un numero negativo para finalizar): ";
    
    while (true)
    {
        cin>>numero;
        if (numero < 0)
        {
            break;
        }

        int digito;
        while (numero > 0) //Procesar cada dígito.
            {
            digito = numero % 10; //Obtener el último dígito del número.
            arreglo[digito]++; //Incrementar el contador correspondiente al dígito.
            numero = numero / 10; //Eliminar el último dígito del número.
        }
    }
    
    cout<<"\nCantidad de veces que aparecio cada digito:"<<endl;
    for (int i = 0; i < dimFis; i++)
    {
        cout<<"Digito "<<i<<": "<<arreglo[i]<<" veces."<<endl;
    }

    return 0;
}