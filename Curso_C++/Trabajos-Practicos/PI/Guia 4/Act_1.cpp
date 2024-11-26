#include <iostream>
using namespace std;

/*
Dado el siguiente programa, analizarlo (sin ejecutarlo en la máquina) e indicar qué calcula. 
¿Cuál es el caso base de este algoritmo? ¿Y el caso recursivo?
*/

int funcion(int m, int n) {
    if (n == 0) { // Caso base
        return 0;
    }
    return m + funcion(m, n-1); // Caso recursivo
}

int main() {
    cout << funcion(20, 3);
    return 0;
}

// Respuesta: 60