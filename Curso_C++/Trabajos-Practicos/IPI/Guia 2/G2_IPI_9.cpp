// Escribir un programa que solicite al usuario el ingreso de 10 nombres de personas y muestre en pantalla
// el nombre que contenga la mayor cantidad de letras. En caso de ingresar 2 (o más) con la misma cantidad,
// se debe mostrar el último nombre procesado con esa cantidad de letras.

#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;
    string nombreLargo;
    int maxLongitud = 0;

    cout<<"ingrese el nombre de 10 personas."<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<<"Nombre "<<i+1<<": ";
        getline(cin>>ws, nombre);

        if (nombre.length() >= maxLongitud) {
            maxLongitud = nombre.length(); //establecer la longitud a traves de la cantidad del indice.
            nombreLargo = nombre; //guarda el nombre mas largo al momento, a la otra variable.
        }
        
    }
    cout<<"el nombre con la mayor longitud es: "<<nombreLargo;

    return 0;
}
