#include "afiche.h"
#include "cliente.h"
#include "utn.h"
#include <string.h>
#include <stdio_ext.h>
#include <stdlib.h>

static int getLugarLibre(Cliente* array, int len);
static int getNextId();
static int getIndice(Cliente* array,int len);

/** \brief obtiene un indice que este vacio.
 *
 * \param Con un if validamos que este vacio.
 * \return la posicion del array.
 *
 */

static int getLugarLibre(Cliente* array, int len)
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

/** \brief Inicializamos a los clientes.
 *
 * \param Utilizamos la funcion  getIndice para ingresar el indice.
 * \param Con un if validamos y le agregamos un 1 a cada posicion del array indicando que esta vacia.
 * \return retorno.
 *
 */

int cliente_Init(Cliente* array, int len)
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

/** \brief Damos de alta.
 *
 * \param Utilizamos la funcion  getLugarlibre para posicionarnos en un indice vacio.
 * \param Con un if validamos que los valores sean correctos.
 * \return 0 si esta bien.
 *
 */

int cliente_Alta(Cliente* array, int len, int* id)
{
    int retorno = -1;
    int indice;
    char name[NAME];
    char lastName[LASTNAME];
    char cuit[CUIT];

    indice = getLugarLibre(array,len);

    if(array != NULL && len > 0 &&
       indice >= 0 && indice < len)
       {
         if(!utn_getNombre(name,NAME,"Ingrese Nombre: ","Nombre invalido.",2) &&
            !utn_getNombre(lastName,LASTNAME,"Ingrese Apellido: ","Apellido invalido.",2) &&
            !utn_getCuil(cuit,CUIT,"Ingrese CUIT: ","CUIT Invalido.",2))
            {
                strncpy(array[indice].name,name,NAME);
                strncpy(array[indice].lastName,lastName,LASTNAME);
                strncpy(array[indice].cuit,cuit,CUIT);
                array[indice].isEmpty = 0;
                array[indice].clienteId = getNextId();
                *id = array[indice].clienteId;
                retorno = 0;
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
    static int ultimoId=-1;
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

int cliente_Baja(Cliente* array, int len, void* arrayDos, int lenDos)
{
    int retorno = 1;
    int indice;
    char respuesta[3];
    int idCliente;
    indice = getIndice(array,len);
    Afiche* afiche = arrayDos;
    Afiche* aficheElegido;

     if(array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty==0)
        {
            printf("Confirma la baja del cliente?\n");
            fgets(respuesta,3,stdin);

            if(!strcmp(respuesta,"si"))
            {
                array[indice].isEmpty = 1;
                idCliente = array[indice].clienteId;
                aficheElegido = afiche_getByID(afiche,lenDos,idCliente);
                aficheElegido->isEmpty = 1;
                retorno = 0;
            }
            else if(!strcmp(respuesta,"no"))
            {
                printf("Se cancela la baja\n");
            }
            else
            {
                printf("Respuesta incorrecta\n");
            }
        }
        else
        {
            printf("No hay carga en el ID indicado");
            retorno = 1;
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

int cliente_Modificar(Cliente* array, int len)
{
    int retorno = -1;
    int indice;
    char cuit[CUIT];
    char name[NAME];
    char lastName[LASTNAME];

    indice = getIndice(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len &&
        (!array[indice].isEmpty))
    {
          if(!utn_getNombre(name,NAME,"Ingrese Nombre: ","Nombre invalido.",2) &&
            !utn_getNombre(lastName,LASTNAME,"ingrese Apellido: ","Apellido invalido.",2) &&
            !utn_getCuil(cuit,CUIT,"Ingrese CUIT: ","CUIT Invalido.",2))
            {
                strncpy(array[indice].name,name,NAME);
                strncpy(array[indice].lastName,lastName,LASTNAME);
                strncpy(array[indice].cuit,cuit,CUIT);
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

static int getIndice(Cliente* array,int len)
{
   int retorno=-1;
   int i;
   int id;

   if(utn_getSoloInt(&id,ID,"Ingrese el ID: ","ID invalido.",2)==0)
   {
       for(i=0;i<len;i++)
       {
           if(array[i].clienteId==id)
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

int cliente_altaForzada(Cliente* array,int len,char* name,char* lastName, char* cuit)
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
            strcpy(array[i].lastName,lastName);
            strcpy(array[i].cuit,cuit);
            array[i].clienteId = getNextId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Devuelve el array cliente en una posicion especifica.
 *
 * \param Con un if validamos el array.
 * \param Usamos un for para pasar por los elementos de array.
 * \param y un if para que entre cuando el id que ingresemos sea igual al id del array.
 * \return el array.
 *
 */


Cliente* cliente_getByID(Cliente* array,int len,int id)
{
    Cliente* retorno = NULL;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
           if(!array[i].isEmpty && array[i].clienteId == id)
            {
                retorno = array+i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief MUestra los clientes con sus afiches.
 *
 * \param Con un if validamos el array.
 * \param Usamos un for para recorrer el array.
 * \param y un if validad que es cargado el array y mostramos los clientes con printf.
 * \return 0 si esta bien.
 *
 */

int cliente_mostrar(Cliente* array,void* arrayDos,int lenUno,int lenDos)
{
    int retorno = -1;
    int i;
    int idCliente;
    Afiche* afiche = arrayDos;
    Afiche* aficheElegido;
    if(lenUno > 0 && array!= NULL)
    {
        retorno = 0;
        for(i=0;i<lenUno;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\nNombre: %s - Apellido: %s ",array[i].name, array[i].lastName);
                printf("- Cuit: %s - ID: %d\n",array[i].cuit,array[i].clienteId);
                idCliente = array[i].clienteId;
                aficheElegido = afiche_getByID(afiche,lenDos,idCliente);

                if(aficheElegido!=NULL)
                {
                     printf("cantidad: %d\n",aficheElegido->cantidad);
                }
                else
                {
                    printf("cantidad: 0\n");
                }
            }
        }
    }
    return retorno;
}
