#include <iostream>
using namespace std;

/*
Escribir una función recursiva que, dadas dos listas enlazadas simples, retorne true si ambas listas tienen la
misma longitud (cantidad de nodos), false en caso contrario. Optimizar la función para que, en caso de que una
lista sea más corta que la otra (por ejemplo, la lista A tiene 10000 nodos y la lista B tiene 5 nodos), no se
continúe contabilizando la cantidad de nodos de la lista más larga.
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

bool compararLongitudes(Nodo* listaA, Nodo* listaB) {
    if (listaA == nullptr && listaB == nullptr) { // Case base: Si ambas listas están vacías
        return true;
    }
    if (listaA == nullptr || listaB == nullptr) { // Caso base: Si una lista está vacia y la otra no
        return false;
    }

    return compararLongitudes(listaA->siguiente, listaB->siguiente); // Caso recursivo: Continuar comparando los siguientes nodos de ambas listas
}

int main () {
    Nodo* listaA = nullptr;
    Nodo* listaB = nullptr;
    int numero;

    cout << "Ingrese numeros para la primera lista (-1 para finalizar): ";
    cin >> numero;
    while (numero != -1)
    {
        listaA = insertarAlInicio(listaA, numero);
        cout << "Ingrese otro numero para la primera lista (-1 para finalizar): ";
        cin >> numero;
    }

    cout << "Ingrese numeros para la segunda lista (-1 para finalizar): ";
    cin >> numero;
    while (numero != -1)
    {
        listaB = insertarAlInicio(listaB, numero);
        cout << "Ingrese otro numero para la segunda lista (-1 para finalizar): ";
        cin >> numero;
    }

    if (!compararLongitudes(listaA, listaB))
    {
        
        cout << "Las listas no tienen la misma longitud." << endl;
    }
    else
    {
        cout << "Las listas tienen la misma longitud." << endl;
    }
        
    return 0;
}