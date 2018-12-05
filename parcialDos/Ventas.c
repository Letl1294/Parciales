#include "Ventas.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/** \brief Valida un float.
 *
 * \param Con un if validamos que haya un punto y que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidFloat(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    int contadorPuntos=0;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                if((pBuffer[i]!='.') || (pBuffer[0]=='.') || (pBuffer[strlen(pBuffer)-1]=='.'))
                {
                    retorno = 0;
                    break;
                }
                if(pBuffer[i]=='.')
                {
                    contadorPuntos++;
                }
                if(contadorPuntos>1)
                {
                    retorno = 0;
                }
            }
         }
    }
    return retorno;
}

/** \brief Valida el cuil.
 *
 * \param Con un if validamos los guiones y que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidCuil(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    int contadorGuion=0;
    int contadorDigitos=strlen(pBuffer);

    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                if((pBuffer[i]!='-') || (pBuffer[0]=='-') || (pBuffer[strlen(pBuffer)-1]=='-'))
                {
                    retorno=0;
                    break;
                }
                if(pBuffer[i]=='-')
                {
                    contadorGuion++;
                }
            }
         }
            if(contadorGuion!=2)
            {
                retorno=0;
            }
            if(contadorGuion==2)
            {
                retorno=0;
                if(pBuffer[2]=='-' && pBuffer[11]=='-')
                {
                    retorno=1;
                }
                if(contadorDigitos>13)
                {
                    retorno=0;
                }
            }
    }
    return retorno;
}

/** \brief Valida el nombre.
 *
 * \param Con un if validamos que solo haya letras. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidInt(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Reservo memoria para un nuevo empleado
 *
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion malloc que nos dara una posicion de memoria para empleado.
 * \return this
 *
 */

Ventas* Ventas_new()
{
    Ventas* this;
    this = malloc(sizeof(Ventas));
    return this;
}

/** \brief libera memoria
 *
 * \param utilizo un if para validar que this no este vacio.
 * \param si no esta vacio se libera la memoria.
 * \return 0
 *
 */

int Ventas_delete(Ventas* this)
{
    int retorno = 1;
    if(this != NULL)
    {
         free(this);
         retorno = 0;
    }
    return retorno;
}

/** \brief Cargo una venta con sus parametros
 *
 * \param Les pasamos a la funcion los string con los datos.
 * \param Declaro un puntero de empleado con la palabra reservada this.
 * \param a this le asigno la funcion ventas_new que nos dara una posicion de memoria.
 * \param con un if valido que las funciones esten bien. En caso de no estarlo se libera la posicion de memoria.
 * \return this(la venta con parametros). O NULL si esta mal.
 *
 */

Ventas* ventas_newConParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* precioStr,char* cuitStr)//le ponemos Str porque son todos string.
{
    Ventas* this;
    this = Ventas_new();

    if((isValidCuil(cuitStr,LEN)) &&
        isValidInt(idStr,LEN)&&
        isValidInt(cantidadStr,LEN)&&
        isValidFloat(precioStr,LEN))
    {
        Ventas_setId(this,atoi(idStr));
        Ventas_setFecha(this,fechaStr);
        Ventas_setCodigo(this,codigoStr);
        Ventas_setCantidad(this,atoi(cantidadStr));
        Ventas_setPrecio(this,atof(precioStr));
        Ventas_setCuit(this,cuitStr);
        return this;
    }
    Ventas_delete(this);
    return NULL;
}

/** \brief Genera un ID
 *
 * \param Declaro un variable estatica del tipo int llamado proximoId.
 * \param Con if y un else if valido que no sea NULL y el valor de id.
 * \return 0 si esta bien.
 *
 */

int Ventas_setId(Ventas* this,int id)
{
    int retorno=-1;
    static int proximoId=0;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id = proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    else if(id==0)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

/** \brief Nos entrega el ID
 *
 * \param valida que el puntero de ventas que le pasamos no sea NULL.
 * \param y la direccion de memoria de id le asigna el valor de el id de la venta.
 * \return el id.
 *
 */

int Ventas_getId(Ventas* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

/** \brief Le setea la fecha del empleado
 *
 * \param le pasamos un puntero de venta y una fecha.
 * \param con un if validamos que no sea NULL ni el puntero a venta ni el dato.
 * \param le pasamos con la funcion strcpy la fecha al puntero de ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_setFecha(Ventas* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos la fecha
 *
 * \param con un if validamos que venta y fecha no sean NULL
 * \param con la funcion strcpy le pasamos la fecha de empleado a el string fecha.
 * \return 0 si esta bien.
 *
 */

int Ventas_getFecha(Ventas* this,char* fecha)
{
    int retorno=-1;
    if(this!=NULL && fecha!=NULL)
    {
        strcpy(fecha,this->fecha);
        retorno = 0;
    }
    return retorno;
}

/** \brief Le setea la cantidad.
 *
 * \param le pasamos un puntero de cantidad y un int.
 * \param con un if validamos que no sea NULL el puntero a ventas.
 * \param le pasamos las horas al puntero ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_setCantidad(Ventas* this,int cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

/** \brief obtenemos la cantidad.
 *
 * \param le pasamos un puntero de ventas y un int.
 * \param con un if validamos que no sea NULL ventas.
 * \param le pasamos al puntero de int del ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_getCantidad(Ventas* this,int* cantidad)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *cantidad=this->cantidad;
        retorno=0;
    }
    return retorno;
}

/** \brief Seteamos el precio de ventas
 *
 * \param le pasamos un puntero de ventas y un float.
 * \param con un if validamos que no sea NULL ventas.
 * \param le pasamos al puntero de ventas el precio.
 * \return 0 si esta bien.
 *
 */

int Ventas_setPrecio(Ventas* this,float precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el precio del ventas
 *
 * \param le pasamos un puntero de ventas y un float.
 * \param con un if validamos que no sea NULL ventas.
 * \param le pasamos al float el precio de ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_getPrecio(Ventas* this,float* precio)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *precio = this->precio;
        retorno=0;
    }
    return retorno;
}

/** \brief seteamos el codigo
 *
 * \param le pasamos un puntero de ventas y un char.
 * \param con un if validamos que no sea NULL venta.
 * \param le pasamos el codigo a ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_setCodigo(Ventas* this,char* codigoVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->codigo,codigoVenta);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el codigo de ventas
 *
 * \param le pasamos un puntero de ventas y un char.
 * \param con un if validamos que no sea NULL ventas.
 * \param le pasamos al char con un strcpy el codigo de ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_getCodigo(Ventas* this,char* codigoVenta)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(codigoVenta,this->codigo);
        retorno=0;
    }
    return retorno;
}

/** \brief seteamos el cuit
 *
 * \param le pasamos un puntero de ventas y un char.
 * \param con un if validamos que no sea NULL venta.
 * \param le pasamos el cuit a ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_setCuit(Ventas* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(this->cuit,cuit);
        retorno=0;
    }
    return retorno;
}

/** \brief Obtenemos el cuit de ventas
 *
 * \param le pasamos un puntero de ventas y un char.
 * \param con un if validamos que no sea NULL ventas.
 * \param le pasamos al char con un strcpy el cuit de ventas.
 * \return 0 si esta bien.
 *
 */

int Ventas_getCuit(Ventas* this,char* cuit)
{
    int retorno=-1;
    if(this!=NULL)
    {
        strcpy(cuit,this->cuit);
        retorno=0;
    }
    return retorno;
}

/** \brief Mostramos las ventas
 *
 * \param le pasamos un puntero de void.
 * \param con un if validamos que no sea NULL ventas.
 * \param hacemos un get de todos los datos y los mostramos con un printf.
 * \return 0 si esta bien.
 *
 */

int Ventas_mostrar(void* pVentas)
{
    int retorno = -1;
    int auxId;
    char auxFecha[LEN];
    char auxCodigo[LEN];
    int auxCantidad;
    float auxPrecio;
    char auxCuit[LEN];
    if(pVentas != NULL)
    {
        Ventas_getId(pVentas,&auxId);
        if(auxId != -1)
        {
            Ventas_getId(pVentas,&auxId);
            Ventas_getFecha(pVentas,auxFecha);
            Ventas_getCodigo(pVentas,auxCodigo);
            Ventas_getCantidad(pVentas,&auxCantidad);
            Ventas_getPrecio(pVentas,&auxPrecio);
            Ventas_getCuit(pVentas,auxCuit);
            printf("\nID: %d",auxId);
            printf(" - Fecha: %s",auxFecha);
            printf(" - Codigo: %s",auxCodigo);
            printf("\nCantidad: %d",auxCantidad);
            printf(" - Precio: %.2f",auxPrecio);
            printf(" - CUIT: %s\n",auxCuit);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief devolmemos la cantidad de ventas segun criterio
 *
 * \param le pasamos un puntero de void.
 * \param con un if validamos que no sea NULL ventas.
 * \param y le asignamos a cantidad la cantidad del elemento.
 * \return 0 si esta bien.
 *
 */

int criterioCantidadTotal(void* pVenta,char* criterio)
{
    int cantidad = 0;
    Ventas* pVentas = pVenta;

    if(pVentas != NULL && !Ventas_getCantidad(pVentas,&cantidad))
    {
        if(pVentas->cantidad>atoi(criterio))
        {
            cantidad = pVentas->cantidad;
        }

    }
return cantidad;
}

/** \brief devolmemos la cantidad de ventas segun criterio
 *
 * \param le pasamos un puntero de void.
 * \param con un if validamos que no sea NULL ventas.
 * \param hace una multiplicacion de precio y unidades del elemento.
 * \param con un if validamos que sea total sea mayor a 20000. Si es asi devolvemos la cantidad.
 * \return 0 si esta bien.
 *
 */

int criterioVentasMayores(void* pVenta,char* criterio)
{
    int cantidad = 0;
    Ventas* pVentas = pVenta;
    int precio;
    int total;
    int unidades;

    if(pVentas != NULL)
    {
        unidades = pVentas->cantidad;
        precio = pVentas->precio;
        total = unidades*precio;
        if(total>atoi(criterio))
        {
            cantidad = 1;
        }
    }
    return cantidad;
}

/** \brief devolmemos la cantidad de ventas segun criterio
 *
 * \param le pasamos un puntero de void.
 * \param con un if validamos que no sea NULL ventas.
 * \param hacemos un if y un strcmp valido que sea igual a lcd_tv. Si es el caso devuelde la cantidad de ese elemento.
 * \return 0 si esta bien.
 *
 */

int criterioTv(void* pVenta,char* criterio)
{
    int cantidad = 0;
    Ventas* pVentas = pVenta;

    if(pVentas != NULL && !strcmp(pVentas->codigo,criterio))
    {
        cantidad = pVentas->cantidad;
    }
    return cantidad;
}
