#include <iostream>
using namespace std;

/*
Escribir una función recursiva que calcule el producto de dos números naturales, usando sumas.
Ejemplo: 2*3 se puede calcular como 2+2+2.
*/

int ProductoNumeros(int a, int b) {
    if (a == 0 || b == 0) { // Caso base: si alguno de los números es 0, el producto es 0
        return 0;
    }
    return a + ProductoNumeros(a, b - 1); // Caso recursivo: suma 'a' a la suma de 'a' multiplicado por 'b-1'
}
int main() {
    int a, b;
    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero: ";
    cin >> b;

    cout << "El producto de " << a << " y " << b << " es: " << ProductoNumeros(a, b);
    return 0;
}