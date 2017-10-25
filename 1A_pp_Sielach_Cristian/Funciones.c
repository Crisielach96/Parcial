#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"


int menu()
{
    int opcion;
    system("cls");
    printf("1- Alta Cliente\n");
    printf("2- Modificar numero de tarjeta\n");
    printf("3- Ingreso de auto\n");
    printf("4- Egreso de auto\n");
    printf("5- Mostrar\n");
    printf("6- Salir\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int buscarLibre(eCliente lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int buscarLibreAuto(eAuto lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int buscarClientePorId(int id,eCliente lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].idDuenio==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

void variablesCero(eCliente lista[],int i)
{
    lista[i].idDuenio=0;
    strcpy(lista[i].nombre,"\0");
    strcpy(lista[i].apellido,"\0");
    strcpy(lista[i].direccion,"\0");
    lista[i].numeroTarjeta=0;
    lista[i].estado=0;
    lista[i].numeroTarjeta=0;
}

void variablesCeroAuto(eAuto lista[],int i)
{
    lista[i].estado=0;
}

void inicializarVariables(eCliente lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCero(lista,i);
    }
}

void inicializarVariablesAutos(eAuto lista[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        variablesCeroAuto(lista,i);
    }
}

void alta(eCliente lista[],int tam)
{
    eCliente nuevoCliente;
    int lugar;

    lugar=buscarLibre(lista,tam);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\nIngrese nombre: ");
        fflush(stdin);
        gets(nuevoCliente.nombre);
        printf("\nIngrese apellido: ");
        fflush(stdin);
        gets(nuevoCliente.apellido);
        printf("\nIngrese direccion: ");
        fflush(stdin);
        gets(nuevoCliente.direccion);
        printf("\nIngrese Numero de Tarjeta: ");
        scanf("%ld",&nuevoCliente.numeroTarjeta);
        nuevoCliente.estado=1;
        nuevoCliente.idDuenio=lugar;

    }
    lista[lugar]=nuevoCliente;
}

void altaAuto(eAuto lista[],int tamA,eCliente cliente[],int tamC)
{
    eAuto nuevoAuto;
    int lugar;
    int id;
    int esta;

    lugar=buscarLibreAuto(lista,tamA);

    if(lugar==-1)
    {
        printf("No hay lugar!\n");
    }
    else
    {
        printf("\nIngrese ID del Duenio: ");
        scanf("%d",&id);
        esta=buscarClientePorId(id,cliente,tamC);

        if(esta!=-1)
        {
            mostrarCliente(cliente[esta]);
            nuevoAuto.duenio=id;
            printf("\n\nIngrese Patente: ");
            fflush(stdin);
            gets(nuevoAuto.patente);
            printf("\nIngrese Marca del auto \n1-Alfa Romeo\n2-Ferrari\n3-Audi\n4-Otro\n");
            scanf("%d",&nuevoAuto.marca);
            printf("\nIngrese hora de entrada: ");
            scanf("%d",&nuevoAuto.horaEntrada);
            while(nuevoAuto.horaEntrada<0 || nuevoAuto.horaEntrada>24)
            {
                printf("\nError! hora incorrecta.");
                printf("\nReingrese: ");
                scanf("%d",&nuevoAuto.horaEntrada);
            }
            nuevoAuto.estado=1;
        }
        else
        {
            printf("La ID no existe.");
        }
    }
    lista[lugar]=nuevoAuto;
}

void harcCliente(eCliente lista[],int tam)
{
    int i;
    int idDuenio[]= {0,1,2,3};
    char nombre[][20]= {"Raul","Jorge","Manuel","Miguel"};
    char apellido[][20]= {"Gomez","Lopez","Campos","Rojas"};
    char direccion[][50]= {"Rodolfo Lopez 123","Mitre 124","Garibaldi 125","Alem 126"};
    long int numeroTarjeta[]= {40080379,39621487,36987123,37693481};
    int estado[]= {1,1,1,1};

    for(i=0; i<tam; i++)
    {
        lista[i].idDuenio=idDuenio[i];
        strcpy(lista[i].direccion,direccion[i]);
        strcpy(lista[i].nombre,nombre[i]);
        strcpy(lista[i].apellido,apellido[i]);
        lista[i].numeroTarjeta=numeroTarjeta[i];
        lista[i].estado=estado[i];
    }
}

void mostrarCliente(eCliente lista)
{
    printf("    %d    \t%s",lista.idDuenio,lista.nombre);
}

void mostrarAuto(eAuto lista)
{
    char mac[20];

    if(lista.marca==1)
    {
        strcpy(mac,"Alfa Romeo");
    }
    else if(lista.marca==2)
    {
        strcpy(mac,"Ferrari");
    }
    else if(lista.marca==3)
    {
        strcpy(mac,"Audi");
    }
    else
    {
        strcpy(mac,"Otro");
    }

    printf("%s    \t%s              \t%d",mac,lista.patente,lista.horaEntrada);
}

void mostrarClientes(eCliente lista[], int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrarCliente(lista[i]);
            flag=1;
        }
    }

    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void mostrarClientesAutos(eCliente lista[], int tamC,eAuto autos[],int tamA)
{
    int i,j;
    int flag=0;

    printf("Marca    \tPatente    \tHora de entrada      \tID    \tNombre\n");
    printf("----------------------------------------------------------------------\t\n");
    for(i=0; i<tamA; i++)
    {
        if(autos[i].estado==1)
        {
            for(j=0; j<tamC; j++)
            {
                if(lista[j].estado==1)
                {
                    if(autos[i].duenio==lista[j].idDuenio)
                    {
                        mostrarAuto(autos[i]);
                        printf("           ");
                        mostrarCliente(lista[j]);
                        printf("\n");
                        flag=1;
                    }
                }

            }

        }
    }
    printf("----------------------------------------------------------------------\t\n");

    if(flag==0)
    {
        printf("\nNo hay datos cargados en el sistema");
    }
}

void ordenar(eAuto autos[],int tamA)
{
    int i,j;
    eAuto auxA;

    for(i=0; i<tamA-1; i++)
    {
        for(j=i+1; j<tamA; j++)
        {
            if(autos[i].estado==1 && autos[j].estado==1)
            {
                if(autos[i].horaEntrada>autos[j].horaEntrada)
                {
                    auxA=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxA;
                }
                else
                {
                    if(autos[j].horaEntrada==autos[i].horaEntrada)
                    {
                        if(strcmp(autos[i].patente,autos[j].patente)>0)
                        {
                            auxA=autos[i];
                            autos[i]=autos[j];
                            autos[j]=auxA;
                        }


                    }
                }
            }
        }
    }
}
void harcAuto(eAuto autos[],int tam)
{
    char patente[][4]= {{"das"},{"des"},{"asd"},{"bod"}};
    int marca[]= {3,2,3,1};
    int duenio[]= {2,0,1,3};
    int horaEntrada[]= {12,21,21,15};
    int estado[]= {1,1,1,1};

    int i;

    for(i=0; i<tam; i++)
    {
        strcpy(autos[i].patente,patente[i]);
        autos[i].marca=marca[i];
        autos[i].duenio=duenio[i];
        autos[i].horaEntrada=horaEntrada[i];
        autos[i].estado=estado[i];
    }

}

void modificacion(eCliente lista[],int tam)
{
    int esta;
    int id;
    char respuesta='n';

    printf("\ningrese ID: ");
    scanf("%d",&id);
    esta=buscarClientePorId(id,lista,tam);

    if(esta!=-1)
    {
        mostrarCliente(lista[esta]);
        printf("\nDesea modificar esta entrada: S/N\n");
        fflush(stdin);
        respuesta=getch();
        if(respuesta=='s')
        {
            printf("\nIngrese Nuemero de tarjeta: ");
            scanf("%ld",&lista[esta].numeroTarjeta);
            printf("\nModificacion con exito");
        }
        if(respuesta=='n')
        {
            printf("accion cancelada.\n");
        }
    }
    else
    {
        printf("\nNo se ha encontrado el ID.");

    }
}

int buscarAutoId(int id,eAuto lista[],int tam)
{
    int i;
    int flag=-1;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1 && lista[i].duenio==id)
        {
            flag=i;
            break;
        }
    }
    return flag;
}

int bajaAuto(eCliente lista[],int tamC,eAuto autos[],int tamA,int gananciaXmarca[])
{
    char respuesta='n';
    int aux, auxHora;
    int total=0,id;
    int i;

    printf("Ingrese ID para darle de baja: ");
    scanf("%d",&id);
    aux=buscarAutoId(id,autos,tamA);

    if(aux!=-1)
    {
        printf("\n");
        mostrarAuto(autos[aux]);
        printf("\n");
        printf("\nDesea darle de baja a este objeto? s/n");
        fflush(stdin);
        respuesta=getch();

        if(respuesta=='s')
        {
            autos[aux].estado=0;
            printf("\n\ningrese hora de salida: ");
            scanf("%d",&auxHora);

            if(auxHora<autos[aux].horaEntrada)
            {
                printf("\n\nReingrese hora de salida: ");
                scanf("%d",&auxHora);
            }

            auxHora=auxHora-autos[aux].horaEntrada;

            if(autos[aux].marca==1)
            {
                total=auxHora*150;
                gananciaXmarca[0]+=total;
            }
            if(autos[aux].marca==2)
            {
                total=auxHora*175;
                gananciaXmarca[1]+=total;
            }
            if(autos[aux].marca==3)
            {
                total=auxHora*200;
                gananciaXmarca[2]+=total;
            }
            if(autos[aux].marca==4)
            {
                total=auxHora*250;
                gananciaXmarca[3]+=total;
            }

            printf("\nBaja exitosa!!!\n\n");

            for(i=0; i<tamC; i++)
            {
                if(autos[aux].duenio==lista[i].idDuenio)
                {
                    printf("\n\t                              **TICKET**\n\n\n");
                    printf("Marca    \tPatente    \tHora de entrada      \tID    \tNombre      Precio\n");
                    printf("----------------------------------------------------------------------------------\t\n");
                    mostrarAuto(autos[aux]);
                    printf("           ");
                    mostrarCliente(lista[i]);
                    printf("       %d",total);
                }
            }

        }
        else
        {
            printf("\nAccion CANCELADA, no se dio de baja al objeto \n");
        }
    }
    return total;
}

void maxCantAutos(eCliente lista[],int tamC,eAuto autos[],int tamA)
{
    int i,j;

    printf("Marca    \tPatente    \tHora de entrada      \tID    \tNombre\n");
    printf("----------------------------------------------------------------------\t\n");
    for(i=0; i<tamA; i++)
    {
        for(j=0; j<tamC; j++)
        {
            if(autos[i].marca==3 && autos[i].estado==1 && lista[j].idDuenio==autos[i].duenio && lista[j].estado==1)
            {

                mostrarAuto(autos[i]);
                printf("           ");
                mostrarCliente(lista[j]);
                printf("\n");
            }
        }
    }
}
