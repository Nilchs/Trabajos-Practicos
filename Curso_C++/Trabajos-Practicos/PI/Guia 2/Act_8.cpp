/*Realizar un programa que almacene en un arreglo la lista de invitados a una fiesta. El salón donde se realizará,
tiene capacidad máxima para 150 personas.
De cada invitado se conoce su nombre, apellido, sexo y edad. Se ingresarán datos hasta que el nombre sea
igual a “ZZZ” o hasta que la capacidad del salón esté completa.
Una vez finalizada la carga:
A. Informar la cantidad de invitados que asistirán a la fiesta.
B. Realizar una función que liste los nombres de las mujeres cuya edad sea <= 20.
C. Realizar una función que, dado un apellido y nombre, permita eliminar un invitado en caso de no poder
asistir.*/

#include <iostream>
#include <string>
using namespace std;

const int salonCapacidad = 150;

struct Invitado
{
    string nombre;
    string apellido;
    char sexo;
    int edad;
};

void cargarInvitados(Invitado invitados[], int& dl) {

    if (dl >= salonCapacidad) // Si el arreglo está lleno, no se puede cargar más libros
    {
        cout << "\nNo hay más espacio para agregar invitados." << endl;
        return;
    }

    string nombre;
    cout << "\nIngrese el nombre del primer invitado('ZZZ' para salir de la carga): ";
    getline(cin >> ws, nombre);

    for (unsigned int i = 0; i < nombre.length(); i++)
    {
        nombre[i] = (toupper(nombre[i]));
    }

    while (nombre != "ZZZ" && dl < salonCapacidad)
    {
        invitados[dl].nombre = nombre;
        cout << "Ingrese el apellido: ";
        getline(cin >> ws, invitados[dl].apellido);
        cout << "Ingrese el sexo(F o M): ";
        cin >> invitados[dl].sexo;
        cout << "Ingrese la edad: ";
        cin >> invitados[dl].edad;
        cout << "----------" << endl;

        dl++; // Elemento cargado

        cout << "\nIngrese el nombre del siguiente invitado('ZZZ' para salir de la carga): ";
        getline(cin >> ws, nombre);

        for (unsigned int i = 0; i < nombre.length(); i++)
        {
            nombre[i] = toupper(nombre[i]);
        }
    }
}

void imprimirInvitados(Invitado invitados[], int dl) {

    cout << "\nInvitados a la fiesta:" << endl;
    for (int i = 0; i < dl; i++)
    {
        cout << "Invitado " << i+1 << ":" << endl;
        cout << "Nombre: " << invitados[i].nombre << endl;
        cout << "Apellido: " << invitados[i].apellido << endl;
        cout << "Sexo: " << invitados[i].sexo << endl;
        cout << "Edad: " << invitados[i].edad << endl;
        cout << "................." << endl;
    }
}

void listaInvitados(Invitado invitados[], int dim) {

    cout << "\nListado de mujeres menores de 20 años.";
    for (int i = 0; i < dim; i++)
    {
        if (invitados[i].sexo == 'F' && invitados[i].edad <= 20)
        {
            cout << invitados[i].nombre;
        }
        cout << endl;
    }
}

void eliminarInvitado(Invitado invitados[], int& dl) {

    string Nombre, Apellido;
    
    cout << "\nIngrese el nombre y apellido a eliminar." << endl;
    cout << "Nombre: ";
    getline(cin >> ws, Nombre);
    cout << "Apellido: ";
    getline(cin >> ws, Apellido);
    
    int indice = 0;

    while (indice <= dl && invitados[indice].nombre != Nombre || invitados[indice].apellido != Apellido)
    {
        indice++;
    }

    if (indice < dl)
    {
        for (int j = indice; j < dl-1; j++)
        {
            invitados[j].nombre = invitados[j+1].nombre;
            invitados[j].apellido = invitados[j+1].apellido;
            dl--;
        }
        cout << "Invitado eliminado.";
    }
    else
    {
        cout << "No se encontro el invitado.";
    }
}

void menu(Invitado invitados[], int dl) {
    char opcion;
    do
    {
        cout << "\nBienvenido a la lista de invitados para su fiesta!." << endl;
        cout << "1. Cargar invitados." << endl;
        cout << "2. Imprimir invitados." << endl;
        cout << "3. Lista de mujeres con menos de 20 anos." << endl;
        cout << "4. Eliminar invitado." << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case '1':
            cargarInvitados(invitados, dl);
            break;

        case '2':
            imprimirInvitados(invitados, dl);
            break;

        case '3':
            listaInvitados(invitados, dl);
            break;

        case '4':
            eliminarInvitado(invitados, dl);
            break;

        case '5':
            cout << "Saliendo del programa..." << endl;
            break;
        
        default:
            cout << "Ingrese una opcion valida." << endl;
            break;
        }
    } while (opcion != '5');
}

int main () {
    int dl = 0;
    Invitado invitados[salonCapacidad]; 
    menu(invitados, dl);

    return 0;
}