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
/*
Chave: 0, Valor: 106744728.00
Chave: 1, Valor: 86927200.00
Chave: 2, Valor: 1119183104.00
Chave: 3, Valor: 134811504.00
Chave: 4, Valor: 1217647488.00
Chave: 5, Valor: 1856056832.00
Chave: 6, Valor: 2036194816.00
Chave: 7, Valor: 1483861120.00
Chave: 8, Valor: 1737257600.00
Chave: 9, Valor: 1716799744.00

*/