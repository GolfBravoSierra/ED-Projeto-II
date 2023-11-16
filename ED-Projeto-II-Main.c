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
// ---------------------------------------------------------------------

//InsertionSort function lower to higher ---------
void insertionSort(no *vetor, int tamanho){

    //parte para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end = 0;
    double cpu_time_used;

    start = clock();

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

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execucao(insertsort): %f\n", cpu_time_used);
    printf("primeia posicao %d\n", vetor[0].chave);
    printf("ultima posicao %d\n", vetor[tamanho-1].chave);
}
//--------------------------------------------

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
            j = i;
            while(vetor[j-h].chave < aux.chave)
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
        if (c[iv].chave <= c[ic].chave)
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
    printf("primeia posicao %d\n", v[0].chave);
    printf("ultima posicao %d\n", v[n-1].chave);

}
//---------------------------------------------

//QuickSort function lower to higher-----------

int particao(no *v, int LI, int LS){
    int pivo, aux;
    int e = LI, d = LS;
    pivo = v[LI].chave;
    while(e < d)
    {
        while((v[e].chave >= pivo)&&(e < LS))
        {
            e++;
        }
        while((v[d].chave > pivo)&&(d > LI))
        {
            d--;
        }
        if(e < d)
        {
            aux = v[e].chave;
            v[e].chave = v[d].chave;
            v[d].chave = aux;
        }
    }
    aux = v[LI].chave;
    v[LI].chave = v[d].chave;
    v[d].chave = aux;
    return d;
}

double quicksort(no *v ,int LI,  int LS ){

    // patente para da biblioteca time.h para marcar o tempo de execução
    clock_t start = 0, end;
    double cpu_time_used;

    if(LI<LS)
    {
        int p;
        p= particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }

    //parte para da biblioteca time.h para marcar o tempo de execução e verificar a ordenação
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("primeia posicao %d\n", v[0].chave);
    printf("ultima posicao %d\n", v[LS-1].chave);
    return cpu_time_used;
    
}

//---------------------------------------------
int main(){
    int size = 10; // tamanho do vetor
    int seed = 0; // seed para geraçõa do vetor randomico
    
    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    createRandomVector(vector, size, seed);
    //para imprimir o vetor desordenado descomente a linha abaixo
    //printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------

//-------------------------VetorOrdenadoInsertSort-----------------------------------------
    insertionSort(vector, size);

    //para imprimir o vetor ordenado pelo insertSort descomente a linha abaixo
    //printf("\nVetor ordenadoinsetsort:\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

//-------------------------VetorOrdenadoBubleSort-----------------------------------------  
    bubleSort(vector, size);

    //para imprimir o vetor ordenado pelo bubleSort descomente a linha abaixo
    //printf("\nVetor ordenado(bublesort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

//-------------------------VetorOrdenadoShellSort-----------------------------------------  
    shellsort(vector, size);

    //para imprimir o vetor ordenado pelo shellSort descomente a linha abaixo
    //printf("\nVetor ordenado(shellsort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

//-----------------------MergeSort---------------------------------------------------------
    mergesort(vector , size);
    
    //para imprimir o vetor ordenado pelo mergeSort descomente a linha abaixo
    //printf("\nVetor ordenado(mergesort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

//-----------------------QuickSort---------------------------------------------------------
    double tempo;
    tempo = quicksort(vector , 0 , size);
    printf("\n\nTempo de execucao(quicksort): %f\n", tempo);


    //para imprimir o vetor ordenado pelo quickSort descomente a linha abaixo
    printf("\nVetor ordenado(quicksort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

    free(vector);

    return 0;
}





