#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[11];
	char nombre[25];
	char apellido[25];
	char precio[32];
	char flycode[20];
	char typePassenger[15];
	char statusFlight[15];

	pFile = fopen("data.csv", "r");
	if(pasajeros == NULL)
	{
		printf("No se pudo abrir el archivo\n");
		exit(1);
	}
	while
	{
		fscanf(pasajeros, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n");
	}

    return 1;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
