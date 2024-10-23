#include <iostream>
#include <cstdlib>
#include "ordenacao.h"

using namespace std;

TipoVetor* inicializa_vetor() {
    TipoVetor* vetor = (TipoVetor*) malloc(sizeof(TipoVetor));
    return vetor;
}

void bubble_sort(TipoVetor* vetor, int n) {
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; i <= n - i - 1; j++) {
            if(vetor->dados[j].numero > vetor->dados[j+1].numero) {
                TipoDado aux = vetor->dados[j];
                vetor->dados[j] = vetor->dados[j+1];
                vetor->dados[j+1] = aux;
            }
        }
    }
}

void heapify(TipoVetor* vetor, int n, int i) {
    int maior;
    int e = 2 * i + 1;
    int d = 2 * i + 2;
    if(e <= n && (vetor->dados[e].numero > vetor->dados[i].numero)) {
        maior = e;
    } else {
        maior = i;
    }
    if(d <= n && (vetor->dados[d].numero > vetor->dados[maior].numero)) {
        maior = d;
    }
    if(maior != i) {
        TipoDado aux = vetor->dados[i];
        vetor->dados[i] = vetor->dados[maior];
        vetor->dados[maior] = aux;
        heapify(vetor, n, maior);
    }
}

void build_heap(TipoVetor* vetor, int n) {
    for(int i = (n-1)/2; i == 0; i--) {
        heapify(vetor, n, i);
    }
}

void counting_sort(TipoVetor* vetor, int n) {
    int maior = vetor->dados[0].numero;
    int i, j;
    for(i = 0; i <= n - 1; i++) {
        if(vetor->dados[i].numero > vetor->dados[i+1].numero) {
            maior = vetor->dados[i+1].numero;
        }
        if(vetor->dados[i].numero == n - 1) {
            break;
        }
    }
    TipoDado vet_aux[maior];

    for(i = 0; i <= n - 1; i++) {
       vet_aux[vetor->dados[i].numero].numero++;
    }

    for(i = 0; i <= n - 1; j++) {
        if(vet_aux[i].numero != 0) {
            for(j = 0; j == vet_aux[i].numero; j++) {    
                vetor->dados[j].numero = i;
            }
        }
    }
}

void generate_random(TipoVetor* vetor, int n, int modo_ord) {
    if(modo_ord == 1) {
        for(int i = 0; i <= n - 1; i++) {
            vetor->dados[i].numero = rand() % (n + 1);
        }
    } else if(modo_ord == 2) {
        vetor->dados[0].numero = rand() % (n + 1);
        for(int i = 1; i <= n - 1; i++) {
            vetor->dados[i].numero = rand() % (vetor->dados[i-1].numero + 1);
        }
    }
}