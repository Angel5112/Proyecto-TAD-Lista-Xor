#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Definicion de las estructuras para la lista y los nodos

typedef struct Node
{
    int data;
    struct Node *prev_next;
}node;

typedef struct List
{
    node *head, *tail;
}Lista;

// Funcion para hacer XOR entre direcciones de punteros (Usando la libreria <stdint.h>)

node *XOR(node *x, node *y);

// Funcion para Crear una nueva Lista

Lista *crearLista(Lista *L);

// Funcion para verificar si una Lista esta Vacia

int esVacia(Lista *L);

// Funcion para insertar un elemento al Final de la Lista

int insertarFinal(Lista *L, int element);

// Funcion para listar de Inicio a Final (Imprimir de Izquierda a Derecha)

void listarInicioAFinal(Lista *L);