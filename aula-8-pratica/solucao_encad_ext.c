// Implementar encadeamento exterior

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct aluno
{
    int matricula;
    float cr;
    struct aluno *prox;
} TAluno;

typedef TAluno *Hash; // Hash é um vetor que será alocado dinamicamente

void inicializa(Hash *tab, int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        tab[i] = NULL;
    }
}

TAluno *aloca(int mat, float cr)
{
    TAluno *novo = (TAluno *)malloc(sizeof(TAluno));
    novo->matricula = mat;
    novo->cr = cr;
    return novo;
}

void *encadeia(int mat, float cr, TAluno *self) // NEW
{
    while (self->prox != NULL)
    {
        self = self->prox;
    }
    TAluno *novo = aloca(mat, cr);
    self->prox = novo;
}

int hash(int mat, int m)
{
    return mat % m;
}

void libera(Hash *tab, int m) // Ajustado
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (tab[i])
        {
            TAluno *iterador = tab[i];
            while (iterador->prox != NULL)
            {
                TAluno *aux = iterador->prox;
                free(iterador);
                iterador = aux;
            }
        }
    }
}

int busca(Hash *tab, int m, int mat) // Ajustado
{
    int pos = hash(mat, m);
    if (tab[pos] != NULL)
    {
        TAluno *resp = tab[pos];
        if (resp->matricula == mat)
        {
            return pos;
        }
        else
        {
            while (resp->prox != NULL)
            {
                resp = resp->prox;
                if (resp->matricula == mat)
                {
                    return pos;
                }
            }
        }
    }
    return -1;
}

void insere(Hash *tab, int m, int mat, float cr) // Ajustado
{
    int ini = hash(mat, m);
    if (tab[ini] == NULL)
    {
        tab[ini] = aloca(mat, cr);
    }
    else
    {
        encadeia(mat, cr, tab[ini]);
        printf("Compartimento ja ocupado -- encadeamento exterior realizado\n");
    }
}

void imprime(Hash *tab, int m) // Ajustado
{
    int h;
    for (int i = 0; i < m; i++)
    {
        h = i;
        printf("%d:\n", h);

        if (tab[h] != NULL)
        {
            TAluno *p = tab[h];
            printf("\tmat: %d\tcr: %f\n", p->matricula, p->cr);
            while (p->prox != NULL)
            {
                p = p->prox;
                printf("\tmat: %d\tcr: %f\n", p->matricula, p->cr);
            }
        }
    }
}

int main()
{
    int n, m;
    printf("Digite m (tamanho da tabela hash)... ");
    scanf("%d", &m);
    printf("Digite n (quantidade de matriculas)... ");
    scanf("%d", &n);

    if ((n <= 1) || (m <= 1))
        return 0;

    Hash tab[m];
    inicializa(tab, m);

    int i, mat;
    float cr;
    for (i = 0; i < n; i++)
    {
        printf("Digite a matricula e o cr...\n");
        scanf("%d", &mat);
        scanf("%f", &cr);
        insere(tab, m, mat, cr);
    }
    imprime(tab, m);

    char resp;

    do
    {
        printf("Digite a matricula a ser procurada... ");
        scanf("%d", &mat);
        int ind = busca(tab, m, mat);
        if (ind == -1)
            printf("Elemento nao encontrado!\n");
        else
        {
            TAluno *p = tab[ind];
            while (p->matricula != mat)
            {
                p = p->prox;
            }
            printf("%d\t%f\n", p->matricula, p->cr);
        }
        printf("Quer continuar? ");
        scanf(" %c", &resp);
    } while ((resp != 'N') && (resp != 'n'));
    imprime(tab, m);

    libera(tab, m);

    return 0;
}
