/*
 ============================================================================
 Name        : main.c
 Author      : Julian Etchebarne
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float ingresarKm(float numero)
{
	printf("Ingrese la cantidad de Kilómetros: ");
	fflush(stdout);
	scanf("%f", &numero);
	return numero;
}

int subMenu(){
	int unSubMenu;
	printf("1) Precio Aerolíneas. \n");
	printf("2) Precio Latam. \n");
	printf("3) Salir. \n");
	utn_getInt("\n Elija una opción: ", "Ingresar opcion entre 1 y 3", &unSubMenu,2,3,1);
	return unSubMenu;
}

float precioAerolineas(float aerolineas)
{
		printf("Ingrese el precio de Areolíneas: ");
		fflush(stdout);
		scanf("%f", &aerolineas);
		return aerolineas;
}

float precioLatam(float latam){
	printf("Ingrese el precio de Latam: ");
	fflush(stdout);
	scanf("%f", &latam);
	return latam;
}

int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo)
{
    int retorno = -1;
    int bufferInt;
    int resultadoScanf;
    if(        mensaje != NULL &&
            mensajeError != NULL &&
            pResultado != NULL &&
            reintentos >= 0 &&
            maximo >= minimo)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdout); // fflush // __fpurge
            resultadoScanf = scanf("%d" , &bufferInt);
            if(resultadoScanf == 1 && bufferInt >= minimo && bufferInt <= maximo)
            {
                retorno = 0;
                *pResultado = bufferInt;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

float tarjetaDebito(float descuento){
	float sacarDescuento;
	sacarDescuento = descuento - (descuento * 10 / 100);
	return sacarDescuento;
}

float tarjetaCredito(float interes){
	float sacarInteres;
	sacarInteres = interes + (interes * 10 /100);
	return sacarInteres;
}

float precioBitcoin(float precio){
	float bitcoin = 4606954.55;
	precio = precio / bitcoin;
	return precio;
}
