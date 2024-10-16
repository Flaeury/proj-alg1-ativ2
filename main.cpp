// ARQUIVO GERADO PELO CHATGPT, VAMOS NOS BASEAR NELE PARA ENTENDER COMO DEVE FUNCIONAR

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

// Funções para geração de dados
vector<int> gerarAleatorio(int n);
vector<int> gerarDescendente(int n);

// Funções dos algoritmos de ordenação
void bubbleSort(vector<int>& arr, int& comparacoes, int& trocas);
void selectionSort(vector<int>& arr, int& comparacoes, int& trocas);
void insertionSort(vector<int>& arr, int& comparacoes, int& trocas);
// void quickSort(vector<int>& arr, int esq, int dir, int& comparacoes, int& trocas);
// void mergeSort(vector<int>& arr, int l, int r, int& comparacoes, int& trocas);
// void heapSort(vector<int>& arr, int& comparacoes, int& trocas);

// Classe que gerencia o processo de ordenação
class SortManager {
public:
    void executar();

private:
    void escolherEntrada();
    void escolherAlgoritmo();
    void mostrarResultado();

    vector<int> dados;
    int nValores;
    string tipoOrdenacao;
    int algoritmoEscolhido;

    // Variáveis de desempenho
    int comparacoes = 0;
    int trocas = 0;
    duration<double> tempoExecucao;
};

int main() {
    SortManager manager;
    manager.executar();
    return 0;
}

void SortManager::executar() {
    escolherEntrada();
    escolherAlgoritmo();
    
    cout << "Vetor antes da ordenação: ";
    for (int i : dados) cout << i << " ";
    cout << endl;

    auto inicio = high_resolution_clock::now();

    // Escolha do algoritmo
    switch(algoritmoEscolhido) {
        case 1: bubbleSort(dados, comparacoes, trocas); break;
        case 2: selectionSort(dados, comparacoes, trocas); break;
        case 3: insertionSort(dados, comparacoes, trocas); break;
        // Implementar também quickSort, mergeSort, etc.
        // Adicionar o grupo de outros algoritmos também
    }

    auto fim = high_resolution_clock::now();
    tempoExecucao = duration_cast<duration<double>>(fim - inicio);

    mostrarResultado();
}

void SortManager::escolherEntrada() {
    cout << "Escolha o número de valores (10, 100, 1000, 10000): ";
    cin >> nValores;

    cout << "Escolha o tipo de entrada (1 - Aleatório, 2 - Descendente): ";
    int escolha;
    cin >> escolha;

    if (escolha == 1) dados = gerarAleatorio(nValores);
    else dados = gerarDescendente(nValores);
}

void SortManager::escolherAlgoritmo() {
    cout << "Escolha um algoritmo de ordenação:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cin >> algoritmoEscolhido;
}

void SortManager::mostrarResultado() {
    cout << "Vetor ordenado: ";
    for (int i : dados) cout << i << " ";
    cout << endl;

    cout << "Tempo de execução: " << tempoExecucao.count() << " segundos\n";
    cout << "Número de comparações: " << comparacoes << "\n";
    cout << "Número de trocas: " << trocas << "\n";
}

// Exemplo de implementação de algoritmos de ordenação

void bubbleSort(vector<int>& arr, int& comparacoes, int& trocas) {
    int n = arr.size();
    bool trocou;
    for (int i = 0; i < n-1; i++) {
        trocou = false;
        for (int j = 0; j < n-i-1; j++) {
            comparacoes++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                trocas++;
                trocou = true;
            }
        }
        if (!trocou) break;
    }
}

// Implementação de Selection Sort
void selectionSort(vector<int>& arr, int& comparacoes, int& trocas) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparacoes++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            trocas++;
        }
    }
}

// Implementação de Insertion Sort
void insertionSort(vector<int>& arr, int& comparacoes, int& trocas) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparacoes++;
            arr[j + 1] = arr[j];
            j--;
            trocas++;
        }
        arr[j + 1] = key;
    }
}


vector<int> gerarAleatorio(int n) {
    vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

vector<int> gerarDescendente(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
    return arr;
}
