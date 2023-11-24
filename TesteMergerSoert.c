
//------------------------ParteDasBilbiotecasEstruturasEtc----------------------
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

//função troca --------------------------------------------------------
void troca(no *a, no *b){
    no aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// ---------------------------------------------------------------------

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


    //parte da função merge sort
    no *c = malloc(sizeof(no)*n);
    sort (v, c, 0, n-1);
    free(c);


}
//---------------------------------------------

//---------------------MAIN-------------------
int main(){

    double cpu_time_used;
    clock_t start = 0, end = 0;
    int size = 1e4; // tamanho do vetor
    no* vector = (no *)malloc(size * sizeof(no));

    system("cls");

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
     int seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 1: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-2)--------------------------------------
    seed = 22006737; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 2: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-3)--------------------------------------
    seed = 11012004; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 3: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-4)--------------------------------------
    seed = 20042004; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 4: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-5)--------------------------------------
    seed = 17072003; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 5: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-6)--------------------------------------
    seed = 65465478; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergersort)seed 6: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-7)--------------------------------------
    seed = 47225896; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 7: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-8)--------------------------------------
    seed = 35736436; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 8: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-9)--------------------------------------
    seed = 32578587; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergersort)seed 9: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-10)--------------------------------------
    seed = 84644564; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
    free(vector);

    return 0;
}