/*a) Declarar una variable puntero a Venta y reservar memoria.
b) Pedir al usuario que ingrese una cantidad vendida, descripción de producto y precio de producto,
almacenando los datos en la Venta apuntada por el puntero declarado en el inciso anterior.
c) Restar un 15% al precio del Producto guardado en la Venta apuntada por el puntero.
d) Imprimir la descripción del producto dentro de la Venta y monto total (precio del producto * cantidad).*/

#include <iostream>
#include <string>
using namespace std;

struct Producto {
    string descripcion;
    float precio;
};

struct Venta {
    Producto producto;
    int cantidad;
};

int main () {
    Venta* venta = new Venta();
    cout << "Ingrese la cantidad vendida: ";
    cin >> venta->cantidad;
    cout << "Ingrese la descripcion del producto: ";
    getline(cin >> ws, venta->producto.descripcion);
    cout << "Ingrese el precio del producto: ";
    cin >> venta->producto.precio;
    venta->producto.precio *= 0.85;
    cout << "Descripcion del producto: " << venta->producto.descripcion << endl;
    cout << "Monto total: " << venta->cantidad * venta->producto.precio <<  endl;
    delete venta;
        
    return 0;
}