#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "listaxor.h"

int main(void)
{
    int action;
    printf("\nProyecto 2: TAD Lista XOR ~ Presentado por: Angel Patino y Leonardo Gonzalez\n");
    
    while (action != 0)
    {
        printf("\nIndique la accion a realizar:\n\n");
        printf("1. Crear Lista\n");
        printf("0. Cerrar la Aplicacion.\n\n");
        printf("Accion: ");
        scanf("%d", &action);

        if (action == 1)
        {
            Lista *list;
            list = crearLista(list);
            while (action != 0)
            {
                printf("\nUna nueva lista se ha creado!\n");
                printf("\nIndique la accion a realizar sobre la lista: \n\n");
                printf("1. Inicializar Lista (Eliminar todos sus elementos).\n");
                printf("2. Verificar si la Lista esta Vacia.\n");
                printf("3. Insertar elemento al Principio de la Lista.\n");
                printf("4. Insertar elemento al Final de la Lista.\n");
                printf("5. Insertar elemento de manera Ordenada en la Lista.\n");
                printf("6. Buscar un elemento en la Lista.\n");
                printf("7. Sacar elemento del Principio de la Lista.\n");
                printf("8. Sacar elemento del Final de la Lista.\n");
                printf("9. Sacar primera ocurrencia de un elemento en la Lista.\n");
                printf("10. Listar la Lista de Inicio a Final (Imprimir de Izquierda a Derecha).\n");
                printf("11. Listar la Lista de Final a Inicio (Imprimir de Derecha a Izquierda).\n");
                printf("12. Mostrar la cantidad de elementos de la Lista.\n");
                printf("0. Volver al menu principal.\n\n");
                printf("Accion: ");
                scanf("%d", &action);
            }
            action = -1;            
        }
    }

    printf("\nCerrando aplicacion...\n\n");
}