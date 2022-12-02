#include "fila_fifo.h"

/*Função que inicia a Fila e
aloca um tipo Fila_FIFO Vazia ao vetor.*/
void f_inicializar(Fila_FIFO **f) {
int idx;
Fila_FIFO *novo;
novo = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
novo->primeiro = NULL;
novo->ultimo = NULL;
return;
}

int f_inserir(Fila_FIFO **f, int chave, int valor) {
return 0;
}

int f_obter_proxima_chave(Fila_FIFO **f) { return 0; }

int f_consultar_proxima_chave(Fila_FIFO **f) { return 0; }

int f_consultar_proximo_valor(Fila_FIFO **f) { return 0; }

int f_num_elementos(Fila_FIFO **f) { return 0; }

int f_consultar_chave_por_posicao(Fila_FIFO **f, int posicao) { return 0; }

int f_consultar_valor_por_posicao(Fila_FIFO **f, int posicao) { return 0; }
