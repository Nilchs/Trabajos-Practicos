/*"The Golden Gate Bridge" es el puente más famoso de la ciudad de San Francisco (California). Cuenta con una
longitud aproximada de 1280 metros y posee tres radares de toma de velocidad. Por cada móvil que se
desplaza por las vías principales se registra la siguiente información: sensor que lo captó (puede ser "norte",
"sur" o "medio"), patente (no tiene un formato único ya que difiere de un estado a otro y pueden transitar
autos extranjeros, aunque se sabe que están formadas sólo por letras y números) y velocidad en km/h.
A. Cargar las lecturas que hacen los sensores en una lista enlazada simple ordenando por patente y, para
la misma patente, ordenando por sensor (ya que un mismo automóvil puede ser captado por más de un
sensor). Finaliza con la patente "aaa99", que no se debe ingresar.*/

#include <iostream>
#include <string>
using namespace std;

struct Radar {
    string patente, sensor;
    float velocidad; // km/h
};

struct Nodo {
    Radar dato;
    Nodo *siguiente;
};

Nodo* crearNodo(Radar dato) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

// la lista enlazada se ordenará primero por patente y, en caso de que las patentes sean iguales, por sensor.
void lista_ordenada (Nodo*& inicio, Nodo* nuevo) {
    if (inicio == nullptr || (nuevo->dato.patente < inicio->dato.patente) || (nuevo->dato.patente == inicio->dato.patente && nuevo->dato.sensor < inicio->dato.sensor)) { // si el nuevo nodo es menor que el inicio, o si son iguales las patentes, pero el nuevo tiene un sensor menor a otro sensor con la misma patente entra al if.
        nuevo->siguiente = inicio; // El nuevo nodo apunta al nodo actual.
        inicio = nuevo; // El nodo actual es el nuevo nodo.
    }
    else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr && (aux->siguiente->dato.patente < nuevo->dato.patente || (aux->siguiente->dato.patente == nuevo->dato.patente && aux->siguiente->dato.sensor < nuevo->dato.sensor))) { // Mientras el siguiente nodo sea menor que el nuevo nodo, o si son iguales pero el siguiente tiene un sensor menor a otro sensor con la misma patente, se sigue avanzando.
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente; // El nuevo nodo apunta al nodo que estaba después del nodo actual.
        aux->siguiente = nuevo; // El nodo actual apunta al nuevo nodo.
    }
}

void cargarRadares(Nodo*& lista) {
    string patente;
    Radar radar;
    cout << "Ingrese la patente del vehiculo ('aaa99' para finalizar): ";
    getline(cin >> ws, patente);

    while (patente != "aaa99" || patente != "AAA99") {
        radar.patente = patente;
        do
        {
            cout << "Ingrese el sensor que capturo la lectura(Norte, Sur o Medio): ";
            getline(cin >> ws, radar.sensor);
            if (radar.sensor != "Norte" && radar.sensor != "Sur" && radar.sensor != "Medio")
            {
                cout << "Sensor invalido, por favor ingrese Norte, Sur o Medio.";
            } 
        } while (radar.sensor != "Norte" && radar.sensor != "Sur" && radar.sensor != "Medio");

        cout << "Ingrese la velocidad del vehiculo en km/h: ";
        cin >> radar.velocidad;

        Nodo* nuevoNodo = crearNodo(radar);
        lista_ordenada(lista, nuevoNodo);

        cout << "Ingrese la siguiente patente del vehiculo('aaa99' para finalizar): ";
        getline(cin >> ws, patente);
    }
}

void imprimirLecturas(Nodo* inicio)
{
    Nodo* aux = inicio;
    while (aux != nullptr)
    {
        cout << "Patente: " << aux -> dato.patente << ", Sensor: " << aux -> dato.sensor << ", Velocidad: " << aux -> dato.velocidad << " km/h" << endl;
        aux = aux -> siguiente;
    }
}

int main () {
    Nodo* inicio = nullptr;

    cargarRadares(inicio);
    imprimirLecturas(inicio);
        
    return 0;
}