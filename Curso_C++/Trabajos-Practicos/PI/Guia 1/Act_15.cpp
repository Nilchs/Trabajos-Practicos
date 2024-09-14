/*Escribe un programa que busque un número en una matriz dada y devuelva su posición. Si el número no se
encuentra, debe indicarlo.*/

#include <iostream>
#include <string>
using namespace std;

int main () {
    int numero;
    int F, C;

    cout << "Ingrese las filas y columnas para su matriz." <<endl;
    cout << "Filas: ";
    cin >> F;
    cout << "Columnas: ";
    cin >> C;
    int matriz[F][C];

    cout << "Ingrese los elementos de la matriz." << endl;
    for(int i = 0; i < F; i++)
    {
        cout << "Elementos de la fila " << i+1 << ": ";
        for(int j = 0; j < C; j++)
        {
            cin >> matriz[i][j];
        }
        cout<<endl;
    }

    cout << "Ingrese el numero a buscar en la matriz: ";
    cin >> numero;
    
    bool encontrado = false;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matriz[i][j] == numero)
            {
                cout << "El numero " << numero << " aparece en la posicion (" << i << ", " << j << ")." << endl;
                encontrado = true; // Se encontró el número
            }
        }
    }
    
    if (encontrado == false)
    {
        cout << "el numero " << numero << " no fue encontrado en la matriz." << endl;
    }
    
    return 0;
}