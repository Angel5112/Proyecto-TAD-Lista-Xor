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

// Funcion (Nro 2) para Inicializar una Lista (Eliminar todos sus elementos)

void Inicializar(Lista *L)
{
    if (esVacia(L) == 1)
    {
        // Verificar si la lista esta vacia para evitar hacer operaciones innecesarias

        printf("La lista ya esta Vacia!\n");
        return;
    }
    else
    {
        int element;
        while (cantidadElementos(L) != 0)   // Mientras la lista siga teniendo elementos, eliminar el final
            sacarFinal(L, &element);
        L->head = L->tail = NULL;       // Asignar los punteros de Head y Tail a NULL
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
        // Si la lista esta vacia, se crea un nuevo nodo y es asignado a Head y Tail de la lista

        new_node->data = element;
        new_node->prev_next = XOR(NULL, NULL);
        L->head = L->tail = new_node;

        return 1;
    }
    else if (esVacia(L) == 0)
    {
        new_node->data = element;   // Asignar el elemento al nodo
        new_node->prev_next = XOR(NULL, L->head);   // Asignarle la direccion en prev_next
        ptr_next = XOR(NULL, L->head->prev_next);   // Tener referencia del siguiente a Head
        L->head->prev_next = XOR(new_node, ptr_next);   // Asignar la direccion del nodo siguiente al nuevo como la siguiente de Head
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
        // Si la lista esta vacia, el nuevo nodo sera el unico elemento de la lista

        new_node->data = element;
        new_node->prev_next = XOR(NULL, NULL);
        L->head = L->tail = new_node;       // Tanto Head como Tail apuntaran al nuevo nodo

        return 1;
    }
    else if (esVacia(L) == 0)
    {
        new_node->data = element;
        new_node->prev_next = XOR(L->tail, NULL);   // Prev_next del nuevo nodo guardara la posicion de Tail
        ptr_prev = XOR(L->tail->prev_next, NULL);   // Guardar referencia del nodo anterior a Tail
        L->tail->prev_next = XOR(ptr_prev, new_node);  // Asignar la direccion del anterior al nuevo nodo 
        L->tail = new_node;                         // La nueva Tail sera el nuevo nodo

        return 1;
    }
    else
        return 0;
}

// Funcion (Nro 6) para insertar un elemento de manera ordenada en la Lista

int insertarOrden(Lista *L, int element)
{
    // CASO 1: Lista vacia

    if (esVacia(L) == 1)
    {
        insertarPrincipio(L, element);
        return 1;
    }
    else
    {
        // CASO 2: Lista de 1 solo elemento

        if (L->head == L->tail)
        {
            if (element <= L->head->data)
            {
                insertarPrincipio(L, element);
                return 1;
            }
            else
            {
                insertarFinal(L, element);
                return 1;
            }
        }

        // CASO 3: Elemento nuevo es menor que el primer elemento de la lista

        if (element <= L->head->data)
        {
            insertarPrincipio(L, element);
            return 1;
        }

        // Ojo, como se sabe que el elemento no es menor que el primero, es recomendable pasar de una al segundo elemento, asi se podra usar el ptr_prev->data para las comparaciones

        node *ptr_aux, *ptr_prev, *ptr_next, *ptr_new, *ptr_prev2;

        ptr_aux = L->head;
        ptr_prev = NULL;
        ptr_new = (node*)malloc(sizeof(node));
        ptr_new->data = element;

        ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
        ptr_prev = ptr_aux;
        ptr_aux = ptr_next;

        while (ptr_aux != NULL)
        {
            // CASO 4: Nuevo nodo se encuentra entre 2 nodos

            if (ptr_prev->data <= element && ptr_aux->data > element)
            {
                ptr_new->prev_next = XOR(ptr_prev, ptr_aux);
                ptr_prev2 = XOR(ptr_prev->prev_next, ptr_aux);
                ptr_prev->prev_next = XOR(ptr_prev2, ptr_new);
                ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
                ptr_aux->prev_next = XOR(ptr_new, ptr_next);

                return 1;
            }

            ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
            ptr_prev = ptr_aux;
            ptr_aux = ptr_next;

            // CASO 5: Llegada a Tail que es menor que el nuevo elemento del nodo a insertar

            if (ptr_aux == L->tail && element >= L->tail->data)
            {
                insertarFinal(L, element);
                return 1;
            }
        }
    }
}

// Funcion (Nro 7) para buscar un elemento en la Lista

int buscar(Lista *L, int element)
{
    if (esVacia(L) == 1)
        return 0;
    else
    {
        node * ptr_aux, *ptr_prev, *ptr_next;
        ptr_aux = L->head;  // Se comenzara la busqueda desde la Head
        ptr_prev = NULL;

        while (ptr_aux != NULL) // Mientras el elemento actual, no sea NULL, recorrer la lista
        {
            if (ptr_aux->data == element)   // Si un elemento en la lista coincide con el elemento a buscar, se retorna 1
                return 1;
            else
            {
                ptr_next = XOR(ptr_prev, ptr_aux->prev_next);   // Si no se consigue en ese nodo, iterar al siguiente
                ptr_prev = ptr_aux;
                ptr_aux = ptr_next;
            }
        }

        return 0;    // No se consigue el elemento tras iterar dentro de la lista, retornar 0
    }
}

// Funcion (Nro 8) para sacar el elemento del inicio en la Lista

int sacarPrincipio(Lista *L, int *element)
{
    if (esVacia(L) == 1)    // Si la lista es vacia, no se puede eliminar nada
        return 0;
    else
    {
        node *ptr_aux, *ptr_free, *ptr_prev, *ptr_next;
        ptr_prev = NULL;
        ptr_aux = L->head;

        if (L->head == L->tail) // Si la Head apunta al mismo nodo que la Tail, se elimina el unico nodo de la lista
        {
            *element = L->head->data;
            free(ptr_aux);
            L->head = NULL;
            L->tail = NULL;

            return 1;
        }
        else    // Se guarda la referencia al siguiente de la Head y se le asigna un puntero a Head
        {
            *element = L->head->data;
            ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
            ptr_free = ptr_aux;
            ptr_aux = ptr_next; // Se mueve el puntero auxiliar al siguiente de Head
            ptr_prev = ptr_free;
            L->head = ptr_aux;  // Se asigna la nueva Head
            ptr_aux->prev_next = XOR(ptr_prev, L->head->prev_next); // Se actualiza el prev_next de la nueva Head
            ptr_prev = NULL;
            free(ptr_free);     // Liberar el nodo guardado en la anterior Head

            return 1;
        }
    }
}

// Funcion (Nro 9) para sacar el elemento del final en la Lista

int sacarFinal(Lista *L, int *element)
{
    if (esVacia(L) == 1)    // Si la lista esta vacia, no se puede hacer nada
        return 0;
    else
    {
        node *ptr_aux, *ptr_free, *ptr_prev, *ptr_next;
        ptr_next = NULL;
        ptr_aux = L->tail;

        if (L->head == L->tail) // Si la Head apunta al mismo nodo que Tail, se elimina el unico nodo de la lista
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
            ptr_prev = XOR(L->tail->prev_next, ptr_next);   // Guardar la referencia del anterior a Tail
            ptr_free = ptr_aux;     // Asignar un puntero a Tail
            ptr_aux = ptr_prev; // Mover el puntero original al anterior a Tail
            L->tail = ptr_aux;  // Reasignar Tail
            ptr_next = ptr_free;
            ptr_aux->prev_next = XOR(L->tail->prev_next, ptr_next); // Ajustar el prev_next del anterior al antiguo Tail
            ptr_next = NULL;    
            free(ptr_free);     // Eliminar el nodo que era la anterior Tail

            return 1;
        }
    }
}

// Funcion (Nro 11) para listar de Inicio a Final (Imprimir de Izquierda a Derecha)

void listarInicioAFinal(Lista *L)
{
    if (esVacia(L) == 1)    // Si la lista esta vacia, no se puede imprimir nada
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
        while (ptr_aux != NULL) // Imprimir elemento a elemento de la lista mientras que el puntero auxiliar != NULL
        {
            printf("%d ", ptr_aux->data);
            next = XOR(prev, ptr_aux->prev_next);   // Iterar de derecha a izquierda
            prev = ptr_aux;
            ptr_aux = next;
        }
        printf("<--- End\n");
    }
}

// Funcion (Nro 12) para listar de Final a Inicio (Imprimir de Derecha a Izquierda)

void listarFinalAInicio(Lista *L)
{
    if (esVacia(L) == 1)    // Si la lista esta vacia, no se puede imprimir nada
    {
        printf("La lista es vacia! No tiene elementos para listar...\n");
        return;       
    }
    else
    {
        node *ptr_aux, *prev, *next;
        ptr_aux = L->tail;
        next = NULL;
        printf("End ---> ");

        while (ptr_aux != NULL) // Imprimir elemento a elemento de la lista mientras que el puntero auxiliar != NULL
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

    if (esVacia(L) == 1)    // Si es vacia, entonces tiene 0 elementos
        return element_count;
    else
    {
        while (ptr_aux != NULL) // Recorrer la lista y usar un contador elemento por elemento
        {
            element_count += 1;
            ptr_next = XOR(ptr_prev, ptr_aux->prev_next);
            ptr_prev = ptr_aux;
            ptr_aux = ptr_next;
        }

        return element_count;
    }
}