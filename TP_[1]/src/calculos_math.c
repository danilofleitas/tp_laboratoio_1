/*
 * calculos_math.c
 *
 *  Created on: 12 abr. 2022
 *      Author: PC
 */

#include <stdio.h>
#include <stdlib.h>

int suma_math(int operador1, int operador2, int* resultado )
{

	int retorno=-1;

	if(resultado!=NULL)
	{
		*resultado=operador1+operador2;
		retorno=0;
	}
	else
	{
		printf("ERROR");
	}

	return retorno;
}



int resta_math(float operador1, float operador2, float* resultado )
{

	int retorno=-1;

	if(resultado!=NULL)
	{
		*resultado=operador1-operador2;
		retorno=0;
	}
	else
	{
		printf("ERROR");
	}

	return retorno;
}

int multiplicar_math(float operador1, float operador2, float* resultado)
{

	int retorno=-1;

		if(resultado!=NULL)
		{
			*resultado=operador1*operador2;
			retorno=0;
		}
		else
		{
			printf("ERROR");
		}

	return retorno;
}

int dividir_math(float operador1, float operador2, float* resultado)
{

	int retorno=-1;


		if(resultado!=NULL && operador2!=0)
		{
			*resultado=operador1/operador2;
			retorno=0;
		}
		else
		{
			printf("ERROR, NO SE PUEDE DIVIDIR POR 0");
		}

      return retorno;
}


int btc_math(float operador1, float* resultado)
{

	int retorno=-1;
	int btc=4606954.55;

		if(resultado!=NULL)
		{
			*resultado=operador1/btc;
			retorno=0;
		}
		else
		{
			printf("ERROR");
		}

      return retorno;
}














































































