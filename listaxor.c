#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "listaxor.h"

// Funcion para hacer XOR entre direcciones de punteros (Usando la libreria <stdint.h>)

node *XOR(node *x, node *y)
{
    return (node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}