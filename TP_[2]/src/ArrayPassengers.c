/*
 * Passengers.c
 *
 *  Created on: 10 may. 2022
 *      Author: PC
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassengers.h"
#include "get_stuff.h"

#define TRUE 0
#define FALSE 1
#define BAJA -1

static int Passenger_ObtenerID(void);

static int Passenger_ObtenerID(void)
{
	static int Pantalla_idIncremental=0;
	return Pantalla_idIncremental++;
}


int Passenger_ObtenerIndexLibre(Passenger list[], int len)
{
	{
		int retorno=-1;
		int i;

		//si existe el array y el limite es valido

		if(list!=NULL && len>0)
		{
			//recorro todo el array
			for(i=0;i<len;i++)
			{
				//pregunto por el estado "libre"(true)
				if(list[i].isEmpty==TRUE)
				{
					//obtengo el primer index del vector "libre"(true) y salgo
					retorno=i;
					break;
				}
			}
		}
		return retorno;
	}


}


Passenger Passenger_CargarDatos(void)
{
	Passenger auxiliar;
	int opcion;
	int opcionVuelo;
	/**cargar datos necesarios para el alta*/
	/** importante - no cargar id ni estado - se ahce en el alta*/

	utn_getString(auxiliar.name,51,"Ingrese nombre de pasajero: ","Error.",5);
	utn_getString(auxiliar.lastName,51,"Ingrese apellido de pasajero: ","Error.",5);
	utn_get_Float(&auxiliar.price,"Ingrese un precio: ","Erorr, ingrese un precio valido: ",1,1000000000,5);
	utn_getString(auxiliar.flycode,10,"Ingrese flycode del pasajero : ","Error, ingrese un codigo valido",5);
	utn_getNumero(&opcionVuelo,"Ingrese estado del vuelo 1)ACTIVO 2)CANCELADO  : ","Error, ingrese un estado valido",1,2,5);


	utn_getNumero(&opcion,"\nINGRESE TIPO DE PASAJERO 1)PRIMERA CLASE 2)TURISTA\n","\nError. Reingrese\n",1,2,5);

	switch(opcion)
	{
		case 1:
			auxiliar.typePassenger=1;

			break;
		case 2:
			auxiliar.typePassenger=2;
			break;
	}

	switch(opcionVuelo)
		{
			case 1:
				auxiliar.statusFlight=1;

				break;
			case 2:
				auxiliar.statusFlight=2;
				break;
		}

return auxiliar;
}


int initPassengers(Passenger* list, int len)
{
	int i;
	int retorno=-1;

	if(list!=NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			retorno=0;
			list[i].isEmpty=TRUE;

		}
	}
	return retorno;
}





int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno=0;
	Passenger auxPassenger;

	//busco espacio en el array
	int index=Passenger_ObtenerIndexLibre(list,len);

	//si index == -1 array lleno
	//si index != -1 tengo en index posicion de array libre
	if(index!=-1)
	{
		//pido datos - cargo pantalla auxiliar
		auxPassenger=Passenger_CargarDatos();
		//seteo ID unico - variable estatica autoincremental
		auxPassenger.id=Passenger_ObtenerID();
		//cambio su estado a "ocupado(false)"
		auxPassenger.isEmpty=FALSE;
		//seteo el array con auxiliar en index libre obtenido previamente
		list[index]=auxPassenger;
		//retorno 1 para saber que fue dado de alta satisfactoriamente
		retorno=1;
	}
	return retorno;
}
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno=-1;
	int i;

	//si existe el array y el limite es valido
	if(list!=NULL && len>0)
	{
		//recorro todo el array
		for(i=0;i<len;i++)
		{
			//busco que este "ocupado" y que coincida el id que estoy buscando
			if(list[i].id==id && list[i].isEmpty==FALSE)
			{
				//si encontre el id
				//devuelvo el index de donde esta el id buscado y salgo
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

void Passenger_MostrarUno(Passenger mPassenger)
{
	//printf de un solo passenger
	printf("%d", mPassenger.id);
	if(mPassenger.typePassenger==1)
	{
		printf("%30s", "PRIMERA CLASE");
	}
	else
	{
		printf("%25s", "TURISTA");
	}
	printf("%15.2f\n", mPassenger.price);
	printf("%10s\n", mPassenger.name);
	printf("%8s\n",mPassenger.lastName);
}


int printPassenger(Passenger* list,int lenght)
{
	int i;
	int retorno=0;
	int cantidad=0;

	//cabecera
	printf(" PASAJEROS  \n");
	printf("ID   APELLIDO   NOMBRE   PRECIO   CODIGO   TIPO   ESTADO\n");
	printf("---------------------------------------------------------------\n");

	//si existe el array y el limite es valido
	if(list!=NULL && lenght>0)
	{
		//recorro todo el array
		for(i=0;i<lenght;i++)
		{
			//pregunto por su estado OCUPADO(false)
			if(list[i].isEmpty==FALSE)
			{
				Passenger_MostrarUno(list[i]);
				//contador de passenger
				cantidad++;
			}
		}
	}

	// si cantidad ==0 NO HUBO Passenger para mostrar (array sin altas)
	if(cantidad>0)
	{
			retorno=1;
	}
	return retorno;
}





int removePassenger(Passenger* list, int len, int id)
{
	int retorno=0;
	int index;
	int flag=0;

	//listo todos los passenger
	if(printPassenger(list,len))
	{
		//bandera en 1 si hay passengers dados de alta para listar
		flag=1;
	}

	//si hay passenger para dar de baja
	if(flag)
	{
		//pido id para dar de baja
		/** usar funcion get_int de libreria de inputs*/

			utn_getNumero(&id,"INGRESE ID A DAR DE BAJA","ERROR, INGRESE ID VALIDO",0,10,5);

		//busco index por id en array
		while(findPassengerById(list,len,id)==-1)
		{
			puts("NO EXISTE ID.");

			/** usar funcion get_int de libreria de inputs*/
			utn_getNumero(&id,"INGRESE ID A DAR DE BAJA","ERROR, INGRESE ID VALIDO",0,10,5);
		}

		// obtengo index del array de pantalla a dar de baja
		index=findPassengerById(list,len,id);


		/**preguntar si desea continuar*/
		//baja aceptada - cambio estado a "baja"
		list[index].isEmpty=BAJA;

		// retorno 1 si s dio de baja correctamente

		retorno=1;
	}

	return retorno;
}


Passenger Passenger_ModificarUno(Passenger m_Passenger)
{
	int opcion;


	while(opcion!=6){
	utn_getNumero(&opcion,"Seleccione una opcion a modificar 1)Nombre 2)Apellido 3)Precio 4)Codigo de Vuelo 5)Tipo de pasajero 6) salir\n", "Error.", 1, 6, 3);

	//While - para cargar cuantos datos quiera el usuario

	switch (opcion)
	{
		case 1:
			utn_getString(m_Passenger.name,51,"Ingrese nombre: ","Error, reingrese nombre: ",5);
			break;
		case 2:
			utn_getString(m_Passenger.name,51,"Ingrese apellido: ","Error, reingrese apellido: ",5);
			break;
		case 3:
			utn_get_Float(&m_Passenger.price,"Ingrese el precio: ","Error,ingrese un precio valido: ",0,100000000,5);
			break;
		case 4:
			utn_getString(m_Passenger.flycode,10,"Ingrese codigo de vuelo: ", "Error, reingrese codigo de vuelo: ",5);
			break;
		case 5:
			utn_getNumero(&opcion,"Seleccione una opcion a modificar 1)PRIMERA CLASE 2)TURISTA", "Error.", 1, 2, 3);
				switch(opcion)
				{
				case 1:
					m_Passenger.typePassenger=1;
					break;
				case 2:
					m_Passenger.typePassenger=2;
					break;
				}
			break;
		case 6:
			puts("");
			break;
		}
}
	return m_Passenger;
}




int Passenger_Modificacion(Passenger* list, int len, int id)
{
	int retorno=0;
	int index;
	int flag=0;

	Passenger auxiliar;

	//listo todos los passenger
	if(printPassenger(list,len))
	{
		//bandera en 1 si hay passengers dados de alta para listar
		flag=1;
	}

	//si hay passenger para dar de baja
	if(flag)
	{
		//pido id para dar de baja
		/** usar funcion get de libreria de inputs*/

			utn_getNumero(&id,"INGRESE ID A DAR DE BAJA","ERROR, INGRESE ID VALIDO",0,10,5);

		//busco index por id en array
		while(findPassengerById(list,len,id)==-1)
		{
			puts("NO EXISTE ID.");

			/** usar funcion get de libreria de inputs*/
			utn_getNumero(&id,"INGRESE ID A DAR DE BAJA","ERROR, INGRESE ID VALIDO",0,10,5);
		}

				// obtengo index del array de passenger a dar de baja
				index=findPassengerById(list,len,id);


				//llamo a funcion que modifica passenger
				auxiliar=Passenger_ModificarUno(list[index]);

				/**preguntar si desea continuar*/
						//modificaciona aceptada
						list[index]=auxiliar;

		// retorno 1 si s dio de baja correctamente

		retorno=1;
	}

	return retorno;
}


int sortPassengers(Passenger* list, int len)
{
	int retorno=-1;
	int flagSwap;
	int i;

	Passenger buffer;

	if(list!=NULL && len>0)
	{
		do
		{
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if(strncmp(list[i].lastName,list[i+1].lastName,51)>0)
				{
					flagSwap=1;
					buffer=list[i];
					list[i]=list[i+1];
					list[i+1]=buffer;

				}
			}
			flagSwap=0;
			for(i=0;i<len-1;i++)
			{
				if((list[i].typePassenger < list[i+1].typePassenger)>0)
				{
					flagSwap=1;
					buffer=list[i];
					list[i]=list[i+1];
					list[i+1]=buffer;

				}
			}



		}while(flagSwap);

		retorno=0;
	}

	return retorno;
}




void Alta_Forzada(void)
{



}













