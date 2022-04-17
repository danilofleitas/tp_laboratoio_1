/*
 * utn_getNumero.h
 *
 *  Created on: 10 abr. 2022
 *      Author: PC
 */

#ifndef UTN_GETNUMERO_H_
#define UTN_GETNUMERO_H_

int utn_getNumero(int*pResultado, char*mensaje,char* mensajeError, int minimo, int maximo, int reintentos);
/// @fn int utn_getChar(char*, char*, char*, char, char, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getChar(char*pResultado, char*mensaje,char* mensajeError, char minimo, char maximo, int reintentos);
/// @fn int utn_getFloat(float*, char*, char*, float, float, int)
/// @brief
///
/// @param pResultado
/// @param mensaje
/// @param mensajeError
/// @param minimo
/// @param maximo
/// @param reintentos
/// @return
int utn_getFloat(float*pResultado, char*mensaje,char* mensajeError, float minimo, float maximo, int reintentos);




#endif /* UTN_GETNUMERO_H_ */
