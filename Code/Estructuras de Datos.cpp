#include <list>
//Listas Simplemente Enlazadas (SE)

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* siguiente;
};

// Agregar un nodo al final de la lista
void agregarNodo(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (*cabeza == nullptr) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

//////////////////////////////////////
//Listas Doblemente Enlazadas (DE)

// Definición del nodo
struct Nodo {
    int dato;
    Nodo* anterior;
    Nodo* siguiente;
};

// Agregar un nodo al final de la lista
void agregarNodo(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (*cabeza == nullptr) {
        nuevoNodo->anterior = nullptr;
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
    }
}

//////////////////////////////////////
//Pilas

// Definición de la pila
struct Pila {
    int dato;
    Pila* siguiente;
};

// Agregar un elemento a la pila
void push(Pila** cima, int valor) {
    Pila* nuevoNodo = new Pila;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cima;
    *cima = nuevoNodo;
}

// Eliminar un elemento de la pila
int pop(Pila** cima) {
    if (*cima == nullptr) {
        return -1; // Pila vacía
    }
    Pila* temp = *cima;
    int valor = temp->dato;
    *cima = (*cima)->siguiente;
    delete temp;
    return valor;
}

//////////////////////////////////////
//Colas

// Definición de la cola
struct Cola {
    int dato;
    Cola* siguiente;
};

// Agregar un elemento a la cola
void encolar(Cola** frente, Cola** final, int valor) {
    Cola* nuevoNodo = new Cola;
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = nullptr;

    if (*frente == nullptr) {
        *frente = *final = nuevoNodo;
    } else {
        (*final)->siguiente = nuevoNodo;
        *final = nuevoNodo;
    }
}

// Eliminar un elemento de la cola
int desencolar(Cola** frente, Cola** final) {
    if (*frente == nullptr) {
        return -1; // Cola vacía
    }
    Cola* temp = *frente;
    int valor = temp->dato;
    *frente = (*frente)->siguiente;
    if (*frente == nullptr) {
        *final = nullptr;
    }
    delete temp;
    return valor;
}

//////////////////////////////////////
//Grafos

// Definición del grafo usando Lista de Vertices
struct Grafo {
    int vertices;
    list<int>* lista;
};

// Crear un grafo
Grafo* crearGrafo(int vertices) {
    Grafo* nuevoGrafo = new Grafo;
    nuevoGrafo->vertices = vertices;
    nuevoGrafo->lista = new list<int>[vertices];
    return nuevoGrafo;
}

// Agregar una arista al grafo
void agregarArista(Grafo* grafo, int origen, int destino) {
    grafo->lista[origen].push_back(destino);
}

// Imprimir el grafo
void imprimirGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->vertices; ++i) {
        cout << "Vértice " << i << ":";
        for (int vertice : grafo->lista[i]) {
            cout << " -> " << vertice;
        }
        cout << endl;
    }
}

// Definición del grafo usando Matriz de Adyacencia

// Definición del grafo usando Lista de listas de Adyacencia
