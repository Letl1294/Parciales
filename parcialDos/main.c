#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Ventas.h"
#include "LinkedList.h"
#include "parser.h"

int main()
{
    LinkedList* listaVentas = ll_newLinkedList();
    if(parser_ventasFromText("data.csv",listaVentas)== 0)
    {
        ll_map(listaVentas,Ventas_mostrar);
        printf("\nSize de la lista: %d",ll_len(listaVentas));
        parser_ventasToText("informes.txt",listaVentas);
    }
    return 0;
}
