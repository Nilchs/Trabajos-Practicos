/*Generar una lista enlazada simple con la nómina de artículos de un supermercado. De cada artículo se conoce:
código, descripción, precio y stock. La carga finaliza con el código -1. Se solicita:
A. Leer de teclado un porcentaje e incrementar el precio de todos los artículos en esa cantidad.
B. Incrementar el stock de un artículo. Se lee de teclado el código y la cantidad con la que se debe
incrementar el stock. Si no existe el artículo en la lista se debe informar.
C. Eliminar de la lista los artículos que no tienen stock.*/

#include <iostream>
#include <string>
using namespace std;

struct Articulo {
    int codigo, stock;
    string descripcion;
    double precio;
};

struct Nodo {
    Articulo dato;
    Nodo *siguiente;
};

void insertar_al_final(Nodo *&inicio, Nodo* nuevoNodo) {
    if  (inicio == nullptr) {
        inicio = nuevoNodo; // Si la lista está vacía, el nuevo nodo es el primero.
    }
    else {
        Nodo * aux = inicio; // Auxiliar para recorrer la lista sin modificar el puntero principal.
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo; // El último nodo apunta al nuevo nodo.
    }
}


Nodo* crearNodo(Articulo dato) {
    Nodo *nuevo = new Nodo(); // Reservo memoria para un nuevo nodo.
    nuevo->dato = dato;
    nuevo->siguiente = nullptr; // El siguiente nodo es nulo.
    return nuevo; // Devuelvo el nuevo nodo.

}

void agregar(Nodo *&lista) {
    int cod;
    Articulo art; // Se crea un objeto de tipo Articulo.
    cout << "\nIngrese el codigo del articulo: ";
    cin >> cod;

    while (cod != -1) {
        art.codigo = cod;
        cout << "Ingrese la descripcion del articulo: ";
        getline(cin >> ws, art.descripcion);
        cout << "Ingrese el precio del articulo: ";
        cin >> art.precio;
        cout << "Ingrese el stock del articulo: ";
        cin >> art.stock;

        Nodo* nuevoArt = crearNodo(art); // Se crea un nuevo nodo con el articulo ingresado.
        insertar_al_final(lista, nuevoArt); //  Se inserta el nuevo nodo al final de la lista.
        cout << "\nIngrese el codigo del articulo: ";
        cin >> cod;
    }
}

void actualizar_precio(Nodo* lista) {
    int porcentaje;
    cout << "\nIngrese el porcentaje de aumento: ";
    cin >> porcentaje;
    
    for (Nodo* aux = lista; aux != nullptr; aux = aux->siguiente) {
        aux->dato.precio = aux->dato.precio + (aux->dato.precio * porcentaje / 100);
    }
}

void incrementar_stock(Nodo* lista) {
    int cod, cantidad;

    cout << "\nIngrese el codigo del articulo: ";
    cin >> cod;
    Nodo* aux = lista;

    while (aux->siguiente  != nullptr &&  aux->dato.codigo != cod) {
        aux = aux->siguiente;
    }
    if (aux->dato.codigo == cod) {
        cout << "Ingrese la cantidad a agregar: ";
        cin >> cantidad;
        aux->dato.stock += cantidad;
        cout << "Stock actualizado correctamente!";
    }
    else {
        cout << "Articulo no encontrado.";
    }
}

int main () {
    Nodo * inicio = nullptr;
    agregar(inicio);
    actualizar_precio(inicio);
    incrementar_stock(inicio);
        
    return 0;
}