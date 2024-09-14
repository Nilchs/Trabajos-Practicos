#include <iostream>
#include <string>
using namespace std;

/*void funcion(int a, int & y, int & z) {
int b = 1;
y = y+1;
z = z+a;
b = 4;
}*/

void funcion(int x, int & y, int & z) {
int b = 1;
y = y+1;
z = z+x;
b = 4;
}

int main() {
int a = 2;
int b = 3;
funcion(a+b, a, a);
cout << "Variable a:" << a << endl;
cout << "Variable b:" << b << endl;
return 0;
}