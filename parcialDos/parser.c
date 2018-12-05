#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Ventas.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo no sea NULL y con while y la funcion feof que salga cuando se llegue al final.
 * \param el fgets se utiliza para tomar todos los caracteres, los contamos con el strlen.
 * \param con un if valida la cantidad. Con un strncpy cargos los datos en los buffer.
 * \param llamamos a la funcion para cargar ventas y le pasamos los datos que sacamos del texto y...
 * \param Se la pVentas con un if se valida si es distinta a NULL y se agrega a la linkedlist.
 * \return 0
 *
 */

int parser_ventasFromText(char* fileName, LinkedList* listaVentas)
{
    char bufferId[LEN];
    char bufferFecha[LEN];
    char bufferCodigo[LEN];
    char bufferCantidad[LEN];
    char bufferPrecio[LEN];
    char bufferCuit[LEN];
    char bufferText[LEN];
    int retorno = -1;
    int len;
    Ventas* pVentas;
    FILE* pFile = fopen(fileName,"r");
    if(pFile!=NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            fgets(bufferText,sizeof(bufferText),pFile);
            len = strlen(bufferText);
            if(len > 15) //Minimo 15 caracteres tendra el fgets para que sea correcto.
            {
                strncpy(bufferId,strtok(bufferText,","),LEN); //delimitador la ",". Reemplaza la "," por null \0.
                strncpy(bufferFecha,strtok(NULL,","),LEN); //en el segundo caso arranca desde el null hasta la siguiente ",".
                strncpy(bufferCodigo,strtok(NULL,","),LEN);
                strncpy(bufferCantidad,strtok(NULL,","),LEN);
                strncpy(bufferPrecio,strtok(NULL,","),LEN);
                strncpy(bufferCuit,strtok(NULL,"\n"),LEN);
                pVentas = ventas_newConParametros(bufferId,bufferFecha,bufferCodigo,bufferCantidad,bufferPrecio,
                bufferCuit);
                if(pVentas!=NULL && atoi(bufferId)>=0)
                {
                    ll_add(listaVentas,pVentas);
                }
            }
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param le pasamos a la funcion el path del archivo. Y un puntero de LinkedList.
 * \param con un if validamos que el archivo y la linkedlist no sean NULL.
 * \param usamos la funcion ll_count con su criterios y pasamos los resultados que retornan a un auxiliar.
 * \param con fprintf imprimimos en el texto a todos los datos.
 * \return 0
 *
 */

int parser_ventasToText(char* fileName, void* listaVentas)
{
    int retorno = -1;
    int auxTotal;
    int auxTv;
    int auxVentasMayores10;
    int auxVentasMayores20;

    FILE* pFile = fopen(fileName,"w");
    if(pFile != NULL && listaVentas != NULL)
    {
        auxTotal = ll_count(listaVentas,criterioCantidadTotal,"0");
        auxVentasMayores10 = ll_count(listaVentas,criterioVentasMayores,"10000");
        auxVentasMayores20 = ll_count(listaVentas,criterioVentasMayores,"20000");
        auxTv = ll_count(listaVentas,criterioTv,"LCD_TV");
        fprintf(pFile,"\nCantidad de unidades vendidas totales: %d",auxTotal);
        fprintf(pFile,"\nCantidad de ventas por un monto mayor a 10000: %d",auxVentasMayores10);
        fprintf(pFile,"\nCantidad de ventas por un monto mayor a 20000: %d",auxVentasMayores20);
        fprintf(pFile,"\nCantidad de TV LCD Vendidas: %d",auxTv);
        retorno = 0;
    }
    return retorno;
}
