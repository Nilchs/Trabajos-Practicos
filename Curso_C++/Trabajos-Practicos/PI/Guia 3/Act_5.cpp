/*Se lee de teclado una secuencia de números enteros, finalizando cuando el usuario ingresa un cero (que no
debe insertarse). Los números leídos deberán ser almacenados en una lista enlazada simple. Hacer tres
versiones, insertando en cada una con diferente criterio, a saber:
a) Al inicio de la lista.
b) Al final de la lista.
c) En la posición correcta para que la lista quede ordenada de menor a mayor. Si el número a insertar ya
se encontraba en la lista, deberá quedar antes que todas sus repeticiones.
Finalmente, imprimir la lista.*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

int main () {
    Nodo * inicio = nullptr;
    int n;
    cout << "Ingrese un número(0 para finalizar): ";
    cin >> n;
    
    // a).
    while (n != 0) {
        Nodo * nuevo = new Nodo();
        nuevo->dato = n;
        nuevo->siguiente = inicio;
        inicio = nuevo;
        cout << "Ingrese el siguiente numero(0 para finalizar): ";
        cin >> n;
    }
        
    return 0;
}