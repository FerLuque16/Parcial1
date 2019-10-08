typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
}eJuegos;

typedef struct
{
    int dia,mes,anio;
}eFecha;

typedef struct
{
  int id;//Auto incremental
  char nombre[51];
  char apellido[51];
  char sexo;
  char domicilio[51];

  int isEmpty;
  char telefono[21];

}eClientes;

typedef struct
{
    int id;//Auto incremental
    int idJuego;
    int idCliente;
    eFecha fechaAlquiler;
    int isEmpty;

}eAlquileres;


int initClientes(eClientes *cliente, int len);
int initAlquileres(eAlquileres *alquiler, int lenAlquiler);

int addClientes(eClientes *cliente, int len, int idCliente);
int removeCliente(eClientes *cliente,int len);
void modifyCliente(eClientes *cliente,int len);

int addAlquiler(eAlquileres *alquiler,eClientes *cliente, int lenCliente, eJuegos *juego, int lenJuegos, int idAlquiler);





void printJuegos(eJuegos *juego, int len);
void printCliente(eClientes cliente, int formato);
void printAllClientes(eClientes *cliente, int len);
void printAlquileres(eAlquileres *alquiler, int lenAlquiler);
void printAlquiler(eAlquileres alquiler);
void sortClientes(eClientes *emp, int len);
//void calculateSalaryInfo(eEmployee emp[], int len);
int findEmptyPlace (eClientes *cliente, int len);
int findClienteById(eClientes *cliente, int len, int id);
int findJuegoById(eJuegos *juego,int lenJuego, int id);
void sortJuegos(eJuegos *juego, int len);
