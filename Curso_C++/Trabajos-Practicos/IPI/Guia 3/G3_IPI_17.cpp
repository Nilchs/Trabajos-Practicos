/*Escribir una función que reciba un arreglo de números enteros y devuelva la suma de
los elementos que son pares.*/

#include <iostream>
#include <string>
using namespace std;

const int dim_fisica = 4;

int suma_pares(int numeros[], int dim_logica) {
    int suma = 0;
    
    for (int i = 0; i < dim_logica; i++)
    {
        if (numeros[i]%2==0)
        {
            suma += numeros[i]; 
        }    
    }
    return suma;
}

int main () {
    int numeros[dim_fisica] = {};
    int dim_Logica = 0;

    for (int i = 0; i < dim_fisica; i++)
    {
        
        cout<<"ingrese un numero: ";
        cin>>numeros[i];
        dim_Logica = dim_Logica+1;
    }
    
    cout<<"la suma de los elementos pares es: "<<suma_pares(numeros, dim_Logica);
    return 0;
}