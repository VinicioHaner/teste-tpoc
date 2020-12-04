#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Algoritmos.h"

int main() {

    int opcheck, tam_vetor, *vetor = NULL, tam;
    char *nomeArq;
    do {
        srand(time(NULL));
        printf("Qual o tamanho do vetor?\n");
        printf("1 para tamanho 1000\n");
        printf("2 para tamanho 10000\n");
        printf("0 para encerrar programa\n");
        scanf("%d", &tam_vetor);
        if (tam_vetor == 1){
            tam = 1000;
            nomeArq = "1000.txt";
        } else if (tam_vetor == 2){
            tam = 10000;
            nomeArq = "10000.txt";
        } else if (tam_vetor == 0){
            break;
        }

        vetor = (int *)malloc(tam * sizeof(int));

        do {
            printf("*****************************************\n");
            printf("|               Menu                    |\n");
            printf("|                                       |\n");
            printf("| Opcoes                                |\n");
            printf("| 1 - BubbleSort                        |\n");
            printf("| 2 - RadixSort                         |\n");
            printf("| 3 - QuickSort                         |\n");
            printf("| 4 - BogoSort                          |\n");
            printf("| 5 - BogoSort otimizado                |\n");
            printf("| 0 - Voltar                            |\n");
            printf("*****************************************\n");
            fflush(stdin);
            scanf("%d", &opcheck);
            if (opcheck == 1) {
                BubbleSort(vetor, tam, nomeArq);

            } else if (opcheck == 2) {
                RadixSort(vetor, tam, nomeArq);

            } else if (opcheck == 3) {
                int inicio = 0;
                int fim = tam-1;
                QuickSort(vetor, inicio, fim, nomeArq, tam);


            } else if (opcheck == 4) {
                BogoSort(vetor, tam, nomeArq);

            } else if (opcheck == 5) {
                BogoSort_otimizado(vetor, tam, nomeArq);

            }
        }while(opcheck!=0);
    }while (tam_vetor != 0);
    return 0;
}
