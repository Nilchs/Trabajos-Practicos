// Solicitar al usuario que ingrese el día de la semana y la cantidad de artículos comprados por un cliente
// en una tienda. Finalmente, imprimir “Accede al descuento” si el día es lunes y el cliente compró más de
// 3 artículos. En caso contrario, no imprimir nada.

#include <iostream>
#include <string>
using namespace std;

int main () {
    string dia;
    int articulos;
    cout<<"dia de la semana es: "<<endl;
    getline(cin>>ws, dia);

    for (int i = 0; i < dia.length(); i++) {
        dia[i] = tolower(dia[i]);
    }

    cout<<"los articulos comprados son: "<<endl;
    cin>>articulos;
    

    if (dia == "lunes" && articulos > 3)
    {
        cout<<"!Accede al descuento!"<<endl;
    }

    return 0;
}