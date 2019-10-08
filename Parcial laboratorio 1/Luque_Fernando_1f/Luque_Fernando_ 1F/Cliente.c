#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Cliente.h"

/** \brief Indica que toda la posicion del array esta vacio,
* esta funcion pone a isEmpty en 1 indicando que esa posicion esta vacia.
* \param emp eEmployye* puntero al array de clientes
* \param len int Indica el largo del array
*
*/
int initClientes(eClientes *cliente, int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        cliente[i].isEmpty=1;
    }

    return 0;
}


/** \brief Agrega los datos del cliente en la posicion del array obtenido mediante otra funcion,
*
* \param cliente eClientes* puntero al array de clientes
* \param len int Indica el largo del array
* \param idCliente int obtiene el id del cliente

* \return Retorna -1 si la funcion no dio de alta a algun cliente, retorna 0 si  dio de alta a alguien
*/
int addClientes(eClientes *cliente, int len, int idCliente)

{
    int index;
    char rta;
    int retorno=-1;

    index=findEmptyPlace(cliente,len);

    if(index!=-1)
    {
        cliente[index].id=idCliente+1;
        getString(cliente[index].nombre,"\nIngrese nombre: \n","\nERROR\n",1,51,3);
        getString(cliente[index].apellido,"\nIngrese apellido : \n","\nERROR\n",1,51,3);
        getChar(&cliente[index].sexo,"\nIngrese sexo f o m: \n","\nERROR\n",'f','m',3);
        getDomicilio(cliente[index].domicilio,"\nIngrese domicilio : \n","\nERROR\n",1,51,3);
        getTelefono(cliente[index].telefono,"\nIngrese el telefono\n","ERROR",1,21,3);
        system("cls");



        getChar(&rta,"\nIngrese s para confirmar el alta\n","\nERROR\n",'a','z',3);


        if(rta == 's' || rta == 'S')
        {
            cliente[index].isEmpty=0;
            retorno=0;
        }
        else
        {
            printf("\nNo se ha dado de alta el cliente\n");
            system("pause");
        }

    }
    else
    {
           printf("\nNo hay mas espacio libre\n");
    }

    return retorno;
    }

/** \brief Remueve a un cliente del sistema seteando el flag isEmpty en 1,
*dependiendo al id del cliente indicado por el usuario.
* \param cliente eClientes* puntero al array de cliente
* \param len int Indica el largo del array
* \return Retorna -1 si la funcion no remocio a algun empleado, retorna 0 si lo ha hecho.
*/

int removeCliente(eClientes *cliente,int len)
{
    char rta;
    int auxId;
    int index;
    int retorno=-1;

    printAllClientes(cliente,len);
    getInt(&auxId,"\nIngrese ID del cliente: \n","\nERROR\n",1,1000,3);

    index=findClienteById(cliente,len,auxId);

            if(index != -1)
            {

               do
               {
                   system("cls");

                   getChar(&rta,"\n¿Confirma la baja del cliente? Ingrese s o n: \n","\nERROR\n",'n','s',3);
                   system("pause");

               }while(rta != 's' &&  rta != 'n');

               if(rta=='s')
                {
                    cliente[index].isEmpty=1;
                    retorno=0;

                }
               else
                {
                    printf("\nNo se ha dado de baja\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se ha encontrado al cliente\n");
            }

    return retorno;

}

/** \brief Permite modificar algun dato del cliente mediante el ID indicado por el usuario
* \param cliente eClientes* puntero al array de clientes
* \param len int Indica el largo del array
*/

void modifyCliente(eClientes *cliente,int len)
{
    char rta;
    int auxId,index;
    int opcMod;

//    sortClientes(cliente,len,1);
    printAllClientes(cliente,len);
    getInt(&auxId,"\nIngrese ID del cliente: ","\nERROR\n",1,1000,3);

    index=findClienteById(cliente,len,auxId);


            if(index!=-1)
            {
                getChar(&rta,"\n¿Desea modificar? Ingrese s o n\n","\nERROR\n",'n','s',3);

               if(rta=='s')
                {
                    do
                    {
                        system("cls");


                        getInt(&opcMod,"1. Modificar nombre.\n2. Modificar apellido.\n3. Modificar sexo.\n4. Modificar domicilio.\n5. Modificar telefono\n6. Atras.\n\nIngrese la opcion a realizar: \n","OPCION NO VALIDA",1,6,0);

                        switch(opcMod)
                        {
                            case 1:
                                getString(cliente[index].nombre,"\nIngrese nombre\n","\nERROR\n",1,51,3);


                                break;

                            case 2:
                                getString(cliente[index].apellido,"\nIngrese apellido\n","ERROR",1,51,3);

                                break;

                            case 3:
                                getChar(&cliente[index].sexo,"\nIngrese sexo f o m: \n","\nERROR\n",'f','m',3);

                                break;

                            case 4:
                                getDomicilio(cliente[index].domicilio,"\nIngrese domicilio : \n ","\nERROR\n",1,51,3);

                                break;

                            case 5:
                                getTelefono(cliente[index].telefono,"\nIngrese telefono : \n","\nERROR\n",1,21,3);
                                break;

                            case 6:
                                opcMod=6;


                        }
                    }while(opcMod!=6);
                }
               else
                {
                    printf("\nNo se ha modificado al cliente\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se ha encontrado al cliente\n");
                system("pause");
            }
    }

/** \brief Imprime el ID, descripcion e importe de los juegos
* \param juego eJuegos* puntero al array de juegos
* \param len int Largo del array de juegos
*/
void printJuegos(eJuegos *juego, int len)
{
    setbuf(stdin,NULL);
    int i;
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("%s %10s %10s", "Id", "Nombre", "Importe");


        for(i=0;i<len;i++)
            {
                    printf("\n%d\t%s\t%.2f\n" ,juego[i].idJuego,juego[i].descripcion,juego[i].importe);
            }
}

/** \brief Busca al cliente mediante el id ingresado por el usuario.
* \param cliente eClientes* puntero al array clientes
* \param len int Indica el largo del array
*\param id len Es el id del cliente a buscar.
* \return Retorna el indice del array del cliente encontrado.
*/

int findClienteById(eClientes *cliente, int len, int id)
{
    int i;
    int  index = -1;

    for(i=0; i<len; i++)
    {
        if(cliente[i].id == id && cliente[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}
/** \brief Busca el juego mediante el id ingresado por el usuario.
* \param juego eJuegos* puntero al array juegos
* \param lenJuego int Indica el largo del array
*\param id len Es el id del juego a buscar.
* \return Retorna el indice del array del juego encontrado.
*/
int findJuegoById(eJuegos *juego,int lenJuego, int id)
{
    int index=-1;
    int i;

    for(i=0;i<lenJuego;i++)
    {
        if(juego[i].idJuego==id)
        {
            index=i;
            break;
        }
    }

    return index;
}

/** \brief Busca en el array de clientes un espacio libre,
* o sea que el flag isEmpty este en 1
* \param cliente eClientes* puntero al array de empleados
* \param len int Indica el largo del array
* \return Retorna el indice libre encontrado.
*/
int findEmptyPlace (eClientes *cliente, int len)
{
    int i;
    int index=-1;

    for(i=0; i<len; i++)
    {
        if(cliente[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}

/** \brief Imprime los datos del cliente.
* \param cliente eClientes Cliente a mostrar.
* \param formato int Indica el formato en el que mostrar.
*/

void printCliente(eClientes cliente, int formato)
{

        if(formato==0)
        {
            printf("\n%10d %10s %10s %10c %10.2s %15s\n", cliente.id, cliente.nombre, cliente.apellido, cliente.sexo, cliente.domicilio, cliente.telefono);

        }



}

/** \brief Imprime los datos de todos los clientess en el sistema.
* \param cliente eClientes* Cliente a mostrar.
* \param len int Indica el largo de la estructura de clientes.
*/


void printAllClientes(eClientes *cliente, int len)
{
    int i;
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("%10s %10s %10s %10s %10s %10s", "Id", "Nombre", "Apellido", "Sexo", "Domicilio", "Telefono");

        for(i=0; i<len; i++)
        {
            if(cliente[i].isEmpty == 0)
            {
                printCliente(cliente[i],0);
                printf("\n--------------------------------------------------------------------------------------------------\n");
            }
        }

}

/** \brief Indica que toda la posicion del array esta vacio,
* esta funcion pone a isEmpty en 1 indicando que esa posicion esta vacia.
* \param alquiler eAlquileres* puntero al array de alquileres
* \param lenAlquiler int Indica el largo del array
*
*/

int initAlquileres(eAlquileres *alquiler, int lenAlquiler)
{
    int i;

    for(i=0;i<lenAlquiler;i++)
    {
        alquiler[i].isEmpty=1;
    }

    return 0;
}

/** \brief Agrega los datos del alquiler de acuerdo a los datos ingresados
* \param alquiler eAlquileres* puntero al array de alquileres
* \param cliente eClientes* puntero al array de clientes
* \param lenCliente int Indica el largo del array de clientes
* \param juego eJuegos* puntero al array de juegos
* \param lenJuegos int Indica el largo del array de juegos
* \param idAlquiler int Recibe el id que obtendra el alquilar al ser dado de alta
* \return Retorna -1 si la funcion no dio de alta a algun cliente, retorna 0 si  dio de alta a alguien
*/

int addAlquiler(eAlquileres *alquiler,eClientes *cliente, int lenCliente, eJuegos *juego, int lenJuegos,int idAlquiler)
{
    int retorno=-1;
    int indexCliente;
    int indexJuego;
    int auxIdCliente;
    int auxIdJuego;
    eAlquileres auxAlquiler;
    char rta;

    printAllClientes(cliente,lenCliente);
    printf("\nIngrese el ID del cliente\n");
    scanf("%d" ,&auxIdCliente);

    indexCliente=findClienteById(cliente,lenCliente,auxIdCliente);
    system("cls");

    if(indexCliente!=-1)
    {
        sortJuegos(juego,lenJuegos);
        printJuegos(juego,lenJuegos);
        system("pause");

        printf("\nIngrese el ID del juego a alquilar : \n");
        scanf("%d" ,&auxIdJuego);

        indexJuego=findJuegoById(juego,lenJuegos,auxIdJuego);

        if(indexJuego!=-1)
        {
            auxAlquiler.idCliente=auxIdCliente;
            auxAlquiler.idJuego=auxIdJuego;
            auxAlquiler.id=idAlquiler+1;
            getInt(&auxAlquiler.fechaAlquiler.dia,"\nIngrese la fecha del alquiler","\nERROR\n",1,31,4);
            getInt(&auxAlquiler.fechaAlquiler.mes,"\nIngrese el mes del alquiler\n","\nERROR\n",1,12,4);
            getInt(&auxAlquiler.fechaAlquiler.anio,"\nIngrese el anio del alquiler\n","\nERROR\n",1900,2019,4);
            auxAlquiler.isEmpty=0;


            getChar(&rta,"\nIngrese s para confirmar el alta\n","\nERROR\n",'a','z',3);

            if(rta == 's' || rta == 'S')
            {
                alquiler[idAlquiler]=auxAlquiler;
                retorno=0;
            }
            else
            {
                printf("\nNo se ha dado de alta el alquiler\n");
                system("pause");
            }

        }
        else
        {
            printf("\nNo se ha encontrado el juego deseado");
            system("pause");
        }

    }
    else
    {
        printf("\nNo se ha encontrado al cliente");
    }

    return retorno;



}

/** \brief Ordena a los clientes de manera ascendente.
* \param cliente eClientes* puntero al array de clientes
* \param len int Indica el largo del array
* \param
*/

void sortClientes(eClientes *cliente, int len)
{
    int i, j;
    eClientes auxCliente;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {

                if(strcmp(cliente[i].apellido, cliente[j].apellido) > 0)
                {
                    auxCliente = cliente[i];
                    cliente[i] = cliente[j];
                    cliente[j] = auxCliente;
                }
                if(strcmp(cliente[i].apellido, cliente[j].apellido) > 0)
                {
                    auxCliente = cliente[i];
                    cliente[i] = cliente[j];
                    cliente[j] = auxCliente;
                }


        }
    }
}

/** \brief Ordena a los juegos de manera ascendente.
* \param juego eJuegos* puntero al array de clientes.
* \param len int Indica el largo del array.
* \param
*/
void sortJuegos(eJuegos *juego, int len)
{
    int i, j;
    eJuegos auxJuego;
    for(i=0; i<len-1; i++)
    {
        for(j=i+1; j<len; j++)
        {

                if(strcmp(juego[i].descripcion, juego[j].descripcion) > 0)
                {
                    auxJuego = juego[i];
                    juego[i] = juego[j];
                    juego[j] = auxJuego;
                }



        }
    }
}
void printAlquiler(eAlquileres alquiler)
{

            printf("\n%10d %10d %10d %10d %10d %10d\n", alquiler.id, alquiler.idCliente, alquiler.idJuego, alquiler.fechaAlquiler.dia ,alquiler.fechaAlquiler.mes, alquiler.fechaAlquiler.anio);


}

void printAlquileres(eAlquileres *alquiler, int lenAlquiler)
{
    int i;

    for(i=0;i<lenAlquiler;i++)
    {
        if(alquiler[i].isEmpty==0)
        {
        printAlquiler(alquiler[i]);
        }
    }

}
/*void calculatesalarioInfo(eEmployee emp[], int len)
{
    int i;
    int employeeCounter = 0;
    int employeeExceedCounter = 0;
    float salarioAcumulator = 0;
    float averagesalario;
    for(i=0; i<len; i++)
    {
        if(emp[i].isEmpty == 0)
        {
            salarioAcumulator += emp[i].salario;
            employeeCounter++;
        }
    }
    averagesalario = salarioAcumulator / employeeCounter;
    for(i=0; i<len; i++)
    {
        if(emp[i].salario > averagesalario && emp[i].isEmpty == 0)
        {
            employeeExceedCounter++;
        }
    }
    printf("Total de salarios: $%.2f | Promedio de salarios: $%.2f | Empleados que superan el promedio: %d\n\n", salarioAcumulator, averagesalario, employeeExceedCounter);
    system("pause");
}*/


