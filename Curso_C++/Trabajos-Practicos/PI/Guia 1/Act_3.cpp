#include <iostream>
#include <string>
using namespace std;

void Funcion(int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    
}

int main () {
    int n;

    cout<<"Ingrese el tamano del cuadrado: ";
    cin>>n;

    Funcion(n);

    return 0;
}