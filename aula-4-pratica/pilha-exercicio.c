#include "pilha-lista.h"

TPilha *inicializa()
{
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void libera(TPilha *p)
{
    TLista *q = p->topo;
    TLista *r;
    while (q != NULL)
    {
        r = q;
        q = q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha)
{
    if (pilha->topo == NULL)
        return 1; // pilha vazia
    else
        return 0; // pilha tem pelo menos 1 elemento
}

/* *
 * Insere elem no topo da pilha
 * */
void push(TPilha *pilha, int elem)
{
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

/* *
 * Altera o elemento do topo da pilha
 * */
void altera_topo(TPilha *pilha, int elem)
{
    if (pilha_vazia(pilha))
        exit(1);

    pilha->topo->info = elem;
}

/* *
 * Exclui o elemento do topo da pilha
 * retorna o info do elemento excluído
 */
int pop(TPilha *pilha)
{
    if (pilha_vazia(pilha))
        return -1;

    int info = pilha->topo->info;
    pilha->topo = pilha->topo->prox;

    return info;
}

/* *
 * Consulta o elemento do topo da pilha
 * retorna info do elemento do topo
 */
int peek(TPilha *pilha)
{
    if (pilha_vazia(pilha))
        return -1;

    return pilha->topo->info;
}

void imprime_pilha(TPilha *pilha)
{
    if (pilha_vazia(pilha))
        exit(1);

    TLista *aux = pilha->topo;

    while (aux != NULL)
    {
        printf("info: %d\n", aux->info);
        aux = aux->prox;
    }
    free(aux);
}

int main()
{
    TPilha *pilha;
    pilha = inicializa();
    push(pilha, 5);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 3);
    printf("topo: %d\n", peek(pilha));

    imprime_pilha(pilha);

    int info = pop(pilha);
    printf("elemento removido: %d\n", info);

    imprime_pilha(pilha);
}
