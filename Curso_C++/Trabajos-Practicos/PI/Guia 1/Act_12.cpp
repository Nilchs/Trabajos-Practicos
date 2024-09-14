/*Escribir las sentencias necesarias para:
A. Declarar un arreglo de enteros de 7 filas y 10 columnas
B. Asignar el valor 105 a la posición que se encuentra en la segunda fila, quinta columna.
C. Asignar en todas las posiciones de la cuarta fila el valor 5.
D. Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
E. Permutar las columnas 3 y 5.
F. Sumar todos los elementos de las filas 2 y 6.
G. Imprimir todos los valores de la tercera columna.
H. Hallar en qué fila y columna se encuentra almacenado el mayor elemento.*/

#include <iostream>
#include <string>
using namespace std;

const int f=7;
const int c=10;

void mayorElemento(int arreglo[f][c]) { //en los parametros los arreglos de matrices es obligatorio pasar su dimFis.

    int mayorelemento = arreglo[0][0]; //el primer elemento de la matriz lo indico como el mayor.
    int filaMax, columnaMax = 0;
    for (int i = 0; i < f; i++) //Hallar en qué fila y columna se encuentra almacenado el mayor elemento.
    {
        for (int j = 0; j < c; j++)
        {
            if (arreglo[i][j] > mayorelemento)
            {
                mayorelemento = arreglo[i][j];
                filaMax=i;
                columnaMax=j;
            }
        }
    }
    cout<<" "<<filaMax+1<<" "<<columnaMax+1;
}

int main () {

    int arreglo[f][c]; //A)

    /*
    int n;
    for (int i = 0; i < f; i++) //Completar una matriz B)
    {
        for (int j = 0; j < c; i++)
        {
            cout<<"Ingrese un numero: ";
            cin>>n;
            arreglo[i][j]=n;
        }
    }
    */

    arreglo[1][4] = 105; //Asignar el valor 105 a la 2da fila y 5ta columna.

    /*
    for (int i = 0; i < c; i++) //Asignar en todas las posiciones de la cuarta fila el valor 5.
    {
        arreglo[3][i]=5;
    }
    */

    /*
    for (int i = 0; i < f; i++) //Imprimir todos los valores de la matriz, colocando cada fila en una nueva línea.
    {
        for (int j = 0; j < c; j++)
        {
            cout<<arreglo[i][j]<<" ";
        }
        cout<<endl;
    }
    */

    /*
    for (int i = 0; i < f; i++) //Permutar las columnas 3 y 5.
    {
        for (int j = 0; j < c; j++)
        {
            if (arreglo[i][j] == arreglo[i][2])
            {
                
            }
        }
    }
    */

    /*
    int suma = 0;
    for (int i = 0; i < c; i++) //Sumar todos los elementos de las filas 2 y 6.
    {
        suma += arreglo[1][i];
        suma += arreglo[5][i];
    }
    cout<<suma;
    */

    /*
    for (int i = 0; i < f; i++) //Imprimir todos los valores de la tercera columna.
    {
        cout<<arreglo[i][2]<<" ";
    }
    */

    /*   
    //imprimir la suma de todas las celdas de cada fila.
    int suma2;
    for (int i = 0; i < f; i++)
    {
       suma2 = 0;
       for (int j = 0; j < c; j++)
       {
        suma2 += arreglo[i][j];
       }
       cout<<suma2<<endl;
    }
    */

    return 0;
}