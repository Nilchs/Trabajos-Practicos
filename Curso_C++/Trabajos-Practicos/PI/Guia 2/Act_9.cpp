/*Escribir un programa que almacene en un arreglo los datos de los alumnos de una escuela luego de finalizado el
año académico. Como máximo, puede haber 5.000 alumnos. De cada alumno se debe guardar el nombre y la
calificación obtenida en el primer, segundo y tercer trimestre del año académico. Imprimir el listado de nombres
de alumnos mostrando un mensaje de "APTO" si el alumno supera o iguala la calificación de 5 para todas las
notas o "NO APTO" si no lo alcanza. Utilizar un arreglo como campo del struct para almacenar las tres
calificaciones.*/

#include <iostream>
#include <string>
using namespace std;

const int maxAlumnos = 5000;

struct Alumno
{
    string nombre;
    double calificaciones[3];
    double promedio;
};

void cargarAlumnos(Alumno alumnos[], int& dl) {
    string alumnosNombre;
    double promedio1;
    
    if (dl >= maxAlumnos) // Si el arreglo está lleno, no se puede cargar más alumnos
    {
        cout << "\nNo hay más espacio para agregar alumnos." << endl;
        return;
    }

    cout << "Carga de alumnos y sus calificaciones trimestrales." << endl;
    for (int i = dl; i < maxAlumnos; i++)
    {
        cout << "\nIngrese el nombre del alumno('nulo' para finalizar la carga): ";
        getline(cin >> ws, alumnosNombre);

        //Pasar todo el string a minuscula.
        for (unsigned int j = 0; j < alumnosNombre.length(); j++)
        {
            alumnosNombre[j] = (tolower(alumnosNombre[j]));
        }
        
        //Verificar si quiere salir de la carga.
        if (alumnosNombre == "nulo")
        {
            cout << "\nFinalizando la carga..." << endl;
            break;
        }

        alumnos[i].nombre = alumnosNombre;
        
        //Carga de las notas por cada trimestre del alumno.
        cout << "\nCarga de calificaciones." << endl;
        promedio1 = 0.0;
        promedio1 = alumnos[i].promedio;
        for (int k = 0; k < 3; k++)
        {
            cout << "Calificacion del " << k+1 << " Trimestre: ";
            cin >> alumnos[i].calificaciones[k];
            promedio1 += alumnos[i].calificaciones[k];
            cout << endl;
        }

        //Incremento el alumno cargado y en el campo promedio quedo el promedio de los tres trimestres.
        alumnos[i].promedio = promedio1 / 3.0;
        dl++;
    }
}

void imprimirAlumnos(Alumno alumnos[], int dl) {
    
    cout << "\nListado de alumnos aptos o no." << endl;
    for (int i = 0; i < dl; i++)
    {
        cout << "\nAlumno: " << alumnos[i].nombre;

        if (alumnos[i].promedio >= 5.0)
        {
            cout << "\nResultado: APTO." << endl;
        }
        else
        {
            cout << "\nResultado: NO APTO." << endl;
        }
    }
}

int main () {
    int dl = 0;
    Alumno alumnos[maxAlumnos];

    cargarAlumnos(alumnos, dl);

    imprimirAlumnos(alumnos, dl);

    return 0;
}