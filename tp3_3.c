/*3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria) (Lea las notas 1 y 2)*/

#include <stdio.h>
#include <stdlib.h> //malloc
#include <string.h> //strlen , strcpy

int main()
{
    int cant = 5;
    char **nombres = (char **)malloc(cant * sizeof(char*));
    char *Buff = (char *)malloc(100 * sizeof(char)); //variable auxiliar 

    for (int i = 0; i < cant; i++)
    {
        printf("Ingrese un nombre: ");
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