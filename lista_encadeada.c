#include "lista_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

lista inserirInicio(lista l, int valor)
{
    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = l;
    return novo;
}

lista inserirFim(lista l, int valor)
{
    lista aux = l;
    if (l == NULL)
    {
        return inserirInicio(l, valor);
    }

    while (aux->proximo != NULL)
    {
        aux = aux->proximo;
    }

    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    novo->proximo = NULL;

    aux->proximo = novo;
    return l;
}

lista inserirPosicao(lista l, int posicao, int valor)
{

    if (!(posicao < 0))
    {

        if (posicao == 0)
        {
            return inserirInicio(l, valor);
        }

        if (posicao > tamanho(l))
        {
            return inserirFim(l, valor);
        }

        lista aux = l;
        int contador = 0;

        while (contador < posicao - 1)
        {
            aux = aux->proximo;
            contador++;
        }

        lista novo = (lista)malloc(sizeof(no));
        novo->valor = valor;
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    return l;
}

lista inserirOrdem(lista l, int valor)
{
    lista novo = (lista)malloc(sizeof(no));
    novo->valor = valor;
    lista aux = l;

    if (l == NULL || l->valor >= novo->valor)
    {
        return inserirInicio(l, valor);
    }

    else
    {
        while (aux->proximo != NULL && aux->proximo->valor < novo->valor)
        {
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    return l;
}

void exibir(lista l)
{
    lista aux = l;
    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}

void reverso(lista l)
{
    if (l == NULL)
    {
        return;
    }

    reverso(l->proximo);
    printf("[%d]", l->valor);
}

lista removerInicio(lista l)
{
    if (l == NULL)
    {
        return NULL;
    }
    lista aux = l->proximo;
    free(l);
    return aux;
}

lista removerFim(lista l)
{

    if (l == NULL)
    {
        return NULL;
    }

       if (l->proximo == NULL)
    {
        return removerInicio(l);
    }

    lista aux = l;
    while (aux->proximo->proximo != NULL)
    {
        aux = aux->proximo;
    }
    free(aux->proximo);
    aux->proximo = NULL;
    return l;
}

lista removerPosicao(lista l, int posicao)
{
    lista aux = l;
    int contador = 0;

    if (!(posicao < 0 || posicao > tamanho(l) - 1 || l == NULL))
    {
        if (posicao == 0)
        {
            return removerInicio(l);
        }
        while (contador < posicao - 1)
        {
            aux = aux->proximo;
            contador++;
        }

        lista proximo = aux->proximo->proximo;
        free(aux->proximo);
        aux->proximo = proximo;
    }
    return l;
}

lista removerValor(lista l, int valor)
{
    lista aux = l;

    if (l == NULL)
    {
        return NULL;
    }
    if (aux->valor == valor)
    {
        return removerInicio(l);
    }

    while (aux->proximo != NULL && aux->proximo->valor != valor)
    {
        aux = aux->proximo;
    }
    if (aux->proximo == NULL)
    {
        return l;
    }
    lista proximo = aux->proximo->proximo;
    free(aux->proximo);
    aux->proximo = proximo;
    return l;
}

lista procurar(lista l, int n)
{

    lista aux = l;
    while (aux != NULL)
    {
        if (aux->valor == n)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

int somatorio(lista l)
{
    int somatorio = 0;
    lista aux = l;
    while (aux != NULL)
    {
        somatorio = somatorio + aux->valor;
        aux = aux->proximo;
    }
    return somatorio;
}

int tamanho(lista l)
{
    int contador = 0;
    lista aux = l;

    while (aux != NULL)
    {
        aux = aux->proximo;
        contador++;
    }

    return contador;
}

lista quadrado(lista l)
{

    lista aux = l;
    while (aux != NULL)
    {
        aux->valor = aux->valor * aux->valor;
        aux = aux->proximo;
    }
    return l;
}

int qtdPrimo(lista l)
{
    int i;
    int contador = 0;

    lista aux = l;
    while (aux != NULL)
    {
        if (aux->valor > 1)
        {
            int primo = 1;

            for (i = 2; i < aux->valor; i++)
            {
                if (aux->valor % i == 0)
                {
                    primo = 0;
                }
            }

            if (primo == 1)
            {
                contador++;
            }
        }
        aux = aux->proximo;
    }
    return contador;
}