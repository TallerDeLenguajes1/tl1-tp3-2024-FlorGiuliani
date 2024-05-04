/*5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación. */

#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //strlen , strcpy

int main()
{
    //int cant = 5;
    int cant;
    printf("Cuantos nombres desea cargar? ");
    scanf("%d", &cant);

    char **nombres = (char **)malloc(cant * sizeof(char*));
    char *Buff = (char *)malloc(100 * sizeof(char)); //variable auxiliar 

    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese un nombre: ");
        fflush(stdin);
        gets(Buff);
        nombres[i] = (char *)malloc(sizeof(char) * (strlen(Buff)+1));
        strcpy(nombres[i], Buff);
    }

    for (int i = 0; i < cant; i++)
    {
        printf("%s\n", *(nombres + i));
    }

    free(Buff);
    free(nombres);
    
    return 0;
}