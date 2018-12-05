#ifndef ventas_H_INCLUDED
#define ventas_H_INCLUDED
#include "LinkedList.h"
#define LEN 1024

typedef struct
{
    int id;
    char fecha[LEN];
    char codigo[LEN];
    int cantidad;
    float precio;
    char cuit[LEN];
}Ventas;

Ventas* Ventas_new();
int Ventas_delete(Ventas* this);

Ventas* ventas_newConParametros(char* idStr,char* fechaStr,char* codigoStr,char* cantidadStr,char* precioStr,char* cuitStr);

int Ventas_setId(Ventas* this,int id);
int Ventas_getId(Ventas* this,int* id);

int Ventas_setFecha(Ventas* this,char* fecha);
int Ventas_getFecha(Ventas* this,char* fecha);

int Ventas_setCodigo(Ventas* this,char* codigoVenta);
int Ventas_getCodigo(Ventas* this,char* codigoVenta);

int Ventas_setCantidad(Ventas* this,int cantidad);
int Ventas_getCantidad(Ventas* this,int* cantidad);

int Ventas_setCantidadTotal(Ventas* this,int cantidadTotal);
int Ventas_getCantidadTotal(Ventas* this,int* cantidadTotal);

int Ventas_setPrecio(Ventas* this,float precio);
int Ventas_getPrecio(Ventas* this,float* precio);

int Ventas_setCuit(Ventas* this,char* cuit);
int Ventas_getCuit(Ventas* this,char* cuit);

int Ventas_mostrar(void* pVentas);

int criterioCantidadTotal(void* pVenta,char* criterio);

int criterioVentasMayores(void* pVentas,char* criterio);

int criterioTv(void* pVenta,char* criterio);
#endif // VENTAS_H_IN
