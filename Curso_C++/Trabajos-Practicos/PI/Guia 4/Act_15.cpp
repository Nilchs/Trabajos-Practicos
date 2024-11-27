#include <iostream>
using namespace std;

/*
Escribir una función recursiva que, dada una lista de enteros, retorne la suma de todos sus elementos. En caso
de que la lista esté vacía, deberá retornar 0.
Ejemplo: si la lista contiene 5 - 2 - 1 - 9 retornará 17.
*/

struct Nodo
{
    int dato;
    Nodo* siguiente;
};

Nodo* insertarAlInicio(Nodo* inicio, int numero)
{
    Nodo* nuevoNodo = new Nodo; // Crear nodo nuevo
    nuevoNodo -> dato = numero;
    nuevoNodo -> siguiente = inicio;
    inicio = nuevoNodo; // Que el nuevo nodo sea el inicio, osea el primer elemento
    return inicio;
}

int sumaLista(Nodo* inicio)
{
    if(inicio == nullptr) // Caso base: Si la lista está vacía
    {
        return 0;
    }
    else
    {
        return inicio -> dato + sumaLista(inicio -> siguiente); // Caso recursivo: Sumar el dato del nodo actual con el siguiente nodo llamando a la función cambiando de elemento
    }
}

int main () {
    Nodo* inicio = nullptr;  

    int numero;
    cout << "Ingrese un numero (-1 para finalizar): ";
    cin >> numero;
    while(numero != -1)
    {
        inicio = insertarAlInicio(inicio, numero);
        cout << "Ingrese otro numero (-1 para finalizar): ";
        cin >> numero;
    }

    int resultado = sumaLista(inicio);
    cout << "La suma de los elementos de la lista es: " << resultado;
          
    return 0;
}