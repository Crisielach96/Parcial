#include "LinkedList.h"

typedef struct
{
    int id_receta;
    char nombre[100];
    int id_ingrediente;
    int cantidad;

}S_receta;

S_receta* newReceta();

int receta_cargarReceta(S_receta* pReceta, char* auxIdReceta, char* auxNombre, char* auxIdIngrediente,
                                     char* auxCantidad);

int receta_setIdReceta(S_receta* pAuxEstructura, int id_receta);
int receta_setNombre(S_receta* pAuxEstructura, char* nombre);
int receta_setIdIngrediente(S_receta* pAuxEstructura, int id_ingrediente);
int receta_setCantidad(S_receta* pAuxEstructura, int cantidad);

int receta_nuevaReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes);

///Mostrar
void receta_mostrarReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes);
void receta_mostrarLista(LinkedList* listaRecetas);
