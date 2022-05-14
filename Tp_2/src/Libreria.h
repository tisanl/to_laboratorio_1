/*
 * Libreria.h
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#ifndef LIBRERIA_H_
#define LIBRERIA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENNAME 51

typedef struct
{
    int id;
    char name[LENNAME];
    char lastName[LENNAME];
    float price;
    char flyCode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;

}passenger;

typedef struct
{
    char destino[20];
    char code[15];
    float precio;
    char statusFlight[15];
    int numeroStatusFlight;

}codigoVuelo;

typedef struct
{
    char clase[20];
    int numeroClave;
    float precio;
}tipoPasajero;


#endif /* LIBRERIA_H_ */

//FUNCION QUE DESPLIEGA EL MENU Y VALIDA LA OPCION
/** \brief
 *
 * \return int
 *
 */
int menu();

//FUNCION initPassengers tal cual esta descripta en el tp
/** \brief
 *
 * \param passenger[]
 * \param int
 * \return int
 *
 */
int initPassengers(passenger[], int );

//FUNCION addPassenger (no entendi como pasarle todos esos valores a la vez pasando el array, con que objetivo, no encontre utilidad ni como hacerlo)
/** \brief
 *
 * \param passenger[]
 * \param int
 * \param int*
 * \return int
 *
 */
int addPassenger(passenger[], int, int*);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \param int
 * \return int
 *
 */
int findPassengerById(passenger[], int, int);

/** \brief
 *
 * \param int*
 * \return void
 *
 */
void pedirId(int*);

//MODIFICACION DE PASAJERO
/** \brief
 *
 * \param passenger[]
 * \param int
 * \param int
 * \return void
 *
 */
void modifyPassenger(passenger[], int, int);

/** \brief
 *
 * \return int
 *
 */
int subMenuModify(); //SUB MENU DEL MENU DE MODIFICACION

//BAJA DE PASAJERO
/** \brief
 *
 * \param passenger[]
 * \param int
 * \param int
 * \return void
 *
 */
void removePassenger(passenger[], int, int);

//HARDCODEO Y MUESTRA EN PANTALLA DE PASAJEROS TIPOS Y CODIGOS DE VUELO
/** \brief
 *
 * \param codigoVuelo[]
 * \param int
 * \return void
 *
 */
void hardcodeoCodigoVuelo(codigoVuelo[], int);

/** \brief
 *
 * \param codigoVuelo[]
 * \param int
 * \return void
 *
 */
void mostrarVuelos(codigoVuelo[], int);

/** \brief
 *
 * \param tipoPasajero[]
 * \param len
 * \return void
 *
 */
void hardcodeoTipoPasajero(tipoPasajero[], int);

/** \brief
 *
 * \param tipoPasajero[]
 * \param int
 * \return void
 *
 */
void mostrarTipoPasajero(tipoPasajero[], int);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \return void
 *
 */
void mostrarPasajeroUnico(passenger[], int);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \return void
 *
 */
void mostrarPasajeros(passenger[], int);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \param codigoVuelo[]
 * \param char[]
 * \param char[]
 * \param int
 * \return void
 *
 */
void mostrarDestinoYEstado(passenger[], int, codigoVuelo[],char[], char[], int);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \param tipoPasajero[]
 * \param char[]
 * \param int
 * \return void
 *
 */
void mostrarType(passenger[], int, tipoPasajero[],char[], int);

/** \brief
 *
 * \param passenger[]
 * \param int*
 * \return void
 *
 */
void hardcodearEmpleados(passenger[],int*);

// VALIDACIONES PARA HACER LAS FUNCIONES
/** \brief
 *
 * \param passenger[]
 * \param int
 * \return int
 *
 */
int preguntarSiHayLugar(passenger[], int);

/** \brief
 *
 * \param passenger[]
 * \param int
 * \return int
 *
 */
int preguntarSiHayCargado(passenger[], int);

//INFORMES
/** \brief
 *
 * \param passenger[]
 * \param int
 * \return int
 *
 */
int sortPassengers(passenger[], int); //INFORME 1

/** \brief
 *
 * \param passenger[]
 * \param int
 * \param int
 * \return void
 *
 */
void acomodar(passenger[], int, int); //SWITCH

/** \brief
 *
 * \param passenger[]
 * \param int
 * \return void
 *
 */
void informarPrecio(passenger[], int); //INFORME 2

/** \brief
 *
 * \param passenger[]
 * \param int
 * \return int
 *
 */
int sortPassengersByCode(passenger[], int); //INFORME 3

/** \brief
 *
 * \return int
 *
 */
int subMenuInforme();//SUBMENU DE LA OPCION INFORMES

/** \brief
 *
 * \param char*
 * \return void
 * sirve para pedir la y en casos en lo que se necesita una confirmacion del usuario para repetir o salir
 */
void salirDelPrograma(char*);

//FUNCIONES QUE EN EN CONJUNTO SIRVEN PARA VALIDAR CUANDO SE PIDA UNA STRING

/** \brief
 *
 * \param char[]
 * \param int
 * \return int
 *
 */
int pedirYValidarString(char[], int);

/** \brief
 *
 * \param char[]
 * \return int
 *
 */
int validarTodoAlpha(char[]);

/** \brief
 *
 * \param int
 * \return void
 *
 */
void whyInvalidString(int);

// FUNCIONES QUE SIRVEN PARA PEDIR NUMEROS

/** \brief
 *
 * \param int*
 * \param int
 * \param int
 * \return int
 *
 */
int pedirNumeroConRango(int*, int, int);  //FUNCION EN LA QUE HAY QUE PEDIR UN NUMERO ENTRE UN RANGO

/** \brief
 *
 * \param int*
 * \param int
 * \param int
 * \return int
 *
 */
int pedirNumeroConRangoMenu(int*, int, int); //FUNCION EN LA QUE HAY QUE PEDIR UN NUMERO ENTRE UN RANGO PERO CON EL ADICIONAL DE LA SALIDA DEL MENU

/** \brief
 *
 * \param int*
 * \param int
 * \return int
 *
 */
int pedirNumeroMenorToInfinito(int*, int); //FUNCION EN LA QUE HAY QUE PEDIR UN NUMERO ENTRE 0 A INFINITO


