/* Escribí un programa que, dada una frase, imprima una a una las palabras que la contienen. precondiciones: cada palabra está separada por un espacio No existen espacios al principio ni al final de la frase ingresada.
Ejemplo: si la frase es “aquí me pongo a cantar” se imprimirá:
aquí
me
pongo
a
cantar */

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    cout << "ingrese una frase: ";
    getline(cin>>ws, frase);

    // Iterar a través de la frase y extraer cada palabra
    string palabra = "";
    for (char caracter : frase) {
        // Si el caracter es un espacio, imprimir la palabra actual
        if (caracter == ' ') {
            cout << palabra << endl;
            palabra = ""; // Reiniciar la palabra para la próxima iteración
        } else {
            // Si no es un espacio, agregar el caracter a la palabra actual
            palabra += caracter;
        }
    }

    cout<< palabra <<endl;

    return 0;
}