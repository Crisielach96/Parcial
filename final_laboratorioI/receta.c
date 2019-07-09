#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include "validaciones.h"
#include "receta.h"
#include "ingrediente.h"
#include "LinkedList.h"

S_receta* newReceta()
{
	//Creo un puntero del tipo estructura
    S_receta* pReceta=NULL;

	//Asigno espacio en memoria
    pReceta = (S_receta*)malloc(sizeof(S_receta)); //casteo

	//retorna el puntero
    return pReceta;
}

int receta_cargarReceta(S_receta* pReceta, char* auxIdReceta, char* auxNombre, char* auxIdIngrediente,
                                     char* auxCantidad)
{
    int retorno = 0;//no cargo
    int id_receta;
    int id_ingrediente;
    float cantidad;

    //compruebo que el puntero no sea null
    if(pReceta != NULL)
    {

        id_receta = atoi(auxIdReceta);
        id_ingrediente = atoi(auxIdIngrediente);
        cantidad = atoi(auxCantidad);

        //Seteo los datos en la estructura
        receta_setIdReceta(pReceta, id_receta);
        receta_setNombre(pReceta, auxNombre);
        receta_setIdIngrediente(pReceta, id_ingrediente);
        receta_setCantidad(pReceta, cantidad);

        retorno = 1;//cargó
    }

    return retorno;
}


int receta_setIdReceta(S_receta* pAuxEstructura, int id_receta)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id_receta = id_receta;

		retorno = 1;
	}

    return retorno;
}

int receta_setNombre(S_receta* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre, nombre);

		retorno = 1;
	}

    return retorno;
}


int receta_setIdIngrediente(S_receta* pAuxEstructura, int id_ingrediente)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id_ingrediente = id_ingrediente;

		retorno = 1;
	}

    return retorno;
}

int receta_setCantidad(S_receta* pAuxEstructura, int cantidad)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->cantidad = cantidad;

		retorno = 1;
	}

    return retorno;
}

int receta_nuevaReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes)
{
    int retorno = 0;//no cargo
    char nombreReceta[100];
    char nombreIngrediente[60];
    int cantidad;
    int id_ingrediente= -1;
    char respuesta;

    S_receta* pAuxNuevaReceta;

    if(listaIngredientes != NULL)
    {
        pAuxNuevaReceta = newReceta();

        //agregarid
        pedirCadenaLetras("\nNombre de la receta", nombreReceta);
        do
        {


            pedirCadenaLetras("Nombre del ingrediente", nombreIngrediente);

            id_ingrediente = ingrediente_buscarIngredientePorNombre(listaIngredientes, nombreIngrediente);

            if(id_ingrediente != -1) //esta el ingrediente
            {
                cantidad = pedirCadenaInt("Cantidad", 0, 9999);
                receta_setIdReceta(pAuxNuevaReceta, ll_len(listaRecetas)+1);
                receta_setNombre(pAuxNuevaReceta, nombreReceta);
                receta_setIdIngrediente(pAuxNuevaReceta, id_ingrediente);
                receta_setCantidad(pAuxNuevaReceta, cantidad);

                ll_add(listaRecetas, pAuxNuevaReceta);

                retorno = 1;

            }
            else
            {
                printf("No se encontro el ingrediente.\n");
            }

            printf("\nDesea ingresar otro ingrediente(s/n)\n");
            fflush(stdin);
            respuesta = getche();

        }while(respuesta != 'n');


    }

    return retorno;
}


void receta_mostrarReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes)
{
    int i;
    int j;
    int id_receta;


    S_ingrediente* pAuxIngrediente;
    S_receta* pAuxReceta;

    id_receta = pedirCadenaInt("Ingrese el id de la receta", 0, 9999);

    for(i = 0; i < ll_len(listaRecetas); i++)
    {
        pAuxReceta = (S_receta*)ll_get(listaRecetas, i);
        if(id_receta == pAuxReceta->id_receta)
        {
            for(j=0; j < ll_len(listaIngredientes); j++)
            {
                pAuxIngrediente = ll_get(listaIngredientes, j);

                if(pAuxReceta->id_ingrediente == pAuxIngrediente->id)
                {
                    printf("\n");
                    printf("Receta: %s\n", pAuxReceta->nombre);
                    printf("Valor nutricional:\n Nombre:%s\n Calorias:%d; Grasas:%f; Sodio:%d; Carbohidratos:%d; Proteinas%d\n",
                           ingrediente_getNombre(pAuxIngrediente), ingrediente_getCalorias(pAuxIngrediente), ingrediente_getGrasa(pAuxIngrediente), ingrediente_getSodio(pAuxIngrediente),
                           ingrediente_getCarbohidratos(pAuxIngrediente), ingrediente_getProteinas(pAuxIngrediente));
                    printf("\n");
                    break;
                }
            }

        }

    }

}

void receta_mostrarLista(LinkedList* listaRecetas)
{
    int i;

    S_receta* pAuxReceta;


    for(i = 0; i < ll_len(listaRecetas); i++)
    {
        pAuxReceta = (S_receta*)ll_get(listaRecetas, i);

        printf("Receta: %d;%s\n", pAuxReceta->id_receta, pAuxReceta->nombre);


    }
}
