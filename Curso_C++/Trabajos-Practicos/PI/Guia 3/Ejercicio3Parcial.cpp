#include <iostream>
#include <string>
using namespace std;

/*
Contexto: Una tienda de tecnología necesita un sistema para gestionar las ventas de productos electrónicos. De cada venta se debe almacenar: 
código de producto, categoría, nombre del vendedor, fecha de venta (DD/MM), y monto cobrado. 
Realizar un programa con los módulos necesarios para cumplir con la siguiente funcionalidad:

a. Permitir al usuario cargar las categorías de productos en un arreglo estático (máximo 20 categorías). Definir una condición de corte.
b. Permitir al usuario cargar las ventas del mes, insertándolas en una lista enlazada ordenada de menor a mayor por monto cobrado. 
Validar que la categoría exista antes de insertar cada venta.
c. Mostrar el total de ventas con un monto mayor a $10,000.
d. Pedir al usuario que ingrese un código de producto y, si existe en la lista, mostrar los datos de las ventas de ese producto.
*/

const int df = 20;

struct Venta {
    int codigo;
    float montoCobrado;
    long int fecha_venta;
    string nombre, categoria;
};

struct Nodo {
    Venta dato;
    Nodo* siguiente;
};

Nodo* crearNodo(Venta dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

Nodo* lista_ordenada(Nodo* inicio, Nodo* nuevoNodo) {
    if (inicio == nullptr || nuevoNodo->dato.categoria < inicio->dato.categoria) {
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
    }
    else
    {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato.categoria < aux->siguiente->dato.categoria) {
            aux = aux->siguiente;
        }
        nuevoNodo->siguiente = aux->siguiente;
        aux->siguiente = nuevoNodo;
    }
    return inicio;
}

bool existeCategoria(string arregloCat[], int dl, string categoria) {
    for (int i = 0; i < dl; i++)
    {
        if (arregloCat[i] == categoria) {
            return true;
        }
    }
    return false;
}

void cargaVentas(Nodo*& lista) {
    
}

int main () {
    Nodo* inicio = nullptr;
    int dl = 0;
    string arregloCategoria[df];
        
    return 0;
}