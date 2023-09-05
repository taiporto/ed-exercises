// Completar o código em anexo de forma que ele faça:
// - Ler um inteiro n
// - Alocar dinamicamente um vetor de n floats
// - Fazer uma função que recebe o vetor e o valor n e retorna o valor da média
// - Imprimir a média

#include <stdio.h>
#include <stdlib.h>

float media(int tam_vetor, float *numeros)
{
  float soma = 0;
  /* Fazer código aqui*/
  for (int i = 0; i < tam_vetor; i++)
  {
    soma += numeros[i];
  }

  return soma / tam_vetor;
}

int main(void)
{
  float *v;
  float med = 0.0;
  int i, n;
  /*Ler o Inteiro n*/
  printf("Insira a quantidade de valores: ");
  scanf("%d", &n);

  /*Alocar o vetor*/
  v = (float *)malloc(n * sizeof(float));

  /* leitura dos valores */
  for (i = 0; i < n; i++)
  {
    /*Leitura dos valores*/
    printf("Insira o %d° valor: ", i + 1);
    scanf("%f", &v[i]);
  }

  med = media(n, v);
  /* exibição do resultado */
  printf("media = %.2f\n", med);
  free(v);
}
