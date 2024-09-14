/*Escribir un programa que solicite cinco números enteros, los almacene en un arreglo
y luego calcule y muestre en pantalla el promedio de esos números.*/

#include <iostream>
#include <string>
using namespace std;

const int dim_fisica = 5;

//calcular promedio
/*int calcular_Promedio(int dim_Logica, int numeros[]) {
    int promedio = 0;
    for (int i = 0; i < dim_Logica; i++)
    {
        promedio += numeros[i];
    }
    return promedio/dim_Logica;
}*/

int main () {
    int num;
    int numeros[dim_fisica] = { };
    int dim_Logica = 0;
    int promedio = 0;

    for (int i = 0; i < dim_fisica; i++) //agregar elementos al arreglo y no debe superar la dim_fisica.
    {
        cout<<"ingrese un numero: ";
        cin>>num;
        numeros[i] = num;//guardar cada elemento dependiendo el indice.
        dim_Logica = dim_Logica+1; //aumentar la dim_logica a medida que se agregan elementos al arreglo.
    }

    for (int i = 0; i < dim_Logica; i++) //para recorrer sobre el arreglo numeros.
    {
        promedio += numeros[i];
    }

    cout<<"el promedio de los 5 numeros es: "<<promedio/dim_Logica/*calcular_Promedio(dim_Logica, numeros)*/;
    return 0;
}