#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// estrutura do nó
typedef struct No{
    int chave; // chave para ordenação do vetor
    float valor; // valor do nó 
} no;

//função para criar um vetor randomico
void createRandomVector(no *vector, int size) {
    int i;
    srand(22007263); // usa o tempo atual como semente para o gerador aleatório

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
        printf("---Chave: %d, Valor: %.2f---", vetor[i].chave, vetor[i].valor); // imprime a chave e o valor
    }
    
}

//função troca 
void troca(no *a, no *b){
    no aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//InsertionSort function lower to higher
void insertionSort(no *vetor, int tamanho){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int i, j;
    no aux;
    for(i = 0; i < tamanho; i++)
    {
        for (j=i ; j >= 0 ; j--)
        {
            if(vetor[j-1].chave < vetor[j].chave)
            {
                troca(&vetor[j-1], &vetor[j]);
            }
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f\n", cpu_time_used);
}


//BubleSort function lower to higher
void bubleSort(no *vetor, int tamanho){
    int i, j;
    no aux;
    for(i = 0; i < tamanho -1; i++)
    {
        for (j = 0; j < tamanho - i; j++)
        {
            if(vetor[j].chave > vetor[j-1].chave)
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j-1] = aux;
            }
        }
    }
}

int main(){
    int size = 10; // tamanho do vetor
    no* vector = malloc(size * sizeof(no));

    printf("Vetor desordenado:\n");

    createRandomVector(vector, size);

    imprimevetor(vector, size);

    printf("\nVetor ordenado:\n");

    insertionSort(vector, size);

    imprimevetor(vector, size);

    free(vector);

    // agora você pode usar o vetor preenchido aqui na função main

    return 0;
}


