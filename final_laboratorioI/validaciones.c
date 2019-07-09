#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "validaciones.h"
#define TAM_BUFFER 30 //ultimo elemento se reemplaza por /0


int esInt(char* auxiliar)
{
    int i;
    int flag=1;//1 es entero
    int contadorNegativo=0;//cuenta los '-'

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(*(auxiliar+i)<'0' || *(auxiliar+i)>'9')
        {
            if(*(auxiliar+i)=='-')
            {
                contadorNegativo++;
            }


            if(contadorNegativo>1 || *(auxiliar+i)!='-')
            {
                flag=0;//No es numero entero
                break;
            }
        }
    }

    return flag;
}

int esFloat(char* auxiliar)
{
    int i;
    int flag=1;//1 es entero
    int contadorPunto=0;
    int contadorNegativo=0;

    for(i=0; i<strlen(auxiliar); i++)
    {
        if(*(auxiliar+i)<'0' || *(auxiliar+i)>'9')
        {
            if(*(auxiliar+i)=='.')
            {
                contadorPunto++;
            }

            if(*(auxiliar+i)=='-')
            {
                contadorNegativo++;
            }

            if((*(auxiliar+i)!='.' && *(auxiliar+i)!='-')
                    || (contadorPunto>1 || contadorNegativo>1))
            {

                flag=0;
                break;
            }
        }
    }

    return flag;
}


int esLetra(char* auxiliar)
{
    int i;
    int flag=1;//1 es char

    for(i=0;i<strlen(auxiliar);i++)
    {
        if((*(auxiliar+i)!=' ') && (*(auxiliar+i)<'A' || *(auxiliar+i)>'Z') && (*(auxiliar+i)<'a' || *(auxiliar+i)>'z')) //Si hay espacio tambien es valido como letra
        {
            flag=0;//0 no es char
            break;
        }
    }

    return flag;
}

//Pido al usuario
int pedirCadenaLetras(char* mensaje, char* cadena)
{
    int flag=0;//No cargo
    char* auxiliar;

    if(cadena!=NULL)
    {
        auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

        cargarCadena(mensaje, auxiliar);

        while(esLetra(auxiliar)!=1)
        {
            printf("Error. No es valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        strcpy(cadena, auxiliar);


        if(stricmp(cadena, auxiliar)==0)
        {
            flag=1;//Cargo la cadena
        }

        free(auxiliar);

    }

    return flag;

}

int pedirCadenaInt(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    int numeroAuxiliar;

    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esInt(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        numeroAuxiliar=atoi(auxiliar);//*Tomo el valor

        if(numeroAuxiliar>=minimo && numeroAuxiliar<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);

    free(auxiliar);


    return numeroAuxiliar;

}

float pedirCadenaFloat(char* mensaje, int minimo, int maximo)
{
    int flag=0;//No esta cargado
    char* auxiliar;
    float numeroAuxiliar;


    auxiliar=(char*)malloc(sizeof(char)*TAM_BUFFER);

    do
    {
        cargarCadena(mensaje, auxiliar);

        while(esFloat(auxiliar)!=1)
        {
            printf("Error. No es un numero valido.\n");
            cargarCadena(mensaje, auxiliar);
        }

        numeroAuxiliar=atof(auxiliar);//*Tomo el valor

        if(numeroAuxiliar>=minimo && numeroAuxiliar<=maximo)
        {
            flag=1;//Cumple con las condiciones. Sale de la iteracion.
        }
        else
        {
            printf("Fuera de rango.\n");
        }


    }while(flag==0);

    free(auxiliar);


    return numeroAuxiliar;

}

//Carga la cadena
int cargarCadena(char* mensaje, char* cadena)
{
    int flag=0;//No está cargada

    if(cadena!=NULL)
    {

        printf("%s: ", mensaje);
        fflush(stdin);

        //Para no escribir de más en memoria uso fgets
        //(limita lo que se puede ingresar)
        fgets(cadena,sizeof(char)*TAM_BUFFER,stdin);

        //Agregar '\0' al final cuando cadena < al buffer
        //para que pueda validar (porque fgets escribe '\n' al final)
        if(strlen(cadena)<TAM_BUFFER-1)
        {
            *(cadena+(strlen(cadena)-1))='\0';
        }


        if(strlen(cadena)>0)
        {
            flag=1;//Está cargada
        }
    }

    return flag;
}

void mostrarMenu()
{
    printf("---------------------------\n");
    printf("1-Alta ingrediente\n");
    printf("2-Modificacion ingrediente\n");
    printf("3-Baja de ingrediente\n");
    printf("4-Listar ingredientes\n");
    printf("5-Nueva receta\n");
    printf("6-Informar valor nutricional de la receta\n");
    printf("7-Salir\n");
    printf("---------------------------\n");

}
