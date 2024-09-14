// Escribir un bucle para validar lo ingresado por el usuario: se debe solicitar el ingreso de un carácter y sólo
// se debe interrumpir el bucle cuando el usuario haya ingresado el carácter 's' o el carácter 'n'. La solicitud
// de ingreso del dato debe hacerse al menos una vez antes de evaluar si el bucle debe interrumpirse o no.
// No utilizar "while true" como condición. A continuación, si el usuario ingresó la letra 's', imprimir "usted
// eligió SÍ" y, si ingresó la 'n' imprimir "usted eligió NO".

#include <iostream>
#include <string>
#include <cctype> // Para la función toupper()

using namespace std;

int main() {
    string cadena;
    
    // Leer una cadena de caracteres desde el teclado
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, cadena);
    
    // Mostrar la longitud de la cadena
    cout << "La longitud de la cadena es: " << cadena.length() << endl;
    
    // Convertir la cadena a mayúsculas
    string cadenaMayusculas = cadena;
    for (char &c : cadenaMayusculas) {
        c = toupper(c); // Convertir cada carácter a mayúsculas
    }
    cout << "La cadena en mayusculas es: " << cadenaMayusculas << endl;
    
    // Mostrar el último carácter
    if (!cadena.empty()) {
        cout << "El ultimo caracter es: " << cadena.back() << endl;
    } else {
        cout << "La cadena esta vacia." << endl;
    }
    
    return 0;
}