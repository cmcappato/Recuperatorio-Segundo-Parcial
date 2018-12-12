#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empresa.h"

/** \brief Parsea los datos los datos de los clientes desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCliente LinkedList*
 * \return int
 *
 */
int parser_ClientFromText(FILE* pFile , LinkedList* cliente)
{
    eCliente* pCliente = clienteNuevo();
    int cantidad;
    char id[20];
    char nombre[51];
    char sexo[20];
    char numeroTelefono[21];
    char importe[20];
    int i = 0;

    if(pFile != NULL)
    {
        cantidad = fscanf(pFile ,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, sexo, numeroTelefono, importe);
        do
        {
            cantidad = fscanf(pFile ,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, sexo, numeroTelefono, importe);

            if(cantidad == 5)
            {
                pCliente = newParametrosCliente(id, nombre, sexo, numeroTelefono, importe);

                if (pCliente != NULL)
                {
                    ll_add (cliente, pCliente);
                }
                else
                {
                    printf("No hay mas espacio en memoria");
                }
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
    }
    return i;
}
