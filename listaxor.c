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