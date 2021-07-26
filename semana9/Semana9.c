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
    char nome[30];
    int numConta;
    float saldo;
} stContaCliente;

bool VerificaCliente(stContaCliente cliente[30], char nome[30], int numeroConta)
{
    int numCountPerUser = 0;
    int numNumConta = 0;

    for (int i = 0; i < 30; i++)
    {
        if (cliente[i].numConta == numeroConta)
            numNumConta++;

        if (strcmp(nome, cliente[i].nome) == 0)
            numCountPerUser++;
    }
    if (numCountPerUser > 15)
    {
        printf("Numero de contas do cliente excede 15!\n");
        return false;
    }
    if (numNumConta > 1)
    {
        printf("Numero de conta indisponivel!\n");
        return false;
    }

    return true;
}
void CadastrarContas(stContaCliente cliente[30])
{
    int select = 0;

    for (int i = 0; i < 30; i++)
    {
        char nome[30];
        getchar();
        printf("ID = %d\n", i);
        printf("Digite nome: ");
        gets(cliente[i].nome);

        printf("Digite o numero da conta: ");
        scanf("%d", &cliente[i].numConta);

        printf("Digite o saldo(R$): ");
        scanf("%f", &cliente[i].saldo);

        if (!VerificaCliente(cliente, cliente[i].nome, cliente[i].numConta))
        {
            cliente[i] = cliente[i + 1];
            i--;
        }
        printf("Deseja parar de adicionar usuarios? (1 - comfirmar): ");
        scanf("%d", &select);
        if (select == 1)
            break;
    }
    return;
}

void ExibirContas(stContaCliente cliente[30])
{

    bool clienteVerification = false;
    char nome[30] = "";
    getchar();
    printf("Digite o nome do cliente:");
    gets(nome);

    for (int i = 0; i < 30; i++)
    {
        if (strcmp(nome, cliente[i].nome) == 0)
        {
            clienteVerification = true;
            printf("ID = %d\n", i);
            printf("Nome: %s\n", cliente[i].nome);
            printf("Numero da conta: %d\n", cliente[i].numConta);
            printf("Saldo: %f R$\n", cliente[i].saldo);
        }
    }
    if (!clienteVerification)
    {
        printf("cliente não encontrado!! \n");
        return;
    }
    if (clienteVerification)
    {
        return;
    }
}

void ExcluirContaMenorSaldo(stContaCliente cliente[30])
{
    float menorValue = 999999.0;
    int menorIndex = -1;
    for (int i = 0; i < 30; i++)
    {
        if (cliente[i].saldo < menorValue)
        {
            menorValue = cliente[i].saldo;
            menorIndex = i;
        }
    }
    for (int i = menorIndex; i < 30 - menorIndex; i++)
    {
        cliente[i] = cliente[i + 1];
    }
    return;
}

int main(int argc, char *argv[])
{
    bool executa = true;
    int opcao = 0;
    stContaCliente cliente[30];

    while (executa)
    {
        printf("1. cadastrar conta. \n2. visualizar todas as contas de um determinado cliente. \n3. excluir a conta com menor saldo.\n4. sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            CadastrarContas(cliente);
            break;

        case 2:
            ExibirContas(cliente);
            break;

        case 3:
            ExcluirContaMenorSaldo(cliente);
            break;

        case 4:
            executa = false;
            break;
        default:
            printf("Opcao invalida!!\n");
            break;
        }
    }

    return 0;
}