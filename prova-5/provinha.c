#include <stdio.h>
#include <stdlib.h>

typedef struct noA
{
	char info;
	struct noA *esq;
	struct noA *dir;
} TNoA;

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

void profundidade(TNoA *a)
{
	if (a != NULL)
	{
		printf("%c ", a->info);
		profundidade(a->esq);
		profundidade(a->dir);
	}
}

// RECURSIVA

// SIMETRICA: vai até o final, imprime, volta pra raiz e imprime, percorre o outro lado

// Guarda a raiz
// Guarda o nó esquerdo
// Se o nó esquerdo é o último da árvore, imprime e remove da pilha
// Imprime a raiz

// B A D C E
void simetrica(TNoA *a)
{
	if (a != NULL)
	{
		if (a->esq != NULL)
		{
			printf("%c ", a->esq->info);
			printf("%c ", a->info);

			if (a->esq->esq == NULL && a->esq->dir == NULL)
			{
				simetrica(a->dir);
				return;
			}
		}

		if (a->dir != NULL)
		{
			printf("%c ", a->dir->info);

			simetrica(a->dir);
		}
		printf("%c ", a->info);
	}
}

// RECURSIVA

// POSORDEM: vai ate o final, imprime, volta pra raiz, NÃO IMPRIME, desce pelo outro lado, imprime, sobre pra raiz e imprime

// B D E C A
void posOrdem(TNoA *a)
{
	if (a != NULL)
	{
		if (a->esq != NULL)
		{
			posOrdem(a->esq);
		}

		if (a->dir != NULL)
		{
			posOrdem(a->dir);
		}
		printf("%c ", a->info);
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
	imprime(raiz, 0);
	printf("\n");
	profundidade(raiz);
	printf("\n");
	simetrica(raiz);
	printf("\n");
	posOrdem(raiz);
};
