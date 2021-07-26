#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int MENORELEM(int n[6][6])
{
    int menorElement = 999;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {

            if (i == 5 - j)
            {
                if (n[i][j] < menorElement)
                {
                    menorElement = n[i][j];
                }
            }
        }
        printf("\n");
    }
    return menorElement;
}

int main(int argc, char *argv[])
{
    int mat[6][6], i, j;

    ////Com numeros aleatorios
    srand(time(NULL));
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            mat[i][j] = (rand() % 99) + 1;
        }
    }

    ////com inserção de valores
    // for (i = 0; i < 6; i++)
    // {
    //     for (j = 0; j < 6; j++)
    //     {
    //         printf("incira o valor da posicao %dx%d: ", i, j);
    //         scanf("%d", &mat[i][j]);
    //     }
    // }

    printf("Matriz inicial:\n");

    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%3d | ", mat[i][j]);
        }
        printf("\n");
    }

    printf("O menor Elemento da diagonal secundaria:%d", MENORELEM(mat));

    return 0;
}