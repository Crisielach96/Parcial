#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "ingrediente.h"
#include "receta.h"



//Parser logs
int archivo_cargarIngrediente(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_ingrediente* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag = 0;

    //Variables auxiliares de estructura
    char auxId[60];
    char auxNombre[60];
    char auxCalorias[60];
    char auxGrasa[60];
    char auxSodio[60];
    char auxCarbohidratos[60];
    char auxProteinas[60];

    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxCalorias,
                                     auxGrasa,auxSodio, auxCarbohidratos, auxProteinas);

                //Puedo hacer 1 falsa lectura:

                if(cantidadDatos==7 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==7 && flag==1)///Compruebo que se haya copiado toda la linea
                    {
                        //Creo una estructura en memoria
                        pAuxEstructura=newIngrediente();

                        //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                        ingrediente_cargarIngrediente(pAuxEstructura, auxId, auxNombre,auxCalorias,
                                                                     auxGrasa, auxSodio, auxCarbohidratos, auxProteinas);

                        //Lo agrego a la lista
                        ll_add(nombreLista, pAuxEstructura);
                    }

                }


            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

int archivo_cargarReceta(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    S_receta* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag = 0;

    //Variables auxiliares de estructura
    char auxIdReceta[60];
    char auxNombre[100];
    char auxIdIngrediente[60];
    char auxCantidad[60];

    //Datos copiados
    int cantidadDatos=0;
    //int flag=0;//Flag para falsa lectura

    if(nombreLista!=NULL)
    {

        pArchivo=fopen(nombreArchivo,"r");


        if(pArchivo!=NULL)
        {
            do
            {
                //Copio los datos del archivo
                //Parser: todos los char menos: ';' y '\n' (al final)
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxIdReceta, auxNombre,
                                     auxIdIngrediente, auxCantidad);

                //Puedo hacer 1 falsa lectura:

                if(cantidadDatos==4 && flag==0)
                {
                    flag=1;
                }
                else
                {
                    if(cantidadDatos==4 && flag==1)///Compruebo que se haya copiado toda la linea
                    {
                        //Creo una estructura en memoria
                        pAuxEstructura=newReceta();

                        //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                        receta_cargarReceta(pAuxEstructura, auxIdReceta, auxNombre, auxIdIngrediente, auxCantidad);

                        //Lo agrego a la lista
                        ll_add(nombreLista, pAuxEstructura);
                    }

                }


            }while(!feof(pArchivo));//Sigue iterando hasta el final del archivo

            fclose(pArchivo);

            retorno=1;//Cargo los datos
        }
        else
        {
            printf("No se pudo abrir el archivo.\n");
            retorno=0;//No se pudo abrir
        }
    }

    return retorno;

}

