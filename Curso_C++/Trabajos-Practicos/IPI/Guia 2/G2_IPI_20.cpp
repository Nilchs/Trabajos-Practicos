/*20) Escribe un programa que solicite al usuario ingresar un carácter y un número entero positivo. Luego
imprime en pantalla un triángulo formado por el carácter ingresado, con altura igual al número que se
ingresó.
Ejemplo:
Ingresa un carácter: #
Ingresa un número entero positivo: 5
#
##
###
####
#####*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    int num;
    char caracter;

    cout<<"Ingrese un caracter: ";
    cin>>caracter;

    cout<<"Ingrese un numero positivo: ";
    cin>>num;

    if (num > 0)
    {
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout<<caracter;
            }
            cout << endl;
        }
    }
    else
    {
        cout<<"El numero ingresado no es positivo.";
    }
    
    return 0;
}