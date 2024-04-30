/*3) Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una vez cargados sean listados por pantalla (Todo implementando reserva dinámica de memoria) (Lea las notas 1 y 2)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cant = 5;
    char *Buff = (char *)malloc(100 * sizeof(char)); //variable auxiliar
    char **nombres = (char **)malloc(cant * sizeof(char*));

    for (int i = 0; i < cant; i++)
    {
        char *filaNombres[i] = (char *)malloc(100 * sizeof(char));
        printf("Ingrese un nombre: ");
        gets(Buff);
        free(Buff);
    }

    free(nombres);
    
    return 0;
}