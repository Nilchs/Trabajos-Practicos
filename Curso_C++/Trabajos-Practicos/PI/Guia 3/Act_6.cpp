/*Permitir al usuario guardar en una lista enlazada simple los nombres de los alumnos de un curso, insertando al
final de la lista y cortando la carga cuando se inserte como nombre "x", ya sea en mayúscula o en minúscula (el
cual no debe insertarse en la lista).
A continuación, solicitar al usuario el nombre de un alumno e informar si se encuentra en la lista o no.
Por último, eliminar a la alumna "Josefina Ortega" de la lista (se asume que no se han almacenado nombres
repetidos).*/

#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    string dato;
    Nodo *siguiente;
};

void insertar_al_final(Nodo *&inicio, Nodo* nuevoNodo) {
    if  (inicio == nullptr) {
        inicio = nuevoNodo; // Si la lista está vacía, el nuevo nodo es el primero.
    }
    else {
        Nodo * aux = inicio; // Auxiliar para recorrer la lista sin modificar el puntero principal.
        while (aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo; // El último nodo apunta al nuevo nodo.
    }
}

Nodo* crearNodo(string dato) {
    Nodo *nuevo = new Nodo(); // Reservo memoria para un nuevo nodo.
    nuevo->dato = dato;
    nuevo->siguiente = nullptr; // El siguiente nodo es nulo.
    return nuevo; // Devuelvo el nuevo nodo.
}

void agregarNombres(Nodo*& Lista) {
    string nombre;
    Nodo* nuevoNodo;
    cout << "Carga de nombres de alumnos." << endl;
    cout << "Ingrese el nombre del alumno(Ingrese 'x' para finalizar): ";
    getline(cin >> ws, nombre);

    //Pasar todo el string a minuscula.
    for (unsigned int i = 0; i < nombre.length(); i++) { 
        nombre[i] = (tolower(nombre[i])); 
    }

    while (nombre != "x") {
        nuevoNodo = crearNodo(nombre); // Creo un nuevo nodo con el nombre ingresado.
        insertar_al_final(Lista, nuevoNodo); // Inserto el nuevo nodo al final.
        cout << "Ingrese el nombre del siguiente alumno(Ingrese 'x' para finalizar): ";
        getline(cin >> ws, nombre);

        for (unsigned int i = 0; i < nombre.length(); i++) {
            nombre[i] = (tolower(nombre[i]));
        }
    }
}

void buscarAlumno(Nodo* Lista) {
    string nombreABuscar;
    cout << "\nFuncion para buscar nombres de alumnos cargados." << endl;
    cout << "Ingrese el nombre del alumno a buscar: ";
    getline(cin >> ws, nombreABuscar);

    for (unsigned int i = 0; i < nombreABuscar.length(); i++) {
        nombreABuscar[i] = (tolower(nombreABuscar[i]));
    }

    Nodo* aux = Lista; // Auxiliar para recorrer la lista.
    while (aux->siguiente != nullptr && aux->dato != nombreABuscar) {
        aux =  aux->siguiente;
    }
    if (aux->dato == nombreABuscar) {
        cout << "\nEl nombre se encuentra en la lista." << endl;
    }
    else {
        cout << "El nombre no se encuentra en la lista." << endl;
    }
}

int main () {
    Nodo* inicio = nullptr;
    agregarNombres(inicio);
    buscarAlumno(inicio);
    return 0;
}