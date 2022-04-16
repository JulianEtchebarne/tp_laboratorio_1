/*
 * funciones.h
 *
 *  Created on: 15 abr. 2022
 *      Author: julian
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/*
 brief: ingreso de los kilometros
 param: float donde se va a guardar la variable
 return: numero ingresado
 * */
float ingresarKm(float numero);
/*
 brief: Funcion para validar datos enteros
 param: 2 char, 4 int para validacion
 return: si no se ingresa nada retorna -1
 * */
int utn_getInt(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int maximo,int minimo);
/*
 brief: despliegue de submenú
 param: void
 return: parametro elegido
 * */
int subMenu();
/*
 brief: ingreso del precio de aerolineas
 param: float precio de aerolineas
 return: float precio de aerolineas
 * */
float precioAerolineas(float aerolineas);
/*
 brief: ingreso del precio de latam
 param: float precio de latam
 return: float precio de latam
 * */
float precioLatam(float latam);
/*
 brief: descuento por pagar con tarjeta de debito
 param: float con el precio total
 return: float con el descuento aplicado
 * */
float tarjetaDebito(float descuento);
/*
 brief: interes por pagar con tarjeta de credito
 param: float con el precio total
 return: float con el interes aplicado
 * */
float tarjetaCredito(float interes);
/*
 brief: precio de un producto en bitcoin
 param: float con el precio total
 return: float del valor del producto en bitcoin
 * */
float precioBitcoin(float bitcoin);

#endif /* FUNCIONES_H_ */
