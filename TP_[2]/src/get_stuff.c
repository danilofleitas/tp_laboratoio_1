/*
 * get_stuff.c
 *
 *  Created on: 10 may. 2022
 *      Author: PC
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_stuff.h"

static int esNumerica(char* cadena);


static int myGets(char* cadena, int longitud);
static int getFloat(float* pResultado);
static int esFloat(char* cadena);
static int getInt(int* pResultado);
static int get_Nombre(char* pResultado, int longitud);
//////////////get string/////////////////////

int get_String(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

		if(cadena != NULL && longitud > 0){
			fflush(stdin);
			if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
				if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
					bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
				}
				if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
					strncpy(cadena,bufferString,longitud);
					retorno=0;
				}
			}
		}
		return retorno;
}

int es_Nombre(char* cadena, int longitud)
{
	int i=0;
	int retorno = 1;

		if(cadena != NULL && longitud > 0){
			for(i=0 ; cadena[i] != '\0' && i < longitud; i++){
				if((cadena[i] < 'A' || cadena[i] > 'Z' ) &&
						(cadena[i] < 'a' || cadena[i] > 'z' )){
					retorno = 0;
					break;
				}
			}
		}
		return retorno;
}

static int get_Nombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	get_String(buffer,sizeof(buffer))==0 &&
    		es_Nombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<longitud){
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(get_Nombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}




////////// get numero/float /////////////


static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferGetInt[4096];

	if(myGets(bufferGetInt, sizeof(bufferGetInt))==0 && esNumerica (bufferGetInt))
	{
		retorno=0;
		*pResultado = atoi(bufferGetInt);
	}
	return retorno;
}

static int myGets(char* cadena, int longitud)
{


	if(cadena != NULL && longitud > 0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0';
		}
		return 0;
	}
	return -1;
}


static int esNumerica(char* cadena)
{
	int i=0;
	int retorno = 1;
		if(cadena != NULL && strlen(cadena) > 0)
		{
			while(cadena[i] != '\0')
			{
				if(cadena[i] < '0' || cadena[i] > '9' )
				{
					retorno = 0;
					break;
				}
				i++;
			}
		}
		return retorno;
}

static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferGetFloat[4096];

	if(myGets(bufferGetFloat, sizeof(bufferGetFloat))==0 && esFloat (bufferGetFloat)==1)
	{
		retorno=0;
		*pResultado=atof(bufferGetFloat);
	}
	return retorno;
}




static int esFloat (char* cadena)
{
    int retorno = 1;
    int i=0;
    int contador=0;

    if(cadena != NULL && strlen(cadena)>0)
    {
        for(i=0; cadena[i] != '\0'; i++)
        {
            if (cadena [i] > '9' || cadena [i] < '0')
            {
                if (cadena [i] == '.')
                {
                    contador++;
                    if(contador>1)
                    {
                        retorno=0;
                        break;
                    }
                    else
                    {
                        if(i==0)
                        {
                            if (cadena [i] != '+' && cadena [i] != '-')
                            {
                                retorno=0;
                                break;
                            }
                            else
                            {
                                retorno=0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    return retorno;
}







int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getInt (&bufferInt) == 0 && bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

int utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat (&bufferFloat) == 0 && bufferFloat>=minimo && bufferFloat<=maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos>=0);
	}
	return retorno;
}

























