#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "escalonador.h"

int main(int narg, char *argv[]) {
  float i;
  int j;
  char *saida, numero[4];
  Escalonador *Esc;
  Esc = (Escalonador *)malloc(sizeof(Escalonador));
  saida = (char *)malloc(sizeof(char) * 15);
  for (j = i = 0; i < narg; i++, j++) {
    sprintf(saida, "saida-0%3.0f", i);
    e_rodar(Esc, argv[j], saida);
  }
  return EXIT_SUCCESS;
}