#include <iostream>
#include <cstdlib>
#include "ordenacao.h"  // Inclui o arquivo de cabeçalho com as definições de funções

using namespace std;

int comparisions = 0; // Definindo comparações como globais
int switches = 0; // Definindo trocas como globais

// Função para inicializar o vetor, alocando espaço para o TipoVetor
TipoVetor* inicializa_vetor() {
    TipoVetor* vetor = (TipoVetor*) malloc(sizeof(TipoVetor));
    return vetor;
}

// Função de ordenação Bubble Sort
void bubble_sort(TipoVetor* vetor, int n) {

    // Loop de ordenação
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisions++; // Contabilizando a comparação

            // Verifica se o valor atual é maior que o próximo
            if (vetor->dados[j].numero > vetor->dados[j+1].numero) {
                // Troca os valores se a condição for verdadeira
                TipoDado aux = vetor->dados[j];
                vetor->dados[j] = vetor->dados[j+1];
                vetor->dados[j+1] = aux;

                switches++; // Contabilizando a troca
            }
        }
    }

    // Exibe o número total de comparações e trocas
    cout << "Numero total de comparacoes: " << comparisions << endl;
    cout << "Numero total de trocas: " << switches << endl;
}

// Função auxiliar para o Heap Sort (heapify)
void heapify(TipoVetor* vetor, int n, int i) {
    int maior = i; // Inicialmente assume que o maior é o nó raiz
    int e = 2 * i + 1; // Índice do filho esquerdo
    int d = 2 * i + 2; // Índice do filho direito

    comparisions++; // Contabilizando a comparação

    // Verifica se o filho esquerdo é maior que a raiz
    if ((e < n) && (vetor->dados[e].numero > vetor->dados[maior].numero)) {
        maior = e;
    }

    comparisions++; // Contabilizando a comparação

    // Verifica se o filho direito é maior que o maior atual
    if ((d < n) && (vetor->dados[d].numero > vetor->dados[maior].numero)) {
        maior = d;
    }

    // Se o maior não for a raiz, troca os valores
    if (maior != i) {
        TipoDado aux = vetor->dados[i];
        vetor->dados[i] = vetor->dados[maior];
        vetor->dados[maior] = aux;

        switches++; // Contabilizando a troca

        // Recursivamente aplica o heapify no subárvore afetado
        heapify(vetor, n, maior);
    }
}

// Função para construir o heap e ordenar (Heap Sort)
void build_heap(TipoVetor* vetor, int n) {

    // Constrói o heap (reorganiza o array)
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(vetor, n, i);
    }

    // Extrai elementos do heap um por um
    for (int i = n - 1; i > 0; i--) {
        // Move a raiz atual para o fim
        TipoDado aux = vetor->dados[0];
        vetor->dados[0] = vetor->dados[i];
        vetor->dados[i] = aux;

        switches++; // Contabilizando a troca

        // Aplica o heapify na árvore reduzida
        heapify(vetor, i, 0);
    }

    // Exibe o número total de comparações e trocas
    cout << "Numero total de comparacoes: " << comparisions << endl;
    cout << "Numero total de trocas: " << switches << endl;
}

// Função de ordenação Counting Sort
void counting_sort(TipoVetor* vetor, int n) {
    comparisions = 0; // Reinicializando o contador de comparações
    switches = 0; // Reinicializando o contador de trocas

    // Encontra o maior elemento no vetor
    int maior = vetor->dados[0].numero;
    for (int i = 1; i < n; i++) {
        if (vetor->dados[i].numero > maior) {
            maior = vetor->dados[i].numero;
        }
        comparisions++; // Contabilizando a comparação
    }

    // Cria o vetor auxiliar
    int* vet_aux = (int*) calloc(maior + 1, sizeof(int));

    // Conta a frequência de cada número
    for (int i = 0; i < n; i++) {
        vet_aux[vetor->dados[i].numero]++;
    }

    // Reconstroi o vetor original ordenado
    int j = 0;
    for (int i = 0; i <= maior; i++) {
        while (vet_aux[i] > 0) {
            vetor->dados[j].numero = i;
            j++;
            vet_aux[i]--;

            switches++; // Contabilizando a troca
        }
    }

    free(vet_aux); // Libera a memória auxiliar

    // Exibe o número total de comparações e trocas
    cout << "Numero total de comparacoes: " << comparisions << endl;
    cout << "Numero total de trocas: " << switches << endl;
}

// Função para gerar o vetor em ordem aleatória ou decrescente
void generate_random(TipoVetor* vetor, int n, int modo_ord) {
    if(modo_ord == 1) {  // Gera números aleatórios
        for(int i = 0; i <= n - 1; i++) {
            vetor->dados[i].numero = rand() % n;
        }
    } else if(modo_ord == 2) {  // Gera números em ordem decrescente
        vetor->dados[0].numero = n;
        for(int i = 0; i <= n - 1; i++) {
            vetor->dados[i].numero = n - i;
        }
    }
}

// Função para imprimir o vetor
void print_vector(TipoVetor* vetor, int n) {
    for(int i = 0; i < n; i++) {
        cout << vetor->dados[i].numero << " ";  // Imprime cada elemento do vetor
    }
    cout << endl << endl;
}

// Função para converter a escolha do número de elementos
int turn_quant_elem(int quant_elem) {
    switch (quant_elem) {
    case 1:
        return 10;  // Retorna 10 elementos
        break;
    case 2:
        return 100;  // Retorna 100 elementos
        break;
    case 3:
        return 1000;  // Retorna 1000 elementos
        break;
    case 4:
        return 10000;  // Retorna 10000 elementos
        break;
    }
}
