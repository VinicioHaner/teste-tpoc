#ifndef TP4OC_ALGORITMOS_H
#define TP4OC_ALGORITMOS_H
#include <stdbool.h>

int BubbleSort(int *vetor, int tam, char *nomeArq);
int RadixSort(int *vetor, int tam, char *nomeArq);
int QuickSort(int *vetor, int inicio, int fim, char *nomeArq, int tam);
int OrdenaQuickSort(int *vetor, int inicio, int fim, char *nomeArq, int tam);
int BogoSort(int *vetor, int tam, char *nomeArq);
bool ver_ordenacao(int *vetor, int tam);
void embaralha(int *a, int tam);
int BogoSort_otimizado(int *vetor, int tam, char *nomeArq);
void embaralha_otimizado(int *a, int tam);
void Imprime(int *vetor, int tam);
void LeArquivo(int *vetor, int tam, char *nome);
#endif //TP4OC_ALGORITMOS_H
