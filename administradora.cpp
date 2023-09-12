#include "administradora.h"

using namespace std;

administradora::administradora() : cabeza(nullptr) {}

void administradora::agregarInicio(Neurona& neu ){
    Nodo* nuevoNodo = new Nodo(neu);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void administradora::agregarFinal(Neurona& neu){
    Nodo* nuevoNodo = new Nodo(neu);

        // Si la lista está vacía, simplemente establece la cabeza como el nuevo nodo.
        if (!cabeza) {
            cabeza = nuevoNodo;
            return;
        }

        // Encuentra el último nodo en la lista.
        Nodo* temp = cabeza;
        while (temp->siguiente) {
            temp = temp->siguiente;
        }

        // Conecta el último nodo con el nuevo nodo.
        temp->siguiente = nuevoNodo;
}

string administradora::mostrar(){
    Nodo* temp = cabeza;
    std::string res;  // Inicializa res como una cadena vacía
    while (temp)
    {
        res += temp->dato.print(); // Usa += para agregar datos a res
        temp = temp->siguiente;
    }
    return res;
}
