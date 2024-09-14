/*Escribir un programa que permita al usuario gestionar los pagos de la cuota de un club. Para ello, almacenar en
un arreglo los números de DNI de los socios que pagaron. El club no tiene más de 200 socios.
Permitir al usuario buscar un DNI en el arreglo y, si el DNI está en el arreglo, imprimir "Cuota al día". Si no está,
imprimir "Socio con deuda".
También se debe permitir al usuario eliminar un DNI del arreglo, en caso de haberlo ingresado erróneamente.
Finalmente, imprimir todo el arreglo.*/

#include <iostream>
#include <string>
using namespace std;

const int dimFis = 200;

void mostrarMenu() {

    cout<<"\nMenu de opciones."<<endl;
    cout<<"1 : Agregar un DNI de socio que pago."<<endl;
    cout<<"2 : verificar estado de cuota."<<endl;
    cout<<"3 : Eliminar un DNI del sistema."<<endl;
    cout<<"4 : Mostrar todos los socios."<<endl;
    cout<<"5 : Salir del programa."<<endl;
}

bool buscarDNI(int socios_dni[], int dni, int dimLog) {

    for (int i = 0; i < dimLog; i++)
    {
        if (socios_dni[i] == dni)
        {
            return true;
        }
    } 
    return false;
}

void eliminarDNI(int socios_dni[], int dni, int& dl) {

    for (int i = 0; i < dl; i++)
    {
        if(socios_dni[i] == dni)
        {
            for(int j = i; j < dl - 1; j++) // Se encarga de desplazar todos los elementos posteriores hacia la izquierda, sobrescribiendo el numero que se desea eliminar
            {
                socios_dni[j] = socios_dni[j+1]; // cada elemento del arreglo se sobrescribe con el siguiente
            }
            dl--;
            break;
        }
    }
}

void agregarDNI(int arreglo[], int& dl) {

    for (int i = dl; i < dimFis; i++)
    {
        cin>>arreglo[i];
        if (arreglo[i] < 0)
        {
            break;
        }
        dl++;
    }

    if (dl == dimFis)
    {
        cout<<"El arreglo alcanzo su capacida total."<<endl;
    }    
}

void mostrarArreglo (int arreglo[], int dl) {
    
    cout<<"\nEl arreglo es: ";
    for (int i = 0; i < dl; i++)
    {
        cout<<arreglo[i]<<" ";
    }
    cout<<endl;
}

int main () {
    int arreglo[dimFis], dl = 0, dni;
    char opciones;

    do
    {
        mostrarMenu();

        cout<<"\nSeleccione una opcion: ";
        cin>>opciones;
        cin.ignore(); // Para eliminar el salto de línea del buffer

        switch (opciones)
        {
        case '1':
            agregarDNI(arreglo, dl);
            break;
        
        case '2':
            cout<<"\nIngrese el DNI a buscar: ";
            cin>>dni;
            if (buscarDNI(arreglo, dl, dni))
            {
                cout<<"El DNI "<<dni<<" se encuentra al dia."<<endl;
            }
            else
            {
                cout<<"El DNI "<<dni<<" no se encuentra al dia."<<endl;   
            }
            break;
        
        case '3':
            cout<<"\nIngrese un DNI a eliminar: ";
            cin>>dni;
            eliminarDNI(arreglo, dl, dni);

            cout<<"\nEl arreglo nuevo es: "<<endl;
            mostrarArreglo(arreglo, dl);
            break;
        
        case '4':
            mostrarArreglo(arreglo, dl);
            break;
        
        case '5':
            cout<<"Saliendo del programa...\n";
            break;
        
        default:
            cout<<"Opcion no valida, por favor intenta de nuevo.\n";
            break;
        }
    } while (opciones != '5');
     
        
    return 0;
}