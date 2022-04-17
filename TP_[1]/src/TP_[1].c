/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Danilo Fleitas División F
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_getNumero.h"
#include "calculos_math.h"
#include "utn_cargaForzada.h"


int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int respuesta;
	int respuestakm;
	float kilometrosIngresados;
	float precioAerolineas;
	float precioLatam;
	float precioAerolineasIngresado;
	float precioLatamIngresado;
	float debitoAero;
	float creditoAero;
	float debitoLat;
	float creditoLat;
	float r_debitoLat;
	float r_creditoLat;
	float r_creditoAero;
	float r_debitoAero;
	float precioBtcAero;
	float precioBtcLat;
	float r_precioBtcAero;
	float r_precioBtcLat;
	float precioXkmAero;
	float r_precioXkmAero;
	float precioXkmLat;
	float r_precioXkmLat;
	float resta;
	float r_resta;
	int flag=0;

		do
		{
			respuesta=utn_getNumero(&opcion,"Seleccione una opcion\n\n1-ingresar kilometros\n\n2-ingresar precio de vuelos\n\n3-calcular costos\n\n4-informar resultados\n\n5-carga forzada de datos\n\n6-Salir\n\n", "ingrese una opcion valida\n\n",1,6,10);

			if(!respuesta)
							{

									switch(opcion)
									{
										case 1:
											respuestakm=utn_getFloat(&kilometrosIngresados,"Ingrese cantidad de kilometros:  \n","la cantidad debe ser entre 1 y 80.000\n",1,80000,5);
										if(respuestakm==0)
										{
											continue;
										}
									break;
									case 2:
									precioAerolineas=utn_getFloat(&precioAerolineasIngresado, "Ingrese precio de aerolineas: \n","Ingrese un precio valido: \n",1,10000000,5);
									precioLatam=utn_getFloat(&precioLatamIngresado,"Ingrese precio de Latam: \n","Ingrese un precio valido\n",1,1000000,5);

									if(precioAerolineas==0 && precioLatam==0)
									{
										continue;
									}
									break;
								case 3:
									flag=1;
									debitoAero=multiplicar_math(precioAerolineasIngresado,0.90,&r_debitoAero);
									creditoAero=multiplicar_math(precioAerolineasIngresado,1.25,&r_creditoAero);
									debitoLat=multiplicar_math(precioLatamIngresado,0.90,&r_debitoLat);
									creditoLat=multiplicar_math(precioLatamIngresado,1.25,&r_creditoLat);
									precioBtcAero=btc_math(precioAerolineasIngresado,&r_precioBtcAero);
									precioBtcLat=btc_math(precioLatamIngresado,&r_precioBtcLat);
									precioXkmAero=dividir_math(precioAerolineasIngresado,kilometrosIngresados,&r_precioXkmAero);
									precioXkmLat=dividir_math(precioLatamIngresado,kilometrosIngresados,&r_precioXkmLat);
									resta=resta_math(precioAerolineasIngresado,precioLatamIngresado,&r_resta);

									if(debitoAero==0 && creditoAero==0 && debitoLat==0 && creditoLat==0 && precioBtcAero==0 && precioBtcLat==0 && precioXkmAero==0 && precioXkmLat==0 && resta==0)
									{
										continue;
									}
									break;
								case 4:
									if(flag==1)
									{
										printf("\nKMs ingresados: %f\n\n",kilometrosIngresados);

										printf("\n El precio de Aerolineas es : $ %.2f \n",precioAerolineasIngresado);
										printf("\n a)Precio con tarjeta de débito: $ %.2f  \n",r_debitoAero);
										printf("\n b)Precio con tarjeta de credito: $ %.2f \n",r_creditoAero);
										printf("\n c)Precio con Bitcoin Aerolineas:  %f \n",r_precioBtcAero);
										printf("\n d)El precio por km en aerolineas es de: $ %.2f \n\n ",r_precioXkmAero);

										printf("\n El precio Latam es : $ %.2f \n",precioLatamIngresado);
										printf("\n a)Precio con tarjeta de débito: $ %.2f  \n",r_debitoLat);
										printf("\n b)Precio con tarjeta de credito: $ %.2f \n",r_creditoLat);
										printf("\n c)Precio con Bitcon Latam:  %f \n",r_precioBtcLat);
										printf("\n d)El precio por km en Latam es de: $ %.2f \n\n\n",r_precioXkmLat);



									    printf("\n La diferencia entre ambos precios es de: $  %.2f \n\n\n",r_resta);
									}
									break;
								case 5:
									carga_forzada();
									break;
								}
							}
							else
							{
									printf("\nERROR");
							}
		}
		while(opcion!=6);




	return EXIT_SUCCESS;
}
