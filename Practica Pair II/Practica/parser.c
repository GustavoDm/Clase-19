#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Cliente.h"


int parserCliente(FILE  *pFile , ArrayList* pArrayListEmployee)
{

    int retorno =-1;

    char nombre[64];
    char apellido[64];
    char email[256];
    char genero;
    char profesion[256];
    char usuario[256];
    char nacionalidad[256];
    char id[254];

    if(pFile != NULL)
    {
        retorno = 0;
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
               ,nombre,apellido,email,genero,profesion,usuario,nacionalidad,id);


        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n"
               ,nombre,apellido,email,genero,profesion,usuario,nacionalidad,id);

            al_add(pArrayListEmployee,
            cliente_newParametros(nombre,apellido,email,genero,profesion,usuario,nacionalidad,id));
        }
    }
}
