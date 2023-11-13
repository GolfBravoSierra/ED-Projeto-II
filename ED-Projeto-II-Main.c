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

//função troca 
void troca(no *a, no *b){
    no aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

//InsertionSort function lower to higher
double insertionSort(no *vetor, int tamanho){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    start = clock();

    int i = 0, j;
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
    return cpu_time_used;
}


//BubleSort function lower to higher
double bubleSort(no *vetor, int tamanho){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    start = clock();

    int i = 0 , j;
    no aux;
    for(i = tamanho; i - 1 > 0; i--)
    {
        for (j = tamanho; j - 1 > 0 ; j--)
        {
            if(vetor[j].chave > vetor[j-1].chave)
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j-1] = aux;
            }
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

//Shell Sort function lower to higher
double shellsort(no *vetor , int tamanho){
    int i = 0  , j , h;
    no aux;

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for(h = 1; h < tamanho; h = 3*h+1);
    while(h > 0)
    {
        h = (h-1)/3;
        for(i = h; i < tamanho; i++)
        {
            aux = vetor[i];
            j = i;
            while(vetor[j-h].chave < aux.chave)
            {
                vetor[j] = vetor[j-h];
                j = j-h;
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
    return cpu_time_used;
}
/*
//MergeSort function lower to higher
void merger(int *v , int *c, int i, int m , int f){
    int z, iv = i, ic = m+1;
    for(z = i; z <= f; z++)
    {
        c[z] = v[z];
    }
    z = i;
    while (iv <= m && ic <= f)
    {
        if (c[iv] <= c[ic])
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

void sort (no *v, int *c, int i,int f){
    if (i < f)
    {
        int m = (i+f)/2;
        sort(v, c, i, m);
        sort(v, c, m+1, f);
        if (v.chave[m] > v[m+1])
        {
            merger(v, c, i, m, f);
        }
    }
}

double mergesort (no *v , int n){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    int *c = malloc(sizeof(int)*n);
    sort (v, c, 0, n-1);
    free(c);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

*/


int main(){
    int size = 10; // tamanho do vetor
    int seed = 0; // seed para geraçõa do vetor randomico
    double time = 0; // variavel para armazenar o tempo de execução
    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    createRandomVector(vector, size, seed);

    //para imprimir o vetor desordenado descomente a linha abaixo
    printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------

//-------------------------VetorOrdenadoInsertSort-----------------------------------------
    time = insertionSort(vector, size);

    //para imprimir o vetor ordenado pelo insertSort descomente a linha abaixo
    printf("\nVetor ordenadoinsetsort:\n"); imprimevetor(vector, size);

    printf("\n\nTempo de execucao(insertsort): %f\n", time);
//-----------------------------------------------------------------------------------------

//-------------------------VetorOrdenadoBubleSort-----------------------------------------
    time = bubleSort(vector, size);

    //para imprimir o vetor ordenado pelo bubleSort descomente a linha abaixo
    printf("\nVetor ordenado(bublesort):\n"); imprimevetor(vector, size);

    printf("\n\nTempo de execucao(bulbesort): %f\n", time);
//-----------------------------------------------------------------------------------------


//-------------------------VetorOrdenadoShellSort-----------------------------------------
    time = shellsort(vector, size);

    //para imprimir o vetor ordenado pelo shellSort descomente a linha abaixo
    printf("\nVetor ordenado(shellsort):\n"); imprimevetor(vector, size);

    printf("\n\nTempo de execucao(shellsort): %f\n", time);
//-----------------------------------------------------------------------------------------

//-----------------------MergeSort---------------------------------------------------------
    //time = mergesort(vector , size);

    //para imprimir o vetor ordenado pelo mergeSort descomente a linha abaixo
    //printf("\nVetor ordenado(mergesort):\n"); imprimevetor(vector, size);

    printf("\n\nTempo de execucao(mergesort): %f\n", time);
//-----------------------------------------------------------------------------------------

    free(vector);

    return 0;
}





