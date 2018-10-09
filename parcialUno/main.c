#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiche.h"
#include "informes.h"
#include "utn.h"

/**
* \brief ABM, se realizan altas, bajas y modificaciones y se muestran a los empleados.
* \param Declaramos la variable flag para saber si se esta pasando por el alta. Y varios if en los diferentes case para validar.
* \param Se utiliza un "do" para que lo haga al menos una vez y si se cumple la condicion del "while" se repite.
* \param Dentro del "do" se utiliza un printf para que el usuario pueda ver las opciones del menu y se le pide que seleccione una.
* \param La funcion scanInt es para que se ingrese el numero de la opcion.
* \param Switch, una vez ingresada la opcion se entra en uno de los "case:" de este. Sino esta muestra un mensaje de error.
* \return 0 al terminar el programa.
*/

int main()
{
    Cliente arrayUno[CANTIDAD_DE_CLIENTES];
    Afiche arrayDos[CANTIDAD_DE_VENTAS];
    cliente_Init(arrayUno,CANTIDAD_DE_CLIENTES);
    afiche_Init(arrayDos,CANTIDAD_DE_VENTAS);
    int opcion;
    int id;
    int contadorAfiches=0;
    int contadorClientes=0;

    cliente_altaForzada(arrayUno,CANTIDAD_DE_CLIENTES,"Lucas","torres","20-19018614-9");
    cliente_altaForzada(arrayUno,CANTIDAD_DE_CLIENTES,"Marta","Sanchez","20-14343411-8");
    cliente_altaForzada(arrayUno,CANTIDAD_DE_CLIENTES,"Lio","Messi","14-11111343-1");
    cliente_altaForzada(arrayUno,CANTIDAD_DE_CLIENTES,"Julio","Saliva","11-114343143-0");
    cliente_altaForzada(arrayUno,CANTIDAD_DE_CLIENTES,"Marito","baracus","14-123343123-4");

    contadorClientes = 5;

    afiche_altaForzada(arrayDos,CANTIDAD_DE_VENTAS,"sol.jpg","zona oeste",4,0);
    afiche_altaForzada(arrayDos,CANTIDAD_DE_VENTAS,"plaza.jpg","caba",6,1);
    afiche_altaForzada(arrayDos,CANTIDAD_DE_VENTAS,"torneo.jpg","zona oeste",1,2);
    afiche_altaForzada(arrayDos,CANTIDAD_DE_VENTAS,"mujer.jpg","zona sur",11,3);
    afiche_altaForzada(arrayDos,CANTIDAD_DE_VENTAS,"disney.jpg","zona sur",16,4);

    contadorAfiches = 5;

    do{

        printf("MENU:\n");
        printf("\n1.Alta Cliente\n");
        printf("2.Modificar Cliente\n");
        printf("3.Baja Cliente\n");
        printf("4.Vender Afiches\n");
        printf("5.Editar ventas\n");
        printf("6.Cobrar ventas\n");
        printf("7.Imprimir Cientes\n");
        printf("8.Mostrar cantidad de afiches por zona\n");
        printf("9.Mostrar Promedio de afiches vendidos por cliente\n");
        printf("10.Mostrar Ventas por Zona\n");
        printf("11.Mostrar Cliente con mayor cantidad no cobradas\n");
        printf("12.Mostrar Cliente con mayor cantidad de afiches\n");
        printf("13.Salir\n");
        utn_ScanInt("Ingrese una opcion: ",&opcion);

        switch (opcion)
        {
            case 1:
                if(!cliente_Alta(arrayUno,CANTIDAD_DE_CLIENTES,&id))
                {
                    printf("\nAlta realizada. ID: %d",id);
                    contadorClientes++;
                }
                else
                {
                    printf("Datos erroneos para cargar.");
                }
                break;

            case 2:
                if(contadorClientes>0)
                {
                    if(!cliente_Modificar(arrayUno,CANTIDAD_DE_CLIENTES))
                    {
                        printf("\nDatos del cliente Modificados");
                    }
                }
                else
                {
                    printf("\nFaltan clientes para modificar");
                }
                break;

            case 3:
                if(contadorClientes>0)
                {
                   if(!cliente_Baja(arrayUno,CANTIDAD_DE_CLIENTES,arrayDos,CANTIDAD_DE_VENTAS))
                    {
                        printf("\nCliente dado de baja");
                        contadorClientes--;
                    }
                }
                else
                {
                printf("\nNo hay clientes para dar de baja");
                }
                break;

            case 4:
                if(!utn_getSoloInt(&id,ID,"Ingrese ID del cliente: ","Id incorrecto",2))
                {
                    if(cliente_getByID(arrayUno,CANTIDAD_DE_CLIENTES,id)==NULL)
                    {
                      printf("No hay cliente");
                      break;
                    }
                    else
                    {
                        if(!afiche_vender(arrayDos,CANTIDAD_DE_VENTAS,id))
                        {
                            printf("\nVenta realizada.Pendiente de pago");
                            contadorAfiches++;
                        }
                        else
                        {
                            printf("\nFaltan datos");
                        }
                    }
                }
                break;

            case 5:
                if(contadorAfiches>0)
                {
                    if(!afiche_Modificar(arrayDos,CANTIDAD_DE_VENTAS))
                    {
                        printf("Datos del afiche modificados");
                    }
                }
                else
                {
                    printf("Datos del afiche modificados");
                }
                break;

            case 6:
                if(contadorAfiches>0)
                {
                    if(!afiche_Cobrar(arrayDos,arrayUno,CANTIDAD_DE_VENTAS,CANTIDAD_DE_CLIENTES))
                    {
                        printf("Pago realizado");
                        contadorAfiches--;
                    }
                }
                else
                {
                    printf("No hay venta a cobrar");
                }
                break;

            case 7:
                if(contadorClientes>0)
                {
                    cliente_mostrar(arrayUno,arrayDos,CANTIDAD_DE_CLIENTES,CANTIDAD_DE_VENTAS);
                }
                else
                {
                    printf("No hay clientes");
                }
                break;

            case 8:
                if(contadorAfiches>0)
                {
                    informes_cantidadPorZona(arrayDos,CANTIDAD_DE_VENTAS);
                }
                else
                {
                    printf("No hay ventas");
                }
                break;

            case 9:
                if(contadorAfiches>0)
                {
                   informes_promedioPorCiente(arrayDos,CANTIDAD_DE_VENTAS,arrayUno,CANTIDAD_DE_CLIENTES);
                }
                else
                {
                    printf("No hay ventas");
                }
                break;

            case 10:
                if(contadorAfiches>0)
                {
                    informes_VentasZona(arrayDos,CANTIDAD_DE_VENTAS);
                }
                else
                {
                    printf("No hay ventas");
                }
                break;

            case 11:
                if(contadorClientes>0)
                {
                    informes_clienteMasCantidadNoCobradas(arrayUno,arrayDos,CANTIDAD_DE_CLIENTES,CANTIDAD_DE_VENTAS);
                }
                else
                {
                    printf("No hay clientes");
                }
                break;

            case 12:
                if(contadorAfiches>0)
                {
                    informes_clienteMasAfiches(arrayUno,arrayDos,CANTIDAD_DE_CLIENTES,CANTIDAD_DE_VENTAS);
                }
                else
                {
                    printf("No hay clientes");
                }
                break;

            case 13:
                printf("\nHasta Luego");
                break;

            default:
                printf("Opcion invalida.");
                break;
        }
        __fpurge(stdin); //para limpiar el buffer.
        printf("\nIngrese ENTER para continuar");
        getchar(); //te freeza hasta que apretas una letra.
        system("clear"); //limpia la pantalla

    }while(opcion!=13);

return 0;
}
