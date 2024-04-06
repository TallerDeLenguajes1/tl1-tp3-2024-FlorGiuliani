/*2) Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna es un mes. Ud. debe realizar las siguientes tareas: 
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MESES 12
#define ANIOS 5

int main()
{
    int produccion[ANIOS][MESES], promedio[ANIOS];
    int max=0, min=51000, mesMax, anioMax, mesMin, anioMin;

    srand(time(NULL));
    for (int i = 0; i < ANIOS; i++)
    {
        promedio[i] = 0;
        for (int j = 0; j < MESES; j++)
        {
            produccion[i][j] = 10000 + rand() % (50000-10000+1);
            printf("%d\t", produccion[i][j]);
            promedio[i] += produccion[i][j];

            if (produccion[i][j] > max)
            {
                max = produccion[i][j];
                anioMax = i+1;
                mesMax = j+1;
            }
            if (produccion[i][j] < min)
            {
                min = produccion[i][j];
                anioMin = i+1;
                mesMin = j+1;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < ANIOS; i++)
    {
        printf("El promedio de ganancias en el año %d es: %d \n", i+1, promedio[i]/12);
    }
    
    printf("La mayor producción obtenida fue en el año %d, en el mes %d y fue de %d \n", anioMax, mesMax, max);
    printf("La menor producción obtenida fue en el año %d, en el mes %d y fue de %d \n", anioMin, mesMin, min);

    return 0;
}