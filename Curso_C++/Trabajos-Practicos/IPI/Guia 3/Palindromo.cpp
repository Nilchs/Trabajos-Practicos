#include <iostream>
#include <string>
using namespace std;

string quitarEspacios(string palabra){
    
    string palabraSinEspacios;

    for (unsigned i = 0; i < palabra.length(); i++)
    {
        if (palabra[i] != ' ')
        {
            palabraSinEspacios += palabra[i];
        }
    }
    return palabraSinEspacios;
}

bool esPalindromo(string palabra){

    int a = 0;
    int b = (palabra.length() - 1);

    for (unsigned int i = 0; i < palabra.length(); i++)
    {
        if (tolower(palabra[a]) == tolower(palabra[b])) {
            a++;
            b--;
        }
        else {
            return false;
        }
        
    }
    return true;
}

int main () {
    string frase;
    string fraseSinEspacios;

    cout<<"Ingrese una frase o palabra: ";
    getline(cin, frase);

    fraseSinEspacios = quitarEspacios(frase);

    if (esPalindromo(fraseSinEspacios))
    {
        cout<<"la palabra o frase ingresada es palindroma"<<endl;
    } 
    else
    {
        cout<<"la palabra o frase ingresada no es palindroma"<<endl;
    }
    
    return 0;
}