/*
 ============================================================================
 Name        : Tp_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Libreria.h"

#define LEN 2000
#define LENNAME 51



int main()
{
	setbuf(stdout, NULL);
    char confirm = 'n';
    passenger listaPasajeros[LEN];
    int id = 1000;
    int arrayEncontrado;
    int idPedido;
    int cant;
    char confirmacion = 'y';

    if((initPassengers(listaPasajeros, LEN)) == 0)
    {
        do
        {
            switch(menu())
            {
                case 1:
                    cant = preguntarSiHayLugar(listaPasajeros, LEN);
                    if(cant == 1)
                    {
                        addPassenger(listaPasajeros, LEN, &id);
                    }
                    else
                    {
                        printf("\n");
                        printf("No hay lugar en la base.\n");
                        system("pause");
                    }
                    break;
                case 2:
                    //modificar
                    cant = preguntarSiHayCargado(listaPasajeros,LEN);
                    if(cant == 1)
                    {
                        mostrarPasajeros(listaPasajeros, LEN);
                        pedirId(&idPedido);
                        arrayEncontrado = findPassengerById(listaPasajeros, LEN, idPedido);
                        if(arrayEncontrado == -1)
                        {
                            printf("\n");
                            printf("El id no tiene ningun pasajero asociado.\n\n");
                        }
                        else
                        {
                            modifyPassenger(listaPasajeros, LEN, arrayEncontrado);
                        }
                    }
                    else
                    {
                        printf("\n");
                        printf("No hay cargado ningun pasajero en el sistema\n\n");
                    }

                    system("pause");
                    break;
                case 3: //dar de baja
                    do
                    {
                        cant = preguntarSiHayCargado(listaPasajeros,LEN);
                        if(cant == 1)
                        {
                            mostrarPasajeros(listaPasajeros, LEN);
                            pedirId(&idPedido);
                            arrayEncontrado = findPassengerById(listaPasajeros, LEN, idPedido);
                            if(arrayEncontrado == -1)
                            {

                                printf("\n");
                                printf("El id no tiene ningun pasajero asociado.\n\n");
                                printf("Desea cargar otra baja? Presion 'Y' para confirmar o otra tecla para volver al menu: ");
                                salirDelPrograma(&confirmacion);
                            }
                            else
                            {
                                removePassenger(listaPasajeros, LEN, arrayEncontrado);
                                printf("Desea cargar otra baja? Presion 'Y' para confirmar o otra tecla para volver al menu: ");
                                salirDelPrograma(&confirmacion);
                            }
                        }
                        else
                        {
                            printf("\n");
                            printf("No hay cargado ningun pasajero en el sistema\n\n");
                        }
                    }while(confirmacion == 'y');
                    system("pause");
                    break;
                case 4:
                    cant = preguntarSiHayCargado(listaPasajeros,LEN);
                    if(cant == 1)
                    {
                        do
                        {
                            switch(subMenuInforme())
                            {
                                case 1:
                                    sortPassengers(listaPasajeros, LEN);
                                    mostrarPasajeros(listaPasajeros, LEN);
                                    printf("Desea cargar otro informe? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
                                    salirDelPrograma(&confirmacion);
                                    break;
                                case 2:
                                    informarPrecio(listaPasajeros, LEN);
                                    printf("\n");
                                    printf("Desea cargar otro informe? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
                                    salirDelPrograma(&confirmacion);
                                    break;
                                case 3:
                                    sortPassengersByCode(listaPasajeros, LEN);
                                    mostrarPasajeros(listaPasajeros, LEN);
                                    printf("Desea cargar otro informe? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
                                    salirDelPrograma(&confirmacion);
                                    break;
                                default:
                                    printf("\n");
                                    printf("Desea salir al menu? Teclee 'Y' para confirmar o cualquier otra tecla para cancelar: ");
                                    salirDelPrograma(&confirmacion);
                                    if(confirmacion == 'y')
                                    {
                                        confirmacion = 'n';
                                    }
                            }
                        }while(confirmacion == 'y');
                    }
                    else
                    {
                        printf("\n");
                        printf("No hay cargado ningun pasajero en el sistema\n\n");
                    }
                    system("pause");
                    break;
                case 5:
                    hardcodearEmpleados(listaPasajeros, &id);
                    printf("Se han hardcodeado 10 pasajeros\n\n");
                    system("pause");
                    break;
                case 6:
                    printf("Desea salir del programa? Teclee 'Y' para confirmar o cualquier otra tecla para volver al menu: ");
                    salirDelPrograma(&confirm);
                    break;
                default:
                    confirm = 'y';
            }
        }while(confirm != 'y');
    }

    printf("\nHasta luego!!\n\n");
    system("pause");

    return 0;
}
