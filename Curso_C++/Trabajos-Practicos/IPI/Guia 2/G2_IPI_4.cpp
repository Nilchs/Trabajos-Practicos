// Escribir un programa que solicite ingresar una cantidad de números enteros a procesar. Luego, permitir
// al usuario ir ingresando uno a uno la cantidad pedida de números. Una vez finalizado el ingreso, se deberá
// mostrar la suma total de los números ingresados.

#include <iostream>
#include <string>
using namespace std;

int main () {
    int numero, numeroProcesar;
    int suma = 0;

    cout<<"cantidad de numeros a procesar: ";
    cin>>numeroProcesar;

    if (numeroProcesar > 0)
    {
        for (int i = 0; i < numeroProcesar; i++)
        {
            cout<<"ingrese el numero "<<i+1<<": ";
            cin>>numero;
            suma += numero;
        }
        cout<<"la suma de los numeros ingresados es: "<<suma<<endl;
    }
    else
    {
        cout<<"la cantidad de numeros ingresados no pueden ser procesados.";
    }
    
    return 0;
}