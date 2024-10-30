// RAIANE GABRIELE BRITO DE OLIVEIRA
// ROGERIO DOS ANJOS BARBOSA

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "ordenacao.h"

using namespace std;

int main() {
    // Declaração de variáveis para o número de elementos, modo de ordenação, algoritmo escolhido, 
    // quantidade convertida e opção para printar o vetor
    int quant_elem, modo_ord, algoritmo, turned_quant;
    char print;
    
    // Inicializa o vetor usando a função inicializa_vetor
    TipoVetor* vetor = inicializa_vetor();

    // Apresenta as opções de quantidade de elementos para o usuário
    cout << "(digite 1 para 10 elementos)" << endl;
    cout << "(digite 2 para 100 elementos)" << endl;
    cout << "(digite 3 para 1000 elementos)" << endl;
    cout << "(digite 4 para 10000 elementos)" << endl;
    cout << "(digite 5 para sair)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> quant_elem;  // Recebe a escolha do usuário
    cout << endl;

    // Converte a escolha do usuário em quantidade de elementos real
    turned_quant = turn_quant_elem(quant_elem);

    // Apresenta as opções de modo de ordenação: aleatória ou decrescente
    cout << "(digite 1 para ordem aleatoria)" << endl;
    cout << "(digite 2 para ordem decrescente)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> modo_ord;  // Recebe a escolha do usuário para a ordenação
    cout << endl;

    // Gera o vetor aleatório ou em ordem decrescente com base na escolha do usuário
    generate_random(vetor, turned_quant, modo_ord);

    // Pergunta ao usuário se deseja printar o vetor antes da ordenação
    cout << "Deseja printar o vetor? (s/n): ";
    cin >> print;  // Recebe a opção do usuário
    cout << endl;

    // Se o usuário escolheu sim, imprime o vetor antes da ordenação
    if (print == 's' || print == 'S') {
        cout << "Vetor antes da ordenacao: ";
        print_vector(vetor, turned_quant);  // Chama a função para imprimir o vetor
    }

    // Apresenta as opções de algoritmos de ordenação
    cout << "(digite 1 para bubble sort)" << endl;
    cout << "(digite 2 para heap sort)" << endl;
    cout << "(digite 3 para counting sort)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> algoritmo;  // Recebe a escolha do usuário para o algoritmo de ordenação
    cout << endl;

    // Marca o tempo de início da execução do algoritmo de ordenação
    auto inicio = chrono::high_resolution_clock::now();

    // Escolhe o algoritmo de ordenação com base na escolha do usuário
    switch (algoritmo) {
        case 1:  // Caso o usuário escolha o Bubble Sort
            bubble_sort(vetor, turned_quant);
            break;
        case 2:  // Caso o usuário escolha o Heap Sort
            build_heap(vetor, turned_quant);
            break;
        case 3:  // Caso o usuário escolha o Counting Sort
            counting_sort(vetor, turned_quant);
            break;
    }

    // Marca o tempo de fim da execução do algoritmo de ordenação
    auto fim = chrono::high_resolution_clock::now();

    // Calcula a duração da execução do algoritmo
    chrono::duration<double> duracao = fim - inicio;

    // Imprime o vetor já ordenado
    cout << "Vetor ordenado: ";
    print_vector(vetor, turned_quant);  // Chama a função para imprimir o vetor ordenado

    // Exibe o tempo que o algoritmo levou para ser executado
    cout << "A funcao levou " << duracao.count() << " segundos para executar" << endl;

    return 0;
}
