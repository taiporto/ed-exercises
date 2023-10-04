#include "arvore-binaria.h"

typedef struct item
{
    char info;
    struct item *prox;
} TItem;

typedef struct fila
{
    TItem *inicio;
    TItem *fim;
} TFila;

typedef struct pilha
{
    TItem *topo;
} TPilha;

TNoA *inicializa(void)
{
    return NULL;
}

void imprime(TNoA *nodo, int tab)
{
    for (int i = 0; i < tab; i++)
    {
        printf("-");
    }
    if (nodo != NULL)
    {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    }
    else
        printf("vazio");
}

TNoA *criaNo(char ch)
{
    TNoA *novo;
    novo = (TNoA *)malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int fila_vazia(TFila *f)
{
    if (f->inicio == NULL)
    {
        return 1;
    }

    return 0;
}

void insere(TFila *f, char elemento)
{
    TItem *novo = (TItem *)malloc(sizeof(TItem));
    novo->info = elemento;
    novo->prox = NULL;
    if (!fila_vazia(f))
    {
        f->fim->prox = novo; // aponta o endereço do fim prox pro novo elemento pra encadear a lista
    }
    else
    {
        f->inicio = novo;
    }
    f->fim = novo; // o elemento novo é o novo fim da fila
}

int remove_fila(TFila *f)
{
    if (fila_vazia(f))
    {
        exit(1);
    }
    int info = f->inicio->info;

    TItem *aux = f->inicio;
    f->inicio = f->inicio->prox;
    // se elemento removido era o único da fila
    // faz fim apontar para NULL também
    if (f->inicio == NULL)
    {
        f->fim = NULL;
    }
    free(aux);
    return 0;
}

// 1 - Caminho em largura usando fila

// - Adicionar a raiz na fila
// - Repetir até que a fila fique vazia:
//     1. Retirar primeiro da fila (visita)
//     2. Adicionar nó da esquerda na fila (se diferente de NULL)
//     3. Adicionar nó da direita na fila (se diferente de NULL)

void largura(TNoA *raiz)
{
    if (raiz == NULL)
        return;

    TFila *fila = (TFila *)malloc(sizeof(TFila));
    fila->fim = NULL;
    fila->inicio = NULL;

    insere(fila, raiz->info);

    printf("%c ", fila->inicio->info);

    while (!fila_vazia(fila))
    {
        remove_fila(fila);

        if (raiz->esq != NULL)
        {
            insere(fila, raiz->esq->info);
        }
        if (raiz->dir != NULL)
        {
            insere(fila, raiz->dir->info);
        }

        raiz = raiz->esq;
    }
}

int main(void)
{
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    // imprime(raiz, 0);
    printf("\n");
    largura(raiz);
};