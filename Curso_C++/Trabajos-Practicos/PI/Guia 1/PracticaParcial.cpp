/*En la tienda, los productos (100 como máximo) están organizados en una tabla con las siguiente columnas:
    - Código del producto
    - Cantidad en stock del producto
    - Precio del producto
Construir un sistema que permita mediante un menú:
    1. Cargar productos hasta que no tenga más lugar la tabla de 100 filas o haya una condición de corte
    2. Imprimir el listado de todos los productos.
    3. Informar todos los productos con stock menor a un determinado valor ingresado por el usuario
    4. Ingresar un código de producto, un determinado porcentaje y un valor que indique si es aumento o baja, para actualizar el precio de dicho producto en el determinado porcentaje
    5. Salir*/

#include <iostream>
#include <string>
using namespace std;

const int Fila = 100;
const int Columna = 3;

void menu() {
    cout << "\nBienvenido al menu de la tienda!" << endl;
    cout << "1 : Cargar productos." << endl;
    cout << "2 : Imprimir listado de los productos." << endl;
    cout << "3 : Obtener informacion de stock en la lista." << endl;
    cout << "4 : Aumentar o bajar precio de un producto." << endl;
    cout << "5 : Salir." << endl;
}

void CargarProductos(int arreglo[Fila][Columna], int& dl) {

    if (dl == Fila) // Si la dimension logica es igual a las filas, quiere decir que el arreglo de la lista esta completa
    {
        cout << "\nNo se puede agregar mas elementos a la tienda.";
    }

    for (int i = dl; i < Fila; i++) // La variable "i" esta inicializada en dl para evitar que se sobrepisen los productos, como si lo haria si estuviera inicializada en 0
    {
        cout << "\nCargando el " << i+1 << " producto." <<endl;
        cout << "Ingresar codigo del producto(Ingrese numero negativo para finalizar)." << endl;
        cin >> arreglo[i][0];
        if (arreglo[i][0] < 0) // Si el codigo ingresado es negativo finaliza la funcion
        {
            break;
        }

        cout << "\nIngrese stock del producto: ";
        cin >> arreglo[i][1];
        if (arreglo[i][1] < 0) // Si el stock ingresado es negativo finaliza la funcion
        {
            break;
        }

        cout << "\nIngrese precio por producto: ";
        cin >> arreglo[i][2];
        if (arreglo[i][2] < 0) // Si el precio ingresado es negativo finaliza la funcion
        {
            break;
        }
        cout << endl;
        dl++; // Aumento la dimension logica por cada producto agregado en el arreglo
    }
}

void informarListado(int arreglo[Fila][Columna], int dl) {

    cout << "\nListado de los productos.";
    cout << endl;

    for (int i = 0; i < dl; i++)
    {
        cout << "\nProducto: " << i+1 << endl;
        cout << "Codigo del producto #" <<arreglo[i][0] << endl;
        cout << "Stock del producto: " <<arreglo[i][1] << endl;
        cout << "Precio del producto: $" <<arreglo[i][2] << endl;
    }
}

void InformarStock(int arreglo[Fila][Columna], int dl) {
    int valor;

    cout << "\nIngrese un valor a comparar con el stock: ";
    cin >> valor;
    for (int i = 0; i < dl; i++)
    {
        if (arreglo[i][1] < valor) // Si la columna del stock es menor al valor, entonces informa el stock que cumpla esta condicion
        {
            cout << "\nProductos con stock menor a " << valor << " : " << endl;
            cout << "Codigo: #" <<arreglo[i][0] << endl;
            cout << "Precio: $" <<arreglo[i][0] << endl;
        }
    }
}

void ActualizarPrecio(int arreglo[Fila][Columna], int dl) {
    double porcentaje = 0;
    bool encontrado = false;
    int codigo;
    char opcion;

    cout << "\nIngrese codigo: ";
    cin >> codigo;

    for (int i = 0; i < dl; i++)
    {
        if (arreglo[i][0] == codigo)
        {
            cout << "\nIngrese porcentaje a actualizar del producto: ";
            cin >> porcentaje;
            if (porcentaje < 0)
            {
                cout << "\nEl valor del porcentaje ingresado es invalido.";
                return; // Termina la funcion
            }
            
            encontrado = true; // Ya el producto fue encontrado si entro dentro del "if"
            
            do { // Hago un "do while" para que si el usuario ingresa un caracter distinto de 1 o 2 vuelva a solicitar
            
                cout << "\nDesea aumentar o bajar el precio en el valor " <<porcentaje <<"%? (1 : Aumentar ~ 2 : Bajar): ";
                cin >> opcion;
                cin.ignore(); // Para eliminar el salto de línea del buffer
                cout << endl;

                switch (opcion)
                {
                case '1':
                    arreglo[i][2] = arreglo[i][2] * (1 + (porcentaje) / 100.0);
                    cout << "El precio actualizado del producto es $" <<arreglo[i][2] << "." << endl;
                    break;

                case '2':
                    arreglo[i][2] = arreglo[i][2] * (1 - (porcentaje) / 100.0);
                    cout << "El precio actualizado del producto es $" <<arreglo[i][2] << "." << endl;
                    break;
            
                default:
                    cout << "Opcion no valida, por favor ingrese '1' o '2'.\n";
                    break;
                }
                
            } while (opcion != '1' || opcion != '2');
        }
    }

    if (!encontrado) // Si el codigo no fue encontrado informa en pantalla
    {
        cout << "\nEl codigo no fue encontrado en la lista." << endl;
    }
}

int main () {
    int dl = 0;
    int arreglo[Fila][Columna];
    char opciones;
    
    do
    {
        menu();

        cout << "\nElija la opcion que desee: ";
        cin >> opciones;
        cin.ignore(); // Para eliminar el salto de línea del buffer
        cout << endl;

        switch (opciones)
        {
        case '1':
            CargarProductos(arreglo, dl);
            break;

        case '2':
            informarListado(arreglo, dl);
            break;

        case '3':
            InformarStock(arreglo, dl);
            break;

        case '4':
            ActualizarPrecio(arreglo, dl);
            break;

        case '5':
            cout << "Saliendo del programa...\n";
            break;
        
        default:
            cout << "Opcion no valida, por favor intenta de nuevo.\n";
            break;
        }

    } while (opciones != '5');
    
    return 0;
}