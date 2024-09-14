/*a) Implementar la función cantidad_vocales(cadena), la cual debe informar la
cantidad de vocales sin tilde que contiene la cadena pasada por parámetro,independientemente si son minúsculas o mayúsculas.
b) Escribir un programa que solicite el ingreso por teclado de una cadena y luego
llame a la función creada en el punto anterior. Finalmente, informar el resultado
en pantalla.*/

#include <iostream>
#include <string>
using namespace std;

int cantidad_vocales(string cadena) {
        string vocales = "aeiou"; //las pongo juntas en un string, y si encuentra una al menos de ahi la toma.
        int contador = 0; //variable para guardar la cantidad de vocales sin tilde.
        for (unsigned int i = 0; i < cadena.length(); i++) //va a iterar sobre cada indice de la cadena.(se pone unsigned a int porque en la condicion se trabaja con una cadena que no tiene signo.)
        {
            if (vocales.find(tolower(cadena[i])) != -1) //busca las vocales en la cadena y a su vez transforma la cadena a minuscula dentro del parametro de find.
            {
                contador++;
            }
            
        }
        return contador;
    }

int main () {
    string cadena;
    cout<<"ingrese una cadena de caracteres: ";
    getline(cin, cadena);

    cout<<"la cantidad de vocales sin tilde son: "<<cantidad_vocales(cadena);
    return 0;
}