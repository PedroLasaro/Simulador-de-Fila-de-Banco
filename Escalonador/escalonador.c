#include "escalonador.h"

#include <stdlib.h>

void e_inicializar(Escalonador *e, int caixas, int delta_t, int n_1, int n_2,
                   int n_3, int n_4, int n_5) {
  Escalonador *novo;
  novo = (Escalonador *)malloc(sizeof(Escalonador));

  f_inicializar(&novo->Premiun);
  f_inicializar(&novo->Ouro);
  f_inicializar(&novo->Bronze);
  f_inicializar(&novo->Prata);
  f_inicializar(&novo->Leezu);
  novo->caixas = caixas;
  novo->deltaT = delta_t;
  novo->n1 = n_1;
  novo->n2 = n_2;
  novo->n3 = n_3;
  novo->n4 = n_4;
  novo->n5 = n_5;

  return;
}

int e_inserir_por_fila(Escalonador *e, int classe, int num_conta,
                       int qtde_operacoes) {
  return 0;
}

int e_obter_prox_num_conta(Escalonador *e) { return 0; }

int e_consultar_prox_num_conta(Escalonador *e) { return 0; }

int e_consultar_prox_qtde_oper(Escalonador *e) { return 0; }

int e_consultar_prox_fila(Escalonador *e) { return 0; }

int e_consultar_qtde_clientes(Escalonador *e) { return 0; }

int e_consultar_tempo_prox_cliente(Escalonador *e) { return 0; }

int e_conf_por_arquivo(Escalonador *e, char *nome_arq_conf) { return 0; }

void e_rodar(Escalonador *e, char *nome_arq_in, char *nome_arq_out) {
  return 0;
}
