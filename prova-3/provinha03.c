#include "lista-encadeada.h"

TLista *cria_lista(void)
{
    return NULL;
}

TLista *insere_fim_recursivo(TLista *li, int i)
{
    if (li == NULL || li->prox == NULL)
    {
        TLista *novo = (TLista *)malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL)
        {
            li = novo;
        }
        else
            li->prox = novo;
    }
    else
        insere_fim_recursivo(li->prox, i);
    return li;
}

TLista *insere_ordenado_recursivo(TLista *li, int i)
{

    if (li == NULL || li->prox == NULL)
    { // lista vazia ou último elemento
        TLista *novo = (TLista *)malloc(sizeof(TLista));
        novo->info = i;
        novo->prox = NULL;
        if (li == NULL) // lista vazia
            return novo;
        else
        { // eh o ultimo elemento
            if (li->info > i)
            { // vê se tem que inserir antes do ultimo
                novo->prox = li;
                return novo;
            }
            else
            { // vai inserir no final
                li->prox = novo;
                return li;
            }
        }
    }
    else
    { // não ta no final da lista ainda
        if (li->info > i)
        { // se for o lugar certo de inserir, insere
            TLista *novo = (TLista *)malloc(sizeof(TLista));
            novo->info = i;
            novo->prox = li;
            return novo;
        }
        else
        { // se nao for o lugar certo, chama recursivamente no proximo
            li->prox = insere_ordenado_recursivo(li->prox, i);
        }
    }
    // retorna a cabeça da lista
    return li;
}

void imprime_lista(TLista *li)
{
    TLista *p;
    for (p = li; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

int main(void)
{
    TLista *l1;
    TLista *l2;
    /* Insere elementos no inicio da lista */
    l1 = cria_lista(); /* cria e inicializa lista como vazia */
    l1 = insere_fim_recursivo(l1, 2);
    l1 = insere_fim_recursivo(l1, 3);
    l1 = insere_fim_recursivo(l1, 5);
    l1 = insere_fim_recursivo(l1, 4);
    printf("Lista 1:\n");
    imprime_lista(l1);

    /* Insere elementos no final da lista*/
    l2 = cria_lista(); /* cria e inicializa lista como vazia */
    l2 = insere_ordenado_recursivo(l2, 2);
    l2 = insere_ordenado_recursivo(l2, 5);
    l2 = insere_ordenado_recursivo(l2, 3);
    l2 = insere_ordenado_recursivo(l2, 4);
    l2 = insere_ordenado_recursivo(l2, 1);
    printf("Lista 2:\n");
    imprime_lista(l2);

    return 0;
}
