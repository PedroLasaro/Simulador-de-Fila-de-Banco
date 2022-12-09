#include "escalonador.h"

#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"
#include "fila_fifo.h"
#include "leitor.h"
#include "logtree.h"

void e_inicializar(Escalonador *e, int caixas, int delta_t, int n_1, int n_2,
                   int n_3, int n_4, int n_5) {
  Escalonador *novo;
  novo = (Escalonador *)malloc(sizeof(Escalonador));
  int i, ordem[5] = {n_1, n_2, n_3, n_4, n_5};
  for (i = 0; i < 5; i++)
    f_inicializar(&novo->filas[i]), novo->ordem[i] = ordem[i];
  novo->qntdcaixas = caixas;
  novo->deltaT = delta_t;
  novo->totalClientes = 0;
  return;
}

int e_inserir_por_fila(Escalonador *e, int classe, int num_conta,
                       int qtde_operacoes) {
  return f_inserir(&e->filas[classe], num_conta, qtde_operacoes);
}

int e_obter_prox_num_conta(Escalonador *e) {
  int num_conta, count, old_fila;

  old_fila = e->atual;
  count = 0;
  do {
    e->atual = e_consultar_prox_fila(e);
  } while (f_num_elementos(&e->filas[e->atual]) == 0 && ++count < 5);

  if (e->atual != old_fila) e->totalClientes = 0;

  num_conta = f_obter_proxima_chave(&e->filas[e->atual]);
  if (num_conta != -1) e->totalClientes++;

  return num_conta;
}

int e_consultar_prox_num_conta(Escalonador *e) {
  int num_conta, count, prox_fila;

  prox_fila = e_consultar_prox_fila(e);
  count = 0;
  do {
    num_conta = f_consultar_proxima_chave(&e->filas[prox_fila]);
    if (num_conta == -1) prox_fila = (prox_fila + 1) % 5;
  } while (num_conta == -1 && ++count < 5);

  return num_conta;
}

int e_consultar_prox_qtde_oper(Escalonador *e) {
  int qtde, count, prox_fila;
  prox_fila = e_consultar_prox_fila(e);
  count = 0;
  do {
    qtde = f_consultar_proximo_valor(&e->filas[prox_fila]);
    if (qtde == -1) prox_fila = (prox_fila + 1) % 5;
  } while (qtde == -1 && ++count < 5);

  return qtde;
}

int e_consultar_prox_fila(Escalonador *e) {
  int disciplina = e->ordem[e->atual];
  int len = f_num_elementos(&e->filas[e->atual]);
  return (e->totalClientes == disciplina || len == 0) ? (e->atual + 1) % 5
                                                      : e->atual;
}

int e_consultar_qtde_clientes(Escalonador *e) {
  int qtde, i;
  qtde = 0;
  for (i = 0; i < 5; i++) {
    qtde += f_num_elementos(&e->filas[i]);
  }
  return qtde;
}

int e_consultar_tempo_prox_cliente(Escalonador *e) {
  int ops;
  ops = e_consultar_prox_qtde_oper(e);
  return (ops == -1) ? -1 : ops * e->deltaT;
}

int e_conf_por_arquivo(Escalonador *e, char *nome_arq_conf) {
  int idx, caixas, delta, *n;
  FILE *arq;
  char *linha;
  size_t tam;
  Cli *cliente;

  arq = fopen(nome_arq_conf, "r");
  if (arq == NULL) return 0;  // erro de alocação de memoria

  for (idx = 0; idx < 3; ++idx) {
    getline(&linha, &tam, arq);
    if (idx == 1) {
      caixas = pegarNumero(linha);
    } else if (idx == 2) {
      delta = pegarNumero(linha);
    } else if (idx == 3) {
      n = pegarVetorNumerico(linha);
      e_inicializar(e, caixas, delta, n[0], n[1], n[2], n[3], n[4]);
    }
  }
  while (getline(&linha, &tam, arq) != -1) {
    cliente = criarCliente(linha);
    e_inserir_por_fila(e, cliente->classe, cliente->conta, cliente->ops);
  }

  fclose(arq);
  return 1;
}

void e_rodar(Escalonador *e, char *nome_arq_in, char *nome_arq_out) {
  int tempo, i, ops, conta, clientes, tempoTotal;
  Log *l;
  log_inicializar(&l);
  FILE *arq_out;

  e_conf_por_arquivo(e, nome_arq_in);
  clientes = e_consultar_qtde_clientes(e);

  arq_out = fopen(nome_arq_out, "wt");
  if (arq_out == NULL) return;

  i, tempo, tempoTotal = 0;
  while (clientes > 0) {
    if (e->caixas[i].tempo == tempo) {
      clientes--;
      e->caixas[i].qntdClientes++;
      e->caixas[i].tempo += e_consultar_tempo_prox_cliente(e);

      ops = e_consultar_prox_qtde_oper(e);
      conta = e_obter_prox_num_conta(e);

      log_registrar(l, conta, e->atual + 1, tempo, i + 1);
      o_tempo_cliente(tempo, i + 1, e->atual + 1, conta, ops, arq_out);
    }
    i = (i + 1) % e->qntdcaixas;
    if (i == 0) tempo++;
  }

  for (i = 0; i < e->qntdcaixas; i++) {
    tempoTotal =
        (e->caixas[i].tempo > tempoTotal) ? e->caixas[i].tempo : tempoTotal;
  }

  o_tempo_total(tempoTotal, arq_out);
  o_tempo_classe(l, arq_out);
  o_caixas(e->caixas, e->qntdcaixas, arq_out);

  fclose(arq_out);
}
