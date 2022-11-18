#include <stdlib.h>
#include <stdio.h>
#define N 5

struct listaLinear
{
    int codigo;
    int valor;
};
typedef struct listaLinear listaLinear;

int menuLista(int op);
int inserirFinal(listaLinear LL[], int *inicioLista, int *finalLista, int inicioArranjo, int finalArranjo, listaLinear tipoLista);
int removerFinal(listaLinear LL[], int *inicioLista, int *finalLista, int inicioArranjo, int finalArranjo, listaLinear tipoLista);
int buscar(listaLinear LL[], listaLinear tipoLista, int *finalLista);
int mostrar(listaLinear LL[], int inicioLista, int *finalLista, int inicioArranjo, int *finalArranjo, listaLinear tipoLista);

void main()
{
    printf("Menu - Lista Linear \n");
    int op, inicioLista = -1, finalLista = -1, inicioArranjo = 0, finalArranjo = N - 1;
    listaLinear LL[N], tipoLista;
    tipoLista.codigo = 1;
    do
    {
        op = menuLista(op);
        switch (op)
        {
        case 1:
            if (tipoLista.codigo > N)
            {
                printf("lista cheia!!!");
                break;
            }
            printf("Codigo: %d\n", tipoLista.codigo);
            printf("Digite o valor: ");
            scanf("%d", &tipoLista.valor);
            inserirFinal(LL, &inicioLista, &finalLista, inicioArranjo, finalArranjo, tipoLista);
            printf("codigo: %d \nvalor: %d\n", tipoLista.codigo, tipoLista.valor);
            tipoLista.codigo++;
            break;

        case 2:
            removerFinal(LL, &inicioLista, &finalLista, inicioArranjo, finalArranjo, tipoLista);

            tipoLista.codigo--;
            break;

        case 3:
            buscar(LL, tipoLista, &finalLista);
            break;

        case 4:
            mostrar(LL, inicioArranjo, &inicioLista, finalArranjo, &finalLista, tipoLista);
            break;

        default:
            printf("Finalizado!!");
            break;
        }
    } while (op != 0);
}

int menuLista(int op)
{
    printf("\n------------------\n");
    printf("1 - Inserir no fim \n");
    printf("2 - Remover do fim \n");
    printf("3 - Buscar na lista \n");
    printf("4 - Mostrar lista\n");
    printf("0 - Encerrar\n");
    printf("Selecione uma opçao: ");
    scanf("%d", &op);
    return op;
}

int inserirFinal(listaLinear LL[], int *inicioLista, int *finalLista, int inicioArranjo, int finalArranjo, listaLinear tipoLista)
{
    if (inicioArranjo == *inicioLista && finalArranjo == *finalLista)
    {
        printf("lista cheia!!!");
        return 1;
    }
    else
    {
        if (*inicioLista == -1)
        {
            *inicioLista = *finalLista = inicioArranjo;
        }
        else if (*finalLista < finalArranjo)
        {
            *finalLista = *finalLista + 1;
        }
        else
        {
            for (int i = *inicioLista; i <= *finalLista; i++)
            {
                LL[i - 1] = LL[i];
            }
        }
        LL[*finalLista] = tipoLista;
        return 0;
    }
}

int buscar(listaLinear LL[], listaLinear tipoLista, int *finalLista)
{
    int aux, finalAux;
    printf("Digite o codigo: ");
    scanf("%d", &aux);

    finalAux = (*finalLista+1) / 2;
    if (aux == finalAux)
    {
        printf("O codigo %d guarda o valor: %d", LL[finalAux-1].codigo, LL[finalAux-1].valor);
    }
    else
    {
        while (aux != finalAux)
        {
            if (aux < finalAux)
            {
               finalAux = finalAux / 2;
            }
            else if (aux > finalAux)
            {
                finalAux = finalAux + 1;
            }
        }
        printf("O codigo %d guarda o valor: %d", LL[finalAux-1].codigo, LL[finalAux-1].valor);
        return 0;
    }
}

int mostrar(listaLinear LL[], int inicioArranjo, int *inicioLista, int finalArranjo, int *finalLista, listaLinear tipoLista)
{
    for (int i = inicioArranjo; i <= finalArranjo; i++)
    {
        if (i >= *inicioLista && i <= *finalLista)
            printf("codigo: %d valor: %d\n", LL[i].codigo, LL[i].valor);
        else
            printf("-------------\n");
    }
    return 0;
}

int removerFinal(listaLinear LL[], int *inicioLista, int *finalLista, int inicioArranjo, int finalArranjo, listaLinear tipoLista)
{
    if (*inicioLista == -1 || *finalLista < 0)
    {
        printf("lista vazia!!!");
        return 1;
    }
    else
    {
        if (*inicioLista == -1)
        {
            *inicioLista = *finalLista = inicioArranjo;
        }
        else if (*finalLista <= finalArranjo)
        {
            *finalLista = *finalLista - 1;
        }
        else
        {
            for (int i = *inicioLista; i <= *finalLista; i++)
            {
                LL[i - 1] = LL[i];
            }
        }
        return 0;
    }
}