#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.h"

typedef struct fila
{
  TLista *inicio; // TLista = {int info, TLista *prox}
  TLista *fim;    // TLista = {int info, TLista *prox}
} TFila;

TFila *inicializa()
{
  TFila *fila = (TFila *)malloc(sizeof(TFila));
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

int fila_vazia(TFila *fila)
{
  if (fila->inicio == NULL)
    return 1;

  return 0;
}

void insere(TFila *fila, int elem)
{
  TLista *novo = (TLista *)malloc(sizeof(TLista));
  novo->info = elem;
  novo->prox = NULL; // inserção no fim da fila
  if (!fila_vazia(fila))
  {
    fila->fim->prox = novo;
  }
  else
  {
    fila->inicio = novo;
  }
  fila->fim = novo; // elt. novo é o novo fim da fila
}

void imprime_fila(TFila *fila)
{
  while (fila->inicio != NULL)
  {
    printf("Info: %d\n", fila->inicio->info);
    fila->inicio = fila->inicio->prox;
  }
}

// EXERCISE
int update(TFila *fila, int nova_info)
{
  if (fila_vazia(fila))
    return -1;

  fila->inicio->info = nova_info;
  return nova_info;
}

int main()
{
  TFila *fila = inicializa();

  insere(fila, 4);
  insere(fila, 6);
  insere(fila, 9);

  int output = update(fila, 10);

  if (output != -1)
    imprime_fila(fila);
}