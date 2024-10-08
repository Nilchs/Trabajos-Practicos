#include <iostream>
#include <string>
using namespace std;

const int max_personas = 3000;

struct Direccion {
    string calle;
    int altura;
    string localidad;
};

struct  Participante {
    int DNI;
    string apellido;
    string  nombre;
    Direccion  direccion;
};

void cargarParticipantes(Participante participantes[], int& dl) {
    if (dl >= max_personas) // Si el arreglo está lleno, no se puede cargar más alumnos
    {
        cout << "\nNo hay más espacio para agregar participantes." << endl;
        return;
    }
    
    int dni;
    cout << " Ingrese el DNI del participante (0 para finalizar): ";
    cin >> dni;

    while(dl <= max_personas && dni != 0) {
        participantes[dl].DNI = dni;
        cout << " Ingrese el apellido del participante: ";
        getline(cin >> ws,  participantes[dl].apellido);
        cout << " Ingrese el nombre del participante: ";
        getline(cin >> ws, participantes[dl].nombre);
        cout << " Ingrese la calle de la direccion del participante: ";
        getline(cin >> ws, participantes[dl].direccion.calle);
        cout << " Ingrese la altura de la direccion del participante: ";
        cin >> participantes[dl].direccion.altura;
        cin.ignore();
        cout << " Ingrese la localidad de la direccion del participante: ";
        getline(cin >> ws, participantes[dl].direccion.localidad);
        dl++;
        cout << " Ingrese el DNI del participante (0 para finalizar): ";
        cin >> dni;
        cin.ignore();
    }
    cout << endl;
}

void emitirCredencial(Participante participantes[], int dl) {
    int dniABuscar;
    cout << "\nIngrese el DNI del participante para emitir credencial: ";
    cin >> dniABuscar;

    int i = 0;
    while (i < dl && participantes[i].DNI != dniABuscar) {
        i++;
    }
    if (i < dl) {
        cout << "\nCredencial emitida con exito.";
    }
    else {
        cout << "\nDebe acreditarse.";
    }
}

void imprimirParticipantes(Participante  participantes[], int dl) {
    for (int i = 0; i < dl; i++) {
        cout << "\nDNI: " << participantes[i].DNI << endl;
        cout << "Apellido: " <<  participantes[i].apellido << endl;
        cout << "Nombre: " <<  participantes[i].nombre << endl;
        cout << "Localidad." << endl;
        cout << "Calle: " << participantes[i].direccion.calle << endl;
        cout << "Altura: " << participantes[i].direccion.altura << endl;
        cout << "Localidad: " << participantes[i].direccion.localidad << endl;
    }
}

int main () {
    int dl = 0;
    Participante participantes[max_personas];
    cargarParticipantes(participantes, dl);
    emitirCredencial(participantes, dl);
    imprimirParticipantes(participantes, dl);

    return 0;
}