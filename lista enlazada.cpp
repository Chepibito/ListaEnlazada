#include <iostream>
#include <string>
using namespace std;

// Clase Nodo
class Nodo {
public:
    // Dato del nodo que puede ser de cualquier tipo
    string data;
    Nodo* siguiente; // Puntero al siguiente nodo

    Nodo(string data) : data(data), siguiente(nullptr) {}
};

// Clase Lista Simplemente Enlazada
class ListaEnlazada {
private:
    Nodo* cabeza; // Puntero al primer nodo

public:
    ListaEnlazada() : cabeza(nullptr) {} // Constructor

    // Método para insertar un nuevo nodo al final
    void insertar(string valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (cabeza == nullptr) {
            cabeza = nuevoNodo; // Si la lista está vacía, el nuevo nodo es la cabeza
        } else {
            Nodo* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente; // Recorre hasta el final
            }
            actual->siguiente = nuevoNodo; // Inserta el nuevo nodo al final
        }
    }

    // Método para imprimir la lista
    void imprimir() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            cout << actual->data << " -> ";
            actual = actual->siguiente;
        }
        cout << "null" << endl;
    }

    // Destructor para liberar memoria
    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaEnlazada lista;

    // Insertar enteros (se convierten a string)
    lista.insertar(to_string(10));
    lista.insertar(to_string(20));

    // Insertar caracteres
    lista.insertar(string(1, 'A'));
    lista.insertar(string(1, 'B'));

    // Insertar cadenas
    lista.insertar("Hola");
    lista.insertar("Mundo");

    // Imprimir la lista
    lista.imprimir();

    return 0;
}
