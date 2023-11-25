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
        vector[i].chave = (int)(rand() + 1); // gera um número aleatório acima de 100 e armazena na chave
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

//BubleSort function lower to higher -------------------------------
void bubleSort(no *vetor, int tamanho){


    int i, j;
    for(i = 0 ; i < tamanho - 1; i++)
    {
        for (j = 1 ; j  < tamanho - i; j++)
        {
            if(vetor[j].chave > vetor[j-1].chave)
            {
                troca(&vetor[j-1], &vetor[j]);
            }
        }
    }

}
//------------------------------------------------------------------





//---------------------MAIN-------------------
int main(){

    double cpu_time_used;
    clock_t start = 0, end = 0;
    int size = 5*1e5; // tamanho do vetor
    no* vector = (no *)malloc(size * sizeof(no));

    system("cls");
    FILE *file = fopen("5x1e5-VdesordenadoBublrSort.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("propgrama iniciado\n");





       printf("parte buble sort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
     int seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 1: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 2: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 3: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 4: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 5: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 6: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 7: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 8: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 9: %f\n", cpu_time_used);
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
    bubleSort(vector,size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(BubleSort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
    printf("fim do programa\n");
fclose(stdout);


    free(vector);

    return 0;
}