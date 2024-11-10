#include <iostream>
#include <string>
using namespace std;

/*
Ejercicio: Control de Inventario en una Librería
Descripción: En una librería, cada producto tiene los campos: código de producto, descripción, cantidad en stock y precio por unidad.
- Permitir agregar productos al principio de la lista.
- Eliminar un producto específico según el código ingresado por el usuario.
- Calcular y mostrar el valor total del inventario (precio por unidad * cantidad en stock) y la cantidad de productos cuyo valor de inventario supere un valor ingresado.
- Mostrar los productos con stock bajo (menor o igual a 5 unidades).
*/

struct Producto {
    int codigo, stock;
    string descripcion;
    float precio;
};

struct Nodo {
    Producto dato;
    Nodo* siguiente;
};

Nodo* insertar_al_inicio(Nodo* inicio, Producto dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = inicio; // El nuevo nodo apunta al inicio actual
    inicio = nuevoNodo; // El inicio ahora es el nuevo nodo
    return inicio;
}

void agregarProductos(Nodo*& lista) {
    int cod;
    Producto dato;
    cout << "Carga de productos de la libreria: " << endl;
    cout << "Ingrese el codigo del producto(-1 para finalizar): ";
    cin >> cod;
    cin.ignore();

    while (cod != -1)
    {
        dato.codigo = cod;
        cout << "Ingrese la descripcion del producto: ";
        getline(cin >> ws, dato.descripcion);
        cout << "Ingrese la cantidad en stock del producto: ";
        cin >> dato.stock;
        cin.ignore();
        cout << "Ingrese el precio por unidad del producto: ";
        cin >> dato.precio;
        cin.ignore();

        Nodo* nuevoProducto = insertar_al_inicio(lista, dato);

        cout << "Producto cargado con exito." << endl;
        cout << "----------------" << endl;
        cout << "Ingrese el codigo del siguiente producto(-1 para finalizar): ";
        cin >> cod;
        cin.ignore();
    }
}

Nodo* eliminarProducto(Nodo* inicio, int cod) {
    if (inicio == nullptr) 
    {
        Nodo* auxiliar = inicio;
        if (auxiliar->dato.codigo == cod) // Si el primer elemento es el que contiene el dato a eliminar
        { 
            inicio = inicio->siguiente; // El inicio pasa a apuntar al siguiente elemento
            delete auxiliar; // Se elimina el que era el primer elemento y el que era el segundo pasa a ser el primero
        }
        else
        {
            while (auxiliar->siguiente != nullptr && auxiliar->siguiente->dato.codigo != cod) {
                auxiliar = auxiliar->siguiente;
            }
            if (auxiliar->siguiente->dato.codigo == cod) // Si el siguiente nodo apuntado por el puntero auxiliar contiene el dato a eliminar
            {
                Nodo* AEliminar = auxiliar->siguiente; // Se guarda el puntero del nodo a eliminar en el puntero aEliminar
                auxiliar->siguiente = AEliminar->siguiente; // Se asigna el puntero del nodo actual al siguiente que hay que eliminar
                delete AEliminar; // Se elimina el nodo deseado
            }
        }
    }
    return inicio; // Se retorna el inicio por si se modificó
}

void control_de_inventario(Nodo* inicio, int valor) {
    Nodo* aux = inicio;
    int totalInventario, contador = 0;
    while (aux != nullptr) 
    {
        totalInventario = 0;
        totalInventario += (aux->dato.stock * aux->dato.precio);

        if (totalInventario > valor) {
            contador++;
        }   

        aux = aux->siguiente;
    }
    
    cout << "\nEl valor total del inventario es: $" << totalInventario << endl;
    cout << "La cantidad de productos cuyo valor de inventario supera el valor ingresado es: " << contador << endl;
}

void mostrarStockMenorA(Nodo* inicio, int minimo) {
    Nodo* aux = inicio;

    cout << "\nProductos con stock menor a " << minimo << endl;
    while (aux != nullptr) {
        if (aux->dato.stock <= minimo) {
            cout << "Codigo: " << aux->dato.codigo << endl;
            cout << "Descripcion del producto: " << aux->dato.descripcion << endl;
            cout << "Precio: $" << aux->dato.precio << endl;
            cout << "Stock: " << aux->dato.stock << endl;
        }
        aux = aux->siguiente;
    }
    cout << endl;
}

int main () {
    Nodo* inicio = nullptr;
    int num;

    agregarProductos(inicio);
    cout << "\nIngrese el codigo del producto a eliminar: ";
    cin >> num;
    eliminarProducto(inicio, num);
    cout << "Ingrese un valor que supere el precio total por stock: ";
    cin >> num;
    control_de_inventario(inicio, num);
    cout << "Ingrese el valor minimo a buscar por stock de producto/u: ";
    cin >> num;
    mostrarStockMenorA(inicio, num);
    return 0;
}