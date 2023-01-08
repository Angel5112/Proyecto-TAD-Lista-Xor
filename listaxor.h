#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Definicion de las estructuras para la lista y los nodos

typedef struct Node
{
    int data;
    Node *prev_next;
}node;

typedef struct List
{
    node *head, *tail;
}list;

// Funcion para hacer XOR entre direcciones de punteros (Usando la libreria <stdint.h>)

node *XOR(node *x, node *y);