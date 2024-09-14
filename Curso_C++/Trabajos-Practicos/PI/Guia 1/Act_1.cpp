#include <iostream>
#include <string>
using namespace std;

void Funcion(int num, char caracter) {

    if (num > 0) {
        for (int i = 0; i <= num; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout<<caracter;
            }
            cout << endl;
        }
    }
    else {
        cout<<"El numero ingresado no es positivo.";
    }
}

int main () {
    int num;
    char caracter;

    cout<<"Ingrese un caracter: ";
    cin>>caracter;

    cout<<"Ingrese un numero positivo: ";
    cin>>num;

    Funcion(num, caracter);
    
    return 0;
}