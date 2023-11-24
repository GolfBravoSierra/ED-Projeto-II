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

//QuickSort function lower to higher-----------

int particao(no *v, int LI, int LS){
    int pivo, aux;
    int e = LI, d = LS;
    pivo = v[LI].chave;
    while(e > d)
    {
        while((v[e].chave >= pivo)&&(e > LS))
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
//----------------------------------------------------------------------------------

//---------------------MAIN-------------------
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

//-----------------------QuickSort---------------------------------------------------------
    double tempo;
    tempo = quicksort(vector , 0 , size);
    printf("\n\nTempo de execucao(quicksort): %f\n", tempo);


    //para imprimir o vetor ordenado pelo quickSort descomente a linha abaixo
    //printf("\nVetor ordenado(quicksort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

    free(vector);

    return 0;
}