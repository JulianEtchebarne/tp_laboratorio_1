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
#include <string.h>
#include <ctype.h>

// Declaración de variables
float km = 0;
float aerolineas;
float latam;
float debitoAerolineas;
float debitoLatam;
float creditoAerolineas;
float creditoLatam;
float bitcoinAerolineas;
float bitcoinLatam;
float precioKmAerolineas;
float precioKmLatam;
float diferenciaPrecios;
float forzadoDebitoAerolineas;
float forazadoDebitoLatam;
float forzadoCreditoAerolineas;
float forzadoCreditoLatam;
float forzadoBitcoinAerolineas;
float forzadoBitcoinLatam;
float forzadoKmAerolineas;
float forzadoKmLatam;
int banderaCostos = 0;
int opcion;
int empresa;
int segundaOpcion;

// Programa Principal
int main(void) {
	setvbuf(stdout, NULL, 0, _IONBF);
	do
	{
		printf("Bienvenido! ¿Qué desea hacer? \n");
		printf("1) Ingresar kilómetros. (KM = %f) \n", km);
		printf("2) Ingresar precio de vuelos. (Aerolíneas = %f, Latam = %f) \n", aerolineas, latam);
		printf("3) Calcular todos los costos. \n");
		printf("4) Informar resultados. \n");
		printf("5) Carga forzada de datos. \n");
		printf("6) Salir. \n");
		fflush(stdout);
		scanf("%i", &opcion);
		switch(opcion)
		{
		case 1:
			km = ingresarKm(km);

			break;
		case 2:
			do
			{
				segundaOpcion = subMenu();
				switch(segundaOpcion){
				case 1:
					aerolineas = precioAerolineas(aerolineas);
					break;
				case 2:
					latam = precioLatam(latam);
					break;
				case 3:
					printf("Saliendo del sub menú. \n");
					break;
				}
			} while (segundaOpcion != 3);
			break;
		case 3:
			if (aerolineas == 0 || latam == 0 || km == 0 ){
				printf("Se deben ingresar más datos para calcular los costos. \n");
				break;
			}
			else
			{
				debitoAerolineas = tarjetaDebito(aerolineas);
				debitoLatam = tarjetaDebito(latam);

				creditoAerolineas = tarjetaCredito(aerolineas);
				creditoLatam = tarjetaCredito(latam);

				bitcoinAerolineas = precioBitcoin(aerolineas);
				bitcoinLatam = precioBitcoin(latam);

				precioKmAerolineas = aerolineas / km;
				printf("El precio por km de Aerolineas es de: $ %f \n", precioKmAerolineas);
				precioKmLatam = latam / km;
				printf("El precio por km de Latam es de: $ %f \n", precioKmLatam);

				diferenciaPrecios = aerolineas - latam;
				printf("La diferencia de precios de Aerolineas sobre Latam es de: $ %f \n", diferenciaPrecios);
				banderaCostos = 1;
				break;
			}
		case 4:
			if (banderaCostos == 0){
				printf("Los costos aún no han sido calculados. \n");
				break;
			}
			else
			{
				printf("KMs Ingresados: %f km \n \n", km);
				printf("Precio Aerolineas: $%f \n", aerolineas);
				printf("a) Precio con tarjeta de débito: $%f \n", debitoAerolineas);
				printf("b) Precio con tarjeta de crédito: $%f \n", creditoAerolineas);
				printf("c) Precio pagando con bitcoin: %f BTC \n", bitcoinAerolineas);
				printf("d) Mostrar precio unitario: %f \n \n", precioKmAerolineas);

				printf("Precio Latam: $%f \n", latam);
				printf("a) Precio con tarjeta de débito: $%f \n", debitoLatam);
				printf("b) Precio con tarjeta de crédito: $%f \n", creditoLatam);
				printf("c) Precio pagando con bitcoin: %f BTC \n", bitcoinLatam);
				printf("d) Mostrar precio unitario: %f \n \n", precioKmLatam);
				printf("La diferencia de precio es: %f", diferenciaPrecios);
				break;
			}
		case 5:
			km = 7090;
			aerolineas = 162965;
			latam = 159339;
			forzadoDebitoAerolineas = tarjetaDebito(aerolineas);
			forazadoDebitoLatam = tarjetaDebito(latam);
			forzadoCreditoAerolineas = tarjetaCredito(aerolineas);
			forzadoCreditoLatam = tarjetaCredito(latam);
			forzadoBitcoinAerolineas = precioBitcoin (aerolineas);
			forzadoBitcoinLatam = precioBitcoin(latam);
			forzadoKmAerolineas = aerolineas / km;
			forzadoKmLatam = latam / km;
			diferenciaPrecios = aerolineas - latam;

			printf("KMs Ingresados: %f km \n \n", km);
			printf("Precio Aerolineas: $%f \n", aerolineas);
			printf("a) Precio con tarjeta de débito: $%f \n", forzadoDebitoAerolineas);
			printf("b) Precio con tarjeta de crédito: $%f \n", forzadoCreditoAerolineas);
			printf("c) Precio pagando con bitcoin: %f BTC \n", forzadoBitcoinAerolineas);
			printf("d) Mostrar precio unitario: %f \n \n", forzadoKmAerolineas);

			printf("Precio Latam: $%f \n", latam);
			printf("a) Precio con tarjeta de débito: $%f \n", forazadoDebitoLatam);
			printf("b) Precio con tarjeta de crédito: $%f \n", forzadoCreditoLatam);
			printf("c) Precio pagando con bitcoin: %f BTC \n", forzadoBitcoinLatam);
			printf("d) Mostrar precio unitario: %f \n \n", forzadoKmLatam);
			printf("La diferencia de precio es: %f", diferenciaPrecios);
			break;

		}
	}while (opcion != 6);
	printf("Saliendo del programa.");

	return EXIT_SUCCESS;
}
