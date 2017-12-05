#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "ArrayList.h"

int main()
{
    char seguir= 's';
    int opcion=0;

    ArrayList* nuevaLista = al_newArrayList();
    ArrayList* destinatariosArray = al_newArrayList();
    ArrayList* black_listArray = al_newArrayList();


    if(destinatariosArray != NULL && black_listArray != NULL && nuevaLista != NULL)
    {
      do
    {
        printf("1- Cargar Destinatarios\n");
        printf("2- Cargar Lista negra\n");
        printf("3- Depurar\n");
        printf("4- Listar\n");
        printf("5- salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            lee_archivo_cliente(destinatariosArray);
            system("cls");
            break;
        case 2:
            cargarBlackList(destinatariosArray,black_listArray);
            system("cls");
            break;
        case 3:
            depurar(nuevaLista,destinatariosArray,black_listArray);
            system("cls");
            break;
        case 4:
            mostrar_clientes(nuevaLista);
            system("cls");
            break;
        case 5:
            seguir='n';
            break;
        }
    }while(seguir == 's');

}
    return 0;
    }
