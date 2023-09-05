// - Percorrer a lista buscando uma chave (info).
// - Ao encontrar a chave, excluir o elemento e arrumar os ponteiros para que a lista continue encadeada.

#include <stdio.h>
#include <stdlib.h>

// PRE-WORK
typedef struct lista
{
  int info;
  struct lista *prox;
} TLista;

// PRE-WORK
TLista *cria_lista(void)
{
  return NULL;
}

// PRE-WORK
void imprime_lista(TLista *li)
{
  for (TLista *p = li; p != NULL; p = p->prox)
  {
    printf("info = %d\n", p->info);
  }
}

// PRE-WORK
TLista *insere_inicio(TLista *li, int i)
{
  TLista *novo = (TLista *)malloc(sizeof(TLista));
  novo->info = i;
  novo->prox = li;
  return novo;
}

// EXERCISE
void imprime_lista_recursivo(TLista *lista)
{
  if (lista == NULL)
  {
    printf("\n");
    return;
  }
  printf("%d ", lista->info);
  imprime_lista_recursivo(lista->prox);
}

int main()
{
  TLista *lista = (TLista *)malloc(sizeof(TLista));

  lista = cria_lista();

  lista = insere_inicio(lista, 3);
  lista = insere_inicio(lista, 2);
  lista = insere_inicio(lista, 1);

  imprime_lista_recursivo(lista);
}