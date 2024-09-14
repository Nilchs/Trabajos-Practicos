/*Implementar la función Buscar elemento que reciba un arreglo de números enteros, su dimensión lógica y un
número por parámetro e indique si dicho número existe en el arreglo.*/

#include <iostream>
#include <string>
using namespace std;

const int dimFis = 5;

bool buscarElemento(int Arreglo[], int dimLog, int numero) {
    
    for (int i = 0; i <= dimLog; i++)
    {
        if (Arreglo[i] == numero)
        {
            return true;
        }
    }
    return false;
}

int main () {
    int Arreglo[dimFis], dimLog, numero, h;

    // Agregar números al arreglo
    cout << "Ingrese numeros para el arreglo (ingrese un valor negativo para finalizar): ";
    for(int j = 0; j <= dimFis; j++)
    {
        cin >> Arreglo[j];
        if(Arreglo[j] < 0) // Usar un número negativo para finalizar
        {
            break;
        }
    }

    // Ingresar el numero a buscar en el arreglo
    cout << "Ingrese un numero a buscar en el arreglo: ";
    cin >> numero;

    // Averiguar la dimensión lógica
    h = 0;
    while (h < dimFis && Arreglo[h] >= 0)
    {  // Verifica hasta llegar al final del arreglo o encontrar un número negativo
        h++;
    }
    dimLog = h;

    if (buscarElemento(Arreglo, dimLog, numero))
    {
        cout << "El numero: "<<numero<<" existe en el arreglo."<<endl;
    }
    else
    {
        cout << "El numero: "<<numero<<" no existe en el arreglo."<<endl;
    }
    
    return 0;
}