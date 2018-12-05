#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096

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

/** \brief Valida el dni.
 *
 * \param Con un if validamos los puntos y que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidDni(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    int contadorPuntos=0;
    int contadorDigitos=strlen(pBuffer);

    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i] < '0' || pBuffer[i] > '9')
            {
                if((pBuffer[i]!='.') || (pBuffer[0]=='.') || (pBuffer[strlen(pBuffer)-1]=='.'))
                {
                    retorno=0;
                    break;
                }
                if(pBuffer[i]=='.')
                {
                    contadorPuntos++;
                }
            }
            if(contadorPuntos<2 || contadorPuntos>2)
            {
                retorno=0;
            }
            if(contadorPuntos==2)
            {
                retorno=0;
                if(pBuffer[2]=='.' && pBuffer[6]=='.')
                {
                    retorno=1;
                }
                if(contadorDigitos>10)
                {
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Valida el telefono.
 *
 * \param Con un if validamos los guiones y que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidTel(char* pBuffer,int limite)
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
            if(contadorGuion<1 || contadorGuion>2)
            {
                retorno=0;
            }
            if(contadorGuion==1)
            {
                retorno=0;
                if(pBuffer[4]=='-')
                {
                    retorno=1;
                }
                if(contadorDigitos>9)
                {
                    retorno=0;
                }
            }
            if(contadorGuion==2)
            {
                retorno=0;
                if(pBuffer[2]=='-' && pBuffer[7]=='-')
                {
                    retorno=1;
                }
                if(contadorDigitos>12)
                {
                    retorno=0;
                }
            }
        }
    }
    return retorno;
}

/** \brief Valida el cuil.
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

/** \brief Valida el int.
 *
 * \param Con un if validamos que solo haya numeros. Con el For pasamos por los diferentes elementos del array.
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

/** \brief Valida el nombre.
 *
 * \param Con un if validamos que solo haya letras. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0 && strlen(pBuffer)>0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida letras y numeros.
 *
 * \param Con un if validamos los espacios y que solo haya letras y numeros. Con el For pasamos por los diferentes elementos del array.
 * \return return 1 si esta bien.
 *
 */

static int isValidAlfaNum(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') &&
               (pBuffer[i]<'0' || pBuffer[i]>'9') && (pBuffer[i]!=' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Valida el getString.
 *
 * \param Con un if validamos que el enter sea reemplazado con \0.
 * \return return 0 si esta bien.
 *
 */

static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    __fpurge(stdin);
    fgets(bufferStr,limite,stdin);
    len = strlen(bufferStr);

    if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
    retorno = 0;

    strncpy(pBuffer,bufferStr,limite);

    return retorno;
}

/** \brief Permite ingresar un nombre.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un numero entero.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getSoloInt( char* pInt, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferInt[BUFFER_STR];

    if( pInt != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferInt,limite) == 0 &&
                isValidInt(bufferInt,limite))
            {
                strncpy(pInt,bufferInt,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un numero con decimales.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getSoloFloat(  float* pFloat, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    float auxFloat;
    char bufferFloat[BUFFER_STR];

    if( pFloat != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferFloat,limite) == 0 &&
                isValidFloat(bufferFloat,limite))
            {
                auxFloat=atof(bufferFloat);
                *pFloat=auxFloat;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un telefono.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getSoloTelefono(  char* pTelefono, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferTel[BUFFER_STR];

    if( pTelefono != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferTel,limite) == 0 &&
                isValidTel(bufferTel,limite))
            {
                strncpy(pTelefono,bufferTel,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un DNI.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getSoloDni(char* pDni, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferDni[BUFFER_STR];

    if( pDni != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferDni,limite) == 0 &&
                isValidDni(bufferDni,limite))
            {
                strncpy(pDni,bufferDni,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un CUIL.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getCuil(char* pCuil, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferCuil[BUFFER_STR];

    if( pCuil != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferCuil,limite) == 0 &&
                isValidCuil(bufferCuil,limite))
            {
                strncpy(pCuil,bufferCuil,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/** \brief Permite ingresar un entero sin validar.
 *
 * \return return 0 si esta bien.
 *
 */

int utn_ScanInt(char* mensaje,int* numero)
{
    int retorno = -1;
    int auxiliarInt;
    printf("%s",mensaje);
    scanf("%d",&auxiliarInt);
    *numero = auxiliarInt;
    retorno = 0;
    return retorno;
}

/** \brief Permite ingresar un letras y numeros.
 *
 * \param Con un if validamos que el array este cargado. Y utilizamos variables auxiliares para validar los datos ingresados.
 * \return return 0 si esta bien.
 *
 */

int utn_getAlfaNum(char* pAlfaNum, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferAlfNum[BUFFER_STR];

    if( bufferAlfNum != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferAlfNum,limite) == 0 &&
                isValidAlfaNum(bufferAlfNum,limite))
            {
                strncpy(pAlfaNum,bufferAlfNum,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
