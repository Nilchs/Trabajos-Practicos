#include <iostream>
#include <string>
using namespace std;

struct Direccion {
    int piso;
    string localidad, calle;
    char departamento;
};

struct Participante {
    string nombre, apellido;
    string mail;
    string tipo_documento;
    int numero_documento;
    Direccion direccion;
};

const int max_participantes = 3000;

void agregarParticipante(Participante participantes[], int &dl) {
    int num_documento;
    cout << "Ingrese el numero de documento del participante(0 para finalizar): ";
    cin >> num_documento;

    while (dl < max_participantes &&  num_documento != 0) {
        participantes[dl].numero_documento = num_documento;
        cout << "Ingrese el nombre del participante: ";
        getline(cin >> ws, participantes[dl].nombre);
        cout << "Ingrese el apellido del participante: ";
        getline(cin >> ws, participantes[dl].apellido);
        cout << "Ingrese el mail del participante: ";
        getline(cin >> ws, participantes[dl].mail);
        participantes[dl].tipo_documento = "DNI"; // definido por defecto el tipo de documento como 'DNI'.
        
        cout << "------------" << endl;
        cout << "Carga de Direccion." << endl;
        cout << "Ingrese el piso de su domicilio: ";
        cin >> participantes[dl].direccion.piso;
        cout << "Ingrese la localidad de su domicilio: ";
        getline(cin >> ws, participantes[dl].direccion.localidad);
        cout << "Ingrese el departamento: ";
        cin >> participantes[dl].direccion.departamento;
        cout << "Ingrese la calle de su domicilio: ";
        getline(cin >> ws, participantes[dl].direccion.calle);
        dl++;

        cout << "Ingrese el numero de documento del proximo participante(0 para finalizar): ";
        cin >> num_documento;
        cin.ignore();
    }
}

void BuscaParticipante(Participante participantes[], int dl) {
    int dniABuscar;
    cout << "\nIngrese el DNI del participante a buscar: ";
    cin >> dniABuscar;
    
    int i = 0;
    while (i < dl && participantes[i].numero_documento != dniABuscar) {
        i++;
    }

    if (i < dl) {
        cout << "Participante validado satisfactoriamente." << endl;
    } else {
        cout << "Para validarse primero debe acreditarse." << endl;
    }
}

void imprimirParticipantes(Participante participantes[], int dl) {
    cout << "\nDatos de los participantes acreditados." << endl;
    for  (int i = 0; i < dl; i++) {
        cout << "Nombre: " << participantes[i].nombre << endl;
        cout << "Apellido: " << participantes[i].apellido << endl;
        cout << "Numero de documento del DNI: " << participantes[i].numero_documento << endl;
        cout << "Mail: " << participantes[i].mail << endl;
        cout << "Datos de la direccion del participante." << endl;
        cout << "Piso: " << participantes[i].direccion.piso << endl;
        cout << "Localidad: " << participantes[i].direccion.localidad << endl;
        cout << "Departamento: " << participantes[i].direccion.departamento << endl;
        cout << "Calle: " << participantes[i].direccion.calle << endl;
        cout << endl;
        cout << "------------" << endl;
    }
    cout  << endl;
}

int main () {
    Participante participantes[max_participantes];
    int dl = 0;

    agregarParticipante(participantes, dl);
    BuscaParticipante(participantes, dl);
    imprimirParticipantes(participantes, dl);
    return 0;
}