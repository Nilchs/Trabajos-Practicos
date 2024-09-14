/*a) Implementar la función mayuscula(cadena) que transforme una cadena pasada
por parámetro en mayúsculas.
b) Escribir un programa que solicite el ingreso por teclado de una cadena y luego
llame a la función creada en el punto anterior para informar el resultado en
pantalla.*/

#include <iostream>
#include <string>
using namespace std;

string mayuscula(string cadena) {
    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}

int main () {
    string cadena;

    cout<<"ingrese una cadena: ";
    getline(cin, cadena);
    
    cout<<"cadena en mayusculas: "<<mayuscula(cadena)<<endl;  
    return 0;
}