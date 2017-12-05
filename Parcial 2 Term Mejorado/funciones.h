#include "ArrayList.h"

typedef struct
{
    char nombre[51];
    char mail[71];
    int isEmpty;
}eDestinatario;

eDestinatario* new_destinatario();
int lee_archivo_cliente(ArrayList* lista);
int cargarBlackList(ArrayList* destinatarios, ArrayList* blacklist);
int depurar(ArrayList* nuevaLista, ArrayList* destinatarios, ArrayList* blacklist);
int mostrar_clientes (ArrayList* lista);
