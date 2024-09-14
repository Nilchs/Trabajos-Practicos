/*Escribir un programa para ser utilizado en una ventanilla de venta de entradas de un pequeño teatro con
capacidad para 50 personas. Las filas están identificadas de la 0 a la 4 y cada fila tiene asientos numerados de 1
a 10. Se debe registrar, por cada asiento, si está libre o no. Al iniciar el programa, todos los asientos están libres.
Cuando alguien desea comprar una entrada, se deben informar qué localidades están libres. Entonces el cliente
deberá elegir su asiento (indicando fila y número de asiento) y éste se marcará como vendido. Si ya se vendieron
todas las entradas, no se debe permitir elegir asiento.*/

#include <iostream>
#include <string>
using namespace std;

const int F = 5;
const int C = 10;

void menu() {
    cout << "\nBienvenido al teatro!" <<endl;
    cout << "1 : Reservar asientos." <<endl;
    cout << "2 : Salir del programa." <<endl;
}

void asientosLibres(bool matriz[F][C]) {

    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            matriz[i][j] = false; // Libre
        }
    }
}

void mostrarEstadoAsientos(const bool matriz[F][C]) {

    cout << "Estado de los asientos: " << endl;
    for (int fila = 0; fila < F; ++fila)
    {
        cout << "Fila " << fila << ": ";
        for (int asiento = 0; asiento < C; ++asiento)
        {
            if (matriz[fila][asiento])
            {
                cout << "O "; // O indica asiento ocupado
            } else 
            {
                cout << "L "; // L indica asiento libre
            }
        }
        cout << endl;
    }
}

int main () {
    bool matriz[F][C];
    asientosLibres(matriz);

    int totalEntradas = F * C; // Total de asientos
    int entradasVendidas = 0;
    char opciones;             
    char eleccion;             // Para decidir si reservar más asientos
    int fila, asiento;

    do
    {
        menu();

        cout << "Elija la opcion que desee: ";
        cin >> opciones;
        cin.ignore(); // Para eliminar el salto de línea del buffer
        cout << endl;

        switch (opciones)
        {
        case '1':
            // Bucle para permitir al usuario reservar múltiples asientos
            do {
                mostrarEstadoAsientos(matriz);

                cout << "\nSeleccione su lugar" << endl;
                cout << "Numero de fila: ";
                cin >> fila;
                cout << "Numero de asiento: ";
                cin >> asiento;

                if (fila < 0 || fila >= F || asiento < 1 || asiento > C) {
                
                    cout << "Asiento invalido. Por favor, elija un asiento valido." << endl;
                    continue; //Saltear el siguiente bloque y vuelve a mostrar el estado de los asientos
                }

                if (matriz[fila][asiento - 1]) {
                    cout << "Este asiento ya esta ocupado. Por favor, elija otro si desea." << endl;
                } else {
                    matriz[fila][asiento - 1] = true; // Marcar el asiento como ocupado
                    cout << "Asiento vendido correctamente." << endl;
                    entradasVendidas++;
                }

                // Verificar si quedan asientos disponibles
                if (entradasVendidas >= totalEntradas) {
                    cout << "Todas las entradas han sido vendidas. El teatro esta lleno." << endl;
                    break; // Salir del bucle si no quedan más asientos
                }
                
                cout << "Desea reservar otro asiento? (S para si, otro caracter para no): ";
                cin >> eleccion;
                cout << endl;
            } while (eleccion == 'S' || eleccion == 's'); // El usuario puede seguir reservando asientos
        
        break;

        case '2':
            cout << "Saliendo del programa...\n";
            break;
        
        default:
            cout << "Opcion no valida, por favor intenta de nuevo.\n";
            break;
        }
    } while (opciones != '2' && entradasVendidas < totalEntradas);
     
    return 0;
}