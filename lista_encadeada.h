#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct no
{
        int valor;
        struct no *proximo;
} no;

typedef no *lista;

lista inserirInicio(lista l, int valor);
lista inserirFim(lista l, int valor);
lista inserirPosicao(lista l, int posicao, int valor);
lista inserirOrdem(lista l, int valor);
void exibir(lista l);
void reverso(lista l);
lista removerInicio(lista l);
lista removerFim(lista l);
lista removerPosicao(lista l, int posicao);
lista removerValor(lista l, int valor);
lista procurar(lista l, int n);
int tamanho(lista l);
int somatorio(lista l);
lista quadrado(lista l);
int qtdPrimo(lista l);

#endif