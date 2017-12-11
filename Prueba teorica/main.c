#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
    int codigo;
    char marca[20];
    char modelo[20];
    int cantidad;
    int capacidad;
} ePendrive;

int main()
{
    int* puntero;
    int i, num=5;

    printf("%d\n",num);

    puntero=&num;

    *puntero=10;

    printf("%d\n\n",num);
    printf("------------------------------------------------------",num);
    printf("\n\n",num);

    int* pVec;
    int* aux;

    pVec = (int*)malloc(sizeof(int)*5);

    if(pVec!=NULL)
    {
        for(i=0; i<5; i++)
        {
            *(pVec+i)=i+1;
            printf("%d\n",*(pVec+i));
        }

        printf("\n");

        aux = (int*)realloc(pVec,sizeof(int*)*10);

        if(aux!=NULL)
        {
            pVec=aux;

            for(i=5; i<10; i++)
            {
                *(pVec+i)=i+1;
                printf("%d\n",*(pVec+i));
            }
        }
    }

     printf("------------------------------------------------------",num);
    printf("\n\n",num);


    SYSTEMTIME lt;

    GetLocalTime(&lt);

    printf("\n%d/%d/%d",lt.wDay,lt.wMonth,lt.wYear);

     printf("\n------------------------------------------------------",num);
    printf("\n\n",num);



    FILE *binario;
    ePendrive pendrive[2];
    ePendrive* pendriveptr;
    pendriveptr=&pendrive[0];
    if((binario=fopen("binario.bin","rb"))==NULL)
    {
        if((binario=fopen("binario.bin","wb"))==NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }
        else
        {
            for(int i=0; i<2; i++)
            {
                printf("\nIngrese cantidad: \n");
                scanf("%d",&(pendriveptr+i)->cantidad);
                printf("\nIngrese codigo: \n");
                scanf("%d",&(pendriveptr+i)->codigo);
            }
            printf("Archivo creado con exito!\n");
            system("pause");
            system("cls");
            fwrite(pendriveptr,sizeof(ePendrive),2,binario);
        }
        fclose(binario);
    }
    else
    {
        fread(pendriveptr,sizeof(ePendrive),2,binario);
        fclose(binario);
        system("pause");
        system("cls");
        printf("Archivo abierto con exito! Contiene esto: \n");
        for(int i=0; i<2; i++)
        {
            printf("cantidad: %d  ---  codigo: %d\n",(pendriveptr+i)->cantidad,(pendriveptr+i)->codigo);
        }

    }




    return 0;
}

ePendrive* new_pendrive()
{
    ePendrive* returnAux;

    returnAux = (ePendrive*)malloc(sizeof(ePendrive));

    if(returnAux!=NULL)
    {
        returnAux->codigo=0;
        strcpy(returnAux->marca,"");
        strcpy(returnAux->modelo,"");
        returnAux->capacidad=0;
    }
    return returnAux;
}
