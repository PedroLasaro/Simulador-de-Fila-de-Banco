#ifndef fila_fifo_h
#define fila_fifo_h

// Implementação dos tipo

// Nó da fila
// tipo que armazena os dados da fila
typedef struct noh {
  int chave, valor;
  struct noh *prox;
} Noh;

// Implementação da fila
// Ponteiro apontando pra primeira e a ultima posição da fila
// Inserção na ultima posição e saída na primeira posição
typedef struct fila_fifo {
  int tam;
  Noh *inicio, *fim;
} Fila_FIFO;

// Nota: chave == -1 significa fila vazia

void f_inicializar(Fila_FIFO **);
// Inicializa a fila.

int f_inserir(Fila_FIFO **, int, int);
// Insere um determinado valor inteiro indexado por um valor de chave na fila.
// Retorna 1 se a inserção for bem sucedida e 0 se houver algum
// problema(duplicação de chave ou falta de memória).

int f_obter_proxima_chave(Fila_FIFO **);
// Retorna o número de chave do próximo elemento da fila, retirando-o da fila.
// Retorna -1 se a fila estiver vazia.

int f_consultar_proxima_chave(Fila_FIFO **);
// Retorna a chave do elemento que está na cabeça da fila, sem retirá-lo da
// fila.

int f_consultar_proximo_valor(Fila_FIFO **);
// Retorna o valor armazenado no elemento que está na cabeça da fila, sem
// retirá-lo da fila.

int f_num_elementos(Fila_FIFO **);
// Retorna o número de elementos presentes na fila.

int f_consultar_chave_por_posicao(Fila_FIFO **, int);
// Retorna a chave do posicao-ésimo elemento da fila.
// Caso não exista a posição desejada, retornar -1. A posição se inicia em 1.

int f_consultar_valor_por_posicao(Fila_FIFO **, int);
// Retorna o valor do posicao-ésimo elemento da fila.
// Caso não exista a posição desejada, retornar -1. A posição se inicia em 1.

#endif  // fila_fifo