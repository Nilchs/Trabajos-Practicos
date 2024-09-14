#include <iostream>
#include <string>

using namespace std;

int main() {
    string cadena;
    int x = 0;

    while (true)
    {
        cout<< "ingrese una cadena: ";
        getline(cin, cadena);

        if (cadena.length() >= 10)
        {
            break; //frenar el bucle
        }
        else
        {
            cout<<"ingrese una cadena con al menos 10 caracteres."<<endl;
        }
    }
    
    for (int i = 0; i < cadena.length(); i++)
    {
        char y = tolower(cadena[i]); // convertir el caracter a minuscula para compara con las vocales.

        if (y == 'a' || y == 'e' || y == 'o')
        {
            x++;
        }
        
    }
    
    cout << "la cadena "<<cadena<< " tiene "<<x<< " vocales abiertas (a, e, o)."<<endl;

    return 0;
}