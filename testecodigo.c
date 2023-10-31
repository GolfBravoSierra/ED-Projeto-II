#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int i;
    int size = 10; // tamanho do vetor
    int vector[size];

    srand(22007263); // usa o tempo atual como semente para o gerador aleatório

    for(i = 0; i < size; i++) {
        vector[i] = rand() + 100; // gera um número aleatório e armazena no vetor
        printf("%d\n", vector[i]); // imprime o número aleatório
    }

    return 0;
}
/*
6275
29724
22565
30779
24913
56
12921
22148
17132
6477
*/