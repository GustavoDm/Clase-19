#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "cliente.h"
#include "getsValids.h"

Cliente* cliente_new(void)
{

    Cliente* returnAux = (Cliente*) malloc(sizeof(Cliente));
    return returnAux;

}

void cliente_delete(Cliente* this)
{
    if(this != NULL)
        free(this);
}

int cliente_setId(Cliente* this, int id)
{
    static int ultimoId = -1;
    int retorno = -1;
    if(this != NULL && id == -1)
    {
        retorno = 0;
        ultimoId++;
        this->id = ultimoId;
    }
    else if(this != NULL && id > ultimoId)
    {
        retorno = 0;
        ultimoId = id;
        this->id = ultimoId;
    }
    return retorno;
}

int cliente_getId(Cliente* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        retorno = 0;
        *id = this->id;
    }
    return retorno;
}

int cliente_setNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL && val_letras(nombre))
    {
        retorno = 0;
        strcpy(this->nombre,nombre);
    }
    return retorno;
}

int cliente_getNombre(Cliente* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        retorno = 0;
        strcpy(nombre,this->nombre);
    }
    return retorno;
}

int cliente_setApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && !val_letras(apellido))
    {
        retorno = 0;
        strcpy(this->apellido,apellido);
    }
    return retorno;
}

int cliente_getApellido(Cliente* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido != NULL && !val_letras(apellido))
    {
        retorno = 0;
        strcpy(apellido,this->apellido);
    }
    return retorno;
}

int cliente_setEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && !val_email(email))
    {
        retorno = 0;
        strcpy(this->email,email);
    }
    return retorno;
}

int cliente_getEmail(Cliente* this, char* email)
{
    int retorno = -1;
    if(this != NULL && email != NULL && !val_email(email))
    {
        retorno = 0;
        strcpy(email,this->email);
    }
    return retorno;
}

int cliente_setGenero(Cliente* this, char *genero)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        this->genero=*genero;
    }
    return retorno;
}

int cliente_getGenero(Cliente* this, char *genero)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = 0;
        *genero=this->genero;
    }
    return retorno;
}

int cliente_setProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL && !val_letras(profesion))
    {
        retorno = 0;
        strcpy(this->profesion,profesion);
    }
    return retorno;
}

int cliente_getProfesion(Cliente* this, char* profesion)
{
    int retorno = -1;
    if(this != NULL && profesion != NULL && !val_letras(profesion))
    {
        retorno = 0;
        strcpy(profesion,this->profesion);
    }
    return retorno;
}

int cliente_setUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL && !val_alfaNumerico(usuario))
    {
        retorno = 0;
        strcpy(this->usuario,usuario);
    }
    return retorno;
}

int cliente_getUsuario(Cliente* this, char* usuario)
{
    int retorno = -1;
    if(this != NULL && usuario != NULL && !val_alfaNumerico(usuario))
    {
        retorno = 0;
        strcpy(usuario,this->usuario);
    }
    return retorno;
}

int cliente_setNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad != NULL && !val_letras(nacionalidad))
    {
        retorno = 0;
        strcpy(this->nacionalidad,nacionalidad);
    }
    return retorno;
}

int cliente_getNacionalidad(Cliente* this, char* nacionalidad)
{
    int retorno = -1;
    if(this != NULL && nacionalidad!= NULL && !val_letras(nacionalidad))
    {
        retorno = 0;
        strcpy(nacionalidad,this->nacionalidad);
    }
    return retorno;
}

Cliente* cliente_newParametros( char *nombre, char *apellido, char *email, char *genero, char *profesion, char *usuario, char *nacionalidad, int id)
{

   Cliente* this;


    this = cliente_new();
    if( !cliente_setId(this,id) &&
        !cliente_setNombre(this,nombre) &&
        !cliente_setApellido(this,apellido) &&
        !cliente_setEmail(this,email) &&
        !cliente_setGenero(this, genero) &&
        !cliente_setProfesion(this, profesion) &&
        !cliente_setUsuario(this, usuario) &&
        !cliente_setNacionalidad(this, nacionalidad)
       )
    {
        return this;
    }
    cliente_delete(this);
    return NULL;
}
