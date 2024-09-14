/*Escribir un programa que imprima el menú mostrado a continuación y solicite al usuario
elegir una opción, la cual se debe ejecutar para luego volver a mostrar el menú repetidas
veces, hasta que el usuario decida salir:
‘A’: Invertir número.
‘B’: Sumatoria de dígitos.
‘C’: Decir si son múltiplos.
‘D’: Salir.*/

#include <iostream>
#include <string>
using namespace std;

//Case 'B'
int suma_digito(int numero){//sacada del ej2.
    int suma = 0;
    while (numero != 0)
    {
        int resto = numero%10;
        suma += resto;
        numero = numero/10;//para cuando vuelva al while se le va el ultimo digito.
    }
    return suma;
}

//case 'A'
string  numInvertido (string numero){
  string numerovolteado = "" ; 
  for( int i = numero.length () -1 ; i >= 0 ; i--) {
    numerovolteado += numero[i];
/**/
  
  }
    return numerovolteado;
}

//case 'C'
bool sonMmultiplos(int x, int y) {
    return x % y == 0;//verifica si el resto de la division entre dos numeros es igual a 0 entonces son multiplos.
}



void Menu() {
    cout<<endl;
    cout<< "Menu:" << endl;
    cout<< "'A': Invertir numero." << endl;
    cout<< "'B': Sumatoria de digitos." << endl;
    cout<< "'C': Decir si son multiplos." << endl;
    cout<< "'D': Salir." << endl;
}

int main () {
    char operador;
    
    do
    {
        Menu();
        cout << "Elegir una opcion: ";
        cin >> operador;
        operador = toupper(operador);

        switch (operador)
        {
        case 'A': {
            string numero;
            cout<<"Ingrese un numero: ";
            cin>>numero;
            cout<<"El número invertido es: "<<numInvertido(numero)<<endl;
            break;
        }

        case 'B': {
            int num1;
            cout<<"ingrese un numero: ";
            cin>>num1;
            cout<<"la suma de los digitos es: "<<suma_digito(num1)<<endl;
            break;
        }

        case 'C': {
            int x, y;
            cout << "Ingresa el primer numero: ";
            cin >> x;
            cout << "Ingresa el segundo numero: ";
            cin >> y;
            if (sonMmultiplos(x, y)) 
            {
                cout << x << " es multiplo de " << y << endl;
            } else {
                cout << x << " no es multiplo de " << y << endl;
            }
            break;
        }

        case 'D': {
            cout<<"Saliendo del programa."<<endl;
            break;
        }

        default: {
            cout<<"Opcion no valida. ingrese el operador indicado."<<endl;
            break;
        }
    }
        
    } while (operador != 'D');
        
    return 0;
}