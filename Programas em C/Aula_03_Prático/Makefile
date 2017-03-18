questao_8: questao_8.o num_caracs.o
	gcc -o questao_8 questao_8.o num_caracs.o
questao_8.o: questao_8.c num_caracs.h
	gcc -c questao_8.c
num_caracs.o: num_caracs.c num_caracs.h
	gcc -c num_caracs.c
clean:
	rm -f *.o num_caracs 
