#include <iostream>
#include <string>
using namespace std;

/*
Escribir una función recursiva que reciba una palabra y retorne true si es palíndromo, false si no lo es
(diferenciando mayúsculas y minúsculas).
Ejemplo: si la palabra es "radar" retorna true.
*/

bool es_palindromo(string palabra) {    
    if(palabra.length() <= 1) { // Si la palabra tiene 1 o menos caracteres, es palíndromo
        return true;
    }
    if(palabra[0] != palabra[palabra.length() - 1]) { // Compara el primer y último carácter para ver si son distintos
        return false;
    }
    return es_palindromo(palabra.substr(1, palabra.length() - 2)); // Si no son distintos, se llama a la función con la palabra sin el primer y último carácter
}

int main () {
    string s;
    cout << "Ingrese una palabra: ";
    getline(cin >> ws, s);

    string s_minuscula; // Nueva cadena para almacenar la palabra en minúsculas
    for(unsigned int i = 0; i < s.length(); i++) {
        s_minuscula += tolower(s[i]); // Agrega cada carácter en minúscula a la nueva cadena
    }
    
    if(!es_palindromo(s_minuscula)) {
        cout << "La palabra no es palindromo" << endl;
    }
    else {
        cout << "La palabra es palindromo" << endl;
    }

    return 0;
}