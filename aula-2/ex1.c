#include <stdio.h>
#include <stdlib.h>

float calculaMedia(int tam_vetor, int *numeros);

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

  media = calculaMedia(n, numeros);

  free(numeros);

  printf("Media dos valores: %.2f\n", media);
}

float calculaMedia(int tam_vetor, int *numeros)
{
  float soma = 0;

  for (int i = 0; i < tam_vetor; i++)
  {
    soma += numeros[i];
  }

  return soma / tam_vetor;
}