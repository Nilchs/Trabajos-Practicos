/*En un equipo de Formula 1 utiizan tablas para ver el rendimiento de sus pilotos.

Vuelta/Piloto   Piloto 1    Piloto 2    Piloto 3
----------------------------------------------------
vuelta 1            1           2           3       
vuelta 2            4           5           6           
vuelta 3            7           8           9
-----------------------------------------------------

1. Cargar los resultados en una matriz 3x3
2. Imprimir en pantalla la posicion final de cada piloto despues de 3 vuelta.
   La posicion de largada se determina sumando los tiempos de las tres vueltas
   El piloto con el menor tiempo larga primero, el que le sigue en tiempo segundo, y
   asi sucesivamente
3. Imprimir en pantalla en que vuelta cada piloto tuvo su mejor desempeño
*/

#include <iostream>
#include <string>
using namespace std;

const int F = 3;
const int C = 3;

void menu() {
    cout << "\nBienvenido a la tabla de rendimientos." << endl;
    cout << "1 : Cargar resultados." << endl;
    cout << "2 : Imprimir la posicion de largada de cada piloto despues de la 3 vueltas." << endl;
    cout << "3 : Imprimir la mejor vuelta de cada piloto." << endl;
    cout << "4 : Salir." << endl;
}

void cargarResultados(int resultado[F][C]) {

    cout << "\nCargue en cada vuelta los tiempos de los pilotos.";
    for (int i = 0; i < F; i++)
    {
        cout << "\nVuelta " << i+1 << ": ";
        for (int j = 0; j < C; j++)
        {
            cout << "\nPiloto: " << j+1 << ": ";
            cin >> resultado[F][C];
        }
        cout << endl;
    }
}

void imprimirLargada(int resultado[F][C]) {
    int tiempoPilotos[3] = {0, 0, 0};

    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            tiempoPilotos[i] += resultado[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "\nTiempo del piloto (" << i+1 <<"): "<< tiempoPilotos[i] << endl;
    }
    
}

void imprimirMejorVuelta(int resultado[F][C]) {
    
    int mejorTiempo;
    int vuelta;

    for (int i = 0; i < F; i++)
    {
        mejorTiempo = 0;
        vuelta = 0;
        for (int j = 0; j < C; j++)
        {
            if (resultado[i][j] > mejorTiempo)
            {
                mejorTiempo = resultado[i][j];
                vuelta = j+1;
            }
        }
        cout << "Piloto " << i+1 << ": Vuelta " << vuelta << " " << mejorTiempo << endl;
    }
    
}

int main () {
    int resultado[F][C];
    char opciones;

    do
    {
        menu();

        cout << "\nElija la opcion que desee: ";
        cin >> opciones;
        cin.ignore(); // Para eliminar el salto de línea del buffer
        cout << endl;

        switch (opciones)
        {
        case '1':
            cargarResultados(resultado);
            break;

        case '2':
            imprimirLargada(resultado);
            break;

        case '3':
            imprimirMejorVuelta(resultado);
            break;

        case '4':
            cout << "Saliendo del programa...\n";
            break;
        
        default:
            cout << "Opcion no valida, por favor intenta de nuevo.\n";
            break;
        }

    } while (opciones != '4');
    
    return 0;
}