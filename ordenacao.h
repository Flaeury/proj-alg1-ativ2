#define MaxTam 10000  // Define o tamanho máximo do vetor como 10.000

// Estrutura para armazenar um número no vetor
typedef struct tipodado {
    int numero;
} TipoDado;

// Estrutura que representa um vetor de TipoDado
typedef struct tipovetor {
    TipoDado dados[MaxTam];  // Vetor de TipoDado com tamanho máximo definido
} TipoVetor;

// Funções de ordenação e outras
TipoVetor* inicializa_vetor();  // Função para inicializar um vetor
void bubble_sort(TipoVetor*, int);  // Função para ordenação Bubble Sort
void heapify(TipoVetor*, int);  // Função auxiliar para o Heap Sort (heapify)
void build_heap(TipoVetor*, int);  // Função para construir e ordenar (Heap Sort)
void counting_sort(TipoVetor*, int);  // Função para ordenação Counting Sort
void generate_random(TipoVetor*, int, int);  // Função para gerar um vetor aleatório ou decrescente
void print_vector(TipoVetor*, int);  // Função para imprimir o vetor
int turn_quant_elem(int);  // Função para converter a escolha do número de elementos
