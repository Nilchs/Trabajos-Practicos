#include <iostream>
#include <string>
using namespace std;

int main () {
    int i, arreglo[10];
for (i = 0; i < 10; i++)
arreglo[i] = 2*i;
for (i = 0; i < 10; i++)
cout << arreglo[i] << " ";
cout << endl;
for (i = 0; i <= 10; i = i + 2)
cout << arreglo[i] << " ";    
    return 0;
}