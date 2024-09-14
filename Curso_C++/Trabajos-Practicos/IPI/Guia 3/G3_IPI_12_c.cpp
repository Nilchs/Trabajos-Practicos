#include <iostream>
#include <string>
using namespace std;

int sumatoriaPares(int numero) {
    int suma = 0;
    while (numero != 0) {
        if ((numero%10)%2 == 0) {
            suma += numero%10;
        }
        numero = numero/10;
    }
    return suma;
}

void alterarNumero(int a, int & b, int c) {
    a = sumatoriaPares(c);
    b = a;
}

int main() {
    int i = 4;
    int numero = 90210;
    alterarNumero(i, numero, sumatoriaPares(numero));
    cout << "Numero: " << numero << endl;
    cout << "Variable i: " << i << endl;
    return 0;
}