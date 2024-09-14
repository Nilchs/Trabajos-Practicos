#include <iostream>
#include <string>
using namespace std;

// Funciones
void mostrarMenu() {
   cout<<endl;
   cout<< "Menu:" << endl;
   cout<< " 1 : Registrar venta." << endl;
   cout<< " 2 : Mostrar venta." << endl;
   cout<< " 3 : Calcular el total de una venta." << endl;
   cout<< " 4 : Calcular el total pero con descuento." << endl;
   cout<< " 5 : Salir." << endl;
}

void registrarVenta(string & cliente, string & producto, int & cantidad, double & precio) {
   
   cout<<endl;
   cout<<"Ingrese datos de la venta."<<endl;
   cout<<"Ingrese el cliente: ";
   getline(cin>>ws, cliente);
   cout<<"Ingrese el producto de la venta: ";
   getline(cin>>ws, producto);
   cout<<"Ingrese la cantidad de productos vendidos: ";
   cin>>cantidad;
   cout<<"Ingrese el precio del producto por indivual: ";
   cin>>precio;
}

void mostrarVenta(string cliente, string producto, int cantidad, double precio) {
   cout<<endl;
   cout<<"Cliente: "<<cliente<<endl;
   cout<<"Producto: "<<producto<<endl;
   cout<<"Cantidad del producto: "<<cantidad<<endl;
   cout<<"Precio por unidad: "<<precio<<endl;
}

double calcularTotal(int cantidad, double precio) {
   
   return cantidad*precio;
}

double aplicarDescuento(double total) {
   const double descuento = 0.30; // 30% de descuento.

   if (total > 10000)
   {
      return total * (1-descuento);
   }
   else
   {
      return total;
   }
}


int main() {
 string cliente;
 string producto;
 int cantidad = 0;
 double precio = 0.0;
 char opcion;

 do {
 mostrarMenu();

 cout<<endl;
 cout << "Selecciona una opcion: ";
 cin >> opcion;
 cin.ignore(); // Para eliminar el salto de línea del buffer

 switch (opcion) {

    case '1':
    registrarVenta(cliente, producto, cantidad, precio);
    break;

    case '2':
    mostrarVenta(cliente, producto, cantidad, precio);
    break;

    case '3':
    {
    double total = calcularTotal(cantidad, precio);
    cout << "El total de la venta es: " << total << "\n";
    }
    break;

    case '4':
    {
    double total = calcularTotal(cantidad, precio);
    double totalConDescuento = aplicarDescuento(total);
    cout << "El total con descuento es: " << totalConDescuento << "\n";
    }
    break;

    case '5':
    cout << "Saliendo del programa...\n";
    break;

    default:
    cout << "Opcion no valida, por favor intenta de nuevo.\n";
    }

 } while (opcion != '5');

 return 0; }