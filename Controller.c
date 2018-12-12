#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empresa.h"
#include "utn.h"
#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* this)
{
    int indice = 0;
    FILE* fp = fopen( path, "r");

    if(fp != NULL && this != NULL)
    {
        parser_ClientFromText(fp, this);
        indice = 1;
        printf("Archivo cargado con exito\n");
    }
    else
    {
        printf("El archivo no se pudo cargar.\n");
        fclose(fp);
    }
    fclose(fp);
    return indice;
}
int controller_List(LinkedList* this)
{
    eCliente* pCliente;
    int indice = 0;
    int auxId;
    char auxNombre[50];
    char auxSexo[5];
    char auxNumeroTelefonico[21];
    int auxImporte;
    int i;

    if(this != NULL && ll_len(this) > 0)
    {
        printf("Id\t\tNombre\t\tSexo\tNumero telefonico\tImporte \n");
        for(i = 0; i < ll_len(this); i++)
        {
            pCliente = (eCliente*) ll_get(this, i);
            getIdCliente(pCliente, &auxId);
            getNombreCliente(pCliente, auxNombre);
            getSexo(pCliente, auxSexo);
            getNumeroTelefonico(pCliente, auxNumeroTelefonico);
            getImporte(pCliente, &auxImporte);

            printf("%d%25s\t%s\t%s\t\t%d \n", auxId, auxNombre, auxSexo, auxNumeroTelefonico, auxImporte);
        }
        indice = 1;
    }
    else
    {
        printf("No se pudieron cargar los datos \n");
    }
    return indice;
}






