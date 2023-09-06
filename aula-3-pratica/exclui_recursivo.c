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

// ESTUDO EXEMPLO
TLista *insere_ordenado_recursivo(TLista *li, int i)
{
  if (li == NULL || li->prox == NULL) // lista vazia
  {
    TLista *novo = (TLista *)malloc(sizeof(TLista));
    novo->info = i;    // cria o nó com a informação nova
    novo->prox = NULL; // designa o próximo de novo como nulo
    if (li == NULL)    // se a lista for nula (chegou ao fim da lista), só designa o novo nó a ela (entra como último nó)
      li = novo;
    else                // se a lista não for nula (chegou no último item)
    {                   /* inserir no meio da lista */
      if (li->info > i) // se a info do último nó for maior que i
      {
        novo->prox = li; // o próximo nó do novo nó pasa a ser o último nó, e ele entra logo antes
        li = novo;       // move o nó atual para ser o novo nó
      }
      else               // se a info do último nó não for maior que i
        li->prox = novo; // o novo nó passa a ser o último
    }
  }
  else // se não estiver no último da lista
  {
    if (li->info > i) // se a info do nó atual for maior do que i
    {
      TLista *novo = (TLista *)malloc(sizeof(TLista)); // cria um novo nó
      novo->info = i;                                  // designa i como informação do novo nó
      novo->prox = li;                                 // o próximo do novo nó passa a ser o nó atual
      li = novo;                                       // move o nó atual para ser o novo nó
    }
    else                                                 // se a info do nó atual for menor do que i -> MAIOR PARTE DOS CASOS, CASO DE CONTINUE
      li->prox = insere_ordenado_recursivo(li->prox, i); // designa o proximo do nó atual como a função recursiva dele mesmo
  }
  return li; // retorna o nó atual
}

// EXERCISE
TLista *exclui_recursivo(TLista *lista, int info)
{

  if (lista->prox == NULL)
    return;

  if ((lista->prox->info != info)) // caso de parada geral. chegou no final da lista e não achou nada
    return lista;

  else
  {
    if (lista->info == info)
    {

      if (lista->prox == NULL)
      {
        // exclui o ponteiro atual
        // aponta o anterior para nulo
      }
      else
      {
        // guarda a ref de memoria do prox num ponteiro auxiliar
        //  exclui o ponteiro atual
        //  aponta o anterior para o proximo
      }
    }
  }
}

// RESOLUTION

TLista *exclui(TLista *li, int i)
{
  TLista *prox = li->prox;

  printf("Current li: %d\n", li->info);

  if (li == NULL || li->prox == NULL)
  {
    return li;
  }

  if (li->info == i)
  {
    TLista *aux = li;
    li = prox;
    free(aux);
  }
  else
  {
    if (prox->info == i)
    {
      li->prox = prox->prox;
      free(prox);
    }
    else
    {
      li->prox = exclui(prox, i);
    }
  }

  return li;
}

int main()
{
  TLista *lista = (TLista *)malloc(sizeof(TLista));

  lista = cria_lista();

  lista = insere_inicio(lista, 3);
  lista = insere_inicio(lista, 2);
  lista = insere_inicio(lista, 1);

  lista = exclui(lista, 2);

  imprime_lista(lista);
}