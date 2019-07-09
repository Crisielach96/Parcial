#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[60];
    int calorias;
    float grasa;
    int sodio;
    int carbohidratos;
    int proteinas;

}S_ingrediente;



///Estructuras con memoria dinámica:
/** \brief Crea una nueva estructura en memoria
 *
 * \return S_ingrediente* puntero a la estructura creada
 *
 */
 S_ingrediente* newIngrediente();

 int ingrediente_cargarIngrediente(S_ingrediente* pIngrediente, char* auxId, char* auxNombre, char*auxCalorias,
                                     char* auxGrasa, char* auxSodio, char* auxCarbohidratos, char* auxProteinas);
int ingrediente_agregarIngrediente(LinkedList* listaIngredientes);
int ingrediente_modificarIngrediente(LinkedList* listaIngredientes);
int ingrediente_eliminarIngrediente(LinkedList* listaIngredientes, LinkedList* listaRecetas);
int ingrediente_buscarIngredientePorNombre(LinkedList* listaIngredientes, char* nombre);

///Muestro
void ingrediente_mostrarListaIngredientes(LinkedList* listaIngredientes);

int ingrediente_ordenarIngrediente(void* ingredienteUno, void* ingredienteDos);



 ///Setters

int ingrediente_setId(S_ingrediente* pAuxEstructura, int id);
int ingrediente_setNombre(S_ingrediente* pAuxEstructura, char* nombre);
int ingrediente_setCalorias(S_ingrediente* pAuxEstructura, int calorias);
float ingrediente_setGrasa(S_ingrediente* pAuxEstructura, float grasa);
int ingrediente_setSodio(S_ingrediente* pAuxEstructura, int sodio);
int ingrediente_setCarbohidratos(S_ingrediente* pAuxEstructura, int carbohidratos);
int ingrediente_setProteinas(S_ingrediente* pAuxEstructura, int proteinas);

///Setters
int ingrediente_getId(void* pEstructura);
char* ingrediente_getNombre(void* pEstructura);
int ingrediente_getCalorias(void* pEstructura);
float ingrediente_getGrasa(void* pEstructura);
int ingrediente_getSodio(void* pEstructura);
int ingrediente_getCarbohidratos(void* pEstructura);
int ingrediente_getProteinas(void* pEstructura);
