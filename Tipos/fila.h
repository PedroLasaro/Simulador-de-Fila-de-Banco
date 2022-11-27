#ifndef fila_h
#define fila_h

#include "cliente.h"

typedef struct _fila_FIFO {
  int chave;
  cli cliente;
  struct _fila_FIFO *prox;
} Fila_FIFO;

#endif  // !fila_h