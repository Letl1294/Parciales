#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getSoloInt(  char* pInt, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getSoloFloat(  float* pFloat, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getSoloTelefono(  char* pTelefono, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getSoloDni(char* pDni, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getCuil(char* pCuil, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_ScanInt(char* mensaje,int* numero);
#endif // UTN_H_INCLUDED
