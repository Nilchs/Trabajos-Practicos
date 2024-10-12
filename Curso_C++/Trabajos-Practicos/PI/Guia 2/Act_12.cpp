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
    int legajo;
    string nombre;
    int dni;
};

const int max_elementos = 2000;
int main () {
        
    return 0;
}