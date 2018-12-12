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

int controller_listAbonos(LinkedList* this, LinkedList* this2)
{
    eAbono* auxiliarAbono;
    eCliente* auxiliarCliente;
    int indice = -1;
    int largoListaDos = ll_len(this2);
    int idAuxAbono;
    int tipoAuxAbono;
    int idClienteAuxAbono;
    int importeFinalAuxAbono;
    char nombreAuxCliente[50];
    char sexoAuxCliente[2];
    char numeroTelefonicoAuxCliente[21];
    int importeAuxCliente, i, j;


    if(this != NULL)
    {
        if(ll_len(this) > 0)
        {
            printf(" Id\t\tTipo\t\tId Cliente\t Importe Total   \n");

            for(i = 0; i < ll_len(this); i++)
            {
                auxiliarAbono = (eAbono*)ll_get(this, i);
                getIdAbono(auxiliarAbono, &idAuxAbono);
                getTipoAbono(auxiliarAbono, &tipoAuxAbono);
                getIdAbonoCliente(auxiliarAbono, &idClienteAuxAbono);
                getImporteFinalAbono(auxiliarAbono, &importeFinalAuxAbono);
                printf("%3d\t\t  %d\t\t    %d\t\t    %d\t\t  \n", idAuxAbono, tipoAuxAbono, idClienteAuxAbono, importeFinalAuxAbono);

                for(j = i + 1; j <largoListaDos ; j++)
                {
                    auxiliarCliente = (eCliente*)ll_get(this2, j);
                    if(auxiliarAbono -> idCliente == auxiliarCliente -> id)
                    {
                        getNombreCliente(auxiliarCliente, nombreAuxCliente);
                        getSexo(auxiliarCliente, sexoAuxCliente);
                        getNumeroTelefonico(auxiliarCliente,numeroTelefonicoAuxCliente);
                        getImporte(auxiliarCliente, &importeAuxCliente);
                        printf("%-3s\t    %s\t     %-s\t      %d\t \n", nombreAuxCliente, sexoAuxCliente, numeroTelefonicoAuxCliente, importeAuxCliente );
                    }
                }
            }
            indice = 1;
        }
        else
        {
            printf("No se cargaron los datos.\n");
        }

    }
    return indice;
}

int controller_saveAsText(char* path, LinkedList* pArrayAbono)
{
    int indice = 0;
    int largoLista = ll_len(pArrayAbono);
    eAbono* pArrayAbonoAux;
    FILE* fp = fopen(path, "w");
    int i;
    if(fp==NULL)
    {
        printf("Error al abrir archivo para guardar\n");
        return indice;
    }
    fprintf(fp, "Id,Tipo,Id Cliente,Importe final\n");
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pArrayAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fprintf(fp, "%d,%d,%d,%f\n", pArrayAbonoAux->id, pArrayAbonoAux->tipo, pArrayAbonoAux->idCliente, pArrayAbonoAux->importeFinal);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        indice = 1;
    }
    fclose(fp);
    return indice;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayAbono)
{
    int indice = 0;
    int largoLista = ll_len(pArrayAbono);
    eAbono* pAbonoAux;
    FILE* fp = fopen(path, "wb");
    int i;
    if(fp==NULL)
    {
        printf("Error al guardar\n");
        return indice;
    }
    if(pArrayAbono!=NULL)
    {
        for(i = 0; i < largoLista; i++)
        {
            pAbonoAux = (eAbono*)ll_get(pArrayAbono, i);
            fwrite(pAbonoAux, sizeof(eAbono), 1, fp);
        }
        printf("Se ha realizado el guardado del archivo con exito !\n");
        indice = 1;
    }
    fclose(fp);
    return indice;
}




