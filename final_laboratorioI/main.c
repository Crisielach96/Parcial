#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "validaciones.h"
#include "parser.h"
#include "ingrediente.h"
#include "receta.h"

int main()
{
    int opcion;
    char respuesta;

    LinkedList* listaIngredientes;
    LinkedList* listaRecetas;

    listaIngredientes = ll_newLinkedList();
    listaRecetas = ll_newLinkedList();

    archivo_cargarIngrediente("ingrediente.csv", listaIngredientes);
    archivo_cargarReceta("receta.csv", listaRecetas);

    do
    {
        mostrarMenu();
        opcion = pedirCadenaInt("Opcion", 0, 7);

        switch(opcion)
        {
            case 1:
                do
                {
                    if(ingrediente_agregarIngrediente(listaIngredientes))
                    {
                        printf("Ingrediente agredado.\n");
                    }

                    printf("\nDesea seguir agregando ingredientes(s/n)\n");
                    fflush(stdin);
                    respuesta = getche();

                }while(respuesta != 'n');
                break;
            case 2:
                do
                {
                    if(ingrediente_modificarIngrediente(listaIngredientes))
                    {
                        printf("Ingrediente modificado.\n");
                    }

                    printf("\nDesea seguir modificando ingredientes(s/n)\n");
                    fflush(stdin);
                    respuesta = getche();

                }while(respuesta != 'n');
                break;
            case 3:
                do
                {

                    if(ingrediente_eliminarIngrediente(listaIngredientes, listaRecetas))
                    {
                        printf("Ingrediente eliminado\n");
                    }

                    printf("\nDesea seguir eliminando ingredientes(s/n)\n");
                    fflush(stdin);
                    respuesta = getche();

                }while(respuesta != 'n');
                break;
            case 4:
                ll_sort(listaIngredientes, ingrediente_ordenarIngrediente,1);
                //mostrar
                ingrediente_mostrarListaIngredientes(listaIngredientes);
                getche();
                break;
            case 5:
                do
                {

                //Nueva receta
                    if(receta_nuevaReceta(listaRecetas, listaIngredientes))
                    {
                        printf("Se guardo la receta.");
                    }

                    printf("\nDesea seguir ingresando recetas(s/n)\n");
                    fflush(stdin);
                    respuesta = getche();

                }while(respuesta != 'n');
                break;
            case 6:
                receta_mostrarLista(listaRecetas);
                receta_mostrarReceta(listaRecetas, listaIngredientes);
                getche();
                break;
            case 7:
                break;
        }
        system("cls");
    }while(opcion != 7);

    return 0;
}
