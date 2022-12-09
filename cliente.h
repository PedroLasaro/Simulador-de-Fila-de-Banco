#ifndef cliente_h
#define cliente_h

typedef struct _cliente {
    int conta;
    int classe;
    int ops;
} Cli;

// Classe por Inteiro
// 0 = Sem Classe
// 1 = Premiun
// 2 = Ouro
// 3 = Prata
// 4 = Bronze
// 5 = Leezu

Cli * criarCliente(char *);

#endif