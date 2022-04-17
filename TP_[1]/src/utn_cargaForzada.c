/*
 * utn_cargaForzada.c
 *
 *  Created on: 14 abr. 2022
 *      Author: PC
 */


#include <stdio.h>
#include <stdlib.h>
#include "calculos_math.h"

void carga_forzada()
{
	float cF_precioAerolineas=162965;
	float cF_kilometrosIngresados=7090;
	float cF_precioLatam=159339;



	float cF_debitoAero_r;
	float cF_creditoAero_r;
	float cF_debitoLat_r;
	float cF_creditoLat_r;
	float cF_precioBtcAero_r;
	float cF_precioBtcLat_r;
	float cF_precioXkmAero_r;
	float cF_precioXkmLat_r;
	float cF_resta_r;


	multiplicar_math(162965,1.25,&cF_creditoAero_r);
	multiplicar_math(162965,0.90,&cF_debitoAero_r);
	multiplicar_math(159339,0.90,&cF_debitoLat_r);
    multiplicar_math(159339,1.25,&cF_creditoLat_r);
    btc_math(162965,&cF_precioBtcAero_r);
    btc_math(159339,&cF_precioBtcLat_r);
    dividir_math(162965,cF_kilometrosIngresados,&cF_precioXkmAero_r);
    dividir_math(159339,cF_kilometrosIngresados,&cF_precioXkmLat_r);
    resta_math(162965,159339,&cF_resta_r);


    	printf("\nKMs ingresados: %f\n\n",cF_kilometrosIngresados);

    		printf("\n Precio de Aerolineas es : $ %f \n",cF_precioAerolineas);
    		printf("\n a)Precio con tarjeta de débito: $ %f  \n",cF_debitoAero_r);
    		printf("\n b)Precio con tarjeta de credito: $ %f \n",cF_creditoAero_r);
    		printf("\n c)Precio con Bitcoin Aerolineas:  %f \n",cF_precioBtcAero_r);
    		printf("\n d)El precio por km en aerolineas es de: $ %.2f \n\n ",cF_precioXkmAero_r);

    		printf("\n Precio Latam es : $ %.2f \n",cF_precioLatam);
    		printf("\n a)Precio con tarjeta de débito: $ %f  \n",cF_debitoLat_r);
    		printf("\n b)Precio con tarjeta de credito: $ %f \n",cF_creditoLat_r);
    		printf("\n c)Precio con Bitcon Latam:  %f \n",cF_precioBtcLat_r);
    		printf("\n d)El precio por km en Latam es de: $ %f \n\n\n",cF_precioXkmLat_r);



    		printf("\n La diferencia entre ambos precios es de: $  %.2f \n\n\n",cF_resta_r);


}
