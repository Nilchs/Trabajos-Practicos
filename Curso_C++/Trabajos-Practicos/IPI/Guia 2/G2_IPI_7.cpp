// Escribir un programa con el cual se procesarán las notas de un final de la materia. Para esto, se solicitará
// el ingreso del número de alumno y la nota recibida, hasta que se ingrese un número de alumno igual a
// cero, en cuyo caso se deberá imprimir en pantalla la leyenda 'Aprobados: ' y la cantidad de aprobados,
// junto con la leyenda 'Desaprobados: ' y la cantidad de desaprobados. Se deberá tener en cuenta que se
// aprueba con una nota mayor a 4.

#include <iostream>
#include <string>
using namespace std;

int main () {
    int alumno;
    double nota;
    int aprobados = 0;
    int desaprobados = 0;
    
    while (true)
    {
        cout<<"ingrese el numero de alumno (ingrese 0 para finalizar): ";
        cin>>alumno;

        if (alumno == 0) {
            break;
        } if (alumno < 0) {
            cout<<"ingrese un numero positivo para su alumno."<<endl;
            break;
        }
        
        cout<<"la nota del alumno es: ";
        cin>>nota;
        if (nota > 4) {
            aprobados++;
        } else {
            desaprobados++;
        }
        
    }
    cout<<"Aprobados: "<<aprobados<<endl;
    cout<<"Desaprobados: "<<desaprobados<<endl;

    return 0;
}