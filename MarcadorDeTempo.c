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
        //para escolhero o metodo de gerar o vetor decomente a linha desejada
        //vector[i].chave = i;
        vector[i].chave = (int)(rand() + 1); // gera um número aleatório para a chave
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

//InsertionSort function lower to higher ---------
void insertionSort(no *vetor, int tamanho){


    

    int i = 0, j = 0;
    for(i = 1; i < tamanho ; i++)
    {
        for (j=i ; j > 0 ; j--)
        {
            if(vetor[j-1].chave < vetor[j].chave)
            {
                troca(&vetor[j-1], &vetor[j]);
            }
        }
    }
}
//--------------------------------------------

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



//Shell Sort function lower to higher -------------------------------
void shellSort(no *vetor , int tamanho){
    int i,j,h;
    no aux;

    for (h=1; h<tamanho; h = 3*h+1);

    while(h>0){
        h = (h-1)/3;
        for(i=h; i<tamanho; i++){
            aux = vetor[i];
            j = i;

            while (vetor[j-h].chave < aux.chave) {
                vetor[j] = vetor[j - h];
                j -= h;
                if (j<h) break;
            }
            vetor[j] = aux;
        }
    }
}
//------------------------------------------------------------------


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


//QuickSort function lower to higher-----------

int particao(no *v, int LI, int LS) {
    no aux;
    int e = LI;
    int d = LS - 1; // Ajuste aqui para evitar acessar v[LS], que é o pivô
    no pivo = v[LS];
    while (e <= d) {
        while (e <= d && v[e].chave > pivo.chave) {
            e++;
        }
        while (d >= e && v[d].chave <= pivo.chave) {
            d--;
        }
        if (e < d) {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    aux = v[e];
    v[e] = v[LS];
    v[LS] = aux;
    return e;
}
void quickSort(no*v, int LI, int LS) {
    if (LI < LS) {
        int p;
        p = particao(v, LI, LS);
        quickSort(v, LI, p - 1);
        quickSort(v, p + 1, LS);
    }
}
//----------------------------------------------------------------------------------


//---------------------MAIN-------------------
int main(){

    double cpu_time_used;
    clock_t start = 0, end = 0;
    int size = 100; // tamanho do vetor
    no* vector = (no *)malloc(size * sizeof(no));

    system("cls");

    printf("propgrama iniciado\n");

    printf("parte insertion sort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    int seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 1: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 2: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 3: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 4: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 5: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 6: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 7: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 8: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 9: %f\n", cpu_time_used);
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
    insertionSort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------

    printf("parte mergesort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
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
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    mergesort(vector, size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(mergesort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------
    
        printf("parte buble sort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
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
    
        printf("parte shellsort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 1: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
   printf("\n\nTempo de execucao(shellsort)seed 2: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 3: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 4: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 5: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 6: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 7: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 8: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 9: %f\n", cpu_time_used);
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
    shellSort(vector , size);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(shellsort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------

        printf("parte quicksort\n");
//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    //parte para da biblioteca time.h para marcar o tempo de execução
    start = 0; 
    end = 0;
    vector = (no *)malloc(size * sizeof(no));
    createRandomVector(vector, size, seed);
    start = clock();
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 1: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 2: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 3: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 4: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 5: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 6: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 7: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 8: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 9: %f\n", cpu_time_used);
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
    quickSort(vector, 0 , size-1);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(QuickSort)seed 10: %f\n", cpu_time_used);
    free(vector);
//--------------------------------------------------------------------------------



    printf("fim do programa\n");
fclose(stdout);


    free(vector);

    return 0;
}