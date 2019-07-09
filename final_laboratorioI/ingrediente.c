#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "ingrediente.h"
#include "validaciones.h"
#include "receta.h"

S_ingrediente* newIngrediente()
{
	//Creo un puntero del tipo estructura
    S_ingrediente* pIngrediente=NULL;

	//Asigno espacio en memoria
    pIngrediente = (S_ingrediente*)malloc(sizeof(S_ingrediente)); //casteo

	//retorna el puntero
    return pIngrediente;
}

int ingrediente_cargarIngrediente(S_ingrediente* pIngrediente, char* auxId, char* auxNombre, char*auxCalorias,
                                     char* auxGrasa, char* auxSodio, char* auxCarbohidratos, char* auxProteinas)
{
    int retorno = 0;//no cargo
    int id;
    int calorias;
    float grasa;
    int sodio;
    int carbohidratos;
    int proteinas;

    //compruebo que el puntero no sea null
    if(pIngrediente != NULL)
    {

        id = atoi(auxId);
        calorias = atoi(auxCalorias);
        grasa = atof(auxGrasa);
        sodio= atoi(auxSodio);
        carbohidratos = atoi(auxCarbohidratos);
        proteinas = atoi(auxProteinas);
        //Seteo los datos en la estructura
        ingrediente_setId(pIngrediente, id);
        ingrediente_setNombre(pIngrediente, auxNombre);
        ingrediente_setCalorias(pIngrediente, calorias);
        ingrediente_setGrasa(pIngrediente, grasa);
        ingrediente_setSodio(pIngrediente, sodio);
        ingrediente_setCarbohidratos(pIngrediente, carbohidratos);
        ingrediente_setProteinas(pIngrediente, proteinas);

        retorno = 1;//cargó
    }

    return retorno;
}


int ingrediente_setId(S_ingrediente* pAuxEstructura, int id)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->id = id;

		retorno = 1;
	}

    return retorno;
}

int ingrediente_setNombre(S_ingrediente* pAuxEstructura, char* nombre)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		strcpy(pAuxEstructura->nombre, nombre);

		retorno = 1;
	}

    return retorno;
}

int ingrediente_setCalorias(S_ingrediente* pAuxEstructura, int calorias)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->calorias = calorias;

		retorno = 1;
	}

    return retorno;
}

float ingrediente_setGrasa(S_ingrediente* pAuxEstructura, float grasa)
{
	float retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->grasa = grasa;

		retorno = 1;
	}

    return retorno;
}

int ingrediente_setSodio(S_ingrediente* pAuxEstructura, int sodio)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->sodio = sodio;

		retorno = 1;
	}

    return retorno;
}

int ingrediente_setCarbohidratos(S_ingrediente* pAuxEstructura, int carbohidratos)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->carbohidratos = carbohidratos;

		retorno = 1;
	}

    return retorno;
}

int ingrediente_setProteinas(S_ingrediente* pAuxEstructura, int proteinas)
{
	int retorno = 0;

	if(pAuxEstructura != NULL)
	{
		pAuxEstructura->proteinas = proteinas;

		retorno = 1;
	}

    return retorno;
}

void ingrediente_mostrarListaIngredientes(LinkedList* listaIngredientes)
{
    int i;
    S_ingrediente* pAuxIngrediente;

    for(i = 0; i < ll_len(listaIngredientes); i++)
    {
        pAuxIngrediente = (S_ingrediente*)ll_get(listaIngredientes, i);

        printf("%d;%s;%d;%f;%d;%d;%d\n", ingrediente_getId(pAuxIngrediente), ingrediente_getNombre(pAuxIngrediente),
                ingrediente_getCalorias(pAuxIngrediente),ingrediente_getGrasa(pAuxIngrediente), ingrediente_getSodio(pAuxIngrediente),
                ingrediente_getCarbohidratos(pAuxIngrediente), ingrediente_getProteinas(pAuxIngrediente));
    }


}


///Getters
int ingrediente_getId(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->id;
    }

    return retorno;
}

char* ingrediente_getNombre(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente=NULL;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
    }


    return pAuxIngrediente->nombre;
}

int ingrediente_getCalorias(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->calorias;
    }

    return retorno;
}

float ingrediente_getGrasa(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    float retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->grasa;
    }

    return retorno;
}

int ingrediente_getSodio(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->sodio;
    }

    return retorno;
}

int ingrediente_getCarbohidratos(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->carbohidratos;
    }

    return retorno;
}

int ingrediente_getProteinas(void* pEstructura)
{
    S_ingrediente* pAuxIngrediente;
    int retorno;

    if(pEstructura!=NULL)
    {
        pAuxIngrediente=pEstructura;
        retorno=pAuxIngrediente->proteinas;
    }

    return retorno;
}

int ingrediente_ordenarIngrediente(void* ingredienteUno, void* ingredienteDos)
{
    //tengo que pasarlos a un auxiliar para utilizar el operador flecha
    S_ingrediente* pAuxIngredienteUno;
    S_ingrediente* pAuxIngredienteDos;

    pAuxIngredienteUno = (S_ingrediente*) ingredienteUno;
    pAuxIngredienteDos= (S_ingrediente*) ingredienteDos;

    int retorno = 0;

    if(stricmp(pAuxIngredienteUno->nombre,pAuxIngredienteDos->nombre)<0)
    {
        retorno = -1; //ordeno
    }
    else
    {
        if(stricmp(pAuxIngredienteUno->nombre, pAuxIngredienteDos->nombre)>0)
        {
            retorno = 1;//no ordeno
        }
    }

    return retorno;
}

int ingrediente_agregarIngrediente(LinkedList* listaIngredientes)
{
    int retorno = 0;//no cargo
    char nombre[60];
    int calorias;
    float grasa;
    int sodio;
    int carbohidratos;
    int proteinas;

    S_ingrediente* pAuxIngrediente;
    if(listaIngredientes != NULL)
    {
        pAuxIngrediente = newIngrediente();

        //agregarid
        pedirCadenaLetras("Nombre", nombre);
        calorias = pedirCadenaInt("Calorias", 0, 9999);
        grasa = pedirCadenaFloat("Grasa", 0, 999);
        sodio = pedirCadenaInt("Sodio", 0, 9999);
        carbohidratos = pedirCadenaInt("Carbohidratos", 0, 9999);
        proteinas = pedirCadenaInt("Proteinas", 0, 9999);

        ingrediente_setId(pAuxIngrediente, ll_len(listaIngredientes)+1);
        ingrediente_setNombre(pAuxIngrediente, nombre);
        ingrediente_setCalorias(pAuxIngrediente, calorias);
        ingrediente_setGrasa(pAuxIngrediente, grasa);
        ingrediente_setSodio(pAuxIngrediente, sodio);
        ingrediente_setCarbohidratos(pAuxIngrediente, carbohidratos);
        ingrediente_setProteinas(pAuxIngrediente, proteinas);

        ll_add(listaIngredientes, pAuxIngrediente);

        retorno = 1;
    }

    return retorno;
}

int ingrediente_modificarIngrediente(LinkedList* listaIngredientes)
{
    int id;
    int i;
    int retorno = 0;//no cargo
    char nombre[60];
    int calorias;
    float grasa;
    int sodio;
    int carbohidratos;
    int proteinas;

    S_ingrediente* pAuxIngrediente;

    id = pedirCadenaInt("Ingrese el id del ingrediente", 0, 100);

    for(i = 0; i < ll_len(listaIngredientes); i++)
    {
        pAuxIngrediente = (S_ingrediente*)ll_get(listaIngredientes, i);

        if(id == pAuxIngrediente->id)
        {
            pAuxIngrediente = (S_ingrediente*)ll_pop(listaIngredientes, i);

            pedirCadenaLetras("Nombre", nombre);
            calorias = pedirCadenaInt("Calorias", 0, 9999);
            grasa = pedirCadenaFloat("Grasa", 0, 999);
            sodio = pedirCadenaInt("Sodio", 0, 9999);
            carbohidratos = pedirCadenaInt("Carbohidratos", 0, 9999);
            proteinas = pedirCadenaInt("Proteinas", 0, 9999);

            ingrediente_setNombre(pAuxIngrediente, nombre);
            ingrediente_setCalorias(pAuxIngrediente, calorias);
            ingrediente_setGrasa(pAuxIngrediente, grasa);
            ingrediente_setSodio(pAuxIngrediente, sodio);
            ingrediente_setCarbohidratos(pAuxIngrediente, carbohidratos);
            ingrediente_setProteinas(pAuxIngrediente, proteinas);

            ll_add(listaIngredientes, pAuxIngrediente);

            retorno = 1;

            break;
        }
    }

    return retorno;
}

int ingrediente_eliminarIngrediente(LinkedList* listaIngredientes, LinkedList* listaRecetas)
{
    int id;
    int i;
    int j;
    int retorno = 0;//no cargo
    int flagEstaEnReceta = 0;//No esta

    S_ingrediente* pAuxIngrediente;
    S_receta* pAuxReceta;

    ingrediente_mostrarListaIngredientes(listaIngredientes);
    id = pedirCadenaInt("Ingrese el id del ingrediente", 0, 100);

    for(i = 0; i < ll_len(listaIngredientes); i++)
    {
        pAuxIngrediente = (S_ingrediente*)ll_get(listaIngredientes, i);

        if(id == pAuxIngrediente->id)
        {
            for(j = 0; j < ll_len(listaRecetas); j++)
            {
                pAuxReceta = ll_get(listaRecetas, j);

                if(id == pAuxReceta->id_receta)
                {
                    flagEstaEnReceta = 1 ; //esta en la receta no se puede eliminar
                    break;
                }

            }

            if(flagEstaEnReceta == 0)
            {
                ll_remove(listaIngredientes, i);
                retorno = 1;
            }
            else
            {
                printf("No se puede dar de baja. Forma parte de una receta.\n");
            }
        }
    }

    return retorno;
}

int ingrediente_buscarIngredientePorNombre(LinkedList* listaIngredientes, char* nombre)
{
    int i;
    int retorno= -1;// no se encuentra
    S_ingrediente* pAuxIngrediente;

    for(i = 0; i < ll_len(listaIngredientes); i++)
    {
        pAuxIngrediente = ll_get(listaIngredientes, i);

        if(stricmp(pAuxIngrediente->nombre, nombre) == 0)
        {
            retorno = pAuxIngrediente->id;
            break;
        }
    }

    return retorno;
}
