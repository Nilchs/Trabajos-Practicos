/*Escribe un programa que sume dos matrices de 3x3 y muestre la matriz resultante.*/

#include <iostream>
#include <string>
using namespace std;

const int F = 3;
const int C = 3;

int main () {
    int arregloNuevo[F][C] = {0};
    int matriz1[F][C] = {0};
    int matriz2[F][C] = {0};

    cout << "Introduce los elementos de la primera matriz 3x3." << endl;

    for (int i = 0; i < F; i++) //Completar la 1er matriz
    {
        cout << "Elementos de la fila " << i+1 << ": " << endl;
        for (int j = 0; j < C; j++)
        {
            cout<<"Ingrese un numero: ";
            cin>>matriz1[i][j];
        }
        cout<<endl;
    }

    cout << "\nIntroduce los elementos de la segunda matriz 3x3:" << endl;

    for (int i = 0; i < F; i++) //Completar la 2da matriz
    {
        cout << "Elementos de la fila " << i+1 << ": " << endl;
        for (int j = 0; j < C; j++)
        {
            cout<<"Ingrese un numero: ";
            cin>>matriz2[i][j];
        }
        cout<<endl;
    }


    // La suma de las matrices la guardo en una nueva matriz
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            arregloNuevo[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    
    // Muestro la matriz nueva sumada
    cout<<"La matriz resultado de la suma es:"<<endl;
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << " [ "<< arregloNuevo[i][j] << " ] ";
        }
        cout << endl;
    }

    return 0;
}