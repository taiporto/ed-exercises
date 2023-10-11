#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct sNoA
{
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

void imprime(TNoA *nodo, int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("-");
    }
    if (nodo != NULL)
    {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }
    else
        printf("vazio");
}

TNoA *insere(TNoA *no, int chave)
{
    if (no == NULL)
    {
        no = (TNoA *)malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    }
    else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave))
    {
        no->dir = insere(no->dir, chave);
    }
    else
    {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

TNoA *criaArvoreBalanceada(TNoA *raiz, int *v, int inicio, int fim)
{
    printf("arvore antes de rodar\n");
    imprime(raiz, 0);
    printf("\n");
    if (inicio <= fim)
    {
        int meio = (inicio + fim) / 2;
        if (raiz == NULL)
        { // se for primeiro nó a ser inserido tem que atualizar a raiz da arvore
            raiz = (TNoA *)malloc(sizeof(TNoA));
            raiz->esq = NULL;
            raiz->dir = NULL;
            raiz->chave = v[meio];
        }
        else
        {
            printf("meio: %d; v[meio]: %d\n", meio, v[meio]);
            insere(raiz, v[meio]);
        }
        // constroi subárvores esquerda e direita
        int *subVetorEsq = (int *)malloc(meio * sizeof(int));
        int *subVetorDir = (int *)malloc(meio * sizeof(int));

        if (subVetorEsq == NULL || subVetorDir == NULL)
        {
            printf("Memoria insuficiente\n");
            exit(1);
        }

        for (int i = 0, j = meio; i <= meio; i++, j++)
        {
            subVetorEsq[i] = v[i];
            subVetorDir[j] = v[j];
        }

        if (subVetorEsq[(inicio + meio) / 2] != v[meio])
        {
            criaArvoreBalanceada(raiz, subVetorEsq, inicio, meio);
        }

        if (subVetorDir[(meio + fim) / 2] != v[meio])
        {
            criaArvoreBalanceada(raiz, subVetorDir, meio, fim);
        }
        printf("arvore depois de rodar\n");
        imprime(raiz, 0);
        printf("\n");
    }
    return raiz;
}

int main(void)
{
    int tam = 7;
    int v[7] = {150, 300, 400, 500, 600, 800, 900};
    TNoA *raiz = NULL;
    raiz = criaArvoreBalanceada(raiz, v, 0, tam - 1);
    imprime(raiz, 0);
}
