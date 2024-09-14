/*Cargar un arreglo con 20 números enteros ingresados por teclado de manera que el arreglo siempre se
encuentre ordenado en forma ascendente. El arreglo se cargará por completo.
Hacer dos variantes, suponiendo que el usuario carga los datos de las siguientes formas:
a) El usuario ingresa los números en orden ascendente (Inserción al final)
b) El usuario ingresa los números sin un orden en particular (Inserción ordenada)*/

#include <iostream>
#include <string>
using namespace std;

const int DimFisica = 20;

//Variante A.
void ordenAscendente() {
    int arreglo[DimFisica];

    cout<<"Ingrese una serie de 20 numeros en forma ascendente:\n";

    for (int i = 0; i < DimFisica; i++)
    {
        int num;
        cin>>num;

        // Verificar si el numero ingresado es mayor o igual que el anterior (para mantener el orden).
        if (i > 0 && num < arreglo[i - 1])
        {
            cout<<"Error: el numero deber ser mayor o igual al numero anterior."<<endl;
            i--;//Repetir la entrada.
        }
        else
        {
            arreglo[i] = num;//Insertar el numero al arreglo.
        }
    }
        
    //imprimir el arreglo ordenado.
    cout<<"Arreglo en forma ascendente:\n";

    for (int j = 0; j < DimFisica; j++)
    {
        cout<<arreglo[j]<<" ";
    }
    cout<<endl;
}

int main () {
    
    ordenAscendente();
    
    return 0;
}