#include <iostream>
#include <string>
using namespace std;

string mayusculas(string cadena) {
    for (unsigned int i = 0; i < cadena.length(); i++) {
    cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}

int main() {
string nombre;
cout << "Cuál es tu nombre?: ";
getline(cin>>ws, nombre);

nombre = mayusculas(nombre);
cout << "Hola, " << nombre << "!" << endl;
return 0;
}