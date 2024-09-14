#include <iostream>
#include <string>
using namespace std;

void funcion(int & x, int y, int & z) {
    cout<<x<<y<<z;//muestra los valores ingresados hasta el momento de la funcion.
    x=1;
    y=2;
    z=3;
    cout<<x<<y<<z;//muestra los nuevos valores de las tres variables.
}

int main () {
    int a=10, b=20, c=30;
    funcion(a, b, c);
    cout<<a<<b<<c;//muestra los valores de a,b y c pero modificado 'a' y 'c' por el "&".
    return 0;
}