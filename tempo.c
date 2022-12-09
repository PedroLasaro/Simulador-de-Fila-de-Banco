#include "tempo.h"

#include <stdio.h>

#include "cliente.h"
#include "escalonador.h"
#include "logtree.h"

const char *nome_da_classe(int classe) {
  if (classe == 1) return "Premiun";
  if (classe == 2) return "Ouro";
  if (classe == 3) return "Prata";
  if (classe == 4) return "Bronze";
  if (classe == 5) return "Leezu";
}

void saidaTempoTotal(int tempo, FILE *arq_out) {
  fprintf(arq_out, "Tempo total de atendimento: %d minutos.\n", tempo);
}

void saidaTempoDosCliente(int timer, int caixa, int classe, int conta, int ops,
                          FILE *arq_out) {
  fprintf(arq_out,
          "T = %d min: Caixa %d chama da categoria %s cliente da conta "
          "%d para realizar %d operacao(oes).\n",
          timer, caixa, nome_da_classe(classe), conta, ops);
}

void saidaTempoDasClasse(Log *l, FILE *arq_out) {
  int i;
  int tempos[5], clientes[5], operacoes[5];

  for (i = 0; i < 5; i++) {
    fprintf(
        arq_out, "Tempo medio de espera dos %d clientes %s: %.2f\n",
        clientes[i], nome_da_classe(i + 1),
        clientes[i] == 0 ? (float)0 : (float)tempos[i] / (float)clientes[i]);
  }

  for (i = 0; i < 5; i++) {
    fprintf(
        arq_out, "Quantidade media de operacoes por cliente %s = %.2f\n",
        nome_da_classe(i + 1),
        clientes[i] == 0 ? (float)0 : (float)operacoes[i] / (float)clientes[i]);
  }
}

void saidaTempoDasCaixas(Caixas *caixas, int tamanho, FILE *arq_out) {
  int i;
  for (i = 0; i < tamanho; i++) {
    fprintf(arq_out, "O caixa de número %d atendeu %d clientes.\n", i + 1,
            caixas[i].qntdClientes);
  }
}