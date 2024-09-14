#include <iostream>
#include <string>
using namespace std;

const int dimFisica = 20;

//Variante B.
void OrdenAleatorio() {
    int arr[dimFisica];
    int tamanoActual = 0; // Tamaño actual del arreglo, comienza en 0

    cout << "Introduce 20 numeros en cualquier orden:\n";

    for (int i = 0; i < dimFisica; ++i) {
        int num;
        cin >> num;

        // Encontrar la posición de inserción para mantener el orden ascendente
        int j = tamanoActual - 1;
        while (j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j]; // Desplazar los elementos hacia la derecha
            j--;
        }

        arr[j + 1] = num; // Insertar el número en la posición correcta
        tamanoActual++;    // Aumentar el tamaño actual del arreglo
    }
}

int main () {

    OrdenAleatorio();

    return 0;
}