
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum
{
    false = 0,
    true = !false
} bool;

typedef struct
{
    char nome[30], sexo[1];
    int cpf;
    float altura, peso;
} stDadosPessoa;

int main(int argc, char *argv[])
{
    bool busca = false;
    int select = 0, cpfBusca = 0;
    stDadosPessoa pessoas[30];

    for (int i = 0; i < 30; i++)
    {
        printf("ID = %d\n", i);
        printf("Digite nome: ");
        scanf("%s", &pessoas[i].nome);

        printf("Digite o sexo: ");
        scanf("%s", &pessoas[i].sexo);

        printf("Digite o CPF: ");
        scanf("%d", &pessoas[i].cpf);

        printf("Digite o altura: ");
        scanf("%f", &pessoas[i].altura);

        printf("Digite o peso: ");
        scanf("%f", &pessoas[i].peso);

        printf("Deseja continuar adicionar mais usuarios?(1:sim,2:nao): ");
        scanf("%d", &select);
        if (select == 2)
            break;
    }
    printf("Digite o cpf do usuario que esta procuarando: ");
    scanf("%d", &cpfBusca);

    for (int i = 0; i < 30; i++)
    {
        if (cpfBusca == pessoas[i].cpf)
        {
            printf("ID = %d\n", i);
            printf("Nome: %s\n", pessoas[i].nome);
            printf("IMC: %2f\n", pessoas[i].peso / (pessoas[i].altura * pessoas[i].altura));
            printf("Sexo: %s\n", pessoas[i].sexo);
            printf("CPF: %d\n", pessoas[i].cpf);
            printf("Altura: %2f\n", pessoas[i].altura);
            printf("Peso: %2f\n", pessoas[i].peso);
            busca = true;
        }
    }
    if (!busca)
        printf("CPF nao encontrado!!\n");

    printf("finalizando programa !\n");
    return 0;
}