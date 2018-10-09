#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "afiche.h"
#include "informes.h"

/** \brief Calculo del promedio de cantidad de afiches y clientes
 *
 * \param Con if validamos el array.
 * \param Usamos dos for para recorrer los array.
 * \param utilizamos un if para validar que este cargado el array afiche, y le sumamos la cantidad al acumulador de afiches.
 * \param utilizamos otro if para validar que este cargado el array cliente y aumentamos contador de clientes.
 * \param con un float promedio realizamos el calculo: cantidad de afiches / cantidad de clientes.
 * \return 0 si esta bien.
 *
 */

int informes_promedioPorCiente(Afiche arrayUno[], int lenUno, Cliente arrayDos[], int lenDos)
{
    int retorno = -1;
    int totalAfiches = 0;
    int contadorClientes = 0;
    float promedio;
    int i,j;

    if(arrayUno != NULL && lenUno > 0 && arrayDos != NULL && lenDos >0)
    {
        for(i=0;i<lenUno;i++)
        {
            if(!arrayUno[i].isEmpty)
            {
                totalAfiches = totalAfiches + arrayUno[i].cantidad;
            }
        }
        for(j=0;j<lenDos;j++)
        {
            if(!arrayDos[j].isEmpty)
            {
                contadorClientes++;
            }
        }
        promedio = totalAfiches / contadorClientes;
        printf("Cantidad de Afiches vendidos por Cliente: %.2f",promedio);
        retorno = 0;
    }
    return retorno;
}

/** \brief mostrar todas las ventas por zona.
 *
 * \param Con un if validamos el array.
 * \param Usamos un for para recorrer el array.
 * \param utilizamos un if para validar que este cargado y la zona. Mostamos las ventas y aumentamos el contador de ventas
 * \param para luego mostrarlo.
 * \return 0 si esta bien.
 *
 */

int informes_VentasZona(Afiche array[], int len)
{
    int retorno = -1;
    int contadorVentas = 0;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
            {
                if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"CABA"))
                {
                    printf("\n\nID Cliente: %d",array[i].clienteId);
                    printf("\nNombre: %s",array[i].name);
                    printf("\nCantidad: %d",array[i].cantidad);
                    printf("\nZona: %s",array[i].zona);
                    printf("\n\nEstado: %d",array[i].cobrar);
                    contadorVentas++;
                }
            }
            printf("\n\nVentas realizadas en CABA: %d",contadorVentas);
            contadorVentas = 0;
            for(i=0;i<len;i++)
            {
                if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"ZONA SUR"))
                {
                    printf("\n\nID Cliente: %d",array[i].clienteId);
                    printf("\nNombre: %s",array[i].name);
                    printf("\nCantidad: %d",array[i].cantidad);
                    printf("\nZona: %s",array[i].zona);
                    printf("\nEstado: %d",array[i].cobrar);
                    contadorVentas++;
                }
            }
            printf("\n\nVentas realizadas en ZONA SUR: %d",contadorVentas);
            contadorVentas = 0;
            for(i=0;i<len;i++)
            {
                if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"ZONA OESTE"))
                {
                    printf("\n\nID Cliente: %d",array[i].clienteId);
                    printf("\nNombre: %s",array[i].name);
                    printf("\nCantidad: %d",array[i].cantidad);
                    printf("\nZona: %s",array[i].zona);
                    printf("\nEstado: %d",array[i].cobrar);
                    contadorVentas++;
                }
            }
            printf("\n\nVentas realizadas en ZONA OESTE: %d",contadorVentas);
            retorno = 0;
        }
    return retorno;
}

/** \brief Mostrar clientes con menos Cantidad no cobradas.
 *
 * \param Con un if validamos el array.
 * \param Usamos 2 for para recorrer el array de clientes y afiche.
 * \param utilizamos un if para validar que este cargado, que el estado sea acobrar y menor a cantidad.
 * \param Y le cargamos 1 a flag. si el flag es 1 significa que entra a la validacion y mostramos al cliente.
 * \return 0 si esta bien.
 *
 */

int informes_clienteMasCantidadNoCobradas(Cliente arrayUno[],Afiche arrayDos[],
                                int lenUno,int lenDos)
{
    int retorno = -1;
    int i;
    int j;
    int id;
    int flag = 0;
    int mayorCantidad;
    Afiche* aficheElegido;

    if(arrayUno != NULL && arrayDos != NULL && lenUno > 0 && lenDos > 0)
    {
        for(i=0;i<lenUno;i++)
        {
            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<lenDos;j++)
                {
                    if(arrayUno[i].clienteId == arrayDos[j].clienteId)
                    {
                        aficheElegido = afiche_getByID(arrayDos,lenDos,arrayDos[j].clienteId);

                        if((aficheElegido != NULL && aficheElegido->cantidad > mayorCantidad) && ((aficheElegido->cobrar)
                            || flag == 0))
                        {
                            mayorCantidad = aficheElegido->cantidad;
                            id = aficheElegido->clienteId;
                            flag = 1;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    if(flag==1)
    {
        printf("\n\nCliente con mayor cantidad no cobradas: ");
        printf("\n\nID Cliente: %d",arrayUno[id].clienteId);
        printf("\nNombre: %s",arrayUno[id].name);
        printf("\nApellido: %s",arrayUno[id].lastName);
        printf("\nCuit: %s",arrayUno[id].cuit);
    }
    return retorno;
}

/** \brief Mostrar cliente con mas afiches.
 *
 * \param Con un if validamos que los array esten cargados.
 * \param Usamos 2 for para recorrer el array de cliente y afiche.
 * \param utilizamos un if para validar que esten cargado, y que sea mayor a cantidad. Y le cargamos 1 a flag.
 * \param si el flag es 1 significa que entre a la validacion y mostramos al cliente.
 * \return 0 si esta bien.
 *
 */

int informes_clienteMasAfiches(Cliente arrayUno[], Afiche arrayDos[], int lenUno, int lenDos)
{
    int retorno = -1;
    int i;
    int j;
    int id;
    int flag = 0;
    int mayorCantidad;
    Afiche* aficheElegido;

    if(arrayUno != NULL && arrayDos != NULL && lenUno > 0 && lenDos > 0)
    {
        for(i=0;i<lenUno;i++)
        {
            if(!arrayUno[i].isEmpty)
            {
                for(j=0;j<lenDos;j++)
                {
                    if(arrayUno[i].clienteId == arrayDos[j].clienteId)
                    {
                        aficheElegido = afiche_getByID(arrayDos,lenDos,arrayDos[j].clienteId);

                        if((aficheElegido != NULL && aficheElegido->cantidad > mayorCantidad)
                            || flag == 0)
                        {
                            mayorCantidad = aficheElegido->cantidad;
                            id = aficheElegido->clienteId;
                            flag = 1;
                            retorno = 0;
                        }
                    }
                }
            }
        }
    }
    if(flag==1)
    {
        printf("\n\nCliente con mayor cantidad de afiches: ");
        printf("\n\nID Cliente: %d",arrayUno[id].clienteId);
        printf("\nNombre: %s",arrayUno[id].name);
        printf("\nApellido: %s",arrayUno[id].lastName);
        printf("\nCuit: %s",arrayUno[id].cuit);
    }
    return retorno;
}

/** \brief Mostrar cantidad por zona.
 *
 * \param Con un if validamos el array.
 * \param Usamos 2 for para recorrer el array de cliente y afiche.
 * \param utilizamos un if para validar que este cargado, y con un strcasecmp comprobamos la zona. y la sumamos en cantidadAfiches.
 * \param Con un printf mostramos la cantidad por zona.
 * \return 0 si esta bien.
 *
 */

int informes_cantidadPorZona(Afiche array[], int len)
{
    int retorno = -1;
    int cantidadAfiches = 0;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"CABA"))
            {
                cantidadAfiches = cantidadAfiches + array[i].cantidad;
            }
        }
        printf("\n\nCantidad de afiches vendidos en CABA: %d",cantidadAfiches);
        cantidadAfiches = 0;
        for(i=0;i<len;i++)
        {
            if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"ZONA SUR"))
            {
                cantidadAfiches = cantidadAfiches + array[i].cantidad;
            }
        }
        printf("\n\nCantidad de afiches vendidos en ZONA SUR: %d",cantidadAfiches);
        cantidadAfiches = 0;
        for(i=0;i<len;i++)
        {
            if((!array[i].isEmpty) && !strcasecmp(array[i].zona,"ZONA OESTE"))
            {
                cantidadAfiches = cantidadAfiches + array[i].cantidad;
            }
        }
        printf("\n\nCantidad de afiches vendidos en ZONA OESTE: %d\n",cantidadAfiches);
        retorno = 0;
    }
    return retorno;
}
