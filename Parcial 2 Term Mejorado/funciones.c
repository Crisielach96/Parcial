#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "ArrayList.h"

eDestinatario* new_destinatario()
{
    eDestinatario* returnAux;

    returnAux=(eDestinatario*)malloc(sizeof(eDestinatario));

    if(returnAux!=NULL)
    {
        strcpy(returnAux->nombre, "");
        strcpy(returnAux->mail, "");
        returnAux->isEmpty = 0;
    }
    return returnAux;
}

int lee_archivo_cliente(ArrayList* lista)
{
    FILE* archivo=NULL;
    eDestinatario* returnAux;
    //eCliente* auxCliente;
    char auxMail[50];
    char auxNombre[50];
    int salida=-1;
    char nomarchivo[20];

    printf("Ingrese nombre del archivo: ");
    fflush(stdin);
    gets(nomarchivo);

    archivo = fopen(nomarchivo,"r");

    if(archivo!= NULL && lista != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%s\n",auxNombre,auxMail);


            returnAux = new_destinatario();
            if(feof(archivo) || returnAux==NULL)
            {
                break;
            }

            else
            {
                if(returnAux!=NULL)
                {
                    strcpy(returnAux->mail,auxMail);
                    strcpy(returnAux->nombre,auxNombre);
                    returnAux->isEmpty=1;

                    lista->add(lista,returnAux);

                    salida=0;
                }

            }
        }
        printf("Cargado con exito!");
        getch();
    }
    else
    {
        printf("ERROR; No se pudo abrir el archivo");
        exit(1);
    }

    fclose(archivo);

    return salida;
}

int cargarBlackList(ArrayList* destinatarios, ArrayList* blacklist)
{
    FILE* archivo=NULL;
    eDestinatario* returnAux;
    char auxMail[50];
    char auxNombre[50];
    int i,salida=-1;
    char nomarchivo[20];

    printf("Ingrese nombre del archivo: ");
    fflush(stdin);
    gets(nomarchivo);

    archivo = fopen(nomarchivo,"r");

    if(archivo!= NULL && destinatarios != NULL)
    {
        while(!feof(archivo))
        {
            fflush(stdin);
            fscanf(archivo,"%[^,],%s\n",auxNombre,auxMail);

            for (i = 0; i < destinatarios->len(destinatarios); i++)
            {
                returnAux =(eDestinatario*) al_get(destinatarios, i); //TRAIGO EL PRIMERO ELEMENTO DEL ARRAY DE "DESTINATARIOS"

                if (strcmp(returnAux->mail, auxMail) == 0) //COMPARO EL CAMPO MAIL CON LO QUE EXTRAJE DEL ARCHIVO
                {
                    al_add(blacklist, al_get(destinatarios, i)); //SI COINCIDEN AGREGO ELEMENTO CON ADD PORQUE ESTE ME PERMITE
                }                                                //PONERLE LA MISMA DIRRECCION DE MEMORIA. USANDO GET PORQUE
            }
        }
        printf("Cargado con exito!");
        getch();
    }
    else
        {
           printf("Error al cargar el archivo!");
           exit(1);
        }

    fclose(archivo);

    salida=1;

    return salida;
}

int depurar(ArrayList* nuevaLista, ArrayList* destinatarios, ArrayList* blacklist)
{
    int retorno = 0, i, flag = 0;
    void* returnAux;

    if (nuevaLista != NULL && destinatarios != NULL && blacklist != NULL)
    {
        for (i = 0; i < destinatarios->len(destinatarios); i++)
        {
            returnAux = al_get(destinatarios, i);

            if (al_contains(blacklist, returnAux) == 0)
            {
                al_add(nuevaLista, returnAux);
                flag = 1;
            }
        }
    }

    if (flag)
        retorno = 1;

    return retorno;
}

int mostrar_clientes (ArrayList* lista)
{
    eDestinatario* auxCliente;
    int salida=-1,i;

    for(i=0; i<lista->size; i++)
    {
        auxCliente= (eDestinatario*) lista->get(lista,i);
        printf("Nombre: %s  ",auxCliente->nombre);
        printf("  \t  Correo: %s \n",auxCliente->mail);
        salida=0;
    }

    getch();
    return salida;

}
