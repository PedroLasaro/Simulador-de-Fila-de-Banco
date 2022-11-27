#ifndef escalonadorT_h
#define escalonadorT_h

#include "fila.h"

typedef struct _escalonador {
  Fila_FIFO Premiun;
  Fila_FIFO Ouro;
  Fila_FIFO Prata;
  Fila_FIFO Bronze;
  Fila_FIFO Leezu;
} Escalonador;

#endif  // !escalonadorT_h