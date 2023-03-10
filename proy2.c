#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "listaxor.h"

int main(void)
{
    int action, boolean, new_element, element_num;

    action = -1;

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
            printf("\nUna nueva lista se ha creado!\n");

            while (action != 0)
            {
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

                if (action == 1)
                {
                    Inicializar(list);
                    printf("\nEliminado todos los elementos de la Lista!\n");
                }
                else if (action == 2)
                {
                    boolean = esVacia(list);
                    if (boolean == 0)
                        printf("\nLa lista NO esta Vacia!\n");
                    else
                        printf("\nLa lista esta Vacia!\n");
                }
                else if (action == 3)
                {
                    printf("\nIngrese el nuevo elemento a introducir en el inicio: ");
                    scanf("%d", &new_element);
                    boolean = insertarPrincipio(list, new_element);
                    if (boolean == 0)
                        printf("\nError: No se pudo insertar el elemento %d!\n", new_element);
                    else
                        printf("\nElemento %d insertado en el inicio de la lista!\n", new_element);
                }
                else if (action == 4)
                {
                    printf("\nIngrese el nuevo elemento a introducir al final: ");
                    scanf("%d", &new_element);
                    boolean = insertarFinal(list, new_element);
                    if (boolean == 0)
                        printf("\nError: No se pudo insertar el elemento %d!\n", new_element);
                    else
                        printf("\nElemento %d insertado al final de la lista!\n", new_element);
                }
                else if (action == 5)
                {
		    list = ordenarLista(list);
		    printf("\nIngrese el nuevo elemento a introducir de manera ordenada: ");
                    scanf("%d", &new_element);
		    boolean = insertarOrden(list, new_element);
                    if (boolean == 0)
                        printf("\nError: No se pudo insertar el elemento %d!\n", new_element);
                    else
                        printf("\nElemento %d insertado en la lista!\n", new_element);
                }
                else if (action == 6)
                {
                    printf("\nIngrese el elemento que desee buscar en la lista: ");
                    scanf("%d", &new_element);
                    boolean = buscar(list, new_element);
                    if (boolean == 0)
                        printf("\nEl elemento %d NO se encuentra en la lista!\n", new_element);
                    else
                        printf("\nElemento %d se encuentra en la lista!\n", new_element);
                }
                else if (action == 7)
                {
                    int pop_element;
                    boolean = sacarPrincipio(list, &pop_element);
                    if (boolean == 0)
                        printf("\nEl elemento del inicio no se ha podida eliminar, la lista esta vacia!\n");
                    else
                        printf("\nEl elemento %d ha sido removido del inicio de la lista!\n", pop_element);
                }
                else if (action == 8)
                {
                    int pop_element;
                    boolean = sacarFinal(list, &pop_element);
                    if (boolean == 0)
                        printf("\nEl elemento del final no se ha podida eliminar, la lista esta vacia!\n");
                    else
                        printf("\nEl elemento %d ha sido removido del final de la lista!\n", pop_element);
                }
                else if (action == 9)
                {
                    printf("\nIngrese el elemento que desee remover de la lista: ");
                    scanf("%d", &new_element);
                    boolean = sacarPrimeraOcurrencia(list, new_element);
                    if (boolean == 0)
                        printf("\nEl elemento no se ha podida eliminar, la lista esta vacia!\n");
                    else
                        printf("\nEl elemento %d ha sido removido de la lista!\n", new_element);
                }
                else if (action == 10)
                {
                    printf("\nLa lista (De Inicio a Final) es:\n\n");
                    listarInicioAFinal(list);
                }
                else if (action == 11)
                {
                    printf("\nLa lista (De Final a Inicio) es:\n\n");
                    listarFinalAInicio(list);
                }
                else if (action == 12)
                {
                    element_num = cantidadElementos(list);
                    printf("\nLa cantidad de elementos es de: %d elementos en Lista!\n", element_num);
                }
            
            boolean = -1;

            }
            action = -1;            
        }
    }

    printf("\nCerrando aplicacion...\n\n");
}
