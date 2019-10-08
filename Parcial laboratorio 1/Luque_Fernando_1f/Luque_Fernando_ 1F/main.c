#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"

#define CANT_CLIENTES 100
#define CANT_JUEGOS 9
#define CANT_ALQUILERES 900

int main()
{

    eAlquileres alquiler[CANT_ALQUILERES];

    eClientes cliente [CANT_CLIENTES];

    eJuegos juego[CANT_JUEGOS]={{1,"Juego1",100},
                    {2,"Juego2",150},
                    {3,"Juego3",125},
                    {4,"Juego4",150},
                    {5,"Juego5",200},
                    {6,"Juego6",225},
                    {7,"Juego7",230},
                    {8,"Juego8",175},
                    {9,"Juego9",300}};


    initClientes(cliente,CANT_CLIENTES);
    initAlquileres(alquiler,CANT_ALQUILERES);

    int opcMenu;
    int seguir;
    int contadorClientes=0;
    int idCliente=0;
    int idAlquiler=0;
    int index;
    int indexAlquiler;
    int removed;



    do
    {
        system("cls");

        getInt(&opcMenu,"\nCLIENTES:\n1. Altas\n2. Modificar\n3. Baja\n4. Listar\n\nJUEGOS:\n5. Listar\n\nALQUILERES:\n6. Alta de alquiler\n\n7. Salir\n\nIngrese la opcion a realizar: ","Opcion no valida",1,7,1);
        switch(opcMenu)
            {


            case 1:
               index=addClientes(cliente,CANT_CLIENTES,idCliente);

               if(index!=-1)
               {
                   printf("Se ha dado de alta al cliente\n");
                   system("pause");
                   contadorClientes++;
                   idCliente++;
               }
               else
                {
                    printf("No se ha dado de alta\n");
                }
                break;


            case 2:
                if(contadorClientes>0)
                {
                    modifyCliente(cliente,CANT_CLIENTES);
                }
                else
                {
                    printf("No hay clientes en el sistema");
                    system("pause");
                }
                break;


            case 3:
                if(contadorClientes>0)
                {
                    removed=removeCliente(cliente,CANT_CLIENTES);
                    if(removed!=-1)
                    {
                        contadorClientes--;
                    }
                }
                else
                {
                    printf("No hay clientes en el sistema");
                    system("pause");
                }
                break;


            case 4:
                if(contadorClientes>0)
                {
                    printAllClientes(cliente,CANT_CLIENTES);
                    system("pause");
                }
                else
                {
                    printf("No hay clientes en el sistema");
                    system("pause");
                }
                break;

            case 5:
                sortJuegos(juego,CANT_JUEGOS);
                printJuegos(juego,CANT_JUEGOS);
                system("pause");
                break;

            case 6:
                indexAlquiler=addAlquiler(alquiler,cliente,CANT_CLIENTES,juego,CANT_JUEGOS,idAlquiler);

                if(indexAlquiler!=-1)
                {
                        printf("\nSe ha dado de alta correctamente el alquiler\n");
                        system("pause");
                        idAlquiler++;
                        printAlquileres(alquiler,CANT_ALQUILERES);
                        system("pause");
                }

                break;

            case 7:
                seguir=0;
                break;
            }

    }while(seguir!=0);


    return 0;
}
