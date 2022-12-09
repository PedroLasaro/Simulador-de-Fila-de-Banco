#ifndef tempo_h
#define tempo_h

#include <stdio.h>

#include "cliente.h"
#include "escalonador.h"
#include "logtree.h"

void saidaTempoTotal(int, FILE *);
void saidaTempoDosCliente(int, int, int, int, int, FILE *);
void saidaTempoDasClasse(Log *, FILE *);
void saidaTempoDasCaixas(Caixas *caixas, int, FILE *);

#endif