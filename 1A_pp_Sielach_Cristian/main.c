#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

#define cantClientes 10
#define cantAutos 10


int main()
{
    eCliente cliente[10];
    eAuto autos[10];
    inicializarVariablesAutos(autos,cantAutos);
    inicializarVariables(cliente,cantClientes);
    harcCliente(cliente,4);
    harcAuto(autos,4);

    int salir = 1,totalRecaudacion=0, gananciaMarca[]= {0,0,0,0};

    do
    {
        switch(menu())
        {

        case 1:
            system("cls");
            alta(cliente,cantClientes);
            getch();

            break;

        case 2:
            system("cls");
            modificacion(cliente,cantClientes);
            getch();

            break;
        case 3:
            system("cls");
            altaAuto(autos,cantAutos,cliente,cantClientes);
            getch();

            break;

        case 4:
            system("cls");
            totalRecaudacion+=bajaAuto(cliente,cantClientes,autos,cantAutos,gananciaMarca);
            getch();
            break;

        case 5:
            system("cls");
            ordenar(autos,cantAutos);
            mostrarClientesAutos(cliente,cantClientes,autos,cantAutos);
            getch();

            printf("\n\n");
            printf(" \nTodos los clientes con Audis. \n");
            maxCantAutos(cliente,cantClientes,autos,cantAutos);
            getch();

            printf("\n\n");
            printf(" \nGanancia por Marca \n\n");
            printf("ALPHA: $%d  FERRARI: $%d  AUDI: $%d  OTROS: $%d \n",gananciaMarca[0],gananciaMarca[1],gananciaMarca[2],gananciaMarca[3]);
            getch();

            printf("\n\n");
            printf(" \nRecaudacion del total del estacionamiento \n");
            printf("\nGanancias Totales: $%d",totalRecaudacion);
            getch();
            break;

        case 6:
            salir = 0;
            break;

        default:
            printf("Opcion Invalida!!\n");
            system("pause");
        }
    }
    while(salir);
    return 0;
}
