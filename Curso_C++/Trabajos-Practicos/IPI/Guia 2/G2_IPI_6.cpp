// Calcular e imprimir la suma de los primeros 25 números de la sucesión de Fibonacci. La sucesión
// comienza con los números 0 y 1 y, a partir de estos, cada elemento es la suma de los dos números
// anteriores en la secuencia: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...

#include <iostream>
#include <string>
using namespace std;

int main () {
    // numeros de elementos a considerar de fibonacci, es decir, 25. En este caso serian 23 porque ya conocemos los dos primeros numeros ( 0, 1).
    int n = 23;
    // arreglo para almacenar los numeros de la sucesion.
    int fibonacci[n];

    // se inicia fibonacci con 0 y 1.
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // generar los numeros de sucesion
    for (int i = 2; i < n; i++)
    {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // formula de fibonacci.
    }
    
    // calcular la suma de los primeros 25 numeros.
    long long suma = 0;

    for (int i = 0; i < n; i++)
    {
        suma += fibonacci[i];
    }
    
    cout << "la suma de los primeros 25 numeros de la sucesion de Fibonacci es: " << suma << endl;
    return 0;
}