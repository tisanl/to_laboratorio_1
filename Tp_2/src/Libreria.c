/*
 * Libreria.c
 *
 *  Created on: 14 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Libreria.h"

#define AUX 200

//FUNCION QUE DESPLIEGA EL MENU Y VALIDA LA OPCION
int menu()
{
    int opcion;

    system("cls");
    printf("===========================================================\n");
    printf("******************** MENU DE PASAJEROS ********************\n");
    printf("===========================================================\n\n");
    printf("Opcion 1: Alta de pasajero\n");
    printf("Opcion 2: Modificacion de pasajero\n");
    printf("Opcion 3: Baja de pasajero\n");
    printf("Opcion 4: Informar\n");
    printf("Opcion 5: Hardcodear\n");
    printf("Opcion 6: Salir\n\n");
    printf("Ingrese una opcion: ");
    pedirNumeroConRangoMenu(&opcion, 1, 6);

    return opcion;
}

//FUNCION initPassengers tal cual esta descripta en el tp
int initPassengers(passenger list[], int len)
{
    int todoOk = -1;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }

    return todoOk;
}

//FUNCION PARA DAR DE ALTA

//FUNCION addPassenger (no entendi como pasarle todos esos valores a la vez pasando el array, con que objetivo, no encontre utilidad ni como hacerlo)
int addPassenger(passenger list[], int len, int* id)
{
    int todoOk = -1;
    int cant;
    codigoVuelo vuelos[7];
    int numeroCodigo;
    tipoPasajero clase[3];
    int numeroTipo;
    float precio;
    char confirmacion = 'y';

    system("cls");

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len && confirmacion == 'y'; i++)
        {
            if(list[i].isEmpty == 1)
            {
                //Pedir name
                printf("\nIngrese el nombre del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].name, LENNAME);
                while(cant != 1)
                {
                    printf("Nombre");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].name, LENNAME);
                }

                //pedir LastName
                printf("Ingrese el apellido del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].lastName, LENNAME);
                while(cant != 1)
                {
                    printf("Apellido");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].lastName, LENNAME);
                }

                //pedir FlyCode
                printf("\n");
                hardcodeoCodigoVuelo(vuelos, 7);
                mostrarVuelos(vuelos, 7);
                printf("Ingrese el numero que corresponda al destino y codigo del vuelo del pasajero: ");
                pedirNumeroConRango(&numeroCodigo, 1, 7);
                numeroCodigo -= 1;
                strcpy(list[i].flyCode, vuelos[numeroCodigo].code);
                list[i].statusFlight = vuelos[numeroCodigo].numeroStatusFlight;
                precio = vuelos[numeroCodigo].precio;

                //pedir TypePassenger
                printf("\n");
                hardcodeoTipoPasajero(clase, 3);
                mostrarTipoPasajero(clase, 3);
                printf("Ingrese el numero que corresponda al tipo del pasajero: ");
                pedirNumeroConRango(&numeroTipo, 1, 3);
                numeroTipo -=1;
                list[i].typePassenger = clase[numeroTipo].numeroClave;
                precio += clase[numeroTipo].precio;
                list[i].price = precio;

                //Poner id
                list[i].id = *id;
                *id += 1;

                //poner isEmpty
                list[i].isEmpty = 0;

                mostrarPasajeroUnico(list, i);

                printf("\nDesea ingresar otro pasajero? Teclee 'y' para ingresar otro o cualquier otra tecla para salir: ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                confirmacion = tolower(confirmacion);

                todoOk = 0;
            }
        }
    }

    system("pause");

    return todoOk;
}

int findPassengerById(passenger list[], int len, int id)
{
    int array = -1;

    for(int i = 0;i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            array = i;
            printf("El pasajero ha sido encontrado.\n");
            break;
        }
    }

    return array;
}

void pedirId(int* id)
{
    printf("Ingrese el Id del pasajero que busca: ");
    pedirNumeroMenorToInfinito(id, 1000);
}

//MODIFICACION DE PASAJERO
void modifyPassenger(passenger list[], int len, int i)
{
    int cant;
    float precio;
    codigoVuelo vuelos[7];
    int numeroCodigo;
    int numeroTipo;
    tipoPasajero clase[3];
    char confirm = 'n';

    mostrarPasajeroUnico(list, i);
    do
    {
        system("cls");
        mostrarPasajeroUnico(list, i);
        switch(subMenuModify())
        {
            case 1:
                printf("\nIngrese el nombre del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].name, LENNAME);
                while(cant != 1)
                {
                    printf("Nombre");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].name, LENNAME);
                }
                break;
            case 2:
                printf("Ingrese el apellido del pasajero: "); //las funciones estan detalladas en cada una
                cant = pedirYValidarString(list[i].lastName, LENNAME);
                while(cant != 1)
                {
                    printf("Apellido");
                    whyInvalidString(cant);
                    cant = pedirYValidarString(list[i].lastName, LENNAME);
                }
                break;
            case 3:
                printf("Ingrese el precio del vuelo: ");
                fflush(stdin);
                cant = scanf("%f", &precio);
                while(cant == 0 || precio < 0)
                {
                    printf("Numero no valido. Ingrese un valor mayor a 0: ");
                    fflush(stdin);
                    cant = scanf("%f", &precio);
                }
                list[i].price = precio;
                break;
            case 4:
                hardcodeoTipoPasajero(clase, 3);
                mostrarTipoPasajero(clase, 3);
                printf("Ingrese el numero que corresponda al tipo del pasajero: ");
                pedirNumeroConRango(&numeroTipo, 1, 3);
                numeroTipo -=1;
                list[i].typePassenger = clase[numeroTipo].numeroClave;
                break;
            case 5:
                hardcodeoCodigoVuelo(vuelos, 7);
                mostrarVuelos(vuelos, 7);
                printf("Ingrese el numero que corresponda al destino y codigo del vuelo del pasajero: ");
                pedirNumeroConRango(&numeroCodigo, 1, 7);
                numeroCodigo -= 1;
                strcpy(list[i].flyCode, vuelos[numeroCodigo].code);
                list[i].statusFlight = vuelos[numeroCodigo].numeroStatusFlight;
                break;
        }
        printf("Ingrese 'Y' si quiere modificar otro dato o cualquier otra tecla para volver al menu: ");
        salirDelPrograma(&confirm);
    }while(confirm == 'y');
}

int subMenuModify() //SUB MENU DEL MENU DE MODIFICACION
{
    int opcion;

    printf("==============================================================\n");
    printf("******************** MENU DE MODIFICACION ********************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Modificar el nombre\n");
    printf("Opcion 2: Modificar el apellido\n");
    printf("Opcion 3: Modificar el precio del vuelo\n");
    printf("Opcion 4: Modificar el tipo de pasajero\n");
    printf("Opcion 5: Modificar el Codigo del vuelo\n");
    printf("Opcion 6: Salir\n\n");
    printf("Ingrese una opcion: ");
    pedirNumeroConRangoMenu(&opcion, 1, 6);

    return opcion;
}

//BAJA DE PASAJERO
void removePassenger(passenger list[], int len, int i)
{
    char confirmacionBaja;

    printf("\nDesea dar de baja al pasajero? Escriba 'Y' para confirmar la baja: ");
    fflush(stdin);
    scanf("%c", &confirmacionBaja);
    confirmacionBaja = tolower(confirmacionBaja);
    if(confirmacionBaja == 'y')
    {
        list[i].isEmpty = 1;
        printf("El pasajero se ha dado de baja con exito.\n\n");
    }
    else
    {
        printf("El pasajero no se ha dado de baja.\n\n");
    }
}

//HARDCODEO Y MUESTRA EN PANTALLA DE PASAJEROS TIPOS Y CODIGOS DE VUELO
void hardcodeoCodigoVuelo(codigoVuelo vuelo[], int len)
{
    codigoVuelo harcodeados[7]=
    {
        {"Nueva York", "TONYSTARK", 3000, "Activo", 1},
        {"Asgard", "THOR4", 4000, "Demorado", 2},
        {"Los Angeles", "LAN420", 2000, "Cancelado", 3},
        {"Texas", "ELONMUSK", 2700, "Activo", 1},
        {"Tokio", "JAP164", 1800, "Demorado", 2},
        {"Madrid", "DELAOSSA", 1000, "Activo", 1},
        {"Londres", "LON157", 1200, "Cancelado", 3}
    };

    for(int i = 0; i < len; i++)
    {
        strcpy(vuelo[i].destino, harcodeados[i].destino);
        strcpy(vuelo[i].code, harcodeados[i].code);
        strcpy(vuelo[i].statusFlight, harcodeados[i].statusFlight);
        vuelo[i].precio = harcodeados[i].precio;
    }
}

void mostrarVuelos(codigoVuelo vuelo[], int len)
{
    int numero;

    printf("===================================================\n");
    printf("Numero||Destino        ||Codigos    ||Estado       \n");
    printf("------||---------------||-----------||-------------\n");
    for(int i = 0; i < len; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s||", vuelo[i].destino);
        printf("%-11s||", vuelo[i].code);
        printf("%-11s\n", vuelo[i].statusFlight);
    }
    printf("===================================================\n");
    printf("\n");
}

void hardcodeoTipoPasajero(tipoPasajero clase[], int len)
{
    tipoPasajero harcodeados[3] =
    {
        {"Turista", 1, 500},
        {"Bussines", 2, 800},
        {"Primera Clase", 3, 1300, }
    };

    for(int i = 0; i < len; i++)
    {
        strcpy(clase[i].clase, harcodeados[i].clase);
        clase[i].numeroClave = harcodeados[i].numeroClave;
        clase[i].precio = harcodeados[i].precio;
    }
}

void mostrarTipoPasajero(tipoPasajero clase[], int len)
{
    int numero;

    printf("=======================\n");
    printf("Numero||Clase      \n");
    printf("------||---------------\n");
    for(int i = 0; i < len; i++)
    {
        numero = i+1;
        printf("%-6d||", numero);
        printf("%-15s\n", clase[i].clase);
    }
    printf("=======================\n");
    printf("\n");
}

void mostrarPasajeroUnico(passenger lista[], int i)
{


    system("cls");
    printf("============================================================================================\n");
    printf("    Nombre     ||    Apellido   ||   id   || Codigo de vuelo ||Tipo de pasajero||   Precio  \n");
    printf("---------------||---------------||--------||-----------------||----------------||-----------\n");
    printf("%15s||", lista[i].name);
    printf("%15s||", lista[i].lastName);
    printf("%8d||", lista[i].id);
    printf("%17s||", lista[i].flyCode);
    printf("%16d||", lista[i].typePassenger);
    printf("%11f\n", lista[i].price);
    //printf();
    printf("=============================================================================================\n");
    printf("\n");
}

void mostrarPasajeros(passenger list[], int len)
{
    codigoVuelo vuelo[7];
    tipoPasajero type[3];
    char stringTipo[15];
    char stringDestino[15];
    char stringEstado[15];

    hardcodeoCodigoVuelo(vuelo, 7);
    hardcodeoTipoPasajero(type, 3);
    system("cls");
    printf("=============================================================================================================================\n");
    printf("    Nombre     ||    Apellido   ||   id   ||  Destino  || Codigo de vuelo || Estado del vuelo ||Tipo de pasajero||   Precio  \n");
    printf("---------------||---------------||--------||-----------||-----------------||------------------||----------------||-----------\n");
    for(int i = 0; i < len && list[i].isEmpty == 0; i++)
    {
        printf("%15s||", list[i].name);
        printf("%15s||", list[i].lastName);
        printf("%8d||", list[i].id);
        mostrarDestinoYEstado(list, i, vuelo, stringDestino, stringEstado, 7);
        printf("%11s||", stringDestino);
        printf("%17s||", list[i].flyCode);
        printf("%18s||", stringEstado);
        mostrarType(list, i, type, stringTipo, 3);
        printf("%16s||", stringTipo);
        printf("%11.2f\n", list[i].price);
    }
    printf("==============================================================================================================================\n");
    printf("\n");

}

void mostrarDestinoYEstado(passenger list[], int j, codigoVuelo vuelo[],char destino[15], char estado[15], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(strcmp(vuelo[i].code, list[j].flyCode) == 0)
        {
            strcpy(destino, vuelo[i].destino);
            strcpy(estado, vuelo[i].statusFlight);
        }
    }
}

void mostrarType(passenger list[], int j, tipoPasajero type[],char clase[15], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(type[i].numeroClave == list[j].typePassenger)
        {
            strcpy(clase, type[i].clase);
        }
    }
}

void hardcodearEmpleados(passenger list[],int* id)
{
    passenger harcodeados[10] =
    {
        {1000, "Santiago", "Lopez", 3500, "DELAOSSA", 3, 3, 0},
        {1001, "Fernando", "Lopez", 2000, "TONYSTARK", 2, 2, 0},
        {1002, "Matias", "Rodriguez", 1000, "ELONMUSK", 1, 2, 0},
        {1003, "Mateo", "Holik", 2800, "THOR4", 3, 1, 0},
        {1004, "Facundo", "Graziano", 4000, "JAP164", 3, 3, 0},
        {1005, "Rodrigo", "Garofalo", 500, "THOR4", 3, 3, 0},
        {1006, "Tomas", "Germinario", 1700, "LAN420", 2, 1, 0},
        {1007, "Laura", "Perez", 600, "ELONMUSK", 1, 2, 0},
        {1008, "Maria", "Ramon", 2400, "DELAOSSA", 1, 1, 0},
        {1009, "Jimena", "Barba", 3200, "LON157", 2, 2, 0},
    };

    for(int i = 0; i < 10; i++)
    {
        strcpy(list[i].name, harcodeados[i].name);
        strcpy(list[i].lastName, harcodeados[i].lastName);
        strcpy(list[i].flyCode, harcodeados[i].flyCode);
        list[i].id = harcodeados[i].id;
        list[i].price = harcodeados[i].price;
        list[i].isEmpty = harcodeados[i].isEmpty;
        list[i].statusFlight = harcodeados[i].statusFlight;
        list[i].typePassenger = harcodeados[i].typePassenger;
    }

    *id += 10;
}

// VALIDACIONES PARA HACER LAS FUNCIONES
int preguntarSiHayLugar(passenger list[], int len)
{
   int vacio = 0;
   for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            vacio = 1;
            break;
        }
    }
    return vacio;
}

int preguntarSiHayCargado(passenger list[], int len)
{
   int ocupado = 0;
   for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            ocupado = 1;
            break;
        }
    }
    return ocupado;
}

//INFORMES
int sortPassengers(passenger list[], int len) //INFORME 1
{
    int orden;
    int cant;

    printf("\n");
    printf("Se mostraran los pasajeros ordenados por apellido y tipo de pasajero.\n");
    printf("Ingrese 1 para mostrarlos de manera ascendente o  2 para manera descendente: ");
    fflush(stdin);
    cant = scanf("%d", &orden);
    while(cant == 0 || (orden != 1 && orden != 2))
    {
        printf("Opcion no valida. Ingrese 1 o 2: ");
        fflush(stdin);
        cant = scanf("%d", &orden);
    }

    if(orden == 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(stricmp(list[i].lastName, list[j].lastName) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    acomodar(list, i, j);
                }
                if(stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0 &&
                   list[j].typePassenger > list[i].typePassenger)
                {
                    acomodar(list, i, j);
                }
            }
        }
    }
    if(orden == 2)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(stricmp(list[i].lastName, list[j].lastName) < 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    acomodar(list, i, j);
                }
                if(stricmp(list[i].lastName, list[j].lastName) == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0 &&
                   list[j].typePassenger > list[i].typePassenger)
                {
                    acomodar(list, i, j);
                }
            }
        }
    }

    return 0;
}

void acomodar(passenger list[], int i, int j) //SWITCH
{
    char auxcad[100];
    int auxNumero;
    float auxPrecio;

    //cambiar nombre
    strcpy(auxcad, list[i].name);
    strcpy(list[i].name, list[j].name);
    strcpy(list[j].name, auxcad);

    //cambiar apellido
    strcpy(auxcad, list[i].lastName);
    strcpy(list[i].lastName, list[j].lastName);
    strcpy(list[j].lastName, auxcad);

    //cambiar id
    auxNumero = list[i].id;
    list[i].id = list[j].id;
    list[j].id = auxNumero;

    //cambiar status flight
    auxNumero = list[i].statusFlight;
    list[i].statusFlight = list[j].statusFlight;
    list[j].statusFlight = auxNumero;

    //cambiar type passenger
    auxNumero = list[i].typePassenger;
    list[i].typePassenger = list[j].typePassenger;
    list[j].typePassenger = auxNumero;

    //cambiar precio
    auxPrecio = list[i].price;
    list[i].price = list[j].price;
    list[j].price = auxPrecio;

    //cambiar flycode
    strcpy(auxcad, list[i].flyCode);
    strcpy(list[i].flyCode, list[j].flyCode);
    strcpy(list[j].flyCode, auxcad);
}

void informarPrecio(passenger list[], int len) //INFORME 2
{
    float acumulador = 0;
    int contador = 0;
    float precioPromedio;
    int contadorSuperaPromedio = 0;

    for(int i = 0; i < len; i ++)
    {
        if(list[i].isEmpty == 0)
        {
            acumulador += list[i].price;
            contador ++;
        }
    }

    precioPromedio = acumulador / contador;

    for(int i = 0; i < len; i ++)
    {
        if(list[i].isEmpty == 0 && list[i].price > precioPromedio)
        {
            contadorSuperaPromedio ++;
        }
    }

    printf("\n");
    printf("El total del precio de los pasajes es: %.2f\n", acumulador);
    printf("El promedio del precio de los pasajes es: %.2f\n", precioPromedio);
    printf("La cantidad de pasajeros que abonan mas del precio promedio es: %d.\n", contadorSuperaPromedio);
}

int sortPassengersByCode(passenger list[], int len) //INFORME 3
{
    int orden;
    int cant;

    printf("\n");
    printf("Se mostraran los pasajeros ordenados por codigo de vuelo y estado.\n");
    printf("Ingrese 1 para mostrarlos de manera ascendente o  2 para manera descendente: ");
    fflush(stdin);
    cant = scanf("%d", &orden);
    while(cant == 0 || (orden != 1 && orden != 2))
    {
        printf("Opcion no valida. Ingrese 1 o 2: ");
        fflush(stdin);
        cant = scanf("%d", &orden);
    }

    if(orden == 1)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(stricmp(list[i].flyCode, list[j].flyCode) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    acomodar(list, i, j);
                }
                if(stricmp(list[i].flyCode, list[j].flyCode) == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0 &&
                   list[j].statusFlight > list[i].statusFlight)
                {
                    acomodar(list, i, j);
                }
            }
        }
    }
    if(orden == 2)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(stricmp(list[i].flyCode, list[j].flyCode) < 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    acomodar(list, i, j);
                }
                if(stricmp(list[i].flyCode, list[j].flyCode) == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0 &&
                   list[j].statusFlight > list[i].statusFlight)
                {
                    acomodar(list, i, j);
                }
            }
        }
    }

    return 0;
}

int subMenuInforme()//SUBMENU DE LA OPCION INFORMES
{
    int opcion;

    system("cls");
    printf("==============================================================\n");
    printf("******************** MENU DE INFORMES ************************\n");
    printf("==============================================================\n\n");
    printf("Opcion 1: Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero.\n");
    printf("Opcion 2: Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n");
    printf("Opcion 3: Listado de los pasajeros por codigo de vuelo y estados de vuelos ‘ACTIVO’\n");
    printf("Opcion 4: Salir\n\n");
    printf("Ingrese una opcion: ");
    pedirNumeroConRangoMenu(&opcion, 1, 4);

    return opcion;
}

void salirDelPrograma(char* confirm)
{
    fflush(stdin);
    scanf("%c", confirm);
    *confirm = tolower(*confirm);
}

int pedirYValidarString(char string[], int len)
{
    char auxCad[AUX];
    int alpha;
    int todoOk = 0; //retorna case 0 si es largo y hay caracteres invalidos

    fflush(stdin);
    gets(auxCad);
    alpha = validarTodoAlpha(auxCad);
    if(strlen(auxCad) < len && alpha == 1) //devuelve 1 si esta todo bien y guarda el cambio
    {
        todoOk = 1;
        strcpy(string, auxCad);
    }
    else if(strlen(auxCad) > len && alpha == 1) //retorna -1 si es muy larga
    {
        todoOk = -1;
    }
    else if(strlen(auxCad) < len && alpha == 0) //retorna -2 si hay cosas que no son numero
    {
        todoOk = -2;
    }

    return todoOk;
}

int validarTodoAlpha(char auxCad[])
{
    int todoOk = 1;
    int cant;
    for(int i = 0; i < AUX -1; i++)
    {
        cant = isalpha(auxCad[i]);
        if(auxCad[i] == '\0')
        {
            break;
        }
        else if(cant == 0 && auxCad[i] != 32)
        {
            todoOk = 0;
            break;
        }
    }

    return todoOk;
}

void whyInvalidString(int caso)
{
    switch(caso)
    {
        case -1:
            printf(" muy largo. Intente nuevamente: ");
            break;
        case -2:
            printf(" con caracteres no validos. Intente nuevamente: ");
            break;
        case 0:
            printf(" con caracteres no validos y muy largo. Intente nuevamente: ");
            break;
    }
}

int pedirNumeroConRango(int* numero, int menor, int mayor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    while(cant == 0 || *numero < menor || *numero > mayor)
    {
        printf("Opcion invalida. Ingrese un numero del %d al %d: ", menor, mayor);
        fflush(stdin);
        cant = scanf("%d", numero);
        todoOk = 1;
    }

    return todoOk;
}

int pedirNumeroConRangoMenu(int* numero, int menor, int mayor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    for(int i = 0; cant == 0 || *numero < menor || *numero > mayor; i++)
    {
        printf("Opcion invalida. Ingrese un numero del %d al %d: ",menor , mayor);
        fflush(stdin);
        cant = scanf("%d", numero);
        if(i == 7)
        {
            printf("\nHa realizado muchos intentos. Intente denuevo mas tarde.\n"
                   "Hasta luego\n\n");
            *numero = mayor +1;
            todoOk = 1;
            system("pause");
            break;
        }
    }

    return todoOk;
}

int pedirNumeroMenorToInfinito(int* numero, int menor)
{
    int cant;
    int todoOk = 0;

    fflush(stdin);
    cant = scanf("%d", numero);
    while(cant == 0 || *numero < menor)
    {
        printf("Opcion invalida. Ingrese un numero mayor a %d: ", menor);
        fflush(stdin);
        cant = scanf("%d", numero);
        todoOk = 1;
    }

    return todoOk;
}
