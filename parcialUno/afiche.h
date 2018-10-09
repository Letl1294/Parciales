#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED
#define NAME 51
#define ZONA 25
#define ID 4
#define CANTIDAD_DE_VENTAS 1000

typedef struct
{
    char name[NAME];
    char zona[ZONA];
    int cantidad;
    int aficheId;
    int clienteId;
    int isEmpty;
    int cobrar;
}Afiche;

int afiche_vender(Afiche* array, int len,int id);
int afiche_Init(Afiche* array, int len);
int afiche_Modificar(Afiche* array, int len);
int afiche_Cobrar(Afiche* array,void* arrayDos, int lenUno,int lenDos);
int afiche_mostrar(Afiche* array, int len);
int afiche_altaForzada(Afiche* array,int len,char* name,char* zona, int cantidad, int id);
Afiche* afiche_getByID(Afiche* array,int len,int id);
#endif
