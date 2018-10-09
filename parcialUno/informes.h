#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "afiche.h"
#include "cliente.h"

int informes_promedioPorCiente(Afiche arrayUno[], int lenUno, Cliente arrayDos[], int lenDos);

int informes_VentasZona(Afiche array[], int len);

int informes_clienteMasCantidadNoCobradas(Cliente arrayUno[],Afiche arrayDos[], int lenUno,int lenDos);

int informes_clienteMasAfiches(Cliente arrayUno[], Afiche arrayDos[], int lenUno, int lenDos);

int informes_cantidadPorZona(Afiche array[], int len);
#endif
