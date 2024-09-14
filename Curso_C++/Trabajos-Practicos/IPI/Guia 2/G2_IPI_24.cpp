/*Escribir un programa que solicite al usuario una frase y reemplace todas las letras ‘a’ por ‘b’.*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    cout<< "ingrese una frase: ";
    getline(cin, frase);

    for (int i = 0; i < frase.length(); i++)
    {
        char caracter = frase[i];

        if (caracter == 'a')
        {
            // cambiarla por una 'b'.
            frase[i] = 'b';
        }
        
    }
    
    cout << "Frase con todas las letras 'a' reemplazadas por 'b': " << frase << endl;

    return 0;
}