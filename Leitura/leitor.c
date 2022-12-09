#include "leitor.h"

#include <stdio.h>

void percorrar(char *linha) {
  do linha++;
  while (*linha != '=');
}

int pegarNumero(char *linha) {
  char numero[10];
  percorrar(linha);

  while (*linha != '\n') {
  }
}