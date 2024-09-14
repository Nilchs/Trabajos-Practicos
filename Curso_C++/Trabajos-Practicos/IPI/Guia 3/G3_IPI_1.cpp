/*a) Escribir la función es_par(numero) que determine si el número entero que recibe
a través del parámetro “numero” es o no es par. La función deberá retornar 1 si
“numero” efectivamente es par y 0 en caso contrario.
b) Escribir un programa que solicite al usuario el ingreso de un número entero, y que
utilizando la función, es_par(numero) del ejercicio anterior, determine si el
número ingresado es par o impar, imprimiendo un mensaje que lo informe al
usuario por pantalla.*/

#include <iostream>
#include <string>
using namespace std;

//declaracion y definicion de Funciones
int es_par(int numero){
    if (numero %2==0) {
        return 1;
    } else {
        return 0;
    }
}

int main () {
    int num1;
    cout<<"ingrese un numero entero: ";
    cin>>num1;
    
    //invocacion de la funcion es_par
    if (es_par(num1)==1)
    {
        cout<<"el numero ingresado es PAR";
    } else
    {
        cout<<"el numero ingresado es IMPAR";
    }

    return 0;
}