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

// Funcion (Nro 1) para Crear una nueva Lista

Lista *crearLista(Lista *L);

// Funcion (Nro 2 NO COMPLETADA) para Inicializar una Lista (Eliminar todos sus elementos)

void Inicializar(Lista *L);

// Funcion (Nro 3) para verificar si una Lista esta Vacia

int esVacia(Lista *L);

// Funcion (Nro 4) para insertar un elemento al Inicio de la Lista

int insertarPrincipio(Lista *L, int element);

// Funcion (Nro 5) para insertar un elemento al Final de la Lista

int insertarFinal(Lista *L, int element);

// Funcion (Nro 7) para buscar un elemento en la Lista

int buscar(Lista *L, int element);

// Funcion (Nro 8) para sacar el elemento del inicio en la Lista

int sacarPrincipio(Lista *L, int *element);

// Funcion (Nro 9) para sacar el elemento del final en la Lista

int sacarFinal(Lista *L, int *element);

// Funcion (Nro 11) para listar de Inicio a Final (Imprimir de Izquierda a Derecha)

void listarInicioAFinal(Lista *L);

// Funcion (Nro 12) para listar de Final a Inicio (Imprimir de Derecha a Izquierda)

void listarFinalAInicio(Lista *L);

// Funcion (Nro 13) para determinar la cantidad de elementos en la Lista.

int cantidadElementos(Lista *L);