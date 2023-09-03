#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct nodo {
    int dato;
    nodo* siguiente;
};

void insertarlista(nodo*&, int);
void buscarLista(nodo*, int);
void mostrarLista(nodo *);
void eliminarNodo(nodo*&, int);
void actualizarNodo(nodo* , int , int );

int main() {
    nodo* lista = NULL;
    char opcion;

    do {
        cout << "MENU:" << endl;
        cout << "1. Insertar un numero" << endl;
        cout << "2. Buscar un numero" << endl;
        cout << "3. Mostrar la lista de numeros" << endl;
        cout << "4. Eliminar un nodo de la lista"<<endl;
        cout << "5. Modificar/ actualizar un nodo"<<endl;
        cout << "6. Salir"<< endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case '1': {
                int dato;
                cout << "Digite un numero: ";
                cin >> dato;
                cout<<"\n";
                insertarlista(lista, dato);
                break;
            }
            case '2': {
                int dato;
                cout << "Digite el numero a buscar: ";
                cin >> dato;
                cout<<"\n";
                buscarLista(lista, dato);
                break;
            }
            case '3' :{
                mostrarLista(lista);
                cout<<"\n";
                break;
            }
            case '4' :{
                int dato;
                cout<<"Ingrese el valor que quiere borrar: ";
                cin>> dato;
                eliminarNodo(lista, dato);
                cout<<"\n";
                break;
            }
            case '5': {
                int dato, nuevoDato;
                cout << "Digite el numero a actualizar: ";
                cin >> dato;
                cout << "Digite el nuevo numero: ";
                cin >> nuevoDato;
                cout << "\n";
                actualizarNodo(lista, dato, nuevoDato);
                break;
            }
            case '6':
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Por favor, seleccione una opcion valida." << endl;
        }
    } while (opcion != '6');

    return 0;
}
void insertarlista(nodo*& lista, int n) {
    nodo* nuevonodo = new nodo();
    nuevonodo->dato = n;
    if (lista == nullptr) {
        lista = nuevonodo;
        nuevonodo->siguiente = nuevonodo;  
    } else {
        nodo* ultimo = lista;
        while (ultimo->siguiente != lista) {
            ultimo = ultimo->siguiente;
        }
        nuevonodo->siguiente = lista;
        lista = nuevonodo;
        ultimo->siguiente = lista;  // Hacer que el último nodo apunte al nuevo primer nodo
    }
    cout << "Elemento " << n << " insertado en la lista correctamente" << endl;
}
void buscarLista(nodo* lista, int n) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    int posicion = 1;
    nodo* m = lista;
    do {
        if (m->dato == n) {
            cout << "Elemento " << n << " encontrado en el nodo " << posicion << endl;
            return;
        }
        m = m->siguiente;
        posicion++; 
    } while (m != lista);

    cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
}

void mostrarLista(nodo* lista) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    nodo* actual = lista;
    do {
        cout << actual->dato << " -> ";
        actual = actual->siguiente;
    } while (actual != lista);
    cout << endl;
}

void eliminarNodo(nodo*& lista, int n) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    nodo* aux_borrar = lista;
    nodo* anterior = nullptr;

    do {
        if (aux_borrar->dato == n) {
            if (anterior == nullptr) {
                if (lista->siguiente == lista) {
                    // Caso especial: solo hay un nodo en la lista
                    delete lista;
                    lista = nullptr;
                } else {
                    nodo* ultimo = lista;
                    while (ultimo->siguiente != lista) {
                        ultimo = ultimo->siguiente;
                    }
                    lista = lista->siguiente;
                    ultimo->siguiente = lista;
                    delete aux_borrar;
                }
            } else {
                anterior->siguiente = aux_borrar->siguiente;
                if (aux_borrar == lista) {
                    lista = lista->siguiente;
                }
                delete aux_borrar;
            }
            cout << "Elemento " << n << " eliminado correctamente" << endl;
            return;
        }
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
    } while (aux_borrar != lista);
    cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
}

void actualizarNodo(nodo* lista, int n, int nuevoDato) {
    if (lista == nullptr) {
        cout << "La lista está vacía" << endl;
        return;
    }

    nodo* m = lista;
    do {
        if (m->dato == n) {
            m->dato = nuevoDato;
            cout << "Elemento " << n << " actualizado a " << nuevoDato << " correctamente" << endl;
            return;
        }
        m = m->siguiente;
    } while (m != lista);
    cout << "Elemento " << n << " no ha sido encontrado en la lista" << endl;
}

