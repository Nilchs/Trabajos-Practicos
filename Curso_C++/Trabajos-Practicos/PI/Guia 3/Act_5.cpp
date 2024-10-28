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

void imprimir_lista(Nodo * inicio) {
    for (Nodo * aux = inicio;  aux != nullptr; aux = aux->siguiente) {
        cout << aux->dato << " ";
    }
    cout << endl;
}

void  insertar_inicio(Nodo *& inicio, int dato) {
    Nodo * nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = inicio;
    inicio = nuevo;
}


void insertar_al_final(Nodo *& inicio, int dato) {
    Nodo * nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = nullptr;

    if  (inicio == nullptr) {
        inicio = nuevo;
    }
    else {
        Nodo * aux = inicio;
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

int main () {
    Nodo * inicio = nullptr;

    int n;
    cout << "Cargar lista al inicio: " << endl;
    cout << "Ingrese un numero(0 para finalizar): ";
    cin >> n;
    
    while (n != 0) {
        insertar_inicio(inicio, n);
        cout << "Ingrese el siguiente numero(0 para finalizar): ";
        cin >> n;
    }

    cout << "Cargar lista al final: " << endl;
    cout << "Ingrese un numero(0 para finalizar): ";
    cin >> n;

    while (n != 0) {
        insertar_al_final(inicio, n);
        cout << "Ingrese el siguiente numero(0 para finalizar): ";
        cin >> n;
    }

    imprimir_lista(inicio);

    return 0;
}