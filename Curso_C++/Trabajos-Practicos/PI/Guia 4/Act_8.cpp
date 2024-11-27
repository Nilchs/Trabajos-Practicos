#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba un string y lo retorne con sus caracteres invertidos.
*/

string invertir(string cadena) {
    if(cadena.length() == 1) {
        return cadena;
    }
    if(cadena == "") { 
        return 0;
    }
    return cadena[cadena.length() - 1] + invertir(cadena.substr(0, cadena.length() - 1)); // Se suma el último caracter y se llama a la función recursiva con el string restante 
}

int main () {
    string frase;
    cout << "Ingrese una frase: ";
    getline(cin >> ws, frase);

    cout << "La frase invertida es: " << invertir(frase) << endl;

    return 0;
}