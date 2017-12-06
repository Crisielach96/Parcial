#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"

int main()
{
    ArrayList* lista = al_newArrayList();
    FILE *pFile;
    pFile = fopen("data.csv","r");

    parserEmployee(pFile,lista);

    printf("*********** LISTA COMPLETA ****************\n");
    int i;
    for(i=0; i < al_len(lista); i++)
    {
        Employee* e = al_get(lista,i);
        employee_print(e);
    }

//    // Obtengo lista filtrada
    ArrayList* filteredList = al_filter(lista,employee_filterEmployee);

    printf("*********** LISTA FILTRADA ****************\n");
    for(i=0; i<al_len(filteredList); i++)
    {
        Employee* e = al_get(filteredList,i);
        employee_print(e);
    }

    // genero archivo con lista filtrada
    dm_dumpEmployeeList(filteredList);

    return 0;
}
