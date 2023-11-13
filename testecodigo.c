#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// estrutura do nó
typedef struct No{
    int chave; // chave para ordenação do vetor
    float valor; // valor do nó 
} no;   

typedef struct {
    int chave;
    // Adicione outros campos necessários aqui
} no;

void merger(no *v , no *c, int i, int m , int f){
    int z, iv = i, ic = m+1;
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
    while (iv <= m && ic <= f)
    {
        if (c[iv].chave <= c[ic].chave)
        {
            v[z] = c[iv++];
        }
        else
        {
            v[z] = c[ic++];
        }
    }
    while (iv <= m)
    {
        v[z++] = c[iv++];
    }
    while (ic <= f)
    {
        v[z++] = c[ic++];
    }
}

void sort (no *v, no *c, int i,int f){
    if (i < f)
    {
        int m = (i+f)/2;
        sort(v, c, i, m);
        sort(v, c, m+1, f);
        if (v[m].chave > v[m+1].chave)
        {
            merger(v, c, i, m, f);
        }
    }
}

double mergesort (no *v , int n){
    clock_t start = 0, end;
    double cpu_time_used;

    no *c = malloc(sizeof(no)*n);
    sort (v, c, 0, n-1);
    free(c);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int main() {
    int i;
    int size = 10; // tamanho do vetor
    int vector[size];

    srand(22007263); // usa o tempo atual como semente para o gerador aleatório

    for(i = 0; i < size; i++) {
        vector[i] = rand() + 100; // gera um número aleatório e armazena no vetor
        printf("%d\n", vector[i]); // imprime o número aleatório
    }

    mergesort(vector, size);

    return 0;
}
/*
6275
29724
22565
30779
24913
56
12921
22148
17132
6477
*/
/*
Chave: 0, Valor: 106744728.00
Chave: 1, Valor: 86927200.00
Chave: 2, Valor: 1119183104.00
Chave: 3, Valor: 134811504.00
Chave: 4, Valor: 1217647488.00
Chave: 5, Valor: 1856056832.00
Chave: 6, Valor: 2036194816.00
Chave: 7, Valor: 1483861120.00
Chave: 8, Valor: 1737257600.00
Chave: 9, Valor: 1716799744.00

*/