/*11) Leer desde teclado una cadena de caracteres y luego:
a) Mostrar la longitud de la misma.
b) Convertir la cadena a mayúsculas y mostrarla en pantalla.
c) Mostrar el último carácter.
*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    string fraseMayus;

    cout<<"Ingrese una frase: ";
    getline(cin>>ws, frase);

    cout<<"\n la longitud de la frase es: "<<frase.length()<<endl;// consigna a).

    for (unsigned i = 0; i < frase.length(); i++)
    {
        fraseMayus += toupper(frase[i]);
    }
    
    cout<<"\n la frase convertida en mayusculas es: "<<fraseMayus<<endl;// consigna b). 

    char ultimoCaracter = frase[frase.length() - 1];

    cout<<"\n El ultimo caracter de la frase es: "<<ultimoCaracter<<endl;// consigna c).

    return 0;
}