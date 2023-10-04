# Resposta

## Algoritmo de percurso simétrico

Simétrico: 
  1. Percorre a sub-árvore esquerda
  2. Visita a raiz
  3. Percorre a sub-árvore direita

Estrutura auxiliar necessária: Pilha

- Empilhar o nó atual
- Repetir até que `esq` seja nulo:
  1. Empilhar nó da direita (se diferente de NULL)
  2. Empilhar nó da esquerda (se diferente de NULL)
  3. Descer pra `esq`
- Desempilhar topo da pilha até que ela esteja vazia;
- Repetir até que `dir` seja nulo:
  1. Empilhar nó da direita (se diferente de NULL)
  2. Empilhar nó da esquerda (se diferente de NULL)
  3. Descer pra `dir`


## Algoritmo de percurso pós-ordem

Pós-ordem:
  1. Percorre a sub-árvore esquerda
  2. Percorre a sub-árvore direita
  3. Visita a raiz

Estrutura auxiliar necessária: Pilha

- Empilhar a raiz
- Repetir até que nó atual seja nulo:
  1. Empilhar nó da direita (se diferente de NULL)
  2. Empilhar nó da esquerda (se diferente de NULL)
- Desempilhar até que a pilha seja nula