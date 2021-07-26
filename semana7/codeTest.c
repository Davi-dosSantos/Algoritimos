#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef enum
{
    false = 0,
    true = !false
} bool;

int main(int argc, char *argv[])
{
    int vet[10];
    bool verifica = false;

    for (int i = 0; i < 10; i++)
    {

        printf("incira o valor do vetor na posicao %d: ", i);
        scanf("%d", &vet[i]);

        if (vet[i] > 50)
        {
            printf("elemento: %d , indice: %d \n", vet[i], i);
            verifica = true;
        }
    }

    printf("Vetor gerado : \n [ ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", vet[i]);
    }
    printf("] \n");

    if (!verifica)
    {
        printf("Nenhum elemento maior que 50 encontrado");
    }

    return 0;
}