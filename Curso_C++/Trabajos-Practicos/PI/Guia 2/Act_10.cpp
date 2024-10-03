/*La universidad posee información histórica sobre los estudiantes (no más de 1.000) de una materia determinada.
De cada uno almacena: nombre y apellido, legajo, cantidad de inasistencias a clase, calificación obtenida.
Almacenar esta información en un arreglo de structs. Se solicita generar los siguientes reportes:
a) Imprimir nombre y apellido de los alumnos que tuvieron más de 5 inasistencias.
b) Imprimir número de legajo de los alumnos cuya calificación promedio sea mayor o igual a la calificación
promedio total (requiere calcular un promedio de las calificaciones de todos los alumnos en el listado).
c) Imprimir el número de legajo de aquellos alumnos que tienen promedio mayor o igual a 9.
d) Dado el legajo de un alumno, eliminarlo del listado.
Nota: analizar si es posible reutilizar código en más de uno de los incisos.*/

#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    string apellido;
    int legajo;
    int inasistencias;
    float calificacion;
};

const int MAX_ALUMNOS = 1000;

void imprimirAlumnosConMasDe5Inasistencias(Alumno alumnos[], int cantidadAlumnos) {
    cout << "Alumnos con mas de 5 inasistencias:" << endl;
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].inasistencias > 5) {
            cout << alumnos[i].nombre << " " << alumnos[i].apellido << endl;
        }
    }
}

float calcularPromedioTotal(Alumno alumnos[], int cantidadAlumnos) {
    float promedioTotal = 0;
    for (int i = 0; i < cantidadAlumnos; i++) {
        promedioTotal += alumnos[i].calificacion;
    }
    promedioTotal /= cantidadAlumnos;
    return promedioTotal;
}

void imprimirLegajosConCalificacionPromedioMayorOIgual(Alumno alumnos[], int cantidadAlumnos, float promedioTotal) {
    cout << "Legajos de alumnos con calificacion promedio mayor o igual al promedio total:" << endl;
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].calificacion >= promedioTotal) {
            cout << alumnos[i].legajo << endl;
        }
    }
}

void imprimirLegajosConCalificacionMayorOIgualA9(Alumno alumnos[], int cantidadAlumnos) {
    cout << "Legajos de alumnos con calificacion mayor o igual a 9:" << endl;
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].calificacion >= 9) {
            cout << alumnos[i].legajo << endl;
        }
    }
}

void eliminarAlumnoPorLegajo(Alumno alumnos[], int &cantidadAlumnos, int legajoABorrar) {
    for (int i = 0; i < cantidadAlumnos; i++) {
        if (alumnos[i].legajo == legajoABorrar) {
            // Eliminar el alumno del arreglo (en este caso, solo lo "borramos" moviendo los demás elementos)
            for (int j = i; j < cantidadAlumnos - 1; j++) {
                alumnos[j] = alumnos[j + 1];
            }
            cantidadAlumnos--;
            cout << "Alumno eliminado" << endl;
            return;
        }
    }
    cout << "Alumno no encontrado" << endl;
}

int main() {
    Alumno alumnos[MAX_ALUMNOS];
    int cantidadAlumnos = 0;

    cout << "Ingrese la cantidad de alumnos: ";
    cin >> cantidadAlumnos;

    for (int i = 0; i < cantidadAlumnos; i++) {
        cout << "Ingrese nombre del alumno " << i + 1 << ": ";
        cin >> alumnos[i].nombre;
        cout << "Ingrese apellido del alumno " << i + 1 << ": ";
        cin >> alumnos[i].apellido;
        cout << "Ingrese legajo del alumno " << i + 1 << ": ";
        cin >> alumnos[i].legajo;
        cout << "Ingrese cantidad de inasistencias del alumno " << i + 1 << ": ";
        cin >> alumnos[i].inasistencias;
        cout << "Ingrese calificación del alumno " << i + 1 << ": ";
        cin >> alumnos[i].calificacion;
    }

    imprimirAlumnosConMasDe5Inasistencias(alumnos, cantidadAlumnos);

    float promedioTotal = calcularPromedioTotal(alumnos, cantidadAlumnos);
    cout << "Promedio total: " << promedioTotal << endl;
    imprimirLegajosConCalificacionPromedioMayorOIgual(alumnos, cantidadAlumnos, promedioTotal);

    imprimirLegajosConCalificacionMayorOIgualA9(alumnos, cantidadAlumnos);

    int legajoABorrar;
    cout << "Ingrese el legajo del alumno a eliminar: ";
    cin >> legajoABorrar;
    eliminarAlumnoPorLegajo(alumnos, cantidadAlumnos, legajoABorrar);

    return 0;
}