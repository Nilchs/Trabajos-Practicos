/*Escribí un programa que solicite el ingreso de una cadena de caracteres e informe qué vocales
aparecen en la cadena, informando su existencia por única vez.
Por ejemplo, para 'programación' debería informar: a, i, o. */

#include <iostream>
#include <string>
using namespace std;

int main () {
    // definir las vocales
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    string cadena;

    cout<< "ingrese una cadena de caracteres: ";
    getline(cin, cadena);

    // Iterar sobre cada vocal y verificar si está presente en la cadena
    for (char vocal : vocales) {
        // Iterar sobre cada caracter de la cadena
        for (char caracter : cadena) {
            // Verificar si el caracter es una vocal
            if (tolower(caracter) == vocal) {
                cout << vocal << ", ";
                break; // Salir del bucle interno una vez que se encuentra la vocal
            }
        }
    }

    cout << endl;
    
    return 0;
}