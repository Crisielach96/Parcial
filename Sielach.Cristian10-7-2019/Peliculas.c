#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include "validaciones.h"
#include "Peliculas.h"
#include "LinkedList.h"

ePelicula* newPelicula()
{
	//Creo un puntero del tipo estructura
    ePelicula* pPelicula=NULL;

	//Asigno espacio en memoria
    pPelicula = (ePelicula*)malloc(sizeof(ePelicula)); //casteo

	//retorna el puntero
    return pPelicula;
}

int pelicula_cargarPelicula(ePelicula* pPelicula, char* auxId, char* auxNombre, char* auxAnio,
                                     char* auxGenero)
{
    int retorno = 0;//no cargo
    int id;
    int anio;

    //compruebo que el puntero no sea null
    if(pPelicula != NULL)
    {

        id = atoi(auxId);
        anio = atoi(auxAnio);

        //Seteo los datos en la estructura
        pelicula_setId(pPelicula,id);
        pelicula_setNombre(pPelicula,auxNombre);
        pelicula_setAnio(pPelicula,anio);
        pelicula_setGenero(pPelicula,auxGenero);

        retorno = 1;//cargó
    }

    return retorno;
}


int pelicula_setId(ePelicula* pAuxEstructura, int id)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id = id;

		retorno = 1;
	}

    return retorno;
}

int pelicula_setNombre(ePelicula* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre, nombre);

		retorno = 1;
	}

    return retorno;
}


int pelicula_setAnio(ePelicula* pAuxEstructura, int anio)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->anio = anio;

		retorno = 1;
	}

    return retorno;
}

int pelicula_setGenero(ePelicula* pAuxEstructura, char* genero)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->genero, genero);

		retorno = 1;
	}

    return retorno;
}

void pelicula_mostrarLista(LinkedList* listaPeliculas)
{
    int i;

    ePelicula* pPelicula;


    for(i = 0; i < ll_len(listaPeliculas); i++)
    {
        pPelicula = (ePelicula*)ll_get(listaPeliculas, i);

        printf("Pelicula: %d - %s - %d - %s\n", pPelicula->id, pPelicula->nombre, pPelicula->anio, pPelicula->genero);


    }
}
