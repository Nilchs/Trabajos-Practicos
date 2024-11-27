#include <iostream>
using namespace std;

/*
Escribir una función recursiva que reciba un arreglo de int y su dimensión lógica, y retorne el primer número
impar encontrado en el arreglo. En caso de no haber números impares, debe retornar 0.
Ejemplo: Dado el arreglo [ 2, 0, 8, 7, 4, 3 ] retornará 3.
*/

const int dimFis = 10;

int encontrarImpar(int arreglo[], int dl)
{
    if (dl == 0) // Caso base: Si no hay elementos en el arreglo
    {
        return 0;
    }
    if (arreglo[dl - 1] % 2 != 0) // Caso recursivo: Verificar si el último elemento es impar
    {
        return arreglo[dl - 1];
    }
    return encontrarImpar(arreglo, dl - 1); // Si es par, sigue al siguiente elemento
}

int main () {
    int arreglo[dimFis], dl = 0;

    for(int i = 0; i < dimFis; i++)
    {
        cout << "Ingrese numeros para el arreglo: ";
        cin >> arreglo[i];
        dl++;
    }

    int resultado = encontrarImpar(arreglo, dl);
    if(resultado != 0)
    {
        cout << "El primer numero impar es: " << resultado;
    }
    else
    {
        cout << "No se encontraron numeros impares";
    }
        
    return 0;
}