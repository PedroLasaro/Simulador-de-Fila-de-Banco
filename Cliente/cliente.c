#include "cliente.h"

#include <stdlib.h>

int pegarClasse(char *linha) {
  char *Classe;
  size_t i;
  int count;
  while (linha != "-") count++;
  Classe = (char *)malloc(count + 1);
  for (i = 0; i < count; i++) Classe[i] = linha[i];
  Classe[i] = '\0';
  if (Classe == "Premiun") return 1;
  if (Classe == "Ouro") return 2;
  if (Classe == "Prata") return 3;
  if (Classe == "Bronze") return 4;
  if (Classe == "Leezu") return 5;
  return 0;
}

int pegarConta(char *linha) {}

int pegarQntOpe(char *linha) {}

Cli *criarCliente(char *linha) {
  Cli *novo;
  novo = (Cli *)malloc(sizeof(Cli));
  novo->classe = pegarClasse(linha);
  novo->conta = pegarConta(linha);
  novo->ops = pegarQntOpe(linha);
  return novo;
}