/*
 * get_stuff.h
 *
 *  Created on: 10 may. 2022
 *      Author: PC
 */

#ifndef GET_STUFF_H_
#define GET_STUFF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utn_getString(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);
int es_Nombre(char* cadena,int longitud);
int get_String(char* cadena, int longitud);
int utn_get_Float(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);




#endif /* GET_STUFF_H_ */
