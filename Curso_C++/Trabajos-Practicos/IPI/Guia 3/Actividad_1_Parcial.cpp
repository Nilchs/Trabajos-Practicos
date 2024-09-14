#include <iostream>
#include <string>
using namespace std;

//Funciones
void menu() {
    cout<<endl;
    cout<<"Menu:"<<endl;
    cout<<"1: Transformar el primer caracter a Mayuscula."<<endl;
    cout<<"2: Transformar todas las vocales por un '@'."<<endl;
    cout<<"3: Devolver el ultimo caracter de la cadena o frase."<<endl;
    cout<<"4: Salir del programa."<<endl;
}

string primerMayus(string cadena) {
    
    cout<<"\nIngrese una cadena o frase: ";
    getline(cin>>ws, cadena);

    if (cadena.length() > 0)//verifica que por lo menos ingreso un caracter o mas.
    {
        cadena[0] = toupper(cadena[0]);//cambia solamente el primer caracter a mayuscula.
    }
    
    return cadena;
}

string cambioVocales(string cadena) {
    string vocales = "aeiou";

    cout<<"\nIngrese una cadena o frase: ";
    getline(cin, cadena);

    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        if (vocales.find(tolower(cadena[i])) != -1)//busca las vocales en la cadena y a su vez transforma la cadena a minuscula dentro del parametro de find.
        {
            cadena[i] = '@';//a ese caracter que en este caso es vocal le asigna un nuevo valor.
        }
    }
    return cadena;
}

char ultimoCaracter(string cadena) {
    
    char Caracter1;
    cout<<"\ningrese una cadena o frase: ";
    getline(cin>>ws, cadena);

    for (unsigned int i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] != (cadena.length() - 1))//compara si el caracter es el ultimo de la cadena.
        {
            Caracter1 = cadena[i];//el ultimo caracter lo guarda en una variable char.   
        }
    }
    
    return Caracter1;//retorna el ultimo caracter.
}

int main () {
    string cadena;
    int opcion;

    do
    {
        menu();

        cout<<"\nSelecciona una opcion: ";
        cin>>opcion;
        cin.ignore();

        switch (opcion)
        {
        case 1:
            cout<<"\nLa cadena modificada es: "<<primerMayus(cadena)<<endl;
            break;

        case 2:
            cout<<"\nLa cadena modificada es: "<<cambioVocales(cadena)<<endl;
            break;

        case 3:
            char Caracter;
            Caracter = ultimoCaracter(cadena);
            cout<<"\nEl ultimo caracter de la cadena o frase es: "<<"'"<<Caracter<<"'"<<endl;
            break;
        
        case 4:
            cout<<"Saliendo del programa...\n";
            break;
        
        default:
            cout<<"Opcion no valida, por favor intenta de nuevo.\n";
            break;
        }

    } while (opcion != 4);
        
    return 0;
}