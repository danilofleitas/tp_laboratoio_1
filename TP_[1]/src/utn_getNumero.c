/*
 * utn_getNumero.c
 *
 *  Created on: 10 abr. 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>

 int utn_getNumero(int*pResultado, char*mensaje,char* mensajeError, int minimo, int maximo, int reintentos)
 {

	 int bufferInt;
	 int retorno=-1;
	 if(pResultado !=NULL && mensaje!=NULL && mensajeError !=NULL && minimo<= maximo && reintentos >=0)
	 {


		 do
		 {
			 	 printf("%s", mensaje);

			 	 scanf("%d", &bufferInt);

			 		 if(bufferInt >=minimo && bufferInt <=maximo)
			 		 {
			 			 *pResultado=bufferInt;
			 			 retorno=0;
			 			 break;
			 		 }
			 		 else
			 		 {
			 			 printf("%s",mensajeError);
			 			 reintentos--;
			 		 }

		 }while(reintentos>=0);

	 }

	 return retorno;
 }




 int utn_getChar(char*pResultado, char*mensaje,char* mensajeError, char minimo, char maximo, int reintentos)
 {

 	 char bufferChar;
 	 int retorno=-1;

 	 if(pResultado !=NULL && mensaje!=NULL && mensajeError !=NULL && minimo<= maximo && reintentos >=0)
 	 {


 		 do
 		 {
 			 	 printf("%s", mensaje);
 			 	 fflush(stdin);
 			 	 scanf("%c", &bufferChar);

 			 		 if(bufferChar >=minimo && bufferChar <=maximo)
 			 		 {
 			 			 *pResultado=bufferChar;
 			 			 retorno=0;
 			 			 break;
 			 		 }
 			 		 else
 			 		 {
 			 			 printf("%s",mensajeError);
 			 			 reintentos--;
 			 		 }

 		 }while(reintentos>=0);

 	 }

 	 return retorno;
  }

 int utn_getFloat(float*pResultado, char*mensaje,char* mensajeError, float minimo, float maximo, int reintentos)
 {

	 float bufferFloat;
  	 int retorno=-1;

  	 if(pResultado !=NULL && mensaje!=NULL && mensajeError !=NULL && minimo<= maximo && reintentos >=0)
  	 {


  		 do
  		 {
  			 	 printf("%s", mensaje);
  			 	 scanf("%f", &bufferFloat);

  			 		 if(bufferFloat >=minimo && bufferFloat <=maximo)
  			 		 {
  			 			 *pResultado=bufferFloat;
  			 			 retorno=0;
  			 			 break;
  			 		 }
  			 		 else
  			 		 {
  			 			 printf("%s",mensajeError);
  			 			 reintentos--;
  			 		 }

  		 }while(reintentos>=0);

  	 }

  	 return retorno;
   }
