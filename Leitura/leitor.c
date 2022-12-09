#include "leitor.h"

#include <ctype.h>
#include <stdio.h>

void percorrar(char *linha, char comp) {
  do *linha++;
  while (*linha != comp);
}

int pegarNumero(char *linha) {
  char *numero;
  numero = (char *)malloc(10);
  percorrar(linha, '=');

  do {
    *linha++;
    if (isdigit(*linha) != 0) {
      *numero = *linha;
      *numero++;
    }
  } while (*linha != '\n');
  *numero++;
  *numero = '\0';
  return atoi(numero);
}

int *pegarVetorNumerico(char *linha) {
  char *numero;
  numero = (char *)malloc(10);
  int vector[5], i = 0;
  percorrar(linha, '{');
  while (*linha != '\n') {
    while (*linha != ',' || &linha != '}') {
      *linha++;
      if (isdigit(*linha) != 0) {
        *numero = *linha;
        *numero++;
      }
      *numero = '\0';
      vector[i] = *numero;
      numero = (char *)realloc(numero, 10);
    }
    *linha++;
  }
  return vector;
}