#include <iostream>
using namespace std;

/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne la suma de los
elementos pares almacenados en el arreglo. En caso de no haber números pares, debe retornar 0.
Ejemplo: Dado el arreglo [ 4, 5, 10, 17, 2, 3 ] retornará 16.
*/

const int dimFis = 10;

int sumaPares(int arreglo[], int dl) {
    if(dl == 0) { // Caso base: si la dimensión lógica es 0, no hay elementos
        return 0;
    }

    if(arreglo[dl - 1] % 2 == 0) { // Si el último elemento es par
        return arreglo[dl - 1] + sumaPares(arreglo, dl - 1); // Si es par, se suma y sigue con el resto del arreglo
    }
    else {
        return sumaPares(arreglo, dl - 1); // Si el elemento no es par, seguir con el resto del arreglo
    }
}

int main() {
    int arreglo[dimFis], dl = 0;

    for(int i = 0; i < dimFis; i++)
    {
        cout << "Ingrese numeros para el arreglo: ";
        cin >> arreglo[i];
        dl++;
    }

    int resultado = sumaPares(arreglo, dl);

    if(resultado != 0)
    {
        cout << "La suma de los numeros pares en el arreglo es: " << resultado;
    }
    else
    {
        cout << "No hay numeros pares en el arreglo";
    }
    
    return 0;
}

