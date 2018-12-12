#include "LinkedList.h"
#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2

typedef struct
{
    int id;
    char nombre [51]; //Maximo 51 caracteres
    char sexo[5]; // F o M
    char numeroTelefonico[21];
    int importe;
}eCliente;


typedef struct
{
    int id; //Autonumerico
    int tipo; // >=0
    int idCliente; // >=0
    float importeFinal;
}eAbono;


/// GENERAR MEMORIA ///

eCliente* clienteNuevo();

eAbono* abonoNuevo();


/// ASIGNAR PARAMETROS ///

eCliente* newParametrosCliente(char*, char*, char*, char*, char*);


/// ID CLIENTE ///

int setIdCliente(eCliente*, int );

int getIdCliente(eCliente*, int*);


/// NOMBRE CLIENTE ///

int setNombreCliente(eCliente*, char*);

int getNombreCliente(eCliente*, char*);


/// SEXO ///

int setSexo(eCliente*, char*);

int getSexo(eCliente*, char*);


/// NUMERO TELEFONICO ///

int setNumeroTelefonico(eCliente*, char*);

int getNumeroTelefonico(eCliente*, char*);


/// IMPORTE ///

int setImporte(eCliente*, int);

int getImporte(eCliente*, int*);


/// ID ABONO ///

int setIdAbono(eAbono*, int);

int getIdAbono(eAbono*, int*);


/// TIPO ABONO ///

int setTipoAbono(eAbono*, int);

int getTipoAbono(eAbono*, int*);


/// ID CLIENTE ABONO ///

int setIdAbonoCliente(eAbono*, int);

int getIdAbonoCliente(eAbono*, int*);


/// IMPORTE FINAL ABONO ///

int setImporteFinalAbono (eAbono*, float);

int getImporteFinalAbono(eAbono*, float*);


/// ORDFENAR ///

int sortByIdAbono(void*, void*);

int sortByImporteAbono(void*, void*);

LinkedList* crearListaAbono(LinkedList*);






