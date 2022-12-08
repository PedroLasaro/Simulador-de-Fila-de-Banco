#include "cliente.h"

#include <stdlib.h>

int Classe(char *Classe) {
  if (strcmp("Premiun", Classe) == 0) return 1;
  if (strcmp("Ouro", Classe) == 0) return 2;
  if (strcmp("Prata", Classe) == 0) return 3;
  if (strcmp("Bronze", Classe) == 0) return 4;
  if (strcmp("Leezu", Classe) == 0) return 5;
  return 0;
}

int lidarCliente(char *linha, Cli *cliente) {
  char *temp;
  size_t i, j;
  temp = (char *)malloc(10);
  if (temp == NULL) return 0;

  // Este fragmento vai ler a classe
  for (j = 0; *linha != ' '; *linha++, j++) temp[j] = *linha;
  j++, temp[j + 1] = '\0';
  i = i + 3;
  cliente->classe = Classe(temp);

  // Esta fragmento vai ler a conta
  while (*linha != ' ') *linha++;
  temp = (char *)relloc(temp, 10);
  for (j = 0; *linha != ' '; *linha++) temp[j] = *linha;
  j++, temp[j + 1] = '\0';
  cliente->conta = atoi(temp);

  // este fragmente vai lidar com o numero de operação
  temp = (char *)relloc(temp, 10);
  for (j = 0; *linha != ' '; *linha++) temp[j] = *linha;
  temp[j + 1] = '\0';
  cliente->ops = atoi(temp);
  free(temp);
  return 1;
}

Cli *criarCliente(char *linha) {
  Cli *novo;
  novo = (Cli *)malloc(sizeof(Cli));
  lidarCliente(linha, novo);
  return novo;
}