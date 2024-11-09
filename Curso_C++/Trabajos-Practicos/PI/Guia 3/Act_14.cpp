/*Generar una lista con los datos personales de los alumnos de un colegio (legajo, apellido y nombre, DNI) y las
notas de tres materias: matemática, literatura y geografía (para cada alumno se cargarán las tres materias). Las
notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas, volviendo a pedir una
nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor en el rango indicado. Se pide
informar la cantidad de alumnos que aprobaron las tres materias (se aprueba con 7) y el porcentaje que
representan los aprobados sobre el total de alumnos.*/

#include <iostream>
#include <string>
using namespace std;

const int DF = 3;

struct Alumno {
    int legajo, dni, notas[DF]; // 0 para matematica, 1 literatura y 2 geografia.;
    string apellido, nombre;
};

struct Nodo {
    Alumno dato;
    Nodo *siguiente;
};

void insertarAlFinal(Nodo* &inicio, Nodo* nuevoNodo)
{
    if(inicio == nullptr) {
        inicio = nuevoNodo;
    }
    else {
        Nodo* aux = inicio;
        while(aux->siguiente != nullptr) {
            aux = aux->siguiente;
        }
        aux -> siguiente = nuevoNodo;
    }
}

Nodo* crearNodo(Alumno dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void agregarAlumnos(Nodo*& lista) {
    int legajoTemporal;
    Alumno alumno;
    cout << "Carga de alumnos del colegio: " << endl;
    cout << "Ingrese el legajo del alumno(-1 para finalizar): ";
    cin >> legajoTemporal;

    while (legajoTemporal != -1 && legajoTemporal > 0) {
        alumno.legajo = legajoTemporal;
        cout << "Ingrese el apellido del alumno: ";
        getline(cin >> ws, alumno.apellido);
        cout << "Ingrese el nombre del alumno: ";
        getline(cin >> ws, alumno.nombre);
        cout << "Ingrese el DNI del alumno: ";
        cin >> alumno.dni;
        cin.ignore();

        do
        {
            cout << "Ingrese la nota de Matematica del alumno (1-10): ";
            cin >> alumno.notas[0];
            cin.ignore();
            if (alumno.notas[0] < 1 || alumno.notas[0] > 10) {
                cout << "Nota invalida, ingrese una nota correspondiente." << endl;
            }
        } while (alumno.notas[0] < 1 || alumno.notas[0] > 10);

        do
        {
            cout << "Ingrese la nota de Literatura del alumno (1-10): ";
            cin >> alumno.notas[1];
            cin.ignore();
            if (alumno.notas[1] < 1 || alumno.notas[1] > 10) {
                cout << "Nota invalida, ingrese una nota correspondiente." << endl;
            }
        } while (alumno.notas[1] < 1 || alumno.notas[1] > 10);

        do
        {
            cout << "Ingrese la nota de Geografia del alumno (1-10): ";
            cin >> alumno.notas[0];
            cin.ignore();
            if (alumno.notas[2] < 1 || alumno.notas[2] > 10) {
                cout << "Nota invalida, ingrese una nota correspondiente." << endl;
            }
        } while (alumno.notas[2] < 1 || alumno.notas[2] > 10);

        Nodo* nuevoAlumno = crearNodo(alumno); // Crea un nuevo nodo con el alumno cargado
        insertarAlFinal(lista, nuevoAlumno); // Inserta el nuevo nodo al final de la lista

        cout << "\nAlumno cargado con exito." << endl;
        cout << "----------------" << endl;
        cout << "Ingrese el legajo del alumno(-1 para finalizar): ";
        cin >> legajoTemporal;
        cin.ignore();
    }
}

void informarAprobados(Nodo* lista) {
    cout << "\nAlumnos aprobados:" << endl;

    Nodo* aux = lista;
    while (aux != nullptr) {
        if (aux->dato.notas[0] < 7 || aux->dato.notas[1] < 7 || aux->dato.notas[2] < 7)
        {
            cout << "El alumno con legajo: " << aux->dato.legajo << " no fue aprobado ya que se necesita al menos un 7 o mas en las tres materias." << endl;
            cout << "Sus notas son:" << endl;
            cout << "Matematica: " << aux->dato.notas[0] << endl;
            cout << "Literatura: " << aux->dato.notas[1] << endl;
            cout << "Geografia: " << aux->dato.notas[2] << endl;
            cout << "----------------" << endl;
        }
        else {
            cout << "El alumno con legajo: " << aux->dato.legajo << " fue aprobado ya que tiene las tres materias aprobadas." << endl;
            cout << "Sus notas son:" << endl;
            cout << "Matematica: " << aux->dato.notas[0] << endl;
            cout << "Literatura: " << aux->dato.notas[1] << endl;
            cout << "Geografia: " << aux->dato.notas[2] << endl;
            cout << "----------------" << endl;
        }
        aux = aux->siguiente;
    } 
}

void porcentajeAprobados(Nodo* lista) {
    int totalAlumnos = 0;
    int cantidadAprobados = 0;

    Nodo* aux = lista;
    while (aux != nullptr) {
        totalAlumnos++;

        if (aux->dato.notas[0] >= 7 && aux->dato.notas[1] >= 7 && aux->dato.notas[2] >= 7) {
            cantidadAprobados++;
        }
        
        aux = aux->siguiente;
    }

    if (totalAlumnos == 0)
    {
        cout << "No hay alumnos registrados." << endl;
        return;
    }

    // Con 'static_cast<float>' se asegura de que la división sea con `float` para un resultado correcto
    float porcentajeAprobados = (static_cast<float>(cantidadAprobados) / totalAlumnos) * 100;

    cout << "Cantidad total de alumnos: " << totalAlumnos << endl;
    cout << "Cantidad de alumnos aprobados en las tres materias: " << cantidadAprobados << endl;
    cout << "Porcentaje de aprobados: " << porcentajeAprobados << "%" << endl;
}

int main () {
    Nodo* inicio = nullptr;
    Alumno dato;

    agregarAlumnos(inicio);
    informarAprobados(inicio);
    porcentajeAprobados(inicio);
        
    return 0;
}