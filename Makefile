ALL: Escalonador

Escalonador: escalonador.o cliente.o fila_fifo.o leitor.o logtree.o
	gcc escalonador.o cliente.o fila_fifo.o leitor.o logtree.o -o escalonador

escalonador.o: escalonador.c escalonador.h cliente.h fila_fifo.h leitor.h logtree.h
	gcc -c escalonador.c

cliente.o: cliente.c cliente.h
	gcc -c cliente.c

fila_fifo.o: fila_fifo.c fila_fifo.h
	gcc -c fila_fifo.c

leitor.o: leitor.c leitor.h
	gcc -c leitor.c

logtree.o: logtree.c logtree.h
	gcc -c logtree.c

clean:
	rm -rf *.o main