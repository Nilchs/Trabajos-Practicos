#include <iostream>
using namespace std;

/*
Graficar la pila de llamadas (colocando parámetros y valores de retorno):
*/

int sumatoria(int num) {
    if (num == 0) // Caso base
        return 0;
    return sumatoria(num-1) + num; // Caso recursivo
}

int main () {
    cout << sumatoria(5);    
    return 0;
}

/*
El programa funciona de la siguiente manera:
1. sumatoria(5) llama a sumatoria(4) y retorna sumatoria(4) + 5.
2. sumatoria(4) llama a sumatoria(3) y retorna sumatoria(3) + 4.
3. sumatoria(3) llama a sumatoria(2) y retorna sumatoria(2) + 3:
4. sumatoria(2) llama a sumatoria(1) y retorna sumatoria(1) + 2.
5. sumatoria(1) llama a sumatoria(0) y retorna sumatoria(0) + 1.
6. sumatoria(0) retorna 0.

Entonces sumatoria(1) retorna 0 + 1 = 1
sumatoria(2) retorna 1 + 2 = 3
sumatoria(3) retorna 3 + 3 = 6
sumatoria(4) retorna 6 + 4 = 10
sumatoria(5) retorna 10 + 5 = 15
*/