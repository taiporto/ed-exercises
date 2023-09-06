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
TLista *exclui_ordenada(TLista *li, int info)
{
  TLista *iterador, *anterior = (TLista *)malloc(sizeof(TLista));

  iterador = li;

  while (iterador->prox != NULL && iterador->info < info) // Enquanto não for fim da lista e a informação não for encontrada
  {
    anterior = iterador;
    iterador = iterador->prox;
  }

  if (iterador->info != info)
  { // Se chegou num numero maior que a info e a informação não foi encontrada, retorna a lista como é
    printf("Info nao encontrada\n");
    return li;
  }

  if (iterador == NULL) // Se chegou no fim da lista e o iterador é nulo, remove ele e designa a lista ao ponteiro anterior
  {
    li = anterior;
    free(iterador);
    return li;
  }

  anterior->prox = iterador->prox; // "pula" o último item iterado no while da lista, que é o item encontrado
  free(iterador);                  // libera a memória do iterador

  return li;
}

int main()
{
  TLista *lista = (TLista *)malloc(sizeof(TLista));

  lista = cria_lista();

  lista = insere_inicio(lista, 9);
  lista = insere_inicio(lista, 6);
  lista = insere_inicio(lista, 2);
  lista = insere_inicio(lista, 1);

  // imprime_lista(lista);

  lista = exclui_ordenada(lista, 2);

  imprime_lista(lista);
}