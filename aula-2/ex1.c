#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, *numeros, soma = 0;
  float media;

  printf("Insira a quantidade de valores: ");
  scanf("%d", &n);

  numeros = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
  {
    printf("Insira o %d° valor: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  for (int i = 0; i < n; i++)
  {
    soma += numeros[i];
  }

  free(numeros);

  media = (float)soma / n;

  printf("Media dos valores: %.2f\n", media);
}