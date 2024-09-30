/*Escribir un programa en C++ que realice una búsqueda secuencial en un arreglo desordenado de cadena de
caracteres. El programa debe solicitar al usuario que ingrese, por teclado, nombres de diferentes colores (elegir
una condición de corte apropiada). Éstos deben ser almacenados en un arreglo. Por otra parte, se debe ofrecer
una opción de búsqueda, donde se solicite al usuario ingresar el nombre de un color e informar si dicho color se
encuentra o no en el arreglo.*/

#include <iostream>
#include <string>
using namespace std;

const int DF = 50;

int busquedaSecuencialDesordenada(string arreglo[], int dimension, string buscado) {
    
    int i = 0;
    while (i < dimension && arreglo[i] != buscado) {
        i++;
    }
    if (i < dimension) {
        return i;
    }
    else {
        return -1; 
    }
}

int main () {
    string arreglo[DF];
    int dimension = 0;
    string color;

    cout << "Ingrese el color a buscar(ingrese 'fin' para finalizar): ";
    getline(cin>>ws, color);
    
    for (unsigned int i = 0; i < color.length(); i++) // Pasar color a minuscula.
    {
        color[i] = tolower(color[i]);
    }
    
    while (dimension < DF && color != "fin")
    {
        arreglo[dimension] = color;
        dimension++;
        cout << "\nIngrese el color a buscar(ingrese 'fin' para finalizar): ";
        getline(cin>>ws, color);
    }

    cout << "\nIngrese un color a buscar: ";
    getline(cin, color);

    if (busquedaSecuencialDesordenada(arreglo, dimension, color) != -1)
    {
        cout << "el color " << color <<" se encontro en el arreglo.";
    }
    else
    {
        cout << "El color no se encuentra en el arreglo.";
    }
    
        
    return 0;
}