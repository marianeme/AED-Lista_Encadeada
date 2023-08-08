#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

void menu_opcoes()
{
    printf("Selecione uma opcao: \n\n");
    printf("\t 1 - inserir no inicio\n");
    printf("\t 2 - inserir no fim\n");
    printf("\t 3 - inserir na posicao\n");
    printf("\t 4 - inserir na ordem\n");
    printf("\t 5 - exibir lista\n");
    printf("\t 6 - exibir reverso\n");
    printf("\t 7 - remover inicio\n");
    printf("\t 8 - remover fim\n");
    printf("\t 9 - remover posicao\n");
    printf("\t 10 - remover valor\n");
    printf("\t 11 - procurar\n");
    printf("\t 12 - somatorio\n");
    printf("\t 13 - tamanho\n");
    printf("\t 14 - quadrado\n");
    printf("\t 15 - quantidade de primos\n");
    printf("\t 99 - sair\n");
}

int main(int argc, char **argv)
{
    int opcao;
    int valor;
    int posicao;

    lista l1 = NULL;

    while (1)
    {
        menu_opcoes();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido no inicio:\n");
            scanf("%d", &valor);
            l1 = inserirInicio(l1, valor);
            printf("Valor inserido no inicio!\n");
            break;
        case 2:
            printf("Digite o valor a ser inserido no fim:\n");
            scanf("%d", &valor);
            l1 = inserirFim(l1, valor);
            printf("Valor inserido no fim!\n");
            break;
        case 3:
            printf("Digite o valor a ser inserido na posicao:\n");
            scanf("%d", &valor);
            printf("Digite a posicao:\n");
            scanf("%d", &posicao);
            l1 = inserirPosicao(l1, posicao, valor);
            break;
        case 4:
            printf("Digite o valor a ser inserido na ordem:\n");
            scanf("%d", &valor);
            l1 = inserirOrdem(l1, valor);
            printf("Valor inserido!\n");
            break;
        case 5:
            printf("Lista l1:\n");
            exibir(l1);
            break;
        case 6:
            printf("Lista na ordem reversa:\n");
            reverso(l1);
            printf("\n");
            break;
        case 7:
            l1 = removerInicio(l1);
            if (l1 == NULL)
            {
                printf("Inicio nao removido! (lista vazia)\n ");
            }
            else
            {
                printf("Inicio removido!\n");
            }
            break;
        case 8:
            l1 = removerFim(l1);
            if (l1 == NULL)
            {
                printf("Fim nao removido! (lista vazia)\n");
            }
            else
            {
                printf("Fim removido!\n");
            }
            break;
        case 9:
            printf("Digite a posicao para remover:\n");
            scanf("%d", &posicao);
            l1 = removerPosicao(l1, posicao);
            break;
        case 10:
            printf("Digite o valor para remover:\n");
            scanf("%d", &valor);
            l1 = removerValor(l1, valor);
            break;
        case 11:
            printf("Digite o valor para procurar:\n");
            scanf("%d", &valor);
            if (procurar(l1, valor) == NULL)
            {
                printf("Valor nao encontrado!\n");
            }
            else
            {
                printf("Valor encontrado!\n");
            }
            break;
        case 12:
            printf("Somatorio dos valores da lista: %d\n", somatorio(l1));
            break;
        case 13:
            printf("Tamanho da lista: %d\n", tamanho(l1));
            break;
        case 14:
            if (l1 == NULL)
            {
                printf("Lista vazia!\n");
            }
            else
            {
                quadrado(l1);
                printf("Operação realizada!");
            }
            break;
        case 15:
            printf("Quantidade de primos encontrada: %d\n", qtdPrimo(l1));
            break;
        case 99:
            exit(0);
        default:
            printf("Opcao invalida!\n");
        }
    }
}
