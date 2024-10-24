#include <iostream>
#include <cstdlib>
#include "ordenacao.h"

using namespace std;

TipoVetor* inicializa_vetor() {
    TipoVetor* vetor = (TipoVetor*) malloc(sizeof(TipoVetor));
    return vetor;
}

void bubble_sort(TipoVetor* vetor, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(vetor->dados[j].numero > vetor->dados[j+1].numero) {
                TipoDado aux = vetor->dados[j];
                vetor->dados[j] = vetor->dados[j+1];
                vetor->dados[j+1] = aux;

                print_vector(vetor, 's', n);
            }
        }
    }
}

void heapify(TipoVetor* vetor, int n, int i) {
    int maior = i; // assume que maior é o pai
    int e = 2 * i + 1;
    int d = 2 * i + 2;

    if((e < n) && (vetor->dados[e].numero > vetor->dados[maior].numero)) {
        maior = e; // maior se torna o esquerdo
    }

    if((d < n) && (vetor->dados[d].numero > vetor->dados[maior].numero)) {
        maior = d; // maior se torna direito
    }

    print_vector(vetor ,'s', n);

    if(maior != i) { // se o maior não for o pai, troca
        TipoDado aux = vetor->dados[i];
        vetor->dados[i] = vetor->dados[maior];
        vetor->dados[maior] = aux;

        heapify(vetor, n, maior);
    }
}

void build_heap(TipoVetor* vetor, int n) {
    for(int i = (n / 2) - 1; i >= 0; i--) {
        heapify(vetor, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        TipoDado aux = vetor->dados[0];
        vetor->dados[0] = vetor->dados[i];
        vetor->dados[i] = aux;

        heapify(vetor, i, 0);
    }

    print_vector(vetor, 's', n);
}

void counting_sort(TipoVetor* vetor, int n) {
    int maior = vetor->dados[0].numero;
    for(int i = 1; i < n; i++) {
        if(vetor->dados[i].numero > maior) {
            maior = vetor->dados[i].numero;
        }
    }

    int* vet_aux = (int*) calloc(maior + 1, sizeof(int));

    for(int i = 0; i < n; i++) {
        vet_aux[vetor->dados[i].numero]++;
    }

    print_vector(vetor, 's', n);

    cout << "Vetor de frequencias: ";
    for(int i = 0; i <= maior; i++) {
        cout << vet_aux[i] << " ";
    }
    cout << endl << endl;;

    int index = 0;
    for(int i = 0; i <= maior; i++) {
        while(vet_aux[i] > 0) {
            vetor->dados[index].numero = i;
            index++;
            vet_aux[i]--;
            print_vector(vetor, 's', n);
        }
        cout << endl << endl;
    }

    free(vet_aux);
}


void generate_random(TipoVetor* vetor, int n, int modo_ord) {
    if(modo_ord == 1) {
        for(int i = 0; i <= n - 1; i++) {
            vetor->dados[i].numero = rand() % n;
        }
    } else if(modo_ord == 2) {
        vetor->dados[0].numero = n;
        for(int i = 0; i <= n - 1; i++) {
            vetor->dados[i].numero = n - i;
        }
    }
}

void print_vector(TipoVetor* vetor, char print, int n) {
    if(print == 's' || print == 'S') {
        for(int i = 0; i < n; i++) {
            cout << vetor->dados[i].numero << " ";
        }
        cout << endl << endl;
    }
}

int turn_quant_elem(int quant_elem) {
    switch (quant_elem) {
    case 1:
        return 10;
        break;
    case 2:
        return 100;
        break;
    case 3:
        return 1000;
        break;
    case 4:
        return 10000;
        break;
    }
}
