/*a) Implementar la función promedio_de_edades(edad1, edad2, edad3).
b) Escribir un programa que solicite el ingreso por teclado de tres edades y luego
llame a la función creada en el punto anterior. Finalmente, informar el resultado
en pantalla.*/

#include <iostream>
#include <string>
using namespace std;

int promedio_de_edades(int edad1, int edad2, int edad3){
    int promedio;
    int suma = edad1+edad2+edad3;
    promedio = suma/3;
    return promedio;
}

int main () {
    int ed1, ed2, ed3;
    cout<<"ingrese la primer edad: ";
    cin>>ed1;
    cout<<"ingrese la segunda edad: ";
    cin>>ed2;
    cout<<"ingrese la tercer edad: ";
    cin>>ed3;

    
    cout<<"el promedio de las tres edades es: "<<promedio_de_edades(ed1, ed2, ed3);
    return 0;
}