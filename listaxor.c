#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "listaxor.h"

// Funcion para hacer XOR entre direcciones de punteros (Usando la libreria <stdint.h>)

node *XOR(node *x, node *y)
{
    return (node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

// Funcion (Nro 1) para Crear una nueva Lista

Lista *crearLista(Lista *L)
{
    L = (Lista*)malloc(sizeof(Lista));

    // Inicializamos la Cabeza y Cola de la Lista

    L->head = NULL;
    L->tail = NULL;

    return L;   // Regresamos los cambios hechos a main
}

// Funcion (Nro 2 NO COMPLETADA) para Inicializar una Lista (Eliminar todos sus elementos)

void Inicializar(Lista *L)
{
    if (esVacia(L) == 1)
    {
        printf("La lista ya esta Vacia!\n");
        return;
    }
    else
    {
        int element;
        while (cantidadElementos(L) != 0)
            sacarFinal(L, &element);
        L->head = L->tail = NULL;
        return;
    }
}

// Funcion (Nro 3) para verificar si una Lista esta Vacia

int esVacia(Lista *L)
{
    // Si la Lista esta vacia (No tiene ningun elemento) entonces retornara un 1 a boolean en main()

    if (L->head == NULL && L->tail == NULL)
        return 1;
    else
        return 0;   // Si no esta vacia (Tiene minimo 1 un elemento), entonces retornara un 0 a boolean en main()
}

// Funcion (Nro 4) para insertar un elemento al Inicio de la Lista

int insertarPrincipio(Lista *L, int element)
{
    node *new_node, *ptr_next;
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
        new_node->prev_next = XOR(NULL, L->head);
        ptr_next = XOR(NULL, L->head->prev_next);
        L->head->prev_next = XOR(new_node, ptr_next);
        L->head = new_node;

        return 1;
    }
    else
        return 0;
}

// Funcion (Nro 5) para insertar un elemento al Final de la Lista

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

// Funcion (Nro 7) para buscar un elemento en la Lista

int buscar(Lista *L, int element)
{
    if (esVacia(L) == 1)
        return 0;
    else
    {
        node * ptr_aux, *ptr_prev, *ptr_next;
        ptr_aux = L->head;
        ptr_prev = NULL;

        while (ptr_aux != NULL)
        {
            if (ptr_aux->data == element)
                return 1;
            else
            {
                ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
                ptr_prev = ptr_aux;
                ptr_aux = ptr_next;
            }
        }

        return 0;    // No se consigue el elemento tras iterar dentro de la lista, retornar 0
    }
}

// Funcion (Nro 9) para sacar el elemento del final en la Lista

int sacarFinal(Lista *L, int *element)
{
    if (esVacia(L) == 1)
        return 0;
    else
    {
        node *ptr_aux, *ptr_free, *ptr_prev, *ptr_next;
        ptr_next = NULL;
        ptr_aux = L->tail;

        if (L->head == L->tail)
        {
            *element = L->head->data;
            free(ptr_aux);
            L->head = NULL;
            L->tail = NULL;

            return 1;
        }
        else
        {
            *element = L->tail->data;
            ptr_prev = XOR(L->tail->prev_next, ptr_next);
            ptr_free = ptr_aux;
            ptr_aux = ptr_prev;
            L->tail = ptr_aux;
            ptr_next = ptr_free;
            ptr_aux->prev_next = XOR(L->tail->prev_next, ptr_next);
            ptr_next = NULL;
            free(ptr_free);

            return 1;
        }
    }
}

// Funcion (Nro 11) para listar de Inicio a Final (Imprimir de Izquierda a Derecha)

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

// Funcion (Nro 12) para listar de Final a Inicio (Imprimir de Derecha a Izquierda)

void listarFinalAInicio(Lista *L)
{
    if (esVacia(L) == 1)
    {
        printf("La lista es vacia! No tiene elementos para listar...\n");
        return;       
    }
    else
    {
        node *ptr_aux, *prev, *next;
        ptr_aux = L->tail;
        next = NULL;
        printf("Tail ---> ");

        while (ptr_aux != NULL)
        {
            printf("%d ", ptr_aux->data);
            prev = XOR(next, ptr_aux->prev_next);
            next = ptr_aux;
            ptr_aux = prev;
        }
        printf("<--- Head\n");    
    }
}

// Funcion (Nro 13) para determinar la cantidad de elementos en la Lista.

int cantidadElementos(Lista *L)
{
    int element_count = 0;
    node *ptr_aux, *ptr_prev, *ptr_next;
    ptr_aux = L->head;
    ptr_prev = NULL;

    if (esVacia(L) == 1)
        return element_count;
    else
    {
        while (ptr_aux != NULL)
        {
            element_count += 1;
            ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
            ptr_prev = ptr_aux;
            ptr_aux = ptr_next;
        }

        return element_count;
    }
}