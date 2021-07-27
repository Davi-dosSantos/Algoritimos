#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false = 0,
    true = !false
} bool;

typedef struct
{
    char nome[30], sexo[2];
    int idade;
    float altura, peso;
} stPaciente;

void ExibirPacientesMaisPesado(stPaciente paciente[20])
{
    int maiorPeso = 0;
    int maiorPesoIndex = -1;

    for (int i = 0; i < 20; i++)
        if (strcmp(paciente[i].sexo, "f") == 0 || strcmp(paciente[i].sexo, "m") == 0)
        {
            if (paciente[i].peso > maiorPeso)
            {
                maiorPeso = paciente[i].peso;
                maiorPesoIndex = i;
            }
        }
    printf("Nome: %s\n", paciente[maiorPesoIndex].nome);
    printf("Idade: %d\n", paciente[maiorPesoIndex].idade);
    return;
}

void CadastrarPaciente(stPaciente paciente[20], int id)
{
    int select = 0;

    char nome[30];
    getchar();
    printf("ID = %d\n", id);
    printf("Digite nome: ");
    gets(paciente[id].nome);

    while (true)
    {
        printf("Digite o sexo 'm'(masculino) ou 'f'(feminino): ");
        scanf("%s", &paciente[id].sexo);
        if (strcmp(paciente[id].sexo, "f") == 0)
            break;
        if (strcmp(paciente[id].sexo, "m") == 0)
            break;
    }

    printf("Digite a idade: ");
    scanf("%d", &paciente[id].idade);

    printf("Digite o peso(kg): ");
    scanf("%f", &paciente[id].peso);

    printf("Digite o altura(m): ");
    scanf("%f", &paciente[id].altura);

    printf("Deseja adicionar mais algum paciente? (1 - comfirmar): ");
    scanf("%d", &select);
    if (select == 1)
    {
        id++;
        CadastrarPaciente(paciente, id);
    }
    id++;
    return;
}

void ExibirPacientesAbaixoDoPeso(stPaciente paciente[20])
{
    printf("Pacientes ABAIXO do peso ideal:\n");
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(paciente[i].sexo, "f") == 0 || strcmp(paciente[i].sexo, "m") == 0)
        {
            if (strcmp(paciente[i].sexo, "m") == 0)
                if (paciente[i].peso < ((72.7 * paciente[i].altura) - 58))
                {
                    printf("Nome: %s\n", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Peso Ideal: %f\n", ((72.7 * paciente[i].altura) - 58));
                }
            if (strcmp(paciente[i].sexo, "f") == 0)
                if (paciente[i].peso < ((62.1 * paciente[i].altura) - 44.7))
                {
                    printf("Nome: %s\n", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Peso Ideal: %f\n", ((62.1 * paciente[i].altura) - 44.7));
                }
        }
    }
    return;
}

void ExibirPacientesAcimaDoPeso(stPaciente paciente[20])
{
    printf("Pacientes ACIMA do peso ideal:\n");
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(paciente[i].sexo, "f") == 0 || strcmp(paciente[i].sexo, "m") == 0)
        {
            if (strcmp(paciente[i].sexo, "m") == 0)
                if (paciente[i].peso > ((72.7 * paciente[i].altura) - 58))
                {
                    printf("Nome: %s\n", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Peso Ideal: %f\n", ((72.7 * paciente[i].altura) - 58));
                }
            if (strcmp(paciente[i].sexo, "f") == 0)
                if (paciente[i].peso > ((62.1 * paciente[i].altura) - 44.7))
                {
                    printf("Nome: %s\n", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Peso Ideal: %f\n", ((62.1 * paciente[i].altura) - 44.7));
                }
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    int id = 0;
    bool executa = true;
    int opcao = 0;
    stPaciente paciente[20];

    while (executa)
    {
        printf("1. cadastrar paciente. \n2. visualizar todos os pacientes acima do peso. \n3. visualizar todos os pacientes abaixo do peso.\n4. visualizar o paciente mais pesado. \n5. sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            CadastrarPaciente(paciente, id);
            break;

        case 2:
            ExibirPacientesAcimaDoPeso(paciente);
            break;

        case 3:
            ExibirPacientesAbaixoDoPeso(paciente);
            break;

        case 4:
            ExibirPacientesMaisPesado(paciente);
            break;

        case 5:
            executa = false;
            break;
        default:
            printf("Opcao invalida!!\n");
            break;
        }
    }

    return 0;
}