#include "fila_fifo.h"

#include <stdlib.h>

// inicializando a fila deixando o ponteiro para ela nulo
void f_inicializar(Fila_FIFO **f) { *f = NULL; }

// funcao para inserir na fila
int f_inserir(Fila_FIFO **f, int chave, int valor) {
  // inicializando o noh a ser inserido
  Noh *novo = (Noh *)malloc(sizeof(Noh));
  if (novo == NULL) return 0;  // falta de memoria

  // atribuindo os valores do noh
  novo->chave = chave;
  novo->valor = valor;
  novo->prox = NULL;

  // caso em que a fila esta vazia
  if (*f == NULL) {
    // inicio ela com o noh 'novo'
    *f = (Fila_FIFO *)malloc(sizeof(Fila_FIFO));
    if (*f == NULL) return 0;  // falta de memoria
    (*f)->fim = novo;
    (*f)->inicio = novo;
    (*f)->tam = 1;
    return 1;
    // retorno 1 mostrando sucesso na operacao
  }

  // percorro a fila para ver se ha alguma chave com o mesmo valor do parametro
  for (Noh *p = (*f)->inicio; p != NULL; p = p->prox)
    if (p->chave == chave) return 0;  // duplicacao de chave

  // se nao houver, adiciono o noh na fila e atualizo o tamanho da mesma
  (*f)->fim->prox = novo;
  (*f)->fim = (*f)->fim->prox;
  (*f)->tam++;

  return 1;
  // inidico que a insercao foi bem sucedida
}

// funcao para obter a proxima chave
int f_obter_proxima_chave(Fila_FIFO **f) {
  // se a fila estiver vazia retorno -1 indicando erro
  if (*f == NULL) return -1;

  // se nao pego o noh que representa o inicio da fila e seu valor chave
  Noh *aux = (*f)->inicio;
  int chave = aux->chave;
  (*f)->inicio = (*f)->inicio->prox;
  (*f)->tam--;
  // retiro o noh que estava no inicio e atualizo a fila

  // se o inicio da fila ficar nulo, inicializo ela
  if ((*f)->inicio == NULL) f_inicializar(f);

  // deleto da memoria o noh que estava no inicio
  free(aux);

  return chave;
  // retorno a chave do noh que estava no inicio
}

// funcao para consultar a proxima chave, sem retirar o noh
int f_consultar_proxima_chave(Fila_FIFO **f) {
  return (*f)->inicio->chave;
  // retorno o valor da chave do inicio da fila
}

// funcao para consultar o proximo valor, sem retirar o noh
int f_consultar_proximo_valor(Fila_FIFO **f) {
  return (*f)->inicio->valor;
  // retorno o valor do inicio da fila
}

// funcao que retorna o tamanho de uma fila
int f_num_elementos(Fila_FIFO **f) {
  return (*f)->tam;
  // retorno o atributo tam da fila que representa o tamanho
}

// funcao para consultar a chave em sua posicao
int f_consultar_chave_por_posicao(Fila_FIFO **f, int posicao) {
  // inicializo a variavel da posicao como 1
  int i = 1;

  // se a posicao nao existir, retorno -1 indicando erro
  if (posicao > (*f)->tam || posicao < 1) return -1;

  // percorro a fila para encontrar a posicao
  for (Noh *p = (*f)->inicio; p != NULL; p = p->prox, ++i) {
    if (i == posicao) return p->chave;
    // retorno a chave quando a posicao for encontrada
  }

  return -1;
}

// funcao para consultar o valor em sua posicao
int f_consultar_valor_por_posicao(Fila_FIFO **f, int posicao) {
  // inicializo a variavel da posicao como 1
  int i = 1;

  // se a posicao nao existir, retorno -1 indicando erro
  if (posicao > (*f)->tam || posicao < 1) return -1;

  // percorro a fila para encontrar a posicao
  for (Noh *p = (*f)->inicio; p != NULL; p = p->prox, ++i) {
    if (i == posicao) return p->valor;
    // retorno o valor quando a posicao for encontrada
  }

  return -1;
}