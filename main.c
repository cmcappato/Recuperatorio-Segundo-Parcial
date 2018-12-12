#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "Parser.h"
#include "Controller.h"

int main()
{
    int opcion;
    LinkedList* listadoClientes = ll_newLinkedList();
    LinkedList* listadoAbono;

    do
    {
        printf("******************************************************************************* \n");
        printf("1- Cargar los datos de los clientes desde el archivo clientes.csv (modo texto) \n");
        printf("2- Listar los clientes cargados \n");
        printf("3- Crear nueva lista con abonos \n");
        printf("4- Listar abono y cliente ordenado por importe \n");
        printf("5- Guardar los datos de los abonos en el archivo abonos.csv (modo texto) \n");
        printf("6- Guardar los datos de los abonos en el archivo abonos.bin (modo binario) \n");
        printf("10- Salir \n");
        printf("******************************************************************************* \n");
        printf("Elija una opcion: \n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                controller_loadFromText("clientes.csv", listadoClientes);
                ll_sort(listadoClientes, sortByIdAbono, 0);
                break;
            case 2:
                controller_List(listadoClientes);
                break;
            case 3:
                listadoAbono = crearListaAbono(listadoClientes);
                printf("Lista creada con exito \n");
                break;
            case 4:
                ll_sort(listadoAbono, sortByImporteAbono, 0);
                controller_listAbonos(listadoAbono, listadoClientes);
                break;
            case 5:
                controller_saveAsText("Abonos.csv", listadoAbono);
                break;
            case 6:
                controller_saveAsBinary("Abonos.bin", listadoAbono);
                break;
            case 10:
                printf("Gracias por utilizar el programa \n");
                break;
            default:
                printf("Error, ingrese una opcion del 1 al 10");
        }
        system("pause");
        system("cls");
    }while (opcion != 10);



    return 0;
}

