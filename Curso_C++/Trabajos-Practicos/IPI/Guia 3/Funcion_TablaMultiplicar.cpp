#include <iostream>
#include <string>
using namespace std;

void tablaMul(int num1, int num2) {

    cout<<"\n"<<num1<<" * "<<num2<<" = "<<num1*num2;
}

int main () {
    int n;

    cout<<"ingrese un numero: ";
    cin>>n;

    cout<<"tabla de multiplicar del: "<<n;

    for (int i = 0; i <= 12; i++)
    {
        tablaMul(n, i);
    }
    
    return 0;
}