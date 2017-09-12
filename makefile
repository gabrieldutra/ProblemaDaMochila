CC=gcc
OPCOES_COMPILADOR=-lm
TODOS_ARQUIVOS_PONTOH = modelos/util/util.h modelos/item/item.h algoritmos/backtracking/backtracking.h algoritmos/guloso/guloso.h
TODOS_ARQUIVOS_OBJ = mochila.o modelos/util/util.o modelos/item/item.o algoritmos/backtracking/backtracking.o algoritmos/guloso/guloso.o

%.o: ../%.c $(TODOS_ARQUIVOS_PONTOH)
	$(CC) -o $@ -c $< $(OPCOES_COMPILADOR)

all: $(TODOS_ARQUIVOS_OBJ)
	gcc -o mochila.out $^ $(OPCOES_COMPILADOR)

clean:
	rm *.o modelos/*/*.o algoritmos/*/*.o *.out