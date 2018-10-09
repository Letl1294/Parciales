#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#define NAME 51
#define LASTNAME 51
#define CUIT 21
#define ID 4
#define CANTIDAD_DE_CLIENTES 100

typedef struct
{
    char name[NAME];
    char lastName[LASTNAME];
    char cuit[CUIT];
    int clienteId;
    int isEmpty;
}Cliente;

int cliente_Alta(Cliente* array, int len, int* id);
int cliente_Init(Cliente* array, int len);
int cliente_Baja(Cliente* array, int len, void* arrayDos, int lenDos);
int cliente_Modificar(Cliente* array, int len);
Cliente* cliente_getByID(Cliente* array,int len,int id);
int cliente_altaForzada(Cliente* array,int len,char* name,char* lastName, char* cuit);
int cliente_mostrar(Cliente* array,void* arrayDos,int lenUno, int lenDos);
#endif
