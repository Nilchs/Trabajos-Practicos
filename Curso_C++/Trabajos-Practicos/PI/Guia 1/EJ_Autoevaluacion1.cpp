#include <iostream>
using namespace std;

int buscarElemento(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Retorna el índice del elemento encontrado
        }
    }
    return -1; // Retorna -1 si el elemento no se encuentra en el arreglo
}

int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int tamano = sizeof(numeros) / sizeof(numeros[0]);
    int x = 30;
    int resultado = buscarElemento(numeros, tamano, x);

    if (resultado != -1) {
        cout<< "Elemento " << x << " encontrado en la posición: " << resultado << endl;
    } else {
        cout<< "Elemento " << x << " no encontrado." << endl;
    }
    
    return 0;
}