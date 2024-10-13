/*Escribir un programa para gestionar las sucursales de una empresa.
a) Almacenar en un arreglo (máximo 2.000 elementos) los datos de los empleados: legajo, nombre y DNI.
En otro arreglo (máximo 20 elementos) almacenar la información de las sucursales: nombre de la
sucursal y legajo del encargado. Cada vez que se ingrese un legajo del encargado de una sucursal, se
debe validar si corresponde a un empleado existente. Si no existe, dejar al usuario en un bucle hasta que
ingrese un número de legajo existente.
b) Dado el legajo de un empleado, informar su nombre.
c) Imprimir un listado de sucursales, mostrando nombre de sucursal y nombre del empleado encargado.
Nota: analizar si es posible reutilizar código en más de uno de los incisos.*/

#include <iostream>
#include <string>
using namespace std;

struct Empleado {
    int legajoEmpleado;
    string nombre;
    int dni;
};

struct Sucursal {
    string nombre;
    int legajoEncargado;
};

const int max_elementos = 2000;
const int max_sucursales = 20;

// Función para buscar empleado por legajo
int buscarEmpleado(Empleado empleados[], int cantEmpleados, int legajo) {
    for (int i = 0; i < cantEmpleados; i++) {
        if (empleados[i].legajoEmpleado == legajo) {
            return i; // Retorna el índice del empleado si lo encuentra
        }
    }
    return -1; // Retorna -1 si no se encuentra el legajo
}

void agregarEmpleadoSucursal(Empleado empleados[], Sucursal sucursales[], int &cantEmpleados, int &cantSucursales) {
    if (cantEmpleados >= max_elementos) // Si el arreglo está lleno, no se puede cargar más empleados.
    {
        cout << "\nNo hay mas espacio para agregar empleados." << endl;
        return;
    }
    if (cantSucursales >= max_sucursales)
    {
        cout << "\nSucursales cargadas por completo." << endl;
        return;
    }
    
    int legajo;
    cout << "Ingrese el legajo del empleado(0 para finalizar): ";
    cin >> legajo;

    while (cantEmpleados < max_elementos && legajo != 0) {
        empleados[cantEmpleados].legajoEmpleado  = legajo;
        cout << "Ingrese el nombre del empleado: ";
        getline(cin >> ws,  empleados[cantEmpleados].nombre);
        cout << "Ingrese el DNI del empleado: ";
        cin >> empleados[cantEmpleados].dni;
        cin.ignore();
        cantEmpleados++;

        cout << "------------" << endl;
        cout << "Carga de informacion de las sucursales." << endl;
        cout << "Ingrese el nombre de la sucursal: ";
        getline(cin >> ws, sucursales[cantSucursales].nombre);
        cout << "Ingrese el legajo del encargado de la sucursal: ";
        cin >> sucursales[cantSucursales].legajoEncargado;

        // Validar que el legajo del encargado corresponda a un empleado existente
        while (buscarEmpleado(empleados, cantEmpleados, sucursales[cantSucursales].legajoEncargado) == -1) {
            cout << "Legajo no valido. Ingrese un legajo de empleado existente: ";
            cin >> sucursales[cantSucursales].legajoEncargado;
        }
        cantSucursales++;
        cout << "------------" << endl;
        cout << "Ingrese el legajo del siguiente empleado(0 para finalizar): ";
        cin >> legajo;
    }
}

void informarNombreEmpleado(Empleado empleados[], int cantEmpleados, int legajo) {
    int indice = buscarEmpleado(empleados, cantEmpleados, legajo);
    if (indice  != -1) {
        cout << "Nombre del empleado: " << empleados[indice].nombre << endl;
    } else {
        cout << "Legajo no encontrado." << endl;
    }
}

void informarSucursal(Sucursal sucursales[], Empleado empleados[], int cantSucursales, int cantEmpleados) {
    int indiceEncargado;
    cout << "\nListado de sucursales y encargados."  << endl;
    for  (int i = 0; i < cantSucursales; i++) {
        indiceEncargado = buscarEmpleado(empleados, cantEmpleados, sucursales[i].legajoEncargado);
        if (indiceEncargado != -1) {
            cout << "Sucursal: " << sucursales[i].nombre << " - Encargado: " << empleados[indiceEncargado].nombre << endl;
        } else {
            cout << "Sucursal: " << sucursales[i].nombre << " - Encargado: No encontrado" << endl;
        }
    }
}


int main () {
    Empleado empleados[max_elementos];
    Sucursal sucursales[max_sucursales];
    int cantEmpleados = 0;
    int cantSucursales = 0;

    agregarEmpleadoSucursal(empleados, sucursales, cantEmpleados, cantSucursales);

    int legajoBuscado;
    cout << "Ingrese el legajo de un empleado para obtener su nombre: ";
    cin >> legajoBuscado;
    informarNombreEmpleado(empleados, cantEmpleados, legajoBuscado);

    informarSucursal(sucursales, empleados, cantSucursales, cantEmpleados);
    return 0;
}