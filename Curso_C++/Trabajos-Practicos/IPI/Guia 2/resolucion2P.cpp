#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    cout<<"ingrese una frase: ";
    getline(cin>>ws, frase);

    while (frase.find(" ")== -1)
    {
        cout<<"ingrese otra frase: ";
        getline(cin>>ws, frase);
    }
    int contador = 0;
    int longitud = frase.length();

    for (int i = 0; i < longitud; i++) // puede ser i<= longitud -1, cualquiera de las dos esta bien.
    {
        char caracter = frase[i];
        if (caracter == 'S' || caracter == 's') //[ frase.find("S")!=-1 || frase.find("s")!=-1 ] -> antes pero contaba si habia una S en toda la cadena y la sumaba al contador siempre.
        {
            contador++;
        }
        
    }
    cout<<"la cantidad de s: "<<contador<<endl;

    return 0;
}