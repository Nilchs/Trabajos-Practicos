#include <iostream>
#include <string>
using namespace std;

struct TipoZapato {
string estilo;
double precio;
};

int main () {
    TipoZapato zapato1, zapato2;
    zapato1.estilo = "Sandalia";
    zapato1.precio = 9.99;
    cout << zapato1.estilo << " $" << zapato1.precio << endl;
    zapato2 = zapato1;
    zapato2.precio = zapato2.precio / 9;
    cout << zapato2.estilo << " $" << zapato2.precio << endl;
    return 0;
}