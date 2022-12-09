ALL: main

main : main.o escalonador.o cliente.o fila_fifo.o leitor.o logtree.o tempo.o
	gcc main.o escalonador.o cliente.o fila_fifo.o leitor.o logtree.o tempo.o -o main

main.o: main.c escalonador.h
	gcc -c main.c

escalonador.o: escalonador.c escalonador.h cliente.h fila_fifo.h leitor.h logtree.h tempo.h
	gcc -c escalonador.c

tempo.o:  tempo.c tempo.h cliente.h logtree.h escalonador.h
	gcc -c tempo.c

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