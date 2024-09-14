#include <iostream>
#include <string>
using namespace std;

string mayusculas(string cadena) {
    for (int i=0; i<cadena.length(); i++){
    cadena[i] = toupper(cadena[i]);
    }
}

int main() {
    string nombre;
    cout << "Cuál es tu nombre?: ";
    getline(cin>>ws, nombre);
    
    mayusculas(nombre);
    cout << "Hola, " << nombre << "!" << endl;
    return 0;
}