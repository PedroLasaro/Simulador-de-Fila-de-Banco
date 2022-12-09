#include "logtree.h"

#include <stdio.h>
#include <stdlib.h>

// funcao para inicialiar arvore
void log_inicializar(Log **l) {
  *l = NULL;
  // inicializando como ponteiro
}

void log_registrar(Log **l, int conta, int classe, int timer, int caixa) {
  // se a arvore estiver vazia inicializamos ela com um noh
  if (*l == NULL) {
    *l = (Log *)malloc(sizeof(Log));
    (*l)->esquerda = NULL;
    (*l)->direita = NULL;
    (*l)->conta = conta;
    (*l)->classe = classe;
    (*l)->timer = timer;
    (*l)->caixa = caixa;
  } else {
    // se nao, percorremos ela com base na conta para adicionar um noh
    if (conta < (*l)->conta) {
      log_registrar(&((*l)->esquerda), conta, classe, timer, caixa);
    } else {
      log_registrar(&((*l)->direita), conta, classe, timer, caixa);
    }
  }
}

// funcao para calcular a media da classe
float log_media_por_classe(Log **l, int classe) {
  // utiliza as outras duas funcoes e retorna a divisao de uma pela outra
  return ((float)log_obter_soma_por_classe(l, classe) /
          (float)log_obter_contagem_por_classe(l, classe));
}

// funcao para obter a soma por classe
int log_obter_soma_por_classe(Log **l, int classe) {
  // se o noh for nulo paramos a recorrencia e retornamos 0
  if (*l == NULL) return 0;
  float soma = 0;
  // se a classe do noh for a mesma do parametro, o valor da soma nao sera zero
  // e sim o valor do timer
  if ((*l)->classe == classe) soma += (*l)->timer;
  // se nao for nulo continuamos a recorrencia percorrendo a arvore e somando
  // sempre que possivel
  return soma + log_obter_soma_por_classe(&((*l)->esquerda), classe) +
         log_obter_soma_por_classe(&((*l)->direita), classe);
}

// funcao para obter a contagem por classe
int log_obter_contagem_por_classe(Log **l, int classe) {
  // se o noh for nulo paramos a recorrencia e retornamos 0
  if (*l == NULL) return 0;
  // se a classe do noh for a mesma do parametro, retornamos 1, representando
  // mais um noh da mesma classe, somado das recorrencias do noh esquerdo e do
  // direito
  if ((*l)->classe == classe)
    return 1 + log_obter_contagem_por_classe(&((*l)->esquerda), classe) +
           log_obter_contagem_por_classe(&((*l)->direita), classe);
  // se nao for da mesma classe, retornamos o resto da soma sem o 1
  return log_obter_contagem_por_classe(&((*l)->esquerda), classe) +
         log_obter_contagem_por_classe(&((*l)->direita), classe);
}