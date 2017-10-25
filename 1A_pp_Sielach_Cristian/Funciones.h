typedef struct
{
    int idDuenio;
    char nombre[20];
    char apellido[20];
    long int numeroTarjeta;
    char direccion[50];
    int estado;
}eCliente;

typedef struct
{
    char patente[8];
    int marca;
    int duenio;
    int horaEntrada;
    int estado;
}eAuto;

/** \brief Genera un menu
 *
 * \return la opcion ingresada
 *
 */
int menu();

/** \brief Busca un espacio libre
 *
 * \param Lista de clientes
 * \param Tamaño de la lista
 * \return el espacio libre encontrado
 *
 */
int buscarLibre(eCliente lista[],int tam);

/** \brief Busca por ID
 *
 * \param El ID ingresado
 * \param Lista de los clientes
 * \param Tamaño de la lista
 * \return La posicion del cliente encontrado
 *
 */
int buscarClientePorId(int id,eCliente lista[],int tam);

/** \brief Convierte las variables a 0
 *
 * \param Lista de clientes
 * \param Posicion
 * \return void
 *
 */
void variablesCero(eCliente lista[],int i);

/** \brief Inicializa las variables
 *
 * \param Lista de clientes
 * \param Tamaño de la lista
 * \return void
 *
 */
void inicializarVariables(eCliente lista[],int tam);

/** \brief Alta de cliente
 *
 * \param Lista de clientes
 * \param Tamaño de la lista
 * \return void
 *
 */
void alta(eCliente lista[],int tam);

/** \brief Harcodea Clientes
 *
 * \param Lista de clientes
 * \param Tamaño de la lista
 * \return void
 *
 */
void harcCliente(eCliente lista[],int tam);

/** \brief Muestra todos los clientes dados de alta
 *
 * \param Lista de clientes
 * \param Tamaño de la lista
 * \return void
 *
 */
void mostrarClientes(eCliente lista[], int tam);

/** \brief Muestra un solo cliente
 *
 * \param Lista de clientes
 * \return void
 *
 */
void mostrarCliente(eCliente lista);

/** \brief Busca un espacio libre
 *
 * \param Lista de autos
 * \param Tamaño de la lista
 * \return el espacio libre encontrado
 *
 */
int buscarLibreAuto(eAuto lista[],int tam);

/** \brief Convierte las variables a 0
 *
 * \param Lista de autos
 * \param Posicion
 * \return void
 *
 */
void variablesCeroAuto(eAuto lista[],int i);

/** \brief Alta de autos
 *
 * \param Lista de autos
 * \param Tamaño de la lista
 * \return void
 *
 */
void inicializarVariablesAutos(eAuto lista[],int tam);

/** \brief Ingreso de auto
 *
 * \param Lista de autos
 * \param Tamaño de la lista de autos
 * \param Lista de clientes
 * \param Tamaño de la lista de clientes
 * \return void
 *
 */
void altaAuto(eAuto lista[],int tamA,eCliente cliente[],int tamC);

/** \brief Muestra autos con sus dueños
 *
 * \param Lista de autos
 * \param Tamaño de la lista de autos
 * \param Lista de clientes
 * \param Tamaño de la lista de clientes
 * \return void
 *
 */
void mostrarClientesAutos(eCliente lista[], int tamC,eAuto autos[],int tamA);

/** \brief Ordena por horario de entrada y ordena alfabeticamente las patentes
 *
 * \param Lista de autos
 * \param Tamaño de lista de autos
 * \return void
 *
 */
void ordenar(eAuto autos[],int tamA);

/** \brief Harcodea Autos
 *
 * \param Lista de autos
 * \param Tamaño de la lista de autos
 * \return void
 *
 */
void harcAuto(eAuto autos[],int tam);

/** \brief Modifica la tarjeta del cliente
 *
 * \param Lista de clientes
 * \param Tamaño de la lista de clientes
 * \return void
 *
 */
void modificacion(eCliente lista[],int tam);

/** \brief Egreso de un auto
 *
 * \param lista de clientes
 * \param tamaño de la lista de clientes
 * \param lista de autos
 * \param tamaño de la lista de autos
 * \param Las ganancias por marca
 * \return Total recaudado
 *
 */
int bajaAuto(eCliente lista[],int tamC,eAuto autos[],int tamA,int gananciaXmarca[]);

/** \brief Busca auto por ID
 *
 * \param ID ingresado
 * \param Lista de autos
 * \param Tamaño de la lista de autos
 * \return Posicion del elemento encontrado
 *
 */
int buscarAutoId(int id,eAuto lista[],int tam);

/** \brief Muetra todos los clientes con una marca en en concreto
 *
 * \param lista de clientes
 * \param Tamaño de lista de clientes
 * \param Lista de autos
 * \param Tamaño de la lista de autos
 * \return void
 *
 */
void maxCantAutos(eCliente lista[],int tamC,eAuto autos[],int tamA);
