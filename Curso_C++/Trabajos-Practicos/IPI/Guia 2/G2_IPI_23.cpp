/*23) Escribir un programa que solicite al usuario 2 palabras y determine si ambas palabras tienen la misma
longitud.*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    string frase;
    string frase1;

    cout<<"Ingrese la primera frase: ";
    getline(cin>>ws, frase);

    cout<<"Ingrese la segunda frase: ";
    getline(cin>>ws, frase1);

    if (frase.length() == frase1.length())
    {
        cout<<"Las dos frases ingresadas tienen la misma longitud."<<endl;
    }
    else
    {
        cout<<"Las dos frases ingresadas no tienen la misma longitud."<<endl;
    }
    
    return 0;
}