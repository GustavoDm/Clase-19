#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Cliente.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Cargar datos desde data.csv
        2. Listar Clientes
        3. Ordenar por nombre y apellido
        4. Ordenar por mail
        5. Agregar un Cliente
        6. Elimina un Cliente
        7. Modificar Cliente (Nombre, Apellido y Mail)
        8. Listar Clientes
        9. Guardar datos en data.csv (modo texto)
       10. Guardar datos en data.bin (modo binario)
*****************************************************/


int main()
{
    FILE* pFile;
    pFile = fopen("data.csv","r");
    ArrayList* pArrayClientes;

    pArrayClientes = al_newArrayList();
    parserCliente("data.csv", pArrayClientes);

    int menu;

    switch(menu)
    {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;


    }






    return 0;
}
