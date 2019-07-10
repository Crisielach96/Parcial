#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "parser.h"
#include "ingrediente.h"
#include "Peliculas.h"


int archivo_cargarPelicula(char* nombreArchivo, LinkedList* nombreLista)
{
    FILE* pArchivo;
    //Estructura auxiliar
    ePelicula* pAuxEstructura;

    int retorno=-1;//No cargó
    int flag = 0;

    //Variables auxiliares de estructura
    char auxId[60];
    char auxNombre[100];
    char auxAnio[60];
    char auxGenero[100];

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
                cantidadDatos=fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^\n]\n",auxId, auxNombre,
                                     auxAnio, auxGenero);

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
                        pAuxEstructura=newPelicula();

                        //Cargo los campos en la estructura (Hacer funcion que devuelva estructura cargada)
                        pelicula_cargarPelicula(pAuxEstructura, auxId, auxNombre, auxAnio, auxGenero);

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

