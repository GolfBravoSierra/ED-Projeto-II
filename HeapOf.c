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

void criaHeap(no* vet, int i, int f){
    no aux = vet[i];
    int j = i * 2 + 1;
    while (j <= f){
        if(j < f && vet[j].chave > vet[j + 1].chave){ // Alteração na comparação para ordem decrescente
            j = j + 1;
        }
        if(aux.chave > vet[j].chave){ // Alteração na comparação para ordem decrescente
            vet[i] = vet[j];
            i = j;
            j = 2 * i + 1;
        }else{
            break;
        }
    }
    vet[i] = aux;
}

void heapSort(no *vet, int N){
    int i;
    no aux;
    for(i=(N - 1)/2; i >= 0; i--){
        criaHeap(vet, i, N-1);
    }
    for (i = N-1; i >= 1; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        criaHeap(vet, 0, i - 1);
    }
}

//---------------------MAIN-------------------
int main(){

    double cpu_time_used;
    clock_t start = 0, end = 0;
    int size = 1e5; // tamanho do vetor
    no* vector = (no *)malloc(size * sizeof(no));

    printf("propgrama iniciado\n");





       printf("parte Heap Of sort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
     int seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 1: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-2)--------------------------------------
    seed = 22006737; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 2: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-3)--------------------------------------
    seed = 11012004; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 3: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-4)--------------------------------------
    seed = 20042004; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 4: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-5)--------------------------------------
    seed = 17072003; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 5: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-6)--------------------------------------
    seed = 65465478; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 6: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-7)--------------------------------------
    seed = 47225896; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 7: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-8)--------------------------------------
    seed = 35736436; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 8: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-9)--------------------------------------
    seed = 32578587; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 9: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
//-------------------------VetorDesordenado(CASO-10)--------------------------------------
    seed = 84644564; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
heapSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(HeapOf)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
    printf("fim do programa\n");


    free(vector);

    return 0;
}