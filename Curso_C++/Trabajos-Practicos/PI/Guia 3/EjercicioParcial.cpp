/*Un comercio multirubros necesita un programa para administrar sus ventas, de cada venta se debe almacenar:
código de artículo, rubro, nombre del vendedor, fecha de venta (DD/MM), monto cobrado. Realizar un programa
con todos los módulos necesarios para cumplir con la siguiente funcionalidad:
a. Permitir al usuario cargar los rubros existenes, en un arreglo estático, teniendo en cuenta que no existen más
de 15 rubros posibles, pero el usuario podría cargar menos. Definir una condición de corte.
b. Permitir al usuario cargar las ventas del mes, insertando en una lista enlazada ordenada por rubro.
Se debe tener en cuenta que, antes de insertar cada venta, se debe validar que el rubro exista (es decir que 
sea uno de los rubros cargados en el inciso A). Definir un condición de corte.
c. Informar la cantidad de ventas mayores a $5000.
d. Pedir al usuario el ingreso de un código de artículo por teclado a buscar en la lista de ventas, e imprimir
los datos de las ventas correspondientes a ese código.*/

#include <iostream>
#include <string>
using namespace std;

const int DF = 15;

struct Venta {
    int codigo;
    string rubro;
    string nombre;
    long int fecha_venta;
    double monto_cobrado;
};

struct Nodo {
    Venta dato;
    Nodo *siguiente;
};

void cargarRubros(string arregloRub[], int& dl) {
    string rub;
    cout << "\nCarga de rubros: " << endl;
    cout << "Ingrese el nombre del rubro('z' para finalizar): ";
    getline(cin >> ws, rub);

    while (dl < DF && rub != "z" && rub != "Z") {
        arregloRub[dl] = rub;
        dl++;
        cout << "Ingrese el nombre del rubro('z' para finalizar): ";
        getline(cin >> ws, rub);
    }
}

bool existeRubro(string arregloRub[], int dl, string rub) {  // Busca si el rubro existe en el arreglo
    for (int i = 0; i < dl; i++) {
        if (arregloRub[i] == rub) {
            return true;
        }
    }
    return false;
}

Nodo* crearNodo(Venta dato) {
    Nodo *nuevo = new Nodo(); // Reservo memoria para un nuevo nodo.
    nuevo->dato = dato;
    nuevo->siguiente = nullptr; // El siguiente nodo es nulo.
    return nuevo; // Devuelvo el nuevo nodo.
}

void carga_ventas(Nodo*& lista, string rubros[], int dl) {
    int cod;
    Venta venta;
    string rubroTemporal; // Variable temporal para almacenar el rubro ingresado
    cout << "\nCarga de ventas: " << endl;
    cout << "Ingrese el codigo de la venta(0 para finalizar): "; 
    cin >> cod;

    while (cod != 0) {
        venta.codigo = cod;
        cout << "Ingrese un rubro existente: ";
        getline(cin >> ws, rubroTemporal);
        while (!existeRubro(rubros, dl, rubroTemporal)) {
            cout << "El rubro ingresado no existe. Ingrese un rubro existente: ";
            getline(cin >> ws, rubroTemporal);
        }
        cout << "Ingrese el nombre del vendedor: ";
        getline(cin >> ws, venta.nombre);
        cout << "Ingrese la fecha de la venta(DD/MM): ";
        cin >>  venta.fecha_venta;
        cout << "Ingrese el monto cobrado: ";
        cin >> venta.monto_cobrado;

        Nodo* nuevaVenta = crearNodo(venta); // Creo un nuevo nodo con la venta ingresada.
        lista_ordenada(lista, nuevaVenta); //  Llamo a la función para ordenar la lista.
        cout << "\nVenta  cargada con éxito." << endl;
        cout << "---------------" << endl;
        cout << "Ingrese el codigo de la siguiente venta(0 para finalizar): ";
        cin >> cod;
    }
}

void lista_ordenada(Nodo*& inicio, Nodo* nuevo) {
    if (inicio == nullptr || nuevo->dato.rubro < inicio->dato.rubro) { // Si la lista está vacía o el nuevo nodo tiene un rubro menor que el del nodo actual, lo inserto al inicio.
        nuevo->siguiente = inicio; // El nuevo nodo apunta al nodo actual.
        inicio = nuevo; // El nodo actual es el nuevo nodo.
    }
    else {
        Nodo* aux = inicio;
        while (aux->siguiente != nullptr && aux->siguiente->dato.rubro < nuevo->dato.rubro) {
            aux = aux->siguiente;
        }
        nuevo->siguiente = aux->siguiente; // El nuevo nodo apunta al nodo que estaba después del nodo actual.
        aux->siguiente = nuevo; // El nodo actual apunta al nuevo nodo.
    }
}

void informarVentasMayoresA(Nodo* lista, int maximo) {
    int contador = 0;
    
    Nodo* aux = lista;
    while (aux != nullptr) {
        if (aux->dato.monto_cobrado >= maximo) {
            contador++;
        }
        aux = aux->siguiente;
    }

    cout << "La cantidad de ventas mayores a $5000 son: " << contador << endl;
}

void imprimir_ventas(Nodo* lista) {
    int cod;
    cout << "Ingrese el codigo del articulo a buscar: ";
    cin >> cod;
    
    Nodo* aux = lista;
    while(aux != nullptr) {
        if(aux->dato.codigo == cod) {
            cout << "Nombre del vendedor: " << aux->dato.nombre << endl;
            cout << "Fecha de la venta: " << aux->dato.fecha_venta << endl;
            cout << "Monto cobrado: " << aux->dato.monto_cobrado <<  endl;
        }
        aux = aux->siguiente; // Avanzo al siguiente nodo.

    }
}

int main () {
    Nodo* inicio = nullptr;
    int dl = 0;
    string arregloRubro[DF];
    int max;

    cargarRubros(arregloRubro, dl);
    carga_ventas(inicio, arregloRubro, dl);
    cout << "\nIngrese el valor maximo a buscar por ventas: ";
    cin >> max;
    informarVentasMayoresA(inicio, max);
    imprimir_ventas(inicio);
    return 0;
}