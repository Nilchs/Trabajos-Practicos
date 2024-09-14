// Escribí un programa que solicite el ingreso del monto de cada venta realizada en una tienda durante la
// última semana. Luego, se deberá imprimir el monto total de las ventas. Si se lee un monto negativo, se
// debe informar el problema sin interrumpir el ingreso de los datos. La lectura de la información finaliza al
// leer un monto igual a cero.

#include <iostream>
#include <string>
using namespace std;

int main () {
    double montoVenta;
    double montoTotal = 0.0;

     // Solicitar el ingreso del monto de cada venta hasta que se ingrese un monto igual a cero
    while (true) {
        // Solicitar el monto de la venta
        cout << "Ingrese el monto de la venta (0 para finalizar): ";
        cin >> montoVenta;
        
        // Verificar si se debe finalizar la lectura de datos
        if (montoVenta == 0) {
            break;
        }
        
        // Verificar si el monto de la venta es negativo
        if (montoVenta < 0) {
            cout << "Error: El monto de la venta no puede ser negativo. Por favor, intente nuevamente." << endl;
            continue;
        }
        
        // Sumar el monto de la venta al monto total
        montoTotal += montoVenta;
    }
    
    // Imprimir el monto total de las ventas
    cout << "El monto total de las ventas es: " << montoTotal << endl;
    
    return 0;
}