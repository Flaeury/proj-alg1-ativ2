#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ordenacao.h"

using namespace std;

int main() {
    int quant_elem, modo_ord, algoritmo, turned_quant;
    char print;
    TipoVetor* vetor = inicializa_vetor();

    cout << "(digite 1 para 10 elementos)" << endl;
    cout << "(digite 2 para 100 elementos)" << endl;
    cout << "(digite 3 para 1000 elementos)" << endl;
    cout << "(digite 4 para 10000 elementos)" << endl;
    cout << "(digite 5 para sair)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> quant_elem;
    cout << endl;

    turned_quant = turn_quant_elem(quant_elem);

    cout << "(digite 1 para ordem aleatoria)" << endl;
    cout << "(digite 2 para ordem decrescente)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> modo_ord;
    cout << endl;

    generate_random(vetor, turned_quant, modo_ord);

    cout << "Deseja printar o vetor? (s/n): ";
    cin >> print;
    cout << endl;

    print_vector(vetor, print, turned_quant);

    cout << "(digite 1 para bubble sort)" << endl;
    cout << "(digite 2 para heap sort)" << endl;
    cout << "(digite 3 para counting sort)" << endl;
    cout << "Digite um valor dentre as opcoes: ";
    cin >> algoritmo;
    cout << endl;

    switch(algoritmo) {
    case 1: // bubble sort
        bubble_sort(vetor, turned_quant);
        break;
    case 2: // heap sort
        build_heap(vetor, turned_quant);
        break;
    case 3: // counting sort
        counting_sort(vetor, turned_quant);
        break;
    }

    return 0;
}
