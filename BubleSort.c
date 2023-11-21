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

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end = 0;
    double cpu_time_used;

    start = clock();

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

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(bulbesort): %f\n", cpu_time_used);
    printf("primeia posicao %d\n", vetor[0].chave);
    printf("ultima posicao %d\n", vetor[tamanho-1].chave);
}
//------------------------------------------------------------------

//---------------------MAIN-------------------
int main(){

    int size = 5*1e4; // tamanho do vetor
    int seed = 0; // seed para geraçõa do vetor randomico
    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 84644564; // seed para geraçõa do vetor randomico
    createRandomVector(vector, size, seed);
    //para imprimir o vetor desordenado descomente a linha abaixo
    //printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------

//-------------------------VetorOrdenadoBubleSort----------------------------------------- 
    bubleSort(vector, size);
    //para imprimir o vetor ordenado pelo bubleSort descomente a linha abaixo
    //printf("\nVetor ordenado(bublesort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------


    free(vector);

    return 0;
}