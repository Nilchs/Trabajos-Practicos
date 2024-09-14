#include <iostream>
using namespace std;

void TablaMultiplicar() {

    for (int i = 1; i <= 10; i++)
    {
        cout<<"\ntabla de multiplicar del "<<i<<endl;

        for (int j = 1; j <= 10; j++) 
        {
            cout<<"\n"<<i<<" x "<<j<<" = "<<i*j;
        }
        cout<<endl;
    }
}

int main () {

    TablaMultiplicar();

    return 0;
}