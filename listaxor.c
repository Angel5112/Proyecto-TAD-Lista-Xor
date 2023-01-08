#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "listaxor.h"

// Funcion para hacer XOR entre direcciones de punteros (Usando la libreria <stdint.h>)

node *XOR(node *x, node *y)
{
    return (node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

// Funcion para Crear una nueva Lista

Lista *crearLista(Lista *L)
{
    L = (Lista*)malloc(sizeof(Lista));

    // Inicializamos la Cabeza y Cola de la Lista

    L->head = NULL;
    L->tail = NULL;

    return L;   // Regresamos los cambios hechos a main
}

// Funcion para verificar si una Lista esta Vacia

int esVacia(Lista *L)
{
    // Si la Lista esta vacia (No tiene ningun elemento) entonces retornara un 1 a boolean en main()

    if (L->head == NULL && L->tail == NULL)
        return 1;
    else
        return 0;   // Si no esta vacia (Tiene minimo 1 un elemento), entonces retornara un 0 a boolean en main()
}

// Funcion para insertar un elemento al Final de la Lista

int insertarFinal(Lista *L, int element)
{
    node *new_node, *ptr_prev;
    new_node = (node*)malloc(sizeof(node));

    if (esVacia(L) == 1)
    {
        new_node->data = element;
        new_node->prev_next = XOR(NULL, NULL);
        L->head = L->tail = new_node;

        return 1;
    }
    else if (esVacia(L) == 0)
    {
        new_node->data = element;
        new_node->prev_next = XOR(L->tail, NULL);
        ptr_prev = XOR(L->tail->prev_next, NULL);
        L->tail->prev_next = XOR(ptr_prev, new_node);
        L->tail = new_node;

        return 1;
    }
    else
        return 0;
}

// Funcion para listar de Inicio a Final (Imprimir de Izquierda a Derecha)

void listarInicioAFinal(Lista *L)
{
    if (esVacia(L) == 1)
    {
        printf("La lista es vacia! No tiene elementos para listar...\n");
        return;
    }
    else
    {
        node *ptr_aux, *prev, *next;
        prev = NULL;
        printf("Head ---> ");
        ptr_aux = L->head;
        while (ptr_aux != NULL)
        {
            printf("%d ", ptr_aux->data);
            next = XOR(prev, ptr_aux->prev_next);
            prev = ptr_aux;
            ptr_aux = next;
        }
        printf("<--- Tail\n");
    }
}