#include <iostream>
#include <string>
using namespace std;

char validarEleccion() {
char opcion;
do {
    cout << "Desea confirmar el préstamo? Ingrese S ó N: ";
    cin>>opcion;
    opcion = tolower(opcion);
} while (opcion != 's' && opcion != 'n');
return opcion;
}

int main() {
    cout << " *** BIENVENIDO AL SISTEMA DEL BANCO MONEYMONEY *** " << endl;
    cout << "Ingrese monto para obtener un préstamo: ";
    float monto;
    cin >> monto;
    cout << "El interés es del 25%." << endl;
    if (validarEleccion() == 's')
    cout << "Ahora usted nos debe " << monto + (monto*0.25) << endl;
    else
    cout << "Lamentamos que no quiera hacer negocios con nosotros.";
    return 0;
}