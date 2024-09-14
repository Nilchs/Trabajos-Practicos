/*22) Escribir un programa que solicite al usuario una frase y devolver como resultado la cantidad de letras ‘a’
que contiene*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    int contador = 0;
    string letra = "a";

    cout<<"ingrese una frase: ";
    getline(cin, frase);

    for (unsigned int i = 0; i < frase.length(); i++)
    {
        if (letra.find(tolower(frase[i])) != -1)
        {
            contador++;
        }
        
    }
    
    cout<<"La cantidad de letras 'a' que contiene la frase es: "<<contador;
    return 0;
}