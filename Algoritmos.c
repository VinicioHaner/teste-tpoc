#include "Algoritmos.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int BubbleSort(int *vetor, int tam, char *nomeArq){
    int k, j, aux;
    LeArquivo(vetor, tam, nomeArq);
    for (k = 1; k < tam; k++) {
        for (j = 0; j < tam - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
    Imprime(vetor, tam);
}
int RadixSort(int *vetor, int tam, char *nomeArq){
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;
    LeArquivo(vetor, tam, nomeArq);

    b = (int *)calloc(tam, sizeof(int));

    for (i = 0; i < tam; i++) {
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < tam; i++)
            bucket[(vetor[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];
        for (i = tam - 1; i >= 0; i--)
            b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for (i = 0; i < tam; i++)
            vetor[i] = b[i];
        exp *= 10;
    }

    free(b);
    Imprime(vetor, tam);
}

int QuickSort(int *vetor, int inicio, int fim, char *nomeArq, int tam){
    LeArquivo(vetor, tam, nomeArq);
    OrdenaQuickSort(vetor, inicio, fim, nomeArq, tam);
    Imprime(vetor, tam);
}

int OrdenaQuickSort(int *vetor, int inicio, int fim, char *nomeArq, int tam){
    int pivo, aux, i, j, meio;
    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2);
    pivo = vetor[meio];

    do{
        while (vetor[i] < pivo) i = i + 1;
        while (vetor[j] > pivo) j = j - 1;

        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);

    if(inicio < j) OrdenaQuickSort(vetor, inicio, j, nomeArq, tam);
    if(i < fim) OrdenaQuickSort(vetor, i, fim, nomeArq, tam);
}
int BogoSort(int *vetor, int tam, char *nomeArq){
    LeArquivo(vetor, tam, nomeArq);
    while ( !ver_ordenacao(vetor, tam) ){
        embaralha(vetor, tam);
    }
    Imprime(vetor, tam);
}
bool ver_ordenacao(int *vetor, int tam){
    while ( --tam >= 1 ) {
        if ( vetor[tam] < vetor[tam-1] ){
            return false;
        }
    }
    return true;
}
void embaralha(int *a, int tam){
    int i, t, r;
    for(i=0; i < tam; i++) {
        t = a[i];
        r = rand() % tam;
        a[i] = a[r];
        a[r] = t;
    }
}

int BogoSort_otimizado(int *vetor, int tam, char *nomeArq){
    LeArquivo(vetor, tam, nomeArq);
    while ( !ver_ordenacao(vetor, tam) ){
        embaralha_otimizado(vetor, tam);
    }
    Imprime(vetor, tam);
}
void embaralha_otimizado(int *a, int tam){
    int i, t, r;
    for(i=0; i < tam; i++) {
        t = a[i];
        r = rand() % tam;
        if (i <= r){
            if (a[i] <= a[r]){
                continue;
            } else {
                a[i] = a[r];
                a[r] = t;
            }
        }else {
            if (a[i] >= a[r]){
                continue;
            } else {
                a[i] = a[r];
                a[r] = t;
            }
        }
    }
}

void Imprime(int *vetor, int tam){
    for(int k = 0; k < tam; k++){
        printf("%d ", vetor[k]);
    }
    printf("\n");
}

void LeArquivo(int *vetor, int tam, char *nomeArq){
    FILE *fp;
    int qtdValor = 0, i;
//Actions
    fp = fopen(nomeArq, "r");
    if(fp != NULL) {
        while(!feof(fp)) {
            fscanf(fp, "%d", &vetor[qtdValor]);
            qtdValor++;
        }
        puts("");
/*        for(i = 0; i < (tam - 1); i++) {
            printf("%d ", vetor[i]);
        }
        puts("");*/
    } else {
        puts("Cannot read the file!");
    }
}