#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Empresa.h"


static int generarNextId()
{
    static int id = 0;

    id ++;

    return id;
}

/// GENERAR MEMORIA ///

eCliente* clienteNuevo()
{
    return (eCliente*) calloc(1, sizeof(eCliente));
}

eAbono* abonoNuevo()
{
    return (eAbono*) calloc(1, sizeof(eAbono));
}


/// ASIGNAR PARAMETROS ///

eCliente* newParametrosCliente(char* idStr, char* nombreStr, char* sexoStr, char* numeroTelefonicoStr, char* importeStr)
{
    eCliente* pCliente = clienteNuevo();

    if(pCliente != NULL)
    {
        setIdCliente(pCliente, atoi(idStr));
        setNombreCliente(pCliente, nombreStr);
        setSexo(pCliente, sexoStr);
        setNumeroTelefonico(pCliente, numeroTelefonicoStr);
        setImporte(pCliente, atoi(importeStr));
    }
    return pCliente;
}


/// ID CLIENTE ///

int setIdCliente(eCliente* this,int id)
{
    int indice = 0;

    if(this != NULL && id > 0)
    {
        this -> id = id;
        indice = 1;
    }
    return indice;
}

int getIdCliente(eCliente* this,int* id)
{
    int indice = 0;

    if(this != NULL)
    {
        *id = this -> id;
        indice = 1;
    }
    return indice;
}


/// NOMBRE CLIENTE ///

int setNombreCliente(eCliente* this,char* nombre)
{
    int indice = 0;

    if(this != NULL && strlen(nombre))
    {
        strcpy(this -> nombre, nombre);
        indice = 1;
    }
    return indice;
}

int getNombreCliente(eCliente* this,char* nombre)
{
    int indice = 0;
    if(this != NULL)
    {
        strcpy (nombre, this->nombre);
        indice = 1;
    }
    return indice;
}


/// SEXO ///

int setSexo(eCliente* this, char* sexo)
{
    int indice = 0;

    if(this != NULL && strlen(sexo))
    {
            strcpy(this->sexo, sexo);
            indice = 1;
    }
    return indice;
}

int getSexo(eCliente* this, char* sexo)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (sexo, this -> sexo);
        indice = 1;
    }
    return indice;
}


/// NUMERO TELEFONICO ///

int setNumeroTelefonico(eCliente* this, char* numeroTelefonico)
{
    int indice = 0;

    if(this != NULL && strlen(numeroTelefonico))
    {
        strcpy(this -> numeroTelefonico, numeroTelefonico);
        indice = 1;
    }
    return indice;
}

int getNumeroTelefonico(eCliente* this, char* numeroTelefonico)
{
    int indice = 0;

    if(this != NULL)
    {
        strcpy (numeroTelefonico, this -> numeroTelefonico);
        indice = 1;
    }
    return indice;
}


/// IMPORTE ///

int setImporte(eCliente* this, int importe)
{
    int indice = 0;
    if(this != NULL )
    {
        if(importe > 0)
        {
            this -> importe = importe;
            indice = 1;
        }
    }
    return indice;
}

int getImporte(eCliente* this, int* importe)
{
    int indice = 0;
    if(this != NULL)
    {
        *importe = this -> importe;
        indice = 1;
    }
    return indice;
}


/// ID ABONO ///

int setIdAbono(eAbono* this, int id)
{
    int indice = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        indice = 1;
    }
    return indice;
}

int getIdAbono(eAbono* this, int* id)
{
    int indice = 0;

    if (this != NULL)
    {
        *id = this->id;
        indice = 1;
    }
    return indice;
}


/// TIPO ABONO ///

int setTipoAbono(eAbono* this, int tipo)
{
    int indice = 0;
    if(this != NULL)
    {
        if(tipo > 0)
        {
            this -> tipo = tipo;
            indice = 1;
        }
    }
    return indice;
}


int getTipoAbono(eAbono* this, int* tipo)
{
    int indice = 0;

    if (this != NULL)
    {
        *tipo = this -> tipo;
        indice = 1;
    }
    return indice;
}


/// ID CLIENTE ABONO ///

int setIdAbonoCliente(eAbono* this, int idCliente)
{
    int indice = 0;

    if(this != NULL && idCliente > 0)
    {
        this -> idCliente = idCliente;
        indice = 1;
    }
    return indice;
}

int getIdAbonoCliente(eAbono* this ,int* idCliente)
{
    int indice = 0;
    if (this != NULL)
    {
        *idCliente = this -> idCliente;
        indice = 1;
    }
    return indice;
}


/// IMPORTE FINAL ABONO ///

int setImporteFinalAbono (eAbono* this, float importeFinal)
{
    int indice = 0;

    if(this != NULL && importeFinal > 0)
    {
        this -> importeFinal = importeFinal;
        indice = 1;
    }
    return indice;
}

int getImporteFinalAbono(eAbono* this, float* importeFinal)
{
    int indice = 0;

    if (this != NULL)
    {
        *importeFinal = this -> importeFinal;
        indice = 1;
    }
    return indice;
}


/// ORDFENAR ///

int sortByIdAbono(void* idA, void* idB)
{
    int indice;
    eCliente* idAuxA = NULL;
    eCliente* idAuxB = NULL;

    if((idAuxA != NULL )&& (idAuxB != NULL))
    {
        idAuxA = (eCliente*) idAuxA;
        idAuxB = (eCliente*) idAuxB;
        if(idAuxA -> id == idAuxB -> id)
        {
             indice = 1;
        }
        if(idAuxA -> id > idAuxB->id)
        {
            indice = -1;
        }
        if(idAuxA -> id < idAuxB -> id)
        {
            indice = 0;
        }
    }
    return indice;
}

int sortByImporteAbono(void* importeA, void* importeB)
{
    int indice;

    eAbono* impA = NULL;
    eAbono* impB = NULL;

    if((impA != NULL )&& (impB != NULL))
    {
        impA = (eAbono*) impA;
        impB = (eAbono*) impB;
        if(impA -> importeFinal == impB -> importeFinal)
        {
             indice = 1;
        }
        else if(impA -> importeFinal > impB -> importeFinal)
        {
            indice = -1;
        }
        else if(impA -> importeFinal < impB -> importeFinal)
        {
            indice = 0;
        }
    }
    return indice;
}

LinkedList* crearListaAbono (LinkedList* this)
{
    eAbono* abono;
    eCliente* clienteActual;
    eCliente* siguenteCliente;
    LinkedList* listaAbono = ll_newLinkedList();
    int contador = 0;
    int importeTotal = 0;
    int i;

    if(this != NULL)
    {
        for(i = 0; i < ll_len(this); i++)
        {
            clienteActual = (eCliente*) ll_get(this, i);
            if(i + 1 < ll_len(this))
            {
                siguenteCliente = (eCliente*) ll_get(this, i);
                contador ++;
                importeTotal = importeTotal + clienteActual -> importe;

                if((clienteActual ->id != siguenteCliente -> id) || i + 1 == ll_len(this))
                {
                    abono = abonoNuevo();
                    if (contador == 1)
                    {
                        setTipoAbono(abono, PERSONAL);
                        setImporteFinalAbono(abono, importeTotal);
                        setIdAbonoCliente(abono, clienteActual -> id);
                        abono -> idCliente = generarNextId();
                    }
                    else if(contador >= 2 && contador <= 4)
                    {
                        setTipoAbono(abono, FAMILIAR);
                        setImporteFinalAbono(abono, importeTotal);
                        setIdAbonoCliente(abono, clienteActual -> id);
                        abono -> idCliente = generarNextId();
                    }
                    else if (contador >= 5)
                    {
                        setTipoAbono(abono, CORPORATIVO);
                        setImporteFinalAbono(abono, importeTotal);
                        setIdAbonoCliente(abono, clienteActual -> id);
                        abono -> idCliente = generarNextId();
                    }
                    }
                    ll_add(listaAbono, abono);
                    contador = 0;
                    importeTotal = 0;
                }
            }
        }

    return listaAbono;
}









