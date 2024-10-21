/*Dados los siguientes punteros a char:
char* x = new char;
char* z = x;
Escribir y ejecutar las instrucciones para hacer lo siguiente:
a) Almacenar el carácter 'M' en el espacio de memoria apuntado por x.
b) Imprimir el carácter apuntado por x.
c) Almacenar el carácter 'P' en el espacio de memoria apuntado por z.
d) Imprimir el carácter apuntado por z y luego el apuntado por x.
¿Qué carácter crees que imprimirá cada una y por qué?
e) Eliminar el dato apuntado por x.
¿Qué sucedería si a continuación se intentara imprimir *z y por qué?
f) Obtener un nuevo espacio de memoria para un char, almacenando su dirección en x.
g) Permitir al usuario ingresar un char por teclado y almacenarlo en el nuevo espacio apuntado por x.
h) Si el carácter ingresado por el usuario en el inciso anterior es '*', imprimir "asterisco".*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    char* x = new char;
    char* z = x;
    
    //a
    *x = 'M';
    //b
    cout << *x << endl;
    //c
    *z = 'P';
    //d
    cout << *z << " " << *x << endl;
    //e
    delete x;
    //f
    x = new char;
    //g
    char c;
    cout << "Ingrese un caracter: ";
    cin >> c;
    if  (c == '*') {
        cout << "asterisco.";
    }
    else {
        *x = c;   
    }
    return 0;
}