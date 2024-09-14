#include <iostream>
#include <string>
using namespace std;

bool buscarelemento(int matriz[][3], int filas, int columnas, int x, int &filaencontrada, int &columnaencontrada) {
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j]==x)
            {
                filaencontrada = i;
                columnaencontrada = j;
                return true;
            }
        }
    }
    return false;
}

int main () {
    int matriz [3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9} };

    int x = 5;
    int filaencontrada, columnaencontrada;

    if (buscarelemento(matriz, 3, 3, x, filaencontrada, columnaencontrada))
    {
        cout<<"elemento "<<x<<" encontrado en la posicion: ["<<filaencontrada<<"]["<<columnaencontrada<<"]"<<endl;
    }
    else
    {
        cout<<"elemento "<<x<<" no encontrado."<<endl;
    }

    return 0;
}