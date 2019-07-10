#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include <string.h>




static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i=0;

    if(this!=NULL)
    {
        if(nodeIndex>=0 && nodeIndex<ll_len(this))
        {

            pNode=this->pFirstNode;

            while(i!=nodeIndex)
            {
                    pNode=pNode->pNextNode;
                    i++;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    //Declaro tres punteros a Node:
    Node* pPreviousNode=NULL; //Para guardar el nodo anterior
    Node* pNextNode=NULL;//Para guardar el siguiente nodo
    Node* pNewNode=NULL;//El nuevo nodo que voy a insertar con pElement

    if(this!=NULL)
    {
        if(nodeIndex>=0 && nodeIndex<=ll_len(this))
        {
            //Nuevo nodo donde inserto el elemento
            pNewNode=(Node*)malloc(sizeof(Node));

            if(pNewNode!=NULL)
            {
                //Lo inicializo
                pNewNode->pElement=pElement;
                pNewNode->pNextNode=NULL;//Por ahora no apunta a ningun lado

                if(nodeIndex==0) //Si lo tengo que insertar al principio
                {
                    //Guardo en el nuevo nodo la direccion del siguiente, para no perderlo!!!
                    pNewNode->pNextNode=this->pFirstNode;
                    this->pFirstNode=pNewNode; //Paso al nuevo nodo como el primero
                }
                else
                {
                    pPreviousNode=this->pFirstNode; //Tomo la dirección del primer nodo
                    pNextNode=pPreviousNode->pNextNode; //Guardo la dirección del nodo siguiente

                    while(nodeIndex>1) //Hasta index=1, el paso 0 lo hice anteriormente
                    {

                        pPreviousNode=pNextNode;//Copio la dirección del siguiente nodo y pasa a ser el actual
                        pNextNode=pPreviousNode->pNextNode; //Busco el que le sigue y lo guardo
                        //Tengo que restarle 1 al index
                        nodeIndex--;
                    }

                    //Inserto el nuevo nodo:
                    pPreviousNode->pNextNode=pNewNode;//Inserto al nuevo nodo en la posición correspondiente
                    pNewNode->pNextNode=pNextNode;//Paso a nextNode el Nodo original para no perder la referencia

                }

                //Agrando el size!!!
                this->size++;
                //Cambio el valor de retorno!!
                returnAux=0;
            }
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largoLista;

    if(this!=NULL)
    {
        //El tamaño de la lista me da la última posición
        largoLista=ll_len(this);

        if(addNode(this, largoLista, pElement)==0)
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    //int i=1;

    Node* pAuxNode=NULL;

    if(this!=NULL)
    {
        if(index>=0 && index < ll_len(this))
        {
            pAuxNode=getNode(this, index);

            if(pAuxNode!=NULL)
            {
                returnAux=pAuxNode->pElement;
            }
        }

    }
    /*
    //Declaro tres punteros a Node:
    Node* pPreviousNode=NULL; //Para guardar el nodo anterior
    Node* pNextNode=NULL;//Para guardar el siguiente nodo


    if(this!=NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            if(index==0) //Si tengo que devolver el primer elemento
            {
                pPreviousNode=this->pFirstNode;
                returnAux=pPreviousNode->pElement;

            }
            else
            {
                pPreviousNode=this->pFirstNode; //Tomo la dirección del primer nodo
                pNextNode=pPreviousNode->pNextNode; //Guardo la dirección del nodo siguiente

                while(i<index) //Me voy moviendo dentro de la lista hasta i=index;
                {

                    pPreviousNode=pNextNode;//Copio la dirección del siguiente nodo y pasa a ser el actual
                    pNextNode=pPreviousNode->pNextNode; //Busco el que le sigue y lo guardo
                    i++;
                }
                //i=index rompe, el nextNode va a tener el elemento que quiero:
                returnAux=pNextNode->pElement;
            }
        }


    }*/
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    //int i;

    //Declaro punteros a Node:
/*  Node* pPreviousNode=NULL; //Para guardar el nodo anterior
    Node* pNextNode=NULL;//Para guardar el siguiente nodo*/
    Node* auxNode;

    if(this!=NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            //Uso get para encontrar el nodo que quiero modificar
            auxNode=getNode(this,index);

            if(auxNode!=NULL)
            {
                //Modifico el elemento
                auxNode->pElement=pElement;

                returnAux=0;//Cambio el retorno

            }


        /*Metodo largo:
            if(index==0) //Si tengo que devolver el primer elemento
            {
                pPreviousNode=this->pFirstNode;
                //Inserto el elemento en el primer nodo
                pPreviousNode->pElement=pElement;
                returnAux=0;

            }
            else
            {
                pPreviousNode=this->pFirstNode; //Tomo la dirección del primer nodo
                pNextNode=pPreviousNode->pNextNode; //Guardo la dirección del nodo siguiente

                while(i<index) //Me voy moviendo dentro de la lista hasta i=index;
                {

                    pPreviousNode=pNextNode;//Copio la dirección del siguiente nodo y pasa a ser el actual
                    pNextNode=pPreviousNode->pNextNode; //Busco el que le sigue y lo guardo
                    i++;
                }
                //i=index rompe, el nextNode va a apuntar al nodo que quiero:
                pNextNode->pElement=pElement;

                returnAux=0;
            }
        */
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    //Nodos auxiliares:
    Node* pPreviousNode;
    Node* pAuxNode;
    Node* pNextNode;

    if(this!=NULL)
    {
        if(index>=0 && index < ll_len(this))
        {
            if(index==0)
            {
                if(this->pFirstNode!=NULL)
                {
                    pAuxNode=getNode(this, index);
                    pNextNode=getNode(this, index+1);
                    this->pFirstNode=pNextNode;
                    free(pAuxNode);
                }

            }
            else
            {
                pPreviousNode=getNode(this, index-1);
                pAuxNode=getNode(this, index);

                if(pAuxNode->pNextNode==NULL)
                {
                    //Si el nodo siguiente es null solo hago null el anterior
                    pPreviousNode->pNextNode=NULL;//Borro la referencia
                    free(pAuxNode);//Libero la memoria del puntero
                }
                else
                {
                    //Si hay un nodo que le sigue lo tengo que enlazar con el anterior al que voy a borrar
                    pNextNode=pAuxNode->pNextNode;//Asigno a un aux el siguiente nodo (al que apunta el que tengo que borar)
                    pPreviousNode->pNextNode=pNextNode;//Se lo asigno al nodo anterior al que tengo que borrar
                    pAuxNode->pNextNode=NULL;//Borro la referencia al nextNode
                    free(pAuxNode);//Libero memoria
                }
            }

            //Achico el tamaño
            this->size--;
            returnAux=0;

        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;

    if(this!=NULL)
    {

        for(i=ll_len(this)-1;i>=0;i--)
        {
            ll_remove(this, i);
        }

        this->size=0;
        returnAux=0;
    }

    return returnAux;

}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    Node* auxNode=NULL;

    if(this!=NULL)
    {
        for(i=0; i<ll_len(this);i++)
        {
            auxNode=getNode(this, i);

            if(auxNode!=NULL && auxNode->pElement==pElement)
            {
                returnAux=i;
                break;
            }
        }

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(ll_len(this)==0)
        {
            returnAux=1;//Está vacía
        }
        else
        {
            returnAux=0;//No está vacía
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(index>=0 && index<=ll_len(this))
        {
            if(addNode(this, index, pElement)==0)
            {
                returnAux=0;
            }

        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    //int i=0;

    //Nodos auxiliares:
    /*Node* pPreviousNode=NULL;
    Node* pNextNode=NULL;*/
    Node* pAuxNode=NULL;

    if(this!=NULL)
    {
        if(index>=0 && index <= ll_len(this))
        {

            pAuxNode=getNode(this, index);
            if(pAuxNode!=NULL)
            {
                returnAux=pAuxNode->pElement;
                ll_remove(this,index);
            }
        }
    }


            /*Forma mas larga:
            //Tomo el elemento y lo guardo en el retorno
            returnAux=ll_get(this, index);

            //Itero para borrar el elemento del índice especificado
            pPreviousNode=this->pFirstNode;
            pNextNode=pPreviousNode->pNextNode;

            if(index==0)
            {
                pPreviousNode->pElement=NULL;
            }
            else
            {

                for(i=1; i<index; i++)
                {
                    pPreviousNode=pNextNode;
                    pNextNode=pPreviousNode->pNextNode;
                }

                //Queda el elemento que busco en pPreviousNode
                pPreviousNode->pElement=NULL;
            }

            //Achico la lista
            this->size--;

        }


    }*/

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* pAuxElement=NULL;

    if(this!=NULL)
    {
        returnAux=0;

        for(i=0; i<ll_len(this);i++)
        {
            pAuxElement=ll_get(this, i);

            if(pAuxElement!=NULL && pAuxElement==pElement)
            {
                returnAux=1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{

    int returnAux = -1;
    int i;
    void* pAuxElement;
    int auxContains;

    if(this!=NULL && this2!=NULL)
    {
        returnAux=1;

        for(i=0; i<ll_len(this2); i++)
        {
            //Tomo cada uno de los elementos
            pAuxElement=ll_get(this2, i);

            if(pAuxElement!=NULL);
            {
                //Busco si están en la lista
                auxContains=ll_contains(this, pAuxElement);

                if(auxContains==0)//No se encuentra en la lista
                {
                    returnAux=0;
                    break;
                }
            }
        }

    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;

    void* AuxNode=NULL;

    if(this!=NULL)
    {
        if((from>=0 && from<to) && (to>from && to<=ll_len(this)))
        {
           cloneArray=ll_newLinkedList();

           for(i=from;i<to; i++)//to no incluido
           {
               //Tomo los elementos de la lista
               AuxNode=ll_get(this, i);
               if(AuxNode!=NULL)
               {
                   //Los copio en la otra lista
                   ll_add(cloneArray, AuxNode);

               }
           }

        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;


    if(this!=NULL)
    {
           cloneArray=ll_newLinkedList();
           cloneArray=ll_subList(this, 0, ll_len(this));

    }


    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    int j;
    //Creo auxiliar
    void* auxElementI=NULL;
    void* auxElementJ=NULL;

    if(this!=NULL && pFunc!=NULL)
    {
        if(order==0 || order==1)
        {

            for(i=1;i<ll_len(this);i++)
            {
                //Empiezo en indice 1 y voy avanzando hacia la derecha con cada iteración
                auxElementI=ll_get(this, i);
                j=i-1;

                if(order==1)
                {
                    //Comparo con el de la izquierda
                    while(j>=0 && pFunc(auxElementI,ll_get(this,j))<0)//Cantidad desc
                    {
                        auxElementJ=ll_get(this, j);
                        ll_set(this, j+1, auxElementJ);
                        //muevo todo para la derecha
                        j--;
                    }

                    //inserto en la ultima posición a la izquierda
                    ll_set(this, j+1, auxElementI);
                    returnAux=0;
                }

                if(order==0)
                {
                    //Comparo con el de la izquierda
                    while(j>=0 && pFunc(auxElementI,ll_get(this,j))>0)//Cantidad desc
                    {
                        auxElementJ=ll_get(this, j);
                        ll_set(this, j+1, auxElementJ);
                        //muevo todo para la derecha
                        j--;
                    }

                    //inserto en la ultima posición a la izquierda
                    ll_set(this, j+1, auxElementI);

                    returnAux=0;
                }
            }

        }


    }

    return returnAux;

}

