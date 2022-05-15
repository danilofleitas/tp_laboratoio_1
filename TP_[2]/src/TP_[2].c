/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Danilo Fleitas DIV 1F
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_stuff.h"
#include "ArrayPassengers.h"

#define CANT_MAX_PASS 2000


int main(void)
{
	setbuf(stdout,NULL);

	int opcion;


	Passenger arrayPassengers[CANT_MAX_PASS];
	Passenger auxPassenger;

	initPassengers(arrayPassengers,CANT_MAX_PASS);

	do
	{
		utn_getNumero(&opcion,"INGRESE OPCION 1)ALTA 2)MODIFICAR 3)BAJA 4)INFORMAR 5)ALTA FORZADA 6)SALIR ","ERROR, SELECCIONA UNA OPCION CORRECTA... ",1,6,7);


		switch(opcion)
		{
		 case 1:
			 if(addPassenger(arrayPassengers,CANT_MAX_PASS,auxPassenger.id,auxPassenger.name,auxPassenger.lastName,auxPassenger.price,auxPassenger.typePassenger,auxPassenger.flycode)==1)
			 {
				 puts("alta exitosa");
			 }
			 	 	 break;

		 case 2:
			 if(Passenger_Modificacion(arrayPassengers,CANT_MAX_PASS,auxPassenger.id)==1)
			 			 {
			 				 puts("modificacion exitosa");
			 			 }
		 			 break;
		 case 3:
			 if(removePassenger(arrayPassengers,CANT_MAX_PASS,auxPassenger.id)==1)
			 {
				 puts("baja exitosa");
			 }
		 			 break;
		 case 4:
			 if(sortPassengers(arrayPassengers,CANT_MAX_PASS)==0)
			 {
				 printPassenger(arrayPassengers,CANT_MAX_PASS);
				 puts("\n\n\nInforme exitoso!\n\n\n");
			 }
		 			 break;
		 case 5:
			 Alta_Forzada();
		 			 break;
		 case 6:
			 puts("\n\nPROGRAMA TERMINADO");
		 			 break;
		}








	}
	while(opcion!=6);









	return EXIT_SUCCESS;
}
