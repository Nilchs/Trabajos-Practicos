/*a) Implementar la función invertir_cadena(cadena) que muestre una cadena pasada
por parámetro en orden inverso.
b) Escribir un programa que solicite el ingreso por teclado de una cadena y luego
llame a la función creada en el punto anterior para informar el resultado en
pantalla.*/

#include <iostream>
#include <string>
using namespace std;

string invertir_cadena(string cadena){

}

int main () {
    string cadena;
    cout<<"ingrese una cadena: ";
    getline(cin>>ws, cadena);
    cout<<"la cadena invertida es: "<<invertir_cadena(cadena)<<endl;
    return 0;
}