//------------------------------ParteDasBiblietecasEstruturasDeDados---------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// estrutura do nó
typedef struct No{
    int chave; // chave para ordenação do vetor
    float valor; // valor do nó 
} no;   

//função para criar um vetor randomico
void createRandomVector(no *vector, int size, int seed) {
    int i;
    srand(seed); // seed para geraçõa do vetor randomico

    for(i = 0; i < size; i++) 
    {
        vector[i].chave = i; // gera um número aleatório acima de 100 e armazena na chave
        vector[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
        //printf("Chave: %d, Valor: %.2f\n", vector[i].chave, vector[i].valor); // imprime a chave e o valor
    }
}

//função para imprimir o vetor
void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {
        printf("|Chave: %d, Valor: %.2f|", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
    
}
//----------------------------------------------------------------

//MergeSort function lower to higher-----------


void merge(no *v , no *c, int i, int m , int f){
    int z, iv = i, ic = m+1;
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
    while (iv <= m && ic <= f)
    {
        if (c[iv].chave >= c[ic].chave)
        {
            v[z++] = c[iv++];
        }
        else
        {
            v[z++] = c[ic++];
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

void sort(no *v, no *c, int i,int f){
    if (i < f)
    {
        int m = (i+f)/2;
        sort(v, c, i, m);
        sort(v, c, m+1, f);
        if (v[m].chave < v[m+1].chave)
        {
            merge(v, c, i, m, f);
        }
    }
}

void mergesort(no *v , int n){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    //parte da função merge sort
    no *c = malloc(sizeof(no)*n);
    sort (v, c, 0, n-1);
    free(c);

    //parte para da biblioteca time.h para marcar o tempo de execução e verificar a ordenação
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort): %f\n", cpu_time_used);
    
    printf("primeira chave: %d\n", v[0].chave);
    printf("ultima chave: %d\n", v[n-1].chave);

}
//---------------------------------------------

//---------------------MAIN-------------------
int main(){

    int size = 5*1e5; // tamanho do vetor
    int seed = 84644564; // seed para geraçõa do vetor randomico
    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    createRandomVector(vector, size, seed);
    //para imprimir o vetor desordenado descomente a linha abaixo
    //printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

//-----------------------MergeSort---------------------------------------------------------
    mergesort(vector , size);
    //para imprimir o vetor ordenado pelo mergeSort descomente a linha abaixo
    //printf("\nVetor ordenado(mergesort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

    //parte para da biblioteca time.h para marcar o tempo de execução e verificar a ordenação
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort): %f\n", cpu_time_used);

    free(vector);

    return 0;
}