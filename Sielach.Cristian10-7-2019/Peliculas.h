#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[100];
    int anio;
    char genero[100];

}ePelicula;

ePelicula* newReceta();

int receta_cargarReceta(ePelicula* pReceta, char* auxIdReceta, char* auxNombre, char* auxIdIngrediente,
                                     char* auxCantidad);

int receta_setIdReceta(ePelicula* pAuxEstructura, int id_receta);
int receta_setNombre(ePelicula* pAuxEstructura, char* nombre);
int receta_setIdIngrediente(ePelicula* pAuxEstructura, int id_ingrediente);
int receta_setCantidad(ePelicula* pAuxEstructura, int cantidad);

int receta_nuevaReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes);

///Mostrar
void receta_mostrarReceta(LinkedList* listaRecetas, LinkedList* listaIngredientes);
void receta_mostrarLista(LinkedList* listaRecetas);
