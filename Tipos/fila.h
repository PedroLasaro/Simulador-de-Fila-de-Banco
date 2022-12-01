#ifndef fila_h
#define fila_h

#include "cliente.h"

// Implementação do tipo Fila_FIFO

typedef struct _fila_FIFO {
  int chave;
  cli *cliente;
  _fila_FIFO *prox;
} Fila_FIFO;

// Nota: chave == -1 significa fila vazia

#endif  // !fila_h