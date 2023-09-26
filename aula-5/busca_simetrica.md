# Referência

## Algoritmo de percurso em profundidade

Estrutura auxiliar necessária: Pilha

- Empilhar a raiz
- Repetir até que a pilha fique vazia:
    1. Desempilha topo da pilha (visita → faz ação, como imprimir)
    2. Empilha nó da direita (se diferente de NULL)
    3. Empilha nó da esquerda (se diferente de NULL)


# Resposta

## Algoritmo de percurso simétrico

Estrutura auxiliar necessária: Pilha

- Repetir até que `esq` seja nulo:
  1. Empilhar o nó atual
  2. Empilhar nó da direita (se diferente de NULL)
  3. Empilhar nó da esquerda (se diferente de NULL)
- Desempilhar topo da pilha até que ela esteja vazia;
- Repetir até que `dir` seja nulo:
  1. Empilhar o nó atual
  2. Empilhar nó da direita (se diferente de NULL)
  3. Empilhar nó da esquerda (se diferente de NULL)