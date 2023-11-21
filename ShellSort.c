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


//Shell Sort function lower to higher -------------------------------
void shellsort(no *vetor , int tamanho){
    int i = 0  , j = 0 , h;
    no aux;

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end = 0;
    double cpu_time_used;

    start = clock();

    for(h = 1; h < tamanho; h = 3*h+1);
    while(h > 0)
    {
        h = (h-1)/3;
        for(i = h; i < tamanho; i++)
        {
            aux = vetor[i];
            //print de teste
            printf("aux: %d\n", aux.chave);
            j = i;
            while(vetor[j-h].chave > aux.chave)
            {
                vetor[j] = vetor[j-h];
                j = h;
                if(j < h)
                {
                    break;
                }
            }
            vetor[j] = aux;
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort): %f\n", cpu_time_used);
    printf("primeia posicao %d\n", vetor[0].chave);
    printf("ultima posicao %d\n", vetor[tamanho-1].chave);
}
//------------------------------------------------------------------


int main(){
    int size = 1e4; // tamanho do vetor
    int seed = 0; // seed para geraçõa do vetor randomico

    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    createRandomVector(vector, size, seed);
    //para imprimir o vetor desordenado descomente a linha abaixo
    //printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------
//-------------------------VetorOrdenadoShellSort-----------------------------------------
    shellsort(vector, size);
    //para imprimir o vetor ordenado pelo shellSort descomente a linha abaixo
    //printf("\nVetor ordenado(shellsort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------
    free(vector);

    return 0;
}
