#include <stdio.h>
#include "lista-encadeada.h"

typedef struct pilha
{
  TLista *topo; // TLista = {int info, TLista *prox}
} TPilha;

TPilha *inicializa()
{
  TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
  pilha->topo = NULL;
  return pilha;
}

void push(TPilha *pilha, int elem)
{
  TLista *novo = (TLista *)malloc(sizeof(TLista));
  novo->info = elem;
  novo->prox = pilha->topo; // o prox passa a ser o endereço do topo atual
  pilha->topo = novo;       // o topo atual se torna o novo
}

int pilha_vazia(TPilha *pilha)
{
  if (pilha->topo == NULL)
    return 1;
  return 0;
}

void imprime_pilha(TPilha *pilha)
{
  while (pilha->topo != NULL)
  {
    printf("Info: %d\n", pilha->topo->info);
    pilha->topo = pilha->topo->prox;
  }
}

// EXERCISE
int peek(TPilha *pilha)
{
  if (pilha_vazia(pilha))
    return -1;

  return pilha->topo->info;
}

int main()
{
  TPilha *pilha = inicializa();

  push(pilha, 4);
  push(pilha, 6);
  push(pilha, 9);

  int resultado = peek(pilha);

  if (resultado != -1)
    printf("Peek: %d\n", resultado);
}