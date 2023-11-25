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
        vector[i].chave = size - i; // gera um número aleatório acima de 100 e armazena na chave
        vector[i].valor = (float)(rand() + 100); // gera um número aleatório acima de 100 e armazena no valor
        //printf("Chave: %d, Valor: %.2f\n", vector[i].chave, vector[i].valor); // imprime a chave e o valor
    }
}

//função para imprimir o vetor
void imprimevetor(no *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++)
    {
        printf("|Chave: %d|", vetor[i].chave); // imprime a chave e o valor
    }
    
}
//----------------------------------------------------------------

//QuickSort function lower to higher-----------

int particao(no *v, int LI, int LS){
    no aux;
    int e = LI; 
    int d = LS;
    no pivo = v[LS];
    while(e < d)
    {
        while((v[e].chave >= pivo.chave)&&(e < LS))
        {
            e++;
        }
        while((v[d].chave < pivo.chave)&&(d > LI))
        {
            d--;
        }
        if(e < d)
        {
            aux = v[e];
            v[e] = v[d];
            v[d] = aux;
        }
    }
    aux = v[LS];
    v[LS]= v[d];
    v[d]= aux;
    return d;
}

void quicksort(no *v ,int LI,  int LS ){


    if(LI<LS)
    {
        int p;
        p= particao(v,LI,LS);
        quicksort(v,LI,p-1);
        quicksort(v,p+1,LS);
    }
    
}
//----------------------------------------------------------------------------------

//---------------------MAIN-------------------
int main(){

    int size = 10; // tamanho do vetor
    int seed = 0; // seed para geraçõa do vetor randomico
    no* vector = (no *)malloc(size * sizeof(no));

//-------------------------VetorDesordenado(CASO-1)--------------------------------------
    seed = 22007263; // seed para geraçõa do vetor randomico
    createRandomVector(vector, size, seed);
    printf("teste1");
    //para imprimir o vetor desordenado descomente a linha abaixo
    printf("Vetor desordenado:\n"); imprimevetor(vector, size);
//--------------------------------------------------------------------------------

//-----------------------QuickSort---------------------------------------------------------
    quicksort(vector, 0 , size-1);
    printf("teste0");
    //para imprimir o vetor ordenado pelo quickSort descomente a linha abaixo
    printf("\nVetor ordenado(quicksort):\n"); imprimevetor(vector, size);
//-----------------------------------------------------------------------------------------

    free(vector);

    return 0;
}