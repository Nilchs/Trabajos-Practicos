/*19) Escribí un programa que solicite al usuario ingresar una palabra o frase y luego invierta su orden y la
muestre por pantalla.*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    string fraseInv;

    cout<<"Ingrese una frase: ";
    getline(cin>>ws, frase);

    for (int i = frase.length() - 1; i >= 0; i--)
    {
        fraseInv += frase[i];
    }

    cout<<"La frase invertida es: "<<fraseInv<<endl;
     
    return 0;
}