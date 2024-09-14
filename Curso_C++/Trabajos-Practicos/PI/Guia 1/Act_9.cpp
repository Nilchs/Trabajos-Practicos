/*Implementar una función eliminar_ocurrencias que reciba un arreglo de números enteros, su dimensión lógica
y un número por parámetro y elimine todas las ocurrencias de dicho número que existan en el arreglo.*/

#include <iostream>
#include <string>
using namespace std;

const int dimFis = 5;

void eliminar(int arreglo[], int &dimLog, int numero) {

    for(int i = 0; i < dimLog; i++)
    {
        if(arreglo[i] == numero)
        {
            for(int j = i; j < dimLog - 1; j++) // Se encarga de desplazar todos los elementos posteriores hacia la izquierda, sobrescribiendo el numero que se desea eliminar
            {
                arreglo[j] = arreglo[j+1]; // cada elemento del arreglo se sobrescribe con el siguiente
            }
            dimLog--;
            i--; // Para volver a verificar la nueva posición actual
        }
    }
}

int main () {
    int arreglo[dimFis], dimLog, numero, h;

    cout << "Ingrese numeros 5 numeros como maximo para el arreglo (numero negativo para finalizar): ";
    for(int k = 0; k < dimFis; k++)
    {
        cin >> arreglo[k];
        if(arreglo[k] < 0)
        {
            break;
        }
    }

    // Ingresar el numero a eliminar en el arreglo
    cout << "Ingrese un numero a eliminar en el arreglo: ";
    cin >> numero;

    h = 0;
    while(h < dimFis && arreglo[h] >= 0)
    {
        h++;
    }
    dimLog = h;

    eliminar(arreglo, dimLog, numero);

    cout << "El arreglo nuevo es: " << endl;

    for(int p = 0; p < dimLog; p++)
    {
        cout << arreglo[p] << " ";
    }

    return 0;
}