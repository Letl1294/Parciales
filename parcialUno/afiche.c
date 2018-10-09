#include "cliente.h"
#include "afiche.h"
#include "utn.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

static int getLugarLibre(Afiche* array, int len);
static int getNextId();
static int getIndice(Afiche* array,int len);

/** \brief obtiene un indice que este vacio.
 *
 * \param Con un if validamos que este vacio.
 * \return la posicion del array.
 *
 */

static int getLugarLibre(Afiche* array, int len)
{
    int retorno=-1;
    int i;
    if(array!= NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Inicializamos a los afiches.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos y le agregamos un 1 a cada posicion del array indicando que esta vacia.
 * \return retorno.
 *
 */

int afiche_Init(Afiche* array, int len)
{
    int retorno=-1;
    int i;
    if(array!= NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

static int afiche_ValidZona(char zona[])
{
    int retorno = -1;
    char auxZona[ZONA];
    if(!utn_getAlfaNum(auxZona,ZONA,"ingrese Zona: ","Zona invalida.",2))
    {
        if(!strcasecmp(auxZona,"CABA") || !strcasecmp(auxZona,"ZONA SUR") || !strcasecmp(auxZona,"ZONA OESTE"))
        {
            strncpy(zona,auxZona,ZONA);
            retorno = 0;
        }
        else
        {
            printf("zona invalida.\n");
        }
    }
return retorno;
}

/** \brief Damos de alta.
 *
 * \param Utilizamos la funcion getLugarlibre para posicionarnos en un indice vacio.
 * \param Con un if validamos que los valores sean correctos.
 * \return 0 si esta bien.
 *
 */

int afiche_vender(Afiche* array, int len, int id)
{
    int retorno = -1;
    int indice;
    char name[NAME];
    char zona[ZONA];
    int cantidad;

    indice = getLugarLibre(array,len);

    if(array != NULL && len > 0 &&
       indice >= 0 && indice < len)
       {
         if(!utn_getAlfaNum(name,NAME,"Ingrese Nombre del archivo: ","Nombre invalido.",2) &&
            !afiche_ValidZona(zona) &&
            !utn_getSoloInt(&cantidad,CANTIDAD_DE_VENTAS,"Ingrese cantidad de afiches: ","Cantidad Invalida.",2))
            {
                strncpy(array[indice].name,name,NAME);
                strncpy(array[indice].zona,zona,ZONA);
                array[indice].cantidad = cantidad;
                array[indice].isEmpty = 0;
                array[indice].clienteId = id;
                array[indice].aficheId = getNextId();
                array[indice].cobrar=1;
                retorno = 0;
                printf("\nID: %d",array[indice].aficheId);
            }
       }
    return retorno;
}

/** \brief Genera el ID.
 *
 * \param Utilizamos un static int para guardar el ID.
 * \return el ID.
 *
 */

static int getNextId()
{
    static int ultimoId=10;
    ultimoId++;
    return ultimoId;
}

/** \brief Damos de baja.
 *
 * \param Utilizamos la funcion getIndice para ingresar el indice.
 * \param Con un if validamos que este cargado y los damos de baja. Sino nos muestra un mensaje de error.
 * \return retorno.
 *
 */

int afiche_Cobrar(Afiche* array,void* arrayDos, int len,int lenDos)
{
    int retorno = -1;
    int indice;
    int i;
    int idCliente;
    char respuesta[3];
    Cliente* clienteElegido;
    Cliente* cliente = arrayDos;

    for(i=0;i<len;i++)
    {
        if(!array[i].isEmpty)
        {
            printf("\nNombre: %s - Cantidad: %d - ",array[i].name,array[i].cantidad);
            printf("Zona: %s - ID: %d \n",array[i].zona,array[i].aficheId);
        }
    }
    indice=getIndice(array,len);

     if(array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty==0)
        {
            idCliente = array[indice].clienteId;
            clienteElegido = cliente_getByID(cliente,lenDos,idCliente);
            printf("\nNombre del cliente: %s - Apellido: %s ",clienteElegido->name,clienteElegido->lastName);
            printf("-Cuit: %s - ID: %d",clienteElegido->cuit,clienteElegido->clienteId);
            printf("\nConfirma el cobro del cliente?\n");
            fgets(respuesta,3,stdin);

            if(!strcmp(respuesta,"si"))
            {
                array[indice].isEmpty = 0;
                array[indice].cobrar = 0;

                retorno = 0;
            }
            else if(!strcmp(respuesta,"no"))
            {
                printf("Se cancela el cobro\n");
            }
            else
            {
                printf("Respuesta incorrecta\n");
            }
        }
        else
        {
            printf("No hay carga en el ID indicado");
        }
return retorno;
}

/** \brief toma un indice.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos que esten bien las modificaciones.
 * \return retorno.
 *
 */

int afiche_Modificar(Afiche* array, int len)
{
    int retorno = -1;
    int indice;
    char auxZona[ZONA];
    int cantidad;
    int i;

    for(i=0;i<len;i++)
    {
        if(!array[i].isEmpty)
        {
            printf("\nNombre: %s - Cantidad: %d ",array[i].name,array[i].cantidad);
            printf("Zona: %s - ID: %d \n\n",array[i].zona,array[i].aficheId);
        }
    }
    indice = getIndice(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len &&
        (!array[indice].isEmpty))
    {
        if( !afiche_ValidZona(auxZona) &&
            !utn_getSoloInt(&cantidad,CANTIDAD_DE_VENTAS,"Ingrese cantidad de afiches: ","Cantidad Invalida.",2))
            {
                strncpy(array[indice].zona,auxZona,ZONA);
                array[indice].cantidad = cantidad;
                retorno = 0;
            }
    }
    else if(array[indice].isEmpty)
    {
        printf("No hay carga en ese indice");
    }
    return retorno;
}

/** \brief Obtiene el indice.
 *
 * \param Con un if utilizamos validamos el ID con el for pasamos por los elementos del array.
 * \param Y con el if validamos que este cargado array en esa posicion.
 * \return la posicion del indice.
 *
 */

static int getIndice(Afiche* array,int len)
{
   int retorno=-1;
   int i;
   int id;

   if(utn_getSoloInt(&id,ID,"Ingrese el ID: ","ID invalido.",2)==0)
   {
       for(i=0;i<len;i++)
       {
           if(array[i].aficheId==id)
            {
                retorno=i;
                break;
            }
       }
   }
   return retorno;
}

/** \brief Genera altas forzadas.
 *
 * \param Con un if validamos el array.
 * \param Usamos la funciona getlugarlibre para ir cargando en los indices libres del array.
 * \return 0 si esta bien.
 *
 */

int afiche_altaForzada(Afiche* array,int len,char* name,char* zona, int cantidad,int id)
{
    int retorno = -1;
    int i;

    if(len > 0 && array != NULL)
    {
        i = getLugarLibre(array,len);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].name,name);
            strcpy(array[i].zona,zona);
            array[i].cantidad=cantidad;
            array[i].aficheId = getNextId();
            array[i].clienteId=id;
            array[i].isEmpty = 0;
            array[i].cobrar = 1;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Devuelve el array afiche en una posicion especifica.
 *
 * \param Con un if validamos el array.
 * \param Usamos un for para pasar por los elementos de array.
 * \param y un if para que entre cuando el id que ingresemos sea igual al id del array.
 * \return el array.
 *
 */

Afiche* afiche_getByID(Afiche* array,int len,int id)
{
    Afiche* retorno = NULL;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
           if(!array[i].isEmpty && array[i].clienteId == id)
            {
                retorno = &array[i];
                break;
            }
        }
    }
    return retorno;
}
