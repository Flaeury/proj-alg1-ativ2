#define MaxTam 10000

typedef struct tipodado {
    int numero;
} TipoDado;

typedef struct tipovetor {
    TipoDado dados[MaxTam];
} TipoVetor;

TipoVetor* inicializa_vetor();
void bubble_sort(TipoVetor*, int);
void heapify(TipoVetor*, int);
void build_heap(TipoVetor*, int);
void counting_sort(TipoVetor*, int);
void generate_random(TipoVetor*, int, int);
void print_vector(TipoVetor*, char, int);
int turn_quant_elem(int);
