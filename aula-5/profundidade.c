#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int info;
  TNo *esq;
  TNo *dir;
} TNo;

TNo* cria_arvore(int i) {
  TNo *novo = (TNo *)malloc(sizeof(TNo));

  novo->info = i;
  novo->esq = NULL;
  novo->dir = NULL;

  return novo;
}

int cria_no(TNo *pai, int i) {
  if(pai == NULL)
    return -1;
  
  TNo *novo = cria_arvore(i);
  
  if(pai->esq == NULL) {
    pai->esq = novo;
  } else {
    pai->dir = novo;
  }

  return i;
}

int main() {
  TNo *arvore = cria_arvore(100);

  cria_no(arvore, 200);
  cria_no(arvore, 150);
  cria_no(arvore->esq, 300);
  cria_no(arvore->esq, 400);
  
}

